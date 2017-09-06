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
//#define YYPARSE_PARAM	parseResult
//#define PARSE_RESULT	(*((UserLevelRewritingContext::ParseResult*) parseResult))
#define PARSE_RESULT	(*parseResult)

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

static void yyerror(UserLevelRewritingContext::ParseResult* parseResult, char *s);

void cleanUpModuleExpression();
void cleanUpParser();
void missingSpace(const Token& token);


/* Line 268 of yacc.c  */
#line 147 "surface.c"

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
     KW_TEST = 358,
     KW_SMT_SEARCH = 359,
     KW_ENDM = 360,
     KW_IMPORT = 361,
     KW_ENDV = 362,
     KW_SORT = 363,
     KW_SUBSORT = 364,
     KW_OP = 365,
     KW_OPS = 366,
     KW_MSGS = 367,
     KW_VAR = 368,
     KW_CLASS = 369,
     KW_SUBCLASS = 370,
     KW_MB = 371,
     KW_CMB = 372,
     KW_EQ = 373,
     KW_CEQ = 374,
     KW_RL = 375,
     KW_CRL = 376,
     KW_IS = 377,
     KW_FROM = 378,
     KW_ARROW = 379,
     KW_ARROW2 = 380,
     KW_PARTIAL = 381,
     KW_IF = 382,
     KW_LABEL = 383,
     KW_TO = 384,
     KW_COLON2 = 385,
     KW_ASSOC = 386,
     KW_COMM = 387,
     KW_ID = 388,
     KW_IDEM = 389,
     KW_ITER = 390,
     KW_LEFT = 391,
     KW_RIGHT = 392,
     KW_PREC = 393,
     KW_GATHER = 394,
     KW_METADATA = 395,
     KW_STRAT = 396,
     KW_POLY = 397,
     KW_MEMO = 398,
     KW_FROZEN = 399,
     KW_CTOR = 400,
     KW_LATEX = 401,
     KW_SPECIAL = 402,
     KW_CONFIG = 403,
     KW_OBJ = 404,
     KW_MSG = 405,
     KW_DITTO = 406,
     KW_FORMAT = 407,
     KW_ID_HOOK = 408,
     KW_OP_HOOK = 409,
     KW_TERM_HOOK = 410,
     KW_IN = 411,
     IDENTIFIER = 412,
     NUMERIC_ID = 413,
     ENDS_IN_DOT = 414,
     FORCE_LOOKAHEAD = 415
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 105 "surface.yy"

  bool yyBool;
  Int64 yyInt64;
  const char* yyString;
  Token yyToken;
  ImportModule::ImportMode yyImportMode;
  Interpreter::Flags yyFlags;
  Interpreter::PrintFlags yyPrintFlags;
  Interpreter::SearchKind yySearchKind;



/* Line 293 of yacc.c  */
#line 356 "surface.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 343 of yacc.c  */
#line 116 "surface.yy"

int yylex(YYSTYPE* lvalp);


