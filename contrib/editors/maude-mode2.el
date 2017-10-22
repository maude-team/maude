;;; maude-mode.el -- Emacs mode for the programming language Maude

;; Copyright (C) 2004  Free Software Foundation, Inc.

;; Author and Maintainer: Ellef Gjelstad <ellefg+maude*ifi.uio.no>
;; Keywords: Maude
;; Time-stamp: <2004-07-29 14:55 by  (ellefg*ifi.uio.no)>

;; This program is free software; you can redistribute it and/or
;; modify it under the terms of the GNU General Public License as
;; published by the Free Software Foundation; either version 2 of
;; the License, or (at your option) any later version.

;; This program is distributed in the hope that it will be
;; useful, but WITHOUT ANY WARRANTY; without even the implied
;; warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
;; PURPOSE.  See the GNU General Public License for more details.

;; You should have received a copy of the GNU General Public
;; License along with this program; if not, write to the Free
;; Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
;; MA 02111-1307 USA



; This started with inspiration from Scott Andrew Borton's language mode creation tutorial,
; http://two-wugs.net/emacs/mode-tutorial.html

; Todo:
; Full Maude (and parametrised modules)
; ansi-color.el to use format
; Doesnt know wheter run-maude work at the moment.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defvar maude-mode-hook nil)
; Make a keymap (map from keypresses to emacs functions)
(defvar maude-mode-map nil
  "Keymap for Maude major mode")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;; Running Maude
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; This currently does not work on my Windows machine.
;; Don't know whether it still works on Unix.

