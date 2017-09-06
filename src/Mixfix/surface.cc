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
    KW_ENDM = 361,
    KW_IMPORT = 362,
    KW_ENDV = 363,
    KW_SORT = 364,
    KW_SUBSORT = 365,
    KW_OP = 366,
    KW_OPS = 367,
    KW_MSGS = 368,
    KW_VAR = 369,
    KW_CLASS = 370,
    KW_SUBCLASS = 371,
    KW_MB = 372,
    KW_CMB = 373,
    KW_EQ = 374,
    KW_CEQ = 375,
    KW_RL = 376,
    KW_CRL = 377,
    KW_IS = 378,
    KW_FROM = 379,
    KW_ARROW = 380,
    KW_ARROW2 = 381,
    KW_PARTIAL = 382,
    KW_IF = 383,
    KW_LABEL = 384,
    KW_TO = 385,
    KW_COLON2 = 386,
    KW_ASSOC = 387,
    KW_COMM = 388,
    KW_ID = 389,
    KW_IDEM = 390,
    KW_ITER = 391,
    KW_LEFT = 392,
    KW_RIGHT = 393,
    KW_PREC = 394,
    KW_GATHER = 395,
    KW_METADATA = 396,
    KW_STRAT = 397,
    KW_POLY = 398,
    KW_MEMO = 399,
    KW_FROZEN = 400,
    KW_CTOR = 401,
    KW_LATEX = 402,
    KW_SPECIAL = 403,
    KW_CONFIG = 404,
    KW_OBJ = 405,
    KW_MSG = 406,
    KW_DITTO = 407,
    KW_FORMAT = 408,
    KW_ID_HOOK = 409,
    KW_OP_HOOK = 410,
    KW_TERM_HOOK = 411,
    KW_IN = 412,
    IDENTIFIER = 413,
    NUMERIC_ID = 414,
    ENDS_IN_DOT = 415,
    FORCE_LOOKAHEAD = 416
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

#line 354 "surface.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (UserLevelRewritingContext::ParseResult* parseResult);

#endif /* !YY_YY_SURFACE_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 116 "surface.yy" /* yacc.c:358  */

int yylex(YYSTYPE* lvalp);

#line 371 "surface.c" /* yacc.c:358  */

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
#define YYFINAL  117
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  176
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  246
/* YYNRULES -- Number of rules.  */
#define YYNRULES  621
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  929

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   416

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
     131,   132,   143,   142,   137,     2,   133,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   129,     2,
     134,   130,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   135,     2,   136,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   144,   138,   145,     2,     2,     2,     2,
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
     125,   126,   127,   128,   139,   140,   141,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175
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
    1628,  1629,  1632,  1633,  1636,  1637,  1640,  1641,  1644,  1645,
    1648,  1649,  1650,  1659,  1660,  1660,  1664,  1664,  1666,  1676,
    1676,  1678,  1679,  1679,  1684,  1684,  1686,  1686,  1688,  1692,
    1692,  1694,  1694,  1696,  1709,  1709,  1711,  1712,  1712,  1721,
    1721,  1723,  1723,  1725,  1725,  1727,  1735,  1735,  1737,  1737,
    1739,  1739,  1741,  1749,  1749,  1751,  1751,  1753,  1762,  1761,
    1768,  1768,  1770,  1778,  1778,  1780,  1780,  1782,  1790,  1790,
    1792,  1792,  1794,  1797,  1797,  1799,  1803,  1803,  1805,  1805,
    1807,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1821,  1821,
    1821,  1821,  1821,  1821,  1825,  1825,  1825,  1825,  1825,  1825,
    1829,  1829,  1829,  1829,  1829,  1829,  1833,  1833,  1833,  1833,
    1833,  1837,  1837,  1837,  1837,  1837,  1843,  1844,  1847,  1848,
    1851,  1858,  1859,  1862,  1867,  1874,  1874,  1874,  1874,  1874,
    1874,  1874
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
  "KW_VU_NARROW", "KW_ENDM", "KW_IMPORT", "KW_ENDV", "KW_SORT",
  "KW_SUBSORT", "KW_OP", "KW_OPS", "KW_MSGS", "KW_VAR", "KW_CLASS",
  "KW_SUBCLASS", "KW_MB", "KW_CMB", "KW_EQ", "KW_CEQ", "KW_RL", "KW_CRL",
  "KW_IS", "KW_FROM", "KW_ARROW", "KW_ARROW2", "KW_PARTIAL", "KW_IF",
  "':'", "'='", "'('", "')'", "'.'", "'<'", "'['", "']'", "','", "'|'",
  "KW_LABEL", "KW_TO", "KW_COLON2", "'+'", "'*'", "'{'", "'}'", "KW_ASSOC",
  "KW_COMM", "KW_ID", "KW_IDEM", "KW_ITER", "KW_LEFT", "KW_RIGHT",
  "KW_PREC", "KW_GATHER", "KW_METADATA", "KW_STRAT", "KW_POLY", "KW_MEMO",
  "KW_FROZEN", "KW_CTOR", "KW_LATEX", "KW_SPECIAL", "KW_CONFIG", "KW_OBJ",
  "KW_MSG", "KW_DITTO", "KW_FORMAT", "KW_ID_HOOK", "KW_OP_HOOK",
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,    58,
      61,    40,    41,    46,    60,    91,    93,    44,   124,   384,
     385,   386,    43,    42,   123,   125,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416
};
# endif

#define YYPACT_NINF -743

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-743)))

