//
//	Abstract class for table of equations indexed under some symbol.
//
#ifndef _equationTable_hh_
#define _equationTable_hh_

class EquationTable
{
public:
  void offerEquation(Equation* equation);
  const Vector<Equation*>& getEquations() const;
  bool equationFree() const;
  virtual void compileEquations();
  //virtual bool eqRewrite(DagNode* subject, RewritingContext& context) = 0;

protected:
  virtual bool acceptEquation(Equation* equation) = 0;
  bool applyReplace(DagNode* subject,
		    RewritingContext& context,
		    ExtensionInfo* extensionInfo = 0);

#ifdef DUMP
  virtual void dumpEquationTable(ostream& s, int indentLevel);
#endif

private:
  Vector<Equation*> equations;
};

inline void
EquationTable::offerEquation(Equation* equation)
{
   if (acceptEquation(equation))
     equations.append(equation);
}

inline const Vector<Equation*>&
EquationTable::getEquations() const
{
  return equations;
}

inline bool
EquationTable::equationFree() const
{
  return equations.isNull();
}

#endif
