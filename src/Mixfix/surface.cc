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

#include "global.hh"
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
#define YYLAST   7206

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  162
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  279
/* YYNRULES -- Number of rules. */
#define YYNRULES  738
/* YYNRULES -- Number of states. */
#define YYNSTATES  1136

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
     468,   469,   474,   477,   480,   483,   485,   490,   493,   495,
     499,   501,   503,   505,   508,   509,   511,   512,   517,   521,
     523,   527,   528,   531,   533,   535,   538,   541,   543,   545,
     546,   550,   552,   554,   557,   558,   564,   565,   571,   572,
     578,   579,   585,   587,   589,   591,   592,   598,   600,   602,
     604,   607,   608,   614,   619,   621,   624,   626,   629,   631,
     634,   635,   642,   643,   650,   651,   658,   660,   661,   663,
     664,   667,   668,   671,   674,   675,   680,   681,   687,   690,
     691,   692,   698,   701,   702,   703,   709,   712,   713,   714,
     720,   723,   724,   725,   731,   734,   735,   736,   742,   745,
     746,   747,   753,   756,   757,   759,   762,   764,   765,   770,
     771,   777,   780,   783,   785,   787,   789,   790,   796,   797,
     802,   804,   806,   809,   811,   813,   815,   817,   818,   823,
     825,   827,   829,   831,   833,   835,   837,   839,   841,   843,
     845,   847,   849,   851,   853,   855,   857,   859,   861,   863,
     865,   867,   869,   871,   873,   875,   877,   879,   881,   883,
     885,   887,   889,   891,   893,   895,   897,   899,   901,   903,
     905,   907,   909,   911,   913,   915,   917,   919,   921,   923,
     925,   927,   929,   931,   933,   935,   937,   939,   941,   943,
     945,   947,   949,   951,   953,   955,   957,   959,   961,   963,
     965,   967,   969,   971,   973,   975,   977,   979,   981,   983,
     985,   987,   989,   991,   993,   995,   997,   999,  1001,  1003,
    1005,  1007,  1009,  1011,  1013,  1015,  1017,  1019,  1021,  1023,
    1025,  1027,  1029,  1031,  1033,  1035,  1037,  1039,  1041,  1043,
    1045,  1047,  1049,  1051,  1053,  1055,  1057,  1059,  1061,  1063,
    1065,  1067,  1069,  1071,  1073,  1075,  1077,  1079,  1081,  1083,
    1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,  1103,
    1105,  1107,  1109,  1111,  1113,  1115,  1117,  1119,  1121,  1123,
    1125,  1127,  1129,  1131,  1133,  1135,  1137,  1138,  1139,  1146,
    1147,  1148,  1155,  1156,  1160,  1161,  1165,  1166,  1171,  1172,
    1177,  1178,  1183,  1184,  1189,  1190,  1195,  1196,  1200,  1201,
    1205,  1210,  1211,  1215,  1216,  1221,  1222,  1228,  1229,  1235,
    1236,  1242,  1243,  1249,  1254,  1255,  1261,  1262,  1268,  1269,
    1275,  1276,  1282,  1286,  1290,  1291,  1297,  1298,  1304,  1305,
    1311,  1312,  1318,  1319,  1325,  1326,  1332,  1333,  1339,  1340,
    1346,  1351,  1357,  1362,  1363,  1369,  1375,  1381,  1388,  1394,
    1400,  1407,  1413,  1419,  1425,  1431,  1436,  1437,  1438,  1446,
    1447,  1448,  1457,  1462,  1468,  1474,  1480,  1485,  1491,  1494,
    1497,  1500,  1503,  1509,  1514,  1515,  1519,  1521,  1523,  1526,
    1529,  1531,  1533,  1535,  1537,  1539,  1541,  1542,  1544,  1546,
    1548,  1550,  1552,  1554,  1556,  1558,  1560,  1562,  1564,  1566,
    1568,  1570,  1572,  1574,  1576,  1578,  1580,  1582,  1583,  1585,
    1586,  1588,  1590,  1592,  1593,  1598,  1599,  1604,  1605,  1606,
    1613,  1615,  1616,  1620,  1621,  1626,  1627,  1632,  1633,  1637,
    1638,  1643,  1645,  1646,  1650,  1651,  1656,  1658,  1659,  1663,
    1664,  1669,  1670,  1675,  1676,  1680,  1681,  1685,  1686,  1691,
    1693,  1694,  1698,  1699,  1703,  1704,  1709,  1711,  1712,  1716,
    1717,  1722,  1724,  1725,  1729,  1730,  1735,  1737,  1738,  1742,
    1743,  1748,  1750,  1751,  1755,  1756,  1761,  1763,  1766,  1767,
    1770,  1771,  1774,  1775,  1777,  1779,  1781,  1783,  1785,  1787,
    1789,  1791,  1792,  1797,  1799,  1801,  1803,  1805,  1807,  1809,
    1811,  1812,  1817,  1819,  1821,  1823,  1825,  1827,  1829,  1830,
    1835,  1837,  1839,  1841,  1843,  1845,  1847,  1849,  1850,  1855,
    1857,  1859,  1861,  1863,  1865,  1867,  1868,  1873,  1875,  1877,
    1879,  1881,  1883,  1885,  1886,  1891,  1893,  1895,  1897,  1899,
    1901,  1903,  1904,  1909,  1911,  1913,  1915,  1917,  1919,  1920,
    1925,  1927,  1929,  1931,  1933,  1935,  1936,  1941,  1944,  1946,
    1948,  1949,  1954,  1956,  1958,  1960,  1962,  1964,  1966
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     163,     0,    -1,   164,    -1,    -1,   211,    -1,   199,    -1,
     165,    -1,   328,    -1,    -1,   158,   166,     3,    -1,    -1,
      91,   167,     3,    -1,    86,    -1,    -1,    87,   168,     3,
      -1,    -1,    88,   169,     3,    -1,    89,    -1,    -1,    90,
     170,     4,    -1,    92,    -1,    93,    -1,   311,   280,    -1,
     320,   120,    -1,   178,   280,    -1,   175,   280,    -1,   176,
     280,    -1,   172,   129,   171,    -1,   161,    -1,   173,    -1,
     172,   129,   172,    -1,   174,    -1,   175,    -1,   178,    -1,
     176,    -1,   310,    -1,   173,   130,   180,    -1,    -1,   174,
     131,   177,   179,   132,    -1,   118,   172,   119,    -1,   179,
     124,   310,    -1,   310,    -1,    -1,    -1,   118,   181,   183,
     182,   119,    -1,   184,    -1,     1,    -1,   184,   124,   185,
      -1,   185,    -1,    97,   302,   127,   302,    -1,   126,   310,
     127,   310,    -1,    99,   186,   189,   127,   190,   193,    -1,
      -1,   310,   187,   288,    -1,    -1,   118,   188,   284,   119,
      -1,   116,   258,   257,   259,    -1,    -1,    -1,   310,   191,
     290,    -1,    -1,   118,   192,   284,   119,    -1,   122,   194,
     123,    -1,    -1,   194,   195,    -1,   195,    -1,   140,   159,
      -1,    -1,   141,   118,   196,   273,   119,    -1,    -1,   154,
     118,   197,   273,   119,    -1,    -1,   148,   118,   198,     5,
     119,    -1,    -1,    -1,    -1,     8,   200,   310,   111,   172,
     201,   127,   172,   202,   279,   203,    96,    -1,   203,   204,
      -1,    -1,    97,   302,   127,   206,    -1,   101,   246,   116,
     219,    -1,    -1,    99,   205,   288,   207,    -1,     1,   120,
      -1,   302,   280,    -1,   161,    -1,    -1,    -1,   116,   208,
     258,   257,   259,   127,   209,   220,    -1,    -1,   127,   210,
     220,    -1,    -1,    -1,   221,   212,   310,   213,   215,   279,
     222,    94,    -1,   120,    -1,   161,    -1,   131,   216,   132,
      -1,    -1,   216,   124,   217,    -1,   217,    -1,   310,   128,
     172,    -1,   161,    -1,   259,   280,    -1,   218,    -1,   298,
     214,    -1,   161,    -1,     6,    -1,     7,    -1,   222,   223,
      -1,    -1,    95,   171,    -1,    -1,    97,   224,   281,   214,
      -1,    -1,    98,   225,   282,   214,    -1,    99,   247,   253,
      -1,    55,   250,   253,    -1,   101,   246,   116,   219,    -1,
      -1,    -1,   104,   226,   286,   116,   227,   220,    -1,    -1,
      -1,    -1,   105,   228,   286,   116,   229,   296,   115,   230,
     220,    -1,    -1,    -1,   106,   231,   292,   117,   232,   220,
      -1,    -1,    -1,    -1,   107,   233,   292,   117,   234,   296,
     115,   235,   220,    -1,    -1,    -1,   108,   236,   294,   113,
     237,   220,    -1,    -1,    -1,    -1,   109,   238,   294,   113,
     239,   296,   115,   240,   220,    -1,   152,   247,   253,    -1,
     100,   250,   253,    -1,    -1,   102,   310,   241,   243,   120,
      -1,    -1,   103,   242,   282,   214,    -1,     1,   120,    -1,
     125,    -1,   125,   244,    -1,   245,    -1,   244,   124,   245,
      -1,   311,   116,   310,    -1,   246,   316,    -1,   316,    -1,
      -1,   310,   248,   286,    -1,    -1,   118,   249,   284,   119,
      -1,   250,   251,    -1,   251,    -1,   316,    -1,    -1,   118,
     252,   284,   119,    -1,   116,   254,    -1,   259,   255,    -1,
     257,   256,    -1,   218,    -1,   259,   258,   257,   256,    -1,
     257,   256,    -1,   120,    -1,   259,   262,   280,    -1,   218,
      -1,   112,    -1,   114,    -1,   258,   259,    -1,    -1,   302,
      -1,    -1,   122,   260,   261,   123,    -1,   261,   124,   302,
      -1,   302,    -1,   122,   263,   123,    -1,    -1,   263,   265,
      -1,   265,    -1,   135,    -1,   138,   135,    -1,   139,   135,
      -1,   133,    -1,   134,    -1,    -1,   264,   266,   307,    -1,
     136,    -1,   137,    -1,   140,   159,    -1,    -1,   141,   118,
     267,   273,   119,    -1,    -1,   154,   118,   268,   273,   119,
      -1,    -1,   143,   118,   269,   273,   119,    -1,    -1,   144,
     118,   270,   273,   119,    -1,   145,    -1,   147,    -1,   146,
      -1,    -1,   146,   118,   271,   273,   119,    -1,   150,    -1,
     151,    -1,   152,    -1,   142,   159,    -1,    -1,   148,   118,
     272,     5,   119,    -1,   149,   118,   274,   119,    -1,   153,
      -1,   273,   159,    -1,   159,    -1,   274,   275,    -1,   275,
      -1,   155,   310,    -1,    -1,   155,   310,   118,   276,   284,
     119,    -1,    -1,   156,   310,   118,   277,   284,   119,    -1,
      -1,   157,   310,   118,   278,   284,   119,    -1,   110,    -1,
      -1,   120,    -1,    -1,   281,   302,    -1,    -1,   282,   302,
      -1,   282,   121,    -1,    -1,   302,   283,   281,   121,    -1,
      -1,   284,   118,   285,   284,   119,    -1,   284,   310,    -1,
      -1,    -1,   286,   118,   287,   284,   119,    -1,   286,   316,
      -1,    -1,    -1,   288,   118,   289,   284,   119,    -1,   288,
     317,    -1,    -1,    -1,   290,   118,   291,   284,   119,    -1,
     290,   318,    -1,    -1,    -1,   292,   118,   293,   284,   119,
      -1,   292,   314,    -1,    -1,    -1,   294,   118,   295,   284,
     119,    -1,   294,   313,    -1,    -1,    -1,   296,   118,   297,
     284,   119,    -1,   296,   315,    -1,    -1,   299,    -1,   298,
     320,    -1,   320,    -1,    -1,   118,   300,   284,   119,    -1,
      -1,   298,   118,   301,   284,   119,    -1,   299,   323,    -1,
     298,   312,    -1,   311,    -1,   303,    -1,   319,    -1,    -1,
     303,   131,   304,   305,   132,    -1,    -1,   305,   124,   306,
     303,    -1,   303,    -1,   308,    -1,   307,   308,    -1,   322,
      -1,   324,    -1,   325,    -1,   120,    -1,    -1,   118,   309,
     284,   119,    -1,   322,    -1,   323,    -1,   325,    -1,   326,
      -1,   120,    -1,   321,    -1,   124,    -1,   127,    -1,   323,
      -1,   325,    -1,   326,    -1,   321,    -1,   124,    -1,   127,
      -1,   325,    -1,   326,    -1,   322,    -1,   323,    -1,   326,
      -1,   120,    -1,   121,    -1,   116,    -1,   112,    -1,   114,
      -1,   117,    -1,   115,    -1,   322,    -1,   323,    -1,   326,
      -1,   120,    -1,   121,    -1,   116,    -1,   112,    -1,   114,
      -1,   113,    -1,   115,    -1,   322,    -1,   323,    -1,   326,
      -1,   120,    -1,   121,    -1,   116,    -1,   112,    -1,   114,
      -1,   117,    -1,   113,    -1,   322,    -1,   323,    -1,   326,
      -1,   120,    -1,   121,    -1,   112,    -1,   114,    -1,   117,
      -1,   113,    -1,   115,    -1,   321,    -1,   161,    -1,   124,
      -1,   323,    -1,   326,    -1,   120,    -1,   121,    -1,   112,
      -1,   114,    -1,   117,    -1,   113,    -1,   115,    -1,   321,
      -1,   161,    -1,   127,    -1,   323,    -1,   327,    -1,   120,
      -1,   123,    -1,   325,    -1,   159,    -1,   323,    -1,   327,
      -1,   117,    -1,   125,    -1,   129,    -1,   130,    -1,   113,
      -1,   115,    -1,   110,    -1,   126,    -1,   127,    -1,   120,
      -1,   161,    -1,   159,    -1,   131,    -1,   132,    -1,   129,
      -1,   130,    -1,   125,    -1,   128,    -1,   126,    -1,   111,
      -1,   110,    -1,   321,    -1,   161,    -1,   124,    -1,   127,
      -1,   152,    -1,   324,    -1,    95,    -1,    97,    -1,    98,
      -1,    99,    -1,    55,    -1,   101,    -1,   100,    -1,   102,
      -1,   103,    -1,   104,    -1,   105,    -1,   106,    -1,   107,
      -1,   108,    -1,   109,    -1,    94,    -1,    96,    -1,   121,
      -1,   116,    -1,   112,    -1,   114,    -1,   117,    -1,   113,
      -1,   115,    -1,   122,    -1,   123,    -1,   327,    -1,   133,
      -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,   138,
      -1,   139,    -1,   140,    -1,   141,    -1,   143,    -1,   144,
      -1,   145,    -1,   147,    -1,   148,    -1,   149,    -1,   146,
      -1,   142,    -1,   150,    -1,   151,    -1,   153,    -1,   154,
      -1,   155,    -1,   156,    -1,   157,    -1,    -1,    -1,    31,
     329,   419,   330,   417,   120,    -1,    -1,    -1,    80,   331,
     419,   332,   417,   120,    -1,    -1,     9,   333,   376,    -1,
      -1,    79,   334,   376,    -1,    -1,   373,    11,   335,   376,
      -1,    -1,   373,    12,   336,   382,    -1,    -1,   373,    19,
     337,   392,    -1,    -1,   373,    20,   338,   392,    -1,    -1,
     373,    21,   339,   382,    -1,    -1,    23,   340,   392,    -1,
      -1,   372,   341,   382,    -1,   373,    22,   374,   120,    -1,
      -1,    13,   342,   376,    -1,    -1,   118,   343,   416,   119,
      -1,    -1,    28,   369,   344,   437,   120,    -1,    -1,    28,
     370,   345,   437,   120,    -1,    -1,    48,   369,   346,   437,
     120,    -1,    -1,    35,   371,   347,   437,   120,    -1,    64,
      65,   145,   120,    -1,    -1,    25,     6,   348,   417,   120,
      -1,    -1,    25,    50,   349,   417,   120,    -1,    -1,    25,
      53,   350,   417,   120,    -1,    -1,    25,     8,   351,   417,
     120,    -1,    25,    51,   120,    -1,    25,    52,   120,    -1,
      -1,    25,    54,   352,   417,   120,    -1,    -1,    25,    55,
     353,   417,   120,    -1,    -1,    25,    56,   354,   417,   120,
      -1,    -1,    25,    57,   355,   417,   120,    -1,    -1,    25,
      58,   356,   417,   120,    -1,    -1,    25,    59,   357,   417,
     120,    -1,    -1,    25,    60,   358,   417,   120,    -1,    -1,
      25,    61,   359,   417,   120,    -1,    25,    49,    85,   120,
      -1,    25,    49,   126,    85,   120,    -1,    25,    23,    36,
     120,    -1,    -1,    25,    81,   360,   417,   120,    -1,    24,
      25,    62,   368,   120,    -1,    24,    25,    44,   368,   120,
      -1,    24,    25,    13,    44,   368,   120,    -1,    24,    25,
      45,   368,   120,    -1,    24,    25,    47,   368,   120,    -1,
      24,    25,    13,    45,   368,   120,    -1,    24,    25,    46,
     368,   120,    -1,    24,    25,    42,   368,   120,    -1,    24,
      35,   366,   368,   120,    -1,    24,    28,   367,   368,   120,
      -1,    24,    48,   368,   120,    -1,    -1,    -1,    24,   375,
     361,   440,   362,   368,   120,    -1,    -1,    -1,    24,     7,
      68,   363,   440,   364,   368,   120,    -1,    24,    63,   368,
     120,    -1,    24,    65,   145,   368,   120,    -1,    24,    65,
      59,   368,   120,    -1,    24,    72,    73,   368,   120,    -1,
      24,    81,   368,   120,    -1,    24,    65,    81,   368,   120,
      -1,    75,   120,    -1,    76,   120,    -1,    77,   120,    -1,
      78,   120,    -1,    24,    42,    25,   368,   120,    -1,    24,
      44,   368,   120,    -1,    -1,     1,   365,   120,    -1,    37,
      -1,    38,    -1,    39,    41,    -1,    39,    40,    -1,    36,
      -1,    70,    -1,    82,    -1,    83,    -1,    84,    -1,   154,
      -1,    -1,    33,    -1,    30,    -1,    34,    -1,    31,    -1,
      57,    -1,    58,    -1,    59,    -1,    12,    -1,    29,    -1,
      26,    -1,    27,    -1,    31,    -1,    32,    -1,    69,    -1,
      68,    -1,    70,    -1,    71,    -1,    16,    -1,    15,    -1,
      74,    -1,    -1,    85,    -1,    -1,    66,    -1,    67,    -1,
      68,    -1,    -1,   158,   377,   418,   379,    -1,    -1,   425,
     378,   417,   120,    -1,    -1,    -1,   116,   380,   419,   381,
     417,   120,    -1,   120,    -1,    -1,   122,   383,   386,    -1,
      -1,   158,   384,   418,   379,    -1,    -1,   427,   385,   417,
     120,    -1,    -1,   160,   387,   389,    -1,    -1,   429,   388,
     417,   120,    -1,   120,    -1,    -1,   123,   390,   376,    -1,
      -1,   431,   391,   417,   120,    -1,   120,    -1,    -1,   122,
     393,   396,    -1,    -1,   158,   394,   418,   379,    -1,    -1,
     427,   395,   417,   120,    -1,    -1,   160,   397,   400,    -1,
      -1,   124,   398,   410,    -1,    -1,   435,   399,   417,   120,
      -1,   120,    -1,    -1,   123,   401,   376,    -1,    -1,   124,
     402,   404,    -1,    -1,   433,   403,   417,   120,    -1,   120,
      -1,    -1,   160,   405,   407,    -1,    -1,   429,   406,   417,
     120,    -1,   120,    -1,    -1,   123,   408,   376,    -1,    -1,
     431,   409,   417,   120,    -1,   120,    -1,    -1,   160,   411,
     413,    -1,    -1,   429,   412,   417,   120,    -1,   120,    -1,
      -1,   123,   414,   376,    -1,    -1,   431,   415,   417,   120,
      -1,   120,    -1,   416,   419,    -1,    -1,   417,   421,    -1,
      -1,   418,   423,    -1,    -1,   159,    -1,   160,    -1,   122,
      -1,   123,    -1,   158,    -1,   116,    -1,   120,    -1,   124,
      -1,    -1,   118,   420,   416,   119,    -1,   159,    -1,   160,
      -1,   122,    -1,   123,    -1,   158,    -1,   116,    -1,   124,
      -1,    -1,   118,   422,   416,   119,    -1,   159,    -1,   160,
      -1,   122,    -1,   123,    -1,   158,    -1,   124,    -1,    -1,
     118,   424,   416,   119,    -1,   159,    -1,   160,    -1,   122,
      -1,   123,    -1,   116,    -1,   120,    -1,   124,    -1,    -1,
     118,   426,   416,   119,    -1,   159,    -1,   160,    -1,   123,
      -1,   116,    -1,   120,    -1,   124,    -1,    -1,   118,   428,
     416,   119,    -1,   159,    -1,   122,    -1,   123,    -1,   158,
      -1,   116,    -1,   124,    -1,    -1,   118,   430,   416,   119,
      -1,   159,    -1,   160,    -1,   122,    -1,   158,    -1,   116,
      -1,   124,    -1,    -1,   118,   432,   416,   119,    -1,   159,
      -1,   160,    -1,   122,    -1,   158,    -1,   116,    -1,    -1,
     118,   434,   416,   119,    -1,   159,    -1,   122,    -1,   123,
      -1,   158,    -1,   116,    -1,    -1,   118,   436,   416,   119,
      -1,   437,   438,    -1,   438,    -1,   440,    -1,    -1,   118,
     439,   416,   119,    -1,   159,    -1,   160,    -1,   122,    -1,
     123,    -1,   158,    -1,   116,    -1,   124,    -1
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
     772,   772,   776,   780,   781,   786,   794,   799,   804,   811,
     812,   815,   816,   819,   820,   823,   829,   829,   836,   837,
     840,   841,   844,   845,   848,   852,   856,   862,   866,   870,
     870,   872,   876,   880,   881,   881,   883,   883,   885,   885,
     887,   887,   889,   893,   897,   902,   902,   904,   908,   912,
     916,   920,   920,   922,   923,   929,   930,   933,   934,   937,
     942,   942,   947,   947,   952,   952,   962,   964,   970,   972,
     980,   981,   984,   985,   986,   986,   993,   993,   995,   996,
     999,   999,  1001,  1002,  1005,  1005,  1007,  1008,  1011,  1011,
    1013,  1014,  1017,  1017,  1019,  1020,  1023,  1023,  1025,  1026,
    1029,  1029,  1031,  1032,  1035,  1036,  1037,  1040,  1040,  1042,
    1042,  1044,  1045,  1046,  1052,  1064,  1065,  1065,  1069,  1069,
    1071,  1077,  1078,  1081,  1081,  1081,  1081,  1082,  1082,  1089,
    1089,  1089,  1089,  1089,  1092,  1092,  1092,  1093,  1093,  1093,
    1096,  1096,  1096,  1097,  1097,  1100,  1100,  1100,  1100,  1101,
    1101,  1101,  1101,  1101,  1101,  1104,  1104,  1104,  1104,  1105,
    1105,  1105,  1105,  1105,  1105,  1108,  1108,  1108,  1108,  1109,
    1109,  1109,  1109,  1109,  1109,  1112,  1112,  1112,  1112,  1113,
    1113,  1113,  1113,  1113,  1113,  1116,  1116,  1116,  1117,  1117,
    1117,  1118,  1118,  1118,  1118,  1118,  1118,  1121,  1121,  1121,
    1122,  1122,  1122,  1122,  1122,  1125,  1125,  1125,  1126,  1126,
    1126,  1126,  1127,  1127,  1127,  1127,  1127,  1130,  1130,  1136,
    1136,  1136,  1136,  1136,  1136,  1136,  1136,  1137,  1137,  1140,
    1140,  1140,  1140,  1143,  1143,  1146,  1146,  1146,  1146,  1146,
    1146,  1147,  1147,  1147,  1148,  1148,  1148,  1148,  1148,  1148,
    1148,  1148,  1151,  1151,  1151,  1151,  1151,  1151,  1151,  1154,
    1154,  1154,  1157,  1157,  1157,  1157,  1157,  1157,  1157,  1158,
    1158,  1158,  1158,  1158,  1158,  1159,  1159,  1159,  1159,  1160,
    1160,  1160,  1160,  1161,  1161,  1161,  1188,  1189,  1188,  1195,
    1196,  1195,  1204,  1203,  1217,  1216,  1230,  1229,  1243,  1242,
    1256,  1255,  1270,  1269,  1284,  1283,  1297,  1296,  1311,  1310,
    1323,  1328,  1327,  1339,  1339,  1348,  1348,  1354,  1354,  1360,
    1360,  1366,  1366,  1372,  1380,  1380,  1387,  1387,  1394,  1394,
    1401,  1401,  1408,  1412,  1416,  1416,  1423,  1423,  1430,  1430,
    1437,  1437,  1444,  1444,  1451,  1451,  1458,  1458,  1465,  1465,
    1472,  1476,  1480,  1484,  1484,  1494,  1498,  1502,  1506,  1510,
    1514,  1518,  1522,  1526,  1530,  1534,  1538,  1539,  1538,  1544,
    1545,  1544,  1550,  1554,  1558,  1562,  1566,  1570,  1577,  1581,
    1585,  1589,  1596,  1600,  1607,  1607,  1614,  1615,  1616,  1617,
    1618,  1619,  1620,  1621,  1622,  1623,  1626,  1627,  1628,  1629,
    1630,  1631,  1632,  1633,  1634,  1635,  1638,  1639,  1642,  1643,
    1646,  1647,  1650,  1651,  1654,  1655,  1658,  1659,  1662,  1663,
    1666,  1667,  1668,  1676,  1676,  1678,  1678,  1682,  1683,  1682,
    1685,  1695,  1695,  1697,  1697,  1699,  1699,  1704,  1704,  1706,
    1706,  1708,  1713,  1712,  1718,  1718,  1720,  1733,  1733,  1735,
    1735,  1737,  1737,  1746,  1746,  1748,  1748,  1750,  1750,  1752,
    1761,  1760,  1766,  1766,  1768,  1768,  1770,  1778,  1778,  1780,
    1780,  1782,  1791,  1790,  1797,  1797,  1799,  1807,  1807,  1809,
    1809,  1811,  1820,  1819,  1825,  1825,  1827,  1833,  1834,  1837,
    1838,  1842,  1843,  1849,  1849,  1849,  1849,  1849,  1849,  1849,
    1849,  1850,  1850,  1854,  1854,  1854,  1854,  1854,  1854,  1854,
    1855,  1855,  1860,  1860,  1860,  1860,  1860,  1860,  1861,  1861,
    1865,  1865,  1865,  1865,  1865,  1865,  1865,  1866,  1866,  1870,
    1870,  1870,  1870,  1870,  1870,  1871,  1871,  1876,  1876,  1876,
    1876,  1876,  1876,  1877,  1877,  1882,  1882,  1882,  1882,  1882,
    1882,  1883,  1883,  1888,  1888,  1888,  1888,  1888,  1889,  1889,
    1894,  1894,  1894,  1894,  1894,  1895,  1895,  1901,  1902,  1905,
    1911,  1911,  1919,  1919,  1919,  1919,  1919,  1919,  1919
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
  "@46", "domainRangeAttr", "dra2", "dra3", "typeAttr", "arrow", 
  "typeList", "typeName", "@47", "sortNames", "attributes", 
  "attributeList", "idKeyword", "attribute", "@48", "@49", "@50", "@51", 
  "@52", "@53", "@54", "idList", "hookList", "hook", "@55", "@56", "@57", 
  "expectedIs", "expectedDot", "sortNameList", "subsortList", "@58", 
  "tokens", "@59", "tokensBarColon", "@60", "tokensBarColonTo", "@61", 
  "tokensBarCommaLeft", "@62", "tokensBarEqual", "@63", "tokensBarArrow2", 
  "@64", "tokensBarIf", "@65", "endTokens", "noTrailingDot", "@66", "@67", 
  "sortName", "sortNameFrag", "@68", "sortNameFrags", "@69", "identity", 
  "identityChunk", "@70", "token", "tokenBarDot", "endToken", 
  "tokenBarArrow2", "tokenBarEqual", "tokenBarIf", "tokenBarColon", 
  "tokenBarColonTo", "tokenBarCommaLeft", "sortToken", "endsInDot", 
  "inert", "identifier", "startKeyword", "startKeyword2", "midKeyword", 
  "attrKeyword", "attrKeyword2", "command", "@71", "@72", "@73", "@74", 
  "@75", "@76", "@77", "@78", "@79", "@80", "@81", "@82", "@83", "@84", 
  "@85", "@86", "@87", "@88", "@89", "@90", "@91", "@92", "@93", "@94", 
  "@95", "@96", "@97", "@98", "@99", "@100", "@101", "@102", "@103", 
  "@104", "@105", "@106", "@107", "printOption", "traceOption", 
  "polarity", "select", "exclude", "conceal", "match", "optDebug", 
  "optNumber", "importMode", "moduleAndTerm", "@108", "@109", "inEnd", 
  "@110", "@111", "numberModuleTerm", "@112", "@113", "@114", 
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
     252,   251,   253,   254,   254,   254,   255,   255,   255,   256,
     256,   257,   257,   258,   258,   259,   260,   259,   261,   261,
     262,   262,   263,   263,   264,   264,   264,   265,   265,   266,
     265,   265,   265,   265,   267,   265,   268,   265,   269,   265,
     270,   265,   265,   265,   265,   271,   265,   265,   265,   265,
     265,   272,   265,   265,   265,   273,   273,   274,   274,   275,
     276,   275,   277,   275,   278,   275,   279,   279,   280,   280,
     281,   281,   282,   282,   283,   282,   285,   284,   284,   284,
     287,   286,   286,   286,   289,   288,   288,   288,   291,   290,
     290,   290,   293,   292,   292,   292,   295,   294,   294,   294,
     297,   296,   296,   296,   298,   298,   298,   300,   299,   301,
     299,   299,   299,   299,   302,   303,   304,   303,   306,   305,
     305,   307,   307,   308,   308,   308,   308,   309,   308,   310,
     310,   310,   310,   310,   311,   311,   311,   311,   311,   311,
     312,   312,   312,   312,   312,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   318,   318,   318,
     318,   318,   318,   318,   318,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   320,   320,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   322,
     322,   322,   322,   323,   323,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   325,   325,   325,   325,   325,   325,   325,   326,
     326,   326,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   329,   330,   328,   331,
     332,   328,   333,   328,   334,   328,   335,   328,   336,   328,
     337,   328,   338,   328,   339,   328,   340,   328,   341,   328,
     328,   342,   328,   343,   328,   344,   328,   345,   328,   346,
     328,   347,   328,   328,   348,   328,   349,   328,   350,   328,
     351,   328,   328,   328,   352,   328,   353,   328,   354,   328,
     355,   328,   356,   328,   357,   328,   358,   328,   359,   328,
     328,   328,   328,   360,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   361,   362,   328,   363,
     364,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   365,   328,   366,   366,   366,   366,
     366,   366,   366,   366,   366,   366,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   368,   368,   369,   369,
     370,   370,   371,   371,   372,   372,   373,   373,   374,   374,
     375,   375,   375,   377,   376,   378,   376,   380,   381,   379,
     379,   383,   382,   384,   382,   385,   382,   387,   386,   388,
     386,   386,   390,   389,   391,   389,   389,   393,   392,   394,
     392,   395,   392,   397,   396,   398,   396,   399,   396,   396,
     401,   400,   402,   400,   403,   400,   400,   405,   404,   406,
     404,   404,   408,   407,   409,   407,   407,   411,   410,   412,
     410,   410,   414,   413,   415,   413,   413,   416,   416,   417,
     417,   418,   418,   419,   419,   419,   419,   419,   419,   419,
     419,   420,   419,   421,   421,   421,   421,   421,   421,   421,
     422,   421,   423,   423,   423,   423,   423,   423,   424,   423,
     425,   425,   425,   425,   425,   425,   425,   426,   425,   427,
     427,   427,   427,   427,   427,   428,   427,   429,   429,   429,
     429,   429,   429,   430,   429,   431,   431,   431,   431,   431,
     431,   432,   431,   433,   433,   433,   433,   433,   434,   433,
     435,   435,   435,   435,   435,   436,   435,   437,   437,   438,
     439,   438,   440,   440,   440,   440,   440,   440,   440
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
       0,     4,     2,     2,     2,     1,     4,     2,     1,     3,
       1,     1,     1,     2,     0,     1,     0,     4,     3,     1,
       3,     0,     2,     1,     1,     2,     2,     1,     1,     0,
       3,     1,     1,     2,     0,     5,     0,     5,     0,     5,
       0,     5,     1,     1,     1,     0,     5,     1,     1,     1,
       2,     0,     5,     4,     1,     2,     1,     2,     1,     2,
       0,     6,     0,     6,     0,     6,     1,     0,     1,     0,
       2,     0,     2,     2,     0,     4,     0,     5,     2,     0,
       0,     5,     2,     0,     0,     5,     2,     0,     0,     5,
       2,     0,     0,     5,     2,     0,     0,     5,     2,     0,
       0,     5,     2,     0,     1,     2,     1,     0,     4,     0,
       5,     2,     2,     1,     1,     1,     0,     5,     0,     4,
       1,     1,     2,     1,     1,     1,     1,     0,     4,     1,
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
       1,     1,     1,     1,     1,     1,     0,     0,     6,     0,
       0,     6,     0,     3,     0,     3,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     3,     0,     3,
       4,     0,     3,     0,     4,     0,     5,     0,     5,     0,
       5,     0,     5,     4,     0,     5,     0,     5,     0,     5,
       0,     5,     3,     3,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       4,     5,     4,     0,     5,     5,     5,     6,     5,     5,
       6,     5,     5,     5,     5,     4,     0,     0,     7,     0,
       0,     8,     4,     5,     5,     5,     4,     5,     2,     2,
       2,     2,     5,     4,     0,     3,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     0,
       1,     1,     1,     0,     4,     0,     4,     0,     0,     6,
       1,     0,     3,     0,     4,     0,     4,     0,     3,     0,
       4,     1,     0,     3,     0,     4,     1,     0,     3,     0,
       4,     0,     4,     0,     3,     0,     3,     0,     4,     1,
       0,     3,     0,     3,     0,     4,     1,     0,     3,     0,
       4,     1,     0,     3,     0,     4,     1,     0,     3,     0,
       4,     1,     0,     3,     0,     4,     1,     2,     0,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     1,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     0,     4,
       1,     1,     1,     1,     1,     0,     4,     2,     1,     1,
       0,     4,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,   544,   106,   107,    73,   452,   471,   575,   574,   466,
       0,     0,     0,   446,     0,     0,     0,   576,     0,     0,
       0,     0,   454,   449,    12,    13,    15,    17,    18,    10,
      20,    21,   473,     8,     0,     2,     6,     5,     4,    91,
       7,   468,     0,     0,     0,     0,     0,     0,     0,     0,
     556,     0,     0,     0,     0,     0,     0,   580,   581,   582,
       0,     0,   526,   484,   490,     0,     0,   486,     0,     0,
     488,   494,   496,   498,   500,   502,   504,   506,   508,   513,
     568,   569,   571,   570,   475,   477,     0,   572,   573,   481,
     479,     0,   538,   539,   540,   541,     0,     0,     0,     0,
       0,     0,   648,     0,     1,     0,     0,   456,   458,   460,
     462,   464,   579,   545,   399,   410,   395,   411,   396,   397,
     398,   401,   400,   402,   403,   404,   405,   406,   407,   408,
     409,   388,   387,   414,   417,   415,   418,   413,   416,   293,
     412,   419,   420,   391,   384,   386,   392,   385,   382,   383,
     380,   381,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   438,   431,   432,   433,   437,   434,   435,   436,   439,
     440,   393,   441,   442,   443,   444,   445,   379,   390,     0,
     389,   289,   290,   394,   291,   292,   421,   684,   687,   685,
     682,   683,   686,   583,   680,   681,   453,   585,   472,   692,
     695,   693,   607,   691,   694,   609,   689,   690,   467,   611,
     529,     0,     0,     0,     0,     0,     0,     0,   564,   565,
     558,   560,   557,   559,   561,   562,   563,     0,   550,   546,
     547,     0,   551,   552,   553,   554,   555,     0,     0,   566,
     567,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     650,   650,     0,     0,     0,   650,   492,   493,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,     0,     0,
     658,   661,   659,   655,   656,   660,   657,   653,   654,   447,
       0,     0,     0,   455,   450,    14,    16,    19,    11,     0,
       9,    92,   591,   593,   469,   595,     0,     0,     0,     0,
       0,   578,     0,     0,   648,   652,   650,   648,     0,   652,
     650,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   549,   548,     0,     0,   543,   525,   532,     0,     0,
       0,     0,   536,   737,   734,   735,   738,   736,   732,   733,
     527,     0,     0,   512,   510,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   730,     0,   728,
     729,     0,   648,   650,     0,     0,   483,   650,   474,   647,
      97,     0,   652,   650,   457,   459,   461,   463,   465,   470,
       0,    74,    29,    31,    32,    34,    33,    35,     0,     0,
       0,     0,   724,   725,   619,   721,   722,   615,   723,   720,
     613,   608,   617,     0,     0,   530,     0,     0,   522,   516,
     518,   521,   519,   515,   524,   523,   542,   534,   537,   533,
     535,     0,   668,   670,   485,   665,   666,   669,   667,   663,
     664,   649,   491,   511,   487,   489,   495,   497,   499,   501,
     503,   505,   507,   509,   514,   648,   476,   727,   478,     0,
       0,   482,   480,     0,     0,   227,   701,   703,   601,   698,
     699,   702,   700,   697,   597,   592,   599,     0,     0,     0,
       0,     0,     0,    37,   688,   587,   678,   590,   674,   675,
     677,   676,   672,   673,   584,   651,   586,   696,   648,     0,
       0,   650,   610,   612,     0,   517,   520,     0,   648,     0,
     662,   448,   451,     0,    99,     0,   226,   109,   648,     0,
     650,   594,   596,    39,    30,     0,    42,    36,     0,     0,
     648,     0,   641,   637,   616,   639,   717,   718,   626,   715,
     620,   622,   716,   713,   714,   614,   624,     0,     0,   528,
       0,   731,     0,    96,     0,     0,     0,   709,   711,   606,
     707,   602,   710,   708,   705,   706,   598,   604,     0,    75,
       0,     0,    41,   588,     0,   726,     0,   650,   648,     0,
       0,   650,   618,   531,   671,    98,   100,     0,     0,    93,
       0,   111,   113,     0,     0,     0,     0,   143,   118,   121,
     125,   128,   132,   135,     0,   108,   704,   648,     0,   650,
     600,   227,    46,     0,     0,     0,    43,    45,    48,     0,
      38,   650,   679,   646,   642,   638,   644,     0,     0,   621,
     631,   627,   623,   629,     0,   145,   340,   343,   341,   344,
     342,   160,   338,   339,     0,   158,   159,   335,   336,   337,
     293,   295,   296,    28,   110,     0,   229,   229,   229,   229,
       0,   294,   297,   298,   299,   231,     0,   155,     0,   153,
       0,     0,   152,   141,     0,   243,   243,   255,   255,   259,
     259,     0,     0,   603,     0,    78,   374,   372,   373,   368,
     369,   375,   376,   370,   371,   365,     0,   274,   275,   366,
     367,    54,    57,    52,     0,     0,     0,    40,     0,     0,
     650,   640,   719,     0,   650,   625,   239,     0,   157,   116,
       0,   228,    25,    26,    24,    22,    23,     0,     0,   234,
     239,   115,   243,   140,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   139,   712,   605,     0,     0,   276,
     239,   174,     0,   247,     0,    44,    47,   589,   643,     0,
     636,   632,   628,   634,     0,     0,   171,   172,   176,   101,
     165,   162,     0,     0,   175,    27,    30,    94,    95,   112,
     230,   233,   114,   232,   231,     0,   154,   103,   117,   229,
     146,     0,   144,   119,   240,   242,   122,   321,   323,   322,
     324,   320,   126,   252,   318,   319,   254,   315,   316,   317,
     129,   311,   133,   312,   314,   310,   313,   256,   308,   309,
     258,   305,   306,   307,   136,     0,    76,     0,    81,     0,
      77,    49,     0,     0,     0,     0,    53,    50,   645,     0,
     650,   630,   236,   161,   238,     0,   170,   164,   181,   168,
     163,     0,   174,     0,   156,   102,   295,   296,   147,   148,
       0,   294,   297,   298,   299,   142,     0,   239,   263,     0,
     239,   263,     0,   239,   263,    83,     0,   247,     0,   280,
       0,    55,     0,   173,    60,    63,    58,   352,   355,   353,
     356,   354,   244,   350,   351,   347,   346,   246,   345,   348,
     349,   633,     0,   239,     0,   179,     0,   229,   167,     0,
     235,     0,     0,   267,   377,   378,   120,     0,   264,   273,
     266,     0,     0,   127,     0,     0,   134,     0,     0,     0,
       0,     0,   278,   277,    56,   239,     0,    51,   251,   239,
     635,     0,   177,     0,   187,   188,   184,   191,   192,     0,
       0,     0,     0,     0,     0,     0,   202,   204,   203,     0,
       0,   207,   208,   209,   214,     0,     0,   189,   183,   169,
       0,   149,   150,   239,   269,   377,   301,   302,   378,   104,
     272,   265,   300,   303,   304,   271,   241,   331,   334,   332,
     123,   330,   333,   260,   328,   329,   262,   325,   326,   327,
     253,   130,   257,   137,    85,    79,   229,    86,    89,    82,
      80,     0,     0,     0,     0,     0,     0,     0,    65,    59,
       0,   237,   178,   185,   186,   193,   194,   210,   198,   200,
     205,   211,     0,   196,   180,   182,     0,   166,     0,   239,
       0,   239,     0,     0,    84,   174,     0,   279,    61,    66,
      67,    71,    69,    62,    64,   248,   362,   363,   359,   358,
     250,   357,   360,   364,   361,   245,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,     0,   287,   286,   190,
     281,   283,   284,   285,   268,     0,   124,     0,   131,   138,
       0,    90,     0,     0,     0,   239,   216,     0,     0,     0,
       0,     0,   219,     0,     0,   213,   217,     0,   239,   282,
     270,   261,     0,     0,     0,     0,     0,   195,   215,   199,
     201,   206,   212,   220,   222,   224,   197,     0,     0,    68,
      72,    70,   249,   239,   239,   239,   288,    87,     0,     0,
       0,     0,   221,   223,   225,    88
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    34,    35,    36,   103,   101,    98,    99,   100,   644,
     381,   382,   383,   384,   385,   518,   386,   561,   517,   560,
     695,   606,   607,   608,   692,   743,   740,   742,   875,   928,
     925,   927,  1007,  1008,  1082,  1084,  1083,    37,    44,   471,
     601,   737,   820,   867,   995,   999,  1035,  1131,  1036,    38,
     105,   370,   769,   455,   503,   504,   836,   778,   906,    39,
     545,   595,   655,   656,   665,   856,   666,   858,  1030,   667,
     859,   668,   861,  1032,   669,   862,   670,   864,  1033,   726,
     664,   781,   848,   849,   661,   658,   722,   720,   634,   635,
     706,   709,   761,   840,   837,   762,   824,   838,   835,   894,
     897,   956,   957,   958,  1026,  1056,  1066,  1057,  1058,  1059,
    1060,  1087,  1064,  1065,  1123,  1124,  1125,   507,   712,   717,
     718,   774,   755,   893,   728,   857,   826,   929,  1009,  1085,
     730,   860,   732,   863,   912,  1031,   907,   908,   963,  1029,
     764,   687,   822,   870,  1001,  1069,  1070,  1098,   834,   909,
     970,   810,   796,   986,   636,   887,  1050,   688,   910,   180,
     181,   182,   183,   184,   185,   186,    40,    86,   363,    97,
     367,    45,    96,   296,   297,   298,   299,   300,    47,   106,
      46,   102,   268,   269,   281,   280,   250,   255,   258,   251,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   249,
     421,   311,   494,    43,   237,   227,   241,    84,    85,    89,
      41,    42,   302,    62,   196,   305,   306,   484,   519,   611,
     294,   371,   372,   373,   465,   509,   510,   556,   598,   599,
     208,   308,   309,   310,   401,   490,   489,   491,   535,   569,
     570,   571,   622,   703,   704,   752,   829,   830,   524,   566,
     567,   615,   699,   700,   289,   341,   389,   369,   362,   431,
     498,   485,   520,   197,   304,   209,   307,   466,   508,   557,
     597,   536,   568,   402,   488,   358,   359,   445,   360
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -959
static const short yypact[] =
{
     893,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    6238,  6200,    69,  -959,   112,   181,     6,  -959,   -36,    19,
      28,    41,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,    75,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,   603,    49,  4513,  6263,  6263,  6272,    37,    52,
     400,    51,   125,   252,   252,   252,   -25,  -959,  -959,  -959,
     133,   252,  -959,  -959,  -959,   162,   -31,  -959,    96,   103,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  6281,  -959,  -959,  -959,
    -959,    97,  -959,  -959,  -959,  -959,  6263,  6281,   241,   250,
     257,   266,  -959,   271,  -959,  4513,  6326,  -959,  -959,  -959,
    -959,  -959,   203,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,   195,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,   240,   252,   252,   252,   252,   252,   252,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,   252,  -959,  -959,
    -959,   256,  -959,  -959,  -959,  -959,  -959,   252,   252,  -959,
    -959,   183,   189,   191,   252,   252,   252,   252,   204,    70,
    -959,  -959,   208,   210,   253,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,   134,   134,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
     134,   134,   215,  -959,  -959,  -959,  -959,  -959,  -959,   513,
    -959,  -959,  -959,  -959,  -959,  -959,  6263,  6326,  6272,  6272,
    6326,  -959,   220,  2762,  -959,  -959,  -959,  -959,  6335,  -959,
    -959,    70,   252,   252,   224,   228,   232,   235,   236,   242,
     258,  -959,  -959,   287,   291,  -959,  -959,  -959,   294,   295,
     299,   301,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  6344,  6353,  -959,  -959,   302,  6398,  6407,  6416,  6425,
    6470,  6479,  6488,  6497,  6542,  6551,  6560,  -959,  6569,  -959,
    -959,  6614,  -959,  -959,  6623,  6632,  -959,  -959,  -959,  -959,
     229,  6641,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    2762,   303,   298,   293,  -959,  -959,  -959,  -959,   598,  6686,
    6695,   656,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  6686,  6704,  -959,   315,   316,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,   252,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,   728,
    6713,  -959,  -959,  6758,  4513,   336,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  6686,  6767,   -52,
    2762,   317,   330,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  6776,
    6785,  -959,  -959,  -959,   252,  -959,  -959,   331,  -959,   816,
    -959,  -959,  -959,   -58,  -959,   322,  -959,  -959,  -959,  6830,
    -959,  -959,  -959,  -959,  -959,  2762,  -959,  -959,  4513,  6281,
    -959,   890,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  6839,   340,  -959,
     936,  -959,  4513,  -959,  2762,   932,  5640,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  6848,   303,
      32,   -51,  -959,  -959,  6109,  -959,  6857,  -959,  -959,  6263,
    6902,  -959,  -959,  -959,  -959,  -959,   303,   341,  4616,  -959,
    2865,  -959,  -959,  2968,  4616,  5028,  4513,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  2968,  -959,  -959,  -959,  6263,  -959,
    -959,   336,  -959,  6048,  3071,  4513,  -959,   329,  -959,  4513,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  6911,  6118,  -959,
    -959,  -959,  -959,  -959,  6920,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  3174,  -959,  -959,  -959,  -959,  -959,
     346,   118,   239,   146,  -959,   325,   -38,   255,   268,   347,
     349,   243,   274,   309,   334,  -959,  6048,  -959,   354,  -959,
    3174,  4719,  -959,  -959,  6048,  -959,  -959,  -959,  -959,  -959,
    -959,   354,  6254,  -959,  6929,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,   345,   342,  -959,  -959,
    -959,  -959,   359,  -959,   350,   366,    31,  -959,  6974,  6263,
    -959,  -959,  -959,  6983,  -959,  -959,  -959,  5272,  -959,  -959,
    2865,  -959,  -959,  -959,  -959,  -959,  -959,  5408,  5340,  -959,
    -959,  -959,  -959,  -959,  5476,  -959,   361,  5340,  3277,  3380,
    3483,  3586,  3689,  3792,  -959,  -959,  -959,    46,  6048,  -959,
    -959,  -959,   364,  -959,  4513,  -959,  -959,  -959,  -959,  6992,
    -959,  -959,  -959,  -959,  7001,  1011,  -959,  -959,  -959,  -959,
    -959,  -959,  5476,  5783,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  1114,  4822,  -959,  -959,   347,
    5680,   372,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,   374,  -959,  6048,  -959,  5028,
    -959,  -959,  6048,  1217,  5849,  3895,  5131,  -959,  -959,  6263,
    -959,  -959,  -959,  -959,  -959,  6048,  -959,  -959,   373,  -959,
    -959,  5476,  -959,  5915,  -959,  -959,  -959,  -959,   375,  -959,
     381,  -959,  -959,  -959,  -959,  -959,  3998,  -959,  -959,  3998,
    -959,  -959,  3998,  -959,  -959,  -959,   376,  -959,  4925,   342,
      22,  -959,  5982,  -959,  -959,   379,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  7046,  -959,   192,  -959,  1143,   347,  -959,  5849,
    -959,  5680,  4513,  -959,  -959,   646,  -959,  6210,   767,  -959,
    -959,  1320,  4101,  -959,  1423,  4204,  -959,  1526,  4307,  5544,
    4410,  5476,  -959,  -959,  -959,  -959,   172,  -959,  -959,  -959,
    -959,  1629,  -959,  6048,  -959,  -959,  -959,  -959,  -959,   367,
     371,   351,   391,   353,   395,   396,  -959,   397,  -959,   398,
     401,  -959,  -959,  -959,  -959,   403,  1048,  -959,  -959,  -959,
    5476,  -959,  -959,  -959,  -959,   730,  -959,  -959,   894,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,   347,  -959,  -959,  -959,
    -959,  6048,  1732,   363,   407,   409,   410,   150,  -959,  5203,
    1835,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,   333,  -959,  -959,  -959,  5612,  -959,  1938,  -959,
    3998,  -959,  3998,  3998,  -959,  -959,  3998,   342,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,   378,   378,   378,   378,
     525,  4513,  4513,  4513,    40,  -959,   378,  -959,  -959,  5612,
    -959,  -959,  -959,  -959,  -959,  2041,  -959,  2144,  -959,  -959,
    5849,  -959,   378,   526,   378,  -959,  -959,   -73,   -66,   -56,
     -55,   399,   414,   415,   416,  -959,  -959,   -41,  -959,  -959,
    -959,  -959,  5982,     8,   419,    30,  2247,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  2350,   408,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  2453,  2556,
    2659,  3998,  -959,  -959,  -959,  -959
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -170,
    -353,  -959,  -959,  -545,  -542,  -959,  -530,  -959,  -959,  -959,
    -959,  -959,  -959,  -155,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -464,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -690,  -959,  -959,     2,  -685,  -376,  -750,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -349,  -263,   -39,  -959,  -959,   -21,  -575,
    -959,  -588,  -959,  -959,  -805,  -755,  -817,  -684,  -959,  -959,
    -959,  -959,  -959,  -397,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -657,  -959,  -498,  -959,  -959,  -959,   -32,  -643,  -203,
     -92,  -959,  -480,  -959,  -609,  -959,  -293,  -959,  -959,  -959,
     -93,  -959,   -87,  -959,  -674,  -959,  -959,  -959,  -959,  -959,
    -110,  -790,  -959,  -959,  -959,  -959,  -489,  -959,   -44,  -559,
    -959,  -959,  -959,  -959,  -509,  -959,  -959,  -959,  -578,  -525,
      35,  -554,  -958,  -439,  -339,  -160,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,   -13,   569,  -959,  -959,
    -959,  -959,  -959,  -959,   -45,  -959,  -959,  -351,  -959,  -959,
     -90,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
      34,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,  -959,
    -959,  -959,  -959,  -959,  -181,  -248,  -264,   -77,  -959,  -959,
    -959,  -959,  -959,  -959,  -959,   -62,  -959,  -446,  -959,  -537,
    -959,  -959,  -959,  -959,  -959,  -109,   -15,  -959,  -189
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -578
static const short yytable[] =
{
     179,   198,   650,   342,   713,   714,   715,   346,   841,   279,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     284,   649,   760,   763,   638,   899,   652,   469,   772,   616,
     638,   638,   869,   602,   244,   646,   898,   782,   647,   777,
     779,   242,   243,   525,   295,   403,  1107,   815,   248,   689,
     648,   283,   492,  1109,   253,   651,   245,   729,   390,   708,
     340,   291,   404,  1110,  1111,   211,   542,   513,  1072,   872,
     721,    91,   723,   609,   543,   104,   662,   470,  1116,   842,
     638,   610,   711,   734,    92,   708,  1108,   228,   229,   230,
     231,   -32,   -32,  1108,   212,   254,   213,   214,   215,   216,
      80,    81,   689,  1108,  1108,   210,   638,   638,   467,   913,
     689,  1072,   916,   776,   217,   450,   511,   514,  1108,   453,
     246,   232,   405,   388,   623,   468,   391,  1119,   603,   603,
     604,   604,   650,   233,   234,   235,   845,    82,    83,    93,
     873,   653,   816,   817,   960,   818,   922,   819,    94,  1121,
     238,   649,   725,   689,   923,  1027,   652,   605,   605,  1095,
     361,    95,   559,   689,   689,   646,   753,  1108,   647,   113,
     689,   364,   365,   689,   638,   638,   798,   798,   812,   812,
     648,   449,    87,    88,   689,   651,   333,   915,   924,  1108,
     918,   576,   334,   335,   336,  1061,  1062,  1063,   252,   314,
     315,   316,   317,   318,   319,   236,   247,   375,   689,   689,
     378,  1037,    80,    81,   320,   873,   256,   969,  1080,   785,
     785,   850,   638,   257,   323,   324,   852,   645,   337,   338,
     339,   328,   329,   330,   331,   295,   777,   779,   295,   639,
     775,   654,   282,   537,   285,   639,   639,  -391,  -391,  -391,
     333,   374,   357,   286,   959,   851,   334,   335,   336,   387,
     823,   287,   558,   689,   499,   638,  -378,   785,   689,   288,
     689,   653,   889,  1043,   290,  -390,  -390,  -390,   239,   240,
    1076,   689,  1078,  1079,   312,   313,  1081,   689,   301,   689,
    1003,  1004,   337,   338,   339,   639,   321,   322,  1005,   406,
     407,   888,   852,   325,  1006,   852,   303,   521,   852,   326,
     662,   327,  1003,  1004,   638,   932,   933,   540,   689,   617,
    1005,   639,   639,   624,   332,  1102,  1006,   546,   343,   971,
     344,   851,   376,   377,   851,   366,   387,   851,   345,   564,
     379,   853,   850,   447,   408,   689,   447,   852,   409,   447,
     447,   674,   410,  1034,   975,   411,   412,   766,   988,   725,
     454,   988,   413,   698,   988,   689,   889,   689,  -392,  -392,
    -392,   654,  -389,  -389,  -389,   711,   851,   911,   414,   689,
     914,  1135,   972,   917,   -34,   -34,   -34,   618,   711,   639,
     639,   799,   799,   813,   813,   888,   873,   -33,   -33,   -33,
    1088,  1089,  1090,  -290,  -290,  -290,   689,   415,   497,  1097,
     505,   416,   218,   931,   417,   418,   672,   853,  1118,   419,
     853,   420,   433,   853,   473,  1103,   387,  1105,   472,   219,
     220,   221,   470,   222,   223,   495,   496,   639,  -291,  -291,
    -291,   854,   563,   690,   515,  1002,   506,   689,   516,  1010,
     544,   539,   749,   696,   710,  1052,   754,   224,   225,   226,
     573,   625,   853,  -292,  -292,  -292,  -377,   711,   973,   716,
     707,   387,   738,   739,   562,   741,   852,   744,   852,   852,
     639,   538,   852,  1028,  1051,   745,   780,   890,  1061,  1062,
    1063,   825,   855,   686,   865,   896,   690,   902,   505,   901,
     387,   926,  1013,   919,   690,   851,  1014,   851,   851,  1016,
    1015,   851,  1017,  1018,  1019,  1020,  1021,   854,  1112,  1022,
     854,  1023,  1039,   854,   619,  1040,   689,  1041,  1042,   639,
    1091,  1104,  1113,  1114,  1115,  1127,   387,  1086,  1120,   659,
     765,   746,   663,  1044,   575,  1000,   719,   690,   689,  1075,
     659,  1077,   961,   673,   719,   671,   868,   690,   690,  1025,
     693,   694,   854,   660,   690,   697,  1096,   690,   974,   675,
    1053,   843,   727,   989,   920,   731,   989,   852,   690,   989,
    1099,   890,   892,   733,    90,     0,     0,  1073,     0,     0,
       0,   853,     0,   853,   853,     0,     0,   853,     0,     0,
       0,     0,   690,   690,     0,  1106,   851,   770,   773,     0,
       0,     0,     0,   637,   107,   108,     0,   773,  1117,   637,
     637,     0,   109,   110,   111,   112,     0,     0,   821,   270,
    1073,   271,   368,   272,     0,   273,   274,   275,     0,     0,
       0,     0,     0,  1128,  1129,  1130,     0,  -105,     0,     0,
       0,     0,     0,     0,   748,     0,     0,   690,     0,     0,
       0,     0,   690,     0,   690,     0,   387,     0,     0,   637,
       0,   276,   277,   278,     0,   690,     0,     0,     0,     0,
       0,   690,     0,   690,     0,     0,     0,     0,     0,     0,
       0,   854,   853,   854,   854,   637,   637,   854,     0,     0,
     827,  -105,     0,     0,     0,     0,     0,   866,     0,     0,
       0,     0,   690,     0,   270,     0,   271,   474,   272,     0,
     273,   274,   275,     0,     0,   895,     0,     0,     0,     0,
       0,   -94,     0,   770,     0,     0,     0,     0,     0,   690,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,   276,   277,   278,   690,
       0,   690,     0,   637,   637,   797,   797,   811,   811,     0,
       0,     0,   270,   690,   271,   487,   272,     0,   273,   274,
     275,   876,     0,     0,   891,   -94,     0,     0,     0,     0,
       0,     0,   854,     0,     0,     0,     0,     0,  -105,     0,
     690,     0,     0,     0,     0,     0,     0,     0,     0,   996,
       0,   637,     0,     0,   276,   277,   278,     0,     0,     0,
       0,     0,   114,  1012,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
       0,   690,     0,     0,   270,     0,   271,   500,   272,  1054,
     273,   274,   275,     0,   637,     0,     0,     0,   962,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
       0,     0,   -94,     0,     0,     0,   276,   277,   278,     0,
       0,     0,     0,    -3,     1,   -95,     0,     0,     0,     2,
       3,     4,     5,   637,  -577,  -577,     6,     0,     7,     8,
       0,     0,  -577,  -577,  -577,  -577,     9,    10,    11,   171,
     690,    12,     0,     0,    13,     0,     0,     0,    14,     0,
       0,     0,   270,   577,   271,   541,   272,     0,   273,   274,
     275,    15,   690,     0,     0,     0,     0,   987,     0,   -95,
     987,     0,     0,   987,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,    21,    22,    23,   276,   277,   278,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,   578,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,     0,     0,   270,     0,   271,   565,
     272,    32,   273,   274,   275,     0,     0,  1092,  1093,  1094,
       0,     0,     0,     0,     0,     0,   579,   580,     0,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,     0,     0,     0,     0,   -95,     0,   276,   277,
     278,    33,   270,     0,   271,   574,   272,     0,   273,   274,
     275,  1071,     0,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,   277,   278,     0,     0,     0,
       0,     0,     0,     0,  1071,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   832,
     833,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   114,
     177,  1024,   178,     0,     0,     0,     0,     0,     0,     0,
       0,   934,   935,   936,   937,   938,   939,   940,   941,   942,
     943,   944,   945,   946,   947,   948,   949,   950,   951,   952,
     953,   954,   955,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   832,   844,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   114,   177,     0,   178,   934,   935,   936,   937,
     938,   939,   940,   941,   942,   943,   944,   945,   946,   947,
     948,   949,   950,   951,   952,   953,   954,   955,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   832,   871,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   114,   177,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   832,   976,
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
     138,   832,   990,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   114,   177,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   832,   992,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   114,   177,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   832,  1011,   139,
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
     832,  1038,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     114,   177,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   832,  1055,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   114,   177,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   832,  1074,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   114,   177,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   832,
    1100,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   114,
     177,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   832,  1101,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   114,   177,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   832,  1122,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   114,   177,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   832,  1126,
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
     138,   832,  1132,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   114,   177,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   832,  1133,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   114,   177,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   832,  1134,   139,
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
     380,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     114,   177,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   380,     0,   640,   140,   141,   142,   641,
     144,   145,   642,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   114,   177,     0,   643,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   657,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   114,   177,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   691,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   114,
     177,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   626,   627,   628,   629,
     707,   630,   631,     0,   632,   633,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   114,   177,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   626,
     627,   628,   629,   783,   630,   784,     0,   632,   633,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   114,   177,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   626,   627,   628,   629,   786,   630,   784,     0,
     632,   633,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   114,   177,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   787,   788,   789,   790,   791,
     792,   793,     0,   794,   795,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   114,   177,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   787,   788,
     789,   790,   791,   800,   793,     0,   794,   795,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   114,   177,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   801,   802,   803,   804,   805,   806,   807,     0,   808,
     809,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   114,   177,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   801,   814,   803,   804,   805,   806,
     807,     0,   808,   809,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     114,   177,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   874,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   114,   177,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   903,     0,   904,   140,
     141,   142,   846,   144,   145,   847,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   114,   177,     0,   905,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   977,   978,   979,   980,   981,   982,   983,
       0,   984,   985,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   114,
     177,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   977,   978,   979,   991,
     981,   982,   983,     0,   984,   985,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   114,   177,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   977,
     978,   979,   993,   981,   982,   983,     0,   984,   985,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   114,   177,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   877,   878,   879,   880,   997,   881,   882,     0,
     883,   884,   141,   142,   885,   144,   145,   998,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   114,   177,
       0,   886,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   114,   177,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   626,   627,
     628,   629,     0,   630,   631,     0,   632,   633,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   114,   177,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   626,   627,   628,   629,   724,   630,     0,     0,   632,
     633,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   114,   177,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   626,   627,   628,   629,     0,   630,
     784,     0,   632,   633,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     114,   177,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   626,   627,   628,
     629,   921,   630,     0,     0,   632,   633,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   114,   177,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     626,   627,   628,   629,     0,   630,     0,     0,   632,   633,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   114,   177,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   877,   878,   879,   880,     0,   881,   882,
       0,   883,   884,   141,   142,   885,   144,   145,   114,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,     0,
     177,     0,   886,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,  1045,     0,  1046,   140,     0,  1047,   114,   144,   145,
    1048,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,     0,   177,     0,  1049,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   676,     0,   756,   677,   757,   678,     0,   679,
       0,     0,     0,     0,   758,   114,     0,   680,   681,   682,
       0,   683,   684,     0,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
       0,   685,     0,   759,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     676,     0,     0,   677,     0,   678,     0,   679,     0,     0,
     767,   771,     0,   114,     0,   680,   681,   682,     0,   683,
     684,     0,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,     0,   685,
       0,   768,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   676,     0,
       0,   677,     0,   678,     0,   679,     0,     0,   767,     0,
       0,   114,     0,   680,   681,   682,     0,   683,   684,     0,
       0,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,   685,     0,   768,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   676,     0,     0,   677,
       0,   678,     0,   679,     0,     0,     0,     0,   758,   114,
       0,   680,   681,   682,     0,   683,   684,     0,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,     0,   685,     0,   759,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   676,     0,     0,   677,     0,   678,
       0,   679,     0,     0,     0,     0,     0,   114,     0,   680,
     681,   682,     0,   683,   684,     0,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,     0,   685,     0,   994,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
    1067,     0,  1068,   140,     0,   114,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,   271,   596,
     272,     0,   273,   274,   275,     0,     0,     0,     0,     0,
       0,   177,     0,   178,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   276,   277,
     278,   140,   141,   142,   846,   144,   145,   847,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   114,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   676,     0,   756,   677,   757,   678,     0,
     679,     0,     0,   839,   114,   758,     0,     0,   680,   681,
     682,     0,   683,   684,     0,     0,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,     0,   685,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   676,
       0,   756,   677,   757,   678,     0,   679,     0,     0,     0,
     114,   758,     0,     0,   680,   681,   682,     0,   683,   684,
       0,     0,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,     0,   685,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   676,     0,     0,   677,     0,
     678,     0,   679,     0,     0,     0,   900,   114,     0,     0,
     680,   681,   682,     0,   683,   684,     0,     0,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,     0,   685,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   676,     0,     0,   677,     0,   678,     0,   679,
       0,     0,     0,   114,   758,     0,     0,   680,   681,   682,
       0,   683,   684,     0,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
       0,   685,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   676,     0,
       0,   677,     0,   678,     0,   679,     0,     0,     0,     0,
       0,     0,     0,   680,   681,   682,     0,   683,   684,     0,
       0,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    63,   685,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,     0,   270,     0,   271,   612,   272,
       0,   273,   274,   275,   270,     0,   271,   702,   272,     0,
     273,   274,   275,     0,     0,    48,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,    49,     0,     0,    50,   276,   277,   278,
       0,     0,     0,    51,     0,     0,   276,   277,   278,     0,
      52,    79,    53,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    56,    57,    58,    59,     0,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,    61,
     131,   132,   133,   134,   135,   136,   137,   138,   964,     0,
     965,   140,   141,   142,   966,   144,   145,   967,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,     0,   172,   173,   174,   175,   176,     0,   177,
     270,   968,   271,   735,   272,     0,   273,   274,   275,   187,
       0,   188,     0,   189,     0,   190,   191,   192,   199,     0,
     200,     0,   201,     0,   202,   203,   204,   270,     0,   271,
       0,   272,     0,   273,   274,   275,     0,     0,     0,     0,
       0,     0,   276,   277,   278,     0,     0,     0,     0,     0,
       0,   193,   194,   195,     0,     0,     0,     0,     0,     0,
     205,   206,   207,     0,     0,     0,     0,     0,     0,   276,
     277,   278,   199,     0,   200,     0,   201,     0,   292,   203,
     204,   392,     0,   393,     0,   394,     0,   395,   396,   397,
     422,     0,   423,     0,   424,     0,   425,   426,   427,   422,
       0,   423,     0,   432,     0,   425,   426,   427,     0,     0,
       0,     0,     0,     0,   293,   206,   207,     0,     0,     0,
       0,     0,     0,   398,   399,   400,     0,     0,     0,     0,
       0,     0,   428,   429,   430,     0,     0,     0,     0,     0,
       0,   428,   429,   430,   422,     0,   423,     0,   434,     0,
     425,   426,   427,   422,     0,   423,     0,   435,     0,   425,
     426,   427,   422,     0,   423,     0,   436,     0,   425,   426,
     427,   422,     0,   423,     0,   437,     0,   425,   426,   427,
       0,     0,     0,     0,     0,     0,   428,   429,   430,     0,
       0,     0,     0,     0,     0,   428,   429,   430,     0,     0,
       0,     0,     0,     0,   428,   429,   430,     0,     0,     0,
       0,     0,     0,   428,   429,   430,   422,     0,   423,     0,
     438,     0,   425,   426,   427,   422,     0,   423,     0,   439,
       0,   425,   426,   427,   422,     0,   423,     0,   440,     0,
     425,   426,   427,   422,     0,   423,     0,   441,     0,   425,
     426,   427,     0,     0,     0,     0,     0,     0,   428,   429,
     430,     0,     0,     0,     0,     0,     0,   428,   429,   430,
       0,     0,     0,     0,     0,     0,   428,   429,   430,     0,
       0,     0,     0,     0,     0,   428,   429,   430,   422,     0,
     423,     0,   442,     0,   425,   426,   427,   422,     0,   423,
       0,   443,     0,   425,   426,   427,   422,     0,   423,     0,
     444,     0,   425,   426,   427,   333,     0,   357,     0,   446,
       0,   334,   335,   336,     0,     0,     0,     0,     0,     0,
     428,   429,   430,     0,     0,     0,     0,     0,     0,   428,
     429,   430,     0,     0,     0,     0,     0,     0,   428,   429,
     430,     0,     0,     0,     0,     0,     0,   337,   338,   339,
     333,     0,   357,     0,   448,     0,   334,   335,   336,   333,
       0,   357,     0,   451,     0,   334,   335,   336,   333,     0,
     357,     0,   452,     0,   334,   335,   336,   456,     0,   457,
       0,   458,     0,   459,   460,   461,     0,     0,     0,     0,
       0,     0,   337,   338,   339,     0,     0,     0,     0,     0,
       0,   337,   338,   339,     0,     0,     0,     0,     0,     0,
     337,   338,   339,     0,     0,     0,     0,     0,     0,   462,
     463,   464,   475,     0,   476,     0,   477,     0,   478,   479,
     480,   422,     0,   423,     0,   486,     0,   425,   426,   427,
     422,     0,   423,     0,   493,     0,   425,   426,   427,   422,
       0,   423,     0,   501,     0,   425,   426,   427,     0,     0,
       0,     0,     0,     0,   481,   482,   483,     0,     0,     0,
       0,     0,     0,   428,   429,   430,     0,     0,     0,     0,
       0,     0,   428,   429,   430,     0,     0,     0,     0,     0,
       0,   428,   429,   430,   422,     0,   423,     0,   502,     0,
     425,   426,   427,   422,     0,   423,     0,   512,     0,   425,
     426,   427,   456,     0,   457,     0,   522,     0,   459,   460,
     461,   526,     0,   527,     0,   528,     0,   529,   530,   531,
       0,     0,     0,     0,     0,     0,   428,   429,   430,     0,
       0,     0,     0,     0,     0,   428,   429,   430,     0,     0,
       0,     0,     0,     0,   462,   463,   523,     0,     0,     0,
       0,     0,     0,   532,   533,   534,   547,     0,   548,     0,
     549,     0,   550,   551,   552,   422,     0,   423,     0,   572,
       0,   425,   426,   427,   422,     0,   423,     0,   600,     0,
     425,   426,   427,   547,     0,   548,     0,   613,     0,   550,
     614,   552,     0,     0,     0,     0,     0,     0,   553,   554,
     555,     0,     0,     0,     0,     0,     0,   428,   429,   430,
       0,     0,     0,     0,     0,     0,   428,   429,   430,     0,
       0,     0,     0,     0,     0,   553,   554,   555,   456,     0,
     457,     0,   620,     0,   459,   460,   461,   422,     0,   423,
       0,   701,     0,   425,   426,   427,   422,     0,   423,     0,
     705,     0,   425,   426,   427,   422,     0,   423,     0,   736,
       0,   425,   426,   427,     0,     0,     0,     0,     0,     0,
     462,   463,   621,     0,     0,     0,     0,     0,     0,   428,
     429,   430,     0,     0,     0,     0,     0,     0,   428,   429,
     430,     0,     0,     0,     0,     0,     0,   428,   429,   430,
     422,     0,   423,     0,   747,     0,   425,   426,   427,   547,
       0,   548,     0,   750,     0,   550,   751,   552,   422,     0,
     423,     0,   828,     0,   425,   426,   427,   422,     0,   423,
       0,   831,     0,   425,   426,   427,     0,     0,     0,     0,
       0,     0,   428,   429,   430,     0,     0,     0,     0,     0,
       0,   553,   554,   555,     0,     0,     0,     0,     0,     0,
     428,   429,   430,     0,     0,     0,     0,     0,     0,   428,
     429,   430,   422,     0,   423,     0,   930,     0,   425,   426,
     427,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   428,   429,   430
};

static const short yycheck[] =
{
      44,    46,   580,   251,   647,   648,   649,   255,   763,    86,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
      97,   580,   707,   707,   578,   842,   580,   380,   718,   566,
     584,   585,   822,     1,    59,   580,   841,   727,   580,   724,
     724,    54,    55,   489,   106,   309,   119,     1,    61,   603,
     580,    96,   403,   119,    85,   580,    81,   666,   306,   634,
     249,   105,   310,   119,   119,    13,   124,   119,  1026,   824,
     658,    65,   660,   124,   132,     0,   585,   129,   119,   763,
     634,   132,   120,   671,   120,   660,   159,    36,    37,    38,
      39,   129,   130,   159,    42,   126,    44,    45,    46,    47,
      31,    32,   656,   159,   159,    68,   660,   661,   372,   859,
     664,  1069,   862,   722,    62,   363,   467,   470,   159,   367,
     145,    70,   311,   304,   570,   373,   307,   119,    97,    97,
      99,    99,   710,    82,    83,    84,   779,    68,    69,   120,
     824,   580,    96,    97,   899,    99,   124,   101,   120,   119,
      25,   710,   661,   707,   132,   960,   710,   126,   126,   119,
     269,   120,   515,   717,   718,   710,   703,   159,   710,   120,
     724,   280,   281,   727,   728,   729,   730,   731,   732,   733,
     710,   362,    70,    71,   738,   710,   116,   861,   872,   159,
     864,   544,   122,   123,   124,   155,   156,   157,    36,   212,
     213,   214,   215,   216,   217,   154,    73,   297,   762,   763,
     300,  1001,    31,    32,   227,   899,   120,   907,  1035,   728,
     729,   780,   776,   120,   237,   238,   780,   580,   158,   159,
     160,   244,   245,   246,   247,   297,   921,   921,   300,   578,
     720,   580,   145,   491,     3,   584,   585,   129,   130,   131,
     116,   296,   118,     3,   897,   780,   122,   123,   124,   303,
     740,     4,   510,   817,   445,   819,   120,   776,   822,     3,
     824,   710,   826,   123,     3,   129,   130,   131,    26,    27,
    1030,   835,  1032,  1033,    44,    45,  1036,   841,    85,   843,
     140,   141,   158,   159,   160,   634,    40,    41,   148,   312,
     313,   826,   856,   120,   154,   859,   111,   488,   862,   120,
     819,   120,   140,   141,   868,   123,   124,   498,   872,   567,
     148,   660,   661,   571,   120,  1080,   154,   508,   120,   907,
     120,   856,   298,   299,   859,   120,   380,   862,    85,   520,
     120,   780,   901,   358,   120,   899,   361,   901,   120,   364,
     365,   599,   120,   996,   908,   120,   120,   710,   912,   868,
     131,   915,   120,   611,   918,   919,   920,   921,   129,   130,
     131,   710,   129,   130,   131,   120,   901,   857,   120,   933,
     860,  1131,   907,   863,   129,   130,   131,   568,   120,   728,
     729,   730,   731,   732,   733,   920,  1080,   129,   130,   131,
    1057,  1058,  1059,   129,   130,   131,   960,   120,   421,  1066,
     454,   120,    12,   893,   120,   120,   597,   856,  1102,   120,
     859,   120,   120,   862,   131,  1082,   470,  1084,   130,    29,
      30,    31,   129,    33,    34,   120,   120,   776,   129,   130,
     131,   780,   519,   603,   127,   925,   110,  1001,   118,   929,
     128,   120,   700,   124,   129,  1009,   704,    57,    58,    59,
     120,   120,   901,   129,   130,   131,   120,   120,   907,   120,
     116,   515,   127,   131,   518,   116,  1030,   127,  1032,  1033,
     819,   494,  1036,   963,  1009,   119,   125,   826,   155,   156,
     157,   127,   120,   603,   120,   122,   656,   116,   542,   124,
     544,   122,   135,   127,   664,  1030,   135,  1032,  1033,   118,
     159,  1036,   159,   118,   118,   118,   118,   856,   119,   118,
     859,   118,   159,   862,   569,   118,  1080,   118,   118,   868,
       5,     5,   118,   118,   118,   127,   580,   159,   119,   583,
     710,   696,   586,  1007,   542,   921,   656,   707,  1102,  1029,
     594,  1031,   901,   598,   664,   594,   819,   717,   718,   956,
     604,   605,   901,   584,   724,   609,  1064,   727,   907,   601,
    1009,   774,   664,   912,   867,   668,   915,  1131,   738,   918,
    1069,   920,   830,   670,    15,    -1,    -1,  1026,    -1,    -1,
      -1,  1030,    -1,  1032,  1033,    -1,    -1,  1036,    -1,    -1,
      -1,    -1,   762,   763,    -1,  1085,  1131,   717,   718,    -1,
      -1,    -1,    -1,   578,    11,    12,    -1,   727,  1098,   584,
     585,    -1,    19,    20,    21,    22,    -1,    -1,   738,   116,
    1069,   118,   119,   120,    -1,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,  1123,  1124,  1125,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,   699,    -1,    -1,   817,    -1,    -1,
      -1,    -1,   822,    -1,   824,    -1,   710,    -1,    -1,   634,
      -1,   158,   159,   160,    -1,   835,    -1,    -1,    -1,    -1,
      -1,   841,    -1,   843,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1030,  1131,  1032,  1033,   660,   661,  1036,    -1,    -1,
     744,    55,    -1,    -1,    -1,    -1,    -1,   817,    -1,    -1,
      -1,    -1,   872,    -1,   116,    -1,   118,   119,   120,    -1,
     122,   123,   124,    -1,    -1,   835,    -1,    -1,    -1,    -1,
      -1,     1,    -1,   843,    -1,    -1,    -1,    -1,    -1,   899,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   158,   159,   160,   919,
      -1,   921,    -1,   728,   729,   730,   731,   732,   733,    -1,
      -1,    -1,   116,   933,   118,   119,   120,    -1,   122,   123,
     124,   825,    -1,    -1,   829,    55,    -1,    -1,    -1,    -1,
      -1,    -1,  1131,    -1,    -1,    -1,    -1,    -1,   152,    -1,
     960,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   919,
      -1,   776,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    55,   933,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      -1,  1001,    -1,    -1,   116,    -1,   118,   119,   120,  1009,
     122,   123,   124,    -1,   819,    -1,    -1,    -1,   902,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,   158,   159,   160,    -1,
      -1,    -1,    -1,     0,     1,     1,    -1,    -1,    -1,     6,
       7,     8,     9,   868,    11,    12,    13,    -1,    15,    16,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,   152,
    1080,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,
      -1,    -1,   116,     1,   118,   119,   120,    -1,   122,   123,
     124,    48,  1102,    -1,    -1,    -1,    -1,   912,    -1,    55,
     915,    -1,    -1,   918,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    80,   158,   159,   160,    -1,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    55,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,    -1,   116,    -1,   118,   119,
     120,   118,   122,   123,   124,    -1,    -1,  1061,  1062,  1063,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,   152,    -1,   158,   159,
     160,   158,   116,    -1,   118,   119,   120,    -1,   122,   123,
     124,  1026,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1069,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    55,
     159,   123,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    55,   159,    -1,   161,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
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
     117,    -1,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    55,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,    -1,   120,   121,   122,   123,
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
     112,   113,   114,   115,    -1,   117,    -1,    -1,   120,   121,
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
      -1,   120,   121,   122,   123,   124,   125,   126,    55,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    -1,   161,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,   120,   121,    -1,   123,    55,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    -1,   159,    -1,   161,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,   112,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    55,    -1,   125,   126,   127,
      -1,   129,   130,    -1,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    -1,   161,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,
     120,   121,    -1,    55,    -1,   125,   126,   127,    -1,   129,
     130,    -1,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    -1,   159,
      -1,   161,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,   113,    -1,   115,    -1,   117,    -1,    -1,   120,    -1,
      -1,    55,    -1,   125,   126,   127,    -1,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    -1,   159,    -1,   161,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,   113,
      -1,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,    55,
      -1,   125,   126,   127,    -1,   129,   130,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    -1,   159,    -1,   161,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,   113,    -1,   115,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    55,    -1,   125,
     126,   127,    -1,   129,   130,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,    -1,   161,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,   120,   121,    -1,    55,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,   119,
     120,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   161,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   158,   159,
     160,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    55,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,   112,   113,   114,   115,    -1,
     117,    -1,    -1,   120,    55,   122,    -1,    -1,   125,   126,
     127,    -1,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    -1,   159,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,   112,   113,   114,   115,    -1,   117,    -1,    -1,    -1,
      55,   122,    -1,    -1,   125,   126,   127,    -1,   129,   130,
      -1,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    -1,   159,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,   113,    -1,
     115,    -1,   117,    -1,    -1,    -1,   121,    55,    -1,    -1,
     125,   126,   127,    -1,   129,   130,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    -1,   159,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,   113,    -1,   115,    -1,   117,
      -1,    -1,    -1,    55,   122,    -1,    -1,   125,   126,   127,
      -1,   129,   130,    -1,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,    -1,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     6,   159,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,   116,    -1,   118,   119,   120,
      -1,   122,   123,   124,   116,    -1,   118,   119,   120,    -1,
     122,   123,   124,    -1,    -1,     7,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    25,    -1,    -1,    28,   158,   159,   160,
      -1,    -1,    -1,    35,    -1,    -1,   158,   159,   160,    -1,
      42,    81,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,   153,   154,   155,   156,   157,    -1,   159,
     116,   161,   118,   119,   120,    -1,   122,   123,   124,   116,
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
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    15,    16,    23,
      24,    25,    28,    31,    35,    48,    64,    74,    75,    76,
      77,    78,    79,    80,    86,    87,    88,    89,    90,    91,
      92,    93,   118,   158,   163,   164,   165,   199,   211,   221,
     328,   372,   373,   365,   200,   333,   342,   340,     7,    25,
      28,    35,    42,    44,    48,    63,    65,    66,    67,    68,
      72,    81,   375,     6,     8,    23,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    81,
      31,    32,    68,    69,   369,   370,   329,    70,    71,   371,
     369,    65,   120,   120,   120,   120,   334,   331,   168,   169,
     170,   167,   343,   166,     0,   212,   341,    11,    12,    19,
      20,    21,    22,   120,    55,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   159,   161,   310,
     321,   322,   323,   324,   325,   326,   327,   116,   118,   120,
     122,   123,   124,   158,   159,   160,   376,   425,   376,   116,
     118,   120,   122,   123,   124,   158,   159,   160,   392,   427,
      68,    13,    42,    44,    45,    46,    47,    62,    12,    29,
      30,    31,    33,    34,    57,    58,    59,   367,    36,    37,
      38,    39,    70,    82,    83,    84,   154,   366,    25,    26,
      27,   368,   368,   368,    59,    81,   145,    73,   368,   361,
     348,   351,    36,    85,   126,   349,   120,   120,   350,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   344,   345,
     116,   118,   120,   122,   123,   124,   158,   159,   160,   419,
     347,   346,   145,   376,   419,     3,     3,     4,     3,   416,
       3,   310,   122,   158,   382,   427,   335,   336,   337,   338,
     339,    85,   374,   111,   426,   377,   378,   428,   393,   394,
     395,   363,    44,    45,   368,   368,   368,   368,   368,   368,
     368,    40,    41,   368,   368,   120,   120,   120,   368,   368,
     368,   368,   120,   116,   122,   123,   124,   158,   159,   160,
     440,   417,   417,   120,   120,    85,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   118,   437,   438,
     440,   437,   420,   330,   437,   437,   120,   332,   119,   419,
     213,   383,   384,   385,   376,   382,   392,   392,   382,   120,
     118,   172,   173,   174,   175,   176,   178,   310,   416,   418,
     417,   416,   116,   118,   120,   122,   123,   124,   158,   159,
     160,   396,   435,   418,   417,   440,   368,   368,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   362,   116,   118,   120,   122,   123,   124,   158,   159,
     160,   421,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   439,   120,   438,   120,   416,
     417,   120,   120,   417,   131,   215,   116,   118,   120,   122,
     123,   124,   158,   159,   160,   386,   429,   418,   417,   172,
     129,   201,   130,   131,   119,   116,   118,   120,   122,   123,
     124,   158,   159,   160,   379,   423,   120,   119,   436,   398,
     397,   399,   379,   120,   364,   120,   120,   368,   422,   416,
     119,   120,   120,   216,   217,   310,   110,   279,   430,   387,
     388,   379,   120,   119,   172,   127,   118,   180,   177,   380,
     424,   416,   120,   160,   410,   429,   116,   118,   120,   122,
     123,   124,   158,   159,   160,   400,   433,   417,   368,   120,
     416,   119,   124,   132,   128,   222,   416,   116,   118,   120,
     122,   123,   124,   158,   159,   160,   389,   431,   417,   172,
     181,   179,   310,   419,   416,   119,   411,   412,   434,   401,
     402,   403,   120,   120,   119,   217,   172,     1,    55,    94,
      95,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   152,   223,   119,   432,   390,   391,
     120,   202,     1,    97,    99,   126,   183,   184,   185,   124,
     132,   381,   119,   120,   123,   413,   431,   417,   416,   376,
     120,   160,   404,   429,   417,   120,   112,   113,   114,   115,
     117,   118,   120,   121,   250,   251,   316,   322,   323,   326,
     120,   124,   127,   161,   171,   172,   175,   176,   178,   311,
     320,   321,   323,   325,   326,   224,   225,   118,   247,   310,
     250,   246,   316,   310,   242,   226,   228,   231,   233,   236,
     238,   247,   416,   376,   417,   279,   110,   113,   115,   117,
     125,   126,   127,   129,   130,   159,   302,   303,   319,   323,
     327,   118,   186,   310,   310,   182,   124,   310,   417,   414,
     415,   120,   119,   405,   406,   120,   252,   116,   251,   253,
     129,   120,   280,   280,   280,   280,   120,   281,   282,   302,
     249,   253,   248,   253,   116,   316,   241,   282,   286,   286,
     292,   292,   294,   294,   253,   119,   120,   203,   127,   131,
     188,   116,   189,   187,   127,   119,   185,   120,   376,   417,
     120,   123,   407,   431,   417,   284,   112,   114,   122,   161,
     218,   254,   257,   259,   302,   171,   172,   120,   161,   214,
     302,   121,   214,   302,   283,   284,   286,   218,   219,   259,
     125,   243,   214,   116,   118,   316,   116,   112,   113,   114,
     115,   116,   117,   118,   120,   121,   314,   322,   323,   326,
     117,   112,   113,   114,   115,   116,   117,   118,   120,   121,
     313,   322,   323,   326,   113,     1,    96,    97,    99,   101,
     204,   302,   304,   284,   258,   127,   288,   310,   120,   408,
     409,   120,   118,   119,   310,   260,   218,   256,   259,   120,
     255,   257,   259,   281,   119,   280,   124,   127,   244,   245,
     311,   321,   323,   325,   326,   120,   227,   287,   229,   232,
     293,   234,   237,   295,   239,   120,   302,   205,   246,   303,
     305,   119,   257,   259,   118,   190,   310,   112,   113,   114,
     115,   117,   118,   120,   121,   124,   161,   317,   321,   323,
     326,   376,   417,   285,   261,   302,   122,   262,   256,   258,
     121,   124,   116,   118,   120,   161,   220,   298,   299,   311,
     320,   284,   296,   220,   284,   296,   220,   284,   296,   127,
     288,   116,   124,   132,   259,   192,   122,   193,   191,   289,
     120,   284,   123,   124,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   263,   264,   265,   280,
     257,   245,   310,   300,   118,   120,   124,   127,   161,   214,
     312,   320,   321,   325,   326,   323,   119,   112,   113,   114,
     115,   116,   117,   118,   120,   121,   315,   322,   323,   326,
     119,   115,   119,   115,   161,   206,   302,   116,   127,   207,
     219,   306,   284,   140,   141,   148,   154,   194,   195,   290,
     284,   119,   302,   135,   135,   159,   118,   159,   118,   118,
     118,   118,   118,   118,   123,   265,   266,   256,   284,   301,
     230,   297,   235,   240,   280,   208,   210,   303,   119,   159,
     118,   118,   118,   123,   195,   118,   120,   123,   127,   161,
     318,   321,   323,   325,   327,   119,   267,   269,   270,   271,
     272,   155,   156,   157,   274,   275,   268,   118,   120,   307,
     308,   322,   324,   325,   119,   284,   220,   284,   220,   220,
     258,   220,   196,   198,   197,   291,   159,   273,   273,   273,
     273,     5,   310,   310,   310,   119,   275,   273,   309,   308,
     119,   119,   257,   273,     5,   273,   284,   119,   159,   119,
     119,   119,   119,   118,   118,   118,   119,   284,   259,   119,
     119,   119,   119,   276,   277,   278,   119,   127,   284,   284,
     284,   209,   119,   119,   119,   220
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
#line 776 "surface.yy"
    {;}
    break;

  case 164:
#line 782 "surface.yy"
    {
			  if (yyvsp[-1].yyBool)
			    CM->convertSortsToKinds();
			;}
    break;

  case 165:
#line 787 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) <<
				       ": missing " << QUOTE("->") << " in constant declaration.");
			;}
    break;

  case 166:
#line 795 "surface.yy"
    {
			  if (yyvsp[-1].yyBool)
			    CM->convertSortsToKinds();
			;}
    break;

  case 167:
#line 800 "surface.yy"
    {
			  if (yyvsp[-1].yyBool)
			    CM->convertSortsToKinds();
			;}
    break;

  case 168:
#line 805 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
			  ": missing " << QUOTE("->") << " in constant declaration.");
			;}
    break;

  case 171:
#line 815 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 172:
#line 816 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 175:
#line 824 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  currentSyntaxContainer->addType(false, bubble);
			;}
    break;

  case 176:
#line 829 "surface.yy"
    { clear(); ;}
    break;

  case 177:
#line 831 "surface.yy"
    {
			  currentSyntaxContainer->addType(true, bubble);
			;}
    break;

  case 178:
#line 836 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 179:
#line 837 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 180:
#line 840 "surface.yy"
    {;}
    break;

  case 184:
#line 849 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			;}
    break;

  case 185:
#line 853 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			;}
    break;

  case 186:
#line 857 "surface.yy"
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			;}
    break;

  case 187:
#line 863 "surface.yy"
    {
			  CM->setFlag(SymbolType::ASSOC);
			;}
    break;

  case 188:
#line 867 "surface.yy"
    {
			  CM->setFlag(SymbolType::COMM);
			;}
    break;

  case 189:
#line 870 "surface.yy"
    { clear(); ;}
    break;

  case 190:
#line 871 "surface.yy"
    { CM->setIdentity(bubble); ;}
    break;

  case 191:
#line 873 "surface.yy"
    {
			  CM->setFlag(SymbolType::IDEM);
			;}
    break;

  case 192:
#line 877 "surface.yy"
    {
			  CM->setFlag(SymbolType::ITER);
			;}
    break;

  case 193:
#line 880 "surface.yy"
    { CM->setPrec(yyvsp[0].yyToken); ;}
    break;

  case 194:
#line 881 "surface.yy"
    { clear(); ;}
    break;

  case 195:
#line 882 "surface.yy"
    { CM->setGather(bubble); ;}
    break;

  case 196:
#line 883 "surface.yy"
    { clear(); ;}
    break;

  case 197:
#line 884 "surface.yy"
    { CM->setFormat(bubble); ;}
    break;

  case 198:
#line 885 "surface.yy"
    { clear(); ;}
    break;

  case 199:
#line 886 "surface.yy"
    { CM->setStrat(bubble); ;}
    break;

  case 200:
#line 887 "surface.yy"
    { clear(); ;}
    break;

  case 201:
#line 888 "surface.yy"
    { CM->setPoly(bubble); ;}
    break;

  case 202:
#line 890 "surface.yy"
    {
			  CM->setFlag(SymbolType::MEMO);
			;}
    break;

  case 203:
#line 894 "surface.yy"
    {
			  CM->setFlag(SymbolType::CTOR);
			;}
    break;

  case 204:
#line 898 "surface.yy"
    {
			  clear();
			  CM->setFrozen(bubble);
			;}
    break;

  case 205:
#line 902 "surface.yy"
    { clear(); ;}
    break;

  case 206:
#line 903 "surface.yy"
    { CM->setFrozen(bubble); ;}
    break;

  case 207:
#line 905 "surface.yy"
    {
			  CM->setFlag(SymbolType::CONFIG);
			;}
    break;

  case 208:
#line 909 "surface.yy"
    {
			  CM->setFlag(SymbolType::OBJECT);
			;}
    break;

  case 209:
#line 913 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 210:
#line 917 "surface.yy"
    {
			  CM->setMetadata(yyvsp[0].yyToken);
			;}
    break;

  case 211:
#line 920 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 212:
#line 921 "surface.yy"
    { CM->setLatexMacro(yyvsp[-1].yyString); ;}
    break;

  case 213:
#line 922 "surface.yy"
    {;}
    break;

  case 214:
#line 924 "surface.yy"
    {
			  CM->setFlag(SymbolType::DITTO);
			;}
    break;

  case 215:
#line 929 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 216:
#line 930 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 219:
#line 938 "surface.yy"
    {
			  clear();
			  CM->addHook(PreModule::ID_HOOK, yyvsp[0].yyToken, bubble);
			;}
    break;

  case 220:
#line 942 "surface.yy"
    { clear(); ;}
    break;

  case 221:
#line 944 "surface.yy"
    {
			  CM->addHook(PreModule::ID_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 222:
#line 947 "surface.yy"
    { clear(); ;}
    break;

  case 223:
#line 949 "surface.yy"
    {
			  CM->addHook(PreModule::OP_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 224:
#line 952 "surface.yy"
    { clear(); ;}
    break;

  case 225:
#line 954 "surface.yy"
    {
			  CM->addHook(PreModule::TERM_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 226:
#line 962 "surface.yy"
    {;}
    break;

  case 227:
#line 964 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing " <<
				       QUOTE("is") << " keyword.");
			;}
    break;

  case 228:
#line 970 "surface.yy"
    {;}
    break;

  case 229:
#line 972 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			;}
    break;

  case 230:
#line 980 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 232:
#line 984 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 233:
#line 985 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 234:
#line 986 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 235:
#line 987 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 236:
#line 993 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 237:
#line 994 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 238:
#line 995 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 240:
#line 999 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 241:
#line 1000 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 242:
#line 1001 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 244:
#line 1005 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 245:
#line 1006 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 246:
#line 1007 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 248:
#line 1011 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 249:
#line 1012 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 250:
#line 1013 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 252:
#line 1017 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 253:
#line 1018 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 254:
#line 1019 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 256:
#line 1023 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 257:
#line 1024 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 258:
#line 1025 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 260:
#line 1029 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 261:
#line 1030 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 262:
#line 1031 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 265:
#line 1036 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 266:
#line 1037 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 267:
#line 1040 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 268:
#line 1041 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 269:
#line 1042 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 270:
#line 1043 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 271:
#line 1044 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 272:
#line 1045 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 273:
#line 1046 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 274:
#line 1053 "surface.yy"
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

  case 275:
#line 1064 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 276:
#line 1065 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 277:
#line 1066 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 278:
#line 1069 "surface.yy"
    { fragStore(yyvsp[0].yyToken); ;}
    break;

  case 279:
#line 1070 "surface.yy"
    {;}
    break;

  case 280:
#line 1071 "surface.yy"
    {;}
    break;

  case 281:
#line 1077 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 282:
#line 1078 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 287:
#line 1082 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 288:
#line 1083 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 446:
#line 1188 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 447:
#line 1189 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 448:
#line 1191 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.setCurrentModule(bubble);
			;}
    break;

  case 449:
#line 1195 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 450:
#line 1196 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 451:
#line 1198 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->dump();
			;}
    break;

  case 452:
#line 1204 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 453:
#line 1210 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(bubble);
			;}
    break;

  case 454:
#line 1217 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 455:
#line 1223 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(bubble);
			;}
    break;

  case 456:
#line 1230 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 457:
#line 1236 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(bubble, yyvsp[-3].yyBool);
			;}
    break;

  case 458:
#line 1243 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 459:
#line 1250 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(bubble, number, yyvsp[-3].yyBool);
			;}
    break;

  case 460:
#line 1256 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 461:
#line 1264 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 462:
#line 1270 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 463:
#line 1278 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 464:
#line 1284 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 465:
#line 1291 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(bubble, number, yyvsp[-3].yyBool);
			;}
    break;

  case 466:
#line 1297 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 467:
#line 1305 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(bubble, number, number2);
			;}
    break;

  case 468:
#line 1311 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 469:
#line 1318 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(bubble, yyvsp[-2].yyBool, number);
			;}
    break;

  case 470:
#line 1324 "surface.yy"
    {
			  interpreter.cont(yyvsp[-1].yyInt64, yyvsp[-3].yyBool);
			;}
    break;

  case 471:
#line 1328 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 472:
#line 1334 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(bubble);
			;}
    break;

  case 473:
#line 1339 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 474:
#line 1341 "surface.yy"
    {
			  lexerInitialMode();
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(bubble);
			;}
    break;

  case 475:
#line 1348 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 476:
#line 1350 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 477:
#line 1354 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 478:
#line 1356 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude(yyvsp[-3].yyBool);
			;}
    break;

  case 479:
#line 1360 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 480:
#line 1362 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 481:
#line 1366 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 482:
#line 1368 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal(yyvsp[-3].yyBool);
			;}
    break;

  case 483:
#line 1373 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			;}
    break;

  case 484:
#line 1380 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 485:
#line 1382 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 486:
#line 1387 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 487:
#line 1389 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 488:
#line 1394 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 489:
#line 1396 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showModule(true);
			;}
    break;

  case 490:
#line 1401 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 491:
#line 1403 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentView(bubble))
			    interpreter.showView();
			;}
    break;

  case 492:
#line 1409 "surface.yy"
    {
			  interpreter.showModules(true);
			;}
    break;

  case 493:
#line 1413 "surface.yy"
    {
			  interpreter.showNamedViews();
			;}
    break;

  case 494:
#line 1416 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 495:
#line 1418 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSortsAndSubsorts();
			;}
    break;

  case 496:
#line 1423 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 497:
#line 1425 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showOps();
			;}
    break;

  case 498:
#line 1430 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 499:
#line 1432 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showVars();
			;}
    break;

  case 500:
#line 1437 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 501:
#line 1439 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showMbs();
			;}
    break;

  case 502:
#line 1444 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 503:
#line 1446 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showEqs();
			;}
    break;

  case 504:
#line 1451 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 505:
#line 1453 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showRls();
			;}
    break;

  case 506:
#line 1458 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 507:
#line 1460 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSummary();
			;}
    break;

  case 508:
#line 1465 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 509:
#line 1467 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showKinds();
			;}
    break;

  case 510:
#line 1473 "surface.yy"
    {
			  interpreter.showSearchPath(yyvsp[-1].yyInt64);
			;}
    break;

  case 511:
#line 1477 "surface.yy"
    {
			  interpreter.showSearchPathLabels(yyvsp[-1].yyInt64);
			;}
    break;

  case 512:
#line 1481 "surface.yy"
    {
			  interpreter.showSearchGraph();
			;}
    break;

  case 513:
#line 1484 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 514:
#line 1486 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showProfile();
			;}
    break;

  case 515:
#line 1495 "surface.yy"
    {
			  globalAdvisoryFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 516:
#line 1499 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 517:
#line 1503 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 518:
#line 1507 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 519:
#line 1511 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, yyvsp[-1].yyBool);
			;}
    break;

  case 520:
#line 1515 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 521:
#line 1519 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, yyvsp[-1].yyBool);
			;}
    break;

  case 522:
#line 1523 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 523:
#line 1527 "surface.yy"
    {
			  interpreter.setPrintFlag(yyvsp[-2].yyPrintFlags, yyvsp[-1].yyBool);
			;}
    break;

  case 524:
#line 1531 "surface.yy"
    {
			  interpreter.setFlag(yyvsp[-2].yyFlags, yyvsp[-1].yyBool);
			;}
    break;

  case 525:
#line 1535 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, yyvsp[-1].yyBool);
			;}
    break;

  case 526:
#line 1538 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 527:
#line 1539 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 528:
#line 1541 "surface.yy"
    {
			  interpreter.setAutoImport(yyvsp[-5].yyImportMode, yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 529:
#line 1544 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 530:
#line 1545 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 531:
#line 1547 "surface.yy"
    {
			  interpreter.setOmodInclude(yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 532:
#line 1551 "surface.yy"
    {
			  globalVerboseFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 533:
#line 1555 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, yyvsp[-1].yyBool);
			;}
    break;

  case 534:
#line 1559 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, yyvsp[-1].yyBool);
			;}
    break;

  case 535:
#line 1563 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, yyvsp[-1].yyBool);
			;}
    break;

  case 536:
#line 1567 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 537:
#line 1571 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 538:
#line 1578 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			;}
    break;

  case 539:
#line 1582 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			;}
    break;

  case 540:
#line 1586 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			;}
    break;

  case 541:
#line 1590 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			;}
    break;

  case 542:
#line 1597 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 543:
#line 1601 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 544:
#line 1607 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 546:
#line 1614 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_MIXFIX; ;}
    break;

  case 547:
#line 1615 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_FLAT; ;}
    break;

  case 548:
#line 1616 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_WITH_ALIASES; ;}
    break;

  case 549:
#line 1617 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_WITH_PARENS; ;}
    break;

  case 550:
#line 1618 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_GRAPH; ;}
    break;

  case 551:
#line 1619 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_CONCEAL; ;}
    break;

  case 552:
#line 1620 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_NUMBER; ;}
    break;

  case 553:
#line 1621 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_RAT; ;}
    break;

  case 554:
#line 1622 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_COLOR; ;}
    break;

  case 555:
#line 1623 "surface.yy"
    { yyval.yyPrintFlags = Interpreter::PRINT_FORMAT; ;}
    break;

  case 556:
#line 1626 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE; ;}
    break;

  case 557:
#line 1627 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_CONDITION; ;}
    break;

  case 558:
#line 1628 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_WHOLE; ;}
    break;

  case 559:
#line 1629 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_SUBSTITUTION; ;}
    break;

  case 560:
#line 1630 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_SELECT; ;}
    break;

  case 561:
#line 1631 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_MB; ;}
    break;

  case 562:
#line 1632 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_EQ; ;}
    break;

  case 563:
#line 1633 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_RL; ;}
    break;

  case 564:
#line 1634 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_REWRITE; ;}
    break;

  case 565:
#line 1635 "surface.yy"
    { yyval.yyFlags = Interpreter::TRACE_BODY; ;}
    break;

  case 566:
#line 1638 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 567:
#line 1639 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 568:
#line 1642 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 569:
#line 1643 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 570:
#line 1646 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 571:
#line 1647 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 572:
#line 1650 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 573:
#line 1651 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 574:
#line 1654 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 575:
#line 1655 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 576:
#line 1658 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 577:
#line 1659 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 578:
#line 1662 "surface.yy"
    { yyval.yyInt64 = yyvsp[0].yyInt64; ;}
    break;

  case 579:
#line 1663 "surface.yy"
    { yyval.yyInt64 = NONE; ;}
    break;

  case 580:
#line 1666 "surface.yy"
    { yyval.yyImportMode = ImportModule::PROTECTING; ;}
    break;

  case 581:
#line 1667 "surface.yy"
    { yyval.yyImportMode = ImportModule::EXTENDING; ;}
    break;

  case 582:
#line 1668 "surface.yy"
    { yyval.yyImportMode = ImportModule::INCLUDING; ;}
    break;

  case 583:
#line 1676 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 585:
#line 1678 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 587:
#line 1682 "surface.yy"
    { moduleExpr = bubble; clear(); ;}
    break;

  case 588:
#line 1683 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 589:
#line 1684 "surface.yy"
    {;}
    break;

  case 590:
#line 1685 "surface.yy"
    {;}
    break;

  case 591:
#line 1695 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 593:
#line 1697 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 595:
#line 1699 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 597:
#line 1704 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 599:
#line 1706 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 601:
#line 1708 "surface.yy"
    {;}
    break;

  case 602:
#line 1713 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 604:
#line 1718 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 606:
#line 1720 "surface.yy"
    {;}
    break;

  case 607:
#line 1733 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 609:
#line 1735 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 611:
#line 1737 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 613:
#line 1746 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 615:
#line 1748 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 617:
#line 1750 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 619:
#line 1752 "surface.yy"
    {;}
    break;

  case 620:
#line 1761 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 622:
#line 1766 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 624:
#line 1768 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 626:
#line 1770 "surface.yy"
    {;}
    break;

  case 627:
#line 1778 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 629:
#line 1780 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 631:
#line 1782 "surface.yy"
    {;}
    break;

  case 632:
#line 1791 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  number2 = Token::codeToInt64(bubble[3].code());
			  clear();
			;}
    break;

  case 634:
#line 1797 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 636:
#line 1799 "surface.yy"
    {;}
    break;

  case 637:
#line 1807 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 639:
#line 1809 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 641:
#line 1811 "surface.yy"
    {;}
    break;

  case 642:
#line 1820 "surface.yy"
    {
			  number2 = Token::codeToInt64(bubble[2].code());
			  clear();
			;}
    break;

  case 644:
#line 1825 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 646:
#line 1827 "surface.yy"
    {;}
    break;

  case 647:
#line 1833 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 649:
#line 1837 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 651:
#line 1842 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 661:
#line 1850 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 662:
#line 1851 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 670:
#line 1855 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 671:
#line 1856 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 678:
#line 1861 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 679:
#line 1862 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 687:
#line 1866 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 688:
#line 1867 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 695:
#line 1871 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 696:
#line 1872 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 703:
#line 1877 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 704:
#line 1878 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 711:
#line 1883 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 712:
#line 1884 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 718:
#line 1889 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 719:
#line 1890 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 725:
#line 1895 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 726:
#line 1896 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 729:
#line 1906 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  interpreter.addSelected(bubble);
			;}
    break;

  case 730:
#line 1911 "surface.yy"
    { clear(); ;}
    break;

  case 731:
#line 1913 "surface.yy"
    {
			  interpreter.addSelected(bubble);
			;}
    break;


    }

/* Line 999 of yacc.c.  */
#line 6399 "surface.c"

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


#line 1943 "surface.yy"


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

