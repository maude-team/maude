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
     KW_OREWRITE = 276,
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
#define KW_OREWRITE 276
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
#line 97 "surface.yy"
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
#line 447 "surface.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 107 "surface.yy"

int yylex(YYSTYPE* lvalp);


/* Line 214 of yacc.c.  */
#line 462 "surface.c"

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
#define YYLAST   6786

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  162
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  260
/* YYNRULES -- Number of rules. */
#define YYNRULES  696
/* YYNRULES -- Number of states. */
#define YYNSTATES  1070

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
      43,    45,    47,    50,    54,    56,    58,    62,    64,    68,
      72,    73,    79,    81,    85,    87,    88,    93,    97,    99,
     104,   109,   116,   117,   121,   122,   127,   132,   133,   134,
     138,   139,   144,   148,   149,   152,   154,   157,   158,   164,
     165,   171,   172,   178,   179,   180,   181,   194,   197,   198,
     203,   208,   209,   214,   217,   219,   220,   221,   230,   231,
     235,   236,   237,   246,   248,   250,   254,   255,   259,   261,
     265,   267,   270,   272,   275,   277,   279,   281,   284,   285,
     288,   289,   294,   295,   300,   304,   308,   313,   314,   315,
     322,   323,   324,   325,   335,   336,   337,   344,   345,   346,
     347,   357,   358,   359,   366,   367,   368,   369,   379,   383,
     387,   388,   394,   395,   400,   403,   405,   408,   410,   414,
     418,   421,   423,   424,   428,   429,   434,   437,   439,   441,
     442,   447,   452,   456,   458,   460,   462,   465,   466,   468,
     469,   474,   478,   480,   484,   485,   488,   490,   492,   495,
     498,   500,   502,   503,   507,   509,   511,   514,   515,   521,
     522,   528,   529,   535,   536,   542,   544,   546,   548,   549,
     555,   557,   559,   561,   564,   565,   571,   576,   578,   581,
     583,   586,   588,   591,   592,   599,   600,   607,   608,   615,
     618,   619,   622,   625,   626,   631,   632,   638,   641,   642,
     643,   649,   652,   653,   654,   660,   663,   664,   665,   671,
     674,   675,   676,   682,   685,   686,   687,   693,   696,   697,
     698,   704,   707,   708,   710,   713,   715,   716,   721,   722,
     728,   731,   734,   736,   738,   740,   741,   747,   748,   753,
     755,   757,   760,   762,   764,   766,   768,   769,   774,   776,
     778,   780,   782,   784,   786,   788,   790,   792,   794,   796,
     798,   800,   802,   804,   806,   808,   810,   812,   814,   816,
     818,   820,   822,   824,   826,   828,   830,   832,   834,   836,
     838,   840,   842,   844,   846,   848,   850,   852,   854,   856,
     858,   860,   862,   864,   866,   868,   870,   872,   874,   876,
     878,   880,   882,   884,   886,   888,   890,   892,   894,   896,
     898,   900,   902,   904,   906,   908,   910,   912,   914,   916,
     918,   920,   922,   924,   926,   928,   930,   932,   934,   936,
     938,   940,   942,   944,   946,   948,   950,   952,   954,   956,
     958,   960,   962,   964,   966,   968,   970,   972,   974,   976,
     978,   980,   982,   984,   986,   988,   990,   992,   994,   996,
     998,  1000,  1002,  1004,  1006,  1008,  1010,  1012,  1014,  1016,
    1018,  1020,  1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,
    1038,  1040,  1042,  1044,  1046,  1048,  1050,  1052,  1054,  1056,
    1058,  1060,  1062,  1064,  1066,  1068,  1070,  1072,  1074,  1076,
    1078,  1080,  1082,  1084,  1086,  1088,  1089,  1090,  1097,  1098,
    1099,  1106,  1107,  1111,  1112,  1116,  1117,  1122,  1123,  1128,
    1129,  1134,  1135,  1140,  1141,  1145,  1146,  1150,  1155,  1156,
    1160,  1161,  1166,  1167,  1173,  1174,  1180,  1181,  1187,  1188,
    1194,  1199,  1200,  1206,  1207,  1213,  1214,  1220,  1221,  1227,
    1231,  1235,  1236,  1242,  1243,  1249,  1250,  1256,  1257,  1263,
    1264,  1270,  1271,  1277,  1278,  1284,  1285,  1291,  1296,  1302,
    1307,  1308,  1314,  1320,  1326,  1333,  1339,  1345,  1352,  1358,
    1364,  1370,  1376,  1381,  1382,  1383,  1391,  1392,  1393,  1402,
    1407,  1413,  1419,  1425,  1430,  1436,  1439,  1442,  1445,  1448,
    1454,  1459,  1460,  1464,  1466,  1468,  1471,  1474,  1476,  1478,
    1480,  1482,  1484,  1486,  1487,  1489,  1491,  1493,  1495,  1497,
    1499,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,  1517,
    1519,  1521,  1523,  1525,  1527,  1528,  1530,  1531,  1533,  1535,
    1537,  1538,  1543,  1544,  1549,  1550,  1551,  1558,  1560,  1561,
    1565,  1566,  1571,  1572,  1577,  1578,  1582,  1583,  1588,  1590,
    1591,  1595,  1596,  1601,  1603,  1604,  1608,  1609,  1614,  1615,
    1620,  1621,  1625,  1626,  1631,  1633,  1634,  1638,  1639,  1643,
    1644,  1649,  1651,  1652,  1656,  1657,  1662,  1664,  1665,  1669,
    1670,  1675,  1677,  1680,  1681,  1684,  1685,  1688,  1689,  1691,
    1693,  1695,  1697,  1699,  1701,  1703,  1705,  1706,  1711,  1713,
    1715,  1717,  1719,  1721,  1723,  1725,  1726,  1731,  1733,  1735,
    1737,  1739,  1741,  1743,  1744,  1749,  1751,  1753,  1755,  1757,
    1759,  1761,  1763,  1764,  1769,  1771,  1773,  1775,  1777,  1779,
    1781,  1782,  1787,  1789,  1791,  1793,  1795,  1797,  1799,  1800,
    1805,  1807,  1809,  1811,  1813,  1815,  1817,  1818,  1823,  1825,
    1827,  1829,  1831,  1833,  1834,  1839,  1842,  1844,  1846,  1847,
    1852,  1854,  1856,  1858,  1860,  1862,  1864
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     163,     0,    -1,   164,    -1,    -1,   206,    -1,   194,    -1,
     165,    -1,   319,    -1,    -1,   158,   166,     3,    -1,    -1,
      91,   167,     3,    -1,    86,    -1,    -1,    87,   168,     3,
      -1,    -1,    88,   169,     3,    -1,    89,    -1,    -1,    90,
     170,     4,    -1,    92,    -1,    93,    -1,   173,   120,    -1,
     172,   129,   171,    -1,   161,    -1,   173,    -1,   172,   129,
     172,    -1,   174,    -1,   173,   130,   177,    -1,   118,   172,
     119,    -1,    -1,   174,   131,   175,   176,   132,    -1,   301,
      -1,   176,   124,   301,    -1,   301,    -1,    -1,   118,   178,
     179,   119,    -1,   179,   124,   180,    -1,   180,    -1,    97,
     293,   127,   293,    -1,   126,   301,   127,   301,    -1,    99,
     181,   184,   127,   185,   188,    -1,    -1,   301,   182,   279,
      -1,    -1,   118,   183,   275,   119,    -1,   116,   251,   250,
     252,    -1,    -1,    -1,   301,   186,   281,    -1,    -1,   118,
     187,   275,   119,    -1,   122,   189,   123,    -1,    -1,   189,
     190,    -1,   190,    -1,   140,   159,    -1,    -1,   141,   118,
     191,   266,   119,    -1,    -1,   154,   118,   192,   266,   119,
      -1,    -1,   148,   118,   193,     5,   119,    -1,    -1,    -1,
      -1,     8,   195,   301,   111,   172,   196,   127,   172,   197,
     110,   198,    96,    -1,   198,   199,    -1,    -1,    97,   293,
     127,   201,    -1,   101,   241,   116,   214,    -1,    -1,    99,
     200,   279,   202,    -1,   293,   120,    -1,   161,    -1,    -1,
      -1,   116,   203,   251,   250,   252,   127,   204,   215,    -1,
      -1,   127,   205,   215,    -1,    -1,    -1,   216,   207,   301,
     208,   210,   110,   217,    94,    -1,   120,    -1,   161,    -1,
     131,   211,   132,    -1,    -1,   211,   124,   212,    -1,   212,
      -1,   301,   128,   172,    -1,   161,    -1,   252,   120,    -1,
     213,    -1,   289,   209,    -1,   161,    -1,     6,    -1,     7,
      -1,   217,   218,    -1,    -1,    95,   171,    -1,    -1,    97,
     219,   272,   209,    -1,    -1,    98,   220,   273,   209,    -1,
      99,   242,   248,    -1,    55,   245,   248,    -1,   101,   241,
     116,   214,    -1,    -1,    -1,   104,   221,   277,   116,   222,
     215,    -1,    -1,    -1,    -1,   105,   223,   277,   116,   224,
     287,   115,   225,   215,    -1,    -1,    -1,   106,   226,   283,
     117,   227,   215,    -1,    -1,    -1,    -1,   107,   228,   283,
     117,   229,   287,   115,   230,   215,    -1,    -1,    -1,   108,
     231,   285,   113,   232,   215,    -1,    -1,    -1,    -1,   109,
     233,   285,   113,   234,   287,   115,   235,   215,    -1,   152,
     242,   248,    -1,   100,   245,   248,    -1,    -1,   102,   301,
     236,   238,   120,    -1,    -1,   103,   237,   273,   209,    -1,
       1,   120,    -1,   125,    -1,   125,   239,    -1,   240,    -1,
     239,   124,   240,    -1,   302,   116,   301,    -1,   241,   307,
      -1,   307,    -1,    -1,   301,   243,   277,    -1,    -1,   118,
     244,   275,   119,    -1,   245,   246,    -1,   246,    -1,   307,
      -1,    -1,   118,   247,   275,   119,    -1,   116,   251,   250,
     249,    -1,   252,   255,   120,    -1,   213,    -1,   112,    -1,
     114,    -1,   251,   252,    -1,    -1,   293,    -1,    -1,   122,
     253,   254,   123,    -1,   254,   124,   293,    -1,   293,    -1,
     122,   256,   123,    -1,    -1,   256,   258,    -1,   258,    -1,
     135,    -1,   138,   135,    -1,   139,   135,    -1,   133,    -1,
     134,    -1,    -1,   257,   259,   298,    -1,   136,    -1,   137,
      -1,   140,   159,    -1,    -1,   141,   118,   260,   266,   119,
      -1,    -1,   154,   118,   261,   266,   119,    -1,    -1,   143,
     118,   262,   266,   119,    -1,    -1,   144,   118,   263,   266,
     119,    -1,   145,    -1,   147,    -1,   146,    -1,    -1,   146,
     118,   264,   266,   119,    -1,   150,    -1,   151,    -1,   152,
      -1,   142,   159,    -1,    -1,   148,   118,   265,     5,   119,
      -1,   149,   118,   267,   119,    -1,   153,    -1,   266,   159,
      -1,   159,    -1,   267,   268,    -1,   268,    -1,   155,   301,
      -1,    -1,   155,   301,   118,   269,   275,   119,    -1,    -1,
     156,   301,   118,   270,   275,   119,    -1,    -1,   157,   301,
     118,   271,   275,   119,    -1,   272,   293,    -1,    -1,   273,
     293,    -1,   273,   121,    -1,    -1,   293,   274,   272,   121,
      -1,    -1,   275,   118,   276,   275,   119,    -1,   275,   301,
      -1,    -1,    -1,   277,   118,   278,   275,   119,    -1,   277,
     307,    -1,    -1,    -1,   279,   118,   280,   275,   119,    -1,
     279,   308,    -1,    -1,    -1,   281,   118,   282,   275,   119,
      -1,   281,   309,    -1,    -1,    -1,   283,   118,   284,   275,
     119,    -1,   283,   305,    -1,    -1,    -1,   285,   118,   286,
     275,   119,    -1,   285,   304,    -1,    -1,    -1,   287,   118,
     288,   275,   119,    -1,   287,   306,    -1,    -1,   290,    -1,
     289,   311,    -1,   311,    -1,    -1,   118,   291,   275,   119,
      -1,    -1,   289,   118,   292,   275,   119,    -1,   290,   314,
      -1,   289,   303,    -1,   302,    -1,   294,    -1,   310,    -1,
      -1,   294,   131,   295,   296,   132,    -1,    -1,   296,   124,
     297,   294,    -1,   294,    -1,   299,    -1,   298,   299,    -1,
     313,    -1,   315,    -1,   316,    -1,   120,    -1,    -1,   118,
     300,   275,   119,    -1,   313,    -1,   314,    -1,   316,    -1,
     317,    -1,   120,    -1,   312,    -1,   124,    -1,   127,    -1,
     314,    -1,   316,    -1,   317,    -1,   312,    -1,   124,    -1,
     127,    -1,   316,    -1,   317,    -1,   313,    -1,   314,    -1,
     317,    -1,   120,    -1,   121,    -1,   116,    -1,   112,    -1,
     114,    -1,   117,    -1,   115,    -1,   313,    -1,   314,    -1,
     317,    -1,   120,    -1,   121,    -1,   116,    -1,   112,    -1,
     114,    -1,   113,    -1,   115,    -1,   313,    -1,   314,    -1,
     317,    -1,   120,    -1,   121,    -1,   116,    -1,   112,    -1,
     114,    -1,   117,    -1,   113,    -1,   313,    -1,   314,    -1,
     317,    -1,   120,    -1,   121,    -1,   112,    -1,   114,    -1,
     117,    -1,   113,    -1,   115,    -1,   312,    -1,   161,    -1,
     124,    -1,   314,    -1,   317,    -1,   120,    -1,   121,    -1,
     112,    -1,   114,    -1,   117,    -1,   113,    -1,   115,    -1,
     312,    -1,   161,    -1,   127,    -1,   314,    -1,   318,    -1,
     120,    -1,   123,    -1,   316,    -1,   159,    -1,   314,    -1,
     318,    -1,   117,    -1,   125,    -1,   129,    -1,   130,    -1,
     113,    -1,   115,    -1,   110,    -1,   126,    -1,   127,    -1,
     120,    -1,   161,    -1,   159,    -1,   131,    -1,   132,    -1,
     129,    -1,   130,    -1,   125,    -1,   128,    -1,   126,    -1,
     111,    -1,   110,    -1,   312,    -1,   161,    -1,   124,    -1,
     127,    -1,   152,    -1,   315,    -1,    95,    -1,    97,    -1,
      98,    -1,    99,    -1,    55,    -1,   101,    -1,   100,    -1,
     102,    -1,   103,    -1,   104,    -1,   105,    -1,   106,    -1,
     107,    -1,   108,    -1,   109,    -1,    94,    -1,    96,    -1,
     121,    -1,   116,    -1,   112,    -1,   114,    -1,   117,    -1,
     113,    -1,   115,    -1,   122,    -1,   123,    -1,   318,    -1,
     133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,
     138,    -1,   139,    -1,   140,    -1,   141,    -1,   143,    -1,
     144,    -1,   145,    -1,   147,    -1,   148,    -1,   149,    -1,
     146,    -1,   142,    -1,   150,    -1,   151,    -1,   153,    -1,
     154,    -1,   155,    -1,   156,    -1,   157,    -1,    -1,    -1,
      31,   320,   402,   321,   400,   120,    -1,    -1,    -1,    80,
     322,   402,   323,   400,   120,    -1,    -1,     9,   324,   366,
      -1,    -1,    79,   325,   366,    -1,    -1,   363,    11,   326,
     366,    -1,    -1,   363,    12,   327,   372,    -1,    -1,   363,
      19,   328,   372,    -1,    -1,   363,    20,   329,   382,    -1,
      -1,    23,   330,   372,    -1,    -1,   362,   331,   372,    -1,
     363,    22,   364,   120,    -1,    -1,    13,   332,   366,    -1,
      -1,   118,   333,   399,   119,    -1,    -1,    28,   359,   334,
     418,   120,    -1,    -1,    28,   360,   335,   418,   120,    -1,
      -1,    48,   359,   336,   418,   120,    -1,    -1,    35,   361,
     337,   418,   120,    -1,    64,    65,   145,   120,    -1,    -1,
      25,     6,   338,   400,   120,    -1,    -1,    25,    50,   339,
     400,   120,    -1,    -1,    25,    53,   340,   400,   120,    -1,
      -1,    25,     8,   341,   400,   120,    -1,    25,    51,   120,
      -1,    25,    52,   120,    -1,    -1,    25,    54,   342,   400,
     120,    -1,    -1,    25,    55,   343,   400,   120,    -1,    -1,
      25,    56,   344,   400,   120,    -1,    -1,    25,    57,   345,
     400,   120,    -1,    -1,    25,    58,   346,   400,   120,    -1,
      -1,    25,    59,   347,   400,   120,    -1,    -1,    25,    60,
     348,   400,   120,    -1,    -1,    25,    61,   349,   400,   120,
      -1,    25,    49,    85,   120,    -1,    25,    49,   126,    85,
     120,    -1,    25,    23,    36,   120,    -1,    -1,    25,    81,
     350,   400,   120,    -1,    24,    25,    62,   358,   120,    -1,
      24,    25,    44,   358,   120,    -1,    24,    25,    13,    44,
     358,   120,    -1,    24,    25,    45,   358,   120,    -1,    24,
      25,    47,   358,   120,    -1,    24,    25,    13,    45,   358,
     120,    -1,    24,    25,    46,   358,   120,    -1,    24,    25,
      42,   358,   120,    -1,    24,    35,   356,   358,   120,    -1,
      24,    28,   357,   358,   120,    -1,    24,    48,   358,   120,
      -1,    -1,    -1,    24,   365,   351,   421,   352,   358,   120,
      -1,    -1,    -1,    24,     7,    68,   353,   421,   354,   358,
     120,    -1,    24,    63,   358,   120,    -1,    24,    65,   145,
     358,   120,    -1,    24,    65,    59,   358,   120,    -1,    24,
      72,    73,   358,   120,    -1,    24,    81,   358,   120,    -1,
      24,    65,    81,   358,   120,    -1,    75,   120,    -1,    76,
     120,    -1,    77,   120,    -1,    78,   120,    -1,    24,    42,
      25,   358,   120,    -1,    24,    44,   358,   120,    -1,    -1,
       1,   355,   120,    -1,    37,    -1,    38,    -1,    39,    41,
      -1,    39,    40,    -1,    36,    -1,    70,    -1,    82,    -1,
      83,    -1,    84,    -1,   154,    -1,    -1,    33,    -1,    30,
      -1,    34,    -1,    31,    -1,    57,    -1,    58,    -1,    59,
      -1,    12,    -1,    29,    -1,    26,    -1,    27,    -1,    31,
      -1,    32,    -1,    69,    -1,    68,    -1,    70,    -1,    71,
      -1,    16,    -1,    15,    -1,    74,    -1,    -1,    85,    -1,
      -1,    66,    -1,    67,    -1,    68,    -1,    -1,   158,   367,
     401,   369,    -1,    -1,   408,   368,   400,   120,    -1,    -1,
      -1,   116,   370,   402,   371,   400,   120,    -1,   120,    -1,
      -1,   122,   373,   376,    -1,    -1,   158,   374,   401,   369,
      -1,    -1,   410,   375,   400,   120,    -1,    -1,   160,   377,
     379,    -1,    -1,   412,   378,   400,   120,    -1,   120,    -1,
      -1,   123,   380,   366,    -1,    -1,   414,   381,   400,   120,
      -1,   120,    -1,    -1,   122,   383,   386,    -1,    -1,   158,
     384,   401,   369,    -1,    -1,   410,   385,   400,   120,    -1,
      -1,   160,   387,   389,    -1,    -1,   412,   388,   400,   120,
      -1,   120,    -1,    -1,   123,   390,   366,    -1,    -1,   124,
     391,   393,    -1,    -1,   416,   392,   400,   120,    -1,   120,
      -1,    -1,   160,   394,   396,    -1,    -1,   412,   395,   400,
     120,    -1,   120,    -1,    -1,   123,   397,   366,    -1,    -1,
     414,   398,   400,   120,    -1,   120,    -1,   399,   402,    -1,
      -1,   400,   404,    -1,    -1,   401,   406,    -1,    -1,   159,
      -1,   160,    -1,   122,    -1,   123,    -1,   158,    -1,   116,
      -1,   120,    -1,   124,    -1,    -1,   118,   403,   399,   119,
      -1,   159,    -1,   160,    -1,   122,    -1,   123,    -1,   158,
      -1,   116,    -1,   124,    -1,    -1,   118,   405,   399,   119,
      -1,   159,    -1,   160,    -1,   122,    -1,   123,    -1,   158,
      -1,   124,    -1,    -1,   118,   407,   399,   119,    -1,   159,
      -1,   160,    -1,   122,    -1,   123,    -1,   116,    -1,   120,
      -1,   124,    -1,    -1,   118,   409,   399,   119,    -1,   159,
      -1,   160,    -1,   123,    -1,   116,    -1,   120,    -1,   124,
      -1,    -1,   118,   411,   399,   119,    -1,   159,    -1,   122,
      -1,   123,    -1,   158,    -1,   116,    -1,   124,    -1,    -1,
     118,   413,   399,   119,    -1,   159,    -1,   160,    -1,   122,
      -1,   158,    -1,   116,    -1,   124,    -1,    -1,   118,   415,
     399,   119,    -1,   159,    -1,   160,    -1,   122,    -1,   158,
      -1,   116,    -1,    -1,   118,   417,   399,   119,    -1,   418,
     419,    -1,   419,    -1,   421,    -1,    -1,   118,   420,   399,
     119,    -1,   159,    -1,   160,    -1,   122,    -1,   123,    -1,
     158,    -1,   116,    -1,   124,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   215,   215,   217,   222,   223,   224,   225,   231,   231,
     241,   241,   251,   255,   255,   266,   266,   277,   288,   288,
     293,   298,   331,   332,   340,   350,   351,   361,   362,   371,
     372,   372,   379,   385,   386,   393,   392,   403,   404,   407,
     411,   415,   418,   418,   423,   423,   430,   431,   434,   434,
     436,   436,   440,   441,   444,   445,   448,   449,   449,   451,
     451,   453,   453,   460,   462,   470,   460,   483,   484,   487,
     491,   492,   492,   496,   497,   508,   516,   507,   525,   524,
     559,   561,   559,   574,   575,   585,   586,   589,   590,   593,
     601,   613,   614,   617,   618,   628,   628,   631,   632,   635,
     642,   642,   645,   645,   648,   650,   652,   654,   655,   654,
     658,   659,   660,   658,   663,   664,   663,   667,   668,   669,
     667,   672,   673,   672,   676,   677,   678,   676,   681,   686,
     692,   691,   698,   698,   701,   712,   713,   716,   717,   720,
     725,   726,   729,   729,   731,   731,   735,   736,   739,   745,
     745,   749,   756,   757,   760,   761,   764,   765,   768,   774,
     774,   781,   782,   785,   786,   789,   790,   793,   797,   801,
     807,   811,   815,   815,   817,   821,   825,   826,   826,   828,
     828,   830,   830,   832,   832,   834,   838,   842,   847,   847,
     849,   853,   857,   861,   865,   865,   867,   868,   874,   875,
     878,   879,   882,   887,   887,   892,   892,   897,   897,   907,
     908,   911,   912,   913,   913,   920,   920,   922,   923,   926,
     926,   928,   929,   932,   932,   934,   935,   938,   938,   940,
     941,   944,   944,   946,   947,   950,   950,   952,   953,   956,
     956,   958,   959,   962,   963,   964,   967,   967,   969,   969,
     971,   972,   973,   979,   991,   992,   992,   996,   996,   998,
    1004,  1005,  1008,  1008,  1008,  1008,  1009,  1009,  1016,  1016,
    1016,  1016,  1016,  1019,  1019,  1019,  1020,  1020,  1020,  1023,
    1023,  1023,  1024,  1024,  1027,  1027,  1027,  1027,  1028,  1028,
    1028,  1028,  1028,  1028,  1031,  1031,  1031,  1031,  1032,  1032,
    1032,  1032,  1032,  1032,  1035,  1035,  1035,  1035,  1036,  1036,
    1036,  1036,  1036,  1036,  1039,  1039,  1039,  1039,  1040,  1040,
    1040,  1040,  1040,  1040,  1043,  1043,  1043,  1044,  1044,  1044,
    1045,  1045,  1045,  1045,  1045,  1045,  1048,  1048,  1048,  1049,
    1049,  1049,  1049,  1049,  1052,  1052,  1052,  1053,  1053,  1053,
    1053,  1054,  1054,  1054,  1054,  1054,  1057,  1057,  1063,  1063,
    1063,  1063,  1063,  1063,  1063,  1063,  1064,  1064,  1067,  1067,
    1067,  1067,  1070,  1070,  1073,  1073,  1073,  1073,  1073,  1073,
    1074,  1074,  1074,  1075,  1075,  1075,  1075,  1075,  1075,  1075,
    1075,  1078,  1078,  1078,  1078,  1078,  1078,  1078,  1081,  1081,
    1081,  1084,  1084,  1084,  1084,  1084,  1084,  1084,  1085,  1085,
    1085,  1085,  1085,  1085,  1086,  1086,  1086,  1086,  1087,  1087,
    1087,  1087,  1088,  1088,  1088,  1115,  1116,  1115,  1122,  1123,
    1122,  1131,  1130,  1144,  1143,  1157,  1156,  1170,  1169,  1183,
    1182,  1197,  1196,  1211,  1210,  1224,  1223,  1236,  1241,  1240,
    1252,  1252,  1261,  1261,  1267,  1267,  1273,  1273,  1279,  1279,
    1285,  1293,  1293,  1300,  1300,  1307,  1307,  1314,  1314,  1321,
    1325,  1329,  1329,  1336,  1336,  1343,  1343,  1350,  1350,  1357,
    1357,  1364,  1364,  1371,  1371,  1378,  1378,  1385,  1389,  1393,
    1397,  1397,  1407,  1411,  1415,  1419,  1423,  1427,  1431,  1435,
    1439,  1443,  1447,  1451,  1452,  1451,  1457,  1458,  1457,  1463,
    1467,  1471,  1475,  1479,  1483,  1490,  1494,  1498,  1502,  1509,
    1513,  1520,  1520,  1527,  1528,  1529,  1530,  1531,  1532,  1533,
    1534,  1535,  1536,  1539,  1540,  1541,  1542,  1543,  1544,  1545,
    1546,  1547,  1548,  1551,  1552,  1555,  1556,  1559,  1560,  1563,
    1564,  1567,  1568,  1571,  1572,  1575,  1576,  1579,  1580,  1581,
    1589,  1589,  1591,  1591,  1595,  1596,  1595,  1598,  1607,  1607,
    1609,  1609,  1611,  1611,  1616,  1616,  1618,  1618,  1620,  1625,
    1624,  1630,  1630,  1632,  1641,  1641,  1643,  1643,  1645,  1645,
    1650,  1650,  1652,  1652,  1654,  1659,  1658,  1664,  1664,  1666,
    1666,  1668,  1672,  1672,  1674,  1674,  1676,  1681,  1680,  1687,
    1687,  1689,  1695,  1696,  1699,  1700,  1704,  1705,  1711,  1711,
    1711,  1711,  1711,  1711,  1711,  1711,  1712,  1712,  1716,  1716,
    1716,  1716,  1716,  1716,  1716,  1717,  1717,  1722,  1722,  1722,
    1722,  1722,  1722,  1723,  1723,  1727,  1727,  1727,  1727,  1727,
    1727,  1727,  1728,  1728,  1732,  1732,  1732,  1732,  1732,  1732,
    1733,  1733,  1738,  1738,  1738,  1738,  1738,  1738,  1739,  1739,
    1744,  1744,  1744,  1744,  1744,  1744,  1745,  1745,  1750,  1750,
    1750,  1750,  1750,  1751,  1751,  1758,  1759,  1762,  1768,  1768,
    1776,  1776,  1776,  1776,  1776,  1776,  1776
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
  "KW_FREWRITE", "KW_OREWRITE", "KW_CONTINUE", "KW_SEARCH", "KW_SET", 
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
  "moduleExpr2", "moduleExpr3", "@6", "argList", "renaming", "@7", 
  "mappingList", "mapping", "fromOpName", "@8", "@9", "fromSpec", 
  "toOpName", "@10", "@11", "toAttributes", "toAttributeList", 
  "toAttribute", "@12", "@13", "@14", "view", "@15", "@16", "@17", 
  "viewDecList", "viewDeclaration", "@18", "sortDot", "viewEndOpMap", 
  "@19", "@20", "@21", "module", "@22", "@23", "dot", "parameters", 
  "parameterList", "parameter", "badType", "typeDot", "endStatement", 
  "startModule", "decList", "declaration", "@24", "@25", "@26", "@27", 
  "@28", "@29", "@30", "@31", "@32", "@33", "@34", "@35", "@36", "@37", 
  "@38", "@39", "@40", "@41", "@42", "classDef", "cPairList", "cPair", 
  "varNameList", "opName", "@43", "@44", "opNameList", "simpleOpName", 
  "@45", "domainRangeAttr", "typeAttr", "arrow", "typeList", "typeName", 
  "@46", "sortNames", "attributes", "attributeList", "idKeyword", 
  "attribute", "@47", "@48", "@49", "@50", "@51", "@52", "@53", "idList", 
  "hookList", "hook", "@54", "@55", "@56", "sortNameList", "subsortList", 
  "@57", "tokens", "@58", "tokensBarColon", "@59", "tokensBarColonTo", 
  "@60", "tokensBarCommaLeft", "@61", "tokensBarEqual", "@62", 
  "tokensBarArrow2", "@63", "tokensBarIf", "@64", "endTokens", 
  "noTrailingDot", "@65", "@66", "sortName", "sortNameFrag", "@67", 
  "sortNameFrags", "@68", "identity", "identityChunk", "@69", "token", 
  "tokenBarDot", "endToken", "tokenBarArrow2", "tokenBarEqual", 
  "tokenBarIf", "tokenBarColon", "tokenBarColonTo", "tokenBarCommaLeft", 
  "sortToken", "endsInDot", "inert", "identifier", "startKeyword", 
  "startKeyword2", "midKeyword", "attrKeyword", "attrKeyword2", "command", 
  "@70", "@71", "@72", "@73", "@74", "@75", "@76", "@77", "@78", "@79", 
  "@80", "@81", "@82", "@83", "@84", "@85", "@86", "@87", "@88", "@89", 
  "@90", "@91", "@92", "@93", "@94", "@95", "@96", "@97", "@98", "@99", 
  "@100", "@101", "@102", "@103", "@104", "@105", "printOption", 
  "traceOption", "polarity", "select", "exclude", "conceal", "match", 
  "optDebug", "optNumber", "importMode", "moduleAndTerm", "@106", "@107", 
  "inEnd", "@108", "@109", "numberModuleTerm", "@110", "@111", "@112", 
  "numberModuleTerm1", "@113", "@114", "numberModuleTerm2", "@115", 
  "@116", "numbersModuleTerm", "@117", "@118", "@119", 
  "numbersModuleTerm1", "@120", "@121", "numbersModuleTerm2", "@122", 
  "@123", "@124", "numbersModuleTerm3", "@125", "@126", 
  "numbersModuleTerm4", "@127", "@128", "cTokens", "cTokensBarDot", 
  "cTokensBarDotColon", "cToken", "@129", "cTokenBarDot", "@130", 
  "cTokenBarDotColon", "@131", "cTokenBarIn", "@132", "cTokenBarLeftIn", 
  "@133", "cTokenBarDotNumber", "@134", "cTokenBarDotRight", "@135", 
  "cTokenBarDotCommaRight", "@136", "cOpNameList", "cSimpleOpName", 
  "@137", "cSimpleTokenBarDot", 0
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
     165,   165,   171,   171,   171,   172,   172,   173,   173,   174,
     175,   174,   174,   176,   176,   178,   177,   179,   179,   180,
     180,   180,   182,   181,   183,   181,   184,   184,   186,   185,
     187,   185,   188,   188,   189,   189,   190,   191,   190,   192,
     190,   193,   190,   195,   196,   197,   194,   198,   198,   199,
     199,   200,   199,   201,   201,   203,   204,   202,   205,   202,
     207,   208,   206,   209,   209,   210,   210,   211,   211,   212,
     213,   214,   214,   215,   215,   216,   216,   217,   217,   218,
     219,   218,   220,   218,   218,   218,   218,   221,   222,   218,
     223,   224,   225,   218,   226,   227,   218,   228,   229,   230,
     218,   231,   232,   218,   233,   234,   235,   218,   218,   218,
     236,   218,   237,   218,   218,   238,   238,   239,   239,   240,
     241,   241,   243,   242,   244,   242,   245,   245,   246,   247,
     246,   248,   249,   249,   250,   250,   251,   251,   252,   253,
     252,   254,   254,   255,   255,   256,   256,   257,   257,   257,
     258,   258,   259,   258,   258,   258,   258,   260,   258,   261,
     258,   262,   258,   263,   258,   258,   258,   258,   264,   258,
     258,   258,   258,   258,   265,   258,   258,   258,   266,   266,
     267,   267,   268,   269,   268,   270,   268,   271,   268,   272,
     272,   273,   273,   274,   273,   276,   275,   275,   275,   278,
     277,   277,   277,   280,   279,   279,   279,   282,   281,   281,
     281,   284,   283,   283,   283,   286,   285,   285,   285,   288,
     287,   287,   287,   289,   289,   289,   291,   290,   292,   290,
     290,   290,   290,   293,   294,   295,   294,   297,   296,   296,
     298,   298,   299,   299,   299,   299,   300,   299,   301,   301,
     301,   301,   301,   302,   302,   302,   302,   302,   302,   303,
     303,   303,   303,   303,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   309,   309,   309,   309,
     309,   309,   309,   309,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   311,   311,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   313,   313,
     313,   313,   314,   314,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   316,   316,   316,   316,   316,   316,   316,   317,   317,
     317,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   320,   321,   319,   322,   323,
     319,   324,   319,   325,   319,   326,   319,   327,   319,   328,
     319,   329,   319,   330,   319,   331,   319,   319,   332,   319,
     333,   319,   334,   319,   335,   319,   336,   319,   337,   319,
     319,   338,   319,   339,   319,   340,   319,   341,   319,   319,
     319,   342,   319,   343,   319,   344,   319,   345,   319,   346,
     319,   347,   319,   348,   319,   349,   319,   319,   319,   319,
     350,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   351,   352,   319,   353,   354,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   355,   319,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   358,   358,   359,   359,   360,   360,   361,
     361,   362,   362,   363,   363,   364,   364,   365,   365,   365,
     367,   366,   368,   366,   370,   371,   369,   369,   373,   372,
     374,   372,   375,   372,   377,   376,   378,   376,   376,   380,
     379,   381,   379,   379,   383,   382,   384,   382,   385,   382,
     387,   386,   388,   386,   386,   390,   389,   391,   389,   392,
     389,   389,   394,   393,   395,   393,   393,   397,   396,   398,
     396,   396,   399,   399,   400,   400,   401,   401,   402,   402,
     402,   402,   402,   402,   402,   402,   403,   402,   404,   404,
     404,   404,   404,   404,   404,   405,   404,   406,   406,   406,
     406,   406,   406,   407,   406,   408,   408,   408,   408,   408,
     408,   408,   409,   408,   410,   410,   410,   410,   410,   410,
     411,   410,   412,   412,   412,   412,   412,   412,   413,   412,
     414,   414,   414,   414,   414,   414,   415,   414,   416,   416,
     416,   416,   416,   417,   416,   418,   418,   419,   420,   419,
     421,   421,   421,   421,   421,   421,   421
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     0,     3,
       0,     3,     1,     0,     3,     0,     3,     1,     0,     3,
       1,     1,     2,     3,     1,     1,     3,     1,     3,     3,
       0,     5,     1,     3,     1,     0,     4,     3,     1,     4,
       4,     6,     0,     3,     0,     4,     4,     0,     0,     3,
       0,     4,     3,     0,     2,     1,     2,     0,     5,     0,
       5,     0,     5,     0,     0,     0,    12,     2,     0,     4,
       4,     0,     4,     2,     1,     0,     0,     8,     0,     3,
       0,     0,     8,     1,     1,     3,     0,     3,     1,     3,
       1,     2,     1,     2,     1,     1,     1,     2,     0,     2,
       0,     4,     0,     4,     3,     3,     4,     0,     0,     6,
       0,     0,     0,     9,     0,     0,     6,     0,     0,     0,
       9,     0,     0,     6,     0,     0,     0,     9,     3,     3,
       0,     5,     0,     4,     2,     1,     2,     1,     3,     3,
       2,     1,     0,     3,     0,     4,     2,     1,     1,     0,
       4,     4,     3,     1,     1,     1,     2,     0,     1,     0,
       4,     3,     1,     3,     0,     2,     1,     1,     2,     2,
       1,     1,     0,     3,     1,     1,     2,     0,     5,     0,
       5,     0,     5,     0,     5,     1,     1,     1,     0,     5,
       1,     1,     1,     2,     0,     5,     4,     1,     2,     1,
       2,     1,     2,     0,     6,     0,     6,     0,     6,     2,
       0,     2,     2,     0,     4,     0,     5,     2,     0,     0,
       5,     2,     0,     0,     5,     2,     0,     0,     5,     2,
       0,     0,     5,     2,     0,     0,     5,     2,     0,     0,
       5,     2,     0,     1,     2,     1,     0,     4,     0,     5,
       2,     2,     1,     1,     1,     0,     5,     0,     4,     1,
       1,     2,     1,     1,     1,     1,     0,     4,     1,     1,
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
       1,     1,     1,     1,     1,     0,     0,     6,     0,     0,
       6,     0,     3,     0,     3,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     3,     0,     3,     4,     0,     3,
       0,     4,     0,     5,     0,     5,     0,     5,     0,     5,
       4,     0,     5,     0,     5,     0,     5,     0,     5,     3,
       3,     0,     5,     0,     5,     0,     5,     0,     5,     0,
       5,     0,     5,     0,     5,     0,     5,     4,     5,     4,
       0,     5,     5,     5,     6,     5,     5,     6,     5,     5,
       5,     5,     4,     0,     0,     7,     0,     0,     8,     4,
       5,     5,     5,     4,     5,     2,     2,     2,     2,     5,
       4,     0,     3,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     0,     1,     1,     1,
       0,     4,     0,     4,     0,     0,     6,     1,     0,     3,
       0,     4,     0,     4,     0,     3,     0,     4,     1,     0,
       3,     0,     4,     1,     0,     3,     0,     4,     0,     4,
       0,     3,     0,     4,     1,     0,     3,     0,     3,     0,
       4,     1,     0,     3,     0,     4,     1,     0,     3,     0,
       4,     1,     2,     0,     2,     0,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     0,     4,     1,     1,
       1,     1,     1,     0,     4,     2,     1,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,   521,    95,    96,    63,   431,   448,   552,   551,   443,
       0,     0,     0,   425,     0,     0,     0,   553,     0,     0,
       0,     0,   433,   428,    12,    13,    15,    17,    18,    10,
      20,    21,   450,     8,     0,     2,     6,     5,     4,    80,
       7,   445,     0,     0,     0,     0,     0,     0,     0,     0,
     533,     0,     0,     0,     0,     0,     0,   557,   558,   559,
       0,     0,   503,   461,   467,     0,     0,   463,     0,     0,
     465,   471,   473,   475,   477,   479,   481,   483,   485,   490,
     545,   546,   548,   547,   452,   454,     0,   549,   550,   458,
     456,     0,   515,   516,   517,   518,     0,     0,     0,     0,
       0,     0,   613,     0,     1,     0,     0,   435,   437,   439,
     441,   556,   522,   378,   389,   374,   390,   375,   376,   377,
     380,   379,   381,   382,   383,   384,   385,   386,   387,   388,
     367,   366,   393,   396,   394,   397,   392,   395,   272,   391,
     398,   399,   370,   363,   365,   371,   364,   361,   362,   359,
     360,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     417,   410,   411,   412,   416,   413,   414,   415,   418,   419,
     372,   420,   421,   422,   423,   424,   358,   369,     0,   368,
     268,   269,   373,   270,   271,   400,   649,   652,   650,   647,
     648,   651,   560,   645,   646,   432,   562,   449,   657,   660,
     658,   568,   656,   659,   570,   654,   655,   444,   572,   506,
       0,     0,     0,     0,     0,     0,     0,   541,   542,   535,
     537,   534,   536,   538,   539,   540,     0,   527,   523,   524,
       0,   528,   529,   530,   531,   532,     0,     0,   543,   544,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   615,
     615,     0,     0,     0,   615,   469,   470,   615,   615,   615,
     615,   615,   615,   615,   615,   615,   615,     0,     0,   623,
     626,   624,   620,   621,   625,   622,   618,   619,   426,     0,
       0,     0,   434,   429,    14,    16,    19,    11,     0,     9,
      81,   446,     0,     0,     0,     0,   555,     0,     0,   613,
     617,   615,   613,     0,   617,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,   525,     0,     0,
     520,   502,   509,     0,     0,     0,     0,   513,   695,   692,
     693,   696,   694,   690,   691,   504,     0,     0,   489,   487,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   688,     0,   686,   687,     0,   613,   615,     0,
       0,   460,   615,   451,   612,    86,   436,   438,   440,   584,
     586,   442,   588,   447,     0,    64,    25,    27,    32,     0,
       0,     0,     0,   666,   668,   578,   663,   664,   667,   665,
     662,   574,   569,   576,     0,     0,   507,     0,     0,   499,
     493,   495,   498,   496,   492,   501,   500,   519,   511,   514,
     510,   512,     0,   633,   635,   462,   630,   631,   634,   632,
     628,   629,   614,   468,   488,   464,   466,   472,   474,   476,
     478,   480,   482,   484,   486,   491,   613,   453,   685,   455,
       0,     0,   459,   457,     0,     0,     0,     0,   617,   615,
       0,     0,     0,     0,    30,   653,   564,   643,   567,   639,
     640,   642,   641,   637,   638,   561,   616,   563,   661,   613,
       0,   615,   571,   573,     0,   494,   497,     0,   613,     0,
     627,   427,   430,     0,    88,     0,    98,   594,   590,   585,
     592,     0,     0,    29,    26,     0,    35,    28,     0,     0,
     613,     0,   674,   676,   583,   672,   579,   675,   673,   670,
     671,   575,   581,     0,     0,   505,     0,   689,     0,    85,
       0,     0,     0,   615,   587,   589,    65,     0,     0,    34,
     565,     0,   669,   613,     0,   615,   577,   508,   636,    87,
      89,     0,     0,    82,     0,   100,   102,     0,     0,     0,
       0,   132,   107,   110,   114,   117,   121,   124,     0,    97,
     682,   683,   601,   680,   595,   597,   681,   678,   679,   591,
     599,     0,     0,     0,     0,     0,     0,    38,     0,    31,
     615,   644,     0,   580,     0,   134,   319,   322,   320,   323,
     321,   149,   317,   318,     0,   147,   148,   314,   315,   316,
      24,    99,     0,    25,   210,     0,   144,     0,   142,     0,
       0,   141,   130,     0,   222,   222,   234,   234,   238,   238,
       0,   613,     0,     0,   615,   593,    68,   353,   351,   352,
     347,   348,   354,   355,   349,   350,   344,     0,   253,   254,
     345,   346,    44,    47,    42,     0,    36,     0,    33,     0,
     677,   582,   218,   157,   146,   105,     0,    22,     0,     0,
     213,   218,   104,   222,   129,     0,   140,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,   596,   606,   602,
     598,   604,     0,     0,     0,   255,   218,   157,     0,   226,
       0,    37,   566,     0,     0,    23,    26,    83,    84,   101,
     209,   212,   103,   211,   210,     0,   143,   159,    90,    92,
     106,     0,   158,   135,     0,   133,   108,   219,   221,   111,
     300,   302,   301,   303,   299,   115,   231,   297,   298,   233,
     294,   295,   296,   118,   290,   122,   291,   293,   289,   292,
     235,   287,   288,   237,   284,   285,   286,   125,   684,     0,
     615,   600,    66,     0,    71,     0,    67,    39,     0,     0,
       0,     0,    43,    40,   215,   150,   217,   154,   155,     0,
     156,     0,   145,     0,    91,   274,   275,   136,   137,     0,
     273,   276,   277,   278,   131,     0,   218,   242,     0,   218,
     242,     0,   218,   242,   611,   607,   603,   609,     0,     0,
     226,     0,   259,     0,    45,     0,    50,    53,    48,   331,
     334,   332,   335,   333,   223,   329,   330,   326,   325,   225,
     324,   327,   328,   218,   153,   151,   164,   214,     0,   162,
       0,     0,   246,   356,   357,   109,     0,   243,   252,   245,
       0,     0,   116,     0,     0,   123,     0,     0,     0,   615,
     605,     0,     0,     0,   257,   256,    46,   218,     0,    41,
     230,   218,     0,     0,     0,   160,     0,   138,   139,   218,
     248,   356,   280,   281,   357,    93,   251,   244,   279,   282,
     283,   250,   220,   310,   313,   311,   112,   309,   312,   239,
     307,   308,   241,   304,   305,   306,   232,   119,   236,   126,
     608,     0,    74,    69,     0,    75,    78,    72,    70,     0,
       0,     0,     0,     0,     0,     0,    55,    49,     0,   216,
     170,   171,   167,   174,   175,     0,     0,     0,     0,     0,
       0,     0,   185,   187,   186,     0,     0,   190,   191,   192,
     197,     0,     0,   172,   166,   152,   161,     0,   218,     0,
     218,     0,     0,   610,    73,   157,     0,   258,    51,    56,
      57,    61,    59,    52,    54,   227,   341,   342,   338,   337,
     229,   336,   339,   343,   340,   224,   168,   169,   176,   177,
     193,   181,   183,   188,   194,     0,   179,   163,   165,     0,
     247,     0,   113,     0,   120,   127,     0,    79,     0,     0,
       0,   218,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,     0,   266,   265,   173,   260,   262,   263,   264,
     249,   240,     0,   199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,   196,   200,     0,   218,
     261,     0,    58,   198,    62,    60,   228,   178,   182,   184,
     189,   195,   203,   205,   207,   180,     0,    76,   218,   218,
     218,   267,     0,     0,     0,     0,    77,   204,   206,   208
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    34,    35,    36,   103,   101,    98,    99,   100,   601,
     375,   376,   377,   498,   528,   497,   527,   576,   577,   643,
     689,   686,   688,   807,   860,   857,   859,   915,   916,   998,
    1000,   999,    37,    44,   452,   572,   683,   756,   800,   903,
     907,   955,  1062,   956,    38,   105,   365,   699,   446,   483,
     484,   709,   710,   835,    39,   521,   559,   604,   605,   614,
     785,   615,   787,   949,   616,   788,   617,   790,   951,   618,
     791,   619,   793,   952,   667,   613,   714,   777,   778,   610,
     607,   663,   661,   594,   595,   652,   655,   825,   769,   694,
     770,   773,   828,   864,   942,   943,   944,   989,  1002,  1012,
    1003,  1004,  1005,  1006,  1024,  1010,  1011,  1058,  1059,  1060,
     658,   659,   704,   693,   823,   669,   786,   762,   861,   917,
    1001,   671,   789,   673,   792,   841,   950,   836,   837,   869,
     948,   712,   638,   758,   803,   909,  1015,  1016,  1039,   766,
     838,   876,   743,   729,   892,   596,   819,   970,   639,   839,
     179,   180,   181,   182,   183,   184,   185,    40,    86,   358,
      97,   362,    45,    96,   292,   293,   294,   295,    47,   106,
      46,   102,   267,   268,   280,   279,   249,   254,   257,   250,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   248,
     412,   306,   474,    43,   236,   226,   240,    84,    85,    89,
      41,    42,   297,    62,   195,   300,   301,   465,   499,   580,
     207,   303,   304,   305,   392,   470,   471,   511,   534,   535,
     371,   447,   448,   449,   489,   522,   523,   569,   622,   623,
     624,   680,   749,   750,   796,   848,   849,   288,   336,   380,
     364,   357,   422,   478,   466,   500,   196,   299,   208,   302,
     393,   469,   512,   533,   570,   621,   353,   354,   436,   355
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -949
static const short yypact[] =
{
     690,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    5944,   856,    91,  -949,   117,   165,   -27,  -949,   -41,   -35,
     -28,   -11,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,    54,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,   471,     0,  4374,   -58,   -58,  5860,    84,    31,
     429,    59,   133,   181,   181,   181,   -29,  -949,  -949,  -949,
     105,   181,  -949,  -949,  -949,   166,   -52,  -949,   111,   128,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  5969,  -949,  -949,  -949,
    -949,    92,  -949,  -949,  -949,  -949,   -58,  5969,   248,   254,
     262,   264,  -949,   265,  -949,  4374,  5860,  -949,  -949,  -949,
    -949,   180,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,   169,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
     201,   181,   181,   181,   181,   181,   181,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,   181,  -949,  -949,  -949,
     215,  -949,  -949,  -949,  -949,  -949,   181,   181,  -949,  -949,
     157,   164,   173,   181,   181,   181,   181,   182,    16,  -949,
    -949,   185,   187,   223,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,   261,   261,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,   261,
     261,   191,  -949,  -949,  -949,  -949,  -949,  -949,   428,  -949,
    -949,  -949,   -58,  5860,  5860,  5978,  -949,   194,  2623,  -949,
    -949,  -949,  -949,  5987,  -949,  -949,    16,   181,   181,   195,
     196,   199,   203,   205,   208,   211,  -949,  -949,   217,   220,
    -949,  -949,  -949,   222,   227,   232,   235,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  6032,  6041,  -949,  -949,
     236,  6050,  6059,  6104,  6113,  6122,  6131,  6176,  6185,  6194,
    6203,  6248,  -949,  6257,  -949,  -949,  6266,  -949,  -949,  6275,
    6320,  -949,  -949,  -949,  -949,   155,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  2623,   171,   190,   226,  -949,   445,
    6329,  6338,   564,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  6329,  6347,  -949,   239,   244,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,   181,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
     626,  6392,  -949,  -949,  6401,  4374,   259,  6410,  -949,  -949,
     -82,  2623,   243,   253,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    6419,  -949,  -949,  -949,   181,  -949,  -949,   255,  -949,   762,
    -949,  -949,  -949,   -90,  -949,   252,  -949,  -949,  -949,  -949,
    -949,  6329,  6464,  -949,  -949,  2623,  -949,  -949,  4374,  5969,
    -949,   772,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  6473,   266,  -949,  5433,  -949,  4374,  -949,
    2623,   752,  6482,  -949,  -949,  -949,   171,    36,   -76,  -949,
    -949,  5536,  -949,  -949,   -58,  -949,  -949,  -949,  -949,  -949,
     171,   268,  4477,  -949,  2726,  -949,  -949,  2829,  4477,  4889,
    4374,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  2829,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  6491,   272,  5775,  2932,  4374,   -69,  -949,  4374,  -949,
    -949,  -949,  5836,  -949,  6536,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  3035,  -949,  -949,  -949,  -949,  -949,
      99,  -949,   273,     7,  -949,  5775,  -949,   275,  -949,  3035,
    4580,  -949,  -949,  5775,  -949,  -949,  -949,  -949,  -949,  -949,
     275,  -949,   -58,  6545,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,   267,   277,  -949,
    -949,  -949,  -949,   288,  -949,   282,  -949,    36,  -949,  6554,
    -949,  -949,  -949,  -949,  -949,  -949,  2726,  -949,  5201,  5133,
    -949,  -949,  -949,  -949,  -949,  5269,  -949,   285,  5133,  3138,
    3241,  3344,  3447,  3550,  3653,  -949,  5960,  -949,  -949,  -949,
    -949,  -949,  6563,   200,  5775,  -949,  -949,  -949,   284,  -949,
    4374,  -949,  -949,   872,  5576,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,   975,  4683,  -949,  -949,  -949,
    -949,   293,  -949,  5473,   295,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  6608,
    -949,  -949,  -949,  5775,  -949,  4889,  -949,  -949,  5775,  1078,
    5576,  3756,  4992,  -949,  -949,  -949,  -949,  -949,  -949,  5269,
    -949,  5642,  -949,  5775,  -949,  -949,  -949,   298,  -949,   301,
    -949,  -949,  -949,  -949,  -949,  3859,  -949,  -949,  3859,  -949,
    -949,  3859,  -949,  -949,  -949,  -949,  -949,  -949,  6617,   296,
    -949,  4786,   277,    41,  -949,  5709,  -949,   303,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,   310,  -949,   138,  -949,
    5473,  4374,  -949,  -949,   556,  -949,  5916,  5841,  -949,  -949,
    1181,  3962,  -949,  1284,  4065,  -949,  1387,  4168,   -58,  -949,
    -949,  5337,  4271,  5269,  -949,  -949,  -949,  -949,    58,  -949,
    -949,  -949,  1490,   901,   317,  -949,  5775,  -949,  -949,  -949,
    -949,   719,  -949,  -949,   735,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  6626,  -949,  -949,   322,  -949,  -949,  -949,  -949,  5775,
    1593,   302,   326,   329,   334,   213,  -949,  5064,  1696,  -949,
    -949,  -949,  -949,  -949,  -949,   330,   332,   305,   339,   309,
     351,   353,  -949,   357,  -949,   361,   362,  -949,  -949,  -949,
    -949,   367,   805,  -949,  -949,  -949,  -949,  1799,  -949,  3859,
    -949,  3859,  3859,  -949,  -949,  -949,  3859,   277,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,    69,  -949,  -949,  -949,  5405,
    -949,  1902,  -949,  2005,  -949,  -949,  5576,  -949,   335,   492,
     335,  -949,   335,   335,   335,   335,   494,  4374,  4374,  4374,
      65,  -949,   335,  -949,  -949,  5405,  -949,  -949,  -949,  -949,
    -949,  -949,  5709,  -949,   -79,   385,   -70,  2108,   -60,   -51,
     -47,   -14,   386,   389,   390,   391,  -949,  -949,    -2,  -949,
    -949,   383,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  2211,  -949,  -949,  -949,
    -949,  -949,  3859,  2314,  2417,  2520,  -949,  -949,  -949,  -949
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -144,
    -367,  -520,  -949,  -949,  -949,  -949,  -949,  -949,  -134,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -400,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -632,  -949,  -949,
       1,  -253,  -335,  -606,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -310,  -230,
     -32,  -949,  -949,   -20,  -491,  -949,  -496,  -949,  -752,  -664,
    -644,  -949,  -949,  -949,  -949,  -949,  -410,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -576,  -949,  -474,  -949,  -949,  -949,
    -167,   -75,  -949,  -426,  -949,  -580,  -949,  -261,  -949,  -949,
    -949,   -68,  -949,   -61,  -949,  -557,  -949,  -949,  -949,  -949,
    -949,   -78,  -755,  -949,  -949,  -949,  -949,  -475,  -949,   -44,
    -709,  -949,  -949,  -949,  -949,  -506,  -949,  -949,  -949,  -295,
    -307,  -523,  -479,  -948,  -396,  -503,  -355,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,    27,   527,  -949,  -949,
    -949,  -949,  -949,  -949,   -45,  -949,  -949,  -372,  -949,  -949,
     -77,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,   -88,  -248,  -276,
     -66,  -949,  -949,  -949,  -949,  -949,  -949,  -949,   271,  -949,
    -442,  -949,  -179,  -949,  -949,  -949,  -124,    40,  -949,  -216
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -555
static const short yytable[] =
{
     178,   197,   337,   802,   779,   490,   341,   450,   805,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   597,
     278,   711,   472,   760,   603,   597,   597,   702,   394,   291,
     243,   283,   335,   252,   518,   670,   715,   493,    91,   599,
    1042,  1018,   519,   611,   210,   599,   599,   451,   578,  1045,
     646,   282,   244,   381,   104,   647,   579,   395,   186,  1047,
     187,   290,   188,   598,   189,   190,   191,  1018,  1048,   598,
     598,   597,  1049,   211,   253,   212,   213,   214,   215,    92,
    1043,   241,   242,   706,   494,    93,   597,   597,   247,  1043,
     396,   599,    94,   216,   640,   227,   228,   229,   230,  1043,
     192,   193,   194,   654,   666,  1050,   599,   599,  1043,    95,
     441,   662,  1043,   664,   444,   598,   245,  1055,   654,   524,
     112,   779,    80,    81,   675,   826,   640,   657,   526,   231,
     598,   598,   328,   573,   640,   574,   603,   453,   329,   330,
     331,   232,   233,   234,   356,  1043,   597,   597,   730,   730,
     744,   744,   209,   540,   957,   359,   360,  1043,   237,    82,
      83,   856,   575,   718,   718,   854,   599,   599,   732,   732,
     746,   746,   491,   855,   332,   333,   334,   602,   246,   640,
     640,   681,   842,   597,  1036,   845,   640,    87,    88,   640,
     598,   598,   731,   731,   745,   745,    80,    81,   911,   912,
     718,   492,   251,   599,   875,   640,   913,   238,   239,   711,
     783,   379,   914,   235,   382,   640,   367,   368,   641,  -369,
    1007,  1008,  1009,   513,  1007,  1008,  1009,   598,  -369,  -369,
    -369,   255,   597,   844,   781,   705,   847,   281,   309,   310,
     311,   312,   313,   314,  1022,   307,   308,   366,   256,   611,
     641,   284,   599,   315,   378,   316,   317,   285,   641,   822,
     759,   865,   866,   318,   319,   296,   286,   287,   289,   440,
     323,   324,   325,   326,   640,   571,   598,   320,   597,   640,
     298,   640,   783,   821,   321,   783,   445,   584,   783,   696,
     640,   996,   640,   322,   640,   666,   752,   753,   599,   754,
     451,   755,   327,   641,   641,   338,   781,   339,   340,   781,
     641,   361,   781,   641,   373,   399,   400,   782,   893,   401,
     453,   893,   598,   402,   893,   403,   640,   783,   404,   641,
     378,   405,   649,   880,   397,   398,   963,   406,   895,   641,
     407,   895,   408,   992,   895,   994,   995,   409,   479,   822,
     997,   781,   410,   911,   912,   411,   424,   454,   881,   475,
     840,   913,   894,   843,   476,   894,   846,   914,   894,   486,
     495,   496,   640,   821,   640,   515,   682,   328,  1041,   352,
     520,   501,   626,   329,   330,   331,   537,   640,   585,   782,
     516,   653,   782,   438,   684,   782,   438,   862,   641,   438,
     438,   485,   656,   641,   687,   641,   780,   378,   685,   690,
     713,   761,   531,   774,   641,   784,   641,   831,   641,   332,
     333,   334,   830,   851,  1026,   858,  1028,  1029,  1030,  1031,
     640,   910,   863,   530,   782,   918,  1038,   945,   972,   477,
     879,   217,   954,   947,   960,   582,   783,   961,   783,   783,
     641,   378,   962,   783,   529,   820,  1066,   979,   218,   219,
     220,   959,   221,   222,   978,   976,  1017,   977,   980,   981,
     781,   982,   781,   781,   485,   983,   378,   781,   780,   984,
     985,   780,   107,   108,   780,   986,   223,   224,   225,   583,
     109,   110,  1017,   111,  1023,   637,   641,  1025,   641,  1032,
     378,   514,   798,   608,  1044,  1051,   612,  1052,  1053,  1054,
    1057,   641,   695,   691,   608,   964,   824,   640,   908,   539,
     867,   973,   991,   780,   993,   801,   620,   660,   609,   878,
     644,   645,   988,   676,   648,   660,  1037,   771,   668,   852,
    1040,   877,    90,   640,   269,   820,   270,   363,   271,   672,
     272,   273,   274,   782,   641,   782,   782,   -94,   674,   783,
     782,   269,   974,   270,   455,   271,   372,   272,   273,   274,
     797,     0,     0,     0,     0,  1027,     0,   677,     0,     0,
     700,   703,     0,   781,     0,     0,   275,   276,   277,     0,
     703,     0,     0,  1019,     0,     0,     0,     0,     0,     0,
       0,   901,     0,   275,   276,   277,   757,     0,     0,     0,
     971,   -94,   378,  1056,     0,     0,     0,     0,     0,  1019,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1063,  1064,  1065,     0,     0,     0,     0,     0,
       0,   641,   780,     0,   780,   780,   763,     0,     0,   780,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   782,   641,     0,     0,
       0,     0,     0,     0,     0,   799,     0,     0,     0,     0,
     269,     0,   270,   468,   271,     0,   272,   273,   274,     0,
      -3,     1,     0,   700,     0,   829,     2,     3,     4,     5,
       0,  -554,  -554,     6,     0,     7,     8,     0,   -94,  -554,
    -554,     0,  -554,     9,    10,    11,     0,   808,    12,     0,
     -83,    13,   275,   276,   277,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -84,     0,    15,     0,
       0,     0,   269,     0,   270,   480,   271,     0,   272,   273,
     274,     0,     0,   541,    16,   780,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,     0,     0,   904,   -83,     0,    24,    25,    26,    27,
      28,    29,    30,    31,   275,   276,   277,   868,   946,     0,
     -84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   900,     0,     0,     0,   542,    32,     0,
       0,     0,     0,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,     0,   543,   544,    33,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,    63,     0,    64,     0,     0,     0,     0,     0,
       0,   -83,     0,     0,     0,     0,     0,     0,   269,    65,
     270,   517,   271,     0,   272,   273,   274,   -84,   269,     0,
     270,   532,   271,     0,   272,   273,   274,     0,     0,     0,
       0,     0,     0,     0,   558,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     0,     0,
     275,   276,   277,     0,     0,     0,     0,   113,   987,     0,
     275,   276,   277,     0,     0,     0,     0,    79,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,   930,   931,
     932,   933,   934,   935,   936,   937,   938,   939,   940,   941,
       0,     0,     0,  1033,  1034,  1035,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     764,   765,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     113,   176,     0,   177,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   929,   930,   931,   932,   933,   934,   935,
     936,   937,   938,   939,   940,   941,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   764,   772,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   113,   176,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   764,   804,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   113,   176,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   764,
     882,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   113,
     176,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   764,   896,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   113,   176,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   764,   898,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   113,   176,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   764,   919,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   113,   176,
       0,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   764,   958,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   113,   176,     0,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   764,   975,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   113,   176,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   764,   990,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   113,   176,     0,
     177,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     764,  1020,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     113,   176,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   764,  1021,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   113,   176,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   764,  1046,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   113,   176,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   764,
    1061,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   113,
     176,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   764,  1067,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   113,   176,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   764,  1068,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   113,   176,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   764,  1069,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   113,   176,
       0,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   374,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   113,   176,     0,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   374,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   113,   176,     0,   600,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   606,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   113,   176,     0,
     177,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     642,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     113,   176,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   586,   587,   588,
     589,   653,   590,   591,     0,   592,   593,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   113,   176,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     586,   587,   588,   589,   716,   590,   717,     0,   592,   593,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   113,   176,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   586,   587,   588,   589,   719,   590,   717,
       0,   592,   593,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   113,
     176,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   720,   721,   722,   723,
     724,   725,   726,     0,   727,   728,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   113,   176,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   720,
     721,   722,   723,   724,   733,   726,     0,   727,   728,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   113,   176,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   734,   735,   736,   737,   738,   739,   740,     0,
     741,   742,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   113,   176,
       0,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   734,   747,   736,   737,   738,
     739,   740,     0,   741,   742,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   113,   176,     0,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   806,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   113,   176,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   832,     0,   833,
     139,   140,   141,   775,   143,   144,   776,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   113,   176,     0,
     834,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   883,   884,   885,   886,   887,   888,
     889,     0,   890,   891,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     113,   176,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   883,   884,   885,
     897,   887,   888,   889,     0,   890,   891,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   113,   176,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     883,   884,   885,   899,   887,   888,   889,     0,   890,   891,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   113,   176,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   809,   810,   811,   812,   905,   813,   814,
       0,   815,   816,   140,   141,   817,   143,   144,   906,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   113,
     176,     0,   818,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   113,   176,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   586,
     587,   588,   589,     0,   590,   591,     0,   592,   593,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   113,   176,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   586,   587,   588,   589,   665,   590,     0,     0,
     592,   593,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   113,   176,
       0,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   586,   587,   588,   589,     0,
     590,   717,     0,   592,   593,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   113,   176,     0,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   586,   587,
     588,   589,   853,   590,     0,     0,   592,   593,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   113,   176,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   586,   587,   588,   589,     0,   590,     0,     0,   592,
     593,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   113,   176,     0,
     177,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   809,   810,   811,   812,     0,   813,
     814,     0,   815,   816,   140,   141,   817,   143,   144,   113,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,     0,   818,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   965,     0,   966,   139,     0,   967,   113,   143,
     144,   968,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,     0,   969,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   627,     0,     0,   628,     0,   629,     0,
     630,     0,     0,   697,   701,     0,   113,     0,   631,   632,
     633,     0,   634,   635,     0,     0,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,     0,   636,     0,   698,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   627,     0,     0,   628,     0,   629,     0,   630,     0,
       0,   697,     0,     0,   113,     0,   631,   632,   633,     0,
     634,   635,     0,     0,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,     0,
     636,     0,   698,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   627,
       0,     0,   628,     0,   629,     0,   630,     0,     0,     0,
       0,   707,   113,     0,   631,   632,   633,     0,   634,   635,
       0,     0,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     0,   636,     0,
     708,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   627,     0,     0,
     628,     0,   629,     0,   630,     0,     0,     0,     0,     0,
     113,     0,   631,   632,   633,     0,   634,   635,     0,     0,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,     0,   636,     0,   902,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,  1013,     0,  1014,   139,     0,   113,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,   270,   538,   271,     0,   272,   273,   274,     0,     0,
       0,     0,     0,     0,   176,     0,   177,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   275,   276,   277,   139,   140,   141,   775,   143,   144,
     776,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   113,   176,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   269,     0,   270,   581,   271,     0,   272,   273,
     274,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   627,     0,   767,   628,
     768,   629,     0,   630,   275,   276,   277,   113,   707,     0,
       0,   631,   632,   633,     0,   634,   635,     0,     0,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   636,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   627,     0,     0,   628,     0,   629,     0,   630,
       0,     0,     0,   827,   113,     0,     0,   631,   632,   633,
       0,   634,   635,     0,     0,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   636,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   627,
       0,     0,   628,     0,   629,     0,   630,     0,     0,     0,
     113,   707,     0,     0,   631,   632,   633,     0,   634,   635,
       0,     0,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     0,   636,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   627,     0,     0,   628,     0,
     629,     0,   630,     0,     0,     0,   113,     0,     0,     0,
     631,   632,   633,     0,   634,   635,     0,     0,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,     0,   636,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    48,   269,     0,   270,   650,   271,     0,   272,   273,
     274,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,    50,     0,     0,     0,   198,     0,   199,    51,
     200,     0,   201,   202,   203,     0,    52,     0,    53,     0,
       0,     0,    54,   170,   275,   276,   277,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,    56,
      57,    58,    59,     0,     0,     0,    60,     0,   204,   205,
     206,     0,     0,     0,     0,    61,   130,   131,   132,   133,
     134,   135,   136,   137,   870,     0,   871,   139,   140,   141,
     872,   143,   144,   873,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     0,   171,
     172,   173,   174,   175,     0,   176,   269,   874,   270,   748,
     271,     0,   272,   273,   274,   269,     0,   270,     0,   271,
       0,   272,   273,   274,   198,     0,   199,     0,   200,     0,
     369,   202,   203,   383,     0,   384,     0,   385,     0,   386,
     387,   388,     0,     0,     0,     0,     0,     0,   275,   276,
     277,     0,     0,     0,     0,     0,     0,   275,   276,   277,
       0,     0,     0,     0,     0,     0,   370,   205,   206,     0,
       0,     0,     0,     0,     0,   389,   390,   391,   413,     0,
     414,     0,   415,     0,   416,   417,   418,   413,     0,   414,
       0,   423,     0,   416,   417,   418,   413,     0,   414,     0,
     425,     0,   416,   417,   418,   413,     0,   414,     0,   426,
       0,   416,   417,   418,     0,     0,     0,     0,     0,     0,
     419,   420,   421,     0,     0,     0,     0,     0,     0,   419,
     420,   421,     0,     0,     0,     0,     0,     0,   419,   420,
     421,     0,     0,     0,     0,     0,     0,   419,   420,   421,
     413,     0,   414,     0,   427,     0,   416,   417,   418,   413,
       0,   414,     0,   428,     0,   416,   417,   418,   413,     0,
     414,     0,   429,     0,   416,   417,   418,   413,     0,   414,
       0,   430,     0,   416,   417,   418,     0,     0,     0,     0,
       0,     0,   419,   420,   421,     0,     0,     0,     0,     0,
       0,   419,   420,   421,     0,     0,     0,     0,     0,     0,
     419,   420,   421,     0,     0,     0,     0,     0,     0,   419,
     420,   421,   413,     0,   414,     0,   431,     0,   416,   417,
     418,   413,     0,   414,     0,   432,     0,   416,   417,   418,
     413,     0,   414,     0,   433,     0,   416,   417,   418,   413,
       0,   414,     0,   434,     0,   416,   417,   418,     0,     0,
       0,     0,     0,     0,   419,   420,   421,     0,     0,     0,
       0,     0,     0,   419,   420,   421,     0,     0,     0,     0,
       0,     0,   419,   420,   421,     0,     0,     0,     0,     0,
       0,   419,   420,   421,   413,     0,   414,     0,   435,     0,
     416,   417,   418,   328,     0,   352,     0,   437,     0,   329,
     330,   331,   328,     0,   352,     0,   439,     0,   329,   330,
     331,   328,     0,   352,     0,   442,     0,   329,   330,   331,
       0,     0,     0,     0,     0,     0,   419,   420,   421,     0,
       0,     0,     0,     0,     0,   332,   333,   334,     0,     0,
       0,     0,     0,     0,   332,   333,   334,     0,     0,     0,
       0,     0,     0,   332,   333,   334,   328,     0,   352,     0,
     443,     0,   329,   330,   331,   456,     0,   457,     0,   458,
       0,   459,   460,   461,   413,     0,   414,     0,   467,     0,
     416,   417,   418,   413,     0,   414,     0,   473,     0,   416,
     417,   418,     0,     0,     0,     0,     0,     0,   332,   333,
     334,     0,     0,     0,     0,     0,     0,   462,   463,   464,
       0,     0,     0,     0,     0,     0,   419,   420,   421,     0,
       0,     0,     0,     0,     0,   419,   420,   421,   413,     0,
     414,     0,   481,     0,   416,   417,   418,   413,     0,   414,
       0,   482,     0,   416,   417,   418,   383,     0,   384,     0,
     487,     0,   386,   387,   388,   502,     0,   503,     0,   504,
       0,   505,   506,   507,     0,     0,     0,     0,     0,     0,
     419,   420,   421,     0,     0,     0,     0,     0,     0,   419,
     420,   421,     0,     0,     0,     0,     0,     0,   389,   390,
     488,     0,     0,     0,     0,     0,     0,   508,   509,   510,
     413,     0,   414,     0,   525,     0,   416,   417,   418,   413,
       0,   414,     0,   536,     0,   416,   417,   418,   560,     0,
     561,     0,   562,     0,   563,   564,   565,   413,     0,   414,
       0,   625,     0,   416,   417,   418,     0,     0,     0,     0,
       0,     0,   419,   420,   421,     0,     0,     0,     0,     0,
       0,   419,   420,   421,     0,     0,     0,     0,     0,     0,
     566,   567,   568,     0,     0,     0,     0,     0,     0,   419,
     420,   421,   413,     0,   414,     0,   651,     0,   416,   417,
     418,   383,     0,   384,     0,   678,     0,   386,   387,   388,
     413,     0,   414,     0,   692,     0,   416,   417,   418,   413,
       0,   414,     0,   751,     0,   416,   417,   418,     0,     0,
       0,     0,     0,     0,   419,   420,   421,     0,     0,     0,
       0,     0,     0,   389,   390,   679,     0,     0,     0,     0,
       0,     0,   419,   420,   421,     0,     0,     0,     0,     0,
       0,   419,   420,   421,   502,     0,   503,     0,   794,     0,
     505,   795,   507,   413,     0,   414,     0,   850,     0,   416,
     417,   418,   413,     0,   414,     0,   953,     0,   416,   417,
     418,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   508,   509,   510,     0,
       0,     0,     0,     0,     0,   419,   420,   421,     0,     0,
       0,     0,     0,     0,   419,   420,   421
};

static const short yycheck[] =
{
      44,    46,   250,   758,   713,   447,   254,   374,   760,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   542,
      86,   665,   394,   687,   544,   548,   549,   659,   304,   106,
      59,    97,   248,    85,   124,   615,   668,   119,    65,   542,
     119,   989,   132,   549,    13,   548,   549,   129,   124,   119,
     119,    96,    81,   301,     0,   124,   132,   305,   116,   119,
     118,   105,   120,   542,   122,   123,   124,  1015,   119,   548,
     549,   594,   119,    42,   126,    44,    45,    46,    47,   120,
     159,    54,    55,   663,   451,   120,   609,   610,    61,   159,
     306,   594,   120,    62,   573,    36,    37,    38,    39,   159,
     158,   159,   160,   594,   610,   119,   609,   610,   159,   120,
     358,   607,   159,   609,   362,   594,   145,   119,   609,   491,
     120,   830,    31,    32,   620,   769,   605,   120,   495,    70,
     609,   610,   116,    97,   613,    99,   656,   130,   122,   123,
     124,    82,    83,    84,   268,   159,   669,   670,   671,   672,
     673,   674,    68,   520,   909,   279,   280,   159,    25,    68,
      69,   805,   126,   669,   670,   124,   669,   670,   671,   672,
     673,   674,   448,   132,   158,   159,   160,   544,    73,   658,
     659,   623,   788,   706,   119,   791,   665,    70,    71,   668,
     669,   670,   671,   672,   673,   674,    31,    32,   140,   141,
     706,   449,    36,   706,   836,   684,   148,    26,    27,   853,
     713,   299,   154,   154,   302,   694,   293,   294,   573,   120,
     155,   156,   157,   471,   155,   156,   157,   706,   129,   130,
     131,   120,   755,   790,   713,   661,   793,   145,   211,   212,
     213,   214,   215,   216,   996,    44,    45,   292,   120,   755,
     605,     3,   755,   226,   298,    40,    41,     3,   613,   762,
     686,   123,   124,   236,   237,    85,     4,     3,     3,   357,
     243,   244,   245,   246,   753,   523,   755,   120,   801,   758,
     111,   760,   785,   762,   120,   788,   131,   535,   791,   656,
     769,   955,   771,   120,   773,   801,    96,    97,   801,    99,
     129,   101,   120,   658,   659,   120,   785,   120,    85,   788,
     665,   120,   791,   668,   120,   120,   120,   713,   841,   120,
     130,   844,   801,   120,   847,   120,   805,   830,   120,   684,
     374,   120,   580,   836,   307,   308,   123,   120,   841,   694,
     120,   844,   120,   949,   847,   951,   952,   120,   436,   852,
     956,   830,   120,   140,   141,   120,   120,   131,   837,   120,
     786,   148,   841,   789,   120,   844,   792,   154,   847,   110,
     127,   118,   851,   852,   853,   120,   624,   116,  1022,   118,
     128,   469,   110,   122,   123,   124,   120,   866,   120,   785,
     478,   116,   788,   353,   127,   791,   356,   823,   753,   359,
     360,   445,   129,   758,   116,   760,   713,   451,   131,   127,
     125,   127,   500,   120,   769,   120,   771,   116,   773,   158,
     159,   160,   124,   127,  1000,   122,  1002,  1003,  1004,  1005,
     909,   857,   122,   499,   830,   861,  1012,   120,   917,   412,
     836,    12,   120,   869,   118,   533,   949,   118,   951,   952,
     805,   495,   118,   956,   498,   762,  1062,   118,    29,    30,
      31,   159,    33,    34,   159,   135,   989,   135,   159,   118,
     949,   118,   951,   952,   518,   118,   520,   956,   785,   118,
     118,   788,    11,    12,   791,   118,    57,    58,    59,   534,
      19,    20,  1015,    22,   159,   573,   851,     5,   853,     5,
     544,   474,   750,   547,   119,   119,   550,   118,   118,   118,
     127,   866,   656,   647,   558,   915,   769,   996,   853,   518,
     830,   917,   948,   830,   950,   755,   558,   605,   548,   836,
     574,   575,   942,   621,   578,   613,  1010,   704,   613,   800,
    1015,   836,    15,  1022,   116,   852,   118,   119,   120,   617,
     122,   123,   124,   949,   909,   951,   952,     1,   619,  1062,
     956,   116,   917,   118,   119,   120,   295,   122,   123,   124,
     749,    -1,    -1,    -1,    -1,  1001,    -1,   622,    -1,    -1,
     658,   659,    -1,  1062,    -1,    -1,   158,   159,   160,    -1,
     668,    -1,    -1,   989,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   849,    -1,   158,   159,   160,   684,    -1,    -1,    -1,
     917,    55,   656,  1039,    -1,    -1,    -1,    -1,    -1,  1015,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1058,  1059,  1060,    -1,    -1,    -1,    -1,    -1,
      -1,   996,   949,    -1,   951,   952,   690,    -1,    -1,   956,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,  1062,  1022,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   753,    -1,    -1,    -1,    -1,
     116,    -1,   118,   119,   120,    -1,   122,   123,   124,    -1,
       0,     1,    -1,   771,    -1,   773,     6,     7,     8,     9,
      -1,    11,    12,    13,    -1,    15,    16,    -1,   152,    19,
      20,    -1,    22,    23,    24,    25,    -1,   761,    28,    -1,
       1,    31,   158,   159,   160,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    48,    -1,
      -1,    -1,   116,    -1,   118,   119,   120,    -1,   122,   123,
     124,    -1,    -1,     1,    64,  1062,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    -1,    -1,   851,    55,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,   158,   159,   160,   831,   866,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   848,    -1,    -1,    -1,    55,   118,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,    -1,    94,    95,   158,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,   116,    23,
     118,   119,   120,    -1,   122,   123,   124,   152,   116,    -1,
     118,   119,   120,    -1,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   152,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
     158,   159,   160,    -1,    -1,    -1,    -1,    55,   123,    -1,
     158,   159,   160,    -1,    -1,    -1,    -1,    81,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,  1007,  1008,  1009,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      55,   159,    -1,   161,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
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
     116,   117,    -1,    -1,   120,   121,   122,   123,   124,   125,
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
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    55,   159,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    55,   159,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
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
     114,   115,   116,   117,    -1,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    55,   159,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,   117,    -1,    -1,   120,
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
     118,    -1,   120,   121,   122,   123,   124,   125,   126,    55,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    -1,   161,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,   120,   121,    -1,   123,    55,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,    -1,   161,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,   113,    -1,   115,    -1,
     117,    -1,    -1,   120,   121,    -1,    55,    -1,   125,   126,
     127,    -1,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    -1,   159,    -1,   161,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,   113,    -1,   115,    -1,   117,    -1,
      -1,   120,    -1,    -1,    55,    -1,   125,   126,   127,    -1,
     129,   130,    -1,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    -1,   161,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,
      -1,   122,    55,    -1,   125,   126,   127,    -1,   129,   130,
      -1,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    -1,   159,    -1,
     161,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
     113,    -1,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      55,    -1,   125,   126,   127,    -1,   129,   130,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,    -1,   161,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,   121,    -1,    55,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,   118,   119,   120,    -1,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,   161,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   158,   159,   160,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    55,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,   118,   119,   120,    -1,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,   112,   113,
     114,   115,    -1,   117,   158,   159,   160,    55,   122,    -1,
      -1,   125,   126,   127,    -1,   129,   130,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    -1,   159,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,   113,    -1,   115,    -1,   117,
      -1,    -1,    -1,   121,    55,    -1,    -1,   125,   126,   127,
      -1,   129,   130,    -1,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,
      55,   122,    -1,    -1,   125,   126,   127,    -1,   129,   130,
      -1,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    -1,   159,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,   113,    -1,
     115,    -1,   117,    -1,    -1,    -1,    55,    -1,    -1,    -1,
     125,   126,   127,    -1,   129,   130,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    -1,   159,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     7,   116,    -1,   118,   119,   120,    -1,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    28,    -1,    -1,    -1,   116,    -1,   118,    35,
     120,    -1,   122,   123,   124,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,   152,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    72,    -1,   158,   159,
     160,    -1,    -1,    -1,    -1,    81,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,   153,
     154,   155,   156,   157,    -1,   159,   116,   161,   118,   119,
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
     122,   123,   124,   116,    -1,   118,    -1,   120,    -1,   122,
     123,   124,   116,    -1,   118,    -1,   120,    -1,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    15,    16,    23,
      24,    25,    28,    31,    35,    48,    64,    74,    75,    76,
      77,    78,    79,    80,    86,    87,    88,    89,    90,    91,
      92,    93,   118,   158,   163,   164,   165,   194,   206,   216,
     319,   362,   363,   355,   195,   324,   332,   330,     7,    25,
      28,    35,    42,    44,    48,    63,    65,    66,    67,    68,
      72,    81,   365,     6,     8,    23,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    81,
      31,    32,    68,    69,   359,   360,   320,    70,    71,   361,
     359,    65,   120,   120,   120,   120,   325,   322,   168,   169,
     170,   167,   333,   166,     0,   207,   331,    11,    12,    19,
      20,    22,   120,    55,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   159,   161,   301,   312,
     313,   314,   315,   316,   317,   318,   116,   118,   120,   122,
     123,   124,   158,   159,   160,   366,   408,   366,   116,   118,
     120,   122,   123,   124,   158,   159,   160,   372,   410,    68,
      13,    42,    44,    45,    46,    47,    62,    12,    29,    30,
      31,    33,    34,    57,    58,    59,   357,    36,    37,    38,
      39,    70,    82,    83,    84,   154,   356,    25,    26,    27,
     358,   358,   358,    59,    81,   145,    73,   358,   351,   338,
     341,    36,    85,   126,   339,   120,   120,   340,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   334,   335,   116,
     118,   120,   122,   123,   124,   158,   159,   160,   402,   337,
     336,   145,   366,   402,     3,     3,     4,     3,   399,     3,
     301,   372,   326,   327,   328,   329,    85,   364,   111,   409,
     367,   368,   411,   373,   374,   375,   353,    44,    45,   358,
     358,   358,   358,   358,   358,   358,    40,    41,   358,   358,
     120,   120,   120,   358,   358,   358,   358,   120,   116,   122,
     123,   124,   158,   159,   160,   421,   400,   400,   120,   120,
      85,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   118,   418,   419,   421,   418,   403,   321,   418,
     418,   120,   323,   119,   402,   208,   366,   372,   372,   122,
     158,   382,   410,   120,   118,   172,   173,   174,   301,   399,
     401,   400,   399,   116,   118,   120,   122,   123,   124,   158,
     159,   160,   376,   412,   401,   400,   421,   358,   358,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   352,   116,   118,   120,   122,   123,   124,   158,
     159,   160,   404,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   420,   120,   419,   120,
     399,   400,   120,   120,   400,   131,   210,   383,   384,   385,
     172,   129,   196,   130,   131,   119,   116,   118,   120,   122,
     123,   124,   158,   159,   160,   369,   406,   120,   119,   413,
     377,   378,   369,   120,   354,   120,   120,   358,   405,   399,
     119,   120,   120,   211,   212,   301,   110,   120,   160,   386,
     412,   401,   400,   119,   172,   127,   118,   177,   175,   370,
     407,   399,   116,   118,   120,   122,   123,   124,   158,   159,
     160,   379,   414,   400,   358,   120,   399,   119,   124,   132,
     128,   217,   387,   388,   369,   120,   172,   178,   176,   301,
     402,   399,   119,   415,   380,   381,   120,   120,   119,   212,
     172,     1,    55,    94,    95,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   152,   218,
     116,   118,   120,   122,   123,   124,   158,   159,   160,   389,
     416,   400,   197,    97,    99,   126,   179,   180,   124,   132,
     371,   119,   399,   366,   400,   120,   112,   113,   114,   115,
     117,   118,   120,   121,   245,   246,   307,   313,   314,   317,
     161,   171,   172,   173,   219,   220,   118,   242,   301,   245,
     241,   307,   301,   237,   221,   223,   226,   228,   231,   233,
     242,   417,   390,   391,   392,   120,   110,   110,   113,   115,
     117,   125,   126,   127,   129,   130,   159,   293,   294,   310,
     314,   318,   118,   181,   301,   301,   119,   124,   301,   400,
     119,   120,   247,   116,   246,   248,   129,   120,   272,   273,
     293,   244,   248,   243,   248,   116,   307,   236,   273,   277,
     277,   283,   283,   285,   285,   248,   399,   366,   120,   160,
     393,   412,   400,   198,   127,   131,   183,   116,   184,   182,
     127,   180,   120,   275,   251,   171,   172,   120,   161,   209,
     293,   121,   209,   293,   274,   275,   277,   122,   161,   213,
     214,   252,   293,   125,   238,   209,   116,   118,   307,   116,
     112,   113,   114,   115,   116,   117,   118,   120,   121,   305,
     313,   314,   317,   117,   112,   113,   114,   115,   116,   117,
     118,   120,   121,   304,   313,   314,   317,   113,   119,   394,
     395,   120,    96,    97,    99,   101,   199,   293,   295,   275,
     251,   127,   279,   301,   118,   119,   301,   112,   114,   250,
     252,   272,   119,   253,   120,   124,   127,   239,   240,   302,
     312,   314,   316,   317,   120,   222,   278,   224,   227,   284,
     229,   232,   286,   234,   120,   123,   396,   414,   400,   293,
     200,   241,   294,   296,   119,   250,   118,   185,   301,   112,
     113,   114,   115,   117,   118,   120,   121,   124,   161,   308,
     312,   314,   317,   276,   213,   249,   252,   121,   254,   293,
     124,   116,   118,   120,   161,   215,   289,   290,   302,   311,
     275,   287,   215,   275,   287,   215,   275,   287,   397,   398,
     120,   127,   279,   116,   124,   132,   252,   187,   122,   188,
     186,   280,   275,   122,   255,   123,   124,   240,   301,   291,
     118,   120,   124,   127,   161,   209,   303,   311,   312,   316,
     317,   314,   119,   112,   113,   114,   115,   116,   117,   118,
     120,   121,   306,   313,   314,   317,   119,   115,   119,   115,
     366,   400,   161,   201,   293,   116,   127,   202,   214,   297,
     275,   140,   141,   148,   154,   189,   190,   281,   275,   119,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   256,   257,   258,   120,   293,   275,   292,   225,
     288,   230,   235,   120,   120,   203,   205,   294,   119,   159,
     118,   118,   118,   123,   190,   118,   120,   123,   127,   161,
     309,   312,   314,   316,   318,   119,   135,   135,   159,   118,
     159,   118,   118,   118,   118,   118,   118,   123,   258,   259,
     119,   275,   215,   275,   215,   215,   251,   215,   191,   193,
     192,   282,   260,   262,   263,   264,   265,   155,   156,   157,
     267,   268,   261,   118,   120,   298,   299,   313,   315,   316,
     119,   119,   250,   159,   266,     5,   266,   275,   266,   266,
     266,   266,     5,   301,   301,   301,   119,   268,   266,   300,
     299,   252,   119,   159,   119,   119,   119,   119,   119,   119,
     119,   119,   118,   118,   118,   119,   275,   127,   269,   270,
     271,   119,   204,   275,   275,   275,   215,   119,   119,   119
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
#line 215 "surface.yy"
    { YYACCEPT; ;}
    break;

  case 3:
#line 217 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			;}
    break;

  case 8:
#line 231 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 9:
#line 233 "surface.yy"
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
#line 241 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 11:
#line 243 "surface.yy"
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
#line 252 "surface.yy"
    {
			  cout << directoryManager.getCwd() << '\n';
			;}
    break;

  case 13:
#line 255 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 14:
#line 257 "surface.yy"
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
#line 266 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 16:
#line 268 "surface.yy"
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
#line 278 "surface.yy"
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
#line 288 "surface.yy"
    { lexerStringMode(); ;}
    break;

  case 19:
#line 290 "surface.yy"
    {
			  system((string("ls") + yyvsp[0].yyString).c_str());
			;}
    break;

  case 20:
#line 294 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			;}
    break;

  case 21:
#line 299 "surface.yy"
    {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			;}
    break;

  case 23:
#line 333 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			;}
    break;

  case 24:
#line 341 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  moduleExpressions.push(new ModuleExpression(t));
			;}
    break;

  case 26:
#line 352 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			;}
    break;

  case 28:
#line 363 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			;}
    break;

  case 29:
#line 371 "surface.yy"
    {;}
    break;

  case 30:
#line 372 "surface.yy"
    { clear(); ;}
    break;

  case 31:
#line 374 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, bubble));
			;}
    break;

  case 32:
