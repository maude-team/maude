all: \
	tools

tools: \
	tools/meta/metalevel-ext.maude \
	tools/meta/structured-names.maude \
	tools/meta/cterms.maude \
	tools/meta/foform.maude \
	tools/meta/mtemplate.maude \
	tools/meta/mtransform.maude \
	tools/meta/unification.maude \
	tools/meta/variables.maude

# `pd` is a patched version of `pandoc` capable of writing code files
# Download it from 'https://github.com/ehildenb/pandoc'

tools/meta/%.maude: tools/meta.md/%.md
	pd --from markdown --to 'code{.maude}' $< > $@