;; For documentation on the functionality provided by comint mode, and
;; the hooks available for customising it, see the file `comint.el'.
(require 'comint)
(setq maude-cmd "/local/bin/maude")
(require 'derived)


(defun copy-current-buffer-to-maude ()
  (interactive)
  (save-buffer)
  (comint-send-string "Maude" (concat "in " (buffer-file-name) "\n")))


(define-derived-mode maude-running-mode
  comint-mode "Maude running"
  "Major mode for running Maude."
  (font-lock-mode)
  (setq font-lock-keywords
				(list '("Maude>" 0 font-lock-comment-face t))))

 (if maude-mode-map nil
  (progn
    (setq maude-mode-map (make-keymap))
    (define-key maude-mode-map "\C-c\C-c" 'maude-send-paragraph)
    (define-key maude-mode-map "\C-c\C-r" 'maude-send-region)
    (define-key maude-mode-map "\C-c\C-b" 'maude-send-buffer)
    (define-key maude-mode-map "\t" 'maude-indent-line)))



;; for running Maude
(defvar maude-buffer nil
  "Defines the buffer to call the Maude engine in"
  )


(defun maude-send-region (start end)
  "Send a region to the MAUDE process."
  (interactive "r")
  (if (buffer-live-p maude-buffer)
      (save-excursion
	(comint-send-region maude-buffer start end)
	(if (string-match "\n$" (buffer-substring start end))
	    ()
	  (comint-send-string maude-buffer "\n"))
	(message "Sent string to buffer %s." (buffer-name maude-buffer))
; 	(if maude-pop-to-buffer-after-send-region )
; 	    (pop-to-buffer maude-buffer))
; 	  (display-buffer maude-buffer)))
)
    (message "No Maude process started.  M-x run-maude.")))

(defun maude-send-paragraph ()
  "Send the current paragraph to the MAUDE process."
  (interactive)
  (let ((start (save-excursion
		 (backward-paragraph)
		 (point)))
	(end (save-excursion
	       (forward-paragraph)
	       (point))))
    (maude-send-region start end)))

(defun maude-send-buffer ()
  "Send the buffer contents to the MAUDE process."
  (interactive)
  (maude-send-region (point-min) (point-max)))

(defun run-maude ()
  (interactive)
  (save-buffer)
  (setq maude-buffer (make-comint "Maude" maude-cmd ))
  ;; in 99% you don't wanna know...
  (comint-send-string "Maude" "set show timing off .\n")
  (switch-to-buffer-other-window maude-buffer)
  (maude-running-mode)
  (other-window -1)
  )

(defun run-full-maude ()
  (interactive)
  (run-maude)
  (comint-send-string "Maude"
		      (concat "in " (file-name-directory maude-cmd)
			      "full-maude.maude\n"))
  (comint-send-string "Maude" "loop init .\n")
  (switch-to-buffer-other-window maude-buffer)
  (other-window -1)
	)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;; Syntax higlighting
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; FACES IN MAUDE-MODE
;; The most important faces are:
;; - attribute-face: attributes to operators (like comm and gather)
;; - attribute-value-face: their values
;; - maude-module-name-face: names of modules
;; - maude-file-face: Face on files and directories
;; - maude-start-face: words like mod and fmod
;; - bold: used to emphasize the dots.
;; - font-lock-keyword-face: all the other keywords
;; - font-lock-type-face: defining sorts
;; - element-face: about what values we can have in a sort (ctor, subsort etc)
;; - font-lock-variable-name-face: variables
;; - font-lock-function-name-face: operators
;; - maude-pattern-face: patterns to match, in equations and ifs
;; - maude-label-face: name of rules and equation
;; - maude-end-face: the dot at the end of commands.
;; - font-lock-comment-face.  This doesn't handle (*** style multiline comments well.
;; - maude-comment-highlight-face:  Highlight **** comments.
;; - maude-comment-highlight-highlight-face: Highlight ***** comments.
;; - warning-face: Face to emphasize certain dangerous constructs.

; This should be removed, but I don't have the guts yet.
; May be good in full maude context???
(defconst maude-keywords
  (eval-when-compile
		(regexp-opt '(;"in"
;; 									"loop" "match" "xmatch" "set" "trace" "on" "off" "show" "debug" "select" "include"
;; 									"pr" "protecting"
;; 									"inc" "including"
;; 									"sorts" "sort"
;;                            "subsorts" "subsort"  ;; Handled otherwise
;; 									 "id:" "identity:" "assoc" "associative" "comm" "commutative" "prec" "precedence" ;; These are handled as operator attributes
;; 									"idem" "idempotent" "strat" "strategy"
;; 									"vars" "var"
									"red" "reduce" "rew" "rewrite" "cond" "condition" "subst" "substitution" "cont" "continue" "flat" "flattened" "parens" "parentheses" "cmd" "command"
;; 									"sort" "sorts" "op" "ops" "var" "vars" "mb" "mbs" "eq" "eqs" "rl" "rls"
									"kinds" "components" "module"
									"pr" "inc" "is" "class" "cmb" "rl" "crl" "msg" "msgs" "ceq"
;; 									"ctor" "id"
									"and" "or" "else" "fi"
									"fth" "endfth" "view" "endv"
									"subclass")
								t))
	"Maude keywords")


(defconst maude-warnings
	(concat "\\(\\<eof\\>"          ; eof
					"\\|\\<quit\\>\\|^\\s-*?q\\>"         ; quit
					"\\|\\w\\.\\s-*?$"      ; text.
					"\\|\\]\\."                ; ].
					"\\|)\\."                  ; ).
					"\\|\\w->"               ; text->
					"\\|->\\w"       ; ->text
					"\\|\\w=>"       ; text=>
					"\\|=>\\w"       ; =>text
					"\\|var.*\\w:"     ; var text:
					"\\|var.*:\\w"       ; var :text
					"\\|\\<eq\\>.*\\s-=>\\s-" ; eq foo => bar
					"\\|\\<rl\\>.*\\s-=[ ][^\n][^\n]" ; rl foo = bar ; This doesn't work
					"\\|\\<var\\>\\s-+\\w+\\s-+\\w+" ; var, not vars
					"\\|\\<sort\\>\\s-+\\w+\\s-+[a-su-zA-Z][a-np-zA-Z]\\w*?" ; sort, not sorts.  Not sort Foo to Bar .
					"\\|\\<op\\>\\s-+\\w+\\s-+\\w+.*:" ; op, not ops
 					"\\|\\<vars?\\>.*?," ; vars foo , bar
 					"\\|\\<sorts?\\>.*?," ; sorts foo , bar
 					"\\|\\<ops?\\>[^:$t(]*?," ; ops foo , bar  The reason for the t is mappings in full maude: op identity to vector(0,0) .
					"\\|\\<prec\\w*\\>\\s-*9[6-9]" ; I have no Idea why this caused error once.  Precedence < 95 ok
					"\\|\\<prec\\w*\\>\\s-*1[1-3][0-9]" ; I have no Idea why this caused error once.  Precedence < 95 ok
					"\\|\\<prec\\w*\\>\\s-*[2-9][0-9][0-9]" ; Illegal high precedences?
					"\\|^omod\\|^fth\\|^view" ; Should have full maude here, with "(" before
					"\\)")
	"Regexps to be coloured with warning-face")

; Making faces
(setq attribute-face 'attribute-face)
(setq attribute-value-face 'attribute-value-face)
(setq element-face 'element-face)
(setq bold 'bold)
(setq default 'default)

(defvar maude-start-face () "Face to starting words like fmod in maude")
(make-face 'maude-start-face)
; (defface maude-start-face '((t (:foreground "green" :bold t)))
; 	"Face for starting words like fmod in maude")
(copy-face 'font-lock-variable-name-face 'maude-start-face)
(set-face-bold-p 'maude-start-face t)
(setq maude-start-face 'maude-start-face)

(defvar maude-module-name-face () "Face to declaration of e.g. modules in maude")
(make-face 'maude-module-name-face)
(copy-face 'font-lock-type-face 'maude-module-name-face )
(set-face-bold-p 'maude-module-name-face t)
(setq maude-module-name-face 'maude-module-name-face)

(defvar maude-pattern-face () "Face in patterns in ifs and equations")
(make-face 'maude-pattern-face)
;; (copy-face 'default 'maude-pattern-face)
(set-face-italic-p 'maude-pattern-face t)
(setq maude-pattern-face 'maude-pattern-face)

(defvar maude-label-face () "Face on labels in Maude")
(defface maude-label-face
	'((((type x w32 mac) (class color))
		 (:box (:line-width -1 :style released-button)
; ; 	   :background "grey75" :foreground "black"
					 ))
		(t
		 (:inverse-video t)))
	"Face on labels in Maude."
;;    :version "21.1"
	:group 'maude)
;; (make-face 'maude-label-face)
;; (copy-face 'font-lock-doc-face 'maude-label-face)
;; (set-face-bold-p 'maude-label-face t)
(setq maude-label-face 'maude-label-face)

(defvar maude-file-face () "Face on files and directories")
(make-face 'maude-file-face)
(copy-face 'maude-module-name-face 'maude-file-face)
(invert-face 'maude-file-face)
(setq maude-file-face 'maude-file-face)

(defvar maude-comment-highlight-face () "Face on 'comment headlines' with four asterisks")
(make-face 'maude-comment-highlight-face)
(copy-face 'font-lock-comment-face 'maude-comment-highlight-face)
(set-face-bold-p 'maude-comment-highlight-face t)
(setq maude-comment-highlight-face 'maude-comment-highlight-face)

(defvar maude-comment-highlight-highlight-face () "Face on important 'comment headlines' with five asterisks")
(make-face 'maude-comment-highlight-highlight-face)
(copy-face 'maude-comment-highlight-face 'maude-comment-highlight-highlight-face)
(invert-face 'maude-comment-highlight-highlight-face)
(setq maude-comment-highlight-highlight-face 'maude-comment-highlight-highlight-face)

(defvar maude-end-face () "Face on the final '.'")
(make-face 'maude-end-face)
(copy-face 'bold 'maude-end-face)
(setq maude-end-face 'maude-end-face)

;; Temporary variables for maude-font-lock-regexp.
;; However, didnt find elegant way of setting them local (with let or something)
;; These regexps match the space after them.
(setq maude-flk-label "\\(\\(\\[.+?\\]\\)\\s-+?\\(:\\)\\s-+?\\)?" ; [label]
			maude-flk-pattern "\\(.*?\\)\\s-+?" ; pattern term
			maude-flk-term "\\(.+\\)\\s-+" ; term
			maude-flk-name "\\(\\w+\\)\\s-+" ; General name.  Try to use sth else
			maude-flk-type-name "\\([a-zA-Z0-9()|]+@?[a-zA-Z0-9()|]*\\s-+\\)" ; sort name.  May contain @ and several ()
;; 			maude-flk-module "\\(\\w\\S-*\\s-+\\)" ; module name	
			maude-flk-mod-id "\\(\\w\\S-*\\s-+\\)" ; module name	
			maude-flk-mod-exp "\\(\\w.*?\\)\\s-+" ; module expression.  May be parametrised module, M*N, M+N, (M)
			maude-flk-end "\\(\\.\\)\\s-" ; end of command.
			maude-flk-end-command "\\(\\.\\))?\\s-" ; end of command.  ) for Full Maude
			maude-flk-number-in-square "\\(\\[[0-9]+\\]\\s-+\\)?" ; [10]
			maude-flk-in-module "\\(\\(\\<in\\>\\)\\s-+\\(\\w+\\)\\s-+\\)?" ; in FOO :
			maude-flk-term-possibly-two-lines  ".*?\\s-*?.*?\\s-*?"
			maude-flk-debug "\\(\\<debug\\>\\s-+\\)?"
			maude-flk-such-that-condition "\\(\\(\\<such\\s-+that\\>\\|\\<s\\.t\\.\\)\\s-+\\(.+\\)\\s-\\)?"
			maude-flk-file-name "\\(\\S-+\\)\\s-*"
			maude-flk-directory "\\(\\w\\S-*\\)\\s-*"
			maude-flk-on-off "\\<\\(on\\|off\\)\\>\\s-+"
			)

(defun maude-flk-keyword (keyword)
	(concat "\\(\\<" keyword "\\>\\)\\s-+?"))
(defun maude-flk-attribute (attribute)
	(concat "\\[.*\\(\\<" attribute "\\>\\).*]"))
(defun maude-flk-attribute-value (attribute value)
	(concat "\\[.*\\(\\<" attribute "\\>\\)\\s-+\\(" value "\\).*]"))
(defun maude-flk-attribute-colon-value (attribute value)
	(concat "\\[.*\\(\\<" attribute ":\\)\\s-+\\(" value "\\).*]"))

; To a certain degree, this follows the order of the Maude grammar
(defconst maude-font-lock-keywords
  (list
   ;; Fontify keywords
;   (cons  (concat "\\<\\(" maude-keywords "\\)\\>") 'font-lock-keyword-face)
;;    ;; Fontify system
;;    (cons (concat "\\<\\(" system "\\)\\>") 'font-lock-type-face)
    ;; punctuations : . ->    =    =>     <=    <      >    =/=
;	 (cons "\:\\|\\.\\|\-\>\\|\~\>\\|\=\\|\=\>\\|\<\=\\|\<\\|\>\\|\\/" 'font-lock-keyword-face)
	 ;;; SYSTEM COMMANDS
	 (list (concat (maude-flk-keyword "in") maude-flk-file-name "$")
				 '(1 maude-start-face t t) '(2 maude-file-face t t))
	 (list (concat "^\\s-*\\<\\(quit\\|q\\|eof\\|popd\\|pwd\\)\\\\s-*$")
				 '(1 maude-start-face t t))
	 (list (concat (maude-flk-keyword "cd\\|push") maude-flk-directory "$")
				 '(1 maude-start-face t t) '(2 maude-file-face t t))
	 (list (concat (maude-flk-keyword "ls") "\\(.*?\\)\\s-+" maude-flk-directory "$")
				 '(1 maude-start-face t t) '(2 font-lock-builtin-face t t) '(3 maude-file-face t t))
	 ;;; COMMANDS
	 (list (concat (maude-flk-keyword "select") maude-flk-name maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 maude-module-name-face t t) '(3 maude-end-face t t))
	 (list (concat (maude-flk-keyword "load") maude-flk-file-name "$")
				 '(1 maude-start-face t t) '(2 maude-file-face t t))
;; 	 (list (concat (maude-flk-keyword "in") maude-flk-file-name)
;; 				 '(1 maude-start-face t t) '(2 maude-module-name-face t t))
	 (list (concat (maude-flk-keyword "parse") maude-flk-in-module "\\(:\\)" maude-flk-term maude-flk-end-command)
				 '(1 maude-start-face t t) '(3 font-lock-keyword-face t t) '(4 maude-module-name-face t t) '(6 maude-end-face))
	 (list (concat maude-flk-debug (maude-flk-keyword "red\\|reduce")
								 maude-flk-in-module "\\(:\\)" maude-flk-term maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 maude-start-face t t) '(4 font-lock-keyword-face) '(5 maude-module-name-face t t)
				 '(6 font-lock-keyword-face t t) '(8 maude-end-face))
	 (list (concat maude-flk-debug (maude-flk-keyword "red\\|reduce")
								 maude-flk-term maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 maude-start-face t t)  '(4 maude-end-face))
	 (list (concat maude-flk-debug (maude-flk-keyword "rew\\|rewrite") maude-flk-number-in-square maude-flk-in-module
								 maude-flk-term-possibly-two-lines maude-flk-end-command)
				 '(1 maude-start-face prepend t) ; debug
				 '(2 maude-start-face prepend t) ; rew
				 '(3 font-lock-builtin-face prepend t) ; [10]
				 '(5 font-lock-keyword-face prepend t) ; in
				 '(6 maude-module-name-face prepend t)
				 '(7 maude-end-face prepend t))
	 (list (concat maude-flk-debug (maude-flk-keyword "frew\\|frewrite")
								 "\\(\\[[0-9, ]+\\]\\)?\\s-+" ; Note the regexp [10, 10]
								 maude-flk-in-module
								 maude-flk-term-possibly-two-lines maude-flk-end-command)
				 '(1 maude-start-face prepend t) ; debug
				 '(2 maude-start-face prepend t) ; rew
				 '(3 font-lock-builtin-face prepend t) ; [10]
				 '(5 font-lock-keyword-face prepend t) ; in
				 '(6 maude-module-name-face prepend t)
				 '(7 maude-end-face prepend t))
	 (list (concat (maude-flk-keyword "x?match") maude-flk-number-in-square
 								 maude-flk-in-module maude-flk-term "\\(<=\\?\\)" "\\(.+?\\)\\s-"
 								 maude-flk-such-that-condition maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 font-lock-builtin-face t t) '(4 font-lock-keyword-face t t) '(5 maude-module-name-face t t)
 				 '(7 maude-start-face t t) ; <=?
 				 '(10 font-lock-keyword-face t t) ; such that
 				 '(12 maude-end-face t t)) ; such that
	 (list (concat "(?" (maude-flk-keyword "search") maude-flk-number-in-square
								 maude-flk-in-module maude-flk-term "\\(=>[!+*1]\\)" "\\(.+?\\)\\s-"
								 maude-flk-such-that-condition maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 font-lock-builtin-face t t) '(4 font-lock-keyword-face t t) '(5 maude-module-name-face t t)
				 '(7 maude-start-face t t) ; =>
 				 '(10 font-lock-keyword-face t t) ; such that
 				 '(12 maude-pattern-face t t)
 				 '(12 maude-end-face t t))
	 (list (concat (maude-flk-keyword "continue\\|cont") "\\([1-9][0-9]\\)*\\s-+" maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 font-lock-builtin-face t t) '(3 maude-end-face t t))
	 (list (concat (maude-flk-keyword "loop") maude-flk-in-module maude-flk-term maude-flk-end-command)
				 '(1 maude-start-face t t) '(3 font-lock-keyword-face t t) '(4 maude-module-name-face t t) '(6 maude-end-face t t))
	 (list (concat (maude-flk-keyword "trace") "\\<\\(select\\|deselect\\|include\\|exclude\\)\\>\\s-+" maude-flk-mod-exp maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 font-lock-keyword-face t t) '(4 maude-end-face t t))
	 (list (concat (maude-flk-keyword "print") "\\<\\(conceal\\|reveal\\)\\>\\s-+" maude-flk-mod-exp maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 font-lock-keyword-face t t) '(4 maude-end-face t t))
	 (list (concat (maude-flk-keyword "break") "\\<\\(select\\|deselect\\)\\>\\s-+" maude-flk-mod-exp maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 font-lock-keyword-face t t) '(4 maude-end-face t t))
	 (list (concat (maude-flk-keyword "show") maude-flk-term maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 default t t) '(3 maude-end-face t t))
	 (list (concat (maude-flk-keyword "show") (maude-flk-keyword "modules") maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 font-lock-keyword-face t t) '(3 maude-end-face t t))
	 (list (concat (maude-flk-keyword "show") (maude-flk-keyword "search\\s-+graph") maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 font-lock-keyword-face t t) '(3 maude-end-face t t))
	 (list (concat (maude-flk-keyword "show") (maude-flk-keyword "path") "\\([1-9][0-9]*\\)\\s-+" maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 font-lock-keyword-face t t) '(3 font-lock-builtin-face t t) '(4 maude-end-face t t))
	 (list (concat (maude-flk-keyword "do") (maude-flk-keyword "clear\\s-+memo") maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 font-lock-keyword-face t t) '(3 maude-end-face t t))
	 (list (concat (maude-flk-keyword "set") (maude-flk-keyword "show\\|print\\|trace\\|include") maude-flk-mod-exp maude-flk-on-off maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 attribute-face t t) '(3 attribute-face t t) '(4 attribute-value-face t t) '(5 maude-end-face t t))
	 (list (concat (maude-flk-keyword "set") (maude-flk-keyword "break") maude-flk-on-off maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 attribute-face t t) '(3 attribute-value-face t t) '(4 maude-end-face t t))
	 ;;; DEBUGGER COMMANDS
	 (list (concat (maude-flk-keyword "resume\\|abort\\|step\\|where") maude-flk-end-command)
				 '(1 maude-start-face t t) '(2 maude-end-face t t))
	 ;;; MODULE
   (list "(?\\(fmod\\|mod\\)\\s-+\\(.+\\)\\s-+\\(is\\)"
				 '(1 maude-start-face prepend t)
 				 '(2 maude-module-name-face prepend t)
 				 '(3 maude-start-face prepend t))
   (list  "\\(endm\\|endfm\\)"
					'(1 maude-start-face prepend t))
 	 (list (concat "\\<\\(\\<protecting\\|extending\\|including\\|ex\\|pr\\|inc\\)\\>\\s-+" maude-flk-mod-exp maude-flk-end)
				 '(1 font-lock-keyword-face append t) '(2 maude-module-name-face prepend t)'(3 maude-end-face))
	 ;;; MODULE * TYPES
	 (list (concat (maude-flk-keyword "sorts?") "\\(\\([a-zA-Z0-9()]+\\s-+\\)+\\)" maude-flk-end) ; The double \\(\\) because font-lock only match once a line
				 '(1 font-lock-keyword-face)
				 '(2 font-lock-type-face prepend t)
				 '(4 maude-end-face prepend t))
 	 ;; subsort.  Havent found good way to do this without colorizing the >s.
	 (list "\\(\\<subsorts?\\>\\)\\s-\\(.+\\)\\(\\.\\)" '(1 font-lock-keyword-face) '(2 element-face prepend t) '(3 maude-end-face prepend t))
	 (list "\\(\\<subsorts?\\>\\)[^<]+\\(<\\).+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 default prepend t) '(3 maude-end-face prepend t))
	 (list "\\(\\<subsorts?\\>\\)[^<]+<[^<]+\\(<\\).+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 default prepend t) '(3 maude-end-face prepend t))
	 (list "\\(\\<subsorts?\\>\\)[^<]+<[^<]+<[^<]+\\(<\\).+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 default prepend t) '(3 maude-end-face prepend t))
	 (list "\\(\\<subsorts?\\>\\)[^<]+<[^<]+<[^<]+<[^<]+\\(<\\).+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 default prepend t) '(3 maude-end-face prepend t))
	 (list "\\(\\<subsorts?\\>\\)[^<]+<[^<]+<[^<]+<[^<]+<[^<]+\\(<\\).+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 default prepend t) '(3 maude-end-face prepend t))
;; Hmm.  Doesnt work
;; 	 (list (concat "\\(subsorts?\\)\\s-+" maude-flk-type-name "\\(\\(<\\)\\s-+" maude-flk-type-name "\\)+" maude-flk-end)
;; 				 '(1 maude-module-name-face t t)
;; 				 '(2 default append append)
;; 				 '(3 element-face prepend t)
;; 				 '(4 definiendum-face append ())
;; 				 '(5 element-face prepend t)
;; 				 '(6 maude-end-face prepend t))
;;  	 ;; subsorts.  Silly way to do this.  Anyone better?
;;  	 (list "\\(\\<subsorts?\\>\\)\\([^<]+\\)\\s-+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 element-face prepend t) '(3 maude-end-face prepend t))
;;  	 (list "\\(\\<subsorts?\\>\\)\\s-+[^<]+<\\([^<]+\\)\\s-+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 element-face prepend t) '(3 maude-end-face prepend t))
;;  	 (list "\\(\\<subsorts?\\>\\)\\s-+[^<]+<[^<]+<\\([^<]+\\)\\s-+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 element-face prepend t) '(3 maude-end-face prepend t))
;;  	 (list "\\(\\<subsorts?\\>\\)\\s-+[^<]+<[^<]+<[^<]+<\\([^<]+\\)\\s-+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 element-face prepend t) '(3 maude-end-face prepend t))
;;  	 (list "\\(\\<subsorts?\\>\\)\\s-+[^<]+<[^<]+<[^<]+<[^<]+<\\([^<]+\\)\\s-+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 element-face prepend t) '(3 maude-end-face prepend t))
;;  	 (list "\\(\\<subsorts?\\>\\)\\s-+[^<]+<[^<]+<[^<]+<[^<]+<[^<]+<\\([^<]+\\)\\s-+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 element-face prepend t) '(3 maude-end-face prepend t))
;;  	 (list "\\(\\<subsorts?\\>\\)\\s-+[^<]+<[^<]+<[^<]+<[^<]+<[^<]+<[^<]+<\\([^<]+\\)\\s-+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 element-face prepend t) '(3 maude-end-face prepend t))
;;  	 (list "\\(\\<subsorts?\\>\\)\\s-+[^<]+<[^<]+<[^<]+<[^<]+<[^<]+<[^<]+<[^<]+<\\([^<]+\\)\\s-+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 element-face prepend t) '(3 maude-end-face prepend t))
;;  	 (list "\\(\\<subsorts?\\>\\)\\s-+[^<]+<[^<]+<[^<]+<[^<]+<[^<]+<[^<]+<[^<]+<[^<]+<\\([^<]+\\)\\s-+\\(\\.\\)" '(1 font-lock-keyword-face) '(2 element-face prepend t) '(3 maude-end-face prepend t))
	 ;; classs    ; could be made more effective?
	 (list "\\<\\(\\<class\\)\\s-+\\(.+\\)|"
				 '(2 font-lock-type-face prepend t))
; 	 ;; subclasss
; 	 (list "\\<\\(subclass\\)\\>\\([^<]+\\)"
; 				 '(2 font-lock-type-face prepend t))
; 	 (list "\\<subclasses\\>\\([^<]+\\)"
; 				 '(2 font-lock-type-face prepend t))
	 ;;; MODULE * OPERATORS
 	 (list (concat (maude-flk-keyword "ops?") "\\(.*\\)\\s-"
 								 "\\(:\\)\\s-+\\(" maude-flk-type-name "\\)*"
								 "\\([-~]>\\)\\s-+" maude-flk-type-name
								 "\\(\\[[^]]*\\]\\s-+\\)?" maude-flk-end)
				 '(1 font-lock-keyword-face prepend t)
				 '(2 font-lock-function-name-face prepend t)
				 '(3 font-lock-keyword-face prepend t) ; :
				 '(6 font-lock-keyword-face prepend t) ; ->
				 '(9 maude-end-face prepend t))
	 ; Attr
	 (list (maude-flk-attribute "assoc\\|associative") '(1 attribute-face prepend t))
	 (list (maude-flk-attribute "comm\\|commutative") '(1 attribute-face prepend t))
	 (list (maude-flk-attribute-colon-value "id" "[^]\n]*")       '(1 attribute-face prepend t) '(2 attribute-face t t))
	 (list (maude-flk-attribute-colon-value "\\(\\<left\\>\\|\\<right\\>\\)\\s-+id" "[^]\n]*") ; Need to be before the other attributes in the elisp code
				 '(1 attribute-face prepend t) '(2 attribute-face prepend t) '(3 attribute-face prepend t))
	 (list (maude-flk-attribute "idem\\|idempotent") '(1 attribute-face prepend t))
	 (list (maude-flk-attribute "iter\\|iterated") '(1 attribute-face prepend t))
	 (list (maude-flk-attribute "memo") '(1 attribute-face prepend t))
	 (list (maude-flk-attribute "ditto") '(1 attribute-face prepend t))
	 (list (maude-flk-attribute-value "poly" "([ 0-9]+)")       '(1 attribute-face prepend t)      '(2 attribute-value-face prepend t))
	 (list (maude-flk-attribute-value "strat\\|strategy" "([ 0-9]+)")       '(1 attribute-face prepend t)      '(2 attribute-value-face prepend t))
	 (list (maude-flk-attribute-value "gather" "([ eE&]+)")       '(1 attribute-face prepend t)      '(2 attribute-value-face prepend t))
	 (list "\\[.*\\(\\<format\\)\\s-+\\(([^)]+)\\).*\\]"     '(1 attribute-face prepend t)        '(2 attribute-value-face prepend t))
	 (list (maude-flk-attribute-value "special" "(.+)")       '(1 attribute-face prepend t)      '(2 attribute-value-face prepend t))
	 ; StatementAttr elsewhere: nonexec, otherwise, metadata, label
	 (list (maude-flk-attribute-value "prec\\|precedence" "[0-9]+")   '(1 attribute-face prepend t)	 '(2 attribute-value-face prepend t))
;; 	 (list "\\[.*\\(\\<id:\\)\\s-+\\(\\w+\\).*\\]"   '(1 attribute-face prepend t)   '(2 attribute-value-face prepend t))
	 (list (maude-flk-attribute "ctor\\|constructor") '(1 element-face prepend t))
	 (list (maude-flk-attribute "frozen") '(1 attribute-face prepend t))
	 (list (maude-flk-attribute-value "frozen" "([ 0-9]+)")       '(1 attribute-face prepend t)      '(2 attribute-value-face prepend t))
	 ;;; MODULE * VARIABLES
	 (list (concat (maude-flk-keyword "vars?") "\\(\\([0-9a-zA-Z@']+\\s-+\\)*\\)"
								 "\\(:\\)\\s-+" maude-flk-type-name maude-flk-end)
				 '(1 font-lock-keyword-face prepend t)
				 '(2 font-lock-variable-name-face prepend t)
				 '(4 font-lock-keyword-face prepend t)
				 '(6 maude-end-face prepend t))
	 ;;; MODULE * MEMBERSHIP
	 (list (concat "\\<\\(mb\\)\\>\\s-+?" maude-flk-label maude-flk-pattern
								 "\\(:\\)\\s-+?" maude-flk-type-name maude-flk-end)
				 '(1 font-lock-keyword-face prepend t) ; mb
				 '(3 maude-label-face prepend t)         ; [label]
				 '(4 font-lock-keyword-face prepend t)         ; :
				 '(5 maude-pattern-face prepend t)
				 '(6 font-lock-keyword-face prepend t) ; :
				 '(7 element-face prepend t)
				 '(8 maude-end-face prepend t))
	 (list (concat "\\<\\(cmb\\)\\>\\s-+?" maude-flk-label maude-flk-pattern
								 "\\(:\\)\\s-+?" maude-flk-type-name
								 "\\(if\\)\\s-+" maude-flk-pattern maude-flk-end)
				 '(1 font-lock-keyword-face prepend t) ;cmb
				 '(3 maude-label-face prepend t)         ; [label]
				 '(4 font-lock-keyword-face prepend t)         ; :
				 '(5 maude-pattern-face prepend t)
				 '(6 font-lock-keyword-face prepend t) ; :
				 '(7 element-face prepend t)
				 '(8 font-lock-keyword-face prepend t) ; if
				 '(9 maude-pattern-face prepend t)
				 '(10 maude-end-face prepend t))
	 ;;; MODULE * EQUATIONS
	 (list (concat "\\(\\<eq\\>\\)\\s-+?" maude-flk-label maude-flk-pattern
								 "\\(=\\)\\s-+" maude-flk-term maude-flk-end)
				 '(1 font-lock-keyword-face prepend t) ; eq
				 '(3 maude-label-face prepend t)         ; [label]
				 '(4 font-lock-keyword-face prepend t)         ; :
				 '(5 maude-pattern-face prepend t)     ; pattern
				 '(6 font-lock-keyword-face prepend t) ; =
				 '(8 maude-end-face prepend t))
	 (list (concat "\\<\\(ceq\\|cq\\)\\>\\s-+?" maude-flk-label maude-flk-pattern
								 "\\(=\\)\\s-+" maude-flk-term
								 "\\(if\\)\\s-+" maude-flk-pattern maude-flk-end)
				 '(1 font-lock-keyword-face prepend t)
				 '(3 maude-label-face prepend t)         ; [label]
				 '(4 font-lock-keyword-face prepend t)         ; :
				 '(5 maude-pattern-face prepend t)
				 '(6 font-lock-keyword-face prepend t) ; =
				 '(8 font-lock-keyword-face prepend t) ; if
				 '(9 maude-pattern-face prepend t)
				 '(10 maude-end-face prepend t))
	 ; Statement Attr (as opposed to attr)
	 (list (maude-flk-attribute "nonexec") '(1 attribute-face prepend t))
	 (list (maude-flk-attribute "owise\\|otherwise") '(1 attribute-face prepend t))
	 (list (maude-flk-attribute-value "metadata" "\\w+")       '(1 attribute-face prepend t)      '(2 attribute-value-face prepend t))
	 (list (maude-flk-attribute-value "label" "\\w+")       '(1 attribute-face prepend t)      '(2 attribute-value-face prepend t))
	 ;;; MODULE * RULES
	 ; rl [rule-name] : pattern => result .
	 (list (concat "\\(\\<rl\\>\\)\\s-+?" maude-flk-label maude-flk-pattern
								 "\\(=>\\)\\s-+" maude-flk-term maude-flk-end)
				 '(1 font-lock-keyword-face prepend t) ; eq
				 '(3 maude-label-face prepend t)         ; [label]
				 '(4 font-lock-keyword-face prepend t)         ; :
				 '(5 maude-pattern-face prepend t)     ; pattern
				 '(6 font-lock-keyword-face prepend t) ; =
				 '(8 maude-end-face prepend t))
	 (list (concat "\\(\\<crl\\>\\)\\s-+?" maude-flk-label maude-flk-pattern
								 "\\(=>\\)\\s-+" maude-flk-term
								 "\\(if\\)\\s-+" maude-flk-pattern maude-flk-end)
				 '(1 font-lock-keyword-face prepend t)
				 '(3 maude-label-face prepend t)         ; [label]
				 '(4 font-lock-keyword-face prepend t)         ; :
				 '(5 maude-pattern-face prepend t)
				 '(6 font-lock-keyword-face prepend t) ; =
				 '(8 font-lock-keyword-face prepend t) ; if
				 '(9 maude-pattern-face prepend t)
				 '(10 maude-end-face prepend t))
	 ;;; END OF CORE MAUDE GRAMMAR
	 ;;; FULL MAUDE
	 ; Don't have the full Maude grammar here, but try to include something
   (list "(\\(omod\\|fth\\|th\\|oth\\) \\(.+\\) \\(is\\)"
				 '(1 maude-start-face prepend t)
 				 '(2 maude-module-name-face prepend t)
 				 '(3 maude-start-face prepend t))
   (list  "\\(endom\\|endfth\\|endth\\|endoth\\|endv\\))"
					'(1 maude-start-face prepend t))
	 (list (concat (maude-flk-keyword "view") "\\(.*\\)\\s-+?"
								 (maude-flk-keyword "from") maude-flk-mod-exp
								 (maude-flk-keyword "to") maude-flk-mod-exp
								 (maude-flk-keyword "is"))
				 '(1 maude-start-face prepend t) ; view
				 '(2 maude-module-name-face prepend t)
				 '(3 maude-start-face prepend t) ; from
				 '(4 maude-module-name-face prepend t)
				 '(5 maude-start-face prepend t) ; to
				 '(6 maude-module-name-face prepend t)
				 '(7 maude-start-face prepend t)) ; is
	 (list (concat (maude-flk-keyword "sort\\|class") maude-flk-type-name
								 (maude-flk-keyword "to") maude-flk-type-name maude-flk-end)
				 '(1 font-lock-keyword-face prepend t) ; sort
				 '(2 font-lock-type-face prepend t) ;
				 '(3 font-lock-keyword-face prepend t) ; to
				 '(4 font-lock-type-face prepend t)
				 '(5 maude-end-face prepend t)) ; .
	 (list (concat (maude-flk-keyword "op\\|msg") maude-flk-term
								 (maude-flk-keyword "to") maude-flk-term maude-flk-end)
				 '(1 font-lock-keyword-face prepend t) ; op
				 '(2 font-lock-function-name-face prepend t) ;
				 '(3 font-lock-keyword-face prepend t) ; to
				 '(4 font-lock-function-name-face prepend t)
				 '(5 maude-end-face prepend t)) ; .
	 (list (concat (maude-flk-keyword "attr") maude-flk-name "\\(\\.\\)\\s-+" maude-flk-type-name
								 (maude-flk-keyword "to") maude-flk-name maude-flk-end)
				 '(1 font-lock-keyword-face prepend t) ; attr
				 '(2 attribute-face prepend t) ;
				 '(3 font-lock-keyword-face prepend t) ; .
				 '(4 font-lock-type-face prepend t)
				 '(5 font-lock-keyword-face prepend t) ; to
				 '(6 attribute-face prepend t)
				 '(7 maude-end-face prepend t)) ; .
	 ;; OTHER STUFF
	 ;; if then else
	 (list (concat (maude-flk-keyword "if") maude-flk-pattern
								 (maude-flk-keyword "then") maude-flk-pattern
								 "\\(" (maude-flk-keyword "else") maude-flk-pattern
								 "\\)?" (maude-flk-keyword "fi"))
				 '(1 font-lock-keyword-face prepend t)
				 '(2 maude-pattern-face prepend t)
				 '(3 font-lock-keyword-face prepend t) ;then
				 '(6 font-lock-keyword-face prepend t) ; else
				 '(8 font-lock-keyword-face prepend t)) ; fi
    ;;; WARNINGS
;    Remove this if it causes too much confusion.  Ellef 2004-06-20
 	 (list maude-warnings '(1 font-lock-warning-face prepend t))
	 (list "\\(\\.\\)\\s-*$" '(1 bold append t)) ;; To be removed
	 (list "\\(\\.\\)\\s-*\\*\\*\\*" '(1 bold append t)) ;; To be removed
; COMMENTS
	 (list "\\(\\*\\{3\\}.*$\\)" '(1 font-lock-comment-face t t))
	 (list "\\((\\*\\{3\\}.*\\*)\\)" '(1 font-lock-comment-face t t))
	 (list "\\((\\*\\{3\\}.*\\)" '(1 font-lock-comment-face t t))     ; Poor-man multiline comments: Just the first and last line
	 (list "\\(.*\\*)\\)" '(1 font-lock-comment-face t t)) ; End of multiline comment
	 (list "\\(\\*\\{4\\}.*\\)" '(1 maude-comment-highlight-face t t)) ; Highlight ****
	 (list "\\(\\*\\{5\\}.*\\)" '(1 maude-comment-highlight-highlight-face t t)) ; Highlight *****
	 (list "\\(\\*\\*\\*\\s-*(\\)" '(1 font-lock-warning-face t t)); Dirty bug in maude 2.1.
; 	 (cons (concat "\\<\\("
; 								 (eval-when-compile
; 									 (regexp-opt '(":" "<" "." "->" "=")))
; 								 "\\)\\>") 'font-lock-keyword-face)
;; 	 (list "\\(\\*\\*\\*.*)\\)"                         ; The famous *** foo ) error in maude
;; 				 '(1 font-lock-warning-face t t))
	 )
  "Subdued level highlighting for Maude mode.")


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;; Automatic indentation
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defun maude-in-comment-p () "Return t if this is in a comment.  Currently handles only monoline comments"
	(interactive)
	(save-excursion
		(let ((answer ()) (decision-made ()))
			(while (not decision-made)
;; 				(message "466 maude-in-comment-p in while")
				(cond ((looking-at "\\*\\*\\*")
							 (setq answer t decision-made t))
							((bolp)
							 (setq answer () decision-made t))
							((<= (point) 2)
							 (setq answer () decision-made t)))
				(forward-char -1))
;			(if answer (message "Yes") (message "No")) ; Debugging
			answer)))

;; (defun indent-line-function () " " (interactive)
;; 	(maude-indent-line))
(defun maude-indent-line ()
  "Indent current line as maude code.  Uses the variable standard-indent."
  (interactive)
	(let ((start-regexp "^\\s-*") (not-indented t) (cur-indent 0))
		(save-excursion
			(beginning-of-line)
			(save-excursion
				;; Go back one char at a time, stopping when not not-indented.
				;; cur-indent is how many steps to indent
				(while not-indented
					(if (and (looking-at "$") (maude-in-comment-p))
							(search-backward "***"))
					(cond
					 ((<= (point) 1) (setq not-indented ()))
					 ((or (looking-at (concat start-regexp "(?[fo]?mod\\>"))
								(looking-at (concat start-regexp "^(")))
						(incf cur-indent standard-indent)
						(setq not-indented ()))
					 ((or (looking-at (concat start-regexp "end")))
						(incf cur-indent 0)
						(setq not-indented ()))
					 ((or (looking-at (concat start-regexp "\\<c?\\(rl\\|eq\\|mb\\)\\>"))
								(looking-at (concat start-regexp "\\<\\(var\\|op\\|sort\\|subsort\\)s?\\>"))
								(looking-at (concat start-regexp "\\<\\(protecting\\|pr\\|extending\\|ex\\|including\\|inc\\)\\>")))
						(incf cur-indent (* 2 standard-indent))
						(setq not-indented ()))
					 ((or (looking-at "\\s(")
								(looking-at "\\<if\\>"))
						(incf cur-indent 2))
					 ((or (looking-at "\\s)")
								(looking-at "\\<fi\\>"))
						(decf cur-indent 2))
					 ((or (looking-at  "\\s-\\.\\s-*?$")
								(looking-at  "\\s-\\.\\s-+\\*\\*\\*"))
						(decf cur-indent standard-indent)))
					(if not-indented (forward-char -1)))); eof save-excursion
			;; 						(message "512 after while")
			;; 						(print cur-indent)
			(save-excursion
				;; 							 (message "513")
				(beginning-of-line)
				;; 							 (message "515")
				(cond 								
				 ((or (looking-at (concat start-regexp "="))
							(looking-at (concat start-regexp "\\<\\(if\\|then\\|else\\|fi\\)\\>"))
							(looking-at (concat start-regexp "to"))) ; Full Maude views
					(incf cur-indent -2))
				 ((or (looking-at (concat start-regexp "\\<c?\\(rl\\|eq\\|mb\\)\\>"))
							(looking-at (concat start-regexp "\\<\\(including\\|extending\\|protecting\\)\\>"))
							(looking-at (concat start-regexp "\\<\\(inc\\|ext\\|pr\\)\\>"))
							(looking-at (concat start-regexp "\\<c?\\(var\\|op\\|sort\\|subsort\\)s?\\>")))
					(setq cur-indent standard-indent))
				 ((or  (looking-at (concat start-regexp "\\<\\(in\\|load\\)\\>"))
							 (looking-at (concat start-regexp "(?\\([fo]?mod\\)\\>"))
;; 							 (looking-at (concat start-regexp "\\<\\(end[fo]?m\\))?\\>"))
							 (looking-at (concat start-regexp "\\<\\(end\\)"))
							 (looking-at (concat start-regexp "(?\\<\\(search\\|red\\|reduce\\|rew\\|rewrite\\|trace\\|x?match\\)")))
					(setq cur-indent 0)))))
;; 			(if (looking-at "^\\s-*$") (insert-string "...."))
;;  			(print cur-indent)
;;  			(insert-string "X") ; See delete-char 1 down
			(indent-line-to (max 0 cur-indent)))
;; 			(delete-char 1) ; Delete the X.  This is so we can indent empty lines
	(cond ((looking-at "^$") ; Ugly hack to fix indent in empty lines.  Doesnt work well between modules.
				 (insert-string (make-string (/ standard-indent 2) ?\t ))))
	(if (looking-at "^\\s-*$") (end-of-line)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;; Abbreviations
;;;;; Turn this on with (abbrev-mode t)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defvar maude-mode-abbrev-table ()
	"Abbrev table for maude mode")

(defun maude-mode-join-attributes () "Join operator/statement attributes.  Turn on with abbrev mode"
	(save-excursion ; remove ][
		(while (re-search-backward "\\] *\\[" (line-beginning-position) t)
			(replace-match " " nil nil)))
	(save-excursion ; Remove [[
		(while (re-search-backward "\\[\\(.*\\)\\[" (line-beginning-position) t)
			(replace-match "[\\1 " nil nil)))
	(save-excursion ; Remove ]]
		(end-of-line) ; re-search-backward only search up to point
		(while (re-search-backward "\\]\\(.*\\)\\]" (line-beginning-position) t)
			(replace-match " \\1]" nil nil)))
	(dotimes (a 3) ; Remove unneccessary double space.  Why is dotimes neessary despite the while?
		(save-excursion
			(while (re-search-backward "\\[\\(.*\\S-?\\)\\s-\\{2,\\}\\(\\S-?.*\\)\\]" (line-beginning-position) t)
				(replace-match "[\\1 \\2]" nil nil))))
	(save-excursion ; Remove [\\s-
		(end-of-line)
		(while (re-search-backward "\\[ +" (line-beginning-position) t)
			(replace-match "[" nil nil)))
	(save-excursion ; Remove \\s-]
		(end-of-line)
		(while (re-search-backward " +\\]" (line-beginning-position) t)
			(replace-match "]" nil nil)))
	(save-excursion ; Fix ]\\s-.
		(end-of-line)
		(re-search-backward "\\(][ \\.]*\\)" (line-beginning-position) t)
		(replace-match "] ."))
	(end-of-line)
	(re-search-backward "\\]\\s-" (line-beginning-position) t)
	(forward-char 1))

(defun maude-mode-place-after (string) "Place cursor after last occurence of string before point"
	(search-backward string (line-beginning-position))
	(forward-char (length string)))
; This doesn't work.  Occurs this is executed before insertion of the space trigging abbrev-mode.
; Doesnt know how to fix this.
;; 	(save-excursion
;; 		(backward-char 1)
;; 		(if (looking-at "\\s-")
;; 				(delete-char 1)
;; 			(message "not deleted"))))


(define-abbrev-table 'maude-mode-abbrev-table
	'(
		; Attr (of operators)
		("ctor" "[ctor]" maude-mode-join-attributes 0)
		("assoc" "[assoc]" maude-mode-join-attributes 0)
		("associative" "[assoc]" maude-mode-join-attributes 0)
		("comm" "[comm]" maude-mode-join-attributes 0)
		("commutative" "[comm]" maude-mode-join-attributes 0)
		("left" "[left id:]" (lambda () (maude-mode-join-attributes) (maude-mode-place-after "id:")) 0)
		("right" "[right id:]" (lambda () (maude-mode-join-attributes) (maude-mode-place-after "id:")) 0)
		("id" "[id:]"  (lambda () (maude-mode-join-attributes) (maude-mode-place-after "id:"))  0)
;; 		("identity" "[id:"  (lambda () (maude-mode-join-attributes) (maude-mode-place-after "id:"))  0)
		("idem" "[idem]" maude-mode-join-attributes 0)
		("iter" "[iter]" maude-mode-join-attributes 0)
		("memo" "[memo]" maude-mode-join-attributes 0)
		("ditto" "[ditto]" maude-mode-join-attributes 0)
		("poly" "[poly]" maude-mode-join-attributes 0)
		("strat" "[strat ()]"  (lambda () (maude-mode-join-attributes) (maude-mode-place-after "strat ("))  0)
		("frozen" "[frozen]" (lambda () (maude-mode-join-attributes) (maude-mode-place-after "frozen"))  0)
		("prec" "[prec]"  (lambda () (maude-mode-join-attributes) (maude-mode-place-after "prec"))  0)
		("gather" "[gather ()]"  (lambda () (maude-mode-join-attributes) (maude-mode-place-after "gather ("))  0)	
		("format" "[format ()]"  (lambda () (maude-mode-join-attributes) (maude-mode-place-after "format ("))  0)
		("special" "[special ()]"  (lambda () (maude-mode-join-attributes) (maude-mode-place-after "special ("))  0)
		; Statement attr (rules, equations and membership axioms)
		("nonexec" "[nonexec]" maude-mode-join-attributes 0)
		("owise" "[owise]" maude-mode-join-attributes 0)
		("otherwise" "[owise]" maude-mode-join-attributes 0)
		("metadata" "[metadata]"  (lambda () (maude-mode-join-attributes) (maude-mode-place-after "metadata"))  0)
		("label" "[label]"  (lambda () (maude-mode-join-attributes) (maude-mode-place-after "label"))  0)
		;-) To impress your friend with fast typing
		("list" "[assoc right id:]"  (lambda () (maude-mode-join-attributes) (maude-mode-place-after "id:"))  0)
		("mset" "[comm assoc id:]"  (lambda () (maude-mode-join-attributes) (maude-mode-place-after "id:")) 0)
		("set" "[comm assoc idem]" maude-mode-join-attributes 0) ; Dangerous with id: here?
		("endm" "endm" (lambda () (save-excursion (indent-line-to 0))))
		("endom" "endom" (lambda () (save-excursion (indent-line-to 0))))
		("endfm" "endfm" (lambda () (save-excursion (indent-line-to 0))))
		("endth" "endth" (lambda () (save-excursion (indent-line-to 0))))
		("endoth" "endoth" (lambda () (save-excursion (indent-line-to 0))))
		("endfth" "endfth" (lambda () (save-excursion (indent-line-to 0))))
		("endv" "endv" (lambda () (save-excursion (indent-line-to 0))))
		("mod" "mod" (lambda () (save-excursion (indent-line-to 0))))
		("fmod" "fmod" (lambda () (save-excursion (indent-line-to 0))))
		("omod" "omod" (lambda () (save-excursion (indent-line-to 0))))
		("view" "view" (lambda () (save-excursion (indent-line-to 0))))
		("th" "th" (lambda () (save-excursion (indent-line-to 0))))
		("fth" "fth" (lambda () (save-excursion (indent-line-to 0))))
		("oth" "oth" (lambda () (save-excursion (indent-line-to 0))))
		))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; Other stuff
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Tell emacs about the code
(defvar maude-mode-syntax-table ()
  "Syntax table for maude-mode")

(defun maude-create-syntax-table ()
  (if maude-mode-syntax-table () ; If there are none previous
    (setq maude-mode-syntax-table (make-syntax-table))
    (set-syntax-table maude-mode-syntax-table)))

; ; -> should be treated like a word)
; (modify-syntax-entry ?- "w" maude-mode-syntax-table))
; Start of comment.  * as a first and second character
; (modify-syntax-entry ?* ". 124b" maude-mode-syntax-table)
; (modify-syntax-entry ?( ". 2" maude-mode-syntax-table)
; (modify-syntax-entry ?) ". 3" maude-mode-syntax-table)
; (modify-syntax-entry ?  ". 4" maude-mode-syntax-table)
; ; End of comment.  Newline.
; (modify-syntax-entry ?\n ">" maude-mode-syntax-table)

; This turns out to do as much bad as good.  Due to Emacs' lack of ability to handle
; more than two letters in comments, it can't handle the *** comment of maude.
; We don't need this either.  Ellef 2003-02-06
; ; Start of comment.  ** (emacs can't handle ***).
; (modify-syntax-entry ?* ". 12" maude-mode-syntax-table)
; ; End of comment.  Newline.
; (modify-syntax-entry ?\n ">" maude-mode-syntax-table)

; The other comment syntax in maude, multiline (*** *), can't be handled
; by Emacs.  However, I have made some colouring.



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defun maude-mode ()
 "Major mode for editing Maude files.
  Provides syntax highlighting.
  \\[maude-indent-line] indents current line.
  \\[run-maude] starts an interactive maude process.
  \\[run-full-maude] starts an interactive full maude process.
  \\[maude-send-paragraph] sends current region to the (full) maude process.
  \\[maude-send-region] sends current paragraph to the (full) maude process.
  \\[maude-send-buffer] and the entire buffer, to the process.
  If you want certain keywords (try operator attributes) to be automatically expanded, put
    (add-hook 'maude-mode-hook
			'(lambda ()
         (abbrev-mode t)))
  in your .emacs .
  If you don't want the red warnings, put
    (add-hook 'maude-mode-hook
         '(lambda ()
            (setq maude-warnings ())))
  in your .emacs .
  The following keys are set:
  \\{maude-mode-map}"
 (interactive)
 (kill-all-local-variables)
 (maude-create-syntax-table)
 (make-local-variable 'font-lock-defaults)
 (setq font-lock-defaults '(maude-font-lock-keywords))
 (make-local-variable 'indent-line-function)
 (setq indent-line-function 'maude-indent-line)
 (setq major-mode 'maude-mode)
 (setq mode-name "Maude")
 (use-local-map maude-mode-map)
 (run-hooks 'maude-mode-hook)
 (make-local-variable 'comment-start)
 (setq comment-start "***")
 (setq local-abbrev-table maude-mode-abbrev-table)
 (message "Some new features in Maude-mode 2004-07-05.  Press C-h m!")
)

(provide 'maude-mode)
