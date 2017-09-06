/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
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


/* Line 268 of yacc.c  */
#line 146 "surface.c"

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
     KW_CHECK = 274,
     KW_GET = 275,
     KW_VARIANTS = 276,
     KW_VARIANT = 277,
     KW_EREWRITE = 278,
     KW_FREWRITE = 279,
     KW_SREWRITE = 280,
     KW_CONTINUE = 281,
     KW_SEARCH = 282,
     KW_SET = 283,
     KW_SHOW = 284,
     KW_ON = 285,
     KW_OFF = 286,
     KW_TRACE = 287,
     KW_BODY = 288,
     KW_BUILTIN = 289,
     KW_WHOLE = 290,
     KW_SELECT = 291,
     KW_DESELECT = 292,
     KW_CONDITION = 293,
     KW_SUBSTITUTION = 294,
     KW_PRINT = 295,
     KW_GRAPH = 296,
     KW_MIXFIX = 297,
     KW_FLAT = 298,
     KW_ATTRIBUTE = 299,
     KW_NEWLINE = 300,
     KW_WITH = 301,
     KW_PARENS = 302,
     KW_ALIASES = 303,
     KW_GC = 304,
     KW_TIME = 305,
     KW_STATS = 306,
     KW_TIMING = 307,
     KW_CMD = 308,
     KW_BREAKDOWN = 309,
     KW_BREAK = 310,
     KW_PATH = 311,
     KW_MODULE = 312,
     KW_MODULES = 313,
     KW_VIEWS = 314,
     KW_ALL = 315,
     KW_SORTS = 316,
     KW_OPS2 = 317,
     KW_VARS = 318,
     KW_MBS = 319,
     KW_EQS = 320,
     KW_RLS = 321,
     KW_SUMMARY = 322,
     KW_KINDS = 323,
     KW_ADVISE = 324,
     KW_VERBOSE = 325,
     KW_DO = 326,
     KW_CLEAR = 327,
     KW_PROTECT = 328,
     KW_EXTEND = 329,
     KW_INCLUDE = 330,
     KW_EXCLUDE = 331,
     KW_CONCEAL = 332,
     KW_REVEAL = 333,
     KW_COMPILE = 334,
     KW_COUNT = 335,
     KW_DEBUG = 336,
     KW_IRREDUNDANT = 337,
     KW_RESUME = 338,
     KW_ABORT = 339,
     KW_STEP = 340,
     KW_WHERE = 341,
     KW_CREDUCE = 342,
     KW_SREDUCE = 343,
     KW_DUMP = 344,
     KW_PROFILE = 345,
     KW_NUMBER = 346,
     KW_RAT = 347,
     KW_COLOR = 348,
     SIMPLE_NUMBER = 349,
     KW_PWD = 350,
     KW_CD = 351,
     KW_PUSHD = 352,
     KW_POPD = 353,
     KW_LS = 354,
     KW_LOAD = 355,
     KW_QUIT = 356,
     KW_EOF = 357,
     KW_ENDM = 358,
     KW_IMPORT = 359,
     KW_ENDV = 360,
     KW_SORT = 361,
     KW_SUBSORT = 362,
     KW_OP = 363,
     KW_OPS = 364,
     KW_MSGS = 365,
     KW_VAR = 366,
     KW_CLASS = 367,
     KW_SUBCLASS = 368,
     KW_MB = 369,
     KW_CMB = 370,
     KW_EQ = 371,
     KW_CEQ = 372,
     KW_RL = 373,
     KW_CRL = 374,
     KW_IS = 375,
     KW_FROM = 376,
     KW_ARROW = 377,
     KW_ARROW2 = 378,
     KW_PARTIAL = 379,
     KW_IF = 380,
     KW_LABEL = 381,
     KW_TO = 382,
     KW_COLON2 = 383,
     KW_ASSOC = 384,
     KW_COMM = 385,
     KW_ID = 386,
     KW_IDEM = 387,
     KW_ITER = 388,
     KW_LEFT = 389,
     KW_RIGHT = 390,
     KW_PREC = 391,
     KW_GATHER = 392,
     KW_METADATA = 393,
     KW_STRAT = 394,
     KW_POLY = 395,
     KW_MEMO = 396,
     KW_FROZEN = 397,
     KW_CTOR = 398,
     KW_LATEX = 399,
     KW_SPECIAL = 400,
     KW_CONFIG = 401,
     KW_OBJ = 402,
     KW_MSG = 403,
     KW_DITTO = 404,
     KW_FORMAT = 405,
     KW_ID_HOOK = 406,
     KW_OP_HOOK = 407,
     KW_TERM_HOOK = 408,
     KW_IN = 409,
     IDENTIFIER = 410,
     NUMERIC_ID = 411,
     ENDS_IN_DOT = 412,
     FORCE_LOOKAHEAD = 413
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 103 "surface.yy"

  bool yyBool;
  Int64 yyInt64;
  const char* yyString;
  Token yyToken;
  ImportModule::ImportMode yyImportMode;
  Interpreter::Flags yyFlags;
  Interpreter::PrintFlags yyPrintFlags;
  Interpreter::SearchKind yySearchKind;



/* Line 293 of yacc.c  */
#line 353 "surface.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 343 of yacc.c  */
#line 114 "surface.yy"

int yylex(YYSTYPE* lvalp);


