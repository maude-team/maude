Module Transformations
======================

This file is a collection of the module transformations available for Maude.

Removing Conditional Equations/Rules
------------------------------------

```maude
fmod UNCONDITIONALIZE is
   protecting META-LEVEL .

    var M : Module . var FM : FModule . var S : Sort .
    vars T T' C' : Term . var AS : AttrSet . var C : Condition . var V : Variable .
    var H : Header . var IL : ImportList . var SS : SortSet .
    var SSDS : SubsortDeclSet . var OPDS : OpDeclSet . var MAS : MembAxSet .
    var EQS : EquationSet . var RLS : RuleSet .

    --- TODO: Implement/use some existing implementation.
    op varAway : TermList -> Variable .
    -----------------------------------

    op cSort : Sort -> Sort .
    -------------------------
    eq cSort(S) = qid("C" + string(S)) .

    op ctermOp : Sort -> OpDecl .
    -----------------------------
    eq ctermOp(S) = (op '_|_ : S 'Condition -> cSort(S) [none] .) .

    op mmImport : -> Import .
    -------------------------
    eq mmImport = (protecting 'META-MODULE .) .

    op internalizeConditions : Module Sort RuleSet -> [RuleSet] .
    -------------------------------------------------------------
    eq internalizeConditions(M, S, none) = none .
    eq internalizeConditions(M, S,  rl T => T'      [AS] . RLS) = (rl      T     =>      T'                [AS] .) internalizeConditions(M, S, RLS) .
   ceq internalizeConditions(M, S, crl T => T' if C [AS] . RLS) = (rl '_|_[T, V] => '_|_[T', '_/\_[V, C']] [AS] .) internalizeConditions(M, S, RLS)
    if sameKind(M, S, leastSort(M, T))
    /\ C' := upTerm(C)
    /\ V  := varAway((T,T',C')) .

    op internalizeConditions : Module Sort -> [Module] .
    ----------------------------------------------------
    eq internalizeConditions(FM, S) = FM .
   ceq internalizeConditions(M, S)  = ( mod H is
                                           IL mmImport
                                           sorts S ; cSort(S) ; SS .
                                           SSDS (subsort S < cSort(S) .)
                                           OPDS ctermOp(S)
                                           MAS
                                           EQS internalizeConditions(M, S, RLS)
                                        endm
                                      )
    if (mod H is IL sorts S ; SS . SSDS OPDS MAS EQS RLS endm) := M .
endfm
```
