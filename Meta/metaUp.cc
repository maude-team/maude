DagNode*
MetaLevel::upQid(int id, PointerMap& qidMap)
{
  void* p = const_cast<void*>(static_cast<const void*>(Token::name(id)));
  DagNode *d = static_cast<DagNode*>(qidMap.getMap(p));
  if (d == 0)
    {
      d = new QuotedIdentifierDagNode(qidSymbol, Token::backQuoteSpecials(id));
      (void) qidMap.setMap(p, d);
    }
  return d;
}

DagNode*
MetaLevel::upType(Sort* sort, PointerMap& qidMap)
{
  int id = sort->id();
  if (sort->index() == Sort::ERROR_SORT)
    {
      string fullName("`[");
      ConnectedComponent* component = sort->component();
      int nrMaxSorts = component->nrMaximalSorts();
      for (int i = 1; i <= nrMaxSorts; i++)
	{
	  fullName += Token::name(component->sort(i)->id());
	  fullName += (i == nrMaxSorts) ? "`]" : "`,";
	}
      id = Token::encode(fullName.c_str());
    }
  return upQid(id, qidMap);
}

DagNode*
MetaLevel::upJoin(int id, Sort* sort, char sep, PointerMap& qidMap)
{
  Assert(sort != 0, "null sort");
  string fullName(Token::name(id));
  fullName += sep;
  if (sort->index() == Sort::ERROR_SORT)
    {
      fullName += "`[";
      ConnectedComponent* component = sort->component();
      int nrMaxSorts = component->nrMaximalSorts();
      for (int i = 1; i <= nrMaxSorts; i++)
	{
	  fullName += Token::name(component->sort(i)->id());
	  fullName += (i == nrMaxSorts) ? "`]" : "`,";
	}
    }
  else
    fullName += Token::name(sort->id());
  return upQid(Token::encode(fullName.c_str()), qidMap);
}

inline DagNode*
MetaLevel::upConstant(int id, Sort* sort, PointerMap& qidMap)
{
  return upJoin(id, sort, '.', qidMap);
}

inline DagNode*
MetaLevel::upVariable(int id, Sort* sort, PointerMap& qidMap)
{
  return upJoin(id, sort, ':', qidMap);
}

DagNode*
MetaLevel::upDagNode(DagNode* dagNode,
		     MixfixModule* m,
		     PointerMap& qidMap,
		     PointerMap& dagNodeMap)
{
  Assert(dagNode != 0, "null dagNode");
  Vector<DagNode*> args(2);  // can't be static!
  //
  //	See if we have already up'd this dag node via a different path.
  //
  DagNode *d = static_cast<DagNode*>(dagNodeMap.getMap(dagNode));
  if (d != 0)
    return d;
  //
  //	Examine symbol to see if we have a special representation with its own
  //	conversion scheme.
  //
  Symbol* s = dagNode->symbol();
  switch (m->getSymbolType(s).getBasicType())
    {
    case SymbolType::QUOTED_IDENTIFIER:
      {
	int id = static_cast<QuotedIdentifierDagNode*>(dagNode)->getIdIndex();
	d = upConstant(Token::quoteNameCode(id), dagNode->getSort(), qidMap);
	break;
      }
    case SymbolType::STRING:
      {
	string result;
	Token::ropeToString(static_cast<StringDagNode*>(dagNode)->getValue(), result);
	d = upConstant(Token::encode(result.c_str()), dagNode->getSort(), qidMap);
	break;
      }
    case SymbolType::FLOAT:
      {
	double mf = static_cast<FloatDagNode*>(dagNode)->getValue();
	d = upConstant(Token::doubleToCode(mf), dagNode->getSort(), qidMap);
	break;
      }
    case SymbolType::VARIABLE:
      {
	int id = static_cast<VariableDagNode*>(dagNode)->id();
	d = upVariable(id, dagNode->getSort(), qidMap);
	break;
      }
    default:
      {
	int nrArgs = s->arity();
	if (nrArgs == 0)
	  d = upConstant(s->id(), dagNode->getSort(), qidMap);
	else
	  {
	    int id = s->id();
	    if (m->getSymbolType(s).hasFlag(SymbolType::ITER))
	      {
		const mpz_class& number = safeCast(S_DagNode*, dagNode)->getNumber();
		if (number > 1)
		  {
		    string tmp(Token::name(id));
		    tmp += '^';
		    char* str = mpz_get_str(0, 10, number.get_mpz_t());
		    tmp += str;
		    free(str);
		    id = Token::encode(tmp.c_str());
		  }
	      }
	    args[0] = upQid(id, qidMap);
	    DagArgumentIterator a(*dagNode);
	    if (nrArgs == 1)
	      args[1] = upDagNode(a.argument(), m, qidMap, dagNodeMap);
	    else
	      {
		Vector<DagNode*> args2(0, nrArgs);  // can't be static!
		for (; a.valid(); a.next())
		  args2.append(upDagNode(a.argument(), m, qidMap, dagNodeMap));
		args[1] = metaArgSymbol->makeDagNode(args2);
	      }
	    d = metaTermSymbol->makeDagNode(args);
	  }
	break;
      }
    }
  (void) dagNodeMap.setMap(dagNode, d);
  return d;
}

