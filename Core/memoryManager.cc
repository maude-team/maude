//
//	Allocation and garbage collection routines.
//

const int
DagNode::dagNodeSize = sizeof(DagNode::DummyDagNode) / sizeof(DagNode::Word);

struct DagNode::Arena
{
  union
  {
    Arena* nextArena;
    Int64 alignmentDummy;  // force 8 byte alignment for DagNode objects
  };
  Word storage[ARENA_SIZE * dagNodeSize];
  DummyDagNode* firstNode();
};

inline DagNode::DummyDagNode*
DagNode::Arena::firstNode()
{
  return reinterpret_cast<DummyDagNode*>(storage);
}

bool DagNode::showGC = false;
//
//	Arena management variables.
//
int DagNode::nrArenas = 0;
int DagNode::nrNodesInUse = 0;
bool DagNode::currentArenaPastActiveArena = true;
bool DagNode::needToCollectGarbage = false;
DagNode::Arena* DagNode::firstArena = 0;
DagNode::Arena* DagNode::lastArena = 0;
DagNode::Arena* DagNode::currentArena = 0;
DagNode::DummyDagNode* DagNode::nextNode = 0;
DagNode::DummyDagNode* DagNode::endPointer = 0;
DagNode::Arena* DagNode::lastActiveArena = 0;
DagNode::DummyDagNode* DagNode::lastActiveNode = 0;
//
//	Bucket management variables.
//
int DagNode::nrBuckets = 0;
DagNode::Bucket* DagNode::bucketList = 0;
DagNode::Bucket* DagNode::unusedList = 0;
size_t DagNode::bucketStorage = 0;
size_t DagNode::storageInUse = 0;
size_t DagNode::target = INITIAL_TARGET;

DagNode::Arena*
DagNode::allocateNewArena()
{
#ifdef GC_DEBUG
  cerr << "allocateNewArena()\n";
  dumpMemoryVariables(cerr);
#endif
  Arena* a = new Arena;
  a->nextArena = 0;
  if (lastArena == 0)
    firstArena = a;
  else
    lastArena->nextArena = a;
  lastArena = a;
  DummyDagNode* d = a->firstNode();
  for (int i = 0; i < ARENA_SIZE; i++, d++)
    d->flags = 0;
  ++nrArenas;
  return a;
}

void*
DagNode::slowNew()
{
#ifdef GC_DEBUG
  cerr << "slowNew()\n";
  dumpMemoryVariables(cerr);
#endif
  for(;;)
    {
      if (currentArena == 0)
	{
	  //
	  //	Allocate first arena.
	  //
	  currentArena = allocateNewArena();
	  DummyDagNode* d = currentArena->firstNode();
	  endPointer = d + ARENA_SIZE - RESERVE_SIZE;
	  nextNode = d + 1;
	  Assert(d->flags == 0, cerr << "flags not cleared");
	  return d;
	}
      Arena* a = currentArena->nextArena;
      if (a == 0)
	{
	  needToCollectGarbage = true;
	  DummyDagNode* e = currentArena->firstNode() + ARENA_SIZE;
	  if (endPointer != e)
	    {
	      //
	      //	Use up reserve.
	      //
	      nextNode = endPointer;  // nextNode is invalid where we are called
	      endPointer = e;
	    }
	  else
	    {
	      //
	      //	Allocate a new arena.
	      //
	      if (currentArena == lastActiveArena)
		currentArenaPastActiveArena = true;
	      currentArena = allocateNewArena();
	      DummyDagNode* d = currentArena->firstNode();
	      endPointer = d + ARENA_SIZE;
	      nextNode = d + 1;
	      Assert(d->flags == 0, cerr << "flags not cleared");
	      return d;
	    }
	}
      else
	{
	  //
	  //	Use next arena.
	  //
	  if (currentArena == lastActiveArena)
	    currentArenaPastActiveArena = true;
	  currentArena = a;
	  nextNode = a->firstNode();
	  endPointer = nextNode +
	    ((a->nextArena != 0) ? ARENA_SIZE : ARENA_SIZE - RESERVE_SIZE);
	}
      //
      //	Now execute lazy sweep to actually find a free location
      //
#ifdef GC_DEBUG
      checkInvariant();
#endif
      DummyDagNode* e = endPointer;
      for (DummyDagNode* d = nextNode; d != e; d++)
	{
	  if ((d->flags & (MARKED | CALL_DTOR)) == 0)
	    {
	      nextNode = d + 1;
	      d->flags = 0;
	      return static_cast<void*>(d);
	    }
	  if ((d->flags & MARKED) == 0)
	    {
	      (static_cast<DagNode*>(d))->~DagNode();
	      nextNode = d + 1;
	      d->flags = 0;
	      return static_cast<void*>(d);
	    }
	  d->flags &= ~MARKED;
	}
    }
}