#define YYTABLE_NINF -496

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     691,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,   436,   471,    87,  -743,    -1,   205,
     -30,  -743,   -86,   -25,    28,    43,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,    92,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,   147,    47,  1073,   254,   254,   417,   254,     4,
     227,    29,    44,   125,   317,   317,   317,   -42,  -743,  -743,
    -743,   114,   317,  -743,  -743,  -743,   171,   -59,  -743,    86,
      90,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,   -76,  -743,  -743,
    -743,  -743,    72,  -743,  -743,  -743,  -743,   254,   254,   -76,
     236,   256,   271,   289,   254,   163,   300,  -743,  1073,   431,
     417,  -743,  -743,   175,   265,  -743,  -743,  -743,   213,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,   185,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   238,
     317,   317,   317,   317,   317,   317,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,   317,  -743,  -743,  -743,
     206,   323,  -743,  -743,  -743,  -743,  -743,   317,   317,  -743,
    -743,   180,   183,   191,   317,   317,   317,   317,   194,   309,
     -76,   -76,   196,   218,   290,   -76,  -743,  -743,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,  2160,  2160,
    -743,  -743,  -743,  2160,  2160,   222,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,   254,   417,  -743,   353,  -743,   431,   431,   417,
    -743,   275,   797,   -76,   -77,   -76,   440,   -76,   309,   317,
     317,   276,   281,   299,   301,   302,   303,   308,   317,   315,
    -743,  -743,   318,   319,  -743,  -743,  -743,   320,   321,   322,
     324,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,   326,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
     494,  -743,  -743,  -743,  -743,  -743,  -743,   250,   508,   -76,
    -743,  -743,  -743,   417,  -743,  -743,  -743,  -743,   797,   291,
     255,   312,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,   327,   333,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,   334,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,   317,  -743,  -743,  -743,  -743,  -743,  1073,   347,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,   417,  -743,   -28,   797,   331,   341,  -743,   -76,   -76,
     597,   -76,   317,  -743,  -743,  -743,   340,   -19,  -743,   -83,
    -743,  -743,   628,   674,   -76,  -743,  -743,  -743,   797,  -743,
    -743,  1073,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,   342,  -743,  1073,  -743,  -743,
    -743,   797,   247,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   291,    21,
      10,  -743,   254,   -76,  -743,  -743,   291,   350,  -743,   866,
    -743,  -743,  -743,  1142,  1142,  1349,  1073,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,   683,   -76,   254,  2142,
     -76,   347,  -743,  2100,  -743,  1073,  -743,   337,  -743,  1073,
    -743,  -743,  -743,  -743,   351,   177,   195,   199,  -743,   344,
     110,   253,   259,   355,   356,   234,   274,   277,   280,  -743,
    2100,   364,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
     935,  -743,  -743,  -743,  -743,  -743,  1004,  1211,  -743,  -743,
    2100,   370,   371,   373,   375,   381,   386,   372,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
     374,   369,  -743,  -743,  -743,   388,   378,   387,   111,  -743,
     866,  -743,  -743,  -743,  -743,  -743,  -743,  1625,  1556,  -743,
    -743,  1418,  -743,  1418,   397,  -743,   385,  1556,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,   254,   -76,  2151,   -76,    35,
    2100,  -743,  -743,   384,  1073,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  1418,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  1694,  -743,  -743,  -743,  -743,
    1694,  1832,   407,  -743,   -76,   413,   -76,   414,   -76,   419,
    1418,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   412,  -743,
    2100,  -743,  1349,  -743,  -743,  2100,  -743,  -743,  -743,  1966,
    -743,  2100,  -743,  -743,   420,  1487,  -743,  -743,   355,  -743,
    -743,   422,  -743,   427,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,   254,   -76,  -743,   409,
     -74,  1280,   369,    79,  1899,   428,  -743,   244,  -743,  2189,
     355,  -743,  -743,  -743,     2,  -743,  -743,  -743,  1832,  1073,
     -76,   -76,   -76,  -743,  -743,  1763,  -743,  -743,  -743,   397,
    -743,  -743,  2033,  -743,  -743,  -743,  2100,  -743,  -743,  -743,
    -743,  -743,   424,   426,   393,   439,   406,   448,   450,  -743,
     452,  -743,   453,   454,  -743,  -743,  -743,  -743,   455,   717,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,   355,  -743,   -76,  1694,  2100,  -743,   169,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   261,  -743,
    -743,  -743,   418,  -743,  1899,  -743,  -743,   369,   415,   461,
     463,   464,   151,  -743,   425,   425,   425,   425,   591,  1073,
    1073,  1073,    -4,  -743,   425,  -743,  -743,  2033,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,   -88,   -73,   -71,   -62,   466,
     468,   468,   468,  -743,  -743,   -41,   467,   425,   603,   425,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,   -27,   477,   -21,   -76,  -743,  -743,  -743,  -743
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   456,   108,   109,    69,   351,   382,   487,   488,   493,
     492,   373,   367,   489,     0,     0,     0,   347,     0,     0,
       0,   494,     0,     0,     0,     0,   353,   355,   349,    12,
      13,    15,    17,    18,    10,    20,    21,   380,   490,   491,
      91,     8,     0,     2,     6,     5,   384,     4,    93,     7,
     369,   371,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   468,     0,     0,     0,     0,     0,     0,   500,   501,
     502,     0,     0,   438,   394,   400,     0,     0,   396,     0,
       0,   398,   404,   406,   408,   410,   412,   414,   416,   418,
     423,   481,   482,   484,   483,   385,   387,     0,   485,   486,
     391,   389,     0,   450,   451,   452,   453,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,   357,   359,   497,     0,   361,   363,   365,   499,   457,
     311,   296,   312,   297,   298,   299,   300,   302,   301,   303,
     304,   305,   306,   307,   308,   309,   310,   289,   288,   315,
     318,   316,   319,   314,   317,   249,   313,   320,   321,   292,
     285,   287,   293,   286,   283,   284,   281,   282,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   339,   332,   333,
     334,   338,   335,   336,   337,   340,   341,   294,   342,   343,
     344,   345,   346,   280,   291,     0,   290,   245,   246,   295,
     247,   248,   322,   575,   566,   576,   573,   574,   577,   568,
     571,   572,   570,   352,   503,   504,   383,   581,   582,   509,
     580,   583,   578,   579,   374,   511,   512,   368,   441,     0,
       0,     0,     0,     0,     0,     0,   476,   477,   478,   470,
     472,   469,   471,   473,   474,   475,     0,   462,   458,   459,
       0,     0,   463,   464,   465,   466,   467,     0,     0,   479,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   403,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,   348,     0,     0,     0,   354,   356,   350,    14,
      16,    19,    11,   381,    92,     9,    94,   524,   370,   526,
     527,   372,     0,     0,   496,     0,   375,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     461,   460,     0,     0,   455,   437,   444,     0,     0,     0,
       0,   448,   620,   617,   618,   621,   619,   615,   616,   439,
     395,   401,   422,   420,     0,   397,   399,   405,   407,   409,
     411,   413,   415,   417,   419,   424,   610,   614,   386,   607,
       0,   612,   613,   388,   392,   390,   393,    99,     0,     0,
     358,   360,   377,     0,   362,   364,   366,   379,     0,    70,
      29,    31,    32,    34,    33,    35,   567,   506,   508,   569,
     505,   588,   563,   585,   586,   589,   587,   584,   514,   565,
     510,   518,   516,   513,   442,     0,     0,   432,   426,   428,
     431,   429,   425,   436,     0,   434,   433,   454,   446,   449,
     445,   447,     0,   421,   608,   606,   609,   611,     0,   229,
     600,   597,   598,   531,   599,   596,   529,   525,   535,   533,
     528,     0,   376,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,   427,   430,   435,     0,     0,   101,     0,
     228,   111,     0,     0,     0,   378,    39,    30,     0,    42,
      36,     0,   507,   564,   594,   592,   519,   595,   593,   590,
     591,   515,   523,   521,   517,     0,   440,     0,    98,   104,
     103,     0,     0,   553,   532,   557,   555,   605,   603,   536,
     538,   604,   601,   602,   530,   542,   540,   534,    71,     0,
       0,    41,     0,     0,   443,   100,   102,     0,    95,     0,
     113,   115,   117,     0,     0,     0,     0,   149,   122,   125,
     129,   132,   136,   139,   143,   110,     0,     0,     0,     0,
       0,   229,    46,     0,    51,     0,    43,    45,    48,     0,
      38,   520,   522,   151,   249,   251,   252,    28,   112,     0,
     231,   231,   231,   231,     0,   250,   253,   254,   255,   233,
       0,     0,   261,   264,   262,   265,   263,   259,   260,   162,
       0,   160,   161,   256,   257,   258,     0,     0,   158,   147,
       0,     0,     0,     0,     0,     0,     0,     0,   558,   554,
     562,   560,   556,   537,   543,   539,   547,   545,   541,    74,
     275,   273,   274,   269,   270,   276,   277,   271,   272,   266,
       0,   238,   239,   267,   268,    56,     0,     0,     0,    40,
       0,   230,    25,    26,    24,    22,    23,     0,     0,   236,
     118,     0,   159,     0,    76,   157,     0,     0,   123,   126,
     130,   133,   137,   140,   144,     0,     0,     0,     0,     0,
       0,   240,    54,     0,     0,    44,    47,    27,    30,    96,
      97,   114,   232,   235,   116,   234,   233,     0,   174,   175,
     179,   105,   165,   120,   164,     0,   177,   178,   146,    75,
       0,   152,     0,   150,     0,     0,     0,     0,     0,     0,
       0,   559,   561,   548,   544,   552,   550,   546,     0,    72,
       0,    79,     0,    73,    49,     0,   177,    52,    50,     0,
     119,     0,   173,   171,   184,   167,   107,   121,   231,   251,
     252,   153,   154,     0,   250,   253,   254,   255,   148,   124,
     127,   131,   134,   138,   141,   145,     0,     0,    81,     0,
       0,     0,   244,     0,     0,    59,   237,     0,   182,     0,
     231,   166,   169,   170,     0,   163,   176,   106,     0,     0,
       0,     0,     0,   549,   551,     0,    84,    87,    80,    76,
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   -40,
    -386,  -743,  -743,  -516,  -511,  -743,  -510,  -743,  -743,  -743,
    -743,  -743,  -743,   -31,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -257,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -183,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   -96,     0,
    -743,  -743,  -743,  -743,  -558,  -743,  -743,   112,  -743,  -702,
    -220,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -162,
    -104,    89,  -318,  -624,  -743,  -743,  -152,  -743,  -742,  -709,
    -553,  -743,  -743,  -743,  -743,  -743,  -195,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -576,  -743,  -246,    77,  -567,
     -50,    32,  -743,  -413,  -704,  -743,  -743,  -743,   -44,  -685,
    -524,  -743,  -743,  -533,  -525,   -49,  -743,  -502,  -494,  -395,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,   -32,   629,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,   -54,  -743,  -743,  -743,  -109,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,    88,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -363,
    -743,   -48,  -743,  -743,  -743,  -112,  -444,  -539,  -743,  -743,
     -33,  -743,   267,  -743,   269,  -239
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    42,    43,    44,   116,   113,   110,   111,   112,   578,
     399,   400,   401,   402,   403,   491,   404,   530,   490,   529,
     647,   566,   567,   568,   645,   775,   683,   736,   804,   847,
     872,   873,   907,   909,   908,    45,    54,   465,   561,   679,
     710,   733,   770,   840,   798,   842,   924,   843,   419,   377,
     115,    47,   118,   387,   691,   449,   477,   478,   511,   702,
     747,    48,   512,   555,   589,   590,   591,   697,   611,   714,
     612,   715,   790,   613,   716,   614,   717,   791,   615,   718,
     616,   719,   792,   617,   720,   666,   610,   712,   751,   752,
     607,   600,   601,   703,   784,   785,   704,   743,   705,   745,
     706,   741,   777,   780,   829,   830,   831,   862,   874,   884,
     875,   876,   877,   878,   886,   895,   882,   883,   481,   652,
     657,   658,   696,   707,   641,   735,   773,   845,   405,   583,
     602,   642,   584,   196,   197,   643,   199,   200,   201,   202,
      49,    97,   109,    55,   107,   108,   312,   313,   317,   318,
     319,    58,   119,   120,    57,   393,   461,   114,    56,   288,
     289,   294,   293,   270,   275,   278,   271,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   269,   442,   328,   472,
      53,   257,   246,   261,    95,    96,   100,    50,    51,    52,
     315,   321,    73,   213,   325,   409,   468,   224,   326,   327,
     420,   470,   471,   501,   532,   533,   308,   388,   389,   457,
     483,   482,   484,   524,   558,   559,   560,   625,   677,   678,
     724,   766,   767,   514,   556,   557,   619,   675,   676,   421,
     469,   214,   323,   324,   215,   226,   422,   503,   459,   526,
     378,   445,   379,   380,   381,   382
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,   292,   216,   742,   227,   198,   585,   310,   746,   225,
     195,   311,   463,   298,   653,   654,   655,   621,   603,   603,
     603,   608,   562,   580,   264,   458,   753,   774,   581,   582,
     359,   772,   802,   262,   263,   273,   728,   587,   516,   708,
     268,   236,   102,   783,   910,   588,   509,   103,   265,   605,
     605,   605,   407,   296,   297,   796,   290,   290,   510,   912,
     303,   913,   237,   238,   239,   240,   797,   241,   242,   198,
     914,   309,   225,   740,   306,   603,    98,    99,   487,   228,
     274,   603,   603,   665,   911,   247,   248,   249,   250,   424,
     251,   919,   117,   243,   244,   245,   765,   291,   291,   911,
     694,   911,   528,   753,   486,   925,   605,   502,   104,   713,
     911,   927,   605,   605,   464,   627,   266,   585,   507,   515,
     525,   252,   887,    91,    92,   536,   508,   698,   903,   699,
     563,   911,   564,   864,   580,   253,   254,   255,   726,   581,
     582,   867,   746,   729,   730,   911,   731,   569,   587,   732,
     640,   911,   744,   579,   258,   570,   588,   748,   121,   122,
     565,   105,    93,    94,   879,   880,   881,   123,   644,   124,
     125,   126,   127,   128,   360,   361,   106,   659,   754,   365,
     129,   787,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   786,   620,   267,   644,   626,   659,   331,   332,
     333,   334,   335,   336,   391,   310,   310,   603,   608,   756,
     396,   256,   272,   832,   337,   644,   800,   757,   339,   276,
     563,   786,   564,   277,   801,   342,   343,   406,   408,   410,
     295,   423,   347,   348,   349,   350,   259,   260,   605,   299,
     229,    91,    92,   651,   692,   695,   603,   665,   537,   846,
     565,   338,   -32,   -32,   695,   754,   383,   314,   390,   300,
     384,   385,   644,   644,   688,   225,   644,   734,   644,   309,
     309,   225,   644,   198,   863,   301,   230,   605,   231,   232,
     233,   234,   662,   316,   462,   644,   756,   892,   662,   329,
     330,   748,   302,   460,   757,   304,   235,   425,   426,   896,
     897,   898,   644,   305,   868,   869,   434,   320,   905,   322,
     644,   786,   870,   344,   725,   644,   345,   769,   871,  -292,
    -292,  -292,   868,   869,   346,   644,   692,   351,   778,   362,
     870,   921,  -279,   923,   906,   644,   871,  -293,  -293,  -293,
     644,  -291,  -291,  -291,   644,   225,   644,   259,   260,   198,
     644,   363,   485,   538,   539,   386,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     340,   341,   492,   493,   392,   504,  -290,  -290,  -290,   644,
     805,   806,   841,   203,   364,   204,   651,   205,   527,   206,
     207,   208,   651,   848,   448,   -34,   -34,   -34,   466,   198,
     644,   -33,   -33,   -33,   479,   394,   395,   644,   397,   427,
     476,   644,   554,   225,   428,   198,  -246,  -246,  -246,  -247,
    -247,  -247,  -248,  -248,  -248,   209,   210,   211,   212,   879,
     880,   881,   429,   464,   430,   431,   432,   572,   352,   198,
     505,   433,   198,    59,   353,   354,   355,   531,   435,   644,
     644,   436,   437,   438,   439,   440,   467,   441,   198,   443,
     473,   622,   198,   479,   628,    60,   474,   475,    61,   644,
     480,   488,   489,   506,   648,   534,    62,    74,   571,    75,
     356,   357,   358,   573,  -278,    63,   650,    64,   651,   656,
     586,    65,   644,   660,   604,   604,   604,   198,    76,   668,
     669,   674,   609,   670,   623,   671,    66,   672,    67,    68,
      69,    70,   673,   681,   680,    71,   198,   682,   684,   685,
     198,   646,   709,   711,   737,   649,    72,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
     758,   760,   762,   599,   599,   768,   217,   764,   204,   795,
     218,   604,   219,   220,   221,   779,   789,   604,   604,   788,
     217,    90,   204,   803,   218,   851,   307,   220,   221,   411,
     852,   412,   849,   290,   850,   413,   414,   415,   853,   854,
     722,   855,   727,   856,   857,   858,   859,   888,   209,   222,
     223,   212,   889,   885,   890,   891,   899,   894,   915,    40,
     599,   586,   209,   222,   223,   212,   599,   920,   922,   926,
     687,   416,   417,   418,   291,   893,   844,   686,   759,   535,
     761,   721,   763,   352,   866,    40,   834,   444,   771,   353,
     354,   355,   833,   606,   861,   198,   904,   450,   629,   412,
     738,   290,   667,   451,   452,   453,   739,   446,   101,   447,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   755,     0,     0,   356,   357,   358,   376,     0,
       0,   794,     0,     0,     0,     0,     0,     0,     0,   454,
     455,   456,   291,   604,     0,     0,     0,     0,     0,     0,
       0,    -3,     1,     0,   836,   837,   838,     2,     3,     4,
       5,     0,  -495,  -495,     6,     7,     8,     9,    10,    11,
      12,  -495,   793,  -495,  -495,  -495,  -495,  -495,    13,    14,
      15,     0,   604,    16,     0,     0,   494,    17,   412,     0,
     290,    18,   495,   496,   497,     0,     0,     0,     0,   755,
     198,     0,     0,     0,     0,   835,    19,   865,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   411,     0,   412,
       0,   290,    20,   413,   414,   415,     0,     0,   498,   499,
     500,   291,    21,     0,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,     0,   416,
     417,   513,   291,   517,     0,   412,     0,   290,     0,   518,
     519,   520,   494,     0,   412,     0,   290,     0,   495,   618,
     497,     0,    40,     0,     0,     0,     0,     0,   928,     0,
     198,   198,   198,     0,     0,   900,   901,   902,     0,     0,
       0,     0,     0,     0,     0,   521,   522,   523,   291,     0,
       0,     0,     0,   860,   498,   499,   500,   291,     0,     0,
       0,     0,    41,   807,   808,   809,   810,   811,   812,   813,
     814,   815,   816,   817,   818,   819,   820,   821,   822,   823,
     824,   825,   826,   827,   828,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     916,   917,   918,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   398,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
       0,   194,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   398,     0,   574,
     156,   157,   158,   575,   160,   161,   576,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,     0,
     577,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     592,   593,   594,   595,   661,   596,    40,     0,   597,   598,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,     0,   194,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   592,
     593,   594,   595,   663,   596,    40,     0,   597,   598,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,     0,   194,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,     0,   194,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   592,   593,   594,
     595,     0,   596,    40,     0,   597,   598,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,     0,   194,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   592,   593,   594,   595,
     664,   596,     0,     0,   597,   598,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,     0,   194,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   592,   593,   594,   595,   799,
     596,     0,     0,   597,   598,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,     0,   194,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   592,   593,   594,   595,     0,   596,
       0,     0,   597,   598,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,     0,   194,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   630,     0,   698,   631,   699,   632,     0,   633,     0,
       0,     0,     0,   700,     0,     0,   634,   635,   636,     0,
     637,   638,     0,     0,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     639,     0,   701,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     630,     0,     0,   631,     0,   632,   781,   633,     0,     0,
     782,     0,   700,     0,     0,   634,   635,   636,     0,   637,
     638,     0,     0,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   639,
       0,   701,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   630,
       0,     0,   631,     0,   632,     0,   633,     0,     0,   689,
     693,     0,     0,     0,   634,   635,   636,     0,   637,   638,
       0,     0,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   639,     0,
     690,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   630,     0,
       0,   631,     0,   632,     0,   633,     0,     0,   689,     0,
       0,     0,     0,   634,   635,   636,     0,   637,   638,     0,
       0,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   639,     0,   690,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   630,     0,     0,
     631,     0,   632,     0,   633,     0,     0,     0,     0,   700,
       0,     0,   634,   635,   636,     0,   637,   638,     0,     0,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   639,     0,   701,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   630,     0,     0,   631,
       0,   632,     0,   633,     0,     0,     0,     0,     0,     0,
       0,   634,   635,   636,     0,   637,   638,     0,     0,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   639,     0,   839,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,     0,   156,   157,   158,   749,
     160,   161,   750,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   630,     0,   698,   631,   699,   632,     0,   633,
       0,     0,     0,     0,   700,     0,     0,   634,   635,   636,
       0,   637,   638,     0,     0,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   639,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   630,
       0,     0,   631,     0,   632,     0,   633,     0,     0,     0,
     776,     0,     0,     0,   634,   635,   636,     0,   637,   638,
       0,     0,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   639,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   630,     0,     0,   631,
       0,   632,     0,   633,     0,     0,     0,     0,   700,     0,
       0,   634,   635,   636,     0,   637,   638,     0,     0,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   639,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   630,     0,     0,   631,     0,   632,     0,
     633,     0,     0,     0,     0,     0,     0,     0,   634,   635,
     636,     0,   637,   638,     0,     0,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   411,   639,   412,     0,   290,     0,   413,   414,   415,
     494,     0,   412,     0,   290,     0,   495,   723,   497,   352,
       0,    40,     0,     0,     0,   353,   354,   355,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   416,   417,   624,   291,     0,     0,     0,
       0,     0,   498,   499,   500,   291,     0,     0,     0,     0,
       0,   356,   357,   358,   376,   807,   808,   809,   810,   811,
     812,   813,   814,   815,   816,   817,   818,   819,   820,   821,
     822,   823,   824,   825,   826,   827,   828
};

