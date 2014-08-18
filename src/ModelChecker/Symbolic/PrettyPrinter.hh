/*
 * PrettyPrinter.hh
 *
 *  Created on: Nov 3, 2011
 *      Author: kquine
 */

#ifndef PRETTYPRINTER_HH_
#define PRETTYPRINTER_HH_

namespace modelChecker {

class PrettyPrinter
{
public:
	PrettyPrinter(Symbol* prettyPrintSymbol, RewritingContext* context);
	void print(ostream& o, DagNode* target) const;

private:
	inline int unBackQuoteId(DagNode* d) const;
    void printBubble(ostream& s, const Vector<int>& bubble) const;

    Symbol* prettyPrintSymbol;
    RewritingContext* parentContext;
};

inline int
PrettyPrinter::unBackQuoteId(DagNode* d) const
{
	if (auto qd = dynamic_cast<QuotedIdentifierDagNode*>(d))
		return Token::unBackQuoteSpecials(qd->getIdIndex());
	else
		return d->symbol()->id();
}

} /* namespace modelChecker */
#endif /* PRETTYPRINTER_HH_ */
