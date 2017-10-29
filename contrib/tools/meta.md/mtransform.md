Module Transformations
======================

This file is a collection of the module transformations available for Maude. The
data-structures used are from `mtemplate.maude` for flexibility (as opposed to
the prelude ones).

```maude
load mtemplate.maude
load variables.maude
```

Removing Conditional Equations/Rules
------------------------------------

```maude
fmod UNCONDITIONALIZE is
   protecting META-LEVEL .
   protecting MODULE-TEMPLATE .
   protecting DETERMINISTIC-VARIABLES .

    var M : Module . var FM : FModule . var S : Sort .
    vars T T' C' : Term . var AS : AttrSet . var C : Condition . var V : Variable .
    var H : Header .
    vars NeMDS NeMDS' : NeModuleDeclSet .
    var IS : ImportDeclSet . var SDS : SortDeclSet .
    var SSDS : SubsortDeclSet . var OPDS : OpDeclSet . var MAS : MembAxSet .
    var EQS : EquationSet . var RLS : RuleSet .

    op cSort : Sort -> Sort .
    -------------------------
    eq cSort(S) = qid("C" + string(S)) .

    op ctermOp : Sort -> OpDecl .
    -----------------------------
    eq ctermOp(S) = (op '_|_ : S 'Condition -> cSort(S) [none] .) .

    op mmImport : -> Import .
    -------------------------
    eq mmImport = (protecting 'META-MODULE .) .

    op rmConditions : Module Sort RuleSet -> [RuleSet] .
    -------------------------------------------------------------
    eq rmConditions(M, S, none) = none .
    eq rmConditions(M, S,  rl T => T'      [AS] . RLS) = (rl      T     =>      T'                [AS] .) rmConditions(M, S, RLS) .
   ceq rmConditions(M, S, crl T => T' if C [AS] . RLS) = (rl '_|_[T, V] => '_|_[T', '_/\_[V, C']] [AS] .) rmConditions(M, S, RLS)
    if sameKind(M, S, leastSort(M, T))
    /\ C' := upTerm(C)
    /\ V  := #var((T,T',C'), 'Condition) .

    op rmConditions : Sort ModuleDeclSet -> [ModuleDeclSet] .
    ---------------------------------------------------------
    eq rmConditions(S, none)                = none .
    eq rmConditions(S, IS SDS SSDS MAS EQS) = IS SDS SSDS MAS EQS .
    eq rmConditions(S, NeMDS NeMDS')        = rmConditions(S, NeMDS) rmConditions(S, NeMDS') .

   ceq rmConditions(S, rl T => T' [AS] .) = ( rl '_|_[T, V] => '_|_[T', V] [AS] . )
    if V := #var((T, T'), 'Condition) .

   ceq rmConditions(S, crl T => T' if C [AS] .) = ( rl '_|_[T, V] => '_|_[T', '_/\_[V, C']] [AS] . )
    if C' := upTerm(C)
    /\ V  := #var((T, T', C'), 'Condition) .
endfm
```
