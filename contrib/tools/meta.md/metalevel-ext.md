Meta Level Extensions
=====================

Code that should be moved into the Meta Level once it's separated from the prelude.

```maude
load unification.maude

fmod META-LEVEL-EXT is
   protecting META-LEVEL .
   protecting SUBSTITUTIONSET .

    vars N M M' : Nat . vars T T' : Term . var MOD : Module .
    var S : Substitution . var CTX : Context .

    op #unifiers : Module Term Term -> SubstitutionSet .
    op #unifiers : Module Term Term Nat Nat -> SubstitutionSet .
    ------------------------------------------------------------
    eq #unifiers(MOD, T, T')       = #unifiers(MOD, T, T', 0, 0) .
   ceq #unifiers(MOD, T, T', N, M) = S | #unifiers(MOD, T, T', s(N), M') if { S , M' } := metaUnify(MOD, T =? T', N, M) .
    eq #unifiers(MOD, T, T', N, M) = empty [owise] .

    op #subsumesWith : Module Term Term -> SubstitutionSet .
    op #subsumesWith : Module Term Term Nat -> SubstitutionSet .
    ------------------------------------------------------------
    eq #subsumesWith(MOD, T, T')    = #subsumesWith(MOD, T, T', 0) .
   ceq #subsumesWith(MOD, T, T', N) = S | #subsumesWith(MOD, T, T', s(N)) if S := metaMatch(MOD, T, T', nil, N) .
    eq #subsumesWith(MOD, T, T', N) = empty [owise] .

    op #subsumesXWith : Module Term Term -> SubstitutionSet .
    op #subsumesXWith : Module Term Term Nat -> SubstitutionSet .
    -------------------------------------------------------------
    eq #subsumesXWith(MOD, T, T')    = #subsumesXWith(MOD, T, T', 0) .
   ceq #subsumesXWith(MOD, T, T', N) = S | #subsumesXWith(MOD, T, T', s(N)) if { S , CTX } := metaXmatch(MOD, T, T', nil, 0, unbounded, N) .
    eq #subsumesXWith(MOD, T, T', N) = empty [owise] .
endfm
```