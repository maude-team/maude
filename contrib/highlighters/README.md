Highlighters for Maude
======================

-   [Vim editor highlighter](maude.vim)
-   [Kakoune editor highlighter](maude.kak)
-   [Pygments PDF highlighter](pygments.py)

Pygments Usage
--------------

### Command Line

In order to use these lexers on the command line, pass the parameter
`-l /path/to/pygments_maude.py:MaudeLexer -x` (for batch Maude code) or
`-l /path/to/pygments_maude.py:MaudeLogLexer -x` (for Maude system interaction
logs) to the `pygmentize` comand in place of a language flag (where
`/path/to/pygments_maude.py` are replaced by the actual local path to the file
[`pygments_maude.py`](https://raw.githubusercontent.com/pthariensflame/pygments-maude/master/pygments_maude.py)
from this repository).

### LaTeX/`minted`

In order to use these lexers with [LaTeX](http://www.latex-project.org) and
[`minted`](https://github.com/gpoore/minted), put the following lines into your
document preamble:

``` latex
\usepackage{xparse}
\NewExpandableDocumentCommand\maudeLexer{}{pygments_maude.py:MaudeLexer -x}
\NewExpandableDocumentCommand\maudeLogLexer{}{pygments_maude.py:MaudeLogLexer -x}
```

Then place the the file
[`pygments_maude.py`](https://raw.githubusercontent.com/pthariensflame/pygments-maude/master/pygments_maude.py)
from this repository into the same directory as your document; you should now be
able to use `\maudeLexer` and `\maudeLogLexer` as languages recognized by all
`minted` commands. (Note that this will require a fairly recent version of
`minted`, as well as a TeX install that supports
[LaTeX3](https://www.latex-project.org/latex3/).)
