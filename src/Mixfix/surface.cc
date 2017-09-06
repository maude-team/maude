/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 27 "surface.yy" /* yacc.c:339  */

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

#line 141 "surface.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "surface.h".  */
#ifndef YY_YY_SURFACE_H_INCLUDED
# define YY_YY_SURFACE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    KW_VU_NARROW = 360,
    KW_FVU_NARROW = 361,
    KW_ENDM = 362,
    KW_IMPORT = 363,
    KW_ENDV = 364,
    KW_SORT = 365,
    KW_SUBSORT = 366,
    KW_OP = 367,
    KW_OPS = 368,
    KW_MSGS = 369,
    KW_VAR = 370,
    KW_CLASS = 371,
    KW_SUBCLASS = 372,
    KW_MB = 373,
    KW_CMB = 374,
    KW_EQ = 375,
    KW_CEQ = 376,
    KW_RL = 377,
    KW_CRL = 378,
    KW_IS = 379,
    KW_FROM = 380,
    KW_ARROW = 381,
    KW_ARROW2 = 382,
    KW_PARTIAL = 383,
    KW_IF = 384,
    KW_LABEL = 385,
    KW_TO = 386,
    KW_COLON2 = 387,
    KW_ASSOC = 388,
    KW_COMM = 389,
    KW_ID = 390,
    KW_IDEM = 391,
    KW_ITER = 392,
    KW_LEFT = 393,
    KW_RIGHT = 394,
    KW_PREC = 395,
    KW_GATHER = 396,
    KW_METADATA = 397,
    KW_STRAT = 398,
    KW_POLY = 399,
    KW_MEMO = 400,
    KW_FROZEN = 401,
    KW_CTOR = 402,
    KW_LATEX = 403,
    KW_SPECIAL = 404,
    KW_CONFIG = 405,
    KW_OBJ = 406,
    KW_MSG = 407,
    KW_DITTO = 408,
    KW_FORMAT = 409,
    KW_ID_HOOK = 410,
    KW_OP_HOOK = 411,
    KW_TERM_HOOK = 412,
    KW_IN = 413,
    IDENTIFIER = 414,
    NUMERIC_ID = 415,
    ENDS_IN_DOT = 416,
    FORCE_LOOKAHEAD = 417
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 105 "surface.yy" /* yacc.c:355  */

  bool yyBool;
  Int64 yyInt64;
  const char* yyString;
  Token yyToken;
  ImportModule::ImportMode yyImportMode;
  Interpreter::Flags yyFlags;
  Interpreter::PrintFlags yyPrintFlags;
  Interpreter::SearchKind yySearchKind;

#line 355 "surface.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (UserLevelRewritingContext::ParseResult* parseResult);

#endif /* !YY_YY_SURFACE_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 116 "surface.yy" /* yacc.c:358  */

int yylex(YYSTYPE* lvalp);

#line 372 "surface.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  111
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2447

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  177
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  246
/* YYNRULES -- Number of rules.  */
#define YYNRULES  622
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  930

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   417

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     132,   133,   144,   143,   138,     2,   134,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   130,     2,
     135,   131,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   136,     2,   137,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   145,   139,   146,     2,     2,     2,     2,
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
     125,   126,   127,   128,   129,   140,   141,   142,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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
    1289,  1288,  1305,  1304,  1315,  1321,  1321,  1327,  1327,  1333,
    1333,  1339,  1339,  1345,  1353,  1353,  1359,  1359,  1365,  1365,
    1371,  1371,  1377,  1381,  1385,  1385,  1391,  1391,  1397,  1397,
    1403,  1403,  1409,  1409,  1415,  1415,  1421,  1421,  1427,  1427,
    1433,  1437,  1441,  1445,  1445,  1454,  1458,  1462,  1466,  1470,
    1474,  1478,  1482,  1486,  1490,  1494,  1498,  1502,  1506,  1507,
    1506,  1512,  1513,  1512,  1518,  1522,  1526,  1530,  1534,  1538,
    1545,  1549,  1553,  1557,  1564,  1568,  1575,  1575,  1582,  1583,
    1584,  1585,  1586,  1587,  1588,  1589,  1590,  1591,  1594,  1595,
    1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1607,
    1608,  1611,  1612,  1615,  1616,  1619,  1620,  1625,  1626,  1627,
    1628,  1629,  1630,  1633,  1634,  1637,  1638,  1641,  1642,  1645,
    1646,  1649,  1650,  1651,  1660,  1661,  1661,  1665,  1665,  1667,
    1677,  1677,  1679,  1680,  1680,  1685,  1685,  1687,  1687,  1689,
    1693,  1693,  1695,  1695,  1697,  1710,  1710,  1712,  1713,  1713,
    1722,  1722,  1724,  1724,  1726,  1726,  1728,  1736,  1736,  1738,
    1738,  1740,  1740,  1742,  1750,  1750,  1752,  1752,  1754,  1763,
    1762,  1769,  1769,  1771,  1779,  1779,  1781,  1781,  1783,  1791,
    1791,  1793,  1793,  1795,  1798,  1798,  1800,  1804,  1804,  1806,
    1806,  1808,  1819,  1819,  1819,  1819,  1819,  1819,  1819,  1822,
    1822,  1822,  1822,  1822,  1822,  1826,  1826,  1826,  1826,  1826,
    1826,  1830,  1830,  1830,  1830,  1830,  1830,  1834,  1834,  1834,
    1834,  1834,  1838,  1838,  1838,  1838,  1838,  1844,  1845,  1848,
    1849,  1852,  1859,  1860,  1863,  1868,  1875,  1875,  1875,  1875,
    1875,  1875,  1875
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "KW_LOAD", "KW_QUIT", "KW_EOF", "KW_TEST", "KW_SMT_SEARCH",
  "KW_VU_NARROW", "KW_FVU_NARROW", "KW_ENDM", "KW_IMPORT", "KW_ENDV",
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
  "$@91", "$@92", "$@93", "$@94", "$@95", "$@96", "$@97", "$@98", "$@99",
  "printOption", "traceOption", "polarity", "select", "exclude", "conceal",
  "search", "match", "optDebug", "optIrredundant", "optNumber",
  "importMode", "moduleAndTerm", "$@100", "inEnd", "$@101",
  "numberModuleTerm", "$@102", "$@103", "numberModuleTerm1", "$@104",
  "$@105", "numberModuleTerm2", "$@106", "$@107", "numbersModuleTerm",
  "$@108", "$@109", "numbersModuleTerm1", "$@110", "$@111", "$@112",
  "numbersModuleTerm2", "$@113", "$@114", "$@115", "numbersModuleTerm3",
  "$@116", "$@117", "numbersModuleTerm4", "$@118", "$@119",
  "numbersModuleTerm5", "$@120", "$@121", "numbersModuleTerm6", "$@122",
  "$@123", "miscEndBubble", "$@124", "initialEndBubble", "$@125", "$@126",
  "cTokenBarIn", "cTokenBarLeftIn", "cTokenBarDotNumber",
  "cTokenBarDotRight", "cTokenBarDotCommaNumber", "cTokenBarDotCommaRight",
  "opSelect", "endSelect", "badSelect", "cOpNameList", "cSimpleOpName",
  "cSimpleTokenBarDot", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
      58,    61,    40,    41,    46,    60,    91,    93,    44,   124,
     385,   386,   387,    43,    42,   123,   125,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417
};
# endif

#define YYPACT_NINF -740

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-740)))

