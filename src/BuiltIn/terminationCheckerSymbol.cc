/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//      Implementation for class TerminationCheckerSymbol.
//

#include <sys/wait.h>
#include <vector>
#include <errno.h>
#include <sstream>

//      utility stuff
#include "macros.hh"
#include "vector.hh"
#include "bindingMacros.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"
#include "AU_Theory.hh"
#include "higher.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

//      core class definitions
#include "stringSymbol.hh"
#include "symbolMap.hh"
#include "rewritingContext.hh"
#include "stringDagNode.hh"
#include "term.hh"
#include "succSymbol.hh"

//      free theory class definitions
#include "freeDagNode.hh"

//      AU theory class definitions
#include "AU_Symbol.hh"
#include "AU_DagNode.hh"

//      front end class definitions
#include "token.hh"
#include "quotedIdentifierSymbol.hh"
#include "quotedIdentifierDagNode.hh"
#include "loopSymbol.hh"

//      mixfix frontend definitions
#include "fileTable.hh"
#include "directoryManager.hh"
#include "mixfixModule.hh"
#include "interpreter.hh"
#include "global.hh"

#include "terminationCheckerSymbol.hh"

//const string TerminationCheckerSymbol::mfeConfigFileName = "mfe.config";
#define MFE_CONFIG "mfe.config"

bool findPrelude(string &directory, string &fileName);

TerminationCheckerSymbol::TerminationCheckerSymbol(int id, int arity)
  : FreeSymbol(id, arity),
    op(NONE),
    stringSymbol(0),
    falseSymbol(0),
    trueSymbol(0),
    quotedIdentifierSymbol(0),
    nilQidListSymbol(0),
    qidListSymbol(0),
    succSymbol(0),
    child(0)
{
//  printf("Constructing\n");
    execFiles = (map<crope, pair <crope, crope> > *)0;
}


TerminationCheckerSymbol::~TerminationCheckerSymbol()
{
  terminate();
}

bool
TerminationCheckerSymbol::attachData(const Vector<Sort*>& opDeclaration,
			   const char* purpose,
			   const Vector<const char*>& data)
{
  BIND_OP(purpose, TerminationCheckerSymbol, op, data);
  return FreeSymbol::attachData(opDeclaration, purpose, data);
}

bool
TerminationCheckerSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
  BIND_SYMBOL(purpose, symbol, stringSymbol, StringSymbol*);
  BIND_SYMBOL(purpose, symbol, falseSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, trueSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, quotedIdentifierSymbol, QuotedIdentifierSymbol*);
  BIND_SYMBOL(purpose, symbol, nilQidListSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, qidListSymbol, AU_Symbol*);
  BIND_SYMBOL(purpose, symbol, succSymbol, SuccSymbol*);
  return FreeSymbol::attachSymbol(purpose, symbol);
}

bool
TerminationCheckerSymbol::attachTerm(const char* purpose, Term* term)
{
//  BIND_TERM(purpose, term, executableTerm);
  return FreeSymbol::attachTerm(purpose, term);
}

void
TerminationCheckerSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
  TerminationCheckerSymbol* orig = safeCast(TerminationCheckerSymbol*, original);
  op = orig->op;
  COPY_SYMBOL(orig, stringSymbol, map, StringSymbol*);
  COPY_SYMBOL(orig, trueSymbol, map, Symbol*);
  COPY_SYMBOL(orig, falseSymbol, map, Symbol*);
  COPY_SYMBOL(orig, quotedIdentifierSymbol, map, QuotedIdentifierSymbol*);
  COPY_SYMBOL(orig, nilQidListSymbol, map, Symbol*);
  COPY_SYMBOL(orig, qidListSymbol, map, AU_Symbol*);
  COPY_SYMBOL(orig, succSymbol, map, SuccSymbol*);
//  COPY_TERM(orig, executableTerm, map);
  FreeSymbol::copyAttachments(original, map);
}