void*
DagNode::slowAllocateStorage(size_t bytesNeeded)
{
  Bucket* p = 0;
  for (Bucket* b = unusedList; b; p = b, b = b->nextBucket)
    {
      if (b->bytesFree >= bytesNeeded)
	{
	  //
	  //	Move b from unused list to bucket list
	  //
	  if (p == 0)
	    unusedList = b->nextBucket;
	  else
	    p->nextBucket = b->nextBucket;
	  b->nextBucket = bucketList;
	  bucketList = b;
	  //
	  //	Allocate storage from b
	  //
	  b->bytesFree -= bytesNeeded;
	  void* t = b->nextFree;
	  b->nextFree = static_cast<char*>(t) + bytesNeeded;
	  return t;
	}
    }
  //
  //	Create new bucket
  //
  size_t size = BUCKET_MULTIPLIER * bytesNeeded;
  if (size < MIN_BUCKET_SIZE)
    size = MIN_BUCKET_SIZE;

  Bucket* b = static_cast<Bucket*>(operator new[](size));
  ++nrBuckets;
  void* t = b + 1;
  size_t nrBytes = size - sizeof(Bucket);
  bucketStorage += nrBytes;
  b->nrBytes = nrBytes;
  b->bytesFree = nrBytes - bytesNeeded;
  b->nextFree = static_cast<char*>(t) + bytesNeeded;
  b->nextBucket = bucketList;
  bucketList = b;
  return t;
}

void
DagNode::tidyArenas()
{
#ifdef GC_DEBUG
  cerr << "tidyArenas()\n";
  dumpMemoryVariables(cerr);
#endif
  //
  //	Tidy up lazy sweep phase - clear marked flags and call dtors
  //	where necessary.
  //
  Arena* newLastActiveArena = currentArena;
  DummyDagNode* newLastActiveNode = nextNode - 1;  // nextNode never points to first node

  if (!currentArenaPastActiveArena)
    {
      //
      //	First tidy arenas from current up to lastActive.
      //
    DummyDagNode* d = nextNode;
    Arena* c = currentArena;
    for (; c != lastActiveArena; c = c->nextArena, d = c->firstNode())
      {
	DummyDagNode* e = c->firstNode() + ARENA_SIZE;
	for (; d != e; d++)
	  {
	    if (d->flags & MARKED)
	      {
		newLastActiveArena = c;
		newLastActiveNode = d;
		d->flags &= ~MARKED;
	      }
	    else
	      {
		if (d->flags & CALL_DTOR)
		  (static_cast<DagNode*>(d))->~DagNode();
		d->flags = 0;
	      }
	  }
      }
    //
    //	Now tidy lastActiveArena from d upto and including lastActiveNode.
    //
    DummyDagNode* e = lastActiveNode;
    for(; d <= e; d++)
      {
	if (d->flags & MARKED)
	  {
	    newLastActiveArena = c;
	    newLastActiveNode = d;
	    d->flags &= ~MARKED;
	  }
	else
	  {
	    if (d->flags & CALL_DTOR)
	      (static_cast<DagNode*>(d))->~DagNode();
	    d->flags = 0;
	  }
      }
    }

  lastActiveArena = newLastActiveArena;
  lastActiveNode = newLastActiveNode;
}

