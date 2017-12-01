Cellular Automata in Maude
==========================

A cellular automata is a soup of cells, where each cell is holding some internal
state. Once a cell is "activated", it reads the state of each of its neighbor
cells to compute its own next state. Once the next state has been computed, a
cell waits to be deactivated. All of the cells are activated simultaneously, and
once all of the cells have computed their next state they are all deactivated.

To make a query, first launch `maude` with the input file:

```sh
$ maude caut.maude
```

Then ask Maude to `rewrite` a certain number of times from the initial state:

```sh
Maude> rewrite [25] tick { init } .
Maude> rewrite [28] tick { init } .
```


Cellular Cultures
-----------------

We define the structure of a `Culture`. Every `Cell` is a singleton `Culture`.

```maude
fmod CELLULAR-CULTURE is

    sorts State States State? .
    subsort State < States State? .
    sorts StateLabel StateKey .
    sorts Cell Culture .
    subsort Cell < Culture .

    sorts Clock Dish .
```

### Cell

`Cell`s store a different amount of data, depending on whether they are
"activated" or not. They always store their own `StateLabel` and their own
`State?`. A `State?` can just be a regular `State` (by subsorting), or it can be
a `State` and a `States` (using the `_->_` operator), meaning the `Cell` is
activated and calculating its next state.

```maude
    op _->_ : State States -> State? [prec 56] .
    op _::_ : StateLabel State? -> Cell [prec 57] .
```

### Culture

We have an "empty" `Culture` (`mt`), and say that `Culture`s can be combined
associatively/comuttatively using the `_;_` operator.

```maude
    op mt  : -> Culture [ctor] .
    op _;_ : Culture Culture -> Culture
             [assoc comm idem id: mt prec 60 format(d n d d)] .
```

### Computing Next State

When computing the next state for the current cell, we'll need a list of
neigbhoring states. To know which neighboring cell corresponds to each
neighboring state, we'll use a marker `StateKey`, which can hold either the
`StateLabel` or the `State` of the state it corresponds to.

```maude
    op mt   : -> States .
    op __   : States   States     -> States [assoc comm id: mt prec 55] .
    op _[_] : StateKey State      -> States .
    op _[_] : StateKey StateLabel -> States .

    op neighbors : StateLabel -> State? .
```

The `neighbors` function is used to calculate which neighbors are relevant to
each `Cell`. This is simulation specific.

### Neighbor Lookup

If what we're holding is the `StateLabel`, we need to do a lookup in the
associative commutative soup of `Cell` to find the corresponding `State`. It
could be that the `StateLabel` refers to our own state, which needs to be
handled specially.

```maude
    vars N N'   : StateLabel .
    vars S S'   : State .
    var  SS SS' : States .
    var  SK     : StateKey .

    eq   N :: S -> SK[N] SS
       = N :: S -> SK[S] SS .

    eq   N :: S -> SK[N'] SS ; N' :: S' -> SS'
       = N :: S -> SK[S'] SS ; N' :: S' -> SS' .
```

### Life Cycle

To drive the whole simulation forward, we'll need a `Clock` which switches back
and forth between two states, `tick` and `tock`. A `Clock` together with a
`Culture` is a `Dish`.

```maude
    ops tick tock : -> Clock .
    op  _{_}      : Clock Culture -> Dish [format(d n s n d)].
```

Notice that on `tick`, any unactivated `Cell` is activated by querying the
`neighbors` function to get the relevant state from the surrounding `Culture`.
On `tock` the simplified `Cell`s which have already computed their next state
are deactivated (notice we use variable `S'`, which is of sort `State`, not of
sort `State?`).

```maude
    var  C    : Culture .

    eq   tick { N :: S                 ; C }
       = tick { N :: S -> neighbors(N) ; C } .

    eq   tock { N :: S -> S' ; C }
       = tock { N :: S'      ; C } .
endfm
```

Our Simulation
--------------

```maude
fmod DISH-PARAMETERS is
    protecting INT .
    protecting RANDOM .
    extending CELLULAR-CULTURE .

    sort Point .
    subsort Point < StateLabel .

    --- Labels are indices in a 5X5 Circular Grid

    op (_,_) : Int Int -> Point .
    op pt    : Int -> Point .

    vars N M : Int .

    ops width height : -> Nat .
    eq  width  = 5 .
    eq  height = 5 .
    eq  pt(N) = (N rem width, N quo width) .

    ceq (N,M) = (N - width, M)  if N >= width .
    ceq (N,M) = (N, M - height) if M >= height .
    ceq (N,M) = (N + width, M)  if N < 0 .
    ceq (N,M) = (N, M + height) if M < 0 .

    --- States are either `X` or `-`
    --- The neighborhood is the current cell + adjacent cells

    ops X - : -> State .
    ops up down left right : -> StateKey .

    eq neighbors((N,M)) = up    [(N , M + 1)]
                          left  [(N - 1 , M)]
                          down  [(N , M - 1)]
                          right [(N + 1 , M)]
                          .

    vars S U D L R : State .

    --- calculate the next state as a function of the neighborhood

    eq S -> up[X] down[X] left[L] right[R] = S -> X .
    eq S -> up[U] down[D] left[-] right[X] = S -> X .
    eq - -> up[-] down[X] left[-] right[-] = - -> X .
    eq S -> up[U] down[D] left[L] right[R] = S -> - [owise] .

    --- generate a random 5X5 grid

    var Rn : Nat .

    op init    : -> Culture .
    op genInit : Nat -> Culture .

    eq  init = genInit(0) .
    ceq genInit(Rn) = mt
        if Rn == width * height .
    ceq genInit(Rn) = genInit(Rn + 1)
                    ; pt(Rn) :: if random(Rn) rem 2 == 0 then X else - fi
        if Rn < 25 .
endfm
```

```maude
mod CELLULAR-AUTOMATA is
    extending DISH-PARAMETERS .

    --- once all dish simplifications are done, push clock forward

    rl [tock] : tick => tock .
    rl [tick] : tock => tick .
endm
```