#line 380 "surface.yy"
    {
			  moduleExpressions.push(new ModuleExpression(yyvsp[0].yyToken));
			;}
    break;

  case 33:
#line 385 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 34:
#line 386 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 35:
#line 393 "surface.yy"
    {
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			;}
    break;

  case 36:
#line 398 "surface.yy"
    {
			  currentSyntaxContainer = oldSyntaxContainer;
			;}
    break;

  case 39:
#line 408 "surface.yy"
    {
			  currentRenaming->addSortMapping(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 40:
#line 412 "surface.yy"
    {
			  currentRenaming->addLabelMapping(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 41:
#line 415 "surface.yy"
    {;}
    break;

  case 42:
#line 418 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 43:
#line 420 "surface.yy"
    {
			  currentRenaming->addOpMapping(bubble);
			;}
    break;

  case 44:
#line 423 "surface.yy"
    { clear(); ;}
    break;

  case 45:
#line 425 "surface.yy"
    {
			  currentRenaming->addOpMapping(bubble);
			;}
    break;

  case 46:
#line 430 "surface.yy"
    {;}
    break;

  case 48:
#line 434 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 49:
#line 435 "surface.yy"
    { currentRenaming->addOpTarget(bubble); ;}
    break;

  case 50:
#line 436 "surface.yy"
    { clear(); ;}
    break;

  case 51:
#line 437 "surface.yy"
    { currentRenaming->addOpTarget(bubble); ;}
    break;

  case 52:
#line 440 "surface.yy"
    {;}
    break;

  case 56:
#line 448 "surface.yy"
    { currentRenaming->setPrec(yyvsp[0].yyToken); ;}
    break;

  case 57:
#line 449 "surface.yy"
    { clear(); ;}
    break;

  case 58:
#line 450 "surface.yy"
    { currentRenaming->setGather(bubble); ;}
    break;

  case 59:
#line 451 "surface.yy"
    { clear(); ;}
    break;

  case 60:
#line 452 "surface.yy"
    { currentRenaming->setFormat(bubble); ;}
    break;

  case 61:
#line 453 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 62:
#line 454 "surface.yy"
    { currentRenaming->setLatexMacro(yyvsp[-1].yyString); ;}
    break;

  case 63:
#line 460 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 64:
#line 462 "surface.yy"
    {
			  fileTable.beginModule(yyvsp[-4].yyToken, yyvsp[-2].yyToken);
			  interpreter.setCurrentView(new View(yyvsp[-2].yyToken));
			  currentSyntaxContainer = CV;
			  CV->addFrom(moduleExpressions.top());
			  moduleExpressions.pop();
			;}
    break;

  case 65:
#line 470 "surface.yy"
    {
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			;}
    break;

  case 66:
#line 475 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  interpreter.insertView((yyvsp[-9].yyToken).code(), CV);
			  CV->finishView();
			;}
    break;

  case 69:
#line 488 "surface.yy"
    {
			  CV->addSortMapping(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 70:
#line 491 "surface.yy"
    {;}
    break;

  case 71:
#line 492 "surface.yy"
    { clear(); ;}
    break;

  case 73:
#line 496 "surface.yy"
    { yyval.yyToken = yyvsp[-1].yyToken; ;}
    break;

  case 74:
#line 498 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  yyval.yyToken = t;
			;}
    break;

  case 75:
#line 508 "surface.yy"
    {
			  //
			  //	Specific op->op mapping.
			  //
			  Token::peelParens(bubble);  // remove any enclosing parens from op name
			  CV->addOpMapping(bubble);
			;}
    break;

  case 76:
#line 516 "surface.yy"
    {
			  clear();
			;}
    break;

  case 77:
#line 520 "surface.yy"
    {
			  Token::peelParens(bubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(bubble);
			;}
    break;

  case 78:
#line 525 "surface.yy"
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

  case 79:
#line 535 "surface.yy"
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

  case 80:
#line 559 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 81:
#line 561 "surface.yy"
    {
			  interpreter.setCurrentModule(new PreModule(yyvsp[-2].yyToken, yyvsp[0].yyToken));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 82:
#line 567 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule(yyvsp[0].yyToken);
			;}
    break;

  case 83:
#line 574 "surface.yy"
    {;}
    break;

  case 84:
#line 576 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  store(t);
			;}
    break;

  case 85:
#line 585 "surface.yy"
    {;}
    break;

  case 89:
#line 594 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter(yyvsp[-2].yyToken, me);
			;}
    break;

  case 90:
#line 602 "surface.yy"
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

  case 94:
#line 619 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  store(t);
			;}
    break;

  case 99:
#line 636 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport(yyvsp[-1].yyToken, me);
			;}
    break;

  case 100:
#line 642 "surface.yy"
    { clear(); ;}
    break;

  case 101:
#line 643 "surface.yy"
    { CM->addSortDecl(bubble); ;}
    break;

  case 102:
#line 645 "surface.yy"
    { clear(); ;}
    break;

  case 103:
#line 646 "surface.yy"
    { CM->addSubsortDecl(bubble); ;}
    break;

  case 104:
#line 648 "surface.yy"
    {;}
    break;

  case 105:
#line 650 "surface.yy"
    {;}
    break;

  case 106:
#line 652 "surface.yy"
    {;}
    break;

  case 107:
#line 654 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 108:
#line 655 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 109:
#line 656 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 110:
#line 658 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 111:
#line 659 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 112:
#line 660 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 113:
#line 661 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 114:
#line 663 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 115:
#line 664 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 116:
#line 665 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 117:
#line 667 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 118:
#line 668 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 119:
#line 669 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 120:
#line 670 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 121:
#line 672 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 122:
#line 673 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 123:
#line 674 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 124:
#line 676 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 125:
#line 677 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 126:
#line 678 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 127:
#line 679 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 128:
#line 682 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 129:
#line 687 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 130:
#line 692 "surface.yy"
    {
			;}
    break;

  case 131:
#line 695 "surface.yy"
    {
			;}
    break;

  case 132:
#line 698 "surface.yy"
    { clear(); ;}
    break;

  case 133:
#line 699 "surface.yy"
    { CM->addSubsortDecl(bubble); ;}
    break;

  case 134:
#line 702 "surface.yy"
    {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeOpDeclsConsistent();
			;}
    break;

  case 135:
#line 712 "surface.yy"
    {;}
    break;

  case 136:
#line 713 "surface.yy"
    {;}
    break;

  case 139:
#line 721 "surface.yy"
    {
			;}
    break;

  case 140:
#line 725 "surface.yy"
    { currentSyntaxContainer->addVarDecl(yyvsp[0].yyToken); ;}
    break;

  case 141:
#line 726 "surface.yy"
    { currentSyntaxContainer->addVarDecl(yyvsp[0].yyToken); ;}
    break;

  case 142:
#line 729 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 143:
#line 730 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 144:
#line 731 "surface.yy"
    { clear(); ;}
    break;

  case 145:
#line 732 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 148:
#line 740 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  CM->addOpDecl(bubble);
			;}
    break;

  case 149:
#line 745 "surface.yy"
    { clear(); ;}
    break;

  case 150:
#line 746 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 151:
#line 750 "surface.yy"
    {
			  if (yyvsp[-1].yyBool)
			    CM->convertSortsToKinds();
			;}
    break;

  case 154:
#line 760 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 155:
#line 761 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 158:
#line 769 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  currentSyntaxContainer->addType(false, bubble);
			;}
    break;

  case 159:
#line 774 "surface.yy"
    { clear(); ;}
    break;

  case 160:
#line 776 "surface.yy"
    {
			  currentSyntaxContainer->addType(true, bubble);
			;}
    break;

  case 161:
#line 781 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 162:
#line 782 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 163:
#line 785 "surface.yy"
    {;}
    break;

  case 167:
#line 794 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			;}
    break;

  case 168:
#line 798 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			;}
    break;

  case 169:
#line 802 "surface.yy"
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			;}
    break;

  case 170:
#line 808 "surface.yy"
    {
			  CM->setFlag(SymbolType::ASSOC);
			;}
    break;

  case 171:
#line 812 "surface.yy"
    {
			  CM->setFlag(SymbolType::COMM);
			;}
    break;

  case 172:
#line 815 "surface.yy"
    { clear(); ;}
    break;

  case 173:
#line 816 "surface.yy"
    { CM->setIdentity(bubble); ;}
    break;

  case 174:
#line 818 "surface.yy"
    {
			  CM->setFlag(SymbolType::IDEM);
			;}
    break;

  case 175:
#line 822 "surface.yy"
    {
			  CM->setFlag(SymbolType::ITER);
			;}
    break;

  case 176:
#line 825 "surface.yy"
    { CM->setPrec(yyvsp[0].yyToken); ;}
    break;

  case 177:
#line 826 "surface.yy"
    { clear(); ;}
    break;

  case 178:
#line 827 "surface.yy"
    { CM->setGather(bubble); ;}
    break;

  case 179:
#line 828 "surface.yy"
    { clear(); ;}
    break;

  case 180:
#line 829 "surface.yy"
    { CM->setFormat(bubble); ;}
    break;

  case 181:
#line 830 "surface.yy"
    { clear(); ;}
    break;

  case 182:
#line 831 "surface.yy"
    { CM->setStrat(bubble); ;}
    break;

  case 183:
#line 832 "surface.yy"
    { clear(); ;}
    break;

  case 184:
#line 833 "surface.yy"
    { CM->setPoly(bubble); ;}
    break;

  case 185:
#line 835 "surface.yy"
    {
			  CM->setFlag(SymbolType::MEMO);
			;}
    break;

  case 186:
#line 839 "surface.yy"
    {
			  CM->setFlag(SymbolType::CTOR);
			;}
    break;

  case 187:
#line 843 "surface.yy"
    {
			  clear();
			  CM->setFrozen(bubble);
			;}
    break;

  case 188:
#line 847 "surface.yy"
    { clear(); ;}
    break;

  case 189:
#line 848 "surface.yy"
    { CM->setFrozen(bubble); ;}
    break;

  case 190:
#line 850 "surface.yy"
    {
			  CM->setFlag(SymbolType::CONFIG);
			;}
    break;

  case 191:
#line 854 "surface.yy"
    {
			  CM->setFlag(SymbolType::OBJECT);
			;}
    break;

  case 192:
#line 858 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 193:
#line 862 "surface.yy"
    {
			  CM->setMetadata(yyvsp[0].yyToken);
			;}
    break;

  case 194:
#line 865 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 195:
#line 866 "surface.yy"
    { CM->setLatexMacro(yyvsp[-1].yyString); ;}
    break;

  case 196:
#line 867 "surface.yy"
    {;}
    break;

  case 197:
#line 869 "surface.yy"
    {
			  CM->setFlag(SymbolType::DITTO);
			;}
    break;

  case 198:
#line 874 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 199:
#line 875 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 202:
#line 883 "surface.yy"
    {
			  clear();
			  CM->addHook(PreModule::ID_HOOK, yyvsp[0].yyToken, bubble);
			;}
    break;

  case 203:
