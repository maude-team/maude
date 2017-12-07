Cellular Automata in Maude
==========================

A cellular automata is a soup of cells, where each cell is holding some internal state.
Once a cell is "activated", it reads the state of each of its neighbor cells to compute its own next state.
Once the next state has been computed, a cell waits to be deactivated.
All of the cells are activated simultaneously, and once all of the cells have computed their next state they are all deactivated.

Data Structures
---------------

### States

```maude
fmod CELLULAR-AUTOMATA-DATA is
```

-   Sort `State` is left empty (for the user to fill) and represents the states that each cell can be in.

```maude
    sorts State States State? .
    ---------------------------
    subsort State < States State? .

    vars S S'   : State .
    var  SS SS' : States .
```

-   Operator `_->_` represents a cell that is computing its next state given its current state and neighboring states.
-   Operator `__` lets us group states together in a multiset.

```maude
    op _->_ : State States  -> State? [prec 56] .
    ---------------------------------------------

    op .States : -> States .
    op __      : States States -> States [assoc comm id: .States prec 55] .
    -----------------------------------------------------------------------
```

### Cells

-   Sort `Cell` represents an individual cell on the board.
-   Operator `_::_` holds a cell marked by its identifier and current state.
-   Operator `_;_` gives us a soup of cells which can evolve together (with the empty set of cells being `.Cells`).

```maude
    sorts CellId Cell Cells .
    -------------------------
    subsort Cell < Cells .

    var  C    : Cell .
    var  CS   : Cells .
    vars N N' : CellId .

    op _::_ : CellId State? -> Cell [prec 57] .
    -------------------------------------------

    op .Cells : -> Cells [ctor] .
    op _;_    : Cells Cells -> Cells [assoc comm idem id: .Cells prec 60 format(d n d d)] .
    ---------------------------------------------------------------------------------------
    eq C ; C = C .
```

### Evolution

-   Sort `CellKey` should be filled by the user to provide identifiers for each neighboring cell state.
-   Operator `_[_]` is used to load the current state of the neighboring cells so that the next state of the current cell can be calculated.

```maude
    sort CellKey .
    --------------
    var CK : CellKey .

    op _[_] : CellKey State  -> States .
    op _[_] : CellKey CellId -> States .
    ------------------------------------
    eq N :: S -> CK[N] SS
     = N :: S -> CK[S] SS .

    eq N :: S -> CK[N'] SS ; N' :: S' -> SS'
     = N :: S -> CK[S'] SS ; N' :: S' -> SS' .
```

-   `neighbors` is defined by the user to inform which cells should be considered neighbors by the simulator.

```maude
    op neighbors : CellId -> State? .
    ---------------------------------
```

-   Sort `Conf` wraps sort `Cells` to create the "game board".
-   Operator `[_]` tells the board that it's time to load the neighboring states.
-   Operator `{_}` tells the board that it's time to accept the new state.

```maude
    sort Conf .
    -----------

    op [_] : Cells -> Conf .
    ------------------------
    eq [ N :: S                 ; CS ]
     = [ N :: S -> neighbors(N) ; CS ] .

    op {_} : Cells -> Conf .
    ------------------------
    eq { N :: S -> S' ; CS }
     = { N :: S'      ; CS } .
endfm
```

Simulator
---------

To drive the clock forward, we'll have two rules which switch the surrounding braces between `[_]` and `{_}`.

```maude
mod CELLULAR-AUTOMATA is
   protecting CELLULAR-AUTOMATA-DATA .

    var CS : Cells .

    rl [tock] : [ CS ] => { CS } .
    rl [tick] : { CS } => [ CS ] .
endm
```

Instantiations
==============

The above data-structures provide a simulator for *any* cellular automata, but some common cases come up often.

Periodic Grid
-------------

One common example is the 2D periodic grid (embedding on a torus).
Here, the `CELLULAR-AUTOMATA-DATA` is specialized to this case.
This grid does not count diagonal neighbors, which would be necessary for Conway's Game of Life.

```maude
mod PERIODIC-GRID is
   protecting INT .
    extending CELLULAR-AUTOMATA .

    vars N M : Int .
```

-   Sort `Point` will be pairs of integers marking which position in the torus we're at.

```maude
    sort Point .
    ------------
    subsort Point < CellId .

    op <_,_> : Int Int -> Point .
    op pt    : Int     -> Point .
    -----------------------------
    eq pt(N) = < N quo width , N rem width > .
```

-   `width` and `height` are specified by the user to make the grid the correct size (notice that inside a `Point` modular arithmetic is performed).

```maude
   ops width height : -> Nat .
   ---------------------------
   ceq < N , M > = < N - height , M         > if N >= height .
   ceq < N , M > = < N          , M - width > if M >= width .
   ceq < N , M > = < N + height , M         > if N < 0 .
   ceq < N , M > = < N          , M + width > if M < 0 .
```

-   We have 4 neighbors, so there are 4 `CellKey`s, one for each neighbor.
    Here we specify how `neighbors` calculates the correct `CellId` for each neighboring `CellKey`.

```maude
   ops up down left right : -> CellKey .
   -------------------------------------
    eq neighbors(< N , M >)
     = up    [< N - 1 , M     >]
       left  [< N     , M - 1 >]
       down  [< N + 1 , M     >]
       right [< N     , M + 1 >] .
endm
```
