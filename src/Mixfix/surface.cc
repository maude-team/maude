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
stack<ModuleExpression*> moduleExpressions;
Renaming* currentRenaming = 0;

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
#line 94 "surface.yy"
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
#line 444 "surface.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 104 "surface.yy"

int yylex(YYSTYPE* lvalp);


/* Line 214 of yacc.c.  */
#line 459 "surface.c"

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
#define YYLAST   6653

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  162
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  259
/* YYNRULES -- Number of rules. */
#define YYNRULES  695
/* YYNRULES -- Number of states. */
#define YYNSTATES  1063

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
     104,   109,   116,   117,   121,   122,   127,   132,   133,   136,
     137,   139,   140,   145,   146,   150,   151,   156,   160,   161,
     164,   166,   169,   170,   176,   177,   183,   184,   190,   191,
     192,   193,   206,   209,   210,   215,   216,   223,   226,   228,
     229,   230,   239,   241,   243,   247,   248,   252,   254,   258,
     260,   263,   265,   268,   270,   272,   274,   277,   278,   281,
     282,   287,   288,   293,   297,   301,   306,   307,   308,   315,
     316,   317,   318,   328,   329,   330,   337,   338,   339,   340,
     350,   351,   352,   359,   360,   361,   362,   372,   376,   380,
     381,   387,   388,   393,   396,   398,   401,   403,   407,   411,
     414,   416,   417,   421,   422,   427,   430,   432,   434,   435,
     440,   445,   449,   451,   453,   455,   458,   459,   461,   462,
     467,   471,   473,   477,   478,   481,   483,   485,   488,   491,
     493,   495,   496,   500,   502,   504,   507,   508,   514,   515,
     521,   522,   528,   529,   535,   537,   539,   541,   542,   548,
     550,   552,   554,   557,   558,   564,   569,   571,   574,   576,
     579,   581,   584,   585,   592,   593,   600,   601,   608,   611,
     612,   615,   618,   619,   624,   625,   631,   634,   635,   636,
     642,   645,   646,   647,   653,   656,   657,   658,   664,   667,
     668,   669,   675,   678,   679,   680,   686,   689,   690,   691,
     697,   700,   701,   703,   706,   708,   709,   714,   715,   721,
     724,   727,   729,   731,   733,   734,   740,   741,   746,   748,
     750,   753,   755,   757,   759,   761,   762,   767,   769,   771,
     773,   775,   777,   779,   781,   783,   785,   787,   789,   791,
     793,   795,   797,   799,   801,   803,   805,   807,   809,   811,
     813,   815,   817,   819,   821,   823,   825,   827,   829,   831,
     833,   835,   837,   839,   841,   843,   845,   847,   849,   851,
     853,   855,   857,   859,   861,   863,   865,   867,   869,   871,
     873,   875,   877,   879,   881,   883,   885,   887,   889,   891,
     893,   895,   897,   899,   901,   903,   905,   907,   909,   911,
     913,   915,   917,   919,   921,   923,   925,   927,   929,   931,
     933,   935,   937,   939,   941,   943,   945,   947,   949,   951,
     953,   955,   957,   959,   961,   963,   965,   967,   969,   971,
     973,   975,   977,   979,   981,   983,   985,   987,   989,   991,
     993,   995,   997,   999,  1001,  1003,  1005,  1007,  1009,  1011,
    1013,  1015,  1017,  1019,  1021,  1023,  1025,  1027,  1029,  1031,
    1033,  1035,  1037,  1039,  1041,  1043,  1045,  1047,  1049,  1051,
    1053,  1055,  1057,  1059,  1061,  1063,  1065,  1067,  1069,  1071,
    1073,  1075,  1077,  1079,  1081,  1082,  1083,  1090,  1091,  1092,
    1099,  1100,  1104,  1105,  1109,  1110,  1115,  1116,  1121,  1122,
    1127,  1128,  1133,  1134,  1138,  1139,  1143,  1148,  1149,  1153,
    1154,  1159,  1160,  1166,  1167,  1173,  1174,  1180,  1181,  1187,
    1192,  1193,  1199,  1200,  1206,  1207,  1213,  1214,  1220,  1224,
    1228,  1229,  1235,  1236,  1242,  1243,  1249,  1250,  1256,  1257,
    1263,  1264,  1270,  1271,  1277,  1278,  1284,  1289,  1295,  1300,
    1301,  1307,  1313,  1319,  1326,  1332,  1338,  1345,  1351,  1357,
    1363,  1369,  1374,  1375,  1376,  1384,  1385,  1386,  1395,  1400,
    1406,  1412,  1418,  1423,  1429,  1432,  1435,  1438,  1441,  1447,
    1452,  1453,  1457,  1459,  1461,  1464,  1467,  1469,  1471,  1473,
    1475,  1477,  1479,  1480,  1482,  1484,  1486,  1488,  1490,  1492,
    1494,  1496,  1498,  1500,  1502,  1504,  1506,  1508,  1510,  1512,
    1514,  1516,  1518,  1520,  1521,  1523,  1524,  1526,  1528,  1530,
    1531,  1536,  1537,  1542,  1543,  1544,  1551,  1553,  1554,  1558,
    1559,  1564,  1565,  1570,  1571,  1575,  1576,  1581,  1583,  1584,
    1588,  1589,  1594,  1596,  1597,  1601,  1602,  1607,  1608,  1613,
    1614,  1618,  1619,  1624,  1626,  1627,  1631,  1632,  1636,  1637,
    1642,  1644,  1645,  1649,  1650,  1655,  1657,  1658,  1662,  1663,
    1668,  1670,  1673,  1674,  1677,  1678,  1681,  1682,  1684,  1686,
    1688,  1690,  1692,  1694,  1696,  1698,  1699,  1704,  1706,  1708,
    1710,  1712,  1714,  1716,  1718,  1719,  1724,  1726,  1728,  1730,
    1732,  1734,  1736,  1737,  1742,  1744,  1746,  1748,  1750,  1752,
    1754,  1756,  1757,  1762,  1764,  1766,  1768,  1770,  1772,  1774,
    1775,  1780,  1782,  1784,  1786,  1788,  1790,  1792,  1793,  1798,
    1800,  1802,  1804,  1806,  1808,  1810,  1811,  1816,  1818,  1820,
    1822,  1824,  1826,  1827,  1832,  1835,  1837,  1839,  1840,  1845,
    1847,  1849,  1851,  1853,  1855,  1857
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     163,     0,    -1,   164,    -1,    -1,   205,    -1,   197,    -1,
     165,    -1,   318,    -1,    -1,   158,   166,     3,    -1,    -1,
      91,   167,     3,    -1,    86,    -1,    -1,    87,   168,     3,
      -1,    -1,    88,   169,     3,    -1,    89,    -1,    -1,    90,
     170,     4,    -1,    92,    -1,    93,    -1,   173,   120,    -1,
     172,   129,   171,    -1,   161,    -1,   173,    -1,   172,   129,
     172,    -1,   174,    -1,   173,   130,   177,    -1,   118,   172,
     119,    -1,    -1,   174,   131,   175,   176,   132,    -1,   300,
      -1,   176,   124,   300,    -1,   300,    -1,    -1,   118,   178,
     179,   119,    -1,   179,   124,   180,    -1,   180,    -1,    97,
     292,   127,   292,    -1,   126,   300,   127,   300,    -1,    99,
     181,   184,   127,   188,   191,    -1,    -1,   300,   182,   278,
      -1,    -1,   118,   183,   274,   119,    -1,   116,   185,   249,
     186,    -1,    -1,   185,   186,    -1,    -1,   292,    -1,    -1,
     122,   187,   253,   123,    -1,    -1,   300,   189,   280,    -1,
      -1,   118,   190,   274,   119,    -1,   122,   192,   123,    -1,
      -1,   192,   193,    -1,   193,    -1,   140,   159,    -1,    -1,
     141,   118,   194,   265,   119,    -1,    -1,   154,   118,   195,
     265,   119,    -1,    -1,   148,   118,   196,     5,   119,    -1,
      -1,    -1,    -1,     8,   198,   300,   111,   172,   199,   127,
     172,   200,   110,   201,    96,    -1,   201,   202,    -1,    -1,
      97,   292,   127,   204,    -1,    -1,    99,   181,   184,   127,
     203,   214,    -1,   292,   120,    -1,   161,    -1,    -1,    -1,
     215,   206,   300,   207,   209,   110,   216,    94,    -1,   120,
      -1,   161,    -1,   131,   210,   132,    -1,    -1,   210,   124,
     211,    -1,   211,    -1,   300,   128,   172,    -1,   161,    -1,
     251,   120,    -1,   212,    -1,   288,   208,    -1,   161,    -1,
       6,    -1,     7,    -1,   216,   217,    -1,    -1,    95,   171,
      -1,    -1,    97,   218,   271,   208,    -1,    -1,    98,   219,
     272,   208,    -1,    99,   241,   247,    -1,    55,   244,   247,
      -1,   101,   240,   116,   213,    -1,    -1,    -1,   104,   220,
     276,   116,   221,   214,    -1,    -1,    -1,    -1,   105,   222,
     276,   116,   223,   286,   115,   224,   214,    -1,    -1,    -1,
     106,   225,   282,   117,   226,   214,    -1,    -1,    -1,    -1,
     107,   227,   282,   117,   228,   286,   115,   229,   214,    -1,
      -1,    -1,   108,   230,   284,   113,   231,   214,    -1,    -1,
      -1,    -1,   109,   232,   284,   113,   233,   286,   115,   234,
     214,    -1,   152,   241,   247,    -1,   100,   244,   247,    -1,
      -1,   102,   300,   235,   237,   120,    -1,    -1,   103,   236,
     272,   208,    -1,     1,   120,    -1,   125,    -1,   125,   238,
      -1,   239,    -1,   238,   124,   239,    -1,   301,   116,   300,
      -1,   240,   306,    -1,   306,    -1,    -1,   300,   242,   276,
      -1,    -1,   118,   243,   274,   119,    -1,   244,   245,    -1,
     245,    -1,   306,    -1,    -1,   118,   246,   274,   119,    -1,
     116,   250,   249,   248,    -1,   251,   254,   120,    -1,   212,
      -1,   112,    -1,   114,    -1,   250,   251,    -1,    -1,   292,
      -1,    -1,   122,   252,   253,   123,    -1,   253,   124,   292,
      -1,   292,    -1,   122,   255,   123,    -1,    -1,   255,   257,
      -1,   257,    -1,   135,    -1,   138,   135,    -1,   139,   135,
      -1,   133,    -1,   134,    -1,    -1,   256,   258,   297,    -1,
     136,    -1,   137,    -1,   140,   159,    -1,    -1,   141,   118,
     259,   265,   119,    -1,    -1,   154,   118,   260,   265,   119,
      -1,    -1,   143,   118,   261,   265,   119,    -1,    -1,   144,
     118,   262,   265,   119,    -1,   145,    -1,   147,    -1,   146,
      -1,    -1,   146,   118,   263,   265,   119,    -1,   150,    -1,
     151,    -1,   152,    -1,   142,   159,    -1,    -1,   148,   118,
     264,     5,   119,    -1,   149,   118,   266,   119,    -1,   153,
      -1,   265,   159,    -1,   159,    -1,   266,   267,    -1,   267,
      -1,   155,   300,    -1,    -1,   155,   300,   118,   268,   274,
     119,    -1,    -1,   156,   300,   118,   269,   274,   119,    -1,
      -1,   157,   300,   118,   270,   274,   119,    -1,   271,   292,
      -1,    -1,   272,   292,    -1,   272,   121,    -1,    -1,   292,
     273,   271,   121,    -1,    -1,   274,   118,   275,   274,   119,
      -1,   274,   300,    -1,    -1,    -1,   276,   118,   277,   274,
     119,    -1,   276,   306,    -1,    -1,    -1,   278,   118,   279,
     274,   119,    -1,   278,   307,    -1,    -1,    -1,   280,   118,
     281,   274,   119,    -1,   280,   308,    -1,    -1,    -1,   282,
     118,   283,   274,   119,    -1,   282,   304,    -1,    -1,    -1,
     284,   118,   285,   274,   119,    -1,   284,   303,    -1,    -1,
      -1,   286,   118,   287,   274,   119,    -1,   286,   305,    -1,
      -1,   289,    -1,   288,   310,    -1,   310,    -1,    -1,   118,
     290,   274,   119,    -1,    -1,   288,   118,   291,   274,   119,
      -1,   289,   313,    -1,   288,   302,    -1,   301,    -1,   293,
      -1,   309,    -1,    -1,   293,   131,   294,   295,   132,    -1,
      -1,   295,   124,   296,   293,    -1,   293,    -1,   298,    -1,
     297,   298,    -1,   312,    -1,   314,    -1,   315,    -1,   120,
      -1,    -1,   118,   299,   274,   119,    -1,   312,    -1,   313,
      -1,   315,    -1,   316,    -1,   120,    -1,   311,    -1,   124,
      -1,   127,    -1,   313,    -1,   315,    -1,   316,    -1,   311,
      -1,   124,    -1,   127,    -1,   315,    -1,   316,    -1,   312,
      -1,   313,    -1,   316,    -1,   120,    -1,   121,    -1,   116,
      -1,   112,    -1,   114,    -1,   117,    -1,   115,    -1,   312,
      -1,   313,    -1,   316,    -1,   120,    -1,   121,    -1,   116,
      -1,   112,    -1,   114,    -1,   113,    -1,   115,    -1,   312,
      -1,   313,    -1,   316,    -1,   120,    -1,   121,    -1,   116,
      -1,   112,    -1,   114,    -1,   117,    -1,   113,    -1,   312,
      -1,   313,    -1,   316,    -1,   120,    -1,   121,    -1,   112,
      -1,   114,    -1,   117,    -1,   113,    -1,   115,    -1,   311,
      -1,   161,    -1,   124,    -1,   313,    -1,   316,    -1,   120,
      -1,   121,    -1,   112,    -1,   114,    -1,   117,    -1,   113,
      -1,   115,    -1,   311,    -1,   161,    -1,   127,    -1,   313,
      -1,   317,    -1,   120,    -1,   123,    -1,   315,    -1,   159,
      -1,   313,    -1,   317,    -1,   117,    -1,   125,    -1,   129,
      -1,   130,    -1,   113,    -1,   115,    -1,   110,    -1,   126,
      -1,   127,    -1,   120,    -1,   161,    -1,   159,    -1,   131,
      -1,   132,    -1,   129,    -1,   130,    -1,   125,    -1,   128,
      -1,   126,    -1,   111,    -1,   110,    -1,   311,    -1,   161,
      -1,   124,    -1,   127,    -1,   152,    -1,   314,    -1,    95,
      -1,    97,    -1,    98,    -1,    99,    -1,    55,    -1,   101,
      -1,   100,    -1,   102,    -1,   103,    -1,   104,    -1,   105,
      -1,   106,    -1,   107,    -1,   108,    -1,   109,    -1,    94,
      -1,    96,    -1,   121,    -1,   116,    -1,   112,    -1,   114,
      -1,   117,    -1,   113,    -1,   115,    -1,   122,    -1,   123,
      -1,   317,    -1,   133,    -1,   134,    -1,   135,    -1,   136,
      -1,   137,    -1,   138,    -1,   139,    -1,   140,    -1,   141,
      -1,   143,    -1,   144,    -1,   145,    -1,   147,    -1,   148,
      -1,   149,    -1,   146,    -1,   142,    -1,   150,    -1,   151,
      -1,   153,    -1,   154,    -1,   155,    -1,   156,    -1,   157,
      -1,    -1,    -1,    31,   319,   401,   320,   399,   120,    -1,
      -1,    -1,    80,   321,   401,   322,   399,   120,    -1,    -1,
       9,   323,   365,    -1,    -1,    79,   324,   365,    -1,    -1,
     362,    11,   325,   365,    -1,    -1,   362,    12,   326,   371,
      -1,    -1,   362,    19,   327,   371,    -1,    -1,   362,    20,
     328,   381,    -1,    -1,    23,   329,   371,    -1,    -1,   361,
     330,   371,    -1,   362,    22,   363,   120,    -1,    -1,    13,
     331,   365,    -1,    -1,   118,   332,   398,   119,    -1,    -1,
      28,   358,   333,   417,   120,    -1,    -1,    28,   359,   334,
     417,   120,    -1,    -1,    48,   358,   335,   417,   120,    -1,
      -1,    35,   360,   336,   417,   120,    -1,    64,    65,   145,
     120,    -1,    -1,    25,     6,   337,   399,   120,    -1,    -1,
      25,    50,   338,   399,   120,    -1,    -1,    25,    53,   339,
     399,   120,    -1,    -1,    25,     8,   340,   399,   120,    -1,
      25,    51,   120,    -1,    25,    52,   120,    -1,    -1,    25,
      54,   341,   399,   120,    -1,    -1,    25,    55,   342,   399,
     120,    -1,    -1,    25,    56,   343,   399,   120,    -1,    -1,
      25,    57,   344,   399,   120,    -1,    -1,    25,    58,   345,
     399,   120,    -1,    -1,    25,    59,   346,   399,   120,    -1,
      -1,    25,    60,   347,   399,   120,    -1,    -1,    25,    61,
     348,   399,   120,    -1,    25,    49,    85,   120,    -1,    25,
      49,   126,    85,   120,    -1,    25,    23,    36,   120,    -1,
      -1,    25,    81,   349,   399,   120,    -1,    24,    25,    62,
     357,   120,    -1,    24,    25,    44,   357,   120,    -1,    24,
      25,    13,    44,   357,   120,    -1,    24,    25,    45,   357,
     120,    -1,    24,    25,    47,   357,   120,    -1,    24,    25,
      13,    45,   357,   120,    -1,    24,    25,    46,   357,   120,
      -1,    24,    25,    42,   357,   120,    -1,    24,    35,   355,
     357,   120,    -1,    24,    28,   356,   357,   120,    -1,    24,
      48,   357,   120,    -1,    -1,    -1,    24,   364,   350,   420,
     351,   357,   120,    -1,    -1,    -1,    24,     7,    68,   352,
     420,   353,   357,   120,    -1,    24,    63,   357,   120,    -1,
      24,    65,   145,   357,   120,    -1,    24,    65,    59,   357,
     120,    -1,    24,    72,    73,   357,   120,    -1,    24,    81,
     357,   120,    -1,    24,    65,    81,   357,   120,    -1,    75,
     120,    -1,    76,   120,    -1,    77,   120,    -1,    78,   120,
      -1,    24,    42,    25,   357,   120,    -1,    24,    44,   357,
     120,    -1,    -1,     1,   354,   120,    -1,    37,    -1,    38,
      -1,    39,    41,    -1,    39,    40,    -1,    36,    -1,    70,
      -1,    82,    -1,    83,    -1,    84,    -1,   154,    -1,    -1,
      33,    -1,    30,    -1,    34,    -1,    31,    -1,    57,    -1,
      58,    -1,    59,    -1,    12,    -1,    29,    -1,    26,    -1,
      27,    -1,    31,    -1,    32,    -1,    69,    -1,    68,    -1,
      70,    -1,    71,    -1,    16,    -1,    15,    -1,    74,    -1,
      -1,    85,    -1,    -1,    66,    -1,    67,    -1,    68,    -1,
      -1,   158,   366,   400,   368,    -1,    -1,   407,   367,   399,
     120,    -1,    -1,    -1,   116,   369,   401,   370,   399,   120,
      -1,   120,    -1,    -1,   122,   372,   375,    -1,    -1,   158,
     373,   400,   368,    -1,    -1,   409,   374,   399,   120,    -1,
      -1,   160,   376,   378,    -1,    -1,   411,   377,   399,   120,
      -1,   120,    -1,    -1,   123,   379,   365,    -1,    -1,   413,
     380,   399,   120,    -1,   120,    -1,    -1,   122,   382,   385,
      -1,    -1,   158,   383,   400,   368,    -1,    -1,   409,   384,
     399,   120,    -1,    -1,   160,   386,   388,    -1,    -1,   411,
     387,   399,   120,    -1,   120,    -1,    -1,   123,   389,   365,
      -1,    -1,   124,   390,   392,    -1,    -1,   415,   391,   399,
     120,    -1,   120,    -1,    -1,   160,   393,   395,    -1,    -1,
     411,   394,   399,   120,    -1,   120,    -1,    -1,   123,   396,
     365,    -1,    -1,   413,   397,   399,   120,    -1,   120,    -1,
     398,   401,    -1,    -1,   399,   403,    -1,    -1,   400,   405,
      -1,    -1,   159,    -1,   160,    -1,   122,    -1,   123,    -1,
     158,    -1,   116,    -1,   120,    -1,   124,    -1,    -1,   118,
     402,   398,   119,    -1,   159,    -1,   160,    -1,   122,    -1,
     123,    -1,   158,    -1,   116,    -1,   124,    -1,    -1,   118,
     404,   398,   119,    -1,   159,    -1,   160,    -1,   122,    -1,
     123,    -1,   158,    -1,   124,    -1,    -1,   118,   406,   398,
     119,    -1,   159,    -1,   160,    -1,   122,    -1,   123,    -1,
     116,    -1,   120,    -1,   124,    -1,    -1,   118,   408,   398,
     119,    -1,   159,    -1,   160,    -1,   123,    -1,   116,    -1,
     120,    -1,   124,    -1,    -1,   118,   410,   398,   119,    -1,
     159,    -1,   122,    -1,   123,    -1,   158,    -1,   116,    -1,
     124,    -1,    -1,   118,   412,   398,   119,    -1,   159,    -1,
     160,    -1,   122,    -1,   158,    -1,   116,    -1,   124,    -1,
      -1,   118,   414,   398,   119,    -1,   159,    -1,   160,    -1,
     122,    -1,   158,    -1,   116,    -1,    -1,   118,   416,   398,
     119,    -1,   417,   418,    -1,   418,    -1,   420,    -1,    -1,
     118,   419,   398,   119,    -1,   159,    -1,   160,    -1,   122,
      -1,   123,    -1,   158,    -1,   116,    -1,   124,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   212,   212,   214,   219,   220,   221,   222,   228,   228,
     238,   238,   248,   252,   252,   263,   263,   274,   285,   285,
     290,   295,   328,   329,   337,   347,   348,   358,   359,   368,
     369,   369,   376,   382,   383,   390,   389,   396,   397,   400,
     404,   408,   411,   411,   416,   416,   423,   424,   427,   428,
     431,   437,   437,   444,   444,   446,   446,   450,   451,   454,
     455,   458,   459,   459,   461,   461,   463,   463,   470,   472,
     479,   470,   494,   495,   498,   502,   502,   506,   507,   520,
     522,   520,   534,   535,   545,   546,   549,   550,   553,   561,
     573,   574,   577,   578,   588,   588,   591,   592,   595,   602,
     602,   605,   605,   608,   610,   612,   614,   615,   614,   618,
     619,   620,   618,   623,   624,   623,   627,   628,   629,   627,
     632,   633,   632,   636,   637,   638,   636,   641,   646,   652,
     651,   658,   658,   661,   672,   673,   676,   677,   680,   685,
     686,   689,   689,   691,   691,   695,   696,   699,   705,   705,
     709,   716,   717,   720,   721,   724,   725,   728,   734,   734,
     741,   742,   745,   746,   749,   750,   753,   757,   761,   767,
     771,   775,   775,   777,   781,   785,   786,   786,   788,   788,
     790,   790,   792,   792,   794,   798,   802,   807,   807,   809,
     813,   817,   821,   825,   825,   827,   828,   834,   835,   838,
     839,   842,   847,   847,   852,   852,   857,   857,   867,   868,
     871,   872,   873,   873,   880,   880,   882,   883,   886,   886,
     888,   889,   892,   892,   894,   895,   898,   898,   900,   901,
     904,   904,   906,   907,   910,   910,   912,   913,   916,   916,
     918,   919,   922,   923,   924,   927,   927,   929,   929,   931,
     932,   933,   939,   951,   952,   952,   956,   956,   958,   964,
     965,   968,   968,   968,   968,   969,   969,   976,   976,   976,
     976,   976,   979,   979,   979,   980,   980,   980,   983,   983,
     983,   984,   984,   987,   987,   987,   987,   988,   988,   988,
     988,   988,   988,   991,   991,   991,   991,   992,   992,   992,
     992,   992,   992,   995,   995,   995,   995,   996,   996,   996,
     996,   996,   996,   999,   999,   999,   999,  1000,  1000,  1000,
    1000,  1000,  1000,  1003,  1003,  1003,  1004,  1004,  1004,  1005,
    1005,  1005,  1005,  1005,  1005,  1008,  1008,  1008,  1009,  1009,
    1009,  1009,  1009,  1012,  1012,  1012,  1013,  1013,  1013,  1013,
    1014,  1014,  1014,  1014,  1014,  1017,  1017,  1023,  1023,  1023,
    1023,  1023,  1023,  1023,  1023,  1024,  1024,  1027,  1027,  1027,
    1027,  1030,  1030,  1033,  1033,  1033,  1033,  1033,  1033,  1034,
    1034,  1034,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,
    1038,  1038,  1038,  1038,  1038,  1038,  1038,  1041,  1041,  1041,
    1044,  1044,  1044,  1044,  1044,  1044,  1044,  1045,  1045,  1045,
    1045,  1045,  1045,  1046,  1046,  1046,  1046,  1047,  1047,  1047,
    1047,  1048,  1048,  1048,  1075,  1076,  1075,  1082,  1083,  1082,
    1091,  1090,  1104,  1103,  1117,  1116,  1130,  1129,  1143,  1142,
    1157,  1156,  1171,  1170,  1184,  1183,  1196,  1201,  1200,  1212,
    1212,  1221,  1221,  1227,  1227,  1233,  1233,  1239,  1239,  1245,
    1253,  1253,  1260,  1260,  1267,  1267,  1274,  1274,  1281,  1285,
    1289,  1289,  1296,  1296,  1303,  1303,  1310,  1310,  1317,  1317,
    1324,  1324,  1331,  1331,  1338,  1338,  1345,  1349,  1353,  1357,
    1357,  1367,  1371,  1375,  1379,  1383,  1387,  1391,  1395,  1399,
    1403,  1407,  1411,  1412,  1411,  1417,  1418,  1417,  1423,  1427,
    1431,  1435,  1439,  1443,  1450,  1454,  1458,  1462,  1469,  1473,
    1480,  1480,  1487,  1488,  1489,  1490,  1491,  1492,  1493,  1494,
    1495,  1496,  1499,  1500,  1501,  1502,  1503,  1504,  1505,  1506,
    1507,  1508,  1511,  1512,  1515,  1516,  1519,  1520,  1523,  1524,
    1527,  1528,  1531,  1532,  1535,  1536,  1539,  1540,  1541,  1549,
    1549,  1551,  1551,  1555,  1556,  1555,  1558,  1567,  1567,  1569,
    1569,  1571,  1571,  1576,  1576,  1578,  1578,  1580,  1585,  1584,
    1590,  1590,  1592,  1601,  1601,  1603,  1603,  1605,  1605,  1610,
    1610,  1612,  1612,  1614,  1619,  1618,  1624,  1624,  1626,  1626,
    1628,  1632,  1632,  1634,  1634,  1636,  1641,  1640,  1647,  1647,
    1649,  1655,  1656,  1659,  1660,  1664,  1665,  1671,  1671,  1671,
    1671,  1671,  1671,  1671,  1671,  1672,  1672,  1676,  1676,  1676,
    1676,  1676,  1676,  1676,  1677,  1677,  1682,  1682,  1682,  1682,
    1682,  1682,  1683,  1683,  1687,  1687,  1687,  1687,  1687,  1687,
    1687,  1688,  1688,  1692,  1692,  1692,  1692,  1692,  1692,  1693,
    1693,  1698,  1698,  1698,  1698,  1698,  1698,  1699,  1699,  1704,
    1704,  1704,  1704,  1704,  1704,  1705,  1705,  1710,  1710,  1710,
    1710,  1710,  1711,  1711,  1718,  1719,  1722,  1728,  1728,  1736,
    1736,  1736,  1736,  1736,  1736,  1736
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
  "fromTypeList", "fromType", "@10", "toOpName", "@11", "@12", 
  "toAttributes", "toAttributeList", "toAttribute", "@13", "@14", "@15", 
  "view", "@16", "@17", "@18", "viewDecList", "viewDeclaration", "@19", 
  "sortDot", "module", "@20", "@21", "dot", "parameters", "parameterList", 
  "parameter", "badType", "typeDot", "endStatement", "startModule", 
  "decList", "declaration", "@22", "@23", "@24", "@25", "@26", "@27", 
  "@28", "@29", "@30", "@31", "@32", "@33", "@34", "@35", "@36", "@37", 
  "@38", "@39", "@40", "classDef", "cPairList", "cPair", "varNameList", 
  "opName", "@41", "@42", "opNameList", "simpleOpName", "@43", 
  "domainRangeAttr", "typeAttr", "arrow", "typeList", "typeName", "@44", 
  "sortNames", "attributes", "attributeList", "idKeyword", "attribute", 
  "@45", "@46", "@47", "@48", "@49", "@50", "@51", "idList", "hookList", 
  "hook", "@52", "@53", "@54", "sortNameList", "subsortList", "@55", 
  "tokens", "@56", "tokensBarColon", "@57", "tokensBarColonTo", "@58", 
  "tokensBarCommaLeft", "@59", "tokensBarEqual", "@60", "tokensBarArrow2", 
  "@61", "tokensBarIf", "@62", "endTokens", "noTrailingDot", "@63", "@64", 
  "sortName", "sortNameFrag", "@65", "sortNameFrags", "@66", "identity", 
  "identityChunk", "@67", "token", "tokenBarDot", "endToken", 
  "tokenBarArrow2", "tokenBarEqual", "tokenBarIf", "tokenBarColon", 
  "tokenBarColonTo", "tokenBarCommaLeft", "sortToken", "endsInDot", 
  "inert", "identifier", "startKeyword", "startKeyword2", "midKeyword", 
  "attrKeyword", "attrKeyword2", "command", "@68", "@69", "@70", "@71", 
  "@72", "@73", "@74", "@75", "@76", "@77", "@78", "@79", "@80", "@81", 
  "@82", "@83", "@84", "@85", "@86", "@87", "@88", "@89", "@90", "@91", 
  "@92", "@93", "@94", "@95", "@96", "@97", "@98", "@99", "@100", "@101", 
  "@102", "@103", "printOption", "traceOption", "polarity", "select", 
  "exclude", "conceal", "match", "optDebug", "optNumber", "importMode", 
  "moduleAndTerm", "@104", "@105", "inEnd", "@106", "@107", 
  "numberModuleTerm", "@108", "@109", "@110", "numberModuleTerm1", "@111", 
  "@112", "numberModuleTerm2", "@113", "@114", "numbersModuleTerm", 
  "@115", "@116", "@117", "numbersModuleTerm1", "@118", "@119", 
  "numbersModuleTerm2", "@120", "@121", "@122", "numbersModuleTerm3", 
  "@123", "@124", "numbersModuleTerm4", "@125", "@126", "cTokens", 
  "cTokensBarDot", "cTokensBarDotColon", "cToken", "@127", "cTokenBarDot", 
  "@128", "cTokenBarDotColon", "@129", "cTokenBarIn", "@130", 
  "cTokenBarLeftIn", "@131", "cTokenBarDotNumber", "@132", 
  "cTokenBarDotRight", "@133", "cTokenBarDotCommaRight", "@134", 
  "cOpNameList", "cSimpleOpName", "@135", "cSimpleTokenBarDot", 0
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
     180,   180,   182,   181,   183,   181,   184,   184,   185,   185,
     186,   187,   186,   189,   188,   190,   188,   191,   191,   192,
     192,   193,   194,   193,   195,   193,   196,   193,   198,   199,
     200,   197,   201,   201,   202,   203,   202,   204,   204,   206,
     207,   205,   208,   208,   209,   209,   210,   210,   211,   212,
     213,   213,   214,   214,   215,   215,   216,   216,   217,   218,
     217,   219,   217,   217,   217,   217,   220,   221,   217,   222,
     223,   224,   217,   225,   226,   217,   227,   228,   229,   217,
     230,   231,   217,   232,   233,   234,   217,   217,   217,   235,
     217,   236,   217,   217,   237,   237,   238,   238,   239,   240,
     240,   242,   241,   243,   241,   244,   244,   245,   246,   245,
     247,   248,   248,   249,   249,   250,   250,   251,   252,   251,
     253,   253,   254,   254,   255,   255,   256,   256,   256,   257,
     257,   258,   257,   257,   257,   257,   259,   257,   260,   257,
     261,   257,   262,   257,   257,   257,   257,   263,   257,   257,
     257,   257,   257,   264,   257,   257,   257,   265,   265,   266,
     266,   267,   268,   267,   269,   267,   270,   267,   271,   271,
     272,   272,   273,   272,   275,   274,   274,   274,   277,   276,
     276,   276,   279,   278,   278,   278,   281,   280,   280,   280,
     283,   282,   282,   282,   285,   284,   284,   284,   287,   286,
     286,   286,   288,   288,   288,   290,   289,   291,   289,   289,
     289,   289,   292,   293,   294,   293,   296,   295,   295,   297,
     297,   298,   298,   298,   298,   299,   298,   300,   300,   300,
     300,   300,   301,   301,   301,   301,   301,   301,   302,   302,
     302,   302,   302,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   308,   308,   308,   308,   308,
     308,   308,   308,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   310,   310,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   312,   312,   312,
     312,   313,   313,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     315,   315,   315,   315,   315,   315,   315,   316,   316,   316,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   319,   320,   318,   321,   322,   318,
     323,   318,   324,   318,   325,   318,   326,   318,   327,   318,
     328,   318,   329,   318,   330,   318,   318,   331,   318,   332,
     318,   333,   318,   334,   318,   335,   318,   336,   318,   318,
     337,   318,   338,   318,   339,   318,   340,   318,   318,   318,
     341,   318,   342,   318,   343,   318,   344,   318,   345,   318,
     346,   318,   347,   318,   348,   318,   318,   318,   318,   349,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   350,   351,   318,   352,   353,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     354,   318,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   357,   357,   358,   358,   359,   359,   360,   360,
     361,   361,   362,   362,   363,   363,   364,   364,   364,   366,
     365,   367,   365,   369,   370,   368,   368,   372,   371,   373,
     371,   374,   371,   376,   375,   377,   375,   375,   379,   378,
     380,   378,   378,   382,   381,   383,   381,   384,   381,   386,
     385,   387,   385,   385,   389,   388,   390,   388,   391,   388,
     388,   393,   392,   394,   392,   392,   396,   395,   397,   395,
     395,   398,   398,   399,   399,   400,   400,   401,   401,   401,
     401,   401,   401,   401,   401,   402,   401,   403,   403,   403,
     403,   403,   403,   403,   404,   403,   405,   405,   405,   405,
     405,   405,   406,   405,   407,   407,   407,   407,   407,   407,
     407,   408,   407,   409,   409,   409,   409,   409,   409,   410,
     409,   411,   411,   411,   411,   411,   411,   412,   411,   413,
     413,   413,   413,   413,   413,   414,   413,   415,   415,   415,
     415,   415,   416,   415,   417,   417,   418,   419,   418,   420,
     420,   420,   420,   420,   420,   420
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     0,     3,
       0,     3,     1,     0,     3,     0,     3,     1,     0,     3,
       1,     1,     2,     3,     1,     1,     3,     1,     3,     3,
       0,     5,     1,     3,     1,     0,     4,     3,     1,     4,
       4,     6,     0,     3,     0,     4,     4,     0,     2,     0,
       1,     0,     4,     0,     3,     0,     4,     3,     0,     2,
       1,     2,     0,     5,     0,     5,     0,     5,     0,     0,
       0,    12,     2,     0,     4,     0,     6,     2,     1,     0,
       0,     8,     1,     1,     3,     0,     3,     1,     3,     1,
       2,     1,     2,     1,     1,     1,     2,     0,     2,     0,
       4,     0,     4,     3,     3,     4,     0,     0,     6,     0,
       0,     0,     9,     0,     0,     6,     0,     0,     0,     9,
       0,     0,     6,     0,     0,     0,     9,     3,     3,     0,
       5,     0,     4,     2,     1,     2,     1,     3,     3,     2,
       1,     0,     3,     0,     4,     2,     1,     1,     0,     4,
       4,     3,     1,     1,     1,     2,     0,     1,     0,     4,
       3,     1,     3,     0,     2,     1,     1,     2,     2,     1,
       1,     0,     3,     1,     1,     2,     0,     5,     0,     5,
       0,     5,     0,     5,     1,     1,     1,     0,     5,     1,
       1,     1,     2,     0,     5,     4,     1,     2,     1,     2,
       1,     2,     0,     6,     0,     6,     0,     6,     2,     0,
       2,     2,     0,     4,     0,     5,     2,     0,     0,     5,
       2,     0,     0,     5,     2,     0,     0,     5,     2,     0,
       0,     5,     2,     0,     0,     5,     2,     0,     0,     5,
       2,     0,     1,     2,     1,     0,     4,     0,     5,     2,
       2,     1,     1,     1,     0,     5,     0,     4,     1,     1,
       2,     1,     1,     1,     1,     0,     4,     1,     1,     1,
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
       1,     1,     1,     1,     0,     0,     6,     0,     0,     6,
       0,     3,     0,     3,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     3,     0,     3,     4,     0,     3,     0,
       4,     0,     5,     0,     5,     0,     5,     0,     5,     4,
       0,     5,     0,     5,     0,     5,     0,     5,     3,     3,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     5,     0,     5,     4,     5,     4,     0,
       5,     5,     5,     6,     5,     5,     6,     5,     5,     5,
       5,     4,     0,     0,     7,     0,     0,     8,     4,     5,
       5,     5,     4,     5,     2,     2,     2,     2,     5,     4,
       0,     3,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     0,     1,     1,     1,     0,
       4,     0,     4,     0,     0,     6,     1,     0,     3,     0,
       4,     0,     4,     0,     3,     0,     4,     1,     0,     3,
       0,     4,     1,     0,     3,     0,     4,     0,     4,     0,
       3,     0,     4,     1,     0,     3,     0,     3,     0,     4,
       1,     0,     3,     0,     4,     1,     0,     3,     0,     4,
       1,     2,     0,     2,     0,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     0,
       4,     1,     1,     1,     1,     1,     1,     0,     4,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     0,     4,     2,     1,     1,     0,     4,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,   520,    94,    95,    68,   430,   447,   551,   550,   442,
       0,     0,     0,   424,     0,     0,     0,   552,     0,     0,
       0,     0,   432,   427,    12,    13,    15,    17,    18,    10,
      20,    21,   449,     8,     0,     2,     6,     5,     4,    79,
       7,   444,     0,     0,     0,     0,     0,     0,     0,     0,
     532,     0,     0,     0,     0,     0,     0,   556,   557,   558,
       0,     0,   502,   460,   466,     0,     0,   462,     0,     0,
     464,   470,   472,   474,   476,   478,   480,   482,   484,   489,
     544,   545,   547,   546,   451,   453,     0,   548,   549,   457,
     455,     0,   514,   515,   516,   517,     0,     0,     0,     0,
       0,     0,   612,     0,     1,     0,     0,   434,   436,   438,
     440,   555,   521,   377,   388,   373,   389,   374,   375,   376,
     379,   378,   380,   381,   382,   383,   384,   385,   386,   387,
     366,   365,   392,   395,   393,   396,   391,   394,   271,   390,
     397,   398,   369,   362,   364,   370,   363,   360,   361,   358,
     359,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     416,   409,   410,   411,   415,   412,   413,   414,   417,   418,
     371,   419,   420,   421,   422,   423,   357,   368,     0,   367,
     267,   268,   372,   269,   270,   399,   648,   651,   649,   646,
     647,   650,   559,   644,   645,   431,   561,   448,   656,   659,
     657,   567,   655,   658,   569,   653,   654,   443,   571,   505,
       0,     0,     0,     0,     0,     0,     0,   540,   541,   534,
     536,   533,   535,   537,   538,   539,     0,   526,   522,   523,
       0,   527,   528,   529,   530,   531,     0,     0,   542,   543,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   614,
     614,     0,     0,     0,   614,   468,   469,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,     0,     0,   622,
     625,   623,   619,   620,   624,   621,   617,   618,   425,     0,
       0,     0,   433,   428,    14,    16,    19,    11,     0,     9,
      80,   445,     0,     0,     0,     0,   554,     0,     0,   612,
     616,   614,   612,     0,   616,   614,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   525,   524,     0,     0,
     519,   501,   508,     0,     0,     0,     0,   512,   694,   691,
     692,   695,   693,   689,   690,   503,     0,     0,   488,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   687,     0,   685,   686,     0,   612,   614,     0,
       0,   459,   614,   450,   611,    85,   435,   437,   439,   583,
     585,   441,   587,   446,     0,    69,    25,    27,    32,     0,
       0,     0,     0,   665,   667,   577,   662,   663,   666,   664,
     661,   573,   568,   575,     0,     0,   506,     0,     0,   498,
     492,   494,   497,   495,   491,   500,   499,   518,   510,   513,
     509,   511,     0,   632,   634,   461,   629,   630,   633,   631,
     627,   628,   613,   467,   487,   463,   465,   471,   473,   475,
     477,   479,   481,   483,   485,   490,   612,   452,   684,   454,
       0,     0,   458,   456,     0,     0,     0,     0,   616,   614,
       0,     0,     0,     0,    30,   652,   563,   642,   566,   638,
     639,   641,   640,   636,   637,   560,   615,   562,   660,   612,
       0,   614,   570,   572,     0,   493,   496,     0,   612,     0,
     626,   426,   429,     0,    87,     0,    97,   593,   589,   584,
     591,     0,     0,    29,    26,     0,    35,    28,     0,     0,
     612,     0,   673,   675,   582,   671,   578,   674,   672,   669,
     670,   574,   580,     0,     0,   504,     0,   688,     0,    84,
       0,     0,     0,   614,   586,   588,    70,     0,     0,    34,
     564,     0,   668,   612,     0,   614,   576,   507,   635,    86,
      88,     0,     0,    81,     0,    99,   101,     0,     0,     0,
       0,   131,   106,   109,   113,   116,   120,   123,     0,    96,
     681,   682,   600,   679,   594,   596,   680,   677,   678,   590,
     598,     0,     0,     0,     0,     0,     0,    38,     0,    31,
     614,   643,     0,   579,     0,   133,   318,   321,   319,   322,
     320,   148,   316,   317,     0,   146,   147,   313,   314,   315,
      24,    98,     0,    25,   209,     0,   143,     0,   141,     0,
       0,   140,   129,     0,   221,   221,   233,   233,   237,   237,
       0,   612,     0,     0,   614,   592,    73,   352,   350,   351,
     346,   347,   353,   354,   348,   349,   343,     0,   252,   253,
     344,   345,    44,    47,    42,     0,    36,     0,    33,     0,
     676,   581,   217,   156,   145,   104,     0,    22,     0,     0,
     212,   217,   103,   221,   128,     0,   139,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,   595,   605,   601,
     597,   603,     0,     0,     0,   254,   217,    49,     0,   225,
       0,    37,   565,     0,     0,    23,    26,    82,    83,   100,
     208,   211,   102,   210,   209,     0,   142,   158,    89,    91,
     105,     0,   157,   134,     0,   132,   107,   218,   220,   110,
     299,   301,   300,   302,   298,   114,   230,   296,   297,   232,
     293,   294,   295,   117,   289,   121,   290,   292,   288,   291,
     234,   286,   287,   236,   283,   284,   285,   124,   683,     0,
     614,   599,    71,     0,     0,    72,    39,     0,     0,     0,
       0,    43,    40,   214,   149,   216,   153,   154,     0,   155,
       0,   144,     0,    90,   273,   274,   135,   136,     0,   272,
     275,   276,   277,   130,     0,   217,   241,     0,   217,   241,
       0,   217,   241,   610,   606,   602,   608,     0,     0,    47,
     258,     0,    45,    51,    48,     0,    50,    55,    58,    53,
     330,   333,   331,   334,   332,   222,   328,   329,   325,   324,
     224,   323,   326,   327,   217,   152,   150,   163,   213,     0,
     161,     0,     0,   245,   355,   356,   108,     0,   242,   251,
     244,     0,     0,   115,     0,     0,   122,     0,     0,     0,
     614,   604,     0,     0,   256,   255,     0,    46,   217,     0,
      41,   229,   217,     0,     0,     0,   159,     0,   137,   138,
     217,   247,   355,   279,   280,   356,    92,   250,   243,   278,
     281,   282,   249,   219,   309,   312,   310,   111,   308,   311,
     238,   306,   307,   240,   303,   304,   305,   231,   118,   235,
     125,   607,     0,    78,    74,     0,    75,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    54,     0,   215,   169,
     170,   166,   173,   174,     0,     0,     0,     0,     0,     0,
       0,   184,   186,   185,     0,     0,   189,   190,   191,   196,
       0,     0,   171,   165,   151,   160,     0,   217,     0,   217,
       0,     0,   609,    77,     0,   257,    52,    56,    61,    62,
      66,    64,    57,    59,   226,   340,   341,   337,   336,   228,
     335,   338,   342,   339,   223,   167,   168,   175,   176,   192,
     180,   182,   187,   193,     0,   178,   162,   164,     0,   246,
       0,   112,     0,   119,   126,    76,     0,     0,     0,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,   265,   264,   172,   259,   261,   262,   263,   248,   239,
     198,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,     0,     0,   195,   199,     0,   217,   260,    63,   197,
      67,    65,   227,   177,   181,   183,   188,   194,   202,   204,
     206,   179,     0,   217,   217,   217,   266,     0,     0,     0,
     203,   205,   207
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    34,    35,    36,   103,   101,    98,    99,   100,   601,
     375,   376,   377,   498,   528,   497,   527,   576,   577,   643,
     689,   686,   688,   759,   804,   856,   808,   861,   858,   860,
     914,   915,   996,   998,   997,    37,    44,   452,   572,   683,
     755,   954,   904,    38,   105,   365,   699,   446,   483,   484,
     709,   710,   836,    39,   521,   559,   604,   605,   614,   784,
     615,   786,   948,   616,   787,   617,   789,   950,   618,   790,
     619,   792,   951,   667,   613,   714,   776,   777,   610,   607,
     663,   661,   594,   595,   652,   655,   826,   768,   694,   711,
     772,   829,   865,   941,   942,   943,   988,  1000,  1010,  1001,
    1002,  1003,  1004,  1021,  1008,  1009,  1053,  1054,  1055,   658,
     659,   704,   693,   824,   669,   785,   761,   862,   916,   999,
     671,   788,   673,   791,   842,   949,   837,   838,   870,   947,
     712,   638,   757,   801,   907,  1013,  1014,  1036,   765,   839,
     877,   743,   729,   893,   596,   820,   969,   639,   840,   179,
     180,   181,   182,   183,   184,   185,    40,    86,   358,    97,
     362,    45,    96,   292,   293,   294,   295,    47,   106,    46,
     102,   267,   268,   280,   279,   249,   254,   257,   250,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   248,   412,
     306,   474,    43,   236,   226,   240,    84,    85,    89,    41,
      42,   297,    62,   195,   300,   301,   465,   499,   580,   207,
     303,   304,   305,   392,   470,   471,   511,   534,   535,   371,
     447,   448,   449,   489,   522,   523,   569,   622,   623,   624,
     680,   749,   750,   795,   849,   850,   288,   336,   380,   364,
     357,   422,   478,   466,   500,   196,   299,   208,   302,   393,
     469,   512,   533,   570,   621,   353,   354,   436,   355
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -937
static const short yypact[] =
{
     758,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    5811,   889,    89,  -937,   134,   210,   -21,  -937,   -58,   -39,
     -37,    -9,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,    76,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,   177,    -5,  4278,   211,   211,   591,    49,    28,
      73,     9,    97,   245,   245,   245,   -27,  -937,  -937,  -937,
      53,   245,  -937,  -937,  -937,    93,   -42,  -937,    13,    54,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  5727,  -937,  -937,  -937,
    -937,     7,  -937,  -937,  -937,  -937,   211,  5727,   173,   183,
     187,   205,  -937,   219,  -937,  4278,   591,  -937,  -937,  -937,
    -937,   144,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,   127,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
     237,   245,   245,   245,   245,   245,   245,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,   245,  -937,  -937,  -937,
     254,  -937,  -937,  -937,  -937,  -937,   245,   245,  -937,  -937,
     126,   128,   130,   245,   245,   245,   245,   139,    12,  -937,
    -937,   141,   156,   199,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  6460,  6460,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  6460,
    6460,   168,  -937,  -937,  -937,  -937,  -937,  -937,   133,  -937,
    -937,  -937,   211,   591,   591,  5845,  -937,   194,  2630,  -937,
    -937,  -937,  -937,  5854,  -937,  -937,    12,   245,   245,   195,
     196,   200,   204,   206,   208,   216,  -937,  -937,   218,   221,
    -937,  -937,  -937,   226,   227,   228,   231,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  5899,  5908,  -937,  -937,
     232,  5917,  5926,  5971,  5980,  5989,  5998,  6043,  6052,  6061,
    6070,  6115,  -937,  6124,  -937,  -937,  6133,  -937,  -937,  6142,
    6187,  -937,  -937,  -937,  -937,   155,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  2630,   178,   209,   222,  -937,   426,
    6196,  6205,   451,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  6196,  6214,  -937,   234,   235,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,   245,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
     499,  6259,  -937,  -937,  6268,  4278,   247,  6277,  -937,  -937,
     -41,  2630,   239,   249,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    6286,  -937,  -937,  -937,   245,  -937,  -937,   248,  -937,   580,
    -937,  -937,  -937,    32,  -937,   244,  -937,  -937,  -937,  -937,
    -937,  6196,  6331,  -937,  -937,  2630,  -937,  -937,  4278,  5727,
    -937,  5234,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  6340,   261,  -937,  5337,  -937,  4278,  -937,
    2630,   820,  6349,  -937,  -937,  -937,   178,    88,    43,  -937,
    -937,  5703,  -937,  -937,   211,  -937,  -937,  -937,  -937,  -937,
     178,   264,  4381,  -937,  2733,  -937,  -937,  2836,  4381,  4690,
    4278,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  2836,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  6358,   276,  5642,  2939,  4278,   -69,  -937,  4278,  -937,
    -937,  -937,  5827,  -937,  6403,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  3042,  -937,  -937,  -937,  -937,  -937,
     138,  -937,   258,    25,  -937,  5642,  -937,   272,  -937,  3042,
    4484,  -937,  -937,  5642,  -937,  -937,  -937,  -937,  -937,  -937,
     272,  -937,   211,  6412,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,   263,   243,  -937,
    -937,  -937,  -937,   275,  -937,   265,  -937,    88,  -937,  6421,
    -937,  -937,  -937,  -937,  -937,  -937,  2733,  -937,  5002,  4934,
    -937,  -937,  -937,  -937,  -937,  5070,  -937,   268,  4934,  3145,
    3248,  3351,  3454,  3557,  3660,  -937,  5836,  -937,  -937,  -937,
    -937,  -937,  6430,   166,  5642,  -937,  -937,  -937,   267,  -937,
    4278,  -937,  -937,   879,  5377,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,   982,  4587,  -937,  -937,  -937,
    -937,   278,  -937,  5274,   279,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  6475,
    -937,  -937,  -937,  5642,  2939,  -937,  -937,  5642,  1085,  5443,
    3763,  4793,  -937,  -937,  -937,  -937,  -937,  -937,  5070,  -937,
    5509,  -937,  5642,  -937,  -937,  -937,   281,  -937,   284,  -937,
    -937,  -937,  -937,  -937,  3866,  -937,  -937,  3866,  -937,  -937,
    3866,  -937,  -937,  -937,  -937,  -937,  -937,  6484,   282,   275,
     243,   111,  -937,  -937,  -937,  5576,  -937,  -937,   280,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,   286,  -937,   179,
    -937,  5274,  4278,  -937,  -937,   624,  -937,  5783,  5708,  -937,
    -937,  1188,  3969,  -937,  1291,  4072,  -937,  1394,  4175,   211,
    -937,  -937,  5138,   285,  -937,  -937,  5642,  -937,  -937,    80,
    -937,  -937,  -937,  1497,  1011,   283,  -937,  5642,  -937,  -937,
    -937,  -937,   759,  -937,  -937,   784,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  6493,  -937,  -937,   291,  -937,  5642,   189,  1600,
     256,   288,   295,   298,    77,  -937,  4865,  1703,  -937,  -937,
    -937,  -937,  -937,  -937,   289,   290,   259,   299,   260,   302,
     303,  -937,   305,  -937,   308,   312,  -937,  -937,  -937,  -937,
     313,   916,  -937,  -937,  -937,  -937,  1806,  -937,  3866,  -937,
    3866,  3866,  -937,  -937,  3866,   243,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,   142,  -937,  -937,  -937,  5206,  -937,
    1909,  -937,  2012,  -937,  -937,  -937,   273,   428,   273,  -937,
     273,   273,   273,   273,   429,  4278,  4278,  4278,   -18,  -937,
     273,  -937,  -937,  5206,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,   -79,   317,   -70,  2115,   -63,   -61,   -60,   -51,   318,
     320,   321,   324,  -937,  -937,   -50,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  2218,  -937,  -937,  -937,  -937,  2321,  2424,  2527,
    -937,  -937,  -937
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -213,
    -351,  -516,  -937,  -937,  -937,  -937,  -937,  -937,  -202,  -308,
    -937,  -937,  -352,  -937,  -356,  -937,  -937,  -937,  -937,  -937,
    -937,  -461,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -630,  -937,  -937,   -56,
    -313,  -937,  -724,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -373,  -937,   -98,
    -937,  -937,   -84,  -497,  -937,  -466,  -937,  -293,  -937,  -663,
    -937,  -386,  -937,  -937,  -937,  -470,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -692,  -937,  -536,  -937,  -937,  -937,  -231,
    -134,  -937,  -626,  -937,  -581,  -937,  -937,  -937,  -937,  -937,
    -137,  -937,  -136,  -937,  -725,  -937,  -937,  -937,  -937,  -937,
    -191,  -754,  -937,  -937,  -937,  -937,  -531,  -937,   -44,  -708,
    -937,  -937,  -937,  -937,  -545,  -937,  -937,  -937,  -353,  -571,
    -523,  -309,  -936,  -671,  -153,  -104,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,   -34,   470,  -937,  -937,  -937,
    -937,  -937,  -937,   -45,  -937,  -937,  -364,  -937,  -937,   -99,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,  -937,
    -937,  -937,  -937,  -937,  -937,  -937,  -263,  -248,  -280,   -64,
    -937,  -937,  -937,  -937,  -937,  -937,  -937,   191,  -937,  -439,
    -937,  -262,  -937,  -937,  -937,    10,   -16,  -937,  -211
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -554
static const short yytable[] =
{
     178,   197,   337,   800,   611,   778,   341,   291,   490,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   597,
     241,   242,   278,   450,   394,   597,   597,   247,   603,   702,
     472,   769,   243,   283,   670,   705,   379,   335,   715,   382,
    1038,   210,   781,   252,    91,   227,   228,   229,   230,  1041,
     646,   282,  1016,   381,   244,   647,  1043,   395,  1044,  1045,
     758,   290,    92,   843,   845,   666,   846,   848,  1046,  1051,
     211,   597,   212,   213,   214,   215,   104,  1016,   493,   231,
    1039,    93,   706,    94,   253,   217,   597,   597,   451,  1039,
     216,   232,   233,   234,   440,   396,  1039,   654,  1039,  1039,
     494,  1033,   218,   219,   220,   827,   221,   222,  1039,  1039,
     441,    95,   654,   781,   444,   112,   781,   209,   245,   781,
      80,    81,   237,   778,   718,   718,   246,   524,   328,   251,
     223,   224,   225,   255,   329,   330,   331,  1005,  1006,  1007,
     603,   662,   779,   664,   526,   657,   597,   597,   730,   730,
     744,   744,   281,   955,   675,   453,   518,    82,    83,   841,
     781,   718,   844,   235,   519,   847,   880,   578,   491,   540,
     332,   333,   334,   479,   256,   579,   284,   309,   310,   311,
     312,   313,   314,   597,   681,   573,   285,   574,   107,   108,
     821,   286,   315,   602,   367,   368,   109,   110,   863,   111,
     962,   492,   318,   319,    87,    88,   501,   876,   287,   323,
     324,   325,   326,   779,   575,   516,   779,   910,   911,   779,
     910,   911,   289,   513,   991,   912,   993,   994,   912,   296,
     995,   913,   909,   598,   913,   854,   917,   531,   298,   598,
     598,    80,    81,   855,   946,   972,   320,   366,   321,   269,
     322,   270,   363,   271,   378,   272,   273,   274,  -368,   327,
     779,   338,   752,   753,   640,   754,   879,  -368,  -368,  -368,
     582,   238,   239,   397,   398,   571,   339,   781,   356,   781,
     781,   307,   308,   781,   340,   598,   445,   584,   361,   359,
     360,   275,   276,   277,   316,   317,   640,  1005,  1006,  1007,
     598,   598,   866,   867,   640,   696,  1023,   451,  1025,  1026,
    1027,  1028,   956,   867,   373,   399,   400,  1017,  1035,   894,
     401,   990,   894,   992,   402,   894,   403,   186,   404,   187,
     378,   188,   649,   189,   190,   191,   405,   438,   406,   453,
     438,   407,  1017,   438,   438,   970,   408,   409,   410,   640,
     640,   411,   424,   454,   475,   476,   640,   486,   676,   640,
     598,   598,   731,   731,   745,   745,   495,   496,   515,   192,
     193,   194,   520,  1024,   685,   640,   682,   779,   477,   779,
     779,   537,   637,   779,   585,   640,   626,   656,   653,   599,
     684,   687,   690,   713,   760,   599,   599,   598,   773,   783,
     832,   485,   859,   944,   780,   831,   959,   378,   864,   852,
    1052,   953,   906,   960,   660,   958,   961,   978,   977,   979,
     980,   981,   660,   982,   975,   976,   983,  1057,  1058,  1059,
     984,   985,  1020,  1022,  1029,   530,  1040,  1047,  1048,  1049,
     514,   599,  1050,   695,   640,   691,   799,   853,   640,   857,
     640,   378,   822,   963,   529,   825,   599,   599,   868,   640,
     620,   640,   539,   640,   609,  1015,   805,   700,   703,   641,
     908,   987,  1034,   770,   485,   780,   378,   703,   780,   668,
     672,   780,  1037,   674,   878,    90,   372,   796,     0,   583,
    1015,     0,     0,   756,     0,     0,   640,     0,     0,     0,
     378,   641,   797,   608,     0,     0,   612,     0,     0,   641,
       0,     0,     0,     0,   608,     0,   599,   599,   732,   732,
     746,   746,   780,     0,     0,     0,     0,     0,     0,   882,
     644,   645,     0,   895,   648,     0,   895,     0,     0,   895,
       0,     0,   269,   640,   270,   455,   271,   640,   272,   273,
     274,     0,     0,   599,   641,   641,     0,     0,   640,     0,
     782,   641,   798,     0,   641,     0,     0,   269,   806,   270,
     468,   271,     0,   272,   273,   274,     0,   677,     0,   700,
     641,   830,     0,     0,   275,   276,   277,     0,     0,     0,
     641,     0,     0,     0,     0,     0,     0,     0,   640,     0,
       0,     0,   902,     0,     0,     0,     0,   971,   823,   275,
     276,   277,   378,     0,   806,   269,     0,   270,   480,   271,
       0,   272,   273,   274,     0,   -93,     0,     0,     0,     0,
       0,   782,     0,     0,   782,     0,     0,   782,     0,   780,
       0,   780,   780,     0,     0,   780,   762,     0,     0,   641,
       0,     0,     0,   641,     0,   641,     0,   275,   276,   277,
       0,   905,     0,     0,   641,   830,   641,     0,   641,     0,
       0,     0,     0,     0,     0,     0,   945,     0,   782,   -93,
       0,     0,     0,     0,   881,     0,     0,     0,     0,   896,
       0,     0,   896,     0,     0,   896,   269,     0,   270,   517,
     271,   641,   272,   273,   274,     0,     0,   198,     0,   199,
     644,   200,     0,   201,   202,   203,   809,     0,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,     0,     0,     0,     0,   275,   276,
     277,     0,     0,     0,     0,     0,     0,     0,   641,   204,
     205,   206,   641,     0,     0,     0,     0,     0,    -3,     1,
     -82,     0,     0,   641,     2,     3,     4,     5,     0,  -553,
    -553,     6,     0,     7,     8,     0,   -93,  -553,  -553,     0,
    -553,     9,    10,    11,     0,   -83,    12,     0,   869,    13,
       0,     0,     0,    14,     0,   782,     0,   782,   782,     0,
       0,   782,     0,   641,   901,     0,    15,     0,     0,     0,
       0,     0,   973,     0,   -82,     0,     0,     0,     0,     0,
       0,   541,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,    21,    22,    23,   -83,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,     0,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,     0,
       0,     0,     0,     0,     0,   542,    32,     0,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,     0,    63,     0,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -82,    65,     0,   543,   544,    33,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
       0,     0,     0,     0,   113,     0,   -83,     0,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1030,  1031,  1032,     0,     0,     0,     0,     0,     0,
      79,     0,   558,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   763,   764,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   113,   176,   986,
     177,     0,     0,     0,     0,     0,     0,     0,     0,   919,
     920,   921,   922,   923,   924,   925,   926,   927,   928,   929,
     930,   931,   932,   933,   934,   935,   936,   937,   938,   939,
     940,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     763,   771,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     113,   176,     0,   177,   919,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,   930,   931,   932,   933,   934,
     935,   936,   937,   938,   939,   940,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   763,   802,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   113,   176,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   763,   883,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   113,   176,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   763,
     897,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   113,
     176,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   763,   899,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   113,   176,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   763,   918,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   113,   176,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   763,   957,
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
     137,   763,   974,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   113,   176,     0,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   763,   989,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   113,   176,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   763,  1018,   138,
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
     763,  1019,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     113,   176,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   763,  1042,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   113,   176,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   763,  1056,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   113,   176,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   763,
    1060,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   113,
     176,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   763,  1061,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   113,   176,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   763,  1062,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   113,   176,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   374,     0,
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
     175,   113,   176,     0,   600,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   606,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   113,   176,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   642,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   113,   176,     0,
     177,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   586,   587,   588,   589,   653,   590,
     591,     0,   592,   593,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     113,   176,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   586,   587,   588,
     589,   716,   590,   717,     0,   592,   593,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   113,   176,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     586,   587,   588,   589,   719,   590,   717,     0,   592,   593,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   113,   176,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   720,   721,   722,   723,   724,   725,   726,
       0,   727,   728,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   113,
     176,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   720,   721,   722,   723,
     724,   733,   726,     0,   727,   728,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   113,   176,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   734,
     735,   736,   737,   738,   739,   740,     0,   741,   742,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   113,   176,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   734,   747,   736,   737,   738,   739,   740,     0,
     741,   742,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   113,   176,
       0,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   807,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   113,   176,     0,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   833,     0,   834,   139,   140,   141,
     774,   143,   144,   775,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   113,   176,     0,   835,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   884,   885,   886,   887,   888,   889,   890,     0,   891,
     892,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   113,   176,     0,
     177,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   884,   885,   886,   898,   888,   889,
     890,     0,   891,   892,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     113,   176,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   884,   885,   886,
     900,   888,   889,   890,     0,   891,   892,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   113,   176,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   113,   176,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   586,   587,   588,   589,     0,   590,   591,
       0,   592,   593,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   113,
     176,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   586,   587,   588,   589,
     665,   590,     0,     0,   592,   593,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   113,   176,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   586,
     587,   588,   589,     0,   590,   717,     0,   592,   593,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   113,   176,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   586,   587,   588,   589,     0,   590,     0,     0,
     592,   593,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   113,   176,
       0,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   810,   811,   812,   813,     0,
     814,   815,     0,   816,   817,   140,   141,   818,   143,   144,
     113,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,     0,   176,     0,   819,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   964,     0,   965,   139,     0,   966,   113,
     143,   144,   967,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,     0,   176,     0,   968,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   627,     0,     0,   628,     0,   629,
       0,   630,     0,     0,   697,   701,     0,   113,     0,   631,
     632,   633,     0,   634,   635,     0,     0,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   636,     0,   698,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   627,     0,     0,   628,     0,   629,     0,   630,
       0,     0,   697,     0,     0,   113,     0,   631,   632,   633,
       0,   634,   635,     0,     0,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   636,     0,   698,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     627,     0,     0,   628,     0,   629,     0,   630,     0,     0,
       0,     0,   707,   113,     0,   631,   632,   633,     0,   634,
     635,     0,     0,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   636,
       0,   708,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   627,     0,
       0,   628,     0,   629,     0,   630,     0,     0,     0,     0,
       0,   113,     0,   631,   632,   633,     0,   634,   635,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   636,     0,   903,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,  1011,     0,  1012,   139,     0,   113,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     269,     0,   270,   532,   271,     0,   272,   273,   274,     0,
       0,     0,     0,     0,     0,   176,     0,   177,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   275,   276,   277,   139,   140,   141,   774,   143,
     144,   775,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   113,   176,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,     0,   270,   538,   271,     0,   272,
     273,   274,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   627,     0,   766,
     628,   767,   629,     0,   630,   275,   276,   277,   113,   707,
       0,     0,   631,   632,   633,     0,   634,   635,     0,     0,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,     0,   636,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   627,     0,   766,   628,   767,   629,     0,
     630,     0,     0,     0,   113,   803,     0,     0,   631,   632,
     633,     0,   634,   635,     0,     0,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,     0,   636,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   627,
       0,     0,   628,     0,   629,     0,   630,     0,     0,     0,
     828,   113,     0,     0,   631,   632,   633,     0,   634,   635,
       0,     0,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     0,   636,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   627,     0,     0,   628,
       0,   629,     0,   630,     0,     0,     0,   113,   803,     0,
       0,   631,   632,   633,     0,   634,   635,     0,     0,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   636,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   627,     0,     0,   628,     0,   629,     0,   630,
       0,     0,     0,   113,     0,     0,     0,   631,   632,   633,
       0,   634,   635,     0,     0,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   636,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    48,   269,
       0,   270,   581,   271,     0,   272,   273,   274,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,    50,
       0,     0,     0,   269,     0,   270,    51,   271,     0,   272,
     273,   274,     0,    52,     0,    53,     0,     0,     0,    54,
     170,   275,   276,   277,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    56,    57,    58,    59,
       0,     0,     0,    60,     0,   275,   276,   277,     0,     0,
       0,     0,    61,   130,   131,   132,   133,   134,   135,   136,
     137,   871,     0,   872,   139,   140,   141,   873,   143,   144,
     874,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     0,   171,   172,   173,   174,
     175,     0,   176,   269,   875,   270,   650,   271,     0,   272,
     273,   274,   269,     0,   270,   748,   271,     0,   272,   273,
     274,   198,     0,   199,     0,   200,     0,   369,   202,   203,
     383,     0,   384,     0,   385,     0,   386,   387,   388,     0,
       0,     0,     0,     0,     0,   275,   276,   277,     0,     0,
       0,     0,     0,     0,   275,   276,   277,     0,     0,     0,
       0,     0,     0,   370,   205,   206,     0,     0,     0,     0,
       0,     0,   389,   390,   391,   413,     0,   414,     0,   415,
       0,   416,   417,   418,   413,     0,   414,     0,   423,     0,
     416,   417,   418,   413,     0,   414,     0,   425,     0,   416,
     417,   418,   413,     0,   414,     0,   426,     0,   416,   417,
     418,     0,     0,     0,     0,     0,     0,   419,   420,   421,
       0,     0,     0,     0,     0,     0,   419,   420,   421,     0,
       0,     0,     0,     0,     0,   419,   420,   421,     0,     0,
       0,     0,     0,     0,   419,   420,   421,   413,     0,   414,
       0,   427,     0,   416,   417,   418,   413,     0,   414,     0,
     428,     0,   416,   417,   418,   413,     0,   414,     0,   429,
       0,   416,   417,   418,   413,     0,   414,     0,   430,     0,
     416,   417,   418,     0,     0,     0,     0,     0,     0,   419,
     420,   421,     0,     0,     0,     0,     0,     0,   419,   420,
     421,     0,     0,     0,     0,     0,     0,   419,   420,   421,
       0,     0,     0,     0,     0,     0,   419,   420,   421,   413,
       0,   414,     0,   431,     0,   416,   417,   418,   413,     0,
     414,     0,   432,     0,   416,   417,   418,   413,     0,   414,
       0,   433,     0,   416,   417,   418,   413,     0,   414,     0,
     434,     0,   416,   417,   418,     0,     0,     0,     0,     0,
       0,   419,   420,   421,     0,     0,     0,     0,     0,     0,
     419,   420,   421,     0,     0,     0,     0,     0,     0,   419,
     420,   421,     0,     0,     0,     0,     0,     0,   419,   420,
     421,   413,     0,   414,     0,   435,     0,   416,   417,   418,
     328,     0,   352,     0,   437,     0,   329,   330,   331,   328,
       0,   352,     0,   439,     0,   329,   330,   331,   328,     0,
     352,     0,   442,     0,   329,   330,   331,     0,     0,     0,
       0,     0,     0,   419,   420,   421,     0,     0,     0,     0,
       0,     0,   332,   333,   334,     0,     0,     0,     0,     0,
       0,   332,   333,   334,     0,     0,     0,     0,     0,     0,
     332,   333,   334,   328,     0,   352,     0,   443,     0,   329,
     330,   331,   456,     0,   457,     0,   458,     0,   459,   460,
     461,   413,     0,   414,     0,   467,     0,   416,   417,   418,
     413,     0,   414,     0,   473,     0,   416,   417,   418,     0,
       0,     0,     0,     0,     0,   332,   333,   334,     0,     0,
       0,     0,     0,     0,   462,   463,   464,     0,     0,     0,
       0,     0,     0,   419,   420,   421,     0,     0,     0,     0,
       0,     0,   419,   420,   421,   413,     0,   414,     0,   481,
       0,   416,   417,   418,   413,     0,   414,     0,   482,     0,
     416,   417,   418,   383,     0,   384,     0,   487,     0,   386,
     387,   388,   502,     0,   503,     0,   504,     0,   505,   506,
     507,     0,     0,     0,     0,     0,     0,   419,   420,   421,
       0,     0,     0,     0,     0,     0,   419,   420,   421,     0,
       0,     0,     0,     0,     0,   389,   390,   488,     0,     0,
       0,     0,     0,     0,   508,   509,   510,   413,     0,   414,
       0,   525,     0,   416,   417,   418,   413,     0,   414,     0,
     536,     0,   416,   417,   418,   560,     0,   561,     0,   562,
       0,   563,   564,   565,   413,     0,   414,     0,   625,     0,
     416,   417,   418,     0,     0,     0,     0,     0,     0,   419,
     420,   421,     0,     0,     0,     0,     0,     0,   419,   420,
     421,     0,     0,     0,     0,     0,     0,   566,   567,   568,
       0,     0,     0,     0,     0,     0,   419,   420,   421,   413,
       0,   414,     0,   651,     0,   416,   417,   418,   383,     0,
     384,     0,   678,     0,   386,   387,   388,   413,     0,   414,
       0,   692,     0,   416,   417,   418,   413,     0,   414,     0,
     751,     0,   416,   417,   418,     0,     0,     0,     0,     0,
       0,   419,   420,   421,     0,     0,     0,     0,     0,     0,
     389,   390,   679,     0,     0,     0,   328,     0,   352,   419,
     420,   421,   329,   330,   331,     0,     0,     0,   419,   420,
     421,   502,     0,   503,     0,   793,     0,   505,   794,   507,
     413,     0,   414,     0,   851,     0,   416,   417,   418,   413,
       0,   414,     0,   952,     0,   416,   417,   418,   332,   333,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   508,   509,   510,     0,     0,     0,     0,
       0,     0,   419,   420,   421,     0,     0,     0,     0,     0,
       0,   419,   420,   421
};

static const short yycheck[] =
{
      44,    46,   250,   757,   549,   713,   254,   106,   447,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   542,
      54,    55,    86,   374,   304,   548,   549,    61,   544,   659,
     394,   694,    59,    97,   615,   661,   299,   248,   668,   302,
     119,    13,   713,    85,    65,    36,    37,    38,    39,   119,
     119,    96,   988,   301,    81,   124,   119,   305,   119,   119,
     686,   105,   120,   787,   789,   610,   790,   792,   119,   119,
      42,   594,    44,    45,    46,    47,     0,  1013,   119,    70,
     159,   120,   663,   120,   126,    12,   609,   610,   129,   159,
      62,    82,    83,    84,   357,   306,   159,   594,   159,   159,
     451,   119,    29,    30,    31,   768,    33,    34,   159,   159,
     358,   120,   609,   784,   362,   120,   787,    68,   145,   790,
      31,    32,    25,   831,   669,   670,    73,   491,   116,    36,
      57,    58,    59,   120,   122,   123,   124,   155,   156,   157,
     656,   607,   713,   609,   495,   120,   669,   670,   671,   672,
     673,   674,   145,   907,   620,   130,   124,    68,    69,   785,
     831,   706,   788,   154,   132,   791,   837,   124,   448,   520,
     158,   159,   160,   436,   120,   132,     3,   211,   212,   213,
     214,   215,   216,   706,   623,    97,     3,    99,    11,    12,
     761,     4,   226,   544,   293,   294,    19,    20,   824,    22,
     123,   449,   236,   237,    70,    71,   469,   837,     3,   243,
     244,   245,   246,   784,   126,   478,   787,   140,   141,   790,
     140,   141,     3,   471,   948,   148,   950,   951,   148,    85,
     954,   154,   858,   542,   154,   124,   862,   500,   111,   548,
     549,    31,    32,   132,   870,   916,   120,   292,   120,   116,
     120,   118,   119,   120,   298,   122,   123,   124,   120,   120,
     831,   120,    96,    97,   573,    99,   837,   129,   130,   131,
     533,    26,    27,   307,   308,   523,   120,   948,   268,   950,
     951,    44,    45,   954,    85,   594,   131,   535,   120,   279,
     280,   158,   159,   160,    40,    41,   605,   155,   156,   157,
     609,   610,   123,   124,   613,   656,   998,   129,  1000,  1001,
    1002,  1003,   123,   124,   120,   120,   120,   988,  1010,   842,
     120,   947,   845,   949,   120,   848,   120,   116,   120,   118,
     374,   120,   580,   122,   123,   124,   120,   353,   120,   130,
     356,   120,  1013,   359,   360,   916,   120,   120,   120,   658,
     659,   120,   120,   131,   120,   120,   665,   110,   621,   668,
     669,   670,   671,   672,   673,   674,   127,   118,   120,   158,
     159,   160,   128,   999,   131,   684,   624,   948,   412,   950,
     951,   120,   573,   954,   120,   694,   110,   129,   116,   542,
     127,   116,   127,   125,   127,   548,   549,   706,   120,   120,
     116,   445,   122,   120,   713,   124,   118,   451,   122,   127,
    1036,   120,   127,   118,   605,   159,   118,   118,   159,   159,
     118,   118,   613,   118,   135,   135,   118,  1053,  1054,  1055,
     118,   118,   159,     5,     5,   499,   119,   119,   118,   118,
     474,   594,   118,   656,   753,   647,   754,   799,   757,   805,
     759,   495,   761,   914,   498,   768,   609,   610,   831,   768,
     558,   770,   518,   772,   548,   988,   759,   658,   659,   573,
     856,   941,  1008,   704,   518,   784,   520,   668,   787,   613,
     617,   790,  1013,   619,   837,    15,   295,   749,    -1,   534,
    1013,    -1,    -1,   684,    -1,    -1,   805,    -1,    -1,    -1,
     544,   605,   750,   547,    -1,    -1,   550,    -1,    -1,   613,
      -1,    -1,    -1,    -1,   558,    -1,   669,   670,   671,   672,
     673,   674,   831,    -1,    -1,    -1,    -1,    -1,    -1,   838,
     574,   575,    -1,   842,   578,    -1,   845,    -1,    -1,   848,
      -1,    -1,   116,   852,   118,   119,   120,   856,   122,   123,
     124,    -1,    -1,   706,   658,   659,    -1,    -1,   867,    -1,
     713,   665,   753,    -1,   668,    -1,    -1,   116,   759,   118,
     119,   120,    -1,   122,   123,   124,    -1,   622,    -1,   770,
     684,   772,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
     694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   907,    -1,
      -1,    -1,   850,    -1,    -1,    -1,    -1,   916,   761,   158,
     159,   160,   656,    -1,   805,   116,    -1,   118,   119,   120,
      -1,   122,   123,   124,    -1,     1,    -1,    -1,    -1,    -1,
      -1,   784,    -1,    -1,   787,    -1,    -1,   790,    -1,   948,
      -1,   950,   951,    -1,    -1,   954,   690,    -1,    -1,   753,
      -1,    -1,    -1,   757,    -1,   759,    -1,   158,   159,   160,
      -1,   852,    -1,    -1,   768,   856,   770,    -1,   772,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   867,    -1,   831,    55,
      -1,    -1,    -1,    -1,   837,    -1,    -1,    -1,    -1,   842,
      -1,    -1,   845,    -1,    -1,   848,   116,    -1,   118,   119,
     120,   805,   122,   123,   124,    -1,    -1,   116,    -1,   118,
     754,   120,    -1,   122,   123,   124,   760,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   852,   158,
     159,   160,   856,    -1,    -1,    -1,    -1,    -1,     0,     1,
       1,    -1,    -1,   867,     6,     7,     8,     9,    -1,    11,
      12,    13,    -1,    15,    16,    -1,   152,    19,    20,    -1,
      22,    23,    24,    25,    -1,     1,    28,    -1,   832,    31,
      -1,    -1,    -1,    35,    -1,   948,    -1,   950,   951,    -1,
      -1,   954,    -1,   907,   849,    -1,    48,    -1,    -1,    -1,
      -1,    -1,   916,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    55,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    55,   118,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    23,    -1,    94,    95,   158,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,    55,    -1,   152,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1005,  1006,  1007,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,   152,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    55,   159,   123,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
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
     112,   113,   114,   115,   116,   117,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    55,   159,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,   117,   118,
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
     110,   111,   112,   113,   114,   115,    -1,   117,    -1,    -1,
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
      55,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    -1,   159,    -1,   161,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,   121,    -1,   123,    55,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    -1,   159,    -1,   161,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,   113,    -1,   115,
      -1,   117,    -1,    -1,   120,   121,    -1,    55,    -1,   125,
     126,   127,    -1,   129,   130,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,    -1,   161,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,   113,    -1,   115,    -1,   117,
      -1,    -1,   120,    -1,    -1,    55,    -1,   125,   126,   127,
      -1,   129,   130,    -1,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    -1,   161,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,
      -1,    -1,   122,    55,    -1,   125,   126,   127,    -1,   129,
     130,    -1,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    -1,   159,
      -1,   161,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    55,    -1,   125,   126,   127,    -1,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    -1,   159,    -1,   161,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,   120,   121,    -1,    55,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,   118,   119,   120,    -1,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,   161,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   158,   159,   160,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    55,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,   118,   119,   120,    -1,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,   112,
     113,   114,   115,    -1,   117,   158,   159,   160,    55,   122,
      -1,    -1,   125,   126,   127,    -1,   129,   130,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,   112,   113,   114,   115,    -1,
     117,    -1,    -1,    -1,    55,   122,    -1,    -1,   125,   126,
     127,    -1,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    -1,   159,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,
     121,    55,    -1,    -1,   125,   126,   127,    -1,   129,   130,
      -1,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    -1,   159,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,   113,
      -1,   115,    -1,   117,    -1,    -1,    -1,    55,   122,    -1,
      -1,   125,   126,   127,    -1,   129,   130,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    -1,   159,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,   113,    -1,   115,    -1,   117,
      -1,    -1,    -1,    55,    -1,    -1,    -1,   125,   126,   127,
      -1,   129,   130,    -1,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     7,   116,
      -1,   118,   119,   120,    -1,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    28,
      -1,    -1,    -1,   116,    -1,   118,    35,   120,    -1,   122,
     123,   124,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,
     152,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    72,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,    81,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,   153,   154,   155,   156,
     157,    -1,   159,   116,   161,   118,   119,   120,    -1,   122,
     123,   124,   116,    -1,   118,   119,   120,    -1,   122,   123,
     124,   116,    -1,   118,    -1,   120,    -1,   122,   123,   124,
     116,    -1,   118,    -1,   120,    -1,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   116,    -1,   118,    -1,   120,
      -1,   122,   123,   124,   116,    -1,   118,    -1,   120,    -1,
     122,   123,   124,   116,    -1,   118,    -1,   120,    -1,   122,
     123,   124,   116,    -1,   118,    -1,   120,    -1,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   116,    -1,   118,
      -1,   120,    -1,   122,   123,   124,   116,    -1,   118,    -1,
     120,    -1,   122,   123,   124,   116,    -1,   118,    -1,   120,
      -1,   122,   123,   124,   116,    -1,   118,    -1,   120,    -1,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   116,
      -1,   118,    -1,   120,    -1,   122,   123,   124,   116,    -1,
     118,    -1,   120,    -1,   122,   123,   124,   116,    -1,   118,
      -1,   120,    -1,   122,   123,   124,   116,    -1,   118,    -1,
     120,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   116,    -1,   118,    -1,   120,    -1,   122,   123,   124,
     116,    -1,   118,    -1,   120,    -1,   122,   123,   124,   116,
      -1,   118,    -1,   120,    -1,   122,   123,   124,   116,    -1,
     118,    -1,   120,    -1,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   116,    -1,   118,    -1,   120,    -1,   122,
     123,   124,   116,    -1,   118,    -1,   120,    -1,   122,   123,
     124,   116,    -1,   118,    -1,   120,    -1,   122,   123,   124,
     116,    -1,   118,    -1,   120,    -1,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   116,    -1,   118,    -1,   120,
      -1,   122,   123,   124,   116,    -1,   118,    -1,   120,    -1,
     122,   123,   124,   116,    -1,   118,    -1,   120,    -1,   122,
     123,   124,   116,    -1,   118,    -1,   120,    -1,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   116,    -1,   118,
      -1,   120,    -1,   122,   123,   124,   116,    -1,   118,    -1,
     120,    -1,   122,   123,   124,   116,    -1,   118,    -1,   120,
      -1,   122,   123,   124,   116,    -1,   118,    -1,   120,    -1,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   116,
      -1,   118,    -1,   120,    -1,   122,   123,   124,   116,    -1,
     118,    -1,   120,    -1,   122,   123,   124,   116,    -1,   118,
      -1,   120,    -1,   122,   123,   124,   116,    -1,   118,    -1,
     120,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,    -1,    -1,    -1,   116,    -1,   118,   158,
     159,   160,   122,   123,   124,    -1,    -1,    -1,   158,   159,
     160,   116,    -1,   118,    -1,   120,    -1,   122,   123,   124,
     116,    -1,   118,    -1,   120,    -1,   122,   123,   124,   116,
      -1,   118,    -1,   120,    -1,   122,   123,   124,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    15,    16,    23,
      24,    25,    28,    31,    35,    48,    64,    74,    75,    76,
      77,    78,    79,    80,    86,    87,    88,    89,    90,    91,
      92,    93,   118,   158,   163,   164,   165,   197,   205,   215,
     318,   361,   362,   354,   198,   323,   331,   329,     7,    25,
      28,    35,    42,    44,    48,    63,    65,    66,    67,    68,
      72,    81,   364,     6,     8,    23,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    81,
      31,    32,    68,    69,   358,   359,   319,    70,    71,   360,
     358,    65,   120,   120,   120,   120,   324,   321,   168,   169,
     170,   167,   332,   166,     0,   206,   330,    11,    12,    19,
      20,    22,   120,    55,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   159,   161,   300,   311,
     312,   313,   314,   315,   316,   317,   116,   118,   120,   122,
     123,   124,   158,   159,   160,   365,   407,   365,   116,   118,
     120,   122,   123,   124,   158,   159,   160,   371,   409,    68,
      13,    42,    44,    45,    46,    47,    62,    12,    29,    30,
      31,    33,    34,    57,    58,    59,   356,    36,    37,    38,
      39,    70,    82,    83,    84,   154,   355,    25,    26,    27,
     357,   357,   357,    59,    81,   145,    73,   357,   350,   337,
     340,    36,    85,   126,   338,   120,   120,   339,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   333,   334,   116,
     118,   120,   122,   123,   124,   158,   159,   160,   401,   336,
     335,   145,   365,   401,     3,     3,     4,     3,   398,     3,
     300,   371,   325,   326,   327,   328,    85,   363,   111,   408,
     366,   367,   410,   372,   373,   374,   352,    44,    45,   357,
     357,   357,   357,   357,   357,   357,    40,    41,   357,   357,
     120,   120,   120,   357,   357,   357,   357,   120,   116,   122,
     123,   124,   158,   159,   160,   420,   399,   399,   120,   120,
      85,   399,   399,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   118,   417,   418,   420,   417,   402,   320,   417,
     417,   120,   322,   119,   401,   207,   365,   371,   371,   122,
     158,   381,   409,   120,   118,   172,   173,   174,   300,   398,
     400,   399,   398,   116,   118,   120,   122,   123,   124,   158,
     159,   160,   375,   411,   400,   399,   420,   357,   357,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   351,   116,   118,   120,   122,   123,   124,   158,
     159,   160,   403,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   419,   120,   418,   120,
     398,   399,   120,   120,   399,   131,   209,   382,   383,   384,
     172,   129,   199,   130,   131,   119,   116,   118,   120,   122,
     123,   124,   158,   159,   160,   368,   405,   120,   119,   412,
     376,   377,   368,   120,   353,   120,   120,   357,   404,   398,
     119,   120,   120,   210,   211,   300,   110,   120,   160,   385,
     411,   400,   399,   119,   172,   127,   118,   177,   175,   369,
     406,   398,   116,   118,   120,   122,   123,   124,   158,   159,
     160,   378,   413,   399,   357,   120,   398,   119,   124,   132,
     128,   216,   386,   387,   368,   120,   172,   178,   176,   300,
     401,   398,   119,   414,   379,   380,   120,   120,   119,   211,
     172,     1,    55,    94,    95,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   152,   217,
     116,   118,   120,   122,   123,   124,   158,   159,   160,   388,
     415,   399,   200,    97,    99,   126,   179,   180,   124,   132,
     370,   119,   398,   365,   399,   120,   112,   113,   114,   115,
     117,   118,   120,   121,   244,   245,   306,   312,   313,   316,
     161,   171,   172,   173,   218,   219,   118,   241,   300,   244,
     240,   306,   300,   236,   220,   222,   225,   227,   230,   232,
     241,   416,   389,   390,   391,   120,   110,   110,   113,   115,
     117,   125,   126,   127,   129,   130,   159,   292,   293,   309,
     313,   317,   118,   181,   300,   300,   119,   124,   300,   399,
     119,   120,   246,   116,   245,   247,   129,   120,   271,   272,
     292,   243,   247,   242,   247,   116,   306,   235,   272,   276,
     276,   282,   282,   284,   284,   247,   398,   365,   120,   160,
     392,   411,   399,   201,   127,   131,   183,   116,   184,   182,
     127,   180,   120,   274,   250,   171,   172,   120,   161,   208,
     292,   121,   208,   292,   273,   274,   276,   122,   161,   212,
     213,   251,   292,   125,   237,   208,   116,   118,   306,   116,
     112,   113,   114,   115,   116,   117,   118,   120,   121,   304,
     312,   313,   316,   117,   112,   113,   114,   115,   116,   117,
     118,   120,   121,   303,   312,   313,   316,   113,   119,   393,
     394,   120,    96,    97,    99,   202,   292,   294,   274,   185,
     127,   278,   300,   118,   119,   300,   112,   114,   249,   251,
     271,   119,   252,   120,   124,   127,   238,   239,   301,   311,
     313,   315,   316,   120,   221,   277,   223,   226,   283,   228,
     231,   285,   233,   120,   123,   395,   413,   399,   292,   181,
     293,   295,   119,   122,   186,   249,   292,   118,   188,   300,
     112,   113,   114,   115,   117,   118,   120,   121,   124,   161,
     307,   311,   313,   316,   275,   212,   248,   251,   121,   253,
     292,   124,   116,   118,   120,   161,   214,   288,   289,   301,
     310,   274,   286,   214,   274,   286,   214,   274,   286,   396,
     397,   120,   127,   184,   124,   132,   187,   186,   190,   122,
     191,   189,   279,   274,   122,   254,   123,   124,   239,   300,
     290,   118,   120,   124,   127,   161,   208,   302,   310,   311,
     315,   316,   313,   119,   112,   113,   114,   115,   116,   117,
     118,   120,   121,   305,   312,   313,   316,   119,   115,   119,
     115,   365,   399,   161,   204,   292,   127,   296,   253,   274,
     140,   141,   148,   154,   192,   193,   280,   274,   119,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   255,   256,   257,   120,   292,   274,   291,   224,   287,
     229,   234,   120,   120,   203,   293,   123,   119,   159,   118,
     118,   118,   123,   193,   118,   120,   123,   127,   161,   308,
     311,   313,   315,   317,   119,   135,   135,   159,   118,   159,
     118,   118,   118,   118,   118,   118,   123,   257,   258,   119,
     274,   214,   274,   214,   214,   214,   194,   196,   195,   281,
     259,   261,   262,   263,   264,   155,   156,   157,   266,   267,
     260,   118,   120,   297,   298,   312,   314,   315,   119,   119,
     159,   265,     5,   265,   274,   265,   265,   265,   265,     5,
     300,   300,   300,   119,   267,   265,   299,   298,   119,   159,
     119,   119,   119,   119,   119,   119,   119,   119,   118,   118,
     118,   119,   274,   268,   269,   270,   119,   274,   274,   274,
     119,   119,   119
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
#line 212 "surface.yy"
    { YYACCEPT; ;}
    break;

  case 3:
#line 214 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			;}
    break;

  case 8:
#line 228 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 9:
#line 230 "surface.yy"
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
#line 238 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 11:
#line 240 "surface.yy"
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
#line 249 "surface.yy"
    {
			  cout << directoryManager.getCwd() << '\n';
			;}
    break;

  case 13:
#line 252 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 14:
#line 254 "surface.yy"
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
#line 263 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 16:
#line 265 "surface.yy"
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
#line 275 "surface.yy"
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
#line 285 "surface.yy"
    { lexerStringMode(); ;}
    break;

  case 19:
#line 287 "surface.yy"
    {
			  system((string("ls") + yyvsp[0].yyString).c_str());
			;}
    break;

  case 20:
#line 291 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			;}
    break;

  case 21:
#line 296 "surface.yy"
    {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			;}
    break;

  case 23:
#line 330 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			;}
    break;

  case 24:
#line 338 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  moduleExpressions.push(new ModuleExpression(t));
			;}
    break;

  case 26:
#line 349 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			;}
    break;

  case 28:
#line 360 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			;}
    break;

  case 29:
#line 368 "surface.yy"
    {;}
    break;

  case 30:
#line 369 "surface.yy"
    { clear(); ;}
    break;

  case 31:
#line 371 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, bubble));
			;}
    break;

  case 32:
