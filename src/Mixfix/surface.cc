
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
     KW_GENERATE = 274,
     KW_VARIANTS = 275,
     KW_EREWRITE = 276,
     KW_FREWRITE = 277,
     KW_SREWRITE = 278,
     KW_CONTINUE = 279,
     KW_SEARCH = 280,
     KW_SET = 281,
     KW_SHOW = 282,
     KW_ON = 283,
     KW_OFF = 284,
     KW_TRACE = 285,
     KW_BODY = 286,
     KW_BUILTIN = 287,
     KW_WHOLE = 288,
     KW_SELECT = 289,
     KW_DESELECT = 290,
     KW_CONDITION = 291,
     KW_SUBSTITUTION = 292,
     KW_PRINT = 293,
     KW_GRAPH = 294,
     KW_MIXFIX = 295,
     KW_FLAT = 296,
     KW_ATTRIBUTE = 297,
     KW_NEWLINE = 298,
     KW_WITH = 299,
     KW_PARENS = 300,
     KW_ALIASES = 301,
     KW_GC = 302,
     KW_TIME = 303,
     KW_STATS = 304,
     KW_TIMING = 305,
     KW_CMD = 306,
     KW_BREAKDOWN = 307,
     KW_BREAK = 308,
     KW_PATH = 309,
     KW_MODULE = 310,
     KW_MODULES = 311,
     KW_VIEWS = 312,
     KW_ALL = 313,
     KW_SORTS = 314,
     KW_OPS2 = 315,
     KW_VARS = 316,
     KW_MBS = 317,
     KW_EQS = 318,
     KW_RLS = 319,
     KW_SUMMARY = 320,
     KW_KINDS = 321,
     KW_ADVISE = 322,
     KW_VERBOSE = 323,
     KW_DO = 324,
     KW_CLEAR = 325,
     KW_PROTECT = 326,
     KW_EXTEND = 327,
     KW_INCLUDE = 328,
     KW_EXCLUDE = 329,
     KW_CONCEAL = 330,
     KW_REVEAL = 331,
     KW_COMPILE = 332,
     KW_COUNT = 333,
     KW_DEBUG = 334,
     KW_RESUME = 335,
     KW_ABORT = 336,
     KW_STEP = 337,
     KW_WHERE = 338,
     KW_CREDUCE = 339,
     KW_SREDUCE = 340,
     KW_DUMP = 341,
     KW_PROFILE = 342,
     KW_NUMBER = 343,
     KW_RAT = 344,
     KW_COLOR = 345,
     SIMPLE_NUMBER = 346,
     KW_PWD = 347,
     KW_CD = 348,
     KW_PUSHD = 349,
     KW_POPD = 350,
     KW_LS = 351,
     KW_LOAD = 352,
     KW_QUIT = 353,
     KW_EOF = 354,
     KW_ENDM = 355,
     KW_IMPORT = 356,
     KW_ENDV = 357,
     KW_SORT = 358,
     KW_SUBSORT = 359,
     KW_OP = 360,
     KW_OPS = 361,
     KW_MSGS = 362,
     KW_VAR = 363,
     KW_CLASS = 364,
     KW_SUBCLASS = 365,
     KW_MB = 366,
     KW_CMB = 367,
     KW_EQ = 368,
     KW_CEQ = 369,
     KW_RL = 370,
     KW_CRL = 371,
     KW_IS = 372,
     KW_FROM = 373,
     KW_ARROW = 374,
     KW_ARROW2 = 375,
     KW_PARTIAL = 376,
     KW_IF = 377,
     KW_LABEL = 378,
     KW_TO = 379,
     KW_COLON2 = 380,
     KW_ASSOC = 381,
     KW_COMM = 382,
     KW_ID = 383,
     KW_IDEM = 384,
     KW_ITER = 385,
     KW_LEFT = 386,
     KW_RIGHT = 387,
     KW_PREC = 388,
     KW_GATHER = 389,
     KW_METADATA = 390,
     KW_STRAT = 391,
     KW_POLY = 392,
     KW_MEMO = 393,
     KW_FROZEN = 394,
     KW_CTOR = 395,
     KW_LATEX = 396,
     KW_SPECIAL = 397,
     KW_CONFIG = 398,
     KW_OBJ = 399,
     KW_MSG = 400,
     KW_DITTO = 401,
     KW_FORMAT = 402,
     KW_ID_HOOK = 403,
     KW_OP_HOOK = 404,
     KW_TERM_HOOK = 405,
     KW_IN = 406,
     IDENTIFIER = 407,
     NUMERIC_ID = 408,
     ENDS_IN_DOT = 409,
     FORCE_LOOKAHEAD = 410
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
#line 352 "surface.c"
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
#line 369 "surface.c"

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
#define YYFINAL  115
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2350

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  170
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  243
/* YYNRULES -- Number of rules.  */
#define YYNRULES  613
/* YYNRULES -- Number of states.  */
#define YYNSTATES  917

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   410

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     125,   126,   137,   136,   131,     2,   127,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   123,     2,
     128,   124,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   129,     2,   130,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   138,   132,   139,     2,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121,   122,   133,   134,
     135,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169
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
     937,   941,   942,   946,   947,   951,   956,   957,   961,   963,
     964,   969,   970,   975,   976,   981,   982,   987,   992,   993,
     998,   999,  1004,  1005,  1010,  1011,  1016,  1020,  1024,  1025,
    1030,  1031,  1036,  1037,  1042,  1043,  1048,  1049,  1054,  1055,
    1060,  1061,  1066,  1067,  1072,  1077,  1083,  1088,  1089,  1094,
    1100,  1106,  1113,  1119,  1125,  1132,  1138,  1144,  1150,  1156,
    1163,  1169,  1174,  1175,  1176,  1184,  1185,  1186,  1195,  1200,
    1206,  1212,  1218,  1223,  1229,  1232,  1235,  1238,  1241,  1247,
    1252,  1253,  1257,  1259,  1262,  1264,  1266,  1269,  1272,  1274,
    1276,  1278,  1280,  1282,  1284,  1285,  1287,  1289,  1291,  1293,
    1295,  1297,  1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,
    1315,  1317,  1319,  1321,  1323,  1325,  1327,  1329,  1331,  1333,
    1334,  1336,  1337,  1339,  1341,  1343,  1345,  1346,  1350,  1351,
    1355,  1357,  1358,  1362,  1364,  1365,  1369,  1370,  1374,  1375,
    1379,  1381,  1382,  1386,  1387,  1391,  1393,  1394,  1398,  1400,
    1401,  1405,  1406,  1410,  1411,  1415,  1416,  1420,  1422,  1423,
    1427,  1428,  1432,  1433,  1437,  1439,  1440,  1444,  1445,  1449,
    1451,  1452,  1456,  1457,  1461,  1463,  1464,  1468,  1469,  1473,
    1475,  1476,  1480,  1481,  1485,  1487,  1488,  1492,  1494,  1495,
    1499,  1500,  1504,  1506,  1508,  1510,  1512,  1514,  1516,  1518,
    1520,  1522,  1524,  1526,  1528,  1530,  1532,  1534,  1536,  1538,
    1540,  1542,  1544,  1546,  1548,  1550,  1552,  1554,  1556,  1558,
    1560,  1562,  1564,  1566,  1568,  1570,  1572,  1574,  1576,  1579,
    1581,  1583,  1585,  1587,  1590,  1592,  1594,  1596,  1598,  1600,
    1602,  1604,  1606,  1608
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     171,     0,    -1,   172,    -1,    -1,   221,    -1,   205,    -1,
     173,    -1,   310,    -1,    -1,   165,   174,     3,    -1,    -1,
      97,   175,     3,    -1,    92,    -1,    -1,    93,   176,     3,
      -1,    -1,    94,   177,     3,    -1,    95,    -1,    -1,    96,
     178,     4,    -1,    98,    -1,    99,    -1,   299,   289,    -1,
     302,   127,    -1,   186,   289,    -1,   183,   289,    -1,   184,
     289,    -1,   180,   136,   179,    -1,   168,    -1,   181,    -1,
     180,   136,   180,    -1,   182,    -1,   183,    -1,   186,    -1,
     184,    -1,   298,    -1,   181,   137,   188,    -1,    -1,   182,
     138,   185,   187,   139,    -1,   125,   180,   126,    -1,   187,
     131,   298,    -1,   298,    -1,    -1,    -1,   125,   189,   191,
     190,   126,    -1,   192,    -1,     1,    -1,   192,   131,   193,
      -1,   193,    -1,   103,   293,   134,   293,    -1,   133,   298,
     134,   298,    -1,    -1,    -1,   105,   194,   196,   134,   195,
     198,    -1,    -1,   123,   197,   269,   268,   270,    -1,    -1,
      -1,   129,   199,   200,   130,    -1,    -1,   200,   201,    -1,
     201,    -1,   147,   166,    -1,    -1,   148,   125,   202,   285,
     126,    -1,    -1,   161,   125,   203,   285,   126,    -1,    -1,
     155,   125,   204,     5,   126,    -1,    -1,    -1,    -1,     8,
     206,   298,   118,   180,   207,   134,   180,   208,   288,   209,
     102,    -1,   209,   211,    -1,    -1,   119,    -1,    -1,   103,
     293,   134,   213,    -1,   108,   260,   123,   210,   230,    -1,
      -1,   105,   212,   214,    -1,     1,   127,    -1,   293,   289,
      -1,   168,    -1,    -1,    -1,   123,   215,   269,   268,   270,
     134,   216,   218,    -1,    -1,   134,   217,   218,    -1,   127,
      -1,   168,    -1,    -1,   125,   220,   126,    -1,    -1,    -1,
     231,   222,   298,   223,   225,   288,   232,   100,    -1,   127,
      -1,   168,    -1,   138,   226,   139,    -1,    -1,   226,   131,
     227,    -1,   227,    -1,   298,   228,   180,    -1,   135,    -1,
     123,    -1,   168,    -1,   270,   289,    -1,   229,    -1,     6,
      -1,     7,    -1,   232,   233,    -1,    -1,   101,   179,    -1,
      -1,   103,   234,   290,   224,    -1,    -1,   104,   235,   291,
     224,    -1,    -1,    -1,   105,   236,   123,   237,   263,    -1,
     106,   261,   123,   263,    -1,   108,   260,   123,   210,   230,
      -1,    -1,    -1,   111,   238,   123,   239,   218,    -1,    -1,
      -1,    -1,   112,   240,   123,   241,   122,   242,   218,    -1,
      -1,    -1,   113,   243,   124,   244,   218,    -1,    -1,    -1,
      -1,   114,   245,   124,   246,   122,   247,   218,    -1,    -1,
      -1,   115,   248,   120,   249,   218,    -1,    -1,    -1,    -1,
     116,   250,   120,   251,   122,   252,   218,    -1,    -1,    -1,
     159,   253,   123,   254,   263,    -1,   107,   261,   123,   263,
      -1,    -1,   109,   298,   255,   257,   127,    -1,    -1,   110,
     256,   291,   224,    -1,     1,   127,    -1,   132,    -1,   132,
     258,    -1,   259,    -1,   258,   131,   259,    -1,   299,   123,
     298,    -1,   260,   300,    -1,   300,    -1,   261,   262,    -1,
     262,    -1,   300,    -1,   219,    -1,   270,   269,   265,    -1,
     266,    -1,   229,    -1,   123,    -1,    -1,   264,   266,    -1,
     127,    -1,   229,    -1,   268,   267,    -1,   270,   273,   289,
      -1,   229,    -1,   119,    -1,   121,    -1,   269,   270,    -1,
      -1,   293,    -1,    -1,   129,   271,   272,   130,    -1,   272,
     131,   293,    -1,   293,    -1,   129,   274,   130,    -1,    -1,
     274,   276,    -1,   276,    -1,   142,    -1,   145,   142,    -1,
     146,   142,    -1,   140,    -1,   141,    -1,    -1,   275,   277,
     284,    -1,   143,    -1,   144,    -1,   147,   166,    -1,    -1,
     148,   125,   278,   285,   126,    -1,    -1,   161,   125,   279,
     285,   126,    -1,    -1,   150,   125,   280,   285,   126,    -1,
      -1,   151,   125,   281,   285,   126,    -1,   152,    -1,   154,
      -1,   153,    -1,    -1,   153,   125,   282,   285,   126,    -1,
     157,    -1,   158,    -1,   159,    -1,   149,   166,    -1,    -1,
     155,   125,   283,     5,   126,    -1,   156,   125,   286,   126,
      -1,   160,    -1,   169,    -1,    -1,   285,   166,    -1,   166,
      -1,   286,   287,    -1,   287,    -1,   162,   298,    -1,   162,
     298,   219,    -1,   163,   298,   219,    -1,   164,   298,   219,
      -1,   117,    -1,    -1,   127,    -1,    -1,   290,   293,    -1,
      -1,   291,   293,    -1,   291,   128,    -1,    -1,   293,   292,
     290,   128,    -1,   294,    -1,   301,    -1,    -1,   294,   138,
     295,   296,   139,    -1,    -1,   296,   131,   297,   294,    -1,
     294,    -1,   304,    -1,   305,    -1,   307,    -1,   308,    -1,
     127,    -1,   303,    -1,   131,    -1,   134,    -1,   305,    -1,
     307,    -1,   308,    -1,   304,    -1,   305,    -1,   308,    -1,
     127,    -1,   128,    -1,   119,    -1,   121,    -1,   124,    -1,
     120,    -1,   122,    -1,   166,    -1,   305,    -1,   309,    -1,
     124,    -1,   132,    -1,   136,    -1,   137,    -1,   120,    -1,
     122,    -1,   117,    -1,   133,    -1,   134,    -1,   127,    -1,
     168,    -1,   166,    -1,   138,    -1,   139,    -1,   136,    -1,
     137,    -1,   132,    -1,   135,    -1,   133,    -1,   118,    -1,
     117,    -1,   303,    -1,   168,    -1,   131,    -1,   134,    -1,
     159,    -1,   306,    -1,   101,    -1,   103,    -1,   104,    -1,
     105,    -1,   106,    -1,   108,    -1,   107,    -1,   109,    -1,
     110,    -1,   111,    -1,   112,    -1,   113,    -1,   114,    -1,
     115,    -1,   116,    -1,   100,    -1,   102,    -1,   128,    -1,
     123,    -1,   119,    -1,   121,    -1,   124,    -1,   120,    -1,
     122,    -1,   129,    -1,   130,    -1,   309,    -1,   140,    -1,
     141,    -1,   142,    -1,   143,    -1,   144,    -1,   145,    -1,
     146,    -1,   147,    -1,   148,    -1,   150,    -1,   151,    -1,
     152,    -1,   154,    -1,   155,    -1,   156,    -1,   153,    -1,
     149,    -1,   157,    -1,   158,    -1,   160,    -1,   161,    -1,
     162,    -1,   163,    -1,   164,    -1,    -1,    34,   311,   218,
      -1,    -1,    86,   312,   218,    -1,    -1,     9,   313,   360,
      -1,    -1,    84,   314,   360,    -1,    -1,    85,   315,   360,
      -1,    -1,   357,    11,   316,   360,    -1,    -1,   357,    12,
     317,   364,    -1,    -1,   357,    21,   318,   373,    -1,    -1,
     357,    22,   319,   373,    -1,    -1,   357,    23,   320,   364,
      -1,    -1,   355,   321,   373,    -1,    -1,   356,   322,   364,
      -1,    -1,    18,   323,   364,    -1,    -1,   348,   324,   364,
      -1,   357,    24,   358,   127,    -1,    -1,    13,   325,   360,
      -1,   219,    -1,    -1,    30,   352,   326,   407,    -1,    -1,
      30,   353,   327,   407,    -1,    -1,    53,   352,   328,   407,
      -1,    -1,    38,   354,   329,   407,    -1,    69,    70,   152,
     127,    -1,    -1,    27,     6,   330,   218,    -1,    -1,    27,
      55,   331,   218,    -1,    -1,    27,    58,   332,   218,    -1,
      -1,    27,     8,   333,   218,    -1,    27,    56,   127,    -1,
      27,    57,   127,    -1,    -1,    27,    59,   334,   218,    -1,
      -1,    27,    60,   335,   218,    -1,    -1,    27,    61,   336,
     218,    -1,    -1,    27,    62,   337,   218,    -1,    -1,    27,
      63,   338,   218,    -1,    -1,    27,    64,   339,   218,    -1,
      -1,    27,    65,   340,   218,    -1,    -1,    27,    66,   341,
     218,    -1,    27,    54,    91,   127,    -1,    27,    54,   133,
      91,   127,    -1,    27,    25,    39,   127,    -1,    -1,    27,
      87,   342,   218,    -1,    26,    27,    67,   351,   127,    -1,
      26,    27,    49,   351,   127,    -1,    26,    27,    13,    49,
     351,   127,    -1,    26,    27,    50,   351,   127,    -1,    26,
      27,    52,   351,   127,    -1,    26,    27,    13,    50,   351,
     127,    -1,    26,    27,    51,   351,   127,    -1,    26,    27,
      47,   351,   127,    -1,    26,    38,   349,   351,   127,    -1,
      26,    38,    42,   351,   127,    -1,    26,    38,    42,    43,
     351,   127,    -1,    26,    30,   350,   351,   127,    -1,    26,
      53,   351,   127,    -1,    -1,    -1,    26,   359,   343,   412,
     344,   351,   127,    -1,    -1,    -1,    26,     7,    73,   345,
     412,   346,   351,   127,    -1,    26,    68,   351,   127,    -1,
      26,    70,   152,   351,   127,    -1,    26,    70,    64,   351,
     127,    -1,    26,    77,    78,   351,   127,    -1,    26,    87,
     351,   127,    -1,    26,    70,    87,   351,   127,    -1,    80,
     127,    -1,    81,   127,    -1,    82,   127,    -1,    83,   127,
      -1,    26,    47,    27,   351,   127,    -1,    26,    49,   351,
     127,    -1,    -1,     1,   347,   127,    -1,    61,    -1,    19,
      20,    -1,    40,    -1,    41,    -1,    44,    46,    -1,    44,
      45,    -1,    39,    -1,    75,    -1,    88,    -1,    89,    -1,
      90,    -1,   161,    -1,    -1,    36,    -1,    33,    -1,    37,
      -1,    34,    -1,    62,    -1,    63,    -1,    64,    -1,    12,
      -1,    31,    -1,    32,    -1,    28,    -1,    29,    -1,    34,
      -1,    35,    -1,    74,    -1,    73,    -1,    75,    -1,    76,
      -1,    14,    -1,    15,    -1,    25,    -1,    17,    -1,    16,
      -1,    79,    -1,    -1,    91,    -1,    -1,    71,    -1,    72,
      -1,    73,    -1,   398,    -1,    -1,   401,   361,   218,    -1,
      -1,   123,   363,   218,    -1,   218,    -1,    -1,   129,   365,
     367,    -1,   398,    -1,    -1,   402,   366,   218,    -1,    -1,
     167,   368,   370,    -1,    -1,   403,   369,   218,    -1,   396,
      -1,    -1,   130,   371,   360,    -1,    -1,   404,   372,   218,
      -1,   396,    -1,    -1,   129,   374,   376,    -1,   398,    -1,
      -1,   402,   375,   218,    -1,    -1,   167,   377,   380,    -1,
      -1,   131,   378,   390,    -1,    -1,   405,   379,   218,    -1,
     396,    -1,    -1,   130,   381,   360,    -1,    -1,   131,   382,
     384,    -1,    -1,   406,   383,   218,    -1,   396,    -1,    -1,
     167,   385,   387,    -1,    -1,   403,   386,   218,    -1,   396,
      -1,    -1,   130,   388,   360,    -1,    -1,   404,   389,   218,
      -1,   396,    -1,    -1,   167,   391,   393,    -1,    -1,   403,
     392,   218,    -1,   396,    -1,    -1,   130,   394,   360,    -1,
      -1,   404,   395,   218,    -1,   396,    -1,    -1,   125,   397,
     218,    -1,   218,    -1,    -1,   125,   399,   218,    -1,    -1,
     165,   400,   362,    -1,   168,    -1,   166,    -1,   167,    -1,
     129,    -1,   130,    -1,   123,    -1,   127,    -1,   131,    -1,
     166,    -1,   167,    -1,   130,    -1,   123,    -1,   127,    -1,
     131,    -1,   166,    -1,   129,    -1,   130,    -1,   165,    -1,
     123,    -1,   131,    -1,   166,    -1,   167,    -1,   129,    -1,
     165,    -1,   123,    -1,   131,    -1,   166,    -1,   129,    -1,
     130,    -1,   165,    -1,   123,    -1,   166,    -1,   167,    -1,
     129,    -1,   165,    -1,   123,    -1,   410,   408,    -1,   409,
      -1,   127,    -1,   409,    -1,   168,    -1,   410,   411,    -1,
     411,    -1,   412,    -1,   219,    -1,   166,    -1,   167,    -1,
     129,    -1,   130,    -1,   165,    -1,   123,    -1,   131,    -1
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
    1220,  1233,  1232,  1245,  1244,  1256,  1261,  1260,  1271,  1277,
    1277,  1283,  1283,  1289,  1289,  1295,  1295,  1301,  1309,  1309,
    1315,  1315,  1321,  1321,  1327,  1327,  1333,  1337,  1341,  1341,
    1347,  1347,  1353,  1353,  1359,  1359,  1365,  1365,  1371,  1371,
    1377,  1377,  1383,  1383,  1389,  1393,  1397,  1401,  1401,  1410,
    1414,  1418,  1422,  1426,  1430,  1434,  1438,  1442,  1446,  1450,
    1454,  1458,  1462,  1463,  1462,  1468,  1469,  1468,  1474,  1478,
    1482,  1486,  1490,  1494,  1501,  1505,  1509,  1513,  1520,  1524,
    1531,  1531,  1535,  1536,  1542,  1543,  1544,  1545,  1546,  1547,
    1548,  1549,  1550,  1551,  1554,  1555,  1556,  1557,  1558,  1559,
    1560,  1561,  1562,  1563,  1564,  1567,  1568,  1571,  1572,  1575,
    1576,  1579,  1580,  1585,  1586,  1587,  1590,  1591,  1594,  1595,
    1598,  1599,  1602,  1603,  1604,  1613,  1614,  1614,  1618,  1618,
    1620,  1630,  1630,  1632,  1633,  1633,  1638,  1638,  1640,  1640,
    1642,  1646,  1646,  1648,  1648,  1650,  1663,  1663,  1665,  1666,
    1666,  1675,  1675,  1677,  1677,  1679,  1679,  1681,  1689,  1689,
    1691,  1691,  1693,  1693,  1695,  1703,  1703,  1705,  1705,  1707,
    1716,  1715,  1722,  1722,  1724,  1732,  1732,  1734,  1734,  1736,
    1744,  1744,  1746,  1746,  1748,  1751,  1751,  1753,  1757,  1757,
    1759,  1759,  1761,  1772,  1772,  1772,  1772,  1772,  1772,  1772,
    1775,  1775,  1775,  1775,  1775,  1775,  1779,  1779,  1779,  1779,
    1779,  1779,  1783,  1783,  1783,  1783,  1783,  1783,  1787,  1787,
    1787,  1787,  1787,  1791,  1791,  1791,  1791,  1791,  1797,  1798,
    1801,  1802,  1805,  1812,  1813,  1816,  1821,  1828,  1828,  1828,
    1828,  1828,  1828,  1828
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
  "KW_GENERATE", "KW_VARIANTS", "KW_EREWRITE", "KW_FREWRITE",
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
  "$@96", "genvars", "printOption", "traceOption", "polarity", "select",
  "exclude", "conceal", "search", "match", "optDebug", "optNumber",
  "importMode", "moduleAndTerm", "$@97", "inEnd", "$@98",
  "numberModuleTerm", "$@99", "$@100", "numberModuleTerm1", "$@101",
  "$@102", "numberModuleTerm2", "$@103", "$@104", "numbersModuleTerm",
  "$@105", "$@106", "numbersModuleTerm1", "$@107", "$@108", "$@109",
  "numbersModuleTerm2", "$@110", "$@111", "$@112", "numbersModuleTerm3",
  "$@113", "$@114", "numbersModuleTerm4", "$@115", "$@116",
  "numbersModuleTerm5", "$@117", "$@118", "numbersModuleTerm6", "$@119",
  "$@120", "miscEndBubble", "$@121", "initialEndBubble", "$@122", "$@123",
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
     375,   376,   377,    58,    61,    40,    41,    46,    60,    91,
      93,    44,   124,   378,   379,   380,    43,    42,   123,   125,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   170,   171,   171,   172,   172,   172,   172,   174,   173,
     175,   173,   173,   176,   173,   177,   173,   173,   178,   173,
     173,   173,   179,   179,   179,   179,   179,   179,   179,   180,
     180,   181,   181,   182,   182,   182,   183,   185,   184,   186,
     187,   187,   189,   190,   188,   191,   191,   192,   192,   193,
     193,   194,   195,   193,   197,   196,   196,   199,   198,   198,
     200,   200,   201,   202,   201,   203,   201,   204,   201,   206,
     207,   208,   205,   209,   209,   210,   210,   211,   211,   212,
     211,   211,   213,   213,   215,   216,   214,   217,   214,   218,
     218,   220,   219,   222,   223,   221,   224,   224,   225,   225,
     226,   226,   227,   228,   228,   229,   230,   230,   231,   231,
     232,   232,   233,   234,   233,   235,   233,   236,   237,   233,
     233,   233,   238,   239,   233,   240,   241,   242,   233,   243,
     244,   233,   245,   246,   247,   233,   248,   249,   233,   250,
     251,   252,   233,   253,   254,   233,   233,   255,   233,   256,
     233,   233,   257,   257,   258,   258,   259,   260,   260,   261,
     261,   262,   262,   263,   263,   263,   264,   264,   265,   265,
     265,   266,   267,   267,   268,   268,   269,   269,   270,   271,
     270,   272,   272,   273,   273,   274,   274,   275,   275,   275,
     276,   276,   277,   276,   276,   276,   276,   278,   276,   279,
     276,   280,   276,   281,   276,   276,   276,   276,   282,   276,
     276,   276,   276,   276,   283,   276,   276,   276,   284,   284,
     285,   285,   286,   286,   287,   287,   287,   287,   288,   288,
     289,   289,   290,   290,   291,   291,   292,   291,   293,   294,
     295,   294,   297,   296,   296,   298,   298,   298,   298,   298,
     299,   299,   299,   299,   299,   299,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   302,   302,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     304,   304,   304,   304,   305,   305,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   307,   307,   307,   307,   307,   307,   307,
     308,   308,   308,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   311,   310,   312,
     310,   313,   310,   314,   310,   315,   310,   316,   310,   317,
     310,   318,   310,   319,   310,   320,   310,   321,   310,   322,
     310,   323,   310,   324,   310,   310,   325,   310,   310,   326,
     310,   327,   310,   328,   310,   329,   310,   310,   330,   310,
     331,   310,   332,   310,   333,   310,   310,   310,   334,   310,
     335,   310,   336,   310,   337,   310,   338,   310,   339,   310,
     340,   310,   341,   310,   310,   310,   310,   342,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   343,   344,   310,   345,   346,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     347,   310,   348,   348,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   351,   351,   352,   352,   353,
     353,   354,   354,   355,   355,   355,   356,   356,   357,   357,
     358,   358,   359,   359,   359,   360,   361,   360,   363,   362,
     362,   365,   364,   364,   366,   364,   368,   367,   369,   367,
     367,   371,   370,   372,   370,   370,   374,   373,   373,   375,
     373,   377,   376,   378,   376,   379,   376,   376,   381,   380,
     382,   380,   383,   380,   380,   385,   384,   386,   384,   384,
     388,   387,   389,   387,   387,   391,   390,   392,   390,   390,
     394,   393,   395,   393,   393,   397,   396,   396,   399,   398,
     400,   398,   398,   401,   401,   401,   401,   401,   401,   401,
     402,   402,   402,   402,   402,   402,   403,   403,   403,   403,
     403,   403,   404,   404,   404,   404,   404,   404,   405,   405,
     405,   405,   405,   406,   406,   406,   406,   406,   407,   407,
     408,   408,   409,   410,   410,   411,   411,   412,   412,   412,
     412,   412,   412,   412
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
       3,     0,     3,     0,     3,     4,     0,     3,     1,     0,
       4,     0,     4,     0,     4,     0,     4,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     3,     3,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     4,     5,     4,     0,     4,     5,
       5,     6,     5,     5,     6,     5,     5,     5,     5,     6,
       5,     4,     0,     0,     7,     0,     0,     8,     4,     5,
       5,     5,     4,     5,     2,     2,     2,     2,     5,     4,
       0,     3,     1,     2,     1,     1,     2,     2,     1,     1,
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
       0,   450,   108,   109,    69,   351,   376,   483,   484,   487,
     486,   371,     0,   485,     0,     0,     0,   347,     0,     0,
     452,     0,   488,     0,     0,     0,     0,   353,   355,   349,
      12,    13,    15,    17,    18,    10,    20,    21,    91,     8,
       0,     2,     6,     5,   378,     4,    93,     7,   373,   367,
     369,     0,     0,     0,     0,     0,     0,   453,     0,     0,
     464,     0,     0,     0,     0,     0,     0,   492,   493,   494,
       0,     0,   432,   388,   394,     0,     0,   390,     0,     0,
     392,   398,   400,   402,   404,   406,   408,   410,   412,   417,
     477,   478,   480,   479,   379,   381,     0,   481,   482,   385,
     383,     0,   444,   445,   446,   447,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
     357,   359,   361,   363,   365,   491,   451,   311,   296,   312,
     297,   298,   299,   300,   302,   301,   303,   304,   305,   306,
     307,   308,   309,   310,   289,   288,   315,   318,   316,   319,
     314,   317,   249,   313,   320,   321,   292,   285,   287,   293,
     286,   283,   284,   281,   282,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   339,   332,   333,   334,   338,   335,
     336,   337,   340,   341,   294,   342,   343,   344,   345,   346,
     280,   291,     0,   290,   245,   246,   295,   247,   248,   322,
     567,   558,   568,   565,   566,   569,   560,   563,   564,   562,
     352,   495,   496,   377,   573,   574,   501,   572,   575,   570,
     571,   372,   503,   504,   435,     0,     0,     0,     0,     0,
       0,     0,   472,   473,   474,   466,   468,   465,   467,   469,
     470,   471,     0,   458,   454,   455,     0,     0,   459,   460,
     461,   462,   463,     0,     0,   475,   476,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   396,   397,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,   348,     0,
       0,     0,   354,   356,   350,    14,    16,    19,    11,    92,
       9,    94,   374,   516,   368,   518,   519,   370,     0,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   457,   456,     0,     0,   449,   431,   438,
       0,     0,     0,     0,   442,   612,   609,   610,   613,   611,
     607,   608,   433,   389,   395,   416,   414,     0,   391,   393,
     399,   401,   403,   405,   407,   409,   411,   413,   418,   602,
     606,   380,   599,     0,   604,   605,   382,   386,   384,   387,
      99,     0,     0,   358,   360,   362,   364,   366,   375,     0,
      70,    29,    31,    32,    34,    33,    35,   559,   498,   500,
     561,   497,   580,   555,   577,   578,   581,   579,   576,   506,
     557,   502,   510,   508,   505,   436,     0,     0,   426,   420,
     422,   425,   423,   419,   430,     0,   428,   427,   448,   440,
     443,   439,   441,     0,   415,   600,   598,   601,   603,     0,
     229,   592,   589,   590,   523,   591,   588,   521,   517,   527,
     525,   520,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,   421,   424,   429,     0,     0,   101,     0,   228,
     111,     0,     0,     0,    39,    30,     0,    42,    36,     0,
     499,   556,   586,   584,   511,   587,   585,   582,   583,   507,
     515,   513,   509,     0,   434,     0,    98,   104,   103,     0,
       0,   545,   524,   549,   547,   597,   595,   528,   530,   596,
     593,   594,   522,   534,   532,   526,    71,     0,     0,    41,
       0,     0,   437,   100,   102,     0,    95,     0,   113,   115,
     117,     0,     0,     0,     0,   149,   122,   125,   129,   132,
     136,   139,   143,   110,     0,     0,     0,     0,     0,   229,
      46,     0,    51,     0,    43,    45,    48,     0,    38,   512,
     514,   151,   249,   251,   252,    28,   112,     0,   231,   231,
     231,   231,     0,   250,   253,   254,   255,   233,     0,     0,
     261,   264,   262,   265,   263,   259,   260,   162,     0,   160,
     161,   256,   257,   258,     0,     0,   158,   147,     0,     0,
       0,     0,     0,     0,     0,     0,   550,   546,   554,   552,
     548,   529,   535,   531,   539,   537,   533,    74,   275,   273,
     274,   269,   270,   276,   277,   271,   272,   266,     0,   238,
     239,   267,   268,    56,     0,     0,     0,    40,     0,   230,
      25,    26,    24,    22,    23,     0,     0,   236,   118,     0,
     159,     0,    76,   157,     0,     0,   123,   126,   130,   133,
     137,   140,   144,     0,     0,     0,     0,     0,     0,   240,
      54,     0,     0,    44,    47,    27,    30,    96,    97,   114,
     232,   235,   116,   234,   233,     0,   174,   175,   179,   105,
     165,   120,   164,     0,   177,   178,   146,    75,     0,   152,
       0,   150,     0,     0,     0,     0,     0,     0,     0,   551,
     553,   540,   536,   544,   542,   538,     0,    72,     0,    79,
       0,    73,    49,     0,   177,    52,    50,     0,   119,     0,
     173,   171,   184,   167,   107,   121,   231,   251,   252,   153,
     154,     0,   250,   253,   254,   255,   148,   124,   127,   131,
     134,   138,   141,   145,     0,     0,    81,     0,     0,     0,
     244,     0,     0,    59,   237,     0,   182,     0,   231,   166,
     169,   170,     0,   163,   176,   106,     0,     0,     0,     0,
       0,   541,   543,     0,    84,    87,    80,    76,   242,   241,
       0,    57,    53,   180,     0,   190,   191,   187,   194,   195,
       0,     0,     0,     0,     0,     0,     0,   205,   207,   206,
       0,     0,   210,   211,   212,   217,     0,     0,   192,   186,
     172,   168,   155,   156,   128,   135,   142,    83,    77,   231,
     177,     0,     0,     0,    55,     0,   181,   188,   189,   196,
     197,   213,   201,   203,   208,   214,     0,   199,   183,   185,
     219,    82,     0,    88,    78,   243,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   223,     0,   218,   193,     0,    62,    63,    67,    65,
      58,    60,   221,     0,     0,     0,     0,     0,   224,     0,
       0,   216,   222,     0,     0,     0,     0,     0,   198,   220,
     202,   204,   209,   215,   225,   226,   227,   200,    85,     0,
       0,     0,     0,    64,    68,    66,    86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    40,    41,    42,   114,   112,   109,   110,   111,   566,
     390,   391,   392,   393,   394,   479,   395,   518,   478,   517,
     635,   554,   555,   556,   633,   763,   671,   724,   792,   835,
     860,   861,   895,   897,   896,    43,    53,   454,   549,   667,
     698,   721,   758,   828,   786,   830,   912,   831,   410,   370,
     113,    45,   116,   380,   679,   440,   466,   467,   499,   690,
     735,    46,   500,   543,   577,   578,   579,   685,   599,   702,
     600,   703,   778,   601,   704,   602,   705,   779,   603,   706,
     604,   707,   780,   605,   708,   654,   598,   700,   739,   740,
     595,   588,   589,   691,   772,   773,   692,   731,   693,   733,
     694,   729,   765,   768,   817,   818,   819,   850,   862,   872,
     863,   864,   865,   866,   874,   883,   870,   871,   470,   640,
     645,   646,   684,   695,   629,   723,   761,   833,   396,   571,
     590,   630,   572,   193,   194,   631,   196,   197,   198,   199,
      47,    96,   108,    54,   106,   107,   308,   309,   310,   311,
     312,   118,   119,    56,   117,    55,   284,   285,   290,   289,
     266,   271,   274,   267,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   265,   433,   321,   461,    52,    48,   253,
     242,   257,    94,    95,    99,    49,    50,    51,   314,    72,
     210,   318,   400,   457,   221,   319,   320,   411,   459,   460,
     489,   520,   521,   304,   381,   382,   448,   472,   471,   473,
     512,   546,   547,   548,   613,   665,   666,   712,   754,   755,
     502,   544,   545,   607,   663,   664,   412,   458,   211,   316,
     317,   212,   223,   413,   491,   450,   514,   371,   436,   372,
     373,   374,   375
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -735
static const yytype_int16 yypact[] =
{
     749,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,    23,  -735,   330,   102,     1,  -735,    69,   135,
    -735,    -9,  -735,   -14,     6,    12,    47,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
     215,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,   309,   105,  1091,   369,   369,   388,  -735,     8,   189,
     409,    53,   219,   245,   245,   245,   -31,  -735,  -735,  -735,
     176,   245,  -735,  -735,  -735,   222,   -46,  -735,   138,   142,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,   -72,  -735,  -735,  -735,
    -735,   134,  -735,  -735,  -735,  -735,   369,   369,   -72,   292,
     304,   305,   314,   186,   315,  -735,  1091,   388,   434,   388,
    -735,  -735,  -735,  -735,  -735,   231,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,   207,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,   230,   245,   245,   245,   245,
     245,   245,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,   245,  -735,  -735,  -735,   170,   237,  -735,  -735,
    -735,  -735,  -735,   245,   245,  -735,  -735,   199,   201,   202,
     245,   245,   245,   245,   208,   185,   -72,   -72,   212,   213,
     251,   -72,  -735,  -735,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   419,   419,  -735,  -735,  -735,   419,
     419,   216,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,   369,   388,
     434,   434,   388,  -735,   221,   815,   -72,   -89,   -72,   447,
     -72,   185,   245,   245,   227,   229,   239,   240,   247,   248,
     253,   245,   254,  -735,  -735,   265,   267,  -735,  -735,  -735,
     268,   270,   279,   281,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,   295,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,   523,  -735,  -735,  -735,  -735,  -735,  -735,
     220,   532,   -72,  -735,  -735,  -735,  -735,  -735,  -735,   815,
     228,   282,   252,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,   298,   302,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,   303,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,   245,  -735,  -735,  -735,  -735,  -735,  1091,
     287,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,    64,   815,   289,   310,  -735,   -72,   -72,   548,
     -72,   245,  -735,  -735,  -735,   312,   -24,  -735,   -71,  -735,
    -735,   579,   684,   -72,  -735,  -735,   815,  -735,  -735,  1091,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,   317,  -735,  1091,  -735,  -735,  -735,   815,
     527,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,   228,    14,    72,  -735,
     369,   -72,  -735,  -735,   228,   321,  -735,   884,  -735,  -735,
    -735,  1160,  1160,  1367,  1091,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,   730,   -72,   369,   739,   -72,   287,
    -735,  2118,  -735,  1091,  -735,   326,  -735,  1091,  -735,  -735,
    -735,  -735,   339,   209,   277,    -1,  -735,   301,   -65,   234,
     249,   347,   348,   296,   318,   324,   327,  -735,  2118,   353,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,   953,  -735,
    -735,  -735,  -735,  -735,  1022,  1229,  -735,  -735,  2118,   354,
     357,   358,   363,   361,   368,   366,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,   356,   359,
    -735,  -735,  -735,   372,   370,   376,    20,  -735,   884,  -735,
    -735,  -735,  -735,  -735,  -735,  1643,  1574,  -735,  -735,  1436,
    -735,  1436,   384,  -735,   374,  1574,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,   369,   -72,  2160,   -72,    46,  2118,  -735,
    -735,   373,  1091,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  1436,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  1712,  -735,  -735,  -735,  -735,  1712,  1850,
     381,  -735,   -72,   390,   -72,   394,   -72,   398,  1436,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,   395,  -735,  2118,  -735,
    1367,  -735,  -735,  2118,  -735,  -735,  -735,  1984,  -735,  2118,
    -735,  -735,   392,  1505,  -735,  -735,   347,  -735,  -735,   393,
    -735,   400,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,   369,   -72,  -735,   391,   -64,  1298,
     359,   111,  1917,   397,  -735,   160,  -735,  2189,   347,  -735,
    -735,  -735,   143,  -735,  -735,  -735,  1850,  1091,   -72,   -72,
     -72,  -735,  -735,  1781,  -735,  -735,  -735,   384,  -735,  -735,
    2051,  -735,  -735,  -735,  2118,  -735,  -735,  -735,  -735,  -735,
     385,   387,   364,   408,   375,   413,   414,  -735,   418,  -735,
     420,   426,  -735,  -735,  -735,  -735,   427,  2156,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,   347,
    -735,   -72,  1712,  2118,  -735,   137,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,   306,  -735,  -735,  -735,
     389,  -735,  1917,  -735,  -735,   359,   396,   435,   441,   442,
     263,  -735,   402,   402,   402,   402,   568,  1091,  1091,  1091,
      81,  -735,   402,  -735,  -735,  2051,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,   -80,   -68,   -66,   -57,   449,   454,   454,
     454,  -735,  -735,   -44,   446,   402,   576,   402,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,   -35,
     456,   -20,   -72,  -735,  -735,  -735,  -735
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,   -55,
    -375,  -735,  -735,  -524,  -518,  -735,  -509,  -735,  -735,  -735,
    -735,  -735,  -735,   -47,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -269,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -195,  -735,  -735,  -735,  -735,  -735,  -735,  -735,   -95,     0,
    -735,  -735,  -735,  -735,  -566,  -735,  -735,    98,  -735,  -682,
    -237,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -180,
    -123,    66,  -531,  -609,  -735,  -735,  -169,  -735,  -734,  -698,
    -463,  -735,  -735,  -735,  -735,  -735,  -213,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -559,  -735,  -265,    57,  -563,
     -76,    18,  -735,  -345,  -699,  -735,  -735,  -735,   -43,  -672,
    -510,  -735,  -735,  -508,  -511,   -48,  -735,  -498,  -483,  -374,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,   -34,   598,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
     -53,  -735,  -735,  -735,   -78,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,    -8,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,  -735,
    -735,  -735,  -735,  -735,  -735,  -735,  -369,  -735,   -52,  -735,
    -735,  -735,   -93,  -431,  -527,  -735,  -735,   -38,  -735,   246,
    -735,   250,  -233
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -490
static const yytype_int16 yytable[] =
{
      44,   288,   213,   568,   222,   195,   641,   642,   643,   569,
     192,   730,   449,   294,   452,   550,   734,   609,   570,   573,
     591,   591,   591,   596,   760,   306,   762,   741,   790,   575,
     258,   259,   352,   260,   398,    90,    91,   264,   286,   302,
     504,   307,   696,    57,   576,   269,   898,   716,   593,   593,
     593,   771,   497,   292,   293,   286,   261,   650,   900,   784,
     901,   101,   639,   650,   498,   222,   305,   222,   195,   902,
     785,   -32,   -32,   301,    92,    93,   728,   591,   475,   287,
     682,   224,   907,   591,   591,   653,   899,   270,   415,   701,
     490,   913,   243,   244,   245,   246,   287,   247,   899,   753,
     899,   516,   503,   513,   741,   593,   915,   495,    73,   899,
      74,   593,   593,   102,   568,   496,   615,   551,   875,   552,
     569,   262,   899,   551,   524,   552,  -279,    75,   248,   570,
     573,   899,   852,   103,   855,  -291,  -291,  -291,   714,   104,
     575,   249,   250,   251,    97,    98,   899,   553,   717,   718,
     734,   719,   567,   553,   720,   576,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    90,
      91,   353,   354,   775,   105,   608,   358,   632,   614,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,    89,
     474,   742,   324,   325,   326,   327,   328,   329,   255,   256,
     453,   744,   225,   557,   632,   820,   628,   891,   330,   591,
     596,   558,   332,   331,   252,   115,   745,   306,   306,   335,
     336,   397,   399,   401,   632,   414,   340,   341,   342,   343,
     732,   384,   126,   647,   387,   736,   226,   593,   227,   228,
     229,   230,   788,   867,   868,   869,   254,   376,   591,   653,
     789,   377,   378,   647,   263,   383,   231,   222,   305,   305,
     222,   268,   686,   676,   687,   272,   851,   195,   742,   273,
     774,   632,   632,   255,   256,   632,   593,   632,   744,   322,
     323,   632,   333,   334,   856,   857,   291,   451,   416,   417,
     793,   794,   858,   745,   632,   295,   713,   425,   859,   774,
     680,   683,   385,   386,   884,   885,   886,   296,   345,   297,
     683,   632,   299,   893,   346,   347,   348,   298,   300,   632,
     120,   121,   313,   722,   632,   315,   337,   834,   338,   339,
     122,   123,   124,   125,   632,   344,   909,    58,   911,   355,
     356,   195,   357,   379,   632,  -292,  -292,  -292,   388,   632,
     349,   350,   351,   632,   418,   632,   419,    59,   439,   632,
      60,   639,   480,   481,   453,   492,   420,   421,    61,   736,
     -34,   -34,   -34,   757,   422,   423,   639,    62,   515,    63,
     424,   426,   680,    64,   766,   -33,   -33,   -33,   632,   774,
     456,   195,   427,   880,   428,   429,   468,   430,    65,   465,
      66,    67,    68,    69,   469,   195,   431,    70,   432,   632,
     856,   857,   894,  -293,  -293,  -293,   632,    71,   858,   455,
     632,   232,   434,   476,   859,   462,   560,   493,   195,   463,
     464,   195,  -290,  -290,  -290,   477,   519,   638,   829,   494,
     233,   234,   235,   236,   522,   237,   238,   195,   561,   836,
     610,   195,   468,   616,  -246,  -246,  -246,   636,   632,   632,
    -247,  -247,  -247,  -248,  -248,  -248,  -278,   559,   867,   868,
     869,   239,   240,   241,   639,   644,   648,   656,   632,   574,
     657,   660,   658,   592,   592,   592,   195,   659,   661,   662,
     668,   597,   200,   611,   201,   670,   202,   669,   203,   204,
     205,   632,   673,   697,   672,   195,   699,   725,   746,   195,
     634,   214,   748,   201,   637,   215,   750,   216,   217,   218,
     752,   767,   756,   777,   776,   783,   791,   837,   525,   838,
     839,   587,   587,   840,   206,   207,   208,   209,   842,   843,
     592,   841,   345,   844,    38,   845,   592,   592,   346,   347,
     348,   846,   847,   206,   219,   220,   209,   214,   873,   201,
     877,   215,   876,   303,   217,   218,   878,   879,   882,   710,
     402,   715,   403,   887,   286,   903,   404,   405,   406,    38,
     908,   910,   914,   675,   349,   350,   351,   369,   587,   674,
     574,   881,   832,   523,   587,   854,   822,   759,   594,   206,
     219,   220,   209,   821,   849,   892,   617,   747,   727,   749,
     709,   751,   407,   408,   409,   287,   655,   100,     0,   437,
       0,     0,     0,   438,   195,     0,     0,   526,   527,   726,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,     0,     0,   345,     0,    38,     0,
     435,   743,   346,   347,   348,   441,     0,   403,     0,   286,
     782,   442,   443,   444,     0,     0,     0,     0,     0,     0,
       0,   482,   592,   403,     0,   286,     0,   483,   484,   485,
       0,     0,     0,   824,   825,   826,   542,     0,   349,   350,
     351,   369,     0,     0,     0,     0,     0,   445,   446,   447,
     287,   781,   402,     0,   403,     0,   286,     0,   404,   405,
     406,   592,     0,   486,   487,   488,   287,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   743,   195,
       0,     0,     0,     0,   823,     0,   853,     0,     0,     0,
       0,     0,     0,     0,   407,   408,   501,   287,     0,    -3,
       1,     0,     0,     0,     0,     2,     3,     4,     5,     0,
    -489,  -489,     6,     7,     8,     9,    10,    11,    12,     0,
    -489,  -489,  -489,  -489,    13,    14,    15,     0,     0,    16,
       0,     0,     0,    17,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,   505,     0,   403,
      20,   286,     0,   506,   507,   508,     0,   916,    21,   195,
     195,   195,     0,     0,   888,   889,   890,     0,    22,    23,
      24,    25,    26,    27,    28,    29,     0,     0,     0,     0,
       0,    30,    31,    32,    33,    34,    35,    36,    37,   509,
     510,   511,   287,   482,     0,   403,     0,   286,     0,   483,
     606,   485,   402,     0,   403,     0,   286,     0,   404,   405,
     406,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   904,   905,
     906,     0,     0,     0,     0,   486,   487,   488,   287,     0,
       0,     0,     0,     0,   407,   408,   612,   287,     0,     0,
       0,     0,     0,     0,    39,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     389,     0,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,     0,   191,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   389,
       0,   562,   153,   154,   155,   563,   157,   158,   564,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,     0,   565,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   580,   581,   582,   583,   649,   584,    38,     0,
     585,   586,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
       0,   191,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   580,   581,   582,   583,   651,   584,    38,     0,   585,
     586,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,     0,
     191,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,     0,     0,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,     0,   191,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   580,
     581,   582,   583,     0,   584,    38,     0,   585,   586,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,     0,   191,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   580,   581,
     582,   583,   652,   584,     0,     0,   585,   586,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,     0,   191,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   580,   581,   582,
     583,   787,   584,     0,     0,   585,   586,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,     0,   191,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   580,   581,   582,   583,
       0,   584,     0,     0,   585,   586,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,     0,   191,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   618,     0,   686,   619,   687,   620,     0,
     621,     0,     0,     0,     0,   688,     0,     0,   622,   623,
     624,     0,   625,   626,     0,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   627,     0,   689,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   618,     0,     0,   619,     0,   620,   769,   621,
       0,     0,   770,     0,   688,     0,     0,   622,   623,   624,
       0,   625,   626,     0,     0,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   627,     0,   689,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   618,     0,     0,   619,     0,   620,     0,   621,     0,
       0,   677,   681,     0,     0,     0,   622,   623,   624,     0,
     625,   626,     0,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     627,     0,   678,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     618,     0,     0,   619,     0,   620,     0,   621,     0,     0,
     677,     0,     0,     0,     0,   622,   623,   624,     0,   625,
     626,     0,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   627,
       0,   678,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   618,
       0,     0,   619,     0,   620,     0,   621,     0,     0,     0,
       0,   688,     0,     0,   622,   623,   624,     0,   625,   626,
       0,     0,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   627,     0,
     689,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   618,     0,
       0,   619,     0,   620,     0,   621,     0,     0,     0,     0,
       0,     0,     0,   622,   623,   624,     0,   625,   626,     0,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   627,     0,   827,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,     0,   153,   154,
     155,   737,   157,   158,   738,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   618,     0,   686,   619,   687,   620,
       0,   621,     0,     0,     0,     0,   688,     0,     0,   622,
     623,   624,     0,   625,   626,     0,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   627,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   618,     0,     0,   619,     0,   620,     0,   621,     0,
       0,     0,   764,     0,     0,     0,   622,   623,   624,     0,
     625,   626,     0,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     627,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   618,     0,
       0,   619,     0,   620,     0,   621,     0,     0,     0,     0,
     688,     0,     0,   622,   623,   624,     0,   625,   626,     0,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   627,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   618,     0,     0,   619,     0,
     620,     0,   621,     0,     0,     0,     0,     0,     0,     0,
     622,   623,   624,     0,   625,   626,     0,     0,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   482,   627,   403,   848,   286,     0,   483,
     711,   485,     0,     0,     0,     0,   795,   796,   797,   798,
     799,   800,   801,   802,   803,   804,   805,   806,   807,   808,
     809,   810,   811,   812,   813,   814,   815,   816,     0,     0,
       0,     0,     0,     0,     0,   486,   487,   488,   287,   795,
     796,   797,   798,   799,   800,   801,   802,   803,   804,   805,
     806,   807,   808,   809,   810,   811,   812,   813,   814,   815,
     816
};

static const yytype_int16 yycheck[] =
{
       0,    96,    55,   527,    56,    53,   569,   570,   571,   527,
      53,   693,   381,   108,   389,     1,   698,   544,   527,   527,
     531,   532,   533,   533,   723,   118,   724,   699,   762,   527,
      64,    65,   265,    64,   123,    34,    35,    71,   127,   117,
     471,   119,   651,    20,   527,    91,   126,     1,   531,   532,
     533,   733,   123,   106,   107,   127,    87,   588,   126,   123,
     126,    70,   127,   594,   135,   117,   118,   119,   116,   126,
     134,   136,   137,   116,    73,    74,   685,   588,   453,   168,
     646,    73,   126,   594,   595,   595,   166,   133,   321,   655,
     459,   126,    39,    40,    41,    42,   168,    44,   166,   708,
     166,   476,   471,   472,   776,   588,   126,   131,     6,   166,
       8,   594,   595,   127,   638,   139,   547,   103,   852,   105,
     638,   152,   166,   103,   499,   105,   127,    25,    75,   638,
     638,   166,   830,   127,   833,   136,   137,   138,   665,   127,
     638,    88,    89,    90,    75,    76,   166,   133,   102,   103,
     832,   105,   527,   133,   108,   638,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    34,
      35,   266,   267,   736,   127,   544,   271,   551,   547,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    87,
     126,   699,   226,   227,   228,   229,   230,   231,    28,    29,
     136,   699,    13,   131,   578,   768,   551,   126,   242,   720,
     720,   139,   246,    43,   161,     0,   699,   310,   311,   253,
     254,   316,   317,   318,   598,   320,   260,   261,   262,   263,
     693,   309,   127,   578,   312,   698,    47,   720,    49,    50,
      51,    52,   131,   162,   163,   164,    27,   285,   759,   759,
     139,   289,   290,   598,    78,   308,    67,   309,   310,   311,
     312,    39,   119,   638,   121,   127,   829,   315,   776,   127,
     733,   645,   646,    28,    29,   649,   759,   651,   776,    49,
      50,   655,    45,    46,   147,   148,   152,   382,   322,   323,
     130,   131,   155,   776,   668,     3,   665,   331,   161,   762,
     645,   646,   310,   311,   863,   864,   865,     3,   123,     4,
     655,   685,   126,   872,   129,   130,   131,     3,     3,   693,
      11,    12,    91,   668,   698,   118,   127,   790,   127,   127,
      21,    22,    23,    24,   708,   127,   895,     7,   897,   127,
     127,   389,    91,   127,   718,   136,   137,   138,   127,   723,
     165,   166,   167,   727,   127,   729,   127,    27,   138,   733,
      30,   127,   457,   458,   136,   460,   127,   127,    38,   832,
     136,   137,   138,   718,   127,   127,   127,    47,   473,    49,
     127,   127,   727,    53,   729,   136,   137,   138,   762,   852,
     138,   439,   127,   130,   127,   127,   439,   127,    68,   433,
      70,    71,    72,    73,   117,   453,   127,    77,   127,   783,
     147,   148,   875,   136,   137,   138,   790,    87,   155,   137,
     794,    12,   127,   134,   161,   127,   521,   461,   476,   127,
     127,   479,   136,   137,   138,   125,   479,   136,   783,   127,
      31,    32,    33,    34,   127,    36,    37,   495,   127,   794,
     545,   499,   495,   548,   136,   137,   138,   131,   832,   833,
     136,   137,   138,   136,   137,   138,   127,   520,   162,   163,
     164,    62,    63,    64,   127,   127,   123,   123,   852,   527,
     123,   120,   124,   531,   532,   533,   534,   124,   120,   123,
     134,   534,   123,   546,   125,   123,   127,   138,   129,   130,
     131,   875,   126,   119,   134,   553,   132,   134,   127,   557,
     553,   123,   122,   125,   557,   127,   122,   129,   130,   131,
     122,   129,   127,   123,   131,   134,   129,   142,     1,   142,
     166,   531,   532,   125,   165,   166,   167,   168,   125,   125,
     588,   166,   123,   125,   125,   125,   594,   595,   129,   130,
     131,   125,   125,   165,   166,   167,   168,   123,   169,   125,
     125,   127,   166,   129,   130,   131,   125,   125,   166,   664,
     123,   666,   125,     5,   127,   126,   129,   130,   131,   125,
     134,     5,   126,   638,   165,   166,   167,   168,   588,   636,
     638,   860,   787,   495,   594,   832,   776,   720,   532,   165,
     166,   167,   168,   772,   817,   870,   549,   702,   684,   704,
     663,   706,   165,   166,   167,   168,   598,    19,    -1,   373,
      -1,    -1,    -1,   373,   672,    -1,    -1,   100,   101,   672,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,   123,    -1,   125,    -1,
     127,   699,   129,   130,   131,   123,    -1,   125,    -1,   127,
     755,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   720,   125,    -1,   127,    -1,   129,   130,   131,
      -1,    -1,    -1,   778,   779,   780,   159,    -1,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   754,   123,    -1,   125,    -1,   127,    -1,   129,   130,
     131,   759,    -1,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   776,   777,
      -1,    -1,    -1,    -1,   777,    -1,   831,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,    -1,     0,
       1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,   123,    -1,   125,
      61,   127,    -1,   129,   130,   131,    -1,   912,    69,   867,
     868,   869,    -1,    -1,   867,   868,   869,    -1,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   165,
     166,   167,   168,   123,    -1,   125,    -1,   127,    -1,   129,
     130,   131,   123,    -1,   125,    -1,   127,    -1,   129,   130,
     131,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   888,   889,
     890,    -1,    -1,    -1,    -1,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,    -1,   168,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
     166,    -1,   168,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,   166,
      -1,   168,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,    -1,
     168,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,   166,    -1,   168,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,   124,   125,    -1,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,   166,    -1,   168,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,   166,    -1,   168,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,   166,    -1,   168,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,   124,    -1,    -1,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,   166,    -1,   168,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,   119,   120,   121,   122,    -1,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,   132,   133,
     134,    -1,   136,   137,    -1,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,   166,    -1,   168,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,   120,    -1,   122,   123,   124,
      -1,    -1,   127,    -1,   129,    -1,    -1,   132,   133,   134,
      -1,   136,   137,    -1,    -1,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,    -1,   168,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,   137,    -1,    -1,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
     166,    -1,   168,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,   120,    -1,   122,    -1,   124,    -1,    -1,
     127,    -1,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
     137,    -1,    -1,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,   166,
      -1,   168,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,    -1,   122,    -1,   124,    -1,    -1,    -1,
      -1,   129,    -1,    -1,   132,   133,   134,    -1,   136,   137,
      -1,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,    -1,
     168,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,   120,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,    -1,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,   166,    -1,   168,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,   166,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,   120,   121,   122,
      -1,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,   132,
     133,   134,    -1,   136,   137,    -1,    -1,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,   166,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,    -1,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,   137,    -1,    -1,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
     166,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,   120,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,   132,   133,   134,    -1,   136,   137,    -1,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,   166,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,   120,    -1,
     122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   123,   166,   125,   130,   127,    -1,   129,
     130,   131,    -1,    -1,    -1,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    14,    15,    16,
      17,    18,    19,    25,    26,    27,    30,    34,    38,    53,
      61,    69,    79,    80,    81,    82,    83,    84,    85,    86,
      92,    93,    94,    95,    96,    97,    98,    99,   125,   165,
     171,   172,   173,   205,   219,   221,   231,   310,   348,   355,
     356,   357,   347,   206,   313,   325,   323,    20,     7,    27,
      30,    38,    47,    49,    53,    68,    70,    71,    72,    73,
      77,    87,   359,     6,     8,    25,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    87,
      34,    35,    73,    74,   352,   353,   311,    75,    76,   354,
     352,    70,   127,   127,   127,   127,   314,   315,   312,   176,
     177,   178,   175,   220,   174,     0,   222,   324,   321,   322,
      11,    12,    21,    22,    23,    24,   127,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     166,   168,   298,   303,   304,   305,   306,   307,   308,   309,
     123,   125,   127,   129,   130,   131,   165,   166,   167,   168,
     360,   398,   401,   360,   123,   127,   129,   130,   131,   166,
     167,   364,   398,   402,    73,    13,    47,    49,    50,    51,
      52,    67,    12,    31,    32,    33,    34,    36,    37,    62,
      63,    64,   350,    39,    40,    41,    42,    44,    75,    88,
      89,    90,   161,   349,    27,    28,    29,   351,   351,   351,
      64,    87,   152,    78,   351,   343,   330,   333,    39,    91,
     133,   331,   127,   127,   332,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   326,   327,   127,   168,   218,   329,
     328,   152,   360,   360,   218,     3,     3,     4,     3,   126,
       3,   298,   364,   129,   373,   398,   402,   364,   316,   317,
     318,   319,   320,    91,   358,   118,   399,   400,   361,   365,
     366,   345,    49,    50,   351,   351,   351,   351,   351,   351,
     351,    43,   351,    45,    46,   351,   351,   127,   127,   127,
     351,   351,   351,   351,   127,   123,   129,   130,   131,   165,
     166,   167,   412,   218,   218,   127,   127,    91,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   168,
     219,   407,   409,   410,   411,   412,   407,   407,   407,   127,
     223,   374,   375,   360,   364,   373,   373,   364,   127,   125,
     180,   181,   182,   183,   184,   186,   298,   218,   123,   218,
     362,   218,   123,   125,   129,   130,   131,   165,   166,   167,
     218,   367,   396,   403,   218,   412,   351,   351,   127,   127,
     127,   127,   127,   127,   127,   351,   127,   127,   127,   127,
     127,   127,   127,   344,   127,   127,   408,   409,   411,   138,
     225,   123,   129,   130,   131,   165,   166,   167,   376,   396,
     405,   218,   180,   136,   207,   137,   138,   363,   397,   368,
     369,   346,   127,   127,   127,   351,   226,   227,   298,   117,
     288,   378,   377,   379,   126,   180,   134,   125,   188,   185,
     218,   218,   123,   129,   130,   131,   165,   166,   167,   370,
     396,   404,   218,   351,   127,   131,   139,   123,   135,   228,
     232,   167,   390,   396,   403,   123,   129,   130,   131,   165,
     166,   167,   380,   396,   406,   218,   180,   189,   187,   298,
     371,   372,   127,   227,   180,     1,   100,   101,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   159,   233,   391,   392,   381,   382,   383,   208,
       1,   103,   105,   133,   191,   192,   193,   131,   139,   360,
     218,   127,   127,   131,   134,   168,   179,   180,   183,   184,
     186,   299,   302,   303,   305,   307,   308,   234,   235,   236,
     119,   120,   121,   122,   124,   127,   128,   219,   261,   262,
     300,   304,   305,   308,   261,   260,   300,   298,   256,   238,
     240,   243,   245,   248,   250,   253,   130,   393,   396,   404,
     218,   360,   167,   384,   396,   403,   218,   288,   117,   120,
     122,   124,   132,   133,   134,   136,   137,   166,   293,   294,
     301,   305,   309,   194,   298,   190,   131,   298,   136,   127,
     289,   289,   289,   289,   127,   290,   291,   293,   123,   123,
     262,   123,   123,   300,   255,   291,   123,   123,   124,   124,
     120,   120,   123,   394,   395,   385,   386,   209,   134,   138,
     123,   196,   134,   126,   193,   179,   180,   127,   168,   224,
     293,   128,   224,   293,   292,   237,   119,   121,   129,   168,
     229,   263,   266,   268,   270,   293,   263,   119,   210,   132,
     257,   224,   239,   241,   244,   246,   249,   251,   254,   360,
     218,   130,   387,   396,   404,   218,     1,   102,   103,   105,
     108,   211,   293,   295,   197,   134,   298,   290,   263,   271,
     229,   267,   270,   269,   229,   230,   270,   131,   134,   258,
     259,   299,   303,   305,   307,   308,   127,   218,   122,   218,
     122,   218,   122,   263,   388,   389,   127,   293,   212,   260,
     294,   296,   269,   195,   128,   272,   293,   129,   273,   123,
     127,   229,   264,   265,   270,   289,   131,   123,   242,   247,
     252,   360,   218,   134,   123,   134,   214,   123,   131,   139,
     268,   129,   198,   130,   131,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   274,   275,   276,
     289,   266,   259,   298,   218,   218,   218,   168,   213,   293,
     215,   217,   210,   297,   270,   199,   293,   142,   142,   166,
     125,   166,   125,   125,   125,   125,   125,   125,   130,   276,
     277,   289,   269,   218,   230,   294,   147,   148,   155,   161,
     200,   201,   278,   280,   281,   282,   283,   162,   163,   164,
     286,   287,   279,   169,   284,   268,   166,   125,   125,   125,
     130,   201,   166,   285,   285,   285,   285,     5,   298,   298,
     298,   126,   287,   285,   270,   202,   204,   203,   126,   166,
     126,   126,   126,   126,   219,   219,   219,   126,   134,   285,
       5,   285,   216,   126,   126,   126,   218
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
			    interpreter.generateVariants(lexerBubble, number);
			;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1257 "surface.yy"
    {
			  interpreter.cont((yyvsp[(3) - (4)].yyInt64), (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1261 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1266 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(lexerBubble);
			;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1272 "surface.yy"
    {
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(lexerBubble);
			;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1277 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1279 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1283 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1285 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1289 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1291 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1295 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1297 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1302 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1309 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1311 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1315 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1317 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1321 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1323 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(true);
			;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1327 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1329 "surface.yy"
    {
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showView();
			;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1334 "surface.yy"
    {
			  interpreter.showModules(true);
			;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1338 "surface.yy"
    {
			  interpreter.showNamedViews();
			;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1341 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1343 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSortsAndSubsorts();
			;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1347 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1349 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showOps();
			;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1353 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1355 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showVars();
			;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1359 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1361 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showMbs();
			;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1365 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1367 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showEqs();
			;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1371 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1373 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showRls();
			;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1377 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1379 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSummary();
			;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1383 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 1385 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showKinds();
			;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 1390 "surface.yy"
    {
			  interpreter.showSearchPath((yyvsp[(3) - (4)].yyInt64));
			;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1394 "surface.yy"
    {
			  interpreter.showSearchPathLabels((yyvsp[(4) - (5)].yyInt64));
			;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1398 "surface.yy"
    {
			  interpreter.showSearchGraph();
			;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 1401 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 1403 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showProfile();
			;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1411 "surface.yy"
    {
			  globalAdvisoryFlag = (yyvsp[(4) - (5)].yyBool);
			;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1415 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1419 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, (yyvsp[(5) - (6)].yyBool));
			;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 1423 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 1427 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1431 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, (yyvsp[(5) - (6)].yyBool));
			;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1435 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1439 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1443 "surface.yy"
    {
			  interpreter.setPrintFlag((yyvsp[(3) - (5)].yyPrintFlags), (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1447 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 1451 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE_NEWLINE, (yyvsp[(5) - (6)].yyBool));
			;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 1455 "surface.yy"
    {
			  interpreter.setFlag((yyvsp[(3) - (5)].yyFlags), (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 1459 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, (yyvsp[(3) - (4)].yyBool));
			;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 1462 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 1463 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 1465 "surface.yy"
    {
			  interpreter.setAutoImport((yyvsp[(2) - (7)].yyImportMode), (yyvsp[(4) - (7)].yyToken), (yyvsp[(6) - (7)].yyBool));
			;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 1468 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 1469 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 1471 "surface.yy"
    {
			  interpreter.setOmodInclude((yyvsp[(5) - (8)].yyToken), (yyvsp[(7) - (8)].yyBool));
			;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 1475 "surface.yy"
    {
			  globalVerboseFlag = (yyvsp[(3) - (4)].yyBool);
			;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 1479 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 1483 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 1487 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 1491 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, (yyvsp[(3) - (4)].yyBool));
			;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 1495 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 1502 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 1506 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 1510 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 1514 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 1521 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 1525 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[(3) - (4)].yyBool));
			;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 1531 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 1542 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_MIXFIX; ;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 1543 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FLAT; ;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 1544 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_ALIASES; ;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 1545 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_PARENS; ;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 1546 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_GRAPH; ;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 1547 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_CONCEAL; ;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 1548 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_NUMBER; ;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 1549 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_RAT; ;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 1550 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_COLOR; ;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 1551 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FORMAT; ;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 1554 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE; ;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 1555 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_CONDITION; ;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 1556 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_WHOLE; ;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 1557 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SUBSTITUTION; ;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 1558 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SELECT; ;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 1559 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_MB; ;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 1560 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_EQ; ;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 1561 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_RL; ;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 1562 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_REWRITE; ;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 1563 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BODY; ;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 1564 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BUILTIN; ;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 1567 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 1568 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 1571 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 1572 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 1575 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 1576 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 1579 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 1580 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 1585 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::NARROW; ;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 1586 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::XG_NARROW; ;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 1587 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::SEARCH; ;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 1590 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 1591 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 1594 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 1595 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 1598 "surface.yy"
    { (yyval.yyInt64) = (yyvsp[(1) - (1)].yyInt64); ;}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 1599 "surface.yy"
    { (yyval.yyInt64) = NONE; ;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 1602 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::PROTECTING; ;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 1603 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::EXTENDING; ;}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 1604 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::INCLUDING; ;}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 1614 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 1618 "surface.yy"
    { moduleExpr = lexerBubble; lexBubble(END_COMMAND, 1); ;}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 1630 "surface.yy"
    { lexSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 1633 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0);  ;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 1638 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 1640 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 1646 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); ;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 1648 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 1663 "surface.yy"
    { lexSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 1666 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 1675 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 1677 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 1679 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 1689 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); ;}
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 1691 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 1693 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 1703 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 1705 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 1716 "surface.yy"
    {
			  number = Token::codeToInt64(lexerBubble[1].code());
			  number2 = Token::codeToInt64(lexerBubble[3].code());
			  clear();
			;}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 1722 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 1732 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 1734 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 1744 "surface.yy"
    { number2 = Token::codeToInt64(lexerBubble[2].code()); ;}
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 1746 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 555:

/* Line 1455 of yacc.c  */
#line 1751 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0, 1); ;}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 1757 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 1, 1); ;}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 1759 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON | END_COMMAND, 0); ;}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 1762 "surface.yy"
    {
			  lexerBubble.resize(1);
			  lexerBubble[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(lexerBubble[0]);
			;}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 1801 "surface.yy"
    {;}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 1806 "surface.yy"
    {
			  singleton[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(singleton[0]);
			  interpreter.addSelected(singleton);
			;}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 1817 "surface.yy"
    {
			  singleton[0] = (yyvsp[(1) - (1)].yyToken);
			  interpreter.addSelected(singleton);
			;}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 1822 "surface.yy"
    {
			  interpreter.addSelected(lexerBubble);
			;}
    break;



/* Line 1455 of yacc.c  */
#line 5938 "surface.c"
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
#line 1852 "surface.yy"


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