int writen(int fd, const char* ptr, int nbytes)
{
  int nleft, nwritten;
  
  nleft = nbytes;
  while (nleft > 0) {
    nwritten = write(fd, ptr, nleft);
    if (nwritten <= 0)
      return(nwritten);  /* error */
    
    nleft -= nwritten;
    ptr += nwritten;
  }
  return(nbytes - nleft);
}

static bool
rewriteToString(StringSymbol* stringSymbol, DagNode* subject,
    RewritingContext& context, const crope& result) {

  bool trace = RewritingContext::getTraceStatus();
  if (trace)
    {
      context.tracePreEqRewrite(subject, 0, RewritingContext::BUILTIN);
      if (context.traceAbort())
	return false;
    }
  (void) new(subject) StringDagNode(stringSymbol, result);
  context.incrementEqCount();
  if (trace)
    context.tracePostEqRewrite(subject);
  return true;
}

static bool
rewriteToQid(QuotedIdentifierSymbol* quotedIdentifierSymbol, DagNode* subject,
    RewritingContext& context, const crope& result) {

  int idIndex = Token::ropeToPrefixNameCode(result);
  if (idIndex != NONE) {
    bool trace = RewritingContext::getTraceStatus();
    if (trace)
    {
      context.tracePreEqRewrite(subject, 0, RewritingContext::BUILTIN);
      if (context.traceAbort())
	return false;
      }
    (void) new(subject) QuotedIdentifierDagNode(quotedIdentifierSymbol, idIndex);
    context.incrementEqCount();
    if (trace)
      context.tracePostEqRewrite(subject);
    return true;
  }
}

list<crope*> splitCrope(const crope & src)
{

  list<crope*> splStr;

  crope::const_iterator f = src.begin(), l = src.end();
  crope::const_iterator iniword, endword;
  while (f != l){
    while (f != l && isspace(*f) != 0){ f++;}
    if (f != l){
      iniword = f;
      while (f != l && isspace(*f) == 0){ f++;}
      endword = f;
      crope * nr = new crope(iniword, endword);
      splStr.push_back(nr);
    }
  }
  return splStr;
}

/*
list<crope*> splitCrope(const crope & src)
{

  list<crope*> splStr;

  string srcAsStr(src.c_str());
  stringstream srcAsStrStream(srcAsStr);
  string word;

  srcAsStrStream >> word;
  while (!srcAsStrStream.fail()){
    splStr.push_back(new crope(word.c_str()));
    srcAsStrStream >> word;
  }
  return splStr;
}
*/

/*
list<crope*> splitString(const string & orig)
{
  stringstream origAsStrStream(orig);
  string word;
  list<crope*> splStr;

  origAsStrStream >> word;
  while (!origAsStrStream.fail()){
    splStr.push_back(new crope(word.c_str()));
    origAsStrStream >> word;
  }
  return splStr;
}
*/

/*
Vector<DagNode*> listcropeTolistQid(QuotedIdentifierSymbol* quotedIdentifierSymbol, list<crope*> listCR)
{
  Vector<DagNode*> listDN;
  list<crope*>:: iterator it;
  for(it = listCR.begin(); it != listCR.end(); it++){
    int idIndex = Token::ropeToPrefixNameCode(**it);
    listDN.append(new QuotedIdentifierDagNode(quotedIdentifierSymbol, idIndex));
  }
  return listDN;
}
*/

DagNode* makeQidListNode(QuotedIdentifierSymbol* quotedIdentifierSymbol, 
                         Symbol* nilQidListSymbol, AU_Symbol* qidListSymbol, 
                         const list<crope*> & listCR) {
      Vector<DagNode*> args;
      if (listCR.empty())
        return nilQidListSymbol->makeDagNode(args);
      else
      {
        const list<crope *>::const_iterator e = listCR.end();
        for(list<crope *>::const_iterator i = listCR.begin(); i!=e; ++i)
        {
          args.append(new QuotedIdentifierDagNode(quotedIdentifierSymbol,
                          Token::ropeToPrefixNameCode(**i)));
        }
      }
      return qidListSymbol->makeDagNode(args);
    }

