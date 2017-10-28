all: \
	meta/structured-names.maude

# `pd` is a patched version of `pandoc` capable of writing code files
# Download it from 'https://github.com/ehildenb/pandoc'

meta/%.maude: meta.md/%.md
	pd --from markdown --to 'code{.maude}' $< > $@
