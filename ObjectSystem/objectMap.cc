//
//	Map from object identifier to (object, message queue) pairs.
//

struct ConfigSymbol::MessageQueue
{
  MessageQueue();

  void markReachableNodes() const;

  DagNode* object;
  list<DagNode*> messages;
};

ConfigSymbol::MessageQueue::MessageQueue()
{
  object = 0;
}

void
ConfigSymbol::MessageQueue::markReachableNodes() const
{
  if (object != 0)
    object->mark();
  FOR_EACH_CONST(i, list<DagNode*>, messages)
    (*i)->mark();
}

struct ConfigSymbol::dagNodeLt
{
  bool operator()(const DagNode* d1, const DagNode* d2)
    {
      return d1->compare(d2) < 0;
    }
};

class ConfigSymbol::ObjectMap
 : public map<DagNode*, MessageQueue, dagNodeLt>,
   private SimpleRootContainer
{
public:
  void dump(ostream& s, int indentLevel = 0);

private:
  void markReachableNodes();
};

void
ConfigSymbol::ObjectMap::markReachableNodes()
{
  FOR_EACH_CONST(i, ObjectMap, *this)
    i->second.markReachableNodes();
}

void
ConfigSymbol::ObjectMap::dump(ostream& s, int indentLevel)
{
  s << Indent(indentLevel) << "begin{ObjectMap}\n";
  FOR_EACH_CONST(i, ObjectMap, *this)
    {
      s << Indent(indentLevel + 1) << i->first << '\n';
      if (i->second.object == 0)
	s << Indent(indentLevel + 2) << "*** NO OBJECT ***\n";
      else
	s << Indent(indentLevel + 2) << i->second.object << '\n';
      FOR_EACH_CONST(j, list<DagNode*>, i->second.messages)
	s << Indent(indentLevel + 2) << *j << '\n';
      s << '\n';
    }
  s << Indent(indentLevel) << "end{ObjectMap}\n";
}
