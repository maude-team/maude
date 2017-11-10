Narrowing and Equational Unification
====================================

Santiago Escobar

```maude
fmod META-LEVEL-MNPA is
  pr META-LEVEL * (op `{_`,_`} : Term Nat -> SmtResult to `{_`,_`}Smt )  .
endfm

fmod UNIFICATIONTRIPLE is
  protecting META-LEVEL-MNPA .
  protecting INT .

  --- UnificationPair --------------------------------------------
  ---sorts UnificationPair UnificationPair? .
  ---op {_,_} : Substitution Nat -> UnificationPair [ctor] .
  ---subsort UnificationPair < UnificationPair? .
  ---op noUnifier : -> UnificationPair? [ctor] .

  op getSubst : UnificationPair -> Substitution .
  eq getSubst({S1:Substitution, N:Nat}) = S1:Substitution .
  op getNextVar : UnificationPair -> Nat .
  eq getNextVar({S1:Substitution, N:Nat}) = N:Nat .

  --- UnificationTriple --------------------------------------------
  ---sorts UnificationTriple UnificationTriple? .
  ---op {_,_,_} : Substitution Substitution Nat -> UnificationTriple [ctor] .
  ---subsort UnificationTriple < UnificationTriple? .
  ---op noUnifier : -> UnificationTriple? [ctor] .

  op getLSubst : UnificationTriple -> Substitution .
  eq getLSubst({S1:Substitution, S2:Substitution, N:Nat}) = S1:Substitution .
  op getRSubst : UnificationTriple -> Substitution .
  eq getRSubst({S1:Substitution, S2:Substitution, N:Nat}) = S2:Substitution .
  op getNextVar : UnificationTriple -> Nat .
  eq getNextVar({S1:Substitution, S2:Substitution, N:Nat}) = N:Nat .

endfm

fmod TERM-HANDLING is
  protecting META-TERM .
  protecting META-LEVEL-MNPA .
  protecting EXT-BOOL . *** For and-then

  var T T' T'' : Term .
  var C C' : Constant .
  var QIL : QidList .
  var N N' : Nat .
  var NL NL' : NatList .
  var Q F F' : Qid .
  var AtS : AttrSet .
  var EqS : EquationSet .
  var Eq : Equation .
  var Cond : Condition .
  var TP : Type .
  var TPL TPL' : TypeList .
  var TL TL' TL'' : TermList .
  var B : Bool .
  var V V' : Variable .
  var Ct : Context .
  var CtL : NeCTermList .
  var NeTL : NeTermList .
  var M : Module .

  *** root  ******************************
  op root : Term -> Qid .
  eq root(V) = V .
  eq root(C) = C .
  eq root(F[TL]) = F .

  *** size  ******************************
  op size : TermList -> Nat .
  eq size(empty) = 0 .
  eq size((T,TL)) = s(size(TL)) .

  *** elem_of_ *****************************************************
  op elem_of_ : Nat TermList ~> Term .
  eq elem 1 of (T,TL) = T .
  eq elem s(s(N)) of (T,TL) = elem s(N) of TL .

  *** subTerm_of_ *****************************************************
  op subTerm_of_ : NatList Term ~> Term .
  eq subTerm NL of T = subTerm* NL of T  .

  op subTerm*_of_ : NatList Term ~> Term .
  eq subTerm* nil of T = T .
  eq subTerm* N NL of (F[TL]) = subTerm* NL of (elem N of TL) .

  *** ToDo: UPGRADE THIS NOTION TO MODULO AC *********************
  *** is_subTermOf_ *****************************************************
  op is_subTermOf_ : Term TermList -> Bool .
  eq is T subTermOf (T',NeTL) = is T subTermOf T'
                                or-else is T subTermOf NeTL .
  eq is T subTermOf T = true .
  eq is T subTermOf T' = is T subTermOf* T' [owise] .

  op is_subTermOf*_ : Term TermList -> Bool .
  eq is T subTermOf* (F[TL]) = is T subTermOf TL .
  eq is T subTermOf* T' = false [owise] .

  *** noVarOfSort_In_ *****************************************************
  op noVarOfSort_In_ : Type TermList -> Bool .
  eq noVarOfSort T:Type In V = getType(V) =/= T:Type .
  eq noVarOfSort T:Type In (F[TL]) = noVarOfSort T:Type In TL .
  eq noVarOfSort T:Type In (T',NeTL)
   = noVarOfSort T:Type In T' and noVarOfSort T:Type In NeTL .
  eq noVarOfSort T:Type In X:TermList = true [owise] .

  *** findSubTermOf_In_ ***********************************************
  op findSubTermOf_In_ : NeCTermList TermList ~> Term .
  eq findSubTermOf (TL, [], TL') In (TL, T, TL') = T .
  eq findSubTermOf (TL, F[CtL], TL'') In (TL, F[TL'], TL'')
   = findSubTermOf CtL In TL' .

  *** replaceElem_of_by_ ****************************************************
  op replaceElem_of_by_ : Nat TermList Term ~> TermList .
  eq replaceElem 1 of (T,TL) by T' = (T',TL) .
  eq replaceElem s(s(N)) of (T,TL) by T' = (T,replaceElem s(N) of TL by T') .

  *** replaceSubTerm_of_by_ *************************************************
  op replaceSubTerm_of_by_ : NatList TermList Term ~> TermList .
  eq replaceSubTerm nil of T by T' = T' .
  eq replaceSubTerm N NL of (F[TL]) by T'
   = F[replaceSubTermL N NL of TL by T'] .

  op replaceSubTermL_of_by_ : NatList TermList Term ~> TermList .
  eq replaceSubTermL 1 NL of (T,TL) by T'
   = (replaceSubTerm NL of T by T', TL) .
  eq replaceSubTermL s(s(N)) NL of (T,TL) by T'
   = (T,replaceSubTermL s(N) NL of TL by T') .

  op replaceTerm_by_in_ : Term Term TermList ~> TermList .
  eq replaceTerm T by T' in T = T' .
  eq replaceTerm T by T' in (F[TL]) = F[replaceTerm T by T' in TL] .
  eq replaceTerm T by T' in T'' = T'' [owise] .
  eq replaceTerm T by T' in (T'',NeTL)
   = (replaceTerm T by T' in T'',replaceTerm T by T' in NeTL) .

  *** context replacement **************************************************

  op _[_] : Context Context -> Context .
  op _[_] : NeCTermList Context -> NeCTermList .
  eq [] [ Ct ] = Ct .
  eq (F[CtL])[ Ct ] = F[ CtL [ Ct ] ] .
  eq (CtL,NeTL) [Ct] = (CtL [Ct] ), NeTL .
  eq (NeTL,CtL) [Ct] = NeTL, (CtL [Ct] ) .

  op _[_] : Context Term -> Term .
  op _[_] : NeCTermList Term -> TermList .
  eq [] [ T ] = T .
  eq (F[CtL])[ T ] = F[ CtL [ T ] ] .
  eq (CtL,NeTL) [T] = (CtL [T] ), NeTL .
  eq (NeTL,CtL) [T] = NeTL, (CtL [T] ) .

  *** is_substring_ *****************************************
  op is_substring_ : Qid Qid -> Bool [memo] .
  eq is F:Qid substring F':Qid
   = rfind(string(F':Qid), string(F:Qid), length(string(F':Qid))) =/= notFound .

  *** addprefix_To_ addsufix_To_ *****************************************
  op addprefix_To_ : Qid Variable -> Variable [memo] .
  eq addprefix Q To V
   = qid(string(Q) + string(getName(V)) + ":" + string(getType(V))) .

  op addprefix_To_ : Qid Constant -> Constant [ditto] .
  eq addprefix Q To F
   = if noUnderBar(F) and getName(F) :: Qid then
       if getType(F) :: Type then
         qid(string(Q) + string(getName(F)) + "." + string(getType(F)))
       else
         qid(string(Q) + string(getName(F)))
       fi
     else
       qid(string(Q) + string(F))
     fi .

  op addsufix_To_ : Qid Variable -> Variable [memo] .
  eq addsufix Q To V
   = qid(string(getName(V)) + string(Q) + ":" + string(getType(V))) .

  op addsufix_To_ : Qid Constant -> Constant [ditto] .
  eq addsufix Q To F
   = if noUnderBar(F) and getName(F) :: Qid then
       if getType(F) :: Type then
         qid(string(getName(F)) + string(Q) + "." + string(getType(F)))
       else
         qid(string(getName(F)) + string(Q))
       fi
     else
       qid(string(F) + string(Q))
     fi .

  op addType_ToVar_ : Type Qid -> Variable [memo] .
  eq addType TP:Qid ToVar V:Qid
   = qid(string(V:Qid) + ":" + string(TP:Qid)) .

  *** noUnderBar (auxiliary) ****************************
  op noUnderBar : Qid -> Bool .
  eq noUnderBar(F)
   = rfind(string(F), "_", length(string(F))) == notFound .

  *** addType  ******************************
  op addType : Qid Type -> Qid .
  eq addType(F,TP)
   = if noUnderBar(F) and getName(F) :: Qid then
       qid( string(getName(F)) + "." + string(TP) )
     else
       qid( string(F) + "." + string(TP) )
     fi .

  *** addTypeVar  ******************************
  op addTypeVar : Qid Type -> Qid .
  eq addTypeVar(F,TP)
   = qid( string(F) + ":" + string(TP) ) .

endfm

fmod SUBSTITUTION-HANDLING is
  protecting META-TERM .
  protecting META-LEVEL-MNPA .
  protecting TERM-HANDLING .

  var S S' Subst Subst' : Substitution .
  var V V' : Variable .
  var C C' : Constant .
  var Ct : Context .
  var T T' T1 T2 T1' T2' T1'' T2'' : Term .
  var F F' : Qid .
  var TL TL' TL1 TL2 TL1' TL2' : TermList .
  var Att : AttrSet .
  var RLS : RuleSet .
  var Rl : Rule .
  var TP : Type .
  var N : Nat .
  var NeTL : NeTermList .
  var CtL : NeCTermList .

  --- Apply Substitution to Term --------------------------------------------
  op _<<_ : Term Substitution -> Term .
  eq TL << none = TL .
  eq C << Subst = C .
  eq V << ((V <- T) ; Subst) = T .
  eq V << Subst = V [owise] .
  eq F[TL] << Subst = F[TL << Subst] .

  op _<<_ : TermList Substitution -> TermList .
  eq (T, NeTL) << Subst = (T << Subst, NeTL << Subst) .
  eq empty << Subst = empty .

  op _<<_ : Context Substitution -> Context .
  eq Ct << none = Ct .
  eq [] << Subst = [] .
  eq F[CtL,NeTL] << Subst = F[CtL << Subst,NeTL << Subst] .
  eq F[NeTL,CtL] << Subst = F[NeTL << Subst, CtL << Subst] .
  eq F[Ct] << Subst = F[Ct << Subst] .

  op _<<_ : Substitution Substitution -> Substitution .
  eq S << (none).Substitution = S .
  eq (none).Substitution << S = (none).Substitution .
  eq ((V' <- T) ; S') <<  S
   = (V' <- (T << S))
     ;
     (S' << S) .

  --- Combine Substitutions -------------------------------------------------
  op _.._ : Substitution Substitution -> Substitution .
  eq S .. S' = (S << S') ; S' .

  --- Restrict Assignments to Variables in a Term ----------------------
  op _|>_ : Substitution TermList -> Substitution .

  eq Subst |> TL = Subst |>* Vars(TL) .

  op _|>*_ : Substitution TermList -> Substitution .
---   eq noMatch |>* TL = noMatch .
  eq Subst |>* TL = Subst |>** TL [none] .

  op _|>**_[_] : Substitution TermList
                 Substitution -> Substitution .
  eq none |>** TL [Subst']
   = Subst' .
  eq ((V <- V) ; Subst) |>** TL [Subst']
   = Subst |>** TL [Subst'] .
  eq ((V <- T') ; Subst) |>** TL [Subst']
    = Subst |>** TL
      [Subst' ; if any V in TL then (V <- T') else none fi] .

  --- Remove Variables from list ----------------------
  op _intersect_ : TermList TermList -> TermList .
  eq (TL1,T,TL2) intersect (TL1',T,TL2')
   = (T,((TL1,TL2) intersect (TL1',TL2'))) .
  eq TL intersect TL' = empty [owise] .

  op _intersectVar_ : TermList TermList -> TermList .
  eq TL1 intersectVar TL2
   = TL1 intersectVar* Vars(TL2) .

  op _intersectVar*_ : TermList TermList -> TermList .
  eq (T,TL1) intersectVar* TL2
   = (if any Vars(T) in TL2 then T else empty fi,TL1 intersectVar* TL2) .
  eq empty intersectVar* TL2
   = empty .

  --- Remove Variables from list ----------------------
  op _setMinus_ : TermList TermList -> TermList .
  eq (TL1,T,TL2) setMinus (TL1',T,TL2')
   = (TL1,TL2) setMinus (TL1',T,TL2') .
  eq TL setMinus TL' = TL [owise] .

  --- Variables ---
  op Vars : GTermList -> TermList .
  eq Vars((T,TL:GTermList)) = VarsTerm(T),Vars(TL:GTermList) .
  eq Vars((Ct,TL:GTermList)) = VarsTerm(Ct),Vars(TL:GTermList) .
  eq Vars(empty) = empty .

  op VarsTerm : Term -> TermList . ---warning memo
  eq VarsTerm(V) = V .
  eq VarsTerm(F[TL:TermList]) = Vars(TL:TermList) .
  eq VarsTerm(C) = empty .

  op VarsTerm : Context -> TermList . ---warning memo
  eq VarsTerm(F[TL:GTermList]) = Vars(TL:GTermList) .

  --- membership ---
  op _in_ : Term TermList -> Bool .
  eq T in (TL,T,TL') = true .
  eq T in TL = false [owise] .

  --- membership ---
  op any_in_ : TermList TermList -> Bool . --- [memo] .
  eq any empty in TL = false .
  eq any (TL1,T,TL2) in (TL1',T,TL2') = true .
  eq any TL in TL' = false [owise] .

  --- membership ---
  op all_in_ : TermList TermList -> Bool . --- [memo] .
  eq all empty in TL = true .
  eq all (TL1,T,TL2) in (TL1',T,TL2') = all (TL1,TL2) in (TL1',T,TL2') .
  eq all TL in TL' = false [owise] .

  --- Occur check ---
  op allVars_inVars_ : GTermList GTermList -> Bool .
  eq allVars TL:GTermList inVars TL':GTermList
   = all Vars(TL:GTermList) in Vars(TL':GTermList) .

  op anyVars_inVars_ : GTermList GTermList -> Bool .
  eq anyVars TL:GTermList inVars TL':GTermList
   = any Vars(TL:GTermList) in Vars(TL':GTermList) .

  op rangeVars : Substitution -> TermList .
  eq rangeVars(V <- T ; Subst) = (Vars(T),rangeVars(Subst)) .
  eq rangeVars(none) = empty .

  op dom_inVars_ : Substitution TermList -> Bool .
  eq dom Subst inVars TL = dom Subst in Vars(TL) .

  op dom_in_ : Substitution TermList -> Bool .
  eq dom (V <- T ; Subst) in (TL1,V,TL2) = true .
  eq dom Subst in TL = false [owise] .

  op dom_notInVars_ : Substitution TermList -> Bool .
  eq dom Subst notInVars TL = dom Subst notIn Vars(TL) .

  op dom_notIn_ : Substitution TermList -> Bool .
  eq dom none notIn TL = true .
 ceq dom (V <- T ; Subst) notIn TL = true if not (V in TL) .
  eq dom Subst notIn TL = false [owise] .

  op range_inVars_ : Substitution TermList -> Bool .
  eq range Subst inVars TL = range Subst in Vars(TL) .

  op range_in_ : Substitution TermList -> Bool .
  eq range (V <- T ; Subst) in TL
   = any Vars(T) in TL or-else range Subst in TL .
  eq range none in TL
   = false .

  op valid-occur-check? : Substitution -> Bool .
  eq valid-occur-check?(Subst)
   = not (dom Subst inVars (rangeVars(Subst))) .

  op extract-bindings : Substitution -> TermList .
  eq extract-bindings(none) = empty .
  eq extract-bindings(V <- T ; Subst) = (T,extract-bindings(Subst)) .
endfm

fmod TERMSET is
  protecting META-LEVEL-MNPA .
  protecting SUBSTITUTION-HANDLING .

  sort TermSet .
  subsort Term < TermSet .
  op emptyTermSet : -> TermSet [ctor] .
  op _|_ : TermSet TermSet -> TermSet
    [ctor assoc comm id: emptyTermSet format (d n d d)] .
  eq X:Term | X:Term = X:Term .

  op _in_ : Term TermSet -> Bool .
  eq T:Term in (T:Term | TS:TermSet) = true .
  eq T:Term in TS:TermSet = false [owise] .

  op TermSet : TermList -> TermSet .
  eq TermSet(empty)
   = emptyTermSet .
  eq TermSet((T:Term,TL:TermList))
   = T:Term | TermSet(TL:TermList) .

endfm

fmod RENAMING is
  protecting META-TERM .
  protecting META-LEVEL-MNPA .
  protecting TERM-HANDLING .
  protecting SUBSTITUTION-HANDLING .
  protecting TERMSET .
  protecting CONVERSION .
  protecting QID .
  protecting INT .
  protecting UNIFICATIONTRIPLE .

  var S S' Subst Subst' : Substitution .
  var V V' : Variable .
  var C C' : Constant .
  var CtL : NeCTermList .
  var Ct : Context .
  var T T' T1 T2 T1' T2' T1'' T2'' : Term .
  var F F' : Qid .
  var TL TL' TL'' TL''' : TermList .
  var Att : AttrSet .
  var RLS : RuleSet .
  var Rl : Rule .
  var TP : Type .
  var N N' : Nat .
  var NeTL : NeTermList .

  var Q Q' : Qid .
  var IL : ImportList .
  var SS : SortSet .
  var SSDS : SubsortDeclSet .
  var OPDS : OpDeclSet .
  var MAS : MembAxSet .
  var EQS : EquationSet .

  var TPL : TypeList .

  --- Extra filter for substitutions ------
  op _|>_ : Substitution Nat -> Substitution .
  eq Subst |> N
   = Subst |>* N [none] .

  op _|>*_[_] : Substitution Nat Substitution -> Substitution .
  eq none |>* N [Subst']
   = Subst' .
  eq ((V <- T') ; Subst) |>* N [Subst']
   = Subst |>* N
     [Subst' ; if highestVar(V) < N then (V <- T') else none fi ] .

  --- instantiatesAbove -----------------------------------
  op _instantiatesAbove_ : Substitution Nat -> Bool .
  eq none instantiatesAbove N = false .
  eq ((V <- T') ; Subst) instantiatesAbove N
   = highestVar(V) >= N
     or-else
     Subst instantiatesAbove N .

  ----------------------------------------------
  --- New Renaming Utilities -------------------
  op highestVar : GTermList -> Nat .
  eq highestVar(TL:GTermList)
   = highestVar(TL:GTermList,0) .

  op highestVarTerm : Term -> Nat . ---warning memo
  op highestVarTerm : Context -> Nat . ---warning memo
  eq highestVarTerm([]) = 0 .
  eq highestVarTerm(C) = 0 .
  eq highestVarTerm(V)
   = if rfind(string(V), "#", length(string(V))) =/= notFound
        and
        rfind(string(V), ":", length(string(V))) =/= notFound
        and
        rat(substr(string(V),
                   rfind(string(V), "#", length(string(V))) + 1,
                   rfind(string(V), ":", length(string(V))) + (- 1))
            ,10)
        :: Nat
     then rat(substr(string(V),
                   rfind(string(V), "#", length(string(V))) + 1,
                   rfind(string(V), ":", length(string(V))) + (- 1))
              ,10)
     else
         if rfind(string(V), "%", length(string(V))) =/= notFound
            and
            rfind(string(V), ":", length(string(V))) =/= notFound
            and
            rat(substr(string(V),
                       rfind(string(V), "%", length(string(V))) + 1,
                       rfind(string(V), ":", length(string(V))) + (- 1))
                ,10)
            :: Nat
         then rat(substr(string(V),
                         rfind(string(V), "%", length(string(V))) + 1,
                         rfind(string(V), ":", length(string(V))) + (- 1))
                  ,10)
         else 0
         fi
     fi .

  eq highestVarTerm(F[TL:GTermList])
   = highestVar(TL:GTermList,0) .

  op highestVar : GTermList Nat -> Nat .
  eq highestVar(empty,N)
   = N .
  eq highestVar((Ct,TL:GTermList),N)
   = highestVar(TL:GTermList,
       if highestVarTerm(Ct) > N then highestVarTerm(Ct) else N fi
     ) .
  eq highestVar((T,TL:GTermList),N)
   = highestVar(TL:GTermList,
       if highestVarTerm(T) > N then highestVarTerm(T) else N fi
     ) .

  --- For substitutions
  op highestVar : Substitution -> Nat . --- [memo] .
  eq highestVar(Subst)
   = highestVar(Subst,0) .

  op highestVar : Substitution Nat -> Nat .
  eq highestVar((none).Substitution,N) = N .
  eq highestVar(V <- T ; Subst,N)
   = highestVar(Subst,highestVar((T,V),N)) .

  --- Renaming ------------------------------------------------------
  op newVar : Nat TypeList -> TermList .
  eq newVar(N,nil) = empty .
  eq newVar(N,TP TPL) = (newVar*(N,TP),newVar(s(N),TPL)) .

  op newVar* : Nat Type -> Variable .
  eq newVar*(N,TP)
   = qid("#" + string(N,10) + ":" + string(TP)) .

  op simplifyVars : TermList -> TermList .
  eq simplifyVars(TL) = TL << 0 < .

  op _<<`(_`)< : TermList GTermList -> TermList .
  eq X:TermList <<(TL:GTermList)<
   = X:TermList << highestVar(TL:GTermList) + 1 < .

  op _<<_ : TermList UnificationPair -> TermList .
  eq TL << {Subst,N} = TL << Subst .

  op _<<_ : TermList UnificationTriple -> TermList .
  eq TL << {Subst,Subst',N} = TL << (Subst ; Subst') .

  op _<<_ : Substitution UnificationTriple -> Substitution .
  eq S:Substitution << {Subst,Subst',N} = S:Substitution << (Subst ; Subst') .

  op _<<_< : TermList Nat -> TermList .
  eq TL << N < = TL << (TL << { none, N } <) .

  op _<<_< : TermList UnificationPair -> UnificationPair . ***Huge [memo] .
  eq C << {S,N} < = {S,N} .
  eq F[TL] << {S,N} < = TL << {S,N} < .
  eq V << {S,N} <
   = if not (dom S inVars V)
     then {S ; V <- newVar(N,getType(V)), N + 1}
     else {S,N}
     fi .

  eq (T,TL:NeTermList) << {S,N} <
   = TL:NeTermList << (T << {S,N} < ) < .
  eq empty << {S,N} <
   = {S,N} .

endfm

fmod SUBSTITUTIONSET is
  protecting SUBSTITUTION-HANDLING .
  protecting META-LEVEL-MNPA .
  protecting TERMSET .
  protecting RENAMING .

  sort SubstitutionSet NeSubstitutionSet .
  subsort Substitution < NeSubstitutionSet < SubstitutionSet .
  op empty : -> SubstitutionSet [ctor] .
  op _|_ : SubstitutionSet SubstitutionSet -> SubstitutionSet
    [ctor assoc comm id: empty format (d n d d)] .
  op _|_ : NeSubstitutionSet SubstitutionSet -> NeSubstitutionSet
    [ctor ditto] .
  eq X:Substitution | X:Substitution = X:Substitution .

  vars SS SS' : SubstitutionSet .
  vars S S' Subst : Substitution .
  vars T T' : Term .
  vars TL TL' : TermList .
  vars N N' : Nat .
  var V : Variable .

  op _<<_ : Substitution SubstitutionSet -> SubstitutionSet .
  eq S << empty = empty .
  ceq S << (S' | SS') = (S << S') | (S << SS') if SS' =/= empty .

  op _..._ : SubstitutionSet [SubstitutionSet]
          -> SubstitutionSet [strat (1) gather (e E)] .

  eq empty ... SS':[SubstitutionSet] = empty .
  eq (S | SS) ... SS':[SubstitutionSet]
   = (S ...' SS':[SubstitutionSet])
     |
     (SS ... SS':[SubstitutionSet]) .

  op _...'_ : Substitution SubstitutionSet -> SubstitutionSet .

  eq S ...' empty
   = empty .

  eq S ...' (S' | SS')
   = (S .. S')
     |
     (S ...' SS') .

  op _|>_ : SubstitutionSet TermList -> SubstitutionSet .
  eq (empty).SubstitutionSet |> TL = empty .
  eq (S | SS:NeSubstitutionSet) |> TL
   = (S |> TL) | (SS:NeSubstitutionSet |> TL) .

  op _|>_ : SubstitutionSet Nat -> SubstitutionSet .
  eq SS:NeSubstitutionSet |> N
   = SS:NeSubstitutionSet |> (0,N) .

  op _|>`(_,_`) : SubstitutionSet Nat Nat -> SubstitutionSet .
  eq (empty).SubstitutionSet |> (N,N') = empty .
  eq (S | SS:NeSubstitutionSet) |> (N,N')
   = (S |> (N,N')) | (SS:NeSubstitutionSet |> (N,N')) .

  op _|>`(_,_`) : Substitution Nat Nat -> Substitution .
  eq none |> (N,N') = none .
  eq ((V <- T') ; Subst) |> (N,N')
   = if N <= highestVar(V) and highestVar(V) <= N'
     then (V <- T')
     else none
     fi
     ; (Subst |> (N,N')) .

  op filter_by!InVars_ : SubstitutionSet TermList -> SubstitutionSet .
  eq filter (empty).SubstitutionSet by!InVars TL
   = (empty).SubstitutionSet .
  eq filter (S | SS) by!InVars TL
   = if dom S inVars TL
     then empty
     else S
     fi
     | filter SS by!InVars TL .

  op _==* none : SubstitutionSet -> Bool .
  eq (none | SS) ==* none = SS ==* none .
  eq (empty).SubstitutionSet ==* none = true .
  eq SS ==* none = false [owise] .

  op |_| : SubstitutionSet -> Nat .
  eq | (empty).SubstitutionSet | = 0 .
  eq | (S | SS) | = s(| SS |) .

endfm

fmod UNIFICATIONPAIRSET is
  protecting SUBSTITUTIONSET .
  protecting RENAMING .
  protecting UNIFICATIONTRIPLE .

  vars V V' : Variable .
  vars U U' : UnificationPair .
  vars US US' : UnificationPairSet .
  vars S S' S1 S1' S2 S2' : Substitution .
  var SS : SubstitutionSet .
  vars N N' N1 N2 : Nat .
  vars T T' : Term .
  var TL : TermList .
  var M : Module .

  --- Combine UnificationPair ---------------------------------------------
  op _.._ : UnificationPair UnificationPair -> UnificationPair .
  eq {S,N} .. {S',N'} = {S .. S',max(N,N')} .

  --- Detect used variables ----------------------------------------------
  op dom_inVars_ : UnificationPair TermList -> Bool . --- [memo] .
  eq dom {S,N} inVars TL = dom S inVars TL .

  --- UnificationPairSet --------------------------------------------------
  sort UnificationPairSet .
  subsort UnificationPair < UnificationPairSet .
  op empty : -> UnificationPairSet [ctor] .
  op _|_ : UnificationPairSet UnificationPairSet -> UnificationPairSet
    [ctor assoc comm id: empty format (d n d d)] .
  eq X:UnificationPair | X:UnificationPair = X:UnificationPair .

  op _..._ : UnificationPairSet [UnificationPairSet]
          -> UnificationPairSet [strat (1) gather (e E)] .

  eq (empty).UnificationPairSet ... US':[UnificationPairSet]
   = (empty).UnificationPairSet .
  eq (U | US) ... US':[UnificationPairSet]
   = (U ...' US':[UnificationPairSet])
     |
     (US ... US':[UnificationPairSet]) .

  op _...'_ : UnificationPair UnificationPairSet -> UnificationPairSet .

  eq U ...' (empty).UnificationPairSet
   = (empty).UnificationPairSet .

  eq U ...' (U' | US')
   = (U .. U')
     |
     (U ...' US') .

  --- Restriction -----------------------
  op _|>_ : UnificationPairSet TermList -> UnificationPairSet .
  eq (empty).UnificationPairSet |> TL = empty .
  eq ({S,N} | US) |> TL = {(S |> TL),N} | (US |> TL) .

  op filter_by!InVars_ : UnificationPairSet TermList
                      -> UnificationPairSet .
  eq filter (empty).UnificationPairSet by!InVars TL
   = (empty).UnificationPairSet .
  eq filter (U | US) by!InVars TL
   = if dom U inVars TL
     then empty
     else U
     fi
     | filter US by!InVars TL .

  op toUnificationPair[_]`(_`) : Nat SubstitutionSet -> UnificationPairSet .
  eq toUnificationPair[N](empty)
   = empty .
  eq toUnificationPair[N](S | SS)
   = {S,highestVar(S,N)}
     | toUnificationPair[N](SS) .

  op toSubstitution : UnificationPairSet -> SubstitutionSet .
  eq toSubstitution((empty).UnificationPairSet)
   = empty .
  eq toSubstitution({S,N} | US)
   = S | toSubstitution(US) .

  op _in_ : UnificationPair UnificationPairSet -> Bool .
  eq X:UnificationPair in (X:UnificationPair | XS:UnificationPairSet) = true .
  eq X:UnificationPair in XS:UnificationPairSet = false [owise] .

endfm

fmod UNIFICATIONTRIPLESET is
  protecting SUBSTITUTIONSET .
  protecting RENAMING .
  protecting UNIFICATIONPAIRSET .

  vars V V' : Variable .
  var C : Constant .
  var F : Qid .
  vars U U' : UnificationTriple .
  vars US US' : UnificationTripleSet .
  vars S S' S1 S1' S2 S2' : Substitution .
  var SS : SubstitutionSet .
  var SSe : NeSubstitutionSet .
  vars N N' N1 N2 NextVar : Nat .
  vars T T' : Term .
  var TL : TermList .
  var NeTL : NeTermList .
  var M : Module .
  var UPS : UnificationPairSet .

  --- Combine UnificationPair ---------------------------------------------
  op _.._ : UnificationTriple UnificationTriple -> UnificationTriple .
  eq {S1,S1',N1} .. {S2,S2',N2} = {S1 .. S2,S1' .. S2',max(N1,N2)} .

  --- UnificationPairSet --------------------------------------------------
  sort UnificationTripleSet .
  subsort UnificationTriple < UnificationTripleSet .
  op empty : -> UnificationTripleSet [ctor] .
  op _|_ : UnificationTripleSet UnificationTripleSet
        -> UnificationTripleSet
    [ctor assoc comm id: empty format (d n d d)] .
  eq X:UnificationTriple | X:UnificationTriple = X:UnificationTriple .

  op _..._ : UnificationTripleSet [UnificationTripleSet]
          -> UnificationTripleSet [strat (1) gather (e E)] .

  eq (empty).UnificationTripleSet ... US':[UnificationTripleSet]
   = (empty).UnificationTripleSet .
  eq (U | US) ... US':[UnificationTripleSet]
   = (U ...' US':[UnificationTripleSet])
     |
     (US ... US':[UnificationTripleSet]) .

  op _...'_ : UnificationTriple UnificationTripleSet
           -> UnificationTripleSet .

  eq U ...' (empty).UnificationTripleSet
   = (empty).UnificationTripleSet .

  eq U ...' (U' | US')
   = (U .. U')
     |
     (U ...' US') .

  --- convert  -----------------------------------------------------
  op split : UnificationPair Nat -> UnificationTriple .
  eq split({none,N},N') = {none,none,N} .
  eq split({(V <- T') ; S,N},N')
   = if highestVar(V) < N'
     then {(V <- T'),none,N}
     else {none,(V <- T'),N}
     fi
     .. split({S,N},N') .

  op split : UnificationPairSet Term Term -> UnificationTripleSet .
  eq split(empty,T,T') = empty .
  eq split({S,N} | UPS,T,T') = {S |> T, S |> T',N} | split(UPS,T,T') .

  op toUnificationTriple[_]`(_`) :
             Nat SubstitutionSet -> UnificationTripleSet .
  eq toUnificationTriple[N](SS)
   = toUnificationTriple*[N](SS,empty) .

  op toUnificationTriple*[_]`(_,_`) :
             Nat SubstitutionSet
             UnificationTripleSet -> UnificationTripleSet .
  eq toUnificationTriple*[N](empty,US)
   = US .
  eq toUnificationTriple*[N](S | SS,US)
   = toUnificationTriple*[N](SS, US | {none,S,highestVar(S,N)}) .

  op toUnificationTriple[_,_]`(_`) :
             Nat Nat SubstitutionSet -> UnificationTripleSet .
  eq toUnificationTriple[NextVar,N](SS)
   = toUnificationTriple*[NextVar,N](SS,empty) .

  op toUnificationTriple*[_,_]`(_,_`) :
             Nat Nat SubstitutionSet
             UnificationTripleSet -> UnificationTripleSet .
  eq toUnificationTriple*[NextVar,N](empty,US)
   = US .
  eq toUnificationTriple*[NextVar,N](S | SS,US)
   = toUnificationTriple*[NextVar,N](SS,
             US | split({S,highestVar(S,N)},NextVar)) .

  op toUnificationTriple[_,_,_]`(_`) :
             Term Term Nat SubstitutionSet -> UnificationTripleSet .
  eq toUnificationTriple[T,T',N](SS)
   = toUnificationTriple*[T,T',N](SS,empty) .

  op toUnificationTriple*[_,_,_]`(_,_`) :
             Term Term Nat SubstitutionSet
             UnificationTripleSet -> UnificationTripleSet .
  eq toUnificationTriple*[T,T',N](empty,US)
   = US .
  eq toUnificationTriple*[T,T',N](S | SS,US)
   = toUnificationTriple*[T,T',N](SS, US | {S |> T,S |> T',highestVar(S,N)}) .

  op toSubstitution : UnificationTripleSet -> SubstitutionSet .
  eq toSubstitution(US)
   = toSubstitution*(US,empty) .

  op toSubstitution* : UnificationTripleSet
                       SubstitutionSet -> SubstitutionSet .
  eq toSubstitution*((empty).UnificationTripleSet,SS)
   = SS .
  eq toSubstitution*({S,S',N} | US,SS)
   = toSubstitution*(US,SS | (S ; S')) .

  op _in_ : UnificationTriple UnificationTripleSet -> Bool .
  eq X:UnificationTriple
     in (X:UnificationTriple | XS:UnificationTripleSet) = true .
  eq X:UnificationTriple in XS:UnificationTripleSet = false [owise] .

  --- restriction ---------------------------------------------------
  op _|>_ : UnificationTripleSet TermList -> UnificationTripleSet .
  eq US |> TL
   = US *|> TL [empty] .

  op _*|>_[_] : UnificationTripleSet TermList
               UnificationTripleSet -> UnificationTripleSet .
  eq (empty).UnificationTripleSet *|> TL [US']
   = US' .
  eq ({S,S',N} | US) *|> TL [US']
   = US *|> TL [US' | {(S |> TL),(S' |> TL),N} ] .

  op _filterBy_ : UnificationTripleSet Nat -> UnificationTripleSet .
  eq US filterBy NextVar
   = US filterBy* NextVar [empty] .

  op _filterBy*_[_] : UnificationTripleSet Nat
                     UnificationTripleSet -> UnificationTripleSet .
  eq empty filterBy* NextVar [US']
   = US' .
  eq ({S,S',N} | US) filterBy* NextVar [US']
   = US filterBy* NextVar
     [US' | if S instantiatesAbove NextVar then empty else {S,S',N} fi ] .
endfm

fmod MODULE-HANDLING is
  protecting INT .
  protecting META-LEVEL-MNPA .
  protecting EXT-BOOL . *** From Full Maude
  protecting SUBSTITUTION-HANDLING .
  protecting UNIFICATIONTRIPLESET .

  var T T' T'' T1 T2 Lhs Rhs : Term .
  var C C' : Constant .
  var QIL : QidList .
  var N N' : Nat .
  var NL NL' : NatList .
  var Q F F' : Qid .
  vars AtS AtS' : AttrSet .
  var EqS : EquationSet .
  var Eq : Equation .
  var RlS : RuleSet .
  var Rl : Rule .
  var Cond : Condition .
  var TP TP' : Type .
  var TPL TPL' : TypeList .
  ---var TPL TPL' : ETypeList .
  ---var ET ET' : EType .
  var VDS OPDS : OpDeclSet .
  var OPD : OpDecl .
  var M : Module .
  var TL TL' TL'' : TermList .
  var B : Bool .
  var V V' : Variable .
  var I  : Int .
  vars S S' : Substitution .
  var US : UnificationTripleSet .

  *** canonice  ******************************
  op canonice : Module Term -> Term .
---  eq canonice(M,T) = getTerm(metaReduce(eraseRls(eraseEqs(M)),T)) .
  eq canonice(M,T) = getTerm(metaNormalize(M,T)) .

  op canonice : Module Substitution -> Substitution .
  eq canonice(M,(none).Substitution) = none .
  eq canonice(M,V <- T ; S) = V <- canonice(M,T) ; canonice(M,S)  .

  op canonice : Module UnificationTripleSet -> UnificationTripleSet .
  eq canonice(M,(empty).UnificationTripleSet) = (empty).UnificationTripleSet .
  eq canonice(M,{S,S',N} | US) = {canonice(M,S),canonice(M,S'),N} | canonice(M,US) .


  *** normalize  ******************************
  op normalize : Module Term -> Term .
  eq normalize(M,T) = getTerm(metaReduce(eraseRls(M),T)) .

  op normalize : Module Substitution -> Substitution .
  eq normalize(M,(none).Substitution) = none .
  eq normalize(M,V <- T ; S) = V <- normalize(M,T) ; normalize(M,S)  .

  *** normalizeRls  ******************************
  op normalizeRls : Module Term -> Term .
  eq normalizeRls(M,T) = getTerm(metaReduce(rls2eqs(M),T)) .

  op normalizeRls : Module Substitution -> Substitution .
  eq normalizeRls(M,(none).Substitution) = none .
  eq normalizeRls(M,V <- T ; S) = V <- normalizeRls(M,T) ; normalizeRls(M,S)  .

  *** typeLeq **************************************************
  op typeLeq : Module TypeList TypeList ~> Bool [memo] .

  eq typeLeq(M,TP:Sort TPL,TP':Sort TPL')
   = sortLeq(M,TP:Sort,TP':Sort) and typeLeq(M,TPL,TPL') .
  eq typeLeq(M,TP:Sort TPL,TP':Kind TPL')
   = getKind(M,TP:Sort) == TP':Kind
     and typeLeq(M,TPL,TPL') .
  eq typeLeq(M,TP:Kind TPL,TP':Sort TPL')
   = false .
  eq typeLeq(M,TP:Kind TPL,TP':Kind TPL')
   = TP:Kind == TP':Kind and typeLeq(M,TPL,TPL') .
  eq typeLeq(M,nil,nil)
   = true .

  *** getTypes **************************************************
  op getTypes : Module TermList -> TypeList . ---Memo is huge
  eq getTypes(M, (T, TL)) = leastSort(M, T) getTypes(M, TL) .
  eq getTypes(M, empty) = nil .

  *** getFrozen ************************************************
  op getFrozen : Module Qid TypeList -> NatList [memo] .
  eq getFrozen(M,F,TPL) = getFrozen(getOpsOfQid(M,F,TPL)) .

  op getFrozen : OpDeclSet -> NatList .
  eq getFrozen((op F : TPL -> TP [frozen(NL) AtS] .) OPDS) = NL .
  eq getFrozen(OPDS) = 0 [owise] .

  *** inNatList ************************************************
  op _inNatList_ : Nat NatList -> Bool .
  eq N inNatList (NL N NL') = true .
  eq N inNatList NL = false [owise] .

  *** membership ************************************************
  op _in_ : Type TypeList ~> Bool .
  eq TP in (TPL TP TPL') = true .
  eq TP in TPL = false [owise] .

  *** isConstructor  ******************************
  op isConstructor : Module Term -> Bool .
  op isConstructor : Module Qid TypeList -> Bool [memo] .
  op isConstructor : OpDeclSet -> Bool .

  eq isConstructor(M,V) = false .
  eq isConstructor(M,C) = isConstructor(M,C,nil) .
  eq isConstructor(M,F[TL]) = isConstructor(M,F,getTypes(M,TL)) .

  eq isConstructor(M,F,TPL)
   = getEqsOfQid(M,F,TPL) == none or-else isConstructor(getOpsOfQid(M,F,TPL)) .

  eq isConstructor((op F : TPL -> TP [ctor AtS] .) OPDS) = true .
  eq isConstructor(OPDS) = false [owise] .

  *** getOpsOfType ***********************************************
  op getOpsOfType : Module Type -> OpDeclSet [memo] .
  op getOpsOfType : Module OpDeclSet Type -> OpDeclSet .

  eq getOpsOfType(M,TP) = getOpsOfType(M,getOps(M),TP) .

  eq getOpsOfType(M,((op F : TPL -> TP [AtS] .) OPDS),TP')
    = if TP == TP'
      then (op F : TPL -> TP [AtS] .)
           getOpsOfType(M,OPDS,TP')
      else getOpsOfType(M,OPDS,TP')
      fi .

  eq getOpsOfType(M,OPDS,TP)
   = none
     [owise] .

  *** getOpsOfQid ***********************************************
  op getOpsOfQid : Module Qid -> OpDeclSet [memo] .
  op getOpsOfQid : Module Qid TypeList -> OpDeclSet [memo] .
  op getOpsOfQid : Module OpDeclSet Qid -> OpDeclSet .
  op getOpsOfQid : Module OpDeclSet Qid TypeList -> OpDeclSet .

  eq getOpsOfQid(M,F)
   = getOpsOfQid(M,getOps(M),F) .

  eq getOpsOfQid(M,F,TPL)
   = if getOpsOfQid(M,getOps(M),F,TPL) =/= none
     then getOpsOfQid(M,getOps(M),F,TPL)
     else getOpsOfQid(M,getOps(M),F,restrict TPL To 2)
     fi .

  eq getOpsOfQid(M,((op F : TPL -> TP [AtS] .) OPDS),F)
    = (op F : TPL -> TP [AtS] .)
      getOpsOfQid(M,OPDS,F) .

  eq getOpsOfQid(M,OPDS,F')
   = none
     [owise] .

  eq getOpsOfQid(M,((op F : TPL -> TP [AtS] .) OPDS),F,TPL')
    = if eSameKind(M,TPL,TPL')
      then (op F : TPL -> TP [AtS] .)
           getOpsOfQid(M,OPDS,F,TPL')
      else getOpsOfQid(M,OPDS,F,TPL')
      fi .

  eq getOpsOfQid(M,OPDS,F',TPL')
   = none
     [owise] .

  op restrict_To_ : TypeList Nat -> TypeList .
  eq restrict nil To NL = nil .
  eq restrict TPL To 0 = nil .
  eq restrict (TP,TPL) To s(N) = (TP, restrict TPL To N) .

  *** getOpsOfEqs ******************************************************
  op getOpsOfEqs : EquationSet -> QidList [memo] .
  eq getOpsOfEqs((eq C = T' [AtS] .) EqS )
   = C getOpsOfEqs(EqS) .
  eq getOpsOfEqs((eq F[TL] = T' [AtS] .) EqS )
   = F getOpsOfEqs(EqS) .
  eq getOpsOfEqs((none).EquationSet)
   = nil .

  *** getEqsOfQid ******************************************************
  op getEqsOfQid : Module Qid TypeList -> EquationSet [memo] .
  op getEqsOfQid : Module Qid TypeList EquationSet -> EquationSet .

  eq getEqsOfQid(M, F,TPL) = getEqsOfQid(M, F, TPL, getEqs(M)) .

  ceq getEqsOfQid(M, F, TPL, (eq C = T' [AtS] .) EqS )
   = (eq C = T' [AtS] .) getEqsOfQid(M, F, TPL, EqS)
   if F == C .
  ceq getEqsOfQid(M, F, TPL, (eq F[TL] = T' [AtS] .) EqS )
   = (eq F[TL] = T' [AtS] .) getEqsOfQid(M, F, TPL, EqS)
   if eSameKind(M,getTypes(M,TL),TPL) .
  ceq getEqsOfQid(M, F, TPL, (ceq C = T' if Cond [AtS] .) EqS )
   = (ceq C = T' if Cond [AtS] .) getEqsOfQid(M, F, TPL, EqS)
   if F == C .
  ceq getEqsOfQid(M, F, TPL, (ceq F[TL] = T' if Cond [AtS] .) EqS )
   = (ceq F[TL] = T' if Cond [AtS] .) getEqsOfQid(M, F, TPL, EqS)
   if eSameKind(M,getTypes(M,TL),TPL) .
  eq getEqsOfQid(M, F, TPL, Eq EqS )
   = getEqsOfQid(M, F, TPL, EqS) [owise] .
  eq getEqsOfQid(M, F, TPL, (none).EquationSet )
   = (none).EquationSet .

  *** getTypesOfQid  ****************************************
  op getTypesOfQid : Module Qid TypeList -> TypeSet [memo] .
  op getTypesOfQid : OpDeclSet -> TypeSet .

  eq getTypesOfQid(M,F,TPL) = getTypesOfQid(getOpsOfQid(M,F,TPL)) .
  eq getTypesOfQid((op F : TPL -> TP [AtS] .) OPDS)
   = TP ; getTypesOfQid(OPDS) .
  eq getTypesOfQid((none).OpDeclSet) = (none).TypeSet .

  *** filterConstructorSymbols ************************************
  op filterConstructorSymbols : OpDeclSet -> OpDeclSet .
  eq filterConstructorSymbols(((op F : TPL -> TP [AtS] .) OPDS))
    = if isConstructor((op F : TPL -> TP [AtS] .) none)
      then (op F : TPL -> TP [AtS] .)
           filterConstructorSymbols(OPDS)
      else filterConstructorSymbols(OPDS)
      fi .
  eq filterConstructorSymbols(none)
    = none .

  *** filterDefinedSymbols *****************************************
  op filterDefinedSymbols : OpDeclSet -> OpDeclSet .
  eq filterDefinedSymbols(((op F : TPL -> TP [ctor AtS] .) OPDS))
    = filterDefinedSymbols(OPDS) .
  eq filterDefinedSymbols(((op F : TPL -> TP [AtS] .) OPDS))
    = (op F : TPL -> TP [AtS] .) filterDefinedSymbols(OPDS) [owise] .
  eq filterDefinedSymbols(none)
    = none .

  *** isCommutative ******************************
  op isCommutative : Module Term -> Bool .
  op isCommutative : Module Qid TypeList -> Bool [memo] .
  op isCommutative : OpDeclSet -> Bool .

  eq isCommutative(M,V) = false .
  eq isCommutative(M,C) = false .
  eq isCommutative(M,F[TL]) = isCommutative(M,F,getTypes(M,TL)) .

  eq isCommutative(M,F,TPL) = isCommutative(getOpsOfQid(M,F,TPL)) .

  eq isCommutative((op F : TPL -> TP [comm AtS] .) OPDS) = true .
  eq isCommutative(OPDS) = false [owise] .

  *** isAssociative ******************************
  op isAssociative : Module Term -> Bool .
  op isAssociative : Module Qid TypeList -> Bool [memo] .
  op isAssociative : OpDeclSet -> Bool .

  eq isAssociative(M,V) = false .
  eq isAssociative(M,C) = false .
  eq isAssociative(M,F[TL]) = isAssociative(M,F,getTypes(M,TL)) .

  eq isAssociative(M,F,TPL) = isAssociative(getOpsOfQid(M,F,TPL)) .

  eq isAssociative((op F : TPL -> TP [assoc AtS] .) OPDS) = true .
  eq isAssociative(OPDS) = false [owise] .

  *** getIdSymbol ******************************
  op getIdSymbol : Module Term ~> Term .
  eq getIdSymbol(M,F[TL]) = getIdSymbol(M,F,getTypes(M,TL)) .

  op getIdSymbol : Module Qid TypeList ~> Term [memo] .
  eq getIdSymbol(M,F,TPL) = getIdSymbol(getOpsOfQid(M,F,TPL)) .

  op getIdSymbol : OpDeclSet ~> Term .
  eq getIdSymbol((op F : TPL -> TP [id(T) AtS] .) OPDS) = T .

  op getLeftIdSymbol : Module Term ~> Term .
  eq getLeftIdSymbol(M,F[TL]) = getLeftIdSymbol(M,F,getTypes(M,TL)) .

  op getLeftIdSymbol : Module Qid TypeList ~> Term .
  eq getLeftIdSymbol(M,F,TPL) = getLeftIdSymbol(getOpsOfQid(M,F,TPL)) .

  op getLeftIdSymbol : OpDeclSet ~> Term .
  eq getLeftIdSymbol((op F : TPL -> TP [left-id(T) AtS] .) OPDS) = T .

  op getRightIdSymbol : Module Term ~> Term .
  eq getRightIdSymbol(M,F[TL]) = getRightIdSymbol(M,F,getTypes(M,TL)) .

  op getRightIdSymbol : Module Qid TypeList ~> Term .
  eq getRightIdSymbol(M,F,TPL) = getRightIdSymbol(getOpsOfQid(M,F,TPL)) .

  op getRightIdSymbol : OpDeclSet ~> Term .
  eq getRightIdSymbol((op F : TPL -> TP [right-id(T) AtS] .) OPDS) = T .

  *** anyIdSymbol ******************************
  op anyIdSymbol : Module Term -> Bool .
  eq anyIdSymbol(M,C:Constant)
   = false .
  eq anyIdSymbol(M,V:Variable)
   = false .
  eq anyIdSymbol(M,F:Qid[TL:TermList])
   = getIdSymbol(M,F:Qid[TL:TermList]) :: Term
     or-else
     anyIdSymbol*(M,TL:TermList) .

  op anyIdSymbol* : Module TermList -> Bool .
  eq anyIdSymbol*(M,empty)
   = false .
  eq anyIdSymbol*(M,(T:Term,TL:TermList))
   = anyIdSymbol(M,T:Term)
     or-else
     anyIdSymbol*(M,TL:TermList) .

  ****
  op anyIdSymbol : Module Substitution -> Bool .
  eq anyIdSymbol(M,(none).Substitution) = false .
  eq anyIdSymbol(M,V:Variable <- T:Term ; S:Substitution)
   = anyIdSymbol(M,T:Term)
     or-else
     anyIdSymbol(M,S:Substitution) .

  *** eSameKind ******************************
  op eSameKind : Module TypeList TypeList -> Bool [memo] .
  eq eSameKind(M,TP TPL, TP' TPL')
   = sameKind(M,TP,TP') and eSameKind(M,TPL,TPL') .
  eq eSameKind(M,nil,nil) = true .
  eq eSameKind(M,TPL,nil) = true .
  eq eSameKind(M,nil,TPL') = true .
  ---eq eSameKind(M,TPL,TPL') = false [owise] .

  *** eqs2rls *******************************
  sort EqSet&RlsSet .
  op {_,_} : EquationSet RuleSet -> EqSet&RlsSet .
  op getEqs : EqSet&RlsSet -> EquationSet .
  eq getEqs({EqS,RlS}) = EqS .
  op getRls : EqSet&RlsSet -> RuleSet .
  eq getRls({EqS,RlS}) = RlS .

  op eqs2rls# : EquationSet -> EqSet&RlsSet [memo] .
  eq eqs2rls#(none) = {none,none} .
  eq eqs2rls#((eq Lhs = Rhs [AtS] .) EqS)
   = {getEqs(eqs2rls#(EqS)),
      (rl Lhs => Rhs [AtS] .) getRls(eqs2rls#(EqS))
     } .
  eq eqs2rls#((ceq Lhs = Rhs if Cond [AtS] .) EqS)
   = {getEqs(eqs2rls#(EqS)),
      (crl Lhs => Rhs if Cond [AtS] .) getRls(eqs2rls#(EqS))
     } .

  op eqs2rls : SModule -> SModule .
  eq eqs2rls(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = mod (addsufix '-EQS2RLS To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       getEqs(eqs2rls#(E:EquationSet))
       getRls(eqs2rls#(E:EquationSet))
     endm .

  op eqs2rls : FModule -> FModule .
  eq eqs2rls(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = mod (addsufix '-EQS2RLS To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       getEqs(eqs2rls#(E:EquationSet))
       getRls(eqs2rls#(E:EquationSet))
     endm .

  op eqsNoBuiltInUnify2rls : SModule -> SModule .
  eq eqsNoBuiltInUnify2rls(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = mod (addsufix '-EQS2RLS To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       (getEqs(eqs2rls#(getEqsNoBuiltInUnify(E:EquationSet))) getEqsBuiltInUnify(E:EquationSet))
       getRls(eqs2rls#(getEqsNoBuiltInUnify(E:EquationSet)))
     endm .

  op eqsNoBuiltInUnify2rls : FModule -> SModule .
  eq eqsNoBuiltInUnify2rls(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = mod (addsufix '-EQS2RLS To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       (getEqs(eqs2rls#(getEqsNoBuiltInUnify(E:EquationSet))) getEqsBuiltInUnify(E:EquationSet))
       getRls(eqs2rls#(getEqsNoBuiltInUnify(E:EquationSet)))
     endm .

  op eqsNoVariant2rls : SModule -> SModule .
  eq eqsNoVariant2rls(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = mod (addsufix '-EQS2RLS To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       (getEqs(eqs2rls#(getEqsNoVariant(E:EquationSet))) getEqsVariant(E:EquationSet))
       getRls(eqs2rls#(getEqsNoVariant(E:EquationSet)))
     endm .

  op eqsNoVariant2rls : FModule -> SModule .
  eq eqsNoVariant2rls(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = mod (addsufix '-EQS2RLS To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       (getEqs(eqs2rls#(getEqsNoVariant(E:EquationSet))) getEqsVariant(E:EquationSet))
       getRls(eqs2rls#(getEqsNoVariant(E:EquationSet)))
     endm .

  op eqsVariant2rls : SModule -> SModule .
  eq eqsVariant2rls(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = mod (addsufix '-EQS2RLS To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       (getEqs(eqs2rls#(getEqsVariant(E:EquationSet))) getEqsNoVariant(E:EquationSet))
       getRls(eqs2rls#(getEqsVariant(E:EquationSet)))
     endm .

  op eqsVariant2rls : FModule -> SModule .
  eq eqsVariant2rls(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = mod (addsufix '-EQS2RLS To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       (getEqs(eqs2rls#(getEqsVariant(E:EquationSet))) getEqsNoVariant(E:EquationSet))
       getRls(eqs2rls#(getEqsVariant(E:EquationSet)))
     endm .

  op removeVariantLabel : SModule -> SModule .
  eq removeVariantLabel(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = mod (addsufix '-EQSV2EQSNV To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       removeVariantLabel(E:EquationSet)
       R:RuleSet
      endm .

  op removeVariantLabel : FModule -> SModule .
  eq removeVariantLabel(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = fmod (addsufix '-EQSV2EQSNV To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       removeVariantLabel(E:EquationSet)
     endfm .

  op removeVariantLabel : EquationSet -> EquationSet .
  eq removeVariantLabel((eq Lhs = Rhs [AtS variant] .) EqS)
   = (eq Lhs = Rhs [AtS] .)
     removeVariantLabel(EqS) .
  eq removeVariantLabel(EqS)
   = EqS [owise] .

  *** getEqsNoBuiltInUnify *******************************
  op getEqsNoBuiltInUnify : Module -> EquationSet .
  eq getEqsNoBuiltInUnify(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = getEqsNoBuiltInUnify(E:EquationSet) .
  eq getEqsNoBuiltInUnify(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = getEqsNoBuiltInUnify(E:EquationSet) .

  op getEqsNoBuiltInUnify : EquationSet -> EquationSet [memo] .
  eq getEqsNoBuiltInUnify(none) = none .
  eq getEqsNoBuiltInUnify((eq Lhs = Rhs [AtS metadata("builtin-unify")] .) EqS)
   = getEqsNoBuiltInUnify(EqS) .
  eq getEqsNoBuiltInUnify((eq Lhs = Rhs [AtS] .) EqS)
   = (eq Lhs = Rhs [AtS] .) getEqsNoBuiltInUnify(EqS)
  [owise] .
  eq getEqsNoBuiltInUnify((ceq Lhs = Rhs if Cond [AtS] .) EqS)
   = (ceq Lhs = Rhs if Cond [AtS] .) getEqsNoBuiltInUnify(EqS) .

  *** getEqsNoVariant *******************************
  op getEqsNoVariant : Module -> EquationSet .
  eq getEqsNoVariant(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = getEqsNoVariant(E:EquationSet) .
  eq getEqsNoVariant(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = getEqsNoVariant(E:EquationSet) .

  op getEqsNoVariant : EquationSet -> EquationSet [memo] .
  eq getEqsNoVariant(none) = none .
  eq getEqsNoVariant((eq Lhs = Rhs [AtS variant] .) EqS)
   = getEqsNoVariant(EqS) .
  eq getEqsNoVariant((eq Lhs = Rhs [AtS] .) EqS)
   = (eq Lhs = Rhs [AtS] .) getEqsNoVariant(EqS)
  [owise] .
  eq getEqsNoVariant((ceq Lhs = Rhs if Cond [AtS] .) EqS)
   = (ceq Lhs = Rhs if Cond [AtS] .) getEqsNoVariant(EqS) .

  *** getEqsVariant *******************************
  op getEqsVariant : Module -> EquationSet .
  eq getEqsVariant(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = getEqsVariant(E:EquationSet) .
  eq getEqsVariant(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = getEqsVariant(E:EquationSet) .

  op getEqsVariant : EquationSet -> EquationSet [memo] .
  eq getEqsVariant(none) = none .
  eq getEqsVariant((eq Lhs = Rhs [AtS variant] .) EqS)
   = (eq Lhs = Rhs [AtS variant] .)
     getEqsVariant(EqS) .
  eq getEqsVariant((eq Lhs = Rhs [AtS] .) EqS)
   = getEqsVariant(EqS)
  [owise] .
  eq getEqsVariant((ceq Lhs = Rhs if Cond [AtS] .) EqS)
   = (ceq Lhs = Rhs if Cond [AtS] .) getEqsVariant(EqS) .

  *** onlyEqsNoBuiltInUnify *******************************
  op onlyEqsNoBuiltInUnify : Module -> Module .
  eq onlyEqsNoBuiltInUnify(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = fmod (addsufix '-OnlyEqsNoBuiltInUnify To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       getEqsNoBuiltInUnify(E:EquationSet)
     endfm .
  eq onlyEqsNoBuiltInUnify(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = mod (addsufix '-OnlyEqsNoBuiltInUnify To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       getEqsNoBuiltInUnify(E:EquationSet)
       R:RuleSet
     endm .

  *** onlyEqsNoVariant *******************************
  op onlyEqsNoVariant : Module -> Module .
  eq onlyEqsNoVariant(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = fmod (addsufix '-OnlyEqsNoVariant To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       getEqsNoVariant(E:EquationSet)
     endfm .
  eq onlyEqsNoVariant(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = mod (addsufix '-OnlyEqsNoVariant To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       getEqsNoVariant(E:EquationSet)
       R:RuleSet
     endm .

  *** getEqsBuiltInUnify *******************************
  op getEqsBuiltInUnify : Module -> EquationSet .
  eq getEqsBuiltInUnify(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = getEqsBuiltInUnify(E:EquationSet) .
  eq getEqsBuiltInUnify(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = getEqsBuiltInUnify(E:EquationSet) .

  op getEqsBuiltInUnify : EquationSet -> EquationSet [memo] .
  eq getEqsBuiltInUnify(none) = none .
  eq getEqsBuiltInUnify((eq Lhs = Rhs [AtS metadata("builtin-unify")] .) EqS)
   = (eq Lhs = Rhs [AtS metadata("builtin-unify")] .) getEqsBuiltInUnify(EqS) .
  eq getEqsBuiltInUnify((eq Lhs = Rhs [AtS] .) EqS)
   = getEqsBuiltInUnify(EqS)
  [owise] .
  eq getEqsBuiltInUnify((ceq Lhs = Rhs if Cond [AtS] .) EqS)
   = getEqsBuiltInUnify(EqS) .

  *** getEqsVariant *******************************
  op getEqsVariant : Module -> EquationSet .
  eq getEqsVariant(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = getEqsVariant(E:EquationSet) .
  eq getEqsVariant(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = getEqsVariant(E:EquationSet) .

  op getEqsVariant : EquationSet -> EquationSet [memo] .
  eq getEqsVariant(none) = none .
  eq getEqsVariant((eq Lhs = Rhs [AtS variant] .) EqS)
   = (eq Lhs = Rhs [AtS variant] .) getEqsVariant(EqS) .
  eq getEqsVariant((eq Lhs = Rhs [AtS] .) EqS)
   = getEqsVariant(EqS)
  [owise] .
  eq getEqsVariant((ceq Lhs = Rhs if Cond [AtS] .) EqS)
   = getEqsVariant(EqS) .

  *** onlyEqsBuiltInUnify *******************************
  op onlyEqsBuiltInUnify : Module -> Module .
  eq onlyEqsBuiltInUnify(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       getEqsBuiltInUnify(E:EquationSet)
     endfm .
  eq onlyEqsBuiltInUnify(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       getEqsBuiltInUnify(E:EquationSet)
       R:RuleSet
     endm .

  *** onlyEqsVariant *******************************
  op onlyEqsVariant : Module -> Module .
  eq onlyEqsVariant(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       getEqsVariant(E:EquationSet)
     endfm .
  eq onlyEqsVariant(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       getEqsVariant(E:EquationSet)
       R:RuleSet
     endm .

  *** rls2eqs *******************************
  op rls2eqs# : RuleSet -> EquationSet [memo] .
  eq rls2eqs#(none) = none .
  eq rls2eqs#((rl Lhs => Rhs [AtS] .) RlS)
   = (eq Lhs = Rhs [AtS] .) rls2eqs#(RlS) .
  eq rls2eqs#((crl Lhs => Rhs if Cond [AtS] .) RlS)
   = (ceq Lhs = Rhs if Cond [AtS] .) rls2eqs#(RlS) .

  op rls2eqs : SModule -> SModule .
  eq rls2eqs(
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = mod (addsufix '-RLS2EQS To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet rls2eqs#(R:RuleSet)
       none
     endm .

  *** flipRls *******************************
  op flipRls : RuleSet -> RuleSet [memo] .
  eq flipRls(none) = none .
  eq flipRls((rl Lhs => Rhs [AtS] .) RlS:RuleSet)
   = if all Vars(Lhs) in Vars(Rhs)
     then (rl Rhs => Lhs [removeNonExec(AtS)] .)
     else (rl Rhs => Lhs [nonexec removeNonExec(AtS)] .)
     fi
     flipRls(RlS:RuleSet) .
  eq flipRls((crl Lhs => Rhs if Cond [AtS] .) RlS:RuleSet)
   = if all Vars(Lhs) in Vars(Rhs)
     then (crl Rhs => Lhs if Cond [removeNonExec(AtS)] .)
     else (crl Rhs => Lhs if Cond [nonexec removeNonExec(AtS)] .)
     fi
     flipRls(RlS:RuleSet) .

  op removeNonExec : AttrSet -> AttrSet .
  eq removeNonExec(nonexec AtS) = AtS .
  eq removeNonExec(AtS) = AtS [owise] .

  op flipRls : SModule -> SModule .
  eq flipRls(mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
             O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm)
   = mod (addsufix '-FLIPPEDRLS To Q:Qid)
     is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
     O:OpDeclSet M:MembAxSet E:EquationSet flipRls(R:RuleSet) endm .

  *** addOp *******************************
  op addOps : OpDeclSet SModule -> SModule .
  eq addOps(OO:OpDeclSet,mod Q:Qid is IL:ImportList sorts S:SortSet .
      S:SubsortDeclSet O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm)
   = mod (addsufix '-ADDEDOPS To Q:Qid)
     is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
     override(O:OpDeclSet,OO:OpDeclSet)
     M:MembAxSet E:EquationSet R:RuleSet endm .
  op addOps : OpDeclSet FModule -> FModule .
  eq addOps(OO:OpDeclSet,fmod Q:Qid is IL:ImportList sorts S:SortSet .
      S:SubsortDeclSet O:OpDeclSet M:MembAxSet E:EquationSet endfm)
   = fmod (addsufix '-ADDEDOPS To Q:Qid)
     is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
     override(O:OpDeclSet,OO:OpDeclSet)
     M:MembAxSet E:EquationSet endfm .

  op override : OpDeclSet OpDeclSet -> OpDeclSet .
  eq override(
      (op F : TPL -> TP [AtS] .)  O:OpDeclSet,
      (op F : TPL -> TP [AtS'] .) O':OpDeclSet)
   = override(O:OpDeclSet,(op F : TPL -> TP [AtS'] .) O':OpDeclSet) .
  eq override(O:OpDeclSet,O':OpDeclSet)
   = O:OpDeclSet O':OpDeclSet [owise] .

  *** addRules *******************************
  op addRules : RuleSet SModule -> SModule [memo] .
  eq addRules(RR:RuleSet,mod Q:Qid is IL:ImportList sorts S:SortSet .
          S:SubsortDeclSet O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm)
   = mod (addsufix '-ADDEDRLS To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet (R:RuleSet RR:RuleSet) endm .

  *** addEqs *******************************
  op addEqs : EquationSet SModule -> SModule .
  op addEqs : EquationSet FModule -> FModule .
  eq addEqs(ES:EquationSet,mod Q:Qid is IL:ImportList sorts S:SortSet .
          S:SubsortDeclSet O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm)
   = mod (addsufix '-ADDEDEQS To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet (E:EquationSet ES:EquationSet) R:RuleSet endm .
  eq addEqs(ES:EquationSet,fmod Q:Qid is IL:ImportList sorts S:SortSet .
          S:SubsortDeclSet O:OpDeclSet M:MembAxSet E:EquationSet endfm)
   = fmod (addsufix '-ADDEDEQS To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet (E:EquationSet ES:EquationSet) endfm .

  *** addSorts *******************************
  op addSorts : SortSet SModule -> SModule .
  op addSorts : SortSet FModule -> FModule .
  eq addSorts(X:SortSet,
       mod Q:Qid is IL:ImportList sorts S:SortSet .
       S:SubsortDeclSet O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm)
   = mod Q:Qid is IL:ImportList sorts (X:SortSet ; S:SortSet) .
       S:SubsortDeclSet O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm .
  eq addSorts(X:SortSet,
       fmod Q:Qid is IL:ImportList sorts S:SortSet .
       S:SubsortDeclSet O:OpDeclSet M:MembAxSet E:EquationSet endfm)
   = fmod Q:Qid is IL:ImportList sorts (X:SortSet ; S:SortSet) .
       S:SubsortDeclSet O:OpDeclSet M:MembAxSet E:EquationSet endfm .

  *** putFrozen *******************************
  op putFrozen : NatList Qid TypeList SModule -> SModule [memo] .
  eq putFrozen(NL,F,TPL,
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [frozen(NL') AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod (addsufix F To (addsufix '-FROZEN# To Q:Qid))
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [frozen(NL) AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm) .
  eq putFrozen(NL,F,TPL,
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod (addsufix F To (addsufix '-FROZEN# To Q:Qid))
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [frozen(NL) AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm) [owise] .

  *** putStrat *******************************
  op putStrat : NatList Qid TypeList SModule -> SModule [memo] .
  eq putStrat(NL,F,TPL,
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [strat(NL') AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod (addsufix F To (addsufix '-STRAT#EQ# To Q:Qid))
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [strat(NL) AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm) .
  eq putStrat(NL,F,TPL,
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod (addsufix F To (addsufix '-STRAT#EQ# To Q:Qid))
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [strat(NL) AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm) [owise] .

  op putStrat : NatList Qid TypeList FModule -> FModule [memo] .
  eq putStrat(NL,F,TPL,
     (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [strat(NL') AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet endfm))
   = (fmod (addsufix F To (addsufix '-STRAT#EQ# To Q:Qid))
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [strat(NL) AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet endfm) .
  eq putStrat(NL,F,TPL,
     (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet endfm))
   = (fmod (addsufix F To (addsufix '-STRAT#EQ# To Q:Qid))
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [strat(NL) AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet endfm) [owise] .

  *** clearFrozen *******************************
  op clearFrozen : NatList Qid TypeList SModule -> SModule [memo] .
  eq clearFrozen(NL,F,TPL,
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [frozen(NL') AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [AtS] .) O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm) .
  eq clearFrozen(NL,F,TPL,M)
   = M [owise] .

  *** clearEqsFrozen *******************************
  op clearEqsFrozen : SModule -> SModule [memo] .
  eq clearEqsFrozen(M)
   = clearEqsFrozen*(M) .

  op clearEqsFrozen* : SModule -> SModule .
  eq clearEqsFrozen*(
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [frozen(NL') AtS] .) O:OpDeclSet)
      M:MembAxSet
      ((eq F[TL] = Rhs [AtS'] .) E:EquationSet)
      R:RuleSet endm))
   = clearEqsFrozen*(
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      ((op F : TPL -> TP [AtS] .) O:OpDeclSet)
      M:MembAxSet
      ((eq F[TL] = Rhs [AtS'] .) E:EquationSet)
      R:RuleSet endm)) .
  eq clearEqsFrozen*(M)
   = M [owise] .

  *** clearAllFrozen *******************************
  op clearAllFrozen : SModule -> SModule [memo] .
  eq clearAllFrozen(
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet
      M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod (addsufix '-CLEARFROZEN To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      clearAllFrozen(O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm) .

  op clearAllFrozen : FModule -> FModule [memo] .
  eq clearAllFrozen(
     (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet
      M:MembAxSet E:EquationSet endfm))
   = (fmod (addsufix '-CLEARFROZEN To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      clearAllFrozen(O:OpDeclSet)
      M:MembAxSet E:EquationSet endfm) .

  op clearAllFrozen : OpDeclSet -> OpDeclSet .
  eq clearAllFrozen(none)
   = none .
  eq clearAllFrozen(
      (op F : TPL -> TP [frozen(NL) AtS] .) O:OpDeclSet)
   = (op F : TPL -> TP [AtS] .)
     clearAllFrozen(O:OpDeclSet) .
  eq clearAllFrozen(
      (op F : TPL -> TP [AtS] .) O:OpDeclSet)
   = (op F : TPL -> TP [AtS] .)
     clearAllFrozen(O:OpDeclSet) [owise] .

  *** anyNonExec *******************************
  op anyNonExec : SModule -> Bool [memo] .
  eq anyNonExec(
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm))
   = anyNonExec(E:EquationSet) or-else anyNonExec(R:RuleSet) .

  op anyNonExec : RuleSet -> Bool .
  eq anyNonExec(
      (rl Lhs => Rhs [nonexec AtS] .) R:RuleSet)
   = true .
  eq anyNonExec(
      (crl Lhs => Rhs if Cond [nonexec AtS] .) R:RuleSet)
   = true .
  eq anyNonExec(R:RuleSet)
   = false [owise] .

  op anyNonExec : EquationSet -> Bool .
  eq anyNonExec(
      (eq Lhs = Rhs [nonexec AtS] .) R:EquationSet)
   = true .
  eq anyNonExec(
      (ceq Lhs = Rhs if Cond [nonexec AtS] .) R:EquationSet)
   = true .
  eq anyNonExec(R:EquationSet)
   = false [owise] .

  *** clearNonExec *******************************
  op clearNonExecRls&Eqs : SModule -> SModule [memo] .
  eq clearNonExecRls&Eqs(M:SModule)
   = clearNonExecRls(clearNonExecEqs(M:SModule)) .

  op clearNonExecRls : SModule -> SModule [memo] .
  eq clearNonExecRls(
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod (addsufix '-CLEARNONEXEC To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet
        E:EquationSet clearNonExec(R:RuleSet) endm) .

  op clearNonExecEqs : SModule -> SModule [memo] .
  eq clearNonExecEqs(
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod (addsufix '-CLEARNONEXEC To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet
        clearNonExec(E:EquationSet) R:RuleSet endm) .

  op clearNonExecEqs : FModule -> FModule [memo] .
  eq clearNonExecEqs(
     (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet endfm))
   = (fmod (addsufix '-CLEARNONEXEC To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet
        clearNonExec(E:EquationSet) endfm) .

  op clearNonExec : RuleSet -> RuleSet .
  eq clearNonExec((none).RuleSet)
   = (none).RuleSet .
  eq clearNonExec(
      (rl Lhs => Rhs [nonexec AtS] .) R:RuleSet)
   = (rl Lhs => Rhs [AtS] .)
     clearNonExec(R:RuleSet) .
  eq clearNonExec(
      (rl Lhs => Rhs [AtS] .) R:RuleSet)
   = (rl Lhs => Rhs [AtS] .)
     clearNonExec(R:RuleSet) [owise] .

  op clearNonExec : EquationSet -> EquationSet .
  eq clearNonExec((none).EquationSet)
   = (none).EquationSet .
  eq clearNonExec(
      (eq Lhs = Rhs [nonexec AtS] .) R:EquationSet)
   = (eq Lhs = Rhs [AtS] .)
     clearNonExec(R:EquationSet) .
  eq clearNonExec(
      (eq Lhs = Rhs [AtS] .) R:EquationSet)
   = (eq Lhs = Rhs [AtS] .)
     clearNonExec(R:EquationSet) [owise] .

  *** eraseRls *******************************
  op eraseRls : Module -> Module [memo] .
  eq eraseRls(
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet none endm) .
  eq eraseRls(
     (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet endfm))
   = (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet endfm) .

  *** eraseEqs *******************************
  op eraseEqs : Module -> Module [memo] .
  eq eraseEqs(
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet none R:RuleSet endm) .
  eq eraseEqs(
     (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet endfm))
   = (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet none endfm) .

  *** flatten  ******************************
  op flatten : Module TermList -> TermList .
  eq flatten(M,V) = V .
  eq flatten(M,C) = C .
  eq flatten(M,F[TL:NeTermList])
   = if isAssociative(M,F,getTypes(M,TL:NeTermList))
     then F[aliens(TL:NeTermList,F)]
     else F[flatten(M,TL:NeTermList)]
     fi .
  eq flatten(M,(T:Term,TL:NeTermList))
   = (flatten(M,T:Term),flatten(M,TL:NeTermList)) .

  op aliens : TermList Qid -> TermList .
  eq aliens(empty,F) = empty .
  eq aliens((F[TL':NeTermList],TL:TermList),F)
   = aliens((TL':NeTermList,TL:TermList),F) .
  eq aliens((T:Term,TL:TermList),F)
   = (T:Term,aliens(TL:TermList,F)) [owise] .

  *** unflatten  ******************************
  op unflatten : Module TermList -> TermList .
  eq unflatten(M,T) = unflatten*(M,T) .

  op unflatten* : Module TermList -> TermList .
  eq unflatten*(M,V) = V .
  eq unflatten*(M,C) = C .
  eq unflatten*(M,F[TL:NeTermList])
   = if isAssociative(M,F,getTypes(M,TL:NeTermList))
     then unflatten**(M,F,TL:NeTermList)
     else F[unflatten*(M,TL:NeTermList)]
     fi .
  eq unflatten*(M,(T:Term,TL:NeTermList))
   = (unflatten*(M,T:Term),unflatten*(M,TL:NeTermList)) .

  op unflatten** : Module Qid TermList -> TermList .
  eq unflatten**(M,F,(T1:Term,TL:NeTermList))
   = F[unflatten*(M,T1:Term),unflatten**(M,F,TL:NeTermList)] .
  eq unflatten**(M,F,T:Term)
   = unflatten*(M,T:Term) .

  *** wrapRules_bySymbol_ *******************************
  op wrapRules_bySymbol_ : SModule Qid -> SModule [memo] .
  eq wrapRules
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet
      M:MembAxSet E:EquationSet R:RuleSet endm)
     bySymbol F:Qid
   = (mod (addsufix F:Qid To (addsufix '-WRAPPED# To Q:Qid))
       is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet
      M:MembAxSet E:EquationSet
      wrapRules R:RuleSet bySymbol F:Qid endm) .

  op wrapRules_bySymbol_ : RuleSet Qid -> RuleSet .
  eq wrapRules none bySymbol F:Qid = none .
  eq wrapRules ((rl Lhs => Rhs [AtS] .) RlS:RuleSet) bySymbol F:Qid
   = (rl F:Qid[Lhs] => F:Qid[Rhs] [AtS] .)
     wrapRules RlS:RuleSet bySymbol F:Qid .
  eq wrapRules ((crl Lhs => Rhs if Cond [AtS] .) RlS:RuleSet) bySymbol F:Qid
   = (crl F:Qid[Lhs] => F:Qid[Rhs] if Cond [AtS] .)
     wrapRules RlS:RuleSet bySymbol F:Qid .

  op toSModule : FModule -> SModule .
  eq toSModule(
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   =  mod (addsufix '-CONVERTED#SMODULE To Q:Qid) is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       none
      endm .

  op newName : Qid SModule -> SModule .
  op newName : Qid FModule -> FModule .
  eq newName(F:Qid,
      fmod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm)
   = fmod F:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
      endfm .
  eq newName(F:Qid,
      mod Q:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm)
   = mod F:Qid is
       IL:ImportList
       sorts S:SortSet .
       S:SubsortDeclSet
       O:OpDeclSet
       M:MembAxSet
       E:EquationSet
       R:RuleSet
      endm .

  ***
  op removeBoolEqs : Module -> Module [memo] .
  eq removeBoolEqs(
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet
      removeBoolEqs(E:EquationSet)
      R:RuleSet endm) .
  eq removeBoolEqs(
     (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet endfm))
   = (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet
      removeBoolEqs(E:EquationSet) endfm) .

  op removeBoolEqs : EquationSet -> EquationSet .
  eq removeBoolEqs((eq '_and_[TL] = Rhs [AtS] .) EqS)
   = removeBoolEqs(EqS) .
  eq removeBoolEqs((eq 'not_[TL] = Rhs [AtS] .) EqS)
   = removeBoolEqs(EqS) .
  eq removeBoolEqs((eq '_or_[TL] = Rhs [AtS] .) EqS)
   = removeBoolEqs(EqS) .
  eq removeBoolEqs((eq '_xor_[TL] = Rhs [AtS] .) EqS)
   = removeBoolEqs(EqS) .
  eq removeBoolEqs((eq '_implies_[TL] = Rhs [AtS] .) EqS)
   = removeBoolEqs(EqS) .
  eq removeBoolEqs(EqS)
   = EqS [owise] .

  *******************************************
  op keepOnlyACAttr : Module -> Module [memo] .
  eq keepOnlyACAttr(
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod (addsufix '-REMOVED-ID-SYMBOLS To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      keepOnlyACAttr*(O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm) .
  eq keepOnlyACAttr(
     (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet endfm))
   = (fmod (addsufix '-REMOVED-ID-SYMBOLS To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      keepOnlyACAttr*(O:OpDeclSet)
      M:MembAxSet E:EquationSet endfm) .

  op keepOnlyACAttr* : OpDeclSet -> OpDeclSet .
  eq keepOnlyACAttr*((op F : TPL -> TP [id(T) AtS] .) OPDS)
   = keepOnlyACAttr*((op F : TPL -> TP [AtS] .) OPDS) .
  eq keepOnlyACAttr*((op F : TPL -> TP [left-id(T) AtS] .) OPDS)
   = keepOnlyACAttr*((op F : TPL -> TP [AtS] .) OPDS) .
  eq keepOnlyACAttr*((op F : TPL -> TP [right-id(T) AtS] .) OPDS)
   = keepOnlyACAttr*((op F : TPL -> TP [AtS] .) OPDS) .
  eq keepOnlyACAttr*(OPDS)
   = removeAssocAttr(OPDS) [owise] .

  op _in#_ : Attr AttrSet -> Bool .
  eq X:Attr in# X:Attr X:AttrSet = true .
  eq X:Attr in# X:AttrSet = false [owise] .

  op removeAssocAttr : OpDeclSet -> OpDeclSet .
  eq removeAssocAttr((op F : TPL -> TP [assoc AtS] .) OPDS)
   = if comm in# AtS
     then (op F : TPL -> TP [assoc AtS] .) removeAssocAttr(OPDS)
     else removeAssocAttr((op F : TPL -> TP [AtS] .) OPDS)
     fi .
  eq removeAssocAttr(OPDS)
   = OPDS [owise] .

  *******************************************
  op keepOnlyACUAttr : Module -> Module [memo] .
  eq keepOnlyACUAttr(
     (mod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet R:RuleSet endm))
   = (mod (addsufix '-REMOVED-ID-SYMBOLS To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      keepOnlyACUAttr*(O:OpDeclSet)
      M:MembAxSet E:EquationSet R:RuleSet endm) .
  eq keepOnlyACUAttr(
     (fmod Q:Qid is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      O:OpDeclSet M:MembAxSet E:EquationSet endfm))
   = (fmod (addsufix '-REMOVED-ID-SYMBOLS To Q:Qid)
      is IL:ImportList sorts S:SortSet . S:SubsortDeclSet
      keepOnlyACUAttr*(O:OpDeclSet)
      M:MembAxSet E:EquationSet endfm) .

  op keepOnlyACUAttr* : OpDeclSet -> OpDeclSet .
  eq keepOnlyACUAttr*(OPDS)
   = removeAssocAttr(OPDS) .

endfm

fmod VARIANT is
  pr SUBSTITUTION-HANDLING .
  pr MODULE-HANDLING .
  pr META-LEVEL-MNPA .

  var M : Module .
  vars T T' TS TS' CtTS CtTS' Lhs Rhs : Term .
  vars N N' NextVar NextVar' NextVar'' : Nat .
  var B : Bound .
  var TL TL' : TermList .
  var NeTL : NeTermList .
  var EqS : EquationSet .
  var AtS : AttrSet .
  var Q : Qid .
  vars S S' : Substitution .
  var V : Variable .
  vars TP TP' : Type .
  var C : Constant .
  vars F F' : Qid .

  --- Variants ----------------------------------------------------------
---  sort VariantTriple .
---  op {_,_,_} : Term Substitution Nat -> VariantTriple [ctor] .

  sort VariantTripleSet .
---  subsort VariantTriple < VariantTripleSet .
  subsort Variant < VariantTripleSet .
  op empty : -> VariantTripleSet [ctor] .
  op _|_ : VariantTripleSet VariantTripleSet -> VariantTripleSet
    [ctor assoc comm id: empty prec 65 format (d d n d)] .
---  eq X:VariantTriple | X:VariantTriple = X:VariantTriple .
  eq X:Variant | X:Variant = X:Variant .

  op getTerms : VariantTripleSet -> TermSet .
  eq getTerms({T:Term,S:Substitution,NextVar:Nat,P:Parent,B:Bool}
              | R:VariantTripleSet)
   = T:Term | getTerms(R:VariantTripleSet) .
  eq getTerms((empty).VariantTripleSet)
   = emptyTermSet .

  op getSubstitutions : VariantTripleSet -> SubstitutionSet .
  eq getSubstitutions({T:Term,S:Substitution,NextVar:Nat,P:Parent,B:Bool}
              | R:VariantTripleSet)
   = S:Substitution | getSubstitutions(R:VariantTripleSet) .
  eq getSubstitutions((empty).VariantTripleSet)
   = empty .

  --- Variants ----------------------------------------------------------
  sort VariantFour .
  op {_,_,_,_} : Term Substitution Substitution Nat -> VariantFour [ctor] .

  sort VariantFourSet .
  subsort VariantFour < VariantFourSet .
  op empty : -> VariantFourSet [ctor] .
  op _|_ : VariantFourSet VariantFourSet -> VariantFourSet
    [ctor assoc comm id: empty prec 65 format (d d n d)] .
  eq X:VariantFour | X:VariantFour = X:VariantFour .

endfm

fmod META-MINIMIZE-BINDINGS is
  pr SUBSTITUTION-HANDLING .
  pr MODULE-HANDLING .
  pr SUBSTITUTIONSET .
  pr UNIFICATIONTRIPLESET .
  pr CONVERSION .
  pr META-LEVEL-MNPA .
  pr VARIANT .

  vars M : Module .
  vars T T' T1 T2 T3 : Term .
  vars TL TL' TL1 TL2 TL3 : TermList .
  vars F F' : Qid .
  vars S S' S* S'* : Substitution .
  vars V V' V1 V2 : Variable .
  vars N N' NOld : Nat .
  var US? : [UnificationTripleSet] .
  vars US US' : UnificationTripleSet .
  vars VTS VTS' : VariantFourSet .

  --- minimizeBindings ---
  op minimizeBindingsTerm : Module TermList UnificationTripleSet
                         -> UnificationTripleSet .
  eq minimizeBindingsTerm(M,TL,US)
   = minimizeBindingsTerm(M,TL,highestVar(TL),US) .

  op minimizeBindingsTerm : Module TermList Nat UnificationTripleSet
                         -> UnificationTripleSet .
  eq minimizeBindingsTerm(M,TL,NOld,US)
   = minimizeBindingsTerm*(M,TL,NOld,US,empty) .

  op minimizeBindingsTerm* : Module TermList Nat UnificationTripleSet
                             UnificationTripleSet -> UnificationTripleSet .
  eq minimizeBindingsTerm*(M,TL,NOld,empty,US')
   = US' .
  eq minimizeBindingsTerm*(M,TL,NOld,{S,S',N} | US,US')
   = minimizeBindingsTerm*(M,TL,NOld,US,
        US' | minimizeBindingsTerm**(M,TL,NOld,{S,S',N},S,S')
     ) .

  ****************
  op minimizeBindingsTerm** : Module TermList ---variables to minimize bindings
                             Nat --- or maximum index of variables
                             UnificationTriple Substitution Substitution
                          -> UnificationTriple .
  eq minimizeBindingsTerm**(M,TL',NOld,{S*,S'*,N},none,none)
   = {remDup(S*),remDup(S'*),N} .

 ceq minimizeBindingsTerm**(M,TL',NOld,{S*,V <- V' ; S'*,N},none,V <- V' ; S')
   = minimizeBindingsTerm**(M,TL',NOld,
         {  S* << (V' <- V),    S'* .. (V' <- V),  N},
         none,
         S' .. (V' <- V)
     )
  if V' =/= V and-then not (V in TL') and-then not (V' in TL')
     and-then highestVar(V) < NOld
     and-then highestVar(V') >= NOld
     and-then typeLeq(M,getTypes(M,V),getTypes(M,V')) .

  eq minimizeBindingsTerm**(M,TL',NOld,{S*,V <- T' ; S'*,N},none,V <- T' ; S')
   = minimizeBindingsTerm**(M,TL',NOld,{S*,V <- T' ; S'*,N},none,S')
  [owise] .

 ceq minimizeBindingsTerm**(M,TL',NOld,{V <- V' ; S*,S'*,N},V <- V' ; S,S')
   = minimizeBindingsTerm**(M,TL',NOld,
         { S* << (V' <- V),   S'* .. (V' <- V),   N},
         S << (V' <- V),
         S' .. (V' <- V)
     )
  if V' =/= V and-then V in TL' and-then not (V' in TL')
     and-then typeLeq(M,getTypes(M,V),getTypes(M,V')) .

  eq minimizeBindingsTerm**(M,TL',NOld,{V <- T' ; S*,S'*,N},V <- T' ; S,S')
   = minimizeBindingsTerm**(M,TL',NOld,{V <- T' ; S*,S'*,N},S,S')
  [owise] .

  --- minimizeBindings ---
  op minimizeBindingsTerm : Module TermList VariantFourSet
                         -> VariantFourSet .
  eq minimizeBindingsTerm(M,TL,VTS)
   = minimizeBindingsTerm(M,TL,highestVar(TL),VTS) .

  op minimizeBindingsTerm : Module TermList Nat VariantFourSet
                         -> VariantFourSet .
  eq minimizeBindingsTerm(M,TL,NOld,VTS)
   = minimizeBindingsTerm*(M,TL,NOld,VTS,empty) .

  op minimizeBindingsTerm* : Module TermList Nat VariantFourSet
                             VariantFourSet -> VariantFourSet .
  eq minimizeBindingsTerm*(M,TL,NOld,empty,VTS')
   = VTS' .
  eq minimizeBindingsTerm*(M,TL,NOld,{T,S,S',N} | VTS,VTS')
   = minimizeBindingsTerm*(M,TL,NOld,VTS,
        VTS' | minimizeBindingsTerm**(M,TL,NOld,{T,S,S',N},S,S')
     ) .

  ****************
  op minimizeBindingsTerm** : Module TermList ---variables to minimize bindings
                             Nat --- or maximum index of variables
                             VariantFour Substitution Substitution
                          -> VariantFour .
  eq minimizeBindingsTerm**(M,TL',NOld,{T,S*,S'*,N},none,none)
   = {T,remDup(S*),remDup(S'*),N} .

 ceq minimizeBindingsTerm**(M,TL',NOld,{T,S*,V <- V' ; S'*,N},none,V <- V' ; S')
   = minimizeBindingsTerm**(M,TL',NOld,
         { T << (V' <- V), S* << (V' <- V),    S'* .. (V' <- V),  N},
         none,
         S' .. (V' <- V)
     )
  if V' =/= V and-then not (V in TL') and-then not (V' in TL')
     and-then highestVar(V) < NOld
     and-then highestVar(V') >= NOld
     and-then typeLeq(M,getTypes(M,V),getTypes(M,V')) .

  eq minimizeBindingsTerm**(M,TL',NOld,{T,S*,V <- T' ; S'*,N},none,V <- T' ; S')
   = minimizeBindingsTerm**(M,TL',NOld,{T,S*,V <- T' ; S'*,N},none,S')
  [owise] .

 ceq minimizeBindingsTerm**(M,TL',NOld,{T,V <- V' ; S*,S'*,N},V <- V' ; S,S')
   = minimizeBindingsTerm**(M,TL',NOld,
         { T << (V' <- V), S* << (V' <- V),   S'* .. (V' <- V),   N},
         S << (V' <- V),
         S' .. (V' <- V)
     )
  if V' =/= V and-then V in TL' and-then not (V' in TL')
     and-then typeLeq(M,getTypes(M,V),getTypes(M,V')) .

  eq minimizeBindingsTerm**(M,TL',NOld,{T,V <- T' ; S*,S'*,N},V <- T' ; S,S')
   = minimizeBindingsTerm**(M,TL',NOld,{T,V <- T' ; S*,S'*,N},S,S')
  [owise] .

  ****
  op remDup : Substitution -> Substitution .
  eq remDup(V <- V ; S) = remDup(S) .
  eq remDup(S) = S [owise] .

endfm
fmod TYPEOFNARROWING is
  pr QID .
  pr META-TERM .

  --- TypeOfNarrowing ----------------------------------
  sorts TypeOfNarrowingElem TypeOfNarrowing .
  subsort TypeOfNarrowingElem < TypeOfNarrowing .
  op none : -> TypeOfNarrowing [ctor] .
  op __ : TypeOfNarrowing TypeOfNarrowing -> TypeOfNarrowing
          [ctor assoc comm id: none] .
  ---eq X:TypeOfNarrowingElem X:TypeOfNarrowingElem = X:TypeOfNarrowingElem .

  *** select one and only one of the following
  op full : -> TypeOfNarrowingElem [ctor] .
  op basic : -> TypeOfNarrowingElem [ctor] .
  op variant : -> TypeOfNarrowingElem [ctor] .
  op variant : Nat -> TypeOfNarrowingElem [ctor] .
  op E-rewriting : -> TypeOfNarrowingElem [ctor] .

  *** Extra flags
  op rigidife : Qid -> TypeOfNarrowingElem [ctor] .

  *** Irreducible terms for equational unification to check
  op irrTerms : TermList -> TypeOfNarrowingElem [ctor] .

  op getIrrTerms : TypeOfNarrowing -> TermList .
  eq getIrrTerms(X:TypeOfNarrowing irrTerms(TL:TermList)) = TL:TermList .
  eq getIrrTerms(X:TypeOfNarrowing) = empty [owise] .

  *** select one and only one of the following
  op E-ACU-unify : -> TypeOfNarrowingElem [ctor] .
  op E-ACU-unify-Irr : -> TypeOfNarrowingElem [ctor] .
  op ACU-unify : -> TypeOfNarrowingElem [ctor] .
  op BuiltIn-unify : -> TypeOfNarrowingElem [ctor] .
  op E-BuiltIn-unify : -> TypeOfNarrowingElem [ctor] .
  op E-BuiltIn-unify-Irr : -> TypeOfNarrowingElem [ctor] .

  *** select one and only one of the following
  op noStrategy : -> TypeOfNarrowingElem [ctor] .
  op topmost : -> TypeOfNarrowingElem [ctor] .
  op innermost : -> TypeOfNarrowingElem [ctor] .
  op outermost : -> TypeOfNarrowingElem [ctor] .

  *** select any combination of the following
  op E-normalize-terms : -> TypeOfNarrowingElem [ctor] .
  op normalize-terms : -> TypeOfNarrowingElem [ctor] .
  op computed-normalized-subs : -> TypeOfNarrowingElem [ctor] .
  op applied-normalized-subs : -> TypeOfNarrowingElem [ctor] .
  op minimal-unifiers : -> TypeOfNarrowingElem [ctor] .
  op testUnifier : -> TypeOfNarrowingElem [ctor] .
  op alsoAtVarPosition : -> TypeOfNarrowingElem [ctor] .

  op _in_ : TypeOfNarrowingElem TypeOfNarrowing -> Bool .
  eq X:TypeOfNarrowingElem in X:TypeOfNarrowingElem XS:TypeOfNarrowing
   = true .
  eq variant in variant(N:Nat) XS:TypeOfNarrowing
   = true .
  eq X:TypeOfNarrowingElem in XS:TypeOfNarrowing
   = false [owise] .

  op _!in_ : TypeOfNarrowingElem TypeOfNarrowing -> Bool .
  eq X:TypeOfNarrowingElem !in XS:TypeOfNarrowing
   = not (X:TypeOfNarrowingElem in XS:TypeOfNarrowing) .
  -------------------------------------------------------

  sort TypeOfRelation .
  ops '* '! '+ : -> TypeOfRelation .

  op [_] : TypeOfRelation -> Qid .
  eq [ '+ ] = qid("+") .
  eq [ '* ] = qid("*") .
  eq [ '! ] = qid("!") .

  op typeOfRelation : Qid ~> TypeOfRelation .
  eq typeOfRelation( '+ ) = '+ .
  eq typeOfRelation( '* ) = '* .
  eq typeOfRelation( '! ) = '! .
endfm

fmod IRR-FLAGS is
  sort IrrFlags .
  op __ : IrrFlags IrrFlags -> IrrFlags [assoc comm id: none] .
  op none : -> IrrFlags [ctor] .
  op irreducible : -> IrrFlags [ctor] .
  op reducible : -> IrrFlags [ctor] .
  op minimal-unifiers : -> IrrFlags [ctor] .
endfm

fmod EFLAGS is
  pr TYPEOFNARROWING .
  pr IRR-FLAGS .

  sort EFlags .
  subsort IrrFlags < EFlags .
  op __ : EFlags EFlags -> EFlags [assoc comm id: none] .
  op none : -> EFlags [ctor] .
  op ACUUnify : -> EFlags [ctor] .
  op BuiltInUnify : -> EFlags [ctor] .
  op testUnifier : -> EFlags [ctor] .

  op _in_ : EFlags EFlags -> Bool .
  eq X:EFlags in X:EFlags Y:EFlags = true .
  eq X:EFlags in Y:EFlags = false [owise] .

  op _!in_ : EFlags EFlags -> Bool .
  eq X:EFlags !in Y:EFlags = not (X:EFlags in Y:EFlags) .

  op [_] : EFlags -> TypeOfNarrowing .
  eq [ ACUUnify X:EFlags ] = ACU-unify [ X:EFlags ] .
  eq [ BuiltInUnify X:EFlags ] = BuiltIn-unify [ X:EFlags ] .
  eq [ minimal-unifiers X:EFlags ] = minimal-unifiers [ X:EFlags ] .
  eq [ testUnifier X:EFlags ] = testUnifier [ X:EFlags ] .
  eq [ X:EFlags ] = none [owise] .
endfm

fmod RESULT-CONTEXT-SET is
  protecting META-TERM .
  protecting META-LEVEL-MNPA .
  protecting TERM-HANDLING .
  protecting SUBSTITUTION-HANDLING .
  protecting RENAMING .
  protecting SUBSTITUTIONSET .
  protecting UNIFICATIONTRIPLESET .
  protecting MODULE-HANDLING .

  vars T T' TS CtTS : Term .
  var TP : Type .
  vars S S' Subst Subst' : Substitution .
  var NL : NatList .
  var M : Module .
  vars Ct CtS : Context .
  vars RTS RTS' : ResultContextSet .
  vars NextVar N : Nat .
  var TL : TermList .

  op subTerm_of_ : NatList ResultTriple ~> ResultTriple .
  eq subTerm NL of {T,TP,S} = {subTerm NL of T,TP,S} .

  op replaceSubTerm_of_by_ : NatList ResultTriple Term ~> ResultTriple .
  eq replaceSubTerm NL of {T,TP,S} by T' = {replaceSubTerm NL of T by T',TP,S} .

  --- ResultTriple ---------------------------
  --- op {_,_,_} : Term Type Substitution -> ResultTriple [ctor] .

  sort ResultTripleSet .
  subsort ResultTriple < ResultTripleSet .
  op empty : -> ResultTripleSet [ctor] .
  op _|_ : ResultTripleSet ResultTripleSet -> ResultTripleSet
    [ctor assoc comm id: empty prec 65 format (d d n d)] .
  eq X:ResultTriple | X:ResultTriple = X:ResultTriple .

  var RT : ResultTripleSet .

  op _|>_ : ResultTripleSet TermList -> ResultTripleSet .
  eq (empty).ResultTripleSet |> TL = (empty).ResultTripleSet .
  eq ({T,TP,S} | RT) |> TL = {T,TP,S |> TL} | (RT |> TL) .
  eq (failure | RT ) |> TL = failure | (RT |> TL) .

  op getTerms : ResultTripleSet -> TermSet .
  eq getTerms({T:Term,TP:Type,S:Substitution} | R:ResultTripleSet)
   = T:Term | getTerms(R:ResultTripleSet) .
  eq getTerms((empty).ResultTripleSet)
   = emptyTermSet .

  op getSubstitutions : ResultTripleSet -> SubstitutionSet .
  eq getSubstitutions({T,TP,S} | R:ResultTripleSet)
   = S | getSubstitutions(R:ResultTripleSet) .
  eq getSubstitutions((empty).ResultTripleSet)
   = (empty).SubstitutionSet .

  --- ResultContextSet ---------------------------

  --- Flags
  sort Flags Flag .
  subsort Flag < Flags .

  op empty : -> Flags [ctor] .
  op __ : Flags Flags -> Flags [ctor assoc comm id: empty] .
  eq X:Flag X:Flag = X:Flag .

  --- Flag to know whether term is a end point or not
  op end : Bool -> Flag [ctor frozen] .

  op end : Bool Flags -> Flags .
  eq end(B:Bool, end(B':Bool) B:Flags) = end(B:Bool) B:Flags .
  eq end(B:Bool, B:Flags) = end(B:Bool) B:Flags [owise] .

  op end : Flags -> Bool .
  eq end(end(B:Bool) B:Flags) = B:Bool .
  eq end(B:Flags) = false [owise] .
  ---

  sorts TraceNarrowStep TraceNarrow TraceNarrowSet .
  subsort TraceNarrowStep < TraceNarrow < TraceNarrowSet .
  op {_,_,_,_} : Term Substitution Type Rule -> TraceNarrowStep [ctor format (d d d d d n d n d d)] .
  op nil : -> TraceNarrow [ctor] .
  op __ : TraceNarrow TraceNarrow -> TraceNarrow [ctor assoc id: nil format (d n d)] .
  op empty : -> TraceNarrowSet [ctor] .
  op _|_ : TraceNarrowSet TraceNarrowSet -> TraceNarrowSet [ctor assoc comm id: empty format (d n n d)] .

  ---
  sorts ResultContext ResultContextSet ResultContextNeSet .
  op {_,_,_,_,_,_,_,_,_,_,_} :
      Term Type
      Substitution Substitution --- computed subs and applied subst
      Context Context --- Original and WithSubst
      Term Term --- TermWithSubst and ContextWithTermAndSubt
      Nat --- highest index of variable
      TraceNarrow
      Flags
      -> ResultContext [ctor] .
		
  subsort ResultContext < ResultContextNeSet < ResultContextSet .
  op empty : -> ResultContextSet [ctor] .
  op _|_ : ResultContextSet ResultContextSet -> ResultContextSet
    [ctor assoc comm id: empty prec 65 format (d n d d)] .
  op _|_ : ResultContextNeSet ResultContextSet -> ResultContextNeSet
    [ctor ditto] .
  eq X:ResultContext | X:ResultContext = X:ResultContext .

  op getCTTerm : ResultContext -> Term .
  eq getCTTerm(
      {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags})
   = CtTS:Term .
  op getNextVar : ResultContext -> Nat .
  eq getNextVar(
      {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags})
   = NextVar .
  op getLSubst : ResultContext -> Substitution .
  eq getLSubst(
      {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags})
   = S .
  op getRSubst : ResultContext -> Substitution .
  eq getRSubst(
      {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags})
   = S' .
		
  op _<<_ : ResultContext UnificationTripleSet -> ResultContextSet .
  eq {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags}
     << (empty).UnificationTripleSet
   = (empty).ResultContextSet .
  eq {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags}
     << ({Subst,Subst',N} | SS:UnificationTripleSet)
   = {T,
      TP,
      (S .. Subst) << Subst', (S' .. Subst') << Subst,
      Ct:Context,
      CtS:Context << (Subst ; Subst'),
      TS:Term << (Subst ; Subst'),
      CtTS:Term << (Subst ; Subst'),
      max(NextVar,N + 1),
      (Tr:TraceNarrow << T TP <) << {Subst,Subst',N},
      B:Flags}
     | {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags}
         << SS:UnificationTripleSet .

  op _<<__< : TraceNarrow Term Type -> TraceNarrow .
  eq (nil).TraceNarrow << T:Term TP:Type <
   = (nil).TraceNarrow .
  eq (Tr:TraceNarrow {T$:Term,none,TP$:Type,R:Rule}) --- Subst none here is special
     << T:Term TP:Type <
   = (Tr:TraceNarrow {T:Term,none,TP:Type,R:Rule}) .
  eq (Tr:TraceNarrow {T$:Term,S:Substitution,TP$:Type,R:Rule})
     << T:Term TP:Type <
   = (Tr:TraceNarrow {T$:Term,S:Substitution,TP$:Type,R:Rule}) [owise] .

  op _<<_ : TraceNarrow UnificationTriple -> TraceNarrow .
  eq (nil).TraceNarrow << {Subst,Subst',N}
   = (nil).TraceNarrow .
  eq (Tr:TraceNarrow {T$:Term,S:Substitution,TP$:Type,R:Rule}) --- Subst none here is special
     << {Subst,Subst',N}
   = (Tr:TraceNarrow {T$:Term << (Subst ; Subst'),S:Substitution .. (Subst ; Subst'),TP$:Type,R:Rule}) .

  op canonice : Module TraceNarrow -> TraceNarrow .
  eq canonice(M, (nil).TraceNarrow) = nil .
  eq canonice(M, Tr:TraceNarrow {T$:Term,S:Substitution,TP$:Type,R:Rule})
   = {canonice(M,T$:Term),canonice(M,S:Substitution),TP$:Type,R:Rule} canonice(M, Tr:TraceNarrow) .

  op toTriple : Module ResultContextSet -> ResultTripleSet .
  eq toTriple(M, empty ) = empty .
  eq toTriple(M, {T,TP,S,S',Ct,CtS,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags} | RTS )
   = {CtTS:Term, leastSort(M,CtTS:Term), S .. S'}
     | toTriple(M,RTS) .

  op _|>_ : ResultContextSet TermList -> ResultContextSet .
  eq (empty).ResultContextSet |> TL = (empty).ResultContextSet .
  eq ({T,TP,S,S',Ct,CtS,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags}
      | RTS:ResultContextSet) |> TL
   = {T,TP,S |> TL,S' |> TL,Ct,CtS,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags}
     | (RTS:ResultContextSet |> TL) .

  op getTerms : ResultContextSet -> TermSet .
  eq getTerms({T,TP,S,S',Ct,CtS,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags} | RTS)
   = CtTS:Term | getTerms(RTS) .
  eq getTerms((empty).ResultContextSet)
   = emptyTermSet .

  op toUnificationTriples : ResultContextSet -> UnificationTripleSet .
  eq toUnificationTriples(
      {T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags} | R:ResultContextSet)
   = {S,S',NextVar}
     | toUnificationTriples(R:ResultContextSet) .
  eq toUnificationTriples((empty).ResultContextSet)
   = (empty).UnificationTripleSet .

  *** auxiliary Sort SubstitutionCond for metaNarrowSearch *****
  sort SubstitutionCond .
  subsort Substitution < SubstitutionCond .

  op |_| : ResultTripleSet -> Nat .
  eq | (empty).ResultTripleSet | = 0 .
  eq | (RT:ResultTriple | RTS:ResultTripleSet) |
   = | RTS:ResultTripleSet | + 1 .

  op |_| : ResultContextSet -> Nat .
  eq | (empty).ResultContextSet | = 0 .
  eq | (RT:ResultContext | RTS:ResultContextSet) |
   = | RTS:ResultContextSet | + 1 .

endfm

fmod META-MATCH is
  protecting TERM-HANDLING .
  protecting MODULE-HANDLING .
  protecting SUBSTITUTION-HANDLING .
  protecting META-LEVEL-MNPA .
  protecting RENAMING .
  protecting SUBSTITUTIONSET .

  vars T T' : Term .
  vars TL TL' : TermList .
  var M : Module .
  vars S S' : Substitution .
  var S? : Substitution? .
  vars SS SS' : SubstitutionSet .
  vars V V' : Variable .
  vars TPL TPL' : TypeList .
  vars N N' : Nat .

  --- Not defined in this module ----------------------------------------
  op isNF$ : Module Term ~> Bool .
  --- Not defined in this module ----------------------------------------

  --- metaCoreMatch(M,T,T') implies that T is an instance of T'
  op metaCoreMatch : Module Term Term -> SubstitutionSet .
  eq metaCoreMatch(M,T,T')
   = metaCoreMatch$(M,canonice(M,T),canonice(M,T')) .

  op metaCoreMatch$ : Module Term Term -> SubstitutionSet .
  eq metaCoreMatch$(M,T,T')
   = if glbSorts(M,leastSort(M,T),leastSort(M,T')) == none
     then empty
     else metaCoreMatchCollect(eraseEqs(eraseRls(M)),T,T')
     fi .

  op metaCoreMatch? : Module Term Term -> Bool .
  eq metaCoreMatch?(M,T,T')
   = metaCoreMatch?$(M,canonice(M,T),canonice(M,T')) .

  op metaCoreMatch?$ : Module Term Term -> Bool .
  eq metaCoreMatch?$(M,T,T')
   = glbSorts(M,leastSort(M,T),leastSort(M,T')) =/= none
     and-then
     metaMatch(eraseEqs(eraseRls(M)),T',T,nil,0) =/= noMatch .

  --- metaCoreMatchCollect(M,T,T') calls Maude metaMatch
  op metaCoreMatchCollect : Module Term Term -> SubstitutionSet .
  eq metaCoreMatchCollect(M,T,T')
   = metaCoreMatchCollect*(M,T,T',empty,0) .

  op metaCoreMatchCollect* : Module Term Term SubstitutionSet Nat
                             -> SubstitutionSet .
  eq metaCoreMatchCollect*(M,T,T',SS,N:Nat)
   = if metaMatch(M,T',T,nil,N:Nat) =/= noMatch
     then metaCoreMatchCollect*(M,T,T',
                            SS | metaMatch(M,T',T,nil,N:Nat),
                            s(N:Nat))
     else SS
     fi .

  op metaBuiltInEqual : Module TermList Term Term -> Bool .
  eq metaBuiltInEqual(M,TL,T,T')
   = canonice(M,T) == canonice(M,T') .

endfm
fmod VARIANT-HANDLING is
  pr SUBSTITUTION-HANDLING .
  pr META-MINIMIZE-BINDINGS .
  pr RESULT-CONTEXT-SET .
  pr MODULE-HANDLING .
  pr META-LEVEL-MNPA .
  pr VARIANT .

  var M : Module .
  vars T T' TS TS' CtTS CtTS' Lhs Rhs : Term .
  vars N N' NextVar NextVar' NextVar'' : Nat .
  var B : Bound .
  var TL TL' : TermList .
  var NeTL : NeTermList .
  var EqS : EquationSet .
  var AtS : AttrSet .
  var Q : Qid .
  vars S S' : Substitution .
  var V : Variable .
  var R RT : ResultContext .
  vars RTS RTS' : ResultContextSet .
  vars TP TP' : Type .
  vars Ct Ct' CtS CtS' : Context .
  var C : Constant .
  vars F F' : Qid .
  var P : Parent .
  var VTS : VariantFourSet .

  op toVariants : Nat ResultContextSet -> VariantFourSet .
  eq toVariants(OldNextVar:Nat,empty)
   = empty .
  eq toVariants(OldNextVar:Nat,{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags} | RTS)
   = {CtTS,S |> OldNextVar:Nat,S' |> OldNextVar:Nat,NextVar}
      | toVariants(OldNextVar:Nat,RTS) .

  op _|>_ : VariantFourSet TermList -> VariantFourSet .
  eq (empty).VariantFourSet |> TL = empty .
  eq ({T,S,S',N} | VTS) |> TL = {T,(S |> TL),(S' |> TL),N} | (VTS |> TL) .

  op getTerms : VariantFourSet -> TermSet .
  eq getTerms({T:Term,S:Substitution,S':Substitution,NextVar:Nat}
              | R:VariantFourSet)
   = T:Term | getTerms(R:VariantFourSet) .
  eq getTerms((empty).VariantFourSet)
   = emptyTermSet .

  op toVariantTripleSet : VariantFourSet -> VariantTripleSet .
  eq toVariantTripleSet(empty)
   = empty .
  eq toVariantTripleSet({T,S,S',NextVar} | VTS)
---    = {T,S ; S',NextVar} | toVariantTripleSet(VTS) .
   = {T,S,NextVar,none,true} | toVariantTripleSet(VTS) .

endfm

fmod RIGIDIFE is
  protecting UNIFICATIONTRIPLESET .
  protecting MODULE-HANDLING .
  protecting RESULT-CONTEXT-SET .
  protecting VARIANT .

  vars V V' : Variable .
  var C : Constant .
  vars F Q : Qid .
  vars U U' : UnificationTriple .
  vars US US' : UnificationTripleSet .
  vars S S' S1 S1' S2 S2' S* : Substitution .
  vars Ct CtS Ct' CtS' : Context .
  vars TS TS' CtTS CtTS' : Term .
  var SS : SubstitutionSet .
  var SSe : NeSubstitutionSet .
  vars N N' N1 N2 NextVar : Nat .
  vars T T' : Term .
  vars TL TL' : TermList .
  var NeTL : NeTermList .
  var M : Module .
  var RTS : ResultTripleSet .
  var TP : Type .

  sort PairRigidife .
  op {_,_} : Module TermList -> PairRigidife .
  op getM : PairRigidife -> Module .
  eq getM({M,TL}) = M .
  op getTL : PairRigidife -> TermList .
  eq getTL({M,TL}) = TL .

  *** Transform variables in TermList into constants
  op rigidifeList : Module Qid TermList TermList -> PairRigidife .
  eq rigidifeList(M,Q,TL,empty)
   = {M,TL} .
  eq rigidifeList(M,Q,(T,NeTL),TL)
   = { getM(rigidifeList(getM(rigidifeList(M,Q,T,TL)),Q,NeTL,TL)),
       (getTL(rigidifeList(M,Q,T,TL)),
        getTL(rigidifeList(getM(rigidifeList(M,Q,T,TL)),Q,NeTL,TL))) } .
  eq rigidifeList(M,Q,C,TL)
   = {M,C} .
  eq rigidifeList(M,Q,F[NeTL],TL)
   = {getM(rigidifeList(M,Q,NeTL,TL)),
      F[getTL(rigidifeList(M,Q,NeTL,TL))]} .
  eq rigidifeList(M,Q,V,TL)
   = if V in TL then rigidifeVar***(M,Q,V) else {M,V} fi .

  *** Transform all variables into constants
  op rigidifeAllVar : Module Qid TermList -> PairRigidife .
  eq rigidifeAllVar(M,Q,TL)
   = rigidifeNat(M,Q,TL,0) .

  *** Transform variables above Nat into constants
  op rigidifeNat : Module Qid TermList Nat -> PairRigidife .
  eq rigidifeNat(M,Q,(T,NeTL),N)
   = { getM(rigidifeNat(getM(rigidifeNat(M,Q,T,N)),Q,NeTL,N)),
       (getTL(rigidifeNat(M,Q,T,N)),
        getTL(rigidifeNat(getM(rigidifeNat(M,Q,T,N)),Q,NeTL,N))) } .
  eq rigidifeNat(M,Q,C,N)
   = {M,C} .
  eq rigidifeNat(M,Q,F[NeTL],N)
   = {getM(rigidifeNat(M,Q,NeTL,N)),
      F[getTL(rigidifeNat(M,Q,NeTL,N))]} .
  eq rigidifeNat(M,Q,V,N)
   = if highestVar(V) >= N then rigidifeVar***(M,Q,V) else {M,V} fi .

  *** Transform variables with rigid# into constants
  op rigidifeRigid : Module Qid TermList -> PairRigidife .
  eq rigidifeRigid(M,Q,(T,NeTL))
   = { getM(rigidifeRigid(getM(rigidifeRigid(M,Q,T)),Q,NeTL)),
       (getTL(rigidifeRigid(M,Q,T)),
        getTL(rigidifeRigid(getM(rigidifeRigid(M,Q,T)),Q,NeTL))) } .
  eq rigidifeRigid(M,Q,C)
   = {M,C} .
  eq rigidifeRigid(M,Q,F[NeTL])
   = {getM(rigidifeRigid(M,Q,NeTL)),
      F[getTL(rigidifeRigid(M,Q,NeTL))]} .
  eq rigidifeRigid(M,Q,V)
   = if rfind(string(V), "rigid#", length(string(V))) =/= notFound
     then rigidifeVar***(M,Q,V)
     else {M,V}
     fi .

  *** Basic case for transforming variables into constants
  op rigidifeVar*** : Module Qid Variable -> PairRigidife .
  ceq rigidifeVar***(M,Q,V)
    = {addOps((op qid(F:String) : nil -> getType(V) [none].), M),
       qid(F:String + "." + string(getType(V)))}
   if F:String := "rigid@" + string(Q)
                     + "@" + string(getName(V)) + "@" + string(getType(V)) .

  *** Undo the transformation of variables into constants
  op unrigidife : Qid TermList -> TermList .
  eq unrigidife(Q,(T,NeTL))
   = (unrigidife(Q,T),unrigidife(Q,NeTL)) .
  eq unrigidife(Q,V) = V .
  eq unrigidife(Q,F[TL]) = F[unrigidife(Q,TL)] .
  eq unrigidife(Q,C)
   = if rfind(string(C), "rigid@" + string(Q) + "@", length(string(C)))
          =/= notFound
     then qid(
           string(
             qid(
              substr(string(C),
               rfind(string(C), "rigid@" + string(Q) + "@", length(string(C)))
                + 7 + length(string(Q)),
               rfind(
                substr(string(C),
                  rfind(string(C), "rigid@" + string(Q) + "@", length(string(C)))
                   + 7 + length(string(Q)),
                  length(string(C))),
                "@",length(string(C))
               )
              )
             )
           )
           + ":" +
           string(getType(qid(
                   substr(string(C),
                   rfind(string(C), "rigid@" + string(Q) + "@",
                           length(string(C))) + 7 + length(string(Q)),
                   length(string(C)))
           )))
          )
     else C
     fi .

  op unrigidife : Qid Substitution -> Substitution .
  eq unrigidife(Q,(none).Substitution) = none .
  eq unrigidife(Q,V <- T ; S)
   = unrigidife(Q,V) <- unrigidife(Q,T) ; unrigidife(Q,S) .

  op unrigidife : Qid SubstitutionSet -> SubstitutionSet .
  eq unrigidife(Q,(empty).SubstitutionSet) = empty .
  eq unrigidife(Q,S | SSe)
   = unrigidife(Q,S) | unrigidife(Q,SSe) .

  op unrigidife : Qid UnificationTripleSet -> UnificationTripleSet .
  eq unrigidife(Q,(empty).UnificationTripleSet) = empty .
  eq unrigidife(Q,{S1,S2,N'} | US)
   = {unrigidife(Q,S1),unrigidife(Q,S2),N'}
     | unrigidife(Q,US) .

  op unrigidife : Qid ResultTripleSet -> ResultTripleSet .
  eq unrigidife(Q,(empty).ResultTripleSet) = empty .
  eq unrigidife(Q,{T,TP,S} | RTS)
   = {unrigidife(Q,T),TP,unrigidife(Q,S)}
     | unrigidife(Q,RTS) .

  op unrigidife : Qid VariantFourSet -> VariantFourSet  .
  eq unrigidife(Q,(empty).VariantFourSet) = empty .
  eq unrigidife(Q,{T,S,S',N} | R:VariantFourSet)
   = {unrigidife(Q,T),unrigidife(Q,S),unrigidife(Q,S'),N}
     | unrigidife(Q,R:VariantFourSet) .

  *** Label variables with rigid
  op rigidLabel : Module TermList TermList -> TermList .
  eq rigidLabel(M,TL,empty)
   = TL .
  eq rigidLabel(M,(T,NeTL),TL)
   = rigidLabel(M,T,TL), rigidLabel(M,NeTL,TL) .
  eq rigidLabel(M,C,TL)
   = C .
  eq rigidLabel(M,F[NeTL],TL)
   = F[rigidLabel(M,NeTL,TL)] .
  eq rigidLabel(M,V,TL)
   = if V in TL then rigidLabel***(M,V) else V fi .

  op rigidLabel*** : Module Variable -> Variable .
  eq rigidLabel***(M,V)
   = qid("rigid#" + string(getName(V)) + ":" + string(getType(V))) .

  *** Undo the transformation of variables into constants
  op unrigidLabel : TermList -> TermList .
  eq unrigidLabel((T,NeTL))
   = (unrigidLabel(T),unrigidLabel(NeTL)) .
  eq unrigidLabel(C) = C .
  eq unrigidLabel(F[TL]) = F[unrigidLabel(TL)] .
  eq unrigidLabel(V)
   = if rfind(string(V), "rigid#", length(string(V)))
          =/= notFound
     then qid(
          string(getName(qid(
                   substr(string(V),
                   rfind(string(V), "rigid#",
                           length(string(V))) + 6,
                   length(string(V)))
          )))
          + ":" +
          string(getType(qid(
                   substr(string(V),
                   rfind(string(V), "rigid#",
                           length(string(V))) + 6,
                   length(string(V)))
          )))
          )
     else V
     fi .

  op unrigidLabel : Substitution -> Substitution .
  eq unrigidLabel((none).Substitution) = none .
  eq unrigidLabel(V <- T ; S)
   = unrigidLabel(V) <- unrigidLabel(T) ; unrigidLabel(S) .

  op unrigidLabel : SubstitutionSet -> SubstitutionSet .
  eq unrigidLabel((empty).SubstitutionSet) = empty .
  eq unrigidLabel(S | SSe)
   = unrigidLabel(S) | unrigidLabel(SSe) .

  op unrigidLabel : UnificationTripleSet -> UnificationTripleSet .
  eq unrigidLabel((empty).UnificationTripleSet) = empty .
  eq unrigidLabel({S1,S2,N'} | US)
   = {unrigidLabel(S1),unrigidLabel(S2),N'}
     | unrigidLabel(US) .

  op unrigidLabel : ResultTripleSet -> ResultTripleSet .
  eq unrigidLabel((empty).ResultTripleSet) = empty .
  eq unrigidLabel({T,TP,S} | RTS)
   = {unrigidLabel(T),TP,unrigidLabel(S)}
     | unrigidLabel(RTS) .

  op unrigidLabel : ResultContextSet -> ResultContextSet .
  eq unrigidLabel((empty).ResultContextSet) = empty .
  eq unrigidLabel({T,TP,S,S*,Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags} | RTS:ResultContextSet)
   = {unrigidLabel(T),TP,unrigidLabel(S),unrigidLabel(S*),Ct,CtS,unrigidLabel(TS),unrigidLabel(CtTS),NextVar,unrigidLabel(Tr:TraceNarrow),B:Flags}
     | unrigidLabel(RTS:ResultContextSet) .

  op unrigidLabel : TraceNarrow -> TraceNarrow .
  eq unrigidLabel((nil).TraceNarrow) = nil .
  eq unrigidLabel(Tr:TraceNarrow {CtTS:Term,Subst:Substitution,TP:Type,R:Rule})
   = unrigidLabel(Tr:TraceNarrow)
     {unrigidLabel(CtTS:Term),unrigidLabel(Subst:Substitution),TP:Type,R:Rule} .

  op unrigidLabel : VariantFourSet -> VariantFourSet  .
  eq unrigidLabel((empty).VariantFourSet) = empty .
  eq unrigidLabel({T,S,S',N} | R:VariantFourSet)
   = {unrigidLabel(T),unrigidLabel(S),unrigidLabel(S'),N}
     | unrigidLabel(R:VariantFourSet) .

  op qid : Nat -> Qid .
  eq qid(N:Nat) = qid(string(N:Nat,10)) .

endfm

fmod META-E-UNIFICATION is
  pr TYPEOFNARROWING .
  pr EFLAGS .
  pr RESULT-CONTEXT-SET .
  pr SUBSTITUTION-HANDLING .
  pr META-MINIMIZE-BINDINGS .
  pr RESULT-CONTEXT-SET .
  pr MODULE-HANDLING .
  pr META-LEVEL-MNPA .
  pr VARIANT .
  pr RIGIDIFE .

  *** Repeated definitions to avoid cross calls between modules ************
  op normalizedSubstitution? : Module SubstitutionSet -> Bool .
  op metaACUUnify : Module Term Term Nat -> UnificationTripleSet .
  op metaACUUnify? : Module Term Term Nat -> Bool .
  op metaACUUnify* : Module UnificandPair Nat Nat ~> UnificationTriple? .
  op metaCoreUnify : Module Term Term Nat -> UnificationTripleSet .
  op metaCoreUnify? : Module Term Term Nat -> Bool .
  op metaBuiltInUnify : Module TermList Term Term Nat -> UnificationTripleSet .
  op metaBuiltInUnify? : Module TermList Term Term Nat -> Bool .
  op _<=[_]_ : SubstitutionSet Module SubstitutionSet -> Bool .
  op _<=[_]_ : Term Module Term -> Bool .
  *** Repeated definitions to avoid cross calls between modules ************

  var M : Module .
  vars T T' TS TS' CtTS CtTS' Lhs Rhs : Term .
  vars N N' NextVar NextVar' NextVar'' NextVar1 NextVar2 NextVar3 : Nat .
  var B : Bound .
  var TL TL' : TermList .
  var NeTL : NeTermList .
  var EqS : EquationSet .
  var AtS : AttrSet .
  var ON : TypeOfNarrowing .
  var Q : Qid .
  vars US US' US$ : UnificationTripleSet .
  vars U U' : UnificationTriple .
  vars S S' S* S'* S1 S1' S2 S2' S3 S3' : Substitution .
  var V : Variable .
  var R RT : ResultContext .
  vars RTS RTS' : ResultContextSet .
  vars TP TP' : Type .
  vars Ct Ct' CtS CtS' : Context .
  var C : Constant .
  vars F F' : Qid .
  var EF : EFlags .
  vars VT VT' : VariantFour .
  vars VTS VTS' VTS$ : VariantFourSet .
  var IRR : IrrFlags .

  --- metaECoreUnify --------------------------------------------------
  op metaECoreUnify : Module Term Term TermList -> SubstitutionSet .
                     --- Term Lhs
  eq metaECoreUnify(M, T, T',TL)
   = metaEACUUnify(M, T, T',TL) .

  op metaECoreUnify? : Module Term Term TermList -> Bool .
  eq metaECoreUnify?(M, T, T', TL)
   = metaEACUUnify?(M, T, T', TL) .

  --- metaVariantUnify --------------------------------------------------
  op metaVariantUnify : Module Term Term -> SubstitutionSet .
  eq metaVariantUnify(M, T, T') = metaEACUUnify(M, T, T', empty) .

  op metaVariantUnify : Module Term Term TermList -> SubstitutionSet .
  eq metaVariantUnify(M, T, T', TL) = metaEACUUnify(M, T, T', TL) .

  op metaVariantUnify? : Module Term Term TermList -> Bool .
  eq metaVariantUnify?(M, T, T', TL) = metaEACUUnify?(M, T, T', TL) .

  op metaVariantUnify : Module Term Term Nat IrrFlags -> UnificationTripleSet .
  eq metaVariantUnify(M, T, T',NextVar,IRR) = metaEACUUnify(M, T, T',empty,NextVar,IRR) .

  op metaVariantUnify : Module Term Term TermList Nat IrrFlags -> UnificationTripleSet .
  eq metaVariantUnify(M, T, T',TL,NextVar,IRR) = metaEACUUnify(M, T, T',TL,NextVar,IRR) .

  op metaVariantUnify? : Module Term Term TermList Nat IrrFlags -> Bool .
  eq metaVariantUnify?(M, T, T',TL,NextVar,IRR) = metaEACUUnify?(M, T, T',TL,NextVar,IRR) .

  --- metaEACUUnify --------------------------------------------------
  op metaEACUUnify : Module Term Term TermList -> SubstitutionSet .
  eq metaEACUUnify(M, T, T', TL)
   = toSubstitution(metaEACUUnify(M,T,T',TL,highestVar((T,T')) + 1,reducible)) .

  op metaEACUUnify? : Module Term Term TermList -> Bool .
  eq metaEACUUnify?(M, T, T', TL)
   = metaEACUUnify?(M,T,T',TL,highestVar((T,T')) + 1,reducible) .

  op metaEACUUnifyIrr : Module Term Term TermList -> SubstitutionSet .
                    --- T irreducible T' reducible
  eq metaEACUUnifyIrr(M, T, T',TL)
   = toSubstitution(metaEACUUnify(M,T,T',TL,highestVar((T,T')) + 1,irreducible)) .

  op metaEACUUnifyIrr? : Module Term Term TermList -> Bool .
  eq metaEACUUnifyIrr?(M, T, T', TL)
   = metaEACUUnify?(M,T,T',TL,highestVar((T,T')) + 1,irreducible) .

  op metaEACUUnify : Module Term Term TermList Nat IrrFlags -> UnificationTripleSet .
  eq metaEACUUnify(M, T, T',TL,NextVar,IRR)
   = minimizeBindingsTerm(M,Vars(T),NextVar,
          metaEUnify&(M, T, T',TL,NextVar,ACUUnify IRR)
     ) |> (T,T',TL) .

  op metaEACUUnify? : Module Term Term TermList Nat IrrFlags -> Bool .
  eq metaEACUUnify?(M, T, T',TL,NextVar,IRR)
   = metaEUnify&?(M, T, T',TL,NextVar,ACUUnify IRR) .

  --- metaEBuiltInUnify --------------------------------------------------
  op metaEBuiltInUnify : Module Term Term -> SubstitutionSet .
  eq metaEBuiltInUnify(M, T, T') = metaEBuiltInUnify(M, T, T',empty) .

  op metaEBuiltInUnify : Module Term Term TermList -> SubstitutionSet .
  eq metaEBuiltInUnify(M, T, T', TL)
   = toSubstitution(metaEBuiltInUnify(M,T,T',TL,highestVar((T,T')) + 1,reducible)) .

  op metaEBuiltInUnify? : Module Term Term -> Bool .
  eq metaEBuiltInUnify?(M, T, T') = metaEBuiltInUnify?(M, T, T',empty) .

  op metaEBuiltInUnify? : Module Term Term TermList -> Bool .
  eq metaEBuiltInUnify?(M, T, T',TL)
   = metaEBuiltInUnify?(M,T,T',TL,highestVar((T,T')) + 1,reducible) .

  op metaEBuiltInUnifyIrr : Module Term Term -> SubstitutionSet .
  eq metaEBuiltInUnifyIrr(M, T, T') = metaEBuiltInUnifyIrr(M, T, T', empty) .

  op metaEBuiltInUnifyIrr : Module Term Term TermList -> SubstitutionSet .
                          --- T irreducible T' reducible
  eq metaEBuiltInUnifyIrr(M, T, T', TL)
   = toSubstitution(
       metaEBuiltInUnify(M,T,T',TL,highestVar((T,T')) + 1,irreducible)
     ) .

  op metaEBuiltInUnifyIrr? : Module Term Term  -> Bool .
  eq metaEBuiltInUnifyIrr?(M, T, T') = metaEBuiltInUnifyIrr?(M, T, T', empty) .

  op metaEBuiltInUnifyIrr? : Module Term Term TermList -> Bool .
                          --- T irreducible T' reducible
  eq metaEBuiltInUnifyIrr?(M, T, T', TL)
   = metaEBuiltInUnify?(M,T,T',TL,highestVar((T,T')) + 1,irreducible) .

  op metaEBuiltInUnify : Module Term Term TermList Nat IrrFlags
                         -> UnificationTripleSet .
  eq metaEBuiltInUnify(M, T, T',TL,NextVar,IRR)
   = minimizeBindingsTerm(M,Vars(T),NextVar,
        metaEUnify&(M, T, T',TL,NextVar,BuiltInUnify IRR)
     ) |> (T,T') .

  op metaEBuiltInUnify? : Module Term Term TermList Nat IrrFlags -> Bool .
  eq metaEBuiltInUnify?(M, T, T',TL,NextVar,IRR)
   = metaEUnify&?(M, T, T',TL,NextVar,BuiltInUnify IRR) .

  --- metaEUnify --------------------------------------------------
  op metaEUnify& : Module Term Term TermList Nat EFlags -> UnificationTripleSet .
                      --- Term Lhs
  eq metaEUnify&(M,T,T',TL,NextVar,EF)
   = if sameKind(M,leastSort(M,T),leastSort(M,T'))
     then metaEUnify&*(removeBoolEqs(M),T,T',TL,NextVar,EF)
     else empty
     fi .

  op metaEUnify&? : Module Term Term TermList Nat EFlags -> Bool .
                      --- Term Lhs
  eq metaEUnify&?(M,T,T',TL,NextVar,EF)
   = sameKind(M,leastSort(M,T),leastSort(M,T'))
     and-then
     metaEUnify&*?(removeBoolEqs(M),T,T',TL,NextVar,EF) .

  op metaEUnify&* : Module Term Term TermList Nat EFlags -> UnificationTripleSet .
                      --- Term Lhs
  eq metaEUnify&*(M,T,T',TL,NextVar,EF)
   = if metaBuiltInUnify?(M,TL,
          fst(generalize(onlyEqsVariant(M),NextVar,T)),
          fst(generalize(onlyEqsVariant(M),
                         snd(generalize(onlyEqsVariant(M),NextVar,T)),T')),
          snd(generalize(onlyEqsVariant(M),
                         snd(generalize(onlyEqsVariant(M),NextVar,T)),T'))
        )
     then if T == fst(generalize(onlyEqsVariant(M),NextVar,T))
             and
             T' == fst(
                    generalize(onlyEqsVariant(M),
                               snd(generalize(onlyEqsVariant(M),NextVar,T)),T'))
          then --- no narrowing is necessary to unify
               metaBuiltInUnify(M,TL,T,T',NextVar)
          else metaEUnify$(M,T,T',TL,NextVar,EF)
          fi
     else empty
     fi .

  op metaEUnify&*? : Module Term Term TermList Nat EFlags -> Bool .
                      --- Term Lhs
  eq metaEUnify&*?(M,T,T',TL,NextVar,EF)
   = if metaBuiltInUnify?(M,TL,
          fst(generalize(onlyEqsVariant(M),NextVar,T)),
          fst(generalize(onlyEqsVariant(M),
                         snd(generalize(onlyEqsVariant(M),NextVar,T)),T')),
          snd(generalize(onlyEqsVariant(M),
                         snd(generalize(onlyEqsVariant(M),NextVar,T)),T'))
        )
     then if T == fst(generalize(onlyEqsVariant(M),NextVar,T))
             and
             T' == fst(
                    generalize(onlyEqsVariant(M),
                               snd(generalize(onlyEqsVariant(M),NextVar,T)),T'))
          then --- no narrowing is necessary to unify
               metaBuiltInUnify?(M,TL,T,T',NextVar)
          else metaEUnify$?(M,T,T',TL,NextVar,EF)
          fi
     else false
     fi .

  op metaEUnify$ : Module Term Term TermList Nat EFlags -> UnificationTripleSet .
                      --- Term Lhs
  eq metaEUnify$(M,T,T',TL,NextVar,irreducible EF)
   = metaEUnifyCollect(M,T,T',(T,TL),NextVar,0,empty) .
  eq metaEUnify$(M,T,T',TL,NextVar,EF)
   = metaEUnifyCollect(M,T,T',TL,NextVar,0,empty) [owise] .

  op metaEUnify$? : Module Term Term TermList Nat EFlags -> Bool .
                      --- Term Lhs
  eq metaEUnify$?(M,T,T',TL,NextVar,irreducible EF)
   = metaEUnifyCollect?(M,T,T',(T,TL),NextVar,0) .
  eq metaEUnify$?(M,T,T',TL,NextVar,EF)
   = metaEUnifyCollect?(M,T,T',TL,NextVar,0) [owise] .

  op metaEUnifyCollect : Module Term Term TermList Nat Nat
                          UnificationTripleSet
                       -> UnificationTripleSet  .
  eq metaEUnifyCollect(M,T,T',TL,N,N',US)
   = if metaEUnify*(M,T =? T',TL,N,N') :: UnificationTriple?
        and
        metaEUnify*(M,T =? T',TL,N,N') =/= noUnifier
     then metaEUnifyCollect(M,T,T',TL,N,s(N'),
             US | metaEUnify*(M,T =? T',TL,N,N') )
     else US
     fi .

  op metaEUnifyCollect? : Module Term Term TermList Nat Nat
                       -> Bool .
  eq metaEUnifyCollect?(M,T,T',TL,N,N')
   = metaEUnify*(M,T =? T',TL,N,N') :: UnificationTriple?
     and
     metaEUnify*(M,T =? T',TL,N,N') =/= noUnifier .

  *** Code for collection all unifiers
  op metaEUnify* : Module UnificandPair TermList Nat Nat ~> UnificationTriple? .
  eq metaEUnify*(M, T =? T',TL,N,N')
   = metaEUnifyTriple(
       M,
       unflatten(M,T) =? unflatten(M,T'),
       TL,N,N') .

  op metaEUnifyTriple : Module UnificationProblem TermList Nat Nat ~> UnificationTriple? .
  eq metaEUnifyTriple(M,T =? T',TL,N,N')
   = if metaVariantUnify(M,T =? T',TL,N,N') == noUnifier
     then noUnifier
     else {getSubst(metaVariantUnify(M,T =? T',TL,N,N')) |> T,
           getSubst(metaVariantUnify(M,T =? T',TL,N,N')) |> T',
           getNextVar(metaVariantUnify(M,T =? T',TL,N,N'))}
     fi .

  **************************************
  ***** Variant Generation

  op getVariants : Module Term -> VariantFourSet .
  eq getVariants(M,T) = getVariants(M,T,highestVar(T) + 1) .

  op getVariants : Module Term Nat -> VariantFourSet .
  eq getVariants(M,T,NextVar) = getVariants(M,T,NextVar,reducible BuiltInUnify) .

  op getVariants : Module Term Nat TermList -> VariantFourSet .
  eq getVariants(M,T,NextVar,TL) = getVariants(M,T,NextVar,reducible BuiltInUnify,TL) .

  op getVariants : Module Term Nat EFlags -> VariantFourSet .
  eq getVariants(M,T,NextVar,EF) = getVariants(M,T,NextVar,EF,empty) .

  op getVariants : Module Term Nat EFlags TermList -> VariantFourSet .
  eq getVariants(M,T,NextVar,EF,TL)
   = unrigidife(qid(NextVar),
      getVariants*(
          getM(rigidifeRigid(M,qid(NextVar),T)),
          getTL(rigidifeRigid(M,qid(NextVar),T)),
          NextVar + 1,EF,TL
      )
     ) .

  op getVariants* : Module Term Nat EFlags TermList -> VariantFourSet .
  eq getVariants*(M,T,NextVar,EF,TL)
   = if howMany(onlyEqsVariant(M),T) == 0
     then {T,none,none,NextVar}
     else if getVariants**(M,T,NextVar,EF,TL) :: VariantFourSet
             and
             getVariants**(M,T,NextVar,EF,TL) =/= empty
          then getVariants**(M,T,NextVar,EF,TL)
          else {T,none,none,NextVar}
          fi
     fi .

  op getVariants** : Module Term Nat EFlags TermList -> VariantFourSet .
  eq getVariants**(M,T,NextVar,EF,TL)
   = minimizeBindingsTerm(M,Vars(T),NextVar,
            getVariants***(M,T,NextVar,empty,0,TL)
     ) .

  op getVariants*** : Module Term Nat VariantFourSet Nat TermList -> VariantFourSet .
  eq getVariants***(M,T,NextVar,VTS,N,TL)
   = if metaGetVariant(M,T,TL,NextVar,N) == noVariant
     then VTS
     else getVariants***$(M,T,NextVar,VTS,N,
             metaGetVariant(M,T,TL,NextVar,N),TL)
     fi .

  op getVariants***$ : Module Term Nat VariantFourSet Nat Variant TermList -> VariantFourSet .
  eq getVariants***$(M,T,NextVar,VTS,N,{T2:Term,S:Substitution,NV2:Nat,P:Parent,B:Bool},TL)
   = getVariants***$$(M,T,NextVar,VTS,N,{T2:Term,S:Substitution,NV2:Nat,P:Parent,B:Bool},
           split({S:Substitution,NV2:Nat},NextVar),TL) .

  op getVariants***$$ : Module Term Nat VariantFourSet Nat Variant UnificationTriple TermList -> VariantFourSet .
  eq getVariants***$$(M,T,NextVar,VTS,N,
         {T2:Term,S:Substitution,NV2:Nat,P:Parent,B:Bool},
         {S1:Substitution,S2:Substitution,NV2:Nat},TL)
   = getVariants***(M,T,NextVar,
             VTS | {T2:Term,S1:Substitution,S2:Substitution,NV2:Nat},
             N + 1,TL) .

  sort PairGeneralize .
  op {_,_} : TermList Nat -> PairGeneralize .
  op fst : PairGeneralize -> TermList .
  eq fst({X:TermList,Y:Nat}) = X:TermList .
  op snd : PairGeneralize -> Nat .
  eq snd({X:TermList,Y:Nat}) = Y:Nat .

  op generalize : Module Nat NeTermList -> PairGeneralize .
  eq generalize(M,NextVar,NeTL)
   = generalize*(M,NextVar,getEqs(M),NeTL) .

  op generalize* : Module Nat EquationSet TermList -> PairGeneralize .
  eq generalize*(M,NextVar,EqS,empty)
   = {empty,NextVar} .
  eq generalize*(M,NextVar,EqS,(T,TL))
   = {(fst(generalize**(M,NextVar,EqS,T)),
       fst(generalize*(M,snd(generalize**(M,NextVar,EqS,T)),EqS,TL))),
      snd(generalize*(M,snd(generalize**(M,NextVar,EqS,T)),EqS,TL))
     } .

  op generalize** : Module Nat EquationSet Term -> PairGeneralize .
  eq generalize**(M,NextVar,EqS,C)
   = {C,NextVar} .
  eq generalize**(M,NextVar,EqS,V)
   = {V,NextVar} .
  ceq generalize**(M,NextVar,(eq F'[TL'] = Rhs [AtS] .) EqS,F[TL])
    = {newVar(NextVar,getKind(M,leastSort(M,F[TL]))),NextVar + 1}
   if F == F'
      and-then
      glbSorts(M,leastSort(M,TL),leastSort(M,TL')) =/= none .
  eq generalize**(M,NextVar,EqS,F[TL])
   = {F[fst(generalize*(M,NextVar,EqS,TL))],
      snd(generalize*(M,NextVar,EqS,TL))}
  [owise] .

  *** Identify bound for terms
  op howMany : Module NeTermList -> Nat .
  eq howMany(M,NeTL)
   = howMany*(M,getEqs(M),NeTL << 0 < ) .

  op howMany* : Module EquationSet TermList -> Nat .
  eq howMany*(M,EqS,empty)
   = 0 .
  eq howMany*(M,EqS,(T,TL))
   = howMany**(M,EqS,T) + howMany*(M,EqS,TL) .

  op howMany** : Module EquationSet Term -> Nat .
  eq howMany**(M,EqS,C)
   = 0 .
  eq howMany**(M,EqS,V)
   = 0 .
  ceq howMany**(M,(eq F'[TL'] = Rhs [AtS] .) EqS,F[TL])
    = 1 + howMany*(M,(eq F'[TL'] = Rhs [AtS] .) EqS,TL)
   if F == F'
      and-then
      glbSorts(M,leastSort(M,TL),leastSort(M,TL')) =/= none
      and-then not isAssociative(M,F,getTypes(M,TL)) .
  ceq howMany**(M,(eq F'[TL'] = Rhs [AtS] .) EqS,F[TL])
    = sd(length(TL),1) + howMany*(M,(eq F'[TL'] = Rhs [AtS] .) EqS,TL)
   if F == F'
      and-then
      glbSorts(M,leastSort(M,TL),leastSort(M,TL')) =/= none
      and-then isCommutative(M,F,getTypes(M,TL))
      and-then isAssociative(M,F,getTypes(M,TL)) .
  eq howMany**(M,EqS,F[TL])
   = howMany*(M,EqS,TL) [owise] .


  *** Identify whether basic or variant narrowing should be used
  op howManyAC : Module NeTermList -> Nat .
  eq howManyAC(M,NeTL)
   = if howManyAC$(M,getEqs(M)) == 0
     then 0
     else howManyAC*(M,getEqs(M),NeTL << 0 < )
     fi .

  op howManyAC* : Module EquationSet TermList -> Nat .
  eq howManyAC*(M,EqS,empty)
   = 0 .
  eq howManyAC*(M,EqS,(T,TL))
   = howManyAC**(M,EqS,T) + howManyAC*(M,EqS,TL) .

  op howManyAC** : Module EquationSet Term -> Nat .
  eq howManyAC**(M,EqS,C)
   = 0 .
  eq howManyAC**(M,EqS,V)
   = 0 .
  ceq howManyAC**(M,(eq F'[TL'] = Rhs [AtS] .) EqS,F[TL])
    = sd(length(TL),1) + howManyAC*(M,(eq F'[TL'] = Rhs [AtS] .) EqS,TL)
   if F == F'
      and-then
      glbSorts(M,leastSort(M,TL),leastSort(M,TL')) =/= none
      and-then isCommutative(M,F,getTypes(M,TL))
      and-then isAssociative(M,F,getTypes(M,TL)) .
  eq howManyAC**(M,EqS,F[TL])
   = howManyAC*(M,EqS,TL) [owise] .

  op length : TermList -> Nat .
  eq length((empty).TermList) = 0 .
  eq length((T:Term,TL:TermList)) = 1 + length(TL:TermList) .

  op howManyAC$ : Module EquationSet -> Nat [memo] .
  eq howManyAC$(M,EqS)
   = howManyAC$$(M,EqS) .

  op howManyAC$$ : Module EquationSet -> Nat .
  eq howManyAC$$(M,none)
   = 0 .
  eq howManyAC$$(M,(eq F[TL] = Rhs [AtS] .) EqS)
    = if isCommutative(M,F,getTypes(M,TL))
         and isAssociative(M,F,getTypes(M,TL))
      then 1 else 0 fi
      + howManyAC$$(M,EqS) .

endfm

fmod META-ACU-UNIFICATION is
  pr TERM-HANDLING .
  pr SUBSTITUTION-HANDLING .
  pr MODULE-HANDLING .
  pr SUBSTITUTIONSET .
  pr UNIFICATIONPAIRSET .
  pr CONVERSION .
  pr META-LEVEL-MNPA .
  pr META-MINIMIZE-BINDINGS .
  pr META-E-UNIFICATION .

  var M : Module .
  vars T T' : Term .
  vars N N' : Nat .
  vars US : UnificationTripleSet .

  --- metaACUUnify --------------------------------------------------
  op metaACUUnify : Module Term Term -> SubstitutionSet .
  eq metaACUUnify(M, T, T')
   = toSubstitution(metaACUUnify(M, T, T', highestVar((T,T')) + 1)) .

  op metaACUUnify? : Module Term Term -> Bool .
  eq metaACUUnify?(M, T, T')
   = metaACUUnify?(M, T, T', highestVar((T,T')) + 1) .

  *** General Call for UnificationPairSet
  op metaACUUnify : Module Term Term Nat -> UnificationTripleSet .
  eq metaACUUnify(M, T, T', N)
   = metaACUUnify$(M, canonice(M,T), canonice(M,T'), N) .

  op metaACUUnify$ : Module Term Term Nat -> UnificationTripleSet .
                      --- Term Lhs
  eq metaACUUnify$(M, T, T', N)
   = if (root(T) =/= root(T')
         and not (root(T) :: Variable) and not (root(T') :: Variable))
        or-else
        glbSorts(M,leastSort(M,T),leastSort(M,T')) == none
     then empty
     else minimizeBindingsTerm(M,Vars(T),N,
              metaACUUnifyCollect(M, T, T',N,0,empty))
     fi .

  op metaACUUnify? : Module Term Term Nat -> Bool .
  eq metaACUUnify?(M, T, T', N)
   = metaACUUnify?$(M, canonice(M,T), canonice(M,T'), N) .

  op metaACUUnify?$ : Module Term Term Nat -> Bool .
  eq metaACUUnify?$(M, T, T', N)
   = glbSorts(M,leastSort(M,T),leastSort(M,T')) =/= none
     and-then
     (metaACUUnify*(M,T =? T',N,0) :: UnificationTriple?
      and
      metaACUUnify*(M,T =? T',N,0) =/= noUnifier) .

  op metaACUUnifyCollect : Module Term Term Nat Nat
                          UnificationTripleSet
                       -> UnificationTripleSet .
  eq metaACUUnifyCollect(M,T,T',N,N',US)
   = if metaACUUnify*(M,T =? T',N,N') :: UnificationTriple?
        and
        metaACUUnify*(M,T =? T',N,N') =/= noUnifier
     then metaACUUnifyCollect(M,T,T',N,s(N'),
             US | metaACUUnify*(M,T =? T',N,N') )
     else US
     fi .

  *** Code for collection all unifiers
  op metaACUUnify* : Module UnificandPair Nat Nat ~> UnificationTriple? .
  eq metaACUUnify*(M, T =? T',N,N')
   = metaUnifyTriple(
       keepOnlyACUAttr(eraseEqs(eraseRls(M))),
       unflatten(M,T) =? unflatten(M,T'),
       N,N') .

  op metaUnifyTriple : Module UnificationProblem Nat Nat ~> UnificationTriple? .
  eq metaUnifyTriple(M,T =? T',N,N')
   = if metaUnify(M,T =? T',N,N') == noUnifier
     then noUnifier
     else {getSubst(metaUnify(M,T =? T',N,N')) |> T,
           getSubst(metaUnify(M,T =? T',N,N')) |> T',
           getNextVar(metaUnify(M,T =? T',N,N'))}
     fi .
endfm

fmod META-UNIFICATION is
  pr META-ACU-UNIFICATION .

  var M : Module .
  var T T' : Term .
  var N : Nat .

  --- metaUnify --------------------------------------------------
  op metaCoreUnify : Module Term Term -> SubstitutionSet .
  eq metaCoreUnify(M, T, T')
   = toSubstitution(metaCoreUnify(M, T, T', highestVar((T,T')) + 1)) .

  op metaCoreUnify : Module Term Term Nat -> UnificationTripleSet .
                    --- Term Lhs
  eq metaCoreUnify(M, T, T', N)
   = metaACUUnify(M, T, T', N)  .

  op metaCoreUnify? : Module Term Term Nat -> Bool .
                    --- Term Lhs
  eq metaCoreUnify?(M, T, T', N)
   = metaACUUnify?(M, T, T', N)  .

endfm

fmod META-MSG-UNIFICATION is
  pr META-ACU-UNIFICATION .
  pr META-MATCH .

  var M : Module .
  vars T T' T1# T2# T1$ T2$ T1 T2 : Term .
  vars N N' N'' N1# N2# : Nat .
  vars S S' S1# S2# LSubst RSubst : Substitution .
  var UP : UnificationProblem .
  vars UTS UTS' : UnificationTripleSet .
  var C : Constant .
  vars V V' V1 V2 V3 : Variable .
  vars F F1 F2 : Qid .
  vars TL TL1 TL1' TL1'' TL2 TL2' TL2'' : TermList .
  var NeTL : NeTermList .

  var U : UnificationPair .
  vars US US' : UnificationPairSet .
  var SS SS' : SubstitutionSet .
  vars TP TP' : Type .
  var TPS : TypeSet .
  var TPL : TypeList .
  var AtS : AttrSet .
  var OPDS : OpDeclSet .

  ******* metaBuiltInMatch ***********************************************
  op metaBuiltInMatch : Module Term Term -> SubstitutionSet .
                           *** T1 instance of T2
  eq metaBuiltInMatch(M, T1, T2)
   = metaCoreMatch(M, T1, T2) .

  op metaBuiltInMatch? : Module Term Term -> Bool .
                           *** T1 instance of T2
  eq metaBuiltInMatch?(M, T1, T2)
   = metaCoreMatch?(M, T1, T2) .

  ******* metaBuiltInUnify ***********************************************
  op metaBuiltInUnify : Module Term Term -> SubstitutionSet .
  eq metaBuiltInUnify(M, T, T')
   = metaBuiltInUnify(M, empty, T, T') .

  op metaBuiltInUnify : Module TermList Term Term -> SubstitutionSet .
  eq metaBuiltInUnify(M, TL T, T')
   = toSubstitution(metaBuiltInUnify(M, TL, T, T', highestVar((T,T')) + 1)) .

  *** General Call for UnificationPairSet
  op metaBuiltInUnify : Module TermList Term Term Nat -> UnificationTripleSet .
                       --- Term Lhs
  eq metaBuiltInUnify(M, TL, T1, T2, N)
   = metaBuiltInUnify(M, T1, T2, N) .

  op metaBuiltInUnify : Module Term Term Nat -> UnificationTripleSet .
  eq metaBuiltInUnify(M, T1, T2, N)
   = metaCoreUnify(M, T1, T2, N) .

  op metaBuiltInUnify? : Module Term Term -> Bool .
  eq metaBuiltInUnify?(M, T, T')
   = metaBuiltInUnify?(M, empty, T, T') .

  op metaBuiltInUnify? : Module TermList Term Term -> Bool .
  eq metaBuiltInUnify?(M, TL, T, T')
   = metaBuiltInUnify?(M, TL, T, T',highestVar((T,T')) + 1) .

  op metaBuiltInUnify? : Module TermList Term Term Nat -> Bool .
  eq metaBuiltInUnify?(M, TL, T1, T2, N)
   = metaBuiltInUnify?(M, T1, T2, N)  .

  op metaBuiltInUnify? : Module Term Term Nat -> Bool .
  eq metaBuiltInUnify?(M, T1, T2, N)
   = metaCoreUnify?(M, T1, T2, N) .


endfm
fmod ORDERS-TERM-SUBSTITUTION is
  protecting TERM-HANDLING .
  protecting SUBSTITUTION-HANDLING .
  protecting META-MATCH .
  protecting META-LEVEL-MNPA .
  protecting META-UNIFICATION .
  protecting META-E-UNIFICATION .
  protecting RENAMING .
  protecting SUBSTITUTIONSET .
  protecting META-MSG-UNIFICATION .

  vars T T' : Term .
  vars TL TL' TL1 TL2 TL3 : TermList .
  var M : Module .
  vars S S' : Substitution .
  vars SS SS' SS'' : SubstitutionSet .
  vars V V' V1 V2 V3 : Variable .
  vars TPL TPL' : TypeList .
  vars N N' : Nat .
  vars F : Qid .
  var C : Constant .

  --- metaEMatch(M,T,T') implies that T is an instance of T' modulo E + axioms
  op metaEMatch : Module Term Term -> SubstitutionSet .
  eq metaEMatch(M,T,T')
   = if metaCoreMatch(M,T,T') =/= empty
     then metaCoreMatch(M,T,T')
     else if metaEBuiltInUnifyIrr?(M,T,T')
          then metaShared-filter(M,T,T',metaEBuiltInUnifyIrr(M,T,T'))
          else empty
          fi
     fi .

  op metaEMatch? : Module Term Term -> Bool .
  eq metaEMatch?(M,T,T')
   = metaCoreMatch?(M,T,T')
     or-else
     metaEBuiltInUnifyIrr?(M,T,T') .

  --- order between terms ---------------------------
  --- T <=[M] T' implies that T' is an instance of T
  op _<=[_]_ : Term Module Term -> Bool .
  eq T <=[M] T' = (metaCoreMatch(M,T',T) |> T) =/= empty .

  --- order between substitutions ---------------------------
  --- Subst <=[M] Subst' implies that Subst' is an instance of Subst
  op _<=[_]_ : SubstitutionSet Module SubstitutionSet -> Bool [ditto] .
  eq SS <=[M] SS'
   = SS <=[empty,M] SS' .

  op _<=[_`,_]_ : SubstitutionSet TermList Module SubstitutionSet -> Bool .
  eq empty <=[TL,M] SS'
   = false .
  eq SS <=[TL,M] SS'
   = SS <=[TL,M]$ SS' [owise] .

  op _<=[_`,_]$_ : SubstitutionSet TermList Module SubstitutionSet -> Bool .
  eq SS <=[TL,M]$ empty
   = true .
  eq SS <=[TL,M]$ (S' | SS')
   = (SS <=[TL,M]* S') and-then SS <=[TL,M]$ SS' .

  op _<=[_`,_]*_ : SubstitutionSet TermList Module Substitution -> Bool .
  eq empty <=[TL,M]* S'
   = false .
  eq (S | SS) <=[TL,M]* S'
   = S <=[TL,M]** S' or-else SS <=[TL,M]* S' .

  op _<=[_`,_]**_ : Substitution TermList Module Substitution -> Bool .
  eq none <=[TL,M]** S'
   = true .
  eq S <=[TL,M]** S'
   = 'Q[1st(gen(TL,S,S'))]
     *<=[
       addSorts('XXX,
       addOps((op 'Q : 3rd(gen(TL,S,S')) -> 'XXX [none] .),
         M))
     ]*
     'Q[2nd(gen(TL,S,S'))]
  [owise] .

  --- T <=[M] T' implies that T' is an instance of T
  --- T and T' can have shared variables
  op _*<=[_]*_ : Term Module Term -> Bool .
  eq T *<=[M]* T'
   = (if anyVars T inVars T'
      then metaCoreMatchShared(M,T',T)
      else metaCoreMatch(M,T',T)
      fi |> T)
     =/= empty .

  sort Triple .
  op {{_`,_`,_}} : TermList TermList TypeList -> Triple .
  op 1st : Triple -> TermList .
  eq 1st({{TL,TL',TPL}}) = TL .
  op 2nd : Triple -> TermList .
  eq 2nd({{TL,TL',TPL}}) = TL' .
  op 3rd : Triple -> TypeList .
  eq 3rd({{TL,TL',TPL}}) = TPL .

  ops gen : TermList Substitution Substitution -> Triple . ---[memo] .
  eq gen(empty,none,none)
   = {{empty,empty,nil}} .
  eq gen((V,TL),none,none)
   = {{(V,1st(gen(TL,none,none))),
       (V,2nd(gen(TL,none,none))),
       (getType(V) 3rd(gen(TL,none,none)))}} .
  eq gen(TL,none,V <- T ; S')
   = {{(V,1st(gen(TL \\ V,none,S'))),
       (T,2nd(gen(TL \\ V,none,S'))),
       (getType(V) 3rd(gen(TL \\ V,none,S')))}} .
  eq gen(TL,V <- T ; S,V <- T' ; S')
   = {{(T,1st(gen(TL \\ V,S,S'))),
       (T',2nd(gen(TL \\ V,S,S'))),
       (getType(V) 3rd(gen(TL \\ V,S,S')))}} .
  eq gen(TL,V <- T ; S,S')
   = {{(T,1st(gen(TL \\ V,S,S'))),
       (V,2nd(gen(TL \\ V,S,S'))),
       (getType(V) 3rd(gen(TL \\ V,S,S')))}}
   [owise] .

  op _\\_ : TermList Variable -> TermList .
  eq (TL,V,TL') \\ V = (TL,TL') .
  eq TL \\ V = TL [owise] .

  --- renaming -----------------------------------------------
  op _=[_]=_ : TermSet Module TermSet -> Bool .
  eq T1:TermSet =[M]= T2:TermSet
   = metaBuiltInRenaming(M,T1:TermSet,T2:TermSet) .

  *****
  op metaBuiltInRenaming : Module TermSet TermSet -> Bool .
  eq metaBuiltInRenaming(M,emptyTermSet,emptyTermSet)
   = true .
 ceq metaBuiltInRenaming(M,T:Term | T:TermSet,T':Term | T':TermSet)
    = metaBuiltInRenaming(M,T:TermSet,T':TermSet)
   if metaBuiltInRenaming$(M,T:Term,T':Term) .
  eq metaBuiltInRenaming(M,T:TermSet,T':TermSet)
   = false [owise] .

  op metaBuiltInRenaming$ : Module Term Term -> Bool .
  eq metaBuiltInRenaming$(M,T:Term,T':Term)
   = canonice(M,nullVars(T)) == canonice(M,nullVars(T'))
     and-then
     (metaBuiltInRenaming$$1(M,canonice(M,T),canonice(M,T'))
      or-else
      metaBuiltInRenaming$$2(M,canonice(M,T),canonice(M,T'))
      ) .

  op metaBuiltInRenaming$$1 : Module Term Term -> Bool .
  eq metaBuiltInRenaming$$1(M,T:Term,T':Term)
   = metaBuiltInRenaming$$1*(
         canonice(M,totalOrder(M,flatten(M,T:Term)) <<( 0 )<),
         canonice(M,totalOrder(M,flatten(M,T':Term)) <<( 0 )<) ) .

  op metaBuiltInRenaming$$1* : Term Term -> Bool .
  eq metaBuiltInRenaming$$1*(T:Term,T':Term) = T:Term == T':Term .

  op totalOrder : Module Term -> Term .
  eq totalOrder(M,C) = C .
  eq totalOrder(M,V) = V .
  eq totalOrder(M,F[TL])
   = if not isCommutative(M,F[TL])
     then F[totalOrderTL(M,TL)]
     else F[reorderTL(M,F,totalOrderTL(M,TL))]
     fi .

  op totalOrderTL : Module TermList -> TermList .
  eq totalOrderTL(M,empty) = empty .
  eq totalOrderTL(M,(T,TL)) = (totalOrder(M,T),totalOrderTL(M,TL)) .

  op reorderTL : Module Qid TermList -> TermList .
  eq reorderTL(M,F,empty) = empty .
  eq reorderTL(M,F,(T,TL))
   = if insertTL(M,F,T,TL) =/= (T,TL)
     then reorderTL(M,F,insertTL(M,F,T,TL))
     else (T,reorderTL(M,F,TL))
     fi .

  op insertTL : Module Qid Term TermList -> TermList .
  eq insertTL(M,F,T',empty) = T' .
  eq insertTL(M,F,T',(T,TL))
   = if canonice(M,F[nullVars(T'),nullVars(T)]) == F[canonice(M,nullVars(T')),canonice(M,nullVars(T))]
     then (T',T,TL)
     else (T,insertTL(M,F,T',TL))
     fi .

  op nullVars : Term -> Term .
  eq nullVars(C) = C .
  eq nullVars(V) = qid("#0:" + string(getType(V))) .
  eq nullVars(F[TL]) = F[nullVarsTL(TL)] .

  op nullVarsTL : TermList -> TermList .
  eq nullVarsTL(empty) = empty .
  eq nullVarsTL((T,TL)) = (nullVars(T),nullVarsTL(TL)) .

  *****
  op metaBuiltInRenaming$$2 : Module Term Term -> Bool .
  eq metaBuiltInRenaming$$2(M,T:Term,T':Term)
   = T == T'
     or-else
     onlyRenamingAny(M,metaBuiltInMatchShared(M,T',T) |> T) .

  *****
  op onlyRenamingAll : Module SubstitutionSet -> Bool .
  eq onlyRenamingAll(M,empty)
   = true .
  eq onlyRenamingAll(M,S | SS)
   = onlyRenaming*(M,S)
     and-then
     onlyRenamingAll(M,SS) .

  op onlyRenamingAny : Module SubstitutionSet -> Bool .
  eq onlyRenamingAny(M,empty)
   = false .
  eq onlyRenamingAny(M,S | SS)
   = onlyRenaming*(M,S)
     or-else
     onlyRenamingAny(M,SS) .

  op onlyRenaming* : Module Substitution -> Bool .
  eq onlyRenaming*(M,(V <- T) ; (V' <- T) ; S)
   = false .
  eq onlyRenaming*(M,S)
   = onlyRenaming**(M,S) [owise] .

  op onlyRenaming** : Module Substitution -> Bool .
 ceq onlyRenaming**(M,(V <- F[TL]) ; S)
   = onlyRenaming*(M,
        canonice(M, S << (V1 <- getIdSymbol(M,F[TL])))
     )
  if getIdSymbol(M,F[TL]) :: Term
  /\ TL1,V1,TL2,V2,TL3 := TL
  /\ typeLeq(M,getType(getIdSymbol(M,F[TL])),getType(V1))
     and-then
     not (V1 in Vars((TL1,TL2,V2,TL3)))
  /\ typeLeq(M,getType(getIdSymbol(M,F[TL])),getType(V2))
     and-then
     not (V2 in Vars((TL1,V1,TL2,TL3))) .
  eq onlyRenaming**(M,S)
   = onlyRenaming***(S) [owise] .

  op onlyRenaming*** : Substitution -> Bool .
  eq onlyRenaming***(none)
   = true .
  eq onlyRenaming***((V <- T) ; S)
   = T :: Variable
     and-then
     getType(V) == getType(T)
     and-then
     onlyRenaming***(S) .

  --- Standard metaMatch does not deal with shared variables between T and T'
  --- metaCoreMatch(M,T,T') implies that T is an instance of T'

  op metaCoreMatchShared : Module Term Term -> SubstitutionSet .
  eq metaCoreMatchShared(M,T,T')
   = metaShared-filter(M,T,T',metaCoreMatch(M,T,T')) .

  op metaBuiltInMatchShared : Module Term Term -> SubstitutionSet .
  eq metaBuiltInMatchShared(M,T,T')
   = metaShared-filter(M,T,T',metaBuiltInMatch(M,T,T')) .

  *******
  op metaShared-filter : Module Term Term SubstitutionSet
                           -> SubstitutionSet .
  eq metaShared-filter(M,T,T',SS)
   = metaShared-filter*(M,T,T',empty,SS) .

  op metaShared-filter* : Module Term Term SubstitutionSet SubstitutionSet
                           -> SubstitutionSet .
  eq metaShared-filter*(M,T,T',SS',empty)
   = SS' .
  eq metaShared-filter*(M,T,T',SS',S | SS)
   = metaShared-filter*(M,T,T',
        if S |> T == none
        then SS' | S
        else SS'
        fi,
     SS ) .


  *** Normalize Substitutions
  op normalizedSubstitution? : Module SubstitutionSet -> Bool .
  eq normalizedSubstitution?(M, empty)
   = true .
  eq normalizedSubstitution?(M, S | SS)
   = normalizedSubstitution?*(M, S) and-then normalizedSubstitution?(M, SS) .

  op normalizedSubstitution?* : Module Substitution -> Bool . ---[memo] .
  eq normalizedSubstitution?*(M, none)
   = true .
  eq normalizedSubstitution?*(M, V <- T ; S:Substitution)
   = isNF$(clearAllFrozen(M),T)
     and-then
     normalizedSubstitution?*(M, S:Substitution) .

  *** Normalize Substitutions
  op |_|`(_`) : SubstitutionSet Module -> SubstitutionSet .
  eq | S:SubstitutionSet |(M)
   = eqNormalizeSubstitution(M,S:SubstitutionSet) .

  op eqNormalizeSubstitution : Module SubstitutionSet -> SubstitutionSet .
  eq eqNormalizeSubstitution(M, empty)
   = empty .
  eq eqNormalizeSubstitution(M, S | SS)
   = eqNormalizeSubstitution*(M, S) | eqNormalizeSubstitution(M, SS) .

  op eqNormalizeSubstitution* : Module Substitution -> Substitution .
  eq eqNormalizeSubstitution*(M, none)
   = none .
  eq eqNormalizeSubstitution*(M, V <- T ; S:Substitution)
   = V <- getTerm(metaReduce(eraseRls(M),T))
     ; eqNormalizeSubstitution*(M, S:Substitution) .

endfm
fmod META-NORMALIZE is
  protecting META-TERM .
  protecting META-LEVEL-MNPA .
  protecting META-UNIFICATION .
  protecting RESULT-CONTEXT-SET .
  protecting ORDERS-TERM-SUBSTITUTION .
  protecting TYPEOFNARROWING .

  vars T T' TOrig Lhs Rhs TS TS' CtTS CtTS' : Term .
  var V : Variable .
  var C : Constant .
  var F : Qid .
  vars TL TL' : TermList .
  var M : Module .
  vars RTS RTS' RTS$ RTS$' : ResultContextSet .
  vars RT RT' : ResultContext .
  vars TP TP' : Type .
  vars S S' S* S'* Subst : Substitution .
  var RLS : RuleSet .
  var Att : AttrSet .
  vars B BN : Bound .
  vars N NextVar NextVar' : Nat .
  var NL : NatList .
  vars Ct CtS Ct' CtS' : Context .
  var ON : TypeOfNarrowing .
  var QQ : TypeOfRelation .

  op |_| : ResultTripleSet -> Nat .
  eq | (empty).ResultTripleSet | = 0 .
  eq | {T,TP,S} | RTS:ResultTripleSet | = s(| RTS:ResultTripleSet |) .

  *** Shortcut to Normalization by rewriting Search
  op metaNormalizeCollect$ : Module Term ~> ResultTripleSet .
  eq metaNormalizeCollect$(M,T)
   = metaNormalizeCollect$(M,{T,leastSort(M,T),none}) .

  op metaNormalizeCollect$ : Module Term Type ~> ResultTripleSet .
  eq metaNormalizeCollect$(M,T,TP)
   = metaNormalizeCollect$(M,{T,TP,none}) .

  op metaNormalizeCollect$ : Module ResultTriple ~> ResultTripleSet .
  eq metaNormalizeCollect$(M,{T,TP,S})
   = metaSearchCollect(M,
       T, (addType TP ToVar 'XXXXXXX),
       '!,unbounded) .

  *** Shortcut to One rewriting step
  op metaOneRewriting$ : Module Term ~> ResultTripleSet .
  eq metaOneRewriting$(M,T)
   = metaOneRewriting$(M,{T,leastSort(M,T),none}) .

  op metaOneRewriting$ : Module Term Type -> ResultTripleSet .
  eq metaOneRewriting$(M,T,TP)
   = metaOneRewriting$(M,{T,TP,none}) .

  op metaOneRewriting$ : Module ResultTriple -> ResultTripleSet .

  eq metaOneRewriting$(M,{T,TP,S})
   = metaSearchCollect(M,
       T, (addType TP ToVar 'XXXXXXX),
       '+,1) .

  *** Use Standard Maude metaSearch
  op metaSearchCollect : Module Term Term TypeOfRelation Bound
                      ~> ResultTripleSet .
  eq metaSearchCollect(M,T,T',QQ,B)
   = metaSearchCollect(M,T,T',QQ,B,0) .

  op metaSearchCollect : Module Term Term TypeOfRelation Bound Nat
                      ~> ResultTripleSet .
  eq metaSearchCollect(M,T,T',QQ,B,N:Nat)
   = if metaSearch(M,T,T',nil,[QQ],B,N:Nat) :: ResultTripleSet
        and
        metaSearch(M,T,T',nil,[QQ],B,N:Nat) =/= failure
     then metaSearch(M,T,T',nil,[QQ],B,N:Nat)
          |
          metaSearchCollect(M,T,T',QQ,B,s(N:Nat))
     else empty
     fi .

  *** Shortcut to normal form detection
  op isNF$ : Module Substitution ~> Bool .
  eq isNF$(M, (none).Substitution)
   = true .
  eq isNF$(M, V:Variable <- T:Term ; S:Substitution)
   = isNF$(M,T) and-then isNF$(M, S:Substitution) .

  op isNF$ : Module Term ~> Bool .
  eq isNF$(M,T) = isNF$$(M,T,leastSort(M,T)) .

  op isNF$$ : Module Term Type ~> Bool .
  eq isNF$$(M,T,TP)
   = metaSearch(M,T,(addType TP ToVar 'XXXXXXX),nil,'+,1,0) == failure .

  ***********************************************************************
  --- Not defined in this module-------------
  op metaNarrowSearchAll : Module Term Term SubstitutionCond TypeOfRelation
                            Bound Bound --- number steps / number solutions
                            Bound --- chosen solution
                            TypeOfNarrowing
                            ResultContextSet
			 -> ResultContextSet .
  --- Not defined in this module-------------

  op metaNormalizeCollect : Module Term ~> ResultTripleSet .
  eq metaNormalizeCollect(M,T)
   = if anyNonExec(M)
     then metaNormalizeCollect#(M,T)
     else metaNormalizeCollect$(M,T)
     fi .

  op metaNormalizeCollect : Module Term Type -> ResultTripleSet .
  eq metaNormalizeCollect(M,T,TP)
   = if anyNonExec(M)
     then metaNormalizeCollect#(M,T,TP)
     else metaNormalizeCollect$(M,T,TP)
     fi .

  op metaNormalizeCollect : Module ResultTriple -> ResultTripleSet .
  eq metaNormalizeCollect(M,{T,TP,S})
   = if anyNonExec(M)
     then metaNormalizeCollect#(M,{T,TP,S})
     else metaNormalizeCollect$(M,{T,TP,S})
     fi .

  op metaOneRewriting : Module Term ~> ResultTripleSet .
  eq metaOneRewriting(M,T)
   = if anyNonExec(M)
     then metaOneRewriting#(M,T)
     else metaOneRewriting$(M,T)
     fi .

  op metaOneRewriting : Module Term Type -> ResultTripleSet .
  eq metaOneRewriting(M,T,TP)
   = if anyNonExec(M)
     then metaOneRewriting#(M,T,TP)
     else metaOneRewriting$(M,T,TP)
     fi .

  op metaOneRewriting : Module ResultTriple -> ResultTripleSet .
  eq metaOneRewriting(M,{T,TP,S})
   = if anyNonExec(M)
     then metaOneRewriting#(M,{T,TP,S})
     else metaOneRewriting$(M,{T,TP,S})
     fi .

  --- Based on narrowing -----------------------------
  op metaNormalizeCollect# : Module Term ~> ResultTripleSet .
  eq metaNormalizeCollect#(M,T)
   = metaNormalizeCollect#(M,{T,leastSort(M,T),none}) .

  op metaNormalizeCollect# : Module Term Type -> ResultTripleSet .
  eq metaNormalizeCollect#(M,T,TP)
   = metaNormalizeCollect#(M,{T,TP,none}) .

  ---metaSearch of Maude doesn't work for rules with extra vars
  op metaNormalizeCollect# : Module ResultTriple -> ResultTripleSet .
  eq metaNormalizeCollect#(M,{T,TP,S})
   = toTriple(M,
     metaNarrowSearchAll(
       M,
       T, (addType TP ToVar 'XXXXXXX),
       none,'!,unbounded,unbounded,unbounded,E-rewriting noStrategy,
       {T,TP,S,none,[],[],T << S,T << S,
        max(highestVar(S),highestVar((T,T << S))) + 1,
        nil,
        empty}
     )) .

  op metaOneRewriting# : Module Term ~> ResultTripleSet .
  eq metaOneRewriting#(M,T)
   = metaOneRewriting#(M,{T,leastSort(M,T),none}) .

  op metaOneRewriting# : Module Term Type -> ResultTripleSet .
  eq metaOneRewriting#(M,T,TP)
   = metaOneRewriting#(M,{T,TP,none}) .

  op metaOneRewriting# : Module ResultTriple -> ResultTripleSet .
  eq metaOneRewriting#(M,{T,TP,S})
   = toTriple(M,
     metaNarrowSearchAll(
       M,
       T, (addType TP ToVar 'XXXXXXX),
       none,'+,1,unbounded,unbounded,E-rewriting noStrategy,
       {T,TP,S,none,[],[],T << S,T << S,
        max(highestVar(S),highestVar((T,T << S))) + 1,
        nil,
        empty}
     )) .

  *** Remove itself
  op noSelf : ResultContextSet ResultContextSet -> ResultContextSet .
  eq noSelf(empty,RTS')
   = RTS' .
  eq noSelf({T,TP,S,S*,Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags} | RTS,RTS')
   = noSelf(RTS,
      if TS == T and-then CtTS == T and-then Ct == [] and-then CtS == []
      then noSelf*({T,TP,S,S*,Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags}, RTS')
      else RTS'
      fi
     ) .

  op noSelf* : ResultContext ResultContextSet -> ResultContextSet .
  eq noSelf*(RT,empty)
   = empty .
  eq noSelf*({T,TP,S,S*,[],[],T,T,NextVar,Tr:TraceNarrow,B:Flags},
             {T',TP',S',S'*,Ct',CtS',TS',CtTS',NextVar',Tr':TraceNarrow,B':Flags} | RTS)
   = if TS' == T' and-then CtTS' == T' and-then Ct' == [] and-then CtS' == []
        and-then
        T == T' and-then TP == TP'
        and-then
        (S |> T) == (S' |> T)
     then ---remove
          empty
     else ---keep
          {T',TP',S',S'*,Ct',CtS',TS',CtTS',NextVar',Tr:TraceNarrow,B':Flags}
     fi
     | noSelf*({T,TP,S,S*,[],[],T,T,NextVar,Tr':TraceNarrow,B:Flags},RTS) .

endfm

fmod META-E-NARROWING is
  protecting META-TERM .
  protecting META-LEVEL-MNPA .
  protecting META-UNIFICATION .
  protecting META-MSG-UNIFICATION .
  protecting META-E-UNIFICATION .
  protecting RESULT-CONTEXT-SET .
  protecting ORDERS-TERM-SUBSTITUTION .
  protecting TYPEOFNARROWING .
  protecting META-NORMALIZE .
  protecting UNIFICATIONTRIPLESET .
  protecting RIGIDIFE .

  var T T' T'' TOrig Lhs Lhs' Rhs Rhs'  : Term .
  var CT' TS TS' TS'' CtTS CtTS' CtTS'' : Term .
  var V : Variable .
  var C : Constant .
  var F : Qid .
  var M : Module .
  var RTS RTS' RTS$ RTS-Rls RTS-Sub RTSSol : ResultContextSet .
  var RTNeS : ResultContextNeSet .
  var RT RT' : ResultContext .
  vars S S' S'' Subst Subst' S* S'* : Substitution .
  var SS : SubstitutionSet .
  var RLS : RuleSet .
  var RL : Rule .
  vars Att Att' : AttrSet .
  var B BN : Bound .
  vars N N' N1 N2 : Nat .
  var NL : NatList .
  vars Ct CtS Ct' CtS' Ct'' CtS'' : Context .
  var NeTL NeTL' : NeTermList .
  vars TL TL' TL'' TL''' : TermList .
  vars TP TP' TP'' : Type .
  var ON : TypeOfNarrowing .
  vars NextVar NextVar' NextVar'' NVarPrev : Nat .
  var U : UnificationTriple .
  vars US US' : UnificationTripleSet .
  var IRR : IrrFlags .

  --- metaNarrow ---------------------------
  ---( We implement:
       * basic narrowing, where terms introduced
         by unifiers (substitutions) are never
         selected for narrowing, and
       * standard narrowing, where this
         restriction does not apply  )


  *** Shortcuts to Narrowing
  op metaNarrow : Module Term -> ResultTripleSet .
  eq metaNarrow(M,T) = metaNarrow(M,T,1) .

  op metaNarrow : Module Term Bound -> ResultTripleSet .
  eq metaNarrow(M,T,B)
   = toTriple(M,metaENarrowShowAll(M,T,B,full noStrategy BuiltIn-unify)) |> T .

  *** Shortcuts to Basic Narrowing
  op metaBasicNarrow : Module Term -> ResultTripleSet .
  eq metaBasicNarrow(M,T) = metaBasicNarrow(M,T,1) .

  op metaBasicNarrow : Module Term Bound -> ResultTripleSet .
  eq metaBasicNarrow(M,T,B)
   = toTriple(M,metaENarrowShowAll(M,T,B,basic noStrategy BuiltIn-unify)) |> T .

  *** Shortcuts to Narrowing
  op metaENarrow : Module Term -> ResultTripleSet .
  eq metaENarrow(M,T) = metaENarrow(M,T,1) .

  op metaENarrow : Module Term Bound -> ResultTripleSet .
  eq metaENarrow(M,T,B)
   = toTriple(M,metaENarrowShowAll(M,T,B,full noStrategy E-BuiltIn-unify))
     |> T .

  *** Shortcuts to Narrowing
  op metaEBuiltInTopMostNarrow : Module Term Nat -> ResultTripleSet .
  eq metaEBuiltInTopMostNarrow(M,T,N)
   = metaETopMostNarrow(M,T,1,reducible, E-BuiltIn-unify,N) .
  op metaEBuiltInTopMostNarrowIrr : Module Term Nat -> ResultTripleSet .
  eq metaEBuiltInTopMostNarrowIrr(M,T,N)
   = metaETopMostNarrow(M,T,1,irreducible, E-BuiltIn-unify,N) .

  op metaEACUTopMostNarrow : Module Term Nat -> ResultTripleSet .
  eq metaEACUTopMostNarrow(M,T,N)
   = metaETopMostNarrow(M,T,1,reducible, E-ACU-unify,N) .
  op metaEACUTopMostNarrowIrr : Module Term Nat -> ResultTripleSet .
  eq metaEACUTopMostNarrowIrr(M,T,N)
   = metaETopMostNarrow(M,T,1,irreducible, E-ACU-unify,N) .

  op metaETopMostNarrow : Module Term Bound IrrFlags TypeOfNarrowing Nat
                       -> ResultTripleSet .
  eq metaETopMostNarrow(M,T,B,IRR,ON,N)
   = toTriple(M,metaENarrowShowAll(M,T,B,full topmost ON [IRR],N)) |> T .

  op metaEBuiltInTopMostNarrowRC : Module Term TermList Nat -> ResultContextSet .
  eq metaEBuiltInTopMostNarrowRC(M,T,TL,N)
   = metaETopMostNarrowRC(M,T,1,reducible, E-BuiltIn-unify irrTerms(TL),N) .
  op metaEBuiltInTopMostNarrowRCIrr : Module Term TermList Nat -> ResultContextSet .
  eq metaEBuiltInTopMostNarrowRCIrr(M,T,TL,N)
   = metaETopMostNarrowRC(M,T,1,irreducible, E-BuiltIn-unify irrTerms(TL),N) .

  op metaEACUTopMostNarrowRC : Module Term Nat -> ResultContextSet .
  eq metaEACUTopMostNarrowRC(M,T,N)
   = metaETopMostNarrowRC(M,T,1,reducible, E-ACU-unify,N) .
  op metaEACUTopMostNarrowRCIrr : Module Term Nat -> ResultContextSet .
  eq metaEACUTopMostNarrowRCIrr(M,T,N)
   = metaETopMostNarrowRC(M,T,1,irreducible, E-ACU-unify,N) .

  op metaETopMostNarrowRC : Module Term Bound IrrFlags TypeOfNarrowing Nat
                       -> ResultContextSet .
  eq metaETopMostNarrowRC(M,T,B,IRR,ON,N)
   = metaENarrowShowAll(M,T,B,full topmost ON [IRR],N) |> T .

  --- Auxiliary
  op [_,_] : TypeOfNarrowing IrrFlags ~> TypeOfNarrowing .
  eq [ E-ACU-unify, reducible ] = E-ACU-unify .
  eq [ E-ACU-unify, irreducible ] = E-ACU-unify-Irr .
  eq [ E-BuiltIn-unify, reducible ] = E-BuiltIn-unify .
  eq [ E-BuiltIn-unify, irreducible ] = E-BuiltIn-unify-Irr .

  *** Shortcuts to Basic Narrowing
  op metaEBasicNarrow : Module Term -> ResultTripleSet .
  eq metaEBasicNarrow(M,T)
   = metaEBasicNarrow(M,T,1) .

  *** Shortcuts for normalization
  op metaEBasicNarrow : Module Term Bound -> ResultTripleSet .
  eq metaEBasicNarrow(M,T,B)
   = toTriple(M,metaENarrowShowAll(M,T,B,E-BuiltIn-unify noStrategy basic)) |> T .

  op metaBasicNarrowNormalize : Module Term -> ResultTripleSet .
  eq metaBasicNarrowNormalize(M,T)
   = toTriple(M,metaBasicNarrowNormalizeAll(M,T,highestVar(T) + 1)) |> T .

  op metaBasicNarrowNormalizeAll : Module Term Nat -> ResultContextSet .
  eq metaBasicNarrowNormalizeAll(M,T,NextVar)
   = metaENarrowShowAll(M,T,unbounded,
         basic BuiltIn-unify
         computed-normalized-subs applied-normalized-subs
         normalize-terms noStrategy,NextVar) .

  op metaNarrowNormalize : Module Term -> ResultTripleSet .
  eq metaNarrowNormalize(M,T)
   = toTriple(M,metaNarrowNormalizeAll(M,T,highestVar(T) + 1)) |> T .

  op metaNarrowNormalizeAll : Module Term Nat -> ResultContextSet .
  eq metaNarrowNormalizeAll(M,T,NextVar)
   = metaENarrowShowAll(M,T,unbounded,
         full BuiltIn-unify
         computed-normalized-subs applied-normalized-subs
         normalize-terms noStrategy,NextVar) .

  *** General Call
  op metaENarrowShowAll : Module Term Bound TypeOfNarrowing
                       -> ResultContextSet .
  eq metaENarrowShowAll(M,T,B,ON)
   = metaENarrowShowAll(M,T,B,ON,highestVar(T) + 1) .

  op metaENarrowShowAll : Module Term Bound TypeOfNarrowing Nat
                       -> ResultContextSet .
  eq metaENarrowShowAll(M,T,B,ON,N)
   = metaENarrowGen(removeBoolEqs(M),B,ON,
       {T,leastSort(M,T),none,none,[],[],T,T,N,nil,empty}) .

  *** Call for ResultContextSet
  op metaENarrowGen : Module Bound TypeOfNarrowing
                      ResultContextSet
                   -> ResultContextSet .

  eq metaENarrowGen(M,B,ON,RTS)
   = if B == 0
     then RTS
     else metaENarrowGen*(M,B,ON,empty,empty,RTS)
     fi .

  op metaENarrowGen* : Module
                       Bound TypeOfNarrowing
                       ResultContextSet ResultContextSet ResultContextSet
                    -> ResultContextSet .
  eq metaENarrowGen*(M,B,ON,RTSSol,RTS',empty)
   = if RTS' == empty
        or-else
        (B =/= unbounded and-then B <= 1)
     then RTSSol | RTS' --- Stop
     else metaENarrowGen*(M,dec(B),ON,RTSSol,empty,RTS')
     fi .
  eq metaENarrowGen*(M,B,ON,RTSSol,RTS',RT | RTS)
   = if isEND(normalize-terms?(M,ON,RT))
     then metaENarrowGen*(M,B,ON,
          RTSSol | normalize-terms?(M,ON,RT),
          RTS',RTS)
     else metaENarrowGen*(M,B,ON,RTSSol,
          RTS' |
             filter-variant-RT(M,ON,normalize-terms?(M,ON,RT),
                metaENarrowGen**(M,B,ON,normalize-terms?(M,ON,RT))),
          RTS)
     fi .

  op testNonVarRedex : TypeOfNarrowing Term Term -> Bool .
  eq testNonVarRedex(alsoAtVarPosition ON,T,TS) = true .
  eq testNonVarRedex(ON,T,TS) = testNonVarRedex*(ON,T,TS) [owise] .

  op testNonVarRedex* : TypeOfNarrowing Term Term -> Bool .
  eq testNonVarRedex*(basic ON,T,TS) = not(T :: Variable) .
  eq testNonVarRedex*(ON,T,TS)       = not(TS :: Variable) [owise] .

  op metaENarrowGen** : Module
                        Bound TypeOfNarrowing
                        ResultContext
                     -> ResultContextSet .
  eq metaENarrowGen**(M,B,ON,{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags})
   = if not testNonVarRedex(ON,T,TS) --- T is a variable
     then if CtS == []
          then *** Term CtTS is a normal form so we return it
               {T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags}
	  else *** Term T is a rigid normal form inside a context Ct
	       *** but since no rewrite has been done and
               *** this can be part of a previous metaNarrowSub call,
               *** this path is discarded
               empty
          fi
     else if metaENarrowStra(M,B,ON,{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags})
	     =/= empty
          then metaENarrowStra(M,B,ON,{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags})
          else if CtS == []
               then *** Term CtTS is a normal form so we return it
                    {T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,end(true,B:Flags)}
	       else *** Term T is a rigid normal form inside a context Ct
	            *** but since no rewrite has been done and
                    *** this can be part of a previous metaNarrowSub call,
                    *** this path is discarded
                    empty
               fi
          fi
     fi .

  *** Try all rules at top level of term T in context Ct with metaENarrowRls
  *** Try also inner subterms of T with metaENarrowSub
  *** Note that metaENarrowRls and metaENarrowSub
  *** call to metaNarrow recursively
  op metaENarrowStra : Module Bound TypeOfNarrowing ResultContext
                    -> ResultContextSet .
  ---innermost
  eq metaENarrowStra(M,B,innermost ON,RT)
   = if metaENarrowSub(M,B,innermost ON,RT) =/= empty
     then metaENarrowSub(M,B,innermost ON,RT)
     else metaENarrowRls(M,B,innermost ON,getRls(M),RT)
     fi .

  ---outermost
  eq metaENarrowStra(M,B,outermost ON,RT)
   = if metaENarrowRls(M,B,outermost ON,getRls(M),RT) =/= empty
     then metaENarrowRls(M,B,outermost ON,getRls(M),RT)
     else metaENarrowSub(M,B,outermost ON,RT)
     fi .

  ---topmost
  eq metaENarrowStra(M,B,topmost ON,RT)
   = metaENarrowRls(M,B,topmost ON,getRls(M),RT) .

  ---noStrategy
  eq metaENarrowStra(M,B,noStrategy ON,RT)
   = metaENarrowRls(M,B,noStrategy ON,getRls(M),RT)
     |
     metaENarrowSub(M,B,noStrategy ON,RT) .

  op dec : Bound -> Bound .
  eq dec(unbounded) = unbounded .
  eq dec(s(N)) = N .

  *** Generic call to metaUnification with different parameters
  op auxMetaUnify : Module TypeOfNarrowing
                    Term Term Nat ~> UnificationTripleSet .
		--- Term Lhs
  eq auxMetaUnify(M,variant(N') ON,T,T',N)
   = unrigidife(qid(N'),
       auxMetaUnify*(getM(rigidifeNat(M,qid(N'),T,N')),
                     variant(N') ON,
                     getTL(rigidifeNat(M,qid(N'),T,N')),
                     T',
                     N)
     ) .

  eq auxMetaUnify(M,ON,T,T',N)
   = auxMetaUnify*(M,ON,T,T',N) [owise] .

  op auxMetaUnify* : Module TypeOfNarrowing
                    Term Term Nat ~> UnificationTripleSet .
		--- Term Lhs
 ceq auxMetaUnify*(M,rigidife(F:Qid) ON,T,T',N)
   = unrigidife(Q:Qid,
       auxMetaUnify**(M#:Module,rigidife(F:Qid) ON,T#:Term,T',N)
     )
  if F:Qid[TL:TermList] := T
  /\ Q:Qid := 'auxMetaUnify
  /\ X:PairRigidife := rigidifeRigid(M,Q:Qid,T)
  /\ M#:Module := getM(X:PairRigidife)
  /\ T#:Term := getTL(X:PairRigidife) .

  eq auxMetaUnify*(M,ON,T,T',N)
   = auxMetaUnify**(M,ON,T,T',N) [owise] .

  op auxMetaUnify** : Module TypeOfNarrowing
                     Term Term Nat ~> UnificationTripleSet .
		 --- Term Lhs
                 --- [memo] . --- Very useful but huge space use
  eq auxMetaUnify**(M,E-rewriting ON,T,T',N)
   = toUnificationTriple[N](metaCoreMatch(removeBoolEqs(M),T,T')) .
  eq auxMetaUnify**(M,E-ACU-unify ON,T,T',N)
   = metaEACUUnify(removeBoolEqs(M),T,T',getIrrTerms(ON),N,reducible) .
  eq auxMetaUnify**(M,E-ACU-unify-Irr ON,T,T',N)
   = metaEACUUnify(removeBoolEqs(M),T,T',getIrrTerms(ON),N,irreducible) .
  eq auxMetaUnify**(M,E-BuiltIn-unify ON,T,T',N)
   = metaEBuiltInUnify(removeBoolEqs(M),T,T',getIrrTerms(ON),N,reducible) .
  eq auxMetaUnify**(M,E-BuiltIn-unify-Irr ON,T,T',N)
   = metaEBuiltInUnify(removeBoolEqs(M),T,T',getIrrTerms(ON),N,irreducible) .
  eq auxMetaUnify**(M,ACU-unify ON,T,T',N)
   = metaACUUnify(removeBoolEqs(M),T,T',N) .
  eq auxMetaUnify**(M,BuiltIn-unify ON,T,T',N)
   = metaBuiltInUnify(removeBoolEqs(M),getIrrTerms(ON),T,T',N) .

  *** Remove rigid normal forms
  op removeEND : ResultContextSet -> ResultContextSet .
  eq removeEND(RTS)
   = removeEND*(RTS,empty) .

  op removeEND* : ResultContextSet ResultContextSet -> ResultContextSet .
  eq removeEND*(empty,RTS')
   = RTS' .
  eq removeEND*(RT | RTS,RTS')
   = removeEND*(RTS,if isEND(RT) then RTS' else RTS' | RT fi) .

  op remove_From_ : ResultContextSet ResultContextSet -> ResultContextSet .
  eq remove(RT | RTS) From (RT | RTS')
   = remove(RTS) From (RT | RTS') .
  eq remove(RTS) From (RTS')
   = RTS [owise] .

  op isEND : ResultContext -> Bool .
  eq isEND({T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags})
   = end(B:Flags) .

  *** Call for Rules ---> Returns empty if no rule is applied
  op metaENarrowRls : Module Bound TypeOfNarrowing
                      RuleSet ResultContext
                   -> ResultContextSet .
  eq metaENarrowRls(M,B,ON,RL RLS,RT)
   = metaENarrowRls#(M,B,ON,RL RLS,RT,empty) .
  eq metaENarrowRls(M,B,ON,none,RT)
   = empty .

  op metaENarrowRls# : Module Bound TypeOfNarrowing
                      RuleSet ResultContext ResultContextSet
                   -> ResultContextSet .
  eq metaENarrowRls#(M,B,ON,none,RT,RTS)
   = RTS .
  eq metaENarrowRls#(M,B,ON,RL RLS,RT,RTS)
   = metaENarrowRls#(M,B,ON,RLS,RT,
      RTS |
        filter-variant-RT(M,ON,RT,
           metaENarrowRls*(M,B,ON,RL,RT)
        )
     ) .

  --- General case
  op metaENarrowRls* : Module Bound TypeOfNarrowing
                       Rule ResultContext
                    -> ResultContextSet .
  eq metaENarrowRls*(M,B,ON,
        (rl Lhs => Rhs [Att].),
	{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags})
   = metaENarrowRls**$(M,B,ON,
        (rl Lhs => Rhs [Att].),
	{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,
           Tr:TraceNarrow {CtTS,none,leastSort(M,CtTS),(rl Lhs => Rhs [Att].)},
                          --- Subst none here is key to write the real stuff
                          --- later in function _<<_
           B:Flags},
        'rl_=>_`[_`].[Lhs,Rhs,'none.AttrSet] <<{none,NextVar}<) .
  eq metaENarrowRls*(M,B,ON, X:Rule, X:ResultContext)
   = empty [owise] .

  op metaENarrowRls**$ : Module Bound TypeOfNarrowing
                         Rule ResultContext
                         UnificationPair
                      -> ResultContextSet .
  eq metaENarrowRls**$(M,B,ON,
        (rl Lhs => Rhs [Att].),
	{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags},
        {Subst,NextVar'})
   = metaENarrowRls**$$(M,B,ON,
	{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags},
        {Subst,NextVar'},
        'rl_=>_`[_`].[Lhs,Rhs,'none.AttrSet] << Subst) .

  op metaENarrowRls**$$ : Module Bound TypeOfNarrowing
                          ResultContext
                          UnificationPair Term
                       -> ResultContextSet .
  eq metaENarrowRls**$$(M,B,ON,
	{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,
          Tr:TraceNarrow {CtTS,none,TP$:Type,(rl Lhs => Rhs [Att].)},
          B:Flags},
        {Subst,NextVar'},
        'rl_=>_`[_`].[Lhs',Rhs','none.AttrSet])
   = metaENarrowRls**$$$(M,B,ON,
	{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,
           Tr:TraceNarrow {CtTS,none,TP$:Type,(rl Lhs' => Rhs' [Att].)},
           B:Flags},
        {Subst,NextVar'},
        'rl_=>_`[_`].[Lhs',Rhs','none.AttrSet],
        auxMetaUnify(M,ON,TS,Lhs',NextVar')) .

  op metaENarrowRls**$$$ : Module Bound TypeOfNarrowing
                           ResultContext
                           UnificationPair Term UnificationTripleSet
                        -> ResultContextSet .
  eq metaENarrowRls**$$$(M,B,ON,
	{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags},
        {Subst,NextVar'},
        'rl_=>_`[_`].[Lhs',Rhs','none.AttrSet],US)
    = if US =/= empty
      then rebuildTypeAndDiscardErroneous(M,ON,
               {Ct[Rhs'],
	        TP,
		S,S',
		[],
		[],
		CtS[Rhs'],
		CtS[Rhs'],
		NextVar',
                Tr:TraceNarrow,
                B:Flags}
               <<(M,ON) US
            )
      else empty
      fi .

  *** rebuild the context of the applied rule **********************
  op rebuildTypeAndDiscardErroneous : Module TypeOfNarrowing
                                      ResultContextSet -> ResultContextSet .
  eq rebuildTypeAndDiscardErroneous(M,ON,empty)
   = empty .
  eq rebuildTypeAndDiscardErroneous(M,ON,RT | RTS)
   = rebuildTypeAndDiscardErroneous*(M,ON,RT)
     | rebuildTypeAndDiscardErroneous(M,ON,RTS) .

  op rebuildTypeAndDiscardErroneous* : Module TypeOfNarrowing
                                       ResultContext -> ResultContextSet .
  eq rebuildTypeAndDiscardErroneous*(M,ON,
       {T,TP,S,S',[],[],TS,TS,NextVar,Tr:TraceNarrow,B:Flags})
   = if	leastSort(M,TS) :: Type
     then normalize-terms?(M,ON,
             {canonice(M,T),leastSort(M,TS),
              canonice(M,S),canonice(M,S'),
              [],[],canonice(M,TS),canonice(M,TS),
              NextVar,
              canonice(M,Tr:TraceNarrow),B:Flags})
     else empty
     fi .

  *** auxiliary for variant narrowing **********************
  op _<<`(_`,_`)_ : ResultContext
                    Module TypeOfNarrowing
                    UnificationTripleSet -> ResultContextSet .

  eq RT <<(M,ON) (empty).UnificationTripleSet
   = (empty).ResultContextSet .

  eq {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags}
     <<(M,ON) ({Subst,Subst',N} | SS:UnificationTripleSet)
   = {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags}
     <<((M,ON)) {Subst,Subst',N}
     |
     {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags}
     <<(M,ON) SS:UnificationTripleSet .

  op _<<`(`(_`,_`)`)_ : ResultContext
                        Module TypeOfNarrowing
                        UnificationTriple -> ResultContextSet .

  eq {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags}
     <<((M,ON)) {Subst,Subst',N}
   = if (variant in ON
         and-then
         (Subst == none
          or-else
          (not anyIdSymbol(M,Subst ; Subst')
           and-then
           normalizedSubstitution?(M,Subst ; Subst'))
          or-else
          anyIdSymbol(M,Subst ; Subst')
         )
        )
        or-else
        (computed-normalized-subs in ON
         and-then normalizedSubstitution?(M,Subst))
        or-else
        (applied-normalized-subs in ON
         and-then normalizedSubstitution?(M,Subst'))
        or-else
        (not variant in ON
         and-then
         not applied-normalized-subs in ON
         and-then
         not computed-normalized-subs in ON)
     then {T,TP,S,S',Ct:Context,CtS:Context,TS:Term,CtTS:Term,NextVar,Tr:TraceNarrow,B:Flags}
           << if anyIdSymbol(M,Subst ; Subst')
              ---then {normalizeRls(M,Subst),normalizeRls(M,Subst'),N}
              then {canonice(M,Subst),canonice(M,Subst'),N}
              else {Subst,Subst',N}
              fi
     else (empty).ResultContextSet
     fi .

  *** test flag normalize-terms and normalize **********************
  *** !!!! This mustn't be combined with basic -> strange behavior
  op normalize-terms? : Module TypeOfNarrowing ResultContext
                     -> ResultContext .
  eq normalize-terms?(M,E-normalize-terms ON,
     {T,TP,S,S',[],[],TS,TS,NextVar,Tr:TraceNarrow,B:Flags})
   = {getTerm(metaReduce(M,T)),
      getType(metaReduce(M,T)),
      S,S',[],[],
      getTerm(metaReduce(M,TS)),
      getTerm(metaReduce(M,TS)),
      NextVar,Tr:TraceNarrow,B:Flags} .
  eq normalize-terms?(M,normalize-terms ON,
     {T,TP,S,S',[],[],TS,TS,NextVar,Tr:TraceNarrow,B:Flags})
   = {getTerm(metaNormalizeCollect(M,T)),
      getType(metaNormalizeCollect(M,T)),
      S,S',[],[],
      getTerm(metaNormalizeCollect(M,TS)),
      getTerm(metaNormalizeCollect(M,TS)),
      NextVar,Tr:TraceNarrow,B:Flags} .
  eq normalize-terms?(M,ON,RT)
   = RT [owise] .

  *** Call at inner subterms
  op metaENarrowSub : Module Bound TypeOfNarrowing ResultContext
                      -> ResultContextSet .
  eq metaENarrowSub(M,B,ON,{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags})
   = metaENarrowSub#(M,B,ON,flatten(M,auxSplitTerm(ON,T,TS)),
            {T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags}) .

  op auxSplitTerm : TypeOfNarrowing Term Term -> Term .
  eq auxSplitTerm(basic ON,T,TS) = T .
  eq auxSplitTerm(ON,T,TS) = TS [owise] .

  op metaENarrowSub# : Module Bound TypeOfNarrowing Term ResultContext
                      -> ResultContextSet .
  eq metaENarrowSub#(M,B,ON,C,RT) = empty .
  eq metaENarrowSub#(M,B,ON,V,RT) = empty .
  eq metaENarrowSub#(M,B,ON,F[NeTL],RT)
   = metaENarrowSub#Gen(M,B,ON,
       splitTerm(M,F,
                 1,getFrozen(M,F,getTypes(M,NeTL)),
                 isAssociative(M,F,getTypes(M,NeTL))
                 or isCommutative(M,F,getTypes(M,NeTL)),
                 empty,NeTL,RT)) .

  op splitTerm : Module Qid
                 Nat NeNatList Bool
                 TermList TermList
                 ResultContext -> ResultContextSet .

  eq splitTerm(M,F,
               N,NL,AC?:Bool,
               TL',empty,
               RT)
   = empty .

  eq splitTerm(M,F,
               N,NL,AC?:Bool,
               TL',(T,TL),
               {T'',TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags})
   = if ((not AC?:Bool) and-then N inNatList NL)
        or-else
        (AC?:Bool and-then NL =/= 0)
     then empty
     else {T,leastSort(M,T),S,S',
           Ct[F[TL',[],TL]],
           CtS[F[TL' << (S ; S'),[],TL << (S ; S')]],T << (S ; S'),
           CtTS,NextVar,Tr:TraceNarrow,B:Flags}
     fi
     | splitTerm(M,F,
                 s(N),NL,AC?:Bool,
                 (TL',T),TL,
                 {T'',TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags}) .

  op metaENarrowSub#Gen : Module Bound TypeOfNarrowing ResultContextSet
                       -> ResultContextSet .
  eq metaENarrowSub#Gen(M,B,ON,empty)
   = empty .
  eq metaENarrowSub#Gen(M,B,ON,RT | RTS)
   = metaENarrowGen**(M,B,ON,RT) | metaENarrowSub#Gen(M,B,ON,RTS) .

  op filter-variant-RT : Module TypeOfNarrowing ResultContext
                      ResultContextSet -> ResultContextSet .
  eq filter-variant-RT(M,ON,
          {T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags},RTS)
   = if variant in ON and testUnifier !in ON
     then filter-variant-RT*(M,Vars(TS),empty,RTS)
     else RTS
     fi .

  op filter-variant-RT* :
       Module TermList ResultContextSet ResultContextSet -> ResultContextSet .
  eq filter-variant-RT*(M,TL,RTS$,empty)
   = RTS$ .
  eq filter-variant-RT*(M,TL,RTS$,RT | RTS)
   = filter-variant-RT**(M,TL,RTS$,RTS,RT,RTS) .

  op filter-variant-RT** :
        Module TermList ResultContextSet ResultContextSet
                        ResultContext ResultContextSet -> ResultContextSet .
  eq filter-variant-RT**(M,TL,RTS$,RTS',RT,empty)
   = --- RT is not implied by any in RTS'
     filter-variant-RT*(M,TL,RTS$ | RT,RTS') .
  eq filter-variant-RT**(M,TL,RTS$,RT | RTS',RT',RT | RTS)
   = if test-variant-RT(M,TL,RT,RT')
     then --- RT' is implied by RT in RTS'
          filter-variant-RT*(M,TL,RTS$,RT | RTS')
     else if test-variant-RT(M,TL,RT',RT)
          then --- remove RT from the set RTS'
               filter-variant-RT**(M,TL,RTS$,RTS',RT',RTS)
          else --- continue searching in RTS
               filter-variant-RT**(M,TL,RTS$,RT | RTS',RT',RTS)
          fi
     fi .

  op test-variant-RT : Module TermList ResultContext ResultContext
                    -> Bool .
  eq test-variant-RT(M,TL,
         {T,TP,S,S*,Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags},
         {T',TP',S',S'*,Ct',CtS',TS',CtTS',NextVar',Tr':TraceNarrow,B':Flags})
   = test-variant-RT*(M,TL,S |> TL,S' |> TL) .

  op test-variant-RT* : Module TermList Substitution Substitution -> Bool .
  eq test-variant-RT*(M,TL,S,S')
   = | S | <= | S' |
     and-then
     S <=[TL,M] S' . --- keep T & remove T'

  op |_| : Substitution -> Nat .
  eq | (none).Substitution | = 0 .
  eq | V <- T ; S | = s(| S |) .

endfm

fmod META-NARROWING-SEARCH is
  protecting META-E-NARROWING .
  protecting META-TERM .
  protecting META-LEVEL-MNPA .
  protecting META-UNIFICATION .
  protecting RESULT-CONTEXT-SET .
  protecting ORDERS-TERM-SUBSTITUTION .

  var T T' TOrig Lhs Rhs TS TS' CtTS CtTS' : Term .
  var V : Variable .
  var C : Constant .
  var F : Qid .
  vars TL TL' : TermList .
  var M : Module .
  var RTS RTS' RTSSol : ResultContextSet .
  var RT RT' : ResultContext .
  vars TP TP' : Type .
  vars S S' Subst S* S'* : Substitution .
  var RLS : RuleSet .
  var Att : AttrSet .
  var B BN Sol : Bound .
  var N : Nat .
  var NL : NatList .
  vars Ct Ct' CtS CtS' : Context .
  var ON : TypeOfNarrowing .
  vars QQ QQ' : TypeOfRelation .
  vars NextVar NextVar' : Nat .

  var SCond : SubstitutionCond .

  --- metaNarrowSearch --------------------------------------------------------

  *** Shortcuts to Narrowing Search
  op metaNarrowSearch : Module Term Term SubstitutionCond
                        TypeOfRelation Bound Bound Bound
                        -> ResultTripleSet .
  eq metaNarrowSearch(M,T,T',SCond,QQ,BN,B,Sol)
   = if (BN == unbounded and-then Sol =/= unbounded)
        or-else
        (BN =/= unbounded and-then Sol =/= unbounded and-then BN < Sol)
     then metaNarrowSearch*(M,T,T',SCond,QQ,Sol,B,Sol)
     else metaNarrowSearch*(M,T,T',SCond,QQ,BN,B,Sol)
     fi .

  op metaNarrowSearch* : Module Term Term SubstitutionCond
                         TypeOfRelation Bound Bound Bound
                         -> ResultTripleSet .
  eq metaNarrowSearch*(M,T,T',SCond,QQ,BN,B,Sol)
   = metaNarrowSearchGen(M,T,T',SCond,QQ,BN,B,Sol,
         full E-BuiltIn-unify noStrategy E-normalize-terms) .

  *** Shortcuts to Paramodulation Search
  op metaParamodulationSearch : Module Term Term SubstitutionCond
                                TypeOfRelation Bound Bound Bound
                             -> ResultTripleSet .
  eq metaParamodulationSearch(M,T,T',SCond,QQ,BN,B,Sol)
   = if (BN == unbounded and-then Sol =/= unbounded)
        or-else
        (BN =/= unbounded and-then Sol =/= unbounded and-then BN < Sol)
     then metaParamodulationSearch*(M,T,T',SCond,QQ,Sol,B,Sol)
     else metaParamodulationSearch*(M,T,T',SCond,QQ,BN,B,Sol)
     fi .

  op metaParamodulationSearch* : Module Term Term SubstitutionCond
                         TypeOfRelation Bound Bound Bound
                         -> ResultTripleSet .
  eq metaParamodulationSearch*(M,T,T',SCond,QQ,BN,B,Sol)
   = metaNarrowSearchGen(M,T,T',SCond,QQ,BN,B,Sol,
         full E-BuiltIn-unify noStrategy E-normalize-terms alsoAtVarPosition) .

  *** General Call
  op metaNarrowSearchGen : Module Term Term SubstitutionCond
                           TypeOfRelation
                           Bound --- number of steps
                           Bound --- number of solutions
                           Bound --- chosen solution
                           TypeOfNarrowing
			-> ResultTripleSet .
  eq metaNarrowSearchGen(M,T,T',SCond,QQ,B,BN,Sol,ON)
   = toTriple(M,metaNarrowSearchGenAll(M,T,T',SCond,QQ,B,BN,Sol,ON)) .

  *** Shortcuts to Narrowing Search Path
  op metaNarrowSearchPath : Module Term Term SubstitutionCond
                            TypeOfRelation Bound Bound Bound
                         -> TraceNarrowSet .
  eq metaNarrowSearchPath(M,T,T',SCond,QQ,B,BN,Sol)
   = if (BN == unbounded and-then Sol =/= unbounded)
        or-else
        (BN =/= unbounded and-then Sol =/= unbounded and-then BN < Sol)
     then metaNarrowSearchPath*(M,T,T',SCond,QQ,Sol,B,Sol)
     else metaNarrowSearchPath*(M,T,T',SCond,QQ,BN,B,Sol)
     fi .

  op metaNarrowSearchPath* : Module Term Term SubstitutionCond
                             TypeOfRelation Bound Bound Bound
                          -> TraceNarrowSet .
  eq metaNarrowSearchPath*(M,T,T',SCond,QQ,BN,B,Sol)
   = extractTraces(
       metaNarrowSearchGenAll(M,T,T',SCond,QQ,B,BN,Sol,
         full E-BuiltIn-unify noStrategy E-normalize-terms)) .

  op extractTraces : ResultContextSet -> TraceNarrowSet .
  eq extractTraces(empty) = empty .
  eq extractTraces({T,TP,S,S*,Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags} | RTS)
   = if Tr:TraceNarrow == nil then empty else Tr:TraceNarrow fi
     | extractTraces(RTS) .

  *** Starting Call
  op metaNarrowSearchGenAll : Module Term Term SubstitutionCond
                              TypeOfRelation Bound Bound Bound TypeOfNarrowing
                           -> ResultContextSet .
  eq metaNarrowSearchGenAll(M,T,T',SCond,QQ,B,BN,Sol,ON)
   = metaNarrowSearchGenAll(M,T,T',SCond,QQ,B,BN,Sol,ON,highestVar((T,T')) + 1) .

  op metaNarrowSearchGenAll : Module Term Term SubstitutionCond
                            TypeOfRelation Bound Bound Bound TypeOfNarrowing Nat
                         -> ResultContextSet .
  eq metaNarrowSearchGenAll(M,T,T',SCond,QQ,B,BN,Sol,ON,N)
   = metaNarrowSearchAll(addSorts('Universal,M),
            T,T',SCond,QQ,B,BN,Sol,ON,
            {T,leastSort(M,T),none,none,[],[],T,T,N,nil,empty}) .

  *** One Narrowing step in the search process (including possible filters)
  op metaNarrowStep : Module SubstitutionCond
                      ResultContextSet TypeOfNarrowing
		   -> ResultContextSet .
  eq metaNarrowStep(M,SCond,RTS,ON)
   = filterSCond(M,SCond,metaENarrowGen(M,1,ON,RTS)) .

  *** Filter and normal forms
  op filterSCond : Module SubstitutionCond ResultContextSet
                   -> ResultContextSet .
  eq filterSCond(M,none,RTS)
   = RTS .
  eq filterSCond(M,SCond,RTS)
   = filterSCond*(M,SCond,RTS) [owise] .

  op filterSCond* : Module SubstitutionCond ResultContextSet
                   -> ResultContextSet .
  eq filterSCond*(M,SCond,empty)
   = empty .
  eq filterSCond*(M,SCond,RT | RTS)
   = filterSCond**(M,SCond,RT) | filterSCond*(M,SCond,RTS) .

  op filterSCond** : Module SubstitutionCond ResultContext
                   -> ResultContextSet .
  eq filterSCond**(M,SCond,{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags})
   = if SCond <=[M] S
     then {T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags}
     else empty
     fi .

  *** Generate next successors in a breadth way
  --- We reuse the metaNarrowSearchAll function
  op metaNarrowSearchAll : Module Term Term SubstitutionCond TypeOfRelation
                            Bound --- number steps
                            Bound --- number solutions
                            Bound --- chosen solution
                            TypeOfNarrowing
                            ResultContextSet
			 -> ResultContextSet .
  eq metaNarrowSearchAll(M,TOrig,T',SCond,QQ,B,BN,Sol,ON,RTS)
   = if QQ == '+
     then noSelf(RTS,
          metaNarrowSearchCheck(M,TOrig,T',SCond,'*,B,BN,Sol,ON,empty,RTS,empty)
          )
     else metaNarrowSearchCheck(M,TOrig,T',SCond,QQ,B,BN,Sol,ON,empty,RTS,RTS)
     fi .

  *** Take only normal forms
  op isNF : Module ResultContext -> Bool .
  eq isNF(M,{T,TP,S,S',Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags})
   = end(B:Flags) or-else metaOneRewriting(M,CtTS) == empty .

  *** Take only normal forms
  op isVariant : Module Nat ResultContextSet ResultContext -> Bool .
  eq isVariant(M,N,
        {T',TP',S',S'*,Ct',CtS',TS',CtTS',NextVar',Tr':TraceNarrow,B':Flags} | RTS,
        {T,TP,S,S*,Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags})
    = not (
       (S' |> N ; (newVar(N + 1,TP') <- CtTS'))
           <=[M]
       (S |> N ; (newVar(N + 1,TP) <- CtTS))
      )
      and-then
      isVariant(M,N,RTS,{T,TP,S,S*,Ct,CtS,TS,CtTS,NextVar,Tr:TraceNarrow,B:Flags}) .
  eq isVariant(M,N,RTS,RT)
   = true [owise] .


  *** Generate successors
  op oneMoreStep : Module SubstitutionCond TypeOfNarrowing
                   ResultContextSet -> ResultContextSet [memo] .
  eq oneMoreStep(M,SCond,ON,RTS)
   = remove metaNarrowStep(M,SCond,removeEND(RTS),ON) From RTS .

  *** Check each next successor for conditions
  op metaNarrowSearchCheck : Module Term Term SubstitutionCond
                             TypeOfRelation Bound Bound Bound TypeOfNarrowing
                             ResultContextSet ResultContextSet ResultContextSet
			     -> ResultContextSet .

  eq metaNarrowSearchCheck(M,TOrig,T',SCond,QQ,B,BN,Sol,ON,RTSSol,RTS',empty)
   = if B == 0 or-else BN == 0 or-else Sol == 0 or-else RTS' == empty
     then *** Stop the search
          RTSSol
     else *** Compute Next successors of RTS' with oneMoreStep
          metaNarrowSearchCheck(M,
            TOrig,T',SCond,
            QQ,
            dec(B),BN,Sol,
            ON,
            RTSSol,
            oneMoreStep(M,SCond,ON,RTS'),
            oneMoreStep(M,SCond,ON,RTS')
          )
     fi .

  eq metaNarrowSearchCheck(M,TOrig,T',SCond,QQ,B,BN,Sol,ON,RTSSol,RTS',
         RT | RTS)
   = if isSolution?(M,TOrig,T',QQ,BN,Sol,ON,RTSSol,RT)
        and-then
        auxMetaUnifyCheck(M,ON,getCTTerm(RT),T',getNextVar(RT)) =/= empty *** Is actual term an instance of T'?
     then *** This is a solution
          metaNarrowSearchCheck(M,TOrig,T',SCond,QQ,
                  B,dec(BN),dec(Sol),
                  ON,
                  if Sol == unbounded or-else Sol == 1
                  then rebuildTypeAndDiscardErroneousCheck(M,ON,
                          RT <<(M,ON) auxMetaUnifyCheck(M,ON,getCTTerm(RT),T',getNextVar(RT)))
                  else empty
                  fi
                  | RTSSol,
                  RTS',RTS)
     else *** Continue with the remaining
	  metaNarrowSearchCheck(M,TOrig,T',SCond,QQ,
             B,BN,Sol,ON,RTSSol,RTS',RTS)
     fi .

  op auxMetaUnifyCheck : Module TypeOfNarrowing Term Term Nat ~> UnificationTripleSet .
  eq auxMetaUnifyCheck(M,ON,T,T',N) = auxMetaUnify(M,ON,T,T',N) .

  op rebuildTypeAndDiscardErroneousCheck : Module TypeOfNarrowing ResultContextSet -> ResultContextSet .
  eq rebuildTypeAndDiscardErroneousCheck(M,ON,RTS) = rebuildTypeAndDiscardErroneous(M,ON,RTS) .

  op isSolution? : Module Term Term
                   TypeOfRelation Bound Bound TypeOfNarrowing
                   ResultContextSet ResultContext
	        -> Bool .
  eq isSolution?(M,TOrig,T',QQ,BN,Sol,ON,RTSSol,RT)
   = *** Is this the chosen solution?
     (BN == unbounded or-else BN > 0)
     and-then
     *** Is this step correct wrt relations <'!,'*,'+> ?
     ( QQ == '* or-else (QQ == '! and-then isEND(RT)) )
     and-then
     *** Is this a valid variant solution?
     (not (variant in ON) or-else
      (isNF(M,RT) and-then isVariant(M,highestVar(TOrig) + 1,RTSSol,RT))) .

  op upDown : Module ResultTripleSet -> ResultTripleSet .
  eq upDown(M,RTS:ResultTripleSet)
   = upDown#(M,empty,RTS:ResultTripleSet) .
  op upDown# : Module ResultTripleSet ResultTripleSet -> ResultTripleSet .
  eq upDown#(M,RTS':ResultTripleSet, empty)
   = RTS':ResultTripleSet .
  eq upDown#(M,RTS':ResultTripleSet, {T,TP,S} | RTS:ResultTripleSet)
   = upDown#(M,{getTerm(metaReduce(M,T)),TP,upDown(M,S)}
               | RTS':ResultTripleSet,RTS:ResultTripleSet) .

  op upDown : Module Substitution -> Substitution .
  eq upDown(M,S:Substitution)
   = upDown#(M,none,S:Substitution) .
  op upDown# : Module Substitution Substitution -> Substitution .
  eq upDown#(M,S':Substitution,none)
   = S':Substitution .
  eq upDown#(M,S':Substitution,V <- T ; S:Substitution)
   = upDown#(M,S':Substitution ; V <- getTerm(metaReduce(M,T)),S:Substitution) .

endfm
```
