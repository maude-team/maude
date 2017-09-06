//
//	Routines for pretty printing a dag as a term graph.
//

void
MixfixModule::graphPrint(ostream& s, DagNode* dagNode)
{
  PointerSet visited;
  Vector<mpz_class> counts;
  graphCount(dagNode, visited, counts);
  s << "Begin{Graph Representation}\n[Term has " << counts[0] <<
    " operator symbol" << (counts[0] == 1 ? "" : "s") <<
    " while graph has " << visited.cardinality() <<
    " node" << pluralize(visited.cardinality()) << ".]\n";
  int nrNodes = visited.cardinality();
  for (int i = 0; i < nrNodes; i++)
    {
      if (UserLevelRewritingContext::interrupted())
	return;
      s << '#' << i << " = ";
      DagNode* dagNode = static_cast<DagNode*>(visited.index2Pointer(i));
      Symbol* symbol = dagNode->symbol();
      SymbolType type = symbolInfo[symbol->getIndexWithinModule()].symbolType;
      switch (type.getBasicType())
	{
	case SymbolType::VARIABLE:
	  {
	    VariableDagNode* v = safeCast(VariableDagNode*, dagNode);
	    printVariable(s, v->id(), safeCast(VariableSymbol*, symbol)->getSort());
	    break;
	  }
	case SymbolType::FLOAT:
	  {
	    s << doubleToString(safeCast(FloatDagNode*, dagNode)->getValue());
	    break;
	  }
	case SymbolType::STRING:
	  {
	    string strValue;
	    Token::ropeToString(safeCast(StringDagNode*, dagNode)->getValue(), strValue);
	    s << strValue;
	    break;
	  }
	case SymbolType::QUOTED_IDENTIFIER:
	  {
	    s << '\'' << Token::name(safeCast(QuotedIdentifierDagNode*, dagNode)->getIdIndex());
	    break;
	  }
	default:
	  {
	    s << Token::name(symbol->id());
	    if (type.hasFlag(SymbolType::ITER))
	      {
		const mpz_class& number = safeCast(S_DagNode*, dagNode)->getNumber();
		if (number > 1)
		  s << '^' << number;
	      }
	    DagArgumentIterator a(*dagNode);
	    if (a.valid())
	      {
		s << '(';
		for (;;)
		  {
		    s << '#' << visited.pointer2Index(a.argument());
		    a.next();
		    if (!(a.valid()))
		      break;
		    s << ", ";
		  }
		s << ')';
	      }
	    break;
	  }
	}
      s << '\n';
    }
  s << "End{Graph Representation}";
}

void
MixfixModule::graphCount(DagNode* dagNode, PointerSet& visited, Vector<mpz_class>& counts)
{
  visited.insert(dagNode);
  int index = counts.length();
  Assert(index == visited.pointer2Index(dagNode), "counts out of step");
  counts.append(0);
 
  mpz_class count(1);
  for(DagArgumentIterator a(*dagNode); a.valid(); a.next())
    {
      DagNode* d = a.argument();
      if (!(visited.contains(d)))
        graphCount(d, visited, counts);
      mpz_class& childsCount = counts[visited.pointer2Index(d)];
      Assert(childsCount != 0, "cycle in dag");
      count += childsCount;
    }
  counts[index] = count;
}