/* Line 343 of yacc.c  */
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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  113
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2342

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  173
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  245
/* YYNRULES -- Number of rules.  */
#define YYNRULES  617
/* YYNRULES -- Number of states.  */
#define YYNSTATES  924

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   413

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     128,   129,   140,   139,   134,     2,   130,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   126,     2,
     131,   127,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   132,     2,   133,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   141,   135,   142,     2,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   136,   137,   138,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172
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
     937,   941,   942,   946,   947,   951,   952,   958,   959,   966,
     971,   972,   976,   978,   979,   984,   985,   990,   991,   996,
     997,  1002,  1007,  1008,  1013,  1014,  1019,  1020,  1025,  1026,
    1031,  1035,  1039,  1040,  1045,  1046,  1051,  1052,  1057,  1058,
    1063,  1064,  1069,  1070,  1075,  1076,  1081,  1082,  1087,  1092,
    1098,  1103,  1104,  1109,  1115,  1121,  1128,  1134,  1140,  1147,
    1153,  1159,  1165,  1171,  1178,  1184,  1189,  1190,  1191,  1199,
    1200,  1201,  1210,  1215,  1221,  1227,  1233,  1238,  1244,  1247,
    1250,  1253,  1256,  1262,  1267,  1268,  1272,  1274,  1276,  1279,
    1282,  1284,  1286,  1288,  1290,  1292,  1294,  1295,  1297,  1299,
    1301,  1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,  1319,
    1321,  1323,  1325,  1327,  1329,  1331,  1333,  1335,  1337,  1339,
    1341,  1343,  1344,  1346,  1347,  1349,  1350,  1352,  1354,  1356,
    1358,  1359,  1363,  1364,  1368,  1370,  1371,  1375,  1377,  1378,
    1382,  1383,  1387,  1388,  1392,  1394,  1395,  1399,  1400,  1404,
    1406,  1407,  1411,  1413,  1414,  1418,  1419,  1423,  1424,  1428,
    1429,  1433,  1435,  1436,  1440,  1441,  1445,  1446,  1450,  1452,
    1453,  1457,  1458,  1462,  1464,  1465,  1469,  1470,  1474,  1476,
    1477,  1481,  1482,  1486,  1488,  1489,  1493,  1494,  1498,  1500,
    1501,  1505,  1507,  1508,  1512,  1513,  1517,  1519,  1521,  1523,
    1525,  1527,  1529,  1531,  1533,  1535,  1537,  1539,  1541,  1543,
    1545,  1547,  1549,  1551,  1553,  1555,  1557,  1559,  1561,  1563,
    1565,  1567,  1569,  1571,  1573,  1575,  1577,  1579,  1581,  1583,
    1585,  1587,  1589,  1592,  1594,  1596,  1598,  1600,  1603,  1605,
    1607,  1609,  1611,  1613,  1615,  1617,  1619,  1621
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     174,     0,    -1,   175,    -1,    -1,   224,    -1,   208,    -1,
     176,    -1,   313,    -1,    -1,   168,   177,     3,    -1,    -1,
     100,   178,     3,    -1,    95,    -1,    -1,    96,   179,     3,
      -1,    -1,    97,   180,     3,    -1,    98,    -1,    -1,    99,
     181,     4,    -1,   101,    -1,   102,    -1,   302,   292,    -1,
     305,   130,    -1,   189,   292,    -1,   186,   292,    -1,   187,
     292,    -1,   183,   139,   182,    -1,   171,    -1,   184,    -1,
     183,   139,   183,    -1,   185,    -1,   186,    -1,   189,    -1,
     187,    -1,   301,    -1,   184,   140,   191,    -1,    -1,   185,
     141,   188,   190,   142,    -1,   128,   183,   129,    -1,   190,
     134,   301,    -1,   301,    -1,    -1,    -1,   128,   192,   194,
     193,   129,    -1,   195,    -1,     1,    -1,   195,   134,   196,
      -1,   196,    -1,   106,   296,   137,   296,    -1,   136,   301,
     137,   301,    -1,    -1,    -1,   108,   197,   199,   137,   198,
     201,    -1,    -1,   126,   200,   272,   271,   273,    -1,    -1,
      -1,   132,   202,   203,   133,    -1,    -1,   203,   204,    -1,
     204,    -1,   150,   169,    -1,    -1,   151,   128,   205,   288,
     129,    -1,    -1,   164,   128,   206,   288,   129,    -1,    -1,
     158,   128,   207,     5,   129,    -1,    -1,    -1,    -1,     8,
     209,   301,   121,   183,   210,   137,   183,   211,   291,   212,
     105,    -1,   212,   214,    -1,    -1,   122,    -1,    -1,   106,
     296,   137,   216,    -1,   111,   263,   126,   213,   233,    -1,
      -1,   108,   215,   217,    -1,     1,   130,    -1,   296,   292,
      -1,   171,    -1,    -1,    -1,   126,   218,   272,   271,   273,
     137,   219,   221,    -1,    -1,   137,   220,   221,    -1,   130,
      -1,   171,    -1,    -1,   128,   223,   129,    -1,    -1,    -1,
     234,   225,   301,   226,   228,   291,   235,   103,    -1,   130,
      -1,   171,    -1,   141,   229,   142,    -1,    -1,   229,   134,
     230,    -1,   230,    -1,   301,   231,   183,    -1,   138,    -1,
     126,    -1,   171,    -1,   273,   292,    -1,   232,    -1,     6,
      -1,     7,    -1,   235,   236,    -1,    -1,   104,   182,    -1,
      -1,   106,   237,   293,   227,    -1,    -1,   107,   238,   294,
     227,    -1,    -1,    -1,   108,   239,   126,   240,   266,    -1,
     109,   264,   126,   266,    -1,   111,   263,   126,   213,   233,
      -1,    -1,    -1,   114,   241,   126,   242,   221,    -1,    -1,
      -1,    -1,   115,   243,   126,   244,   125,   245,   221,    -1,
      -1,    -1,   116,   246,   127,   247,   221,    -1,    -1,    -1,
      -1,   117,   248,   127,   249,   125,   250,   221,    -1,    -1,
      -1,   118,   251,   123,   252,   221,    -1,    -1,    -1,    -1,
     119,   253,   123,   254,   125,   255,   221,    -1,    -1,    -1,
     162,   256,   126,   257,   266,    -1,   110,   264,   126,   266,
      -1,    -1,   112,   301,   258,   260,   130,    -1,    -1,   113,
     259,   294,   227,    -1,     1,   130,    -1,   135,    -1,   135,
     261,    -1,   262,    -1,   261,   134,   262,    -1,   302,   126,
     301,    -1,   263,   303,    -1,   303,    -1,   264,   265,    -1,
     265,    -1,   303,    -1,   222,    -1,   273,   272,   268,    -1,
     269,    -1,   232,    -1,   126,    -1,    -1,   267,   269,    -1,
     130,    -1,   232,    -1,   271,   270,    -1,   273,   276,   292,
      -1,   232,    -1,   122,    -1,   124,    -1,   272,   273,    -1,
      -1,   296,    -1,    -1,   132,   274,   275,   133,    -1,   275,
     134,   296,    -1,   296,    -1,   132,   277,   133,    -1,    -1,
     277,   279,    -1,   279,    -1,   145,    -1,   148,   145,    -1,
     149,   145,    -1,   143,    -1,   144,    -1,    -1,   278,   280,
     287,    -1,   146,    -1,   147,    -1,   150,   169,    -1,    -1,
     151,   128,   281,   288,   129,    -1,    -1,   164,   128,   282,
     288,   129,    -1,    -1,   153,   128,   283,   288,   129,    -1,
      -1,   154,   128,   284,   288,   129,    -1,   155,    -1,   157,
      -1,   156,    -1,    -1,   156,   128,   285,   288,   129,    -1,
     160,    -1,   161,    -1,   162,    -1,   152,   169,    -1,    -1,
     158,   128,   286,     5,   129,    -1,   159,   128,   289,   129,
      -1,   163,    -1,   172,    -1,    -1,   288,   169,    -1,   169,
      -1,   289,   290,    -1,   290,    -1,   165,   301,    -1,   165,
     301,   222,    -1,   166,   301,   222,    -1,   167,   301,   222,
      -1,   120,    -1,    -1,   130,    -1,    -1,   293,   296,    -1,
      -1,   294,   296,    -1,   294,   131,    -1,    -1,   296,   295,
     293,   131,    -1,   297,    -1,   304,    -1,    -1,   297,   141,
     298,   299,   142,    -1,    -1,   299,   134,   300,   297,    -1,
     297,    -1,   307,    -1,   308,    -1,   310,    -1,   311,    -1,
     130,    -1,   306,    -1,   134,    -1,   137,    -1,   308,    -1,
     310,    -1,   311,    -1,   307,    -1,   308,    -1,   311,    -1,
     130,    -1,   131,    -1,   122,    -1,   124,    -1,   127,    -1,
     123,    -1,   125,    -1,   169,    -1,   308,    -1,   312,    -1,
     127,    -1,   135,    -1,   139,    -1,   140,    -1,   123,    -1,
     125,    -1,   120,    -1,   136,    -1,   137,    -1,   130,    -1,
     171,    -1,   169,    -1,   141,    -1,   142,    -1,   139,    -1,
     140,    -1,   135,    -1,   138,    -1,   136,    -1,   121,    -1,
     120,    -1,   306,    -1,   171,    -1,   134,    -1,   137,    -1,
     162,    -1,   309,    -1,   104,    -1,   106,    -1,   107,    -1,
     108,    -1,   109,    -1,   111,    -1,   110,    -1,   112,    -1,
     113,    -1,   114,    -1,   115,    -1,   116,    -1,   117,    -1,
     118,    -1,   119,    -1,   103,    -1,   105,    -1,   131,    -1,
     126,    -1,   122,    -1,   124,    -1,   127,    -1,   123,    -1,
     125,    -1,   132,    -1,   133,    -1,   312,    -1,   143,    -1,
     144,    -1,   145,    -1,   146,    -1,   147,    -1,   148,    -1,
     149,    -1,   150,    -1,   151,    -1,   153,    -1,   154,    -1,
     155,    -1,   157,    -1,   158,    -1,   159,    -1,   156,    -1,
     152,    -1,   160,    -1,   161,    -1,   163,    -1,   164,    -1,
     165,    -1,   166,    -1,   167,    -1,    -1,    36,   314,   221,
      -1,    -1,    89,   315,   221,    -1,    -1,     9,   316,   365,
      -1,    -1,    87,   317,   365,    -1,    -1,    88,   318,   365,
      -1,    -1,   361,    11,   319,   365,    -1,    -1,   361,    12,
     320,   369,    -1,    -1,   361,    23,   321,   378,    -1,    -1,
     361,    24,   322,   378,    -1,    -1,   361,    25,   323,   369,
      -1,    -1,    19,   324,   365,    -1,    -1,   359,   325,   378,
      -1,    -1,   360,   326,   369,    -1,    -1,    18,   327,   369,
      -1,    -1,   361,    22,    18,   328,   369,    -1,    -1,   361,
      20,   362,    21,   329,   369,    -1,   361,    26,   363,   130,
      -1,    -1,    13,   330,   365,    -1,   222,    -1,    -1,    32,
     356,   331,   412,    -1,    -1,    32,   357,   332,   412,    -1,
      -1,    55,   356,   333,   412,    -1,    -1,    40,   358,   334,
     412,    -1,    71,    72,   155,   130,    -1,    -1,    29,     6,
     335,   221,    -1,    -1,    29,    57,   336,   221,    -1,    -1,
      29,    60,   337,   221,    -1,    -1,    29,     8,   338,   221,
      -1,    29,    58,   130,    -1,    29,    59,   130,    -1,    -1,
      29,    61,   339,   221,    -1,    -1,    29,    62,   340,   221,
      -1,    -1,    29,    63,   341,   221,    -1,    -1,    29,    64,
     342,   221,    -1,    -1,    29,    65,   343,   221,    -1,    -1,
      29,    66,   344,   221,    -1,    -1,    29,    67,   345,   221,
      -1,    -1,    29,    68,   346,   221,    -1,    29,    56,    94,
     130,    -1,    29,    56,   136,    94,   130,    -1,    29,    27,
      41,   130,    -1,    -1,    29,    90,   347,   221,    -1,    28,
      29,    69,   355,   130,    -1,    28,    29,    51,   355,   130,
      -1,    28,    29,    13,    51,   355,   130,    -1,    28,    29,
      52,   355,   130,    -1,    28,    29,    54,   355,   130,    -1,
      28,    29,    13,    52,   355,   130,    -1,    28,    29,    53,
     355,   130,    -1,    28,    29,    49,   355,   130,    -1,    28,
      40,   353,   355,   130,    -1,    28,    40,    44,   355,   130,
      -1,    28,    40,    44,    45,   355,   130,    -1,    28,    32,
     354,   355,   130,    -1,    28,    55,   355,   130,    -1,    -1,
      -1,    28,   364,   348,   417,   349,   355,   130,    -1,    -1,
      -1,    28,     7,    75,   350,   417,   351,   355,   130,    -1,
      28,    70,   355,   130,    -1,    28,    72,   155,   355,   130,
      -1,    28,    72,    66,   355,   130,    -1,    28,    79,    80,
     355,   130,    -1,    28,    90,   355,   130,    -1,    28,    72,
      90,   355,   130,    -1,    83,   130,    -1,    84,   130,    -1,
      85,   130,    -1,    86,   130,    -1,    28,    49,    29,   355,
     130,    -1,    28,    51,   355,   130,    -1,    -1,     1,   352,
     130,    -1,    42,    -1,    43,    -1,    46,    48,    -1,    46,
      47,    -1,    41,    -1,    77,    -1,    91,    -1,    92,    -1,
      93,    -1,   164,    -1,    -1,    38,    -1,    35,    -1,    39,
      -1,    36,    -1,    64,    -1,    65,    -1,    66,    -1,    12,
      -1,    33,    -1,    34,    -1,    30,    -1,    31,    -1,    36,
      -1,    37,    -1,    76,    -1,    75,    -1,    77,    -1,    78,
      -1,    14,    -1,    15,    -1,    27,    -1,    17,    -1,    16,
      -1,    81,    -1,    -1,    82,    -1,    -1,    94,    -1,    -1,
      73,    -1,    74,    -1,    75,    -1,   403,    -1,    -1,   406,
     366,   221,    -1,    -1,   126,   368,   221,    -1,   221,    -1,
      -1,   132,   370,   372,    -1,   403,    -1,    -1,   407,   371,
     221,    -1,    -1,   170,   373,   375,    -1,    -1,   408,   374,
     221,    -1,   401,    -1,    -1,   133,   376,   365,    -1,    -1,
     409,   377,   221,    -1,   401,    -1,    -1,   132,   379,   381,
      -1,   403,    -1,    -1,   407,   380,   221,    -1,    -1,   170,
     382,   385,    -1,    -1,   134,   383,   395,    -1,    -1,   410,
     384,   221,    -1,   401,    -1,    -1,   133,   386,   365,    -1,
      -1,   134,   387,   389,    -1,    -1,   411,   388,   221,    -1,
     401,    -1,    -1,   170,   390,   392,    -1,    -1,   408,   391,
     221,    -1,   401,    -1,    -1,   133,   393,   365,    -1,    -1,
     409,   394,   221,    -1,   401,    -1,    -1,   170,   396,   398,
      -1,    -1,   408,   397,   221,    -1,   401,    -1,    -1,   133,
     399,   365,    -1,    -1,   409,   400,   221,    -1,   401,    -1,
      -1,   128,   402,   221,    -1,   221,    -1,    -1,   128,   404,
     221,    -1,    -1,   168,   405,   367,    -1,   171,    -1,   169,
      -1,   170,    -1,   132,    -1,   133,    -1,   126,    -1,   130,
      -1,   134,    -1,   169,    -1,   170,    -1,   133,    -1,   126,
      -1,   130,    -1,   134,    -1,   169,    -1,   132,    -1,   133,
      -1,   168,    -1,   126,    -1,   134,    -1,   169,    -1,   170,
      -1,   132,    -1,   168,    -1,   126,    -1,   134,    -1,   169,
      -1,   132,    -1,   133,    -1,   168,    -1,   126,    -1,   169,
      -1,   170,    -1,   132,    -1,   168,    -1,   126,    -1,   415,
     413,    -1,   414,    -1,   130,    -1,   414,    -1,   171,    -1,
     415,   416,    -1,   416,    -1,   417,    -1,   222,    -1,   169,
      -1,   170,    -1,   132,    -1,   133,    -1,   168,    -1,   126,
      -1,   134,    -1
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
    1157,  1170,  1169,  1183,  1182,  1196,  1195,  1209,  1208,  1221,
    1220,  1234,  1233,  1246,  1245,  1258,  1257,  1271,  1270,  1282,
    1287,  1286,  1297,  1303,  1303,  1309,  1309,  1315,  1315,  1321,
    1321,  1327,  1335,  1335,  1341,  1341,  1347,  1347,  1353,  1353,
    1359,  1363,  1367,  1367,  1373,  1373,  1379,  1379,  1385,  1385,
    1391,  1391,  1397,  1397,  1403,  1403,  1409,  1409,  1415,  1419,
    1423,  1427,  1427,  1436,  1440,  1444,  1448,  1452,  1456,  1460,
    1464,  1468,  1472,  1476,  1480,  1484,  1488,  1489,  1488,  1494,
    1495,  1494,  1500,  1504,  1508,  1512,  1516,  1520,  1527,  1531,
    1535,  1539,  1546,  1550,  1557,  1557,  1564,  1565,  1566,  1567,
    1568,  1569,  1570,  1571,  1572,  1573,  1576,  1577,  1578,  1579,
    1580,  1581,  1582,  1583,  1584,  1585,  1586,  1589,  1590,  1593,
    1594,  1597,  1598,  1601,  1602,  1607,  1608,  1609,  1612,  1613,
    1616,  1617,  1620,  1621,  1624,  1625,  1628,  1629,  1630,  1639,
    1640,  1640,  1644,  1644,  1646,  1656,  1656,  1658,  1659,  1659,
    1664,  1664,  1666,  1666,  1668,  1672,  1672,  1674,  1674,  1676,
    1689,  1689,  1691,  1692,  1692,  1701,  1701,  1703,  1703,  1705,
    1705,  1707,  1715,  1715,  1717,  1717,  1719,  1719,  1721,  1729,
    1729,  1731,  1731,  1733,  1742,  1741,  1748,  1748,  1750,  1758,
    1758,  1760,  1760,  1762,  1770,  1770,  1772,  1772,  1774,  1777,
    1777,  1779,  1783,  1783,  1785,  1785,  1787,  1798,  1798,  1798,
    1798,  1798,  1798,  1798,  1801,  1801,  1801,  1801,  1801,  1801,
    1805,  1805,  1805,  1805,  1805,  1805,  1809,  1809,  1809,  1809,
    1809,  1809,  1813,  1813,  1813,  1813,  1813,  1817,  1817,  1817,
    1817,  1817,  1823,  1824,  1827,  1828,  1831,  1838,  1839,  1842,
    1847,  1854,  1854,  1854,  1854,  1854,  1854,  1854
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
  "KW_CHECK", "KW_GET", "KW_VARIANTS", "KW_VARIANT", "KW_EREWRITE",
  "KW_FREWRITE", "KW_SREWRITE", "KW_CONTINUE", "KW_SEARCH", "KW_SET",
  "KW_SHOW", "KW_ON", "KW_OFF", "KW_TRACE", "KW_BODY", "KW_BUILTIN",
  "KW_WHOLE", "KW_SELECT", "KW_DESELECT", "KW_CONDITION",
  "KW_SUBSTITUTION", "KW_PRINT", "KW_GRAPH", "KW_MIXFIX", "KW_FLAT",
  "KW_ATTRIBUTE", "KW_NEWLINE", "KW_WITH", "KW_PARENS", "KW_ALIASES",
  "KW_GC", "KW_TIME", "KW_STATS", "KW_TIMING", "KW_CMD", "KW_BREAKDOWN",
  "KW_BREAK", "KW_PATH", "KW_MODULE", "KW_MODULES", "KW_VIEWS", "KW_ALL",
  "KW_SORTS", "KW_OPS2", "KW_VARS", "KW_MBS", "KW_EQS", "KW_RLS",
  "KW_SUMMARY", "KW_KINDS", "KW_ADVISE", "KW_VERBOSE", "KW_DO", "KW_CLEAR",
  "KW_PROTECT", "KW_EXTEND", "KW_INCLUDE", "KW_EXCLUDE", "KW_CONCEAL",
  "KW_REVEAL", "KW_COMPILE", "KW_COUNT", "KW_DEBUG", "KW_IRREDUNDANT",
  "KW_RESUME", "KW_ABORT", "KW_STEP", "KW_WHERE", "KW_CREDUCE",
  "KW_SREDUCE", "KW_DUMP", "KW_PROFILE", "KW_NUMBER", "KW_RAT", "KW_COLOR",
  "SIMPLE_NUMBER", "KW_PWD", "KW_CD", "KW_PUSHD", "KW_POPD", "KW_LS",
  "KW_LOAD", "KW_QUIT", "KW_EOF", "KW_ENDM", "KW_IMPORT", "KW_ENDV",
  "KW_SORT", "KW_SUBSORT", "KW_OP", "KW_OPS", "KW_MSGS", "KW_VAR",
  "KW_CLASS", "KW_SUBCLASS", "KW_MB", "KW_CMB", "KW_EQ", "KW_CEQ", "KW_RL",
  "KW_CRL", "KW_IS", "KW_FROM", "KW_ARROW", "KW_ARROW2", "KW_PARTIAL",
  "KW_IF", "':'", "'='", "'('", "')'", "'.'", "'<'", "'['", "']'", "','",
  "'|'", "KW_LABEL", "KW_TO", "KW_COLON2", "'+'", "'*'", "'{'", "'}'",
  "KW_ASSOC", "KW_COMM", "KW_ID", "KW_IDEM", "KW_ITER", "KW_LEFT",
  "KW_RIGHT", "KW_PREC", "KW_GATHER", "KW_METADATA", "KW_STRAT", "KW_POLY",
  "KW_MEMO", "KW_FROZEN", "KW_CTOR", "KW_LATEX", "KW_SPECIAL", "KW_CONFIG",
  "KW_OBJ", "KW_MSG", "KW_DITTO", "KW_FORMAT", "KW_ID_HOOK", "KW_OP_HOOK",
  "KW_TERM_HOOK", "KW_IN", "IDENTIFIER", "NUMERIC_ID", "ENDS_IN_DOT",
  "FORCE_LOOKAHEAD", "$accept", "top", "item", "directive", "$@1", "$@2",
  "$@3", "$@4", "$@5", "moduleExprDot", "moduleExpr", "moduleExpr2",
  "moduleExpr3", "renameExpr", "instantExpr", "$@6", "parenExpr",
  "argList", "renaming", "$@7", "$@8", "renaming2", "mappingList",
  "mapping", "$@9", "$@10", "fromSpec", "$@11", "toAttributes", "$@12",
  "toAttributeList", "toAttribute", "$@13", "$@14", "$@15", "view", "$@16",
  "$@17", "$@18", "viewDecList", "skipStrayArrow", "viewDeclaration",
  "$@19", "sortDot", "viewEndOpMap", "$@20", "$@21", "$@22", "endBubble",
  "parenBubble", "$@23", "module", "$@24", "$@25", "dot", "parameters",
  "parameterList", "parameter", "colon2", "badType", "typeDot",
  "startModule", "decList", "declaration", "$@26", "$@27", "$@28", "$@29",
  "$@30", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "$@37", "$@38",
  "$@39", "$@40", "$@41", "$@42", "$@43", "$@44", "$@45", "$@46", "$@47",
  "$@48", "classDef", "cPairList", "cPair", "varNameList", "opNameList",
  "simpleOpName", "domainRangeAttr", "skipStrayColon", "dra2", "rangeAttr",
  "typeAttr", "arrow", "typeList", "typeName", "$@49", "sortNames",
  "attributes", "attributeList", "idKeyword", "attribute", "$@50", "$@51",
  "$@52", "$@53", "$@54", "$@55", "$@56", "identity", "idList", "hookList",
  "hook", "expectedIs", "expectedDot", "sortNameList", "subsortList",
  "$@57", "sortName", "sortNameFrag", "$@58", "sortNameFrags", "$@59",
  "token", "tokenBarDot", "tokenBarColon", "sortToken", "endsInDot",
  "inert", "identifier", "startKeyword", "startKeyword2", "midKeyword",
  "attrKeyword", "attrKeyword2", "command", "$@60", "$@61", "$@62", "$@63",
  "$@64", "$@65", "$@66", "$@67", "$@68", "$@69", "$@70", "$@71", "$@72",
  "$@73", "$@74", "$@75", "$@76", "$@77", "$@78", "$@79", "$@80", "$@81",
  "$@82", "$@83", "$@84", "$@85", "$@86", "$@87", "$@88", "$@89", "$@90",
  "$@91", "$@92", "$@93", "$@94", "$@95", "$@96", "$@97", "$@98",
  "printOption", "traceOption", "polarity", "select", "exclude", "conceal",
  "search", "match", "optDebug", "optIrredundant", "optNumber",
  "importMode", "moduleAndTerm", "$@99", "inEnd", "$@100",
  "numberModuleTerm", "$@101", "$@102", "numberModuleTerm1", "$@103",
  "$@104", "numberModuleTerm2", "$@105", "$@106", "numbersModuleTerm",
  "$@107", "$@108", "numbersModuleTerm1", "$@109", "$@110", "$@111",
  "numbersModuleTerm2", "$@112", "$@113", "$@114", "numbersModuleTerm3",
  "$@115", "$@116", "numbersModuleTerm4", "$@117", "$@118",
  "numbersModuleTerm5", "$@119", "$@120", "numbersModuleTerm6", "$@121",
  "$@122", "miscEndBubble", "$@123", "initialEndBubble", "$@124", "$@125",
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
     375,   376,   377,   378,   379,   380,    58,    61,    40,    41,
      46,    60,    91,    93,    44,   124,   381,   382,   383,    43,
      42,   123,   125,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   173,   174,   174,   175,   175,   175,   175,   177,   176,
     178,   176,   176,   179,   176,   180,   176,   176,   181,   176,
     176,   176,   182,   182,   182,   182,   182,   182,   182,   183,
     183,   184,   184,   185,   185,   185,   186,   188,   187,   189,
     190,   190,   192,   193,   191,   194,   194,   195,   195,   196,
     196,   197,   198,   196,   200,   199,   199,   202,   201,   201,
     203,   203,   204,   205,   204,   206,   204,   207,   204,   209,
     210,   211,   208,   212,   212,   213,   213,   214,   214,   215,
     214,   214,   216,   216,   218,   219,   217,   220,   217,   221,
     221,   223,   222,   225,   226,   224,   227,   227,   228,   228,
     229,   229,   230,   231,   231,   232,   233,   233,   234,   234,
     235,   235,   236,   237,   236,   238,   236,   239,   240,   236,
     236,   236,   241,   242,   236,   243,   244,   245,   236,   246,
     247,   236,   248,   249,   250,   236,   251,   252,   236,   253,
     254,   255,   236,   256,   257,   236,   236,   258,   236,   259,
     236,   236,   260,   260,   261,   261,   262,   263,   263,   264,
     264,   265,   265,   266,   266,   266,   267,   267,   268,   268,
     268,   269,   270,   270,   271,   271,   272,   272,   273,   274,
     273,   275,   275,   276,   276,   277,   277,   278,   278,   278,
     279,   279,   280,   279,   279,   279,   279,   281,   279,   282,
     279,   283,   279,   284,   279,   279,   279,   279,   285,   279,
     279,   279,   279,   279,   286,   279,   279,   279,   287,   287,
     288,   288,   289,   289,   290,   290,   290,   290,   291,   291,
     292,   292,   293,   293,   294,   294,   295,   294,   296,   297,
     298,   297,   300,   299,   299,   301,   301,   301,   301,   301,
     302,   302,   302,   302,   302,   302,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   305,   305,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     307,   307,   307,   307,   308,   308,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   310,   310,   310,   310,   310,   310,   310,
     311,   311,   311,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   314,   313,   315,
     313,   316,   313,   317,   313,   318,   313,   319,   313,   320,
     313,   321,   313,   322,   313,   323,   313,   324,   313,   325,
     313,   326,   313,   327,   313,   328,   313,   329,   313,   313,
     330,   313,   313,   331,   313,   332,   313,   333,   313,   334,
     313,   313,   335,   313,   336,   313,   337,   313,   338,   313,
     313,   313,   339,   313,   340,   313,   341,   313,   342,   313,
     343,   313,   344,   313,   345,   313,   346,   313,   313,   313,
     313,   347,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   348,   349,   313,   350,
     351,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   352,   313,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   355,   355,   356,
     356,   357,   357,   358,   358,   359,   359,   359,   360,   360,
     361,   361,   362,   362,   363,   363,   364,   364,   364,   365,
     366,   365,   368,   367,   367,   370,   369,   369,   371,   369,
     373,   372,   374,   372,   372,   376,   375,   377,   375,   375,
     379,   378,   378,   380,   378,   382,   381,   383,   381,   384,
     381,   381,   386,   385,   387,   385,   388,   385,   385,   390,
     389,   391,   389,   389,   393,   392,   394,   392,   392,   396,
     395,   397,   395,   395,   399,   398,   400,   398,   398,   402,
     401,   401,   404,   403,   405,   403,   403,   406,   406,   406,
     406,   406,   406,   406,   407,   407,   407,   407,   407,   407,
     408,   408,   408,   408,   408,   408,   409,   409,   409,   409,
     409,   409,   410,   410,   410,   410,   410,   411,   411,   411,
     411,   411,   412,   412,   413,   413,   414,   415,   415,   416,
     416,   417,   417,   417,   417,   417,   417,   417
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
       3,     0,     3,     0,     3,     0,     5,     0,     6,     4,
       0,     3,     1,     0,     4,     0,     4,     0,     4,     0,
       4,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       3,     3,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     4,     5,
       4,     0,     4,     5,     5,     6,     5,     5,     6,     5,
       5,     5,     5,     6,     5,     4,     0,     0,     7,     0,
       0,     8,     4,     5,     5,     5,     4,     5,     2,     2,
       2,     2,     5,     4,     0,     3,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     0,     1,     0,     1,     1,     1,     1,
       0,     3,     0,     3,     1,     0,     3,     1,     0,     3,
       0,     3,     0,     3,     1,     0,     3,     0,     3,     1,
       0,     3,     1,     0,     3,     0,     3,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     0,     3,     1,     0,
       3,     0,     3,     1,     0,     3,     0,     3,     1,     0,
       3,     0,     3,     1,     0,     3,     0,     3,     1,     0,
       3,     1,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   454,   108,   109,    69,   351,   380,   485,   486,   489,
     488,   373,   367,   487,     0,     0,     0,   347,     0,     0,
       0,   490,     0,     0,     0,     0,   353,   355,   349,    12,
      13,    15,    17,    18,    10,    20,    21,    91,     8,     0,
       2,     6,     5,   382,     4,    93,     7,   369,   371,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   466,     0,
       0,     0,     0,     0,     0,   496,   497,   498,     0,     0,
     436,   392,   398,     0,     0,   394,     0,     0,   396,   402,
     404,   406,   408,   410,   412,   414,   416,   421,   479,   480,
     482,   481,   383,   385,     0,   483,   484,   389,   387,     0,
     448,   449,   450,   451,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,   357,   359,   493,
       0,   361,   363,   365,   495,   455,   311,   296,   312,   297,
     298,   299,   300,   302,   301,   303,   304,   305,   306,   307,
     308,   309,   310,   289,   288,   315,   318,   316,   319,   314,
     317,   249,   313,   320,   321,   292,   285,   287,   293,   286,
     283,   284,   281,   282,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   339,   332,   333,   334,   338,   335,   336,
     337,   340,   341,   294,   342,   343,   344,   345,   346,   280,
     291,     0,   290,   245,   246,   295,   247,   248,   322,   571,
     562,   572,   569,   570,   573,   564,   567,   568,   566,   352,
     499,   500,   381,   577,   578,   505,   576,   579,   574,   575,
     374,   507,   508,   368,   439,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   468,   470,   467,   469,   471,
     472,   473,     0,   460,   456,   457,     0,     0,   461,   462,
     463,   464,   465,     0,     0,   477,   478,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,   348,     0,
       0,     0,   354,   356,   350,    14,    16,    19,    11,    92,
       9,    94,   520,   370,   522,   523,   372,     0,     0,   492,
       0,   375,     0,     0,     0,   494,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   459,   458,     0,     0,   453,
     435,   442,     0,     0,     0,     0,   446,   616,   613,   614,
     617,   615,   611,   612,   437,   393,   399,   420,   418,     0,
     395,   397,   403,   405,   407,   409,   411,   413,   415,   417,
     422,   606,   610,   384,   603,     0,   608,   609,   386,   390,
     388,   391,    99,     0,     0,   358,   360,   377,     0,   362,
     364,   366,   379,     0,    70,    29,    31,    32,    34,    33,
      35,   563,   502,   504,   565,   501,   584,   559,   581,   582,
     585,   583,   580,   510,   561,   506,   514,   512,   509,   440,
       0,     0,   430,   424,   426,   429,   427,   423,   434,     0,
     432,   431,   452,   444,   447,   443,   445,     0,   419,   604,
     602,   605,   607,     0,   229,   596,   593,   594,   527,   595,
     592,   525,   521,   531,   529,   524,     0,   376,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,   425,   428,
     433,     0,     0,   101,     0,   228,   111,     0,     0,     0,
     378,    39,    30,     0,    42,    36,     0,   503,   560,   590,
     588,   515,   591,   589,   586,   587,   511,   519,   517,   513,
       0,   438,     0,    98,   104,   103,     0,     0,   549,   528,
     553,   551,   601,   599,   532,   534,   600,   597,   598,   526,
     538,   536,   530,    71,     0,     0,    41,     0,     0,   441,
     100,   102,     0,    95,     0,   113,   115,   117,     0,     0,
       0,     0,   149,   122,   125,   129,   132,   136,   139,   143,
     110,     0,     0,     0,     0,     0,   229,    46,     0,    51,
       0,    43,    45,    48,     0,    38,   516,   518,   151,   249,
     251,   252,    28,   112,     0,   231,   231,   231,   231,     0,
     250,   253,   254,   255,   233,     0,     0,   261,   264,   262,
     265,   263,   259,   260,   162,     0,   160,   161,   256,   257,
     258,     0,     0,   158,   147,     0,     0,     0,     0,     0,
       0,     0,     0,   554,   550,   558,   556,   552,   533,   539,
     535,   543,   541,   537,    74,   275,   273,   274,   269,   270,
     276,   277,   271,   272,   266,     0,   238,   239,   267,   268,
      56,     0,     0,     0,    40,     0,   230,    25,    26,    24,
      22,    23,     0,     0,   236,   118,     0,   159,     0,    76,
     157,     0,     0,   123,   126,   130,   133,   137,   140,   144,
       0,     0,     0,     0,     0,     0,   240,    54,     0,     0,
      44,    47,    27,    30,    96,    97,   114,   232,   235,   116,
     234,   233,     0,   174,   175,   179,   105,   165,   120,   164,
       0,   177,   178,   146,    75,     0,   152,     0,   150,     0,
       0,     0,     0,     0,     0,     0,   555,   557,   544,   540,
     548,   546,   542,     0,    72,     0,    79,     0,    73,    49,
       0,   177,    52,    50,     0,   119,     0,   173,   171,   184,
     167,   107,   121,   231,   251,   252,   153,   154,     0,   250,
     253,   254,   255,   148,   124,   127,   131,   134,   138,   141,
     145,     0,     0,    81,     0,     0,     0,   244,     0,     0,
      59,   237,     0,   182,     0,   231,   166,   169,   170,     0,
     163,   176,   106,     0,     0,     0,     0,     0,   545,   547,
       0,    84,    87,    80,    76,   242,   241,     0,    57,    53,
     180,     0,   190,   191,   187,   194,   195,     0,     0,     0,
       0,     0,     0,     0,   205,   207,   206,     0,     0,   210,
     211,   212,   217,     0,     0,   192,   186,   172,   168,   155,
     156,   128,   135,   142,    83,    77,   231,   177,     0,     0,
       0,    55,     0,   181,   188,   189,   196,   197,   213,   201,
     203,   208,   214,     0,   199,   183,   185,   219,    82,     0,
      88,    78,   243,     0,     0,     0,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   223,     0,
     218,   193,     0,    62,    63,    67,    65,    58,    60,   221,
       0,     0,     0,     0,     0,   224,     0,     0,   216,   222,
       0,     0,     0,     0,     0,   198,   220,   202,   204,   209,
     215,   225,   226,   227,   200,    85,     0,     0,     0,     0,
      64,    68,    66,    86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    39,    40,    41,   112,   110,   107,   108,   109,   573,
     394,   395,   396,   397,   398,   486,   399,   525,   485,   524,
     642,   561,   562,   563,   640,   770,   678,   731,   799,   842,
     867,   868,   902,   904,   903,    42,    51,   460,   556,   674,
     705,   728,   765,   835,   793,   837,   919,   838,   414,   372,
     111,    44,   114,   382,   686,   444,   472,   473,   506,   697,
     742,    45,   507,   550,   584,   585,   586,   692,   606,   709,
     607,   710,   785,   608,   711,   609,   712,   786,   610,   713,
     611,   714,   787,   612,   715,   661,   605,   707,   746,   747,
     602,   595,   596,   698,   779,   780,   699,   738,   700,   740,
     701,   736,   772,   775,   824,   825,   826,   857,   869,   879,
     870,   871,   872,   873,   881,   890,   877,   878,   476,   647,
     652,   653,   691,   702,   636,   730,   768,   840,   400,   578,
     597,   637,   579,   192,   193,   638,   195,   196,   197,   198,
      46,    94,   106,    52,   104,   105,   307,   308,   312,   313,
     314,    55,   115,   116,    54,   388,   456,    53,   284,   285,
     290,   289,   266,   271,   274,   267,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   265,   437,   323,   467,    50,
     253,   242,   257,    92,    93,    97,    47,    48,    49,   310,
     316,    70,   209,   320,   404,   463,   220,   321,   322,   415,
     465,   466,   496,   527,   528,   303,   383,   384,   452,   478,
     477,   479,   519,   553,   554,   555,   620,   672,   673,   719,
     761,   762,   509,   551,   552,   614,   670,   671,   416,   464,
     210,   318,   319,   211,   222,   417,   498,   454,   521,   373,
     440,   374,   375,   376,   377
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -751
static const yytype_int16 yypact[] =
{
     689,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,   293,   469,    81,  -751,    93,   208,
     -28,  -751,   -66,   -42,   -39,   -22,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,    37,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,   633,
      -6,  1071,   206,   206,   337,   206,    47,   100,   386,    38,
     116,   220,   220,   220,   -35,  -751,  -751,  -751,    80,   220,
    -751,  -751,  -751,   136,   -59,  -751,    64,    71,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,   -85,  -751,  -751,  -751,  -751,    67,
    -751,  -751,  -751,  -751,   206,   206,   -85,   210,   232,   243,
     254,   135,   271,  -751,  1071,   383,   337,  -751,  -751,   196,
     278,  -751,  -751,  -751,   190,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,   177,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,   235,   220,   220,   220,   220,
     220,   220,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,   220,  -751,  -751,  -751,    31,   259,  -751,  -751,
    -751,  -751,  -751,   220,   220,  -751,  -751,   182,   184,   189,
     220,   220,   220,   220,   191,   273,   -85,   -85,   193,   205,
     251,   -85,  -751,  -751,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,  2149,  2149,  -751,  -751,  -751,  2149,
    2149,   207,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,   206,   337,  -751,
     325,  -751,   383,   383,   337,  -751,   219,   795,   -85,   -70,
     -85,   414,   -85,   273,   220,   220,   226,   228,   234,   239,
     249,   252,   258,   220,   263,  -751,  -751,   264,   270,  -751,
    -751,  -751,   274,   280,   282,   288,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,   304,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,   434,  -751,  -751,  -751,  -751,
    -751,  -751,   248,   443,   -85,  -751,  -751,  -751,   337,  -751,
    -751,  -751,  -751,   795,   262,   268,   295,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
     308,   309,  -751,  -751,  -751,  -751,  -751,  -751,  -751,   317,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,   220,  -751,  -751,
    -751,  -751,  -751,  1071,   303,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,   337,  -751,    33,   795,
     311,   326,  -751,   -85,   -85,   460,   -85,   220,  -751,  -751,
    -751,   323,   -84,  -751,    -1,  -751,  -751,   509,   598,   -85,
    -751,  -751,  -751,   795,  -751,  -751,  1071,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
     328,  -751,  1071,  -751,  -751,  -751,   795,   690,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,   262,     6,    86,  -751,   206,   -85,  -751,
    -751,   262,   334,  -751,   864,  -751,  -751,  -751,  1140,  1140,
    1347,  1071,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,   710,   -85,   206,   721,   -85,   303,  -751,  2098,  -751,
    1071,  -751,   321,  -751,  1071,  -751,  -751,  -751,  -751,   336,
      58,   188,    25,  -751,   329,    28,   153,   211,   343,   344,
     214,   221,   276,   287,  -751,  2098,   352,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,   933,  -751,  -751,  -751,  -751,
    -751,  1002,  1209,  -751,  -751,  2098,   353,   354,   355,   356,
     358,   361,   359,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,   349,   346,  -751,  -751,  -751,
     363,   360,   362,   -49,  -751,   864,  -751,  -751,  -751,  -751,
    -751,  -751,  1623,  1554,  -751,  -751,  1416,  -751,  1416,   368,
    -751,   364,  1554,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
     206,   -85,  2140,   -85,    35,  2098,  -751,  -751,   366,  1071,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  1416,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    1692,  -751,  -751,  -751,  -751,  1692,  1830,   371,  -751,   -85,
     373,   -85,   379,   -85,   385,  1416,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,   382,  -751,  2098,  -751,  1347,  -751,  -751,
    2098,  -751,  -751,  -751,  1964,  -751,  2098,  -751,  -751,   388,
    1485,  -751,  -751,   343,  -751,  -751,   387,  -751,   396,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,   206,   -85,  -751,   404,   -63,  1278,   346,   120,  1897,
     392,  -751,   183,  -751,  2178,   343,  -751,  -751,  -751,   110,
    -751,  -751,  -751,  1830,  1071,   -85,   -85,   -85,  -751,  -751,
    1761,  -751,  -751,  -751,   368,  -751,  -751,  2031,  -751,  -751,
    -751,  2098,  -751,  -751,  -751,  -751,  -751,   398,   400,   381,
     429,   389,   433,   435,  -751,   437,  -751,   442,   444,  -751,
    -751,  -751,  -751,   446,  2143,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,   343,  -751,   -85,  1692,
    2098,  -751,   108,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,   266,  -751,  -751,  -751,   407,  -751,  1897,
    -751,  -751,   346,   412,   459,   461,   463,   245,  -751,   427,
     427,   427,   427,   592,  1071,  1071,  1071,    51,  -751,   427,
    -751,  -751,  2031,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
     -91,   -86,   -77,   -64,   471,   470,   470,   470,  -751,  -751,
     -62,   472,   427,   601,   427,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,   -10,   478,    -8,   -85,
    -751,  -751,  -751,  -751
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,   -37,
    -390,  -751,  -751,  -522,  -519,  -751,  -512,  -751,  -751,  -751,
    -751,  -751,  -751,   -33,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -252,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -177,  -751,  -751,  -751,  -751,  -751,  -751,  -751,   -93,     0,
    -751,  -751,  -751,  -751,  -515,  -751,  -751,   119,  -751,  -689,
    -217,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -160,
    -103,    87,  -529,  -617,  -751,  -751,  -154,  -751,  -750,  -701,
    -606,  -751,  -751,  -751,  -751,  -751,  -197,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -591,  -751,  -245,    78,  -551,
     -55,    41,  -751,  -344,  -712,  -751,  -751,  -751,   -41,  -686,
    -517,  -751,  -751,  -513,  -491,   -46,  -751,  -510,  -506,  -410,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,   -23,   621,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,   -51,  -751,  -751,  -751,   -99,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,    72,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -375,  -751,
     -45,  -751,  -751,  -751,  -101,  -448,  -545,  -751,  -751,    14,
    -751,   272,  -751,   275,  -223
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -492
static const yytype_int16 yytable[] =
{
      43,   288,   212,   458,   223,   194,   616,   557,   453,   221,
     191,   737,   575,   294,   305,   576,   741,   306,   767,   797,
     748,   580,   577,   603,   582,   648,   649,   650,   583,   511,
     769,   260,   600,   600,   600,   269,   723,   113,   905,   258,
     259,   703,   354,   907,    99,   286,   264,   598,   598,   598,
     502,   778,   908,   292,   293,   261,   402,   558,   503,   559,
     286,   255,   256,   791,   100,   909,   657,   914,   194,   482,
     304,   221,   657,   301,   792,   735,   333,   270,   906,   243,
     244,   245,   246,   906,   247,   660,   287,   560,   101,   600,
     497,   102,   906,   523,   739,   600,   600,   748,   760,   743,
     419,   287,   510,   520,   598,   906,   622,   906,   103,   882,
     598,   598,   558,   225,   559,   248,   531,    88,    89,   920,
     262,   922,   224,   575,   125,   504,   576,   721,   862,   249,
     250,   251,   580,   577,   781,   582,   859,   505,   689,   583,
     724,   725,   560,   726,   574,   254,   727,   708,   639,   226,
     741,   227,   228,   229,   230,  -279,    90,    91,   646,   906,
     263,   906,   481,   781,  -291,  -291,  -291,   -32,   -32,   231,
      95,    96,   459,   355,   356,   639,   615,   268,   360,   621,
     898,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   841,   782,   749,   272,   639,   751,  -292,  -292,  -292,
     752,   273,   252,   326,   327,   328,   329,   330,   331,   386,
     603,   305,   305,   295,   635,   391,   874,   875,   876,   332,
     564,   600,   291,   334,   827,   401,   403,   405,   565,   418,
     337,   338,   693,   743,   694,   296,   598,   342,   343,   344,
     345,   654,   639,   639,    88,    89,   639,   297,   639,   660,
     255,   256,   639,   781,   795,   683,   385,   298,   863,   864,
     600,   654,   796,   221,   299,   639,   865,   304,   304,   221,
     749,   194,   866,   751,   300,   598,   901,   752,   309,   891,
     892,   893,   639,   646,   315,   858,   324,   325,   900,   457,
     639,   455,   -34,   -34,   -34,   639,   311,   720,   317,   378,
      56,   420,   421,   379,   380,   639,   335,   336,   687,   690,
     429,   916,   339,   918,   340,   639,   800,   801,   690,   341,
     639,   346,    57,   357,   639,    58,   639,  -293,  -293,  -293,
     639,   729,   199,    59,   200,   358,   201,   381,   202,   203,
     204,   646,    60,   221,    61,   359,   387,   194,    62,   392,
     -33,   -33,   -33,  -290,  -290,  -290,   422,   480,   423,   639,
    -246,  -246,  -246,    63,   424,    64,    65,    66,    67,   425,
     487,   488,    68,   499,   205,   206,   207,   208,   887,   426,
     639,   764,   427,    69,   389,   390,   522,   639,   428,   443,
     687,   639,   773,   430,   431,   863,   864,   194,   232,   347,
     432,   459,   474,   865,   433,   348,   349,   350,   461,   866,
     434,   221,   435,   194,   471,  -247,  -247,  -247,   436,   233,
     234,   235,   236,   475,   237,   238,  -248,  -248,  -248,   639,
     639,   874,   875,   876,   438,   567,   462,   194,   468,   469,
     194,   351,   352,   353,   500,   526,   836,   470,   483,   639,
     239,   240,   241,   501,   484,   643,   194,   843,   529,   617,
     194,   474,   623,   213,   568,   200,  -278,   214,   645,   215,
     216,   217,   639,   646,   651,    71,   566,    72,   655,   663,
     664,   667,   665,   666,   668,   669,   675,   676,   581,   677,
     704,   680,   599,   599,   599,   194,    73,   679,   755,   706,
     604,   753,   618,   732,   757,   205,   218,   219,   208,   213,
     759,   200,   763,   214,   194,   302,   216,   217,   194,   641,
     774,   783,   784,   644,   798,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,   594,   594,
     406,   790,   407,   844,   286,   845,   408,   409,   410,   599,
     846,   205,   218,   219,   208,   599,   599,   847,   848,    87,
     347,   849,    37,   850,   439,   851,   348,   349,   350,   445,
     852,   407,   853,   286,   854,   446,   447,   448,   717,   880,
     722,   883,   411,   412,   413,   287,   489,   884,   407,   885,
     286,   886,   490,   491,   492,   594,   889,   894,    37,   581,
     910,   594,   351,   352,   353,   371,   917,   921,   682,   915,
     681,   449,   450,   451,   287,   888,   754,   839,   756,   716,
     758,   530,   861,   829,   766,   828,   601,   856,   493,   494,
     495,   287,   899,   194,   624,   406,   734,   407,   733,   286,
      98,   408,   409,   410,   117,   118,   662,   441,     0,     0,
     442,     0,     0,   119,     0,   120,   121,   122,   123,   124,
     750,     0,     0,     0,     0,     0,     0,     0,     0,   789,
       0,     0,     0,     0,     0,     0,     0,   411,   412,   508,
     287,   599,     0,     0,     0,     0,     0,     0,     0,    -3,
       1,   532,   831,   832,   833,     2,     3,     4,     5,     0,
    -491,  -491,     6,     7,     8,     9,    10,    11,    12,  -491,
     788,  -491,  -491,  -491,  -491,  -491,    13,    14,    15,     0,
     599,    16,     0,     0,   512,    17,   407,     0,   286,    18,
     513,   514,   515,     0,     0,     0,     0,   750,   194,     0,
       0,     0,     0,   830,    19,   860,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,   516,   517,   518,   287,
      21,     0,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,     0,   533,   534,     0,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
       0,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,   923,     0,   194,   194,
     194,     0,     0,   895,   896,   897,   489,     0,   407,     0,
     286,     0,   490,   613,   492,     0,     0,   406,     0,   407,
       0,   286,   549,   408,   409,   410,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   493,   494,
     495,   287,     0,     0,     0,     0,     0,     0,     0,   411,
     412,   619,   287,     0,     0,   911,   912,   913,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   393,     0,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,     0,   190,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   393,     0,   569,   152,   153,   154,   570,   156,
     157,   571,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,     0,   572,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   587,   588,   589,   590,   656,
     591,    37,     0,   592,   593,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,     0,   190,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   587,   588,   589,   590,   658,   591,
      37,     0,   592,   593,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,     0,   190,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,     0,   190,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   587,   588,   589,   590,     0,   591,    37,     0,
     592,   593,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
       0,   190,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   587,   588,   589,   590,   659,   591,     0,     0,   592,
     593,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,     0,
     190,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     587,   588,   589,   590,   794,   591,     0,     0,   592,   593,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,     0,   190,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   587,
     588,   589,   590,     0,   591,     0,     0,   592,   593,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,     0,   190,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   625,     0,   693,   626,
     694,   627,     0,   628,     0,     0,     0,     0,   695,     0,
       0,   629,   630,   631,     0,   632,   633,     0,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   634,     0,   696,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   625,     0,     0,   626,     0,
     627,   776,   628,     0,     0,   777,     0,   695,     0,     0,
     629,   630,   631,     0,   632,   633,     0,     0,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   634,     0,   696,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   625,     0,     0,   626,     0,   627,
       0,   628,     0,     0,   684,   688,     0,     0,     0,   629,
     630,   631,     0,   632,   633,     0,     0,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   634,     0,   685,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   625,     0,     0,   626,     0,   627,     0,
     628,     0,     0,   684,     0,     0,     0,     0,   629,   630,
     631,     0,   632,   633,     0,     0,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   634,     0,   685,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   625,     0,     0,   626,     0,   627,     0,   628,
       0,     0,     0,     0,   695,     0,     0,   629,   630,   631,
       0,   632,   633,     0,     0,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   634,     0,   696,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   625,     0,     0,   626,     0,   627,     0,   628,     0,
       0,     0,     0,     0,     0,     0,   629,   630,   631,     0,
     632,   633,     0,     0,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     634,     0,   834,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
       0,   152,   153,   154,   744,   156,   157,   745,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   625,     0,   693,
     626,   694,   627,     0,   628,     0,     0,     0,     0,   695,
       0,     0,   629,   630,   631,     0,   632,   633,     0,     0,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   634,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   625,     0,     0,   626,     0,   627,
       0,   628,     0,     0,     0,   771,     0,     0,     0,   629,
     630,   631,     0,   632,   633,     0,     0,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   634,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   625,     0,     0,   626,     0,   627,     0,   628,     0,
       0,     0,     0,   695,     0,     0,   629,   630,   631,     0,
     632,   633,     0,     0,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     634,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   625,     0,
       0,   626,     0,   627,     0,   628,     0,     0,     0,     0,
       0,     0,     0,   629,   630,   631,     0,   632,   633,     0,
       0,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   489,   634,   407,     0,
     286,     0,   490,   718,   492,   347,   855,    37,     0,     0,
       0,   348,   349,   350,     0,     0,   802,   803,   804,   805,
     806,   807,   808,   809,   810,   811,   812,   813,   814,   815,
     816,   817,   818,   819,   820,   821,   822,   823,   493,   494,
     495,   287,     0,     0,     0,     0,     0,   351,   352,   353,
     371,   802,   803,   804,   805,   806,   807,   808,   809,   810,
     811,   812,   813,   814,   815,   816,   817,   818,   819,   820,
     821,   822,   823
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-751))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    94,    53,   393,    55,    51,   551,     1,   383,    54,
      51,   700,   534,   106,   115,   534,   705,   116,   730,   769,
     706,   534,   534,   540,   534,   576,   577,   578,   534,   477,
     731,    66,   538,   539,   540,    94,     1,     0,   129,    62,
      63,   658,   265,   129,    72,   130,    69,   538,   539,   540,
     134,   740,   129,   104,   105,    90,   126,   106,   142,   108,
     130,    30,    31,   126,   130,   129,   595,   129,   114,   459,
     115,   116,   601,   114,   137,   692,    45,   136,   169,    41,
      42,    43,    44,   169,    46,   602,   171,   136,   130,   595,
     465,   130,   169,   483,   700,   601,   602,   783,   715,   705,
     323,   171,   477,   478,   595,   169,   554,   169,   130,   859,
     601,   602,   106,    13,   108,    77,   506,    36,    37,   129,
     155,   129,    75,   645,   130,   126,   645,   672,   840,    91,
      92,    93,   645,   645,   740,   645,   837,   138,   653,   645,
     105,   106,   136,   108,   534,    29,   111,   662,   558,    49,
     839,    51,    52,    53,    54,   130,    75,    76,   130,   169,
      80,   169,   129,   769,   139,   140,   141,   139,   140,    69,
      77,    78,   139,   266,   267,   585,   551,    41,   271,   554,
     129,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   797,   743,   706,   130,   605,   706,   139,   140,   141,
     706,   130,   164,   226,   227,   228,   229,   230,   231,   308,
     727,   312,   313,     3,   558,   314,   165,   166,   167,   242,
     134,   727,   155,   246,   775,   318,   319,   320,   142,   322,
     253,   254,   122,   839,   124,     3,   727,   260,   261,   262,
     263,   585,   652,   653,    36,    37,   656,     4,   658,   766,
      30,    31,   662,   859,   134,   645,   307,     3,   150,   151,
     766,   605,   142,   308,   129,   675,   158,   312,   313,   314,
     783,   317,   164,   783,     3,   766,   882,   783,    82,   870,
     871,   872,   692,   130,    94,   836,    51,    52,   879,   388,
     700,   384,   139,   140,   141,   705,    18,   672,   121,   285,
       7,   324,   325,   289,   290,   715,    47,    48,   652,   653,
     333,   902,   130,   904,   130,   725,   133,   134,   662,   130,
     730,   130,    29,   130,   734,    32,   736,   139,   140,   141,
     740,   675,   126,    40,   128,   130,   130,   130,   132,   133,
     134,   130,    49,   388,    51,    94,    21,   393,    55,   130,
     139,   140,   141,   139,   140,   141,   130,   456,   130,   769,
     139,   140,   141,    70,   130,    72,    73,    74,    75,   130,
     463,   464,    79,   466,   168,   169,   170,   171,   133,   130,
     790,   725,   130,    90,   312,   313,   479,   797,   130,   141,
     734,   801,   736,   130,   130,   150,   151,   443,    12,   126,
     130,   139,   443,   158,   130,   132,   133,   134,   140,   164,
     130,   456,   130,   459,   437,   139,   140,   141,   130,    33,
      34,    35,    36,   120,    38,    39,   139,   140,   141,   839,
     840,   165,   166,   167,   130,   528,   141,   483,   130,   130,
     486,   168,   169,   170,   467,   486,   790,   130,   137,   859,
      64,    65,    66,   130,   128,   134,   502,   801,   130,   552,
     506,   502,   555,   126,   130,   128,   130,   130,   139,   132,
     133,   134,   882,   130,   130,     6,   527,     8,   126,   126,
     126,   123,   127,   127,   123,   126,   137,   141,   534,   126,
     122,   129,   538,   539,   540,   541,    27,   137,   125,   135,
     541,   130,   553,   137,   125,   168,   169,   170,   171,   126,
     125,   128,   130,   130,   560,   132,   133,   134,   564,   560,
     132,   134,   126,   564,   132,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   538,   539,
     126,   137,   128,   145,   130,   145,   132,   133,   134,   595,
     169,   168,   169,   170,   171,   601,   602,   128,   169,    90,
     126,   128,   128,   128,   130,   128,   132,   133,   134,   126,
     128,   128,   128,   130,   128,   132,   133,   134,   671,   172,
     673,   169,   168,   169,   170,   171,   126,   128,   128,   128,
     130,   128,   132,   133,   134,   595,   169,     5,   128,   645,
     129,   601,   168,   169,   170,   171,     5,   129,   645,   137,
     643,   168,   169,   170,   171,   867,   709,   794,   711,   670,
     713,   502,   839,   783,   727,   779,   539,   824,   168,   169,
     170,   171,   877,   679,   556,   126,   691,   128,   679,   130,
      19,   132,   133,   134,    11,    12,   605,   375,    -1,    -1,
     375,    -1,    -1,    20,    -1,    22,    23,    24,    25,    26,
     706,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   762,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   727,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,     1,   785,   786,   787,     6,     7,     8,     9,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     761,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
     766,    32,    -1,    -1,   126,    36,   128,    -1,   130,    40,
     132,   133,   134,    -1,    -1,    -1,    -1,   783,   784,    -1,
      -1,    -1,    -1,   784,    55,   838,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,   103,   104,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   919,    -1,   874,   875,
     876,    -1,    -1,   874,   875,   876,   126,    -1,   128,    -1,
     130,    -1,   132,   133,   134,    -1,    -1,   126,    -1,   128,
      -1,   130,   162,   132,   133,   134,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,    -1,    -1,   895,   896,   897,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,   169,    -1,   171,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,    -1,   171,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,   169,    -1,   171,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,    -1,   171,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,    -1,   171,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,   169,
      -1,   171,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,   169,    -1,
     171,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,   169,    -1,   171,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,   127,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,   169,    -1,   171,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,   123,
     124,   125,    -1,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,   135,   136,   137,    -1,   139,   140,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,   169,    -1,   171,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,   123,    -1,
     125,   126,   127,    -1,    -1,   130,    -1,   132,    -1,    -1,
     135,   136,   137,    -1,   139,   140,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,   169,    -1,   171,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,   123,    -1,   125,
      -1,   127,    -1,    -1,   130,   131,    -1,    -1,    -1,   135,
     136,   137,    -1,   139,   140,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,    -1,   171,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,   123,    -1,   125,    -1,
     127,    -1,    -1,   130,    -1,    -1,    -1,    -1,   135,   136,
     137,    -1,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,   169,    -1,   171,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,   123,    -1,   125,    -1,   127,
      -1,    -1,    -1,    -1,   132,    -1,    -1,   135,   136,   137,
      -1,   139,   140,    -1,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,    -1,   171,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,   123,    -1,   125,    -1,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
     139,   140,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,    -1,   171,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,   169,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,   135,   136,   137,    -1,   139,   140,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,   169,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,   123,    -1,   125,
      -1,   127,    -1,    -1,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,    -1,   139,   140,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,   123,    -1,   125,    -1,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,   135,   136,   137,    -1,
     139,   140,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,   123,    -1,   125,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,    -1,   139,   140,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   126,   169,   128,    -1,
     130,    -1,   132,   133,   134,   126,   133,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    14,    15,    16,
      17,    18,    19,    27,    28,    29,    32,    36,    40,    55,
      71,    81,    83,    84,    85,    86,    87,    88,    89,    95,
      96,    97,    98,    99,   100,   101,   102,   128,   168,   174,
     175,   176,   208,   222,   224,   234,   313,   359,   360,   361,
     352,   209,   316,   330,   327,   324,     7,    29,    32,    40,
      49,    51,    55,    70,    72,    73,    74,    75,    79,    90,
     364,     6,     8,    27,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    90,    36,    37,
      75,    76,   356,   357,   314,    77,    78,   358,   356,    72,
     130,   130,   130,   130,   317,   318,   315,   179,   180,   181,
     178,   223,   177,     0,   225,   325,   326,    11,    12,    20,
      22,    23,    24,    25,    26,   130,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   169,
     171,   301,   306,   307,   308,   309,   310,   311,   312,   126,
     128,   130,   132,   133,   134,   168,   169,   170,   171,   365,
     403,   406,   365,   126,   130,   132,   133,   134,   169,   170,
     369,   403,   407,   365,    75,    13,    49,    51,    52,    53,
      54,    69,    12,    33,    34,    35,    36,    38,    39,    64,
      65,    66,   354,    41,    42,    43,    44,    46,    77,    91,
      92,    93,   164,   353,    29,    30,    31,   355,   355,   355,
      66,    90,   155,    80,   355,   348,   335,   338,    41,    94,
     136,   336,   130,   130,   337,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   331,   332,   130,   171,   221,   334,
     333,   155,   365,   365,   221,     3,     3,     4,     3,   129,
       3,   301,   132,   378,   403,   407,   369,   319,   320,    82,
     362,    18,   321,   322,   323,    94,   363,   121,   404,   405,
     366,   370,   371,   350,    51,    52,   355,   355,   355,   355,
     355,   355,   355,    45,   355,    47,    48,   355,   355,   130,
     130,   130,   355,   355,   355,   355,   130,   126,   132,   133,
     134,   168,   169,   170,   417,   221,   221,   130,   130,    94,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   171,   222,   412,   414,   415,   416,   417,   412,   412,
     412,   130,   226,   379,   380,   365,   369,    21,   328,   378,
     378,   369,   130,   128,   183,   184,   185,   186,   187,   189,
     301,   221,   126,   221,   367,   221,   126,   128,   132,   133,
     134,   168,   169,   170,   221,   372,   401,   408,   221,   417,
     355,   355,   130,   130,   130,   130,   130,   130,   130,   355,
     130,   130,   130,   130,   130,   130,   130,   349,   130,   130,
     413,   414,   416,   141,   228,   126,   132,   133,   134,   168,
     169,   170,   381,   401,   410,   221,   329,   369,   183,   139,
     210,   140,   141,   368,   402,   373,   374,   351,   130,   130,
     130,   355,   229,   230,   301,   120,   291,   383,   382,   384,
     369,   129,   183,   137,   128,   191,   188,   221,   221,   126,
     132,   133,   134,   168,   169,   170,   375,   401,   409,   221,
     355,   130,   134,   142,   126,   138,   231,   235,   170,   395,
     401,   408,   126,   132,   133,   134,   168,   169,   170,   385,
     401,   411,   221,   183,   192,   190,   301,   376,   377,   130,
     230,   183,     1,   103,   104,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   162,
     236,   396,   397,   386,   387,   388,   211,     1,   106,   108,
     136,   194,   195,   196,   134,   142,   365,   221,   130,   130,
     134,   137,   171,   182,   183,   186,   187,   189,   302,   305,
     306,   308,   310,   311,   237,   238,   239,   122,   123,   124,
     125,   127,   130,   131,   222,   264,   265,   303,   307,   308,
     311,   264,   263,   303,   301,   259,   241,   243,   246,   248,
     251,   253,   256,   133,   398,   401,   409,   221,   365,   170,
     389,   401,   408,   221,   291,   120,   123,   125,   127,   135,
     136,   137,   139,   140,   169,   296,   297,   304,   308,   312,
     197,   301,   193,   134,   301,   139,   130,   292,   292,   292,
     292,   130,   293,   294,   296,   126,   126,   265,   126,   126,
     303,   258,   294,   126,   126,   127,   127,   123,   123,   126,
     399,   400,   390,   391,   212,   137,   141,   126,   199,   137,
     129,   196,   182,   183,   130,   171,   227,   296,   131,   227,
     296,   295,   240,   122,   124,   132,   171,   232,   266,   269,
     271,   273,   296,   266,   122,   213,   135,   260,   227,   242,
     244,   247,   249,   252,   254,   257,   365,   221,   133,   392,
     401,   409,   221,     1,   105,   106,   108,   111,   214,   296,
     298,   200,   137,   301,   293,   266,   274,   232,   270,   273,
     272,   232,   233,   273,   134,   137,   261,   262,   302,   306,
     308,   310,   311,   130,   221,   125,   221,   125,   221,   125,
     266,   393,   394,   130,   296,   215,   263,   297,   299,   272,
     198,   131,   275,   296,   132,   276,   126,   130,   232,   267,
     268,   273,   292,   134,   126,   245,   250,   255,   365,   221,
     137,   126,   137,   217,   126,   134,   142,   271,   132,   201,
     133,   134,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   277,   278,   279,   292,   269,   262,
     301,   221,   221,   221,   171,   216,   296,   218,   220,   213,
     300,   273,   202,   296,   145,   145,   169,   128,   169,   128,
     128,   128,   128,   128,   128,   133,   279,   280,   292,   272,
     221,   233,   297,   150,   151,   158,   164,   203,   204,   281,
     283,   284,   285,   286,   165,   166,   167,   289,   290,   282,
     172,   287,   271,   169,   128,   128,   128,   133,   204,   169,
     288,   288,   288,   288,     5,   301,   301,   301,   129,   290,
     288,   273,   205,   207,   206,   129,   169,   129,   129,   129,
     129,   222,   222,   222,   129,   137,   288,     5,   288,   219,
     129,   129,   129,   221
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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

