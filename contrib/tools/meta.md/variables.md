```maude
load ../base/full-maude.maude
```

Variable Handling
=================

Determiistic Variables
----------------------

Often times, fresh variables aren't needed if you can deterministically compute
a correct "new variable" given an existing list of terms. This module does that.

TODO:
:   Perhaps we could provide a "minimized" fresh generator which hashes the
    string used for the variable name instead?

```maude
fmod DETERMINISTIC-VARIABLES is
   protecting META-TERM .

    var Q : Qid . var STR : String . var S : Sort .
    var T : Term . vars NeTL NeTL' : NeTermList . var TL : TermList .

    op #string : TermList -> String .
    ---------------------------------
    eq #string(Q)              = string(Q) .
    eq #string(Q[TL])          = #string(Q) + "[" + #string(TL) + "]" .
    eq #string((NeTL , NeTL')) = #string(NeTL) + "," + #string(NeTL') .

    op #qid : TermList -> Qid .
    ---------------------------
    eq #qid(TL) = qid(#string(TL)) .

    op #makeVariable : Qid    Sort -> [Variable] .
    op #makeVariable : String Sort -> [Variable] .
    ----------------------------------------------
    eq #makeVariable(Q, S)   = qid("#makeVariable(" + string(Q) + "):" + string(S)) .
    eq #makeVariable(STR, S) = qid("#makeVariable(" + STR + "):" + string(S)) .

    op #var : TermList Sort -> [Variable] .
    ---------------------------------------
    eq #var(TL, S) = #makeVariable(#string(TL), S) .
endfm
```

Metavariable Renaming/Fresh
---------------------------

This file implements a universal metavariable renaming routine for Maude that
will rename some metavariables so that they are fresh with respect to other
metavariables. Dependency on full-maude is very weak; just one function addEqs
is borrowed which could very easily be incorporated into this source.

TODO:
:   Rework renameTmpVar and renameAllVar so that they don't need work by
    evaluating at the metalevel in particular, this entails getting rid of the
    rewrite-rule based presentation that is used now for renameTmpVar. Since
    Maude tools essentially cannot analyze production Maude code, we won't worry
    about using hard-to-analyze features. Primary focus should be making the
    code short, sweet, and usable in larger projects. Secondary focus should be
    given to avoiding namespace pollution, extending prelude sorts with junk,
    etc...

### Glossary

variable:
:   a Maude object or meta\*level variable (depending on context)

object variable:
:   a Maude object level variable with a particular sort, ex: N:Nat

metavariable:
:   a Maude meta-level variable with sort Variable, ex: 'N:Nat

meta\*variable:
:   a Maude meta-level variable that has been upTerm'ed zero or more times

variable name:
:   the part of a variable which has no semantic information, ex: Bob

user data:
:   any data inputted by the user that may contain meta\*variables

user variable:
:   a meta\*variable inputted by the user; not guaranteed to be standard