static const yytype_int16 yycheck[] =
{
       0,    97,    56,   705,    58,    54,   539,   119,   710,    57,
      54,   120,   398,   109,   581,   582,   583,   556,   543,   544,
     545,   545,     1,   539,    66,   388,   711,   736,   539,   539,
     269,   735,   774,    65,    66,    94,     1,   539,   482,   663,
      72,    12,    72,   745,   132,   539,   129,   133,    90,   543,
     544,   545,   129,   107,   108,   129,   133,   133,   141,   132,
     114,   132,    33,    34,    35,    36,   140,    38,    39,   118,
     132,   119,   120,   697,   118,   600,    77,    78,   464,    75,
     139,   606,   607,   607,   172,    41,    42,    43,    44,   328,
      46,   132,     0,    64,    65,    66,   720,   174,   174,   172,
     658,   172,   488,   788,   132,   132,   600,   470,   133,   667,
     172,   132,   606,   607,   142,   559,   158,   650,   137,   482,
     483,    77,   864,    36,    37,   511,   145,   125,   132,   127,
     109,   172,   111,   842,   650,    91,    92,    93,   677,   650,
     650,   845,   844,   108,   109,   172,   111,   137,   650,   114,
     563,   172,   705,   539,    29,   145,   650,   710,    11,    12,
     139,   133,    75,    76,   168,   169,   170,    20,   563,    22,
      23,    24,    25,    26,   270,   271,   133,   590,   711,   275,
     133,   748,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   745,   556,    80,   590,   559,   610,   230,   231,
     232,   233,   234,   235,   313,   317,   318,   732,   732,   711,
     319,   167,    41,   780,   246,   610,   137,   711,   250,   133,
     109,   774,   111,   133,   145,   257,   258,   323,   324,   325,
     158,   327,   264,   265,   266,   267,    30,    31,   732,     3,
      13,    36,    37,   133,   657,   658,   771,   771,     1,   802,
     139,    45,   142,   143,   667,   788,   289,    82,   312,     3,
     293,   294,   657,   658,   650,   313,   661,   680,   663,   317,
     318,   319,   667,   322,   841,     4,    49,   771,    51,    52,
      53,    54,   600,    18,   393,   680,   788,   136,   606,    51,
      52,   844,     3,   389,   788,   132,    69,   329,   330,   875,
     876,   877,   697,     3,   153,   154,   338,    94,   884,   124,
     705,   864,   161,   133,   677,   710,   133,   730,   167,   142,
     143,   144,   153,   154,   133,   720,   739,   133,   741,   133,
     161,   907,   133,   909,   887,   730,   167,   142,   143,   144,
     735,   142,   143,   144,   739,   393,   741,    30,    31,   398,
     745,   133,   461,   106,   107,   133,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      47,    48,   468,   469,    21,   471,   142,   143,   144,   774,
     136,   137,   795,   129,    94,   131,   133,   133,   484,   135,
     136,   137,   133,   806,   144,   142,   143,   144,   143,   448,
     795,   142,   143,   144,   448,   317,   318,   802,   133,   133,
     442,   806,   165,   461,   133,   464,   142,   143,   144,   142,
     143,   144,   142,   143,   144,   171,   172,   173,   174,   168,
     169,   170,   133,   142,   133,   133,   133,   533,   129,   488,
     472,   133,   491,     7,   135,   136,   137,   491,   133,   844,
     845,   133,   133,   133,   133,   133,   144,   133,   507,   133,
     133,   557,   511,   507,   560,    29,   133,   133,    32,   864,
     123,   140,   131,   133,   137,   133,    40,     6,   532,     8,
     171,   172,   173,   133,   133,    49,   142,    51,   133,   133,
     539,    55,   887,   129,   543,   544,   545,   546,    27,   129,
     129,   129,   546,   130,   558,   130,    70,   126,    72,    73,
      74,    75,   126,   144,   140,    79,   565,   129,   140,   132,
     569,   565,   125,   138,   140,   569,    90,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     133,   128,   128,   543,   544,   133,   129,   128,   131,   140,
     133,   600,   135,   136,   137,   135,   129,   606,   607,   137,
     129,    90,   131,   135,   133,   172,   135,   136,   137,   129,
     131,   131,   148,   133,   148,   135,   136,   137,   172,   131,
     676,   131,   678,   131,   131,   131,   131,   172,   171,   172,
     173,   174,   131,   175,   131,   131,     5,   172,   132,   131,
     600,   650,   171,   172,   173,   174,   606,   140,     5,   132,
     650,   171,   172,   173,   174,   872,   799,   648,   714,   507,
     716,   675,   718,   129,   844,   131,   788,   133,   732,   135,
     136,   137,   784,   544,   829,   684,   882,   129,   561,   131,
     684,   133,   610,   135,   136,   137,   696,   380,    19,   380,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   711,    -1,    -1,   171,   172,   173,   174,    -1,
      -1,   767,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,   174,   732,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,   790,   791,   792,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   766,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,   771,    32,    -1,    -1,   129,    36,   131,    -1,
     133,    40,   135,   136,   137,    -1,    -1,    -1,    -1,   788,
     789,    -1,    -1,    -1,    -1,   789,    55,   843,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,   131,
      -1,   133,    71,   135,   136,   137,    -1,    -1,   171,   172,
     173,   174,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    -1,    -1,   171,
     172,   173,   174,   129,    -1,   131,    -1,   133,    -1,   135,
     136,   137,   129,    -1,   131,    -1,   133,    -1,   135,   136,
     137,    -1,   131,    -1,    -1,    -1,    -1,    -1,   924,    -1,
     879,   880,   881,    -1,    -1,   879,   880,   881,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   136,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   171,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     900,   901,   902,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
      -1,   174,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,   172,    -1,
     174,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,    -1,   174,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,    -1,   172,    -1,   174,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,    -1,   174,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,   130,   131,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,   172,    -1,   174,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,   172,    -1,   174,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,    -1,   174,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,   130,
      -1,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,   172,    -1,   174,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,    -1,   135,    -1,    -1,   138,   139,   140,    -1,
     142,   143,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
     172,    -1,   174,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    -1,    -1,   126,    -1,   128,   129,   130,    -1,    -1,
     133,    -1,   135,    -1,    -1,   138,   139,   140,    -1,   142,
     143,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
      -1,   174,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,    -1,   126,    -1,   128,    -1,   130,    -1,    -1,   133,
     134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,   172,    -1,
     174,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    -1,
      -1,   126,    -1,   128,    -1,   130,    -1,    -1,   133,    -1,
      -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,    -1,   174,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,    -1,
     126,    -1,   128,    -1,   130,    -1,    -1,    -1,    -1,   135,
      -1,    -1,   138,   139,   140,    -1,   142,   143,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,    -1,   172,    -1,   174,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    -1,    -1,   126,
      -1,   128,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,   143,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,    -1,   174,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,   172,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,   138,   139,   140,
      -1,   142,   143,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,   172,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,    -1,   126,    -1,   128,    -1,   130,    -1,    -1,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,   172,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    -1,    -1,   126,
      -1,   128,    -1,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,   138,   139,   140,    -1,   142,   143,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,    -1,    -1,   126,    -1,   128,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,    -1,   142,   143,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   129,   172,   131,    -1,   133,    -1,   135,   136,   137,
     129,    -1,   131,    -1,   133,    -1,   135,   136,   137,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,    -1,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
      -1,   171,   172,   173,   174,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    14,    15,    16,
      17,    18,    19,    27,    28,    29,    32,    36,    40,    55,
      71,    81,    83,    84,    85,    86,    87,    88,    89,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     131,   171,   177,   178,   179,   211,   225,   227,   237,   316,
     363,   364,   365,   356,   212,   319,   334,   330,   327,     7,
      29,    32,    40,    49,    51,    55,    70,    72,    73,    74,
      75,    79,    90,   368,     6,     8,    27,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      90,    36,    37,    75,    76,   360,   361,   317,    77,    78,
     362,   360,    72,   133,   133,   133,   133,   320,   321,   318,
     182,   183,   184,   181,   333,   226,   180,     0,   228,   328,
     329,    11,    12,    20,    22,    23,    24,    25,    26,   133,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   172,   174,   304,   309,   310,   311,   312,
     313,   314,   315,   129,   131,   133,   135,   136,   137,   171,
     172,   173,   174,   369,   407,   410,   369,   129,   133,   135,
     136,   137,   172,   173,   373,   407,   411,   369,    75,    13,
      49,    51,    52,    53,    54,    69,    12,    33,    34,    35,
      36,    38,    39,    64,    65,    66,   358,    41,    42,    43,
      44,    46,    77,    91,    92,    93,   167,   357,    29,    30,
      31,   359,   359,   359,    66,    90,   158,    80,   359,   352,
     339,   342,    41,    94,   139,   340,   133,   133,   341,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   335,   336,
     133,   174,   224,   338,   337,   158,   369,   369,   224,     3,
       3,     4,     3,   369,   132,     3,   304,   135,   382,   407,
     411,   373,   322,   323,    82,   366,    18,   324,   325,   326,
      94,   367,   124,   408,   409,   370,   374,   375,   354,    51,
      52,   359,   359,   359,   359,   359,   359,   359,    45,   359,
      47,    48,   359,   359,   133,   133,   133,   359,   359,   359,
     359,   133,   129,   135,   136,   137,   171,   172,   173,   421,
     224,   224,   133,   133,    94,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   174,   225,   416,   418,
     419,   420,   421,   416,   416,   416,   133,   229,   383,   384,
     369,   373,    21,   331,   382,   382,   373,   133,   131,   186,
     187,   188,   189,   190,   192,   304,   224,   129,   224,   371,
     224,   129,   131,   135,   136,   137,   171,   172,   173,   224,
     376,   405,   412,   224,   421,   359,   359,   133,   133,   133,
     133,   133,   133,   133,   359,   133,   133,   133,   133,   133,
     133,   133,   353,   133,   133,   417,   418,   420,   144,   231,
     129,   135,   136,   137,   171,   172,   173,   385,   405,   414,
     224,   332,   373,   186,   142,   213,   143,   144,   372,   406,
     377,   378,   355,   133,   133,   133,   359,   232,   233,   304,
     123,   294,   387,   386,   388,   373,   132,   186,   140,   131,
     194,   191,   224,   224,   129,   135,   136,   137,   171,   172,
     173,   379,   405,   413,   224,   359,   133,   137,   145,   129,
     141,   234,   238,   173,   399,   405,   412,   129,   135,   136,
     137,   171,   172,   173,   389,   405,   415,   224,   186,   195,
     193,   304,   380,   381,   133,   233,   186,     1,   106,   107,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   165,   239,   400,   401,   390,   391,
     392,   214,     1,   109,   111,   139,   197,   198,   199,   137,
     145,   369,   224,   133,   133,   137,   140,   174,   185,   186,
     189,   190,   192,   305,   308,   309,   311,   313,   314,   240,
     241,   242,   125,   126,   127,   128,   130,   133,   134,   225,
     267,   268,   306,   310,   311,   314,   267,   266,   306,   304,
     262,   244,   246,   249,   251,   254,   256,   259,   136,   402,
     405,   413,   224,   369,   173,   393,   405,   412,   224,   294,
     123,   126,   128,   130,   138,   139,   140,   142,   143,   172,
     299,   300,   307,   311,   315,   200,   304,   196,   137,   304,
     142,   133,   295,   295,   295,   295,   133,   296,   297,   299,
     129,   129,   268,   129,   129,   306,   261,   297,   129,   129,
     130,   130,   126,   126,   129,   403,   404,   394,   395,   215,
     140,   144,   129,   202,   140,   132,   199,   185,   186,   133,
     174,   230,   299,   134,   230,   299,   298,   243,   125,   127,
     135,   174,   235,   269,   272,   274,   276,   299,   269,   125,
     216,   138,   263,   230,   245,   247,   250,   252,   255,   257,
     260,   369,   224,   136,   396,   405,   413,   224,     1,   108,
     109,   111,   114,   217,   299,   301,   203,   140,   304,   296,
     269,   277,   235,   273,   276,   275,   235,   236,   276,   137,
     140,   264,   265,   305,   309,   311,   313,   314,   133,   224,
     128,   224,   128,   224,   128,   269,   397,   398,   133,   299,
     218,   266,   300,   302,   275,   201,   134,   278,   299,   135,
     279,   129,   133,   235,   270,   271,   276,   295,   137,   129,
     248,   253,   258,   369,   224,   140,   129,   140,   220,   129,
     137,   145,   274,   135,   204,   136,   137,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   280,
     281,   282,   295,   272,   265,   304,   224,   224,   224,   174,
     219,   299,   221,   223,   216,   303,   276,   205,   299,   148,
     148,   172,   131,   172,   131,   131,   131,   131,   131,   131,
     136,   282,   283,   295,   275,   224,   236,   300,   153,   154,
     161,   167,   206,   207,   284,   286,   287,   288,   289,   168,
     169,   170,   292,   293,   285,   175,   290,   274,   172,   131,
     131,   131,   136,   207,   172,   291,   291,   291,   291,     5,
     304,   304,   304,   132,   293,   291,   276,   208,   210,   209,
     132,   172,   132,   132,   132,   132,   225,   225,   225,   132,
     140,   291,     5,   291,   222,   132,   132,   132,   224
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   176,   177,   177,   178,   178,   178,   178,   180,   179,
     181,   179,   179,   182,   179,   183,   179,   179,   184,   179,
     179,   179,   185,   185,   185,   185,   185,   185,   185,   186,
     186,   187,   187,   188,   188,   188,   189,   191,   190,   192,
     193,   193,   195,   196,   194,   197,   197,   198,   198,   199,
     199,   200,   201,   199,   203,   202,   202,   205,   204,   204,
     206,   206,   207,   208,   207,   209,   207,   210,   207,   212,
     213,   214,   211,   215,   215,   216,   216,   217,   217,   218,
     217,   217,   219,   219,   221,   222,   220,   223,   220,   224,
     224,   226,   225,   228,   229,   227,   230,   230,   231,   231,
     232,   232,   233,   234,   234,   235,   236,   236,   237,   237,
     238,   238,   239,   240,   239,   241,   239,   242,   243,   239,
     239,   239,   244,   245,   239,   246,   247,   248,   239,   249,
     250,   239,   251,   252,   253,   239,   254,   255,   239,   256,
     257,   258,   239,   259,   260,   239,   239,   261,   239,   262,
     239,   239,   263,   263,   264,   264,   265,   266,   266,   267,
     267,   268,   268,   269,   269,   269,   270,   270,   271,   271,
     271,   272,   273,   273,   274,   274,   275,   275,   276,   277,
     276,   278,   278,   279,   279,   280,   280,   281,   281,   281,
     282,   282,   283,   282,   282,   282,   282,   284,   282,   285,
     282,   286,   282,   287,   282,   282,   282,   282,   288,   282,
     282,   282,   282,   282,   289,   282,   282,   282,   290,   290,
     291,   291,   292,   292,   293,   293,   293,   293,   294,   294,
     295,   295,   296,   296,   297,   297,   298,   297,   299,   300,
     301,   300,   303,   302,   302,   304,   304,   304,   304,   304,
     305,   305,   305,   305,   305,   305,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   308,   308,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     310,   310,   310,   310,   311,   311,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   313,   313,   313,   313,   313,   313,   313,
     314,   314,   314,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   317,   316,   318,
     316,   319,   316,   320,   316,   321,   316,   322,   316,   323,
     316,   324,   316,   325,   316,   326,   316,   327,   316,   328,
     316,   329,   316,   330,   316,   331,   316,   332,   316,   316,
     333,   316,   334,   316,   316,   335,   316,   336,   316,   337,
     316,   338,   316,   316,   339,   316,   340,   316,   341,   316,
     342,   316,   316,   316,   343,   316,   344,   316,   345,   316,
     346,   316,   347,   316,   348,   316,   349,   316,   350,   316,
     316,   316,   316,   351,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   352,   353,
     316,   354,   355,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   356,   316,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   359,
     359,   360,   360,   361,   361,   362,   362,   363,   363,   363,
     363,   363,   364,   364,   365,   365,   366,   366,   367,   367,
     368,   368,   368,   369,   370,   369,   372,   371,   371,   374,
     373,   373,   375,   373,   377,   376,   378,   376,   376,   380,
     379,   381,   379,   379,   383,   382,   382,   384,   382,   386,
     385,   387,   385,   388,   385,   385,   390,   389,   391,   389,
     392,   389,   389,   394,   393,   395,   393,   393,   397,   396,
     398,   396,   396,   400,   399,   401,   399,   399,   403,   402,
     404,   402,   402,   406,   405,   405,   408,   407,   409,   407,
     407,   410,   410,   410,   410,   410,   410,   410,   411,   411,
     411,   411,   411,   411,   412,   412,   412,   412,   412,   412,
     413,   413,   413,   413,   413,   413,   414,   414,   414,   414,
     414,   415,   415,   415,   415,   415,   416,   416,   417,   417,
     418,   419,   419,   420,   420,   421,   421,   421,   421,   421,
     421,   421
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
       1,     1,     1,     1,     1,     0,     1,     0,     1,     0,
       1,     1,     1,     1,     0,     3,     0,     3,     1,     0,
       3,     1,     0,     3,     0,     3,     0,     3,     1,     0,
       3,     0,     3,     1,     0,     3,     1,     0,     3,     0,
       3,     0,     3,     0,     3,     1,     0,     3,     0,     3,
       0,     3,     1,     0,     3,     0,     3,     1,     0,     3,
       0,     3,     1,     0,     3,     0,     3,     1,     0,     3,
       0,     3,     1,     0,     3,     1,     0,     3,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 2525 "surface.c" /* yacc.c:1646  */
    break;

  case 3:
#line 237 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			}
#line 2533 "surface.c" /* yacc.c:1646  */
    break;

  case 8:
#line 251 "surface.yy" /* yacc.c:1646  */
    { lexerFileNameMode(); }
#line 2539 "surface.c" /* yacc.c:1646  */
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
#line 2552 "surface.c" /* yacc.c:1646  */
    break;

  case 10:
#line 261 "surface.yy" /* yacc.c:1646  */
    { lexerFileNameMode(); }
#line 2558 "surface.c" /* yacc.c:1646  */
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
#line 2571 "surface.c" /* yacc.c:1646  */
    break;

  case 12:
#line 272 "surface.yy" /* yacc.c:1646  */
    {
			  cout << directoryManager.getCwd() << '\n';
			}
#line 2579 "surface.c" /* yacc.c:1646  */
    break;

  case 13:
#line 275 "surface.yy" /* yacc.c:1646  */
    { lexerFileNameMode(); }
#line 2585 "surface.c" /* yacc.c:1646  */
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
#line 2599 "surface.c" /* yacc.c:1646  */
    break;

  case 15:
#line 286 "surface.yy" /* yacc.c:1646  */
    { lexerFileNameMode(); }
#line 2605 "surface.c" /* yacc.c:1646  */
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
#line 2619 "surface.c" /* yacc.c:1646  */
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
#line 2634 "surface.c" /* yacc.c:1646  */
    break;

  case 18:
#line 308 "surface.yy" /* yacc.c:1646  */
    { lexerStringMode(); }
#line 2640 "surface.c" /* yacc.c:1646  */
    break;

  case 19:
#line 310 "surface.yy" /* yacc.c:1646  */
    {
			  system((string("ls") + (yyvsp[0].yyString)).c_str());
			}
#line 2648 "surface.c" /* yacc.c:1646  */
    break;

  case 20:
#line 314 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			}
#line 2657 "surface.c" /* yacc.c:1646  */
    break;

  case 21:
#line 319 "surface.yy" /* yacc.c:1646  */
    {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			}
#line 2668 "surface.c" /* yacc.c:1646  */
    break;

  case 22:
#line 352 "surface.yy" /* yacc.c:1646  */
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[-1].yyToken)));
                        }
