/*
 * PrettyPrinter.cc
 *
 *  Created on: Nov 3, 2011
 *      Author: kquine
 */

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "quotedIdentifierSymbol.hh"
#include "quotedIdentifierDagNode.hh"
#include "token.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "dagArgumentIterator.hh"

//		core class definitions
#include "rewritingContext.hh"

#include "PrettyPrinter.hh"

namespace modelChecker {

PrettyPrinter::PrettyPrinter(Symbol* prettyPrintSymbol, RewritingContext* context):
		prettyPrintSymbol(prettyPrintSymbol), parentContext(context) {}


void
PrettyPrinter::print(ostream& o, DagNode* target) const
{
	Assert(prettyPrintSymbol != nullptr, "StateFoldingGraph::StateFoldingGraph: null printStateSymbol");
	static Vector<DagNode*> args(1);
	args[0] = target;
	DagNode* printDag = prettyPrintSymbol->makeDagNode(args);
	const unique_ptr<RewritingContext> printContext(
			parentContext->makeSubcontext(printDag));
	printContext->reduce();
	parentContext->addInCount(*printContext);

	DagArgumentIterator i(*printContext->root());
	Vector<int> bubble;
	if ( !i.valid()) // single QID
	{
		bubble.append(unBackQuoteId(printContext->root()));
	}
	else
	{
		while (i.valid())
		{
			bubble.append(unBackQuoteId(i.argument()));
			i.next();
		}
	}
	printBubble(o, bubble);
}


// burrowed from Interface::printBubble
void
PrettyPrinter::printBubble(ostream& s, const Vector<int>& bubble) const
{
	bool ansiActive = false;
	bool needSpace = false;
	int nrTokens = bubble.length();
	for (int i = 0; i < nrTokens; i++)
	{
		const char* n = Token::name(bubble[i]);
		//
		//	Single character case.
		//
		if (n[1] == 0)
		{
			switch (n[0])
			{
				case '(':	case ')':	case '[':	case ']': case '{':	case '}':	case ',':
					needSpace = false;
					break;
				default:
					if (needSpace)
						s << ' ';
					needSpace = true;
					/* no break */
			}
			s << n[0];
			continue;
		}
		//
		//	First character backslash case.
		//
		if (n[0] == '\\')
		{
			if (n[2] == 0)
			{
				switch (n[1])
				{
					case 'n':
					{
						s << '\n';
						needSpace = false;
						continue;
					}
					case 't':
					{
						s << '\t';
						needSpace = false;
						continue;
					}
					case 's':
					{
						s << ' ';
						needSpace = false;
						continue;
					}
					case '\\':
					{
						if (needSpace)
							s << ' ';
						s << '\\';
						needSpace = true;
						continue;
					}
					//
					//	ANSI stuff.
					//
					#define MACRO(m, t) \
					case m: { s << Tty(Tty::t); ansiActive = true; continue; }
					#include "ansiEscapeSequences.cc"
					#undef MACRO
					case 'o':
					{
						s << Tty(Tty::RESET);
						ansiActive = false;
						continue;
					}
				}
			}
			else if (n[1] == '`' &&  n[3] == 0)
			{
				switch (n[2])
				{
					case '(': case ')': case '[': case ']': case '{': case '}': case ',':
						if (needSpace)
							s << ' ';
						s << n[2];
						needSpace = true;
						continue;
				}
			}
		}
		//
		//	Normal case.
		//
		if (needSpace)
			s << ' ';
		s << n;
		needSpace = true;
	}
	if (ansiActive)
		s << Tty(Tty::RESET);
	//s << '\n';
}

} /* namespace modelChecker */
