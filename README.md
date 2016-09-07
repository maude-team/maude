## NOTES ON GIT BRANCHES FOR MAUDE + HOOKS

This branch contains the original Maude sources with the Termination Checker hooks used in Maude Formal Environment. It may be compiled in Linux and Mac OS X. This readme file includes all changes done on Maude source code.

### Initial repository setting

The original repository stands on https://github.com/maude-team/maude.git. Local copy for UMA is stored in //atenea02/gisum/uma/es/usr/jmalvarez/maude-githab/maude. Local repository is a clone of remote repository:

~~~
git clone https://github.com/maude-team/maude.git
~~~

A new branch has been created to host the MFE hooks (mfe-hooks):

~~~
cd maude
git branch mfe-hooks
git checkout mfe-hooks
~~~

Make has been built using the new verion of ncurses library installed in atenea02:

~~~
../configure CPPFLAGS="-I/usr/local/include -I/usr/local/include/ncurses" LDFLAGS="-static -L/usr/local/lib" GMP_LIBS="/usr/local/lib/libgmpxx.a /usr/local/lib/libgmp.a" LIBSIGSEGV_LIB="/usr/local/lib/libsigsegv.a" TECLA_LIBS="/usr/local/lib/libtecla.a /usr/local/lib/libncurses.a" BUDDY_LIB="/usr/local/lib/libbdd.a"
~~~

Maude source files are modified to incorporate the MFE hooks and new source code files are included in their corresponding directories:

~~~
./configure.ac

< AC_INIT(Maude, 2.6, [maude-bugs@maude.cs.uiuc.edu])
---
> AC_INIT(Maude-ceta, 2.6, [maude-bugs@maude.cs.uiuc.edu])
19c19
< AM_INIT_AUTOMAKE(Maude, 2.6)
---
> AM_INIT_AUTOMAKE(Maude-ceta, 2.6)

./src/BuiltIn/Makefile.am
37c37,38
<       equalityExtorFinal.cc
---
>       equalityExtorFinal.cc \
>       terminationCheckerSymbol.cc
64c65,66
<       equalityExtorFinal.hh
---
>       equalityExtorFinal.hh \
>       terminationCheckerSymbol.hh
~~~

Modified ./src/Mixfix/Makefile.am to include new headers in the libbuiltIn_a_CPPFLAGS list:

~~~
        -I$(top_srcdir)/src/Mixfix \
        -I$(top_srcdir)/src/IO_Stuff \
        -I$(top_srcdir)/src/Higher \
        -I$(top_srcdir)/src/StrategyLanguage \
        -I$(top_srcdir)/src/AU_Theory
~~~

Copied source files ./src/BuiltIn/terminationCheckerSymbol.hh and ./src/BuiltIn/terminationCheckerSymbol.cc
Made changes in ../src/Mixfix/mixfixModule.cc to include hook:

~~~
554a555,560
>     case SymbolType::TERMINATION_CHECKER_SYMBOL:
>        return new TerminationCheckerSymbol(name,nrArgs);
~~~

Made changes in ../src/Mixfix/specialSymbolTypes.cc to include hook:

~~~
150a151,155
> // for ceta and termination checker
> #include "terminationCheckerSymbol.hh"
~~~

Made changes in ../src/Mixfix/symbolType.hh to include hook:

~~~
56a57,59
>   MACRO(TerminationCheckerSymbol, SymbolType::TERMINATION_CHECKER_SYMBOL)
~~~

Made changes in ../src/Mixfix/symbolType.hh to include hook:

~~~
56a57,59
78a79,81
>     TERMINATION_CHECKER_SYMBOL,
~~~

Changed ./src/Mixfix/banner.cc to include a new line in the opening banner with information about the new features.

~~~
   s << "\t     With CETA and termination checker extensions \n";
~~~

Installation:

~~~
jmalvarez@atenea02:~/maude-github/maude$ autoconf
jmalvarez@atenea02:~/maude-github/maude$ automake
Useless use of /d modifier in transliteration operator at /usr/share/automake-1.9/Automake/Wrap.pm line 60.
configure.ac:19: version mismatch.  This is Automake 1.9.6,
configure.ac:19: but the definition used by this AM_INIT_AUTOMAKE
configure.ac:19: comes from Automake 1.11.3.  You should recreate
configure.ac:19: aclocal.m4 with aclocal and run automake again.
jmalvarez@atenea02:~/maude-github/maude$ aclocal
~~~

### Mac OS X Users

Maude + TerminationChecker hooks can be compiled on OS X, with a minor change:

In file `/src/BuiltIn/terminationCheckerSymbol.cc` added `#include <signal.h>`. 

## Instructions to create a new hook