#line 2676 "surface.c" /* yacc.c:1646  */
    break;

  case 23:
#line 356 "surface.yy" /* yacc.c:1646  */
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[-1].yyToken)));
                        }
#line 2684 "surface.c" /* yacc.c:1646  */
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
#line 2696 "surface.c" /* yacc.c:1646  */
    break;

  case 28:
#line 371 "surface.yy" /* yacc.c:1646  */
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  moduleExpressions.push(new ModuleExpression(t));
			}
#line 2707 "surface.c" /* yacc.c:1646  */
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
#line 2719 "surface.c" /* yacc.c:1646  */
    break;

  case 35:
#line 397 "surface.yy" /* yacc.c:1646  */
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[0].yyToken)));
                        }
#line 2727 "surface.c" /* yacc.c:1646  */
    break;

  case 36:
#line 404 "surface.yy" /* yacc.c:1646  */
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			}
#line 2738 "surface.c" /* yacc.c:1646  */
    break;

  case 37:
#line 412 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 2744 "surface.c" /* yacc.c:1646  */
    break;

  case 38:
#line 414 "surface.yy" /* yacc.c:1646  */
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, tokenSequence));
			}
#line 2754 "surface.c" /* yacc.c:1646  */
    break;

  case 39:
#line 421 "surface.yy" /* yacc.c:1646  */
    {}
