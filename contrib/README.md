Background
==========

Rewriting Logic
---------------

-   Expressive and general way of describing transition systems.
-   Uses term-structure to represent state.
-   Use algorithms for *matching modulo axioms* $B$ to take a specific transition.
-   *Reflective* nature allows self-representing implementations.

### Conditional Rewriting Logic

-   Allow side-conditions on rules to constrain the transition system further.
-   Side-conditions are rewriting sub-goals.

### Narrowing

-   Symbolic rewriting by using unification instead of matching.
-   Unification algorithm may not be present for a given set of axioms $B$.

Order Sorted Algebra
--------------------

-   Equational rewriting specifications have algebraic models.
-   Rewriting specifications which are confluent, terminating, and coherent modulo axioms behave well algebraically.
-   Maude gives *initial* algeabra semantics to its equational specifications.

### Conditional Equational Logic

-   Models no longer algeabraic, in general become Horn theories?

### Unification

-   Symbolic equational reasoning.
-   Narrowing gives semi-algorithm for unification for equationally specified systems.
-   When a theory has the *finite variant property (FVP)*, narrowing becomes algorithm/decidable?
-   Provided an *OS-compact constructor sub-signature*, even better?
-   In case the conditions are in FVP sub-theory, recover algebraic models?

Maude
-----

-   Rewriting Logic engine with many fast algorithms for matching and unification.

TODO: Include some documentation on `META-LEVEL` module.