DagNode*
MetaLevel::upTerm(const Term* term, MixfixModule* m, PointerMap& qidMap)
{
  Assert(term != 0, "null term");
  Vector<DagNode*> args(2);  // can't be static!
  //
  //	Examine symbol to see if we have a special representation with its own
  //	conversion scheme.
  //

  Symbol* s = term->symbol();
  switch (m->getSymbolType(s).getBasicType())
    {
    case SymbolType::QUOTED_IDENTIFIER:
      {
	int id = static_cast<const QuotedIdentifierTerm*>(term)->getIdIndex();
	return upConstant(Token::quoteNameCode(id), term->getSort(), qidMap);
      }
    case SymbolType::STRING:
      {
	string result;
	Token::ropeToString(static_cast<const StringTerm*>(term)->getValue(), result);
	return upConstant(Token::encode(result.c_str()), term->getSort(), qidMap);
      }
    case SymbolType::FLOAT:
      {
	double mf = static_cast<const FloatTerm*>(term)->getValue();
	return upConstant(Token::doubleToCode(mf), term->getSort(), qidMap);
      }
    case SymbolType::VARIABLE:
      {
	int id = static_cast<const VariableTerm*>(term)->id();
	return upVariable(id, term->getSort(), qidMap);
      }
    default:
      {
	int nrArgs = s->arity();
	if (nrArgs == 0)
	  return upConstant(s->id(), term->getSort(), qidMap);
	else
	  {
	    int id = s->id();
	    if (m->getSymbolType(s).hasFlag(SymbolType::ITER))
	      {
		const mpz_class& number = safeCast(const S_Term*, term)->getNumber();
		if (number > 1)
		  {
		    string tmp(Token::name(id));
		    tmp += '^';
		    char* str = mpz_get_str(0, 10, number.get_mpz_t());
		    tmp += str;
		    free(str);
		    id = Token::encode(tmp.c_str());
		  }
	      }
	    args[0] = upQid(id, qidMap);
	    ArgumentIterator a(*(const_cast<Term*>(term)));
	    if (nrArgs == 1)
	      args[1] = upTerm(a.argument(), m, qidMap);
	    else
	      {
		Vector<DagNode*> args2(0, nrArgs);  // can't be static!
		for (; a.valid(); a.next())
		  args2.append(upTerm(a.argument(), m, qidMap));
		args[1] = metaArgSymbol->makeDagNode(args2);
	      }
	    return metaTermSymbol->makeDagNode(args);
	  }
      }
    }
}

