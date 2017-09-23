# maude
# =====

# Detection
# ---------

hook global BufSetOption mimetype=text/x-maude %{
    set buffer filetype maude
}

hook global BufCreate .*[.](maude) %{
    set buffer filetype maude
}

# Highlighters
# ------------

addhl -group / regions -default code maude \
    string   '"'     (?<!\\)(\\\\)*"      '' \
    comment ---\(   \)---              ---\( \
    comment  (---) $                      '' \
    macro   ^\h*?\K# (?<!\\)\n            ''

addhl -group /maude/string  fill string
addhl -group /maude/comment fill comment
addhl -group /maude/macro   fill meta

addhl -group /maude/code regex \b(load|quit|in|eof|popd|pwd|ls|cd|parse|reduce|red|rewrite|rew|frewrite|erewrite|xmatch|search)\b 0:meta
addhl -group /maude/code regex \b(mod|endm|fmod|endfm|omod|endom|fth|endfth|th|endth|view|endv)\b 0:keyword
addhl -group /maude/code regex \b(is|protecting|including|extending)\b 0:keyword
addhl -group /maude/code regex \b(sort|sorts|subsort|subsorts|op|ops|var|vars|eq|ceq|rl|crl|md|cmb)\b 0:keyword
addhl -group /scala/code regex \b(assoc|comm|left|right|id|idem|iter|memo|ditto|config|obj|msg|metadata|strat|poly|frozen|prec|gather|format|special|nonexec|otherwise|owise|variant|label|print|id-hook|op-hook|term-hook)\b 0:attribute
addhl -group /maude/code regex \b(QID|CONVERSION|STRING|RAT|FLOAT|COUNTER|INT|RANDOM|NAT|EXT-BOOL|BOOL|TRUTH|BOOL-OPS|TRUTH-VALUE)\b 0:type

# Markdown
# ========

# addhl -group / regions -default content markdown \
#     sh         ```maude   ```                    ''

# Initialization
# ==============

hook global WinSetOption filetype=maude %[
    addhl ref maude
]

hook global WinSetOption filetype=(?!maude).* %{
    rmhl maude
}
