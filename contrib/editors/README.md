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

Maude Mode (Emacs)
==================

This is version 0.2 of an XEmacs major mode for the Maude language.
It provides syntax-highlighting, calling Maude in a buffer, commenting/uncommenting regions, and auto-indentation.
If there are new versions, you will find them at <http://www.csl.sri.com/~kai/MaudeMode> .

New in version 0.2 is syntax highlighting in the buffer that is running Maude and a different handling of calls to Maude:

-   `C-c C-m` calls Maude,
-   `C-c C-f` calls Full-Maude, and
-   `C-c C-c` copies the current buffer to Maude.

This mode does *not* work with FSF Emacs since FSF doesn't support nongreedy quantifiers in regular expressions.
Use XEmacs.
For other reasons why to prefer XEmacs over FSF Emacs see point 3.3 and 5.3 at <http://www.xemacs.org/Architecting-XEmacs/xemacs-tour.html>.

To install: Once you have untared maude-mode.tar.gz in your home directory you will find all the files in `~/MaudeMode/`.
Now just add the following lines to your `~/.emacs`:

```emacs
;; ------------------- Maude mode
(setq load-path (cons "~/MaudeMode" load-path))
(setq auto-mode-alist (cons '("\\.maude" . maude-mode) auto-mode-alist))
(defvar maude-cmd "~/Maude/maude-linux/bin/maude.linux"
"Defines the command line to call the Maude engine")

(require 'maude-mode)

;; -------------------
```

Adapt the maude-cmd to your environment.

Just load a Maude file in XEmacs. Syntax highlighting should be automatic, if not, turn it on under `Options -> Syntax Highlighting -> In this Buffer` .
To change colors, see `Options -> Customize -> Faces -> Font Lock Faces`.
You can comment/uncomment regions using `C-c c / C-c u`.

Enjoy.

Kai
kai.bruennler@gmx.net