DagNode*
MetaLevel::upContext(DagNode* dagNode,
		     MixfixModule* m,
		     DagNode* hole,
		     PointerMap& qidMap,
		     PointerMap& dagNodeMap)
{
  Assert(dagNode != 0, "null dagNode");
  //
  //	See if we have already up'd this dag node via a different path.
  //
  if (DagNode *d = static_cast<DagNode*>(dagNodeMap.getMap(dagNode)))
    return d;
  //
  //	See if our node is the hole.
  //
  if (dagNode == hole)
    return holeSymbol->makeDagNode();
  //
  //	Constants cannot contain the hole.
  //
  Symbol* s = dagNode->symbol();
  int nrArgs = s->arity();
  if (nrArgs == 0)
    return upDagNode(dagNode, m, qidMap, dagNodeMap);
  //
  //	Usually case.
  //
  Vector<DagNode*> args(2);  // can't be static!
  args[0] = upQid(s->id(), qidMap);
  DagArgumentIterator a(*dagNode);
  if (nrArgs == 1)
    args[1] = upContext(a.argument(), m, hole, qidMap, dagNodeMap);
  else
    {
      Vector<DagNode*> args2(0, nrArgs);  // can't be static!
      for (; a.valid(); a.next())
	args2.append(upContext(a.argument(), m, hole, qidMap, dagNodeMap));
      args[1] = metaArgSymbol->makeDagNode(args2);
    }
  DagNode* d = metaTermSymbol->makeDagNode(args);
  (void) dagNodeMap.setMap(dagNode, d);
  return d;
}

