//
//	Functions shared between 2 or more pretty printers.
//

bool
MixfixModule::ambiguous(int iflags)
{
  if (iflags & DOMAIN_OVERLOADED)
    return true;
  if (iflags & PSEUDOS)
    {
      if (iflags & PSEUDO_VARIABLE)
	return true;
      else if (iflags & PSEUDO_NAT)
	return !(kindsWithSucc.empty());
      else if (iflags & PSEUDO_NEG)
	return !(kindsWithMinus.empty());
      else if (iflags & PSEUDO_RAT)
	return !(kindsWithDivision.empty());
      else if (iflags & PSEUDO_FLOAT)
	return !(floatSymbols.empty());
      else if (iflags & PSEUDO_STRING)
	return !(stringSymbols.empty());
      else if (iflags & PSEUDO_QUOTED_IDENTIFIER)
	return !(quotedIdentifierSymbols.empty());
    }
  return false;
}