#define YYTABLE_NINF -497

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     765,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,    28,   549,    85,  -740,   259,   324,   -25,  -740,   -80,
     -37,    -7,     4,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,   109,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,   488,    39,  1080,   496,
     496,   512,   496,    71,   205,   383,    -1,   141,   350,   350,
     350,   -40,  -740,  -740,  -740,    34,   350,  -740,  -740,  -740,
     136,   -58,  -740,    53,    76,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,   -82,  -740,  -740,  -740,  -740,    74,  -740,  -740,  -740,
    -740,   496,   496,   -82,   209,   239,   241,   246,   496,   120,
     265,  -740,  1080,   512,  -740,  -740,  -740,  -740,   193,   260,
    -740,  -740,  -740,   191,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,   155,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   345,
     350,   350,   350,   350,   350,   350,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,   350,  -740,  -740,  -740,
      36,   354,  -740,  -740,  -740,  -740,  -740,   350,   350,  -740,
    -740,   162,   165,   167,   350,   350,   350,   350,   171,   204,
     -82,   -82,   173,   175,   217,   -82,  -740,  -740,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   304,   304,
    -740,  -740,  -740,   304,   304,   179,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   496,   512,
    -740,   294,  -740,   521,   521,   512,  -740,   184,   521,   804,
     -82,   -81,   -82,   543,   -82,   204,   350,   350,   187,   199,
     214,   219,   233,   236,   252,   350,   269,  -740,  -740,   273,
     274,  -740,  -740,  -740,   276,   279,   280,   281,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,   286,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  2149,  -740,  -740,
    -740,  -740,  -740,  -740,   180,  -740,  -740,  -740,   512,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,   804,   200,   207,
     230,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,   290,   293,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,   296,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,   350,  -740,  -740,  -740,  -740,  -740,  1080,   307,   512,
    -740,  2158,   -82,    -8,   804,   287,   300,  -740,   -82,   -82,
    2167,   -82,   350,  -740,  -740,  -740,   310,    12,  -740,   -72,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,   804,  -740,  -740,  1080,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,   311,  -740,  1080,  -740,  -740,  -740,   804,
     424,  2176,  2222,   -82,   200,    19,   101,  -740,   496,   -82,
    -740,  -740,   200,   316,  -740,   873,  -740,  -740,  -740,  1149,
    1149,  1356,  1080,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,   307,  -740,  2107,
    -740,  1080,  -740,   314,  -740,  1080,  -740,  -740,  -740,  -740,
     319,    79,   186,    82,  -740,   312,    40,   159,   212,   320,
     322,   220,   229,   240,   245,  -740,  2107,   327,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,   942,  -740,  -740,  -740,
    -740,  -740,  1011,  1218,  -740,  -740,  2107,   329,   330,   332,
     333,   334,   338,   339,  2231,   -82,   496,  2240,   -82,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
     342,   323,  -740,  -740,  -740,   340,   343,   341,   -32,  -740,
     873,  -740,  -740,  -740,  -740,  -740,  -740,  1632,  1563,  -740,
    -740,  1425,  -740,  1425,   347,  -740,   336,  1563,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,    24,  2107,  -740,  -740,
     344,  1080,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  1425,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  1701,  -740,  -740,  -740,  -740,  1701,  1839,   337,
    -740,   -82,   351,   -82,   361,   -82,   362,  1425,   496,   -82,
    2249,   -82,   358,  -740,  2107,  -740,  1356,  -740,  -740,  2107,
    -740,  -740,  -740,  1973,  -740,  2107,  -740,  -740,   357,  1494,
    -740,  -740,   320,  -740,  -740,   359,  -740,   365,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   360,   -55,
    1287,   323,   105,  1906,   368,  -740,   268,  -740,   725,   320,
    -740,  -740,  -740,   -65,  -740,  -740,  -740,  1839,  1080,   -82,
     -82,   -82,   496,   -82,  1770,  -740,  -740,  -740,   347,  -740,
    -740,  2040,  -740,  -740,  -740,  2107,  -740,  -740,  -740,  -740,
    -740,   349,   356,   346,   374,   348,   377,   384,  -740,   385,
    -740,   388,   392,  -740,  -740,  -740,  -740,   394,  2279,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,   320,  -740,   -82,  1701,  2107,  -740,    14,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   222,
    -740,  -740,  -740,   372,  -740,  1906,  -740,  -740,   323,   376,
     401,   418,   419,   190,  -740,   379,   379,   379,   379,   551,
    1080,  1080,  1080,    -5,  -740,   379,  -740,  -740,  2040,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,   -89,   -74,   -68,   -62,
     421,   426,   426,   426,  -740,  -740,   -20,   420,   379,   557,
     379,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,   -18,   430,   -10,   -82,  -740,  -740,  -740,  -740
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   456,   108,   109,    69,   351,   382,   494,   493,   373,
     367,     0,     0,     0,   347,     0,     0,     0,   495,     0,
       0,     0,     0,   353,   355,   349,    12,    13,    15,    17,
      18,    10,    20,    21,   380,    91,     8,     0,     2,     6,
       5,   384,     4,    93,     7,   371,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   468,     0,     0,     0,     0,
       0,     0,   501,   502,   503,     0,     0,   438,   394,   400,
       0,     0,   396,     0,     0,   398,   404,   406,   408,   410,
     412,   414,   416,   418,   423,   481,   482,   484,   483,   385,
     387,     0,   485,   486,   391,   389,     0,   450,   451,   452,
     453,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,   357,   359,   487,   488,   498,     0,
     361,   363,   365,   500,   489,   490,   491,   492,   369,   457,
     311,   296,   312,   297,   298,   299,   300,   302,   301,   303,
     304,   305,   306,   307,   308,   309,   310,   289,   288,   315,
     318,   316,   319,   314,   317,   249,   313,   320,   321,   292,
     285,   287,   293,   286,   283,   284,   281,   282,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   339,   332,   333,
     334,   338,   335,   336,   337,   340,   341,   294,   342,   343,
     344,   345,   346,   280,   291,     0,   290,   245,   246,   295,
     247,   248,   322,   576,   567,   577,   574,   575,   578,   569,
     572,   573,   571,   352,   504,   505,   383,   582,   583,   510,
     581,   584,   579,   580,   374,   512,   513,   368,   441,     0,
       0,     0,     0,     0,     0,     0,   476,   477,   478,   470,
     472,   469,   471,   473,   474,   475,     0,   462,   458,   459,
       0,     0,   463,   464,   465,   466,   467,     0,     0,   479,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   403,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,   348,     0,     0,     0,   354,   356,   350,    14,
      16,    19,    11,   381,    92,     9,    94,   372,     0,     0,
     497,     0,   375,     0,     0,     0,   499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   461,   460,     0,
       0,   455,   437,   444,     0,     0,     0,     0,   448,   621,
     618,   619,   622,   620,   616,   617,   439,   395,   401,   422,
     420,     0,   397,   399,   405,   407,   409,   411,   413,   415,
     417,   419,   424,   611,   615,   386,   608,     0,   613,   614,
     388,   392,   390,   393,    99,   358,   360,   377,     0,   525,
     362,   527,   528,   364,   366,   379,   370,     0,    70,    29,
      31,    32,    34,    33,    35,   568,   507,   509,   570,   506,
     589,   564,   586,   587,   590,   588,   585,   515,   566,   511,
     519,   517,   514,   442,     0,     0,   432,   426,   428,   431,
     429,   425,   436,     0,   434,   433,   454,   446,   449,   445,
     447,     0,   421,   609,   607,   610,   612,     0,   229,     0,
     376,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,   427,   430,   435,     0,     0,   101,     0,
     228,   111,   378,   601,   598,   599,   532,   600,   597,   530,
     526,   536,   534,   529,    39,    30,     0,    42,    36,     0,
     508,   565,   595,   593,   520,   596,   594,   591,   592,   516,
     524,   522,   518,     0,   440,     0,    98,   104,   103,     0,
       0,     0,     0,     0,    71,     0,     0,    41,     0,     0,
     443,   100,   102,     0,    95,     0,   113,   115,   117,     0,
       0,     0,     0,   149,   122,   125,   129,   132,   136,   139,
     143,   110,   554,   533,   558,   556,   606,   604,   537,   539,
     605,   602,   603,   531,   543,   541,   535,   229,    46,     0,
      51,     0,    43,    45,    48,     0,    38,   521,   523,   151,
     249,   251,   252,    28,   112,     0,   231,   231,   231,   231,
       0,   250,   253,   254,   255,   233,     0,     0,   261,   264,
     262,   265,   263,   259,   260,   162,     0,   160,   161,   256,
     257,   258,     0,     0,   158,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
     275,   273,   274,   269,   270,   276,   277,   271,   272,   266,
       0,   238,   239,   267,   268,    56,     0,     0,     0,    40,
       0,   230,    25,    26,    24,    22,    23,     0,     0,   236,
     118,     0,   159,     0,    76,   157,     0,     0,   123,   126,
     130,   133,   137,   140,   144,   559,   555,   563,   561,   557,
     538,   544,   540,   548,   546,   542,     0,     0,   240,    54,
       0,     0,    44,    47,    27,    30,    96,    97,   114,   232,
     235,   116,   234,   233,     0,   174,   175,   179,   105,   165,
     120,   164,     0,   177,   178,   146,    75,     0,   152,     0,
     150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,    79,     0,    73,    49,     0,
     177,    52,    50,     0,   119,     0,   173,   171,   184,   167,
     107,   121,   231,   251,   252,   153,   154,     0,   250,   253,
     254,   255,   148,   124,   127,   131,   134,   138,   141,   145,
     560,   562,   549,   545,   553,   551,   547,    81,     0,     0,
       0,   244,     0,     0,    59,   237,     0,   182,     0,   231,
     166,   169,   170,     0,   163,   176,   106,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    87,    80,    76,   242,
     241,     0,    57,    53,   180,     0,   190,   191,   187,   194,
     195,     0,     0,     0,     0,     0,     0,     0,   205,   207,
     206,     0,     0,   210,   211,   212,   217,     0,     0,   192,
     186,   172,   168,   155,   156,   128,   135,   142,   550,   552,
      83,    77,   231,   177,     0,     0,     0,    55,     0,   181,
     188,   189,   196,   197,   213,   201,   203,   208,   214,     0,
     199,   183,   185,   219,    82,     0,    88,    78,   243,     0,
       0,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,     0,   218,   193,     0,    62,
      63,    67,    65,    58,    60,   221,     0,     0,     0,     0,
       0,   224,     0,     0,   216,   222,     0,     0,     0,     0,
       0,   198,   220,   202,   204,   209,   215,   225,   226,   227,
     200,    85,     0,     0,     0,     0,    64,    68,    66,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   -76,
    -369,  -740,  -740,  -496,  -493,  -740,  -492,  -740,  -740,  -740,
    -740,  -740,  -740,   -73,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -307,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -231,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   -90,     0,
    -740,  -740,  -740,  -740,  -486,  -740,  -740,    63,  -740,  -688,
    -276,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -216,
    -154,    43,  -329,  -607,  -740,  -740,  -209,  -740,  -739,  -692,
    -553,  -740,  -740,  -740,  -740,  -740,  -253,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -594,  -740,  -306,    21,  -570,
    -114,   -26,  -740,  -298,  -726,  -740,  -740,  -740,   -38,  -681,
    -515,  -740,  -740,  -510,  -507,   -43,  -740,  -508,  -388,  -407,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,   -29,   565,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,   -46,  -740,  -740,  -740,  -102,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -202,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -439,
    -740,   -49,  -740,  -740,  -740,   -24,  -472,  -596,  -740,  -740,
      30,  -740,   206,  -740,   208,  -221
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    37,    38,    39,   110,   107,   104,   105,   106,   574,
     398,   399,   400,   401,   402,   489,   403,   516,   488,   515,
     637,   562,   563,   564,   635,   774,   680,   730,   803,   848,
     873,   874,   908,   910,   909,    40,    48,   455,   557,   676,
     707,   727,   769,   841,   797,   843,   925,   844,   418,   374,
     109,    42,   112,   384,   688,   448,   467,   468,   509,   699,
     741,    43,   510,   541,   585,   586,   587,   694,   607,   711,
     608,   712,   789,   609,   713,   610,   714,   790,   611,   715,
     612,   716,   791,   613,   717,   656,   606,   709,   745,   746,
     603,   596,   597,   700,   783,   784,   701,   737,   702,   739,
     703,   735,   776,   779,   828,   829,   830,   863,   875,   885,
     876,   877,   878,   879,   887,   896,   883,   884,   471,   642,
     647,   648,   693,   704,   631,   729,   772,   846,   404,   579,
     598,   632,   580,   196,   197,   633,   199,   200,   201,   202,
      44,    91,   103,    49,   101,   102,   308,   309,   313,   314,
     315,    52,   318,   113,    51,   388,   449,   108,    50,   288,
     289,   294,   293,   270,   275,   278,   271,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   269,   441,   325,   462,
      47,   257,   246,   261,    89,    90,    94,   128,    45,    46,
     311,   317,    67,   213,   322,   408,   458,   224,   323,   324,
     419,   460,   461,   499,   518,   519,   390,   451,   452,   480,
     512,   511,   513,   553,   616,   617,   618,   672,   720,   721,
     763,   792,   793,   543,   614,   615,   666,   718,   719,   420,
     459,   214,   320,   321,   215,   226,   421,   501,   482,   555,
     375,   444,   376,   377,   378,   379
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,   292,   225,   771,   216,   198,   227,   643,   644,   645,
     195,   307,   481,   298,   736,   581,   604,   583,   668,   740,
     558,   500,   599,   599,   599,   722,   264,   747,   453,   576,
     262,   263,   577,   578,   801,    53,   273,   268,   773,   545,
     247,   248,   249,   250,   911,   251,   705,    96,   356,   406,
     265,   782,   290,   290,    97,   296,   297,    54,   507,   913,
      55,   695,   303,   696,   225,   914,   259,   260,    56,   198,
     508,   915,   544,   554,   306,   795,   252,    57,   559,    58,
     560,   335,   274,    59,   912,   485,   796,   734,   655,   599,
     253,   254,   255,   291,   291,   599,   599,    98,    60,   912,
      61,    62,    63,    64,   423,   912,   747,    65,   561,   111,
     759,   912,   393,   920,   267,   926,   396,   514,    66,   266,
     868,    85,    86,   928,   765,   484,   888,    99,   904,   559,
     581,   560,   583,   723,   724,   454,   725,   584,   100,   726,
     522,   601,   601,   601,   576,   674,   228,   577,   578,   738,
     505,   865,   634,   912,   742,   912,   575,   740,   506,   561,
      87,    88,   691,   912,   880,   881,   882,   256,   869,   870,
     258,   710,   786,   129,   641,   667,   871,   272,   673,   634,
     357,   358,   872,   -32,   -32,   362,   785,   276,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   748,   634,
     750,   328,   329,   330,   331,   332,   333,   386,   601,   831,
     277,   604,   299,   394,   601,   601,  -279,   334,   229,   599,
     785,   336,  -292,  -292,  -292,  -291,  -291,  -291,   339,   340,
     405,   407,   409,   295,   422,   344,   345,   346,   347,   565,
     634,   634,   300,   799,   634,   301,   634,   566,   847,   302,
     634,   800,   584,   304,   230,   655,   231,   232,   233,   234,
     225,   630,   385,   599,   391,   391,   225,   652,   305,   391,
     634,   685,   864,   652,   235,   310,   198,   748,   312,   750,
     319,   764,   897,   898,   899,   316,   450,   634,   649,   392,
     392,   906,   742,   641,   392,   634,   341,   424,   425,   342,
     634,   343,   -34,   -34,   -34,   348,   433,   359,   649,   360,
     634,   361,   785,   383,   922,   387,   924,   634,   395,   380,
     751,   426,   634,   381,   382,   447,   634,   893,   634,  -293,
    -293,  -293,   634,   427,   349,   907,    92,    93,   601,   225,
     350,   351,   352,   454,   869,   870,   641,   472,   428,   689,
     692,   456,   871,   429,   198,   -33,   -33,   -33,   872,   692,
      85,    86,   483,  -290,  -290,  -290,   634,   430,   490,   491,
     431,   502,  -246,  -246,  -246,   457,   353,   354,   355,   728,
     259,   260,   601,  -247,  -247,  -247,   432,   634,  -248,  -248,
    -248,   880,   881,   882,   634,   236,   326,   327,   634,   751,
     225,   337,   338,   434,   198,   804,   805,   435,   436,   469,
     437,   198,   466,   438,   439,   440,   237,   238,   239,   240,
     442,   241,   242,   556,   463,   523,   768,   464,   486,   568,
     465,   470,   487,   503,   349,   689,    35,   777,   634,   634,
     350,   351,   352,   198,   504,   520,   198,   243,   244,   245,
     569,   517,   638,  -278,   641,   640,   646,   650,   634,   658,
     659,   662,   198,   660,   661,   663,   198,   469,   678,   664,
     679,   752,   567,   706,   682,   708,   353,   354,   355,   373,
     754,   634,   582,   677,   681,   731,   600,   600,   600,   198,
     756,   758,   767,   778,   605,   788,   842,   787,   850,   114,
     115,   794,   116,   117,   802,   851,   853,   849,   118,   855,
     119,   120,   121,   122,   123,   124,   856,   857,   198,   852,
     858,   854,   198,   636,   859,   669,   860,   639,   675,   595,
     595,   524,   525,   890,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   886,   889,
     891,   892,   895,   600,   916,    68,   900,    69,    35,   600,
     600,   921,   923,   927,   684,   683,   894,   845,   521,   867,
     670,   833,   770,   602,   832,   862,    70,   905,   619,   733,
     657,    95,     0,   445,     0,   446,     0,     0,     0,     0,
     540,     0,   125,   126,   127,     0,   595,   582,     0,     0,
       0,     0,   595,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
       0,   753,     0,   755,     0,   757,   203,     0,   204,   761,
     205,   766,   206,   207,   208,     0,     0,     0,   198,    84,
       0,     0,   217,   732,   204,     0,   218,     0,   219,   220,
     221,   217,     0,   204,     0,   218,     0,   389,   220,   221,
       0,     0,     0,     0,     0,   749,     0,     0,   209,   210,
     211,   212,   760,   410,     0,   411,     0,   290,     0,   412,
     413,   414,     0,   600,   209,   222,   223,   212,     0,     0,
       0,     0,     0,   209,   222,   223,   212,     0,     0,   835,
     836,   837,     0,   839,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   415,   416,   417,   291,     0,
       0,     0,     0,     0,     0,     0,     0,   600,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   749,   198,   838,     0,     0,     0,
     834,     0,     0,     0,   866,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -3,     1,     0,     0,     0,
       0,     2,     3,     4,     5,     0,  -496,  -496,     6,  -496,
    -496,     7,     8,     9,    10,  -496,     0,  -496,  -496,  -496,
    -496,  -496,  -496,    11,    12,     0,     0,    13,     0,     0,
       0,    14,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   929,    17,   198,   198,   198,
       0,     0,   901,   902,   903,     0,    18,     0,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,  -496,
    -496,  -496,   806,   807,   808,   809,   810,   811,   812,   813,
     814,   815,   816,   817,   818,   819,   820,   821,   822,   823,
     824,   825,   826,   827,     0,     0,     0,    35,     0,     0,
       0,   917,   918,   919,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   397,    36,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,     0,   194,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   397,     0,   570,   156,   157,
     158,   571,   160,   161,   572,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,     0,   573,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   588,   589,
     590,   591,   651,   592,    35,     0,   593,   594,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,     0,   194,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   588,   589,   590,
     591,   653,   592,    35,     0,   593,   594,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,     0,   194,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,     0,   194,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   588,   589,   590,   591,     0,
     592,    35,     0,   593,   594,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,     0,   194,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   588,   589,   590,   591,   654,   592,
       0,     0,   593,   594,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,     0,   194,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   588,   589,   590,   591,   798,   592,     0,
       0,   593,   594,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,     0,   194,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   588,   589,   590,   591,     0,   592,     0,     0,
     593,   594,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
       0,   194,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   620,
       0,   695,   621,   696,   622,     0,   623,     0,     0,     0,
       0,   697,     0,     0,   624,   625,   626,     0,   627,   628,
       0,     0,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   629,     0,
     698,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   620,     0,
       0,   621,     0,   622,   780,   623,     0,     0,   781,     0,
     697,     0,     0,   624,   625,   626,     0,   627,   628,     0,
       0,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   629,     0,   698,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   620,     0,     0,
     621,     0,   622,     0,   623,     0,     0,   686,   690,     0,
       0,     0,   624,   625,   626,     0,   627,   628,     0,     0,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   629,     0,   687,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   620,     0,     0,   621,
       0,   622,     0,   623,     0,     0,   686,     0,     0,     0,
       0,   624,   625,   626,     0,   627,   628,     0,     0,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   629,     0,   687,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   620,     0,     0,   621,     0,
     622,     0,   623,     0,     0,     0,     0,   697,     0,     0,
     624,   625,   626,     0,   627,   628,     0,     0,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   629,     0,   698,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   620,     0,     0,   621,     0,   622,
       0,   623,     0,     0,     0,     0,     0,     0,     0,   624,
     625,   626,     0,   627,   628,     0,     0,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   629,     0,   840,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,   156,   157,   158,   743,   160,   161,
     744,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     620,     0,   695,   621,   696,   622,     0,   623,     0,     0,
       0,     0,   697,     0,     0,   624,   625,   626,     0,   627,
     628,     0,     0,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   629,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   620,     0,     0,
     621,     0,   622,     0,   623,     0,     0,     0,   775,     0,
       0,     0,   624,   625,   626,     0,   627,   628,     0,     0,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   629,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   620,     0,     0,   621,     0,   622,
       0,   623,     0,     0,     0,     0,   697,     0,     0,   624,
     625,   626,     0,   627,   628,     0,     0,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   629,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   620,     0,     0,   621,     0,   622,     0,   623,     0,
       0,     0,     0,     0,     0,     0,   624,   625,   626,     0,
     627,   628,     0,     0,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   349,
     629,    35,     0,   443,     0,   350,   351,   352,   473,     0,
     411,     0,   290,     0,   474,   475,   476,   492,     0,   411,
       0,   290,     0,   493,   494,   495,   410,     0,   411,     0,
     290,     0,   412,   413,   414,     0,     0,     0,     0,     0,
       0,   353,   354,   355,   373,     0,     0,     0,     0,     0,
     477,   478,   479,   291,     0,     0,     0,     0,     0,   496,
     497,   498,   291,     0,     0,     0,     0,     0,   415,   416,
     542,   291,   546,     0,   411,     0,   290,     0,   547,   548,
     549,   492,     0,   411,     0,   290,     0,   493,   665,   495,
     410,     0,   411,     0,   290,     0,   412,   413,   414,   492,
       0,   411,     0,   290,     0,   493,   762,   495,     0,     0,
       0,     0,     0,     0,   550,   551,   552,   291,     0,     0,
       0,     0,     0,   496,   497,   498,   291,     0,     0,     0,
       0,     0,   415,   416,   671,   291,   861,     0,     0,     0,
       0,   496,   497,   498,   291,     0,   806,   807,   808,   809,
     810,   811,   812,   813,   814,   815,   816,   817,   818,   819,
     820,   821,   822,   823,   824,   825,   826,   827
};

