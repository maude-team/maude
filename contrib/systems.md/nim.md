Nim Strategy Model Checker
==========================

```maude
mod NIM is
```

-   A stick (symbol `|`) will make up a non-empty row (`sort NeRow`).
-   Every non-empty row will also be a row (`subsort NeRow < Row`).
-   Putting a non-empty rows next to a row makes a non-empty row (`op __ : NeRow Row -> NeRow`).
-   We'll declare row-concatenation (`op __`) to be associative and commutative `[assoc comm id: .Row]`.

```maude
    sorts NeRow Row .
    -----------------
    subsort NeRow < Row .

    op | : -> NeRow .
    ------------------

    op .Row : -> Row .
    op __ :   Row Row ->   Row [assoc comm id: .Row prec 40] .
    op __ : NeRow Row -> NeRow [ditto] .
    ------------------------------------
```

-   A `NeBoard` is formed by bracketing a `NeRow` (`op <_> : NeRow -> NeBoard`).
-   We can also put boards next to each other and form larger boards (`op __ : Board Board -> Board`).
-   If a given board has an empty row (`.Row`), reduce it to the empty board (`.Board`).

```maude
    sorts NeBoard Board .
    ---------------------
    subsort NeBoard < Board .

    op <_> : NeRow -> NeBoard .
    op <_> :   Row ->   Board .
    ---------------------------
    
    op .Board : -> Board .
    op __ :   Board Board ->   Board [assoc comm id: .Board prec 70 format(d n d)] .
    op __ : NeBoard Board -> NeBoard [ditto] .
    ------------------------------------------
    eq < .Row > = .Board .
```

A game configuration consists of a `Board` and a marker of whos turn it is.
If the board is wrapped with `[_]`, it's our turn, with `{_}` and it's the other player's turn.

```maude
    sort Conf .
    -----------

    op {_} : Board -> Conf .
    op [_] : Board -> Conf .
    ------------------------
```

Declare some variables for use in the strategy rules below.

```maude
    var R : Row   . vars NeR NeR' : NeRow   .
    var B : Board . vars NeB      : NeBoard .
```

The other player non-deterministically removes some non-zero amonuts of sticks and passes the turn to us.
This ensures that every potential game-path is explored.

```maude
    rl { < NeR R > B }
    => [ <     R > B ] .
```

Now it's time to program our strategy.
This rule is always safe, if there is a single non-empty row and a row with a single stick, take the non-empty row.

```maude
    rl [ < NeR > < | > ]
    => {         < | > } .
```

The following heuristic is unsafe, as demonstrated below.
In the presences of 3+ rows (notice the `NeB` variable must have at least one row in it), it will make two rows equal in size.

```maude
    rl [ < NeR NeR' > < NeR > NeB ]
    => { < NeR      > < NeR > NeB } .
```

Two initial configurations (`init1` and `init2`):

```maude
    op init1 : -> Board .
    eq init1 = < | >
               < | | >
               < | | | >
               < | | | | >
               < | | | | | > .

    op init2 : -> Board .
    eq init2 = < | >
               < | | | >
               < | | | | | >
               < | | | | | | | > .
endm
```

`search S =>! P` will exhuastively search starting in state `S` for terminating states (`=>!`) such that pattern `P` is matched.
Here we'll just look for *any* terminating state (`C:Conf`) from the initial configurations with it being our turn.
Because we see some un-winnable games in the output, we know our strategy doesn't work.

The actual winning strategy involves computing the Nim-sum of the board (`xor`-ing the binary representations of the number of sticks in each row together).
If the Nim-sum is zero, then any move will make it non-zero; if it is non-zero, you can always make it zero.
This means there is an abstraction of the game (the "kernel") which is controllable.
I wanted to see if I could use the model-checker to come up with some heuristics without explicitely solving the game.
