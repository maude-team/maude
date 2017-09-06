//
//	Functions that initiate parsing and analyse result.
//

void
MixfixModule::getParserStats(int& nrNonterminals, int& nrTerminals, int& nrProductions)
{
  makeGrammar();
  int nrKinds = getConnectedComponents().length();
  nrNonterminals = - nonTerminal(nrKinds, TERM_TYPE) - 1;
  nrTerminals = parser->getTokenSet().cardinality();
  nrProductions = parser->getNrProductions();
}


Term*
MixfixModule::parseTerm(const Vector<Token>& bubble,
			ConnectedComponent* component,
			int begin,
			int end)
{
  makeGrammar();
  int r = parseSentence(bubble,
			((component == 0) ? TERM :
			nonTerminal(component->getIndexWithinModule(), TERM_TYPE)),
			begin,
			end);
  if (r <= 0)
    {
      IssueWarning(LineNumber(bubble[0].lineNumber()) << ": no parse for term.");
      return 0;
    }

  Term* t1;
  Term* t2;
  parser->makeTerms(t1, t2);
  if (r > 1)
    {
      t1->symbol()->fillInSortInfo(t1);
      t2->symbol()->fillInSortInfo(t2);
      IssueWarning(LineNumber(bubble[0].lineNumber()) <<
		   ": ambiguous term, two parses are:\n" << t1 <<
		   "\n-versus-\n" << t2 <<
		   "\n\nArbitrarily taking the first as correct.");
      t2->deepSelfDestruct();
    }
  return t1;
}

int
MixfixModule::parseTerm2(const Vector<Token>& bubble,
			 ConnectedComponent* component,
			 Term*& parse1,
			 Term*& parse2,
			 int& firstBad)
{
  makeGrammar();
  int r = parser->parseSentence(bubble,
				((component == 0) ? TERM :
				 nonTerminal(component->getIndexWithinModule(), TERM_TYPE)),
				firstBad,
				0,
				bubble.length());
  if (r > 0)
    parser->makeTerms(parse1, parse2);
  return r;
}

void
MixfixModule::parseStatement(const Vector<Token>& bubble)
{
  makeGrammar();
  int r = parseSentence(bubble, STATEMENT);
  if (r <= 0)
    {
      IssueWarning(LineNumber(bubble[0].lineNumber()) <<
		   ": no parse for statement\n" << bubble << " .");
      return;
    }
  if (r > 1)
    {
      IssueWarning(LineNumber(bubble[0].lineNumber()) <<
		   ": multiple distinct parses for statement\n" << bubble << " .");
    }
  parser->insertStatement();
}

bool
MixfixModule::parseMatchCommand(const Vector<Token>& bubble,
				Term*& pattern,
				Term*& subject,
				Vector<ConditionFragment*>& condition)
{
  makeGrammar(true);
  int r = parseSentence(bubble, MATCH_COMMAND);
  if (r <= 0)
    {
      IssueWarning(LineNumber(bubble[0].lineNumber()) <<
		   ": no parse for command.");
      return false;
    }
  if (r > 1)
    {
      IssueWarning(LineNumber(bubble[0].lineNumber()) <<
		   ": multiple distinct parses for command.");
    }
  parser->makeMatchCommand(pattern, subject, condition);
  return true;
}

bool
MixfixModule::parseSearchCommand(const Vector<Token>& bubble,
				 Term*& initial,
				 int& searchType,
				 Term*& target,
				 Vector<ConditionFragment*>& condition)
{
  makeGrammar(true);
  int r = parseSentence(bubble, SEARCH_COMMAND);
  if (r <= 0)
    {
      IssueWarning(LineNumber(bubble[0].lineNumber()) <<
		   ": no parse for command.");
      return false;
    }
  if (r > 1)
    {
      IssueWarning(LineNumber(bubble[0].lineNumber()) <<
		   ": multiple distinct parses for command.");
    }
  parser->makeSearchCommand(initial, searchType, target, condition);
  return true;
}

int
MixfixModule::parseSentence(const Vector<Token>& bubble, int root, int begin, int end)
{
  if (end == DEFAULT)
    end = bubble.length() - 1;
  int nrTokens = end - begin + 1;
  int firstBad;
  int r = parser->parseSentence(bubble, root, firstBad, begin, nrTokens);
  if (r <= 0)
    {
      if (r == -1)
	{
	  IssueWarning(LineNumber(bubble[firstBad].lineNumber()) <<
		       ": bad token " << QUOTE(bubble[firstBad].name()) << '.');
	}
      else if (firstBad == nrTokens)
	{
	  IssueWarning(LineNumber(bubble[end].lineNumber()) <<
		       " : unexpected end of tokens.");
	}
      else
	{
	  IssueWarning(LineNumber(bubble[firstBad].lineNumber()) <<
		       ": didn't expect token " << QUOTE(bubble[firstBad]) << ':');
	  Token::printTokenVector(cerr, bubble, begin, firstBad, false);  // HACK
	  cerr << " <---*HERE*\n";
	}
    }
  return r;
}