static const yytype_int16 yycheck[] =
{
       0,    91,    51,   729,    50,    48,    52,   577,   578,   579,
      48,   113,   451,   103,   702,   525,   531,   525,   614,   707,
       1,   460,   529,   530,   531,     1,    66,   708,   397,   525,
      59,    60,   525,   525,   773,     7,    94,    66,   730,   511,
      41,    42,    43,    44,   133,    46,   653,    72,   269,   130,
      90,   739,   134,   134,   134,   101,   102,    29,   130,   133,
      32,   126,   108,   128,   113,   133,    30,    31,    40,   112,
     142,   133,   511,   512,   112,   130,    77,    49,   110,    51,
     112,    45,   140,    55,   173,   454,   141,   694,   603,   596,
      91,    92,    93,   175,   175,   602,   603,   134,    70,   173,
      72,    73,    74,    75,   325,   173,   787,    79,   140,     0,
     717,   173,   314,   133,    80,   133,   318,   486,    90,   159,
     846,    36,    37,   133,   720,   133,   865,   134,   133,   110,
     640,   112,   640,   109,   110,   143,   112,   525,   134,   115,
     509,   529,   530,   531,   640,   617,    75,   640,   640,   702,
     138,   843,   559,   173,   707,   173,   525,   845,   146,   140,
      75,    76,   648,   173,   169,   170,   171,   168,   154,   155,
      29,   657,   742,   134,   134,   614,   162,    41,   617,   586,
     270,   271,   168,   143,   144,   275,   739,   134,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   708,   606,
     708,   230,   231,   232,   233,   234,   235,   309,   596,   779,
     134,   726,     3,   315,   602,   603,   134,   246,    13,   726,
     773,   250,   143,   144,   145,   143,   144,   145,   257,   258,
     320,   321,   322,   159,   324,   264,   265,   266,   267,   138,
     647,   648,     3,   138,   651,     4,   653,   146,   801,     3,
     657,   146,   640,   133,    49,   770,    51,    52,    53,    54,
     309,   559,   308,   770,   313,   314,   315,   596,     3,   318,
     677,   640,   842,   602,    69,    82,   319,   787,    18,   787,
     125,   720,   876,   877,   878,    94,   388,   694,   586,   313,
     314,   885,   845,   134,   318,   702,   134,   326,   327,   134,
     707,   134,   143,   144,   145,   134,   335,   134,   606,   134,
     717,    94,   865,   134,   908,    21,   910,   724,   134,   289,
     708,   134,   729,   293,   294,   145,   733,   137,   735,   143,
     144,   145,   739,   134,   130,   888,    77,    78,   726,   388,
     136,   137,   138,   143,   154,   155,   134,   449,   134,   647,
     648,   144,   162,   134,   397,   143,   144,   145,   168,   657,
      36,    37,   452,   143,   144,   145,   773,   134,   458,   459,
     134,   461,   143,   144,   145,   145,   172,   173,   174,   677,
      30,    31,   770,   143,   144,   145,   134,   794,   143,   144,
     145,   169,   170,   171,   801,    12,    51,    52,   805,   787,
     449,    47,    48,   134,   447,   137,   138,   134,   134,   447,
     134,   454,   441,   134,   134,   134,    33,    34,    35,    36,
     134,    38,    39,   513,   134,     1,   724,   134,   141,   519,
     134,   124,   132,   462,   130,   733,   132,   735,   845,   846,
     136,   137,   138,   486,   134,   134,   489,    64,    65,    66,
     134,   489,   138,   134,   134,   143,   134,   130,   865,   130,
     130,   127,   505,   131,   131,   127,   509,   505,   145,   130,
     130,   134,   518,   126,   133,   139,   172,   173,   174,   175,
     129,   888,   525,   141,   141,   141,   529,   530,   531,   532,
     129,   129,   134,   136,   532,   130,   794,   138,   149,    11,
      12,   141,    14,    15,   136,   149,   132,   805,    20,   132,
      22,    23,    24,    25,    26,    27,   132,   132,   561,   173,
     132,   173,   565,   561,   132,   615,   132,   565,   618,   529,
     530,   107,   108,   132,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   176,   173,
     132,   132,   173,   596,   133,     6,     5,     8,   132,   602,
     603,   141,     5,   133,   640,   638,   873,   798,   505,   845,
     616,   787,   726,   530,   783,   828,    27,   883,   557,   693,
     606,    16,    -1,   377,    -1,   377,    -1,    -1,    -1,    -1,
     166,    -1,   104,   105,   106,    -1,   596,   640,    -1,    -1,
      -1,    -1,   602,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,   711,    -1,   713,    -1,   715,   130,    -1,   132,   719,
     134,   721,   136,   137,   138,    -1,    -1,    -1,   681,    90,
      -1,    -1,   130,   681,   132,    -1,   134,    -1,   136,   137,
     138,   130,    -1,   132,    -1,   134,    -1,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,   708,    -1,    -1,   172,   173,
     174,   175,   718,   130,    -1,   132,    -1,   134,    -1,   136,
     137,   138,    -1,   726,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,   789,
     790,   791,    -1,   793,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   770,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   787,   788,   792,    -1,    -1,    -1,
     788,    -1,    -1,    -1,   844,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   925,    71,   880,   881,   882,
      -1,    -1,   880,   881,   882,    -1,    81,    -1,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,   132,    -1,    -1,
      -1,   901,   902,   903,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   172,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,   173,    -1,   175,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,   175,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    -1,
     131,   132,    -1,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,   173,    -1,   175,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
     173,    -1,   175,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    -1,   131,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,   175,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
      -1,   136,    -1,    -1,   139,   140,   141,    -1,   143,   144,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,   173,    -1,
     175,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,   127,    -1,   129,   130,   131,    -1,    -1,   134,    -1,
     136,    -1,    -1,   139,   140,   141,    -1,   143,   144,    -1,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
     127,    -1,   129,    -1,   131,    -1,    -1,   134,   135,    -1,
      -1,    -1,   139,   140,   141,    -1,   143,   144,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,   173,    -1,   175,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,   127,
      -1,   129,    -1,   131,    -1,    -1,   134,    -1,    -1,    -1,
      -1,   139,   140,   141,    -1,   143,   144,    -1,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,   127,    -1,
     129,    -1,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,
     139,   140,   141,    -1,   143,   144,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,   175,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,   127,    -1,   129,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,   143,   144,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,   173,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,   139,   140,   141,    -1,   143,
     144,    -1,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
     127,    -1,   129,    -1,   131,    -1,    -1,    -1,   135,    -1,
      -1,    -1,   139,   140,   141,    -1,   143,   144,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,   173,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,   127,    -1,   129,
      -1,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,   139,
     140,   141,    -1,   143,   144,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,   127,    -1,   129,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,
     143,   144,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   130,
     173,   132,    -1,   134,    -1,   136,   137,   138,   130,    -1,
     132,    -1,   134,    -1,   136,   137,   138,   130,    -1,   132,
      -1,   134,    -1,   136,   137,   138,   130,    -1,   132,    -1,
     134,    -1,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,   130,    -1,   132,    -1,   134,    -1,   136,   137,
     138,   130,    -1,   132,    -1,   134,    -1,   136,   137,   138,
     130,    -1,   132,    -1,   134,    -1,   136,   137,   138,   130,
      -1,   132,    -1,   134,    -1,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,    -1,   172,   173,   174,   175,   137,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    16,    17,    18,
      19,    28,    29,    32,    36,    40,    55,    71,    81,    83,
      84,    85,    86,    87,    88,    89,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   132,   172,   178,   179,   180,
     212,   226,   228,   238,   317,   365,   366,   357,   213,   320,
     335,   331,   328,     7,    29,    32,    40,    49,    51,    55,
      70,    72,    73,    74,    75,    79,    90,   369,     6,     8,
      27,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    90,    36,    37,    75,    76,   361,
     362,   318,    77,    78,   363,   361,    72,   134,   134,   134,
     134,   321,   322,   319,   183,   184,   185,   182,   334,   227,
     181,     0,   229,   330,    11,    12,    14,    15,    20,    22,
      23,    24,    25,    26,    27,   104,   105,   106,   364,   134,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   173,   175,   305,   310,   311,   312,   313,
     314,   315,   316,   130,   132,   134,   136,   137,   138,   172,
     173,   174,   175,   370,   408,   411,   370,   130,   134,   136,
     137,   138,   173,   174,   374,   408,   412,   370,    75,    13,
      49,    51,    52,    53,    54,    69,    12,    33,    34,    35,
      36,    38,    39,    64,    65,    66,   359,    41,    42,    43,
      44,    46,    77,    91,    92,    93,   168,   358,    29,    30,
      31,   360,   360,   360,    66,    90,   159,    80,   360,   353,
     340,   343,    41,    94,   140,   341,   134,   134,   342,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   336,   337,
     134,   175,   225,   339,   338,   159,   370,   370,   225,     3,
       3,     4,     3,   370,   133,     3,   305,   374,   323,   324,
      82,   367,    18,   325,   326,   327,    94,   368,   329,   125,
     409,   410,   371,   375,   376,   355,    51,    52,   360,   360,
     360,   360,   360,   360,   360,    45,   360,    47,    48,   360,
     360,   134,   134,   134,   360,   360,   360,   360,   134,   130,
     136,   137,   138,   172,   173,   174,   422,   225,   225,   134,
     134,    94,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   175,   226,   417,   419,   420,   421,   422,
     417,   417,   417,   134,   230,   370,   374,    21,   332,   136,
     383,   408,   412,   383,   374,   134,   383,   132,   187,   188,
     189,   190,   191,   193,   305,   225,   130,   225,   372,   225,
     130,   132,   136,   137,   138,   172,   173,   174,   225,   377,
     406,   413,   225,   422,   360,   360,   134,   134,   134,   134,
     134,   134,   134,   360,   134,   134,   134,   134,   134,   134,
     134,   354,   134,   134,   418,   419,   421,   145,   232,   333,
     374,   384,   385,   187,   143,   214,   144,   145,   373,   407,
     378,   379,   356,   134,   134,   134,   360,   233,   234,   305,
     124,   295,   374,   130,   136,   137,   138,   172,   173,   174,
     386,   406,   415,   225,   133,   187,   141,   132,   195,   192,
     225,   225,   130,   136,   137,   138,   172,   173,   174,   380,
     406,   414,   225,   360,   134,   138,   146,   130,   142,   235,
     239,   388,   387,   389,   187,   196,   194,   305,   381,   382,
     134,   234,   187,     1,   107,   108,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     166,   240,   174,   400,   406,   413,   130,   136,   137,   138,
     172,   173,   174,   390,   406,   416,   225,   215,     1,   110,
     112,   140,   198,   199,   200,   138,   146,   370,   225,   134,
     134,   138,   141,   175,   186,   187,   190,   191,   193,   306,
     309,   310,   312,   314,   315,   241,   242,   243,   126,   127,
     128,   129,   131,   134,   135,   226,   268,   269,   307,   311,
     312,   315,   268,   267,   307,   305,   263,   245,   247,   250,
     252,   255,   257,   260,   401,   402,   391,   392,   393,   295,
     124,   127,   129,   131,   139,   140,   141,   143,   144,   173,
     300,   301,   308,   312,   316,   201,   305,   197,   138,   305,
     143,   134,   296,   296,   296,   296,   134,   297,   298,   300,
     130,   130,   269,   130,   130,   307,   262,   298,   130,   130,
     131,   131,   127,   127,   130,   137,   403,   406,   414,   225,
     370,   174,   394,   406,   413,   225,   216,   141,   145,   130,
     203,   141,   133,   200,   186,   187,   134,   175,   231,   300,
     135,   231,   300,   299,   244,   126,   128,   136,   175,   236,
     270,   273,   275,   277,   300,   270,   126,   217,   139,   264,
     231,   246,   248,   251,   253,   256,   258,   261,   404,   405,
     395,   396,     1,   109,   110,   112,   115,   218,   300,   302,
     204,   141,   305,   297,   270,   278,   236,   274,   277,   276,
     236,   237,   277,   138,   141,   265,   266,   306,   310,   312,
     314,   315,   134,   225,   129,   225,   129,   225,   129,   270,
     370,   225,   137,   397,   406,   414,   225,   134,   300,   219,
     267,   301,   303,   276,   202,   135,   279,   300,   136,   280,
     130,   134,   236,   271,   272,   277,   296,   138,   130,   249,
     254,   259,   398,   399,   141,   130,   141,   221,   130,   138,
     146,   275,   136,   205,   137,   138,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   281,   282,
     283,   296,   273,   266,   305,   225,   225,   225,   370,   225,
     175,   220,   300,   222,   224,   217,   304,   277,   206,   300,
     149,   149,   173,   132,   173,   132,   132,   132,   132,   132,
     132,   137,   283,   284,   296,   276,   225,   237,   301,   154,
     155,   162,   168,   207,   208,   285,   287,   288,   289,   290,
     169,   170,   171,   293,   294,   286,   176,   291,   275,   173,
     132,   132,   132,   137,   208,   173,   292,   292,   292,   292,
       5,   305,   305,   305,   133,   294,   292,   277,   209,   211,
     210,   133,   173,   133,   133,   133,   133,   226,   226,   226,
     133,   141,   292,     5,   292,   223,   133,   133,   133,   225
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   177,   178,   178,   179,   179,   179,   179,   181,   180,
     182,   180,   180,   183,   180,   184,   180,   180,   185,   180,
     180,   180,   186,   186,   186,   186,   186,   186,   186,   187,
     187,   188,   188,   189,   189,   189,   190,   192,   191,   193,
     194,   194,   196,   197,   195,   198,   198,   199,   199,   200,
     200,   201,   202,   200,   204,   203,   203,   206,   205,   205,
     207,   207,   208,   209,   208,   210,   208,   211,   208,   213,
     214,   215,   212,   216,   216,   217,   217,   218,   218,   219,
     218,   218,   220,   220,   222,   223,   221,   224,   221,   225,
     225,   227,   226,   229,   230,   228,   231,   231,   232,   232,
     233,   233,   234,   235,   235,   236,   237,   237,   238,   238,
     239,   239,   240,   241,   240,   242,   240,   243,   244,   240,
     240,   240,   245,   246,   240,   247,   248,   249,   240,   250,
     251,   240,   252,   253,   254,   240,   255,   256,   240,   257,
     258,   259,   240,   260,   261,   240,   240,   262,   240,   263,
     240,   240,   264,   264,   265,   265,   266,   267,   267,   268,
     268,   269,   269,   270,   270,   270,   271,   271,   272,   272,
     272,   273,   274,   274,   275,   275,   276,   276,   277,   278,
     277,   279,   279,   280,   280,   281,   281,   282,   282,   282,
     283,   283,   284,   283,   283,   283,   283,   285,   283,   286,
     283,   287,   283,   288,   283,   283,   283,   283,   289,   283,
     283,   283,   283,   283,   290,   283,   283,   283,   291,   291,
     292,   292,   293,   293,   294,   294,   294,   294,   295,   295,
     296,   296,   297,   297,   298,   298,   299,   298,   300,   301,
     302,   301,   304,   303,   303,   305,   305,   305,   305,   305,
     306,   306,   306,   306,   306,   306,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   309,   309,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     311,   311,   311,   311,   312,   312,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   314,   314,   314,   314,   314,   314,   314,
     315,   315,   315,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   318,   317,   319,
     317,   320,   317,   321,   317,   322,   317,   323,   317,   324,
     317,   325,   317,   326,   317,   327,   317,   328,   317,   329,
     317,   330,   317,   331,   317,   332,   317,   333,   317,   317,
     334,   317,   335,   317,   317,   336,   317,   337,   317,   338,
     317,   339,   317,   317,   340,   317,   341,   317,   342,   317,
     343,   317,   317,   317,   344,   317,   345,   317,   346,   317,
     347,   317,   348,   317,   349,   317,   350,   317,   351,   317,
     317,   317,   317,   352,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   353,   354,
     317,   355,   356,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   357,   317,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   360,
     360,   361,   361,   362,   362,   363,   363,   364,   364,   364,
     364,   364,   364,   365,   365,   366,   366,   367,   367,   368,
     368,   369,   369,   369,   370,   371,   370,   373,   372,   372,
     375,   374,   374,   376,   374,   378,   377,   379,   377,   377,
     381,   380,   382,   380,   380,   384,   383,   383,   385,   383,
     387,   386,   388,   386,   389,   386,   386,   391,   390,   392,
     390,   393,   390,   390,   395,   394,   396,   394,   394,   398,
     397,   399,   397,   397,   401,   400,   402,   400,   400,   404,
     403,   405,   403,   403,   407,   406,   406,   409,   408,   410,
     408,   408,   411,   411,   411,   411,   411,   411,   411,   412,
     412,   412,   412,   412,   412,   413,   413,   413,   413,   413,
     413,   414,   414,   414,   414,   414,   414,   415,   415,   415,
     415,   415,   416,   416,   416,   416,   416,   417,   417,   418,
     418,   419,   420,   420,   421,   421,   422,   422,   422,   422,
     422,   422,   422
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       4,     0,     3,     0,     3,     0,     5,     0,     6,     4,
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
       1,     1,     1,     1,     1,     1,     0,     1,     0,     1,
       0,     1,     1,     1,     1,     0,     3,     0,     3,     1,
       0,     3,     1,     0,     3,     0,     3,     0,     3,     1,
       0,     3,     0,     3,     1,     0,     3,     1,     0,     3,
       0,     3,     0,     3,     0,     3,     1,     0,     3,     0,
       3,     0,     3,     1,     0,     3,     0,     3,     1,     0,
       3,     0,     3,     1,     0,     3,     0,     3,     1,     0,
       3,     0,     3,     1,     0,     3,     1,     0,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (parseResult, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, parseResult); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, UserLevelRewritingContext::ParseResult* parseResult)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (parseResult);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, UserLevelRewritingContext::ParseResult* parseResult)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parseResult);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, UserLevelRewritingContext::ParseResult* parseResult)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , parseResult);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parseResult); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, UserLevelRewritingContext::ParseResult* parseResult)
{
  YYUSE (yyvaluep);
  YYUSE (parseResult);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (UserLevelRewritingContext::ParseResult* parseResult)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex (&yylval);
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 235 "surface.yy" /* yacc.c:1646  */
    { YYACCEPT; }
#line 2544 "surface.c" /* yacc.c:1646  */
    break;

  case 3:
#line 237 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			}
#line 2552 "surface.c" /* yacc.c:1646  */
    break;

  case 8:
#line 251 "surface.yy" /* yacc.c:1646  */
    { lexerFileNameMode(); }
#line 2558 "surface.c" /* yacc.c:1646  */
    break;

  case 9:
#line 253 "surface.yy" /* yacc.c:1646  */
    {
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile((yyvsp[0].yyString), directory, fileName, lineNr))
			    includeFile(directory, fileName, false, lineNr);
			}
