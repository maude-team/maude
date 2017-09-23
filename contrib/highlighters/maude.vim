" Vim syntax file
" Language:      Maude <http://maude.cs.uiuc.edu/>
" Maintainer:    Steven N. Severinghaus <sns@severinghaus.org>
" Last Modified: 2005-02-03
" Version: 0.1
" From: github.com/vim-scripts/maude.vim

" Quit if syntax file is already loaded
if version < 600
  syntax clear
elseif exists("b:current_syntax")
  finish
endif

command! -nargs=+ MaudeHiLink hi def link <args>

syn keyword maudeModule     mod fmod omod endm endfm endm fth endfth th endth view endv is
syn keyword maudeImports    protecting including extending
syn keyword maudeSorts      sorts sort subsorts subsort
syn keyword maudeStatements op ops var vars eq ceq rl crl mb cmb
syn match   maudeFlags      "\[.*\]"
syn keyword maudeCommands   reduce
syn match   maudeComment    "\*\*\*.*"
syn match   maudeComment    "---.*"
syn match   maudeOps        "->"
syn match   maudeOps        ":"
"syn match   maudeOps        "^\s*subsorts[^<]*<"hs=e-1
"syn match   maudeOps        "^\s*ceq[^=]*="
syn match   maudeOps        "="
syn match   maudeOps        "\.\s*$"

syn keyword maudeModules    INT FLOAT NAT RAT BOOL QID TRUTH IDENTICAL STRING
syn keyword maudeModules    CONVERSION
syn match   maudeModules    "TRUTH-VALUE"
syn match   maudeModules    "EXT-BOOL"
syn match   maudeModules    "QID-LIST"
syn match   maudeModules    "META-MODULE"
syn match   maudeModules    "META-TERM"
syn match   maudeModules    "META-LEVEL"
syn match   maudeModules    "LOOP-MODE"
syn match   maudeModules    "CONFIGURATION"

syn keyword maudeSorts      Bool Int Float Nat Qid
syn keyword maudeSorts      Zero NzNat NzInt NzRat Rat FiniteFloat
syn keyword maudeSorts      String Char FindResult DecFloat

syn keyword maudeAttrs      assoc comm idem iter id left-id right-id strat memo
syn keyword maudeAttrs      prec gather format ctor config object msg frozen
syn keyword maudeAttrs      poly special label metadata owise nonexec

" Meta stuff; this may not actually be useful
syn keyword maudeSorts      Sort Kind Type
syn keyword maudeSorts      Constant Variable GroundTerm Term GroundTermList TermList
syn keyword maudeSorts      Assignment Substitution
syn keyword maudeSorts      Context CTermList GTermList
syn keyword maudeSorts      Attr AttrSet
syn keyword maudeSorts      Renaming RenamingSet
syn keyword maudeSorts      ModuleExpression
syn keyword maudeSorts      Import ImportList
syn keyword maudeSorts      SortSet SubsortDecl SubsortDeclSet
syn keyword maudeSorts      TypeList NatList QidList
syn keyword maudeSorts      Hook HookList
syn keyword maudeSorts      OpDecl OpDeclSet EqCondition Condition
syn keyword maudeSorts      MembAx MembAxSet Equation EquationSet
syn keyword maudeSorts      Rule RuleSet
syn keyword maudeSorts      FModule SModule FTheory STheory Module
syn keyword maudeSorts      Bound KindSet
syn keyword maudeSorts      ResultPair ResultTriple Result4Tuple MatchPair
syn keyword maudeSorts      State System
syn keyword maudeSorts      Attribute AttributeSet
syn keyword maudeSorts      Oid Cid Object Msg Configuration
syn match   maudeSorts      "Type\?"
syn match   maudeSorts      "ResultPair\?"
syn match   maudeSorts      "ResultTriple\?"
syn match   maudeSorts      "Result4Tuple\?"
syn match   maudeSorts      "MatchPair\?"
syn match   maudeSorts      "Substitution\?"

" From the BOOL module
syn keyword maudeStatements and or xor not implies

syn keyword maudeLiteral    true false
syn match   maudeLiteral    "\<\(0[0-7]*\|0[xX]\x\+\|\d\+\)[lL]\=\>"
syn match   maudeLiteral    "\(\<\d\+\.\d*\|\.\d\+\)\([eE][-+]\=\d\+\)\=[fFdD]\="

MaudeHiLink maudeModule     PreProc
MaudeHiLink maudeImports    PreProc
MaudeHiLink maudeSorts      Type
MaudeHiLink maudeStatements Keyword
MaudeHiLink maudeModules    String
MaudeHiLink maudeComment    Comment
MaudeHiLink maudeOps        Special
MaudeHiLink maudeCommands   Special
MaudeHiLink maudeFlags      PreProc
MaudeHiLink maudeSorts      Type
MaudeHiLink maudeLiteral    String
"hi def     maudeMisc       term=bold cterm=bold gui=bold

delcommand MaudeHiLink

let b:current_syntax = "maude"

"EOF vim: tw=78:ft=vim:ts=8