/*
static bool
rewriteToQidList(QuotedIdentifierSymbol* quotedIdentifierSymbol, 
                 Symbol* nilQidListSymbol, AU_Symbol* qidListSymbol, 
                 DagNode* subject, RewritingContext& context, const crope& result)
{

  int idIndex = Token::ropeToPrefixNameCode(result);
  if (idIndex != NONE) {
    bool trace = RewritingContext::getTraceStatus();
    if (trace)
    {
      context.tracePreEqRewrite(subject, 0, RewritingContext::BUILTIN);
      if (context.traceAbort())
	return false;
    }

    list<crope*> result_lst = splitCrope(result);
    DagNode* ret = makeQidListNode(quotedIdentifierSymbol, nilQidListSymbol, 
                                   qidListSymbol, result_lst);
     return context.builtInReplace(subject, ret);

    context.incrementEqCount();
    if (trace)
      context.tracePostEqRewrite(subject);
    return true;
  }
}
*/

bool
TerminationCheckerSymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), "bad symbol");
  int nrArgs = arity();
  FreeDagNode* d = safeCast(FreeDagNode*, subject);
  std::vector<crope> argums;
  bool specialEval = true;

  // Evaluate arguments.
  for (int i = 0; i < nrArgs; i++) {
    DagNode* a = d->getArgument(i);
    a->reduce(context);
      if (!(succSymbol != 0 && succSymbol->isNat(a)))
        specialEval = false;
  }

  switch (op) {
    case CODE('c','h'):
      {
        Assert(nrArgs == 3, "checkTermination has three arguments");
        DagNode* a = d->getArgument(0);
	if (a->symbol() == stringSymbol) {
          pair<crope, crope> batch_exten = 
                chooseBatch((safeCast(StringDagNode*, a)->getValue()).c_str());
          crope batchfile = batch_exten.first;
          if (batchfile.compare(crope("")) == 0) { 
            cerr << "No batch file associated to tool " << 
                    (safeCast(StringDagNode*, a)->getValue()).c_str() << endl;
          } else {
            argums.push_back(batchfile);
            a = d->getArgument(1);
            if (a->symbol() == stringSymbol) {
              crope extension = batch_exten.second;
              crope tmpFileNam = 
                    createTempFile(safeCast(StringDagNode*, a)->getValue(),
                                            extension);
              if (tmpFileNam.compare(crope("")) != 0){
                argums.push_back(tmpFileNam);
                a = d->getArgument(2);
                if (succSymbol->isNat(a)) {
                  const mpz_class& aa0 = succSymbol->getNat(a);
                  std::stringstream ss;
                  ss << aa0;
                  crope cr_argum3(ss.str().c_str());  
                  argums.push_back(cr_argum3);
	          crope t = sendMsg(argums);
/* JMAP 01/jul/2014
Commented to check content of temporary file because of 
exception raise in aprove.
                  if (remove(tmpFileNam.c_str()) == -1) {
                    cerr << "Warning: error removing temporary file " 
                         << tmpFileNam <<". error " << errno << endl;
                  }
*/
                  list<crope*> result_lst = splitCrope(t);
/*
                  DagNode* ret = makeQidListNode(quotedIdentifierSymbol, 
                                 nilQidListSymbol, qidListSymbol, result_lst);
                  return context.builtInReplace(subject, ret);
*/
                  return rewriteToString(stringSymbol, subject, context, t);
                }
              }
            }
          }
        }
      }
      break;
    case CODE('w', 'r'):
      {
        DagNode* a0 = d->getArgument(0);
        DagNode* a1 = d->getArgument(1);
        DagNode* a2 = d->getArgument(2);
        if ((a0->symbol() == stringSymbol) &&
            (a1->symbol() == stringSymbol)) {
          if ((a2->symbol() == falseSymbol) ||
               (a2->symbol() == trueSymbol)){
            argums.push_back(safeCast(StringDagNode*, a0)->getValue());
            argums.push_back(safeCast(StringDagNode*, a1)->getValue());
            if (a2->symbol() == trueSymbol) {
              crope cropeTrue("true");
              argums.push_back(cropeTrue);
            } else if (a2->symbol() == falseSymbol) {
              crope cropeFalse("false");
              argums.push_back(cropeFalse);
            } else {
              cout << "The value of the third argument " 
                   << "must be 'true' of 'false'." << endl;
            }
	    crope t = writeLogFile(argums);
            return rewriteToString(stringSymbol, subject, context, t);
          } else {
          }
        }
      }
      break;
    case CODE('s','t'):
      {
        DagNode* a0 = d->getArgument(0);
        if (a0->symbol() == stringSymbol){
          list<crope*> 
          result_lst = splitCrope(safeCast(StringDagNode*, a0)->getValue());
          DagNode* ret = makeQidListNode(quotedIdentifierSymbol, 
                         nilQidListSymbol, qidListSymbol, result_lst);
          return context.builtInReplace(subject, ret);
        }
      }
      break;
    default:
      CantHappen("bad string op");
  }
  return FreeSymbol::eqRewrite(subject, context);
}