#line 2571 "surface.c" /* yacc.c:1646  */
    break;

  case 10:
#line 261 "surface.yy" /* yacc.c:1646  */
    { lexerFileNameMode(); }
#line 2577 "surface.c" /* yacc.c:1646  */
    break;

  case 11:
#line 263 "surface.yy" /* yacc.c:1646  */
    {
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile((yyvsp[0].yyString), directory, fileName, lineNr))
			    includeFile(directory, fileName, true, lineNr);
			}
#line 2590 "surface.c" /* yacc.c:1646  */
    break;

  case 12:
#line 272 "surface.yy" /* yacc.c:1646  */
    {
			  cout << directoryManager.getCwd() << '\n';
			}
#line 2598 "surface.c" /* yacc.c:1646  */
    break;

  case 13:
#line 275 "surface.yy" /* yacc.c:1646  */
    { lexerFileNameMode(); }
#line 2604 "surface.c" /* yacc.c:1646  */
    break;

  case 14:
#line 277 "surface.yy" /* yacc.c:1646  */
    {
			  string directory;
			  directoryManager.realPath((yyvsp[0].yyString), directory);
			  if (!directoryManager.cd(directory))
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": cd failed");
			    }
			}
#line 2618 "surface.c" /* yacc.c:1646  */
    break;

  case 15:
#line 286 "surface.yy" /* yacc.c:1646  */
    { lexerFileNameMode(); }
#line 2624 "surface.c" /* yacc.c:1646  */
    break;

  case 16:
#line 288 "surface.yy" /* yacc.c:1646  */
    {
			  string directory;
			  directoryManager.realPath((yyvsp[0].yyString), directory);
			  if (directoryManager.pushd(directory) == UNDEFINED)
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": pushd failed");
			    }
			}
