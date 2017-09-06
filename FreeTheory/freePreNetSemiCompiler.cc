//
//	Code to construct a FreeNet from a FreePreNet.
//
int
FreePreNet::semiCompileNode(FreeNet& freeNet, int nodeNr, const SlotMap& slotMap)
{
  Node& n = net[nodeNr];
  if (n.freeNetIndex != UNBOUNDED)
    return n.freeNetIndex;
  if (n.reducedFringe.empty())
    {
      //
      //	Remainder node.
      //
      patternsUsed.insert(n.liveSet);
      n.freeNetIndex = freeNet.addRemainderList(n.liveSet);
      return n.freeNetIndex;
    }
  else
    {
      //
      //	Test node.
      //
      const Vector<int>& testPosition = positions.index2Position(n.testPositionIndex);
      setVisitedFlags(n.liveSet, testPosition, true);

      int nrMatchArcs = n.sons.length();
      n.freeNetIndex = freeNet.allocateNode(nrMatchArcs);

      Vector<Symbol*> symbols(nrMatchArcs);
      Vector<int> targets(nrMatchArcs);
      Vector<int> saveSlots(nrMatchArcs);
     
      for (int i = 0; i < nrMatchArcs; i++)
	{
	  Symbol* symbol = n.sons[i].label;
	  int target = n.sons[i].target;
	  Assert(symbol != 0, "null symbol");
	  symbols[i] = symbol;
	  if (dynamic_cast<FreeSymbol*>(symbol) != 0 && symbol->arity() > 0)
	    {
	      int slot = allocateSlot(net[target].liveSet, testPosition, symbol);
	      SlotMap newMap(slotMap);
	      newMap[n.testPositionIndex] = slot;
	      targets[i] = semiCompileNode(freeNet, target, newMap);
	      saveSlots[i] = slot;
	    }
	  else
	    {
	      targets[i] = semiCompileNode(freeNet, target, slotMap);
	      saveSlots[i] = NONE;
	    }
	}
      int neqTarget = (n.neqTarget == NONE) ? 0 :
	semiCompileNode(freeNet, n.neqTarget, slotMap);

      int parentIndex = positions.parentIndex(n.testPositionIndex);
      SlotMap::const_iterator i = slotMap.find(parentIndex);
      Assert(i != slotMap.end(), "missing slot");
      freeNet.fillOutNode(n.freeNetIndex,
			  (*i).second,
			  testPosition[testPosition.length() - 1],
			  symbols,
			  targets,
			  saveSlots,
			  neqTarget);

      setVisitedFlags(n.liveSet, testPosition, false);
      return n.freeNetIndex;
    }
}

void
FreePreNet::semiCompile(FreeNet& freeNet)
{
  int nrNodes = net.length();
  if (nrNodes == 0)
    return;
  for (int i = 0; i < nrNodes; i++)
    net[i].freeNetIndex = UNBOUNDED;  // can't use NONE because of negatives

  SlotMap init;
  init[topPositionIndex] = slots.makeElement();  // allocate slot 0 to start everything off
  conflicts.resize(1);  // slot 0 has no conflicts
  
  semiCompileNode(freeNet, 0, init);

  Vector<int> slotTranslation;
  int nrRealSlots = buildSlotTranslation(slotTranslation);
  freeNet.translateSlots(nrRealSlots, slotTranslation);
  freeNet.buildRemainders(topSymbol->getEquations(), patternsUsed, slotTranslation);
}

void
FreePreNet::setVisitedFlags(const NatSet& liveSet,
			    const Vector<int>& position,
			    bool state)
{
  const NatSet::const_iterator e = liveSet.end();
  for (NatSet::const_iterator i = liveSet.begin(); i != e; ++i)
    {
      if (FreeTerm* f = dynamic_cast<FreeTerm*>(patterns[*i].term))
	{
	  Term* t = f->locateSubterm(position);
	  if (t != 0 && (f = dynamic_cast<FreeTerm*>(t)) != 0)
	    f->setVisitedFlag(state);
	}
    }
}

int
FreePreNet::allocateSlot(const NatSet& liveSet,
			 const Vector<int>& position,
			 Symbol* symbol)
{
  int slot = slots.makeElement();
  conflicts.expandBy(1);
  Assert(slot == conflicts.length() - 1,
	 "slot/conflict data structures out of sync");

  // cerr << symbol << endl;
  const NatSet::const_iterator e = liveSet.end();
  for (NatSet::const_iterator i = liveSet.begin(); i != e; ++i)
    {
      // cerr << patterns[*i].term << endl;
      if (FreeTerm* f = dynamic_cast<FreeTerm*>(patterns[*i].term))
	{
	  Term* t = f->locateSubterm(position);
	  if (t != 0 && t->symbol() == symbol)
	    {
	      FreeTerm* ft = safeCast(FreeTerm*, t);
	      int originalSlot = ft->getSlotIndex();
	      if (originalSlot == NONE)
		ft->setSlotIndex(slot);
	      else
		slots.formUnion(slot, originalSlot);
	    }
	  f->findActiveSlots(conflicts[slot]);
	}
    }
  return slot;
}

int
FreePreNet::buildSlotTranslation(Vector<int>& slotTranslation)
{
  int nrSlots = slots.elementCount();
  slotTranslation.expandTo(nrSlots);
  for (int i = 0; i < nrSlots; i++)
    slotTranslation[i] = NONE;
  //
  //	Build initial slot translation by collapsing slots that must be
  //	equivalent and numbering them 0...nrUnique-1
  //
  int nrUnique = 0;
  for (int i = 0; i < nrSlots; i++)
    {
      if (slotTranslation[i] == NONE)
	{
	  int rep = slots.findRep(i);
	  int repTrans = slotTranslation[rep];
	  if (repTrans == NONE)
	    slotTranslation[rep] = repTrans = nrUnique++;
	  slotTranslation[i] = repTrans;
	}
    }
  Assert(slotTranslation[0] == 0, "initial translation failed to preserve slot 0");
  //
  //	Now build final slot translation by using graph coloring to collapse
  //	non-conflicting slots and numbering them 0...nrColors-1
  //
  Graph graph(nrUnique);
  Vector<int> coloring(nrUnique);
  for (int i = 0; i < nrSlots; i++)
    {
      int iTrans = slotTranslation[i];
      const NatSet::const_iterator e = conflicts[i].end();
      for (NatSet::const_iterator j = conflicts[i].begin(); j != e; ++j)
	{
	  int cTrans = slotTranslation[*j];
	  if (iTrans != cTrans)
	    graph.insertEdge(iTrans, cTrans);
	}
    }
  int nrColors = graph.color(coloring);
  for (int i = 0; i < nrSlots; i++)
    slotTranslation[i] = coloring[slotTranslation[i]];
  Assert(slotTranslation[0] == 0, "final translation failed to preserve slot 0");
  return nrColors;
}