temporary:
:   a meta*variable whose name matches .*(#/%)(0/(1[0-9]*))

standard:
:   a meta*variable whose name matches .*@(0/(1[0-9]*))

standard data:
:   any data which is guaranteed to contain only standard variables

indexed data:
:   any data which is guaranteed to contain only temporary/standard variables

standardize:
:   to rename a variable such that it becomes standard

variable index:
:   final number occuring in the name of a temporary or standard meta\*variable

term/termlist:
:   anything which belongs to the sort Term/Context or GTermList in META-TERM

highestVar:
:   a function which returns the highest temporary/standard meta\*variable
    indices

base data:
:   this data contains meta\*variables which will not be renamed

base index:
:   the maximum standard meta\*variable index occuring in the term
    representation of the base data

fresh data:
:   this data contains meta\*variables which will be renamed

fresh w.r.t.:
:   a standard meta\*variable is fresh with respect to a index/base data when
    its index is greater than the index/base index

renameAllVar:
:   a function which standardizes all meta\*variables in fresh data so that they
    are fresh with respect to the base index

renameTmpVar:
:   a function which standardizes only temporary meta\*variables in fresh data
    so that they are fresh with respect to the base index

### Overview

Generally, a caller of this library will only need to import the RENAME-METAVARS
module. This module only defines a small number of function names so as to avoid
polluting the global namespace.

To make proper use of this library, the calling code must observe certain
conventions. Otherwise, the freshness of generated variables cannot be
guaranteed. There is one general assumption made by the whole library:

a.  GTermList MUST NOT have constructors added beyond what is in META-TERM

The renameTmpVar function has an addtional requirement:

b.  the base data MUST NOT contain temporary meta\*variables

NOTE: since these functions understand meta\*variables, the type of data is
irrelevant; a simple call to upTerm() will enable the data to be input into the
function.

The two functions renameAllVar and renameTmpVar work in concert. If dealing with
user data, use renameAllVar to first standardize all user variables. If there
are pieces of user data which must be fresh with respect to each other, use
multiple calls to renameAllVar and pass the base index between each call.

If it is necessary to generate fresh variables for the application of some
sub-algorithm, but the caller doesn't wish to keep track of many indices, then
s/he may do the following:

1.  Ensure the data which the sub-algorithm will operate on does not contain
    temporary variables (as might be the case with user data). If needed, call
    renameAllVar.

2.  The sub-algorithm will maintain a counter; each time a fresh variable is
    required, generate a temporary variable with tmpvar() and your desired
    index. It is irrelevant how many times the temporary variable occurs.

3.  When the sub-algorithm is finished, call renameTmpVar on the relevant data,
    being sure to pass in an appropriate base index so the generated variables
    are really fresh.

Axes of the Design Space In order to understand why this project was designed
the way that it was, it is helpful to explore different points all the design
space and compare and contrast different implementation choices. We list three
axes below:

1.  In which contexts can we rename variables? Most implementations can only
    rename metavariables in a particular datastructure by explicitly recursing
    over it --- our implementation sidesteps this issue because it understands
    how to rename meta*variables; we can rename variables in *any* datastructure
    by first upTerm'ing it, recursing over its metarepresentation, and renaming
    any meta*variables we find.

2.  What data is required to rename variables? Some implementations explictly
    require the user to carry a counter around which signifies the next fresh
    variable name --- our method can automatically compute such counters when
    necessary or the user can explicitly provide them.

3.  Which variables can we rename? Some implementations will rename all
    variables on every pass (if necessary). This has the advantage that the user
    never has to worry about some variables that should be renamed are not.
    However, this approach requires the renaming algorithm to maintain a table
    of variable names and which names they were mapped to --- and incurs a table
    lookup cost each time we access the table. We support this approach, but we
    also support an alternative approach which only renames temporary variables
    which does not need a table lookup.

    NOTE: after running some basic tests on the code base with Maude 2.7.1, it
    appears our alternative approach wins on performance when 3 or more
    variables are going to be renamed.

4.  How are variables renamed? Some implementations replace all variable names
    with numbers in increasing order. Theoretically, this works, but the user
    experience is not very enjoyable. In this implementation, two strategies are
    explored. renameAllVar() appends a unique fresh index to each variable in
    term traversal order. renameTmpVar() precomputes a proper base index and
    renames each temporary variable in place--- only temporary variables are
    renamed.

In practice, fresh metavariables are usually automatically generated according
to a scheme similar to the one we adopt here. For example, fresh metavariables
generated during Maude's unification and built-in variant computation are all
temporary. Thus, this code can be used for renaming the generated variables from
Maude built-in functions.

NOTE: using "cat metafresh.maude | egrep -v
`"^[ ]*---" | egrep -v "^[ ]*$" | wc -l` to count code lines (excl.
comments/blanks) last gave slightly < 250

```maude
fmod RENAME-DATA is
  pr META-LEVEL .
  sort RenameData TermData VarData .
  op ((_,_,_)) : Substitution GTermList FindResult -> RenameData [ctor] .
  op vardata   : Term FindResult FindResult        -> VarData    [ctor] .
  op termdata  : GTermList FindResult              -> TermData   [ctor] .
  op termerr   :                                   ~> TermData   [ctor] .
  op renameerr :                                   ~> RenameData [ctor] .
endfm

fmod STRNAT-DATA is
  pr NAT .
  pr STRING .
  sort StringNatPair StringNatTriple .
  op ((_,_))   : String Nat        -> StringNatPair   .
  op ((_,_,_)) : String String Nat -> StringNatTriple .
endfm

fmod NATQID-PAIR is
  pr NAT .
  pr QID .
  sort NatQidPair .
  op ((_,_)) : Nat Qid -> NatQidPair .
endfm

fmod FINDRESULT-EXTRA is
  pr STRING .
  op maxF : FindResult FindResult -> FindResult .
  var I J : Nat .
  eq maxF(notFound,I)        = I .
  eq maxF(I,notFound)        = I .
  eq maxF(notFound,notFound) = notFound .
  eq maxF(I,J)               = max(I,J) .
endfm

--- Calls upTerm() N times
fmod UPQID is
  pr META-LEVEL .
  op up : Nat Qid -> Qid .
  eq up(s(N:Nat),Q:Qid) = up(N:Nat,upTerm(Q:Qid)) .
  eq up(0,Q:Qid)        = Q:Qid .
endfm

--- Given a Module or SortSet, gets complete TypeSet
fmod GET-TYPES is
  pr META-LEVEL .
  op get-types : Module -> TypeSet [memo] .
  op get-types : Module SortSet -> TypeSet .
  op get-types : Module SortSet KindSet -> TypeSet .
  var M : Module . var S : Sort . var SS : SortSet . var KS : KindSet .
  eq get-types(M)           = getSorts(M) ; get-types(M,getSorts(M),none) .
  eq get-types(M,SS)        = SS ; get-types(M,SS,none) .
  eq get-types(M,S ; SS,KS) = get-types(M,SS,completeName(M,getKind(M,S)) ; KS) .
  eq get-types(M,none,KS)   = KS .
endfm

--- Coerces nth-level meta-variables into variables
fmod PARSE-METAVARS is
  pr META-LEVEL .
  pr STRING .
  pr STRING-PAIR .
  pr STRNAT-DATA .
  pr NATQID-PAIR .
  op  parse-metavar  : Variable TypeSet           -> Variable .
  op  parse-metavar  : Constant TypeSet           ~> Variable .
  op  parse-metavar  : NatQidPair                 ~> Variable .
  op #parse-metavar  : Variable TypeSet           -> NatQidPair .
  op #parse-metavar  : Constant TypeSet           ~> NatQidPair .
  op #parse-metavar  : StringNatPair TypeSet      ~> NatQidPair .
  op #parse-metavar1 : Nat StringNatPair TypeSet  ~> NatQidPair .
  op #parse-metavar1 : Nat Nat StringPair TypeSet ~> NatQidPair .
  op $check-type     : Nat Variable Type TypeSet  ~> NatQidPair .
  op  stripQuotes    : String Nat                 -> StringNatPair .

  var R N : Nat . var V : Variable . var S : String . var TY : Type . var T : TypeSet .

  --- INP: Variable/Constant
  --- PRE: None
  --- OUT: If Variable/Constant represents a conforming meta*variable,
  ---      parse it and return the pair (N,V) where N is the number
  ---      of upTerm's applied and V is the corresponding metavariable
  ---      There is a convenience wrapper which just returns the variable name.
  eq  parse-metavar (Q:TermQid,T)          =  parse-metavar(#parse-metavar(Q:TermQid,T)) .
  eq  parse-metavar ((N,V))                =  V .
  eq #parse-metavar (V,T)                  = $check-type(0,V,getType(V),T) .
  eq #parse-metavar (C:Constant,T)         = #parse-metavar (stripQuotes(string(C:Constant),0),T) .
  eq #parse-metavar ((S,R),T)              = #parse-metavar1(R,(S,R),T) .
  eq #parse-metavar1(R,(S,s(N)),T)         = #parse-metavar1(R,N,rsplit(S,"."),T) .
  eq #parse-metavar1(R,N,(S,"Constant"),T) = #parse-metavar1(R,(S,N),T) .
  eq #parse-metavar1(R,0,(S,"Variable"),T) = $check-type(R,qid(S),getType(qid(S)),T) .
  eq $check-type(R,V,TY,TY ; T)            =  (R,V) .
  ---
  eq  stripQuotes(S,N) = if substr(S,0,1) == "'" then stripQuotes(substr(S,1,length(S)),s(N)) else (S,N) fi .
endfm

--- Given a conforming meta*variable, parse its index
fmod PARSE-VARINDEX is
  pr META-LEVEL .
  pr STRING .
  pr CONVERSION .
  pr STRNAT-DATA .

  sort CharList .
  op _:_ : Char CharList -> CharList [ctor] .
  op nil : -> CharList [ctor] .
  ---
  op  get-idx  : CharList Variable                     ~> Nat .
  op  get-idx  : StringNatTriple                       ~> Nat .
  op #get-idx  : CharList Variable                     ~> StringNatTriple .
  op #get-idx  : CharList String                       ~> StringNatTriple .
  op #get-idx1 : CharList Nat String String            ~> StringNatTriple .
  op #get-idx1 : CharList Nat String String FindResult ~> StringNatTriple .
  var C C' : Char   . var CL  : CharList . var N : String .
  var S    : String . var P L : Nat .

  --- INP: CharList Var:Variable
  --- PRE:
  --- OUT: Returns the variable index for any conforming variable
  eq #get-idx (CL,V:Variable)              = #get-idx (CL,string(V:Variable))  .
  eq #get-idx (CL,S)                       = #get-idx1(CL,length(S),S,substr(S,0,rfind(S,":",length(S)))) .
  eq #get-idx1(C : CL,L,N,S)               = #get-idx1(C : CL,L,N,S,rfind(S,C,L)) .
  eq #get-idx1(C : CL,L,N,S,P)             = (substr(N,0,P),C,rat(substr(S,s(P),L),10)) .
  eq #get-idx1(C : C' : CL,L,N,S,notFound) = #get-idx1(C' : CL,L,N,S,rfind(S,C',L)) .
  eq  get-idx (CL,V:Variable)              = get-idx(#get-idx(CL,V:Variable)) .
  eq  get-idx ((N,S,P))                    = P .
endfm

--- Generate appropriate conforming variable names
fmod GEN-VARNAMES is
  pr META-LEVEL .
  pr CONVERSION .
  op  tmpvar : Nat Variable           -> Variable .
  op  tmpvar : Nat Type               -> Variable .
  op  tmpvar : String Nat Type        -> Variable .
  op  tmpvar : Nat Module Term        -> Variable .
  op  tmpvar : String Nat Module Term -> Variable .
  op  stdvar : Variable Nat           -> Variable .
  op  stdvar : String Nat             -> Variable .
  op $stdvar : Char String Nat        -> Variable .

  var S : Type . var I : Nat    . var N : String .
  var K : Char . var M : Module . var V : Variable .

  --- INP: [String] Nat Type/Term
  --- PRE: None
  --- OUT: A tmpvar with prefix String, index Nat, and type
  ---      either Type or the least sort of Term
  eq  tmpvar(I,V)          = tmpvar(string(getName(V)),I,getType(V)) .
  eq  tmpvar(I,S)          = tmpvar("",I,S) .
  eq  tmpvar(N,I,S)        = qid(N + "#" + string(I,10) + ":" + string(S)) .
  eq  tmpvar(I,M,T:Term)   = tmpvar("",I,leastSort(M,T:Term)) .
  eq  tmpvar(N,I,M,T:Term) = tmpvar(N,I,leastSort(M,T:Term)) .

  --- INP: String Nat
  --- PRE: String should be string(V) where V is a metavariable
  --- OUT: A stdvar deterministically chosen based on S and I
  eq  stdvar(V,I)     =  stdvar(string(V),I) .
  eq  stdvar(N,I)     = $stdvar(substr(N,0,1),N,I) .
  eq $stdvar("#",N,I) =  qid("@" + string(I,10) + substr(N,rfind(N,":",length(N)),length(N))) .
  eq $stdvar("%",N,I) =  qid("@" + string(I,10) + substr(N,rfind(N,":",length(N)),length(N))) .
  eq $stdvar("@",N,I) =  qid("@" + string(I,10) + substr(N,rfind(N,":",length(N)),length(N))) .
  eq $stdvar( K ,N,I) =  qid( K  + "@" + string(I,10) + substr(N,rfind(N,":",length(N)),length(N))) [owise] .
endfm

--- Given a meta*term, grab all of its meta*variables (represented as metavariables)
fmod GV-IMPL is
  pr META-LEVEL .
  pr PARSE-METAVARS .

  op getVar       : GTermList TypeSet                   -> QidSet .
  op {_}{_}{_}    : GTermList TypeSet QidSet            -> QidSet .
  op [_]{_}{_}{_} : [Variable] GTermList TypeSet QidSet -> QidSet .

  var K : [Qid] . var C : Constant . var L : GTermList . var NL : NeTermList  . var T : TypeSet .
  var Q : Qid   . var S : QidSet   . var V : Variable  . var XL : NeCTermList .

  --- [0-4] push qids up term tree and intiate parsing
  --- [5-6] collect and filter parse results
  eq [S] : getVar(L,T)     = {L}{T}{none} .
  eq [0] : {Q,L}{T}{S}     = if Q :: TermQid then [parse-metavar(Q,T)]{L}{T}{S} else {L}{T}{S} fi .
  eq [1] : {[],L}{T}{S}    = {L}{T}{S} .
  eq [2] : {Q[NL],L}{T}{S} = {NL,L}{T}{S} .
  eq [3] : {Q[XL],L}{T}{S} = {XL,L}{T}{S} .
  eq [4] : {empty}{T}{S}   =  S .
  eq [5] : [V]{L}{T}{S}    = {L}{T}{V ; S} .
  eq [6] : [K]{L}{T}{S}    = {L}{T}{S} [owise] .
endfm

--- NOTE: these three modules below implement the functionality
---       needed for renaming temporary variable indices;
---       originally 1 & 2 were a single module, but it seems
---       that Maude special cases equational reduction, so we
---       separated out the single rewrite rule
mod RTV-IMPL1 is pr META-LEVEL .
  sort VarData .
  op vardata : GTermList FindResult FindResult -> VarData  [ctor] .
  op check   : TermQid                         -> TermList [ctor frozen] .
  --- prepares each constant/variable for processing
  rl X:TermQid => check(X:TermQid) .
endm

fmod RTV-IMPL2 is
  pr META-LEVEL .
  pr PARSE-METAVARS .
  pr PARSE-VARINDEX .
  sort VarData .
  --- parameter which is instantiated at module creation time
  op types   :                                      -> TypeSet .
  --- constructors
  op vardata : GTermList FindResult FindResult      -> VarData  [ctor] .
  op gather  : Bool Nat                             -> Term     [ctor] .
  op shift   : Nat String Nat Type                  -> Term     [ctor] .
  --- defined operators
  op check   : TermQid                              -> TermList .
  op check   : TermQid NatQidPair                   -> TermList .
  op check   : TermQid Nat Variable StringNatTriple -> TermList .
  op $max    : Nat FindResult                       -> Nat      .

  var Q   : Qid . var X : TermQid . var T T' : GTermList . var B   : Bool       .
  var I J : Nat . var N : String  . var V    : Variable  . var F G : FindResult .
  var W : [NatQidPair] . var Y : [StringNatTriple] .

  --- [A]   gathers indices at toplevel of termlist
  --- [B-C] computes max std/tmp indices
  eq [A] : Q[T,gather(B,I),T']                 = Q[T,T'],gather(B,I) .
  eq [B] : vardata((T,gather(true,I),T'), F,G) = vardata((T,T'),F,$max(I,G)) .
  eq [C] : vardata((T,gather(false,I),T'),F,G) = vardata((T,T'),$max(I,F),G) .
  --- [0-1] parses meta*vars and ignores constants
  --- [3-5] parses indices, prepares vars for renaming, and passes up indices
  --- [2,6] ignores constants,nonconforming vars
  --- [7-8] max function extened to FindResult
  eq [0] : check(X)               = check(X,#parse-metavar(X,types)) .
  eq [1] : check(X,(I,V))         = check(X,I,V,#get-idx("@" : "#" : "%" : nil,V)) .
  eq [2] : check(X,W)             = X [owise] .
  eq [3] : check(X,I,V,(N,"@",J)) = X,                       gather(true, J) .
  eq [4] : check(X,I,V,(N,"#",J)) = shift(I,N,J,getType(V)), gather(false,J) .
  eq [5] : check(X,I,V,(N,"%",J)) = shift(I,N,J,getType(V)), gather(false,J) .
  eq [6] : check(X,I,V,Y)         = X [owise] .
  eq [7] : $max(I,J)              = max(I,J) .
  eq [8] : $max(I,notFound)       = I .
endfm

fmod RTV-IMPL3 is
  pr META-LEVEL .
  pr GEN-VARNAMES .
  pr UPQID .
  op base  :                     -> Nat  . --- constant for shift
  op shift : Nat String Nat Type -> Term .
  var X : TermQid . var I J : Nat . var N : String . var S : Type .
  eq shift(I,N,J,S) = up(I,qid(N + "@" + string(J + base,10) + ":" + string(S))) .
endfm

--- Renames all meta*vars in a termlist to be fresh w.r.t. a base index
fmod RAV-IMPL is
  pr META-TERM .
  pr PARSE-METAVARS .
  pr PARSE-VARINDEX .
  pr FINDRESULT-EXTRA .
  pr UPQID .
  pr RENAME-DATA .

  --- parameter which is instantiated at module creation time
  op types : -> TypeSet .
  --- Refining META-TERM sorts for easier traversal
  sort GTerm . subsort Context Term < GTerm < GTermList .
  --- Main API
  op renameAllVar   : FindResult GTermList -> TermData .
  op #renameAllVar  : FindResult GTermList -> RenameData .
  op #renameAllVar  : FindResult Substitution GTermList -> [RenameData] .
  op #renameAllVar! : FindResult Substitution GTermList -> [RenameData] .
  --- Renaming Termlists, Terms, and Variables
  op rvL : FindResult Substitution GTermList GTermList          -> RenameData .
  op rvL : RenameData GTermList GTermList                       -> RenameData .
  op rvT : FindResult Substitution GTerm                        -> RenameData .
  op rvT : Qid RenameData                                       -> RenameData .
  op rvT : FindResult Substitution TermQid NatQidPair           -> RenameData .
  op rvV : FindResult Substitution Nat Variable                 -> RenameData .
  op rvV : FindResult Substitution Nat Variable StringNatTriple -> RenameData .
  op rvV : FindResult Substitution Nat Variable Variable        -> RenameData .
  --- Miscellaneous function symbols
  op maxIdx : Substitution QidSet FindResult                 -> [FindResult] .
  op maxIdx : Substitution QidSet StringNatTriple FindResult -> [FindResult] .
  op addIdx : Nat Variable                                   -> Variable .
  op chgIdx : Nat Variable String                            -> Variable .
  op n      : FindResult                                     -> Nat      .
  op p      : RenameData                                     -> TermData .

  var I J : Nat  . var V V' : Variable   . var TL : TermList    . var C : Constant     . var T : GTerm  . var QS : QidSet .
  var Q   : Qid  . var L L' : GTermList  . var CL : NeCTermList . var S : Substitution . var N : String .
  var R   : Char . var M M' : FindResult . var X  : TermQid     . var W : [NatQidPair] . var K : [StringNatTriple] .

  --- [L0-L2] traverse termlist, call rvT to rename each term, pass up result
  --- [T0-T2] recurse on subterms with rvL
  --- [T3-T5] parse meta*variables, constants
  --- [V0-V1] parse variable indices
  --- [V2-V3] generate new variable name
  --- [V4]    return renamed variable
  --- [M0]    project TermData out of RenameData
  --- [M1-M2] perform real work for V2-V3
  --- [M3-M4] a successor function for NAT extended with notFound
  --- [M5-M7] given substitution, ensure is var-indexed renaming and extract max index
  eq [S0] : renameAllVar(M,L)      = p(#renameAllVar(M,L)) .
  eq [S1] : #renameAllVar(M,L)     = rvL(M,none,L,empty) .
  eq [S2] : #renameAllVar(M,S,L)   = rvL(M,S,L,empty) .
 ceq [S3] : #renameAllVar!(M,S,L)  = rvL(M',S,L,empty) if M' := maxIdx(S,none,M) .
  eq [L0] : rvL(M,S,(T,L),L')      = rvL(rvT(M,S,T),L,L') .
  eq [L1] : rvL(M,S,empty,L')      = (S,L',M) .
  eq [L2] : rvL((S,T,M),L,L')      = rvL(M,S,L,(L',T)) .
  eq [T0] : rvT(M,S,Q[CL])         = rvT(Q,rvL(M,S,CL,empty)) .
  eq [T1] : rvT(M,S,Q[TL])         = rvT(Q,rvL(M,S,TL,empty)) .
  eq [T2] : rvT(Q,(S,L,M))         = (S,Q[L],M) .
  eq [T3] : rvT(M,S,X)             = rvT(M,S,X,#parse-metavar(X,types)) .
  eq [T4] : rvT(M,S,X,(I,V))       = rvV(M,S,I,V) .
  eq [T5] : rvT(M,S,X,W)           = (S,X,M) [owise] .
  eq [V0] : rvV(M,V <- V' ; S,I,V) = (V <- V' ; S,up(I,V'),maxF(M,get-idx("@" : nil,V'))) .   --- substitution already contains binding for V
  eq [V1] : rvV(M,S,I,V)           = rvV(M,S,I,V,#get-idx("@" : "#" : "%" : nil,V)) [owise] . --- need to generated binding for V
  eq [V2] : rvV(M,S,I,V,(N,R,J))   = rvV(n(M),S,I,V,chgIdx(n(M),V,N)) .                       --- variable is indexed
  eq [V3] : rvV(M,S,I,V,K)         = rvV(n(M),S,I,V,addIdx(n(M),V)) [owise] .                 --- variable is not indexed
  eq [V4] : rvV(M,S,I,V,V')        = (S ; V <- V',up(I,V'),M) .                               --- propogate freshly generated variable up
  ---
  eq [M0] : p((S,L,M))               = termdata(L,M) .
  eq [M1] : addIdx(I,V)              = qid(string(getName(V)) + "@" + string(I,10)  + ":" + string(getType(V))) .
  eq [M2] : chgIdx(I,V,N)            = qid(N + "@" + string(I,10) + ":" + string(getType(V))) .
  eq [M3] : n(notFound)              = 0 .
  eq [M4] : n(I)                     = s(I) .
  eq [M5] : maxIdx(V <- V' ; S,QS,M) = maxIdx(S,QS,#get-idx("@" : nil,V'),M) .
  eq [M6] : maxIdx(none,QS,M)        = M .
 ceq [M7] : maxIdx(S,QS,(N,R,J),M)   = maxIdx(S,QS ; qid(N),maxF(J,M)) if not qid(N) in QS .
endfm

--- Gathers all functionality into a single module
fmod RENAME-METAVARS is
  pr META-LEVEL      .
  pr CONVERSION      .
  pr GET-TYPES       .
  pr GEN-VARNAMES    .
  pr RENAME-DATA     .
  pr MODULE-HANDLING .

  --- auxiliary function that adds a types equation to a module
  op  add-types    : Module Module -> Module .
  --- given termlist, get set of meta*variable names
  op  getVar       : GTermList -> QidSet .
  --- given termlist, compute their highest tmp/std meta*var indices
  op  highestSVar  : Module GTermList -> FindResult .
  op  highestTVar  : Module GTermList -> FindResult .
  op #highestVar   : Module GTermList -> VarData .
  op #highestVar1  : Term      -> VarData .
  --- given termlist, rename all vars
  op  renameAllVar : Module GTermList            -> GTermList .
  op  renameAllVar : TermData                    -> GTermList .
  op #renameAllVar : Module GTermList            -> TermData .
  op #renameAllVar : Module GTermList GTermList  -> TermData .
  op #renameAllVar : Module FindResult GTermList -> TermData .
  op #renameAllVar : Module Substitution GTermList            -> RenameData .
  op #renameAllVar : Module Substitution GTermList GTermList  -> RenameData .
  op #renameAllVar : Module Substitution FindResult GTermList -> RenameData .
  --- convenience wrappers over highestVar and shiftVar
  op  renameTmpVar : Module GTermList            -> GTermList .
  op  renameTmpVar : TermData                    -> GTermList .
  op #renameTmpVar : Module GTermList            -> TermData .
  op #renameTmpVar : Module GTermList GTermList  -> TermData .
  op #renameTmpVar : Module FindResult GTermList -> TermData .
  --- primary implementation of above functions
  op $renameTmpVar : FindResult VarData         -> TermData .
  op $renameTmpVar : FindResult FindResult Term -> TermData .
  op $renameTmpVar : Nat Term                   -> TermList .

  var M M' : Module . var T T' T'' : Term . var L L' : GTermList . var N : Nat . var TI BI BI' : FindResult . var S : Substitution .

  eq  add-types(M,M') = addEqs(eq 'types.TypeSet = upTerm(get-types(M)) [none].,M') .

  --- INP: TermList
  --- PRE: None
  --- OUT: Set of all of meta*variable names
  eq  getVar(L) = downTerm(getTerm(metaReduce(upModule('GV-IMPL,false),'getVar[upTerm(L)])),none) .

  --- INP: L:TermList
  --- PRE: None
  --- OUT: Maximum tmp/std variable indices in L
 ceq  highestSVar(M,L) = BI if vardata(T,TI,BI) := #highestVar(M,L) .
 ceq  highestTVar(M,L) = TI if vardata(T,TI,BI) := #highestVar(M,L) .
  eq #highestVar(M,L)  =
       #highestVar1(getTerm(metaReduce(add-types(M,upModule('RTV-IMPL2,false)),
         getTerm(metaRewrite(upModule('RTV-IMPL1,false),
           'vardata[upTerm(L),'notFound.FindResult,'notFound.FindResult],unbounded))))) .
  eq #highestVar1('vardata[T,T',T'']) = vardata(T,downTerm(T',0),downTerm(T'',0)) .

  --- INP: [L':TermList/BI':FindResult] L:TermList
  --- PRE: None
  --- OUT: return termdata(L',N) with L' a copy of L with ALL variables renamed
  ---      so they are fresh with respect to L' or BI'
  eq  renameAllVar(M,L)            =  renameAllVar(#renameAllVar(M,L)) .
  eq  renameAllVar(termdata(L,BI)) =  L .
  eq #renameAllVar(M,L)            = #renameAllVar(M,notFound,L) .
  eq #renameAllVar(M,L',L)         = #renameAllVar(M,highestSVar(M,L'),L) .
  eq #renameAllVar(M,BI,L)         = downTerm(getTerm(metaReduce(add-types(M,upModule('RAV-IMPL,false)),'renameAllVar[upTerm(BI),upTerm(L)])),termerr) .
  ---
  eq #renameAllVar(M,S,L)          = #renameAllVar(M,S,notFound,L) .
  eq #renameAllVar(M,S,L',L)       = #renameAllVar(M,S,highestSVar(M,L'),L) .
  eq #renameAllVar(M,S,BI,L)       = downTerm(getTerm(metaReduce(add-types(M,upModule('RAV-IMPL,false)),'#renameAllVar[upTerm(BI),upTerm(S),upTerm(L)])),renameerr) .

  --- INP: [L':TermList/BI':FindResult] L:TermList
  --- PRE: None
  --- OUT: return termdata(L',N) with L' a copy of L with TEMPORARY variables
  ---      standardized and fresh with respect to L'/BI'
  eq  renameTmpVar(M,L)            =  renameTmpVar(#renameTmpVar(M,L)) .
  eq  renameTmpVar(termdata(L,BI)) =  L .
  eq #renameTmpVar(M,L)            = #renameTmpVar(M,notFound,L) .
  eq #renameTmpVar(M,L',L)         = #renameTmpVar(M,highestSVar(M,L'),L) .
  eq #renameTmpVar(M,BI',L)        = $renameTmpVar(BI',#highestVar(M,L)) .

  --- NOTE: implementation of renameTmpVar
  eq $renameTmpVar(BI',vardata(T,TI,BI)) =
       $renameTmpVar(TI,if BI :: Nat then if BI' :: Nat then max(BI,BI') else BI fi else BI' fi,T) .
  eq $renameTmpVar(TI,BI,T) =
       termdata($renameTmpVar(if BI :: Nat then s(BI) else 0 fi,T),
         if TI :: Nat then TI + if BI :: Nat then s(BI) else 0 fi else BI fi) .
  eq $renameTmpVar(N,T) =
       downTerm(getTerm(metaReduce(addEqs(eq 'base.Nat = upTerm(N) [none] .,upModule('RTV-IMPL3,false)),T)),empty) .
endfm
```
