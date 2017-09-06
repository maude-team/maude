//
//      Class to generate MaudeML from Maude internal data structures.
//
#ifndef _maudemlBuffer_hh_
#define _maudemlBuffer_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "xmlBuffer.hh"

class MaudemlBuffer : public XmlBuffer
{
  NO_COPYING(MaudemlBuffer);

public:
  MaudemlBuffer(ostream& output);

  void generateShowSearchPath(int stateNr);
  void generateShowSearchGraph();
  void generateReduce(DagNode* subject);
  void generateRewrite(DagNode* subject, Int64 limit);
  void generateFrewrite(DagNode* subject, Int64 limit, Int64 gas);
  void generateSearch(DagNode* subject,
		      PreEquation* pattern,
		      const string& searchType,
		      Int64 limit);
  void generateContinue(const string& command, Module* module, Int64 limit);
  void generateSearchResult(Int64 number,
			    RewriteSequenceSearch* state,
			    const Timer& timer,
			    bool showStats,
			    bool showTiming,
			    bool showBreakdown);
  void generateSubstitution(const Substitution* substitution,
			    const VariableInfo* varInfo);
  void generateAssignment(Term* variable, DagNode* value);
  // void generateShow(const string& item, Module* module = 0);

  void generate(Term* term);
  void generate(const ConditionFragment* c);
  void generate(Rule* rule);
  void generate(DagNode* dagNode, PointerSet* visited = 0);
  void generateSearchGraph(RewriteSequenceSearch* graph);
  void generateSearchPath(RewriteSequenceSearch* graph, int stateNr);
  void generateCondition(const Vector<ConditionFragment*>& condition);
  void generateResult(RewritingContext& context,
		      const Timer& timer,
		      bool showStats,
		      bool showTiming,
		      bool showBreakdown);

private:
  static string sortString(Sort* sort);
  static string kindString(ConnectedComponent* kind);

  void generateStats(RewritingContext& context,
		     const Timer& timer,
		     bool showTiming,
		     bool showBreakdown);
};

#endif
