
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 27 "surface.yy"

#include <string>
#include <stack>

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

//	core class definitions
#include "lineNumber.hh"

//	front end class definitions
#include "token.hh"
#include "renaming.hh"
#include "view.hh"
#include "moduleExpression.hh"
#include "fileTable.hh"
#include "directoryManager.hh"
#include "syntacticPreModule.hh"
#include "visibleModule.hh"  // HACK
#include "userLevelRewritingContext.hh"
#include "interpreter.hh"

#include "global.hh"
#define clear()			tokenSequence.clear();
#define store(token)		tokenSequence.append(token)
#define fragClear()		fragments.contractTo(0);
#define fragStore(token)	fragments.append(token)
#define YYPARSE_PARAM	parseResult
#define PARSE_RESULT	(*((UserLevelRewritingContext::ParseResult*) parseResult))

#define CM		interpreter.getCurrentModule()
#define CV		interpreter.getCurrentView()

#include "lexerAux.hh"
/*
void lexerInitialMode();
void lexerIdMode();
void lexerCmdMode();
void lexerFileNameMode();
void lexerStringMode();
void lexerLatexMode();
bool handleEof();
bool includeFile(const string& directory, const string& fileName, bool silent, int lineNr);
//void eatComment(bool firstNonWhite);
*/
Vector<Token> singleton(1);
Vector<Token> tokenSequence;
Vector<Token> lexerBubble;
Vector<Token> fragments;
Vector<Token> moduleExpr;
Vector<Token> opDescription;
stack<ModuleExpression*> moduleExpressions;
Renaming* currentRenaming = 0;
SyntaxContainer* currentSyntaxContainer = 0;
SyntaxContainer* oldSyntaxContainer = 0;

Int64 number;
Int64 number2;

static void yyerror(char *s);

void cleanUpModuleExpression();
void cleanUpParser();
void missingSpace(const Token& token);


/* Line 189 of yacc.c  */
#line 148 "surface.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FILE_NAME_STRING = 258,
     UNINTERPRETED_STRING = 259,
     LATEX_STRING = 260,
     KW_MOD = 261,
     KW_OMOD = 262,
     KW_VIEW = 263,
     KW_PARSE = 264,
     KW_NORMALIZE = 265,
     KW_REDUCE = 266,
     KW_REWRITE = 267,
     KW_LOOP = 268,
     KW_NARROW = 269,
     KW_XG_NARROW = 270,
     KW_MATCH = 271,
     KW_XMATCH = 272,
     KW_UNIFY = 273,
     KW_GET = 274,
     KW_VARIANTS = 275,
     KW_VARIANT = 276,
     KW_EREWRITE = 277,
     KW_FREWRITE = 278,
     KW_SREWRITE = 279,
     KW_CONTINUE = 280,
     KW_SEARCH = 281,
     KW_SET = 282,
     KW_SHOW = 283,
     KW_ON = 284,
     KW_OFF = 285,
     KW_TRACE = 286,
     KW_BODY = 287,
     KW_BUILTIN = 288,
     KW_WHOLE = 289,
     KW_SELECT = 290,
     KW_DESELECT = 291,
     KW_CONDITION = 292,
     KW_SUBSTITUTION = 293,
     KW_PRINT = 294,
     KW_GRAPH = 295,
     KW_MIXFIX = 296,
     KW_FLAT = 297,
     KW_ATTRIBUTE = 298,
     KW_NEWLINE = 299,
     KW_WITH = 300,
     KW_PARENS = 301,
     KW_ALIASES = 302,
     KW_GC = 303,
     KW_TIME = 304,
     KW_STATS = 305,
     KW_TIMING = 306,
     KW_CMD = 307,
     KW_BREAKDOWN = 308,
     KW_BREAK = 309,
     KW_PATH = 310,
     KW_MODULE = 311,
     KW_MODULES = 312,
     KW_VIEWS = 313,
     KW_ALL = 314,
     KW_SORTS = 315,
     KW_OPS2 = 316,
     KW_VARS = 317,
     KW_MBS = 318,
     KW_EQS = 319,
     KW_RLS = 320,
     KW_SUMMARY = 321,
     KW_KINDS = 322,
     KW_ADVISE = 323,
     KW_VERBOSE = 324,
     KW_DO = 325,
     KW_CLEAR = 326,
     KW_PROTECT = 327,
     KW_EXTEND = 328,
     KW_INCLUDE = 329,
     KW_EXCLUDE = 330,
     KW_CONCEAL = 331,
     KW_REVEAL = 332,
     KW_COMPILE = 333,
     KW_COUNT = 334,
     KW_DEBUG = 335,
     KW_RESUME = 336,
     KW_ABORT = 337,
     KW_STEP = 338,
     KW_WHERE = 339,
     KW_CREDUCE = 340,
     KW_SREDUCE = 341,
     KW_DUMP = 342,
     KW_PROFILE = 343,
     KW_NUMBER = 344,
     KW_RAT = 345,
     KW_COLOR = 346,
     SIMPLE_NUMBER = 347,
     KW_PWD = 348,
     KW_CD = 349,
     KW_PUSHD = 350,
     KW_POPD = 351,
     KW_LS = 352,
     KW_LOAD = 353,
     KW_QUIT = 354,
     KW_EOF = 355,
     KW_ENDM = 356,
     KW_IMPORT = 357,
     KW_ENDV = 358,
     KW_SORT = 359,
     KW_SUBSORT = 360,
     KW_OP = 361,
     KW_OPS = 362,
     KW_MSGS = 363,
     KW_VAR = 364,
     KW_CLASS = 365,
     KW_SUBCLASS = 366,
     KW_MB = 367,
     KW_CMB = 368,
     KW_EQ = 369,
     KW_CEQ = 370,
     KW_RL = 371,
     KW_CRL = 372,
     KW_IS = 373,
     KW_FROM = 374,
     KW_ARROW = 375,
     KW_ARROW2 = 376,
     KW_PARTIAL = 377,
     KW_IF = 378,
     KW_LABEL = 379,
     KW_TO = 380,
     KW_COLON2 = 381,
     KW_ASSOC = 382,
     KW_COMM = 383,
     KW_ID = 384,
     KW_IDEM = 385,
     KW_ITER = 386,
     KW_LEFT = 387,
     KW_RIGHT = 388,
     KW_PREC = 389,
     KW_GATHER = 390,
     KW_METADATA = 391,
     KW_STRAT = 392,
     KW_POLY = 393,
     KW_MEMO = 394,
     KW_FROZEN = 395,
     KW_CTOR = 396,
     KW_LATEX = 397,
     KW_SPECIAL = 398,
     KW_CONFIG = 399,
     KW_OBJ = 400,
     KW_MSG = 401,
     KW_DITTO = 402,
     KW_FORMAT = 403,
     KW_ID_HOOK = 404,
     KW_OP_HOOK = 405,
     KW_TERM_HOOK = 406,
     KW_IN = 407,
     IDENTIFIER = 408,
     NUMERIC_ID = 409,
     ENDS_IN_DOT = 410,
     FORCE_LOOKAHEAD = 411
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 103 "surface.yy"

  bool yyBool;
  Int64 yyInt64;
  const char* yyString;
  Token yyToken;
  ImportModule::ImportMode yyImportMode;
  Interpreter::Flags yyFlags;
  Interpreter::PrintFlags yyPrintFlags;
  Interpreter::SearchKind yySearchKind;



/* Line 214 of yacc.c  */
#line 353 "surface.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 114 "surface.yy"

int yylex(YYSTYPE* lvalp);


