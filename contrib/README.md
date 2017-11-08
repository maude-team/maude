Introduction
============

-   Rewriting logic provides an expressive specification language for defining systems.
-   Also flexible enough to define analysis directly in that language via `META-LEVEL`.
-   Conditional rewriting increases expressiveness, allowing side-conditions on rewrite sequents.

Background
==========

Order Sorted Algebra
--------------------

-   Equational rewriting specifications have algebraic models.
-   These algebras have homomorphisms, quotients, isomorphisms.
-   Rewriting specifications which are coherent modulo axioms behave well algebraically.
-   Maude specifications have *initial* algebras/models.

Conditional Rewriting
---------------------

-   Allow side-conditions on rules to constrain the transition system further.
-   In equational case, move from algebras to Horn theories.
-   Increases expressiveness substantially, but also decreases decidability.
