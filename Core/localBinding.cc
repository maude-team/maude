//
//      Implementation for class Substitution
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"
//#include "variable.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//      core class definitions
#include "variableInfo.hh"
#include "substitution.hh"
#include "localBinding.hh"

LocalBinding::LocalBinding(int maxSize) : bindings(0, maxSize)
{
}

void
LocalBinding::markReachableNodes()
{
  int nrBindings = bindings.length();
  for (int i = 0; i < nrBindings; i++)
    {
      Assert(bindings[i].value != 0, cerr << "null local binding at index " << i);
      bindings[i].value->mark();
    }
}

void
LocalBinding::addBinding(int index, DagNode* value)
{
  int t = bindings.length();
  bindings.expandBy(1);
  bindings[t].variableIndex = index;
  bindings[t].value = value;
  bindings[t].active = false;
}

bool
LocalBinding::assert(Substitution& substitution)
{
  int nrBindings = bindings.length();
  for (int i = 0; i < nrBindings; i++)
    {
      DagNode* d = substitution.value(bindings[i].variableIndex);
      if (d != 0 && !(d->equal(bindings[i].value)))
        return false;
    }
  for (int i = 0; i < nrBindings; i++)
    {
      int index = bindings[i].variableIndex;
      if (substitution.value(index) == 0)
	{
	  substitution.bind(index, bindings[i].value);
	  bindings[i].active = true;
	}
    }
  return true;
}

void
LocalBinding::retract(Substitution& substitution)
{
  int nrBindings = bindings.length();
  for (int i = 0; i < nrBindings; i++)
    {
      if (bindings[i].active)
        {
          bindings[i].active = false;
          substitution.bind(bindings[i].variableIndex, 0);
        }
    }
}

#ifdef DUMP
void
LocalBinding::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel) const
{
  s << Indent(indentLevel) << "Begin{LocalBinding}\n";
  ++indentLevel;
  //  s << Indent(indentLevel) << "this = " << this << "\tprev = " << prev <<
  //  "\tnext = " << next << '\n';
  int nrBindings = bindings.length();
  for (int i = 0; i < nrBindings; i++)
    {
      int index = bindings[i].variableIndex;
      s << Indent(indentLevel) << "index = " << index <<
	" \"" << variableInfo.index2Variable(index) <<
	"\"\tvalue = " << bindings[i].value << "\t(";
      if (!(bindings[i].active))
	s << "not ";
      s << "active)\n";
    }
  s << Indent(indentLevel - 1) << "End{LocalBinding}\n";
}
	
 
void
LocalBinding::dump(ostream& s, const VariableInfo* variableInfo) const
{
  s << "Dumping LocalBinding (" << this << ")\n";
  //  s << "prev = " << prev << "\tnext = " << next << '\n';
  int nrBindings = bindings.length();
  for (int i = 0; i < nrBindings; i++)
    {
      if (variableInfo != 0)
	s << variableInfo->index2Variable(bindings[i].variableIndex);
      else
	s << "index:" << bindings[i].variableIndex;
      s << "\t=\t" << bindings[i].value << "\t(";
      if (!(bindings[i].active))
	s << "not ";
      s << "active)\n";
    }
}
#endif
