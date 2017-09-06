
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
     KW_EREWRITE = 274,
     KW_FREWRITE = 275,
     KW_SREWRITE = 276,
     KW_CONTINUE = 277,
     KW_SEARCH = 278,
     KW_SET = 279,
     KW_SHOW = 280,
     KW_ON = 281,
     KW_OFF = 282,
     KW_TRACE = 283,
     KW_BODY = 284,
     KW_BUILTIN = 285,
     KW_WHOLE = 286,
     KW_SELECT = 287,
     KW_DESELECT = 288,
     KW_CONDITION = 289,
     KW_SUBSTITUTION = 290,
     KW_PRINT = 291,
     KW_GRAPH = 292,
     KW_MIXFIX = 293,
     KW_FLAT = 294,
     KW_ATTRIBUTE = 295,
     KW_NEWLINE = 296,
     KW_WITH = 297,
     KW_PARENS = 298,
     KW_ALIASES = 299,
     KW_GC = 300,
     KW_TIME = 301,
     KW_STATS = 302,
     KW_TIMING = 303,
     KW_CMD = 304,
     KW_BREAKDOWN = 305,
     KW_BREAK = 306,
     KW_PATH = 307,
     KW_MODULE = 308,
     KW_MODULES = 309,
     KW_VIEWS = 310,
     KW_ALL = 311,
     KW_SORTS = 312,
     KW_OPS2 = 313,
     KW_VARS = 314,
     KW_MBS = 315,
     KW_EQS = 316,
     KW_RLS = 317,
     KW_SUMMARY = 318,
     KW_KINDS = 319,
     KW_ADVISE = 320,
     KW_VERBOSE = 321,
     KW_DO = 322,
     KW_CLEAR = 323,
     KW_PROTECT = 324,
     KW_EXTEND = 325,
     KW_INCLUDE = 326,
     KW_EXCLUDE = 327,
     KW_CONCEAL = 328,
     KW_REVEAL = 329,
     KW_COMPILE = 330,
     KW_COUNT = 331,
     KW_DEBUG = 332,
     KW_RESUME = 333,
     KW_ABORT = 334,
     KW_STEP = 335,
     KW_WHERE = 336,
     KW_CREDUCE = 337,
     KW_SREDUCE = 338,
     KW_DUMP = 339,
     KW_PROFILE = 340,
     KW_NUMBER = 341,
     KW_RAT = 342,
     KW_COLOR = 343,
     SIMPLE_NUMBER = 344,
     KW_PWD = 345,
     KW_CD = 346,
     KW_PUSHD = 347,
     KW_POPD = 348,
     KW_LS = 349,
     KW_LOAD = 350,
     KW_QUIT = 351,
     KW_EOF = 352,
     KW_ENDM = 353,
     KW_IMPORT = 354,
     KW_ENDV = 355,
     KW_SORT = 356,
     KW_SUBSORT = 357,
     KW_OP = 358,
     KW_OPS = 359,
     KW_MSGS = 360,
     KW_VAR = 361,
     KW_CLASS = 362,
     KW_SUBCLASS = 363,
     KW_MB = 364,
     KW_CMB = 365,
     KW_EQ = 366,
     KW_CEQ = 367,
     KW_RL = 368,
     KW_CRL = 369,
     KW_IS = 370,
     KW_FROM = 371,
     KW_ARROW = 372,
     KW_ARROW2 = 373,
     KW_PARTIAL = 374,
     KW_IF = 375,
     KW_LABEL = 376,
     KW_TO = 377,
     KW_COLON2 = 378,
     KW_ASSOC = 379,
     KW_COMM = 380,
     KW_ID = 381,
     KW_IDEM = 382,
     KW_ITER = 383,
     KW_LEFT = 384,
     KW_RIGHT = 385,
     KW_PREC = 386,
     KW_GATHER = 387,
     KW_METADATA = 388,
     KW_STRAT = 389,
     KW_POLY = 390,
     KW_MEMO = 391,
     KW_FROZEN = 392,
     KW_CTOR = 393,
     KW_LATEX = 394,
     KW_SPECIAL = 395,
     KW_CONFIG = 396,
     KW_OBJ = 397,
     KW_MSG = 398,
     KW_DITTO = 399,
     KW_FORMAT = 400,
     KW_ID_HOOK = 401,
     KW_OP_HOOK = 402,
     KW_TERM_HOOK = 403,
     KW_IN = 404,
     IDENTIFIER = 405,
     NUMERIC_ID = 406,
     ENDS_IN_DOT = 407,
     FORCE_LOOKAHEAD = 408
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
#line 350 "surface.c"
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
#line 367 "surface.c"

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
#define YYLAST   2302

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  168
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  239
/* YYNRULES -- Number of rules.  */
#define YYNRULES  605
/* YYNRULES -- Number of states.  */
#define YYNSTATES  906

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   408

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     123,   124,   135,   134,   129,     2,   125,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   121,     2,
     126,   122,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   127,     2,   128,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   136,   130,   137,     2,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   131,   132,   133,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167
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
     187,   188,   189,   202,   205,   206,   211,   216,   217,   221,
     224,   227,   229,   230,   231,   240,   241,   245,   247,   249,
     250,   254,   255,   256,   265,   267,   269,   273,   274,   278,
     280,   284,   286,   288,   290,   293,   295,   297,   299,   302,
     303,   306,   307,   312,   313,   318,   319,   320,   326,   331,
     336,   337,   338,   344,   345,   346,   347,   355,   356,   357,
     363,   364,   365,   366,   374,   375,   376,   382,   383,   384,
     385,   393,   394,   395,   401,   406,   407,   413,   414,   419,
     422,   424,   427,   429,   433,   437,   440,   442,   445,   447,
     449,   451,   455,   457,   459,   461,   463,   465,   468,   472,
     474,   476,   478,   481,   482,   484,   485,   490,   494,   496,
     500,   501,   504,   506,   508,   511,   514,   516,   518,   519,
     523,   525,   527,   530,   531,   537,   538,   544,   545,   551,
     552,   558,   560,   562,   564,   565,   571,   573,   575,   577,
     580,   581,   587,   592,   594,   596,   597,   600,   602,   605,
     607,   610,   614,   618,   622,   624,   625,   627,   628,   631,
     632,   635,   638,   639,   644,   646,   648,   649,   655,   656,
     661,   663,   665,   667,   669,   671,   673,   675,   677,   679,
     681,   683,   685,   687,   689,   691,   693,   695,   697,   699,
     701,   703,   705,   707,   709,   711,   713,   715,   717,   719,
     721,   723,   725,   727,   729,   731,   733,   735,   737,   739,
     741,   743,   745,   747,   749,   751,   753,   755,   757,   759,
     761,   763,   765,   767,   769,   771,   773,   775,   777,   779,
     781,   783,   785,   787,   789,   791,   793,   795,   797,   799,
     801,   803,   805,   807,   809,   811,   813,   815,   817,   819,
     821,   823,   825,   827,   829,   831,   833,   835,   837,   839,
     841,   843,   845,   847,   849,   851,   853,   855,   857,   859,
     861,   863,   865,   867,   868,   872,   873,   877,   878,   882,
     883,   887,   888,   892,   893,   898,   899,   904,   905,   910,
     911,   916,   917,   922,   923,   927,   928,   932,   933,   937,
     942,   943,   947,   949,   950,   955,   956,   961,   962,   967,
     968,   973,   978,   979,   984,   985,   990,   991,   996,   997,
    1002,  1006,  1010,  1011,  1016,  1017,  1022,  1023,  1028,  1029,
    1034,  1035,  1040,  1041,  1046,  1047,  1052,  1053,  1058,  1063,
    1069,  1074,  1075,  1080,  1086,  1092,  1099,  1105,  1111,  1118,
    1124,  1130,  1136,  1142,  1149,  1155,  1160,  1161,  1162,  1170,
    1171,  1172,  1181,  1186,  1192,  1198,  1204,  1209,  1215,  1218,
    1221,  1224,  1227,  1233,  1238,  1239,  1243,  1245,  1247,  1250,
    1253,  1255,  1257,  1259,  1261,  1263,  1265,  1266,  1268,  1270,
    1272,  1274,  1276,  1278,  1280,  1282,  1284,  1286,  1288,  1290,
    1292,  1294,  1296,  1298,  1300,  1302,  1304,  1306,  1308,  1310,
    1312,  1314,  1315,  1317,  1318,  1320,  1322,  1324,  1326,  1327,
    1331,  1332,  1336,  1338,  1339,  1343,  1345,  1346,  1350,  1351,
    1355,  1356,  1360,  1362,  1363,  1367,  1368,  1372,  1374,  1375,
    1379,  1381,  1382,  1386,  1387,  1391,  1392,  1396,  1397,  1401,
    1403,  1404,  1408,  1409,  1413,  1414,  1418,  1420,  1421,  1425,
    1426,  1430,  1432,  1433,  1437,  1438,  1442,  1444,  1445,  1449,
    1450,  1454,  1456,  1457,  1461,  1462,  1466,  1468,  1469,  1473,
    1475,  1476,  1480,  1481,  1485,  1487,  1489,  1491,  1493,  1495,
    1497,  1499,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,
    1517,  1519,  1521,  1523,  1525,  1527,  1529,  1531,  1533,  1535,
    1537,  1539,  1541,  1543,  1545,  1547,  1549,  1551,  1553,  1555,
    1557,  1560,  1562,  1564,  1566,  1568,  1571,  1573,  1575,  1577,
    1579,  1581,  1583,  1585,  1587,  1589
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     169,     0,    -1,   170,    -1,    -1,   218,    -1,   203,    -1,
     171,    -1,   306,    -1,    -1,   163,   172,     3,    -1,    -1,
      95,   173,     3,    -1,    90,    -1,    -1,    91,   174,     3,
      -1,    -1,    92,   175,     3,    -1,    93,    -1,    -1,    94,
     176,     4,    -1,    96,    -1,    97,    -1,   295,   285,    -1,
     298,   125,    -1,   184,   285,    -1,   181,   285,    -1,   182,
     285,    -1,   178,   134,   177,    -1,   166,    -1,   179,    -1,
     178,   134,   178,    -1,   180,    -1,   181,    -1,   184,    -1,
     182,    -1,   294,    -1,   179,   135,   186,    -1,    -1,   180,
     136,   183,   185,   137,    -1,   123,   178,   124,    -1,   185,
     129,   294,    -1,   294,    -1,    -1,    -1,   123,   187,   189,
     188,   124,    -1,   190,    -1,     1,    -1,   190,   129,   191,
      -1,   191,    -1,   101,   289,   132,   289,    -1,   131,   294,
     132,   294,    -1,    -1,    -1,   103,   192,   194,   132,   193,
     196,    -1,    -1,   121,   195,   265,   264,   266,    -1,    -1,
      -1,   127,   197,   198,   128,    -1,    -1,   198,   199,    -1,
     199,    -1,   145,   164,    -1,    -1,   146,   123,   200,   281,
     124,    -1,    -1,   159,   123,   201,   281,   124,    -1,    -1,
     153,   123,   202,     5,   124,    -1,    -1,    -1,    -1,     8,
     204,   294,   116,   178,   205,   132,   178,   206,   284,   207,
     100,    -1,   207,   208,    -1,    -1,   101,   289,   132,   210,
      -1,   106,   257,   121,   227,    -1,    -1,   103,   209,   211,
      -1,     1,   125,    -1,   289,   285,    -1,   166,    -1,    -1,
      -1,   121,   212,   265,   264,   266,   132,   213,   215,    -1,
      -1,   132,   214,   215,    -1,   125,    -1,   166,    -1,    -1,
     123,   217,   124,    -1,    -1,    -1,   228,   219,   294,   220,
     222,   284,   229,    98,    -1,   125,    -1,   166,    -1,   136,
     223,   137,    -1,    -1,   223,   129,   224,    -1,   224,    -1,
     294,   225,   178,    -1,   133,    -1,   121,    -1,   166,    -1,
     266,   285,    -1,   226,    -1,     6,    -1,     7,    -1,   229,
     230,    -1,    -1,    99,   177,    -1,    -1,   101,   231,   286,
     221,    -1,    -1,   102,   232,   287,   221,    -1,    -1,    -1,
     103,   233,   121,   234,   260,    -1,   104,   258,   121,   260,
      -1,   106,   257,   121,   227,    -1,    -1,    -1,   109,   235,
     121,   236,   215,    -1,    -1,    -1,    -1,   110,   237,   121,
     238,   120,   239,   215,    -1,    -1,    -1,   111,   240,   122,
     241,   215,    -1,    -1,    -1,    -1,   112,   242,   122,   243,
     120,   244,   215,    -1,    -1,    -1,   113,   245,   118,   246,
     215,    -1,    -1,    -1,    -1,   114,   247,   118,   248,   120,
     249,   215,    -1,    -1,    -1,   157,   250,   121,   251,   260,
      -1,   105,   258,   121,   260,    -1,    -1,   107,   294,   252,
     254,   125,    -1,    -1,   108,   253,   287,   221,    -1,     1,
     125,    -1,   130,    -1,   130,   255,    -1,   256,    -1,   255,
     129,   256,    -1,   295,   121,   294,    -1,   257,   296,    -1,
     296,    -1,   258,   259,    -1,   259,    -1,   296,    -1,   216,
      -1,   266,   265,   261,    -1,   262,    -1,   226,    -1,   262,
      -1,   125,    -1,   226,    -1,   264,   263,    -1,   266,   269,
     285,    -1,   226,    -1,   117,    -1,   119,    -1,   265,   266,
      -1,    -1,   289,    -1,    -1,   127,   267,   268,   128,    -1,
     268,   129,   289,    -1,   289,    -1,   127,   270,   128,    -1,
      -1,   270,   272,    -1,   272,    -1,   140,    -1,   143,   140,
      -1,   144,   140,    -1,   138,    -1,   139,    -1,    -1,   271,
     273,   280,    -1,   141,    -1,   142,    -1,   145,   164,    -1,
      -1,   146,   123,   274,   281,   124,    -1,    -1,   159,   123,
     275,   281,   124,    -1,    -1,   148,   123,   276,   281,   124,
      -1,    -1,   149,   123,   277,   281,   124,    -1,   150,    -1,
     152,    -1,   151,    -1,    -1,   151,   123,   278,   281,   124,
      -1,   155,    -1,   156,    -1,   157,    -1,   147,   164,    -1,
      -1,   153,   123,   279,     5,   124,    -1,   154,   123,   282,
     124,    -1,   158,    -1,   167,    -1,    -1,   281,   164,    -1,
     164,    -1,   282,   283,    -1,   283,    -1,   160,   294,    -1,
     160,   294,   216,    -1,   161,   294,   216,    -1,   162,   294,
     216,    -1,   115,    -1,    -1,   125,    -1,    -1,   286,   289,
      -1,    -1,   287,   289,    -1,   287,   126,    -1,    -1,   289,
     288,   286,   126,    -1,   290,    -1,   297,    -1,    -1,   290,
     136,   291,   292,   137,    -1,    -1,   292,   129,   293,   290,
      -1,   290,    -1,   300,    -1,   301,    -1,   303,    -1,   304,
      -1,   125,    -1,   299,    -1,   129,    -1,   132,    -1,   301,
      -1,   303,    -1,   304,    -1,   300,    -1,   301,    -1,   304,
      -1,   125,    -1,   126,    -1,   117,    -1,   119,    -1,   122,
      -1,   118,    -1,   120,    -1,   164,    -1,   301,    -1,   305,
      -1,   122,    -1,   130,    -1,   134,    -1,   135,    -1,   118,
      -1,   120,    -1,   115,    -1,   131,    -1,   132,    -1,   125,
      -1,   166,    -1,   164,    -1,   136,    -1,   137,    -1,   134,
      -1,   135,    -1,   130,    -1,   133,    -1,   131,    -1,   116,
      -1,   115,    -1,   299,    -1,   166,    -1,   129,    -1,   132,
      -1,   157,    -1,   302,    -1,    99,    -1,   101,    -1,   102,
      -1,   103,    -1,   104,    -1,   106,    -1,   105,    -1,   107,
      -1,   108,    -1,   109,    -1,   110,    -1,   111,    -1,   112,
      -1,   113,    -1,   114,    -1,    98,    -1,   100,    -1,   126,
      -1,   121,    -1,   117,    -1,   119,    -1,   122,    -1,   118,
      -1,   120,    -1,   127,    -1,   128,    -1,   305,    -1,   138,
      -1,   139,    -1,   140,    -1,   141,    -1,   142,    -1,   143,
      -1,   144,    -1,   145,    -1,   146,    -1,   148,    -1,   149,
      -1,   150,    -1,   152,    -1,   153,    -1,   154,    -1,   151,
      -1,   147,    -1,   155,    -1,   156,    -1,   158,    -1,   159,
      -1,   160,    -1,   161,    -1,   162,    -1,    -1,    32,   307,
     215,    -1,    -1,    84,   308,   215,    -1,    -1,     9,   309,
     354,    -1,    -1,    82,   310,   354,    -1,    -1,    83,   311,
     354,    -1,    -1,   351,    11,   312,   354,    -1,    -1,   351,
      12,   313,   358,    -1,    -1,   351,    19,   314,   367,    -1,
      -1,   351,    20,   315,   367,    -1,    -1,   351,    21,   316,
     358,    -1,    -1,   349,   317,   367,    -1,    -1,   350,   318,
     358,    -1,    -1,    18,   319,   358,    -1,   351,    22,   352,
     125,    -1,    -1,    13,   320,   354,    -1,   216,    -1,    -1,
      28,   346,   321,   401,    -1,    -1,    28,   347,   322,   401,
      -1,    -1,    51,   346,   323,   401,    -1,    -1,    36,   348,
     324,   401,    -1,    67,    68,   150,   125,    -1,    -1,    25,
       6,   325,   215,    -1,    -1,    25,    53,   326,   215,    -1,
      -1,    25,    56,   327,   215,    -1,    -1,    25,     8,   328,
     215,    -1,    25,    54,   125,    -1,    25,    55,   125,    -1,
      -1,    25,    57,   329,   215,    -1,    -1,    25,    58,   330,
     215,    -1,    -1,    25,    59,   331,   215,    -1,    -1,    25,
      60,   332,   215,    -1,    -1,    25,    61,   333,   215,    -1,
      -1,    25,    62,   334,   215,    -1,    -1,    25,    63,   335,
     215,    -1,    -1,    25,    64,   336,   215,    -1,    25,    52,
      89,   125,    -1,    25,    52,   131,    89,   125,    -1,    25,
      23,    37,   125,    -1,    -1,    25,    85,   337,   215,    -1,
      24,    25,    65,   345,   125,    -1,    24,    25,    47,   345,
     125,    -1,    24,    25,    13,    47,   345,   125,    -1,    24,
      25,    48,   345,   125,    -1,    24,    25,    50,   345,   125,
      -1,    24,    25,    13,    48,   345,   125,    -1,    24,    25,
      49,   345,   125,    -1,    24,    25,    45,   345,   125,    -1,
      24,    36,   343,   345,   125,    -1,    24,    36,    40,   345,
     125,    -1,    24,    36,    40,    41,   345,   125,    -1,    24,
      28,   344,   345,   125,    -1,    24,    51,   345,   125,    -1,
      -1,    -1,    24,   353,   338,   406,   339,   345,   125,    -1,
      -1,    -1,    24,     7,    71,   340,   406,   341,   345,   125,
      -1,    24,    66,   345,   125,    -1,    24,    68,   150,   345,
     125,    -1,    24,    68,    62,   345,   125,    -1,    24,    75,
      76,   345,   125,    -1,    24,    85,   345,   125,    -1,    24,
      68,    85,   345,   125,    -1,    78,   125,    -1,    79,   125,
      -1,    80,   125,    -1,    81,   125,    -1,    24,    45,    25,
     345,   125,    -1,    24,    47,   345,   125,    -1,    -1,     1,
     342,   125,    -1,    38,    -1,    39,    -1,    42,    44,    -1,
      42,    43,    -1,    37,    -1,    73,    -1,    86,    -1,    87,
      -1,    88,    -1,   159,    -1,    -1,    34,    -1,    31,    -1,
      35,    -1,    32,    -1,    60,    -1,    61,    -1,    62,    -1,
      12,    -1,    29,    -1,    30,    -1,    26,    -1,    27,    -1,
      32,    -1,    33,    -1,    72,    -1,    71,    -1,    73,    -1,
      74,    -1,    14,    -1,    15,    -1,    23,    -1,    17,    -1,
      16,    -1,    77,    -1,    -1,    89,    -1,    -1,    69,    -1,
      70,    -1,    71,    -1,   392,    -1,    -1,   395,   355,   215,
      -1,    -1,   121,   357,   215,    -1,   215,    -1,    -1,   127,
     359,   361,    -1,   392,    -1,    -1,   396,   360,   215,    -1,
      -1,   165,   362,   364,    -1,    -1,   397,   363,   215,    -1,
     390,    -1,    -1,   128,   365,   354,    -1,    -1,   398,   366,
     215,    -1,   390,    -1,    -1,   127,   368,   370,    -1,   392,
      -1,    -1,   396,   369,   215,    -1,    -1,   165,   371,   374,
      -1,    -1,   129,   372,   384,    -1,    -1,   399,   373,   215,
      -1,   390,    -1,    -1,   128,   375,   354,    -1,    -1,   129,
     376,   378,    -1,    -1,   400,   377,   215,    -1,   390,    -1,
      -1,   165,   379,   381,    -1,    -1,   397,   380,   215,    -1,
     390,    -1,    -1,   128,   382,   354,    -1,    -1,   398,   383,
     215,    -1,   390,    -1,    -1,   165,   385,   387,    -1,    -1,
     397,   386,   215,    -1,   390,    -1,    -1,   128,   388,   354,
      -1,    -1,   398,   389,   215,    -1,   390,    -1,    -1,   123,
     391,   215,    -1,   215,    -1,    -1,   123,   393,   215,    -1,
      -1,   163,   394,   356,    -1,   166,    -1,   164,    -1,   165,
      -1,   127,    -1,   128,    -1,   121,    -1,   125,    -1,   129,
      -1,   164,    -1,   165,    -1,   128,    -1,   121,    -1,   125,
      -1,   129,    -1,   164,    -1,   127,    -1,   128,    -1,   163,
      -1,   121,    -1,   129,    -1,   164,    -1,   165,    -1,   127,
      -1,   163,    -1,   121,    -1,   129,    -1,   164,    -1,   127,
      -1,   128,    -1,   163,    -1,   121,    -1,   164,    -1,   165,
      -1,   127,    -1,   163,    -1,   121,    -1,   404,   402,    -1,
     403,    -1,   125,    -1,   403,    -1,   166,    -1,   404,   405,
      -1,   405,    -1,   406,    -1,   216,    -1,   164,    -1,   165,
      -1,   127,    -1,   128,    -1,   163,    -1,   121,    -1,   129,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   232,   232,   234,   239,   240,   241,   242,   248,   248,
     258,   258,   268,   272,   272,   283,   283,   294,   305,   305,
     310,   315,   348,   352,   356,   357,   358,   359,   367,   376,
     377,   387,   388,   391,   392,   393,   400,   409,   409,   418,
     421,   422,   429,   434,   428,   440,   441,   444,   445,   448,
     452,   456,   457,   456,   463,   463,   465,   471,   471,   473,
     476,   477,   480,   481,   481,   483,   483,   485,   485,   492,
     494,   502,   492,   515,   516,   519,   523,   524,   524,   526,
     529,   530,   540,   548,   539,   557,   556,   589,   590,   599,
     599,   606,   608,   606,   621,   622,   631,   632,   635,   636,
     639,   647,   648,   656,   665,   666,   669,   669,   672,   673,
     676,   683,   683,   686,   686,   689,   690,   689,   693,   695,
     697,   698,   697,   701,   702,   703,   701,   706,   707,   706,
     710,   711,   712,   710,   715,   716,   715,   719,   720,   721,
     719,   724,   725,   724,   728,   734,   733,   740,   740,   743,
     754,   755,   758,   759,   762,   767,   768,   771,   772,   775,
     776,   779,   780,   781,   788,   789,   794,   801,   808,   809,
     812,   813,   816,   817,   820,   825,   825,   832,   833,   836,
     837,   840,   841,   844,   848,   852,   858,   862,   866,   866,
     868,   872,   876,   877,   877,   879,   879,   881,   881,   883,
     883,   885,   889,   893,   898,   898,   900,   904,   908,   912,
     916,   916,   918,   919,   929,   930,   933,   934,   937,   938,
     941,   942,   943,   944,   950,   952,   958,   960,   968,   969,
     972,   973,   974,   974,   981,   993,   994,   994,   998,   998,
    1000,  1006,  1006,  1006,  1006,  1006,  1009,  1009,  1009,  1010,
    1010,  1010,  1013,  1013,  1013,  1013,  1014,  1014,  1014,  1014,
    1014,  1014,  1017,  1017,  1017,  1018,  1018,  1018,  1018,  1019,
    1019,  1019,  1019,  1019,  1022,  1022,  1028,  1028,  1028,  1028,
    1028,  1028,  1028,  1028,  1029,  1029,  1032,  1032,  1032,  1032,
    1035,  1035,  1038,  1038,  1038,  1038,  1038,  1038,  1039,  1039,
    1039,  1040,  1040,  1040,  1040,  1040,  1040,  1040,  1040,  1043,
    1043,  1043,  1043,  1043,  1043,  1043,  1046,  1046,  1046,  1049,
    1049,  1049,  1049,  1049,  1049,  1049,  1050,  1050,  1050,  1050,
    1050,  1050,  1051,  1051,  1051,  1051,  1052,  1052,  1052,  1052,
    1053,  1053,  1053,  1080,  1080,  1085,  1085,  1092,  1091,  1104,
    1103,  1116,  1115,  1128,  1127,  1140,  1139,  1152,  1151,  1165,
    1164,  1178,  1177,  1190,  1189,  1203,  1202,  1215,  1214,  1226,
    1231,  1230,  1241,  1247,  1247,  1253,  1253,  1259,  1259,  1265,
    1265,  1271,  1279,  1279,  1285,  1285,  1291,  1291,  1297,  1297,
    1303,  1307,  1311,  1311,  1317,  1317,  1323,  1323,  1329,  1329,
    1335,  1335,  1341,  1341,  1347,  1347,  1353,  1353,  1359,  1363,
    1367,  1371,  1371,  1380,  1384,  1388,  1392,  1396,  1400,  1404,
    1408,  1412,  1416,  1420,  1424,  1428,  1432,  1433,  1432,  1438,
    1439,  1438,  1444,  1448,  1452,  1456,  1460,  1464,  1471,  1475,
    1479,  1483,  1490,  1494,  1501,  1501,  1508,  1509,  1510,  1511,
    1512,  1513,  1514,  1515,  1516,  1517,  1520,  1521,  1522,  1523,
    1524,  1525,  1526,  1527,  1528,  1529,  1530,  1533,  1534,  1537,
    1538,  1541,  1542,  1545,  1546,  1551,  1552,  1553,  1556,  1557,
    1560,  1561,  1564,  1565,  1568,  1569,  1570,  1579,  1580,  1580,
    1584,  1584,  1586,  1596,  1596,  1598,  1599,  1599,  1604,  1604,
    1606,  1606,  1608,  1612,  1612,  1614,  1614,  1616,  1629,  1629,
    1631,  1632,  1632,  1641,  1641,  1643,  1643,  1645,  1645,  1647,
    1655,  1655,  1657,  1657,  1659,  1659,  1661,  1669,  1669,  1671,
    1671,  1673,  1682,  1681,  1688,  1688,  1690,  1698,  1698,  1700,
    1700,  1702,  1710,  1710,  1712,  1712,  1714,  1717,  1717,  1719,
    1723,  1723,  1725,  1725,  1727,  1738,  1738,  1738,  1738,  1738,
    1738,  1738,  1741,  1741,  1741,  1741,  1741,  1741,  1745,  1745,
    1745,  1745,  1745,  1745,  1749,  1749,  1749,  1749,  1749,  1749,
    1753,  1753,  1753,  1753,  1753,  1757,  1757,  1757,  1757,  1757,
    1763,  1764,  1767,  1768,  1771,  1778,  1779,  1782,  1787,  1794,
    1794,  1794,  1794,  1794,  1794,  1794
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
  "KW_EREWRITE", "KW_FREWRITE", "KW_SREWRITE", "KW_CONTINUE", "KW_SEARCH",
  "KW_SET", "KW_SHOW", "KW_ON", "KW_OFF", "KW_TRACE", "KW_BODY",
  "KW_BUILTIN", "KW_WHOLE", "KW_SELECT", "KW_DESELECT", "KW_CONDITION",
  "KW_SUBSTITUTION", "KW_PRINT", "KW_GRAPH", "KW_MIXFIX", "KW_FLAT",
  "KW_ATTRIBUTE", "KW_NEWLINE", "KW_WITH", "KW_PARENS", "KW_ALIASES",
  "KW_GC", "KW_TIME", "KW_STATS", "KW_TIMING", "KW_CMD", "KW_BREAKDOWN",
  "KW_BREAK", "KW_PATH", "KW_MODULE", "KW_MODULES", "KW_VIEWS", "KW_ALL",
  "KW_SORTS", "KW_OPS2", "KW_VARS", "KW_MBS", "KW_EQS", "KW_RLS",
  "KW_SUMMARY", "KW_KINDS", "KW_ADVISE", "KW_VERBOSE", "KW_DO", "KW_CLEAR",
  "KW_PROTECT", "KW_EXTEND", "KW_INCLUDE", "KW_EXCLUDE", "KW_CONCEAL",
  "KW_REVEAL", "KW_COMPILE", "KW_COUNT", "KW_DEBUG", "KW_RESUME",
  "KW_ABORT", "KW_STEP", "KW_WHERE", "KW_CREDUCE", "KW_SREDUCE", "KW_DUMP",
  "KW_PROFILE", "KW_NUMBER", "KW_RAT", "KW_COLOR", "SIMPLE_NUMBER",
  "KW_PWD", "KW_CD", "KW_PUSHD", "KW_POPD", "KW_LS", "KW_LOAD", "KW_QUIT",
  "KW_EOF", "KW_ENDM", "KW_IMPORT", "KW_ENDV", "KW_SORT", "KW_SUBSORT",
  "KW_OP", "KW_OPS", "KW_MSGS", "KW_VAR", "KW_CLASS", "KW_SUBCLASS",
  "KW_MB", "KW_CMB", "KW_EQ", "KW_CEQ", "KW_RL", "KW_CRL", "KW_IS",
  "KW_FROM", "KW_ARROW", "KW_ARROW2", "KW_PARTIAL", "KW_IF", "':'", "'='",
  "'('", "')'", "'.'", "'<'", "'['", "']'", "','", "'|'", "KW_LABEL",
  "KW_TO", "KW_COLON2", "'+'", "'*'", "'{'", "'}'", "KW_ASSOC", "KW_COMM",
  "KW_ID", "KW_IDEM", "KW_ITER", "KW_LEFT", "KW_RIGHT", "KW_PREC",
  "KW_GATHER", "KW_METADATA", "KW_STRAT", "KW_POLY", "KW_MEMO",
  "KW_FROZEN", "KW_CTOR", "KW_LATEX", "KW_SPECIAL", "KW_CONFIG", "KW_OBJ",
  "KW_MSG", "KW_DITTO", "KW_FORMAT", "KW_ID_HOOK", "KW_OP_HOOK",
  "KW_TERM_HOOK", "KW_IN", "IDENTIFIER", "NUMERIC_ID", "ENDS_IN_DOT",
  "FORCE_LOOKAHEAD", "$accept", "top", "item", "directive", "$@1", "$@2",
  "$@3", "$@4", "$@5", "moduleExprDot", "moduleExpr", "moduleExpr2",
  "moduleExpr3", "renameExpr", "instantExpr", "$@6", "parenExpr",
  "argList", "renaming", "$@7", "$@8", "renaming2", "mappingList",
  "mapping", "$@9", "$@10", "fromSpec", "$@11", "toAttributes", "$@12",
  "toAttributeList", "toAttribute", "$@13", "$@14", "$@15", "view", "$@16",
  "$@17", "$@18", "viewDecList", "viewDeclaration", "$@19", "sortDot",
  "viewEndOpMap", "$@20", "$@21", "$@22", "endBubble", "parenBubble",
  "$@23", "module", "$@24", "$@25", "dot", "parameters", "parameterList",
  "parameter", "colon2", "badType", "typeDot", "startModule", "decList",
  "declaration", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32",
  "$@33", "$@34", "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "$@41",
  "$@42", "$@43", "$@44", "$@45", "$@46", "$@47", "$@48", "classDef",
  "cPairList", "cPair", "varNameList", "opNameList", "simpleOpName",
  "domainRangeAttr", "dra2", "rangeAttr", "typeAttr", "arrow", "typeList",
  "typeName", "$@49", "sortNames", "attributes", "attributeList",
  "idKeyword", "attribute", "$@50", "$@51", "$@52", "$@53", "$@54", "$@55",
  "$@56", "identity", "idList", "hookList", "hook", "expectedIs",
  "expectedDot", "sortNameList", "subsortList", "$@57", "sortName",
  "sortNameFrag", "$@58", "sortNameFrags", "$@59", "token", "tokenBarDot",
  "tokenBarColon", "sortToken", "endsInDot", "inert", "identifier",
  "startKeyword", "startKeyword2", "midKeyword", "attrKeyword",
  "attrKeyword2", "command", "$@60", "$@61", "$@62", "$@63", "$@64",
  "$@65", "$@66", "$@67", "$@68", "$@69", "$@70", "$@71", "$@72", "$@73",
  "$@74", "$@75", "$@76", "$@77", "$@78", "$@79", "$@80", "$@81", "$@82",
  "$@83", "$@84", "$@85", "$@86", "$@87", "$@88", "$@89", "$@90", "$@91",
  "$@92", "$@93", "$@94", "$@95", "printOption", "traceOption", "polarity",
  "select", "exclude", "conceal", "search", "match", "optDebug",
  "optNumber", "importMode", "moduleAndTerm", "$@96", "inEnd", "$@97",
  "numberModuleTerm", "$@98", "$@99", "numberModuleTerm1", "$@100",
  "$@101", "numberModuleTerm2", "$@102", "$@103", "numbersModuleTerm",
  "$@104", "$@105", "numbersModuleTerm1", "$@106", "$@107", "$@108",
  "numbersModuleTerm2", "$@109", "$@110", "$@111", "numbersModuleTerm3",
  "$@112", "$@113", "numbersModuleTerm4", "$@114", "$@115",
  "numbersModuleTerm5", "$@116", "$@117", "numbersModuleTerm6", "$@118",
  "$@119", "miscEndBubble", "$@120", "initialEndBubble", "$@121", "$@122",
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
     375,    58,    61,    40,    41,    46,    60,    91,    93,    44,
     124,   376,   377,   378,    43,    42,   123,   125,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   168,   169,   169,   170,   170,   170,   170,   172,   171,
     173,   171,   171,   174,   171,   175,   171,   171,   176,   171,
     171,   171,   177,   177,   177,   177,   177,   177,   177,   178,
     178,   179,   179,   180,   180,   180,   181,   183,   182,   184,
     185,   185,   187,   188,   186,   189,   189,   190,   190,   191,
     191,   192,   193,   191,   195,   194,   194,   197,   196,   196,
     198,   198,   199,   200,   199,   201,   199,   202,   199,   204,
     205,   206,   203,   207,   207,   208,   208,   209,   208,   208,
     210,   210,   212,   213,   211,   214,   211,   215,   215,   217,
     216,   219,   220,   218,   221,   221,   222,   222,   223,   223,
     224,   225,   225,   226,   227,   227,   228,   228,   229,   229,
     230,   231,   230,   232,   230,   233,   234,   230,   230,   230,
     235,   236,   230,   237,   238,   239,   230,   240,   241,   230,
     242,   243,   244,   230,   245,   246,   230,   247,   248,   249,
     230,   250,   251,   230,   230,   252,   230,   253,   230,   230,
     254,   254,   255,   255,   256,   257,   257,   258,   258,   259,
     259,   260,   260,   260,   261,   261,   261,   262,   263,   263,
     264,   264,   265,   265,   266,   267,   266,   268,   268,   269,
     269,   270,   270,   271,   271,   271,   272,   272,   273,   272,
     272,   272,   272,   274,   272,   275,   272,   276,   272,   277,
     272,   272,   272,   272,   278,   272,   272,   272,   272,   272,
     279,   272,   272,   272,   280,   280,   281,   281,   282,   282,
     283,   283,   283,   283,   284,   284,   285,   285,   286,   286,
     287,   287,   288,   287,   289,   290,   291,   290,   293,   292,
     292,   294,   294,   294,   294,   294,   295,   295,   295,   295,
     295,   295,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   298,   298,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   300,   300,   300,   300,
     301,   301,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   303,
     303,   303,   303,   303,   303,   303,   304,   304,   304,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   307,   306,   308,   306,   309,   306,   310,
     306,   311,   306,   312,   306,   313,   306,   314,   306,   315,
     306,   316,   306,   317,   306,   318,   306,   319,   306,   306,
     320,   306,   306,   321,   306,   322,   306,   323,   306,   324,
     306,   306,   325,   306,   326,   306,   327,   306,   328,   306,
     306,   306,   329,   306,   330,   306,   331,   306,   332,   306,
     333,   306,   334,   306,   335,   306,   336,   306,   306,   306,
     306,   337,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   338,   339,   306,   340,
     341,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   342,   306,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   345,   345,   346,
     346,   347,   347,   348,   348,   349,   349,   349,   350,   350,
     351,   351,   352,   352,   353,   353,   353,   354,   355,   354,
     357,   356,   356,   359,   358,   358,   360,   358,   362,   361,
     363,   361,   361,   365,   364,   366,   364,   364,   368,   367,
     367,   369,   367,   371,   370,   372,   370,   373,   370,   370,
     375,   374,   376,   374,   377,   374,   374,   379,   378,   380,
     378,   378,   382,   381,   383,   381,   381,   385,   384,   386,
     384,   384,   388,   387,   389,   387,   387,   391,   390,   390,
     393,   392,   394,   392,   392,   395,   395,   395,   395,   395,
     395,   395,   396,   396,   396,   396,   396,   396,   397,   397,
     397,   397,   397,   397,   398,   398,   398,   398,   398,   398,
     399,   399,   399,   399,   399,   400,   400,   400,   400,   400,
     401,   401,   402,   402,   403,   404,   404,   405,   405,   406,
     406,   406,   406,   406,   406,   406
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
       0,     0,    12,     2,     0,     4,     4,     0,     3,     2,
       2,     1,     0,     0,     8,     0,     3,     1,     1,     0,
       3,     0,     0,     8,     1,     1,     3,     0,     3,     1,
       3,     1,     1,     1,     2,     1,     1,     1,     2,     0,
       2,     0,     4,     0,     4,     0,     0,     5,     4,     4,
       0,     0,     5,     0,     0,     0,     7,     0,     0,     5,
       0,     0,     0,     7,     0,     0,     5,     0,     0,     0,
       7,     0,     0,     5,     4,     0,     5,     0,     4,     2,
       1,     2,     1,     3,     3,     2,     1,     2,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     2,     0,     1,     0,     4,     3,     1,     3,
       0,     2,     1,     1,     2,     2,     1,     1,     0,     3,
       1,     1,     2,     0,     5,     0,     5,     0,     5,     0,
       5,     1,     1,     1,     0,     5,     1,     1,     1,     2,
       0,     5,     4,     1,     1,     0,     2,     1,     2,     1,
       2,     3,     3,     3,     1,     0,     1,     0,     2,     0,
       2,     2,     0,     4,     1,     1,     0,     5,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     3,     0,     3,     0,     3,     4,
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
       1,     0,     1,     0,     1,     1,     1,     1,     0,     3,
       0,     3,     1,     0,     3,     1,     0,     3,     0,     3,
       0,     3,     1,     0,     3,     0,     3,     1,     0,     3,
       1,     0,     3,     0,     3,     0,     3,     0,     3,     1,
       0,     3,     0,     3,     0,     3,     1,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     1,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     1,     0,     3,     1,
       0,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   444,   106,   107,    69,   347,   370,   475,   476,   479,
     478,   367,   477,     0,     0,     0,   343,     0,     0,     0,
     480,     0,     0,     0,     0,   349,   351,   345,    12,    13,
      15,    17,    18,    10,    20,    21,    89,     8,     0,     2,
       6,     5,   372,     4,    91,     7,   363,   365,     0,     0,
       0,     0,     0,     0,     0,     0,   456,     0,     0,     0,
       0,     0,     0,   484,   485,   486,     0,     0,   426,   382,
     388,     0,     0,   384,     0,     0,   386,   392,   394,   396,
     398,   400,   402,   404,   406,   411,   469,   470,   472,   471,
     373,   375,     0,   473,   474,   379,   377,     0,   438,   439,
     440,   441,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,   353,   355,   357,   359,   361,
     483,   445,   307,   292,   308,   293,   294,   295,   296,   298,
     297,   299,   300,   301,   302,   303,   304,   305,   306,   285,
     284,   311,   314,   312,   315,   310,   313,   245,   309,   316,
     317,   288,   281,   283,   289,   282,   279,   280,   277,   278,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   335,
     328,   329,   330,   334,   331,   332,   333,   336,   337,   290,
     338,   339,   340,   341,   342,   276,   287,     0,   286,   241,
     242,   291,   243,   244,   318,   559,   550,   560,   557,   558,
     561,   552,   555,   556,   554,   348,   487,   488,   371,   565,
     566,   493,   564,   567,   562,   563,   368,   495,   496,   429,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     458,   460,   457,   459,   461,   462,   463,     0,   450,   446,
     447,     0,     0,   451,   452,   453,   454,   455,     0,     0,
     467,   468,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   390,   391,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,   344,     0,     0,     0,   350,   352,   346,
      14,    16,    19,    11,    90,     9,    92,   508,   364,   510,
     511,   366,     0,     0,     0,     0,     0,   482,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   449,   448,     0,
       0,   443,   425,   432,     0,     0,     0,     0,   436,   604,
     601,   602,   605,   603,   599,   600,   427,   383,   389,   410,
     408,     0,   385,   387,   393,   395,   397,   399,   401,   403,
     405,   407,   412,   594,   598,   374,   591,     0,   596,   597,
     376,   380,   378,   381,    97,     0,     0,   354,   356,   358,
     360,   362,   369,     0,    70,    29,    31,    32,    34,    33,
      35,   551,   490,   492,   553,   489,   572,   547,   569,   570,
     573,   571,   568,   498,   549,   494,   502,   500,   497,   430,
       0,     0,   420,   414,   416,   419,   417,   413,   424,     0,
     422,   421,   442,   434,   437,   433,   435,     0,   409,   592,
     590,   593,   595,     0,   225,   584,   581,   582,   515,   583,
     580,   513,   509,   519,   517,   512,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,   415,   418,   423,     0,
       0,    99,     0,   224,   109,     0,     0,     0,    39,    30,
       0,    42,    36,     0,   491,   548,   578,   576,   503,   579,
     577,   574,   575,   499,   507,   505,   501,     0,   428,     0,
      96,   102,   101,     0,     0,   537,   516,   541,   539,   589,
     587,   520,   522,   588,   585,   586,   514,   526,   524,   518,
      71,     0,     0,    41,     0,     0,   431,    98,   100,     0,
      93,     0,   111,   113,   115,     0,     0,     0,     0,   147,
     120,   123,   127,   130,   134,   137,   141,   108,     0,     0,
       0,     0,     0,   225,    46,     0,    51,     0,    43,    45,
      48,     0,    38,   504,   506,   149,   245,   247,   248,    28,
     110,     0,   227,   227,   227,   227,     0,   246,   249,   250,
     251,   229,     0,     0,   257,   260,   258,   261,   259,   255,
     256,   160,     0,   158,   159,   252,   253,   254,     0,     0,
     156,   145,     0,     0,     0,     0,     0,     0,     0,     0,
     542,   538,   546,   544,   540,   521,   527,   523,   531,   529,
     525,    74,   271,   269,   270,   265,   266,   272,   273,   267,
     268,   262,     0,   234,   235,   263,   264,    56,     0,     0,
       0,    40,     0,   226,    25,    26,    24,    22,    23,     0,
       0,   232,   116,     0,   157,     0,     0,   155,     0,     0,
     121,   124,   128,   131,   135,   138,   142,     0,     0,     0,
       0,     0,     0,   236,    54,     0,     0,    44,    47,    27,
      30,    94,    95,   112,   228,   231,   114,   230,   229,     0,
     170,   171,   175,   103,   163,   118,   162,     0,   173,   174,
     144,   105,   119,   227,   150,     0,   148,     0,     0,     0,
       0,     0,     0,     0,   543,   545,   532,   528,   536,   534,
     530,     0,    72,     0,    77,     0,    73,    49,     0,   173,
      52,    50,     0,   117,     0,   169,   167,   180,     0,   104,
     247,   248,   151,   152,     0,   246,   249,   250,   251,   146,
     122,   125,   129,   132,   136,   139,   143,     0,     0,    79,
       0,     0,     0,   240,     0,     0,    59,   233,     0,   178,
       0,   227,   165,   166,   161,   164,   172,     0,     0,     0,
       0,     0,   533,   535,     0,    82,    85,    78,     0,   238,
     237,     0,    57,    53,   176,     0,   186,   187,   183,   190,
     191,     0,     0,     0,     0,     0,     0,     0,   201,   203,
     202,     0,     0,   206,   207,   208,   213,     0,     0,   188,
     182,   168,   153,   154,   126,   133,   140,    81,    75,   227,
     173,     0,    76,     0,    55,     0,   177,   184,   185,   192,
     193,   209,   197,   199,   204,   210,     0,   195,   179,   181,
     215,    80,     0,    86,   239,     0,     0,     0,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,     0,   214,   189,     0,    62,    63,    67,    65,    58,
      60,   217,     0,     0,     0,     0,     0,   220,     0,     0,
     212,   218,     0,     0,     0,     0,     0,   194,   216,   198,
     200,   205,   211,   221,   222,   223,   196,    83,     0,     0,
       0,     0,    64,    68,    66,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    38,    39,    40,   110,   108,   105,   106,   107,   560,
     384,   385,   386,   387,   388,   473,   389,   512,   472,   511,
     629,   548,   549,   550,   627,   756,   665,   719,   783,   825,
     849,   850,   884,   886,   885,    41,    50,   448,   543,   661,
     716,   751,   818,   777,   820,   901,   821,   404,   364,   109,
      43,   112,   374,   673,   434,   460,   461,   493,   684,   692,
      44,   494,   537,   571,   572,   573,   679,   593,   697,   594,
     698,   769,   595,   699,   596,   700,   770,   597,   701,   598,
     702,   771,   599,   703,   648,   592,   695,   732,   733,   589,
     582,   583,   685,   764,   686,   726,   687,   728,   688,   724,
     758,   761,   808,   809,   810,   840,   851,   861,   852,   853,
     854,   855,   863,   872,   859,   860,   464,   634,   639,   640,
     678,   689,   623,   718,   754,   823,   390,   565,   584,   624,
     566,   188,   189,   625,   191,   192,   193,   194,    45,    92,
     104,    51,   102,   103,   302,   303,   304,   305,   306,   113,
     114,    53,    52,   279,   280,   285,   284,   261,   266,   269,
     262,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     260,   427,   315,   455,    49,   248,   237,   252,    90,    91,
      95,    46,    47,    48,   308,    68,   205,   312,   394,   451,
     216,   313,   314,   405,   453,   454,   483,   514,   515,   298,
     375,   376,   442,   466,   465,   467,   506,   540,   541,   542,
     607,   659,   660,   707,   747,   748,   496,   538,   539,   601,
     657,   658,   406,   452,   206,   310,   311,   207,   218,   407,
     485,   444,   508,   365,   430,   366,   367,   368,   369
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -717
static const yytype_int16 yypact[] =
{
     624,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,   330,   266,   267,  -717,   168,   270,   -26,
    -717,   -78,   -47,   -44,   -31,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,    76,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,   451,   -28,
    1058,   183,   183,   257,    51,   231,   406,    67,    99,   326,
     326,   326,   -22,  -717,  -717,  -717,    70,   326,  -717,  -717,
    -717,   121,   -60,  -717,    18,    39,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,   -74,  -717,  -717,  -717,  -717,    44,  -717,  -717,
    -717,  -717,   183,   183,   -74,   189,   206,   232,   208,   124,
     248,  -717,  1058,   331,   257,  -717,  -717,  -717,  -717,  -717,
     169,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,   147,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
     317,   326,   326,   326,   326,   326,   326,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,   326,  -717,  -717,
    -717,    29,   348,  -717,  -717,  -717,  -717,  -717,   326,   326,
    -717,  -717,   140,   145,   152,   326,   326,   326,   326,   163,
     641,   -74,   -74,   166,   170,   218,   -74,  -717,  -717,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,  2136,
    2136,  -717,  -717,  -717,  2136,  2136,   172,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,   183,   257,   331,   331,   257,  -717,   192,   782,
     -74,   -80,   -74,   407,   -74,   641,   326,   326,   211,   220,
     225,   237,   254,   258,   272,   326,   277,  -717,  -717,   281,
     282,  -717,  -717,  -717,   291,   300,   301,   303,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,   304,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,   456,  -717,  -717,
    -717,  -717,  -717,  -717,   195,   571,   -74,  -717,  -717,  -717,
    -717,  -717,  -717,   782,   199,   221,   296,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
     309,   314,  -717,  -717,  -717,  -717,  -717,  -717,  -717,   320,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,   326,  -717,  -717,
    -717,  -717,  -717,  1058,   332,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,   -66,   782,   323,   334,
    -717,   -74,   -74,   617,   -74,   326,  -717,  -717,  -717,   336,
     106,  -717,   -73,  -717,  -717,   627,   636,   -74,  -717,  -717,
     782,  -717,  -717,  1058,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,   352,  -717,  1058,
    -717,  -717,  -717,   782,   452,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
     199,     7,   157,  -717,   183,   -74,  -717,  -717,   199,   354,
    -717,   851,  -717,  -717,  -717,  1127,  1127,  1334,  1058,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,   698,   -74,
     183,   707,   -74,   332,  -717,  2085,  -717,  1058,  -717,   357,
    -717,  1058,  -717,  -717,  -717,  -717,   356,   207,   253,   103,
    -717,   353,    38,   180,   234,   364,   366,   275,   278,   308,
     340,  -717,  2085,   344,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,   920,  -717,  -717,  -717,  -717,  -717,   989,  1196,
    -717,  -717,  2085,   371,   372,   379,   380,   385,   387,   388,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,   374,   376,  -717,  -717,  -717,   389,   381,   390,
      64,  -717,   851,  -717,  -717,  -717,  -717,  -717,  -717,  1610,
    1541,  -717,  -717,  1472,  -717,  1472,  1679,  -717,   391,  1541,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,   183,   -74,  2127,
     -74,    56,  2085,  -717,  -717,   386,  1058,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  1472,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  1679,  -717,  -717,
    -717,  -717,  -717,   364,  1817,   394,  -717,   -74,   400,   -74,
     402,   -74,   403,  1472,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,   404,  -717,  2085,  -717,  1334,  -717,  -717,  2085,  -717,
    -717,  -717,  1951,  -717,  2085,  -717,  -717,   410,  1403,  -717,
    -717,  -717,   398,  -717,   412,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,   183,   -74,  -717,
     399,   129,  1265,   376,   161,  1884,   411,  -717,   245,  -717,
    2128,   364,  -717,  -717,  -717,  -717,  -717,  1817,  1058,   -74,
     -74,   -74,  -717,  -717,  1748,  -717,  -717,  -717,  1679,  -717,
    -717,  2018,  -717,  -717,  -717,  2085,  -717,  -717,  -717,  -717,
    -717,   401,   408,   378,   417,   414,   420,   421,  -717,   429,
    -717,   445,   453,  -717,  -717,  -717,  -717,   457,   701,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,   364,
    -717,   -74,  -717,  2085,  -717,    15,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,   338,  -717,  -717,  -717,
     419,  -717,  1884,  -717,   376,   423,   467,   468,   469,   -79,
    -717,   430,   430,   430,   430,   569,  1058,  1058,  1058,   122,
    -717,   430,  -717,  -717,  2018,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,   -65,   -63,   -51,   -45,   471,   470,   470,   470,
    -717,  -717,   -13,   443,   430,   591,   430,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,    26,   473,
      42,   -74,  -717,  -717,  -717,  -717
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,   -34,
    -372,  -717,  -717,  -515,  -509,  -717,  -507,  -717,  -717,  -717,
    -717,  -717,  -717,   -30,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -250,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,   -91,     0,  -717,
    -717,  -717,  -717,  -547,  -717,  -717,   112,  -717,  -641,  -176,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -164,  -111,
      79,  -440,  -591,  -717,  -117,  -717,  -716,  -688,  -637,  -717,
    -717,  -717,  -717,  -717,  -196,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -337,  -717,  -246,    71,  -546,   -62,    23,
    -717,  -305,  -692,  -717,  -717,  -717,   -40,  -667,  -499,  -717,
    -717,  -518,  -493,   -43,  -717,  -498,  -505,  -510,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,   -24,   599,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,   -50,  -717,  -717,  -717,
     -99,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,    90,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,  -717,
    -717,  -717,  -350,  -717,   -49,  -717,  -717,  -717,   -75,  -421,
    -514,  -717,  -717,    87,  -717,   251,  -717,   260,  -230
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -482
static const yytype_int16 yytable[] =
{
      42,   283,   208,   567,   217,   691,   562,   190,   544,   693,
     187,   446,   563,   289,   564,   301,   570,   635,   636,   637,
     587,   587,   587,   569,   603,   443,   753,   734,   590,   264,
     346,   755,   585,   585,   585,   626,   253,   254,   300,   781,
     255,   392,    97,   259,   498,   281,   725,    98,   491,   869,
     727,   281,   287,   288,   690,   250,   251,   711,   468,   887,
     492,   889,   626,   256,   299,   217,   845,   846,   447,   190,
     325,   265,   296,   890,   847,   469,   111,   587,    99,   891,
     848,   100,   626,   587,   587,   409,   282,   763,   723,   585,
     647,   766,   282,   676,   101,   585,   585,   121,   510,   888,
     734,   888,   696,   484,   238,   239,   240,   241,   545,   242,
     546,   896,   746,   888,   567,   497,   507,   562,   766,   888,
     609,   518,   219,   563,   249,   564,   864,   570,   257,   626,
     626,   844,   842,   626,   569,   626,   626,   691,   547,   626,
     243,   693,   644,   267,   824,   709,   258,   729,   644,   561,
     902,   888,   626,   244,   245,   246,   712,   713,   263,   714,
     845,   846,   715,   633,   268,   545,   904,   546,   847,   626,
     347,   348,   -32,   -32,   848,   352,   735,   626,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   602,   738,
     888,   608,   290,   626,   286,   547,   737,   318,   319,   320,
     321,   322,   323,   626,   378,   766,   888,   381,   626,   291,
     587,   293,   626,   324,   626,   811,   590,   326,   626,   391,
     393,   395,   585,   408,   329,   330,   247,   883,  -275,   300,
     300,   334,   335,   336,   337,   489,   292,  -287,  -287,  -287,
     622,    93,    94,   490,   220,   626,   880,   587,   294,   735,
     775,   295,   377,   647,   217,   299,   299,   217,   307,   585,
     670,   776,   738,   309,   626,   331,   190,   641,   626,   737,
     332,   626,    69,   841,    70,   626,   221,   333,   222,   223,
     224,   225,   856,   857,   858,   445,   551,   641,   338,    71,
     779,   349,   410,   411,   552,   350,   226,   373,   780,    86,
      87,   419,    86,    87,   195,   633,   196,   351,   197,   708,
     198,   199,   200,   626,   -34,   -34,   -34,   382,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,   433,   626,   447,   674,   677,   412,    54,    88,    89,
     190,  -288,  -288,  -288,   677,   413,   201,   202,   203,   204,
     414,    85,   250,   251,   626,    55,   449,   717,    56,   633,
     474,   475,   415,   486,   316,   317,    57,   370,   -33,   -33,
     -33,   371,   372,   784,   785,    58,   509,    59,   209,   416,
     196,    60,   210,   417,   211,   212,   213,  -289,  -289,  -289,
     190,   327,   328,   462,   379,   380,    61,   418,    62,    63,
      64,    65,   420,   459,   190,    66,   421,   422,   750,  -286,
    -286,  -286,  -242,  -242,  -242,    67,   423,   674,   227,   759,
     201,   214,   215,   204,   554,   424,   425,   190,   426,   428,
     190,   487,   450,   513,   456,   228,   229,   230,   231,   457,
     232,   233,  -243,  -243,  -243,   458,   190,   463,   604,   462,
     190,   610,   209,   519,   196,   470,   210,   471,   297,   212,
     213,   488,   115,   116,   553,   642,   234,   235,   236,   819,
     117,   118,   119,   120,  -244,  -244,  -244,   516,   568,   555,
     826,  -274,   586,   586,   586,   190,   630,   632,   591,   633,
     605,   638,   650,   651,   201,   214,   215,   204,   856,   857,
     858,   652,   653,   654,   190,   655,   662,   628,   190,   656,
     664,   631,   663,   666,   667,   873,   874,   875,   720,   739,
     741,   694,   743,   745,   882,   581,   581,   767,   396,   749,
     397,   774,   281,   768,   398,   399,   400,   760,   782,   586,
     830,   827,   829,   832,   833,   586,   586,   898,   828,   900,
     520,   521,   834,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   705,   835,   710,
     401,   402,   403,   282,   876,   897,   836,   339,   831,    36,
     837,   429,   581,   340,   341,   342,   862,   865,   581,   568,
     866,   867,   868,    36,   871,   892,   899,   903,   669,   870,
     668,   517,   822,   812,   752,   588,   740,   704,   742,   536,
     744,   765,   839,   881,   611,   649,   722,    96,   431,   343,
     344,   345,   363,   190,    -3,     1,   721,   432,     0,     0,
       2,     3,     4,     5,     0,  -481,  -481,     6,     7,     8,
       9,    10,    11,  -481,  -481,  -481,  -481,    12,    13,    14,
       0,   736,    15,     0,     0,     0,    16,   773,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   586,     0,     0,    18,     0,     0,   814,   815,
     816,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,   435,     0,   397,     0,   281,   772,   436,   437,
     438,    20,    21,    22,    23,    24,    25,    26,    27,   586,
       0,     0,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,   736,   190,     0,     0,   813,     0,
     843,     0,     0,     0,   439,   440,   441,   282,   476,     0,
     397,     0,   281,     0,   477,   478,   479,    36,   396,     0,
     397,     0,   281,     0,   398,   399,   400,   499,     0,   397,
       0,   281,   339,   500,   501,   502,     0,     0,   340,   341,
     342,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     480,   481,   482,   282,     0,     0,     0,    37,     0,     0,
     401,   402,   495,   282,     0,     0,     0,     0,     0,   503,
     504,   505,   282,     0,   343,   344,   345,     0,     0,     0,
     905,     0,     0,   190,   190,   190,   877,   878,   879,   476,
       0,   397,     0,   281,     0,   477,   600,   479,   396,   838,
     397,     0,   281,     0,   398,   399,   400,     0,     0,   786,
     787,   788,   789,   790,   791,   792,   793,   794,   795,   796,
     797,   798,   799,   800,   801,   802,   803,   804,   805,   806,
     807,   480,   481,   482,   282,     0,     0,     0,     0,     0,
     401,   402,   606,   282,     0,     0,     0,   893,   894,   895,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   383,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,     0,   185,     0,   186,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   383,     0,   556,   148,   149,   150,
     557,   152,   153,   558,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,     0,   185,     0,   559,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   574,   575,   576,
     577,   643,   578,    36,     0,   579,   580,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,     0,   185,     0,   186,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   574,   575,   576,   577,
     645,   578,    36,     0,   579,   580,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,     0,   185,     0,   186,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,     0,   185,     0,   186,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   574,   575,   576,   577,     0,   578,
      36,     0,   579,   580,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
       0,   185,     0,   186,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   574,   575,   576,   577,   646,   578,     0,
       0,   579,   580,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,     0,
     185,     0,   186,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   574,   575,   576,   577,   778,   578,     0,     0,
     579,   580,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,     0,   185,
       0,   186,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   574,   575,   576,   577,     0,   578,     0,     0,   579,
     580,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,     0,   185,     0,
     186,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   612,     0,
     680,   613,   681,   614,     0,   615,     0,     0,   762,     0,
     682,     0,     0,   616,   617,   618,     0,   619,   620,     0,
       0,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,     0,   621,     0,   683,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   612,     0,   680,
     613,   681,   614,     0,   615,     0,     0,     0,     0,   682,
       0,     0,   616,   617,   618,     0,   619,   620,     0,     0,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,     0,   621,     0,   683,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   612,     0,     0,   613,
       0,   614,     0,   615,     0,     0,   671,   675,     0,     0,
       0,   616,   617,   618,     0,   619,   620,     0,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,     0,   621,     0,   672,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   612,     0,     0,   613,     0,
     614,     0,   615,     0,     0,   671,     0,     0,     0,     0,
     616,   617,   618,     0,   619,   620,     0,     0,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,     0,   621,     0,   672,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   612,     0,     0,   613,     0,   614,
       0,   615,     0,     0,     0,     0,   682,     0,     0,   616,
     617,   618,     0,   619,   620,     0,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,     0,   621,     0,   683,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   612,     0,     0,   613,     0,   614,     0,
     615,     0,     0,     0,     0,     0,     0,     0,   616,   617,
     618,     0,   619,   620,     0,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,     0,   621,     0,   817,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,   148,   149,   150,   730,   152,   153,   731,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
       0,   185,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   612,
       0,   680,   613,   681,   614,     0,   615,     0,     0,     0,
       0,   682,     0,     0,   616,   617,   618,     0,   619,   620,
       0,     0,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,     0,   621,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   612,     0,     0,   613,
       0,   614,     0,   615,     0,     0,     0,   757,     0,     0,
       0,   616,   617,   618,     0,   619,   620,     0,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,     0,   621,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   612,     0,     0,   613,     0,   614,     0,
     615,     0,     0,     0,     0,   682,     0,     0,   616,   617,
     618,     0,   619,   620,     0,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,     0,   621,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     612,     0,     0,   613,     0,   614,     0,   615,     0,     0,
       0,     0,     0,     0,     0,   616,   617,   618,     0,   619,
     620,     0,     0,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   476,   621,
     397,     0,   281,     0,   477,   706,   479,   339,     0,    36,
       0,     0,     0,   340,   341,   342,   786,   787,   788,   789,
     790,   791,   792,   793,   794,   795,   796,   797,   798,   799,
     800,   801,   802,   803,   804,   805,   806,   807,     0,     0,
     480,   481,   482,   282,     0,     0,     0,     0,     0,   343,
     344,   345,   363
};

static const yytype_int16 yycheck[] =
{
       0,    92,    52,   521,    53,   646,   521,    50,     1,   646,
      50,   383,   521,   104,   521,   114,   521,   563,   564,   565,
     525,   526,   527,   521,   538,   375,   718,   694,   527,    89,
     260,   719,   525,   526,   527,   545,    60,    61,   113,   755,
      62,   121,    68,    67,   465,   125,   687,   125,   121,   128,
     687,   125,   102,   103,   645,    26,    27,     1,   124,   124,
     133,   124,   572,    85,   113,   114,   145,   146,   134,   112,
      41,   131,   112,   124,   153,   447,     0,   582,   125,   124,
     159,   125,   592,   588,   589,   315,   166,   728,   679,   582,
     589,   728,   166,   640,   125,   588,   589,   125,   470,   164,
     767,   164,   649,   453,    37,    38,    39,    40,   101,    42,
     103,   124,   703,   164,   632,   465,   466,   632,   755,   164,
     541,   493,    71,   632,    25,   632,   842,   632,   150,   639,
     640,   823,   820,   643,   632,   645,   646,   778,   131,   649,
      73,   778,   582,   125,   781,   659,    76,   693,   588,   521,
     124,   164,   662,    86,    87,    88,   100,   101,    37,   103,
     145,   146,   106,   125,   125,   101,   124,   103,   153,   679,
     261,   262,   134,   135,   159,   266,   694,   687,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   538,   694,
     164,   541,     3,   703,   150,   131,   694,   221,   222,   223,
     224,   225,   226,   713,   303,   842,   164,   306,   718,     3,
     715,     3,   722,   237,   724,   761,   715,   241,   728,   310,
     311,   312,   715,   314,   248,   249,   159,   864,   125,   304,
     305,   255,   256,   257,   258,   129,     4,   134,   135,   136,
     545,    73,    74,   137,    13,   755,   124,   752,   124,   767,
     121,     3,   302,   752,   303,   304,   305,   306,    89,   752,
     632,   132,   767,   116,   774,   125,   309,   572,   778,   767,
     125,   781,     6,   819,     8,   785,    45,   125,    47,    48,
      49,    50,   160,   161,   162,   376,   129,   592,   125,    23,
     129,   125,   316,   317,   137,   125,    65,   125,   137,    32,
      33,   325,    32,    33,   121,   125,   123,    89,   125,   659,
     127,   128,   129,   823,   134,   135,   136,   125,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   136,   842,   134,   639,   640,   125,     7,    71,    72,
     383,   134,   135,   136,   649,   125,   163,   164,   165,   166,
     125,    85,    26,    27,   864,    25,   135,   662,    28,   125,
     451,   452,   125,   454,    47,    48,    36,   280,   134,   135,
     136,   284,   285,   128,   129,    45,   467,    47,   121,   125,
     123,    51,   125,   125,   127,   128,   129,   134,   135,   136,
     433,    43,    44,   433,   304,   305,    66,   125,    68,    69,
      70,    71,   125,   427,   447,    75,   125,   125,   713,   134,
     135,   136,   134,   135,   136,    85,   125,   722,    12,   724,
     163,   164,   165,   166,   515,   125,   125,   470,   125,   125,
     473,   455,   136,   473,   125,    29,    30,    31,    32,   125,
      34,    35,   134,   135,   136,   125,   489,   115,   539,   489,
     493,   542,   121,     1,   123,   132,   125,   123,   127,   128,
     129,   125,    11,    12,   514,   121,    60,    61,    62,   774,
      19,    20,    21,    22,   134,   135,   136,   125,   521,   125,
     785,   125,   525,   526,   527,   528,   129,   134,   528,   125,
     540,   125,   121,   121,   163,   164,   165,   166,   160,   161,
     162,   122,   122,   118,   547,   118,   132,   547,   551,   121,
     121,   551,   136,   132,   124,   852,   853,   854,   132,   125,
     120,   130,   120,   120,   861,   525,   526,   129,   121,   125,
     123,   132,   125,   121,   127,   128,   129,   127,   127,   582,
     123,   140,   164,   123,   123,   588,   589,   884,   140,   886,
      98,    99,   123,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   658,   123,   660,
     163,   164,   165,   166,     5,   132,   123,   121,   164,   123,
     123,   125,   582,   127,   128,   129,   167,   164,   588,   632,
     123,   123,   123,   123,   164,   124,     5,   124,   632,   849,
     630,   489,   778,   767,   715,   526,   697,   657,   699,   157,
     701,   728,   808,   859,   543,   592,   678,    18,   367,   163,
     164,   165,   166,   666,     0,     1,   666,   367,    -1,    -1,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,   694,    28,    -1,    -1,    -1,    32,   748,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   715,    -1,    -1,    51,    -1,    -1,   769,   770,
     771,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,   121,    -1,   123,    -1,   125,   747,   127,   128,
     129,    77,    78,    79,    80,    81,    82,    83,    84,   752,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,   767,   768,    -1,    -1,   768,    -1,
     821,    -1,    -1,    -1,   163,   164,   165,   166,   121,    -1,
     123,    -1,   125,    -1,   127,   128,   129,   123,   121,    -1,
     123,    -1,   125,    -1,   127,   128,   129,   121,    -1,   123,
      -1,   125,   121,   127,   128,   129,    -1,    -1,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,    -1,    -1,    -1,   163,    -1,    -1,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,    -1,   163,   164,   165,    -1,    -1,    -1,
     901,    -1,    -1,   856,   857,   858,   856,   857,   858,   121,
      -1,   123,    -1,   125,    -1,   127,   128,   129,   121,   128,
     123,    -1,   125,    -1,   127,   128,   129,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,    -1,    -1,    -1,   877,   878,   879,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,   164,    -1,   166,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    -1,   164,    -1,   166,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,    -1,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,   164,    -1,   166,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,    -1,   164,    -1,   166,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,   164,    -1,   166,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
     123,    -1,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
      -1,   164,    -1,   166,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
     164,    -1,   166,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    -1,   164,
      -1,   166,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,   122,    -1,    -1,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,   164,    -1,
     166,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,   125,    -1,
     127,    -1,    -1,   130,   131,   132,    -1,   134,   135,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    -1,   164,    -1,   166,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,    -1,   127,
      -1,    -1,   130,   131,   132,    -1,   134,   135,    -1,    -1,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,   164,    -1,   166,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,   118,
      -1,   120,    -1,   122,    -1,    -1,   125,   126,    -1,    -1,
      -1,   130,   131,   132,    -1,   134,   135,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    -1,   164,    -1,   166,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,   118,    -1,
     120,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,    -1,
     130,   131,   132,    -1,   134,   135,    -1,    -1,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,   164,    -1,   166,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,   118,    -1,   120,
      -1,   122,    -1,    -1,    -1,    -1,   127,    -1,    -1,   130,
     131,   132,    -1,   134,   135,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,    -1,   164,    -1,   166,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,   118,    -1,   120,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,    -1,   134,   135,    -1,    -1,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,   164,    -1,   166,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
      -1,   164,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
      -1,   127,    -1,    -1,   130,   131,   132,    -1,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,   164,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,   118,
      -1,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,    -1,
      -1,   130,   131,   132,    -1,   134,   135,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    -1,   164,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,   118,    -1,   120,    -1,
     122,    -1,    -1,    -1,    -1,   127,    -1,    -1,   130,   131,
     132,    -1,   134,   135,    -1,    -1,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,   164,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,   118,    -1,   120,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,   134,
     135,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   121,   164,
     123,    -1,   125,    -1,   127,   128,   129,   121,    -1,   123,
      -1,    -1,    -1,   127,   128,   129,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,    -1,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,   166
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    14,    15,    16,
      17,    18,    23,    24,    25,    28,    32,    36,    51,    67,
      77,    78,    79,    80,    81,    82,    83,    84,    90,    91,
      92,    93,    94,    95,    96,    97,   123,   163,   169,   170,
     171,   203,   216,   218,   228,   306,   349,   350,   351,   342,
     204,   309,   320,   319,     7,    25,    28,    36,    45,    47,
      51,    66,    68,    69,    70,    71,    75,    85,   353,     6,
       8,    23,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    85,    32,    33,    71,    72,
     346,   347,   307,    73,    74,   348,   346,    68,   125,   125,
     125,   125,   310,   311,   308,   174,   175,   176,   173,   217,
     172,     0,   219,   317,   318,    11,    12,    19,    20,    21,
      22,   125,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   164,   166,   294,   299,   300,
     301,   302,   303,   304,   305,   121,   123,   125,   127,   128,
     129,   163,   164,   165,   166,   354,   392,   395,   354,   121,
     125,   127,   128,   129,   164,   165,   358,   392,   396,    71,
      13,    45,    47,    48,    49,    50,    65,    12,    29,    30,
      31,    32,    34,    35,    60,    61,    62,   344,    37,    38,
      39,    40,    42,    73,    86,    87,    88,   159,   343,    25,
      26,    27,   345,   345,   345,    62,    85,   150,    76,   345,
     338,   325,   328,    37,    89,   131,   326,   125,   125,   327,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   321,
     322,   125,   166,   215,   324,   323,   150,   354,   354,   215,
       3,     3,     4,     3,   124,     3,   294,   127,   367,   392,
     396,   358,   312,   313,   314,   315,   316,    89,   352,   116,
     393,   394,   355,   359,   360,   340,    47,    48,   345,   345,
     345,   345,   345,   345,   345,    41,   345,    43,    44,   345,
     345,   125,   125,   125,   345,   345,   345,   345,   125,   121,
     127,   128,   129,   163,   164,   165,   406,   215,   215,   125,
     125,    89,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   166,   216,   401,   403,   404,   405,   406,
     401,   401,   401,   125,   220,   368,   369,   354,   358,   367,
     367,   358,   125,   123,   178,   179,   180,   181,   182,   184,
     294,   215,   121,   215,   356,   215,   121,   123,   127,   128,
     129,   163,   164,   165,   215,   361,   390,   397,   215,   406,
     345,   345,   125,   125,   125,   125,   125,   125,   125,   345,
     125,   125,   125,   125,   125,   125,   125,   339,   125,   125,
     402,   403,   405,   136,   222,   121,   127,   128,   129,   163,
     164,   165,   370,   390,   399,   215,   178,   134,   205,   135,
     136,   357,   391,   362,   363,   341,   125,   125,   125,   345,
     223,   224,   294,   115,   284,   372,   371,   373,   124,   178,
     132,   123,   186,   183,   215,   215,   121,   127,   128,   129,
     163,   164,   165,   364,   390,   398,   215,   345,   125,   129,
     137,   121,   133,   225,   229,   165,   384,   390,   397,   121,
     127,   128,   129,   163,   164,   165,   374,   390,   400,   215,
     178,   187,   185,   294,   365,   366,   125,   224,   178,     1,
      98,    99,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   157,   230,   385,   386,
     375,   376,   377,   206,     1,   101,   103,   131,   189,   190,
     191,   129,   137,   354,   215,   125,   125,   129,   132,   166,
     177,   178,   181,   182,   184,   295,   298,   299,   301,   303,
     304,   231,   232,   233,   117,   118,   119,   120,   122,   125,
     126,   216,   258,   259,   296,   300,   301,   304,   258,   257,
     296,   294,   253,   235,   237,   240,   242,   245,   247,   250,
     128,   387,   390,   398,   215,   354,   165,   378,   390,   397,
     215,   284,   115,   118,   120,   122,   130,   131,   132,   134,
     135,   164,   289,   290,   297,   301,   305,   192,   294,   188,
     129,   294,   134,   125,   285,   285,   285,   285,   125,   286,
     287,   289,   121,   121,   259,   121,   121,   296,   252,   287,
     121,   121,   122,   122,   118,   118,   121,   388,   389,   379,
     380,   207,   132,   136,   121,   194,   132,   124,   191,   177,
     178,   125,   166,   221,   289,   126,   221,   289,   288,   234,
     117,   119,   127,   166,   226,   260,   262,   264,   266,   289,
     260,   226,   227,   266,   130,   254,   221,   236,   238,   241,
     243,   246,   248,   251,   354,   215,   128,   381,   390,   398,
     215,     1,   100,   101,   103,   106,   208,   289,   291,   195,
     132,   294,   286,   260,   267,   226,   263,   266,   265,   285,
     129,   132,   255,   256,   295,   299,   301,   303,   304,   125,
     215,   120,   215,   120,   215,   120,   260,   382,   383,   125,
     289,   209,   257,   290,   292,   265,   193,   126,   268,   289,
     127,   269,   125,   226,   261,   262,   266,   129,   121,   239,
     244,   249,   354,   215,   132,   121,   132,   211,   121,   129,
     137,   264,   127,   196,   128,   129,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   270,   271,
     272,   285,   256,   294,   215,   215,   215,   166,   210,   289,
     212,   214,   227,   293,   266,   197,   289,   140,   140,   164,
     123,   164,   123,   123,   123,   123,   123,   123,   128,   272,
     273,   285,   265,   215,   290,   145,   146,   153,   159,   198,
     199,   274,   276,   277,   278,   279,   160,   161,   162,   282,
     283,   275,   167,   280,   264,   164,   123,   123,   123,   128,
     199,   164,   281,   281,   281,   281,     5,   294,   294,   294,
     124,   283,   281,   266,   200,   202,   201,   124,   164,   124,
     124,   124,   124,   216,   216,   216,   124,   132,   281,     5,
     281,   213,   124,   124,   124,   215
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
#line 232 "surface.yy"
    { YYACCEPT; ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 234 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 248 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 250 "surface.yy"
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
#line 258 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 260 "surface.yy"
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
#line 269 "surface.yy"
    {
			  cout << directoryManager.getCwd() << '\n';
			;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 272 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 274 "surface.yy"
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
#line 283 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 285 "surface.yy"
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
#line 295 "surface.yy"
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
#line 305 "surface.yy"
    { lexerStringMode(); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 307 "surface.yy"
    {
			  system((string("ls") + (yyvsp[(3) - (3)].yyString)).c_str());
			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 311 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 316 "surface.yy"
    {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 349 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (2)].yyToken)));
                        ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 353 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (2)].yyToken)));
                        ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 360 "surface.yy"
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
#line 368 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  moduleExpressions.push(new ModuleExpression(t));
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 378 "surface.yy"
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
#line 394 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[(1) - (1)].yyToken)));
                        ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 401 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 409 "surface.yy"
    { clear(); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 411 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, tokenSequence));
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 418 "surface.yy"
    {;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 421 "surface.yy"
    { store((yyvsp[(3) - (3)].yyToken)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 422 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 429 "surface.yy"
    {
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 434 "surface.yy"
    {
			  currentSyntaxContainer = oldSyntaxContainer;
			;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 449 "surface.yy"
    {
			  currentRenaming->addSortMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 453 "surface.yy"
    {
			  currentRenaming->addLabelMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 456 "surface.yy"
    { lexBubble(BAR_COLON | BAR_TO, 1); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 457 "surface.yy"
    { lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 458 "surface.yy"
    {;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 463 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 464 "surface.yy"
    {;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 465 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 471 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 472 "surface.yy"
    {;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 473 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 480 "surface.yy"
    { currentRenaming->setPrec((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 481 "surface.yy"
    { clear(); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 482 "surface.yy"
    { currentRenaming->setGather(tokenSequence); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 483 "surface.yy"
    { clear(); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 484 "surface.yy"
    { currentRenaming->setFormat(tokenSequence); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 485 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 486 "surface.yy"
    { currentRenaming->setLatexMacro((yyvsp[(4) - (5)].yyString)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 492 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 494 "surface.yy"
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
#line 502 "surface.yy"
    {
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 507 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  interpreter.insertView(((yyvsp[(3) - (12)].yyToken)).code(), CV);
			  CV->finishView();
			;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 520 "surface.yy"
    {
			  CV->addSortMapping((yyvsp[(2) - (4)].yyToken), (yyvsp[(4) - (4)].yyToken));
			;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 523 "surface.yy"
    {;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 524 "surface.yy"
    { lexBubble(BAR_COLON | BAR_TO, 1); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 529 "surface.yy"
    { (yyval.yyToken) = (yyvsp[(1) - (2)].yyToken); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 531 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  (yyval.yyToken) = t;
			;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 540 "surface.yy"
    {
			  //
			  //	Specific op->op mapping.
			  //
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpMapping(lexerBubble);
			;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 548 "surface.yy"
    {
			  lexBubble(END_STATEMENT, 1);
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 552 "surface.yy"
    {
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 557 "surface.yy"
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

  case 86:

/* Line 1455 of yacc.c  */
#line 567 "surface.yy"
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

  case 87:

/* Line 1455 of yacc.c  */
#line 589 "surface.yy"
    {;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 591 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  lexerBubble.append(t);
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 599 "surface.yy"
    { lexBubble(BAR_RIGHT_PAREN, 1); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 600 "surface.yy"
    {;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 606 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 608 "surface.yy"
    {
			  interpreter.setCurrentModule(new SyntacticPreModule((yyvsp[(1) - (3)].yyToken), (yyvsp[(3) - (3)].yyToken)));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule((yyvsp[(1) - (3)].yyToken), (yyvsp[(3) - (3)].yyToken));
			;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 614 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule((yyvsp[(8) - (8)].yyToken));
			;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 621 "surface.yy"
    {;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 623 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(t);
			  store(t);
			;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 631 "surface.yy"
    {;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 640 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter((yyvsp[(1) - (3)].yyToken), me);
			;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 647 "surface.yy"
    {;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 649 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			    ": saw " << QUOTE(':') << " instead of " <<
			    QUOTE("::") << " in parameter declaration.");
			;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 657 "surface.yy"
    {
			  singleton[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(singleton[0]);
			  currentSyntaxContainer->addType(false, singleton);
			  (yyval.yyToken) = (yyvsp[(1) - (1)].yyToken);  // needed for line number
			;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 666 "surface.yy"
    {;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 677 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport((yyvsp[(1) - (2)].yyToken), me);
			;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 683 "surface.yy"
    { clear(); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 684 "surface.yy"
    { CM->addSortDecl(tokenSequence); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 686 "surface.yy"
    { clear(); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 687 "surface.yy"
    { CM->addSubsortDecl(tokenSequence); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 689 "surface.yy"
    { lexBubble(BAR_COLON, 1); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 690 "surface.yy"
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 691 "surface.yy"
    {;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 693 "surface.yy"
    {;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 695 "surface.yy"
    {;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 697 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON, 1); ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 698 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 699 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 701 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON, 1);  ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 702 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 703 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 704 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 706 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_EQUALS, 1); ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 707 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 708 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 710 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_EQUALS, 1); ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 711 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 712 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 713 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 715 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_ARROW2, 1); ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 716 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 717 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 719 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_ARROW2, 1); ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 720 "surface.yy"
    { lexContinueBubble((yyvsp[(3) - (3)].yyToken), BAR_IF, 1); ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 721 "surface.yy"
    { lexContinueBubble((yyvsp[(5) - (5)].yyToken), END_STATEMENT, 1); ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 722 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 724 "surface.yy"
    { lexBubble(BAR_COLON, 1); ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 725 "surface.yy"
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 726 "surface.yy"
    { CM->setFlag(SymbolType::MESSAGE); ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 729 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 734 "surface.yy"
    {
			;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 737 "surface.yy"
    {
			;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 740 "surface.yy"
    { clear(); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 741 "surface.yy"
    { CM->addSubsortDecl(tokenSequence); ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 744 "surface.yy"
    {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeOpDeclsConsistent();
			;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 754 "surface.yy"
    {;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 755 "surface.yy"
    {;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 763 "surface.yy"
    {
			;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 767 "surface.yy"
    { currentSyntaxContainer->addVarDecl((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 768 "surface.yy"
    { currentSyntaxContainer->addVarDecl((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 775 "surface.yy"
    { singleton[0] = (yyvsp[(1) - (1)].yyToken); CM->addOpDecl(singleton); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 776 "surface.yy"
    { CM->addOpDecl(lexerBubble); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 782 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) <<
				       ": missing " << QUOTE("->") << " in constant declaration.");
			;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 790 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 795 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[(1) - (1)].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 802 "surface.yy"
    {
			  if ((yyvsp[(1) - (2)].yyBool))
			    CM->convertSortsToKinds();
			;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 809 "surface.yy"
    {;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 812 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 813 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 821 "surface.yy"
    {
			  singleton[0] = (yyvsp[(1) - (1)].yyToken);
			  currentSyntaxContainer->addType(false, singleton);
			;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 825 "surface.yy"
    { clear(); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 827 "surface.yy"
    {
			  currentSyntaxContainer->addType(true, tokenSequence);
			;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 832 "surface.yy"
    { store((yyvsp[(3) - (3)].yyToken)); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 833 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 836 "surface.yy"
    {;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 845 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 849 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 853 "surface.yy"
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 859 "surface.yy"
    {
			  CM->setFlag(SymbolType::ASSOC);
			;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 863 "surface.yy"
    {
			  CM->setFlag(SymbolType::COMM);
			;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 866 "surface.yy"
    { lexBubble(BAR_RIGHT_BRACKET | BAR_OP_ATTRIBUTE, 1); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 867 "surface.yy"
    { CM->setIdentity(lexerBubble); ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 869 "surface.yy"
    {
			  CM->setFlag(SymbolType::IDEM);
			;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 873 "surface.yy"
    {
			  CM->setFlag(SymbolType::ITER);
			;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 876 "surface.yy"
    { CM->setPrec((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 877 "surface.yy"
    { clear(); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 878 "surface.yy"
    { CM->setGather(tokenSequence); ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 879 "surface.yy"
    { clear(); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 880 "surface.yy"
    { CM->setFormat(tokenSequence); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 881 "surface.yy"
    { clear(); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 882 "surface.yy"
    { CM->setStrat(tokenSequence); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 883 "surface.yy"
    { clear(); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 884 "surface.yy"
    { CM->setPoly(tokenSequence); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 886 "surface.yy"
    {
			  CM->setFlag(SymbolType::MEMO);
			;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 890 "surface.yy"
    {
			  CM->setFlag(SymbolType::CTOR);
			;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 894 "surface.yy"
    {
			  clear();
			  CM->setFrozen(tokenSequence);
			;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 898 "surface.yy"
    { clear(); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 899 "surface.yy"
    { CM->setFrozen(tokenSequence); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 901 "surface.yy"
    {
			  CM->setFlag(SymbolType::CONFIG);
			;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 905 "surface.yy"
    {
			  CM->setFlag(SymbolType::OBJECT);
			;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 909 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 913 "surface.yy"
    {
			  CM->setMetadata((yyvsp[(2) - (2)].yyToken));
			;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 916 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 917 "surface.yy"
    { CM->setLatexMacro((yyvsp[(4) - (5)].yyString)); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 918 "surface.yy"
    {;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 920 "surface.yy"
    {
			  CM->setFlag(SymbolType::DITTO);
			;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 933 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 934 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 941 "surface.yy"
    { clear(); CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[(2) - (2)].yyToken), tokenSequence); ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 942 "surface.yy"
    { CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 943 "surface.yy"
    { CM->addHook(SyntacticPreModule::OP_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 944 "surface.yy"
    { CM->addHook(SyntacticPreModule::TERM_HOOK, (yyvsp[(2) - (3)].yyToken), lexerBubble); ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 950 "surface.yy"
    {;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 952 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing " <<
				       QUOTE("is") << " keyword.");
			;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 958 "surface.yy"
    {;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 960 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 968 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 972 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 973 "surface.yy"
    { store((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 974 "surface.yy"
    { store((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 975 "surface.yy"
    { store((yyvsp[(4) - (4)].yyToken)); ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 982 "surface.yy"
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

  case 235:

/* Line 1455 of yacc.c  */
#line 993 "surface.yy"
    { fragStore((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 994 "surface.yy"
    { fragStore((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 995 "surface.yy"
    { fragStore((yyvsp[(5) - (5)].yyToken)); ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 998 "surface.yy"
    { fragStore((yyvsp[(2) - (2)].yyToken)); ;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 999 "surface.yy"
    {;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1000 "surface.yy"
    {;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1080 "surface.yy"
    { lexBubble(END_COMMAND, 1) ;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1082 "surface.yy"
    {
			  interpreter.setCurrentModule(lexerBubble);
			;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1085 "surface.yy"
    { lexBubble(END_COMMAND, 1) ;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1087 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->dump();
			;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1092 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1097 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(lexerBubble);
			;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1104 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1109 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(lexerBubble);
			;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1116 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1121 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sreduce(lexerBubble);
			;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1128 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1133 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(lexerBubble, (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1140 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1146 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(lexerBubble, number, (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1152 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1159 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(lexerBubble, number, number2, (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1165 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1172 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(lexerBubble, number, number2, (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1178 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1184 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1190 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1197 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, (yyvsp[(1) - (3)].yySearchKind));
			;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1203 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1209 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(lexerBubble, (yyvsp[(1) - (3)].yyBool), number);
			;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1215 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1221 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.unify(lexerBubble, number);
			;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1227 "surface.yy"
    {
			  interpreter.cont((yyvsp[(3) - (4)].yyInt64), (yyvsp[(1) - (4)].yyBool));
			;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1231 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1236 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(lexerBubble);
			;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1242 "surface.yy"
    {
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(lexerBubble);
			;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1247 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1249 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1253 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1255 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1259 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1261 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1265 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1267 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal((yyvsp[(2) - (4)].yyBool));
			;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1272 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1279 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1281 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1285 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1287 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1291 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1293 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(true);
			;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1297 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1299 "surface.yy"
    {
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showView();
			;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1304 "surface.yy"
    {
			  interpreter.showModules(true);
			;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1308 "surface.yy"
    {
			  interpreter.showNamedViews();
			;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1311 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1313 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSortsAndSubsorts();
			;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1317 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1319 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showOps();
			;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1323 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1325 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showVars();
			;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1329 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1331 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showMbs();
			;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1335 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1337 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showEqs();
			;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1341 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1343 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showRls();
			;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1347 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1349 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSummary();
			;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1353 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1355 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showKinds();
			;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1360 "surface.yy"
    {
			  interpreter.showSearchPath((yyvsp[(3) - (4)].yyInt64));
			;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1364 "surface.yy"
    {
			  interpreter.showSearchPathLabels((yyvsp[(4) - (5)].yyInt64));
			;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1368 "surface.yy"
    {
			  interpreter.showSearchGraph();
			;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1371 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1373 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showProfile();
			;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 1381 "surface.yy"
    {
			  globalAdvisoryFlag = (yyvsp[(4) - (5)].yyBool);
			;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 1385 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1389 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, (yyvsp[(5) - (6)].yyBool));
			;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1393 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 1397 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 1401 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, (yyvsp[(5) - (6)].yyBool));
			;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1405 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1409 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1413 "surface.yy"
    {
			  interpreter.setPrintFlag((yyvsp[(3) - (5)].yyPrintFlags), (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 1417 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 1421 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE_NEWLINE, (yyvsp[(5) - (6)].yyBool));
			;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1425 "surface.yy"
    {
			  interpreter.setFlag((yyvsp[(3) - (5)].yyFlags), (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1429 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, (yyvsp[(3) - (4)].yyBool));
			;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1432 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1433 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1435 "surface.yy"
    {
			  interpreter.setAutoImport((yyvsp[(2) - (7)].yyImportMode), (yyvsp[(4) - (7)].yyToken), (yyvsp[(6) - (7)].yyBool));
			;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 1438 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 1439 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 1441 "surface.yy"
    {
			  interpreter.setOmodInclude((yyvsp[(5) - (8)].yyToken), (yyvsp[(7) - (8)].yyBool));
			;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 1445 "surface.yy"
    {
			  globalVerboseFlag = (yyvsp[(3) - (4)].yyBool);
			;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 1449 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 1453 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 1457 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 1461 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, (yyvsp[(3) - (4)].yyBool));
			;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 1465 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, (yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 1472 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 1476 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 1480 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 1484 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 1491 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[(4) - (5)].yyBool));
			;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 1495 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[(3) - (4)].yyBool));
			;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 1501 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 1508 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_MIXFIX; ;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 1509 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FLAT; ;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 1510 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_ALIASES; ;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 1511 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_PARENS; ;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 1512 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_GRAPH; ;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 1513 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_CONCEAL; ;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 1514 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_NUMBER; ;}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 1515 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_RAT; ;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 1516 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_COLOR; ;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 1517 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FORMAT; ;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 1520 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE; ;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 1521 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_CONDITION; ;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 1522 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_WHOLE; ;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 1523 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SUBSTITUTION; ;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 1524 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SELECT; ;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 1525 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_MB; ;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 1526 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_EQ; ;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 1527 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_RL; ;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 1528 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_REWRITE; ;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 1529 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BODY; ;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 1530 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BUILTIN; ;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 1533 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 1534 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 1537 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 1538 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 1541 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 1542 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 1545 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 1546 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 1551 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::NARROW; ;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 1552 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::XG_NARROW; ;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 1553 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::SEARCH; ;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 1556 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 1557 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 1560 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 1561 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 1564 "surface.yy"
    { (yyval.yyInt64) = (yyvsp[(1) - (1)].yyInt64); ;}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 1565 "surface.yy"
    { (yyval.yyInt64) = NONE; ;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 1568 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::PROTECTING; ;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 1569 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::EXTENDING; ;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 1570 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::INCLUDING; ;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 1580 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 1584 "surface.yy"
    { moduleExpr = lexerBubble; lexBubble(END_COMMAND, 1); ;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 1596 "surface.yy"
    { lexSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 1599 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0);  ;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 1604 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 1606 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 1612 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); ;}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 1614 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 1629 "surface.yy"
    { lexSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 1632 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 1641 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 1643 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 1645 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 1655 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); ;}
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 1657 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 1659 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 1669 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 1671 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 1682 "surface.yy"
    {
			  number = Token::codeToInt64(lexerBubble[1].code());
			  number2 = Token::codeToInt64(lexerBubble[3].code());
			  clear();
			;}
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 1688 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 1698 "surface.yy"
    { lexContinueSave((yyvsp[(1) - (1)].yyToken)); ;}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 1700 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 1710 "surface.yy"
    { number2 = Token::codeToInt64(lexerBubble[2].code()); ;}
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 1712 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0); ;}
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 1717 "surface.yy"
    { lexContinueBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 0, 1); ;}
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 1723 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), END_COMMAND, 1, 1); ;}
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 1725 "surface.yy"
    { lexBubble((yyvsp[(1) - (1)].yyToken), BAR_COLON | END_COMMAND, 0); ;}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 1728 "surface.yy"
    {
			  lexerBubble.resize(1);
			  lexerBubble[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(lexerBubble[0]);
			;}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 1767 "surface.yy"
    {;}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 1772 "surface.yy"
    {
			  singleton[0].dropChar((yyvsp[(1) - (1)].yyToken));
			  missingSpace(singleton[0]);
			  interpreter.addSelected(singleton);
			;}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 1783 "surface.yy"
    {
			  singleton[0] = (yyvsp[(1) - (1)].yyToken);
			  interpreter.addSelected(singleton);
			;}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 1788 "surface.yy"
    {
			  interpreter.addSelected(lexerBubble);
			;}
    break;



/* Line 1455 of yacc.c  */
#line 5871 "surface.c"
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
#line 1818 "surface.yy"


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