#line 2760 "surface.c" /* yacc.c:1646  */
    break;

  case 40:
#line 424 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 2766 "surface.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 2772 "surface.c" /* yacc.c:1646  */
    break;

  case 42:
#line 432 "surface.yy" /* yacc.c:1646  */
    {
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			}
#line 2781 "surface.c" /* yacc.c:1646  */
    break;

  case 43:
#line 437 "surface.yy" /* yacc.c:1646  */
    {
			  currentSyntaxContainer = oldSyntaxContainer;
			}
#line 2789 "surface.c" /* yacc.c:1646  */
    break;

  case 49:
#line 452 "surface.yy" /* yacc.c:1646  */
    {
			  currentRenaming->addSortMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 2797 "surface.c" /* yacc.c:1646  */
    break;

  case 50:
#line 456 "surface.yy" /* yacc.c:1646  */
    {
			  currentRenaming->addLabelMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 2805 "surface.c" /* yacc.c:1646  */
    break;

  case 51:
#line 459 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_COLON | BAR_TO, 1); }
#line 2811 "surface.c" /* yacc.c:1646  */
    break;

  case 52:
#line 460 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1); }
#line 2817 "surface.c" /* yacc.c:1646  */
    break;

  case 53:
#line 461 "surface.yy" /* yacc.c:1646  */
    {}
#line 2823 "surface.c" /* yacc.c:1646  */
    break;

  case 54:
#line 466 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
#line 2829 "surface.c" /* yacc.c:1646  */
    break;

  case 55:
#line 467 "surface.yy" /* yacc.c:1646  */
    {}
#line 2835 "surface.c" /* yacc.c:1646  */
    break;

  case 56:
#line 468 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
#line 2841 "surface.c" /* yacc.c:1646  */
    break;

  case 57:
#line 474 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
#line 2847 "surface.c" /* yacc.c:1646  */
    break;

  case 58:
#line 475 "surface.yy" /* yacc.c:1646  */
    {}
#line 2853 "surface.c" /* yacc.c:1646  */
    break;

  case 59:
#line 476 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
#line 2859 "surface.c" /* yacc.c:1646  */
    break;

  case 62:
#line 483 "surface.yy" /* yacc.c:1646  */
    { currentRenaming->setPrec((yyvsp[0].yyToken)); }
#line 2865 "surface.c" /* yacc.c:1646  */
    break;

  case 63:
#line 484 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 2871 "surface.c" /* yacc.c:1646  */
    break;

  case 64:
#line 485 "surface.yy" /* yacc.c:1646  */
    { currentRenaming->setGather(tokenSequence); }
#line 2877 "surface.c" /* yacc.c:1646  */
    break;

  case 65:
#line 486 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 2883 "surface.c" /* yacc.c:1646  */
    break;

  case 66:
#line 487 "surface.yy" /* yacc.c:1646  */
    { currentRenaming->setFormat(tokenSequence); }
#line 2889 "surface.c" /* yacc.c:1646  */
    break;

  case 67:
#line 488 "surface.yy" /* yacc.c:1646  */
    { lexerLatexMode(); }
#line 2895 "surface.c" /* yacc.c:1646  */
    break;

  case 68:
#line 489 "surface.yy" /* yacc.c:1646  */
    { currentRenaming->setLatexMacro((yyvsp[-1].yyString)); }
#line 2901 "surface.c" /* yacc.c:1646  */
    break;

  case 69:
#line 495 "surface.yy" /* yacc.c:1646  */
    { lexerIdMode(); }
#line 2907 "surface.c" /* yacc.c:1646  */
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
#line 2919 "surface.c" /* yacc.c:1646  */
    break;

  case 71:
#line 505 "surface.yy" /* yacc.c:1646  */
    {
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			}
#line 2928 "surface.c" /* yacc.c:1646  */
    break;

  case 72:
#line 510 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  interpreter.insertView(((yyvsp[-9].yyToken)).code(), CV);
			  CV->finishView();
			}
#line 2939 "surface.c" /* yacc.c:1646  */
    break;

  case 75:
#line 523 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
				       ": skipping " << QUOTE("->") << " in variable declaration.");
			}
#line 2948 "surface.c" /* yacc.c:1646  */
    break;

  case 77:
#line 531 "surface.yy" /* yacc.c:1646  */
    {
			  CV->addSortMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 2956 "surface.c" /* yacc.c:1646  */
    break;

  case 78:
#line 534 "surface.yy" /* yacc.c:1646  */
    {}
#line 2962 "surface.c" /* yacc.c:1646  */
    break;

  case 79:
#line 535 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_COLON | BAR_TO, 1); }
#line 2968 "surface.c" /* yacc.c:1646  */
    break;

  case 82:
#line 540 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyToken) = (yyvsp[-1].yyToken); }
#line 2974 "surface.c" /* yacc.c:1646  */
    break;

  case 83:
#line 542 "surface.yy" /* yacc.c:1646  */
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  (yyval.yyToken) = t;
			}
#line 2985 "surface.c" /* yacc.c:1646  */
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
#line 2997 "surface.c" /* yacc.c:1646  */
    break;

  case 85:
#line 559 "surface.yy" /* yacc.c:1646  */
    {
			  lexBubble(END_STATEMENT, 1);
			}
#line 3005 "surface.c" /* yacc.c:1646  */
    break;

  case 86:
#line 563 "surface.yy" /* yacc.c:1646  */
    {
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			}
#line 3014 "surface.c" /* yacc.c:1646  */
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
#line 3028 "surface.c" /* yacc.c:1646  */
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
#line 3052 "surface.c" /* yacc.c:1646  */
    break;

  case 89:
#line 600 "surface.yy" /* yacc.c:1646  */
    {}
#line 3058 "surface.c" /* yacc.c:1646  */
    break;

  case 90:
#line 602 "surface.yy" /* yacc.c:1646  */
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  lexerBubble.append(t);
			}
#line 3069 "surface.c" /* yacc.c:1646  */
    break;

  case 91:
#line 610 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_RIGHT_PAREN, 1); }
#line 3075 "surface.c" /* yacc.c:1646  */
    break;

  case 92:
#line 611 "surface.yy" /* yacc.c:1646  */
    {}
#line 3081 "surface.c" /* yacc.c:1646  */
    break;

  case 93:
#line 617 "surface.yy" /* yacc.c:1646  */
    { lexerIdMode(); }
#line 3087 "surface.c" /* yacc.c:1646  */
    break;

  case 94:
#line 619 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setCurrentModule(new SyntacticPreModule((yyvsp[-2].yyToken), (yyvsp[0].yyToken)));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 3097 "surface.c" /* yacc.c:1646  */
    break;

  case 95:
#line 625 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule((yyvsp[0].yyToken));
			}
#line 3107 "surface.c" /* yacc.c:1646  */
    break;

  case 96:
#line 632 "surface.yy" /* yacc.c:1646  */
    {}
#line 3113 "surface.c" /* yacc.c:1646  */
    break;

  case 97:
#line 634 "surface.yy" /* yacc.c:1646  */
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  store(t);
			}
#line 3124 "surface.c" /* yacc.c:1646  */
    break;

  case 98:
#line 642 "surface.yy" /* yacc.c:1646  */
    {}
#line 3130 "surface.c" /* yacc.c:1646  */
    break;

  case 102:
#line 651 "surface.yy" /* yacc.c:1646  */
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter((yyvsp[-2].yyToken), me);
			}
#line 3140 "surface.c" /* yacc.c:1646  */
    break;

  case 103:
#line 658 "surface.yy" /* yacc.c:1646  */
    {}
#line 3146 "surface.c" /* yacc.c:1646  */
    break;

  case 104:
#line 660 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
			    ": saw " << QUOTE(':') << " instead of " <<
			    QUOTE("::") << " in parameter declaration.");
			}
#line 3156 "surface.c" /* yacc.c:1646  */
    break;

  case 105:
#line 668 "surface.yy" /* yacc.c:1646  */
    {
			  singleton[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(singleton[0]);
			  currentSyntaxContainer->addType(false, singleton);
			  (yyval.yyToken) = (yyvsp[0].yyToken);  // needed for line number
			}
#line 3167 "surface.c" /* yacc.c:1646  */
    break;

  case 107:
#line 677 "surface.yy" /* yacc.c:1646  */
    {}
#line 3173 "surface.c" /* yacc.c:1646  */
    break;

  case 112:
#line 688 "surface.yy" /* yacc.c:1646  */
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport((yyvsp[-1].yyToken), me);
			}
#line 3183 "surface.c" /* yacc.c:1646  */
    break;

  case 113:
#line 694 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3189 "surface.c" /* yacc.c:1646  */
    break;

  case 114:
#line 695 "surface.yy" /* yacc.c:1646  */
    { CM->addSortDecl(tokenSequence); }
#line 3195 "surface.c" /* yacc.c:1646  */
    break;

  case 115:
#line 697 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3201 "surface.c" /* yacc.c:1646  */
    break;

  case 116:
#line 698 "surface.yy" /* yacc.c:1646  */
    { CM->addSubsortDecl(tokenSequence); }
#line 3207 "surface.c" /* yacc.c:1646  */
    break;

  case 117:
#line 700 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_COLON, 1); }
#line 3213 "surface.c" /* yacc.c:1646  */
    break;

  case 118:
#line 701 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
#line 3219 "surface.c" /* yacc.c:1646  */
    break;

  case 119:
#line 702 "surface.yy" /* yacc.c:1646  */
    {}
#line 3225 "surface.c" /* yacc.c:1646  */
    break;

  case 120:
#line 704 "surface.yy" /* yacc.c:1646  */
    {}
#line 3231 "surface.c" /* yacc.c:1646  */
    break;

  case 121:
#line 706 "surface.yy" /* yacc.c:1646  */
    {}
#line 3237 "surface.c" /* yacc.c:1646  */
    break;

  case 122:
#line 708 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_COLON, 1); }
#line 3243 "surface.c" /* yacc.c:1646  */
    break;

  case 123:
#line 709 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3249 "surface.c" /* yacc.c:1646  */
    break;

  case 124:
#line 710 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3255 "surface.c" /* yacc.c:1646  */
    break;

  case 125:
#line 712 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_COLON, 1);  }
#line 3261 "surface.c" /* yacc.c:1646  */
    break;

  case 126:
#line 713 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); }
#line 3267 "surface.c" /* yacc.c:1646  */
    break;

  case 127:
#line 714 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3273 "surface.c" /* yacc.c:1646  */
    break;

  case 128:
#line 715 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3279 "surface.c" /* yacc.c:1646  */
    break;

  case 129:
#line 717 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_EQUALS, 1); }
#line 3285 "surface.c" /* yacc.c:1646  */
    break;

  case 130:
#line 718 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3291 "surface.c" /* yacc.c:1646  */
    break;

  case 131:
#line 719 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3297 "surface.c" /* yacc.c:1646  */
    break;

  case 132:
#line 721 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_EQUALS, 1); }
#line 3303 "surface.c" /* yacc.c:1646  */
    break;

  case 133:
#line 722 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); }
#line 3309 "surface.c" /* yacc.c:1646  */
    break;

  case 134:
#line 723 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3315 "surface.c" /* yacc.c:1646  */
    break;

  case 135:
#line 724 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3321 "surface.c" /* yacc.c:1646  */
    break;

  case 136:
#line 726 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_ARROW2, 1); }
#line 3327 "surface.c" /* yacc.c:1646  */
    break;

  case 137:
#line 727 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3333 "surface.c" /* yacc.c:1646  */
    break;

  case 138:
#line 728 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3339 "surface.c" /* yacc.c:1646  */
    break;

  case 139:
#line 730 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_ARROW2, 1); }
#line 3345 "surface.c" /* yacc.c:1646  */
    break;

  case 140:
#line 731 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); }
#line 3351 "surface.c" /* yacc.c:1646  */
    break;

  case 141:
#line 732 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 3357 "surface.c" /* yacc.c:1646  */
    break;

  case 142:
#line 733 "surface.yy" /* yacc.c:1646  */
    { CM->addStatement(lexerBubble); }
#line 3363 "surface.c" /* yacc.c:1646  */
    break;

  case 143:
#line 735 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_COLON, 1); }
#line 3369 "surface.c" /* yacc.c:1646  */
    break;

  case 144:
#line 736 "surface.yy" /* yacc.c:1646  */
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
#line 3375 "surface.c" /* yacc.c:1646  */
    break;

  case 145:
#line 737 "surface.yy" /* yacc.c:1646  */
    { CM->setFlag(SymbolType::MESSAGE); }
#line 3381 "surface.c" /* yacc.c:1646  */
    break;

  case 146:
#line 740 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::MESSAGE);
			}
#line 3389 "surface.c" /* yacc.c:1646  */
    break;

  case 147:
#line 745 "surface.yy" /* yacc.c:1646  */
    {
			}
#line 3396 "surface.c" /* yacc.c:1646  */
    break;

  case 148:
#line 748 "surface.yy" /* yacc.c:1646  */
    {
			}
#line 3403 "surface.c" /* yacc.c:1646  */
    break;

  case 149:
#line 751 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3409 "surface.c" /* yacc.c:1646  */
    break;

  case 150:
#line 752 "surface.yy" /* yacc.c:1646  */
    { CM->addSubsortDecl(tokenSequence); }
#line 3415 "surface.c" /* yacc.c:1646  */
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
#line 3428 "surface.c" /* yacc.c:1646  */
    break;

  case 152:
#line 765 "surface.yy" /* yacc.c:1646  */
    {}
#line 3434 "surface.c" /* yacc.c:1646  */
    break;

  case 153:
#line 766 "surface.yy" /* yacc.c:1646  */
    {}
#line 3440 "surface.c" /* yacc.c:1646  */
    break;

  case 156:
#line 774 "surface.yy" /* yacc.c:1646  */
    {
			}
#line 3447 "surface.c" /* yacc.c:1646  */
    break;

  case 157:
#line 778 "surface.yy" /* yacc.c:1646  */
    { currentSyntaxContainer->addVarDecl((yyvsp[0].yyToken)); }
#line 3453 "surface.c" /* yacc.c:1646  */
    break;

  case 158:
#line 779 "surface.yy" /* yacc.c:1646  */
    { currentSyntaxContainer->addVarDecl((yyvsp[0].yyToken)); }
#line 3459 "surface.c" /* yacc.c:1646  */
    break;

  case 161:
#line 786 "surface.yy" /* yacc.c:1646  */
    { singleton[0] = (yyvsp[0].yyToken); CM->addOpDecl(singleton); }
#line 3465 "surface.c" /* yacc.c:1646  */
    break;

  case 162:
#line 787 "surface.yy" /* yacc.c:1646  */
    { CM->addOpDecl(lexerBubble); }
#line 3471 "surface.c" /* yacc.c:1646  */
    break;

  case 165:
#line 793 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber(lineNumber) <<
				       ": missing " << QUOTE("->") << " in constant declaration.");
			}
#line 3480 "surface.c" /* yacc.c:1646  */
    break;

  case 166:
#line 800 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
				       ": skipping stray " << QUOTE(":") << " in operator declaration.");

			}
#line 3490 "surface.c" /* yacc.c:1646  */
    break;

  case 169:
#line 810 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			}
#line 3499 "surface.c" /* yacc.c:1646  */
    break;

  case 170:
#line 815 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			}
#line 3508 "surface.c" /* yacc.c:1646  */
    break;

  case 171:
#line 822 "surface.yy" /* yacc.c:1646  */
    {
			  if ((yyvsp[-1].yyBool))
			    CM->convertSortsToKinds();
			}
#line 3517 "surface.c" /* yacc.c:1646  */
    break;

  case 173:
#line 829 "surface.yy" /* yacc.c:1646  */
    {}
#line 3523 "surface.c" /* yacc.c:1646  */
    break;

  case 174:
#line 832 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 3529 "surface.c" /* yacc.c:1646  */
    break;

  case 175:
#line 833 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 3535 "surface.c" /* yacc.c:1646  */
    break;

  case 178:
#line 841 "surface.yy" /* yacc.c:1646  */
    {
			  singleton[0] = (yyvsp[0].yyToken);
			  currentSyntaxContainer->addType(false, singleton);
			}
#line 3544 "surface.c" /* yacc.c:1646  */
    break;

  case 179:
#line 845 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3550 "surface.c" /* yacc.c:1646  */
    break;

  case 180:
#line 847 "surface.yy" /* yacc.c:1646  */
    {
			  currentSyntaxContainer->addType(true, tokenSequence);
			}
#line 3558 "surface.c" /* yacc.c:1646  */
    break;

  case 181:
#line 852 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3564 "surface.c" /* yacc.c:1646  */
    break;

  case 182:
#line 853 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3570 "surface.c" /* yacc.c:1646  */
    break;

  case 183:
#line 856 "surface.yy" /* yacc.c:1646  */
    {}
#line 3576 "surface.c" /* yacc.c:1646  */
    break;

  case 187:
#line 865 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			}
#line 3584 "surface.c" /* yacc.c:1646  */
    break;

  case 188:
#line 869 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			}
#line 3592 "surface.c" /* yacc.c:1646  */
    break;

  case 189:
#line 873 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			}
#line 3600 "surface.c" /* yacc.c:1646  */
    break;

  case 190:
#line 879 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::ASSOC);
			}
#line 3608 "surface.c" /* yacc.c:1646  */
    break;

  case 191:
#line 883 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::COMM);
			}
#line 3616 "surface.c" /* yacc.c:1646  */
    break;

  case 192:
#line 886 "surface.yy" /* yacc.c:1646  */
    { lexBubble(BAR_RIGHT_BRACKET | BAR_OP_ATTRIBUTE, 1); }
#line 3622 "surface.c" /* yacc.c:1646  */
    break;

  case 193:
#line 887 "surface.yy" /* yacc.c:1646  */
    { CM->setIdentity(lexerBubble); }
#line 3628 "surface.c" /* yacc.c:1646  */
    break;

  case 194:
#line 889 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::IDEM);
			}
#line 3636 "surface.c" /* yacc.c:1646  */
    break;

  case 195:
#line 893 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::ITER);
			}
#line 3644 "surface.c" /* yacc.c:1646  */
    break;

  case 196:
#line 896 "surface.yy" /* yacc.c:1646  */
    { CM->setPrec((yyvsp[0].yyToken)); }
#line 3650 "surface.c" /* yacc.c:1646  */
    break;

  case 197:
#line 897 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3656 "surface.c" /* yacc.c:1646  */
    break;

  case 198:
#line 898 "surface.yy" /* yacc.c:1646  */
    { CM->setGather(tokenSequence); }
#line 3662 "surface.c" /* yacc.c:1646  */
    break;

  case 199:
#line 899 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3668 "surface.c" /* yacc.c:1646  */
    break;

  case 200:
#line 900 "surface.yy" /* yacc.c:1646  */
    { CM->setFormat(tokenSequence); }
#line 3674 "surface.c" /* yacc.c:1646  */
    break;

  case 201:
#line 901 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3680 "surface.c" /* yacc.c:1646  */
    break;

  case 202:
#line 902 "surface.yy" /* yacc.c:1646  */
    { CM->setStrat(tokenSequence); }
#line 3686 "surface.c" /* yacc.c:1646  */
    break;

  case 203:
#line 903 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3692 "surface.c" /* yacc.c:1646  */
    break;

  case 204:
#line 904 "surface.yy" /* yacc.c:1646  */
    { CM->setPoly(tokenSequence); }
#line 3698 "surface.c" /* yacc.c:1646  */
    break;

  case 205:
#line 906 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::MEMO);
			}
#line 3706 "surface.c" /* yacc.c:1646  */
    break;

  case 206:
#line 910 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::CTOR);
			}
#line 3714 "surface.c" /* yacc.c:1646  */
    break;

  case 207:
#line 914 "surface.yy" /* yacc.c:1646  */
    {
			  clear();
			  CM->setFrozen(tokenSequence);
			}
#line 3723 "surface.c" /* yacc.c:1646  */
    break;

  case 208:
#line 918 "surface.yy" /* yacc.c:1646  */
    { clear(); }
#line 3729 "surface.c" /* yacc.c:1646  */
    break;

  case 209:
#line 919 "surface.yy" /* yacc.c:1646  */
    { CM->setFrozen(tokenSequence); }
#line 3735 "surface.c" /* yacc.c:1646  */
    break;

  case 210:
#line 921 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::CONFIG);
			}
#line 3743 "surface.c" /* yacc.c:1646  */
    break;

  case 211:
#line 925 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::OBJECT);
			}
#line 3751 "surface.c" /* yacc.c:1646  */
    break;

  case 212:
#line 929 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::MESSAGE);
			}
#line 3759 "surface.c" /* yacc.c:1646  */
    break;

  case 213:
#line 933 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setMetadata((yyvsp[0].yyToken));
			}
#line 3767 "surface.c" /* yacc.c:1646  */
    break;

  case 214:
#line 936 "surface.yy" /* yacc.c:1646  */
    { lexerLatexMode(); }
#line 3773 "surface.c" /* yacc.c:1646  */
    break;

  case 215:
#line 937 "surface.yy" /* yacc.c:1646  */
    { CM->setLatexMacro((yyvsp[-1].yyString)); }
#line 3779 "surface.c" /* yacc.c:1646  */
    break;

  case 216:
#line 938 "surface.yy" /* yacc.c:1646  */
    {}
#line 3785 "surface.c" /* yacc.c:1646  */
    break;

  case 217:
#line 940 "surface.yy" /* yacc.c:1646  */
    {
			  CM->setFlag(SymbolType::DITTO);
			}
#line 3793 "surface.c" /* yacc.c:1646  */
    break;

  case 220:
#line 953 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3799 "surface.c" /* yacc.c:1646  */
    break;

  case 221:
#line 954 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3805 "surface.c" /* yacc.c:1646  */
    break;

  case 224:
#line 961 "surface.yy" /* yacc.c:1646  */
    { clear(); CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[0].yyToken), tokenSequence); }
#line 3811 "surface.c" /* yacc.c:1646  */
    break;

  case 225:
#line 962 "surface.yy" /* yacc.c:1646  */
    { CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[-1].yyToken), lexerBubble); }
#line 3817 "surface.c" /* yacc.c:1646  */
    break;

  case 226:
#line 963 "surface.yy" /* yacc.c:1646  */
    { CM->addHook(SyntacticPreModule::OP_HOOK, (yyvsp[-1].yyToken), lexerBubble); }
#line 3823 "surface.c" /* yacc.c:1646  */
    break;

  case 227:
#line 964 "surface.yy" /* yacc.c:1646  */
    { CM->addHook(SyntacticPreModule::TERM_HOOK, (yyvsp[-1].yyToken), lexerBubble); }
#line 3829 "surface.c" /* yacc.c:1646  */
    break;

  case 228:
#line 970 "surface.yy" /* yacc.c:1646  */
    {}
#line 3835 "surface.c" /* yacc.c:1646  */
    break;

  case 229:
#line 972 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing " <<
				       QUOTE("is") << " keyword.");
			}
#line 3844 "surface.c" /* yacc.c:1646  */
    break;

  case 230:
#line 978 "surface.yy" /* yacc.c:1646  */
    {}
#line 3850 "surface.c" /* yacc.c:1646  */
    break;

  case 231:
#line 980 "surface.yy" /* yacc.c:1646  */
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			}
#line 3858 "surface.c" /* yacc.c:1646  */
    break;

  case 232:
#line 988 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3864 "surface.c" /* yacc.c:1646  */
    break;

  case 234:
#line 992 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3870 "surface.c" /* yacc.c:1646  */
    break;

  case 235:
#line 993 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3876 "surface.c" /* yacc.c:1646  */
    break;

  case 236:
#line 994 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3882 "surface.c" /* yacc.c:1646  */
    break;

  case 237:
#line 995 "surface.yy" /* yacc.c:1646  */
    { store((yyvsp[0].yyToken)); }
#line 3888 "surface.c" /* yacc.c:1646  */
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
#line 3902 "surface.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1013 "surface.yy" /* yacc.c:1646  */
    { fragStore((yyvsp[0].yyToken)); }
