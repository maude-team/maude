%option c++

stringContent	([^[:cntrl:]"\\]|("\\"[^[:cntrl:]]))
string		("\""{stringContent}*"\"")

positive	([1-9][0-9]*)

sign		([+\-])
frac		("."[0-9]+)
exponent	([eE]{sign}?[0-9]+)
restFloat	(({frac}{exponent}?)|({frac}?{exponent}))
posFloat	({positive}{restFloat})
float		({sign}?("Infinity"|{posFloat}))

%%

{string}\0				return STRING;				
\'[^[:cntrl:]]*\0			return QUOTED_IDENTIFIER;
0\0					return ZERO;
{positive}\0				return SMALL_NAT;
-{positive}\0				return SMALL_NEG;
[^[:cntrl:]]*":"\0			return ENDS_IN_COLON;
[^[:cntrl:]]*":"[^[:cntrl:]]+\0		return CONTAINS_COLON;
[^[:cntrl:]]+"^"{positive}\0		return ITER_SYMBOL;
{float}\0				return FLOAT;
"-"?{positive}"/"{positive}\0		return RATIONAL;

%%