void
DagNode::collectGarbage()
{
  if (firstArena == 0)
    return;
  tidyArenas();
#ifdef GC_DEBUG
  checkArenas();
#endif
  //
  //	Mark phase
  //
  nrNodesInUse = 0;
  size_t oldStorageInUse = storageInUse;
  Bucket* b = bucketList;
  bucketList = unusedList;
  unusedList = 0;
  storageInUse = 0;

  RootContainer::markPhase();

  unusedList = b;
  for (; b; b = b->nextBucket)
    {
      b->bytesFree = b->nrBytes;
      b->nextFree = b + 1;  // reset
    }
  size_t newTarget = TARGET_MULTIPLIER * storageInUse;
  if (target < newTarget)
    target = newTarget;
  //
  //	Calculate if we should allocate more arenas to avoid an early gc.
  //
  int nrNodes = nrArenas * ARENA_SIZE;
  if (showGC)
    {
      cout << "Arenas: " << nrArenas <<
	"\tNodes: " << nrNodes <<
	//	"\tIn use: " << nrNodesInUse <<
	//	"\tCollected: " << reclaimed << 
	"\tNow: " << nrNodesInUse <<
	"\nBuckets: " << nrBuckets <<
	"\tBytes: " << bucketStorage <<
	"\tIn use: " << oldStorageInUse <<
	"\tCollected: " << oldStorageInUse - storageInUse <<
	"\tNow: " << storageInUse << '\n';
    }
  //
  //	Allocate new arenas so that we have at least 50% of nodes unused.
  //
  int neededArenas = ceilingDivision(2 * nrNodesInUse, ARENA_SIZE);
  while (nrArenas < neededArenas)
    (void) allocateNewArena();
  //
  //	Reset node stuff.
  //
  currentArenaPastActiveArena = false;
  currentArena = firstArena;
  nextNode = currentArena->firstNode();
  endPointer = nextNode +
    ((firstArena->nextArena != 0) ? ARENA_SIZE : ARENA_SIZE - RESERVE_SIZE);
  needToCollectGarbage = false;
#ifdef GC_DEBUG
  // stompArenas();
  cerr << "end of GC\n";
  dumpMemoryVariables(cerr);
#endif
}

#ifdef GC_DEBUG
void
DagNode::stompArenas()
{
  for (Arena* a = firstArena; a != 0; a = a->nextArena)
    {
      DummyDagNode* d = a->firstNode();
      for (int i = 0; i < ARENA_SIZE; i++, d++)
	{
	  if (!(d->flags & MARKED) && !(d->flags & CALL_DTOR))
	    d->topSymbol = reinterpret_cast<Symbol*>(0x33);
	}
    }
}

void
DagNode::checkArenas()
{
  int n = 0;
  for (Arena* a = firstArena; a != 0; a = a->nextArena, n++)
    {
      DummyDagNode* d = a->firstNode();
      for (int i = 0; i < ARENA_SIZE; i++, d++)
	{
	  if (d->flags & MARKED)
	    {
	      cerr << "checkArenas(): MARKED DagNode! arena = " <<
		n << " node = " << i << '\n';
	    }
	}
    }
}

void
DagNode::checkInvariant()
{
  int n = 0;
  for (Arena* a = firstArena;; a = a->nextArena, n++)
    {
      DummyDagNode* d = a->firstNode();
      int bound = (a == currentArena) ? nextNode - d : ARENA_SIZE;
      for (int i = 0; i < bound; i++, d++)
	{
	  if (d->flags & MARKED)
	    {
	      cerr << "checkInvariant() : MARKED DagNode! arena = " <<
		n << " node = " << i << '\n';
	    }
	}
      if (a == currentArena)
	break;
    }
}

void
DagNode::dumpMemoryVariables(ostream& s)
{
  s << "nrArenas = " << nrArenas <<
    "\nnrNodesInUse = " << nrNodesInUse <<
    "\ncurrentArenaPastActiveArena = " << currentArenaPastActiveArena <<
    "\nneedToCollectGarbage = " << needToCollectGarbage <<
    "\nfirstArena = " << firstArena <<
    "\nlastArena = " << lastArena <<
    "\ncurrentArena = " << currentArena <<
    "\nnextNode = " << static_cast<void*>(nextNode) <<
    "\nendPointer = " << static_cast<void*>(endPointer) <<
    "\nlastActiveArena = " << lastActiveArena <<
    "\nlastActiveNode = " << static_cast<void*>(lastActiveNode) <<
    "\n\n";
}
#endif