/* Line 343 of yacc.c  */
#line 373 "surface.c"

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
#define YYFINAL  116
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  175
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  246
/* YYNRULES -- Number of rules.  */
#define YYNRULES  620
/* YYNRULES -- Number of states.  */
#define YYNSTATES  928

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   415

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     130,   131,   142,   141,   136,     2,   132,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   128,     2,
     133,   129,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   134,     2,   135,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   143,   137,   144,     2,     2,     2,     2,
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
     125,   126,   127,   138,   139,   140,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174
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
     971,   972,   976,   977,   981,   983,   984,   989,   990,   995,
     996,  1001,  1002,  1007,  1012,  1013,  1018,  1019,  1024,  1025,
    1030,  1031,  1036,  1040,  1044,  1045,  1050,  1051,  1056,  1057,
    1062,  1063,  1068,  1069,  1074,  1075,  1080,  1081,  1086,  1087,
    1092,  1097,  1103,  1108,  1109,  1114,  1120,  1126,  1133,  1139,
    1145,  1152,  1158,  1164,  1170,  1176,  1183,  1189,  1194,  1195,
    1196,  1204,  1205,  1206,  1215,  1220,  1226,  1232,  1238,  1243,
    1249,  1252,  1255,  1258,  1261,  1267,  1272,  1273,  1277,  1279,
    1281,  1284,  1287,  1289,  1291,  1293,  1295,  1297,  1299,  1300,
    1302,  1304,  1306,  1308,  1310,  1312,  1314,  1316,  1318,  1320,
    1322,  1324,  1326,  1328,  1330,  1332,  1334,  1336,  1338,  1340,
    1342,  1344,  1346,  1348,  1350,  1351,  1353,  1354,  1356,  1357,
    1359,  1361,  1363,  1365,  1366,  1370,  1371,  1375,  1377,  1378,
    1382,  1384,  1385,  1389,  1390,  1394,  1395,  1399,  1401,  1402,
    1406,  1407,  1411,  1413,  1414,  1418,  1420,  1421,  1425,  1426,
    1430,  1431,  1435,  1436,  1440,  1442,  1443,  1447,  1448,  1452,
    1453,  1457,  1459,  1460,  1464,  1465,  1469,  1471,  1472,  1476,
    1477,  1481,  1483,  1484,  1488,  1489,  1493,  1495,  1496,  1500,
    1501,  1505,  1507,  1508,  1512,  1514,  1515,  1519,  1520,  1524,
    1526,  1528,  1530,  1532,  1534,  1536,  1538,  1540,  1542,  1544,
    1546,  1548,  1550,  1552,  1554,  1556,  1558,  1560,  1562,  1564,
    1566,  1568,  1570,  1572,  1574,  1576,  1578,  1580,  1582,  1584,
    1586,  1588,  1590,  1592,  1594,  1596,  1599,  1601,  1603,  1605,
    1607,  1610,  1612,  1614,  1616,  1618,  1620,  1622,  1624,  1626,
    1628
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     176,     0,    -1,   177,    -1,    -1,   226,    -1,   210,    -1,
     178,    -1,   315,    -1,    -1,   170,   179,     3,    -1,    -1,
     100,   180,     3,    -1,    95,    -1,    -1,    96,   181,     3,
      -1,    -1,    97,   182,     3,    -1,    98,    -1,    -1,    99,
     183,     4,    -1,   101,    -1,   102,    -1,   304,   294,    -1,
     307,   132,    -1,   191,   294,    -1,   188,   294,    -1,   189,
     294,    -1,   185,   141,   184,    -1,   173,    -1,   186,    -1,
     185,   141,   185,    -1,   187,    -1,   188,    -1,   191,    -1,
     189,    -1,   303,    -1,   186,   142,   193,    -1,    -1,   187,
     143,   190,   192,   144,    -1,   130,   185,   131,    -1,   192,
     136,   303,    -1,   303,    -1,    -1,    -1,   130,   194,   196,
     195,   131,    -1,   197,    -1,     1,    -1,   197,   136,   198,
      -1,   198,    -1,   108,   298,   139,   298,    -1,   138,   303,
     139,   303,    -1,    -1,    -1,   110,   199,   201,   139,   200,
     203,    -1,    -1,   128,   202,   274,   273,   275,    -1,    -1,
      -1,   134,   204,   205,   135,    -1,    -1,   205,   206,    -1,
     206,    -1,   152,   171,    -1,    -1,   153,   130,   207,   290,
     131,    -1,    -1,   166,   130,   208,   290,   131,    -1,    -1,
     160,   130,   209,     5,   131,    -1,    -1,    -1,    -1,     8,
     211,   303,   123,   185,   212,   139,   185,   213,   293,   214,
     107,    -1,   214,   216,    -1,    -1,   124,    -1,    -1,   108,
     298,   139,   218,    -1,   113,   265,   128,   215,   235,    -1,
      -1,   110,   217,   219,    -1,     1,   132,    -1,   298,   294,
      -1,   173,    -1,    -1,    -1,   128,   220,   274,   273,   275,
     139,   221,   223,    -1,    -1,   139,   222,   223,    -1,   132,
      -1,   173,    -1,    -1,   130,   225,   131,    -1,    -1,    -1,
     236,   227,   303,   228,   230,   293,   237,   105,    -1,   132,
      -1,   173,    -1,   143,   231,   144,    -1,    -1,   231,   136,
     232,    -1,   232,    -1,   303,   233,   185,    -1,   140,    -1,
     128,    -1,   173,    -1,   275,   294,    -1,   234,    -1,     6,
      -1,     7,    -1,   237,   238,    -1,    -1,   106,   184,    -1,
      -1,   108,   239,   295,   229,    -1,    -1,   109,   240,   296,
     229,    -1,    -1,    -1,   110,   241,   128,   242,   268,    -1,
     111,   266,   128,   268,    -1,   113,   265,   128,   215,   235,
      -1,    -1,    -1,   116,   243,   128,   244,   223,    -1,    -1,
      -1,    -1,   117,   245,   128,   246,   127,   247,   223,    -1,
      -1,    -1,   118,   248,   129,   249,   223,    -1,    -1,    -1,
      -1,   119,   250,   129,   251,   127,   252,   223,    -1,    -1,
      -1,   120,   253,   125,   254,   223,    -1,    -1,    -1,    -1,
     121,   255,   125,   256,   127,   257,   223,    -1,    -1,    -1,
     164,   258,   128,   259,   268,    -1,   112,   266,   128,   268,
      -1,    -1,   114,   303,   260,   262,   132,    -1,    -1,   115,
     261,   296,   229,    -1,     1,   132,    -1,   137,    -1,   137,
     263,    -1,   264,    -1,   263,   136,   264,    -1,   304,   128,
     303,    -1,   265,   305,    -1,   305,    -1,   266,   267,    -1,
     267,    -1,   305,    -1,   224,    -1,   275,   274,   270,    -1,
     271,    -1,   234,    -1,   128,    -1,    -1,   269,   271,    -1,
     132,    -1,   234,    -1,   273,   272,    -1,   275,   278,   294,
      -1,   234,    -1,   124,    -1,   126,    -1,   274,   275,    -1,
      -1,   298,    -1,    -1,   134,   276,   277,   135,    -1,   277,
     136,   298,    -1,   298,    -1,   134,   279,   135,    -1,    -1,
     279,   281,    -1,   281,    -1,   147,    -1,   150,   147,    -1,
     151,   147,    -1,   145,    -1,   146,    -1,    -1,   280,   282,
     289,    -1,   148,    -1,   149,    -1,   152,   171,    -1,    -1,
     153,   130,   283,   290,   131,    -1,    -1,   166,   130,   284,
     290,   131,    -1,    -1,   155,   130,   285,   290,   131,    -1,
      -1,   156,   130,   286,   290,   131,    -1,   157,    -1,   159,
      -1,   158,    -1,    -1,   158,   130,   287,   290,   131,    -1,
     162,    -1,   163,    -1,   164,    -1,   154,   171,    -1,    -1,
     160,   130,   288,     5,   131,    -1,   161,   130,   291,   131,
      -1,   165,    -1,   174,    -1,    -1,   290,   171,    -1,   171,
      -1,   291,   292,    -1,   292,    -1,   167,   303,    -1,   167,
     303,   224,    -1,   168,   303,   224,    -1,   169,   303,   224,
      -1,   122,    -1,    -1,   132,    -1,    -1,   295,   298,    -1,
      -1,   296,   298,    -1,   296,   133,    -1,    -1,   298,   297,
     295,   133,    -1,   299,    -1,   306,    -1,    -1,   299,   143,
     300,   301,   144,    -1,    -1,   301,   136,   302,   299,    -1,
     299,    -1,   309,    -1,   310,    -1,   312,    -1,   313,    -1,
     132,    -1,   308,    -1,   136,    -1,   139,    -1,   310,    -1,
     312,    -1,   313,    -1,   309,    -1,   310,    -1,   313,    -1,
     132,    -1,   133,    -1,   124,    -1,   126,    -1,   129,    -1,
     125,    -1,   127,    -1,   171,    -1,   310,    -1,   314,    -1,
     129,    -1,   137,    -1,   141,    -1,   142,    -1,   125,    -1,
     127,    -1,   122,    -1,   138,    -1,   139,    -1,   132,    -1,
     173,    -1,   171,    -1,   143,    -1,   144,    -1,   141,    -1,
     142,    -1,   137,    -1,   140,    -1,   138,    -1,   123,    -1,
     122,    -1,   308,    -1,   173,    -1,   136,    -1,   139,    -1,
     164,    -1,   311,    -1,   106,    -1,   108,    -1,   109,    -1,
     110,    -1,   111,    -1,   113,    -1,   112,    -1,   114,    -1,
     115,    -1,   116,    -1,   117,    -1,   118,    -1,   119,    -1,
     120,    -1,   121,    -1,   105,    -1,   107,    -1,   133,    -1,
     128,    -1,   124,    -1,   126,    -1,   129,    -1,   125,    -1,
     127,    -1,   134,    -1,   135,    -1,   314,    -1,   145,    -1,
     146,    -1,   147,    -1,   148,    -1,   149,    -1,   150,    -1,
     151,    -1,   152,    -1,   153,    -1,   155,    -1,   156,    -1,
     157,    -1,   159,    -1,   160,    -1,   161,    -1,   158,    -1,
     154,    -1,   162,    -1,   163,    -1,   165,    -1,   166,    -1,
     167,    -1,   168,    -1,   169,    -1,    -1,    36,   316,   223,
      -1,    -1,    89,   317,   223,    -1,    -1,     9,   318,   368,
      -1,    -1,    87,   319,   368,    -1,    -1,    88,   320,   368,
      -1,    -1,   364,    11,   321,   368,    -1,    -1,   364,    12,
     322,   372,    -1,    -1,   364,    23,   323,   381,    -1,    -1,
     364,    24,   324,   381,    -1,    -1,   364,    25,   325,   372,
      -1,    -1,    19,   326,   368,    -1,    -1,   362,   327,   381,
      -1,    -1,   363,   328,   372,    -1,    -1,    18,   329,   372,
      -1,    -1,   364,    22,    18,   330,   372,    -1,    -1,   364,
      20,   365,    21,   331,   372,    -1,   364,    26,   366,   132,
      -1,    -1,   103,   332,   368,    -1,    -1,    13,   333,   368,
      -1,   224,    -1,    -1,    32,   359,   334,   415,    -1,    -1,
      32,   360,   335,   415,    -1,    -1,    55,   359,   336,   415,
      -1,    -1,    40,   361,   337,   415,    -1,    71,    72,   157,
     132,    -1,    -1,    29,     6,   338,   223,    -1,    -1,    29,
      57,   339,   223,    -1,    -1,    29,    60,   340,   223,    -1,
      -1,    29,     8,   341,   223,    -1,    29,    58,   132,    -1,
      29,    59,   132,    -1,    -1,    29,    61,   342,   223,    -1,
      -1,    29,    62,   343,   223,    -1,    -1,    29,    63,   344,
     223,    -1,    -1,    29,    64,   345,   223,    -1,    -1,    29,
      65,   346,   223,    -1,    -1,    29,    66,   347,   223,    -1,
      -1,    29,    67,   348,   223,    -1,    -1,    29,    68,   349,
     223,    -1,    29,    56,    94,   132,    -1,    29,    56,   138,
      94,   132,    -1,    29,    27,    41,   132,    -1,    -1,    29,
      90,   350,   223,    -1,    28,    29,    69,   358,   132,    -1,
      28,    29,    51,   358,   132,    -1,    28,    29,    13,    51,
     358,   132,    -1,    28,    29,    52,   358,   132,    -1,    28,
      29,    54,   358,   132,    -1,    28,    29,    13,    52,   358,
     132,    -1,    28,    29,    53,   358,   132,    -1,    28,    29,
      49,   358,   132,    -1,    28,    40,   356,   358,   132,    -1,
      28,    40,    44,   358,   132,    -1,    28,    40,    44,    45,
     358,   132,    -1,    28,    32,   357,   358,   132,    -1,    28,
      55,   358,   132,    -1,    -1,    -1,    28,   367,   351,   420,
     352,   358,   132,    -1,    -1,    -1,    28,     7,    75,   353,
     420,   354,   358,   132,    -1,    28,    70,   358,   132,    -1,
      28,    72,   157,   358,   132,    -1,    28,    72,    66,   358,
     132,    -1,    28,    79,    80,   358,   132,    -1,    28,    90,
     358,   132,    -1,    28,    72,    90,   358,   132,    -1,    83,
     132,    -1,    84,   132,    -1,    85,   132,    -1,    86,   132,
      -1,    28,    49,    29,   358,   132,    -1,    28,    51,   358,
     132,    -1,    -1,     1,   355,   132,    -1,    42,    -1,    43,
      -1,    46,    48,    -1,    46,    47,    -1,    41,    -1,    77,
      -1,    91,    -1,    92,    -1,    93,    -1,   166,    -1,    -1,
      38,    -1,    35,    -1,    39,    -1,    36,    -1,    64,    -1,
      65,    -1,    66,    -1,    12,    -1,    33,    -1,    34,    -1,
      30,    -1,    31,    -1,    36,    -1,    37,    -1,    76,    -1,
      75,    -1,    77,    -1,    78,    -1,    14,    -1,    15,    -1,
      27,    -1,   104,    -1,    17,    -1,    16,    -1,    81,    -1,
      -1,    82,    -1,    -1,    94,    -1,    -1,    73,    -1,    74,
      -1,    75,    -1,   406,    -1,    -1,   409,   369,   223,    -1,
      -1,   128,   371,   223,    -1,   223,    -1,    -1,   134,   373,
     375,    -1,   406,    -1,    -1,   410,   374,   223,    -1,    -1,
     172,   376,   378,    -1,    -1,   411,   377,   223,    -1,   404,
      -1,    -1,   135,   379,   368,    -1,    -1,   412,   380,   223,
      -1,   404,    -1,    -1,   134,   382,   384,    -1,   406,    -1,
      -1,   410,   383,   223,    -1,    -1,   172,   385,   388,    -1,
      -1,   136,   386,   398,    -1,    -1,   413,   387,   223,    -1,
     404,    -1,    -1,   135,   389,   368,    -1,    -1,   136,   390,
     392,    -1,    -1,   414,   391,   223,    -1,   404,    -1,    -1,
     172,   393,   395,    -1,    -1,   411,   394,   223,    -1,   404,
      -1,    -1,   135,   396,   368,    -1,    -1,   412,   397,   223,
      -1,   404,    -1,    -1,   172,   399,   401,    -1,    -1,   411,
     400,   223,    -1,   404,    -1,    -1,   135,   402,   368,    -1,
      -1,   412,   403,   223,    -1,   404,    -1,    -1,   130,   405,
     223,    -1,   223,    -1,    -1,   130,   407,   223,    -1,    -1,
     170,   408,   370,    -1,   173,    -1,   171,    -1,   172,    -1,
     134,    -1,   135,    -1,   128,    -1,   132,    -1,   136,    -1,
     171,    -1,   172,    -1,   135,    -1,   128,    -1,   132,    -1,
     136,    -1,   171,    -1,   134,    -1,   135,    -1,   170,    -1,
     128,    -1,   136,    -1,   171,    -1,   172,    -1,   134,    -1,
     170,    -1,   128,    -1,   136,    -1,   171,    -1,   134,    -1,
     135,    -1,   170,    -1,   128,    -1,   171,    -1,   172,    -1,
     134,    -1,   170,    -1,   128,    -1,   418,   416,    -1,   417,
      -1,   132,    -1,   417,    -1,   173,    -1,   418,   419,    -1,
     419,    -1,   420,    -1,   224,    -1,   171,    -1,   172,    -1,
     134,    -1,   135,    -1,   170,    -1,   128,    -1,   136,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   235,   235,   237,   242,   243,   244,   245,   251,   251,
     261,   261,   271,   275,   275,   286,   286,   297,   308,   308,
     313,   318,   351,   355,   359,   360,   361,   362,   370,   379,
     380,   390,   391,   394,   395,   396,   403,   412,   412,   421,
     424,   425,   432,   437,   431,   443,   444,   447,   448,   451,
     455,   459,   460,   459,   466,   466,   468,   474,   474,   476,
     479,   480,   483,   484,   484,   486,   486,   488,   488,   495,
     497,   505,   495,   518,   519,   522,   527,   530,   534,   535,
     535,   537,   540,   541,   551,   559,   550,   568,   567,   600,
     601,   610,   610,   617,   619,   617,   632,   633,   642,   643,
     646,   647,   650,   658,   659,   667,   676,   677,   680,   680,
     683,   684,   687,   694,   694,   697,   697,   700,   701,   700,
     704,   706,   708,   709,   708,   712,   713,   714,   712,   717,
     718,   717,   721,   722,   723,   721,   726,   727,   726,   730,
     731,   732,   730,   735,   736,   735,   739,   745,   744,   751,
     751,   754,   765,   766,   769,   770,   773,   778,   779,   782,
     783,   786,   787,   790,   791,   792,   799,   805,   808,   809,
     814,   821,   828,   829,   832,   833,   836,   837,   840,   845,
     845,   852,   853,   856,   857,   860,   861,   864,   868,   872,
     878,   882,   886,   886,   888,   892,   896,   897,   897,   899,
     899,   901,   901,   903,   903,   905,   909,   913,   918,   918,
     920,   924,   928,   932,   936,   936,   938,   939,   949,   950,
     953,   954,   957,   958,   961,   962,   963,   964,   970,   972,
     978,   980,   988,   989,   992,   993,   994,   994,  1001,  1013,
    1014,  1014,  1018,  1018,  1020,  1026,  1026,  1026,  1026,  1026,
    1029,  1029,  1029,  1030,  1030,  1030,  1033,  1033,  1033,  1033,
    1034,  1034,  1034,  1034,  1034,  1034,  1037,  1037,  1037,  1038,
    1038,  1038,  1038,  1039,  1039,  1039,  1039,  1039,  1042,  1042,
    1048,  1048,  1048,  1048,  1048,  1048,  1048,  1048,  1049,  1049,
    1052,  1052,  1052,  1052,  1055,  1055,  1058,  1058,  1058,  1058,
    1058,  1058,  1059,  1059,  1059,  1060,  1060,  1060,  1060,  1060,
    1060,  1060,  1060,  1063,  1063,  1063,  1063,  1063,  1063,  1063,
    1066,  1066,  1066,  1069,  1069,  1069,  1069,  1069,  1069,  1069,
    1070,  1070,  1070,  1070,  1070,  1070,  1071,  1071,  1071,  1071,
    1072,  1072,  1072,  1072,  1073,  1073,  1073,  1100,  1100,  1105,
    1105,  1112,  1111,  1124,  1123,  1136,  1135,  1148,  1147,  1160,
    1159,  1172,  1171,  1185,  1184,  1198,  1197,  1211,  1210,  1223,
    1222,  1236,  1235,  1248,  1247,  1260,  1259,  1273,  1272,  1284,
    1289,  1288,  1303,  1302,  1313,  1319,  1319,  1325,  1325,  1331,
    1331,  1337,  1337,  1343,  1351,  1351,  1357,  1357,  1363,  1363,
    1369,  1369,  1375,  1379,  1383,  1383,  1389,  1389,  1395,  1395,
    1401,  1401,  1407,  1407,  1413,  1413,  1419,  1419,  1425,  1425,
    1431,  1435,  1439,  1443,  1443,  1452,  1456,  1460,  1464,  1468,
    1472,  1476,  1480,  1484,  1488,  1492,  1496,  1500,  1504,  1505,
    1504,  1510,  1511,  1510,  1516,  1520,  1524,  1528,  1532,  1536,
    1543,  1547,  1551,  1555,  1562,  1566,  1573,  1573,  1580,  1581,
    1582,  1583,  1584,  1585,  1586,  1587,  1588,  1589,  1592,  1593,
    1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1605,
    1606,  1609,  1610,  1613,  1614,  1617,  1618,  1623,  1624,  1625,
    1626,  1629,  1630,  1633,  1634,  1637,  1638,  1641,  1642,  1645,
    1646,  1647,  1656,  1657,  1657,  1661,  1661,  1663,  1673,  1673,
    1675,  1676,  1676,  1681,  1681,  1683,  1683,  1685,  1689,  1689,
    1691,  1691,  1693,  1706,  1706,  1708,  1709,  1709,  1718,  1718,
    1720,  1720,  1722,  1722,  1724,  1732,  1732,  1734,  1734,  1736,
    1736,  1738,  1746,  1746,  1748,  1748,  1750,  1759,  1758,  1765,
    1765,  1767,  1775,  1775,  1777,  1777,  1779,  1787,  1787,  1789,
    1789,  1791,  1794,  1794,  1796,  1800,  1800,  1802,  1802,  1804,
    1815,  1815,  1815,  1815,  1815,  1815,  1815,  1818,  1818,  1818,
    1818,  1818,  1818,  1822,  1822,  1822,  1822,  1822,  1822,  1826,
    1826,  1826,  1826,  1826,  1826,  1830,  1830,  1830,  1830,  1830,
    1834,  1834,  1834,  1834,  1834,  1840,  1841,  1844,  1845,  1848,
    1855,  1856,  1859,  1864,  1871,  1871,  1871,  1871,  1871,  1871,
    1871
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
  "KW_LOAD", "KW_QUIT", "KW_EOF", "KW_TEST", "KW_SMT_SEARCH", "KW_ENDM",
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
  "$@96", "$@97", "$@98", "$@99", "printOption", "traceOption", "polarity",
  "select", "exclude", "conceal", "search", "match", "optDebug",
  "optIrredundant", "optNumber", "importMode", "moduleAndTerm", "$@100",
  "inEnd", "$@101", "numberModuleTerm", "$@102", "$@103",
  "numberModuleTerm1", "$@104", "$@105", "numberModuleTerm2", "$@106",
  "$@107", "numbersModuleTerm", "$@108", "$@109", "numbersModuleTerm1",
  "$@110", "$@111", "$@112", "numbersModuleTerm2", "$@113", "$@114",
  "$@115", "numbersModuleTerm3", "$@116", "$@117", "numbersModuleTerm4",
  "$@118", "$@119", "numbersModuleTerm5", "$@120", "$@121",
  "numbersModuleTerm6", "$@122", "$@123", "miscEndBubble", "$@124",
  "initialEndBubble", "$@125", "$@126", "cTokenBarIn", "cTokenBarLeftIn",
  "cTokenBarDotNumber", "cTokenBarDotRight", "cTokenBarDotCommaNumber",
  "cTokenBarDotCommaRight", "opSelect", "endSelect", "badSelect",
  "cOpNameList", "cSimpleOpName", "cSimpleTokenBarDot", 0
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
     375,   376,   377,   378,   379,   380,   381,   382,    58,    61,
      40,    41,    46,    60,    91,    93,    44,   124,   383,   384,
     385,    43,    42,   123,   125,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   175,   176,   176,   177,   177,   177,   177,   179,   178,
     180,   178,   178,   181,   178,   182,   178,   178,   183,   178,
     178,   178,   184,   184,   184,   184,   184,   184,   184,   185,
     185,   186,   186,   187,   187,   187,   188,   190,   189,   191,
     192,   192,   194,   195,   193,   196,   196,   197,   197,   198,
     198,   199,   200,   198,   202,   201,   201,   204,   203,   203,
     205,   205,   206,   207,   206,   208,   206,   209,   206,   211,
     212,   213,   210,   214,   214,   215,   215,   216,   216,   217,
     216,   216,   218,   218,   220,   221,   219,   222,   219,   223,
     223,   225,   224,   227,   228,   226,   229,   229,   230,   230,
     231,   231,   232,   233,   233,   234,   235,   235,   236,   236,
     237,   237,   238,   239,   238,   240,   238,   241,   242,   238,
     238,   238,   243,   244,   238,   245,   246,   247,   238,   248,
     249,   238,   250,   251,   252,   238,   253,   254,   238,   255,
     256,   257,   238,   258,   259,   238,   238,   260,   238,   261,
     238,   238,   262,   262,   263,   263,   264,   265,   265,   266,
     266,   267,   267,   268,   268,   268,   269,   269,   270,   270,
     270,   271,   272,   272,   273,   273,   274,   274,   275,   276,
     275,   277,   277,   278,   278,   279,   279,   280,   280,   280,
     281,   281,   282,   281,   281,   281,   281,   283,   281,   284,
     281,   285,   281,   286,   281,   281,   281,   281,   287,   281,
     281,   281,   281,   281,   288,   281,   281,   281,   289,   289,
     290,   290,   291,   291,   292,   292,   292,   292,   293,   293,
     294,   294,   295,   295,   296,   296,   297,   296,   298,   299,
     300,   299,   302,   301,   301,   303,   303,   303,   303,   303,
     304,   304,   304,   304,   304,   304,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   307,   307,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     309,   309,   309,   309,   310,   310,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   312,   312,   312,   312,   312,   312,   312,
     313,   313,   313,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   316,   315,   317,
     315,   318,   315,   319,   315,   320,   315,   321,   315,   322,
     315,   323,   315,   324,   315,   325,   315,   326,   315,   327,
     315,   328,   315,   329,   315,   330,   315,   331,   315,   315,
     332,   315,   333,   315,   315,   334,   315,   335,   315,   336,
     315,   337,   315,   315,   338,   315,   339,   315,   340,   315,
     341,   315,   315,   315,   342,   315,   343,   315,   344,   315,
     345,   315,   346,   315,   347,   315,   348,   315,   349,   315,
     315,   315,   315,   350,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   351,   352,
     315,   353,   354,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   355,   315,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   358,
     358,   359,   359,   360,   360,   361,   361,   362,   362,   362,
     362,   363,   363,   364,   364,   365,   365,   366,   366,   367,
     367,   367,   368,   369,   368,   371,   370,   370,   373,   372,
     372,   374,   372,   376,   375,   377,   375,   375,   379,   378,
     380,   378,   378,   382,   381,   381,   383,   381,   385,   384,
     386,   384,   387,   384,   384,   389,   388,   390,   388,   391,
     388,   388,   393,   392,   394,   392,   392,   396,   395,   397,
     395,   395,   399,   398,   400,   398,   398,   402,   401,   403,
     401,   401,   405,   404,   404,   407,   406,   408,   406,   406,
     409,   409,   409,   409,   409,   409,   409,   410,   410,   410,
     410,   410,   410,   411,   411,   411,   411,   411,   411,   412,
     412,   412,   412,   412,   412,   413,   413,   413,   413,   413,
     414,   414,   414,   414,   414,   415,   415,   416,   416,   417,
     418,   418,   419,   419,   420,   420,   420,   420,   420,   420,
     420
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
       0,     3,     0,     3,     1,     0,     4,     0,     4,     0,
       4,     0,     4,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     3,     3,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       4,     5,     4,     0,     4,     5,     5,     6,     5,     5,
       6,     5,     5,     5,     5,     6,     5,     4,     0,     0,
       7,     0,     0,     8,     4,     5,     5,     5,     4,     5,
       2,     2,     2,     2,     5,     4,     0,     3,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     0,     1,     0,     1,
       1,     1,     1,     0,     3,     0,     3,     1,     0,     3,
       1,     0,     3,     0,     3,     0,     3,     1,     0,     3,
       0,     3,     1,     0,     3,     1,     0,     3,     0,     3,
       0,     3,     0,     3,     1,     0,     3,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     1,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     1,     0,     3,     0,
       3,     1,     0,     3,     1,     0,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   456,   108,   109,    69,   351,   382,   487,   488,   492,
     491,   373,   367,   489,     0,     0,     0,   347,     0,     0,
       0,   493,     0,     0,     0,     0,   353,   355,   349,    12,
      13,    15,    17,    18,    10,    20,    21,   380,   490,    91,
       8,     0,     2,     6,     5,   384,     4,    93,     7,   369,
     371,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     468,     0,     0,     0,     0,     0,     0,   499,   500,   501,
       0,     0,   438,   394,   400,     0,     0,   396,     0,     0,
     398,   404,   406,   408,   410,   412,   414,   416,   418,   423,
     481,   482,   484,   483,   385,   387,     0,   485,   486,   391,
     389,     0,   450,   451,   452,   453,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
     357,   359,   496,     0,   361,   363,   365,   498,   457,   311,
     296,   312,   297,   298,   299,   300,   302,   301,   303,   304,
     305,   306,   307,   308,   309,   310,   289,   288,   315,   318,
     316,   319,   314,   317,   249,   313,   320,   321,   292,   285,
     287,   293,   286,   283,   284,   281,   282,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   339,   332,   333,   334,
     338,   335,   336,   337,   340,   341,   294,   342,   343,   344,
     345,   346,   280,   291,     0,   290,   245,   246,   295,   247,
     248,   322,   574,   565,   575,   572,   573,   576,   567,   570,
     571,   569,   352,   502,   503,   383,   580,   581,   508,   579,
     582,   577,   578,   374,   510,   511,   368,   441,     0,     0,
       0,     0,     0,     0,     0,   476,   477,   478,   470,   472,
     469,   471,   473,   474,   475,     0,   462,   458,   459,     0,
       0,   463,   464,   465,   466,   467,     0,     0,   479,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,   403,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,   348,     0,     0,     0,   354,   356,   350,    14,    16,
      19,    11,   381,    92,     9,    94,   523,   370,   525,   526,
     372,     0,     0,   495,     0,   375,     0,     0,     0,   497,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   461,
     460,     0,     0,   455,   437,   444,     0,     0,     0,     0,
     448,   619,   616,   617,   620,   618,   614,   615,   439,   395,
     401,   422,   420,     0,   397,   399,   405,   407,   409,   411,
     413,   415,   417,   419,   424,   609,   613,   386,   606,     0,
     611,   612,   388,   392,   390,   393,    99,     0,     0,   358,
     360,   377,     0,   362,   364,   366,   379,     0,    70,    29,
      31,    32,    34,    33,    35,   566,   505,   507,   568,   504,
     587,   562,   584,   585,   588,   586,   583,   513,   564,   509,
     517,   515,   512,   442,     0,     0,   432,   426,   428,   431,
     429,   425,   436,     0,   434,   433,   454,   446,   449,   445,
     447,     0,   421,   607,   605,   608,   610,     0,   229,   599,
     596,   597,   530,   598,   595,   528,   524,   534,   532,   527,
       0,   376,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,   427,   430,   435,     0,     0,   101,     0,   228,
     111,     0,     0,     0,   378,    39,    30,     0,    42,    36,
       0,   506,   563,   593,   591,   518,   594,   592,   589,   590,
     514,   522,   520,   516,     0,   440,     0,    98,   104,   103,
       0,     0,   552,   531,   556,   554,   604,   602,   535,   537,
     603,   600,   601,   529,   541,   539,   533,    71,     0,     0,
      41,     0,     0,   443,   100,   102,     0,    95,     0,   113,
     115,   117,     0,     0,     0,     0,   149,   122,   125,   129,
     132,   136,   139,   143,   110,     0,     0,     0,     0,     0,
     229,    46,     0,    51,     0,    43,    45,    48,     0,    38,
     519,   521,   151,   249,   251,   252,    28,   112,     0,   231,
     231,   231,   231,     0,   250,   253,   254,   255,   233,     0,
       0,   261,   264,   262,   265,   263,   259,   260,   162,     0,
     160,   161,   256,   257,   258,     0,     0,   158,   147,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   553,   561,
     559,   555,   536,   542,   538,   546,   544,   540,    74,   275,
     273,   274,   269,   270,   276,   277,   271,   272,   266,     0,
     238,   239,   267,   268,    56,     0,     0,     0,    40,     0,
     230,    25,    26,    24,    22,    23,     0,     0,   236,   118,
       0,   159,     0,    76,   157,     0,     0,   123,   126,   130,
     133,   137,   140,   144,     0,     0,     0,     0,     0,     0,
     240,    54,     0,     0,    44,    47,    27,    30,    96,    97,
     114,   232,   235,   116,   234,   233,     0,   174,   175,   179,
     105,   165,   120,   164,     0,   177,   178,   146,    75,     0,
     152,     0,   150,     0,     0,     0,     0,     0,     0,     0,
     558,   560,   547,   543,   551,   549,   545,     0,    72,     0,
      79,     0,    73,    49,     0,   177,    52,    50,     0,   119,
       0,   173,   171,   184,   167,   107,   121,   231,   251,   252,
     153,   154,     0,   250,   253,   254,   255,   148,   124,   127,
     131,   134,   138,   141,   145,     0,     0,    81,     0,     0,
       0,   244,     0,     0,    59,   237,     0,   182,     0,   231,
     166,   169,   170,     0,   163,   176,   106,     0,     0,     0,
       0,     0,   548,   550,     0,    84,    87,    80,    76,   242,
     241,     0,    57,    53,   180,     0,   190,   191,   187,   194,
     195,     0,     0,     0,     0,     0,     0,     0,   205,   207,
     206,     0,     0,   210,   211,   212,   217,     0,     0,   192,
     186,   172,   168,   155,   156,   128,   135,   142,    83,    77,
     231,   177,     0,     0,     0,    55,     0,   181,   188,   189,
     196,   197,   213,   201,   203,   208,   214,     0,   199,   183,
     185,   219,    82,     0,    88,    78,   243,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,     0,   218,   193,     0,    62,    63,    67,
      65,    58,    60,   221,     0,     0,     0,     0,     0,   224,
       0,     0,   216,   222,     0,     0,     0,     0,     0,   198,
     220,   202,   204,   209,   215,   225,   226,   227,   200,    85,
       0,     0,     0,     0,    64,    68,    66,    86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    41,    42,    43,   115,   112,   109,   110,   111,   577,
     398,   399,   400,   401,   402,   490,   403,   529,   489,   528,
     646,   565,   566,   567,   644,   774,   682,   735,   803,   846,
     871,   872,   906,   908,   907,    44,    53,   464,   560,   678,
     709,   732,   769,   839,   797,   841,   923,   842,   418,   376,
     114,    46,   117,   386,   690,   448,   476,   477,   510,   701,
     746,    47,   511,   554,   588,   589,   590,   696,   610,   713,
     611,   714,   789,   612,   715,   613,   716,   790,   614,   717,
     615,   718,   791,   616,   719,   665,   609,   711,   750,   751,
     606,   599,   600,   702,   783,   784,   703,   742,   704,   744,
     705,   740,   776,   779,   828,   829,   830,   861,   873,   883,
     874,   875,   876,   877,   885,   894,   881,   882,   480,   651,
     656,   657,   695,   706,   640,   734,   772,   844,   404,   582,
     601,   641,   583,   195,   196,   642,   198,   199,   200,   201,
      48,    96,   108,    54,   106,   107,   311,   312,   316,   317,
     318,    57,   118,   119,    56,   392,   460,   113,    55,   287,
     288,   293,   292,   269,   274,   277,   270,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   268,   441,   327,   471,
      52,   256,   245,   260,    94,    95,    99,    49,    50,    51,
     314,   320,    72,   212,   324,   408,   467,   223,   325,   326,
     419,   469,   470,   500,   531,   532,   307,   387,   388,   456,
     482,   481,   483,   523,   557,   558,   559,   624,   676,   677,
     723,   765,   766,   513,   555,   556,   618,   674,   675,   420,
     468,   213,   322,   323,   214,   225,   421,   502,   458,   525,
     377,   444,   378,   379,   380,   381
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -748
static const yytype_int16 yypact[] =
{
     691,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,   436,   471,    29,  -748,    82,   216,
       1,  -748,   -18,    12,    37,    39,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,    85,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,   572,    62,  1073,   -73,   -73,   262,   -73,    98,   227,
     389,    45,   190,   299,   299,   299,   -34,  -748,  -748,  -748,
     159,   299,  -748,  -748,  -748,   202,   -46,  -748,   125,   150,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,   -93,  -748,  -748,  -748,
    -748,   133,  -748,  -748,  -748,  -748,   -73,   -73,   -93,   289,
     292,   303,   310,   -73,   185,   321,  -748,  1073,   418,   262,
    -748,  -748,   257,   309,  -748,  -748,  -748,   238,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,   228,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,   296,   299,
     299,   299,   299,   299,   299,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,   299,  -748,  -748,  -748,    65,
     306,  -748,  -748,  -748,  -748,  -748,   299,   299,  -748,  -748,
     225,   242,   244,   299,   299,   299,   299,   246,   249,   -93,
     -93,   254,   255,   295,   -93,  -748,  -748,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,  2160,  2160,  -748,
    -748,  -748,  2160,  2160,   259,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,   -73,   262,  -748,   374,  -748,   418,   418,   262,  -748,
     273,   797,   -93,   -64,   -93,   437,   -93,   249,   299,   299,
     274,   276,   280,   294,   304,   316,   319,   299,   320,  -748,
    -748,   324,   325,  -748,  -748,  -748,   327,   328,   334,   335,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,   338,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,   495,
    -748,  -748,  -748,  -748,  -748,  -748,   266,   509,   -93,  -748,
    -748,  -748,   262,  -748,  -748,  -748,  -748,   797,   297,   329,
     298,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,   340,   341,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,   342,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,   299,  -748,  -748,  -748,  -748,  -748,  1073,   353,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
     262,  -748,   -89,   797,   343,   350,  -748,   -93,   -93,   598,
     -93,   299,  -748,  -748,  -748,   349,    80,  -748,   -82,  -748,
    -748,   629,   675,   -93,  -748,  -748,  -748,   797,  -748,  -748,
    1073,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,   351,  -748,  1073,  -748,  -748,  -748,
     797,   250,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,   297,    16,   112,
    -748,   -73,   -93,  -748,  -748,   297,   352,  -748,   866,  -748,
    -748,  -748,  1142,  1142,  1349,  1073,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,   684,   -93,   -73,  2142,   -93,
     353,  -748,  2100,  -748,  1073,  -748,   357,  -748,  1073,  -748,
    -748,  -748,  -748,   354,   146,   162,   118,  -748,   347,   -65,
     177,   180,   367,   368,   195,   200,   275,   288,  -748,  2100,
     361,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,   935,
    -748,  -748,  -748,  -748,  -748,  1004,  1211,  -748,  -748,  2100,
     373,   375,   376,   378,   387,   388,   386,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,   379,
     380,  -748,  -748,  -748,   391,   383,   393,    -7,  -748,   866,
    -748,  -748,  -748,  -748,  -748,  -748,  1625,  1556,  -748,  -748,
    1418,  -748,  1418,   416,  -748,   404,  1556,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,   -73,   -93,  2151,   -93,    22,  2100,
    -748,  -748,   405,  1073,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  1418,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  1694,  -748,  -748,  -748,  -748,  1694,
    1832,   385,  -748,   -93,   420,   -93,   422,   -93,   428,  1418,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,   413,  -748,  2100,
    -748,  1349,  -748,  -748,  2100,  -748,  -748,  -748,  1966,  -748,
    2100,  -748,  -748,   425,  1487,  -748,  -748,   367,  -748,  -748,
     424,  -748,   434,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,   -73,   -93,  -748,   417,   -49,
    1280,   380,   139,  1899,   429,  -748,   245,  -748,  2189,   367,
    -748,  -748,  -748,    23,  -748,  -748,  -748,  1832,  1073,   -93,
     -93,   -93,  -748,  -748,  1763,  -748,  -748,  -748,   416,  -748,
    -748,  2033,  -748,  -748,  -748,  2100,  -748,  -748,  -748,  -748,
    -748,   419,   421,   399,   444,   406,   445,   446,  -748,   448,
    -748,   449,   451,  -748,  -748,  -748,  -748,   455,   717,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
     367,  -748,   -93,  1694,  2100,  -748,    70,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,   277,  -748,  -748,
    -748,   390,  -748,  1899,  -748,  -748,   380,   415,   457,   463,
     470,    10,  -748,   431,   431,   431,   431,   599,  1073,  1073,
    1073,    -3,  -748,   431,  -748,  -748,  2033,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,   -87,   -20,   -13,   -10,   472,   476,
     476,   476,  -748,  -748,    -4,   473,   431,   606,   431,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
      41,   482,    49,   -93,  -748,  -748,  -748,  -748
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,   -35,
    -385,  -748,  -748,  -510,  -509,  -748,  -508,  -748,  -748,  -748,
    -748,  -748,  -748,   -32,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -255,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -181,  -748,  -748,  -748,  -748,  -748,  -748,  -748,   -95,     0,
    -748,  -748,  -748,  -748,  -511,  -748,  -748,   113,  -748,  -701,
    -219,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -161,
    -103,    89,  -558,  -626,  -748,  -748,  -150,  -748,  -747,  -708,
    -552,  -748,  -748,  -748,  -748,  -748,  -194,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -575,  -748,  -245,    78,  -566,
     -45,    33,  -748,  -412,  -710,  -748,  -748,  -748,   -43,  -679,
    -523,  -748,  -748,  -532,  -524,   -48,  -748,  -501,  -493,  -394,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,   -31,   627,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,   -53,  -748,  -748,  -748,  -108,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,    86,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -362,
    -748,   -47,  -748,  -748,  -748,  -111,  -443,  -533,  -748,  -748,
     -51,  -748,   268,  -748,   269,  -233
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -495
static const yytype_int16 yytable[] =
{
      45,   291,   215,   741,   226,   197,   584,   309,   745,   224,
     194,   310,   462,   297,   652,   653,   654,   561,   602,   602,
     602,   607,   620,   727,   771,   457,   801,   773,   579,   580,
     581,   752,   263,   261,   262,   358,   707,   586,   515,   289,
     267,   661,   485,   782,   909,   587,   508,   661,   272,   604,
     604,   604,   463,   295,   296,   202,   264,   203,   509,   204,
     302,   205,   206,   207,   406,    90,    91,   650,   289,   197,
     739,   308,   224,   101,   305,   602,   -32,   -32,   486,   795,
     290,   602,   602,   664,   910,   116,   246,   247,   248,   249,
     796,   250,   273,   764,   423,   258,   259,   208,   209,   210,
     211,   562,   527,   563,    92,    93,   604,   501,   752,   290,
     337,   911,   604,   604,   102,   626,   886,   584,   912,   514,
     524,   913,   251,   265,   562,   535,   563,   918,   902,   728,
     729,   564,   730,   863,   866,   731,   252,   253,   254,   579,
     580,   581,   745,   725,   103,   891,   693,   697,   586,   698,
     639,   910,   743,   578,   564,   712,   587,   747,   910,    97,
      98,   910,   867,   868,   878,   879,   880,   910,   643,   104,
     869,   105,   924,   227,   359,   360,   870,   658,   753,   364,
     926,   786,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   785,   619,   128,   643,   625,   658,   330,   331,
     332,   333,   334,   335,   390,   309,   309,   602,   607,   755,
     395,   255,   910,   831,   336,   643,   506,   756,   338,   257,
     910,   785,   867,   868,   507,   341,   342,   405,   407,   409,
     869,   422,   346,   347,   348,   349,   870,   382,   604,   266,
     228,   383,   384,   271,   691,   694,   602,   664,   568,   845,
    -279,   536,    90,    91,   694,   753,   569,   275,   389,  -291,
    -291,  -291,   643,   643,   687,   224,   643,   733,   643,   308,
     308,   224,   643,   197,   862,   799,   229,   604,   230,   231,
     232,   233,   276,   800,   461,   643,   755,  -292,  -292,  -292,
     294,   747,   298,   459,   756,   299,   234,   424,   425,   895,
     896,   897,   643,  -293,  -293,  -293,   433,   300,   904,   650,
     643,   785,   650,   301,   724,   643,   303,   768,   -34,   -34,
     -34,   -33,   -33,   -33,   304,   643,   691,   315,   777,   258,
     259,   920,   319,   922,   905,   643,  -290,  -290,  -290,   313,
     643,  -246,  -246,  -246,   643,   224,   643,   328,   329,   197,
     643,   321,   484,   339,   340,   537,   538,   343,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   491,   492,   344,   503,   345,   351,   350,   643,
     804,   805,   840,   352,   353,   354,   361,   362,   526,   363,
     216,   385,   203,   847,   217,   391,   218,   219,   220,   197,
     643,   235,   393,   394,   478,   396,   426,   643,   427,   447,
     475,   643,   428,   224,   553,   197,  -247,  -247,  -247,   355,
     356,   357,   236,   237,   238,   239,   429,   240,   241,  -248,
    -248,  -248,   208,   221,   222,   211,   430,   571,   463,   197,
     504,   466,   197,    58,   878,   879,   880,   530,   431,   643,
     643,   432,   434,   242,   243,   244,   435,   436,   197,   437,
     438,   621,   197,   478,   627,    59,   439,   440,    60,   643,
     442,   465,   472,   473,   474,   479,    61,    73,   570,    74,
     488,   505,   487,   533,   572,    62,  -278,    63,   649,   659,
     585,    64,   643,   647,   603,   603,   603,   197,    75,   650,
     655,   667,   608,   668,   622,   669,    65,   670,    66,    67,
      68,    69,   671,   672,   673,    70,   197,   757,   679,   681,
     197,   645,   683,   680,   684,   648,    71,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     708,   710,   598,   598,   736,   767,   216,   759,   203,   761,
     217,   603,   306,   219,   220,   763,   794,   603,   603,   778,
     787,    89,   788,   802,   884,   410,   848,   411,   849,   289,
     850,   412,   413,   414,   851,   853,   854,   852,   855,   856,
     721,   857,   726,   120,   121,   858,   887,   888,   208,   221,
     222,   211,   122,   889,   123,   124,   125,   126,   127,   598,
     890,   585,   893,   914,   898,   598,    39,   415,   416,   417,
     290,   921,   919,   925,   686,   685,   892,   843,   758,   534,
     760,   720,   762,   351,   865,    39,   833,   443,   770,   352,
     353,   354,   605,   832,   860,   197,   903,   449,   628,   411,
     737,   289,   666,   450,   451,   452,   100,   445,   446,     0,
     738,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   754,     0,     0,   355,   356,   357,   375,     0,
       0,   793,     0,     0,     0,     0,     0,     0,     0,   453,
     454,   455,   290,   603,     0,     0,     0,     0,     0,     0,
       0,    -3,     1,     0,   835,   836,   837,     2,     3,     4,
       5,     0,  -494,  -494,     6,     7,     8,     9,    10,    11,
      12,  -494,   792,  -494,  -494,  -494,  -494,  -494,    13,    14,
      15,     0,   603,    16,     0,     0,   493,    17,   411,     0,
     289,    18,   494,   495,   496,     0,     0,     0,     0,   754,
     197,     0,     0,     0,     0,   834,    19,   864,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   410,     0,   411,
       0,   289,    20,   412,   413,   414,     0,     0,   497,   498,
     499,   290,    21,     0,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,     0,     0,   415,
     416,   512,   290,   516,     0,   411,     0,   289,     0,   517,
     518,   519,   493,     0,   411,     0,   289,     0,   494,   617,
     496,    39,     0,     0,     0,     0,     0,     0,   927,     0,
     197,   197,   197,     0,     0,   899,   900,   901,     0,     0,
       0,     0,     0,     0,     0,   520,   521,   522,   290,     0,
       0,     0,   859,     0,   497,   498,   499,   290,     0,     0,
       0,    40,   806,   807,   808,   809,   810,   811,   812,   813,
     814,   815,   816,   817,   818,   819,   820,   821,   822,   823,
     824,   825,   826,   827,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   915,
     916,   917,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   397,     0,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,     0,
     193,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   397,     0,   573,   155,
     156,   157,   574,   159,   160,   575,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,     0,   576,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   591,
     592,   593,   594,   660,   595,    39,     0,   596,   597,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,     0,   193,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   591,   592,
     593,   594,   662,   595,    39,     0,   596,   597,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,     0,   193,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,     0,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,     0,   193,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   591,   592,   593,   594,
       0,   595,    39,     0,   596,   597,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,     0,   193,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   591,   592,   593,   594,   663,
     595,     0,     0,   596,   597,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,     0,   193,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   591,   592,   593,   594,   798,   595,
       0,     0,   596,   597,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,     0,   193,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   591,   592,   593,   594,     0,   595,     0,
       0,   596,   597,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,     0,   193,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     629,     0,   697,   630,   698,   631,     0,   632,     0,     0,
       0,     0,   699,     0,     0,   633,   634,   635,     0,   636,
     637,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   638,
       0,   700,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   629,
       0,     0,   630,     0,   631,   780,   632,     0,     0,   781,
       0,   699,     0,     0,   633,   634,   635,     0,   636,   637,
       0,     0,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   638,     0,
     700,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   629,     0,
       0,   630,     0,   631,     0,   632,     0,     0,   688,   692,
       0,     0,     0,   633,   634,   635,     0,   636,   637,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   638,     0,   689,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   629,     0,     0,
     630,     0,   631,     0,   632,     0,     0,   688,     0,     0,
       0,     0,   633,   634,   635,     0,   636,   637,     0,     0,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   638,     0,   689,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   629,     0,     0,   630,
       0,   631,     0,   632,     0,     0,     0,     0,   699,     0,
       0,   633,   634,   635,     0,   636,   637,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   638,     0,   700,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   629,     0,     0,   630,     0,
     631,     0,   632,     0,     0,     0,     0,     0,     0,     0,
     633,   634,   635,     0,   636,   637,     0,     0,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   638,     0,   838,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,     0,     0,   155,   156,   157,   748,   159,
     160,   749,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   629,     0,   697,   630,   698,   631,     0,   632,     0,
       0,     0,     0,   699,     0,     0,   633,   634,   635,     0,
     636,   637,     0,     0,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     638,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   629,     0,
       0,   630,     0,   631,     0,   632,     0,     0,     0,   775,
       0,     0,     0,   633,   634,   635,     0,   636,   637,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   638,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   629,     0,     0,   630,     0,
     631,     0,   632,     0,     0,     0,     0,   699,     0,     0,
     633,   634,   635,     0,   636,   637,     0,     0,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   638,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   629,     0,     0,   630,     0,   631,     0,   632,
       0,     0,     0,     0,     0,     0,     0,   633,   634,   635,
       0,   636,   637,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     410,   638,   411,     0,   289,     0,   412,   413,   414,   493,
       0,   411,     0,   289,     0,   494,   722,   496,   351,     0,
      39,     0,     0,     0,   352,   353,   354,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   415,   416,   623,   290,     0,     0,     0,     0,
       0,   497,   498,   499,   290,     0,     0,     0,     0,     0,
     355,   356,   357,   375,   806,   807,   808,   809,   810,   811,
     812,   813,   814,   815,   816,   817,   818,   819,   820,   821,
     822,   823,   824,   825,   826,   827
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-748))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    96,    55,   704,    57,    53,   538,   118,   709,    56,
      53,   119,   397,   108,   580,   581,   582,     1,   542,   543,
     544,   544,   555,     1,   734,   387,   773,   735,   538,   538,
     538,   710,    66,    64,    65,   268,   662,   538,   481,   132,
      71,   599,   131,   744,   131,   538,   128,   605,    94,   542,
     543,   544,   141,   106,   107,   128,    90,   130,   140,   132,
     113,   134,   135,   136,   128,    36,    37,   132,   132,   117,
     696,   118,   119,    72,   117,   599,   141,   142,   463,   128,
     173,   605,   606,   606,   171,     0,    41,    42,    43,    44,
     139,    46,   138,   719,   327,    30,    31,   170,   171,   172,
     173,   108,   487,   110,    75,    76,   599,   469,   787,   173,
      45,   131,   605,   606,   132,   558,   863,   649,   131,   481,
     482,   131,    77,   157,   108,   510,   110,   131,   131,   107,
     108,   138,   110,   841,   844,   113,    91,    92,    93,   649,
     649,   649,   843,   676,   132,   135,   657,   124,   649,   126,
     562,   171,   704,   538,   138,   666,   649,   709,   171,    77,
      78,   171,   152,   153,   167,   168,   169,   171,   562,   132,
     160,   132,   131,    75,   269,   270,   166,   589,   710,   274,
     131,   747,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   744,   555,   132,   589,   558,   609,   229,   230,
     231,   232,   233,   234,   312,   316,   317,   731,   731,   710,
     318,   166,   171,   779,   245,   609,   136,   710,   249,    29,
     171,   773,   152,   153,   144,   256,   257,   322,   323,   324,
     160,   326,   263,   264,   265,   266,   166,   288,   731,    80,
      13,   292,   293,    41,   656,   657,   770,   770,   136,   801,
     132,     1,    36,    37,   666,   787,   144,   132,   311,   141,
     142,   143,   656,   657,   649,   312,   660,   679,   662,   316,
     317,   318,   666,   321,   840,   136,    49,   770,    51,    52,
      53,    54,   132,   144,   392,   679,   787,   141,   142,   143,
     157,   843,     3,   388,   787,     3,    69,   328,   329,   874,
     875,   876,   696,   141,   142,   143,   337,     4,   883,   132,
     704,   863,   132,     3,   676,   709,   131,   729,   141,   142,
     143,   141,   142,   143,     3,   719,   738,    18,   740,    30,
      31,   906,    94,   908,   886,   729,   141,   142,   143,    82,
     734,   141,   142,   143,   738,   392,   740,    51,    52,   397,
     744,   123,   460,    47,    48,   105,   106,   132,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   467,   468,   132,   470,   132,   128,   132,   773,
     135,   136,   794,   134,   135,   136,   132,   132,   483,    94,
     128,   132,   130,   805,   132,    21,   134,   135,   136,   447,
     794,    12,   316,   317,   447,   132,   132,   801,   132,   143,
     441,   805,   132,   460,   164,   463,   141,   142,   143,   170,
     171,   172,    33,    34,    35,    36,   132,    38,    39,   141,
     142,   143,   170,   171,   172,   173,   132,   532,   141,   487,
     471,   143,   490,     7,   167,   168,   169,   490,   132,   843,
     844,   132,   132,    64,    65,    66,   132,   132,   506,   132,
     132,   556,   510,   506,   559,    29,   132,   132,    32,   863,
     132,   142,   132,   132,   132,   122,    40,     6,   531,     8,
     130,   132,   139,   132,   132,    49,   132,    51,   141,   128,
     538,    55,   886,   136,   542,   543,   544,   545,    27,   132,
     132,   128,   545,   128,   557,   129,    70,   129,    72,    73,
      74,    75,   125,   125,   128,    79,   564,   132,   139,   128,
     568,   564,   139,   143,   131,   568,    90,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     124,   137,   542,   543,   139,   132,   128,   127,   130,   127,
     132,   599,   134,   135,   136,   127,   139,   605,   606,   134,
     136,    90,   128,   134,   174,   128,   147,   130,   147,   132,
     171,   134,   135,   136,   130,   130,   130,   171,   130,   130,
     675,   130,   677,    11,    12,   130,   171,   130,   170,   171,
     172,   173,    20,   130,    22,    23,    24,    25,    26,   599,
     130,   649,   171,   131,     5,   605,   130,   170,   171,   172,
     173,     5,   139,   131,   649,   647,   871,   798,   713,   506,
     715,   674,   717,   128,   843,   130,   787,   132,   731,   134,
     135,   136,   543,   783,   828,   683,   881,   128,   560,   130,
     683,   132,   609,   134,   135,   136,    19,   379,   379,    -1,
     695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   710,    -1,    -1,   170,   171,   172,   173,    -1,
      -1,   766,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
     171,   172,   173,   731,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,   789,   790,   791,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   765,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,   770,    32,    -1,    -1,   128,    36,   130,    -1,
     132,    40,   134,   135,   136,    -1,    -1,    -1,    -1,   787,
     788,    -1,    -1,    -1,    -1,   788,    55,   842,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,   130,
      -1,   132,    71,   134,   135,   136,    -1,    -1,   170,   171,
     172,   173,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,   170,
     171,   172,   173,   128,    -1,   130,    -1,   132,    -1,   134,
     135,   136,   128,    -1,   130,    -1,   132,    -1,   134,   135,
     136,   130,    -1,    -1,    -1,    -1,    -1,    -1,   923,    -1,
     878,   879,   880,    -1,    -1,   878,   879,   880,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   170,   171,   172,   173,    -1,
      -1,    -1,   135,    -1,   170,   171,   172,   173,    -1,    -1,
      -1,   170,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   899,
     900,   901,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,   171,    -1,
     173,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,   171,    -1,   173,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,   171,    -1,   173,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,   171,    -1,   173,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,    -1,   173,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,   129,   130,    -1,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,   171,    -1,   173,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,   171,    -1,   173,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,    -1,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,   171,    -1,   173,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,   129,    -1,
      -1,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,    -1,   173,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,
      -1,    -1,   134,    -1,    -1,   137,   138,   139,    -1,   141,
     142,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,   171,
      -1,   173,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,   125,    -1,   127,   128,   129,    -1,    -1,   132,
      -1,   134,    -1,    -1,   137,   138,   139,    -1,   141,   142,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,   171,    -1,
     173,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,   125,    -1,   127,    -1,   129,    -1,    -1,   132,   133,
      -1,    -1,    -1,   137,   138,   139,    -1,   141,   142,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,   171,    -1,   173,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
     125,    -1,   127,    -1,   129,    -1,    -1,   132,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,   142,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,   171,    -1,   173,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,   125,
      -1,   127,    -1,   129,    -1,    -1,    -1,    -1,   134,    -1,
      -1,   137,   138,   139,    -1,   141,   142,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,   171,    -1,   173,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,   125,    -1,
     127,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,   141,   142,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,    -1,   173,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,   171,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,    -1,   134,    -1,    -1,   137,   138,   139,    -1,
     141,   142,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,   125,    -1,   127,    -1,   129,    -1,    -1,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,    -1,   141,   142,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,   171,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,   125,    -1,
     127,    -1,   129,    -1,    -1,    -1,    -1,   134,    -1,    -1,
     137,   138,   139,    -1,   141,   142,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,   125,    -1,   127,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
      -1,   141,   142,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     128,   171,   130,    -1,   132,    -1,   134,   135,   136,   128,
      -1,   130,    -1,   132,    -1,   134,   135,   136,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
     170,   171,   172,   173,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    14,    15,    16,
      17,    18,    19,    27,    28,    29,    32,    36,    40,    55,
      71,    81,    83,    84,    85,    86,    87,    88,    89,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   130,
     170,   176,   177,   178,   210,   224,   226,   236,   315,   362,
     363,   364,   355,   211,   318,   333,   329,   326,     7,    29,
      32,    40,    49,    51,    55,    70,    72,    73,    74,    75,
      79,    90,   367,     6,     8,    27,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    90,
      36,    37,    75,    76,   359,   360,   316,    77,    78,   361,
     359,    72,   132,   132,   132,   132,   319,   320,   317,   181,
     182,   183,   180,   332,   225,   179,     0,   227,   327,   328,
      11,    12,    20,    22,    23,    24,    25,    26,   132,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   171,   173,   303,   308,   309,   310,   311,   312,
     313,   314,   128,   130,   132,   134,   135,   136,   170,   171,
     172,   173,   368,   406,   409,   368,   128,   132,   134,   135,
     136,   171,   172,   372,   406,   410,   368,    75,    13,    49,
      51,    52,    53,    54,    69,    12,    33,    34,    35,    36,
      38,    39,    64,    65,    66,   357,    41,    42,    43,    44,
      46,    77,    91,    92,    93,   166,   356,    29,    30,    31,
     358,   358,   358,    66,    90,   157,    80,   358,   351,   338,
     341,    41,    94,   138,   339,   132,   132,   340,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   334,   335,   132,
     173,   223,   337,   336,   157,   368,   368,   223,     3,     3,
       4,     3,   368,   131,     3,   303,   134,   381,   406,   410,
     372,   321,   322,    82,   365,    18,   323,   324,   325,    94,
     366,   123,   407,   408,   369,   373,   374,   353,    51,    52,
     358,   358,   358,   358,   358,   358,   358,    45,   358,    47,
      48,   358,   358,   132,   132,   132,   358,   358,   358,   358,
     132,   128,   134,   135,   136,   170,   171,   172,   420,   223,
     223,   132,   132,    94,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   173,   224,   415,   417,   418,
     419,   420,   415,   415,   415,   132,   228,   382,   383,   368,
     372,    21,   330,   381,   381,   372,   132,   130,   185,   186,
     187,   188,   189,   191,   303,   223,   128,   223,   370,   223,
     128,   130,   134,   135,   136,   170,   171,   172,   223,   375,
     404,   411,   223,   420,   358,   358,   132,   132,   132,   132,
     132,   132,   132,   358,   132,   132,   132,   132,   132,   132,
     132,   352,   132,   132,   416,   417,   419,   143,   230,   128,
     134,   135,   136,   170,   171,   172,   384,   404,   413,   223,
     331,   372,   185,   141,   212,   142,   143,   371,   405,   376,
     377,   354,   132,   132,   132,   358,   231,   232,   303,   122,
     293,   386,   385,   387,   372,   131,   185,   139,   130,   193,
     190,   223,   223,   128,   134,   135,   136,   170,   171,   172,
     378,   404,   412,   223,   358,   132,   136,   144,   128,   140,
     233,   237,   172,   398,   404,   411,   128,   134,   135,   136,
     170,   171,   172,   388,   404,   414,   223,   185,   194,   192,
     303,   379,   380,   132,   232,   185,     1,   105,   106,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   164,   238,   399,   400,   389,   390,   391,
     213,     1,   108,   110,   138,   196,   197,   198,   136,   144,
     368,   223,   132,   132,   136,   139,   173,   184,   185,   188,
     189,   191,   304,   307,   308,   310,   312,   313,   239,   240,
     241,   124,   125,   126,   127,   129,   132,   133,   224,   266,
     267,   305,   309,   310,   313,   266,   265,   305,   303,   261,
     243,   245,   248,   250,   253,   255,   258,   135,   401,   404,
     412,   223,   368,   172,   392,   404,   411,   223,   293,   122,
     125,   127,   129,   137,   138,   139,   141,   142,   171,   298,
     299,   306,   310,   314,   199,   303,   195,   136,   303,   141,
     132,   294,   294,   294,   294,   132,   295,   296,   298,   128,
     128,   267,   128,   128,   305,   260,   296,   128,   128,   129,
     129,   125,   125,   128,   402,   403,   393,   394,   214,   139,
     143,   128,   201,   139,   131,   198,   184,   185,   132,   173,
     229,   298,   133,   229,   298,   297,   242,   124,   126,   134,
     173,   234,   268,   271,   273,   275,   298,   268,   124,   215,
     137,   262,   229,   244,   246,   249,   251,   254,   256,   259,
     368,   223,   135,   395,   404,   412,   223,     1,   107,   108,
     110,   113,   216,   298,   300,   202,   139,   303,   295,   268,
     276,   234,   272,   275,   274,   234,   235,   275,   136,   139,
     263,   264,   304,   308,   310,   312,   313,   132,   223,   127,
     223,   127,   223,   127,   268,   396,   397,   132,   298,   217,
     265,   299,   301,   274,   200,   133,   277,   298,   134,   278,
     128,   132,   234,   269,   270,   275,   294,   136,   128,   247,
     252,   257,   368,   223,   139,   128,   139,   219,   128,   136,
     144,   273,   134,   203,   135,   136,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   279,   280,
     281,   294,   271,   264,   303,   223,   223,   223,   173,   218,
     298,   220,   222,   215,   302,   275,   204,   298,   147,   147,
     171,   130,   171,   130,   130,   130,   130,   130,   130,   135,
     281,   282,   294,   274,   223,   235,   299,   152,   153,   160,
     166,   205,   206,   283,   285,   286,   287,   288,   167,   168,
     169,   291,   292,   284,   174,   289,   273,   171,   130,   130,
     130,   135,   206,   171,   290,   290,   290,   290,     5,   303,
     303,   303,   131,   292,   290,   275,   207,   209,   208,   131,
     171,   131,   131,   131,   131,   224,   224,   224,   131,   139,
     290,     5,   290,   221,   131,   131,   131,   223
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
      yyerror (parseResult, YY_("syntax error: cannot back up")); \
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
		  Type, Value, parseResult); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, UserLevelRewritingContext::ParseResult* parseResult)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, parseResult)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    UserLevelRewritingContext::ParseResult* parseResult;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (parseResult);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, UserLevelRewritingContext::ParseResult* parseResult)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, parseResult)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    UserLevelRewritingContext::ParseResult* parseResult;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parseResult);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, UserLevelRewritingContext::ParseResult* parseResult)