#line 887 "surface.yy"
    { clear(); ;}
    break;

  case 204:
#line 889 "surface.yy"
    {
			  CM->addHook(PreModule::ID_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 205:
#line 892 "surface.yy"
    { clear(); ;}
    break;

  case 206:
#line 894 "surface.yy"
    {
			  CM->addHook(PreModule::OP_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 207:
#line 897 "surface.yy"
    { clear(); ;}
    break;

  case 208:
#line 899 "surface.yy"
    {
			  CM->addHook(PreModule::TERM_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 209:
#line 907 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 211:
#line 911 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 212:
#line 912 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 213:
#line 913 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 214:
#line 914 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 215:
#line 920 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 216:
#line 921 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 217:
#line 922 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 219:
#line 926 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 220:
#line 927 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 221:
#line 928 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 223:
#line 932 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 224:
#line 933 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 225:
#line 934 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 227:
#line 938 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 228:
#line 939 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 229:
#line 940 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 231:
#line 944 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 232:
#line 945 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 233:
#line 946 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 235:
#line 950 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 236:
#line 951 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 237:
#line 952 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 239:
#line 956 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 240:
#line 957 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 241:
#line 958 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 244:
#line 963 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 245:
#line 964 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 246:
#line 967 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 247:
#line 968 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 248:
#line 969 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 249:
#line 970 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 250:
#line 971 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 251:
#line 972 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 252:
#line 973 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 253:
#line 980 "surface.yy"
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

  case 254:
#line 991 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 255:
#line 992 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 256:
#line 993 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 257:
#line 996 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 258:
#line 997 "surface.yy"
    {;}
    break;

  case 259:
#line 998 "surface.yy"
    {;}
    break;

  case 260:
#line 1004 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 261:
#line 1005 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 266:
#line 1009 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 267:
#line 1010 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 425:
#line 1115 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 426:
#line 1116 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 427:
#line 1118 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.setCurrentModule(bubble);
			;}
    break;

  case 428:
#line 1122 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 429:
#line 1123 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 430:
#line 1125 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->dump();
			;}
    break;

  case 431:
#line 1131 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 432:
#line 1137 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(bubble);
			;}
    break;

  case 433:
#line 1144 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 434:
#line 1150 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(bubble);
			;}
    break;

  case 435:
#line 1157 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 436:
#line 1163 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(bubble, yyvsp[-3].yyBool);
			;}
    break;

  case 437:
#line 1170 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 438:
#line 1177 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(bubble, number, yyvsp[-3].yyBool);
			;}
    break;

  case 439:
#line 1183 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 440:
#line 1191 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 441:
#line 1197 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 442:
#line 1205 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 443:
#line 1211 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 444:
#line 1218 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(bubble, number);
			;}
    break;

  case 445:
#line 1224 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 446:
#line 1231 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(bubble, yyvsp[-2].yyBool, number);
			;}
    break;

  case 447:
#line 1237 "surface.yy"
    {
			  interpreter.cont(yyvsp[-1].yyInt64, yyvsp[-3].yyBool);
			;}
    break;

  case 448:
#line 1241 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 449:
#line 1247 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(bubble);
			;}
    break;

  case 450:
#line 1252 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 451:
#line 1254 "surface.yy"
    {
			  lexerInitialMode();
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(bubble);
			;}
    break;

  case 452:
#line 1261 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 453:
#line 1263 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 454:
#line 1267 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 455:
#line 1269 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude(yyvsp[-3].yyBool);
			;}
    break;

  case 456:
#line 1273 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 457:
#line 1275 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 458:
#line 1279 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 459:
#line 1281 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal(yyvsp[-3].yyBool);
			;}
    break;

  case 460:
#line 1286 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			;}
    break;

  case 461:
#line 1293 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 462:
#line 1295 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 463:
#line 1300 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 464:
#line 1302 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 465:
#line 1307 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 466:
#line 1309 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showModule(true);
			;}
    break;

  case 467:
#line 1314 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 468:
#line 1316 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentView(bubble))
			    interpreter.showView();
			;}
    break;

  case 469:
#line 1322 "surface.yy"
    {
			  interpreter.showModules(true);
			;}
    break;

  case 470:
#line 1326 "surface.yy"
    {
			  interpreter.showNamedViews();
			;}
    break;

  case 471:
#line 1329 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 472:
#line 1331 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSortsAndSubsorts();
			;}
    break;

  case 473:
#line 1336 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 474:
#line 1338 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showOps();
			;}
    break;

  case 475:
#line 1343 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 476:
#line 1345 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showVars();
			;}
    break;

  case 477:
#line 1350 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 478:
#line 1352 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showMbs();
			;}
    break;

  case 479:
#line 1357 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 480:
#line 1359 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showEqs();
			;}
    break;

  case 481:
#line 1364 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 482:
#line 1366 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showRls();
			;}
    break;

  case 483:
#line 1371 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 484:
#line 1373 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSummary();
			;}
    break;

  case 485:
#line 1378 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 486:
#line 1380 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showKinds();
			;}
    break;

  case 487:
#line 1386 "surface.yy"
    {
			  interpreter.showSearchPath(yyvsp[-1].yyInt64);
			;}
    break;

  case 488:
#line 1390 "surface.yy"
    {
			  interpreter.showSearchPathLabels(yyvsp[-1].yyInt64);
			;}
    break;

  case 489:
#line 1394 "surface.yy"
    {
			  interpreter.showSearchGraph();
			;}
    break;

  case 490:
#line 1397 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 491:
#line 1399 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showProfile();
			;}
    break;

  case 492:
#line 1408 "surface.yy"
    {
			  globalAdvisoryFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 493:
#line 1412 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 494:
#line 1416 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 495:
#line 1420 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 496:
#line 1424 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, yyvsp[-1].yyBool);
			;}
    break;

  case 497:
#line 1428 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 498:
#line 1432 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, yyvsp[-1].yyBool);
			;}
    break;

  case 499:
#line 1436 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 500:
#line 1440 "surface.yy"
    {
			  interpreter.setPrintFlag(yyvsp[-2].yyPrintFlags, yyvsp[-1].yyBool);
			;}
    break;

  case 501:
#line 1444 "surface.yy"
    {
			  interpreter.setFlag(yyvsp[-2].yyFlags, yyvsp[-1].yyBool);
			;}
    break;

  case 502:
#line 1448 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, yyvsp[-1].yyBool);
			;}
    break;

  case 503:
#line 1451 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 504:
#line 1452 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 505:
#line 1454 "surface.yy"
    {
			  interpreter.setAutoImport(yyvsp[-5].yyImportMode, yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 506:
#line 1457 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 507:
#line 1458 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 508:
#line 1460 "surface.yy"
    {
			  interpreter.setOmodInclude(yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 509:
#line 1464 "surface.yy"
    {
			  globalVerboseFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 510:
#line 1468 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, yyvsp[-1].yyBool);
			;}
    break;

  case 511:
#line 1472 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, yyvsp[-1].yyBool);
			;}
    break;

  case 512:
#line 1476 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, yyvsp[-1].yyBool);
			;}
    break;

  case 513:
#line 1480 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 514:
#line 1484 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 515:
#line 1491 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			;}
    break;

  case 516:
#line 1495 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			;}
    break;

  case 517:
#line 1499 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			;}
    break;

  case 518:
#line 1503 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			;}
    break;

  case 519:
#line 1510 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 520:
#line 1514 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 521:
#line 1520 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 523:
#line 1527 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_MIXFIX; ;}
    break;

  case 524:
#line 1528 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_FLAT; ;}
    break;

  case 525:
#line 1529 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_WITH_ALIASES; ;}
    break;

  case 526:
#line 1530 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_WITH_PARENS; ;}
    break;

  case 527:
#line 1531 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_GRAPH; ;}
    break;

  case 528:
#line 1532 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_CONCEAL; ;}
    break;

  case 529:
#line 1533 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_NUMBER; ;}
    break;

  case 530:
#line 1534 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_RAT; ;}
    break;

  case 531:
#line 1535 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_COLOR; ;}
    break;

  case 532:
#line 1536 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_FORMAT; ;}
    break;

  case 533:
#line 1539 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE; ;}
    break;

  case 534:
#line 1540 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_CONDITION; ;}
    break;

  case 535:
#line 1541 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_WHOLE; ;}
    break;

  case 536:
#line 1542 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_SUBSTITUTION; ;}
    break;

  case 537:
#line 1543 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_SELECT; ;}
    break;

  case 538:
#line 1544 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_MB; ;}
    break;

  case 539:
#line 1545 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_EQ; ;}
    break;

  case 540:
#line 1546 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_RL; ;}
    break;

  case 541:
#line 1547 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_REWRITE; ;}
    break;

  case 542:
#line 1548 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_BODY; ;}
    break;

  case 543:
#line 1551 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 544:
#line 1552 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 545:
#line 1555 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 546:
#line 1556 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 547:
#line 1559 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 548:
#line 1560 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 549:
#line 1563 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 550:
#line 1564 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 551:
#line 1567 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 552:
#line 1568 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 553:
#line 1571 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 554:
#line 1572 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 555:
#line 1575 "surface.yy"
    { yyval.yyInt64 = yyvsp[0].yyInt64; ;}
    break;

  case 556:
#line 1576 "surface.yy"
    { yyval.yyInt64 = NONE; ;}
    break;

  case 557:
#line 1579 "surface.yy"
    { yyval.yyImportMode = ImportModule::PROTECTING; ;}
    break;

  case 558:
#line 1580 "surface.yy"
    { yyval.yyImportMode = ImportModule::EXTENDING; ;}
    break;

  case 559:
#line 1581 "surface.yy"
    { yyval.yyImportMode = ImportModule::INCLUDING; ;}
    break;

  case 560:
#line 1589 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 562:
#line 1591 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 564:
#line 1595 "surface.yy"
    { moduleExpr = bubble; clear(); ;}
    break;

  case 565:
#line 1596 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 566:
#line 1597 "surface.yy"
    {;}
    break;

  case 567:
#line 1598 "surface.yy"
    {;}
    break;

  case 568:
#line 1607 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 570:
#line 1609 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 572:
#line 1611 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 574:
#line 1616 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 576:
#line 1618 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 578:
#line 1620 "surface.yy"
    {;}
    break;

  case 579:
#line 1625 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 581:
#line 1630 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 583:
#line 1632 "surface.yy"
    {;}
    break;

  case 584:
#line 1641 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 586:
#line 1643 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 588:
#line 1645 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 590:
#line 1650 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 592:
#line 1652 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 594:
#line 1654 "surface.yy"
    {;}
    break;

  case 595:
#line 1659 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 597:
#line 1664 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 599:
#line 1666 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 601:
#line 1668 "surface.yy"
    {;}
    break;

  case 602:
#line 1672 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 604:
#line 1674 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 606:
#line 1676 "surface.yy"
    {;}
    break;

  case 607:
#line 1681 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  number2 = Token::codeToInt64(bubble[3].code());
			  clear();
			;}
    break;

  case 609:
#line 1687 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 611:
#line 1689 "surface.yy"
    {;}
    break;

  case 612:
#line 1695 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 614:
#line 1699 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 616:
#line 1704 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 626:
#line 1712 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 627:
#line 1713 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 635:
#line 1717 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 636:
#line 1718 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 643:
#line 1723 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 644:
#line 1724 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 652:
#line 1728 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 653:
#line 1729 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 660:
#line 1733 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 661:
#line 1734 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 668:
#line 1739 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 669:
#line 1740 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 676:
#line 1745 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 677:
#line 1746 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 683:
#line 1751 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 684:
#line 1752 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 687:
#line 1763 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  interpreter.addSelected(bubble);
			;}
    break;

  case 688:
#line 1768 "surface.yy"
    { clear(); ;}
    break;

  case 689:
#line 1770 "surface.yy"
    {
			  interpreter.addSelected(bubble);
			;}
    break;


    }

/* Line 999 of yacc.c.  */
#line 6115 "surface.c"

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


#line 1800 "surface.yy"


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