/* Line 264 of yacc.c  */
#line 370 "surface.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  111
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2359

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  243
/* YYNRULES -- Number of rules.  */
#define YYNRULES  613
/* YYNRULES -- Number of states.  */
#define YYNSTATES  919

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   411

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     126,   127,   138,   137,   132,     2,   128,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   124,     2,
     129,   125,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   130,     2,   131,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   139,   133,   140,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   134,
     135,   136,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    12,    14,    15,
      19,    20,    24,    26,    27,    31,    32,    36,    38,    39,
      43,    45,    47,    50,    53,    56,    59,    62,    66,    68,
      70,    74,    76,    78,    80,    82,    84,    88,    89,    95,
      99,   103,   105,   106,   107,   113,   115,   117,   121,   123,
     128,   133,   134,   135,   142,   143,   149,   150,   151,   156,
     157,   160,   162,   165,   166,   172,   173,   179,   180,   186,
     187,   188,   189,   202,   205,   206,   208,   209,   214,   220,
     221,   225,   228,   231,   233,   234,   235,   244,   245,   249,
     251,   253,   254,   258,   259,   260,   269,   271,   273,   277,
     278,   282,   284,   288,   290,   292,   294,   297,   299,   301,
     303,   306,   307,   310,   311,   316,   317,   322,   323,   324,
     330,   335,   341,   342,   343,   349,   350,   351,   352,   360,
     361,   362,   368,   369,   370,   371,   379,   380,   381,   387,
     388,   389,   390,   398,   399,   400,   406,   411,   412,   418,
     419,   424,   427,   429,   432,   434,   438,   442,   445,   447,
     450,   452,   454,   456,   460,   462,   464,   466,   467,   470,
     472,   474,   477,   481,   483,   485,   487,   490,   491,   493,
     494,   499,   503,   505,   509,   510,   513,   515,   517,   520,
     523,   525,   527,   528,   532,   534,   536,   539,   540,   546,
     547,   553,   554,   560,   561,   567,   569,   571,   573,   574,
     580,   582,   584,   586,   589,   590,   596,   601,   603,   605,
     606,   609,   611,   614,   616,   619,   623,   627,   631,   633,
     634,   636,   637,   640,   641,   644,   647,   648,   653,   655,
     657,   658,   664,   665,   670,   672,   674,   676,   678,   680,
     682,   684,   686,   688,   690,   692,   694,   696,   698,   700,
     702,   704,   706,   708,   710,   712,   714,   716,   718,   720,
     722,   724,   726,   728,   730,   732,   734,   736,   738,   740,
     742,   744,   746,   748,   750,   752,   754,   756,   758,   760,
     762,   764,   766,   768,   770,   772,   774,   776,   778,   780,
     782,   784,   786,   788,   790,   792,   794,   796,   798,   800,
     802,   804,   806,   808,   810,   812,   814,   816,   818,   820,
     822,   824,   826,   828,   830,   832,   834,   836,   838,   840,
     842,   844,   846,   848,   850,   852,   854,   856,   858,   860,
     862,   864,   866,   868,   870,   872,   874,   876,   877,   881,
     882,   886,   887,   891,   892,   896,   897,   901,   902,   907,
     908,   913,   914,   919,   920,   925,   926,   931,   932,   936,
     937,   941,   942,   946,   947,   953,   954,   960,   965,   966,
     970,   972,   973,   978,   979,   984,   985,   990,   991,   996,
    1001,  1002,  1007,  1008,  1013,  1014,  1019,  1020,  1025,  1029,
    1033,  1034,  1039,  1040,  1045,  1046,  1051,  1052,  1057,  1058,
    1063,  1064,  1069,  1070,  1075,  1076,  1081,  1086,  1092,  1097,
    1098,  1103,  1109,  1115,  1122,  1128,  1134,  1141,  1147,  1153,
    1159,  1165,  1172,  1178,  1183,  1184,  1185,  1193,  1194,  1195,
    1204,  1209,  1215,  1221,  1227,  1232,  1238,  1241,  1244,  1247,
    1250,  1256,  1261,  1262,  1266,  1268,  1270,  1273,  1276,  1278,
    1280,  1282,  1284,  1286,  1288,  1289,  1291,  1293,  1295,  1297,
    1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,
    1319,  1321,  1323,  1325,  1327,  1329,  1331,  1333,  1335,  1337,
    1338,  1340,  1341,  1343,  1345,  1347,  1349,  1350,  1354,  1355,
    1359,  1361,  1362,  1366,  1368,  1369,  1373,  1374,  1378,  1379,
    1383,  1385,  1386,  1390,  1391,  1395,  1397,  1398,  1402,  1404,
    1405,  1409,  1410,  1414,  1415,  1419,  1420,  1424,  1426,  1427,
    1431,  1432,  1436,  1437,  1441,  1443,  1444,  1448,  1449,  1453,
    1455,  1456,  1460,  1461,  1465,  1467,  1468,  1472,  1473,  1477,
    1479,  1480,  1484,  1485,  1489,  1491,  1492,  1496,  1498,  1499,
    1503,  1504,  1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,
    1524,  1526,  1528,  1530,  1532,  1534,  1536,  1538,  1540,  1542,
    1544,  1546,  1548,  1550,  1552,  1554,  1556,  1558,  1560,  1562,
    1564,  1566,  1568,  1570,  1572,  1574,  1576,  1578,  1580,  1583,
    1585,  1587,  1589,  1591,  1594,  1596,  1598,  1600,  1602,  1604,
    1606,  1608,  1610,  1612
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     172,     0,    -1,   173,    -1,    -1,   222,    -1,   206,    -1,
     174,    -1,   311,    -1,    -1,   166,   175,     3,    -1,    -1,
      98,   176,     3,    -1,    93,    -1,    -1,    94,   177,     3,
      -1,    -1,    95,   178,     3,    -1,    96,    -1,    -1,    97,
     179,     4,    -1,    99,    -1,   100,    -1,   300,   290,    -1,
     303,   128,    -1,   187,   290,    -1,   184,   290,    -1,   185,
     290,    -1,   181,   137,   180,    -1,   169,    -1,   182,    -1,
     181,   137,   181,    -1,   183,    -1,   184,    -1,   187,    -1,
     185,    -1,   299,    -1,   182,   138,   189,    -1,    -1,   183,
     139,   186,   188,   140,    -1,   126,   181,   127,    -1,   188,
     132,   299,    -1,   299,    -1,    -1,    -1,   126,   190,   192,
     191,   127,    -1,   193,    -1,     1,    -1,   193,   132,   194,
      -1,   194,    -1,   104,   294,   135,   294,    -1,   134,   299,
     135,   299,    -1,    -1,    -1,   106,   195,   197,   135,   196,
     199,    -1,    -1,   124,   198,   270,   269,   271,    -1,    -1,
      -1,   130,   200,   201,   131,    -1,    -1,   201,   202,    -1,
     202,    -1,   148,   167,    -1,    -1,   149,   126,   203,   286,
     127,    -1,    -1,   162,   126,   204,   286,   127,    -1,    -1,
     156,   126,   205,     5,   127,    -1,    -1,    -1,    -1,     8,
     207,   299,   119,   181,   208,   135,   181,   209,   289,   210,
     103,    -1,   210,   212,    -1,    -1,   120,    -1,    -1,   104,
     294,   135,   214,    -1,   109,   261,   124,   211,   231,    -1,
      -1,   106,   213,   215,    -1,     1,   128,    -1,   294,   290,
      -1,   169,    -1,    -1,    -1,   124,   216,   270,   269,   271,
     135,   217,   219,    -1,    -1,   135,   218,   219,    -1,   128,
      -1,   169,    -1,    -1,   126,   221,   127,    -1,    -1,    -1,
     232,   223,   299,   224,   226,   289,   233,   101,    -1,   128,
      -1,   169,    -1,   139,   227,   140,    -1,    -1,   227,   132,
     228,    -1,   228,    -1,   299,   229,   181,    -1,   136,    -1,
     124,    -1,   169,    -1,   271,   290,    -1,   230,    -1,     6,
      -1,     7,    -1,   233,   234,    -1,    -1,   102,   180,    -1,
      -1,   104,   235,   291,   225,    -1,    -1,   105,   236,   292,
     225,    -1,    -1,    -1,   106,   237,   124,   238,   264,    -1,
     107,   262,   124,   264,    -1,   109,   261,   124,   211,   231,
      -1,    -1,    -1,   112,   239,   124,   240,   219,    -1,    -1,
      -1,    -1,   113,   241,   124,   242,   123,   243,   219,    -1,
      -1,    -1,   114,   244,   125,   245,   219,    -1,    -1,    -1,
      -1,   115,   246,   125,   247,   123,   248,   219,    -1,    -1,
      -1,   116,   249,   121,   250,   219,    -1,    -1,    -1,    -1,
     117,   251,   121,   252,   123,   253,   219,    -1,    -1,    -1,
     160,   254,   124,   255,   264,    -1,   108,   262,   124,   264,
      -1,    -1,   110,   299,   256,   258,   128,    -1,    -1,   111,
     257,   292,   225,    -1,     1,   128,    -1,   133,    -1,   133,
     259,    -1,   260,    -1,   259,   132,   260,    -1,   300,   124,
     299,    -1,   261,   301,    -1,   301,    -1,   262,   263,    -1,
     263,    -1,   301,    -1,   220,    -1,   271,   270,   266,    -1,
     267,    -1,   230,    -1,   124,    -1,    -1,   265,   267,    -1,
     128,    -1,   230,    -1,   269,   268,    -1,   271,   274,   290,
      -1,   230,    -1,   120,    -1,   122,    -1,   270,   271,    -1,
      -1,   294,    -1,    -1,   130,   272,   273,   131,    -1,   273,
     132,   294,    -1,   294,    -1,   130,   275,   131,    -1,    -1,
     275,   277,    -1,   277,    -1,   143,    -1,   146,   143,    -1,
     147,   143,    -1,   141,    -1,   142,    -1,    -1,   276,   278,
     285,    -1,   144,    -1,   145,    -1,   148,   167,    -1,    -1,
     149,   126,   279,   286,   127,    -1,    -1,   162,   126,   280,
     286,   127,    -1,    -1,   151,   126,   281,   286,   127,    -1,
      -1,   152,   126,   282,   286,   127,    -1,   153,    -1,   155,
      -1,   154,    -1,    -1,   154,   126,   283,   286,   127,    -1,
     158,    -1,   159,    -1,   160,    -1,   150,   167,    -1,    -1,
     156,   126,   284,     5,   127,    -1,   157,   126,   287,   127,
      -1,   161,    -1,   170,    -1,    -1,   286,   167,    -1,   167,
      -1,   287,   288,    -1,   288,    -1,   163,   299,    -1,   163,
     299,   220,    -1,   164,   299,   220,    -1,   165,   299,   220,
      -1,   118,    -1,    -1,   128,    -1,    -1,   291,   294,    -1,
      -1,   292,   294,    -1,   292,   129,    -1,    -1,   294,   293,
     291,   129,    -1,   295,    -1,   302,    -1,    -1,   295,   139,
     296,   297,   140,    -1,    -1,   297,   132,   298,   295,    -1,
     295,    -1,   305,    -1,   306,    -1,   308,    -1,   309,    -1,
     128,    -1,   304,    -1,   132,    -1,   135,    -1,   306,    -1,
     308,    -1,   309,    -1,   305,    -1,   306,    -1,   309,    -1,
     128,    -1,   129,    -1,   120,    -1,   122,    -1,   125,    -1,
     121,    -1,   123,    -1,   167,    -1,   306,    -1,   310,    -1,
     125,    -1,   133,    -1,   137,    -1,   138,    -1,   121,    -1,
     123,    -1,   118,    -1,   134,    -1,   135,    -1,   128,    -1,
     169,    -1,   167,    -1,   139,    -1,   140,    -1,   137,    -1,
     138,    -1,   133,    -1,   136,    -1,   134,    -1,   119,    -1,
     118,    -1,   304,    -1,   169,    -1,   132,    -1,   135,    -1,
     160,    -1,   307,    -1,   102,    -1,   104,    -1,   105,    -1,
     106,    -1,   107,    -1,   109,    -1,   108,    -1,   110,    -1,
     111,    -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,
     116,    -1,   117,    -1,   101,    -1,   103,    -1,   129,    -1,
     124,    -1,   120,    -1,   122,    -1,   125,    -1,   121,    -1,
     123,    -1,   130,    -1,   131,    -1,   310,    -1,   141,    -1,
     142,    -1,   143,    -1,   144,    -1,   145,    -1,   146,    -1,
     147,    -1,   148,    -1,   149,    -1,   151,    -1,   152,    -1,
     153,    -1,   155,    -1,   156,    -1,   157,    -1,   154,    -1,
     150,    -1,   158,    -1,   159,    -1,   161,    -1,   162,    -1,
     163,    -1,   164,    -1,   165,    -1,    -1,    35,   312,   219,
      -1,    -1,    87,   313,   219,    -1,    -1,     9,   314,   361,
      -1,    -1,    85,   315,   361,    -1,    -1,    86,   316,   361,
      -1,    -1,   358,    11,   317,   361,    -1,    -1,   358,    12,
     318,   365,    -1,    -1,   358,    22,   319,   374,    -1,    -1,
     358,    23,   320,   374,    -1,    -1,   358,    24,   321,   365,
      -1,    -1,   356,   322,   374,    -1,    -1,   357,   323,   365,
      -1,    -1,    18,   324,   365,    -1,    -1,   358,    21,    18,
     325,   365,    -1,    -1,   358,    19,    20,   326,   365,    -1,
     358,    25,   359,   128,    -1,    -1,    13,   327,   361,    -1,
     220,    -1,    -1,    31,   353,   328,   408,    -1,    -1,    31,
     354,   329,   408,    -1,    -1,    54,   353,   330,   408,    -1,
      -1,    39,   355,   331,   408,    -1,    70,    71,   153,   128,
      -1,    -1,    28,     6,   332,   219,    -1,    -1,    28,    56,
     333,   219,    -1,    -1,    28,    59,   334,   219,    -1,    -1,
      28,     8,   335,   219,    -1,    28,    57,   128,    -1,    28,
      58,   128,    -1,    -1,    28,    60,   336,   219,    -1,    -1,
      28,    61,   337,   219,    -1,    -1,    28,    62,   338,   219,
      -1,    -1,    28,    63,   339,   219,    -1,    -1,    28,    64,
     340,   219,    -1,    -1,    28,    65,   341,   219,    -1,    -1,
      28,    66,   342,   219,    -1,    -1,    28,    67,   343,   219,
      -1,    28,    55,    92,   128,    -1,    28,    55,   134,    92,
     128,    -1,    28,    26,    40,   128,    -1,    -1,    28,    88,
     344,   219,    -1,    27,    28,    68,   352,   128,    -1,    27,
      28,    50,   352,   128,    -1,    27,    28,    13,    50,   352,
     128,    -1,    27,    28,    51,   352,   128,    -1,    27,    28,
      53,   352,   128,    -1,    27,    28,    13,    51,   352,   128,
      -1,    27,    28,    52,   352,   128,    -1,    27,    28,    48,
     352,   128,    -1,    27,    39,   350,   352,   128,    -1,    27,
      39,    43,   352,   128,    -1,    27,    39,    43,    44,   352,
     128,    -1,    27,    31,   351,   352,   128,    -1,    27,    54,
     352,   128,    -1,    -1,    -1,    27,   360,   345,   413,   346,
     352,   128,    -1,    -1,    -1,    27,     7,    74,   347,   413,
     348,   352,   128,    -1,    27,    69,   352,   128,    -1,    27,
      71,   153,   352,   128,    -1,    27,    71,    65,   352,   128,
      -1,    27,    78,    79,   352,   128,    -1,    27,    88,   352,
     128,    -1,    27,    71,    88,   352,   128,    -1,    81,   128,
      -1,    82,   128,    -1,    83,   128,    -1,    84,   128,    -1,
      27,    48,    28,   352,   128,    -1,    27,    50,   352,   128,
      -1,    -1,     1,   349,   128,    -1,    41,    -1,    42,    -1,
      45,    47,    -1,    45,    46,    -1,    40,    -1,    76,    -1,
      89,    -1,    90,    -1,    91,    -1,   162,    -1,    -1,    37,
      -1,    34,    -1,    38,    -1,    35,    -1,    63,    -1,    64,
      -1,    65,    -1,    12,    -1,    32,    -1,    33,    -1,    29,
      -1,    30,    -1,    35,    -1,    36,    -1,    75,    -1,    74,
      -1,    76,    -1,    77,    -1,    14,    -1,    15,    -1,    26,
      -1,    17,    -1,    16,    -1,    80,    -1,    -1,    92,    -1,
      -1,    72,    -1,    73,    -1,    74,    -1,   399,    -1,    -1,
     402,   362,   219,    -1,    -1,   124,   364,   219,    -1,   219,
      -1,    -1,   130,   366,   368,    -1,   399,    -1,    -1,   403,
     367,   219,    -1,    -1,   168,   369,   371,    -1,    -1,   404,
     370,   219,    -1,   397,    -1,    -1,   131,   372,   361,    -1,
      -1,   405,   373,   219,    -1,   397,    -1,    -1,   130,   375,
     377,    -1,   399,    -1,    -1,   403,   376,   219,    -1,    -1,
     168,   378,   381,    -1,    -1,   132,   379,   391,    -1,    -1,
     406,   380,   219,    -1,   397,    -1,    -1,   131,   382,   361,
      -1,    -1,   132,   383,   385,    -1,    -1,   407,   384,   219,
      -1,   397,    -1,    -1,   168,   386,   388,    -1,    -1,   404,
     387,   219,    -1,   397,    -1,    -1,   131,   389,   361,    -1,
      -1,   405,   390,   219,    -1,   397,    -1,    -1,   168,   392,
     394,    -1,    -1,   404,   393,   219,    -1,   397,    -1,    -1,
     131,   395,   361,    -1,    -1,   405,   396,   219,    -1,   397,
      -1,    -1,   126,   398,   219,    -1,   219,    -1,    -1,   126,
     400,   219,    -1,    -1,   166,   401,   363,    -1,   169,    -1,
     167,    -1,   168,    -1,   130,    -1,   131,    -1,   124,    -1,
     128,    -1,   132,    -1,   167,    -1,   168,    -1,   131,    -1,
     124,    -1,   128,    -1,   132,    -1,   167,    -1,   130,    -1,
     131,    -1,   166,    -1,   124,    -1,   132,    -1,   167,    -1,
     168,    -1,   130,    -1,   166,    -1,   124,    -1,   132,    -1,
     167,    -1,   130,    -1,   131,    -1,   166,    -1,   124,    -1,
     167,    -1,   168,    -1,   130,    -1,   166,    -1,   124,    -1,
     411,   409,    -1,   410,    -1,   128,    -1,   410,    -1,   169,
      -1,   411,   412,    -1,   412,    -1,   413,    -1,   220,    -1,
     167,    -1,   168,    -1,   130,    -1,   131,    -1,   166,    -1,
     124,    -1,   132,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   233,   233,   235,   240,   241,   242,   243,   249,   249,
     259,   259,   269,   273,   273,   284,   284,   295,   306,   306,
     311,   316,   349,   353,   357,   358,   359,   360,   368,   377,
     378,   388,   389,   392,   393,   394,   401,   410,   410,   419,
     422,   423,   430,   435,   429,   441,   442,   445,   446,   449,
     453,   457,   458,   457,   464,   464,   466,   472,   472,   474,
     477,   478,   481,   482,   482,   484,   484,   486,   486,   493,
     495,   503,   493,   516,   517,   520,   525,   528,   532,   533,
     533,   535,   538,   539,   549,   557,   548,   566,   565,   598,
     599,   608,   608,   615,   617,   615,   630,   631,   640,   641,
     644,   645,   648,   656,   657,   665,   674,   675,   678,   678,
     681,   682,   685,   692,   692,   695,   695,   698,   699,   698,
     702,   704,   706,   707,   706,   710,   711,   712,   710,   715,
     716,   715,   719,   720,   721,   719,   724,   725,   724,   728,
     729,   730,   728,   733,   734,   733,   737,   743,   742,   749,
     749,   752,   763,   764,   767,   768,   771,   776,   777,   780,
     781,   784,   785,   788,   789,   790,   797,   803,   806,   807,
     812,   819,   826,   827,   830,   831,   834,   835,   838,   843,
     843,   850,   851,   854,   855,   858,   859,   862,   866,   870,
     876,   880,   884,   884,   886,   890,   894,   895,   895,   897,
     897,   899,   899,   901,   901,   903,   907,   911,   916,   916,
     918,   922,   926,   930,   934,   934,   936,   937,   947,   948,
     951,   952,   955,   956,   959,   960,   961,   962,   968,   970,
     976,   978,   986,   987,   990,   991,   992,   992,   999,  1011,
    1012,  1012,  1016,  1016,  1018,  1024,  1024,  1024,  1024,  1024,
    1027,  1027,  1027,  1028,  1028,  1028,  1031,  1031,  1031,  1031,
    1032,  1032,  1032,  1032,  1032,  1032,  1035,  1035,  1035,  1036,
    1036,  1036,  1036,  1037,  1037,  1037,  1037,  1037,  1040,  1040,
    1046,  1046,  1046,  1046,  1046,  1046,  1046,  1046,  1047,  1047,
    1050,  1050,  1050,  1050,  1053,  1053,  1056,  1056,  1056,  1056,
    1056,  1056,  1057,  1057,  1057,  1058,  1058,  1058,  1058,  1058,
    1058,  1058,  1058,  1061,  1061,  1061,  1061,  1061,  1061,  1061,
    1064,  1064,  1064,  1067,  1067,  1067,  1067,  1067,  1067,  1067,
    1068,  1068,  1068,  1068,  1068,  1068,  1069,  1069,  1069,  1069,
    1070,  1070,  1070,  1070,  1071,  1071,  1071,  1098,  1098,  1103,
    1103,  1110,  1109,  1122,  1121,  1134,  1133,  1146,  1145,  1158,
    1157,  1170,  1169,  1183,  1182,  1196,  1195,  1208,  1207,  1221,
    1220,  1233,  1232,  1245,  1244,  1258,  1257,  1269,  1274,  1273,
    1284,  1290,  1290,  1296,  1296,  1302,  1302,  1308,  1308,  1314,
    1322,  1322,  1328,  1328,  1334,  1334,  1340,  1340,  1346,  1350,
    1354,  1354,  1360,  1360,  1366,  1366,  1372,  1372,  1378,  1378,
    1384,  1384,  1390,  1390,  1396,  1396,  1402,  1406,  1410,  1414,
    1414,  1423,  1427,  1431,  1435,  1439,  1443,  1447,  1451,  1455,
    1459,  1463,  1467,  1471,  1475,  1476,  1475,  1481,  1482,  1481,
    1487,  1491,  1495,  1499,  1503,  1507,  1514,  1518,  1522,  1526,
    1533,  1537,  1544,  1544,  1551,  1552,  1553,  1554,  1555,  1556,
    1557,  1558,  1559,  1560,  1563,  1564,  1565,  1566,  1567,  1568,
    1569,  1570,  1571,  1572,  1573,  1576,  1577,  1580,  1581,  1584,
    1585,  1588,  1589,  1594,  1595,  1596,  1599,  1600,  1603,  1604,
    1607,  1608,  1611,  1612,  1613,  1622,  1623,  1623,  1627,  1627,
    1629,  1639,  1639,  1641,  1642,  1642,  1647,  1647,  1649,  1649,
    1651,  1655,  1655,  1657,  1657,  1659,  1672,  1672,  1674,  1675,
    1675,  1684,  1684,  1686,  1686,  1688,  1688,  1690,  1698,  1698,
    1700,  1700,  1702,  1702,  1704,  1712,  1712,  1714,  1714,  1716,
    1725,  1724,  1731,  1731,  1733,  1741,  1741,  1743,  1743,  1745,
    1753,  1753,  1755,  1755,  1757,  1760,  1760,  1762,  1766,  1766,
    1768,  1768,  1770,  1781,  1781,  1781,  1781,  1781,  1781,  1781,
    1784,  1784,  1784,  1784,  1784,  1784,  1788,  1788,  1788,  1788,
    1788,  1788,  1792,  1792,  1792,  1792,  1792,  1792,  1796,  1796,
    1796,  1796,  1796,  1800,  1800,  1800,  1800,  1800,  1806,  1807,
    1810,  1811,  1814,  1821,  1822,  1825,  1830,  1837,  1837,  1837,
    1837,  1837,  1837,  1837
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FILE_NAME_STRING",
  "UNINTERPRETED_STRING", "LATEX_STRING", "KW_MOD", "KW_OMOD", "KW_VIEW",
  "KW_PARSE", "KW_NORMALIZE", "KW_REDUCE", "KW_REWRITE", "KW_LOOP",
  "KW_NARROW", "KW_XG_NARROW", "KW_MATCH", "KW_XMATCH", "KW_UNIFY",
  "KW_GET", "KW_VARIANTS", "KW_VARIANT", "KW_EREWRITE", "KW_FREWRITE",
  "KW_SREWRITE", "KW_CONTINUE", "KW_SEARCH", "KW_SET", "KW_SHOW", "KW_ON",
  "KW_OFF", "KW_TRACE", "KW_BODY", "KW_BUILTIN", "KW_WHOLE", "KW_SELECT",
  "KW_DESELECT", "KW_CONDITION", "KW_SUBSTITUTION", "KW_PRINT", "KW_GRAPH",
  "KW_MIXFIX", "KW_FLAT", "KW_ATTRIBUTE", "KW_NEWLINE", "KW_WITH",
  "KW_PARENS", "KW_ALIASES", "KW_GC", "KW_TIME", "KW_STATS", "KW_TIMING",
  "KW_CMD", "KW_BREAKDOWN", "KW_BREAK", "KW_PATH", "KW_MODULE",
  "KW_MODULES", "KW_VIEWS", "KW_ALL", "KW_SORTS", "KW_OPS2", "KW_VARS",
  "KW_MBS", "KW_EQS", "KW_RLS", "KW_SUMMARY", "KW_KINDS", "KW_ADVISE",
  "KW_VERBOSE", "KW_DO", "KW_CLEAR", "KW_PROTECT", "KW_EXTEND",
  "KW_INCLUDE", "KW_EXCLUDE", "KW_CONCEAL", "KW_REVEAL", "KW_COMPILE",
  "KW_COUNT", "KW_DEBUG", "KW_RESUME", "KW_ABORT", "KW_STEP", "KW_WHERE",
  "KW_CREDUCE", "KW_SREDUCE", "KW_DUMP", "KW_PROFILE", "KW_NUMBER",
  "KW_RAT", "KW_COLOR", "SIMPLE_NUMBER", "KW_PWD", "KW_CD", "KW_PUSHD",
  "KW_POPD", "KW_LS", "KW_LOAD", "KW_QUIT", "KW_EOF", "KW_ENDM",
  "KW_IMPORT", "KW_ENDV", "KW_SORT", "KW_SUBSORT", "KW_OP", "KW_OPS",
  "KW_MSGS", "KW_VAR", "KW_CLASS", "KW_SUBCLASS", "KW_MB", "KW_CMB",
  "KW_EQ", "KW_CEQ", "KW_RL", "KW_CRL", "KW_IS", "KW_FROM", "KW_ARROW",
  "KW_ARROW2", "KW_PARTIAL", "KW_IF", "':'", "'='", "'('", "')'", "'.'",
  "'<'", "'['", "']'", "','", "'|'", "KW_LABEL", "KW_TO", "KW_COLON2",
  "'+'", "'*'", "'{'", "'}'", "KW_ASSOC", "KW_COMM", "KW_ID", "KW_IDEM",
  "KW_ITER", "KW_LEFT", "KW_RIGHT", "KW_PREC", "KW_GATHER", "KW_METADATA",
  "KW_STRAT", "KW_POLY", "KW_MEMO", "KW_FROZEN", "KW_CTOR", "KW_LATEX",
  "KW_SPECIAL", "KW_CONFIG", "KW_OBJ", "KW_MSG", "KW_DITTO", "KW_FORMAT",
  "KW_ID_HOOK", "KW_OP_HOOK", "KW_TERM_HOOK", "KW_IN", "IDENTIFIER",
  "NUMERIC_ID", "ENDS_IN_DOT", "FORCE_LOOKAHEAD", "$accept", "top", "item",
  "directive", "$@1", "$@2", "$@3", "$@4", "$@5", "moduleExprDot",
  "moduleExpr", "moduleExpr2", "moduleExpr3", "renameExpr", "instantExpr",
  "$@6", "parenExpr", "argList", "renaming", "$@7", "$@8", "renaming2",
  "mappingList", "mapping", "$@9", "$@10", "fromSpec", "$@11",
  "toAttributes", "$@12", "toAttributeList", "toAttribute", "$@13", "$@14",
  "$@15", "view", "$@16", "$@17", "$@18", "viewDecList", "skipStrayArrow",
  "viewDeclaration", "$@19", "sortDot", "viewEndOpMap", "$@20", "$@21",
  "$@22", "endBubble", "parenBubble", "$@23", "module", "$@24", "$@25",
  "dot", "parameters", "parameterList", "parameter", "colon2", "badType",
  "typeDot", "startModule", "decList", "declaration", "$@26", "$@27",
  "$@28", "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36",
  "$@37", "$@38", "$@39", "$@40", "$@41", "$@42", "$@43", "$@44", "$@45",
  "$@46", "$@47", "$@48", "classDef", "cPairList", "cPair", "varNameList",
  "opNameList", "simpleOpName", "domainRangeAttr", "skipStrayColon",
  "dra2", "rangeAttr", "typeAttr", "arrow", "typeList", "typeName", "$@49",
  "sortNames", "attributes", "attributeList", "idKeyword", "attribute",
  "$@50", "$@51", "$@52", "$@53", "$@54", "$@55", "$@56", "identity",
  "idList", "hookList", "hook", "expectedIs", "expectedDot",
  "sortNameList", "subsortList", "$@57", "sortName", "sortNameFrag",
  "$@58", "sortNameFrags", "$@59", "token", "tokenBarDot", "tokenBarColon",
  "sortToken", "endsInDot", "inert", "identifier", "startKeyword",
  "startKeyword2", "midKeyword", "attrKeyword", "attrKeyword2", "command",
  "$@60", "$@61", "$@62", "$@63", "$@64", "$@65", "$@66", "$@67", "$@68",
  "$@69", "$@70", "$@71", "$@72", "$@73", "$@74", "$@75", "$@76", "$@77",
  "$@78", "$@79", "$@80", "$@81", "$@82", "$@83", "$@84", "$@85", "$@86",
  "$@87", "$@88", "$@89", "$@90", "$@91", "$@92", "$@93", "$@94", "$@95",
  "$@96", "$@97", "printOption", "traceOption", "polarity", "select",
  "exclude", "conceal", "search", "match", "optDebug", "optNumber",
  "importMode", "moduleAndTerm", "$@98", "inEnd", "$@99",
  "numberModuleTerm", "$@100", "$@101", "numberModuleTerm1", "$@102",
  "$@103", "numberModuleTerm2", "$@104", "$@105", "numbersModuleTerm",
  "$@106", "$@107", "numbersModuleTerm1", "$@108", "$@109", "$@110",
  "numbersModuleTerm2", "$@111", "$@112", "$@113", "numbersModuleTerm3",
  "$@114", "$@115", "numbersModuleTerm4", "$@116", "$@117",
  "numbersModuleTerm5", "$@118", "$@119", "numbersModuleTerm6", "$@120",
  "$@121", "miscEndBubble", "$@122", "initialEndBubble", "$@123", "$@124",
  "cTokenBarIn", "cTokenBarLeftIn", "cTokenBarDotNumber",
  "cTokenBarDotRight", "cTokenBarDotCommaNumber", "cTokenBarDotCommaRight",
  "opSelect", "endSelect", "badSelect", "cOpNameList", "cSimpleOpName",
  "cSimpleTokenBarDot", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,    58,    61,    40,    41,    46,    60,
      91,    93,    44,   124,   379,   380,   381,    43,    42,   123,
     125,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   171,   172,   172,   173,   173,   173,   173,   175,   174,
     176,   174,   174,   177,   174,   178,   174,   174,   179,   174,
     174,   174,   180,   180,   180,   180,   180,   180,   180,   181,
     181,   182,   182,   183,   183,   183,   184,   186,   185,   187,
     188,   188,   190,   191,   189,   192,   192,   193,   193,   194,
     194,   195,   196,   194,   198,   197,   197,   200,   199,   199,
     201,   201,   202,   203,   202,   204,   202,   205,   202,   207,
     208,   209,   206,   210,   210,   211,   211,   212,   212,   213,
     212,   212,   214,   214,   216,   217,   215,   218,   215,   219,
     219,   221,   220,   223,   224,   222,   225,   225,   226,   226,
     227,   227,   228,   229,   229,   230,   231,   231,   232,   232,
     233,   233,   234,   235,   234,   236,   234,   237,   238,   234,
     234,   234,   239,   240,   234,   241,   242,   243,   234,   244,
     245,   234,   246,   247,   248,   234,   249,   250,   234,   251,
     252,   253,   234,   254,   255,   234,   234,   256,   234,   257,
     234,   234,   258,   258,   259,   259,   260,   261,   261,   262,
     262,   263,   263,   264,   264,   264,   265,   265,   266,   266,
     266,   267,   268,   268,   269,   269,   270,   270,   271,   272,
     271,   273,   273,   274,   274,   275,   275,   276,   276,   276,
     277,   277,   278,   277,   277,   277,   277,   279,   277,   280,
     277,   281,   277,   282,   277,   277,   277,   277,   283,   277,
     277,   277,   277,   277,   284,   277,   277,   277,   285,   285,
     286,   286,   287,   287,   288,   288,   288,   288,   289,   289,
     290,   290,   291,   291,   292,   292,   293,   292,   294,   295,
     296,   295,   298,   297,   297,   299,   299,   299,   299,   299,
     300,   300,   300,   300,   300,   300,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   303,   303,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     305,   305,   305,   305,   306,   306,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   308,   308,   308,   308,   308,   308,   308,
     309,   309,   309,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   312,   311,   313,
     311,   314,   311,   315,   311,   316,   311,   317,   311,   318,
     311,   319,   311,   320,   311,   321,   311,   322,   311,   323,
     311,   324,   311,   325,   311,   326,   311,   311,   327,   311,
     311,   328,   311,   329,   311,   330,   311,   331,   311,   311,
     332,   311,   333,   311,   334,   311,   335,   311,   311,   311,
     336,   311,   337,   311,   338,   311,   339,   311,   340,   311,
     341,   311,   342,   311,   343,   311,   311,   311,   311,   344,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   345,   346,   311,   347,   348,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   349,   311,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   352,   352,   353,   353,   354,
     354,   355,   355,   356,   356,   356,   357,   357,   358,   358,
     359,   359,   360,   360,   360,   361,   362,   361,   364,   363,
     363,   366,   365,   365,   367,   365,   369,   368,   370,   368,
     368,   372,   371,   373,   371,   371,   375,   374,   374,   376,
     374,   378,   377,   379,   377,   380,   377,   377,   382,   381,
     383,   381,   384,   381,   381,   386,   385,   387,   385,   385,
     389,   388,   390,   388,   388,   392,   391,   393,   391,   391,
     395,   394,   396,   394,   394,   398,   397,   397,   400,   399,
     401,   399,   399,   402,   402,   402,   402,   402,   402,   402,
     403,   403,   403,   403,   403,   403,   404,   404,   404,   404,
     404,   404,   405,   405,   405,   405,   405,   405,   406,   406,
     406,   406,   406,   407,   407,   407,   407,   407,   408,   408,
     409,   409,   410,   411,   411,   412,   412,   413,   413,   413,
     413,   413,   413,   413
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     0,     3,
       0,     3,     1,     0,     3,     0,     3,     1,     0,     3,
       1,     1,     2,     2,     2,     2,     2,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     0,     5,     3,
       3,     1,     0,     0,     5,     1,     1,     3,     1,     4,
       4,     0,     0,     6,     0,     5,     0,     0,     4,     0,
       2,     1,     2,     0,     5,     0,     5,     0,     5,     0,
       0,     0,    12,     2,     0,     1,     0,     4,     5,     0,
       3,     2,     2,     1,     0,     0,     8,     0,     3,     1,
       1,     0,     3,     0,     0,     8,     1,     1,     3,     0,
       3,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       2,     0,     2,     0,     4,     0,     4,     0,     0,     5,
       4,     5,     0,     0,     5,     0,     0,     0,     7,     0,
       0,     5,     0,     0,     0,     7,     0,     0,     5,     0,
       0,     0,     7,     0,     0,     5,     4,     0,     5,     0,
       4,     2,     1,     2,     1,     3,     3,     2,     1,     2,
       1,     1,     1,     3,     1,     1,     1,     0,     2,     1,
       1,     2,     3,     1,     1,     1,     2,     0,     1,     0,
       4,     3,     1,     3,     0,     2,     1,     1,     2,     2,
       1,     1,     0,     3,     1,     1,     2,     0,     5,     0,
       5,     0,     5,     0,     5,     1,     1,     1,     0,     5,
       1,     1,     1,     2,     0,     5,     4,     1,     1,     0,
       2,     1,     2,     1,     2,     3,     3,     3,     1,     0,
       1,     0,     2,     0,     2,     2,     0,     4,     1,     1,
       0,     5,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     3,     0,
       3,     0,     3,     0,     5,     0,     5,     4,     0,     3,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     3,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     4,     5,     4,     0,
       4,     5,     5,     6,     5,     5,     6,     5,     5,     5,
       5,     6,     5,     4,     0,     0,     7,     0,     0,     8,
       4,     5,     5,     5,     4,     5,     2,     2,     2,     2,
       5,     4,     0,     3,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     0,     1,     1,     1,     1,     0,     3,     0,     3,
       1,     0,     3,     1,     0,     3,     0,     3,     0,     3,
       1,     0,     3,     0,     3,     1,     0,     3,     1,     0,
       3,     0,     3,     0,     3,     0,     3,     1,     0,     3,
       0,     3,     0,     3,     1,     0,     3,     0,     3,     1,
       0,     3,     0,     3,     1,     0,     3,     0,     3,     1,
       0,     3,     0,     3,     1,     0,     3,     1,     0,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   452,   108,   109,    69,   351,   378,   483,   484,   487,
     486,   371,   485,     0,     0,     0,   347,     0,     0,     0,
     488,     0,     0,     0,     0,   353,   355,   349,    12,    13,
      15,    17,    18,    10,    20,    21,    91,     8,     0,     2,
       6,     5,   380,     4,    93,     7,   367,   369,     0,     0,
       0,     0,     0,     0,     0,     0,   464,     0,     0,     0,
       0,     0,     0,   492,   493,   494,     0,     0,   434,   390,
     396,     0,     0,   392,     0,     0,   394,   400,   402,   404,
     406,   408,   410,   412,   414,   419,   477,   478,   480,   479,
     381,   383,     0,   481,   482,   387,   385,     0,   446,   447,
     448,   449,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,   357,   359,     0,     0,   361,
     363,   365,   491,   453,   311,   296,   312,   297,   298,   299,
     300,   302,   301,   303,   304,   305,   306,   307,   308,   309,
     310,   289,   288,   315,   318,   316,   319,   314,   317,   249,
     313,   320,   321,   292,   285,   287,   293,   286,   283,   284,
     281,   282,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   339,   332,   333,   334,   338,   335,   336,   337,   340,
     341,   294,   342,   343,   344,   345,   346,   280,   291,     0,
     290,   245,   246,   295,   247,   248,   322,   567,   558,   568,
     565,   566,   569,   560,   563,   564,   562,   352,   495,   496,
     379,   573,   574,   501,   572,   575,   570,   571,   372,   503,
     504,   437,     0,     0,     0,     0,     0,     0,     0,   472,
     473,   474,   466,   468,   465,   467,   469,   470,   471,     0,
     458,   454,   455,     0,     0,   459,   460,   461,   462,   463,
       0,     0,   475,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,   348,     0,     0,     0,   354,
     356,   350,    14,    16,    19,    11,    92,     9,    94,   516,
     368,   518,   519,   370,     0,     0,   375,   373,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   457,   456,     0,     0,   451,   433,   440,     0,     0,
       0,     0,   444,   612,   609,   610,   613,   611,   607,   608,
     435,   391,   397,   418,   416,     0,   393,   395,   401,   403,
     405,   407,   409,   411,   413,   415,   420,   602,   606,   382,
     599,     0,   604,   605,   384,   388,   386,   389,    99,     0,
       0,   358,   360,     0,     0,   362,   364,   366,   377,     0,
      70,    29,    31,    32,    34,    33,    35,   559,   498,   500,
     561,   497,   580,   555,   577,   578,   581,   579,   576,   506,
     557,   502,   510,   508,   505,   438,     0,     0,   428,   422,
     424,   427,   425,   421,   432,     0,   430,   429,   450,   442,
     445,   441,   443,     0,   417,   600,   598,   601,   603,     0,
     229,   592,   589,   590,   523,   591,   588,   521,   517,   527,
     525,   520,   376,   374,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,   423,   426,   431,     0,     0,   101,
       0,   228,   111,     0,     0,     0,    39,    30,     0,    42,
      36,     0,   499,   556,   586,   584,   511,   587,   585,   582,
     583,   507,   515,   513,   509,     0,   436,     0,    98,   104,
     103,     0,     0,   545,   524,   549,   547,   597,   595,   528,
     530,   596,   593,   594,   522,   534,   532,   526,    71,     0,
       0,    41,     0,     0,   439,   100,   102,     0,    95,     0,
     113,   115,   117,     0,     0,     0,     0,   149,   122,   125,
     129,   132,   136,   139,   143,   110,     0,     0,     0,     0,
       0,   229,    46,     0,    51,     0,    43,    45,    48,     0,
      38,   512,   514,   151,   249,   251,   252,    28,   112,     0,
     231,   231,   231,   231,     0,   250,   253,   254,   255,   233,
       0,     0,   261,   264,   262,   265,   263,   259,   260,   162,
       0,   160,   161,   256,   257,   258,     0,     0,   158,   147,
       0,     0,     0,     0,     0,     0,     0,     0,   550,   546,
     554,   552,   548,   529,   535,   531,   539,   537,   533,    74,
     275,   273,   274,   269,   270,   276,   277,   271,   272,   266,
       0,   238,   239,   267,   268,    56,     0,     0,     0,    40,
       0,   230,    25,    26,    24,    22,    23,     0,     0,   236,
     118,     0,   159,     0,    76,   157,     0,     0,   123,   126,
     130,   133,   137,   140,   144,     0,     0,     0,     0,     0,
       0,   240,    54,     0,     0,    44,    47,    27,    30,    96,
      97,   114,   232,   235,   116,   234,   233,     0,   174,   175,
     179,   105,   165,   120,   164,     0,   177,   178,   146,    75,
       0,   152,     0,   150,     0,     0,     0,     0,     0,     0,
       0,   551,   553,   540,   536,   544,   542,   538,     0,    72,
       0,    79,     0,    73,    49,     0,   177,    52,    50,     0,
     119,     0,   173,   171,   184,   167,   107,   121,   231,   251,
     252,   153,   154,     0,   250,   253,   254,   255,   148,   124,
     127,   131,   134,   138,   141,   145,     0,     0,    81,     0,
       0,     0,   244,     0,     0,    59,   237,     0,   182,     0,
     231,   166,   169,   170,     0,   163,   176,   106,     0,     0,
       0,     0,     0,   541,   543,     0,    84,    87,    80,    76,
     242,   241,     0,    57,    53,   180,     0,   190,   191,   187,
     194,   195,     0,     0,     0,     0,     0,     0,     0,   205,
     207,   206,     0,     0,   210,   211,   212,   217,     0,     0,
     192,   186,   172,   168,   155,   156,   128,   135,   142,    83,
      77,   231,   177,     0,     0,     0,    55,     0,   181,   188,
     189,   196,   197,   213,   201,   203,   208,   214,     0,   199,
     183,   185,   219,    82,     0,    88,    78,   243,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   223,     0,   218,   193,     0,    62,    63,
      67,    65,    58,    60,   221,     0,     0,     0,     0,     0,
     224,     0,     0,   216,   222,     0,     0,     0,     0,     0,
     198,   220,   202,   204,   209,   215,   225,   226,   227,   200,
      85,     0,     0,     0,     0,    64,    68,    66,    86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    38,    39,    40,   110,   108,   105,   106,   107,   568,
     390,   391,   392,   393,   394,   481,   395,   520,   480,   519,
     637,   556,   557,   558,   635,   765,   673,   726,   794,   837,
     862,   863,   897,   899,   898,    41,    50,   456,   551,   669,
     700,   723,   760,   830,   788,   832,   914,   833,   410,   368,
     109,    43,   112,   378,   681,   440,   468,   469,   501,   692,
     737,    44,   502,   545,   579,   580,   581,   687,   601,   704,
     602,   705,   780,   603,   706,   604,   707,   781,   605,   708,
     606,   709,   782,   607,   710,   656,   600,   702,   741,   742,
     597,   590,   591,   693,   774,   775,   694,   733,   695,   735,
     696,   731,   767,   770,   819,   820,   821,   852,   864,   874,
     865,   866,   867,   868,   876,   885,   872,   873,   472,   642,
     647,   648,   686,   697,   631,   725,   763,   835,   396,   573,
     592,   632,   574,   190,   191,   633,   193,   194,   195,   196,
      45,    92,   104,    51,   102,   103,   304,   305,   308,   309,
     310,   113,   114,    53,   384,   383,    52,   281,   282,   287,
     286,   263,   268,   271,   264,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   262,   433,   319,   463,    49,   250,
     239,   254,    90,    91,    95,    46,    47,    48,   312,    68,
     207,   316,   400,   459,   218,   317,   318,   411,   461,   462,
     491,   522,   523,   300,   379,   380,   448,   474,   473,   475,
     514,   548,   549,   550,   615,   667,   668,   714,   756,   757,
     504,   546,   547,   609,   665,   666,   412,   460,   208,   314,
     315,   209,   220,   413,   493,   450,   516,   369,   436,   370,
     371,   372,   373
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -736
static const yytype_int16 yypact[] =
{
     629,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,   352,   500,    53,  -736,   -16,   266,    -3,
    -736,   -86,   -44,   -12,    -7,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,    45,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   499,     4,
    1068,   210,   210,   413,    35,    30,   323,   204,    84,   190,
     190,   190,   -31,  -736,  -736,  -736,    64,   190,  -736,  -736,
    -736,   119,   -59,  -736,    42,    48,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,   -77,  -736,  -736,  -736,  -736,    26,  -736,  -736,
    -736,  -736,   210,   210,   -77,   223,   240,   189,   262,    81,
     274,  -736,  1068,   708,   413,  -736,  -736,   264,   272,  -736,
    -736,  -736,   237,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   163,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,   254,   190,   190,   190,   190,   190,   190,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   190,
    -736,  -736,  -736,   124,   280,  -736,  -736,  -736,  -736,  -736,
     190,   190,  -736,  -736,   203,   209,   211,   190,   190,   190,
     190,   242,   243,   -77,   -77,   244,   257,   297,   -77,  -736,
    -736,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,    -6,    -6,  -736,  -736,  -736,    -6,    -6,   267,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,   210,   413,  -736,  -736,   708,   708,
     413,  -736,   277,   792,   -77,   -78,   -77,   717,   -77,   243,
     190,   190,   291,   294,   303,   305,   308,   311,   318,   190,
     319,  -736,  -736,   320,   321,  -736,  -736,  -736,   324,   325,
     327,   333,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,   334,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  2068,  -736,  -736,  -736,  -736,  -736,  -736,   251,  2077,
     -77,  -736,  -736,   413,   413,  -736,  -736,  -736,  -736,   792,
     271,   326,   328,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,   335,   337,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,   338,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,   190,  -736,  -736,  -736,  -736,  -736,  1068,
     350,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,   -30,   792,   336,   343,  -736,   -77,
     -77,  2086,   -77,   190,  -736,  -736,  -736,   344,    10,  -736,
     -66,  -736,  -736,  2095,  2141,   -77,  -736,  -736,   792,  -736,
    -736,  1068,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,   349,  -736,  1068,  -736,  -736,
    -736,   792,   205,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   271,    11,
     101,  -736,   210,   -77,  -736,  -736,   271,   354,  -736,   861,
    -736,  -736,  -736,  1137,  1137,  1344,  1068,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  2150,   -77,   210,  2159,
     -77,   350,  -736,  2026,  -736,  1068,  -736,   346,  -736,  1068,
    -736,  -736,  -736,  -736,   355,   186,   225,    28,  -736,   347,
     148,   160,   215,   359,   360,   255,   276,   279,   290,  -736,
    2026,   356,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
     930,  -736,  -736,  -736,  -736,  -736,   999,  1206,  -736,  -736,
    2026,   365,   370,   372,   373,   374,   379,   377,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
     367,   364,  -736,  -736,  -736,   380,   378,   382,    98,  -736,
     861,  -736,  -736,  -736,  -736,  -736,  -736,  1551,  1482,  -736,
    -736,   655,  -736,   655,   385,  -736,   384,  1482,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,   210,   -77,  2168,   -77,    43,
    2026,  -736,  -736,   390,  1068,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,   655,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  1620,  -736,  -736,  -736,  -736,
    1620,  1758,   399,  -736,   -77,   405,   -77,   406,   -77,   407,
     655,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   403,  -736,
    2026,  -736,  1344,  -736,  -736,  2026,  -736,  -736,  -736,  1892,
    -736,  2026,  -736,  -736,   402,  1413,  -736,  -736,   359,  -736,
    -736,   375,  -736,   412,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,   210,   -77,  -736,   414,
     -83,  1275,   364,   131,  1825,   408,  -736,   213,  -736,  2197,
     359,  -736,  -736,  -736,   117,  -736,  -736,  -736,  1758,  1068,
     -77,   -77,   -77,  -736,  -736,  1689,  -736,  -736,  -736,   385,
    -736,  -736,  1959,  -736,  -736,  -736,  2026,  -736,  -736,  -736,
    -736,  -736,   397,   409,   381,   424,   401,   425,   443,  -736,
     444,  -736,   445,   446,  -736,  -736,  -736,  -736,   447,   711,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,   359,  -736,   -77,  1620,  2026,  -736,   125,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   184,  -736,
    -736,  -736,   404,  -736,  1825,  -736,  -736,   364,   411,   450,
     457,   460,    86,  -736,   420,   420,   420,   420,   584,  1068,
    1068,  1068,    88,  -736,   420,  -736,  -736,  1959,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,   -72,   -68,   -62,   -61,   464,
     466,   466,   466,  -736,  -736,   -53,   458,   420,   589,   420,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,   -34,   468,   -19,   -77,  -736,  -736,  -736,  -736
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   -42,
    -378,  -736,  -736,  -503,  -502,  -736,  -501,  -736,  -736,  -736,
    -736,  -736,  -736,   -39,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -262,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -188,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   -91,     0,
    -736,  -736,  -736,  -736,  -584,  -736,  -736,   105,  -736,  -679,
    -231,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -173,
    -116,    74,  -432,  -616,  -736,  -736,  -167,  -736,  -735,  -691,
    -526,  -736,  -736,  -736,  -736,  -736,  -210,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -423,  -736,  -261,    59,  -567,
     -74,    14,  -736,  -513,  -695,  -736,  -736,  -736,   -40,  -665,
    -521,  -736,  -736,  -510,  -486,   -43,  -736,  -509,  -511,  -250,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,   -29,   600,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
     -49,  -736,  -736,  -736,  -105,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,    73,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -371,  -736,   -51,  -736,
    -736,  -736,   -96,  -448,  -531,  -736,  -736,   -26,  -736,   248,
    -736,   249,  -223
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -490
static const yytype_int16 yytable[] =
{
      42,   285,   219,   210,   643,   644,   645,   192,   449,   303,
     189,   454,   552,   291,   598,   611,   732,   302,   578,   575,
     577,   736,   595,   595,   595,   506,   570,   571,   572,   792,
     762,   255,   256,   266,   257,   764,   743,   698,   261,   350,
     630,   786,    98,   222,   718,   111,   398,   593,   593,   593,
     283,   283,   787,   289,   290,   900,   773,   258,   499,   902,
      93,    94,   301,   219,   684,   903,   904,   649,    97,   192,
     500,   730,   298,   703,   909,   267,   655,   477,   223,   595,
     224,   225,   226,   227,    99,   595,   595,   649,    86,    87,
     492,   284,   284,   915,   755,   901,   415,   476,   228,   901,
     518,   617,   505,   515,   593,   901,   901,   455,   917,   221,
     593,   593,   251,   743,   901,   553,   100,   554,   343,   877,
      36,   101,   259,   526,   344,   345,   346,    88,    89,   578,
     575,   577,   123,   901,   682,   685,   716,   570,   571,   572,
     857,   854,   497,   260,   685,   555,   719,   720,   901,   721,
     498,   569,   722,   252,   253,   736,  -279,   724,   652,   265,
     347,   348,   349,   367,   652,  -291,  -291,  -291,   329,   734,
     269,   777,   351,   352,   738,   610,   270,   356,   616,   288,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     747,   744,   746,   294,   322,   323,   324,   325,   326,   327,
     382,   598,   553,   822,   554,   387,   527,   759,   296,   776,
     328,   595,   302,   302,   330,   893,   682,   882,   768,   252,
     253,   333,   334,   397,   399,   401,   292,   414,   338,   339,
     340,   341,   555,   559,   858,   859,   593,   688,   776,   689,
     655,   560,   860,   293,   240,   241,   242,   243,   861,   244,
     595,   869,   870,   871,   219,   381,   374,   301,   301,   219,
     375,   376,   678,   790,   853,   295,   836,   747,   744,   746,
     192,   791,   831,   858,   859,   593,   641,   297,   452,   453,
     245,   860,   313,   838,   306,   -32,   -32,   861,   641,   451,
     307,   416,   417,   246,   247,   248,   715,   -34,   -34,   -34,
     425,    86,    87,   634,   320,   321,   528,   529,   738,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,  -292,  -292,  -292,   331,   332,   776,   311,
     634,   335,   219,   219,   197,   229,   198,   336,   199,   337,
     200,   201,   202,   641,   795,   796,   192,   869,   870,   871,
     634,   896,   -33,   -33,   -33,   230,   231,   232,   233,    54,
     234,   235,  -293,  -293,  -293,   544,   249,   343,   482,   483,
     342,   494,   353,   344,   345,   346,   203,   204,   205,   206,
      55,   385,   386,    56,   517,   354,   236,   237,   238,   355,
     439,    57,  -290,  -290,  -290,   377,   192,   634,   634,   470,
      58,   634,    59,   634,   467,   388,    60,   634,   455,   347,
     348,   349,   192,  -246,  -246,  -246,  -247,  -247,  -247,   418,
     634,    61,   419,    62,    63,    64,    65,  -248,  -248,  -248,
      66,   420,   562,   421,   495,   192,   422,   634,   192,   423,
      67,   521,   886,   887,   888,   634,   424,   426,   427,   428,
     634,   895,   429,   430,   192,   431,   612,   470,   192,   618,
     634,   432,   434,   464,   457,   465,   466,   458,   471,   479,
     634,   478,   496,   561,   911,   634,   913,   524,   638,   634,
     650,   634,   563,  -278,   640,   634,   576,   641,   646,   658,
     594,   594,   594,   192,   659,   662,   599,   660,   661,   613,
     663,   664,   670,   671,   672,   699,    69,   778,    70,   675,
     115,   116,   192,   674,   634,   636,   192,   701,   117,   639,
     118,   119,   120,   121,   122,   727,    71,   748,   750,   752,
     754,   758,   769,   589,   589,   634,   779,   211,   793,   198,
     839,   212,   634,   213,   214,   215,   634,   594,   841,   785,
     842,   844,   840,   594,   594,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,   843,   845,
     846,   847,   848,   849,   875,   712,   879,   717,   878,   203,
     216,   217,   206,   880,   634,   634,   881,   884,    85,   889,
     589,   905,    36,   910,   912,   916,   589,   576,   677,   676,
     883,   834,   525,   856,   634,   824,   761,   823,   596,   851,
     619,   894,   729,   749,   657,   751,   711,   753,    96,   437,
     438,     0,     0,     0,     0,     0,     0,   634,     0,    -3,
       1,   192,     0,     0,   728,     2,     3,     4,     5,     0,
    -489,  -489,     6,     7,     8,     9,    10,    11,  -489,     0,
    -489,  -489,  -489,  -489,  -489,    12,    13,    14,   745,     0,
      15,     0,     0,     0,    16,     0,   784,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
       0,     0,     0,    18,     0,     0,     0,     0,     0,   826,
     827,   828,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,   783,     0,    20,
      21,    22,    23,    24,    25,    26,    27,     0,   594,     0,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,   745,   192,     0,     0,   825,
       0,     0,   855,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   620,     0,   688,   621,   689,   622,     0,
     623,     0,     0,     0,     0,   690,     0,     0,   624,   625,
     626,     0,   627,   628,     0,    37,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   629,   918,   691,     0,   192,   192,   192,   890,
     891,   892,   211,     0,   198,     0,   212,     0,   299,   214,
     215,   402,   850,   403,     0,   283,     0,   404,   405,   406,
       0,     0,   797,   798,   799,   800,   801,   802,   803,   804,
     805,   806,   807,   808,   809,   810,   811,   812,   813,   814,
     815,   816,   817,   818,   203,   216,   217,   206,     0,     0,
       0,     0,     0,   407,   408,   409,   284,     0,     0,     0,
     906,   907,   908,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   389,     0,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,   187,
       0,   188,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   389,     0,   564,
     150,   151,   152,   565,   154,   155,   566,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,     0,
     567,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     582,   583,   584,   585,   651,   586,    36,     0,   587,   588,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,     0,   188,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   582,
     583,   584,   585,   653,   586,    36,     0,   587,   588,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,     0,   188,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,     0,   188,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   582,   583,   584,
     585,     0,   586,    36,     0,   587,   588,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,     0,   188,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   582,   583,   584,   585,
     654,   586,     0,     0,   587,   588,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,   187,     0,   188,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   582,   583,   584,   585,   789,
     586,     0,     0,   587,   588,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,     0,   188,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   582,   583,   584,   585,     0,   586,
       0,     0,   587,   588,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,     0,   188,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   620,     0,     0,   621,     0,   622,   771,   623,     0,
       0,   772,     0,   690,     0,     0,   624,   625,   626,     0,
     627,   628,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     629,     0,   691,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     620,     0,     0,   621,     0,   622,     0,   623,     0,     0,
     679,   683,     0,     0,     0,   624,   625,   626,     0,   627,
     628,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,   629,
       0,   680,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   620,
       0,     0,   621,     0,   622,     0,   623,     0,     0,   679,
       0,     0,     0,     0,   624,   625,   626,     0,   627,   628,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   629,     0,
     680,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   620,     0,
       0,   621,     0,   622,     0,   623,     0,     0,     0,     0,
     690,     0,     0,   624,   625,   626,     0,   627,   628,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   629,     0,   691,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   620,     0,     0,
     621,     0,   622,     0,   623,     0,     0,     0,     0,     0,
       0,     0,   624,   625,   626,     0,   627,   628,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   629,     0,   829,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,     0,   150,   151,   152,
     739,   154,   155,   740,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   620,     0,   688,   621,   689,   622,     0,
     623,     0,     0,     0,     0,   690,     0,     0,   624,   625,
     626,     0,   627,   628,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   629,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     620,     0,     0,   621,     0,   622,     0,   623,     0,     0,
       0,   766,     0,     0,     0,   624,   625,   626,     0,   627,
     628,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,   629,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   620,     0,     0,
     621,     0,   622,     0,   623,     0,     0,     0,     0,   690,
       0,     0,   624,   625,   626,     0,   627,   628,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   629,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   620,     0,     0,   621,     0,   622,
       0,   623,     0,     0,     0,     0,     0,     0,     0,   624,
     625,   626,     0,   627,   628,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   343,   629,    36,     0,   435,     0,   344,   345,
     346,   441,     0,   403,     0,   283,     0,   442,   443,   444,
     484,     0,   403,     0,   283,     0,   485,   486,   487,   402,
       0,   403,     0,   283,     0,   404,   405,   406,     0,     0,
       0,     0,     0,     0,   347,   348,   349,   367,     0,     0,
       0,     0,     0,   445,   446,   447,   284,     0,     0,     0,
       0,     0,   488,   489,   490,   284,     0,     0,     0,     0,
       0,   407,   408,   503,   284,   507,     0,   403,     0,   283,
       0,   508,   509,   510,   484,     0,   403,     0,   283,     0,
     485,   608,   487,   402,     0,   403,     0,   283,     0,   404,
     405,   406,   484,     0,   403,     0,   283,     0,   485,   713,
     487,     0,     0,     0,     0,     0,     0,   511,   512,   513,
     284,     0,     0,     0,     0,     0,   488,   489,   490,   284,
       0,     0,     0,     0,     0,   407,   408,   614,   284,     0,
       0,     0,     0,     0,   488,   489,   490,   284,   797,   798,
     799,   800,   801,   802,   803,   804,   805,   806,   807,   808,
     809,   810,   811,   812,   813,   814,   815,   816,   817,   818
};

static const yytype_int16 yycheck[] =
{
       0,    92,    53,    52,   571,   572,   573,    50,   379,   114,
      50,   389,     1,   104,   535,   546,   695,   113,   529,   529,
     529,   700,   533,   534,   535,   473,   529,   529,   529,   764,
     725,    60,    61,    92,    65,   726,   701,   653,    67,   262,
     553,   124,   128,    13,     1,     0,   124,   533,   534,   535,
     128,   128,   135,   102,   103,   127,   735,    88,   124,   127,
      76,    77,   113,   114,   648,   127,   127,   580,    71,   112,
     136,   687,   112,   657,   127,   134,   597,   455,    48,   590,
      50,    51,    52,    53,   128,   596,   597,   600,    35,    36,
     461,   169,   169,   127,   710,   167,   319,   127,    68,   167,
     478,   549,   473,   474,   590,   167,   167,   137,   127,    74,
     596,   597,    28,   778,   167,   104,   128,   106,   124,   854,
     126,   128,   153,   501,   130,   131,   132,    74,    75,   640,
     640,   640,   128,   167,   647,   648,   667,   640,   640,   640,
     835,   832,   132,    79,   657,   134,   103,   104,   167,   106,
     140,   529,   109,    29,    30,   834,   128,   670,   590,    40,
     166,   167,   168,   169,   596,   137,   138,   139,    44,   695,
     128,   738,   263,   264,   700,   546,   128,   268,   549,   153,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     701,   701,   701,     4,   223,   224,   225,   226,   227,   228,
     305,   722,   104,   770,   106,   310,     1,   720,   127,   735,
     239,   722,   308,   309,   243,   127,   729,   131,   731,    29,
      30,   250,   251,   314,   315,   316,     3,   318,   257,   258,
     259,   260,   134,   132,   148,   149,   722,   120,   764,   122,
     761,   140,   156,     3,    40,    41,    42,    43,   162,    45,
     761,   163,   164,   165,   305,   304,   282,   308,   309,   310,
     286,   287,   640,   132,   831,     3,   792,   778,   778,   778,
     313,   140,   785,   148,   149,   761,   128,     3,   383,   384,
      76,   156,   119,   796,    20,   137,   138,   162,   128,   380,
      18,   320,   321,    89,    90,    91,   667,   137,   138,   139,
     329,    35,    36,   553,    50,    51,   101,   102,   834,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   137,   138,   139,    46,    47,   854,    92,
     580,   128,   383,   384,   124,    12,   126,   128,   128,   128,
     130,   131,   132,   128,   131,   132,   389,   163,   164,   165,
     600,   877,   137,   138,   139,    32,    33,    34,    35,     7,
      37,    38,   137,   138,   139,   160,   162,   124,   459,   460,
     128,   462,   128,   130,   131,   132,   166,   167,   168,   169,
      28,   308,   309,    31,   475,   128,    63,    64,    65,    92,
     139,    39,   137,   138,   139,   128,   439,   647,   648,   439,
      48,   651,    50,   653,   433,   128,    54,   657,   137,   166,
     167,   168,   455,   137,   138,   139,   137,   138,   139,   128,
     670,    69,   128,    71,    72,    73,    74,   137,   138,   139,
      78,   128,   523,   128,   463,   478,   128,   687,   481,   128,
      88,   481,   865,   866,   867,   695,   128,   128,   128,   128,
     700,   874,   128,   128,   497,   128,   547,   497,   501,   550,
     710,   128,   128,   128,   138,   128,   128,   139,   118,   126,
     720,   135,   128,   522,   897,   725,   899,   128,   132,   729,
     124,   731,   128,   128,   137,   735,   529,   128,   128,   124,
     533,   534,   535,   536,   124,   121,   536,   125,   125,   548,
     121,   124,   135,   139,   124,   120,     6,   132,     8,   127,
      11,    12,   555,   135,   764,   555,   559,   133,    19,   559,
      21,    22,    23,    24,    25,   135,    26,   128,   123,   123,
     123,   128,   130,   533,   534,   785,   124,   124,   130,   126,
     143,   128,   792,   130,   131,   132,   796,   590,   167,   135,
     126,   126,   143,   596,   597,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   167,   126,
     126,   126,   126,   126,   170,   666,   126,   668,   167,   166,
     167,   168,   169,   126,   834,   835,   126,   167,    88,     5,
     590,   127,   126,   135,     5,   127,   596,   640,   640,   638,
     862,   789,   497,   834,   854,   778,   722,   774,   534,   819,
     551,   872,   686,   704,   600,   706,   665,   708,    18,   371,
     371,    -1,    -1,    -1,    -1,    -1,    -1,   877,    -1,     0,
       1,   674,    -1,    -1,   674,     6,     7,     8,     9,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,   701,    -1,
      31,    -1,    -1,    -1,    35,    -1,   757,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   722,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,   780,
     781,   782,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   756,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,   761,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,    -1,    -1,    -1,   778,   779,    -1,    -1,   779,
      -1,    -1,   833,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,   121,   122,   123,    -1,
     125,    -1,    -1,    -1,    -1,   130,    -1,    -1,   133,   134,
     135,    -1,   137,   138,    -1,   166,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   914,   169,    -1,   869,   870,   871,   869,
     870,   871,   124,    -1,   126,    -1,   128,    -1,   130,   131,
     132,   124,   131,   126,    -1,   128,    -1,   130,   131,   132,
      -1,    -1,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,    -1,   166,   167,   168,   169,    -1,    -1,    -1,
     890,   891,   892,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
      -1,   169,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,    -1,
     169,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,   167,    -1,   169,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,    -1,   169,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,   167,    -1,   169,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    -1,   125,   126,    -1,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,    -1,   169,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,   167,    -1,   169,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,    -1,   169,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,   125,
      -1,    -1,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,   167,    -1,   169,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,   121,    -1,   123,   124,   125,    -1,
      -1,   128,    -1,   130,    -1,    -1,   133,   134,   135,    -1,
     137,   138,    -1,    -1,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,    -1,   169,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,   121,    -1,   123,    -1,   125,    -1,    -1,
     128,   129,    -1,    -1,    -1,   133,   134,   135,    -1,   137,
     138,    -1,    -1,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
      -1,   169,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,   121,    -1,   123,    -1,   125,    -1,    -1,   128,
      -1,    -1,    -1,    -1,   133,   134,   135,    -1,   137,   138,
      -1,    -1,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,    -1,
     169,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,   121,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,   133,   134,   135,    -1,   137,   138,    -1,
      -1,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,   167,    -1,   169,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
     121,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,   134,   135,    -1,   137,   138,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,    -1,   169,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,   167,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,   121,   122,   123,    -1,
     125,    -1,    -1,    -1,    -1,   130,    -1,    -1,   133,   134,
     135,    -1,   137,   138,    -1,    -1,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,   121,    -1,   123,    -1,   125,    -1,    -1,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,    -1,   137,
     138,    -1,    -1,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
     121,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,   130,
      -1,    -1,   133,   134,   135,    -1,   137,   138,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,   121,    -1,   123,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,    -1,   137,   138,    -1,    -1,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   124,   167,   126,    -1,   128,    -1,   130,   131,
     132,   124,    -1,   126,    -1,   128,    -1,   130,   131,   132,
     124,    -1,   126,    -1,   128,    -1,   130,   131,   132,   124,
      -1,   126,    -1,   128,    -1,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,    -1,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,   169,   124,    -1,   126,    -1,   128,
      -1,   130,   131,   132,   124,    -1,   126,    -1,   128,    -1,
     130,   131,   132,   124,    -1,   126,    -1,   128,    -1,   130,
     131,   132,   124,    -1,   126,    -1,   128,    -1,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    14,    15,    16,
      17,    18,    26,    27,    28,    31,    35,    39,    54,    70,
      80,    81,    82,    83,    84,    85,    86,    87,    93,    94,
      95,    96,    97,    98,    99,   100,   126,   166,   172,   173,
     174,   206,   220,   222,   232,   311,   356,   357,   358,   349,
     207,   314,   327,   324,     7,    28,    31,    39,    48,    50,
      54,    69,    71,    72,    73,    74,    78,    88,   360,     6,
       8,    26,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    88,    35,    36,    74,    75,
     353,   354,   312,    76,    77,   355,   353,    71,   128,   128,
     128,   128,   315,   316,   313,   177,   178,   179,   176,   221,
     175,     0,   223,   322,   323,    11,    12,    19,    21,    22,
      23,    24,    25,   128,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   167,   169,   299,
     304,   305,   306,   307,   308,   309,   310,   124,   126,   128,
     130,   131,   132,   166,   167,   168,   169,   361,   399,   402,
     361,   124,   128,   130,   131,   132,   167,   168,   365,   399,
     403,    74,    13,    48,    50,    51,    52,    53,    68,    12,
      32,    33,    34,    35,    37,    38,    63,    64,    65,   351,
      40,    41,    42,    43,    45,    76,    89,    90,    91,   162,
     350,    28,    29,    30,   352,   352,   352,    65,    88,   153,
      79,   352,   345,   332,   335,    40,    92,   134,   333,   128,
     128,   334,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   328,   329,   128,   169,   219,   331,   330,   153,   361,
     361,   219,     3,     3,     4,     3,   127,     3,   299,   130,
     374,   399,   403,   365,   317,   318,    20,    18,   319,   320,
     321,    92,   359,   119,   400,   401,   362,   366,   367,   347,
      50,    51,   352,   352,   352,   352,   352,   352,   352,    44,
     352,    46,    47,   352,   352,   128,   128,   128,   352,   352,
     352,   352,   128,   124,   130,   131,   132,   166,   167,   168,
     413,   219,   219,   128,   128,    92,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   169,   220,   408,
     410,   411,   412,   413,   408,   408,   408,   128,   224,   375,
     376,   361,   365,   326,   325,   374,   374,   365,   128,   126,
     181,   182,   183,   184,   185,   187,   299,   219,   124,   219,
     363,   219,   124,   126,   130,   131,   132,   166,   167,   168,
     219,   368,   397,   404,   219,   413,   352,   352,   128,   128,
     128,   128,   128,   128,   128,   352,   128,   128,   128,   128,
     128,   128,   128,   346,   128,   128,   409,   410,   412,   139,
     226,   124,   130,   131,   132,   166,   167,   168,   377,   397,
     406,   219,   365,   365,   181,   137,   208,   138,   139,   364,
     398,   369,   370,   348,   128,   128,   128,   352,   227,   228,
     299,   118,   289,   379,   378,   380,   127,   181,   135,   126,
     189,   186,   219,   219,   124,   130,   131,   132,   166,   167,
     168,   371,   397,   405,   219,   352,   128,   132,   140,   124,
     136,   229,   233,   168,   391,   397,   404,   124,   130,   131,
     132,   166,   167,   168,   381,   397,   407,   219,   181,   190,
     188,   299,   372,   373,   128,   228,   181,     1,   101,   102,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   160,   234,   392,   393,   382,   383,
     384,   209,     1,   104,   106,   134,   192,   193,   194,   132,
     140,   361,   219,   128,   128,   132,   135,   169,   180,   181,
     184,   185,   187,   300,   303,   304,   306,   308,   309,   235,
     236,   237,   120,   121,   122,   123,   125,   128,   129,   220,
     262,   263,   301,   305,   306,   309,   262,   261,   301,   299,
     257,   239,   241,   244,   246,   249,   251,   254,   131,   394,
     397,   405,   219,   361,   168,   385,   397,   404,   219,   289,
     118,   121,   123,   125,   133,   134,   135,   137,   138,   167,
     294,   295,   302,   306,   310,   195,   299,   191,   132,   299,
     137,   128,   290,   290,   290,   290,   128,   291,   292,   294,
     124,   124,   263,   124,   124,   301,   256,   292,   124,   124,
     125,   125,   121,   121,   124,   395,   396,   386,   387,   210,
     135,   139,   124,   197,   135,   127,   194,   180,   181,   128,
     169,   225,   294,   129,   225,   294,   293,   238,   120,   122,
     130,   169,   230,   264,   267,   269,   271,   294,   264,   120,
     211,   133,   258,   225,   240,   242,   245,   247,   250,   252,
     255,   361,   219,   131,   388,   397,   405,   219,     1,   103,
     104,   106,   109,   212,   294,   296,   198,   135,   299,   291,
     264,   272,   230,   268,   271,   270,   230,   231,   271,   132,
     135,   259,   260,   300,   304,   306,   308,   309,   128,   219,
     123,   219,   123,   219,   123,   264,   389,   390,   128,   294,
     213,   261,   295,   297,   270,   196,   129,   273,   294,   130,
     274,   124,   128,   230,   265,   266,   271,   290,   132,   124,
     243,   248,   253,   361,   219,   135,   124,   135,   215,   124,
     132,   140,   269,   130,   199,   131,   132,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   275,
     276,   277,   290,   267,   260,   299,   219,   219,   219,   169,
     214,   294,   216,   218,   211,   298,   271,   200,   294,   143,
     143,   167,   126,   167,   126,   126,   126,   126,   126,   126,
     131,   277,   278,   290,   270,   219,   231,   295,   148,   149,
     156,   162,   201,   202,   279,   281,   282,   283,   284,   163,
     164,   165,   287,   288,   280,   170,   285,   269,   167,   126,
     126,   126,   131,   202,   167,   286,   286,   286,   286,     5,
     299,   299,   299,   127,   288,   286,   271,   203,   205,   204,
     127,   167,   127,   127,   127,   127,   220,   220,   220,   127,
     135,   286,     5,   286,   217,   127,   127,   127,   219
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 233 "surface.yy"
    { YYACCEPT; ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 235 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 249 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 251 "surface.yy"
    {
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile((yyvsp[(3) - (3)].yyString), directory, fileName, lineNr))
			    includeFile(directory, fileName, false, lineNr);
			;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 259 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 261 "surface.yy"
    {
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile((yyvsp[(3) - (3)].yyString), directory, fileName, lineNr))
			    includeFile(directory, fileName, true, lineNr);
			;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 270 "surface.yy"
    {
			  cout << directoryManager.getCwd() << '\n';
			;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 273 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 275 "surface.yy"
    {
			  string directory;
			  directoryManager.realPath((yyvsp[(3) - (3)].yyString), directory);
			  if (!directoryManager.cd(directory))
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": cd failed");
			    }
			;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 284 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 286 "surface.yy"
    {
			  string directory;
			  directoryManager.realPath((yyvsp[(3) - (3)].yyString), directory);
			  if (directoryManager.pushd(directory) == UNDEFINED)
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": pushd failed");
			    }
			;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 296 "surface.yy"
    {
			  const char* path = directoryManager.popd();
			  if (path != 0)
			    cout << path << '\n';
			  else
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": popd failed");
			    }
			;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 306 "surface.yy"
    { lexerStringMode(); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 308 "surface.yy"
    {
			  system((string("ls") + (yyvsp[(3) - (3)].yyString)).c_str());
			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 312 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 317 "surface.yy"
    {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 350 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (2)].yyToken)));
                        ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 354 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (2)].yyToken)));
                        ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 361 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 369 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  moduleExpressions.push(new ModuleExpression(t));
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 379 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 395 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (1)].yyToken)));
                        ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 402 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 410 "surface.yy"
    { clear(); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 412 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, tokenSequence));
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 419 "surface.yy"
    {;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 422 "surface.yy"
    { store((yyvsp[(3) - (3)].yyToken)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 423 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 430 "surface.yy"
    {
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 435 "surface.yy"
    {
			  currentSyntaxContainer = oldSyntaxContainer;
			;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 450 "surface.yy"
    {
			  currentRenaming->addSortMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 454 "surface.yy"
    {
			  currentRenaming->addLabelMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 457 "surface.yy"
    { lexBubble(BAR_COLON | BAR_TO, 1); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 458 "surface.yy"
    { lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 459 "surface.yy"
    {;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 464 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 465 "surface.yy"
    {;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 466 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 472 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 473 "surface.yy"
    {;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 474 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 481 "surface.yy"
    { currentRenaming->setPrec((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 482 "surface.yy"
    { clear(); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 483 "surface.yy"
    { currentRenaming->setGather(tokenSequence); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 484 "surface.yy"
    { clear(); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 485 "surface.yy"
    { currentRenaming->setFormat(tokenSequence); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 486 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 487 "surface.yy"
    { currentRenaming->setLatexMacro((yyvsp[(4) - (5)].yyString)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 493 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 495 "surface.yy"
    {
			  fileTable.beginModule((yyvsp[(1) - (5)].yyToken), (yyvsp[(3) - (5)].yyToken));
			  interpreter.setCurrentView(new View((yyvsp[(3) - (5)].yyToken)));
			  currentSyntaxContainer = CV;
			  CV->addFrom(moduleExpressions.top());
			  moduleExpressions.pop();
			;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 503 "surface.yy"
    {
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 508 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  interpreter.insertView(((yyvsp[(3) - (12)].yyToken)).code(), CV);
			  CV->finishView();
			;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 521 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
				       ": skipping " << QUOTE("->") << " in variable declaration.");
			;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 529 "surface.yy"
    {
			  CV->addSortMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 532 "surface.yy"
    {;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 533 "surface.yy"
    { lexBubble(BAR_COLON | BAR_TO, 1); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 538 "surface.yy"
    { (yyval.yyToken) = (yyvsp[(1) - (2)].yyToken); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 540 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  (yyval.yyToken) = t;
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 549 "surface.yy"
    {
			  //
			  //	Specific op->op mapping.
			  //
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpMapping(lexerBubble);
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 557 "surface.yy"
    {
			  lexBubble(END_STATEMENT, 1);
			;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 561 "surface.yy"
    {
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 566 "surface.yy"
    {
			  //
			  //	At this point we don't know if we have an op->term mapping
			  //	or a generic op->op mapping so we save the from description and
			  //	press on.
			  //
			  opDescription = lexerBubble;
			  lexBubble(END_STATEMENT, 1)
			;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 576 "surface.yy"
    {
			  if (lexerBubble[0].code() == Token::encode("term"))
			    {
			      //
			      //	Op->term mapping.
			      //
			      CV->addOpTermMapping(opDescription, lexerBubble);
			    }
			  else
			    {
			      //
			      //	Generic op->op mapping.
			      //
			      Token::peelParens(opDescription);  // remove any enclosing parens from op name
			      CV->addOpMapping(opDescription);
			      Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			      CV->addOpTarget(lexerBubble);
			    }
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 598 "surface.yy"
    {;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 600 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  lexerBubble.append(t);
			;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 608 "surface.yy"
    { lexBubble(BAR_RIGHT_PAREN, 1); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 609 "surface.yy"
    {;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 615 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 617 "surface.yy"
    {
			  interpreter.setCurrentModule(new SyntacticPreModule((yyvsp[(1) - (3)].yyToken), (yyvsp[(3) - (3)].yyToken)));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule((yyvsp[(1) - (3)].yyToken), (yyvsp[(3) - (3)].yyToken));
			;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 623 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule((yyvsp[(8) - (8)].yyToken));
			;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 630 "surface.yy"
    {;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 632 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  store(t);
			;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 640 "surface.yy"
    {;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 649 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter((yyvsp[(1) - (3)].yyToken), me);
			;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 656 "surface.yy"
    {;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 658 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			    ": saw " << QUOTE(':') << " instead of " <<
			    QUOTE("::") << " in parameter declaration.");
			;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 666 "surface.yy"
    {
			  singleton[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(singleton[0]);
			  currentSyntaxContainer->addType(false, singleton);
			  (yyval.yyToken) = (yyvsp[(1) - (1)].yyToken);  // needed for line number
			;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 675 "surface.yy"
    {;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 686 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport((yyvsp[(1) - (2)].yyToken), me);
			;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 692 "surface.yy"
    { clear(); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 693 "surface.yy"
    { CM->addSortDecl(tokenSequence); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 695 "surface.yy"
    { clear(); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 696 "surface.yy"
    { CM->addSubsortDecl(tokenSequence); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 698 "surface.yy"
    { lexBubble(BAR_COLON, 1); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 699 "surface.yy"
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 700 "surface.yy"
    {;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 702 "surface.yy"
    {;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 704 "surface.yy"
    {;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 706 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON, 1); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 707 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 708 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 710 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON, 1);  ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 711 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 712 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 713 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 715 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_EQUALS, 1); ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 716 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 717 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 719 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_EQUALS, 1); ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 720 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 721 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 722 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 724 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_ARROW2, 1); ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 725 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 726 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 728 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_ARROW2, 1); ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 729 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 730 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 731 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 733 "surface.yy"
    { lexBubble(BAR_COLON, 1); ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 734 "surface.yy"
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 735 "surface.yy"
    { CM->setFlag(SymbolType::MESSAGE); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 738 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 743 "surface.yy"
    {
			;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 746 "surface.yy"
    {
			;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 749 "surface.yy"
    { clear(); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 750 "surface.yy"
    { CM->addSubsortDecl(tokenSequence); ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 753 "surface.yy"
    {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeOpDeclsConsistent();
			;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 763 "surface.yy"
    {;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 764 "surface.yy"
    {;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 772 "surface.yy"
    {
			;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 776 "surface.yy"
    { currentSyntaxContainer->addVarDecl((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 777 "surface.yy"
    { currentSyntaxContainer->addVarDecl((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 784 "surface.yy"
    { singleton[0] = (yyvsp[(1) - (1)].yyToken); CM->addOpDecl(singleton); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 785 "surface.yy"
    { CM->addOpDecl(lexerBubble); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 791 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) <<
				       ": missing " << QUOTE("->") << " in constant declaration.");
			;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 798 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
				       ": skipping stray " << QUOTE(":") << " in operator declaration.");

			;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 808 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 813 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 820 "surface.yy"
    {
			  if ((yyvsp[(1) - (2)].yyBool))
			    CM->convertSortsToKinds();
			;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 827 "surface.yy"
    {;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 830 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 831 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 839 "surface.yy"
    {
			  singleton[0] = (yyvsp[(1) - (1)].yyToken);
			  currentSyntaxContainer->addType(false, singleton);
			;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 843 "surface.yy"
    { clear(); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 845 "surface.yy"
    {
			  currentSyntaxContainer->addType(true, tokenSequence);
			;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 850 "surface.yy"
    { store((yyvsp[(3) - (3)].yyToken)); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 851 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 854 "surface.yy"
    {;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 863 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 867 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 871 "surface.yy"
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 877 "surface.yy"
    {
			  CM->setFlag(SymbolType::ASSOC);
			;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 881 "surface.yy"
    {
			  CM->setFlag(SymbolType::COMM);
			;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 884 "surface.yy"
    { lexBubble(BAR_RIGHT_BRACKET | BAR_OP_ATTRIBUTE, 1); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 885 "surface.yy"
    { CM->setIdentity(lexerBubble); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 887 "surface.yy"
    {
			  CM->setFlag(SymbolType::IDEM);
			;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 891 "surface.yy"
    {
			  CM->setFlag(SymbolType::ITER);
			;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 894 "surface.yy"
    { CM->setPrec((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 895 "surface.yy"
    { clear(); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 896 "surface.yy"
    { CM->setGather(tokenSequence); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 897 "surface.yy"
    { clear(); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 898 "surface.yy"
    { CM->setFormat(tokenSequence); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 899 "surface.yy"
    { clear(); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 900 "surface.yy"
    { CM->setStrat(tokenSequence); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 901 "surface.yy"
    { clear(); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 902 "surface.yy"
    { CM->setPoly(tokenSequence); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 904 "surface.yy"
    {
			  CM->setFlag(SymbolType::MEMO);
			;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 908 "surface.yy"
    {
			  CM->setFlag(SymbolType::CTOR);
			;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 912 "surface.yy"
    {
			  clear();
			  CM->setFrozen(tokenSequence);
			;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 916 "surface.yy"
    { clear(); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 917 "surface.yy"
    { CM->setFrozen(tokenSequence); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 919 "surface.yy"
    {
			  CM->setFlag(SymbolType::CONFIG);
			;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 923 "surface.yy"
    {
			  CM->setFlag(SymbolType::OBJECT);
			;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 927 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 931 "surface.yy"
    {
			  CM->setMetadata((yyvsp[(2) - (2)].yyToken));
			;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 934 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 935 "surface.yy"
    { CM->setLatexMacro((yyvsp[(4) - (5)].yyString)); ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 936 "surface.yy"
    {;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 938 "surface.yy"
    {
			  CM->setFlag(SymbolType::DITTO);
			;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 951 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 952 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 959 "surface.yy"
    { clear(); CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[(2) - (2)].yyToken), tokenSequence); ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 960 "surface.yy"
    { CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 961 "surface.yy"
    { CM->addHook(SyntacticPreModule::OP_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 962 "surface.yy"
    { CM->addHook(SyntacticPreModule::TERM_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 968 "surface.yy"
    {;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 970 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing " <<
				       QUOTE("is") << " keyword.");
			;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 976 "surface.yy"
    {;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 978 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 986 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 990 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 991 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 992 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 993 "surface.yy"
    { store((yyvsp[(4) - (4)].yyToken)); ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1000 "surface.yy"
    {
			  Token t;
			  if (fragments.size() == 1)
			    t = fragments[0];
			  else
			    t.tokenize(Token::bubbleToPrefixNameCode(fragments), fragments[0].lineNumber());
			  fragClear();
			  (yyval.yyToken) = t;
			;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1011 "surface.yy"
    { fragStore((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1012 "surface.yy"
    { fragStore((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1013 "surface.yy"
    { fragStore((yyvsp[(5) - (5)].yyToken)); ;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1016 "surface.yy"
    { fragStore((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1017 "surface.yy"
    {;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1018 "surface.yy"
    {;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1098 "surface.yy"
    { lexBubble(END_COMMAND, 1) ;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1100 "surface.yy"
    {
			  interpreter.setCurrentModule(lexerBubble);
			;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1103 "surface.yy"
    { lexBubble(END_COMMAND, 1) ;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1105 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->dump();
			;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1110 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1115 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(lexerBubble);
			;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1122 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1127 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(lexerBubble);
			;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1134 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1139 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sreduce(lexerBubble);
			;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1146 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1151 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(lexerBubble, (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1158 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1164 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(lexerBubble, number, (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1170 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1177 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(lexerBubble, number, number2, (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1183 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1190 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(lexerBubble, number, number2, (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1196 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1202 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1208 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1215 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, (yyvsp[(1) - (3)].yySearchKind));
			;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1221 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1227 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(lexerBubble, (yyvsp[(1) - (3)].yyBool), number);
			;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1233 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1239 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.unify(lexerBubble, number);
			;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1245 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1251 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantUnify(lexerBubble, number, (yyvsp[(1) - (5)].yyBool));
			;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1258 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1264 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.getVariants(lexerBubble, number, (yyvsp[(1) - (5)].yyBool));
			;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1270 "surface.yy"
    {
			  interpreter.cont((yyvsp[(3) - (4)].yyInt64), (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1274 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1279 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(lexerBubble);
			;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1285 "surface.yy"
    {
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(lexerBubble);
			;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1290 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1292 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1296 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1298 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1302 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1304 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1308 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1310 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1315 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1322 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1324 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1328 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1330 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1334 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1336 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(true);
			;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1340 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1342 "surface.yy"
    {
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showView();
			;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1347 "surface.yy"
    {
			  interpreter.showModules(true);
			;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1351 "surface.yy"
    {
			  interpreter.showNamedViews();
			;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1354 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1356 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSortsAndSubsorts();
			;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1360 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1362 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showOps();
			;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1366 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1368 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showVars();
			;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1372 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1374 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showMbs();
			;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1378 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1380 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showEqs();
			;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1384 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1386 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showRls();
			;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1390 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 1392 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSummary();
			;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 1396 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1398 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showKinds();
			;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1403 "surface.yy"
    {
			  interpreter.showSearchPath((yyvsp[(3) - (4)].yyInt64));
			;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 1407 "surface.yy"
    {
			  interpreter.showSearchPathLabels((yyvsp[(4) - (5)].yyInt64));
			;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 1411 "surface.yy"
    {
			  interpreter.showSearchGraph();
			;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1414 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1416 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showProfile();
			;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1424 "surface.yy"
    {
			  globalAdvisoryFlag = (yyvsp[(4) - (5)].yyBool);
			;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 1428 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 1432 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, (yyvsp[(5) - (6)].yyBool));
			;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1436 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1440 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1444 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, (yyvsp[(5) - (6)].yyBool));
			;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1448 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1452 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 1456 "surface.yy"
    {
			  interpreter.setPrintFlag((yyvsp[(3) - (5)].yyPrintFlags), (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 1460 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 1464 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE_NEWLINE, (yyvsp[(5) - (6)].yyBool));
			;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 1468 "surface.yy"
    {
			  interpreter.setFlag((yyvsp[(3) - (5)].yyFlags), (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 1472 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, (yyvsp[(3) - (4)].yyBool));
			;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 1475 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 1476 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 1478 "surface.yy"
    {
			  interpreter.setAutoImport((yyvsp[(2) - (7)].yyImportMode), (yyvsp[(4) - (7)].yyToken), (yyvsp[(6) - (7)].yyBool));
			;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 1481 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 1482 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 1484 "surface.yy"
    {
			  interpreter.setOmodInclude((yyvsp[(5) - (8)].yyToken), (yyvsp[(7) - (8)].yyBool));
			;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 1488 "surface.yy"
    {
			  globalVerboseFlag = (yyvsp[(3) - (4)].yyBool);
			;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 1492 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 1496 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 1500 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 1504 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, (yyvsp[(3) - (4)].yyBool));
			;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 1508 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 1515 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 1519 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 1523 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 1527 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 1534 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 1538 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[(3) - (4)].yyBool));
			;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 1544 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 1551 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_MIXFIX; ;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 1552 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FLAT; ;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 1553 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_ALIASES; ;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 1554 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_PARENS; ;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 1555 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_GRAPH; ;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 1556 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_CONCEAL; ;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 1557 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_NUMBER; ;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 1558 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_RAT; ;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 1559 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_COLOR; ;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 1560 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FORMAT; ;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 1563 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE; ;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 1564 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_CONDITION; ;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 1565 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_WHOLE; ;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 1566 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SUBSTITUTION; ;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 1567 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SELECT; ;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 1568 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_MB; ;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 1569 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_EQ; ;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 1570 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_RL; ;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 1571 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_REWRITE; ;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 1572 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BODY; ;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 1573 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BUILTIN; ;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 1576 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 1577 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 1580 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 1581 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 1584 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 1585 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 1588 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 1589 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 1594 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::NARROW; ;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 1595 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::XG_NARROW; ;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 1596 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::SEARCH; ;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 1599 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 1600 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 1603 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 1604 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 1607 "surface.yy"
    { (yyval.yyInt64) = (yyvsp[(1) - (1)].yyInt64); ;}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 1608 "surface.yy"
    { (yyval.yyInt64) = NONE; ;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 1611 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::PROTECTING; ;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 1612 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::EXTENDING; ;}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 1613 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::INCLUDING; ;}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 1623 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 1627 "surface.yy"
    { moduleExpr = lexerBubble; lexBubble(END_COMMAND, 1); ;}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 1639 "surface.yy"
    { lexSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 1642 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0);  ;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 1647 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 1649 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 1655 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); ;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 1657 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 1672 "surface.yy"
    { lexSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 1675 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 1684 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 1686 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 1688 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 1698 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); ;}
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 1700 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 1702 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 1712 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 1714 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 1725 "surface.yy"
    {
			  number = Token::codeToInt64(lexerBubble[1].code());
			  number2 = Token::codeToInt64(lexerBubble[3].code());
			  clear();
			;}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 1731 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 1741 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 1743 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 1753 "surface.yy"
    { number2 = Token::codeToInt64(lexerBubble[2].code()); ;}
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 1755 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 555:

/* Line 1455 of yacc.c  */
#line 1760 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0, 1); ;}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 1766 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 1, 1); ;}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 1768 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON | END_COMMAND, 0); ;}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 1771 "surface.yy"
    {
			  lexerBubble.resize(1);
			  lexerBubble[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(lexerBubble[0]);
			;}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 1810 "surface.yy"
    {;}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 1815 "surface.yy"
    {
			  singleton[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(singleton[0]);
			  interpreter.addSelected(singleton);
			;}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 1826 "surface.yy"
    {
			  singleton[0] = (yyvsp[(1) - (1)].yyToken);
			  interpreter.addSelected(singleton);
			;}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 1831 "surface.yy"
    {
			  interpreter.addSelected(lexerBubble);
			;}
    break;



/* Line 1455 of yacc.c  */
#line 5963 "surface.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1861 "surface.yy"


static void
yyerror(char *s)
{
  if (!(UserLevelRewritingContext::interrupted()))
    IssueWarning(LineNumber(lineNumber) << ": " << s);
}

void
cleanUpModuleExpression()
{
  //
  //	Delete pieces of a partly built module expression.
  //
  delete currentRenaming;
  currentRenaming = 0;
  while (!moduleExpressions.empty())
    {
      moduleExpressions.top()->deepSelfDestruct();
      moduleExpressions.pop();
    }
}

void
cleanUpParser()
{
  interpreter.makeClean(lineNumber);
}

void
missingSpace(const Token& token)
{
  IssueWarning(LineNumber(token.lineNumber()) << ": missing space between " <<
	       QUOTE(token) << " and period.");
}