#line 2638 "surface.c" /* yacc.c:1646  */
    break;

  case 17:
#line 298 "surface.yy" /* yacc.c:1646  */
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
#line 2653 "surface.c" /* yacc.c:1646  */
    break;

  case 18:
#line 308 "surface.yy" /* yacc.c:1646  */
    { lexerStringMode(); }
#line 2659 "surface.c" /* yacc.c:1646  */
    break;

  case 19:
#line 310 "surface.yy" /* yacc.c:1646  */
    {
			  system((string("ls") + (yyvsp[0].yyString)).c_str());
			}
#line 2667 "surface.c" /* yacc.c:1646  */
    break;

  case 20:
#line 314 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			}
#line 2676 "surface.c" /* yacc.c:1646  */
    break;

  case 21:
#line 319 "surface.yy" /* yacc.c:1646  */
    {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			}
#line 2687 "surface.c" /* yacc.c:1646  */
    break;

  case 22:
#line 352 "surface.yy" /* yacc.c:1646  */
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[-1].yyToken)));
                        }
#line 2695 "surface.c" /* yacc.c:1646  */
    break;

  case 23:
#line 356 "surface.yy" /* yacc.c:1646  */
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[-1].yyToken)));
                        }
#line 2703 "surface.c" /* yacc.c:1646  */
    break;

  case 27:
#line 363 "surface.yy" /* yacc.c:1646  */
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			}
#line 2715 "surface.c" /* yacc.c:1646  */
    break;

  case 28:
#line 371 "surface.yy" /* yacc.c:1646  */
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  moduleExpressions.push(new ModuleExpression(t));
			}
#line 2726 "surface.c" /* yacc.c:1646  */
    break;

  case 30:
#line 381 "surface.yy" /* yacc.c:1646  */
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			}
#line 2738 "surface.c" /* yacc.c:1646  */
    break;

  case 35:
#line 397 "surface.yy" /* yacc.c:1646  */
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[0].yyToken)));
                        }
#line 2746 "surface.c" /* yacc.c:1646  */
    break;

  case 36:
#line 404 "surface.yy" /* yacc.c:1646  */
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			}
#line 2757 "surface.c" /* yacc.c:1646  */
    break;

  case 37:
#line 412 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 2763 "surface.c" /* yacc.c:1646  */
    break;

  case 38:
#line 414 "surface.yy" /* yacc.c:1646  */
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, tokenSequence));
			}
#line 2773 "surface.c" /* yacc.c:1646  */
    break;

  case 39:
#line 421 "surface.yy" /* yacc.c:1646  */
    {}
#line 2779 "surface.c" /* yacc.c:1646  */
    break;

  case 40:
#line 424 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 2785 "surface.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 2791 "surface.c" /* yacc.c:1646  */
    break;

  case 42:
#line 432 "surface.yy" /* yacc.c:1646  */
    {
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			}
#line 2800 "surface.c" /* yacc.c:1646  */
    break;

  case 43:
#line 437 "surface.yy" /* yacc.c:1646  */
    {
			  currentSyntaxContainer = oldSyntaxContainer;
			}
#line 2808 "surface.c" /* yacc.c:1646  */
    break;

  case 49:
#line 452 "surface.yy" /* yacc.c:1646  */
    {
			  currentRenaming->addSortMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 2816 "surface.c" /* yacc.c:1646  */
    break;

  case 50:
#line 456 "surface.yy" /* yacc.c:1646  */
    {
			  currentRenaming->addLabelMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 2824 "surface.c" /* yacc.c:1646  */
    break;

  case 51:
#line 459 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_COLON | BAR_TO, 1); }
#line 2830 "surface.c" /* yacc.c:1646  */
    break;

  case 52:
#line 460 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1); }
#line 2836 "surface.c" /* yacc.c:1646  */
    break;

  case 53:
#line 461 "surface.yy" /* yacc.c:1646  */
    {}
#line 2842 "surface.c" /* yacc.c:1646  */
    break;

  case 54:
#line 466 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
#line 2848 "surface.c" /* yacc.c:1646  */
    break;

  case 55:
#line 467 "surface.yy" /* yacc.c:1646  */
    {}
#line 2854 "surface.c" /* yacc.c:1646  */
    break;

  case 56:
#line 468 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
#line 2860 "surface.c" /* yacc.c:1646  */
    break;

  case 57:
#line 474 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
#line 2866 "surface.c" /* yacc.c:1646  */
    break;

  case 58:
#line 475 "surface.yy" /* yacc.c:1646  */
    {}
#line 2872 "surface.c" /* yacc.c:1646  */
    break;

  case 59:
#line 476 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
#line 2878 "surface.c" /* yacc.c:1646  */
    break;

  case 62:
#line 483 "surface.yy" /* yacc.c:1646  */
    { currentRenaming->setPrec((yyvsp[0].yyToken)); }
#line 2884 "surface.c" /* yacc.c:1646  */
    break;

  case 63:
#line 484 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 2890 "surface.c" /* yacc.c:1646  */
    break;

  case 64:
#line 485 "surface.yy" /* yacc.c:1646  */
    { currentRenaming->setGather(tokenSequence); }
#line 2896 "surface.c" /* yacc.c:1646  */
    break;

  case 65:
#line 486 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 2902 "surface.c" /* yacc.c:1646  */
    break;

  case 66:
#line 487 "surface.yy" /* yacc.c:1646  */
    { currentRenaming->setFormat(tokenSequence); }
#line 2908 "surface.c" /* yacc.c:1646  */
    break;

  case 67:
#line 488 "surface.yy" /* yacc.c:1646  */
    { lexerLatexMode(); }
#line 2914 "surface.c" /* yacc.c:1646  */
    break;

  case 68:
#line 489 "surface.yy" /* yacc.c:1646  */
    { currentRenaming->setLatexMacro((yyvsp[-1].yyString)); }
#line 2920 "surface.c" /* yacc.c:1646  */
    break;

  case 69:
#line 495 "surface.yy" /* yacc.c:1646  */
    { lexerIdMode(); }
#line 2926 "surface.c" /* yacc.c:1646  */
    break;

  case 70:
#line 497 "surface.yy" /* yacc.c:1646  */
    {
			  fileTable.beginModule((yyvsp[-4].yyToken), (yyvsp[-2].yyToken));
			  interpreter.setCurrentView(new View((yyvsp[-2].yyToken)));
			  currentSyntaxContainer = CV;
			  CV->addFrom(moduleExpressions.top());
			  moduleExpressions.pop();
			}
#line 2938 "surface.c" /* yacc.c:1646  */
    break;

  case 71:
#line 505 "surface.yy" /* yacc.c:1646  */
    {
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			}
#line 2947 "surface.c" /* yacc.c:1646  */
    break;

  case 72:
#line 510 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  interpreter.insertView(((yyvsp[-9].yyToken)).code(), CV);
			  CV->finishView();
			}
#line 2958 "surface.c" /* yacc.c:1646  */
    break;

  case 75:
#line 523 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
				       ": skipping " << QUOTE("->") << " in variable declaration.");
			}
#line 2967 "surface.c" /* yacc.c:1646  */
    break;

  case 77:
#line 531 "surface.yy" /* yacc.c:1646  */
    {
			  CV->addSortMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 2975 "surface.c" /* yacc.c:1646  */
    break;

  case 78:
#line 534 "surface.yy" /* yacc.c:1646  */
    {}
#line 2981 "surface.c" /* yacc.c:1646  */
    break;

  case 79:
#line 535 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_COLON | BAR_TO, 1); }
#line 2987 "surface.c" /* yacc.c:1646  */
    break;

  case 82:
#line 540 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyToken) = (yyvsp[-1].yyToken); }
#line 2993 "surface.c" /* yacc.c:1646  */
    break;

  case 83:
#line 542 "surface.yy" /* yacc.c:1646  */
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  (yyval.yyToken) = t;
			}
#line 3004 "surface.c" /* yacc.c:1646  */
    break;

  case 84:
#line 551 "surface.yy" /* yacc.c:1646  */
    {
			  //
			  //	Specific op->op mapping.
			  //
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpMapping(lexerBubble);
			}
#line 3016 "surface.c" /* yacc.c:1646  */
    break;

  case 85:
#line 559 "surface.yy" /* yacc.c:1646  */
    {
			  lexBubble(END_STATEMENT, 1);
			}
#line 3024 "surface.c" /* yacc.c:1646  */
    break;

  case 86:
#line 563 "surface.yy" /* yacc.c:1646  */
    {
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			}
#line 3033 "surface.c" /* yacc.c:1646  */
    break;

  case 87:
#line 568 "surface.yy" /* yacc.c:1646  */
    {
			  //
			  //	At this point we don't know if we have an op->term mapping
			  //	or a generic op->op mapping so we save the from description and
			  //	press on.
			  //
			  opDescription = lexerBubble;
			  lexBubble(END_STATEMENT, 1);
			}
#line 3047 "surface.c" /* yacc.c:1646  */
    break;

  case 88:
#line 578 "surface.yy" /* yacc.c:1646  */
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
#line 3071 "surface.c" /* yacc.c:1646  */
    break;

  case 89:
#line 600 "surface.yy" /* yacc.c:1646  */
    {}
#line 3077 "surface.c" /* yacc.c:1646  */
    break;

  case 90:
#line 602 "surface.yy" /* yacc.c:1646  */
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  lexerBubble.append(t);
			}
#line 3088 "surface.c" /* yacc.c:1646  */
    break;

  case 91:
#line 610 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_RIGHT_PAREN, 1); }
#line 3094 "surface.c" /* yacc.c:1646  */
    break;

  case 92:
#line 611 "surface.yy" /* yacc.c:1646  */
    {}
#line 3100 "surface.c" /* yacc.c:1646  */
    break;

  case 93:
#line 617 "surface.yy" /* yacc.c:1646  */
    { lexerIdMode(); }
#line 3106 "surface.c" /* yacc.c:1646  */
    break;

  case 94:
#line 619 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setCurrentModule(new SyntacticPreModule((yyvsp[-2].yyToken), (yyvsp[0].yyToken)));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 3116 "surface.c" /* yacc.c:1646  */
    break;

  case 95:
#line 625 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule((yyvsp[0].yyToken));
			}
#line 3126 "surface.c" /* yacc.c:1646  */
    break;

  case 96:
#line 632 "surface.yy" /* yacc.c:1646  */
    {}
#line 3132 "surface.c" /* yacc.c:1646  */
    break;

  case 97:
#line 634 "surface.yy" /* yacc.c:1646  */
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  store(t);
			}
#line 3143 "surface.c" /* yacc.c:1646  */
    break;

  case 98:
#line 642 "surface.yy" /* yacc.c:1646  */
    {}
#line 3149 "surface.c" /* yacc.c:1646  */
    break;

  case 102:
#line 651 "surface.yy" /* yacc.c:1646  */
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter((yyvsp[-2].yyToken), me);
			}
#line 3159 "surface.c" /* yacc.c:1646  */
    break;

  case 103:
#line 658 "surface.yy" /* yacc.c:1646  */
    {}
#line 3165 "surface.c" /* yacc.c:1646  */
    break;

  case 104:
#line 660 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
			    ": saw " << QUOTE(':') << " instead of " <<
			    QUOTE("::") << " in parameter declaration.");
			}
#line 3175 "surface.c" /* yacc.c:1646  */
    break;

  case 105:
#line 668 "surface.yy" /* yacc.c:1646  */
    {
			  singleton[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(singleton[0]);
			  currentSyntaxContainer->addType(false, singleton);
			  (yyval.yyToken) = (yyvsp[0].yyToken);  // needed for line number
			}
#line 3186 "surface.c" /* yacc.c:1646  */
    break;

  case 107:
#line 677 "surface.yy" /* yacc.c:1646  */
    {}
#line 3192 "surface.c" /* yacc.c:1646  */
    break;

  case 112:
#line 688 "surface.yy" /* yacc.c:1646  */
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport((yyvsp[-1].yyToken), me);
			}
#line 3202 "surface.c" /* yacc.c:1646  */
    break;

  case 113:
#line 694 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3208 "surface.c" /* yacc.c:1646  */
    break;

  case 114:
#line 695 "surface.yy" /* yacc.c:1646  */
    { CM->addSortDecl(tokenSequence); }
#line 3214 "surface.c" /* yacc.c:1646  */
    break;

  case 115:
#line 697 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3220 "surface.c" /* yacc.c:1646  */
    break;

  case 116:
#line 698 "surface.yy" /* yacc.c:1646  */
    { CM->addSubsortDecl(tokenSequence); }
#line 3226 "surface.c" /* yacc.c:1646  */
    break;

  case 117:
#line 700 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_COLON, 1); }
#line 3232 "surface.c" /* yacc.c:1646  */
    break;

  case 118:
#line 701 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
#line 3238 "surface.c" /* yacc.c:1646  */
    break;

  case 119:
#line 702 "surface.yy" /* yacc.c:1646  */
    {}
#line 3244 "surface.c" /* yacc.c:1646  */
    break;

  case 120:
#line 704 "surface.yy" /* yacc.c:1646  */
    {}
#line 3250 "surface.c" /* yacc.c:1646  */
    break;

  case 121:
#line 706 "surface.yy" /* yacc.c:1646  */
    {}
#line 3256 "surface.c" /* yacc.c:1646  */
    break;

  case 122:
#line 708 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_COLON, 1); }
#line 3262 "surface.c" /* yacc.c:1646  */
    break;

  case 123:
#line 709 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3268 "surface.c" /* yacc.c:1646  */
    break;

  case 124:
#line 710 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3274 "surface.c" /* yacc.c:1646  */
    break;

  case 125:
#line 712 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_COLON, 1);  }
#line 3280 "surface.c" /* yacc.c:1646  */
    break;

  case 126:
#line 713 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); }
#line 3286 "surface.c" /* yacc.c:1646  */
    break;

  case 127:
#line 714 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3292 "surface.c" /* yacc.c:1646  */
    break;

  case 128:
#line 715 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3298 "surface.c" /* yacc.c:1646  */
    break;

  case 129:
#line 717 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_EQUALS, 1); }
#line 3304 "surface.c" /* yacc.c:1646  */
    break;

  case 130:
#line 718 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3310 "surface.c" /* yacc.c:1646  */
    break;

  case 131:
#line 719 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3316 "surface.c" /* yacc.c:1646  */
    break;

  case 132:
#line 721 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_EQUALS, 1); }
#line 3322 "surface.c" /* yacc.c:1646  */
    break;

  case 133:
#line 722 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); }
#line 3328 "surface.c" /* yacc.c:1646  */
    break;

  case 134:
#line 723 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3334 "surface.c" /* yacc.c:1646  */
    break;

  case 135:
#line 724 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3340 "surface.c" /* yacc.c:1646  */
    break;

  case 136:
#line 726 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_ARROW2, 1); }
#line 3346 "surface.c" /* yacc.c:1646  */
    break;

  case 137:
#line 727 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3352 "surface.c" /* yacc.c:1646  */
    break;

  case 138:
#line 728 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3358 "surface.c" /* yacc.c:1646  */
    break;

  case 139:
#line 730 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_ARROW2, 1); }
#line 3364 "surface.c" /* yacc.c:1646  */
    break;

  case 140:
#line 731 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); }
#line 3370 "surface.c" /* yacc.c:1646  */
    break;

  case 141:
#line 732 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3376 "surface.c" /* yacc.c:1646  */
    break;

  case 142:
#line 733 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3382 "surface.c" /* yacc.c:1646  */
    break;

  case 143:
#line 735 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_COLON, 1); }
#line 3388 "surface.c" /* yacc.c:1646  */
    break;

  case 144:
#line 736 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
#line 3394 "surface.c" /* yacc.c:1646  */
    break;

  case 145:
#line 737 "surface.yy" /* yacc.c:1646  */
    { CM->setFlag(SymbolType::MESSAGE); }
#line 3400 "surface.c" /* yacc.c:1646  */
    break;

  case 146:
#line 740 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::MESSAGE);
			}
#line 3408 "surface.c" /* yacc.c:1646  */
    break;

  case 147:
#line 745 "surface.yy" /* yacc.c:1646  */
    {
			}
#line 3415 "surface.c" /* yacc.c:1646  */
    break;

  case 148:
#line 748 "surface.yy" /* yacc.c:1646  */
    {
			}
#line 3422 "surface.c" /* yacc.c:1646  */
    break;

  case 149:
#line 751 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3428 "surface.c" /* yacc.c:1646  */
    break;

  case 150:
#line 752 "surface.yy" /* yacc.c:1646  */
    { CM->addSubsortDecl(tokenSequence); }
#line 3434 "surface.c" /* yacc.c:1646  */
    break;

  case 151:
#line 755 "surface.yy" /* yacc.c:1646  */
    {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeOpDeclsConsistent();
			}
#line 3447 "surface.c" /* yacc.c:1646  */
    break;

  case 152:
#line 765 "surface.yy" /* yacc.c:1646  */
    {}
#line 3453 "surface.c" /* yacc.c:1646  */
    break;

  case 153:
#line 766 "surface.yy" /* yacc.c:1646  */
    {}
#line 3459 "surface.c" /* yacc.c:1646  */
    break;

  case 156:
#line 774 "surface.yy" /* yacc.c:1646  */
    {
			}
#line 3466 "surface.c" /* yacc.c:1646  */
    break;

  case 157:
#line 778 "surface.yy" /* yacc.c:1646  */
    { currentSyntaxContainer->addVarDecl((yyvsp[0].yyToken)); }
#line 3472 "surface.c" /* yacc.c:1646  */
    break;

  case 158:
#line 779 "surface.yy" /* yacc.c:1646  */
    { currentSyntaxContainer->addVarDecl((yyvsp[0].yyToken)); }
#line 3478 "surface.c" /* yacc.c:1646  */
    break;

  case 161:
#line 786 "surface.yy" /* yacc.c:1646  */
    { singleton[0] = (yyvsp[0].yyToken); CM->addOpDecl(singleton); }
#line 3484 "surface.c" /* yacc.c:1646  */
    break;

  case 162:
#line 787 "surface.yy" /* yacc.c:1646  */
    { CM->addOpDecl(lexerBubble); }
#line 3490 "surface.c" /* yacc.c:1646  */
    break;

  case 165:
#line 793 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber(lineNumber) <<
				       ": missing " << QUOTE("->") << " in constant declaration.");
			}
#line 3499 "surface.c" /* yacc.c:1646  */
    break;

  case 166:
#line 800 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
				       ": skipping stray " << QUOTE(":") << " in operator declaration.");

			}
#line 3509 "surface.c" /* yacc.c:1646  */
    break;

  case 169:
#line 810 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			}
#line 3518 "surface.c" /* yacc.c:1646  */
    break;

  case 170:
#line 815 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			}
#line 3527 "surface.c" /* yacc.c:1646  */
    break;

  case 171:
#line 822 "surface.yy" /* yacc.c:1646  */
    {
			  if ((yyvsp[-1].yyBool))
			    CM->convertSortsToKinds();
			}
#line 3536 "surface.c" /* yacc.c:1646  */
    break;

  case 173:
#line 829 "surface.yy" /* yacc.c:1646  */
    {}
#line 3542 "surface.c" /* yacc.c:1646  */
    break;

  case 174:
#line 832 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 3548 "surface.c" /* yacc.c:1646  */
    break;

  case 175:
#line 833 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 3554 "surface.c" /* yacc.c:1646  */
    break;

  case 178:
#line 841 "surface.yy" /* yacc.c:1646  */
    {
			  singleton[0] = (yyvsp[0].yyToken);
			  currentSyntaxContainer->addType(false, singleton);
			}
#line 3563 "surface.c" /* yacc.c:1646  */
    break;

  case 179:
#line 845 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3569 "surface.c" /* yacc.c:1646  */
    break;

  case 180:
#line 847 "surface.yy" /* yacc.c:1646  */
    {
			  currentSyntaxContainer->addType(true, tokenSequence);
			}
#line 3577 "surface.c" /* yacc.c:1646  */
    break;

  case 181:
#line 852 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3583 "surface.c" /* yacc.c:1646  */
    break;

  case 182:
#line 853 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3589 "surface.c" /* yacc.c:1646  */
    break;

  case 183:
#line 856 "surface.yy" /* yacc.c:1646  */
    {}
#line 3595 "surface.c" /* yacc.c:1646  */
    break;

  case 187:
#line 865 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			}
#line 3603 "surface.c" /* yacc.c:1646  */
    break;

  case 188:
#line 869 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			}
#line 3611 "surface.c" /* yacc.c:1646  */
    break;

  case 189:
#line 873 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			}
#line 3619 "surface.c" /* yacc.c:1646  */
    break;

  case 190:
#line 879 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::ASSOC);
			}
#line 3627 "surface.c" /* yacc.c:1646  */
    break;

  case 191:
#line 883 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::COMM);
			}
#line 3635 "surface.c" /* yacc.c:1646  */
    break;

  case 192:
#line 886 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_RIGHT_BRACKET | BAR_OP_ATTRIBUTE, 1); }
#line 3641 "surface.c" /* yacc.c:1646  */
    break;

  case 193:
#line 887 "surface.yy" /* yacc.c:1646  */
    { CM->setIdentity(lexerBubble); }
#line 3647 "surface.c" /* yacc.c:1646  */
    break;

  case 194:
#line 889 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::IDEM);
			}
#line 3655 "surface.c" /* yacc.c:1646  */
    break;

  case 195:
#line 893 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::ITER);
			}
#line 3663 "surface.c" /* yacc.c:1646  */
    break;

  case 196:
#line 896 "surface.yy" /* yacc.c:1646  */
    { CM->setPrec((yyvsp[0].yyToken)); }
#line 3669 "surface.c" /* yacc.c:1646  */
    break;

  case 197:
#line 897 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3675 "surface.c" /* yacc.c:1646  */
    break;

  case 198:
#line 898 "surface.yy" /* yacc.c:1646  */
    { CM->setGather(tokenSequence); }
#line 3681 "surface.c" /* yacc.c:1646  */
    break;

  case 199:
#line 899 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3687 "surface.c" /* yacc.c:1646  */
    break;

  case 200:
#line 900 "surface.yy" /* yacc.c:1646  */
    { CM->setFormat(tokenSequence); }
#line 3693 "surface.c" /* yacc.c:1646  */
    break;

  case 201:
#line 901 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3699 "surface.c" /* yacc.c:1646  */
    break;

  case 202:
#line 902 "surface.yy" /* yacc.c:1646  */
    { CM->setStrat(tokenSequence); }
#line 3705 "surface.c" /* yacc.c:1646  */
    break;

  case 203:
#line 903 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3711 "surface.c" /* yacc.c:1646  */
    break;

  case 204:
#line 904 "surface.yy" /* yacc.c:1646  */
    { CM->setPoly(tokenSequence); }
#line 3717 "surface.c" /* yacc.c:1646  */
    break;

  case 205:
#line 906 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::MEMO);
			}
#line 3725 "surface.c" /* yacc.c:1646  */
    break;

  case 206:
#line 910 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::CTOR);
			}
#line 3733 "surface.c" /* yacc.c:1646  */
    break;

  case 207:
#line 914 "surface.yy" /* yacc.c:1646  */
    {
			  clear();
			  CM->setFrozen(tokenSequence);
			}
#line 3742 "surface.c" /* yacc.c:1646  */
    break;

  case 208:
#line 918 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3748 "surface.c" /* yacc.c:1646  */
    break;

  case 209:
#line 919 "surface.yy" /* yacc.c:1646  */
    { CM->setFrozen(tokenSequence); }
#line 3754 "surface.c" /* yacc.c:1646  */
    break;

  case 210:
#line 921 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::CONFIG);
			}
#line 3762 "surface.c" /* yacc.c:1646  */
    break;

  case 211:
#line 925 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::OBJECT);
			}
#line 3770 "surface.c" /* yacc.c:1646  */
    break;

  case 212:
#line 929 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::MESSAGE);
			}
#line 3778 "surface.c" /* yacc.c:1646  */
    break;

  case 213:
#line 933 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setMetadata((yyvsp[0].yyToken));
			}
#line 3786 "surface.c" /* yacc.c:1646  */
    break;

  case 214:
#line 936 "surface.yy" /* yacc.c:1646  */
    { lexerLatexMode(); }
#line 3792 "surface.c" /* yacc.c:1646  */
    break;

  case 215:
#line 937 "surface.yy" /* yacc.c:1646  */
    { CM->setLatexMacro((yyvsp[-1].yyString)); }
#line 3798 "surface.c" /* yacc.c:1646  */
    break;

  case 216:
#line 938 "surface.yy" /* yacc.c:1646  */
    {}
#line 3804 "surface.c" /* yacc.c:1646  */
    break;

  case 217:
#line 940 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::DITTO);
			}
#line 3812 "surface.c" /* yacc.c:1646  */
    break;

  case 220:
#line 953 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3818 "surface.c" /* yacc.c:1646  */
    break;

  case 221:
#line 954 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3824 "surface.c" /* yacc.c:1646  */
    break;

  case 224:
#line 961 "surface.yy" /* yacc.c:1646  */
    { clear(); CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[0].yyToken), tokenSequence); }
#line 3830 "surface.c" /* yacc.c:1646  */
    break;

  case 225:
#line 962 "surface.yy" /* yacc.c:1646  */
    { CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[-1].yyToken), lexerBubble); }
#line 3836 "surface.c" /* yacc.c:1646  */
    break;

  case 226:
