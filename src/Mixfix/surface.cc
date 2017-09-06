/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     KW_MATCH = 270,
     KW_XMATCH = 271,
     KW_UNIFY = 272,
     KW_XUNIFY = 273,
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
     KW_WHOLE = 285,
     KW_SELECT = 286,
     KW_DESELECT = 287,
     KW_CONDITION = 288,
     KW_SUBSTITUTION = 289,
     KW_PRINT = 290,
     KW_GRAPH = 291,
     KW_MIXFIX = 292,
     KW_FLAT = 293,
     KW_WITH = 294,
     KW_PARENS = 295,
     KW_ALIASES = 296,
     KW_GC = 297,
     KW_TIME = 298,
     KW_STATS = 299,
     KW_TIMING = 300,
     KW_CMD = 301,
     KW_BREAKDOWN = 302,
     KW_BREAK = 303,
     KW_PATH = 304,
     KW_MODULE = 305,
     KW_MODULES = 306,
     KW_VIEWS = 307,
     KW_ALL = 308,
     KW_SORTS = 309,
     KW_OPS = 310,
     KW_VARS = 311,
     KW_MBS = 312,
     KW_EQS = 313,
     KW_RLS = 314,
     KW_SUMMARY = 315,
     KW_KINDS = 316,
     KW_ADVISE = 317,
     KW_VERBOSE = 318,
     KW_DO = 319,
     KW_CLEAR = 320,
     KW_PROTECT = 321,
     KW_EXTEND = 322,
     KW_INCLUDE = 323,
     KW_EXCLUDE = 324,
     KW_CONCEAL = 325,
     KW_REVEAL = 326,
     KW_COMPILE = 327,
     KW_COUNT = 328,
     KW_DEBUG = 329,
     KW_RESUME = 330,
     KW_ABORT = 331,
     KW_STEP = 332,
     KW_WHERE = 333,
     KW_CREDUCE = 334,
     KW_DUMP = 335,
     KW_PROFILE = 336,
     KW_NUMBER = 337,
     KW_RAT = 338,
     KW_COLOR = 339,
     SIMPLE_NUMBER = 340,
     KW_PWD = 341,
     KW_CD = 342,
     KW_PUSHD = 343,
     KW_POPD = 344,
     KW_LS = 345,
     KW_LOAD = 346,
     KW_QUIT = 347,
     KW_EOF = 348,
     KW_ENDM = 349,
     KW_IMPORT = 350,
     KW_ENDV = 351,
     KW_SORT = 352,
     KW_SUBSORT = 353,
     KW_OP = 354,
     KW_MSGS = 355,
     KW_VAR = 356,
     KW_CLASS = 357,
     KW_SUBCLASS = 358,
     KW_MB = 359,
     KW_CMB = 360,
     KW_EQ = 361,
     KW_CEQ = 362,
     KW_RL = 363,
     KW_CRL = 364,
     KW_IS = 365,
     KW_FROM = 366,
     KW_ARROW = 367,
     KW_ARROW2 = 368,
     KW_PARTIAL = 369,
     KW_IF = 370,
     KW_LABEL = 371,
     KW_TO = 372,
     KW_COLON2 = 373,
     KW_ASSOC = 374,
     KW_COMM = 375,
     KW_ID = 376,
     KW_IDEM = 377,
     KW_ITER = 378,
     KW_LEFT = 379,
     KW_RIGHT = 380,
     KW_PREC = 381,
     KW_GATHER = 382,
     KW_METADATA = 383,
     KW_STRAT = 384,
     KW_POLY = 385,
     KW_MEMO = 386,
     KW_FROZEN = 387,
     KW_CTOR = 388,
     KW_LATEX = 389,
     KW_SPECIAL = 390,
     KW_CONFIG = 391,
     KW_OBJ = 392,
     KW_MSG = 393,
     KW_DITTO = 394,
     KW_FORMAT = 395,
     KW_ID_HOOK = 396,
     KW_OP_HOOK = 397,
     KW_TERM_HOOK = 398,
     KW_IN = 399,
     IDENTIFIER = 400,
     NUMERIC_ID = 401,
     ENDS_IN_DOT = 402
   };
#endif
#define FILE_NAME_STRING 258
#define UNINTERPRETED_STRING 259
#define LATEX_STRING 260
#define KW_MOD 261
#define KW_OMOD 262
#define KW_VIEW 263
#define KW_PARSE 264
#define KW_NORMALIZE 265
#define KW_REDUCE 266
#define KW_REWRITE 267
#define KW_LOOP 268
#define KW_NARROW 269
#define KW_MATCH 270
#define KW_XMATCH 271
#define KW_UNIFY 272
#define KW_XUNIFY 273
#define KW_EREWRITE 274
#define KW_FREWRITE 275
#define KW_SREWRITE 276
#define KW_CONTINUE 277
#define KW_SEARCH 278
#define KW_SET 279
#define KW_SHOW 280
#define KW_ON 281
#define KW_OFF 282
#define KW_TRACE 283
#define KW_BODY 284
#define KW_WHOLE 285
#define KW_SELECT 286
#define KW_DESELECT 287
#define KW_CONDITION 288
#define KW_SUBSTITUTION 289
#define KW_PRINT 290
#define KW_GRAPH 291
#define KW_MIXFIX 292
#define KW_FLAT 293
#define KW_WITH 294
#define KW_PARENS 295
#define KW_ALIASES 296
#define KW_GC 297
#define KW_TIME 298
#define KW_STATS 299
#define KW_TIMING 300
#define KW_CMD 301
#define KW_BREAKDOWN 302
#define KW_BREAK 303
#define KW_PATH 304
#define KW_MODULE 305
#define KW_MODULES 306
#define KW_VIEWS 307
#define KW_ALL 308
#define KW_SORTS 309
#define KW_OPS 310
#define KW_VARS 311
#define KW_MBS 312
#define KW_EQS 313
#define KW_RLS 314
#define KW_SUMMARY 315
#define KW_KINDS 316
#define KW_ADVISE 317
#define KW_VERBOSE 318
#define KW_DO 319
#define KW_CLEAR 320
#define KW_PROTECT 321
#define KW_EXTEND 322
#define KW_INCLUDE 323
#define KW_EXCLUDE 324
#define KW_CONCEAL 325
#define KW_REVEAL 326
#define KW_COMPILE 327
#define KW_COUNT 328
#define KW_DEBUG 329
#define KW_RESUME 330
#define KW_ABORT 331
#define KW_STEP 332
#define KW_WHERE 333
#define KW_CREDUCE 334
#define KW_DUMP 335
#define KW_PROFILE 336
#define KW_NUMBER 337
#define KW_RAT 338
#define KW_COLOR 339
#define SIMPLE_NUMBER 340
#define KW_PWD 341
#define KW_CD 342
#define KW_PUSHD 343
#define KW_POPD 344
#define KW_LS 345
#define KW_LOAD 346
#define KW_QUIT 347
#define KW_EOF 348
#define KW_ENDM 349
#define KW_IMPORT 350
#define KW_ENDV 351
#define KW_SORT 352
#define KW_SUBSORT 353
#define KW_OP 354
#define KW_MSGS 355
#define KW_VAR 356
#define KW_CLASS 357
#define KW_SUBCLASS 358
#define KW_MB 359
#define KW_CMB 360
#define KW_EQ 361
#define KW_CEQ 362
#define KW_RL 363
#define KW_CRL 364
#define KW_IS 365
#define KW_FROM 366
#define KW_ARROW 367
#define KW_ARROW2 368
#define KW_PARTIAL 369
#define KW_IF 370
#define KW_LABEL 371
#define KW_TO 372
#define KW_COLON2 373
#define KW_ASSOC 374
#define KW_COMM 375
#define KW_ID 376
#define KW_IDEM 377
#define KW_ITER 378
#define KW_LEFT 379
#define KW_RIGHT 380
#define KW_PREC 381
#define KW_GATHER 382
#define KW_METADATA 383
#define KW_STRAT 384
#define KW_POLY 385
#define KW_MEMO 386
#define KW_FROZEN 387
#define KW_CTOR 388
#define KW_LATEX 389
#define KW_SPECIAL 390
#define KW_CONFIG 391
#define KW_OBJ 392
#define KW_MSG 393
#define KW_DITTO 394
#define KW_FORMAT 395
#define KW_ID_HOOK 396
#define KW_OP_HOOK 397
#define KW_TERM_HOOK 398
#define KW_IN 399
#define IDENTIFIER 400
#define NUMERIC_ID 401
#define ENDS_IN_DOT 402




/* Copy the first part of user declarations.  */
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
#include "preModule.hh"
#include "visibleModule.hh"  // HACK
#include "userLevelRewritingContext.hh"
#include "interpreter.hh"

#include "main.hh"
#define clear()			bubble.contractTo(0);
#define store(token)		bubble.append(token)
#define fragClear()		fragments.contractTo(0);
#define fragStore(token)	fragments.append(token)
#define YYPARSE_PARAM	parseResult
#define PARSE_RESULT	(*((UserLevelRewritingContext::ParseResult*) parseResult))

#define CM		interpreter.getCurrentModule()
#define CV		interpreter.getCurrentView()

void lexerInitialMode();
void lexerIdMode();
void lexerCmdMode();
void lexerFileNameMode();
void lexerStringMode();
void lexerLatexMode();
bool handleEof();
bool includeFile(const string& directory, const string& fileName, bool silent, int lineNr);
void eatComment(bool firstNonWhite);

