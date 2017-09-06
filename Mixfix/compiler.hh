//
//      Class to manage on-the-fly compilation of modules.
//
#ifndef _compiler_hh_
#define _compiler_hh_
#ifdef __GNUG__
#pragma interface
#endif

class Compiler
{
  NO_COPYING(Compiler);

public:
  Compiler();
  ~Compiler();

  bool makeExecutable(PreModule* module, bool countRewrites);
  void runExecutable();
  DagNode* inputGraph(Int64& nrRewrites, Int64& cpu, Int64& real);
  void invalidate(PreModule* module);

  static void outputGraph(DagNode* dagNode);

private:
  static const string& makeBaseName();
  static void depthFirstTraversal(DagNode* dagNode, PointerSet& visited);

  bool fullCompile(PreModule* module, bool countRewrites);

  PreModule* currentExecutable;
  bool compiledWithCount;
  int currentNrSymbols;
};

#endif

