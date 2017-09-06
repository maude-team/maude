//
//	Code for handling importation.
//

void
PreModule::processImports()
{
  /*
  const ModuleDatabase::NameSet::const_iterator e = autoImports.end();
  for (ModuleDatabase::NameSet::const_iterator i = autoImports.begin(); i != e; ++i)
    importModule(*i, *this);
  */
  int nrAutoImports = autoImports.cardinality();
  for (int i = 0; i < nrAutoImports; i++)
    importModule(autoImports.index2Int(i), *this);
  int nrImports = imports.length();
  for (int i = 0; i < nrImports; i++)
    {
      Vector<Token>& import = imports[i];
      if (import.length() != 2)
	{
	  IssueWarning(LineNumber(import[0].lineNumber()) <<
		       ": bad import: " << QUOTE(import));
	}
      else
	{
	  WarningCheck(import[0].code() != Token::encode("us") &&
		       import[0].code() != Token::encode("using"), 
		       LineNumber(import[0].lineNumber()) <<
		       ": importation mode " << QUOTE("using") <<
		       " not supported - treating it like " <<
		       QUOTE("including") << '.');
	  importModule(import[1].code(), import[1].lineNumber());
	}
    }
}

void
PreModule::importModule(int name, const LineNumber& lineNumber)
{
  if (PreModule* m = interpreter.getModule(name))
    {
      if (VisibleModule* fm = m->getFlatSignature())
	{
	  fm->economize();  // HACK
	  if (fm->isBad())
	    {
	      IssueWarning(lineNumber << ": unable to import module " <<
			   QUOTE(m) << " due to unpatchable errors.");
	    }
	  else
	    flatModule->addImport(fm);
	}
      else
	{
	  IssueWarning(lineNumber << ": mutually recursive import of module " <<
		       QUOTE(m) << " ignored.");
	}
    }
  else
    {
      IssueWarning(*this << ": module " << QUOTE(Token::name(name)) <<
		   " does not exist.");
    }
}