/* Line 1806 of yacc.c  */
#line 233 "surface.yy"
    { YYACCEPT; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 235 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 249 "surface.yy"
    { lexerFileNameMode(); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 251 "surface.yy"
    {
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile((yyvsp[(3) - (3)].yyString), directory, fileName, lineNr))
			    includeFile(directory, fileName, false, lineNr);
			}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 259 "surface.yy"
    { lexerFileNameMode(); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 261 "surface.yy"
    {
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile((yyvsp[(3) - (3)].yyString), directory, fileName, lineNr))
			    includeFile(directory, fileName, true, lineNr);
			}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 270 "surface.yy"
    {
			  cout << directoryManager.getCwd() << '\n';
			}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 273 "surface.yy"
    { lexerFileNameMode(); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 275 "surface.yy"
    {
			  string directory;
			  directoryManager.realPath((yyvsp[(3) - (3)].yyString), directory);
			  if (!directoryManager.cd(directory))
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": cd failed");
			    }
			}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 284 "surface.yy"
    { lexerFileNameMode(); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 286 "surface.yy"
    {
			  string directory;
			  directoryManager.realPath((yyvsp[(3) - (3)].yyString), directory);
			  if (directoryManager.pushd(directory) == UNDEFINED)
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": pushd failed");
			    }
			}
    break;

  case 17:

/* Line 1806 of yacc.c  */
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
			}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 306 "surface.yy"
    { lexerStringMode(); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 308 "surface.yy"
    {
			  system((string("ls") + (yyvsp[(3) - (3)].yyString)).c_str());
			}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 312 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 317 "surface.yy"
    {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 350 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (2)].yyToken)));
                        }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 354 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (2)].yyToken)));
                        }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 361 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 369 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  moduleExpressions.push(new ModuleExpression(t));
			}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 379 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 395 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (1)].yyToken)));
                        }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 402 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 410 "surface.yy"
    { clear(); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 412 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, tokenSequence));
			}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 419 "surface.yy"
    {}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 422 "surface.yy"
    { store((yyvsp[(3) - (3)].yyToken)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 423 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 430 "surface.yy"
    {
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 435 "surface.yy"
    {
			  currentSyntaxContainer = oldSyntaxContainer;
			}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 450 "surface.yy"
    {
			  currentRenaming->addSortMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 454 "surface.yy"
    {
			  currentRenaming->addLabelMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 457 "surface.yy"
    { lexBubble(BAR_COLON | BAR_TO, 1); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 458 "surface.yy"
    { lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 459 "surface.yy"
    {}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 464 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 465 "surface.yy"
    {}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 466 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 472 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 473 "surface.yy"
    {}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 474 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 481 "surface.yy"
    { currentRenaming->setPrec((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 482 "surface.yy"
    { clear(); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 483 "surface.yy"
    { currentRenaming->setGather(tokenSequence); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 484 "surface.yy"
    { clear(); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 485 "surface.yy"
    { currentRenaming->setFormat(tokenSequence); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 486 "surface.yy"
    { lexerLatexMode(); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 487 "surface.yy"
    { currentRenaming->setLatexMacro((yyvsp[(4) - (5)].yyString)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 493 "surface.yy"
    { lexerIdMode(); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 495 "surface.yy"
    {
			  fileTable.beginModule((yyvsp[(1) - (5)].yyToken), (yyvsp[(3) - (5)].yyToken));
			  interpreter.setCurrentView(new View((yyvsp[(3) - (5)].yyToken)));
			  currentSyntaxContainer = CV;
			  CV->addFrom(moduleExpressions.top());
			  moduleExpressions.pop();
			}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 503 "surface.yy"
    {
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 508 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  interpreter.insertView(((yyvsp[(3) - (12)].yyToken)).code(), CV);
			  CV->finishView();
			}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 521 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
				       ": skipping " << QUOTE("->") << " in variable declaration.");
			}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 529 "surface.yy"
    {
			  CV->addSortMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 532 "surface.yy"
    {}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 533 "surface.yy"
    { lexBubble(BAR_COLON | BAR_TO, 1); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 538 "surface.yy"
    { (yyval.yyToken) = (yyvsp[(1) - (2)].yyToken); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 540 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  (yyval.yyToken) = t;
			}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 549 "surface.yy"
    {
			  //
			  //	Specific op->op mapping.
			  //
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpMapping(lexerBubble);
			}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 557 "surface.yy"
    {
			  lexBubble(END_STATEMENT, 1);
			}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 561 "surface.yy"
    {
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 566 "surface.yy"
    {
			  //
			  //	At this point we don't know if we have an op->term mapping
			  //	or a generic op->op mapping so we save the from description and
			  //	press on.
			  //
			  opDescription = lexerBubble;
			  lexBubble(END_STATEMENT, 1);
			}
    break;

  case 88:

/* Line 1806 of yacc.c  */
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
			}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 598 "surface.yy"
    {}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 600 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  lexerBubble.append(t);
			}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 608 "surface.yy"
    { lexBubble(BAR_RIGHT_PAREN, 1); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 609 "surface.yy"
    {}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 615 "surface.yy"
    { lexerIdMode(); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 617 "surface.yy"
    {
			  interpreter.setCurrentModule(new SyntacticPreModule((yyvsp[(1) - (3)].yyToken), (yyvsp[(3) - (3)].yyToken)));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule((yyvsp[(1) - (3)].yyToken), (yyvsp[(3) - (3)].yyToken));
			}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 623 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule((yyvsp[(8) - (8)].yyToken));
			}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 630 "surface.yy"
    {}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 632 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  store(t);
			}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 640 "surface.yy"
    {}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 649 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter((yyvsp[(1) - (3)].yyToken), me);
			}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 656 "surface.yy"
    {}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 658 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			    ": saw " << QUOTE(':') << " instead of " <<
			    QUOTE("::") << " in parameter declaration.");
			}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 666 "surface.yy"
    {
			  singleton[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(singleton[0]);
			  currentSyntaxContainer->addType(false, singleton);
			  (yyval.yyToken) = (yyvsp[(1) - (1)].yyToken);  // needed for line number
			}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 675 "surface.yy"
    {}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 686 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport((yyvsp[(1) - (2)].yyToken), me);
			}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 692 "surface.yy"
    { clear(); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 693 "surface.yy"
    { CM->addSortDecl(tokenSequence); }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 695 "surface.yy"
    { clear(); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 696 "surface.yy"
    { CM->addSubsortDecl(tokenSequence); }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 698 "surface.yy"
    { lexBubble(BAR_COLON, 1); }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 699 "surface.yy"
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 700 "surface.yy"
    {}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 702 "surface.yy"
    {}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 704 "surface.yy"
    {}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 706 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON, 1); }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 707 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 708 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 710 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON, 1);  }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 711 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 712 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 713 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 715 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_EQUALS, 1); }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 716 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 717 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 719 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_EQUALS, 1); }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 720 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 721 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 722 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 724 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_ARROW2, 1); }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 725 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 726 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 728 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_ARROW2, 1); }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 729 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 730 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 731 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 733 "surface.yy"
    { lexBubble(BAR_COLON, 1); }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 734 "surface.yy"
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 735 "surface.yy"
    { CM->setFlag(SymbolType::MESSAGE); }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 738 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 743 "surface.yy"
    {
			}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 746 "surface.yy"
    {
			}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 749 "surface.yy"
    { clear(); }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 750 "surface.yy"
    { CM->addSubsortDecl(tokenSequence); }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 753 "surface.yy"
    {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeOpDeclsConsistent();
			}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 763 "surface.yy"
    {}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 764 "surface.yy"
    {}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 772 "surface.yy"
    {
			}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 776 "surface.yy"
    { currentSyntaxContainer->addVarDecl((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 777 "surface.yy"
    { currentSyntaxContainer->addVarDecl((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 784 "surface.yy"
    { singleton[0] = (yyvsp[(1) - (1)].yyToken); CM->addOpDecl(singleton); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 785 "surface.yy"
    { CM->addOpDecl(lexerBubble); }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 791 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) <<
				       ": missing " << QUOTE("->") << " in constant declaration.");
			}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 798 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
				       ": skipping stray " << QUOTE(":") << " in operator declaration.");

			}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 808 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 813 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 820 "surface.yy"
    {
			  if ((yyvsp[(1) - (2)].yyBool))
			    CM->convertSortsToKinds();
			}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 827 "surface.yy"
    {}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 830 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 831 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 839 "surface.yy"
    {
			  singleton[0] = (yyvsp[(1) - (1)].yyToken);
			  currentSyntaxContainer->addType(false, singleton);
			}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 843 "surface.yy"
    { clear(); }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 845 "surface.yy"
    {
			  currentSyntaxContainer->addType(true, tokenSequence);
			}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 850 "surface.yy"
    { store((yyvsp[(3) - (3)].yyToken)); }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 851 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 854 "surface.yy"
    {}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 863 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 867 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 871 "surface.yy"
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 877 "surface.yy"
    {
			  CM->setFlag(SymbolType::ASSOC);
			}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 881 "surface.yy"
    {
			  CM->setFlag(SymbolType::COMM);
			}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 884 "surface.yy"
    { lexBubble(BAR_RIGHT_BRACKET | BAR_OP_ATTRIBUTE, 1); }
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 885 "surface.yy"
    { CM->setIdentity(lexerBubble); }
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 887 "surface.yy"
    {
			  CM->setFlag(SymbolType::IDEM);
			}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 891 "surface.yy"
    {
			  CM->setFlag(SymbolType::ITER);
			}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 894 "surface.yy"
    { CM->setPrec((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 895 "surface.yy"
    { clear(); }
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 896 "surface.yy"
    { CM->setGather(tokenSequence); }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 897 "surface.yy"
    { clear(); }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 898 "surface.yy"
    { CM->setFormat(tokenSequence); }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 899 "surface.yy"
    { clear(); }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 900 "surface.yy"
    { CM->setStrat(tokenSequence); }
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 901 "surface.yy"
    { clear(); }
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 902 "surface.yy"
    { CM->setPoly(tokenSequence); }
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 904 "surface.yy"
    {
			  CM->setFlag(SymbolType::MEMO);
			}
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 908 "surface.yy"
    {
			  CM->setFlag(SymbolType::CTOR);
			}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 912 "surface.yy"
    {
			  clear();
			  CM->setFrozen(tokenSequence);
			}
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 916 "surface.yy"
    { clear(); }
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 917 "surface.yy"
    { CM->setFrozen(tokenSequence); }
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 919 "surface.yy"
    {
			  CM->setFlag(SymbolType::CONFIG);
			}
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 923 "surface.yy"
    {
			  CM->setFlag(SymbolType::OBJECT);
			}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 927 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 931 "surface.yy"
    {
			  CM->setMetadata((yyvsp[(2) - (2)].yyToken));
			}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 934 "surface.yy"
    { lexerLatexMode(); }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 935 "surface.yy"
    { CM->setLatexMacro((yyvsp[(4) - (5)].yyString)); }
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 936 "surface.yy"
    {}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 938 "surface.yy"
    {
			  CM->setFlag(SymbolType::DITTO);
			}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 951 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 952 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 959 "surface.yy"
    { clear(); CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[(2) - (2)].yyToken), tokenSequence); }
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 960 "surface.yy"
    { CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); }
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 961 "surface.yy"
    { CM->addHook(SyntacticPreModule::OP_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 962 "surface.yy"
    { CM->addHook(SyntacticPreModule::TERM_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 968 "surface.yy"
    {}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 970 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing " <<
				       QUOTE("is") << " keyword.");
			}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 976 "surface.yy"
    {}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 978 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			}
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 986 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 990 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 991 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 992 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 993 "surface.yy"
    { store((yyvsp[(4) - (4)].yyToken)); }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 1000 "surface.yy"
    {
			  Token t;
			  if (fragments.size() == 1)
			    t = fragments[0];
			  else
			    t.tokenize(Token::bubbleToPrefixNameCode(fragments), fragments[0].lineNumber());
			  fragClear();
			  (yyval.yyToken) = t;
			}
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 1011 "surface.yy"
    { fragStore((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 1012 "surface.yy"
    { fragStore((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 1013 "surface.yy"
    { fragStore((yyvsp[(5) - (5)].yyToken)); }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 1016 "surface.yy"
    { fragStore((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 1017 "surface.yy"
    {}
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 1018 "surface.yy"
    {}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 1098 "surface.yy"
    { lexBubble(END_COMMAND, 1); }
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 1100 "surface.yy"
    {
			  interpreter.setCurrentModule(lexerBubble);
			}
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 1103 "surface.yy"
    { lexBubble(END_COMMAND, 1); }
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 1105 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->dump();
			}
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 1110 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 1115 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(lexerBubble);
			}
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 1122 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 1127 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(lexerBubble);
			}
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 1134 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 1139 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sreduce(lexerBubble);
			}
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 1146 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 1151 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(lexerBubble, (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 1158 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 1164 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(lexerBubble, number, (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 1170 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 1177 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(lexerBubble, number, number2, (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 1183 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 1190 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(lexerBubble, number, number2, (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 1196 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 1202 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 1209 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 1214 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.check(lexerBubble);
			}
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 1221 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 1228 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, (yyvsp[(1) - (3)].yySearchKind));
			}
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 1234 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 1240 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(lexerBubble, (yyvsp[(1) - (3)].yyBool), number);
			}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 1246 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 1252 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.unify(lexerBubble, number);
			}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 1258 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 1264 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantUnify(lexerBubble, number, (yyvsp[(1) - (5)].yyBool));
			}
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 1271 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 1277 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.getVariants(lexerBubble, number, (yyvsp[(3) - (6)].yyBool), (yyvsp[(1) - (6)].yyBool));
			}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 1283 "surface.yy"
    {
			  interpreter.cont((yyvsp[(3) - (4)].yyInt64), (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 1287 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 1292 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(lexerBubble);
			}
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 1298 "surface.yy"
    {
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(lexerBubble);
			}
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 1303 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 1305 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect((yyvsp[(2) - (4)].yyBool));
			}
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 1309 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 1311 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude((yyvsp[(2) - (4)].yyBool));
			}
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 1315 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 1317 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect((yyvsp[(2) - (4)].yyBool));
			}
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 1321 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 1323 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal((yyvsp[(2) - (4)].yyBool));
			}
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 1328 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			}
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 1335 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 1337 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			}
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 1341 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 1343 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			}
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 1347 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 1349 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(true);
			}
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 1353 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 1355 "surface.yy"
    {
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showView();
			}
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 1360 "surface.yy"
    {
			  interpreter.showModules(true);
			}
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 1364 "surface.yy"
    {
			  interpreter.showNamedViews();
			}
    break;

  case 402:

/* Line 1806 of yacc.c  */
#line 1367 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 1369 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSortsAndSubsorts();
			}
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 1373 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 1375 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showOps();
			}
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 1379 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 1381 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showVars();
			}
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 1385 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 409:

/* Line 1806 of yacc.c  */
#line 1387 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showMbs();
			}
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 1391 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 1393 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showEqs();
			}
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 1397 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 1399 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showRls();
			}
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 1403 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 1405 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSummary();
			}
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 1409 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 1411 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showKinds();
			}
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 1416 "surface.yy"
    {
			  interpreter.showSearchPath((yyvsp[(3) - (4)].yyInt64));
			}
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 1420 "surface.yy"
    {
			  interpreter.showSearchPathLabels((yyvsp[(4) - (5)].yyInt64));
			}
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 1424 "surface.yy"
    {
			  interpreter.showSearchGraph();
			}
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 1427 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 1429 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showProfile();
			}
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 1437 "surface.yy"
    {
			  globalAdvisoryFlag = alwaysAdviseFlag ? true : (yyvsp[(4) - (5)].yyBool);
			}
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 1441 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 1445 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, (yyvsp[(5) - (6)].yyBool));
			}
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 1449 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 1453 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 1457 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, (yyvsp[(5) - (6)].yyBool));
			}
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 1461 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 1465 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 1469 "surface.yy"
    {
			  interpreter.setPrintFlag((yyvsp[(3) - (5)].yyPrintFlags), (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 1473 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 1477 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE_NEWLINE, (yyvsp[(5) - (6)].yyBool));
			}
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 1481 "surface.yy"
    {
			  interpreter.setFlag((yyvsp[(3) - (5)].yyFlags), (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 1485 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, (yyvsp[(3) - (4)].yyBool));
			}
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 1488 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 1489 "surface.yy"
    { lexerInitialMode(); }
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 1491 "surface.yy"
    {
			  interpreter.setAutoImport((yyvsp[(2) - (7)].yyImportMode), (yyvsp[(4) - (7)].yyToken), (yyvsp[(6) - (7)].yyBool));
			}
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 1494 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 1495 "surface.yy"
    { lexerInitialMode(); }
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 1497 "surface.yy"
    {
			  interpreter.setOmodInclude((yyvsp[(5) - (8)].yyToken), (yyvsp[(7) - (8)].yyBool));
			}
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 1501 "surface.yy"
    {
			  globalVerboseFlag = (yyvsp[(3) - (4)].yyBool);
			}
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 1505 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 1509 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 1513 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 1517 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, (yyvsp[(3) - (4)].yyBool));
			}
    break;

  case 447:

/* Line 1806 of yacc.c  */
#line 1521 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 1528 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			}
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 1532 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			}
    break;

  case 450:

/* Line 1806 of yacc.c  */
#line 1536 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			}
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 1540 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			}
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 1547 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 1551 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[(3) - (4)].yyBool));
			}
    break;

  case 454:

/* Line 1806 of yacc.c  */
#line 1557 "surface.yy"
    { lexerInitialMode(); }
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 1564 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_MIXFIX; }
    break;

  case 457:

/* Line 1806 of yacc.c  */
#line 1565 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FLAT; }
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 1566 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_ALIASES; }
    break;

  case 459:

/* Line 1806 of yacc.c  */
#line 1567 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_PARENS; }
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 1568 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_GRAPH; }
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 1569 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_CONCEAL; }
    break;

  case 462:

/* Line 1806 of yacc.c  */
#line 1570 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_NUMBER; }
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 1571 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_RAT; }
    break;

  case 464:

/* Line 1806 of yacc.c  */
#line 1572 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_COLOR; }
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 1573 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FORMAT; }
    break;

  case 466:

/* Line 1806 of yacc.c  */
#line 1576 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE; }
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 1577 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_CONDITION; }
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 1578 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_WHOLE; }
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 1579 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SUBSTITUTION; }
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 1580 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SELECT; }
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 1581 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_MB; }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 1582 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_EQ; }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 1583 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_RL; }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 1584 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_REWRITE; }
    break;

  case 475:

/* Line 1806 of yacc.c  */
#line 1585 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BODY; }
    break;

  case 476:

/* Line 1806 of yacc.c  */
#line 1586 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BUILTIN; }
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 1589 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 1590 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 1593 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 1594 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 481:

/* Line 1806 of yacc.c  */
#line 1597 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 1598 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 1601 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 1602 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 1607 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::NARROW; }
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 1608 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::XG_NARROW; }
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 1609 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::SEARCH; }
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 1612 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 1613 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 1616 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 1617 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 1620 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 1621 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 1624 "surface.yy"
    { (yyval.yyInt64) = (yyvsp[(1) - (1)].yyInt64); }
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 1625 "surface.yy"
    { (yyval.yyInt64) = NONE; }
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 1628 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::PROTECTING; }
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 1629 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::EXTENDING; }
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 1630 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::INCLUDING; }
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 1640 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 1644 "surface.yy"
    { moduleExpr = lexerBubble; lexBubble(END_COMMAND, 1); }
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 1656 "surface.yy"
    { lexSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 1659 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0);  }
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 1664 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 1666 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 1672 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); }
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 1674 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 1689 "surface.yy"
    { lexSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 1692 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 1701 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 1703 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 1705 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 1715 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); }
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 1717 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 1719 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 1729 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 1731 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 1742 "surface.yy"
    {
			  number = Token::codeToInt64(lexerBubble[1].code());
			  number2 = Token::codeToInt64(lexerBubble[3].code());
			  clear();
			}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 1748 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 1758 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 1760 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 1770 "surface.yy"
    { number2 = Token::codeToInt64(lexerBubble[2].code()); }
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 1772 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 1777 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0, 1); }
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 1783 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 1, 1); }
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 1785 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON | END_COMMAND, 0); }
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 1788 "surface.yy"
    {
			  lexerBubble.resize(1);
			  lexerBubble[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(lexerBubble[0]);
			}
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 1827 "surface.yy"
    {}
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 1832 "surface.yy"
    {
			  singleton[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(singleton[0]);
			  interpreter.addSelected(singleton);
			}
    break;

  case 609:

/* Line 1806 of yacc.c  */
#line 1843 "surface.yy"
    {
			  singleton[0] = (yyvsp[(1) - (1)].yyToken);
			  interpreter.addSelected(singleton);
			}
    break;

  case 610:

/* Line 1806 of yacc.c  */
#line 1848 "surface.yy"
    {
			  interpreter.addSelected(lexerBubble);
			}
    break;



/* Line 1806 of yacc.c  */
#line 6033 "surface.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 1878 "surface.yy"


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