#else
static void
yy_reduce_print (yyvsp, yyrule, parseResult)
    YYSTYPE *yyvsp;
    int yyrule;
    UserLevelRewritingContext::ParseResult* parseResult;
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
		       		       , parseResult);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, parseResult); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, UserLevelRewritingContext::ParseResult* parseResult)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, parseResult)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    UserLevelRewritingContext::ParseResult* parseResult;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (parseResult);

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
int yyparse (UserLevelRewritingContext::ParseResult* parseResult);
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
yyparse (UserLevelRewritingContext::ParseResult* parseResult)
#else
int
yyparse (parseResult)
    UserLevelRewritingContext::ParseResult* parseResult;
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
#line 235 "surface.yy"
    { YYACCEPT; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 237 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 251 "surface.yy"
    { lexerFileNameMode(); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 253 "surface.yy"
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
#line 261 "surface.yy"
    { lexerFileNameMode(); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 263 "surface.yy"
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
#line 272 "surface.yy"
    {
			  cout << directoryManager.getCwd() << '\n';
			}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 275 "surface.yy"
    { lexerFileNameMode(); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 277 "surface.yy"
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
#line 286 "surface.yy"
    { lexerFileNameMode(); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 288 "surface.yy"
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
#line 298 "surface.yy"
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
#line 308 "surface.yy"
    { lexerStringMode(); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 310 "surface.yy"
    {
			  system((string("ls") + (yyvsp[(3) - (3)].yyString)).c_str());
			}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 314 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 319 "surface.yy"
    {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 352 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (2)].yyToken)));
                        }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 356 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (2)].yyToken)));
                        }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 363 "surface.yy"
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
#line 371 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  moduleExpressions.push(new ModuleExpression(t));
			}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 381 "surface.yy"
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
#line 397 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (1)].yyToken)));
                        }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 404 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 412 "surface.yy"
    { clear(); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 414 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, tokenSequence));
			}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 421 "surface.yy"
    {}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 424 "surface.yy"
    { store((yyvsp[(3) - (3)].yyToken)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 425 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 432 "surface.yy"
    {
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 437 "surface.yy"
    {
			  currentSyntaxContainer = oldSyntaxContainer;
			}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 452 "surface.yy"
    {
			  currentRenaming->addSortMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 456 "surface.yy"
    {
			  currentRenaming->addLabelMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 459 "surface.yy"
    { lexBubble(BAR_COLON | BAR_TO, 1); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 460 "surface.yy"
    { lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 461 "surface.yy"
    {}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 466 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 467 "surface.yy"
    {}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 468 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 474 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 475 "surface.yy"
    {}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 476 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 483 "surface.yy"
    { currentRenaming->setPrec((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 484 "surface.yy"
    { clear(); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 485 "surface.yy"
    { currentRenaming->setGather(tokenSequence); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 486 "surface.yy"
    { clear(); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 487 "surface.yy"
    { currentRenaming->setFormat(tokenSequence); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 488 "surface.yy"
    { lexerLatexMode(); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 489 "surface.yy"
    { currentRenaming->setLatexMacro((yyvsp[(4) - (5)].yyString)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 495 "surface.yy"
    { lexerIdMode(); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 497 "surface.yy"
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
#line 505 "surface.yy"
    {
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 510 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  interpreter.insertView(((yyvsp[(3) - (12)].yyToken)).code(), CV);
			  CV->finishView();
			}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 523 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
				       ": skipping " << QUOTE("->") << " in variable declaration.");
			}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 531 "surface.yy"
    {
			  CV->addSortMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 534 "surface.yy"
    {}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 535 "surface.yy"
    { lexBubble(BAR_COLON | BAR_TO, 1); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 540 "surface.yy"
    { (yyval.yyToken) = (yyvsp[(1) - (2)].yyToken); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 542 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  (yyval.yyToken) = t;
			}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 551 "surface.yy"
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
#line 559 "surface.yy"
    {
			  lexBubble(END_STATEMENT, 1);
			}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 563 "surface.yy"
    {
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 568 "surface.yy"
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
#line 578 "surface.yy"
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
#line 600 "surface.yy"
    {}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 602 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  lexerBubble.append(t);
			}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 610 "surface.yy"
    { lexBubble(BAR_RIGHT_PAREN, 1); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 611 "surface.yy"
    {}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 617 "surface.yy"
    { lexerIdMode(); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 619 "surface.yy"
    {
			  interpreter.setCurrentModule(new SyntacticPreModule((yyvsp[(1) - (3)].yyToken), (yyvsp[(3) - (3)].yyToken)));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule((yyvsp[(1) - (3)].yyToken), (yyvsp[(3) - (3)].yyToken));
			}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 625 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule((yyvsp[(8) - (8)].yyToken));
			}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 632 "surface.yy"
    {}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 634 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  store(t);
			}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 642 "surface.yy"
    {}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 651 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter((yyvsp[(1) - (3)].yyToken), me);
			}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 658 "surface.yy"
    {}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 660 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			    ": saw " << QUOTE(':') << " instead of " <<
			    QUOTE("::") << " in parameter declaration.");
			}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 668 "surface.yy"
    {
			  singleton[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(singleton[0]);
			  currentSyntaxContainer->addType(false, singleton);
			  (yyval.yyToken) = (yyvsp[(1) - (1)].yyToken);  // needed for line number
			}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 677 "surface.yy"
    {}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 688 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport((yyvsp[(1) - (2)].yyToken), me);
			}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 694 "surface.yy"
    { clear(); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 695 "surface.yy"
    { CM->addSortDecl(tokenSequence); }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 697 "surface.yy"
    { clear(); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 698 "surface.yy"
    { CM->addSubsortDecl(tokenSequence); }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 700 "surface.yy"
    { lexBubble(BAR_COLON, 1); }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 701 "surface.yy"
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 702 "surface.yy"
    {}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 704 "surface.yy"
    {}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 706 "surface.yy"
    {}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 708 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON, 1); }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 709 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 710 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 712 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON, 1);  }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 713 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 714 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 715 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 717 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_EQUALS, 1); }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 718 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 719 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 721 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_EQUALS, 1); }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 722 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 723 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 724 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 726 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_ARROW2, 1); }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 727 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 728 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 730 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_ARROW2, 1); }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 731 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 732 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 733 "surface.yy"
    { CM->addStatement(lexerBubble); }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 735 "surface.yy"
    { lexBubble(BAR_COLON, 1); }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 736 "surface.yy"
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 737 "surface.yy"
    { CM->setFlag(SymbolType::MESSAGE); }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 740 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 745 "surface.yy"
    {
			}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 748 "surface.yy"
    {
			}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 751 "surface.yy"
    { clear(); }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 752 "surface.yy"
    { CM->addSubsortDecl(tokenSequence); }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 755 "surface.yy"
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
#line 765 "surface.yy"
    {}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 766 "surface.yy"
    {}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 774 "surface.yy"
    {
			}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 778 "surface.yy"
    { currentSyntaxContainer->addVarDecl((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 779 "surface.yy"
    { currentSyntaxContainer->addVarDecl((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 786 "surface.yy"
    { singleton[0] = (yyvsp[(1) - (1)].yyToken); CM->addOpDecl(singleton); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 787 "surface.yy"
    { CM->addOpDecl(lexerBubble); }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 793 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) <<
				       ": missing " << QUOTE("->") << " in constant declaration.");
			}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 800 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
				       ": skipping stray " << QUOTE(":") << " in operator declaration.");

			}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 810 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 815 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 822 "surface.yy"
    {
			  if ((yyvsp[(1) - (2)].yyBool))
			    CM->convertSortsToKinds();
			}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 829 "surface.yy"
    {}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 832 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 833 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 841 "surface.yy"
    {
			  singleton[0] = (yyvsp[(1) - (1)].yyToken);
			  currentSyntaxContainer->addType(false, singleton);
			}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 845 "surface.yy"
    { clear(); }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 847 "surface.yy"
    {
			  currentSyntaxContainer->addType(true, tokenSequence);
			}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 852 "surface.yy"
    { store((yyvsp[(3) - (3)].yyToken)); }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 853 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 856 "surface.yy"
    {}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 865 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 869 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 873 "surface.yy"
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 879 "surface.yy"
    {
			  CM->setFlag(SymbolType::ASSOC);
			}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 883 "surface.yy"
    {
			  CM->setFlag(SymbolType::COMM);
			}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 886 "surface.yy"
    { lexBubble(BAR_RIGHT_BRACKET | BAR_OP_ATTRIBUTE, 1); }
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 887 "surface.yy"
    { CM->setIdentity(lexerBubble); }
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 889 "surface.yy"
    {
			  CM->setFlag(SymbolType::IDEM);
			}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 893 "surface.yy"
    {
			  CM->setFlag(SymbolType::ITER);
			}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 896 "surface.yy"
    { CM->setPrec((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 897 "surface.yy"
    { clear(); }
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 898 "surface.yy"
    { CM->setGather(tokenSequence); }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 899 "surface.yy"
    { clear(); }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 900 "surface.yy"
    { CM->setFormat(tokenSequence); }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 901 "surface.yy"
    { clear(); }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 902 "surface.yy"
    { CM->setStrat(tokenSequence); }
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 903 "surface.yy"
    { clear(); }
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 904 "surface.yy"
    { CM->setPoly(tokenSequence); }
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 906 "surface.yy"
    {
			  CM->setFlag(SymbolType::MEMO);
			}
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 910 "surface.yy"
    {
			  CM->setFlag(SymbolType::CTOR);
			}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 914 "surface.yy"
    {
			  clear();
			  CM->setFrozen(tokenSequence);
			}
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 918 "surface.yy"
    { clear(); }
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 919 "surface.yy"
    { CM->setFrozen(tokenSequence); }
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 921 "surface.yy"
    {
			  CM->setFlag(SymbolType::CONFIG);
			}
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 925 "surface.yy"
    {
			  CM->setFlag(SymbolType::OBJECT);
			}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 929 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 933 "surface.yy"
    {
			  CM->setMetadata((yyvsp[(2) - (2)].yyToken));
			}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 936 "surface.yy"
    { lexerLatexMode(); }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 937 "surface.yy"
    { CM->setLatexMacro((yyvsp[(4) - (5)].yyString)); }
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 938 "surface.yy"
    {}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 940 "surface.yy"
    {
			  CM->setFlag(SymbolType::DITTO);
			}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 953 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 954 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 961 "surface.yy"
    { clear(); CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[(2) - (2)].yyToken), tokenSequence); }
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 962 "surface.yy"
    { CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); }
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 963 "surface.yy"
    { CM->addHook(SyntacticPreModule::OP_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 964 "surface.yy"
    { CM->addHook(SyntacticPreModule::TERM_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 970 "surface.yy"
    {}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 972 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing " <<
				       QUOTE("is") << " keyword.");
			}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 978 "surface.yy"
    {}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 980 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			}
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 988 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 992 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 993 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 994 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 995 "surface.yy"
    { store((yyvsp[(4) - (4)].yyToken)); }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 1002 "surface.yy"
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
#line 1013 "surface.yy"
    { fragStore((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 1014 "surface.yy"
    { fragStore((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 1015 "surface.yy"
    { fragStore((yyvsp[(5) - (5)].yyToken)); }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 1018 "surface.yy"
    { fragStore((yyvsp[(2) - (2)].yyToken)); }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 1019 "surface.yy"
    {}
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 1020 "surface.yy"
    {}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 1100 "surface.yy"
    { lexBubble(END_COMMAND, 1); }
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 1102 "surface.yy"
    {
			  interpreter.setCurrentModule(lexerBubble);
			}
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 1105 "surface.yy"
    { lexBubble(END_COMMAND, 1); }
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 1107 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->dump();
			}
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 1112 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 1117 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(lexerBubble);
			}
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 1124 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 1129 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(lexerBubble);
			}
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 1136 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 1141 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sreduce(lexerBubble);
			}
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 1148 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 1153 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(lexerBubble, (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 1160 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 1166 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(lexerBubble, number, (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 1172 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 1179 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(lexerBubble, number, number2, (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 1185 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 1192 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(lexerBubble, number, number2, (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 1198 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 1204 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 1211 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 1216 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.check(lexerBubble);
			}
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 1223 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 1230 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, (yyvsp[(1) - (3)].yySearchKind));
			}
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 1236 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 1242 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(lexerBubble, (yyvsp[(1) - (3)].yyBool), number);
			}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 1248 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 1254 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.unify(lexerBubble, number);
			}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 1260 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 1266 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantUnify(lexerBubble, number, (yyvsp[(1) - (5)].yyBool));
			}
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 1273 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 1279 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.getVariants(lexerBubble, number, (yyvsp[(3) - (6)].yyBool), (yyvsp[(1) - (6)].yyBool));
			}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 1285 "surface.yy"
    {
			  interpreter.cont((yyvsp[(3) - (4)].yyInt64), (yyvsp[(1) - (4)].yyBool));
			}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 1289 "surface.yy"
    {
			  //
			  //	test is a generic command to call code with a term for development purposes.
			  //
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 1297 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.test(lexerBubble);
			}
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 1303 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 1308 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(lexerBubble);
			}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 1314 "surface.yy"
    {
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(lexerBubble);
			}
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 1319 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 1321 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect((yyvsp[(2) - (4)].yyBool));
			}
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 1325 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 1327 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude((yyvsp[(2) - (4)].yyBool));
			}
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 1331 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 1333 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect((yyvsp[(2) - (4)].yyBool));
			}
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 1337 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 1339 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal((yyvsp[(2) - (4)].yyBool));
			}
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 1344 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			}
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 1351 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 1353 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			}
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 1357 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 1359 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			}
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 1363 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 1365 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(true);
			}
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 1369 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 1371 "surface.yy"
    {
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showView();
			}
    break;

  case 402:

/* Line 1806 of yacc.c  */
#line 1376 "surface.yy"
    {
			  interpreter.showModules(true);
			}
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 1380 "surface.yy"
    {
			  interpreter.showNamedViews();
			}
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 1383 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 1385 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSortsAndSubsorts();
			}
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 1389 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 1391 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showOps();
			}
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 1395 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 409:

/* Line 1806 of yacc.c  */
#line 1397 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showVars();
			}
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 1401 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 1403 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showMbs();
			}
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 1407 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 1409 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showEqs();
			}
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 1413 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 1415 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showRls();
			}
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 1419 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 1421 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSummary();
			}
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 1425 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 1427 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showKinds();
			}
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 1432 "surface.yy"
    {
			  interpreter.showSearchPath((yyvsp[(3) - (4)].yyInt64));
			}
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 1436 "surface.yy"
    {
			  interpreter.showSearchPathLabels((yyvsp[(4) - (5)].yyInt64));
			}
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 1440 "surface.yy"
    {
			  interpreter.showSearchGraph();
			}
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 1443 "surface.yy"
    { lexBubble(END_COMMAND, 0); }
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 1445 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showProfile();
			}
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 1453 "surface.yy"
    {
			  globalAdvisoryFlag = alwaysAdviseFlag ? true : (yyvsp[(4) - (5)].yyBool);
			}
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 1457 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 1461 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, (yyvsp[(5) - (6)].yyBool));
			}
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 1465 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 1469 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 1473 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, (yyvsp[(5) - (6)].yyBool));
			}
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 1477 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 1481 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 1485 "surface.yy"
    {
			  interpreter.setPrintFlag((yyvsp[(3) - (5)].yyPrintFlags), (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 1489 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 1493 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE_NEWLINE, (yyvsp[(5) - (6)].yyBool));
			}
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 1497 "surface.yy"
    {
			  interpreter.setFlag((yyvsp[(3) - (5)].yyFlags), (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 1501 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, (yyvsp[(3) - (4)].yyBool));
			}
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 1504 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 1505 "surface.yy"
    { lexerInitialMode(); }
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 1507 "surface.yy"
    {
			  interpreter.setAutoImport((yyvsp[(2) - (7)].yyImportMode), (yyvsp[(4) - (7)].yyToken), (yyvsp[(6) - (7)].yyBool));
			}
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 1510 "surface.yy"
    { lexerCmdMode(); }
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 1511 "surface.yy"
    { lexerInitialMode(); }
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 1513 "surface.yy"
    {
			  interpreter.setOmodInclude((yyvsp[(5) - (8)].yyToken), (yyvsp[(7) - (8)].yyBool));
			}
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 1517 "surface.yy"
    {
			  globalVerboseFlag = (yyvsp[(3) - (4)].yyBool);
			}
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 1521 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 1525 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 447:

/* Line 1806 of yacc.c  */
#line 1529 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 1533 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, (yyvsp[(3) - (4)].yyBool));
			}
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 1537 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, (yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 450:

/* Line 1806 of yacc.c  */
#line 1544 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			}
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 1548 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			}
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 1552 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			}
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 1556 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			}
    break;

  case 454:

/* Line 1806 of yacc.c  */
#line 1563 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[(4) - (5)].yyBool));
			}
    break;

  case 455:

/* Line 1806 of yacc.c  */
#line 1567 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[(3) - (4)].yyBool));
			}
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 1573 "surface.yy"
    { lexerInitialMode(); }
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 1580 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_MIXFIX; }
    break;

  case 459:

/* Line 1806 of yacc.c  */
#line 1581 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FLAT; }
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 1582 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_ALIASES; }
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 1583 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_PARENS; }
    break;

  case 462:

/* Line 1806 of yacc.c  */
#line 1584 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_GRAPH; }
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 1585 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_CONCEAL; }
    break;

  case 464:

/* Line 1806 of yacc.c  */
#line 1586 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_NUMBER; }
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 1587 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_RAT; }
    break;

  case 466:

/* Line 1806 of yacc.c  */
#line 1588 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_COLOR; }
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 1589 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FORMAT; }
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 1592 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE; }
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 1593 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_CONDITION; }
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 1594 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_WHOLE; }
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 1595 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SUBSTITUTION; }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 1596 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SELECT; }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 1597 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_MB; }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 1598 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_EQ; }
    break;

  case 475:

/* Line 1806 of yacc.c  */
#line 1599 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_RL; }
    break;

  case 476:

/* Line 1806 of yacc.c  */
#line 1600 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_REWRITE; }
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 1601 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BODY; }
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 1602 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BUILTIN; }
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 1605 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 1606 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 481:

/* Line 1806 of yacc.c  */
#line 1609 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 1610 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 1613 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 1614 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 1617 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 1618 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 1623 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::NARROW; }
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 1624 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::XG_NARROW; }
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 1625 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::SEARCH; }
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 1626 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::SMT_SEARCH; }
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 1629 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 1630 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 1633 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 1634 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 1637 "surface.yy"
    { (yyval.yyBool) = true; }
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 1638 "surface.yy"
    { (yyval.yyBool) = false; }
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 1641 "surface.yy"
    { (yyval.yyInt64) = (yyvsp[(1) - (1)].yyInt64); }
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 1642 "surface.yy"
    { (yyval.yyInt64) = NONE; }
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 1645 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::PROTECTING; }
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 1646 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::EXTENDING; }
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 1647 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::INCLUDING; }
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 1657 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 1661 "surface.yy"
    { moduleExpr = lexerBubble; lexBubble(END_COMMAND, 1); }
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 1673 "surface.yy"
    { lexSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 1676 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0);  }
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 1681 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 1683 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 1689 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); }
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 1691 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 1706 "surface.yy"
    { lexSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 1709 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 1718 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 1720 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 1722 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 1732 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); }
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 1734 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 1736 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 1746 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 1748 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 1759 "surface.yy"
    {
			  number = Token::codeToInt64(lexerBubble[1].code());
			  number2 = Token::codeToInt64(lexerBubble[3].code());
			  clear();
			}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 1765 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 1775 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); }
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 1777 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 1787 "surface.yy"
    { number2 = Token::codeToInt64(lexerBubble[2].code()); }
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 1789 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); }
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 1794 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0, 1); }
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 1800 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 1, 1); }
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 1802 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON | END_COMMAND, 0); }
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 1805 "surface.yy"
    {
			  lexerBubble.resize(1);
			  lexerBubble[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(lexerBubble[0]);
			}
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 1844 "surface.yy"
    {}
    break;

  case 609:

/* Line 1806 of yacc.c  */
#line 1849 "surface.yy"
    {
			  singleton[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(singleton[0]);
			  interpreter.addSelected(singleton);
			}
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 1860 "surface.yy"
    {
			  singleton[0] = (yyvsp[(1) - (1)].yyToken);
			  interpreter.addSelected(singleton);
			}
    break;

  case 613:

/* Line 1806 of yacc.c  */
#line 1865 "surface.yy"
    {
			  interpreter.addSelected(lexerBubble);
			}
    break;



/* Line 1806 of yacc.c  */
#line 6079 "surface.c"
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
      yyerror (parseResult, YY_("syntax error"));
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
        yyerror (parseResult, yymsgp);
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
		      yytoken, &yylval, parseResult);
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
		  yystos[yystate], yyvsp, parseResult);
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
  yyerror (parseResult, YY_("memory exhausted"));
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
                  yytoken, &yylval, parseResult);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, parseResult);
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
#line 1895 "surface.yy"


static void
yyerror(UserLevelRewritingContext::ParseResult* /*parseResult*/, char *s)
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