void
TerminationCheckerSymbol::getDataAttachments(const Vector<Sort*>& opDeclaration,
				   Vector<const char*>& purposes,
				   Vector<Vector<const char*> >& data)
{
  int nrDataAttachments = purposes.length();
  purposes.resize(nrDataAttachments + 1);
  purposes[nrDataAttachments] = "TerminationCheckerSymbol";
  data.resize(nrDataAttachments + 1);
  data[nrDataAttachments].resize(1);
  const char*& d = data[nrDataAttachments][0];
  switch (op) {
    CODE_CASE(d, 'c', 'h', "checktermination")
    CODE_CASE(d, 'w', 'r', "writelog")
    CODE_CASE(d, 's', 't', "strtokenizer")
    default: 
      CantHappen("bad string op");
  }
  FreeSymbol::getDataAttachments(opDeclaration, purposes, data);
}

void
TerminationCheckerSymbol::getSymbolAttachments(Vector<const char*>& purposes,
				     Vector<Symbol*>& symbols)
{
  APPEND_SYMBOL(purposes, symbols, stringSymbol);
  APPEND_SYMBOL(purposes, symbols, trueSymbol);
  APPEND_SYMBOL(purposes, symbols, falseSymbol);
  APPEND_SYMBOL(purposes, symbols, quotedIdentifierSymbol);
  APPEND_SYMBOL(purposes, symbols, nilQidListSymbol);
  APPEND_SYMBOL(purposes, symbols, qidListSymbol);
  APPEND_SYMBOL(purposes, symbols, succSymbol);
  FreeSymbol::getSymbolAttachments(purposes, symbols);
}

void
TerminationCheckerSymbol::getTermAttachments(Vector<const char*>& purposes,
				   Vector<Term*>& terms)
{
//  APPEND_TERM(purposes, terms, executableTerm);
  FreeSymbol::getTermAttachments(purposes, terms);
}

void
TerminationCheckerSymbol::postInterSymbolPass()
{
  //(void) executableTerm.normalize();
  //executableTerm.prepare();
}

void
TerminationCheckerSymbol::reset()
{
  //executableTerm.reset();  // so executable dag can be garbage collected
  FreeSymbol::reset();     // parents reset() tasks
}

void
TerminationCheckerSymbol::resetRules()
{
//  terminate();
  FreeSymbol::resetRules();
}

crope TerminationCheckerSymbol::sendMsg(vector<crope> & msg) {

  static int max_size = 0;

  char command[1024];
  crope reply_str("");
  char line[1024];
 
  sprintf(command, "%s %s %s", msg[0].c_str(), msg[1].c_str(), msg[2].c_str());

  FILE *pop = popen(command, "r");

  if (pop == NULL){
    cerr << "Error in popen" << endl;
    return "ERROR";
  }

  while ((fgets(line, 1024, pop)) != NULL){
    reply_str += line;
    if (reply_str.size() == 100000) {
      cerr << "Reply size is HUGE!  Bad things ahead." << endl;
    }
  }

  pclose(pop);

  if (max_size < reply_str.size()) {
    max_size = reply_str.size();
//    cerr << "New largest reply " << max_size << endl;
  }

//  cerr << "Received reply" << endl;
  return reply_str;

}

