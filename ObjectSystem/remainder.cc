//
//	Container for leftover args during object-message rewriting.
//

struct ConfigSymbol::Remainder : private SimpleRootContainer
{
  void dump(ostream& s, int indentLevel = 0);

  Vector<DagNode*> dagNodes;
  Vector<int> multiplicities;

private:
  void markReachableNodes();
};

void
ConfigSymbol::Remainder::markReachableNodes()
{
  FOR_EACH_CONST(i, Vector<DagNode*>, dagNodes)
    (*i)->mark();
}

void
ConfigSymbol::Remainder::dump(ostream& s, int indentLevel)
{
  s << Indent(indentLevel) << "begin{Remainder}\n";
  int nrRem = dagNodes.length();
  for (int i = 0; i < nrRem; ++i)
    {
      s << Indent(indentLevel + 1) << multiplicities[i] << '\t' <<
	dagNodes[i] << '\n';
    }
  s << Indent(indentLevel) << "end{Remainder}\n";
}