This is a temptative guide to build new hooks for Maude. The following guidelines are based on guesses I’m doing about the original Maude code and the hooks code I wrote two years ago. Use it with caution and at your own risk.

Files which define hooks in Maude:

../src/BuiltIn/ACU_NumberOpSymbol.cc
../src/BuiltIn/bindingMacros.hh
../src/BuiltIn/CUI_NumberOpSymbol.cc
../src/BuiltIn/floatOpSymbol.cc
../src/BuiltIn/numberOpSymbol.cc
../src/BuiltIn/stringOpSymbol.cc
../src/BuiltIn/terminationCheckerSymbol.cc
../src/Mixfix/quotedIdentifierOpSymbol.cc
../src/SMT/SMT_NumberSymbol.cc

To define a new hook or a new set of hooks, follow the examples in the files listed above. In first place, a new class must be defined. That new class must inherit from FreeSymbol. Create a new header file (.hh) and a new body file (.cc) for the class.

Minimal set of operations to be implemented by classes which implement hooks:
  <<constructor>>(int id, int nrArgs);

  bool attachData(const Vector<Sort*>& opDeclaration,
                  const char* purpose,
                  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  void copyAttachments(Symbol* original, SymbolMap* map);
  void getDataAttachments(const Vector<Sort*>& opDeclaration,
                          Vector<const char*>& purposes,
                          Vector<Vector<const char*> >& data);
  void getSymbolAttachments(Vector<const char*>& purposes,
                            Vector<Symbol*>& symbols);

  bool eqRewrite(DagNode* subject, RewritingContext& context);

The constructor’s arguments must be the same. They are used to call the superclass’ constructor (FreeSymbol(id, nrArgs)).

The inherited attribute op is used in the same way that it is used in the already done hooks, no changes are required.

A new attribute is required for every symbol that the hook can take. Any of those attributes will be declared of a particular *Symbol class. For example, the termination checker hook can take strings, bool values (true, false) and natural numbers as arguments, and return a quid list and a string as results. That means that the following attributes are required:
  StringSymbol* stringSymbol;
  Symbol* falseSymbol;  Symbol* trueSymbol;
  QuotedIdentifierSymbol* quotedIdentifierSymbol;
  Symbol* nilQidListSymbol;
  AU_Symbol* qidListSymbol;
  SuccSymbol* succSymbol;
From the above list, it seems that a new attribute is required for every constructor of the type used.

A new attribute is required for every term that the hook can take. Those attributes are declared of class CachedDag.

The method attachData must include a call to macro BIND_OP for every symbol attribute, where the the second argument of the call to BIND_OP is the name of the new hook’s class. For example:
BIND_OP(purpose, stringSymbol, op, data);

The method attachSymbol must include a call to the macro BIND_SYMBOL for every symbol attribute, where the third and fourth arguments of the call are the name of the new hook’s attributes and a pointer to its class. For example:
BIND_SYMBOL(purpose, symbol, stringSymbol, StringSymbol*);

The method attachTerm must include a call to the macro BIND_TERM for every term attribute, where the the third argument of the call to BIND_TERM is the name of the new hook’s term attributes. For example:
BIND_TERM(purpose, term, trueTerm);

The method copyAttachments must include a call to the macro COPY_SYMBOL for every symbol attribute and a call to the macro COPY_TERM for every term attribute. In the calls to COPY_SYMBOL, the second and argument is the name of the attribute, and the fourth one its type. In the calls to COPY_TERM, the second argument is the name of the attribute. For example:
  COPY_SYMBOL(orig, decFloatSymbol, map, Symbol*);
  COPY_TERM(orig, trueTerm, map);

The method getDataAttachments must include an assignment to add to the array purposes a string with the name of the class. For example:
purposes[nrDataAttachments] = "TerminationCheckerSymbol";

It also must be added a CODE_CASE option for the switch(op) sentence for every hook added. For example:
CODE_CASE(d, 'c', 'h', "checktermination")
where the last argument must match the string defined as the hook identifier in the corresponding Maude module (see below in this document). The first two arguments are the unique code for that symbol. That code will be used in the method eqRewrite.

The method getSymbolAttachments must include a call to the macro APPEND_SYMBOL for every symbol attribute, where the third argument is the the name of the attribute. For example:
  APPEND_SYMBOL(purposes, symbols, stringSymbol);

The method getTermAttachments must include a call to the macro APPEND_TERM for every term attribute, where the third argument of the call to APPEND_TERM is the name attribute. For example:
  APPEND_TERM(purposes, terms, trueTerm);

The method postInterSymbolPass must include a call to the macro PREPARE_TERM for every term attribute where the argument is the name of the attribute. For example:
  PREPARE_TERM(trueTerm);

The method reset() must include a call the the method reset() of every term attribute. For example:
trueTerm.reset();

The method eqRewrite is where the term written by the user in the Maude interpreter is parsed and processed. The string written by the user is stored in the argument subject. To get access to its tokens, the next variables and assignments are used:
      ACU_DagNode* d = getACU_DagNode(subject);
      int nrArgs = d->nrArgs();
      for (int i = 0; i < nrArgs; i++)
        {
          DagNode* a = d->getArgument(i);
          Symbol* s = a->symbol();
          . . .

To check the type of a token, the symbol can be compared in a way like this:
if (a->symbol() == floatSymbol)

To get the value of a symbol, a cast to the proper type can be used:
double a1 = static_cast<FloatDagNode*>(d->getArgument(0))->getValue();
Rope toolName = safeCast(StringDagNode*, a)->getValue();

To parse the possible terms, the CODE macro is used:

switch (op) {
case CODE('c','h'):

The arguments to CODE are similar to the first two arguments used in the call to CODE_CASE in getDataAttachments.


NOTE: Original Maude hooks which deal with boolean values (true and false), define them as terms, what means that no attributes are defined for them, no symbols are bounds for them, but a term is bound for each of them. However, in the termination checker hook, true and false are treated as symbols, and I don’t know the reason. However, it seems to work well with both approaches.


Besides this C++ code, a maude module must be loaded to define the hooks. In the case of the termination checker hook, the module is:

fmod TERMINATION-CHECK is
  pr BOOL .
  pr INT .
  pr STRING .
  pr QID .
  pr QID-LIST .
  op termCheck : [String] [String] [Nat] -> [QidList] [ctor special (
    id-hook TerminationCheckerSymbol (checktermination)
    op-hook succSymbol (s_ : Nat ~> NzNat)
    op-hook quotedIdentifierSymbol (<Qids> : ~> Qid)
    op-hook nilQidListSymbol (nil : ~> QidList)
    op-hook qidListSymbol (__ : QidList QidList ~> QidList)
    op-hook stringSymbol (<Strings> : ~> String))] .
  op writeToFile : [String] [String] [Bool] -> [String] [ctor special (
    id-hook TerminationCheckerSymbol (writelog)
    op-hook trueSymbol (true : ~> Bool)
    op-hook falseSymbol (false : ~> Bool)
    op-hook stringSymbol (<Strings> : ~> String)
    op-hook stringSymbol (<Strings> : ~> String))] .
endfm

Note: The previous version is old, dated back in 2014. There is another version of the module used to work with the tool MTT. If differs in the type of the result returned by termCheck and in that there is a third hook stringTokenize. However that third hook does not work properly now.

fmod TERMINATION-CHECK is
  pr BOOL .
  pr INT .
  pr STRING .
  pr QID .
  pr QID-LIST .

*** First parameter: keywork for the external tool
*** Second parameter: expression to be checked
***                   A temporary file is created containing the expression
***                   and the file is passed as argument to the tool.
*** Third parameter: Maximum number of miliseconds for the computation
*** Result: Resulting String from the external tool shown as QidList
*** This function relays on the existence of a configuration file
*** called mfe.config. This file include one line per tool with two or three
*** keywords:
*** - keyword for the external tool,
*** - batch file to be run
*** - expected file extension for that external tool.
*** Example: 
*** aprove /usr/local/utils/runme .trs
*** othertool /usr/local/utils/runmenow
*** That file is searched in $MAUDE_LIB, the directory where the executable 
*** file is and in the present directory, in that order

  op termCheck : String String Nat ~> String
       [ctor
        special (id-hook TerminationCheckerSymbol (checktermination)
                 op-hook succSymbol (s_ : Nat ~> NzNat)
                 op-hook stringSymbol (<Strings> : ~> String))].
   
*** First parameter: Name of the log file.
*** Second parameter: String to be written to the file.
*** Third parameter: true -> remove previous file content,
***                  false -> append to the previous file content.
*** Result: The message is written to the log file and a String is returned
***         ("ERROR" or "SUCCESS")
  op writeToFile : String String Bool ~> String
       [ctor
        special (id-hook TerminationCheckerSymbol (writelog)
                 op-hook trueSymbol (true : ~> Bool)
                 op-hook falseSymbol (false : ~> Bool)
                 op-hook stringSymbol (<Strings> : ~> String)
                 op-hook stringSymbol (<Strings> : ~> String))].

  op stringTokenize : String ~> QidList 
       [ctor
        special (id-hook TerminationCheckerSymbol (strtokenizer)
                 op-hook quotedIdentifierSymbol (<Qids> : ~> Qid)
                 op-hook nilQidListSymbol (nil : ~> QidList)
                 op-hook qidListSymbol (__ : QidList QidList ~> QidList)
                 op-hook stringSymbol (<Strings> : ~> String))].

endfm