void
TerminationCheckerSymbol::terminate(void)
{
  if (child != 0) {
    // Kill process
    // No need to check error of kill(), because it only should fail if
    // process has already terminated.
    printf("TERMINATING CIME\n");
    kill(child, SIGTERM);
    close(queryFd);
    close(replyFd);
    child = 0;
  }
}

const pair <crope, crope>
TerminationCheckerSymbol::chooseBatch(const crope & tool){
  if (execFiles == (map<crope, pair <crope, crope> >*) 0){
    readToolsFile(&execFiles);
  }
  if (execFiles == (map<crope, pair <crope, crope> >*) 0){
    return pair<crope, crope> (crope(""), crope(""));
  } else {
    if (0 < execFiles->count(tool)){
      return (*execFiles)[tool];
    } else {
      return pair<crope, crope> (crope(""), crope(""));
    }
  }
}

void
TerminationCheckerSymbol::readToolsFile(map<crope, pair<crope, crope> > **mp)
{
  char line[2100], tool_name[1024], test_file_name[1024], extension[32];
  char *envvar = getenv("MAUDE_LIB");
  int read_items, acc_rslt;

// Directory search order for config file:
// $MAUDE_LIB, directory where the executable file is and the presnt dir (.).
  string directory;
  string fileName(MFE_CONFIG);

  if (findPrelude(directory, fileName)){
    string fullPathFileName = directory + "/" + fileName;
    ifstream f(fullPathFileName.c_str());
    if (f.fail()){
      cerr << "Error opening file " << fullPathFileName << endl;
      return;
    }

    f.getline(line, 2100);
    while (!f.fail()){
      read_items = sscanf(line, "%s %s %s\n", 
                          tool_name, test_file_name, extension);
      if (read_items == 1){
        cerr << "Warning: Incorrect line in configuration file"
             << " for tools and batch files. Line discarded" << endl;
      }else if (read_items == 2) {
        if (*mp == (map<crope, pair<crope, crope> >*) 0) {
          *mp = new map<crope, pair<crope, crope> >;
        }
        (**mp)[crope(tool_name)] = 
              pair<crope, crope> (crope(test_file_name), crope(""));
      } else if (read_items == 3){
        if (*mp == (map<crope, pair<crope, crope> >*) 0) {
          *mp = new map<crope, pair<crope, crope> >;
        }
        (**mp)[crope(tool_name)] = 
              make_pair (crope(test_file_name), crope(extension));
      }
      f.getline(line, 2100);
    }

    if (!f.eof()){
      cerr << "Error reading file " << fileName << "." << endl;
    }
    f.close();
  }

}

crope TerminationCheckerSymbol::createTempFile(const crope & expr, const crope & ext)
{
  char fileName[L_tmpnam + 4];
  ofstream f;

  tmpnam(fileName);

  strcat(fileName, ext.c_str());
  f.open(fileName);

  if (!f.fail()) {
    f << expr.c_str();
    f.close();
    return crope(fileName);
  } else {
    return crope("");
  }
}

crope TerminationCheckerSymbol::writeLogFile(const vector<crope> &args)
{
  char *envvar = (char *)0;
  ofstream f;
  ios_base::openmode mode;

  if (args[2] == crope("true")){
    mode = ios_base::out;
  } else if (args[2] == crope("false")){
    mode = ios_base::app;
  } else {
    cerr << "Error: opening mode must be \"true\" to reset the log file or \"false\" to append to the current log file." << endl;
    return crope("ERROR");
  }

  f.open(args[0].c_str(),mode);
  if (f.fail()){
    cerr << "Error when opening file " << args[0] 
         << ". ERROR: " << strerror(errno) << endl;
    return crope("ERROR");
  }

  f << args[1].c_str() << endl;

  f.close();

  return crope("SUCCESS");

}