#line 3908 "surface.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1014 "surface.yy" /* yacc.c:1646  */
    { fragStore((yyvsp[0].yyToken)); }
#line 3914 "surface.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1015 "surface.yy" /* yacc.c:1646  */
    { fragStore((yyvsp[0].yyToken)); }
#line 3920 "surface.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1018 "surface.yy" /* yacc.c:1646  */
    { fragStore((yyvsp[0].yyToken)); }
#line 3926 "surface.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1019 "surface.yy" /* yacc.c:1646  */
    {}
#line 3932 "surface.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1020 "surface.yy" /* yacc.c:1646  */
    {}
#line 3938 "surface.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1100 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 1); }
#line 3944 "surface.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1102 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setCurrentModule(lexerBubble);
			}
#line 3952 "surface.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1105 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 1); }
#line 3958 "surface.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1107 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->dump();
			}
#line 3967 "surface.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1112 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 3976 "surface.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1117 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(lexerBubble);
			}
#line 3986 "surface.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1124 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 3995 "surface.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1129 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(lexerBubble);
			}
#line 4005 "surface.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1136 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 4014 "surface.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1141 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sreduce(lexerBubble);
			}
#line 4024 "surface.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1148 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 4033 "surface.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1153 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(lexerBubble, (yyvsp[-3].yyBool));
			}
#line 4043 "surface.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1160 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4053 "surface.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1166 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(lexerBubble, number, (yyvsp[-3].yyBool));
			}
#line 4063 "surface.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1172 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
#line 4074 "surface.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1179 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(lexerBubble, number, number2, (yyvsp[-3].yyBool));
			}
#line 4084 "surface.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1185 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
#line 4095 "surface.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1192 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(lexerBubble, number, number2, (yyvsp[-3].yyBool));
			}
#line 4105 "surface.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1198 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4115 "surface.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1204 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, (yyvsp[-3].yyBool));
			}
#line 4125 "surface.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1211 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 4134 "surface.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1216 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.check(lexerBubble);
			}
#line 4144 "surface.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1223 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
#line 4155 "surface.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1230 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, (yyvsp[-2].yySearchKind));
			}
#line 4165 "surface.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1236 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4175 "surface.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1242 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(lexerBubble, (yyvsp[-2].yyBool), number);
			}
#line 4185 "surface.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1248 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4195 "surface.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1254 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.unify(lexerBubble, number);
			}
#line 4205 "surface.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1260 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4215 "surface.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1266 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantUnify(lexerBubble, number, (yyvsp[-4].yyBool));
			}
#line 4225 "surface.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1273 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
#line 4235 "surface.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1279 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.getVariants(lexerBubble, number, (yyvsp[-3].yyBool), (yyvsp[-5].yyBool));
			}
#line 4245 "surface.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1285 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.cont((yyvsp[-1].yyInt64), (yyvsp[-3].yyBool));
			}
#line 4253 "surface.c" /* yacc.c:1646  */
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
#line 4265 "surface.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1297 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.test(lexerBubble);
			    //interpreter.newNarrow(lexerBubble);

			}
#line 4277 "surface.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1305 "surface.yy" /* yacc.c:1646  */
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
#line 4286 "surface.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1310 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(lexerBubble);
			}
#line 4296 "surface.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1316 "surface.yy" /* yacc.c:1646  */
    {
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(lexerBubble);
			}
#line 4306 "surface.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1321 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4312 "surface.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1323 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  interpreter.traceSelect((yyvsp[-2].yyBool));
			}
#line 4321 "surface.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1327 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4327 "surface.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1329 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  interpreter.traceExclude((yyvsp[-2].yyBool));
			}
#line 4336 "surface.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1333 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4342 "surface.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1335 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  interpreter.breakSelect((yyvsp[-2].yyBool));
			}
#line 4351 "surface.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1339 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4357 "surface.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1341 "surface.yy" /* yacc.c:1646  */
    {
			  lexerInitialMode();
			  interpreter.printConceal((yyvsp[-2].yyBool));
			}
#line 4366 "surface.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1346 "surface.yy" /* yacc.c:1646  */
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			}
#line 4375 "surface.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1353 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4381 "surface.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1355 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			}
#line 4390 "surface.c" /* yacc.c:1646  */
    break;

  case 396:
#line 1359 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4396 "surface.c" /* yacc.c:1646  */
    break;

  case 397:
#line 1361 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			}
#line 4405 "surface.c" /* yacc.c:1646  */
    break;

  case 398:
#line 1365 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4411 "surface.c" /* yacc.c:1646  */
    break;

  case 399:
#line 1367 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(true);
			}
#line 4420 "surface.c" /* yacc.c:1646  */
    break;

  case 400:
#line 1371 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4426 "surface.c" /* yacc.c:1646  */
    break;

  case 401:
#line 1373 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showView();
			}
#line 4435 "surface.c" /* yacc.c:1646  */
    break;

  case 402:
#line 1378 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.showModules(true);
			}
#line 4443 "surface.c" /* yacc.c:1646  */
    break;

  case 403:
#line 1382 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.showNamedViews();
			}
#line 4451 "surface.c" /* yacc.c:1646  */
    break;

  case 404:
#line 1385 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4457 "surface.c" /* yacc.c:1646  */
    break;

  case 405:
#line 1387 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSortsAndSubsorts();
			}
#line 4466 "surface.c" /* yacc.c:1646  */
    break;

  case 406:
#line 1391 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4472 "surface.c" /* yacc.c:1646  */
    break;

  case 407:
#line 1393 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showOps();
			}
#line 4481 "surface.c" /* yacc.c:1646  */
    break;

  case 408:
#line 1397 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4487 "surface.c" /* yacc.c:1646  */
    break;

  case 409:
#line 1399 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showVars();
			}
#line 4496 "surface.c" /* yacc.c:1646  */
    break;

  case 410:
#line 1403 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4502 "surface.c" /* yacc.c:1646  */
    break;

  case 411:
#line 1405 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showMbs();
			}
#line 4511 "surface.c" /* yacc.c:1646  */
    break;

  case 412:
#line 1409 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4517 "surface.c" /* yacc.c:1646  */
    break;

  case 413:
#line 1411 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showEqs();
			}
#line 4526 "surface.c" /* yacc.c:1646  */
    break;

  case 414:
#line 1415 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4532 "surface.c" /* yacc.c:1646  */
    break;

  case 415:
#line 1417 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showRls();
			}
#line 4541 "surface.c" /* yacc.c:1646  */
    break;

  case 416:
#line 1421 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4547 "surface.c" /* yacc.c:1646  */
    break;

  case 417:
#line 1423 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSummary();
			}
#line 4556 "surface.c" /* yacc.c:1646  */
    break;

  case 418:
#line 1427 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4562 "surface.c" /* yacc.c:1646  */
    break;

  case 419:
#line 1429 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showKinds();
			}
#line 4571 "surface.c" /* yacc.c:1646  */
    break;

  case 420:
#line 1434 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.showSearchPath((yyvsp[-1].yyInt64));
			}
#line 4579 "surface.c" /* yacc.c:1646  */
    break;

  case 421:
#line 1438 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.showSearchPathLabels((yyvsp[-1].yyInt64));
			}
#line 4587 "surface.c" /* yacc.c:1646  */
    break;

  case 422:
#line 1442 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.showSearchGraph();
			}
#line 4595 "surface.c" /* yacc.c:1646  */
    break;

  case 423:
#line 1445 "surface.yy" /* yacc.c:1646  */
    { lexBubble(END_COMMAND, 0); }
#line 4601 "surface.c" /* yacc.c:1646  */
    break;

  case 424:
#line 1447 "surface.yy" /* yacc.c:1646  */
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showProfile();
			}
#line 4610 "surface.c" /* yacc.c:1646  */
    break;

  case 425:
#line 1455 "surface.yy" /* yacc.c:1646  */
    {
			  globalAdvisoryFlag = alwaysAdviseFlag ? true : (yyvsp[-1].yyBool);
			}
#line 4618 "surface.c" /* yacc.c:1646  */
    break;

  case 426:
#line 1459 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[-1].yyBool));
			}
#line 4626 "surface.c" /* yacc.c:1646  */
    break;

  case 427:
#line 1463 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, (yyvsp[-1].yyBool));
			}
#line 4634 "surface.c" /* yacc.c:1646  */
    break;

  case 428:
#line 1467 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, (yyvsp[-1].yyBool));
			}
#line 4642 "surface.c" /* yacc.c:1646  */
    break;

  case 429:
#line 1471 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, (yyvsp[-1].yyBool));
			}
#line 4650 "surface.c" /* yacc.c:1646  */
    break;

  case 430:
#line 1475 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, (yyvsp[-1].yyBool));
			}
#line 4658 "surface.c" /* yacc.c:1646  */
    break;

  case 431:
#line 1479 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, (yyvsp[-1].yyBool));
			}
#line 4666 "surface.c" /* yacc.c:1646  */
    break;

  case 432:
#line 1483 "surface.yy" /* yacc.c:1646  */
    {
			  MemoryCell::setShowGC((yyvsp[-1].yyBool));
			}
#line 4674 "surface.c" /* yacc.c:1646  */
    break;

  case 433:
#line 1487 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setPrintFlag((yyvsp[-2].yyPrintFlags), (yyvsp[-1].yyBool));
			}
#line 4682 "surface.c" /* yacc.c:1646  */
    break;

  case 434:
#line 1491 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE, (yyvsp[-1].yyBool));
			}
#line 4690 "surface.c" /* yacc.c:1646  */
    break;

  case 435:
#line 1495 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE_NEWLINE, (yyvsp[-1].yyBool));
			}
#line 4698 "surface.c" /* yacc.c:1646  */
    break;

  case 436:
#line 1499 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag((yyvsp[-2].yyFlags), (yyvsp[-1].yyBool));
			}
#line 4706 "surface.c" /* yacc.c:1646  */
    break;

  case 437:
#line 1503 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::BREAK, (yyvsp[-1].yyBool));
			}
#line 4714 "surface.c" /* yacc.c:1646  */
    break;

  case 438:
#line 1506 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4720 "surface.c" /* yacc.c:1646  */
    break;

  case 439:
#line 1507 "surface.yy" /* yacc.c:1646  */
    { lexerInitialMode(); }
#line 4726 "surface.c" /* yacc.c:1646  */
    break;

  case 440:
#line 1509 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setAutoImport((yyvsp[-5].yyImportMode), (yyvsp[-3].yyToken), (yyvsp[-1].yyBool));
			}
#line 4734 "surface.c" /* yacc.c:1646  */
    break;

  case 441:
#line 1512 "surface.yy" /* yacc.c:1646  */
    { lexerCmdMode(); }
#line 4740 "surface.c" /* yacc.c:1646  */
    break;

  case 442:
#line 1513 "surface.yy" /* yacc.c:1646  */
    { lexerInitialMode(); }
#line 4746 "surface.c" /* yacc.c:1646  */
    break;

  case 443:
#line 1515 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setOmodInclude((yyvsp[-3].yyToken), (yyvsp[-1].yyBool));
			}
#line 4754 "surface.c" /* yacc.c:1646  */
    break;

  case 444:
#line 1519 "surface.yy" /* yacc.c:1646  */
    {
			  globalVerboseFlag = (yyvsp[-1].yyBool);
			}
#line 4762 "surface.c" /* yacc.c:1646  */
    break;

  case 445:
#line 1523 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, (yyvsp[-1].yyBool));
			}
#line 4770 "surface.c" /* yacc.c:1646  */
    break;

  case 446:
#line 1527 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, (yyvsp[-1].yyBool));
			}
#line 4778 "surface.c" /* yacc.c:1646  */
    break;

  case 447:
#line 1531 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, (yyvsp[-1].yyBool));
			}
#line 4786 "surface.c" /* yacc.c:1646  */
    break;

  case 448:
#line 1535 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::PROFILE, (yyvsp[-1].yyBool));
			}
#line 4794 "surface.c" /* yacc.c:1646  */
    break;

  case 449:
#line 1539 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, (yyvsp[-1].yyBool));
			}
#line 4802 "surface.c" /* yacc.c:1646  */
    break;

  case 450:
#line 1546 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			}
#line 4810 "surface.c" /* yacc.c:1646  */
    break;

  case 451:
#line 1550 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			}
#line 4818 "surface.c" /* yacc.c:1646  */
    break;

  case 452:
#line 1554 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			}
#line 4826 "surface.c" /* yacc.c:1646  */
    break;

  case 453:
#line 1558 "surface.yy" /* yacc.c:1646  */
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			}
#line 4834 "surface.c" /* yacc.c:1646  */
    break;

  case 454:
#line 1565 "surface.yy" /* yacc.c:1646  */
    {
			  MemoryCell::setShowGC((yyvsp[-1].yyBool));
			}
#line 4842 "surface.c" /* yacc.c:1646  */
    break;

  case 455:
#line 1569 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[-1].yyBool));
			}
#line 4850 "surface.c" /* yacc.c:1646  */
    break;

  case 456:
#line 1575 "surface.yy" /* yacc.c:1646  */
    { lexerInitialMode(); }
#line 4856 "surface.c" /* yacc.c:1646  */
    break;

  case 458:
#line 1582 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_MIXFIX; }
#line 4862 "surface.c" /* yacc.c:1646  */
    break;

  case 459:
#line 1583 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FLAT; }
#line 4868 "surface.c" /* yacc.c:1646  */
    break;

  case 460:
#line 1584 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_ALIASES; }
#line 4874 "surface.c" /* yacc.c:1646  */
    break;

  case 461:
#line 1585 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_PARENS; }
#line 4880 "surface.c" /* yacc.c:1646  */
    break;

  case 462:
#line 1586 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_GRAPH; }
#line 4886 "surface.c" /* yacc.c:1646  */
    break;

  case 463:
#line 1587 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_CONCEAL; }
#line 4892 "surface.c" /* yacc.c:1646  */
    break;

  case 464:
#line 1588 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_NUMBER; }
#line 4898 "surface.c" /* yacc.c:1646  */
    break;

  case 465:
#line 1589 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_RAT; }
#line 4904 "surface.c" /* yacc.c:1646  */
    break;

  case 466:
#line 1590 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_COLOR; }
#line 4910 "surface.c" /* yacc.c:1646  */
    break;

  case 467:
#line 1591 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FORMAT; }
#line 4916 "surface.c" /* yacc.c:1646  */
    break;

  case 468:
#line 1594 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE; }
#line 4922 "surface.c" /* yacc.c:1646  */
    break;

  case 469:
#line 1595 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_CONDITION; }
#line 4928 "surface.c" /* yacc.c:1646  */
    break;

  case 470:
#line 1596 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_WHOLE; }
#line 4934 "surface.c" /* yacc.c:1646  */
    break;

  case 471:
#line 1597 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_SUBSTITUTION; }
#line 4940 "surface.c" /* yacc.c:1646  */
    break;

  case 472:
#line 1598 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_SELECT; }
#line 4946 "surface.c" /* yacc.c:1646  */
    break;

  case 473:
#line 1599 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_MB; }
#line 4952 "surface.c" /* yacc.c:1646  */
    break;

  case 474:
#line 1600 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_EQ; }
#line 4958 "surface.c" /* yacc.c:1646  */
    break;

  case 475:
#line 1601 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_RL; }
#line 4964 "surface.c" /* yacc.c:1646  */
    break;

  case 476:
#line 1602 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_REWRITE; }
#line 4970 "surface.c" /* yacc.c:1646  */
    break;

  case 477:
#line 1603 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_BODY; }
#line 4976 "surface.c" /* yacc.c:1646  */
    break;

  case 478:
#line 1604 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyFlags) = Interpreter::TRACE_BUILTIN; }
#line 4982 "surface.c" /* yacc.c:1646  */
    break;

  case 479:
#line 1607 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 4988 "surface.c" /* yacc.c:1646  */
    break;

  case 480:
#line 1608 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 4994 "surface.c" /* yacc.c:1646  */
    break;

  case 481:
#line 1611 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5000 "surface.c" /* yacc.c:1646  */
    break;

  case 482:
#line 1612 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5006 "surface.c" /* yacc.c:1646  */
    break;

  case 483:
#line 1615 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5012 "surface.c" /* yacc.c:1646  */
    break;

  case 484:
#line 1616 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5018 "surface.c" /* yacc.c:1646  */
    break;

  case 485:
#line 1619 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5024 "surface.c" /* yacc.c:1646  */
    break;

  case 486:
#line 1620 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5030 "surface.c" /* yacc.c:1646  */
    break;

  case 487:
#line 1625 "surface.yy" /* yacc.c:1646  */
    { (yyval.yySearchKind) = Interpreter::NARROW; }
#line 5036 "surface.c" /* yacc.c:1646  */
    break;

  case 488:
#line 1626 "surface.yy" /* yacc.c:1646  */
    { (yyval.yySearchKind) = Interpreter::XG_NARROW; }
#line 5042 "surface.c" /* yacc.c:1646  */
    break;

  case 489:
#line 1627 "surface.yy" /* yacc.c:1646  */
    { (yyval.yySearchKind) = Interpreter::SEARCH; }
#line 5048 "surface.c" /* yacc.c:1646  */
    break;

  case 490:
#line 1628 "surface.yy" /* yacc.c:1646  */
    { (yyval.yySearchKind) = Interpreter::SMT_SEARCH; }
#line 5054 "surface.c" /* yacc.c:1646  */
    break;

  case 491:
#line 1629 "surface.yy" /* yacc.c:1646  */
    { (yyval.yySearchKind) = Interpreter::VU_NARROW; }
#line 5060 "surface.c" /* yacc.c:1646  */
    break;

  case 492:
#line 1632 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5066 "surface.c" /* yacc.c:1646  */
    break;

  case 493:
#line 1633 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5072 "surface.c" /* yacc.c:1646  */
    break;

  case 494:
#line 1636 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5078 "surface.c" /* yacc.c:1646  */
    break;

  case 495:
#line 1637 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5084 "surface.c" /* yacc.c:1646  */
    break;

  case 496:
#line 1640 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = true; }
#line 5090 "surface.c" /* yacc.c:1646  */
    break;

  case 497:
#line 1641 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyBool) = false; }
#line 5096 "surface.c" /* yacc.c:1646  */
    break;

  case 498:
#line 1644 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyInt64) = (yyvsp[0].yyInt64); }
#line 5102 "surface.c" /* yacc.c:1646  */
    break;

  case 499:
#line 1645 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyInt64) = NONE; }
#line 5108 "surface.c" /* yacc.c:1646  */
    break;

  case 500:
#line 1648 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyImportMode) = ImportModule::PROTECTING; }
#line 5114 "surface.c" /* yacc.c:1646  */
    break;

  case 501:
#line 1649 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyImportMode) = ImportModule::EXTENDING; }
#line 5120 "surface.c" /* yacc.c:1646  */
    break;

  case 502:
#line 1650 "surface.yy" /* yacc.c:1646  */
    { (yyval.yyImportMode) = ImportModule::INCLUDING; }
#line 5126 "surface.c" /* yacc.c:1646  */
    break;

  case 504:
#line 1660 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5132 "surface.c" /* yacc.c:1646  */
    break;

  case 506:
#line 1664 "surface.yy" /* yacc.c:1646  */
    { moduleExpr = lexerBubble; lexBubble(END_COMMAND, 1); }
#line 5138 "surface.c" /* yacc.c:1646  */
    break;

  case 509:
#line 1676 "surface.yy" /* yacc.c:1646  */
    { lexSave((yyvsp[0].yyToken)); }
#line 5144 "surface.c" /* yacc.c:1646  */
    break;

  case 512:
#line 1679 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0);  }
#line 5150 "surface.c" /* yacc.c:1646  */
    break;

  case 514:
#line 1684 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5156 "surface.c" /* yacc.c:1646  */
    break;

  case 516:
#line 1686 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5162 "surface.c" /* yacc.c:1646  */
    break;

  case 519:
#line 1692 "surface.yy" /* yacc.c:1646  */
    { number = Token::codeToInt64(lexerBubble[1].code()); }
#line 5168 "surface.c" /* yacc.c:1646  */
    break;

  case 521:
#line 1694 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5174 "surface.c" /* yacc.c:1646  */
    break;

  case 524:
#line 1709 "surface.yy" /* yacc.c:1646  */
    { lexSave((yyvsp[0].yyToken)); }
#line 5180 "surface.c" /* yacc.c:1646  */
    break;

  case 527:
#line 1712 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5186 "surface.c" /* yacc.c:1646  */
    break;

  case 529:
#line 1721 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5192 "surface.c" /* yacc.c:1646  */
    break;

  case 531:
#line 1723 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5198 "surface.c" /* yacc.c:1646  */
    break;

  case 533:
#line 1725 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5204 "surface.c" /* yacc.c:1646  */
    break;

  case 536:
#line 1735 "surface.yy" /* yacc.c:1646  */
    { number = Token::codeToInt64(lexerBubble[1].code()); }
#line 5210 "surface.c" /* yacc.c:1646  */
    break;

  case 538:
#line 1737 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5216 "surface.c" /* yacc.c:1646  */
    break;

  case 540:
#line 1739 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5222 "surface.c" /* yacc.c:1646  */
    break;

  case 543:
#line 1749 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5228 "surface.c" /* yacc.c:1646  */
    break;

  case 545:
#line 1751 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5234 "surface.c" /* yacc.c:1646  */
    break;

  case 548:
#line 1762 "surface.yy" /* yacc.c:1646  */
    {
			  number = Token::codeToInt64(lexerBubble[1].code());
			  number2 = Token::codeToInt64(lexerBubble[3].code());
			  clear();
			}
#line 5244 "surface.c" /* yacc.c:1646  */
    break;

  case 550:
#line 1768 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5250 "surface.c" /* yacc.c:1646  */
    break;

  case 553:
#line 1778 "surface.yy" /* yacc.c:1646  */
    { lexContinueSave((yyvsp[0].yyToken)); }
#line 5256 "surface.c" /* yacc.c:1646  */
    break;

  case 555:
#line 1780 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5262 "surface.c" /* yacc.c:1646  */
    break;

  case 558:
#line 1790 "surface.yy" /* yacc.c:1646  */
    { number2 = Token::codeToInt64(lexerBubble[2].code()); }
#line 5268 "surface.c" /* yacc.c:1646  */
    break;

  case 560:
#line 1792 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 5274 "surface.c" /* yacc.c:1646  */
    break;

  case 563:
#line 1797 "surface.yy" /* yacc.c:1646  */
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0, 1); }
#line 5280 "surface.c" /* yacc.c:1646  */
    break;

  case 566:
#line 1803 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 1, 1); }
#line 5286 "surface.c" /* yacc.c:1646  */
    break;

  case 568:
#line 1805 "surface.yy" /* yacc.c:1646  */
    { lexBubble((yyvsp[0].yyToken), BAR_COLON | END_COMMAND, 0); }
#line 5292 "surface.c" /* yacc.c:1646  */
    break;

  case 570:
#line 1808 "surface.yy" /* yacc.c:1646  */
    {
			  lexerBubble.resize(1);
			  lexerBubble[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(lexerBubble[0]);
			}
#line 5302 "surface.c" /* yacc.c:1646  */
    break;

  case 608:
#line 1847 "surface.yy" /* yacc.c:1646  */
    {}
#line 5308 "surface.c" /* yacc.c:1646  */
    break;

  case 610:
#line 1852 "surface.yy" /* yacc.c:1646  */
    {
			  singleton[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(singleton[0]);
			  interpreter.addSelected(singleton);
			}
#line 5318 "surface.c" /* yacc.c:1646  */
    break;

  case 613:
#line 1863 "surface.yy" /* yacc.c:1646  */
    {
			  singleton[0] = (yyvsp[0].yyToken);
			  interpreter.addSelected(singleton);
			}
#line 5327 "surface.c" /* yacc.c:1646  */
    break;

  case 614:
#line 1868 "surface.yy" /* yacc.c:1646  */
    {
			  interpreter.addSelected(lexerBubble);
			}
#line 5335 "surface.c" /* yacc.c:1646  */
    break;


#line 5339 "surface.c" /* yacc.c:1646  */
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
#line 1898 "surface.yy" /* yacc.c:1906  */


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