Vector<Token> bubble;
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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 98 "surface.yy"
typedef union YYSTYPE {
  bool yyBool;
  Int64 yyInt64;
  const char* yyString;
  Token yyToken;
  ImportModule::ImportMode yyImportMode;
  Interpreter::Flags yyFlags;
  Interpreter::PrintFlags yyPrintFlags;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 448 "surface.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 108 "surface.yy"

int yylex(YYSTYPE* lvalp);


/* Line 214 of yacc.c.  */
#line 463 "surface.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  104
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6988

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  162
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  277
/* YYNRULES -- Number of rules. */
#define YYNRULES  732
/* YYNRULES -- Number of states. */
#define YYNSTATES  1126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   402

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     118,   119,   130,   129,   124,     2,   120,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   116,     2,
     121,   117,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   122,     2,   123,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   131,   125,   132,     2,     2,     2,     2,
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
     115,   126,   127,   128,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    12,    14,    15,
      19,    20,    24,    26,    27,    31,    32,    36,    38,    39,
      43,    45,    47,    50,    53,    56,    59,    62,    66,    68,
      70,    74,    76,    78,    80,    82,    84,    88,    89,    95,
      99,   103,   105,   106,   107,   113,   115,   117,   121,   123,
     128,   133,   140,   141,   145,   146,   151,   156,   157,   158,
     162,   163,   168,   172,   173,   176,   178,   181,   182,   188,
     189,   195,   196,   202,   203,   204,   205,   218,   221,   222,
     227,   232,   233,   238,   241,   244,   246,   247,   248,   257,
     258,   262,   263,   264,   273,   275,   277,   281,   282,   286,
     288,   292,   294,   297,   299,   302,   304,   306,   308,   311,
     312,   315,   316,   321,   322,   327,   331,   335,   340,   341,
     342,   349,   350,   351,   352,   362,   363,   364,   371,   372,
     373,   374,   384,   385,   386,   393,   394,   395,   396,   406,
     410,   414,   415,   421,   422,   427,   430,   432,   435,   437,
     441,   445,   448,   450,   451,   455,   456,   461,   464,   466,
     468,   469,   474,   479,   483,   485,   487,   489,   492,   493,
     495,   496,   501,   505,   507,   511,   512,   515,   517,   519,
     522,   525,   527,   529,   530,   534,   536,   538,   541,   542,
     548,   549,   555,   556,   562,   563,   569,   571,   573,   575,
     576,   582,   584,   586,   588,   591,   592,   598,   603,   605,
     608,   610,   613,   615,   618,   619,   626,   627,   634,   635,
     642,   644,   645,   647,   648,   651,   652,   655,   658,   659,
     664,   665,   671,   674,   675,   676,   682,   685,   686,   687,
     693,   696,   697,   698,   704,   707,   708,   709,   715,   718,
     719,   720,   726,   729,   730,   731,   737,   740,   741,   743,
     746,   748,   749,   754,   755,   761,   764,   767,   769,   771,
     773,   774,   780,   781,   786,   788,   790,   793,   795,   797,
     799,   801,   802,   807,   809,   811,   813,   815,   817,   819,
     821,   823,   825,   827,   829,   831,   833,   835,   837,   839,
     841,   843,   845,   847,   849,   851,   853,   855,   857,   859,
     861,   863,   865,   867,   869,   871,   873,   875,   877,   879,
     881,   883,   885,   887,   889,   891,   893,   895,   897,   899,
     901,   903,   905,   907,   909,   911,   913,   915,   917,   919,
     921,   923,   925,   927,   929,   931,   933,   935,   937,   939,
     941,   943,   945,   947,   949,   951,   953,   955,   957,   959,
     961,   963,   965,   967,   969,   971,   973,   975,   977,   979,
     981,   983,   985,   987,   989,   991,   993,   995,   997,   999,
    1001,  1003,  1005,  1007,  1009,  1011,  1013,  1015,  1017,  1019,
    1021,  1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,  1039,
    1041,  1043,  1045,  1047,  1049,  1051,  1053,  1055,  1057,  1059,
    1061,  1063,  1065,  1067,  1069,  1071,  1073,  1075,  1077,  1079,
    1081,  1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,
    1101,  1103,  1105,  1107,  1109,  1111,  1113,  1115,  1117,  1119,
    1121,  1122,  1123,  1130,  1131,  1132,  1139,  1140,  1144,  1145,
    1149,  1150,  1155,  1156,  1161,  1162,  1167,  1168,  1173,  1174,
    1179,  1180,  1184,  1185,  1189,  1194,  1195,  1199,  1200,  1205,
    1206,  1212,  1213,  1219,  1220,  1226,  1227,  1233,  1238,  1239,
    1245,  1246,  1252,  1253,  1259,  1260,  1266,  1270,  1274,  1275,
    1281,  1282,  1288,  1289,  1295,  1296,  1302,  1303,  1309,  1310,
    1316,  1317,  1323,  1324,  1330,  1335,  1341,  1346,  1347,  1353,
    1359,  1365,  1372,  1378,  1384,  1391,  1397,  1403,  1409,  1415,
    1420,  1421,  1422,  1430,  1431,  1432,  1441,  1446,  1452,  1458,
    1464,  1469,  1475,  1478,  1481,  1484,  1487,  1493,  1498,  1499,
    1503,  1505,  1507,  1510,  1513,  1515,  1517,  1519,  1521,  1523,
    1525,  1526,  1528,  1530,  1532,  1534,  1536,  1538,  1540,  1542,
    1544,  1546,  1548,  1550,  1552,  1554,  1556,  1558,  1560,  1562,
    1564,  1566,  1567,  1569,  1570,  1572,  1574,  1576,  1577,  1582,
    1583,  1588,  1589,  1590,  1597,  1599,  1600,  1604,  1605,  1610,
    1611,  1616,  1617,  1621,  1622,  1627,  1629,  1630,  1634,  1635,
    1640,  1642,  1643,  1647,  1648,  1653,  1654,  1659,  1660,  1664,
    1665,  1669,  1670,  1675,  1677,  1678,  1682,  1683,  1687,  1688,
    1693,  1695,  1696,  1700,  1701,  1706,  1708,  1709,  1713,  1714,
    1719,  1721,  1722,  1726,  1727,  1732,  1734,  1735,  1739,  1740,
    1745,  1747,  1750,  1751,  1754,  1755,  1758,  1759,  1761,  1763,
    1765,  1767,  1769,  1771,  1773,  1775,  1776,  1781,  1783,  1785,
    1787,  1789,  1791,  1793,  1795,  1796,  1801,  1803,  1805,  1807,
    1809,  1811,  1813,  1814,  1819,  1821,  1823,  1825,  1827,  1829,
    1831,  1833,  1834,  1839,  1841,  1843,  1845,  1847,  1849,  1851,
    1852,  1857,  1859,  1861,  1863,  1865,  1867,  1869,  1870,  1875,
    1877,  1879,  1881,  1883,  1885,  1887,  1888,  1893,  1895,  1897,
    1899,  1901,  1903,  1904,  1909,  1911,  1913,  1915,  1917,  1919,
    1920,  1925,  1928,  1930,  1932,  1933,  1938,  1940,  1942,  1944,
    1946,  1948,  1950
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     163,     0,    -1,   164,    -1,    -1,   211,    -1,   199,    -1,
     165,    -1,   326,    -1,    -1,   158,   166,     3,    -1,    -1,
      91,   167,     3,    -1,    86,    -1,    -1,    87,   168,     3,
      -1,    -1,    88,   169,     3,    -1,    89,    -1,    -1,    90,
     170,     4,    -1,    92,    -1,    93,    -1,   309,   278,    -1,
     318,   120,    -1,   178,   278,    -1,   175,   278,    -1,   176,
     278,    -1,   172,   129,   171,    -1,   161,    -1,   173,    -1,
     172,   129,   172,    -1,   174,    -1,   175,    -1,   178,    -1,
     176,    -1,   308,    -1,   173,   130,   180,    -1,    -1,   174,
     131,   177,   179,   132,    -1,   118,   172,   119,    -1,   179,
     124,   308,    -1,   308,    -1,    -1,    -1,   118,   181,   183,
     182,   119,    -1,   184,    -1,     1,    -1,   184,   124,   185,
      -1,   185,    -1,    97,   300,   127,   300,    -1,   126,   308,
     127,   308,    -1,    99,   186,   189,   127,   190,   193,    -1,
      -1,   308,   187,   286,    -1,    -1,   118,   188,   282,   119,
      -1,   116,   256,   255,   257,    -1,    -1,    -1,   308,   191,
     288,    -1,    -1,   118,   192,   282,   119,    -1,   122,   194,
     123,    -1,    -1,   194,   195,    -1,   195,    -1,   140,   159,
      -1,    -1,   141,   118,   196,   271,   119,    -1,    -1,   154,
     118,   197,   271,   119,    -1,    -1,   148,   118,   198,     5,
     119,    -1,    -1,    -1,    -1,     8,   200,   308,   111,   172,
     201,   127,   172,   202,   277,   203,    96,    -1,   203,   204,
      -1,    -1,    97,   300,   127,   206,    -1,   101,   246,   116,
     219,    -1,    -1,    99,   205,   286,   207,    -1,     1,   120,
      -1,   300,   278,    -1,   161,    -1,    -1,    -1,   116,   208,
     256,   255,   257,   127,   209,   220,    -1,    -1,   127,   210,
     220,    -1,    -1,    -1,   221,   212,   308,   213,   215,   277,
     222,    94,    -1,   120,    -1,   161,    -1,   131,   216,   132,
      -1,    -1,   216,   124,   217,    -1,   217,    -1,   308,   128,
     172,    -1,   161,    -1,   257,   278,    -1,   218,    -1,   296,
     214,    -1,   161,    -1,     6,    -1,     7,    -1,   222,   223,
      -1,    -1,    95,   171,    -1,    -1,    97,   224,   279,   214,
      -1,    -1,    98,   225,   280,   214,    -1,    99,   247,   253,
      -1,    55,   250,   253,    -1,   101,   246,   116,   219,    -1,
      -1,    -1,   104,   226,   284,   116,   227,   220,    -1,    -1,
      -1,    -1,   105,   228,   284,   116,   229,   294,   115,   230,
     220,    -1,    -1,    -1,   106,   231,   290,   117,   232,   220,
      -1,    -1,    -1,    -1,   107,   233,   290,   117,   234,   294,
     115,   235,   220,    -1,    -1,    -1,   108,   236,   292,   113,
     237,   220,    -1,    -1,    -1,    -1,   109,   238,   292,   113,
     239,   294,   115,   240,   220,    -1,   152,   247,   253,    -1,
     100,   250,   253,    -1,    -1,   102,   308,   241,   243,   120,
      -1,    -1,   103,   242,   280,   214,    -1,     1,   120,    -1,
     125,    -1,   125,   244,    -1,   245,    -1,   244,   124,   245,
      -1,   309,   116,   308,    -1,   246,   314,    -1,   314,    -1,
      -1,   308,   248,   284,    -1,    -1,   118,   249,   282,   119,
      -1,   250,   251,    -1,   251,    -1,   314,    -1,    -1,   118,
     252,   282,   119,    -1,   116,   256,   255,   254,    -1,   257,
     260,   278,    -1,   218,    -1,   112,    -1,   114,    -1,   256,
     257,    -1,    -1,   300,    -1,    -1,   122,   258,   259,   123,
      -1,   259,   124,   300,    -1,   300,    -1,   122,   261,   123,
      -1,    -1,   261,   263,    -1,   263,    -1,   135,    -1,   138,
     135,    -1,   139,   135,    -1,   133,    -1,   134,    -1,    -1,
     262,   264,   305,    -1,   136,    -1,   137,    -1,   140,   159,
      -1,    -1,   141,   118,   265,   271,   119,    -1,    -1,   154,
     118,   266,   271,   119,    -1,    -1,   143,   118,   267,   271,
     119,    -1,    -1,   144,   118,   268,   271,   119,    -1,   145,
      -1,   147,    -1,   146,    -1,    -1,   146,   118,   269,   271,
     119,    -1,   150,    -1,   151,    -1,   152,    -1,   142,   159,
      -1,    -1,   148,   118,   270,     5,   119,    -1,   149,   118,
     272,   119,    -1,   153,    -1,   271,   159,    -1,   159,    -1,
     272,   273,    -1,   273,    -1,   155,   308,    -1,    -1,   155,
     308,   118,   274,   282,   119,    -1,    -1,   156,   308,   118,
     275,   282,   119,    -1,    -1,   157,   308,   118,   276,   282,
     119,    -1,   110,    -1,    -1,   120,    -1,    -1,   279,   300,
      -1,    -1,   280,   300,    -1,   280,   121,    -1,    -1,   300,
     281,   279,   121,    -1,    -1,   282,   118,   283,   282,   119,
      -1,   282,   308,    -1,    -1,    -1,   284,   118,   285,   282,
     119,    -1,   284,   314,    -1,    -1,    -1,   286,   118,   287,
     282,   119,    -1,   286,   315,    -1,    -1,    -1,   288,   118,
     289,   282,   119,    -1,   288,   316,    -1,    -1,    -1,   290,
     118,   291,   282,   119,    -1,   290,   312,    -1,    -1,    -1,
     292,   118,   293,   282,   119,    -1,   292,   311,    -1,    -1,
      -1,   294,   118,   295,   282,   119,    -1,   294,   313,    -1,
      -1,   297,    -1,   296,   318,    -1,   318,    -1,    -1,   118,
     298,   282,   119,    -1,    -1,   296,   118,   299,   282,   119,
      -1,   297,   321,    -1,   296,   310,    -1,   309,    -1,   301,
      -1,   317,    -1,    -1,   301,   131,   302,   303,   132,    -1,
      -1,   303,   124,   304,   301,    -1,   301,    -1,   306,    -1,
     305,   306,    -1,   320,    -1,   322,    -1,   323,    -1,   120,
      -1,    -1,   118,   307,   282,   119,    -1,   320,    -1,   321,
      -1,   323,    -1,   324,    -1,   120,    -1,   319,    -1,   124,
      -1,   127,    -1,   321,    -1,   323,    -1,   324,    -1,   319,
      -1,   124,    -1,   127,    -1,   323,    -1,   324,    -1,   320,
      -1,   321,    -1,   324,    -1,   120,    -1,   121,    -1,   116,
      -1,   112,    -1,   114,    -1,   117,    -1,   115,    -1,   320,
      -1,   321,    -1,   324,    -1,   120,    -1,   121,    -1,   116,
      -1,   112,    -1,   114,    -1,   113,    -1,   115,    -1,   320,
      -1,   321,    -1,   324,    -1,   120,    -1,   121,    -1,   116,
      -1,   112,    -1,   114,    -1,   117,    -1,   113,    -1,   320,
      -1,   321,    -1,   324,    -1,   120,    -1,   121,    -1,   112,
      -1,   114,    -1,   117,    -1,   113,    -1,   115,    -1,   319,
      -1,   161,    -1,   124,    -1,   321,    -1,   324,    -1,   120,
      -1,   121,    -1,   112,    -1,   114,    -1,   117,    -1,   113,
      -1,   115,    -1,   319,    -1,   161,    -1,   127,    -1,   321,
      -1,   325,    -1,   120,    -1,   123,    -1,   323,    -1,   159,
      -1,   321,    -1,   325,    -1,   117,    -1,   125,    -1,   129,
      -1,   130,    -1,   113,    -1,   115,    -1,   110,    -1,   126,
      -1,   127,    -1,   120,    -1,   161,    -1,   159,    -1,   131,
      -1,   132,    -1,   129,    -1,   130,    -1,   125,    -1,   128,
      -1,   126,    -1,   111,    -1,   110,    -1,   319,    -1,   161,
      -1,   124,    -1,   127,    -1,   152,    -1,   322,    -1,    95,
      -1,    97,    -1,    98,    -1,    99,    -1,    55,    -1,   101,
      -1,   100,    -1,   102,    -1,   103,    -1,   104,    -1,   105,
      -1,   106,    -1,   107,    -1,   108,    -1,   109,    -1,    94,
      -1,    96,    -1,   121,    -1,   116,    -1,   112,    -1,   114,
      -1,   117,    -1,   113,    -1,   115,    -1,   122,    -1,   123,
      -1,   325,    -1,   133,    -1,   134,    -1,   135,    -1,   136,
      -1,   137,    -1,   138,    -1,   139,    -1,   140,    -1,   141,
      -1,   143,    -1,   144,    -1,   145,    -1,   147,    -1,   148,
      -1,   149,    -1,   146,    -1,   142,    -1,   150,    -1,   151,
      -1,   153,    -1,   154,    -1,   155,    -1,   156,    -1,   157,
      -1,    -1,    -1,    31,   327,   417,   328,   415,   120,    -1,
      -1,    -1,    80,   329,   417,   330,   415,   120,    -1,    -1,
       9,   331,   374,    -1,    -1,    79,   332,   374,    -1,    -1,
     371,    11,   333,   374,    -1,    -1,   371,    12,   334,   380,
      -1,    -1,   371,    19,   335,   390,    -1,    -1,   371,    20,
     336,   390,    -1,    -1,   371,    21,   337,   380,    -1,    -1,
      23,   338,   390,    -1,    -1,   370,   339,   380,    -1,   371,
      22,   372,   120,    -1,    -1,    13,   340,   374,    -1,    -1,
     118,   341,   414,   119,    -1,    -1,    28,   367,   342,   435,
     120,    -1,    -1,    28,   368,   343,   435,   120,    -1,    -1,
      48,   367,   344,   435,   120,    -1,    -1,    35,   369,   345,
     435,   120,    -1,    64,    65,   145,   120,    -1,    -1,    25,
       6,   346,   415,   120,    -1,    -1,    25,    50,   347,   415,
     120,    -1,    -1,    25,    53,   348,   415,   120,    -1,    -1,
      25,     8,   349,   415,   120,    -1,    25,    51,   120,    -1,
      25,    52,   120,    -1,    -1,    25,    54,   350,   415,   120,
      -1,    -1,    25,    55,   351,   415,   120,    -1,    -1,    25,
      56,   352,   415,   120,    -1,    -1,    25,    57,   353,   415,
     120,    -1,    -1,    25,    58,   354,   415,   120,    -1,    -1,
      25,    59,   355,   415,   120,    -1,    -1,    25,    60,   356,
     415,   120,    -1,    -1,    25,    61,   357,   415,   120,    -1,
      25,    49,    85,   120,    -1,    25,    49,   126,    85,   120,
      -1,    25,    23,    36,   120,    -1,    -1,    25,    81,   358,
     415,   120,    -1,    24,    25,    62,   366,   120,    -1,    24,
      25,    44,   366,   120,    -1,    24,    25,    13,    44,   366,
     120,    -1,    24,    25,    45,   366,   120,    -1,    24,    25,
      47,   366,   120,    -1,    24,    25,    13,    45,   366,   120,
      -1,    24,    25,    46,   366,   120,    -1,    24,    25,    42,
     366,   120,    -1,    24,    35,   364,   366,   120,    -1,    24,
      28,   365,   366,   120,    -1,    24,    48,   366,   120,    -1,
      -1,    -1,    24,   373,   359,   438,   360,   366,   120,    -1,
      -1,    -1,    24,     7,    68,   361,   438,   362,   366,   120,
      -1,    24,    63,   366,   120,    -1,    24,    65,   145,   366,
     120,    -1,    24,    65,    59,   366,   120,    -1,    24,    72,
      73,   366,   120,    -1,    24,    81,   366,   120,    -1,    24,
      65,    81,   366,   120,    -1,    75,   120,    -1,    76,   120,
      -1,    77,   120,    -1,    78,   120,    -1,    24,    42,    25,
     366,   120,    -1,    24,    44,   366,   120,    -1,    -1,     1,
     363,   120,    -1,    37,    -1,    38,    -1,    39,    41,    -1,
      39,    40,    -1,    36,    -1,    70,    -1,    82,    -1,    83,
      -1,    84,    -1,   154,    -1,    -1,    33,    -1,    30,    -1,
      34,    -1,    31,    -1,    57,    -1,    58,    -1,    59,    -1,
      12,    -1,    29,    -1,    26,    -1,    27,    -1,    31,    -1,
      32,    -1,    69,    -1,    68,    -1,    70,    -1,    71,    -1,
      16,    -1,    15,    -1,    74,    -1,    -1,    85,    -1,    -1,
      66,    -1,    67,    -1,    68,    -1,    -1,   158,   375,   416,
     377,    -1,    -1,   423,   376,   415,   120,    -1,    -1,    -1,
     116,   378,   417,   379,   415,   120,    -1,   120,    -1,    -1,
     122,   381,   384,    -1,    -1,   158,   382,   416,   377,    -1,
      -1,   425,   383,   415,   120,    -1,    -1,   160,   385,   387,
      -1,    -1,   427,   386,   415,   120,    -1,   120,    -1,    -1,
     123,   388,   374,    -1,    -1,   429,   389,   415,   120,    -1,
     120,    -1,    -1,   122,   391,   394,    -1,    -1,   158,   392,
     416,   377,    -1,    -1,   425,   393,   415,   120,    -1,    -1,
     160,   395,   398,    -1,    -1,   124,   396,   408,    -1,    -1,
     433,   397,   415,   120,    -1,   120,    -1,    -1,   123,   399,
     374,    -1,    -1,   124,   400,   402,    -1,    -1,   431,   401,
     415,   120,    -1,   120,    -1,    -1,   160,   403,   405,    -1,
      -1,   427,   404,   415,   120,    -1,   120,    -1,    -1,   123,
     406,   374,    -1,    -1,   429,   407,   415,   120,    -1,   120,
      -1,    -1,   160,   409,   411,    -1,    -1,   427,   410,   415,
     120,    -1,   120,    -1,    -1,   123,   412,   374,    -1,    -1,
     429,   413,   415,   120,    -1,   120,    -1,   414,   417,    -1,
      -1,   415,   419,    -1,    -1,   416,   421,    -1,    -1,   159,
      -1,   160,    -1,   122,    -1,   123,    -1,   158,    -1,   116,
      -1,   120,    -1,   124,    -1,    -1,   118,   418,   414,   119,
      -1,   159,    -1,   160,    -1,   122,    -1,   123,    -1,   158,
      -1,   116,    -1,   124,    -1,    -1,   118,   420,   414,   119,
      -1,   159,    -1,   160,    -1,   122,    -1,   123,    -1,   158,
      -1,   124,    -1,    -1,   118,   422,   414,   119,    -1,   159,
      -1,   160,    -1,   122,    -1,   123,    -1,   116,    -1,   120,
      -1,   124,    -1,    -1,   118,   424,   414,   119,    -1,   159,
      -1,   160,    -1,   123,    -1,   116,    -1,   120,    -1,   124,
      -1,    -1,   118,   426,   414,   119,    -1,   159,    -1,   122,
      -1,   123,    -1,   158,    -1,   116,    -1,   124,    -1,    -1,
     118,   428,   414,   119,    -1,   159,    -1,   160,    -1,   122,
      -1,   158,    -1,   116,    -1,   124,    -1,    -1,   118,   430,
     414,   119,    -1,   159,    -1,   160,    -1,   122,    -1,   158,
      -1,   116,    -1,    -1,   118,   432,   414,   119,    -1,   159,
      -1,   122,    -1,   123,    -1,   158,    -1,   116,    -1,    -1,
     118,   434,   414,   119,    -1,   435,   436,    -1,   436,    -1,
     438,    -1,    -1,   118,   437,   414,   119,    -1,   159,    -1,
     160,    -1,   122,    -1,   123,    -1,   158,    -1,   116,    -1,
     124,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   216,   216,   218,   223,   224,   225,   226,   232,   232,
     242,   242,   252,   256,   256,   267,   267,   278,   289,   289,
     294,   299,   332,   336,   340,   341,   342,   343,   351,   361,
     362,   372,   373,   376,   377,   378,   385,   394,   394,   403,
     406,   407,   414,   419,   413,   425,   426,   429,   430,   433,
     437,   441,   444,   444,   449,   449,   456,   457,   460,   460,
     462,   462,   466,   467,   470,   471,   474,   475,   475,   477,
     477,   479,   479,   486,   488,   496,   486,   509,   510,   513,
     517,   518,   518,   520,   523,   524,   535,   543,   534,   552,
     551,   586,   588,   586,   601,   602,   612,   613,   616,   617,
     620,   628,   640,   641,   644,   645,   655,   655,   658,   659,
     662,   669,   669,   672,   672,   675,   677,   679,   681,   682,
     681,   685,   686,   687,   685,   690,   691,   690,   694,   695,
     696,   694,   699,   700,   699,   703,   704,   705,   703,   708,
     713,   719,   718,   725,   725,   728,   739,   740,   743,   744,
     747,   752,   753,   756,   756,   758,   758,   762,   763,   766,
     772,   772,   776,   783,   784,   787,   788,   791,   792,   795,
     801,   801,   808,   809,   812,   813,   816,   817,   820,   824,
     828,   834,   838,   842,   842,   844,   848,   852,   853,   853,
     855,   855,   857,   857,   859,   859,   861,   865,   869,   874,
     874,   876,   880,   884,   888,   892,   892,   894,   895,   901,
     902,   905,   906,   909,   914,   914,   919,   919,   924,   924,
     934,   936,   942,   944,   952,   953,   956,   957,   958,   958,
     965,   965,   967,   968,   971,   971,   973,   974,   977,   977,
     979,   980,   983,   983,   985,   986,   989,   989,   991,   992,
     995,   995,   997,   998,  1001,  1001,  1003,  1004,  1007,  1008,
    1009,  1012,  1012,  1014,  1014,  1016,  1017,  1018,  1024,  1036,
    1037,  1037,  1041,  1041,  1043,  1049,  1050,  1053,  1053,  1053,
    1053,  1054,  1054,  1061,  1061,  1061,  1061,  1061,  1064,  1064,
    1064,  1065,  1065,  1065,  1068,  1068,  1068,  1069,  1069,  1072,
    1072,  1072,  1072,  1073,  1073,  1073,  1073,  1073,  1073,  1076,
    1076,  1076,  1076,  1077,  1077,  1077,  1077,  1077,  1077,  1080,
    1080,  1080,  1080,  1081,  1081,  1081,  1081,  1081,  1081,  1084,
    1084,  1084,  1084,  1085,  1085,  1085,  1085,  1085,  1085,  1088,
    1088,  1088,  1089,  1089,  1089,  1090,  1090,  1090,  1090,  1090,
    1090,  1093,  1093,  1093,  1094,  1094,  1094,  1094,  1094,  1097,
    1097,  1097,  1098,  1098,  1098,  1098,  1099,  1099,  1099,  1099,
    1099,  1102,  1102,  1108,  1108,  1108,  1108,  1108,  1108,  1108,
    1108,  1109,  1109,  1112,  1112,  1112,  1112,  1115,  1115,  1118,
    1118,  1118,  1118,  1118,  1118,  1119,  1119,  1119,  1120,  1120,
    1120,  1120,  1120,  1120,  1120,  1120,  1123,  1123,  1123,  1123,
    1123,  1123,  1123,  1126,  1126,  1126,  1129,  1129,  1129,  1129,
    1129,  1129,  1129,  1130,  1130,  1130,  1130,  1130,  1130,  1131,
    1131,  1131,  1131,  1132,  1132,  1132,  1132,  1133,  1133,  1133,
    1160,  1161,  1160,  1167,  1168,  1167,  1176,  1175,  1189,  1188,
    1202,  1201,  1215,  1214,  1228,  1227,  1242,  1241,  1256,  1255,
    1269,  1268,  1283,  1282,  1295,  1300,  1299,  1311,  1311,  1320,
    1320,  1326,  1326,  1332,  1332,  1338,  1338,  1344,  1352,  1352,
    1359,  1359,  1366,  1366,  1373,  1373,  1380,  1384,  1388,  1388,
    1395,  1395,  1402,  1402,  1409,  1409,  1416,  1416,  1423,  1423,
    1430,  1430,  1437,  1437,  1444,  1448,  1452,  1456,  1456,  1466,
    1470,  1474,  1478,  1482,  1486,  1490,  1494,  1498,  1502,  1506,
    1510,  1511,  1510,  1516,  1517,  1516,  1522,  1526,  1530,  1534,
    1538,  1542,  1549,  1553,  1557,  1561,  1568,  1572,  1579,  1579,
    1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,
    1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,  1606,  1607,
    1610,  1611,  1614,  1615,  1618,  1619,  1622,  1623,  1626,  1627,
    1630,  1631,  1634,  1635,  1638,  1639,  1640,  1648,  1648,  1650,
    1650,  1654,  1655,  1654,  1657,  1667,  1667,  1669,  1669,  1671,
    1671,  1676,  1676,  1678,  1678,  1680,  1685,  1684,  1690,  1690,
    1692,  1705,  1705,  1707,  1707,  1709,  1709,  1718,  1718,  1720,
    1720,  1722,  1722,  1724,  1733,  1732,  1738,  1738,  1740,  1740,
    1742,  1750,  1750,  1752,  1752,  1754,  1763,  1762,  1769,  1769,
    1771,  1779,  1779,  1781,  1781,  1783,  1792,  1791,  1797,  1797,
    1799,  1805,  1806,  1809,  1810,  1814,  1815,  1821,  1821,  1821,
    1821,  1821,  1821,  1821,  1821,  1822,  1822,  1826,  1826,  1826,
    1826,  1826,  1826,  1826,  1827,  1827,  1832,  1832,  1832,  1832,
    1832,  1832,  1833,  1833,  1837,  1837,  1837,  1837,  1837,  1837,
    1837,  1838,  1838,  1842,  1842,  1842,  1842,  1842,  1842,  1843,
    1843,  1848,  1848,  1848,  1848,  1848,  1848,  1849,  1849,  1854,
    1854,  1854,  1854,  1854,  1854,  1855,  1855,  1860,  1860,  1860,
    1860,  1860,  1861,  1861,  1866,  1866,  1866,  1866,  1866,  1867,
    1867,  1873,  1874,  1877,  1883,  1883,  1891,  1891,  1891,  1891,
    1891,  1891,  1891
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FILE_NAME_STRING", "UNINTERPRETED_STRING", 
  "LATEX_STRING", "KW_MOD", "KW_OMOD", "KW_VIEW", "KW_PARSE", 
  "KW_NORMALIZE", "KW_REDUCE", "KW_REWRITE", "KW_LOOP", "KW_NARROW", 
  "KW_MATCH", "KW_XMATCH", "KW_UNIFY", "KW_XUNIFY", "KW_EREWRITE", 
  "KW_FREWRITE", "KW_SREWRITE", "KW_CONTINUE", "KW_SEARCH", "KW_SET", 
  "KW_SHOW", "KW_ON", "KW_OFF", "KW_TRACE", "KW_BODY", "KW_WHOLE", 
  "KW_SELECT", "KW_DESELECT", "KW_CONDITION", "KW_SUBSTITUTION", 
  "KW_PRINT", "KW_GRAPH", "KW_MIXFIX", "KW_FLAT", "KW_WITH", "KW_PARENS", 
  "KW_ALIASES", "KW_GC", "KW_TIME", "KW_STATS", "KW_TIMING", "KW_CMD", 
  "KW_BREAKDOWN", "KW_BREAK", "KW_PATH", "KW_MODULE", "KW_MODULES", 
  "KW_VIEWS", "KW_ALL", "KW_SORTS", "KW_OPS", "KW_VARS", "KW_MBS", 
  "KW_EQS", "KW_RLS", "KW_SUMMARY", "KW_KINDS", "KW_ADVISE", "KW_VERBOSE", 
  "KW_DO", "KW_CLEAR", "KW_PROTECT", "KW_EXTEND", "KW_INCLUDE", 
  "KW_EXCLUDE", "KW_CONCEAL", "KW_REVEAL", "KW_COMPILE", "KW_COUNT", 
  "KW_DEBUG", "KW_RESUME", "KW_ABORT", "KW_STEP", "KW_WHERE", 
  "KW_CREDUCE", "KW_DUMP", "KW_PROFILE", "KW_NUMBER", "KW_RAT", 
  "KW_COLOR", "SIMPLE_NUMBER", "KW_PWD", "KW_CD", "KW_PUSHD", "KW_POPD", 
  "KW_LS", "KW_LOAD", "KW_QUIT", "KW_EOF", "KW_ENDM", "KW_IMPORT", 
  "KW_ENDV", "KW_SORT", "KW_SUBSORT", "KW_OP", "KW_MSGS", "KW_VAR", 
  "KW_CLASS", "KW_SUBCLASS", "KW_MB", "KW_CMB", "KW_EQ", "KW_CEQ", 
  "KW_RL", "KW_CRL", "KW_IS", "KW_FROM", "KW_ARROW", "KW_ARROW2", 
  "KW_PARTIAL", "KW_IF", "':'", "'='", "'('", "')'", "'.'", "'<'", "'['", 
  "']'", "','", "'|'", "KW_LABEL", "KW_TO", "KW_COLON2", "'+'", "'*'", 
  "'{'", "'}'", "KW_ASSOC", "KW_COMM", "KW_ID", "KW_IDEM", "KW_ITER", 
  "KW_LEFT", "KW_RIGHT", "KW_PREC", "KW_GATHER", "KW_METADATA", 
  "KW_STRAT", "KW_POLY", "KW_MEMO", "KW_FROZEN", "KW_CTOR", "KW_LATEX", 
  "KW_SPECIAL", "KW_CONFIG", "KW_OBJ", "KW_MSG", "KW_DITTO", "KW_FORMAT", 
  "KW_ID_HOOK", "KW_OP_HOOK", "KW_TERM_HOOK", "KW_IN", "IDENTIFIER", 
  "NUMERIC_ID", "ENDS_IN_DOT", "$accept", "top", "item", "directive", 
  "@1", "@2", "@3", "@4", "@5", "moduleExprDot", "moduleExpr", 
  "moduleExpr2", "moduleExpr3", "renameExpr", "instantExpr", "@6", 
  "parenExpr", "argList", "renaming", "@7", "@8", "renaming2", 
  "mappingList", "mapping", "fromOpName", "@9", "@10", "fromSpec", 
  "toOpName", "@11", "@12", "toAttributes", "toAttributeList", 
  "toAttribute", "@13", "@14", "@15", "view", "@16", "@17", "@18", 
  "viewDecList", "viewDeclaration", "@19", "sortDot", "viewEndOpMap", 
  "@20", "@21", "@22", "module", "@23", "@24", "dot", "parameters", 
  "parameterList", "parameter", "badType", "typeDot", "endStatement", 
  "startModule", "decList", "declaration", "@25", "@26", "@27", "@28", 
  "@29", "@30", "@31", "@32", "@33", "@34", "@35", "@36", "@37", "@38", 
  "@39", "@40", "@41", "@42", "@43", "classDef", "cPairList", "cPair", 
  "varNameList", "opName", "@44", "@45", "opNameList", "simpleOpName", 
  "@46", "domainRangeAttr", "typeAttr", "arrow", "typeList", "typeName", 
  "@47", "sortNames", "attributes", "attributeList", "idKeyword", 
  "attribute", "@48", "@49", "@50", "@51", "@52", "@53", "@54", "idList", 
  "hookList", "hook", "@55", "@56", "@57", "expectedIs", "expectedDot", 
  "sortNameList", "subsortList", "@58", "tokens", "@59", "tokensBarColon", 
  "@60", "tokensBarColonTo", "@61", "tokensBarCommaLeft", "@62", 
  "tokensBarEqual", "@63", "tokensBarArrow2", "@64", "tokensBarIf", "@65", 
  "endTokens", "noTrailingDot", "@66", "@67", "sortName", "sortNameFrag", 
  "@68", "sortNameFrags", "@69", "identity", "identityChunk", "@70", 
  "token", "tokenBarDot", "endToken", "tokenBarArrow2", "tokenBarEqual", 
  "tokenBarIf", "tokenBarColon", "tokenBarColonTo", "tokenBarCommaLeft", 
  "sortToken", "endsInDot", "inert", "identifier", "startKeyword", 
  "startKeyword2", "midKeyword", "attrKeyword", "attrKeyword2", "command", 
  "@71", "@72", "@73", "@74", "@75", "@76", "@77", "@78", "@79", "@80", 
  "@81", "@82", "@83", "@84", "@85", "@86", "@87", "@88", "@89", "@90", 
  "@91", "@92", "@93", "@94", "@95", "@96", "@97", "@98", "@99", "@100", 
  "@101", "@102", "@103", "@104", "@105", "@106", "@107", "printOption", 
  "traceOption", "polarity", "select", "exclude", "conceal", "match", 
  "optDebug", "optNumber", "importMode", "moduleAndTerm", "@108", "@109", 
  "inEnd", "@110", "@111", "numberModuleTerm", "@112", "@113", "@114", 
  "numberModuleTerm1", "@115", "@116", "numberModuleTerm2", "@117", 
  "@118", "numbersModuleTerm", "@119", "@120", "@121", 
  "numbersModuleTerm1", "@122", "@123", "@124", "numbersModuleTerm2", 
  "@125", "@126", "@127", "numbersModuleTerm3", "@128", "@129", 
  "numbersModuleTerm4", "@130", "@131", "numbersModuleTerm5", "@132", 
  "@133", "numbersModuleTerm6", "@134", "@135", "cTokens", 
  "cTokensBarDot", "cTokensBarDotColon", "cToken", "@136", "cTokenBarDot", 
  "@137", "cTokenBarDotColon", "@138", "cTokenBarIn", "@139", 
  "cTokenBarLeftIn", "@140", "cTokenBarDotNumber", "@141", 
  "cTokenBarDotRight", "@142", "cTokenBarDotCommaRight", "@143", 
  "cTokenBarDotCommaNumber", "@144", "cOpNameList", "cSimpleOpName", 
  "@145", "cSimpleTokenBarDot", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
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
     365,   366,   367,   368,   369,   370,    58,    61,    40,    41,
      46,    60,    91,    93,    44,   124,   371,   372,   373,    43,
      42,   123,   125,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   162,   163,   163,   164,   164,   164,   164,   166,   165,
     167,   165,   165,   168,   165,   169,   165,   165,   170,   165,
     165,   165,   171,   171,   171,   171,   171,   171,   171,   172,
     172,   173,   173,   174,   174,   174,   175,   177,   176,   178,
     179,   179,   181,   182,   180,   183,   183,   184,   184,   185,
     185,   185,   187,   186,   188,   186,   189,   189,   191,   190,
     192,   190,   193,   193,   194,   194,   195,   196,   195,   197,
     195,   198,   195,   200,   201,   202,   199,   203,   203,   204,
     204,   205,   204,   204,   206,   206,   208,   209,   207,   210,
     207,   212,   213,   211,   214,   214,   215,   215,   216,   216,
     217,   218,   219,   219,   220,   220,   221,   221,   222,   222,
     223,   224,   223,   225,   223,   223,   223,   223,   226,   227,
     223,   228,   229,   230,   223,   231,   232,   223,   233,   234,
     235,   223,   236,   237,   223,   238,   239,   240,   223,   223,
     223,   241,   223,   242,   223,   223,   243,   243,   244,   244,
     245,   246,   246,   248,   247,   249,   247,   250,   250,   251,
     252,   251,   253,   254,   254,   255,   255,   256,   256,   257,
     258,   257,   259,   259,   260,   260,   261,   261,   262,   262,
     262,   263,   263,   264,   263,   263,   263,   263,   265,   263,
     266,   263,   267,   263,   268,   263,   263,   263,   263,   269,
     263,   263,   263,   263,   263,   270,   263,   263,   263,   271,
     271,   272,   272,   273,   274,   273,   275,   273,   276,   273,
     277,   277,   278,   278,   279,   279,   280,   280,   281,   280,
     283,   282,   282,   282,   285,   284,   284,   284,   287,   286,
     286,   286,   289,   288,   288,   288,   291,   290,   290,   290,
     293,   292,   292,   292,   295,   294,   294,   294,   296,   296,
     296,   298,   297,   299,   297,   297,   297,   297,   300,   301,
     302,   301,   304,   303,   303,   305,   305,   306,   306,   306,
     306,   307,   306,   308,   308,   308,   308,   308,   309,   309,
     309,   309,   309,   309,   310,   310,   310,   310,   310,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   316,   316,   316,   316,   316,   316,   316,   316,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   318,   318,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   320,   320,   320,   320,   321,   321,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   323,   323,   323,   323,
     323,   323,   323,   324,   324,   324,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     327,   328,   326,   329,   330,   326,   331,   326,   332,   326,
     333,   326,   334,   326,   335,   326,   336,   326,   337,   326,
     338,   326,   339,   326,   326,   340,   326,   341,   326,   342,
     326,   343,   326,   344,   326,   345,   326,   326,   346,   326,
     347,   326,   348,   326,   349,   326,   326,   326,   350,   326,
     351,   326,   352,   326,   353,   326,   354,   326,   355,   326,
     356,   326,   357,   326,   326,   326,   326,   358,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     359,   360,   326,   361,   362,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   363,   326,
     364,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     366,   366,   367,   367,   368,   368,   369,   369,   370,   370,
     371,   371,   372,   372,   373,   373,   373,   375,   374,   376,
     374,   378,   379,   377,   377,   381,   380,   382,   380,   383,
     380,   385,   384,   386,   384,   384,   388,   387,   389,   387,
     387,   391,   390,   392,   390,   393,   390,   395,   394,   396,
     394,   397,   394,   394,   399,   398,   400,   398,   401,   398,
     398,   403,   402,   404,   402,   402,   406,   405,   407,   405,
     405,   409,   408,   410,   408,   408,   412,   411,   413,   411,
     411,   414,   414,   415,   415,   416,   416,   417,   417,   417,
     417,   417,   417,   417,   417,   418,   417,   419,   419,   419,
     419,   419,   419,   419,   420,   419,   421,   421,   421,   421,
     421,   421,   422,   421,   423,   423,   423,   423,   423,   423,
     423,   424,   423,   425,   425,   425,   425,   425,   425,   426,
     425,   427,   427,   427,   427,   427,   427,   428,   427,   429,
     429,   429,   429,   429,   429,   430,   429,   431,   431,   431,
     431,   431,   432,   431,   433,   433,   433,   433,   433,   434,
     433,   435,   435,   436,   437,   436,   438,   438,   438,   438,
     438,   438,   438
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     0,     3,
       0,     3,     1,     0,     3,     0,     3,     1,     0,     3,
       1,     1,     2,     2,     2,     2,     2,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     0,     5,     3,
       3,     1,     0,     0,     5,     1,     1,     3,     1,     4,
       4,     6,     0,     3,     0,     4,     4,     0,     0,     3,
       0,     4,     3,     0,     2,     1,     2,     0,     5,     0,
       5,     0,     5,     0,     0,     0,    12,     2,     0,     4,
       4,     0,     4,     2,     2,     1,     0,     0,     8,     0,
       3,     0,     0,     8,     1,     1,     3,     0,     3,     1,
       3,     1,     2,     1,     2,     1,     1,     1,     2,     0,
       2,     0,     4,     0,     4,     3,     3,     4,     0,     0,
       6,     0,     0,     0,     9,     0,     0,     6,     0,     0,
       0,     9,     0,     0,     6,     0,     0,     0,     9,     3,
       3,     0,     5,     0,     4,     2,     1,     2,     1,     3,
       3,     2,     1,     0,     3,     0,     4,     2,     1,     1,
       0,     4,     4,     3,     1,     1,     1,     2,     0,     1,
       0,     4,     3,     1,     3,     0,     2,     1,     1,     2,
       2,     1,     1,     0,     3,     1,     1,     2,     0,     5,
       0,     5,     0,     5,     0,     5,     1,     1,     1,     0,
       5,     1,     1,     1,     2,     0,     5,     4,     1,     2,
       1,     2,     1,     2,     0,     6,     0,     6,     0,     6,
       1,     0,     1,     0,     2,     0,     2,     2,     0,     4,
       0,     5,     2,     0,     0,     5,     2,     0,     0,     5,
       2,     0,     0,     5,     2,     0,     0,     5,     2,     0,
       0,     5,     2,     0,     0,     5,     2,     0,     1,     2,
       1,     0,     4,     0,     5,     2,     2,     1,     1,     1,
       0,     5,     0,     4,     1,     1,     2,     1,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     6,     0,     0,     6,     0,     3,     0,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     3,     0,     3,     4,     0,     3,     0,     4,     0,
       5,     0,     5,     0,     5,     0,     5,     4,     0,     5,
       0,     5,     0,     5,     0,     5,     3,     3,     0,     5,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     5,     4,     5,     4,     0,     5,     5,
       5,     6,     5,     5,     6,     5,     5,     5,     5,     4,
       0,     0,     7,     0,     0,     8,     4,     5,     5,     5,
       4,     5,     2,     2,     2,     2,     5,     4,     0,     3,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     0,     1,     1,     1,     0,     4,     0,
       4,     0,     0,     6,     1,     0,     3,     0,     4,     0,
       4,     0,     3,     0,     4,     1,     0,     3,     0,     4,
       1,     0,     3,     0,     4,     0,     4,     0,     3,     0,
       3,     0,     4,     1,     0,     3,     0,     3,     0,     4,
       1,     0,     3,     0,     4,     1,     0,     3,     0,     4,
       1,     0,     3,     0,     4,     1,     0,     3,     0,     4,
       1,     2,     0,     2,     0,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     0,
       4,     1,     1,     1,     1,     1,     1,     0,     4,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     0,
       4,     2,     1,     1,     0,     4,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,   538,   106,   107,    73,   446,   465,   569,   568,   460,
       0,     0,     0,   440,     0,     0,     0,   570,     0,     0,
       0,     0,   448,   443,    12,    13,    15,    17,    18,    10,
      20,    21,   467,     8,     0,     2,     6,     5,     4,    91,
       7,   462,     0,     0,     0,     0,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,     0,   574,   575,   576,
       0,     0,   520,   478,   484,     0,     0,   480,     0,     0,
     482,   488,   490,   492,   494,   496,   498,   500,   502,   507,
     562,   563,   565,   564,   469,   471,     0,   566,   567,   475,
     473,     0,   532,   533,   534,   535,     0,     0,     0,     0,
       0,     0,   642,     0,     1,     0,     0,   450,   452,   454,
     456,   458,   573,   539,   393,   404,   389,   405,   390,   391,
     392,   395,   394,   396,   397,   398,   399,   400,   401,   402,
     403,   382,   381,   408,   411,   409,   412,   407,   410,   287,
     406,   413,   414,   385,   378,   380,   386,   379,   376,   377,
     374,   375,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   432,   425,   426,   427,   431,   428,   429,   430,   433,
     434,   387,   435,   436,   437,   438,   439,   373,   384,     0,
     383,   283,   284,   388,   285,   286,   415,   678,   681,   679,
     676,   677,   680,   577,   674,   675,   447,   579,   466,   686,
     689,   687,   601,   685,   688,   603,   683,   684,   461,   605,
     523,     0,     0,     0,     0,     0,     0,     0,   558,   559,
     552,   554,   551,   553,   555,   556,   557,     0,   544,   540,
     541,     0,   545,   546,   547,   548,   549,     0,     0,   560,
     561,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     644,   644,     0,     0,     0,   644,   486,   487,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,     0,     0,
     652,   655,   653,   649,   650,   654,   651,   647,   648,   441,
       0,     0,     0,   449,   444,    14,    16,    19,    11,     0,
       9,    92,   585,   587,   463,   589,     0,     0,     0,     0,
       0,   572,     0,     0,   642,   646,   644,   642,     0,   646,
     644,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   543,   542,     0,     0,   537,   519,   526,     0,     0,
       0,     0,   530,   731,   728,   729,   732,   730,   726,   727,
     521,     0,     0,   506,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   724,     0,   722,
     723,     0,   642,   644,     0,     0,   477,   644,   468,   641,
      97,     0,   646,   644,   451,   453,   455,   457,   459,   464,
       0,    74,    29,    31,    32,    34,    33,    35,     0,     0,
       0,     0,   718,   719,   613,   715,   716,   609,   717,   714,
     607,   602,   611,     0,     0,   524,     0,     0,   516,   510,
     512,   515,   513,   509,   518,   517,   536,   528,   531,   527,
     529,     0,   662,   664,   479,   659,   660,   663,   661,   657,
     658,   643,   485,   505,   481,   483,   489,   491,   493,   495,
     497,   499,   501,   503,   508,   642,   470,   721,   472,     0,
       0,   476,   474,     0,     0,   221,   695,   697,   595,   692,
     693,   696,   694,   691,   591,   586,   593,     0,     0,     0,
       0,     0,     0,    37,   682,   581,   672,   584,   668,   669,
     671,   670,   666,   667,   578,   645,   580,   690,   642,     0,
       0,   644,   604,   606,     0,   511,   514,     0,   642,     0,
     656,   442,   445,     0,    99,     0,   220,   109,   642,     0,
     644,   588,   590,    39,    30,     0,    42,    36,     0,     0,
     642,     0,   635,   631,   610,   633,   711,   712,   620,   709,
     614,   616,   710,   707,   708,   608,   618,     0,     0,   522,
       0,   725,     0,    96,     0,     0,     0,   703,   705,   600,
     701,   596,   704,   702,   699,   700,   592,   598,     0,    75,
       0,     0,    41,   582,     0,   720,     0,   644,   642,     0,
       0,   644,   612,   525,   665,    98,   100,     0,     0,    93,
       0,   111,   113,     0,     0,     0,     0,   143,   118,   121,
     125,   128,   132,   135,     0,   108,   698,   642,     0,   644,
     594,   221,    46,     0,     0,     0,    43,    45,    48,     0,
      38,   644,   673,   640,   636,   632,   638,     0,     0,   615,
     625,   621,   617,   623,     0,   145,   334,   337,   335,   338,
     336,   160,   332,   333,     0,   158,   159,   329,   330,   331,
     287,   289,   290,    28,   110,     0,   223,   223,   223,   223,
       0,   288,   291,   292,   293,   225,     0,   155,     0,   153,
       0,     0,   152,   141,     0,   237,   237,   249,   249,   253,
     253,     0,     0,   597,     0,    78,   368,   366,   367,   362,
     363,   369,   370,   364,   365,   359,     0,   268,   269,   360,
     361,    54,    57,    52,     0,     0,     0,    40,     0,     0,
     644,   634,   713,     0,   644,   619,   233,   168,   157,   116,
       0,   222,    25,    26,    24,    22,    23,     0,     0,   228,
     233,   115,   237,   140,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   139,   706,   599,     0,     0,   270,
     233,   168,     0,   241,     0,    44,    47,   583,   637,     0,
     630,   626,   622,   628,     0,     0,     0,    27,    30,    94,
      95,   112,   224,   227,   114,   226,   225,     0,   154,   170,
     101,   103,   117,   223,   169,   146,     0,   144,   119,   234,
     236,   122,   315,   317,   316,   318,   314,   126,   246,   312,
     313,   248,   309,   310,   311,   129,   305,   133,   306,   308,
     304,   307,   250,   302,   303,   252,   299,   300,   301,   136,
       0,    76,     0,    81,     0,    77,    49,     0,     0,     0,
       0,    53,    50,   639,     0,   644,   624,   230,   161,   232,
     165,   166,     0,   167,     0,   156,     0,   102,   289,   290,
     147,   148,     0,   288,   291,   292,   293,   142,     0,   233,
     257,     0,   233,   257,     0,   233,   257,    83,     0,   241,
       0,   274,     0,    55,     0,    60,    63,    58,   346,   349,
     347,   350,   348,   238,   344,   345,   341,   340,   240,   339,
     342,   343,   627,     0,   233,   164,   162,   175,   229,     0,
     173,     0,     0,   261,   371,   372,   120,     0,   258,   267,
     260,     0,     0,   127,     0,     0,   134,     0,     0,     0,
       0,     0,   272,   271,    56,   233,     0,    51,   245,   233,
     629,     0,     0,   223,   171,     0,   149,   150,   233,   263,
     371,   295,   296,   372,   104,   266,   259,   294,   297,   298,
     265,   235,   325,   328,   326,   123,   324,   327,   254,   322,
     323,   256,   319,   320,   321,   247,   130,   251,   137,    85,
      79,   223,    86,    89,    82,    80,     0,     0,     0,     0,
       0,     0,     0,    65,    59,     0,   231,   181,   182,   178,
     185,   186,     0,     0,     0,     0,     0,     0,     0,   196,
     198,   197,     0,     0,   201,   202,   203,   208,     0,     0,
     183,   177,   163,   172,     0,   233,     0,   233,     0,     0,
      84,   168,     0,   273,    61,    66,    67,    71,    69,    62,
      64,   242,   356,   357,   353,   352,   244,   351,   354,   358,
     355,   239,   179,   180,   187,   188,   204,   192,   194,   199,
     205,     0,   190,   174,   176,     0,   262,     0,   124,     0,
     131,   138,     0,    90,     0,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   212,     0,   281,
     280,   184,   275,   277,   278,   279,   264,   255,     0,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
       0,     0,   207,   211,     0,   233,   276,     0,    68,   209,
      72,    70,   243,   189,   193,   195,   200,   206,   214,   216,
     218,   191,     0,    87,   233,   233,   233,   282,     0,     0,
       0,     0,    88,   215,   217,   219
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    34,    35,    36,   103,   101,    98,    99,   100,   644,
     381,   382,   383,   384,   385,   518,   386,   561,   517,   560,
     695,   606,   607,   608,   692,   743,   740,   742,   866,   918,
     915,   917,   972,   973,  1054,  1056,  1055,    37,    44,   471,
     601,   737,   815,   859,   960,   964,  1011,  1118,  1012,    38,
     105,   370,   761,   455,   503,   504,   771,   772,   896,    39,
     545,   595,   655,   656,   665,   848,   666,   850,  1006,   667,
     851,   668,   853,  1008,   669,   854,   670,   856,  1009,   726,
     664,   776,   840,   841,   661,   658,   722,   720,   634,   635,
     706,   709,   886,   832,   756,   833,   836,   889,   923,   999,
    1000,  1001,  1045,  1058,  1068,  1059,  1060,  1061,  1062,  1080,
    1066,  1067,  1114,  1115,  1116,   507,   712,   717,   718,   766,
     755,   884,   728,   849,   821,   919,   974,  1057,   730,   852,
     732,   855,   902,  1007,   897,   898,   928,  1005,   774,   687,
     817,   862,   966,  1071,  1072,  1095,   829,   899,   935,   805,
     791,   951,   636,   878,  1026,   688,   900,   180,   181,   182,
     183,   184,   185,   186,    40,    86,   363,    97,   367,    45,
      96,   296,   297,   298,   299,   300,    47,   106,    46,   102,
     268,   269,   281,   280,   250,   255,   258,   251,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   249,   421,   311,
     494,    43,   237,   227,   241,    84,    85,    89,    41,    42,
     302,    62,   196,   305,   306,   484,   519,   611,   294,   371,
     372,   373,   465,   509,   510,   556,   598,   599,   208,   308,
     309,   310,   401,   490,   489,   491,   535,   569,   570,   571,
     622,   703,   704,   752,   824,   825,   524,   566,   567,   615,
     699,   700,   289,   341,   389,   369,   362,   431,   498,   485,
     520,   197,   304,   209,   307,   466,   508,   557,   597,   536,
     568,   402,   488,   358,   359,   445,   360
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -969
static const short yypact[] =
{
     856,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
     372,  6030,   150,  -969,   100,   159,   -15,  -969,   -53,   -40,
     -35,   -23,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,    99,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,   510,    -6,  4459,  6045,  6045,  6054,    68,   404,
     656,   349,   123,   226,   226,   226,   -21,  -969,  -969,  -969,
      83,   226,  -969,  -969,  -969,   128,   -38,  -969,    59,   102,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  6063,  -969,  -969,  -969,
    -969,    75,  -969,  -969,  -969,  -969,  6045,  6063,   223,   227,
     230,   233,  -969,   242,  -969,  4459,  6108,  -969,  -969,  -969,
    -969,  -969,   163,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,   144,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,   216,   226,   226,   226,   226,   226,   226,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,   226,  -969,  -969,
    -969,   231,  -969,  -969,  -969,  -969,  -969,   226,   226,  -969,
    -969,   137,   149,   169,   226,   226,   226,   226,   171,   246,
    -969,  -969,   173,   175,   212,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,   105,   105,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
     105,   105,   185,  -969,  -969,  -969,  -969,  -969,  -969,   -50,
    -969,  -969,  -969,  -969,  -969,  -969,  6045,  6108,  6054,  6054,
    6108,  -969,   186,  2708,  -969,  -969,  -969,  -969,  6117,  -969,
    -969,   246,   226,   226,   188,   189,   191,   192,   195,   197,
     198,  -969,  -969,   204,   205,  -969,  -969,  -969,   215,   224,
     228,   237,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  6126,  6135,  -969,  -969,   240,  6180,  6189,  6198,  6207,
    6252,  6261,  6270,  6279,  6324,  6333,  6342,  -969,  6351,  -969,
    -969,  6396,  -969,  -969,  6405,  6414,  -969,  -969,  -969,  -969,
     219,  6423,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    2708,   214,   241,   222,  -969,  -969,  -969,  -969,   504,  6468,
    6477,   643,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  6468,  6486,  -969,   253,   256,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,   226,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,   665,
    6495,  -969,  -969,  6540,  4459,   236,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  6468,  6549,    25,
    2708,   250,   265,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  6558,
    6567,  -969,  -969,  -969,   226,  -969,  -969,   264,  -969,   691,
    -969,  -969,  -969,   -68,  -969,   261,  -969,  -969,  -969,  6612,
    -969,  -969,  -969,  -969,  -969,  2708,  -969,  -969,  4459,  6063,
    -969,   792,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  6621,   270,  -969,
     803,  -969,  4459,  -969,  2708,   898,  5518,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  6630,   214,
      43,    -3,  -969,  -969,  5621,  -969,  6639,  -969,  -969,  6045,
    6684,  -969,  -969,  -969,  -969,  -969,   214,   279,  4562,  -969,
    2811,  -969,  -969,  2914,  4562,  4974,  4459,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  2914,  -969,  -969,  -969,  6045,  -969,
    -969,   236,  -969,  5860,  3017,  4459,  -969,   277,  -969,  4459,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  6693,  5936,  -969,
    -969,  -969,  -969,  -969,  6702,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  3120,  -969,  -969,  -969,  -969,  -969,
     282,   111,   211,    30,  -969,   283,   -29,   298,   353,   293,
     295,   294,   330,   375,   415,  -969,  5860,  -969,   305,  -969,
    3120,  4665,  -969,  -969,  5860,  -969,  -969,  -969,  -969,  -969,
    -969,   305,  6036,  -969,  6711,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,   307,   310,  -969,  -969,
    -969,  -969,   320,  -969,   318,   328,   107,  -969,  6756,  6045,
    -969,  -969,  -969,  6765,  -969,  -969,  -969,  -969,  -969,  -969,
    2811,  -969,  -969,  -969,  -969,  -969,  -969,  5286,  5218,  -969,
    -969,  -969,  -969,  -969,  5354,  -969,   329,  5218,  3223,  3326,
    3429,  3532,  3635,  3738,  -969,  -969,  -969,    56,  5860,  -969,
    -969,  -969,   340,  -969,  4459,  -969,  -969,  -969,  -969,  6774,
    -969,  -969,  -969,  -969,  6783,   957,  5661,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  1060,  4768,  -969,
    -969,  -969,  -969,   293,  -969,  5558,   335,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
     350,  -969,  5860,  -969,  4974,  -969,  -969,  5860,  1163,  5661,
    3841,  5077,  -969,  -969,  6045,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  5354,  -969,  5727,  -969,  5860,  -969,  -969,  -969,
     345,  -969,   356,  -969,  -969,  -969,  -969,  -969,  3944,  -969,
    -969,  3944,  -969,  -969,  3944,  -969,  -969,  -969,   358,  -969,
    4871,   310,    17,  -969,  5794,  -969,   365,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  6828,  -969,  -969,  -969,   366,  -969,   155,
    -969,  5558,  4459,  -969,  -969,   485,  -969,  5992,  5926,  -969,
    -969,  1266,  4047,  -969,  1369,  4150,  -969,  1472,  4253,  5422,
    4356,  5354,  -969,  -969,  -969,  -969,   146,  -969,  -969,  -969,
    -969,  1575,  1089,   293,  -969,  5860,  -969,  -969,  -969,  -969,
     639,  -969,  -969,   882,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,   293,  -969,  -969,  -969,  -969,  5860,  1678,   334,   376,
     378,   379,   126,  -969,  5149,  1781,  -969,  -969,  -969,  -969,
    -969,  -969,   364,   367,   342,   393,   355,   394,   399,  -969,
     400,  -969,   407,   409,  -969,  -969,  -969,  -969,   417,   994,
    -969,  -969,  -969,  -969,  1884,  -969,  3944,  -969,  3944,  3944,
    -969,  -969,  3944,   310,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,   392,  -969,  -969,  -969,  5490,  -969,  1987,  -969,  2090,
    -969,  -969,  5661,  -969,   374,   532,   374,  -969,   374,   374,
     374,   374,   533,  4459,  4459,  4459,    20,  -969,   374,  -969,
    -969,  5490,  -969,  -969,  -969,  -969,  -969,  -969,  5794,  -969,
     -66,   433,   -54,  2193,   -48,   -41,   -37,   -33,   436,   438,
     439,   440,  -969,  -969,   -32,  -969,  -969,   432,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  2296,  -969,  -969,  -969,  -969,  -969,  3944,  2399,
    2502,  2605,  -969,  -969,  -969,  -969
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -147,
    -372,  -969,  -969,  -547,  -545,  -969,  -543,  -969,  -969,  -969,
    -969,  -969,  -969,  -132,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -406,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -688,  -969,  -969,    26,  -265,  -341,  -762,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -320,  -241,   -18,  -969,  -969,    11,  -585,
    -969,  -525,  -969,  -813,  -713,  -719,  -969,  -969,  -969,  -969,
    -969,  -402,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -665,
    -969,  -468,  -969,  -969,  -969,    -1,  -622,  -163,   -58,  -969,
    -277,  -969,  -620,  -969,  -250,  -969,  -969,  -969,   -56,  -969,
     -60,  -969,  -646,  -969,  -969,  -969,  -969,  -969,  -580,  -788,
    -969,  -969,  -969,  -969,  -458,  -969,   -44,  -578,  -969,  -969,
    -969,  -969,  -533,  -969,  -969,  -969,  -576,  -499,  -530,  -544,
    -968,  -517,  -252,  -113,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,   465,   600,  -969,  -969,  -969,  -969,
    -969,  -969,   -45,  -969,  -969,  -371,  -969,  -969,   -83,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,   -16,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,  -969,
    -969,  -969,  -283,  -248,  -266,   -77,  -969,  -969,  -969,  -969,
    -969,  -969,  -969,   -84,  -969,  -447,  -969,  -535,  -969,  -969,
    -969,  -969,  -969,  -186,   -62,  -969,  -204
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -572
static const short yytable[] =
{
     179,   198,   649,   342,   650,   773,   864,   346,   469,   279,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     284,   388,   295,   686,   391,   713,   714,   715,   819,   861,
     764,   616,   492,   646,   638,   647,   652,   648,   244,   777,
     638,   638,   525,   403,   602,   340,   729,   253,   637,   708,
      91,   283,   662,  1098,   637,   637,   542,   810,   390,   689,
     245,   291,   404,   653,   543,  1101,   270,    92,   271,   368,
     272,  1103,   273,   274,   275,   708,   719,  1074,  1104,   449,
      93,   651,  1105,   361,   719,    94,  1106,  1111,   254,   903,
     638,   711,   906,  1099,   364,   365,   511,    95,   514,   104,
     -32,   -32,   768,  1074,   637,  1099,   467,   405,   276,   277,
     278,  1099,   689,   887,   113,   450,   638,   638,  1099,   453,
     689,   609,  1099,   623,   246,   468,  1099,  1099,   725,   610,
     637,   637,   649,   721,   650,   723,   210,   762,   765,  1092,
     603,   912,   604,   559,   513,   914,   734,   765,   238,   913,
    -372,   837,   811,   812,   470,   813,   247,   814,   816,  -384,
    -384,  -384,   499,   646,   252,   647,   652,   648,   753,   605,
      87,    88,   576,   689,   689,  1063,  1064,  1065,  1013,   256,
     689,    80,    81,   689,   638,   638,   793,   793,   807,   807,
      80,    81,   773,   653,   689,   780,   780,   842,   637,   637,
     792,   792,   806,   806,   603,   521,   604,   905,   645,   934,
     908,   651,   689,   295,   375,   540,   295,   378,    82,    83,
     282,   333,   257,   357,   638,   546,   285,   334,   335,   336,
     286,   844,   858,   605,   287,   780,   288,   564,   637,  1078,
    -385,  -385,  -385,   537,  1048,   290,  1050,  1051,   301,  1019,
    1053,   374,   239,   240,   762,   303,   890,   325,   845,   387,
     312,   313,   558,   337,   338,   339,   968,   969,   689,   326,
     638,   321,   322,   689,   970,   689,   843,   880,   924,   925,
     971,   662,   376,   377,   637,   618,   968,   969,   689,   327,
     689,   332,   689,   343,   970,   344,   447,   345,  1052,   447,
     971,  1002,   447,   447,   844,   366,   379,   844,   408,   409,
     844,   410,   411,   842,   672,   412,   638,   413,   414,   617,
     689,   936,   879,   624,   415,   416,   639,   725,   654,   961,
     637,   845,   639,   639,   845,   417,   387,   845,   758,  1010,
    -386,  -386,  -386,   470,   418,  1003,   506,   844,   419,   843,
     454,   674,   843,   473,   940,   843,  1122,   420,   953,  1097,
     433,   953,   333,   698,   953,   689,   880,   689,   334,   335,
     336,   472,   952,   495,   845,   952,   496,   515,   952,    48,
     938,   689,   639,   516,   539,   228,   229,   230,   231,   544,
     573,  1082,   843,  1084,  1085,  1086,  1087,    49,   937,   625,
      50,   696,  -371,  1094,   337,   338,   339,    51,   639,   639,
     505,   879,   710,   711,    52,   716,    53,   211,   711,   232,
      54,   707,   689,  -383,  -383,  -383,   387,   -34,   -34,   -34,
    1028,   233,   234,   235,   738,    55,   741,    56,    57,    58,
      59,   739,   563,   767,    60,   744,   212,   745,   213,   214,
     215,   216,   749,    61,   775,   847,   754,  1029,   654,  -284,
    -284,  -284,   844,   818,   844,   844,   217,   820,   844,   891,
     857,   387,   892,   711,   562,  1027,   639,   639,   794,   794,
     808,   808,   -33,   -33,   -33,   909,  -105,   916,   922,   845,
     690,   845,   845,  1015,  1016,   845,  1017,  1018,   505,  1032,
     387,  1034,  1033,   236,  -285,  -285,  -285,   843,   689,   843,
     843,  1035,  1037,   843,  1036,  1073,   639,  1038,  1039,   242,
     243,   107,   108,   846,   619,  1040,   248,  1041,  1075,   109,
     110,   111,   112,  1079,   689,  1042,   387,  1081,  1088,   659,
    -105,  1073,   663,   690,  -286,  -286,  -286,  1063,  1064,  1065,
     659,   690,  1100,   673,  1075,  1107,  1108,  1109,  1110,  1113,
     693,   694,   639,   757,   746,   697,  1020,   885,   575,   881,
     965,   926,   901,   860,   844,   904,   671,   883,   907,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,   660,   846,  1044,  1093,   846,
     675,   845,   846,   834,   690,   690,   727,   921,   639,   910,
     733,   690,   731,  1096,   690,    90,     0,     0,     0,   843,
     270,     0,   271,   474,   272,   690,   273,   274,   275,     0,
       0,     0,     0,     0,     0,     0,     0,  -105,   967,   846,
     -94,     0,   975,   690,     0,   939,     0,     0,     0,     0,
     954,  1004,     0,   954,   748,     0,   954,     0,   881,     0,
       0,     0,   276,   277,   278,     0,   387,     0,   218,     0,
       0,     0,     0,     0,     0,     0,     0,   314,   315,   316,
     317,   318,   319,     0,     0,   219,   220,   221,     0,   222,
     223,     0,   320,     0,   -94,     0,     0,     0,     0,   690,
     822,     0,   323,   324,   690,     0,   690,     0,     0,   328,
     329,   330,   331,   224,   225,   226,     0,     0,     0,   690,
       0,   690,     0,   690,     0,     0,     0,     0,  1047,     0,
    1049,     0,     0,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,     0,
       0,   690,     0,     0,   846,     0,   846,   846,     0,   270,
     846,   271,   487,   272,     0,   273,   274,   275,     0,     0,
       0,     0,     0,     0,     0,     0,   867,   406,   407,   882,
    1083,   270,     0,   271,   500,   272,     0,   273,   274,   275,
       0,   -94,     0,     0,     0,     0,   690,     0,   690,     0,
       0,   276,   277,   278,     0,     0,     0,   270,     0,   271,
     541,   272,   690,   273,   274,   275,     0,     0,  1112,     0,
       0,     0,     0,   276,   277,   278,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1119,  1120,  1121,
       0,     0,     0,     0,     0,     0,     0,     0,   927,   276,
     277,   278,     0,   690,     0,     0,    -3,     1,     0,     0,
       0,  1030,     2,     3,     4,     5,   846,  -571,  -571,     6,
       0,     7,     8,     0,     0,  -571,  -571,  -571,  -571,     9,
      10,    11,     0,   -95,    12,     0,   497,    13,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,   577,
       0,     0,     0,     0,    15,     0,     0,     0,   270,     0,
     271,   565,   272,     0,   273,   274,   275,     0,     0,   270,
      16,   271,   574,   272,     0,   273,   274,   275,     0,     0,
      17,    18,    19,    20,    21,    22,    23,   -95,     0,   690,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
     276,   277,   278,   578,     0,     0,     0,     0,     0,   538,
       0,   276,   277,   278,     0,   690,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   579,   580,     0,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,     0,     0,
       0,     0,   114,     0,    33,     0,     0,     0,     0,  1089,
    1090,  1091,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   827,   828,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   114,   177,  1043,   178,     0,
       0,     0,     0,     0,     0,     0,     0,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,   991,   992,   993,   994,   995,   996,   997,   998,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   827,   835,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   114,   177,
       0,   178,   977,   978,   979,   980,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,   991,   992,   993,   994,
     995,   996,   997,   998,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   827,   863,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   114,   177,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   827,   941,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   114,   177,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   827,   955,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   114,   177,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     827,   957,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     114,   177,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   827,   976,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   114,   177,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   827,  1014,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   114,   177,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   827,
    1031,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   114,
     177,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   827,  1046,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   114,   177,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   827,  1076,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   114,   177,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   827,  1077,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   114,   177,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   827,  1102,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   114,   177,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   827,  1117,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   114,   177,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   827,  1123,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   114,   177,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     827,  1124,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     114,   177,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   827,  1125,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   114,   177,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   380,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   114,   177,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   380,
       0,   640,   140,   141,   142,   641,   144,   145,   642,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   114,
     177,     0,   643,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   657,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   114,   177,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   691,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   114,   177,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   626,   627,   628,   629,   707,   630,   631,     0,
     632,   633,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   114,   177,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   626,   627,   628,   629,   778,
     630,   779,     0,   632,   633,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   114,   177,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   626,   627,
     628,   629,   781,   630,   779,     0,   632,   633,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   114,   177,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   782,   783,   784,   785,   786,   787,   788,     0,   789,
     790,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   114,   177,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   782,   783,   784,   785,   786,   795,
     788,     0,   789,   790,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     114,   177,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   796,   797,   798,
     799,   800,   801,   802,     0,   803,   804,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   114,   177,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     796,   809,   798,   799,   800,   801,   802,     0,   803,   804,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   114,   177,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   865,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   114,
     177,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   893,     0,   894,   140,   141,   142,   838,   144,
     145,   839,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   114,   177,     0,   895,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   942,
     943,   944,   945,   946,   947,   948,     0,   949,   950,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   114,   177,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   942,   943,   944,   956,   946,   947,   948,     0,
     949,   950,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   114,   177,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   942,   943,   944,   958,   946,
     947,   948,     0,   949,   950,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   114,   177,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   868,   869,
     870,   871,   962,   872,   873,     0,   874,   875,   141,   142,
     876,   144,   145,   963,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   114,   177,     0,   877,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   114,   177,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   626,   627,   628,   629,     0,   630,
     631,     0,   632,   633,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     114,   177,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   626,   627,   628,
     629,   724,   630,     0,     0,   632,   633,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   114,   177,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     626,   627,   628,   629,     0,   630,   779,     0,   632,   633,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   114,   177,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   626,   627,   628,   629,   911,   630,     0,
       0,   632,   633,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   114,
     177,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   626,   627,   628,   629,
       0,   630,     0,     0,   632,   633,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   114,   177,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   868,
     869,   870,   871,     0,   872,   873,     0,   874,   875,   141,
     142,   876,   144,   145,   114,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,     0,   177,     0,   877,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,  1021,     0,  1022,
     140,     0,  1023,   114,   144,   145,  1024,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,     0,   177,     0,
    1025,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   676,     0,
       0,   677,     0,   678,     0,   679,     0,     0,   759,   763,
       0,   114,     0,   680,   681,   682,     0,   683,   684,     0,
       0,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,   685,     0,   760,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   676,     0,     0,   677,
       0,   678,     0,   679,     0,     0,   759,     0,     0,   114,
       0,   680,   681,   682,     0,   683,   684,     0,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,     0,   685,     0,   760,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   676,     0,     0,   677,     0,   678,
       0,   679,     0,     0,     0,     0,   769,   114,     0,   680,
     681,   682,     0,   683,   684,     0,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,     0,   685,     0,   770,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   676,     0,     0,   677,     0,   678,     0,   679,
       0,     0,     0,     0,     0,   114,     0,   680,   681,   682,
       0,   683,   684,     0,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
       0,   685,     0,   959,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,  1069,     0,
    1070,   140,     0,   114,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,     0,   271,   596,   272,     0,
     273,   274,   275,     0,     0,     0,     0,     0,     0,   177,
       0,   178,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   276,   277,   278,   140,
     141,   142,   838,   144,   145,   839,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   114,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,     0,   271,
     612,   272,     0,   273,   274,   275,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   676,     0,   830,   677,   831,   678,     0,   679,   276,
     277,   278,   114,   769,     0,     0,   680,   681,   682,     0,
     683,   684,     0,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,     0,
     685,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   676,     0,     0,
     677,     0,   678,     0,   679,     0,     0,     0,   888,   114,
       0,     0,   680,   681,   682,     0,   683,   684,     0,     0,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,     0,   685,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   676,     0,     0,   677,     0,   678,
       0,   679,     0,     0,     0,   114,   769,     0,     0,   680,
     681,   682,     0,   683,   684,     0,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,     0,   685,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     676,     0,     0,   677,     0,   678,     0,   679,     0,     0,
       0,   114,     0,     0,     0,   680,   681,   682,     0,   683,
     684,     0,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,     0,   685,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    63,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,    65,   271,   702,   272,     0,   273,   274,
     275,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,   276,   277,   278,     0,     0,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     929,    79,   930,   140,   141,   142,   931,   144,   145,   932,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,     0,   172,   173,   174,   175,   176,
       0,   177,   270,   933,   271,   735,   272,     0,   273,   274,
     275,   187,     0,   188,     0,   189,     0,   190,   191,   192,
     199,     0,   200,     0,   201,     0,   202,   203,   204,   270,
       0,   271,     0,   272,     0,   273,   274,   275,     0,     0,
       0,     0,     0,     0,   276,   277,   278,     0,     0,     0,
       0,     0,     0,   193,   194,   195,     0,     0,     0,     0,
       0,     0,   205,   206,   207,     0,     0,     0,     0,     0,
       0,   276,   277,   278,   199,     0,   200,     0,   201,     0,
     292,   203,   204,   392,     0,   393,     0,   394,     0,   395,
     396,   397,   422,     0,   423,     0,   424,     0,   425,   426,
     427,   422,     0,   423,     0,   432,     0,   425,   426,   427,
       0,     0,     0,     0,     0,     0,   293,   206,   207,     0,
       0,     0,     0,     0,     0,   398,   399,   400,     0,     0,
       0,     0,     0,     0,   428,   429,   430,     0,     0,     0,
       0,     0,     0,   428,   429,   430,   422,     0,   423,     0,
     434,     0,   425,   426,   427,   422,     0,   423,     0,   435,
       0,   425,   426,   427,   422,     0,   423,     0,   436,     0,
     425,   426,   427,   422,     0,   423,     0,   437,     0,   425,
     426,   427,     0,     0,     0,     0,     0,     0,   428,   429,
     430,     0,     0,     0,     0,     0,     0,   428,   429,   430,
       0,     0,     0,     0,     0,     0,   428,   429,   430,     0,
       0,     0,     0,     0,     0,   428,   429,   430,   422,     0,
     423,     0,   438,     0,   425,   426,   427,   422,     0,   423,
       0,   439,     0,   425,   426,   427,   422,     0,   423,     0,
     440,     0,   425,   426,   427,   422,     0,   423,     0,   441,
       0,   425,   426,   427,     0,     0,     0,     0,     0,     0,
     428,   429,   430,     0,     0,     0,     0,     0,     0,   428,
     429,   430,     0,     0,     0,     0,     0,     0,   428,   429,
     430,     0,     0,     0,     0,     0,     0,   428,   429,   430,
     422,     0,   423,     0,   442,     0,   425,   426,   427,   422,
       0,   423,     0,   443,     0,   425,   426,   427,   422,     0,
     423,     0,   444,     0,   425,   426,   427,   333,     0,   357,
       0,   446,     0,   334,   335,   336,     0,     0,     0,     0,
       0,     0,   428,   429,   430,     0,     0,     0,     0,     0,
       0,   428,   429,   430,     0,     0,     0,     0,     0,     0,
     428,   429,   430,     0,     0,     0,     0,     0,     0,   337,
     338,   339,   333,     0,   357,     0,   448,     0,   334,   335,
     336,   333,     0,   357,     0,   451,     0,   334,   335,   336,
     333,     0,   357,     0,   452,     0,   334,   335,   336,   456,
       0,   457,     0,   458,     0,   459,   460,   461,     0,     0,
       0,     0,     0,     0,   337,   338,   339,     0,     0,     0,
       0,     0,     0,   337,   338,   339,     0,     0,     0,     0,
       0,     0,   337,   338,   339,     0,     0,     0,     0,     0,
       0,   462,   463,   464,   475,     0,   476,     0,   477,     0,
     478,   479,   480,   422,     0,   423,     0,   486,     0,   425,
     426,   427,   422,     0,   423,     0,   493,     0,   425,   426,
     427,   422,     0,   423,     0,   501,     0,   425,   426,   427,
       0,     0,     0,     0,     0,     0,   481,   482,   483,     0,
       0,     0,     0,     0,     0,   428,   429,   430,     0,     0,
       0,     0,     0,     0,   428,   429,   430,     0,     0,     0,
       0,     0,     0,   428,   429,   430,   422,     0,   423,     0,
     502,     0,   425,   426,   427,   422,     0,   423,     0,   512,
       0,   425,   426,   427,   456,     0,   457,     0,   522,     0,
     459,   460,   461,   526,     0,   527,     0,   528,     0,   529,
     530,   531,     0,     0,     0,     0,     0,     0,   428,   429,
     430,     0,     0,     0,     0,     0,     0,   428,   429,   430,
       0,     0,     0,     0,     0,     0,   462,   463,   523,     0,
       0,     0,     0,     0,     0,   532,   533,   534,   547,     0,
     548,     0,   549,     0,   550,   551,   552,   422,     0,   423,
       0,   572,     0,   425,   426,   427,   422,     0,   423,     0,
     600,     0,   425,   426,   427,   547,     0,   548,     0,   613,
       0,   550,   614,   552,     0,     0,     0,     0,     0,     0,
     553,   554,   555,     0,     0,     0,     0,     0,     0,   428,
     429,   430,     0,     0,     0,     0,     0,     0,   428,   429,
     430,     0,     0,     0,     0,     0,     0,   553,   554,   555,
     456,     0,   457,     0,   620,     0,   459,   460,   461,   422,
       0,   423,     0,   701,     0,   425,   426,   427,   422,     0,
     423,     0,   705,     0,   425,   426,   427,   422,     0,   423,
       0,   736,     0,   425,   426,   427,     0,     0,     0,     0,
       0,     0,   462,   463,   621,     0,     0,     0,     0,     0,
       0,   428,   429,   430,     0,     0,     0,     0,     0,     0,
     428,   429,   430,     0,     0,     0,     0,     0,     0,   428,
     429,   430,   422,     0,   423,     0,   747,     0,   425,   426,
     427,   547,     0,   548,     0,   750,     0,   550,   751,   552,
     422,     0,   423,     0,   823,     0,   425,   426,   427,   422,
       0,   423,     0,   826,     0,   425,   426,   427,     0,     0,
       0,     0,     0,     0,   428,   429,   430,     0,     0,     0,
       0,     0,     0,   553,   554,   555,     0,     0,     0,     0,
       0,     0,   428,   429,   430,     0,     0,     0,     0,     0,
       0,   428,   429,   430,   422,     0,   423,     0,   920,     0,
     425,   426,   427,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   428,   429,   430
};

static const short yycheck[] =
{
      44,    46,   580,   251,   580,   724,   819,   255,   380,    86,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
      97,   304,   106,   603,   307,   647,   648,   649,   741,   817,
     718,   566,   403,   580,   578,   580,   580,   580,    59,   727,
     584,   585,   489,   309,     1,   249,   666,    85,   578,   634,
      65,    96,   585,   119,   584,   585,   124,     1,   306,   603,
      81,   105,   310,   580,   132,   119,   116,   120,   118,   119,
     120,   119,   122,   123,   124,   660,   656,  1045,   119,   362,
     120,   580,   119,   269,   664,   120,   119,   119,   126,   851,
     634,   120,   854,   159,   280,   281,   467,   120,   470,     0,
     129,   130,   722,  1071,   634,   159,   372,   311,   158,   159,
     160,   159,   656,   832,   120,   363,   660,   661,   159,   367,
     664,   124,   159,   570,   145,   373,   159,   159,   661,   132,
     660,   661,   710,   658,   710,   660,    68,   717,   718,   119,
      97,   124,    99,   515,   119,   864,   671,   727,    25,   132,
     120,   773,    96,    97,   129,    99,    73,   101,   738,   129,
     130,   131,   445,   710,    36,   710,   710,   710,   703,   126,
      70,    71,   544,   717,   718,   155,   156,   157,   966,   120,
     724,    31,    32,   727,   728,   729,   730,   731,   732,   733,
      31,    32,   911,   710,   738,   728,   729,   775,   728,   729,
     730,   731,   732,   733,    97,   488,    99,   853,   580,   897,
     856,   710,   756,   297,   297,   498,   300,   300,    68,    69,
     145,   116,   120,   118,   768,   508,     3,   122,   123,   124,
       3,   775,   812,   126,     4,   768,     3,   520,   768,  1052,
     129,   130,   131,   491,  1006,     3,  1008,  1009,    85,   123,
    1012,   296,    26,    27,   834,   111,   836,   120,   775,   303,
      44,    45,   510,   158,   159,   160,   140,   141,   812,   120,
     814,    40,    41,   817,   148,   819,   775,   821,   123,   124,
     154,   814,   298,   299,   814,   568,   140,   141,   832,   120,
     834,   120,   836,   120,   148,   120,   358,    85,  1011,   361,
     154,   923,   364,   365,   848,   120,   120,   851,   120,   120,
     854,   120,   120,   891,   597,   120,   860,   120,   120,   567,
     864,   897,   821,   571,   120,   120,   578,   860,   580,   909,
     860,   848,   584,   585,   851,   120,   380,   854,   710,   961,
     129,   130,   131,   129,   120,   925,   110,   891,   120,   848,
     131,   599,   851,   131,   898,   854,  1118,   120,   902,  1078,
     120,   905,   116,   611,   908,   909,   910,   911,   122,   123,
     124,   130,   902,   120,   891,   905,   120,   127,   908,     7,
     897,   925,   634,   118,   120,    36,    37,    38,    39,   128,
     120,  1056,   891,  1058,  1059,  1060,  1061,    25,   897,   120,
      28,   124,   120,  1068,   158,   159,   160,    35,   660,   661,
     454,   910,   129,   120,    42,   120,    44,    13,   120,    70,
      48,   116,   966,   129,   130,   131,   470,   129,   130,   131,
     974,    82,    83,    84,   127,    63,   116,    65,    66,    67,
      68,   131,   519,   720,    72,   127,    42,   119,    44,    45,
      46,    47,   700,    81,   125,   120,   704,   974,   710,   129,
     130,   131,  1006,   740,  1008,  1009,    62,   127,  1012,   124,
     120,   515,   116,   120,   518,   974,   728,   729,   730,   731,
     732,   733,   129,   130,   131,   127,     1,   122,   122,  1006,
     603,  1008,  1009,   159,   118,  1012,   118,   118,   542,   135,
     544,   159,   135,   154,   129,   130,   131,  1006,  1052,  1008,
    1009,   118,   118,  1012,   159,  1045,   768,   118,   118,    54,
      55,    11,    12,   775,   569,   118,    61,   118,  1045,    19,
      20,    21,    22,   159,  1078,   118,   580,     5,     5,   583,
      55,  1071,   586,   656,   129,   130,   131,   155,   156,   157,
     594,   664,   119,   598,  1071,   119,   118,   118,   118,   127,
     604,   605,   814,   710,   696,   609,   972,   832,   542,   821,
     911,   891,   849,   814,  1118,   852,   594,   825,   855,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   584,   848,   999,  1066,   851,
     601,  1118,   854,   766,   717,   718,   664,   884,   860,   859,
     670,   724,   668,  1071,   727,    15,    -1,    -1,    -1,  1118,
     116,    -1,   118,   119,   120,   738,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,   915,   891,
       1,    -1,   919,   756,    -1,   897,    -1,    -1,    -1,    -1,
     902,   928,    -1,   905,   699,    -1,   908,    -1,   910,    -1,
      -1,    -1,   158,   159,   160,    -1,   710,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,   214,
     215,   216,   217,    -1,    -1,    29,    30,    31,    -1,    33,
      34,    -1,   227,    -1,    55,    -1,    -1,    -1,    -1,   812,
     744,    -1,   237,   238,   817,    -1,   819,    -1,    -1,   244,
     245,   246,   247,    57,    58,    59,    -1,    -1,    -1,   832,
      -1,   834,    -1,   836,    -1,    -1,    -1,    -1,  1005,    -1,
    1007,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,    -1,
      -1,   864,    -1,    -1,  1006,    -1,  1008,  1009,    -1,   116,
    1012,   118,   119,   120,    -1,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   820,   312,   313,   824,
    1057,   116,    -1,   118,   119,   120,    -1,   122,   123,   124,
      -1,   152,    -1,    -1,    -1,    -1,   909,    -1,   911,    -1,
      -1,   158,   159,   160,    -1,    -1,    -1,   116,    -1,   118,
     119,   120,   925,   122,   123,   124,    -1,    -1,  1095,    -1,
      -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1114,  1115,  1116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   892,   158,
     159,   160,    -1,   966,    -1,    -1,     0,     1,    -1,    -1,
      -1,   974,     6,     7,     8,     9,  1118,    11,    12,    13,
      -1,    15,    16,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,     1,    28,    -1,   421,    31,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,   116,    -1,
     118,   119,   120,    -1,   122,   123,   124,    -1,    -1,   116,
      64,   118,   119,   120,    -1,   122,   123,   124,    -1,    -1,
      74,    75,    76,    77,    78,    79,    80,    55,    -1,  1052,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
     158,   159,   160,    55,    -1,    -1,    -1,    -1,    -1,   494,
      -1,   158,   159,   160,    -1,  1078,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    94,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,    55,    -1,   158,    -1,    -1,    -1,    -1,  1063,
    1064,  1065,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    55,   159,   123,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    55,   159,
      -1,   161,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    55,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    55,   159,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    55,   159,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      55,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    55,   159,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    55,   159,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    55,
     159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    55,   159,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    55,   159,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    55,   159,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    55,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    55,   159,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    55,   159,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      55,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    55,   159,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    55,   159,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    55,
     159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    55,   159,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    55,   159,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    55,   159,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    55,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    55,   159,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    55,   159,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      55,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    55,   159,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    55,   159,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    55,
     159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    55,   159,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    55,   159,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    55,   159,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    55,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    55,   159,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    55,   159,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
     118,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      55,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    55,   159,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    55,   159,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    55,
     159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,    -1,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    55,   159,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,   117,   118,    -1,   120,   121,   122,
     123,   124,   125,   126,    55,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,    -1,   161,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,   120,
     121,    -1,   123,    55,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    -1,   159,    -1,
     161,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,   113,    -1,   115,    -1,   117,    -1,    -1,   120,   121,
      -1,    55,    -1,   125,   126,   127,    -1,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    -1,   159,    -1,   161,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,   113,
      -1,   115,    -1,   117,    -1,    -1,   120,    -1,    -1,    55,
      -1,   125,   126,   127,    -1,   129,   130,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    -1,   159,    -1,   161,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,   113,    -1,   115,
      -1,   117,    -1,    -1,    -1,    -1,   122,    55,    -1,   125,
     126,   127,    -1,   129,   130,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,    -1,   161,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,   113,    -1,   115,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    55,    -1,   125,   126,   127,
      -1,   129,   130,    -1,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    -1,   161,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
     120,   121,    -1,    55,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,   118,   119,   120,    -1,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,   161,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   158,   159,   160,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    55,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,
     119,   120,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,   112,   113,   114,   115,    -1,   117,   158,
     159,   160,    55,   122,    -1,    -1,   125,   126,   127,    -1,
     129,   130,    -1,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
     113,    -1,   115,    -1,   117,    -1,    -1,    -1,   121,    55,
      -1,    -1,   125,   126,   127,    -1,   129,   130,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,   113,    -1,   115,
      -1,   117,    -1,    -1,    -1,    55,   122,    -1,    -1,   125,
     126,   127,    -1,   129,   130,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,
      -1,    55,    -1,    -1,    -1,   125,   126,   127,    -1,   129,
     130,    -1,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    -1,   159,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    23,   118,   119,   120,    -1,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    81,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
      -1,   159,   116,   161,   118,   119,   120,    -1,   122,   123,
     124,   116,    -1,   118,    -1,   120,    -1,   122,   123,   124,
     116,    -1,   118,    -1,   120,    -1,   122,   123,   124,   116,
      -1,   118,    -1,   120,    -1,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   116,    -1,   118,    -1,   120,    -1,
     122,   123,   124,   116,    -1,   118,    -1,   120,    -1,   122,
     123,   124,   116,    -1,   118,    -1,   120,    -1,   122,   123,
     124,   116,    -1,   118,    -1,   120,    -1,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   116,    -1,   118,    -1,
     120,    -1,   122,   123,   124,   116,    -1,   118,    -1,   120,
      -1,   122,   123,   124,   116,    -1,   118,    -1,   120,    -1,
     122,   123,   124,   116,    -1,   118,    -1,   120,    -1,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   116,    -1,
     118,    -1,   120,    -1,   122,   123,   124,   116,    -1,   118,
      -1,   120,    -1,   122,   123,   124,   116,    -1,   118,    -1,
     120,    -1,   122,   123,   124,   116,    -1,   118,    -1,   120,
      -1,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     116,    -1,   118,    -1,   120,    -1,   122,   123,   124,   116,
      -1,   118,    -1,   120,    -1,   122,   123,   124,   116,    -1,
     118,    -1,   120,    -1,   122,   123,   124,   116,    -1,   118,
      -1,   120,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   116,    -1,   118,    -1,   120,    -1,   122,   123,
     124,   116,    -1,   118,    -1,   120,    -1,   122,   123,   124,
     116,    -1,   118,    -1,   120,    -1,   122,   123,   124,   116,
      -1,   118,    -1,   120,    -1,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   116,    -1,   118,    -1,   120,    -1,
     122,   123,   124,   116,    -1,   118,    -1,   120,    -1,   122,
     123,   124,   116,    -1,   118,    -1,   120,    -1,   122,   123,
     124,   116,    -1,   118,    -1,   120,    -1,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   116,    -1,   118,    -1,
     120,    -1,   122,   123,   124,   116,    -1,   118,    -1,   120,
      -1,   122,   123,   124,   116,    -1,   118,    -1,   120,    -1,
     122,   123,   124,   116,    -1,   118,    -1,   120,    -1,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   116,    -1,
     118,    -1,   120,    -1,   122,   123,   124,   116,    -1,   118,
      -1,   120,    -1,   122,   123,   124,   116,    -1,   118,    -1,
     120,    -1,   122,   123,   124,   116,    -1,   118,    -1,   120,
      -1,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     116,    -1,   118,    -1,   120,    -1,   122,   123,   124,   116,
      -1,   118,    -1,   120,    -1,   122,   123,   124,   116,    -1,
     118,    -1,   120,    -1,   122,   123,   124,   116,    -1,   118,
      -1,   120,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   116,    -1,   118,    -1,   120,    -1,   122,   123,
     124,   116,    -1,   118,    -1,   120,    -1,   122,   123,   124,
     116,    -1,   118,    -1,   120,    -1,   122,   123,   124,   116,
      -1,   118,    -1,   120,    -1,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   116,    -1,   118,    -1,   120,    -1,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    15,    16,    23,
      24,    25,    28,    31,    35,    48,    64,    74,    75,    76,
      77,    78,    79,    80,    86,    87,    88,    89,    90,    91,
      92,    93,   118,   158,   163,   164,   165,   199,   211,   221,
     326,   370,   371,   363,   200,   331,   340,   338,     7,    25,
      28,    35,    42,    44,    48,    63,    65,    66,    67,    68,
      72,    81,   373,     6,     8,    23,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    81,
      31,    32,    68,    69,   367,   368,   327,    70,    71,   369,
     367,    65,   120,   120,   120,   120,   332,   329,   168,   169,
     170,   167,   341,   166,     0,   212,   339,    11,    12,    19,
      20,    21,    22,   120,    55,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   159,   161,   308,
     319,   320,   321,   322,   323,   324,   325,   116,   118,   120,
     122,   123,   124,   158,   159,   160,   374,   423,   374,   116,
     118,   120,   122,   123,   124,   158,   159,   160,   390,   425,
      68,    13,    42,    44,    45,    46,    47,    62,    12,    29,
      30,    31,    33,    34,    57,    58,    59,   365,    36,    37,
      38,    39,    70,    82,    83,    84,   154,   364,    25,    26,
      27,   366,   366,   366,    59,    81,   145,    73,   366,   359,
     346,   349,    36,    85,   126,   347,   120,   120,   348,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   342,   343,
     116,   118,   120,   122,   123,   124,   158,   159,   160,   417,
     345,   344,   145,   374,   417,     3,     3,     4,     3,   414,
       3,   308,   122,   158,   380,   425,   333,   334,   335,   336,
     337,    85,   372,   111,   424,   375,   376,   426,   391,   392,
     393,   361,    44,    45,   366,   366,   366,   366,   366,   366,
     366,    40,    41,   366,   366,   120,   120,   120,   366,   366,
     366,   366,   120,   116,   122,   123,   124,   158,   159,   160,
     438,   415,   415,   120,   120,    85,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   118,   435,   436,
     438,   435,   418,   328,   435,   435,   120,   330,   119,   417,
     213,   381,   382,   383,   374,   380,   390,   390,   380,   120,
     118,   172,   173,   174,   175,   176,   178,   308,   414,   416,
     415,   414,   116,   118,   120,   122,   123,   124,   158,   159,
     160,   394,   433,   416,   415,   438,   366,   366,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   360,   116,   118,   120,   122,   123,   124,   158,   159,
     160,   419,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   437,   120,   436,   120,   414,
     415,   120,   120,   415,   131,   215,   116,   118,   120,   122,
     123,   124,   158,   159,   160,   384,   427,   416,   415,   172,
     129,   201,   130,   131,   119,   116,   118,   120,   122,   123,
     124,   158,   159,   160,   377,   421,   120,   119,   434,   396,
     395,   397,   377,   120,   362,   120,   120,   366,   420,   414,
     119,   120,   120,   216,   217,   308,   110,   277,   428,   385,
     386,   377,   120,   119,   172,   127,   118,   180,   177,   378,
     422,   414,   120,   160,   408,   427,   116,   118,   120,   122,
     123,   124,   158,   159,   160,   398,   431,   415,   366,   120,
     414,   119,   124,   132,   128,   222,   414,   116,   118,   120,
     122,   123,   124,   158,   159,   160,   387,   429,   415,   172,
     181,   179,   308,   417,   414,   119,   409,   410,   432,   399,
     400,   401,   120,   120,   119,   217,   172,     1,    55,    94,
      95,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   152,   223,   119,   430,   388,   389,
     120,   202,     1,    97,    99,   126,   183,   184,   185,   124,
     132,   379,   119,   120,   123,   411,   429,   415,   414,   374,
     120,   160,   402,   427,   415,   120,   112,   113,   114,   115,
     117,   118,   120,   121,   250,   251,   314,   320,   321,   324,
     120,   124,   127,   161,   171,   172,   175,   176,   178,   309,
     318,   319,   321,   323,   324,   224,   225,   118,   247,   308,
     250,   246,   314,   308,   242,   226,   228,   231,   233,   236,
     238,   247,   414,   374,   415,   277,   110,   113,   115,   117,
     125,   126,   127,   129,   130,   159,   300,   301,   317,   321,
     325,   118,   186,   308,   308,   182,   124,   308,   415,   412,
     413,   120,   119,   403,   404,   120,   252,   116,   251,   253,
     129,   120,   278,   278,   278,   278,   120,   279,   280,   300,
     249,   253,   248,   253,   116,   314,   241,   280,   284,   284,
     290,   290,   292,   292,   253,   119,   120,   203,   127,   131,
     188,   116,   189,   187,   127,   119,   185,   120,   374,   415,
     120,   123,   405,   429,   415,   282,   256,   171,   172,   120,
     161,   214,   300,   121,   214,   300,   281,   282,   284,   122,
     161,   218,   219,   257,   300,   125,   243,   214,   116,   118,
     314,   116,   112,   113,   114,   115,   116,   117,   118,   120,
     121,   312,   320,   321,   324,   117,   112,   113,   114,   115,
     116,   117,   118,   120,   121,   311,   320,   321,   324,   113,
       1,    96,    97,    99,   101,   204,   300,   302,   282,   256,
     127,   286,   308,   120,   406,   407,   120,   118,   119,   308,
     112,   114,   255,   257,   279,   119,   258,   278,   124,   127,
     244,   245,   309,   319,   321,   323,   324,   120,   227,   285,
     229,   232,   291,   234,   237,   293,   239,   120,   300,   205,
     246,   301,   303,   119,   255,   118,   190,   308,   112,   113,
     114,   115,   117,   118,   120,   121,   124,   161,   315,   319,
     321,   324,   374,   415,   283,   218,   254,   257,   121,   259,
     300,   124,   116,   118,   120,   161,   220,   296,   297,   309,
     318,   282,   294,   220,   282,   294,   220,   282,   294,   127,
     286,   116,   124,   132,   257,   192,   122,   193,   191,   287,
     120,   282,   122,   260,   123,   124,   245,   308,   298,   118,
     120,   124,   127,   161,   214,   310,   318,   319,   323,   324,
     321,   119,   112,   113,   114,   115,   116,   117,   118,   120,
     121,   313,   320,   321,   324,   119,   115,   119,   115,   161,
     206,   300,   116,   127,   207,   219,   304,   282,   140,   141,
     148,   154,   194,   195,   288,   282,   119,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   261,
     262,   263,   278,   300,   282,   299,   230,   295,   235,   240,
     278,   208,   210,   301,   119,   159,   118,   118,   118,   123,
     195,   118,   120,   123,   127,   161,   316,   319,   321,   323,
     325,   119,   135,   135,   159,   118,   159,   118,   118,   118,
     118,   118,   118,   123,   263,   264,   119,   282,   220,   282,
     220,   220,   256,   220,   196,   198,   197,   289,   265,   267,
     268,   269,   270,   155,   156,   157,   272,   273,   266,   118,
     120,   305,   306,   320,   322,   323,   119,   119,   255,   159,
     271,     5,   271,   282,   271,   271,   271,   271,     5,   308,
     308,   308,   119,   273,   271,   307,   306,   257,   119,   159,
     119,   119,   119,   119,   119,   119,   119,   119,   118,   118,
     118,   119,   282,   127,   274,   275,   276,   119,   209,   282,
     282,   282,   220,   119,   119,   119
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1


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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 216 "surface.yy"
    { YYACCEPT; ;}
    break;

  case 3:
#line 218 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			;}
    break;

  case 8:
#line 232 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 9:
#line 234 "surface.yy"
    {
			  int lineNr = lineNumber;
			  eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile(yyvsp[0].yyString, directory, fileName, lineNr))
			    includeFile(directory, fileName, false, lineNr);
			;}
    break;

  case 10:
#line 242 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 11:
#line 244 "surface.yy"
    {
			  int lineNr = lineNumber;
			  eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile(yyvsp[0].yyString, directory, fileName, lineNr))
			    includeFile(directory, fileName, true, lineNr);
			;}
    break;

  case 12:
#line 253 "surface.yy"
    {
			  cout << directoryManager.getCwd() << '\n';
			;}
    break;

  case 13:
#line 256 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 14:
#line 258 "surface.yy"
    {
			  string directory;
			  directoryManager.realPath(yyvsp[0].yyString, directory);
			  if (!directoryManager.cd(directory))
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": cd failed");
			    }
			;}
    break;

  case 15:
#line 267 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 16:
#line 269 "surface.yy"
    {
			  string directory;
			  directoryManager.realPath(yyvsp[0].yyString, directory);
			  if (directoryManager.pushd(directory) == UNDEFINED)
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": pushd failed");
			    }
			;}
    break;

  case 17:
#line 279 "surface.yy"
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
#line 289 "surface.yy"
    { lexerStringMode(); ;}
    break;

  case 19:
#line 291 "surface.yy"
    {
			  system((string("ls") + yyvsp[0].yyString).c_str());
			;}
    break;

  case 20:
#line 295 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			;}
    break;

  case 21:
#line 300 "surface.yy"
    {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			;}
    break;

  case 22:
#line 333 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression(yyvsp[-1].yyToken));
                        ;}
    break;

  case 23:
#line 337 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression(yyvsp[-1].yyToken));
                        ;}
    break;

  case 27:
#line 344 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			;}
    break;

  case 28:
#line 352 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  moduleExpressions.push(new ModuleExpression(t));
			;}
    break;

  case 30:
#line 363 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			;}
    break;

  case 35:
#line 379 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression(yyvsp[0].yyToken));
                        ;}
    break;

  case 36:
#line 386 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			;}
    break;

  case 37:
#line 394 "surface.yy"
    { clear(); ;}
    break;

  case 38:
#line 396 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, bubble));
			;}
    break;

  case 39:
#line 403 "surface.yy"
    {;}
    break;

  case 40:
#line 406 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 41:
#line 407 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 42:
#line 414 "surface.yy"
    {
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			;}
    break;

  case 43:
#line 419 "surface.yy"
    {
			  currentSyntaxContainer = oldSyntaxContainer;
			;}
    break;

  case 49:
#line 434 "surface.yy"
    {
			  currentRenaming->addSortMapping(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 50:
#line 438 "surface.yy"
    {
			  currentRenaming->addLabelMapping(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 51:
#line 441 "surface.yy"
    {;}
    break;

  case 52:
#line 444 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 53:
#line 446 "surface.yy"
    {
			  currentRenaming->addOpMapping(bubble);
			;}
    break;

  case 54:
#line 449 "surface.yy"
    { clear(); ;}
    break;

  case 55:
#line 451 "surface.yy"
    {
			  currentRenaming->addOpMapping(bubble);
			;}
    break;

  case 56:
#line 456 "surface.yy"
    {;}
    break;

  case 58:
#line 460 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 59:
#line 461 "surface.yy"
    { currentRenaming->addOpTarget(bubble); ;}
    break;

  case 60:
#line 462 "surface.yy"
    { clear(); ;}
    break;

  case 61:
#line 463 "surface.yy"
    { currentRenaming->addOpTarget(bubble); ;}
    break;

  case 62:
#line 466 "surface.yy"
    {;}
    break;

  case 66:
#line 474 "surface.yy"
    { currentRenaming->setPrec(yyvsp[0].yyToken); ;}
    break;

  case 67:
#line 475 "surface.yy"
    { clear(); ;}
    break;

  case 68:
#line 476 "surface.yy"
    { currentRenaming->setGather(bubble); ;}
    break;

  case 69:
#line 477 "surface.yy"
    { clear(); ;}
    break;

  case 70:
#line 478 "surface.yy"
    { currentRenaming->setFormat(bubble); ;}
    break;

  case 71:
#line 479 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 72:
#line 480 "surface.yy"
    { currentRenaming->setLatexMacro(yyvsp[-1].yyString); ;}
    break;

  case 73:
#line 486 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 74:
#line 488 "surface.yy"
    {
			  fileTable.beginModule(yyvsp[-4].yyToken, yyvsp[-2].yyToken);
			  interpreter.setCurrentView(new View(yyvsp[-2].yyToken));
			  currentSyntaxContainer = CV;
			  CV->addFrom(moduleExpressions.top());
			  moduleExpressions.pop();
			;}
    break;

  case 75:
#line 496 "surface.yy"
    {
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			;}
    break;

  case 76:
#line 501 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  interpreter.insertView((yyvsp[-9].yyToken).code(), CV);
			  CV->finishView();
			;}
    break;

  case 79:
#line 514 "surface.yy"
    {
			  CV->addSortMapping(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 80:
#line 517 "surface.yy"
    {;}
    break;

  case 81:
#line 518 "surface.yy"
    { clear(); ;}
    break;

  case 84:
#line 523 "surface.yy"
    { yyval.yyToken = yyvsp[-1].yyToken; ;}
    break;

  case 85:
#line 525 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  yyval.yyToken = t;
			;}
    break;

  case 86:
#line 535 "surface.yy"
    {
			  //
			  //	Specific op->op mapping.
			  //
			  Token::peelParens(bubble);  // remove any enclosing parens from op name
			  CV->addOpMapping(bubble);
			;}
    break;

  case 87:
#line 543 "surface.yy"
    {
			  clear();
			;}
    break;

  case 88:
#line 547 "surface.yy"
    {
			  Token::peelParens(bubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(bubble);
			;}
    break;

  case 89:
#line 552 "surface.yy"
    {
			  //
			  //	At this point we don't know if we have an op->term mapping
			  //	or a generic op->op mapping so we save the from description and
			  //	press on.
			  //
			  opDescription = bubble;
			  clear();
			;}
    break;

  case 90:
#line 562 "surface.yy"
    {
			  if (bubble[0].code() == Token::encode("term"))
			    {
			      //
			      //	Op->term mapping.
			      //
			      CV->addOpTermMapping(opDescription, bubble);
			    }
			  else
			    {
			      //
			      //	Generic op->op mapping.
			      //
			      Token::peelParens(opDescription);  // remove any enclosing parens from op name
			      CV->addOpMapping(opDescription);
			      Token::peelParens(bubble);  // remove any enclosing parens from op name
			      CV->addOpTarget(bubble);
			    }
			;}
    break;

  case 91:
#line 586 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 92:
#line 588 "surface.yy"
    {
			  interpreter.setCurrentModule(new PreModule(yyvsp[-2].yyToken, yyvsp[0].yyToken));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 93:
#line 594 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule(yyvsp[0].yyToken);
			;}
    break;

  case 94:
#line 601 "surface.yy"
    {;}
    break;

  case 95:
#line 603 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  store(t);
			;}
    break;

  case 96:
#line 612 "surface.yy"
    {;}
    break;

  case 100:
#line 621 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter(yyvsp[-2].yyToken, me);
			;}
    break;

  case 101:
#line 629 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  clear();
			  store(t);
			  currentSyntaxContainer->addType(false, bubble);
			;}
    break;

  case 105:
#line 646 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  store(t);
			;}
    break;

  case 110:
#line 663 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport(yyvsp[-1].yyToken, me);
			;}
    break;

  case 111:
#line 669 "surface.yy"
    { clear(); ;}
    break;

  case 112:
#line 670 "surface.yy"
    { CM->addSortDecl(bubble); ;}
    break;

  case 113:
#line 672 "surface.yy"
    { clear(); ;}
    break;

  case 114:
#line 673 "surface.yy"
    { CM->addSubsortDecl(bubble); ;}
    break;

  case 115:
#line 675 "surface.yy"
    {;}
    break;

  case 116:
#line 677 "surface.yy"
    {;}
    break;

  case 117:
#line 679 "surface.yy"
    {;}
    break;

  case 118:
#line 681 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 119:
#line 682 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 120:
#line 683 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 121:
#line 685 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 122:
#line 686 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 123:
#line 687 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 124:
#line 688 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 125:
#line 690 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 126:
#line 691 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 127:
#line 692 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 128:
#line 694 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 129:
#line 695 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 130:
#line 696 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 131:
#line 697 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 132:
#line 699 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 133:
#line 700 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 134:
#line 701 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 135:
#line 703 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 136:
#line 704 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 137:
#line 705 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 138:
#line 706 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 139:
#line 709 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 140:
#line 714 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 141:
#line 719 "surface.yy"
    {
			;}
    break;

  case 142:
#line 722 "surface.yy"
    {
			;}
    break;

  case 143:
#line 725 "surface.yy"
    { clear(); ;}
    break;

  case 144:
#line 726 "surface.yy"
    { CM->addSubsortDecl(bubble); ;}
    break;

  case 145:
#line 729 "surface.yy"
    {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeOpDeclsConsistent();
			;}
    break;

  case 146:
#line 739 "surface.yy"
    {;}
    break;

  case 147:
#line 740 "surface.yy"
    {;}
    break;

  case 150:
#line 748 "surface.yy"
    {
			;}
    break;

  case 151:
#line 752 "surface.yy"
    { currentSyntaxContainer->addVarDecl(yyvsp[0].yyToken); ;}
    break;

  case 152:
#line 753 "surface.yy"
    { currentSyntaxContainer->addVarDecl(yyvsp[0].yyToken); ;}
    break;

  case 153:
#line 756 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 154:
#line 757 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 155:
#line 758 "surface.yy"
    { clear(); ;}
    break;

  case 156:
#line 759 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 159:
#line 767 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  CM->addOpDecl(bubble);
			;}
    break;

  case 160:
#line 772 "surface.yy"
    { clear(); ;}
    break;

  case 161:
#line 773 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 162:
#line 777 "surface.yy"
    {
			  if (yyvsp[-1].yyBool)
			    CM->convertSortsToKinds();
			;}
    break;

  case 165:
#line 787 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 166:
#line 788 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 169:
#line 796 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  currentSyntaxContainer->addType(false, bubble);
			;}
    break;

  case 170:
#line 801 "surface.yy"
    { clear(); ;}
    break;

  case 171:
#line 803 "surface.yy"
    {
			  currentSyntaxContainer->addType(true, bubble);
			;}
    break;

  case 172:
#line 808 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 173:
#line 809 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 174:
#line 812 "surface.yy"
    {;}
    break;

  case 178:
#line 821 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			;}
    break;

  case 179:
#line 825 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			;}
    break;

  case 180:
#line 829 "surface.yy"
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			;}
    break;

  case 181:
#line 835 "surface.yy"
    {
			  CM->setFlag(SymbolType::ASSOC);
			;}
    break;

  case 182:
#line 839 "surface.yy"
    {
			  CM->setFlag(SymbolType::COMM);
			;}
    break;

  case 183:
#line 842 "surface.yy"
    { clear(); ;}
    break;

  case 184:
#line 843 "surface.yy"
    { CM->setIdentity(bubble); ;}
    break;

  case 185:
#line 845 "surface.yy"
    {
			  CM->setFlag(SymbolType::IDEM);
			;}
    break;

  case 186:
#line 849 "surface.yy"
    {
			  CM->setFlag(SymbolType::ITER);
			;}
    break;

  case 187:
#line 852 "surface.yy"
    { CM->setPrec(yyvsp[0].yyToken); ;}
    break;

  case 188:
#line 853 "surface.yy"
    { clear(); ;}
    break;

  case 189:
#line 854 "surface.yy"
    { CM->setGather(bubble); ;}
    break;

  case 190:
#line 855 "surface.yy"
    { clear(); ;}
    break;

  case 191:
#line 856 "surface.yy"
    { CM->setFormat(bubble); ;}
    break;

  case 192:
#line 857 "surface.yy"
    { clear(); ;}
    break;

  case 193:
#line 858 "surface.yy"
    { CM->setStrat(bubble); ;}
    break;

  case 194:
#line 859 "surface.yy"
    { clear(); ;}
    break;

  case 195:
#line 860 "surface.yy"
    { CM->setPoly(bubble); ;}
    break;

  case 196:
#line 862 "surface.yy"
    {
			  CM->setFlag(SymbolType::MEMO);
			;}
    break;

  case 197:
#line 866 "surface.yy"
    {
			  CM->setFlag(SymbolType::CTOR);
			;}
    break;

  case 198:
#line 870 "surface.yy"
    {
			  clear();
			  CM->setFrozen(bubble);
			;}
    break;

  case 199:
#line 874 "surface.yy"
    { clear(); ;}
    break;

  case 200:
#line 875 "surface.yy"
    { CM->setFrozen(bubble); ;}
    break;

  case 201:
#line 877 "surface.yy"
    {
			  CM->setFlag(SymbolType::CONFIG);
			;}
    break;

  case 202:
#line 881 "surface.yy"
    {
			  CM->setFlag(SymbolType::OBJECT);
			;}
    break;

  case 203:
#line 885 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 204:
#line 889 "surface.yy"
    {
			  CM->setMetadata(yyvsp[0].yyToken);
			;}
    break;

  case 205:
#line 892 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 206:
#line 893 "surface.yy"
    { CM->setLatexMacro(yyvsp[-1].yyString); ;}
    break;

  case 207:
#line 894 "surface.yy"
    {;}
    break;

  case 208:
#line 896 "surface.yy"
    {
			  CM->setFlag(SymbolType::DITTO);
			;}
    break;

  case 209:
#line 901 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 210:
#line 902 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 213:
#line 910 "surface.yy"
    {
			  clear();
			  CM->addHook(PreModule::ID_HOOK, yyvsp[0].yyToken, bubble);
			;}
    break;

  case 214:
#line 914 "surface.yy"
    { clear(); ;}
    break;

  case 215:
#line 916 "surface.yy"
    {
			  CM->addHook(PreModule::ID_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 216:
#line 919 "surface.yy"
    { clear(); ;}
    break;

  case 217:
#line 921 "surface.yy"
    {
			  CM->addHook(PreModule::OP_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 218:
#line 924 "surface.yy"
    { clear(); ;}
    break;

  case 219:
#line 926 "surface.yy"
    {
			  CM->addHook(PreModule::TERM_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 220:
#line 934 "surface.yy"
    {;}
    break;

  case 221:
#line 936 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing " <<
				       QUOTE("is") << " keyword.");
			;}
    break;

  case 222:
#line 942 "surface.yy"
    {;}
    break;

  case 223:
#line 944 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			;}
    break;

  case 224:
#line 952 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 226:
#line 956 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 227:
#line 957 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 228:
#line 958 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 229:
#line 959 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 230:
#line 965 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 231:
#line 966 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 232:
#line 967 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 234:
#line 971 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 235:
#line 972 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 236:
#line 973 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 238:
#line 977 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 239:
#line 978 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 240:
#line 979 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 242:
#line 983 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 243:
#line 984 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 244:
#line 985 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 246:
#line 989 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 247:
#line 990 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 248:
#line 991 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 250:
#line 995 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 251:
#line 996 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 252:
#line 997 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 254:
#line 1001 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 255:
#line 1002 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 256:
#line 1003 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 259:
#line 1008 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 260:
#line 1009 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 261:
#line 1012 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 262:
#line 1013 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 263:
#line 1014 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 264:
#line 1015 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 265:
#line 1016 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 266:
#line 1017 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 267:
#line 1018 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 268:
#line 1025 "surface.yy"
    {
			  Token t;
			  if (fragments.size() == 1)
			    t = fragments[0];
			  else
			    t.tokenize(Token::bubbleToPrefixNameCode(fragments), fragments[0].lineNumber());
			  fragClear();
			  yyval.yyToken = t;
			;}
    break;

  case 269:
#line 1036 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 270:
#line 1037 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 271:
#line 1038 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 272:
#line 1041 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 273:
#line 1042 "surface.yy"
    {;}
    break;

  case 274:
#line 1043 "surface.yy"
    {;}
    break;

  case 275:
#line 1049 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 276:
#line 1050 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 281:
#line 1054 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 282:
#line 1055 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 440:
#line 1160 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 441:
#line 1161 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 442:
#line 1163 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.setCurrentModule(bubble);
			;}
    break;

  case 443:
#line 1167 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 444:
#line 1168 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 445:
#line 1170 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->dump();
			;}
    break;

  case 446:
#line 1176 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 447:
#line 1182 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(bubble);
			;}
    break;

  case 448:
#line 1189 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 449:
#line 1195 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(bubble);
			;}
    break;

  case 450:
#line 1202 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 451:
#line 1208 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(bubble, yyvsp[-3].yyBool);
			;}
    break;

  case 452:
#line 1215 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 453:
#line 1222 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(bubble, number, yyvsp[-3].yyBool);
			;}
    break;

  case 454:
#line 1228 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 455:
#line 1236 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 456:
#line 1242 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 457:
#line 1250 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 458:
#line 1256 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 459:
#line 1263 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(bubble, number, yyvsp[-3].yyBool);
			;}
    break;

  case 460:
#line 1269 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 461:
#line 1277 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(bubble, number, number2);
			;}
    break;

  case 462:
#line 1283 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 463:
#line 1290 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(bubble, yyvsp[-2].yyBool, number);
			;}
    break;

  case 464:
#line 1296 "surface.yy"
    {
			  interpreter.cont(yyvsp[-1].yyInt64, yyvsp[-3].yyBool);
			;}
    break;

  case 465:
#line 1300 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 466:
#line 1306 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(bubble);
			;}
    break;

  case 467:
#line 1311 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 468:
#line 1313 "surface.yy"
    {
			  lexerInitialMode();
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(bubble);
			;}
    break;

  case 469:
#line 1320 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 470:
#line 1322 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 471:
#line 1326 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 472:
#line 1328 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude(yyvsp[-3].yyBool);
			;}
    break;

  case 473:
#line 1332 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 474:
#line 1334 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 475:
#line 1338 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 476:
#line 1340 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal(yyvsp[-3].yyBool);
			;}
    break;

  case 477:
#line 1345 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			;}
    break;

  case 478:
#line 1352 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 479:
#line 1354 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 480:
#line 1359 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 481:
#line 1361 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 482:
#line 1366 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 483:
#line 1368 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showModule(true);
			;}
    break;

  case 484:
#line 1373 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 485:
#line 1375 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentView(bubble))
			    interpreter.showView();
			;}
    break;

  case 486:
#line 1381 "surface.yy"
    {
			  interpreter.showModules(true);
			;}
    break;

  case 487:
#line 1385 "surface.yy"
    {
			  interpreter.showNamedViews();
			;}
    break;

  case 488:
#line 1388 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 489:
#line 1390 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSortsAndSubsorts();
			;}
    break;

  case 490:
#line 1395 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 491:
#line 1397 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showOps();
			;}
    break;

  case 492:
#line 1402 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 493:
#line 1404 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showVars();
			;}
    break;

  case 494:
#line 1409 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 495:
#line 1411 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showMbs();
			;}
    break;

  case 496:
#line 1416 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 497:
#line 1418 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showEqs();
			;}
    break;

  case 498:
#line 1423 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 499:
#line 1425 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showRls();
			;}
    break;

  case 500:
#line 1430 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 501:
#line 1432 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSummary();
			;}
    break;

  case 502:
#line 1437 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 503:
#line 1439 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showKinds();
			;}
    break;

  case 504:
#line 1445 "surface.yy"
    {
			  interpreter.showSearchPath(yyvsp[-1].yyInt64);
			;}
    break;

  case 505:
#line 1449 "surface.yy"
    {
			  interpreter.showSearchPathLabels(yyvsp[-1].yyInt64);
			;}
    break;

  case 506:
#line 1453 "surface.yy"
    {
			  interpreter.showSearchGraph();
			;}
    break;

  case 507:
#line 1456 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 508:
#line 1458 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showProfile();
			;}
    break;

  case 509:
#line 1467 "surface.yy"
    {
			  globalAdvisoryFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 510:
#line 1471 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 511:
#line 1475 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 512:
#line 1479 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 513:
#line 1483 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, yyvsp[-1].yyBool);
			;}
    break;

  case 514:
#line 1487 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 515:
#line 1491 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, yyvsp[-1].yyBool);
			;}
    break;

  case 516:
#line 1495 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 517:
#line 1499 "surface.yy"
    {
			  interpreter.setPrintFlag(yyvsp[-2].yyPrintFlags, yyvsp[-1].yyBool);
			;}
    break;

  case 518:
#line 1503 "surface.yy"
    {
			  interpreter.setFlag(yyvsp[-2].yyFlags, yyvsp[-1].yyBool);
			;}
    break;

  case 519:
#line 1507 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, yyvsp[-1].yyBool);
			;}
    break;

  case 520:
#line 1510 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 521:
#line 1511 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 522:
#line 1513 "surface.yy"
    {
			  interpreter.setAutoImport(yyvsp[-5].yyImportMode, yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 523:
#line 1516 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 524:
#line 1517 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 525:
#line 1519 "surface.yy"
    {
			  interpreter.setOmodInclude(yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 526:
#line 1523 "surface.yy"
    {
			  globalVerboseFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 527:
#line 1527 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, yyvsp[-1].yyBool);
			;}
    break;

  case 528:
#line 1531 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, yyvsp[-1].yyBool);
			;}
    break;

  case 529:
#line 1535 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, yyvsp[-1].yyBool);
			;}
    break;

  case 530:
#line 1539 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 531:
#line 1543 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 532:
#line 1550 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			;}
    break;

  case 533:
#line 1554 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			;}
    break;

  case 534:
#line 1558 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			;}
    break;

  case 535:
#line 1562 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			;}
    break;

  case 536:
#line 1569 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 537:
#line 1573 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 538:
#line 1579 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 540:
#line 1586 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_MIXFIX; ;}
    break;

  case 541:
#line 1587 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_FLAT; ;}
    break;

  case 542:
#line 1588 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_WITH_ALIASES; ;}
    break;

  case 543:
#line 1589 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_WITH_PARENS; ;}
    break;

  case 544:
#line 1590 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_GRAPH; ;}
    break;

  case 545:
#line 1591 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_CONCEAL; ;}
    break;

  case 546:
#line 1592 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_NUMBER; ;}
    break;

  case 547:
#line 1593 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_RAT; ;}
    break;

  case 548:
#line 1594 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_COLOR; ;}
    break;

  case 549:
#line 1595 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_FORMAT; ;}
    break;

  case 550:
#line 1598 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE; ;}
    break;

  case 551:
#line 1599 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_CONDITION; ;}
    break;

  case 552:
#line 1600 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_WHOLE; ;}
    break;

  case 553:
#line 1601 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_SUBSTITUTION; ;}
    break;

  case 554:
#line 1602 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_SELECT; ;}
    break;

  case 555:
#line 1603 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_MB; ;}
    break;

  case 556:
#line 1604 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_EQ; ;}
    break;

  case 557:
#line 1605 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_RL; ;}
    break;

  case 558:
#line 1606 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_REWRITE; ;}
    break;

  case 559:
#line 1607 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_BODY; ;}
    break;

  case 560:
#line 1610 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 561:
#line 1611 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 562:
#line 1614 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 563:
#line 1615 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 564:
#line 1618 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 565:
#line 1619 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 566:
#line 1622 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 567:
#line 1623 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 568:
#line 1626 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 569:
#line 1627 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 570:
#line 1630 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 571:
#line 1631 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 572:
#line 1634 "surface.yy"
    { yyval.yyInt64 = yyvsp[0].yyInt64; ;}
    break;

  case 573:
#line 1635 "surface.yy"
    { yyval.yyInt64 = NONE; ;}
    break;

  case 574:
#line 1638 "surface.yy"
    { yyval.yyImportMode = ImportModule::PROTECTING; ;}
    break;

  case 575:
#line 1639 "surface.yy"
    { yyval.yyImportMode = ImportModule::EXTENDING; ;}
    break;

  case 576:
#line 1640 "surface.yy"
    { yyval.yyImportMode = ImportModule::INCLUDING; ;}
    break;

  case 577:
#line 1648 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 579:
#line 1650 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 581:
#line 1654 "surface.yy"
    { moduleExpr = bubble; clear(); ;}
    break;

  case 582:
#line 1655 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 583:
#line 1656 "surface.yy"
    {;}
    break;

  case 584:
#line 1657 "surface.yy"
    {;}
    break;

  case 585:
#line 1667 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 587:
#line 1669 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 589:
#line 1671 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 591:
#line 1676 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 593:
#line 1678 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 595:
#line 1680 "surface.yy"
    {;}
    break;

  case 596:
#line 1685 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 598:
#line 1690 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 600:
#line 1692 "surface.yy"
    {;}
    break;

  case 601:
#line 1705 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 603:
#line 1707 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 605:
#line 1709 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 607:
#line 1718 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 609:
#line 1720 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 611:
#line 1722 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 613:
#line 1724 "surface.yy"
    {;}
    break;

  case 614:
#line 1733 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 616:
#line 1738 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 618:
#line 1740 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 620:
#line 1742 "surface.yy"
    {;}
    break;

  case 621:
#line 1750 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 623:
#line 1752 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 625:
#line 1754 "surface.yy"
    {;}
    break;

  case 626:
#line 1763 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  number2 = Token::codeToInt64(bubble[3].code());
			  clear();
			;}
    break;

  case 628:
#line 1769 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 630:
#line 1771 "surface.yy"
    {;}
    break;

  case 631:
#line 1779 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 633:
#line 1781 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 635:
#line 1783 "surface.yy"
    {;}
    break;

  case 636:
#line 1792 "surface.yy"
    {
			  number2 = Token::codeToInt64(bubble[2].code());
			  clear();
			;}
    break;

  case 638:
#line 1797 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 640:
#line 1799 "surface.yy"
    {;}
    break;

  case 641:
#line 1805 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 643:
#line 1809 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 645:
#line 1814 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 655:
#line 1822 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 656:
#line 1823 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 664:
#line 1827 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 665:
#line 1828 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 672:
#line 1833 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 673:
#line 1834 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 681:
#line 1838 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 682:
#line 1839 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 689:
#line 1843 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 690:
#line 1844 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 697:
#line 1849 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 698:
#line 1850 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 705:
#line 1855 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 706:
#line 1856 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 712:
#line 1861 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 713:
#line 1862 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 719:
#line 1867 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 720:
#line 1868 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 723:
#line 1878 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  interpreter.addSelected(bubble);
			;}
    break;

  case 724:
#line 1883 "surface.yy"
    { clear(); ;}
    break;

  case 725:
#line 1885 "surface.yy"
    {
			  interpreter.addSelected(bubble);
			;}
    break;


    }

/* Line 999 of yacc.c.  */
#line 6313 "surface.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1915 "surface.yy"


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
  //bubble.contractTo(0);
  //moduleExpr.contractTo(0);
  //pattern.contractTo(0);
  interpreter.makeClean(lineNumber);
  /*
  if (currentModule != 0 && !(currentModule->isComplete()))
    {
      IssueAdvisory(cerr << LineNumber(lineNumber) << ": discarding incomplete module.");
      delete currentModule;
      currentModule = 0;
    }
  */
}