#line 963 "surface.yy" /* yacc.c:1646  */
    { CM->addHook(SyntacticPreModule::OP_HOOK, (yyvsp[-1].yyToken), lexerBubble); }
#line 3842 "surface.c" /* yacc.c:1646  */
    break;

  case 227:
#line 964 "surface.yy" /* yacc.c:1646  */
    { CM->addHook(SyntacticPreModule::TERM_HOOK, (yyvsp[-1].yyToken), lexerBubble); }
#line 3848 "surface.c" /* yacc.c:1646  */
    break;

  case 228:
#line 970 "surface.yy" /* yacc.c:1646  */
    {}
#line 3854 "surface.c" /* yacc.c:1646  */
    break;

  case 229:
#line 972 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing " <<
				       QUOTE("is") << " keyword.");
			}
#line 3863 "surface.c" /* yacc.c:1646  */
    break;

  case 230:
#line 978 "surface.yy" /* yacc.c:1646  */
    {}
#line 3869 "surface.c" /* yacc.c:1646  */
    break;

  case 231:
#line 980 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			}
#line 3877 "surface.c" /* yacc.c:1646  */
    break;

  case 232:
#line 988 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3883 "surface.c" /* yacc.c:1646  */
    break;

  case 234:
#line 992 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3889 "surface.c" /* yacc.c:1646  */
    break;

  case 235:
#line 993 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3895 "surface.c" /* yacc.c:1646  */
    break;

  case 236:
#line 994 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3901 "surface.c" /* yacc.c:1646  */
    break;

  case 237:
#line 995 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3907 "surface.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1002 "surface.yy" /* yacc.c:1646  */
    {
			  Token t;
			  if (fragments.size() == 1)
			    t = fragments[0];
			  else
			    t.tokenize(Token::bubbleToPrefixNameCode(fragments), fragments[0].lineNumber());
			  fragClear();
			  (yyval.yyToken) = t;
			}
#line 3921 "surface.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1013 "surface.yy" /* yacc.c:1646  */
    { fragStore((yyvsp[0].yyToken)); }
#line 3927 "surface.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1014 "surface.yy" /* yacc.c:1646  */
    { fragStore((yyvsp[0].yyToken)); }
#line 3933 "surface.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1015 "surface.yy" /* yacc.c:1646  */
    { fragStore((yyvsp[0].yyToken)); }
#line 3939 "surface.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1018 "surface.yy" /* yacc.c:1646  */
    { fragStore((yyvsp[0].yyToken)); }
#line 3945 "surface.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1019 "surface.yy" /* yacc.c:1646  */
    {}
#line 3951 "surface.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1020 "surface.yy" /* yacc.c:1646  */
    {}
#line 3957 "surface.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1100 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 1); }
#line 3963 "surface.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1102 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setCurrentModule(lexerBubble);
			}
#line 3971 "surface.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1105 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 1); }
#line 3977 "surface.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1107 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->dump();
			}
#line 3986 "surface.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1112 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 3995 "surface.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1117 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(lexerBubble);
			}
#line 4005 "surface.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1124 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 4014 "surface.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1129 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(lexerBubble);
			}
#line 4024 "surface.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1136 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 4033 "surface.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1141 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sreduce(lexerBubble);
			}
#line 4043 "surface.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1148 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 4052 "surface.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1153 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(lexerBubble, (yyvsp[-3].yyBool));
			}
#line 4062 "surface.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1160 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4072 "surface.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1166 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(lexerBubble, number, (yyvsp[-3].yyBool));
			}
#line 4082 "surface.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1172 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
#line 4093 "surface.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1179 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(lexerBubble, number, number2, (yyvsp[-3].yyBool));
			}
#line 4103 "surface.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1185 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
#line 4114 "surface.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1192 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(lexerBubble, number, number2, (yyvsp[-3].yyBool));
			}
#line 4124 "surface.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1198 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4134 "surface.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1204 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, (yyvsp[-3].yyBool));
			}
#line 4144 "surface.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1211 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 4153 "surface.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1216 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.check(lexerBubble);
			}
#line 4163 "surface.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1223 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
#line 4174 "surface.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1230 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, (yyvsp[-2].yySearchKind), (yyvsp[-3].yyBool));
			}
#line 4184 "surface.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1236 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4194 "surface.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1242 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(lexerBubble, (yyvsp[-2].yyBool), number);
			}
#line 4204 "surface.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1248 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4214 "surface.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1254 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.unify(lexerBubble, number);
			}
#line 4224 "surface.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1260 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4234 "surface.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1266 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantUnify(lexerBubble, number, (yyvsp[-4].yyBool));
			}
#line 4244 "surface.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1273 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4254 "surface.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1279 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.getVariants(lexerBubble, number, (yyvsp[-3].yyBool), (yyvsp[-5].yyBool));
			}
#line 4264 "surface.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1285 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.cont((yyvsp[-1].yyInt64), (yyvsp[-3].yyBool));
			}
#line 4272 "surface.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1289 "surface.yy" /* yacc.c:1646  */
    {
			  //
			  //	test is a generic command to call code with a term for development purposes.
			  //
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 4284 "surface.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1297 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.test(lexerBubble);
			    //interpreter.newNarrow(lexerBubble);

			}
#line 4296 "surface.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1305 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 4305 "surface.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1310 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(lexerBubble);
			}
#line 4315 "surface.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1316 "surface.yy" /* yacc.c:1646  */
    {
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(lexerBubble);
			}
#line 4325 "surface.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1321 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4331 "surface.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1323 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  interpreter.traceSelect((yyvsp[-2].yyBool));
			}
#line 4340 "surface.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1327 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4346 "surface.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1329 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  interpreter.traceExclude((yyvsp[-2].yyBool));
			}
#line 4355 "surface.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1333 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4361 "surface.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1335 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  interpreter.breakSelect((yyvsp[-2].yyBool));
			}
#line 4370 "surface.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1339 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4376 "surface.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1341 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  interpreter.printConceal((yyvsp[-2].yyBool));
			}
#line 4385 "surface.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1346 "surface.yy" /* yacc.c:1646  */
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			}
#line 4394 "surface.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1353 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4400 "surface.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1355 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			}
#line 4409 "surface.c" /* yacc.c:1646  */
    break;

  case 396:
#line 1359 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4415 "surface.c" /* yacc.c:1646  */
    break;

  case 397:
#line 1361 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			}
#line 4424 "surface.c" /* yacc.c:1646  */
    break;

  case 398:
#line 1365 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4430 "surface.c" /* yacc.c:1646  */
    break;

  case 399:
#line 1367 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(true);
			}
#line 4439 "surface.c" /* yacc.c:1646  */
    break;

  case 400:
#line 1371 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4445 "surface.c" /* yacc.c:1646  */
    break;

  case 401:
#line 1373 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showView();
			}
#line 4454 "surface.c" /* yacc.c:1646  */
    break;

  case 402:
#line 1378 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.showModules(true);
			}
#line 4462 "surface.c" /* yacc.c:1646  */
    break;

  case 403:
#line 1382 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.showNamedViews();
			}
#line 4470 "surface.c" /* yacc.c:1646  */
    break;

  case 404:
#line 1385 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4476 "surface.c" /* yacc.c:1646  */
    break;

  case 405:
#line 1387 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSortsAndSubsorts();
			}
#line 4485 "surface.c" /* yacc.c:1646  */
    break;

  case 406:
#line 1391 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4491 "surface.c" /* yacc.c:1646  */
    break;

  case 407:
#line 1393 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showOps();
			}
#line 4500 "surface.c" /* yacc.c:1646  */
    break;

  case 408:
#line 1397 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4506 "surface.c" /* yacc.c:1646  */
    break;

  case 409:
#line 1399 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showVars();
			}
#line 4515 "surface.c" /* yacc.c:1646  */
    break;

  case 410:
#line 1403 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4521 "surface.c" /* yacc.c:1646  */
    break;

  case 411:
#line 1405 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showMbs();
			}
#line 4530 "surface.c" /* yacc.c:1646  */
    break;

  case 412:
#line 1409 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4536 "surface.c" /* yacc.c:1646  */
    break;

  case 413:
#line 1411 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showEqs();
			}
#line 4545 "surface.c" /* yacc.c:1646  */
    break;

  case 414:
#line 1415 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4551 "surface.c" /* yacc.c:1646  */
    break;

  case 415:
#line 1417 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showRls();
			}
#line 4560 "surface.c" /* yacc.c:1646  */
    break;

  case 416:
#line 1421 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4566 "surface.c" /* yacc.c:1646  */
    break;

  case 417:
#line 1423 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSummary();
			}
#line 4575 "surface.c" /* yacc.c:1646  */
    break;

  case 418:
#line 1427 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4581 "surface.c" /* yacc.c:1646  */
    break;

  case 419:
#line 1429 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showKinds();
			}
#line 4590 "surface.c" /* yacc.c:1646  */
    break;

  case 420:
#line 1434 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.showSearchPath((yyvsp[-1].yyInt64));
			}
#line 4598 "surface.c" /* yacc.c:1646  */
    break;

  case 421:
#line 1438 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.showSearchPathLabels((yyvsp[-1].yyInt64));
			}
#line 4606 "surface.c" /* yacc.c:1646  */
    break;

  case 422:
#line 1442 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.showSearchGraph();
			}
#line 4614 "surface.c" /* yacc.c:1646  */
    break;

  case 423:
#line 1445 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4620 "surface.c" /* yacc.c:1646  */
    break;

  case 424:
#line 1447 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showProfile();
			}
#line 4629 "surface.c" /* yacc.c:1646  */
    break;

  case 425:
#line 1455 "surface.yy" /* yacc.c:1646  */
    {
			  globalAdvisoryFlag = alwaysAdviseFlag ? true : (yyvsp[-1].yyBool);
			}
#line 4637 "surface.c" /* yacc.c:1646  */
    break;

  case 426:
#line 1459 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[-1].yyBool));
			}
#line 4645 "surface.c" /* yacc.c:1646  */
    break;

  case 427:
#line 1463 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, (yyvsp[-1].yyBool));
			}
#line 4653 "surface.c" /* yacc.c:1646  */
    break;

  case 428:
#line 1467 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, (yyvsp[-1].yyBool));
			}
#line 4661 "surface.c" /* yacc.c:1646  */
    break;

  case 429:
#line 1471 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, (yyvsp[-1].yyBool));
			}
#line 4669 "surface.c" /* yacc.c:1646  */
    break;

  case 430:
#line 1475 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, (yyvsp[-1].yyBool));
			}
#line 4677 "surface.c" /* yacc.c:1646  */
    break;

  case 431:
#line 1479 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, (yyvsp[-1].yyBool));
			}
#line 4685 "surface.c" /* yacc.c:1646  */
    break;

  case 432:
#line 1483 "surface.yy" /* yacc.c:1646  */
    {
			  MemoryCell::setShowGC((yyvsp[-1].yyBool));
			}
#line 4693 "surface.c" /* yacc.c:1646  */
    break;

  case 433:
#line 1487 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setPrintFlag((yyvsp[-2].yyPrintFlags), (yyvsp[-1].yyBool));
			}
#line 4701 "surface.c" /* yacc.c:1646  */
    break;

  case 434:
#line 1491 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE, (yyvsp[-1].yyBool));
			}
#line 4709 "surface.c" /* yacc.c:1646  */
    break;

  case 435:
#line 1495 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE_NEWLINE, (yyvsp[-1].yyBool));
			}
#line 4717 "surface.c" /* yacc.c:1646  */
    break;

  case 436:
#line 1499 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag((yyvsp[-2].yyFlags), (yyvsp[-1].yyBool));
			}
#line 4725 "surface.c" /* yacc.c:1646  */
    break;

  case 437:
#line 1503 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::BREAK, (yyvsp[-1].yyBool));
			}
#line 4733 "surface.c" /* yacc.c:1646  */
    break;

  case 438:
#line 1506 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4739 "surface.c" /* yacc.c:1646  */
    break;

  case 439:
#line 1507 "surface.yy" /* yacc.c:1646  */
    { lexerInitialMode(); }
#line 4745 "surface.c" /* yacc.c:1646  */
    break;

  case 440:
#line 1509 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setAutoImport((yyvsp[-5].yyImportMode), (yyvsp[-3].yyToken), (yyvsp[-1].yyBool));
			}
#line 4753 "surface.c" /* yacc.c:1646  */
    break;

  case 441:
#line 1512 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4759 "surface.c" /* yacc.c:1646  */
    break;

  case 442:
#line 1513 "surface.yy" /* yacc.c:1646  */
    { lexerInitialMode(); }
#line 4765 "surface.c" /* yacc.c:1646  */
    break;

  case 443:
#line 1515 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setOmodInclude((yyvsp[-3].yyToken), (yyvsp[-1].yyBool));
			}
#line 4773 "surface.c" /* yacc.c:1646  */
    break;

  case 444:
#line 1519 "surface.yy" /* yacc.c:1646  */
    {
			  globalVerboseFlag = (yyvsp[-1].yyBool);
			}
#line 4781 "surface.c" /* yacc.c:1646  */
    break;

  case 445:
#line 1523 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, (yyvsp[-1].yyBool));
			}
#line 4789 "surface.c" /* yacc.c:1646  */
    break;

  case 446:
#line 1527 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, (yyvsp[-1].yyBool));
			}
#line 4797 "surface.c" /* yacc.c:1646  */
    break;

  case 447:
#line 1531 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, (yyvsp[-1].yyBool));
			}
#line 4805 "surface.c" /* yacc.c:1646  */
    break;

  case 448:
#line 1535 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::PROFILE, (yyvsp[-1].yyBool));
			}
#line 4813 "surface.c" /* yacc.c:1646  */
    break;

  case 449:
#line 1539 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, (yyvsp[-1].yyBool));
			}
#line 4821 "surface.c" /* yacc.c:1646  */
    break;

  case 450:
#line 1546 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			}
#line 4829 "surface.c" /* yacc.c:1646  */
    break;

  case 451:
#line 1550 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			}
#line 4837 "surface.c" /* yacc.c:1646  */
    break;

  case 452:
#line 1554 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			}
#line 4845 "surface.c" /* yacc.c:1646  */
    break;

  case 453:
#line 1558 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			}
#line 4853 "surface.c" /* yacc.c:1646  */
    break;

  case 454:
#line 1565 "surface.yy" /* yacc.c:1646  */
    {
			  MemoryCell::setShowGC((yyvsp[-1].yyBool));
			}
#line 4861 "surface.c" /* yacc.c:1646  */
    break;

  case 455:
#line 1569 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[-1].yyBool));
			}
#line 4869 "surface.c" /* yacc.c:1646  */
    break;

  case 456:
#line 1575 "surface.yy" /* yacc.c:1646  */
    { lexerInitialMode(); }
#line 4875 "surface.c" /* yacc.c:1646  */
    break;

  case 458:
#line 1582 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_MIXFIX; }
#line 4881 "surface.c" /* yacc.c:1646  */
    break;

  case 459:
#line 1583 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FLAT; }
#line 4887 "surface.c" /* yacc.c:1646  */
    break;

  case 460:
#line 1584 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_ALIASES; }
#line 4893 "surface.c" /* yacc.c:1646  */
    break;

  case 461:
#line 1585 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_PARENS; }
#line 4899 "surface.c" /* yacc.c:1646  */
    break;

  case 462:
#line 1586 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_GRAPH; }
#line 4905 "surface.c" /* yacc.c:1646  */
    break;

  case 463:
#line 1587 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_CONCEAL; }
#line 4911 "surface.c" /* yacc.c:1646  */
    break;

  case 464:
#line 1588 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_NUMBER; }
#line 4917 "surface.c" /* yacc.c:1646  */
    break;

  case 465:
#line 1589 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_RAT; }
#line 4923 "surface.c" /* yacc.c:1646  */
    break;

  case 466:
#line 1590 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_COLOR; }
#line 4929 "surface.c" /* yacc.c:1646  */
    break;

  case 467:
#line 1591 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FORMAT; }
#line 4935 "surface.c" /* yacc.c:1646  */
    break;

  case 468:
#line 1594 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE; }
#line 4941 "surface.c" /* yacc.c:1646  */
    break;

  case 469:
#line 1595 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_CONDITION; }
#line 4947 "surface.c" /* yacc.c:1646  */
    break;

  case 470:
#line 1596 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_WHOLE; }
#line 4953 "surface.c" /* yacc.c:1646  */
    break;

  case 471:
#line 1597 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_SUBSTITUTION; }
#line 4959 "surface.c" /* yacc.c:1646  */
    break;

  case 472:
#line 1598 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_SELECT; }
#line 4965 "surface.c" /* yacc.c:1646  */
    break;

  case 473:
#line 1599 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_MB; }
#line 4971 "surface.c" /* yacc.c:1646  */
    break;

  case 474:
#line 1600 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_EQ; }
#line 4977 "surface.c" /* yacc.c:1646  */
    break;

  case 475:
#line 1601 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_RL; }
#line 4983 "surface.c" /* yacc.c:1646  */
    break;

  case 476:
#line 1602 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_REWRITE; }
#line 4989 "surface.c" /* yacc.c:1646  */
    break;

  case 477:
#line 1603 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_BODY; }
#line 4995 "surface.c" /* yacc.c:1646  */
    break;

  case 478:
#line 1604 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_BUILTIN; }
#line 5001 "surface.c" /* yacc.c:1646  */
    break;

  case 479:
#line 1607 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5007 "surface.c" /* yacc.c:1646  */
    break;

  case 480:
#line 1608 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5013 "surface.c" /* yacc.c:1646  */
    break;

  case 481:
#line 1611 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5019 "surface.c" /* yacc.c:1646  */
    break;

  case 482:
#line 1612 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5025 "surface.c" /* yacc.c:1646  */
    break;

  case 483:
#line 1615 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5031 "surface.c" /* yacc.c:1646  */
    break;

  case 484:
#line 1616 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5037 "surface.c" /* yacc.c:1646  */
    break;

  case 485:
#line 1619 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5043 "surface.c" /* yacc.c:1646  */
    break;

  case 486:
#line 1620 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5049 "surface.c" /* yacc.c:1646  */
    break;

  case 487:
#line 1625 "surface.yy" /* yacc.c:1646  */
    { (yyval.yySearchKind) = Interpreter::NARROW; }
#line 5055 "surface.c" /* yacc.c:1646  */
    break;

  case 488:
#line 1626 "surface.yy" /* yacc.c:1646  */
    { (yyval.yySearchKind) = Interpreter::XG_NARROW; }
#line 5061 "surface.c" /* yacc.c:1646  */
    break;

  case 489:
#line 1627 "surface.yy" /* yacc.c:1646  */
    { (yyval.yySearchKind) = Interpreter::SEARCH; }
#line 5067 "surface.c" /* yacc.c:1646  */
    break;

  case 490:
#line 1628 "surface.yy" /* yacc.c:1646  */
    { (yyval.yySearchKind) = Interpreter::SMT_SEARCH; }
#line 5073 "surface.c" /* yacc.c:1646  */
    break;

  case 491:
#line 1629 "surface.yy" /* yacc.c:1646  */
    { (yyval.yySearchKind) = Interpreter::VU_NARROW; }
#line 5079 "surface.c" /* yacc.c:1646  */
    break;

  case 492:
#line 1630 "surface.yy" /* yacc.c:1646  */
    { (yyval.yySearchKind) = Interpreter::FVU_NARROW; }
#line 5085 "surface.c" /* yacc.c:1646  */
    break;

  case 493:
#line 1633 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5091 "surface.c" /* yacc.c:1646  */
    break;

  case 494:
#line 1634 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5097 "surface.c" /* yacc.c:1646  */
    break;

  case 495:
#line 1637 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5103 "surface.c" /* yacc.c:1646  */
    break;

  case 496:
#line 1638 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5109 "surface.c" /* yacc.c:1646  */
    break;

  case 497:
#line 1641 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5115 "surface.c" /* yacc.c:1646  */
    break;

  case 498:
#line 1642 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5121 "surface.c" /* yacc.c:1646  */
    break;

  case 499:
#line 1645 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyInt64) = (yyvsp[0].yyInt64); }
#line 5127 "surface.c" /* yacc.c:1646  */
    break;

  case 500:
#line 1646 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyInt64) = NONE; }
#line 5133 "surface.c" /* yacc.c:1646  */
    break;

  case 501:
#line 1649 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyImportMode) = ImportModule::PROTECTING; }
#line 5139 "surface.c" /* yacc.c:1646  */
    break;

  case 502:
#line 1650 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyImportMode) = ImportModule::EXTENDING; }
#line 5145 "surface.c" /* yacc.c:1646  */
    break;

  case 503:
#line 1651 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyImportMode) = ImportModule::INCLUDING; }
#line 5151 "surface.c" /* yacc.c:1646  */
    break;

  case 505:
#line 1661 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5157 "surface.c" /* yacc.c:1646  */
    break;

  case 507:
#line 1665 "surface.yy" /* yacc.c:1646  */
    { moduleExpr = lexerBubble; lexBubble(END_COMMAND, 1); }
#line 5163 "surface.c" /* yacc.c:1646  */
    break;

  case 510:
#line 1677 "surface.yy" /* yacc.c:1646  */
    { lexSave((yyvsp[0].yyToken)); }
#line 5169 "surface.c" /* yacc.c:1646  */
    break;

  case 513:
#line 1680 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0);  }
#line 5175 "surface.c" /* yacc.c:1646  */
    break;

  case 515:
#line 1685 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5181 "surface.c" /* yacc.c:1646  */
    break;

  case 517:
#line 1687 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5187 "surface.c" /* yacc.c:1646  */
    break;

  case 520:
#line 1693 "surface.yy" /* yacc.c:1646  */
    { number = Token::codeToInt64(lexerBubble[1].code()); }
#line 5193 "surface.c" /* yacc.c:1646  */
    break;

  case 522:
#line 1695 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5199 "surface.c" /* yacc.c:1646  */
    break;

  case 525:
#line 1710 "surface.yy" /* yacc.c:1646  */
    { lexSave((yyvsp[0].yyToken)); }
#line 5205 "surface.c" /* yacc.c:1646  */
    break;

  case 528:
#line 1713 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5211 "surface.c" /* yacc.c:1646  */
    break;

  case 530:
#line 1722 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5217 "surface.c" /* yacc.c:1646  */
    break;

  case 532:
#line 1724 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5223 "surface.c" /* yacc.c:1646  */
    break;

  case 534:
#line 1726 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5229 "surface.c" /* yacc.c:1646  */
    break;

  case 537:
#line 1736 "surface.yy" /* yacc.c:1646  */
    { number = Token::codeToInt64(lexerBubble[1].code()); }
#line 5235 "surface.c" /* yacc.c:1646  */
    break;

  case 539:
#line 1738 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5241 "surface.c" /* yacc.c:1646  */
    break;

  case 541:
#line 1740 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5247 "surface.c" /* yacc.c:1646  */
    break;

  case 544:
#line 1750 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5253 "surface.c" /* yacc.c:1646  */
    break;

  case 546:
#line 1752 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5259 "surface.c" /* yacc.c:1646  */
    break;

  case 549:
#line 1763 "surface.yy" /* yacc.c:1646  */
    {
			  number = Token::codeToInt64(lexerBubble[1].code());
			  number2 = Token::codeToInt64(lexerBubble[3].code());
			  clear();
			}
#line 5269 "surface.c" /* yacc.c:1646  */
    break;

  case 551:
#line 1769 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5275 "surface.c" /* yacc.c:1646  */
    break;

  case 554:
#line 1779 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5281 "surface.c" /* yacc.c:1646  */
    break;

  case 556:
#line 1781 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5287 "surface.c" /* yacc.c:1646  */
    break;

  case 559:
#line 1791 "surface.yy" /* yacc.c:1646  */
    { number2 = Token::codeToInt64(lexerBubble[2].code()); }
#line 5293 "surface.c" /* yacc.c:1646  */
    break;

  case 561:
#line 1793 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5299 "surface.c" /* yacc.c:1646  */
    break;

  case 564:
#line 1798 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0, 1); }
#line 5305 "surface.c" /* yacc.c:1646  */
    break;

  case 567:
#line 1804 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 1, 1); }
#line 5311 "surface.c" /* yacc.c:1646  */
    break;

  case 569:
#line 1806 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_COLON | END_COMMAND, 0); }
#line 5317 "surface.c" /* yacc.c:1646  */
    break;

  case 571:
#line 1809 "surface.yy" /* yacc.c:1646  */
    {
			  lexerBubble.resize(1);
			  lexerBubble[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(lexerBubble[0]);
			}
#line 5327 "surface.c" /* yacc.c:1646  */
    break;

  case 609:
#line 1848 "surface.yy" /* yacc.c:1646  */
    {}
#line 5333 "surface.c" /* yacc.c:1646  */
    break;

  case 611:
#line 1853 "surface.yy" /* yacc.c:1646  */
    {
			  singleton[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(singleton[0]);
			  interpreter.addSelected(singleton);
			}
#line 5343 "surface.c" /* yacc.c:1646  */
    break;

  case 614:
#line 1864 "surface.yy" /* yacc.c:1646  */
    {
			  singleton[0] = (yyvsp[0].yyToken);
			  interpreter.addSelected(singleton);
			}
#line 5352 "surface.c" /* yacc.c:1646  */
    break;

  case 615:
#line 1869 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.addSelected(lexerBubble);
			}
#line 5360 "surface.c" /* yacc.c:1646  */
    break;


#line 5364 "surface.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1899 "surface.yy" /* yacc.c:1906  */


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