#line 377 "surface.yy"
    {
			  moduleExpressions.push(new ModuleExpression(yyvsp[0].yyToken));
			;}
    break;

  case 33:
#line 382 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 34:
#line 383 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 35:
#line 390 "surface.yy"
    {
			  currentRenaming = new Renaming;
			;}
    break;

  case 39:
#line 401 "surface.yy"
    {
			  currentRenaming->addSortMapping(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 40:
#line 405 "surface.yy"
    {
			  currentRenaming->addLabelMapping(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 41:
#line 408 "surface.yy"
    {;}
    break;

  case 42:
#line 411 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 43:
#line 413 "surface.yy"
    {
			  currentRenaming->addOpMapping(bubble);
			;}
    break;

  case 44:
#line 416 "surface.yy"
    { clear(); ;}
    break;

  case 45:
#line 418 "surface.yy"
    {
			  currentRenaming->addOpMapping(bubble);
			;}
    break;

  case 46:
#line 423 "surface.yy"
    {;}
    break;

  case 50:
#line 432 "surface.yy"
    {
			  clear();
			  bubble.append(yyvsp[0].yyToken);
			  currentRenaming->addType(bubble);
			;}
    break;

  case 51:
#line 437 "surface.yy"
    { clear(); ;}
    break;

  case 52:
#line 439 "surface.yy"
    {
			  currentRenaming->addType(bubble);
			;}
    break;

  case 53:
#line 444 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 54:
#line 445 "surface.yy"
    { currentRenaming->addOpTarget(bubble); ;}
    break;

  case 55:
#line 446 "surface.yy"
    { clear(); ;}
    break;

  case 56:
#line 447 "surface.yy"
    { currentRenaming->addOpTarget(bubble); ;}
    break;

  case 57:
#line 450 "surface.yy"
    {;}
    break;

  case 61:
#line 458 "surface.yy"
    { currentRenaming->setPrec(yyvsp[0].yyToken); ;}
    break;

  case 62:
#line 459 "surface.yy"
    { clear(); ;}
    break;

  case 63:
#line 460 "surface.yy"
    { currentRenaming->setGather(bubble); ;}
    break;

  case 64:
#line 461 "surface.yy"
    { clear(); ;}
    break;

  case 65:
#line 462 "surface.yy"
    { currentRenaming->setFormat(bubble); ;}
    break;

  case 66:
#line 463 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 67:
#line 464 "surface.yy"
    { currentRenaming->setLatexMacro(yyvsp[-1].yyString); ;}
    break;

  case 68:
#line 470 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 69:
#line 472 "surface.yy"
    {
			  fileTable.beginModule(yyvsp[-4].yyToken, yyvsp[-2].yyToken);
			  interpreter.setCurrentView(new View(yyvsp[-2].yyToken));
			  CV->addFrom(moduleExpressions.top());
			  moduleExpressions.pop();
			;}
    break;

  case 70:
#line 479 "surface.yy"
    {
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			  currentRenaming = CV;  // trick to reuse renaming fromOpName, fromSpec syntax
			;}
    break;

  case 71:
#line 485 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CV->finishView();
			  interpreter.insertView((yyvsp[-9].yyToken).code(), CV);
			  currentRenaming = 0;
			;}
    break;

  case 74:
#line 499 "surface.yy"
    {
			  CV->addSortMapping(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 75:
#line 502 "surface.yy"
    { clear(); ;}
    break;

  case 76:
#line 503 "surface.yy"
    { CV->addOpTarget(bubble); ;}
    break;

  case 77:
#line 506 "surface.yy"
    { yyval.yyToken = yyvsp[-1].yyToken; ;}
    break;

  case 78:
#line 508 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  yyval.yyToken = t;
			;}
    break;

  case 79:
#line 520 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 80:
#line 522 "surface.yy"
    {
			  interpreter.setCurrentModule(new PreModule(yyvsp[-2].yyToken, yyvsp[0].yyToken));
			  fileTable.beginModule(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 81:
#line 527 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule(yyvsp[0].yyToken);
			;}
    break;

  case 82:
#line 534 "surface.yy"
    {;}
    break;

  case 83:
#line 536 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  store(t);
			;}
    break;

  case 84:
#line 545 "surface.yy"
    {;}
    break;

  case 88:
#line 554 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter(yyvsp[-2].yyToken, me);
			;}
    break;

  case 89:
#line 562 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  clear();
			  store(t);
			  CM->addType(false, bubble);
			;}
    break;

  case 93:
#line 579 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  store(t);
			;}
    break;

  case 98:
#line 596 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport(yyvsp[-1].yyToken, me);
			;}
    break;

  case 99:
#line 602 "surface.yy"
    { clear(); ;}
    break;

  case 100:
#line 603 "surface.yy"
    { CM->addSortDecl(bubble); ;}
    break;

  case 101:
#line 605 "surface.yy"
    { clear(); ;}
    break;

  case 102:
#line 606 "surface.yy"
    { CM->addSubsortDecl(bubble); ;}
    break;

  case 103:
#line 608 "surface.yy"
    {;}
    break;

  case 104:
#line 610 "surface.yy"
    {;}
    break;

  case 105:
#line 612 "surface.yy"
    {;}
    break;

  case 106:
#line 614 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 107:
#line 615 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 108:
#line 616 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 109:
#line 618 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 110:
#line 619 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 111:
#line 620 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 112:
#line 621 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 113:
#line 623 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 114:
#line 624 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 115:
#line 625 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 116:
#line 627 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 117:
#line 628 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 118:
#line 629 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 119:
#line 630 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 120:
#line 632 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 121:
#line 633 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 122:
#line 634 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 123:
#line 636 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 124:
#line 637 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 125:
#line 638 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 126:
#line 639 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 127:
#line 642 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 128:
#line 647 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 129:
#line 652 "surface.yy"
    {
			;}
    break;

  case 130:
#line 655 "surface.yy"
    {
			;}
    break;

  case 131:
#line 658 "surface.yy"
    { clear(); ;}
    break;

  case 132:
#line 659 "surface.yy"
    { CM->addSubsortDecl(bubble); ;}
    break;

  case 133:
#line 662 "surface.yy"
    {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeOpDeclsConsistent();
			;}
    break;

  case 134:
#line 672 "surface.yy"
    {;}
    break;

  case 135:
#line 673 "surface.yy"
    {;}
    break;

  case 138:
#line 681 "surface.yy"
    {
			;}
    break;

  case 139:
#line 685 "surface.yy"
    { CM->addVarDecl(yyvsp[0].yyToken); ;}
    break;

  case 140:
#line 686 "surface.yy"
    { CM->addVarDecl(yyvsp[0].yyToken); ;}
    break;

  case 141:
#line 689 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 142:
#line 690 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 143:
#line 691 "surface.yy"
    { clear(); ;}
    break;

  case 144:
#line 692 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 147:
#line 700 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  CM->addOpDecl(bubble);
			;}
    break;

  case 148:
#line 705 "surface.yy"
    { clear(); ;}
    break;

  case 149:
#line 706 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 150:
#line 710 "surface.yy"
    {
			  if (yyvsp[-1].yyBool)
			    CM->convertSortsToKinds();
			;}
    break;

  case 153:
#line 720 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 154:
#line 721 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 157:
#line 729 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  CM->addType(false, bubble);
			;}
    break;

  case 158:
#line 734 "surface.yy"
    { clear(); ;}
    break;

  case 159:
#line 736 "surface.yy"
    {
			  CM->addType(true, bubble);
			;}
    break;

  case 160:
#line 741 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 161:
#line 742 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 162:
#line 745 "surface.yy"
    {;}
    break;

  case 166:
#line 754 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			;}
    break;

  case 167:
#line 758 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			;}
    break;

  case 168:
#line 762 "surface.yy"
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			;}
    break;

  case 169:
#line 768 "surface.yy"
    {
			  CM->setFlag(SymbolType::ASSOC);
			;}
    break;

  case 170:
#line 772 "surface.yy"
    {
			  CM->setFlag(SymbolType::COMM);
			;}
    break;

  case 171:
#line 775 "surface.yy"
    { clear(); ;}
    break;

  case 172:
#line 776 "surface.yy"
    { CM->setIdentity(bubble); ;}
    break;

  case 173:
#line 778 "surface.yy"
    {
			  CM->setFlag(SymbolType::IDEM);
			;}
    break;

  case 174:
#line 782 "surface.yy"
    {
			  CM->setFlag(SymbolType::ITER);
			;}
    break;

  case 175:
#line 785 "surface.yy"
    { CM->setPrec(yyvsp[0].yyToken); ;}
    break;

  case 176:
#line 786 "surface.yy"
    { clear(); ;}
    break;

  case 177:
#line 787 "surface.yy"
    { CM->setGather(bubble); ;}
    break;

  case 178:
#line 788 "surface.yy"
    { clear(); ;}
    break;

  case 179:
#line 789 "surface.yy"
    { CM->setFormat(bubble); ;}
    break;

  case 180:
#line 790 "surface.yy"
    { clear(); ;}
    break;

  case 181:
#line 791 "surface.yy"
    { CM->setStrat(bubble); ;}
    break;

  case 182:
#line 792 "surface.yy"
    { clear(); ;}
    break;

  case 183:
#line 793 "surface.yy"
    { CM->setPoly(bubble); ;}
    break;

  case 184:
#line 795 "surface.yy"
    {
			  CM->setFlag(SymbolType::MEMO);
			;}
    break;

  case 185:
#line 799 "surface.yy"
    {
			  CM->setFlag(SymbolType::CTOR);
			;}
    break;

  case 186:
#line 803 "surface.yy"
    {
			  clear();
			  CM->setFrozen(bubble);
			;}
    break;

  case 187:
#line 807 "surface.yy"
    { clear(); ;}
    break;

  case 188:
#line 808 "surface.yy"
    { CM->setFrozen(bubble); ;}
    break;

  case 189:
#line 810 "surface.yy"
    {
			  CM->setFlag(SymbolType::CONFIG);
			;}
    break;

  case 190:
#line 814 "surface.yy"
    {
			  CM->setFlag(SymbolType::OBJECT);
			;}
    break;

  case 191:
#line 818 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 192:
#line 822 "surface.yy"
    {
			  CM->setMetadata(yyvsp[0].yyToken);
			;}
    break;

  case 193:
#line 825 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 194:
#line 826 "surface.yy"
    { CM->setLatexMacro(yyvsp[-1].yyString); ;}
    break;

  case 195:
#line 827 "surface.yy"
    {;}
    break;

  case 196:
#line 829 "surface.yy"
    {
			  CM->setFlag(SymbolType::DITTO);
			;}
    break;

  case 197:
#line 834 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 198:
#line 835 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 201:
#line 843 "surface.yy"
    {
			  clear();
			  CM->addHook(PreModule::ID_HOOK, yyvsp[0].yyToken, bubble);
			;}
    break;

  case 202:
#line 847 "surface.yy"
    { clear(); ;}
    break;

  case 203:
#line 849 "surface.yy"
    {
			  CM->addHook(PreModule::ID_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 204:
#line 852 "surface.yy"
    { clear(); ;}
    break;

  case 205:
#line 854 "surface.yy"
    {
			  CM->addHook(PreModule::OP_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 206:
#line 857 "surface.yy"
    { clear(); ;}
    break;

  case 207:
#line 859 "surface.yy"
    {
			  CM->addHook(PreModule::TERM_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 208:
#line 867 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 210:
#line 871 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 211:
#line 872 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 212:
#line 873 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 213:
#line 874 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 214:
#line 880 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 215:
#line 881 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 216:
#line 882 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 218:
#line 886 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 219:
#line 887 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 220:
#line 888 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 222:
#line 892 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 223:
#line 893 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 224:
#line 894 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 226:
#line 898 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 227:
#line 899 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 228:
#line 900 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 230:
#line 904 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 231:
#line 905 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 232:
#line 906 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 234:
#line 910 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 235:
#line 911 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 236:
#line 912 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 238:
#line 916 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 239:
#line 917 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 240:
#line 918 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 243:
#line 923 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 244:
#line 924 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 245:
#line 927 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 246:
#line 928 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 247:
#line 929 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 248:
#line 930 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 249:
#line 931 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 250:
#line 932 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 251:
#line 933 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 252:
#line 940 "surface.yy"
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

  case 253:
#line 951 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 254:
#line 952 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 255:
#line 953 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 256:
#line 956 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 257:
#line 957 "surface.yy"
    {;}
    break;

  case 258:
#line 958 "surface.yy"
    {;}
    break;

  case 259:
#line 964 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 260:
#line 965 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 265:
#line 969 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 266:
#line 970 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 424:
#line 1075 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 425:
#line 1076 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 426:
#line 1078 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.setCurrentModule(bubble);
			;}
    break;

  case 427:
#line 1082 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 428:
#line 1083 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 429:
#line 1085 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->dump();
			;}
    break;

  case 430:
#line 1091 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 431:
#line 1097 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(bubble);
			;}
    break;

  case 432:
#line 1104 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 433:
#line 1110 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(bubble);
			;}
    break;

  case 434:
#line 1117 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 435:
#line 1123 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(bubble, yyvsp[-3].yyBool);
			;}
    break;

  case 436:
#line 1130 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 437:
#line 1137 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(bubble, number, yyvsp[-3].yyBool);
			;}
    break;

  case 438:
#line 1143 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 439:
#line 1151 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 440:
#line 1157 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 441:
#line 1165 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 442:
#line 1171 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 443:
#line 1178 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(bubble, number);
			;}
    break;

  case 444:
#line 1184 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 445:
#line 1191 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(bubble, yyvsp[-2].yyBool, number);
			;}
    break;

  case 446:
#line 1197 "surface.yy"
    {
			  interpreter.cont(yyvsp[-1].yyInt64, yyvsp[-3].yyBool);
			;}
    break;

  case 447:
#line 1201 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 448:
#line 1207 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(bubble);
			;}
    break;

  case 449:
#line 1212 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 450:
#line 1214 "surface.yy"
    {
			  lexerInitialMode();
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(bubble);
			;}
    break;

  case 451:
#line 1221 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 452:
#line 1223 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 453:
#line 1227 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 454:
#line 1229 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude(yyvsp[-3].yyBool);
			;}
    break;

  case 455:
#line 1233 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 456:
#line 1235 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 457:
#line 1239 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 458:
#line 1241 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal(yyvsp[-3].yyBool);
			;}
    break;

  case 459:
#line 1246 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			;}
    break;

  case 460:
#line 1253 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 461:
#line 1255 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 462:
#line 1260 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 463:
#line 1262 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 464:
#line 1267 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 465:
#line 1269 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showModule(true);
			;}
    break;

  case 466:
#line 1274 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 467:
#line 1276 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentView(bubble))
			    interpreter.showView();
			;}
    break;

  case 468:
#line 1282 "surface.yy"
    {
			  interpreter.showModules(true);
			;}
    break;

  case 469:
#line 1286 "surface.yy"
    {
			  interpreter.showNamedViews();
			;}
    break;

  case 470:
#line 1289 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 471:
#line 1291 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSortsAndSubsorts();
			;}
    break;

  case 472:
#line 1296 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 473:
#line 1298 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showOps();
			;}
    break;

  case 474:
#line 1303 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 475:
#line 1305 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showVars();
			;}
    break;

  case 476:
#line 1310 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 477:
#line 1312 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showMbs();
			;}
    break;

  case 478:
#line 1317 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 479:
#line 1319 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showEqs();
			;}
    break;

  case 480:
#line 1324 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 481:
#line 1326 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showRls();
			;}
    break;

  case 482:
#line 1331 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 483:
#line 1333 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSummary();
			;}
    break;

  case 484:
#line 1338 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 485:
#line 1340 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showKinds();
			;}
    break;

  case 486:
#line 1346 "surface.yy"
    {
			  interpreter.showSearchPath(yyvsp[-1].yyInt64);
			;}
    break;

  case 487:
#line 1350 "surface.yy"
    {
			  interpreter.showSearchPathLabels(yyvsp[-1].yyInt64);
			;}
    break;

  case 488:
#line 1354 "surface.yy"
    {
			  interpreter.showSearchGraph();
			;}
    break;

  case 489:
#line 1357 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 490:
#line 1359 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showProfile();
			;}
    break;

  case 491:
#line 1368 "surface.yy"
    {
			  globalAdvisoryFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 492:
#line 1372 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 493:
#line 1376 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 494:
#line 1380 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 495:
#line 1384 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, yyvsp[-1].yyBool);
			;}
    break;

  case 496:
#line 1388 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 497:
#line 1392 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, yyvsp[-1].yyBool);
			;}
    break;

  case 498:
#line 1396 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 499:
#line 1400 "surface.yy"
    {
			  interpreter.setPrintFlag(yyvsp[-2].yyPrintFlags, yyvsp[-1].yyBool);
			;}
    break;

  case 500:
#line 1404 "surface.yy"
    {
			  interpreter.setFlag(yyvsp[-2].yyFlags, yyvsp[-1].yyBool);
			;}
    break;

  case 501:
#line 1408 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, yyvsp[-1].yyBool);
			;}
    break;

  case 502:
#line 1411 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 503:
#line 1412 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 504:
#line 1414 "surface.yy"
    {
			  interpreter.setAutoImport(yyvsp[-5].yyImportMode, yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 505:
#line 1417 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 506:
#line 1418 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 507:
#line 1420 "surface.yy"
    {
			  interpreter.setOmodInclude(yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 508:
#line 1424 "surface.yy"
    {
			  globalVerboseFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 509:
#line 1428 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, yyvsp[-1].yyBool);
			;}
    break;

  case 510:
#line 1432 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, yyvsp[-1].yyBool);
			;}
    break;

  case 511:
#line 1436 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, yyvsp[-1].yyBool);
			;}
    break;

  case 512:
#line 1440 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 513:
#line 1444 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 514:
#line 1451 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			;}
    break;

  case 515:
#line 1455 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			;}
    break;

  case 516:
#line 1459 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			;}
    break;

  case 517:
#line 1463 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			;}
    break;

  case 518:
#line 1470 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 519:
#line 1474 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 520:
#line 1480 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 522:
#line 1487 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_MIXFIX; ;}
    break;

  case 523:
#line 1488 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_FLAT; ;}
    break;

  case 524:
#line 1489 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_WITH_ALIASES; ;}
    break;

  case 525:
#line 1490 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_WITH_PARENS; ;}
    break;

  case 526:
#line 1491 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_GRAPH; ;}
    break;

  case 527:
#line 1492 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_CONCEAL; ;}
    break;

  case 528:
#line 1493 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_NUMBER; ;}
    break;

  case 529:
#line 1494 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_RAT; ;}
    break;

  case 530:
#line 1495 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_COLOR; ;}
    break;

  case 531:
#line 1496 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_FORMAT; ;}
    break;

  case 532:
#line 1499 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE; ;}
    break;

  case 533:
#line 1500 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_CONDITION; ;}
    break;

  case 534:
#line 1501 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_WHOLE; ;}
    break;

  case 535:
#line 1502 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_SUBSTITUTION; ;}
    break;

  case 536:
#line 1503 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_SELECT; ;}
    break;

  case 537:
#line 1504 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_MB; ;}
    break;

  case 538:
#line 1505 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_EQ; ;}
    break;

  case 539:
#line 1506 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_RL; ;}
    break;

  case 540:
#line 1507 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_REWRITE; ;}
    break;

  case 541:
#line 1508 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_BODY; ;}
    break;

  case 542:
#line 1511 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 543:
#line 1512 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 544:
#line 1515 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 545:
#line 1516 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 546:
#line 1519 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 547:
#line 1520 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 548:
#line 1523 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 549:
#line 1524 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 550:
#line 1527 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 551:
#line 1528 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 552:
#line 1531 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 553:
#line 1532 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 554:
#line 1535 "surface.yy"
    { yyval.yyInt64 = yyvsp[0].yyInt64; ;}
    break;

  case 555:
#line 1536 "surface.yy"
    { yyval.yyInt64 = NONE; ;}
    break;

  case 556:
#line 1539 "surface.yy"
    { yyval.yyImportMode = ImportModule::PROTECTING; ;}
    break;

  case 557:
#line 1540 "surface.yy"
    { yyval.yyImportMode = ImportModule::EXTENDING; ;}
    break;

  case 558:
#line 1541 "surface.yy"
    { yyval.yyImportMode = ImportModule::INCLUDING; ;}
    break;

  case 559:
#line 1549 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 561:
#line 1551 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 563:
#line 1555 "surface.yy"
    { moduleExpr = bubble; clear(); ;}
    break;

  case 564:
#line 1556 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 565:
#line 1557 "surface.yy"
    {;}
    break;

  case 566:
#line 1558 "surface.yy"
    {;}
    break;

  case 567:
#line 1567 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 569:
#line 1569 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 571:
#line 1571 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 573:
#line 1576 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 575:
#line 1578 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 577:
#line 1580 "surface.yy"
    {;}
    break;

  case 578:
#line 1585 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 580:
#line 1590 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 582:
#line 1592 "surface.yy"
    {;}
    break;

  case 583:
#line 1601 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 585:
#line 1603 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 587:
#line 1605 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 589:
#line 1610 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 591:
#line 1612 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 593:
#line 1614 "surface.yy"
    {;}
    break;

  case 594:
#line 1619 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 596:
#line 1624 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 598:
#line 1626 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 600:
#line 1628 "surface.yy"
    {;}
    break;

  case 601:
#line 1632 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 603:
#line 1634 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 605:
#line 1636 "surface.yy"
    {;}
    break;

  case 606:
#line 1641 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  number2 = Token::codeToInt64(bubble[3].code());
			  clear();
			;}
    break;

  case 608:
#line 1647 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 610:
#line 1649 "surface.yy"
    {;}
    break;

  case 611:
#line 1655 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 613:
#line 1659 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 615:
#line 1664 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 625:
#line 1672 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 626:
#line 1673 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 634:
#line 1677 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 635:
#line 1678 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 642:
#line 1683 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 643:
#line 1684 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 651:
#line 1688 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 652:
#line 1689 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 659:
#line 1693 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 660:
#line 1694 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 667:
#line 1699 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 668:
#line 1700 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 675:
#line 1705 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 676:
#line 1706 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 682:
#line 1711 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 683:
#line 1712 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 686:
#line 1723 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  interpreter.addSelected(bubble);
			;}
    break;

  case 687:
#line 1728 "surface.yy"
    { clear(); ;}
    break;

  case 688:
#line 1730 "surface.yy"
    {
			  interpreter.addSelected(bubble);
			;}
    break;


    }

/* Line 999 of yacc.c.  */
#line 6035 "surface.c"

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


#line 1760 "surface.yy"


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