DagNode*
MetaLevel::upResultPair(DagNode* dagNode, MixfixModule* m)
{
  Assert(dagNode != 0, "null dagNode");
  static Vector<DagNode*> args(2);
  PointerMap qidMap;
  PointerMap dagNodeMap;
  args[0] = upDagNode(dagNode, m, qidMap, dagNodeMap);
  args[1] = upType(dagNode->getSort(), qidMap);
  return resultPairSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upResultPair(Term* term, MixfixModule* m)
{
  Assert(term != 0, "null term");
  static Vector<DagNode*> args(2);
  PointerMap qidMap;
  args[0] = upTerm(term, m, qidMap);
  args[1] = upType(term->getSort(), qidMap);
  return resultPairSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upResultTriple(DagNode* dagNode,
			  const Substitution& substitution,
			  const VariableInfo& variableInfo,
			  MixfixModule* m)
{
  Assert(dagNode != 0, "null dagNode");
  static Vector<DagNode*> args(3);
  PointerMap qidMap;
  PointerMap dagNodeMap;
  args[0] = upDagNode(dagNode, m, qidMap, dagNodeMap);
  args[1] = upType(dagNode->getSort(), qidMap);
  args[2] = upSubstition(substitution, variableInfo, m, qidMap, dagNodeMap);
  return resultTripleSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upResult4Tuple(DagNode* dagNode,
			  const Substitution& substitution,
			  const VariableInfo& variableInfo,
			  DagNode* metaContext,
			  MixfixModule* m)
{
  Assert(dagNode != 0, "null dagNode");
  static Vector<DagNode*> args(4);
  PointerMap qidMap;
  PointerMap dagNodeMap;
  args[0] = upDagNode(dagNode, m, qidMap, dagNodeMap);
  args[1] = upType(dagNode->getSort(), qidMap);
  args[2] = upSubstition(substitution, variableInfo, m, qidMap, dagNodeMap);
  args[3] = metaContext;
  return result4TupleSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upSubstition(const Substitution& substitution,
			const VariableInfo& variableInfo,
			MixfixModule* m,
			PointerMap& qidMap,
			PointerMap& dagNodeMap)
{
  int nrVariables = variableInfo.getNrRealVariables();
  if (nrVariables == 0)
    return emptySubstitutionSymbol->makeDagNode();
  if (nrVariables == 1)
    {
      return upAssignment(variableInfo.index2Variable(0),
			  substitution.value(0),
			  m,
			  qidMap,
			  dagNodeMap);
    }
  Vector<DagNode*> args(nrVariables);
  for (int i = 0; i < nrVariables; i++)
    {
      args[i] = upAssignment(variableInfo.index2Variable(i),
			     substitution.value(i),
			     m,
			     qidMap,
			     dagNodeMap);
    }
  return substitutionSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upAssignment(const Term* variable,
			DagNode* value,
			MixfixModule* m,
			PointerMap& qidMap,
			PointerMap& dagNodeMap)
{
  static Vector<DagNode*> args(2);
  args[0] = upTerm(variable, m, qidMap);
  args[1] = upDagNode(value, m, qidMap, dagNodeMap);
  return assignmentSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upFailureTriple()
{
  return failure3Symbol->makeDagNode();
}

DagNode*
MetaLevel::upNoMatchSubst()
{
  return noMatchSubstSymbol->makeDagNode();
}

DagNode*
MetaLevel::upNoMatchPair()
{
  return noMatchPairSymbol->makeDagNode();
}

DagNode*
MetaLevel::upMatchPair(const Substitution& substitution,
		       const VariableInfo& variableInfo,
		       DagNode* dagNode,
		       DagNode* hole,
		       MixfixModule* m)
{
  PointerMap qidMap;
  PointerMap dagNodeMap;
  static Vector<DagNode*> args(2);
  args[0] = upSubstition(substitution, variableInfo, m, qidMap, dagNodeMap);
  args[1] = upContext(dagNode, m, hole, qidMap, dagNodeMap);
  return matchPairSymbol->makeDagNode(args);
}


DagNode*
MetaLevel::upFailure4Tuple()
{
  return failure4Symbol->makeDagNode();
}

DagNode*
MetaLevel::upNoParse(int badTokenIndex)
{
  static Vector<DagNode*> args(1);
  args[0] = succSymbol->makeNatDag(badTokenIndex);
  return noParseSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upAmbiguity(Term* parse1, Term* parse2, MixfixModule* m)
{
  Assert(parse1 != 0 && parse2 != 0, "null term");
  static Vector<DagNode*> args(2);
  static Vector<DagNode*> args2(2);
  PointerMap qidMap;
  args[0] = upTerm(parse1, m, qidMap);
  args[1] = upType(parse1->getSort(), qidMap);
  args2[0] = resultPairSymbol->makeDagNode(args);
  args[0] = upTerm(parse2, m, qidMap);
  args[1] = upType(parse2->getSort(), qidMap);
  args2[1] = resultPairSymbol->makeDagNode(args);
  return ambiguitySymbol->makeDagNode(args2);
}

DagNode*
MetaLevel::upBool(bool value)
{
  return value ? trueTerm.getDag() : falseTerm.getDag();
}

DagNode*
MetaLevel::upSortSet(const Vector<Sort*>& sorts)
{
  int nrSorts = sorts.length();
  if (nrSorts == 0)
    return new FreeDagNode(emptySortSetSymbol);
  if (nrSorts == 1)
    return new QuotedIdentifierDagNode(qidSymbol,
				       Token::backQuoteSpecials(sorts[0]->id()));
  Vector<DagNode*> args(nrSorts);
  for (int i = 0; i < nrSorts; i++)
    {
      args[i] = new QuotedIdentifierDagNode(qidSymbol,
					    Token::backQuoteSpecials(sorts[i]->id()));
    }
  return sortSetSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upKindSet(const Vector<ConnectedComponent*>& kinds)
{
  int nrKinds = kinds.length();
  if (nrKinds == 0)
    return new FreeDagNode(emptyKindSetSymbol);
  PointerMap qidMap;
  if (nrKinds == 1)
    return upType(kinds[0]->sort(0), qidMap);
  Vector<DagNode*> args(nrKinds);
  for (int i = 0; i < nrKinds; i++)
    args[i] = upType(kinds[i]->sort(0), qidMap);
  return kindSetSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upQidList(const Vector<int>& ids)
{
  int nrIds = ids.length();
  if (nrIds == 0)
    return new FreeDagNode(nilQidListSymbol);
  if (nrIds == 1)
    return new QuotedIdentifierDagNode(qidSymbol, Token::backQuoteSpecials(ids[0]));
  PointerMap qidMap;
  Vector<DagNode*> args(nrIds);
  for (int i = 0; i < nrIds; i++)
    args[i] = upQid(ids[i], qidMap);
  return qidListSymbol->makeDagNode(args);
}
