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
     KW_PARSE = 263,
     KW_NORMALIZE = 264,
     KW_REDUCE = 265,
     KW_REWRITE = 266,
     KW_LOOP = 267,
     KW_NARROW = 268,
     KW_MATCH = 269,
     KW_XMATCH = 270,
     KW_UNIFY = 271,
     KW_XUNIFY = 272,
     KW_EREWRITE = 273,
     KW_FREWRITE = 274,
     KW_OREWRITE = 275,
     KW_CONTINUE = 276,
     KW_SEARCH = 277,
     KW_SET = 278,
     KW_SHOW = 279,
     KW_ON = 280,
     KW_OFF = 281,
     KW_TRACE = 282,
     KW_CONTEXT = 283,
     KW_WHOLE = 284,
     KW_SELECT = 285,
     KW_DESELECT = 286,
     KW_CONDITION = 287,
     KW_SUBSTITUTION = 288,
     KW_PRINT = 289,
     KW_GRAPH = 290,
     KW_MIXFIX = 291,
     KW_FLAT = 292,
     KW_WITH = 293,
     KW_PARENS = 294,
     KW_ALIASES = 295,
     KW_GC = 296,
     KW_TIME = 297,
     KW_STATS = 298,
     KW_TIMING = 299,
     KW_CMD = 300,
     KW_BREAKDOWN = 301,
     KW_BREAK = 302,
     KW_PATH = 303,
     KW_MODULE = 304,
     KW_MODULES = 305,
     KW_ALL = 306,
     KW_SORTS = 307,
     KW_OPS = 308,
     KW_VARS = 309,
     KW_MBS = 310,
     KW_EQS = 311,
     KW_RLS = 312,
     KW_SUMMARY = 313,
     KW_KINDS = 314,
     KW_ADVISE = 315,
     KW_VERBOSE = 316,
     KW_DO = 317,
     KW_CLEAR = 318,
     KW_PROTECT = 319,
     KW_EXTEND = 320,
     KW_INCLUDE = 321,
     KW_EXCLUDE = 322,
     KW_CONCEAL = 323,
     KW_REVEAL = 324,
     KW_COMPILE = 325,
     KW_COUNT = 326,
     KW_DEBUG = 327,
     KW_RESUME = 328,
     KW_ABORT = 329,
     KW_STEP = 330,
     KW_WHERE = 331,
     KW_CREDUCE = 332,
     KW_DUMP = 333,
     KW_PROFILE = 334,
     KW_NUMBER = 335,
     KW_RAT = 336,
     KW_COLOR = 337,
     SIMPLE_NUMBER = 338,
     KW_PWD = 339,
     KW_CD = 340,
     KW_PUSHD = 341,
     KW_POPD = 342,
     KW_LS = 343,
     KW_LOAD = 344,
     KW_QUIT = 345,
     KW_EOF = 346,
     KW_ENDM = 347,
     KW_IMPORT = 348,
     KW_SORT = 349,
     KW_SUBSORT = 350,
     KW_OP = 351,
     KW_MSGS = 352,
     KW_VAR = 353,
     KW_CLASS = 354,
     KW_SUBCLASS = 355,
     KW_MB = 356,
     KW_CMB = 357,
     KW_EQ = 358,
     KW_CEQ = 359,
     KW_RL = 360,
     KW_CRL = 361,
     KW_IS = 362,
     KW_ARROW = 363,
     KW_ARROW2 = 364,
     KW_PARTIAL = 365,
     KW_IF = 366,
     KW_LABEL = 367,
     KW_TO = 368,
     KW_ASSOC = 369,
     KW_COMM = 370,
     KW_ID = 371,
     KW_IDEM = 372,
     KW_ITER = 373,
     KW_LEFT = 374,
     KW_RIGHT = 375,
     KW_PREC = 376,
     KW_GATHER = 377,
     KW_METADATA = 378,
     KW_STRAT = 379,
     KW_POLY = 380,
     KW_MEMO = 381,
     KW_FROZEN = 382,
     KW_CTOR = 383,
     KW_LATEX = 384,
     KW_SPECIAL = 385,
     KW_CONFIG = 386,
     KW_OBJ = 387,
     KW_MSG = 388,
     KW_DITTO = 389,
     KW_FORMAT = 390,
     KW_ID_HOOK = 391,
     KW_OP_HOOK = 392,
     KW_TERM_HOOK = 393,
     KW_IN = 394,
     IDENTIFIER = 395,
     NUMERIC_ID = 396,
     ENDS_IN_DOT = 397
   };
#endif
#define FILE_NAME_STRING 258
#define UNINTERPRETED_STRING 259
#define LATEX_STRING 260
#define KW_MOD 261
#define KW_OMOD 262
#define KW_PARSE 263
#define KW_NORMALIZE 264
#define KW_REDUCE 265
#define KW_REWRITE 266
#define KW_LOOP 267
#define KW_NARROW 268
#define KW_MATCH 269
#define KW_XMATCH 270
#define KW_UNIFY 271
#define KW_XUNIFY 272
#define KW_EREWRITE 273
#define KW_FREWRITE 274
#define KW_OREWRITE 275
#define KW_CONTINUE 276
#define KW_SEARCH 277
#define KW_SET 278
#define KW_SHOW 279
#define KW_ON 280
#define KW_OFF 281
#define KW_TRACE 282
#define KW_CONTEXT 283
#define KW_WHOLE 284
#define KW_SELECT 285
#define KW_DESELECT 286
#define KW_CONDITION 287
#define KW_SUBSTITUTION 288
#define KW_PRINT 289
#define KW_GRAPH 290
#define KW_MIXFIX 291
#define KW_FLAT 292
#define KW_WITH 293
#define KW_PARENS 294
#define KW_ALIASES 295
#define KW_GC 296
#define KW_TIME 297
#define KW_STATS 298
#define KW_TIMING 299
#define KW_CMD 300
#define KW_BREAKDOWN 301
#define KW_BREAK 302
#define KW_PATH 303
#define KW_MODULE 304
#define KW_MODULES 305
#define KW_ALL 306
#define KW_SORTS 307
#define KW_OPS 308
#define KW_VARS 309
#define KW_MBS 310
#define KW_EQS 311
#define KW_RLS 312
#define KW_SUMMARY 313
#define KW_KINDS 314
#define KW_ADVISE 315
#define KW_VERBOSE 316
#define KW_DO 317
#define KW_CLEAR 318
#define KW_PROTECT 319
#define KW_EXTEND 320
#define KW_INCLUDE 321
#define KW_EXCLUDE 322
#define KW_CONCEAL 323
#define KW_REVEAL 324
#define KW_COMPILE 325
#define KW_COUNT 326
#define KW_DEBUG 327
#define KW_RESUME 328
#define KW_ABORT 329
#define KW_STEP 330
#define KW_WHERE 331
#define KW_CREDUCE 332
#define KW_DUMP 333
#define KW_PROFILE 334
#define KW_NUMBER 335
#define KW_RAT 336
#define KW_COLOR 337
#define SIMPLE_NUMBER 338
#define KW_PWD 339
#define KW_CD 340
#define KW_PUSHD 341
#define KW_POPD 342
#define KW_LS 343
#define KW_LOAD 344
#define KW_QUIT 345
#define KW_EOF 346
#define KW_ENDM 347
#define KW_IMPORT 348
#define KW_SORT 349
#define KW_SUBSORT 350
#define KW_OP 351
#define KW_MSGS 352
#define KW_VAR 353
#define KW_CLASS 354
#define KW_SUBCLASS 355
#define KW_MB 356
#define KW_CMB 357
#define KW_EQ 358
#define KW_CEQ 359
#define KW_RL 360
#define KW_CRL 361
#define KW_IS 362
#define KW_ARROW 363
#define KW_ARROW2 364
#define KW_PARTIAL 365
#define KW_IF 366
#define KW_LABEL 367
#define KW_TO 368
#define KW_ASSOC 369
#define KW_COMM 370
#define KW_ID 371
#define KW_IDEM 372
#define KW_ITER 373
#define KW_LEFT 374
#define KW_RIGHT 375
#define KW_PREC 376
#define KW_GATHER 377
#define KW_METADATA 378
#define KW_STRAT 379
#define KW_POLY 380
#define KW_MEMO 381
#define KW_FROZEN 382
#define KW_CTOR 383
#define KW_LATEX 384
#define KW_SPECIAL 385
#define KW_CONFIG 386
#define KW_OBJ 387
#define KW_MSG 388
#define KW_DITTO 389
#define KW_FORMAT 390
#define KW_ID_HOOK 391
#define KW_OP_HOOK 392
#define KW_TERM_HOOK 393
#define KW_IN 394
#define IDENTIFIER 395
#define NUMERIC_ID 396
#define ENDS_IN_DOT 397




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
#include "moduleExpression.hh"
#include "fileTable.hh"
#include "directoryManager.hh"
#include "preModule.hh"
#include "visibleModule.hh"  // HACK
#include "userLevelRewritingContext.hh"
#include "interpreter.hh"

#include "main.hh"
#define clear()		bubble.contractTo(0);
#define store(token)	bubble.append(token)
#define YYPARSE_PARAM	parseResult
#define PARSE_RESULT	(*((UserLevelRewritingContext::ParseResult*) parseResult))

#define CM		interpreter.getCurrentModule()

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
#line 89 "surface.yy"
typedef union YYSTYPE {
  bool yyBool;
  Int64 yyInt64;
  const char* yyString;
  Token yyToken;
  ImportModule::ImportMode yyImportMode;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 427 "surface.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 97 "surface.yy"

int yylex(YYSTYPE* lvalp);


/* Line 214 of yacc.c.  */
#line 442 "surface.c"

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
#define YYFINAL  99
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6158

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  155
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  236
/* YYNRULES -- Number of rules. */
#define YYNRULES  675
/* YYNRULES -- Number of states. */
#define YYNSTATES  1048

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   397

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     114,   115,   125,   124,   120,     2,   116,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   112,     2,
     117,   113,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   118,     2,   119,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   121,     2,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   111,   122,   123,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    12,    13,    17,
      18,    22,    24,    25,    29,    30,    34,    36,    37,    41,
      43,    45,    48,    52,    54,    56,    60,    64,    68,    70,
      71,    76,    80,    82,    87,    92,    99,   100,   104,   105,
     110,   115,   116,   119,   120,   122,   123,   128,   129,   133,
     134,   139,   143,   144,   147,   149,   152,   153,   159,   160,
     166,   167,   173,   174,   175,   183,   185,   187,   189,   192,
     194,   197,   199,   201,   203,   206,   207,   210,   211,   216,
     217,   222,   226,   230,   235,   236,   237,   244,   245,   246,
     247,   257,   258,   259,   266,   267,   268,   269,   279,   280,
     281,   288,   289,   290,   291,   301,   305,   309,   310,   316,
     317,   322,   325,   327,   330,   332,   336,   340,   343,   345,
     346,   350,   351,   356,   359,   361,   363,   364,   369,   374,
     378,   380,   382,   384,   387,   388,   390,   391,   396,   400,
     402,   406,   407,   410,   412,   414,   417,   420,   422,   424,
     425,   429,   431,   433,   436,   437,   443,   444,   450,   451,
     457,   458,   464,   466,   468,   470,   471,   477,   479,   481,
     483,   486,   487,   493,   498,   500,   503,   505,   508,   510,
     513,   514,   521,   522,   529,   530,   537,   540,   541,   544,
     547,   548,   553,   554,   560,   563,   564,   565,   571,   574,
     575,   576,   582,   585,   586,   587,   593,   596,   597,   598,
     604,   607,   608,   609,   615,   618,   619,   620,   626,   629,
     630,   632,   635,   637,   638,   643,   644,   650,   653,   656,
     658,   660,   663,   665,   667,   669,   671,   672,   677,   679,
     681,   683,   685,   687,   689,   691,   693,   695,   697,   699,
     701,   703,   705,   707,   709,   711,   713,   715,   717,   719,
     721,   723,   725,   727,   729,   731,   733,   735,   737,   739,
     741,   743,   745,   747,   749,   751,   753,   755,   757,   759,
     761,   763,   765,   767,   769,   771,   773,   775,   777,   779,
     781,   783,   785,   787,   789,   791,   793,   795,   797,   799,
     801,   803,   805,   807,   809,   811,   813,   815,   817,   819,
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
    1021,  1022,  1023,  1030,  1031,  1032,  1039,  1040,  1044,  1045,
    1049,  1050,  1055,  1056,  1061,  1062,  1067,  1068,  1073,  1074,
    1078,  1079,  1083,  1088,  1089,  1093,  1094,  1099,  1100,  1106,
    1107,  1113,  1114,  1120,  1121,  1127,  1132,  1133,  1139,  1140,
    1146,  1147,  1153,  1157,  1158,  1164,  1165,  1171,  1172,  1178,
    1179,  1185,  1186,  1192,  1193,  1199,  1200,  1206,  1207,  1213,
    1218,  1224,  1229,  1230,  1236,  1242,  1248,  1255,  1261,  1267,
    1274,  1280,  1286,  1292,  1298,  1305,  1312,  1318,  1324,  1330,
    1336,  1342,  1348,  1353,  1359,  1365,  1371,  1377,  1383,  1389,
    1395,  1401,  1406,  1407,  1408,  1416,  1417,  1418,  1427,  1432,
    1438,  1444,  1450,  1455,  1461,  1464,  1467,  1470,  1473,  1479,
    1484,  1485,  1489,  1491,  1493,  1495,  1497,  1499,  1501,  1503,
    1505,  1507,  1509,  1511,  1512,  1514,  1515,  1517,  1519,  1521,
    1522,  1527,  1528,  1533,  1534,  1535,  1542,  1544,  1545,  1549,
    1550,  1555,  1556,  1561,  1562,  1566,  1567,  1572,  1574,  1575,
    1579,  1580,  1585,  1587,  1588,  1592,  1593,  1598,  1599,  1604,
    1605,  1609,  1610,  1615,  1617,  1618,  1622,  1623,  1627,  1628,
    1633,  1635,  1636,  1640,  1641,  1646,  1648,  1649,  1653,  1654,
    1659,  1661,  1664,  1665,  1668,  1669,  1672,  1673,  1675,  1677,
    1679,  1681,  1683,  1685,  1687,  1689,  1690,  1695,  1697,  1699,
    1701,  1703,  1705,  1707,  1709,  1710,  1715,  1717,  1719,  1721,
    1723,  1725,  1727,  1728,  1733,  1735,  1737,  1739,  1741,  1743,
    1745,  1747,  1748,  1753,  1755,  1757,  1759,  1761,  1763,  1765,
    1766,  1771,  1773,  1775,  1777,  1779,  1781,  1783,  1784,  1789,
    1791,  1793,  1795,  1797,  1799,  1801,  1802,  1807,  1809,  1811,
    1813,  1815,  1817,  1818,  1823,  1826,  1828,  1830,  1831,  1836,
    1838,  1840,  1842,  1844,  1846,  1848
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     156,     0,    -1,   157,    -1,    -1,   187,    -1,   158,    -1,
     291,    -1,    -1,   151,   159,     3,    -1,    -1,    89,   160,
       3,    -1,    84,    -1,    -1,    85,   161,     3,    -1,    -1,
      86,   162,     3,    -1,    87,    -1,    -1,    88,   163,     4,
      -1,    90,    -1,    91,    -1,   166,   116,    -1,   165,   124,
     164,    -1,   154,    -1,   166,    -1,   165,   124,   165,    -1,
     114,   165,   115,    -1,   166,   125,   167,    -1,   274,    -1,
      -1,   114,   168,   169,   115,    -1,   169,   120,   170,    -1,
     170,    -1,    94,   283,   123,   283,    -1,   122,   274,   123,
     274,    -1,    96,   171,   174,   123,   178,   181,    -1,    -1,
     274,   172,   257,    -1,    -1,   114,   173,   253,   115,    -1,
     112,   175,   228,   176,    -1,    -1,   175,   176,    -1,    -1,
     283,    -1,    -1,   118,   177,   232,   119,    -1,    -1,   274,
     179,   259,    -1,    -1,   114,   180,   253,   115,    -1,   118,
     182,   119,    -1,    -1,   182,   183,    -1,   183,    -1,   133,
     152,    -1,    -1,   134,   114,   184,   244,   115,    -1,    -1,
     147,   114,   185,   244,   115,    -1,    -1,   141,   114,   186,
       5,   115,    -1,    -1,    -1,   194,   188,   274,   107,   189,
     195,    92,    -1,   116,    -1,   154,    -1,   154,    -1,   230,
     116,    -1,   191,    -1,   267,   190,    -1,   154,    -1,     6,
      -1,     7,    -1,   195,   196,    -1,    -1,    93,   164,    -1,
      -1,    94,   197,   250,   190,    -1,    -1,    95,   198,   251,
     190,    -1,    96,   220,   226,    -1,    53,   223,   226,    -1,
      98,   219,   112,   192,    -1,    -1,    -1,   101,   199,   255,
     112,   200,   193,    -1,    -1,    -1,    -1,   102,   201,   255,
     112,   202,   265,   111,   203,   193,    -1,    -1,    -1,   103,
     204,   261,   113,   205,   193,    -1,    -1,    -1,    -1,   104,
     206,   261,   113,   207,   265,   111,   208,   193,    -1,    -1,
      -1,   105,   209,   263,   109,   210,   193,    -1,    -1,    -1,
      -1,   106,   211,   263,   109,   212,   265,   111,   213,   193,
      -1,   145,   220,   226,    -1,    97,   223,   226,    -1,    -1,
      99,   274,   214,   216,   116,    -1,    -1,   100,   215,   251,
     190,    -1,     1,   116,    -1,   121,    -1,   121,   217,    -1,
     218,    -1,   217,   120,   218,    -1,   275,   112,   274,    -1,
     219,   280,    -1,   280,    -1,    -1,   274,   221,   255,    -1,
      -1,   114,   222,   253,   115,    -1,   223,   224,    -1,   224,
      -1,   280,    -1,    -1,   114,   225,   253,   115,    -1,   112,
     229,   228,   227,    -1,   230,   233,   116,    -1,   191,    -1,
     108,    -1,   110,    -1,   229,   230,    -1,    -1,   283,    -1,
      -1,   118,   231,   232,   119,    -1,   232,   120,   283,    -1,
     283,    -1,   118,   234,   119,    -1,    -1,   234,   236,    -1,
     236,    -1,   128,    -1,   131,   128,    -1,   132,   128,    -1,
     126,    -1,   127,    -1,    -1,   235,   237,   271,    -1,   129,
      -1,   130,    -1,   133,   152,    -1,    -1,   134,   114,   238,
     244,   115,    -1,    -1,   147,   114,   239,   244,   115,    -1,
      -1,   136,   114,   240,   244,   115,    -1,    -1,   137,   114,
     241,   244,   115,    -1,   138,    -1,   140,    -1,   139,    -1,
      -1,   139,   114,   242,   244,   115,    -1,   143,    -1,   144,
      -1,   145,    -1,   135,   152,    -1,    -1,   141,   114,   243,
       5,   115,    -1,   142,   114,   245,   115,    -1,   146,    -1,
     244,   152,    -1,   152,    -1,   245,   246,    -1,   246,    -1,
     148,   274,    -1,    -1,   148,   274,   114,   247,   253,   115,
      -1,    -1,   149,   274,   114,   248,   253,   115,    -1,    -1,
     150,   274,   114,   249,   253,   115,    -1,   250,   283,    -1,
      -1,   251,   283,    -1,   251,   117,    -1,    -1,   283,   252,
     250,   117,    -1,    -1,   253,   114,   254,   253,   115,    -1,
     253,   274,    -1,    -1,    -1,   255,   114,   256,   253,   115,
      -1,   255,   280,    -1,    -1,    -1,   257,   114,   258,   253,
     115,    -1,   257,   281,    -1,    -1,    -1,   259,   114,   260,
     253,   115,    -1,   259,   282,    -1,    -1,    -1,   261,   114,
     262,   253,   115,    -1,   261,   278,    -1,    -1,    -1,   263,
     114,   264,   253,   115,    -1,   263,   277,    -1,    -1,    -1,
     265,   114,   266,   253,   115,    -1,   265,   279,    -1,    -1,
     268,    -1,   267,   284,    -1,   284,    -1,    -1,   114,   269,
     253,   115,    -1,    -1,   267,   114,   270,   253,   115,    -1,
     268,   286,    -1,   267,   276,    -1,   275,    -1,   272,    -1,
     271,   272,    -1,   285,    -1,   287,    -1,   288,    -1,   116,
      -1,    -1,   114,   273,   253,   115,    -1,   285,    -1,   286,
      -1,   288,    -1,   289,    -1,   116,    -1,   152,    -1,   120,
      -1,   121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,
      -1,   286,    -1,   288,    -1,   289,    -1,   152,    -1,   120,
      -1,   121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,
      -1,   288,    -1,   289,    -1,   285,    -1,   286,    -1,   289,
      -1,   116,    -1,   117,    -1,   112,    -1,   108,    -1,   110,
      -1,   113,    -1,   111,    -1,   107,    -1,   285,    -1,   286,
      -1,   289,    -1,   116,    -1,   117,    -1,   112,    -1,   108,
      -1,   110,    -1,   109,    -1,   111,    -1,   107,    -1,   285,
      -1,   286,    -1,   289,    -1,   116,    -1,   117,    -1,   112,
      -1,   108,    -1,   110,    -1,   113,    -1,   109,    -1,   107,
      -1,   285,    -1,   286,    -1,   289,    -1,   116,    -1,   117,
      -1,   108,    -1,   110,    -1,   113,    -1,   109,    -1,   111,
      -1,   107,    -1,   152,    -1,   154,    -1,   120,    -1,   121,
      -1,   122,    -1,   124,    -1,   125,    -1,   286,    -1,   289,
      -1,   116,    -1,   117,    -1,   108,    -1,   110,    -1,   113,
      -1,   109,    -1,   111,    -1,   107,    -1,   152,    -1,   154,
      -1,   121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,
      -1,   286,    -1,   290,    -1,   116,    -1,   119,    -1,   288,
      -1,   152,    -1,   286,    -1,   290,    -1,   113,    -1,   121,
      -1,   124,    -1,   125,    -1,   109,    -1,   111,    -1,   107,
      -1,   122,    -1,   123,    -1,   116,    -1,   154,    -1,   152,
      -1,   154,    -1,   120,    -1,   121,    -1,   122,    -1,   123,
      -1,   124,    -1,   125,    -1,   145,    -1,   287,    -1,    93,
      -1,    94,    -1,    95,    -1,    96,    -1,    53,    -1,    98,
      -1,    97,    -1,    99,    -1,   100,    -1,   101,    -1,   102,
      -1,   103,    -1,   104,    -1,   105,    -1,   106,    -1,    92,
      -1,   117,    -1,   112,    -1,   108,    -1,   110,    -1,   113,
      -1,   109,    -1,   111,    -1,   107,    -1,   118,    -1,   119,
      -1,   290,    -1,   126,    -1,   127,    -1,   128,    -1,   129,
      -1,   130,    -1,   131,    -1,   132,    -1,   133,    -1,   134,
      -1,   136,    -1,   137,    -1,   138,    -1,   140,    -1,   141,
      -1,   142,    -1,   139,    -1,   135,    -1,   143,    -1,   144,
      -1,   146,    -1,   147,    -1,   148,    -1,   149,    -1,   150,
      -1,    -1,    -1,    30,   292,   371,   293,   369,   116,    -1,
      -1,    -1,    78,   294,   371,   295,   369,   116,    -1,    -1,
       8,   296,   335,    -1,    -1,    77,   297,   335,    -1,    -1,
     332,    10,   298,   335,    -1,    -1,   332,    11,   299,   341,
      -1,    -1,   332,    18,   300,   341,    -1,    -1,   332,    19,
     301,   351,    -1,    -1,    22,   302,   341,    -1,    -1,   331,
     303,   341,    -1,   332,    21,   333,   116,    -1,    -1,    12,
     304,   335,    -1,    -1,   114,   305,   368,   115,    -1,    -1,
      27,   328,   306,   387,   116,    -1,    -1,    27,   329,   307,
     387,   116,    -1,    -1,    47,   328,   308,   387,   116,    -1,
      -1,    34,   330,   309,   387,   116,    -1,    62,    63,   138,
     116,    -1,    -1,    24,     6,   310,   369,   116,    -1,    -1,
      24,    49,   311,   369,   116,    -1,    -1,    24,    51,   312,
     369,   116,    -1,    24,    50,   116,    -1,    -1,    24,    52,
     313,   369,   116,    -1,    -1,    24,    53,   314,   369,   116,
      -1,    -1,    24,    54,   315,   369,   116,    -1,    -1,    24,
      55,   316,   369,   116,    -1,    -1,    24,    56,   317,   369,
     116,    -1,    -1,    24,    57,   318,   369,   116,    -1,    -1,
      24,    58,   319,   369,   116,    -1,    -1,    24,    59,   320,
     369,   116,    -1,    24,    48,    83,   116,    -1,    24,    48,
     122,    83,   116,    -1,    24,    22,    35,   116,    -1,    -1,
      24,    79,   321,   369,   116,    -1,    23,    24,    60,   327,
     116,    -1,    23,    24,    43,   327,   116,    -1,    23,    24,
      12,    43,   327,   116,    -1,    23,    24,    44,   327,   116,
      -1,    23,    24,    46,   327,   116,    -1,    23,    24,    12,
      44,   327,   116,    -1,    23,    24,    45,   327,   116,    -1,
      23,    24,    41,   327,   116,    -1,    23,    34,    36,   327,
     116,    -1,    23,    34,    37,   327,   116,    -1,    23,    34,
      38,    40,   327,   116,    -1,    23,    34,    38,    39,   327,
     116,    -1,    23,    34,    35,   327,   116,    -1,    23,    34,
      68,   327,   116,    -1,    23,    34,    80,   327,   116,    -1,
      23,    34,    81,   327,   116,    -1,    23,    34,    82,   327,
     116,    -1,    23,    34,   147,   327,   116,    -1,    23,    27,
     327,   116,    -1,    23,    27,    32,   327,   116,    -1,    23,
      27,    28,   327,   116,    -1,    23,    27,    29,   327,   116,
      -1,    23,    27,    33,   327,   116,    -1,    23,    27,    30,
     327,   116,    -1,    23,    27,    55,   327,   116,    -1,    23,
      27,    56,   327,   116,    -1,    23,    27,    57,   327,   116,
      -1,    23,    47,   327,   116,    -1,    -1,    -1,    23,   334,
     322,   390,   323,   327,   116,    -1,    -1,    -1,    23,     7,
      66,   324,   390,   325,   327,   116,    -1,    23,    61,   327,
     116,    -1,    23,    63,   138,   327,   116,    -1,    23,    63,
      57,   327,   116,    -1,    23,    70,    71,   327,   116,    -1,
      23,    79,   327,   116,    -1,    23,    63,    79,   327,   116,
      -1,    73,   116,    -1,    74,   116,    -1,    75,   116,    -1,
      76,   116,    -1,    23,    41,    24,   327,   116,    -1,    23,
      43,   327,   116,    -1,    -1,     1,   326,   116,    -1,    25,
      -1,    26,    -1,    30,    -1,    31,    -1,    67,    -1,    66,
      -1,    68,    -1,    69,    -1,    15,    -1,    14,    -1,    72,
      -1,    -1,    83,    -1,    -1,    64,    -1,    65,    -1,    66,
      -1,    -1,   151,   336,   370,   338,    -1,    -1,   377,   337,
     369,   116,    -1,    -1,    -1,   112,   339,   371,   340,   369,
     116,    -1,   116,    -1,    -1,   118,   342,   345,    -1,    -1,
     151,   343,   370,   338,    -1,    -1,   379,   344,   369,   116,
      -1,    -1,   153,   346,   348,    -1,    -1,   381,   347,   369,
     116,    -1,   116,    -1,    -1,   119,   349,   335,    -1,    -1,
     383,   350,   369,   116,    -1,   116,    -1,    -1,   118,   352,
     355,    -1,    -1,   151,   353,   370,   338,    -1,    -1,   379,
     354,   369,   116,    -1,    -1,   153,   356,   358,    -1,    -1,
     381,   357,   369,   116,    -1,   116,    -1,    -1,   119,   359,
     335,    -1,    -1,   120,   360,   362,    -1,    -1,   385,   361,
     369,   116,    -1,   116,    -1,    -1,   153,   363,   365,    -1,
      -1,   381,   364,   369,   116,    -1,   116,    -1,    -1,   119,
     366,   335,    -1,    -1,   383,   367,   369,   116,    -1,   116,
      -1,   368,   371,    -1,    -1,   369,   373,    -1,    -1,   370,
     375,    -1,    -1,   152,    -1,   153,    -1,   118,    -1,   119,
      -1,   151,    -1,   112,    -1,   116,    -1,   120,    -1,    -1,
     114,   372,   368,   115,    -1,   152,    -1,   153,    -1,   118,
      -1,   119,    -1,   151,    -1,   112,    -1,   120,    -1,    -1,
     114,   374,   368,   115,    -1,   152,    -1,   153,    -1,   118,
      -1,   119,    -1,   151,    -1,   120,    -1,    -1,   114,   376,
     368,   115,    -1,   152,    -1,   153,    -1,   118,    -1,   119,
      -1,   112,    -1,   116,    -1,   120,    -1,    -1,   114,   378,
     368,   115,    -1,   152,    -1,   153,    -1,   119,    -1,   112,
      -1,   116,    -1,   120,    -1,    -1,   114,   380,   368,   115,
      -1,   152,    -1,   118,    -1,   119,    -1,   151,    -1,   112,
      -1,   120,    -1,    -1,   114,   382,   368,   115,    -1,   152,
      -1,   153,    -1,   118,    -1,   151,    -1,   112,    -1,   120,
      -1,    -1,   114,   384,   368,   115,    -1,   152,    -1,   153,
      -1,   118,    -1,   151,    -1,   112,    -1,    -1,   114,   386,
     368,   115,    -1,   387,   388,    -1,   388,    -1,   390,    -1,
      -1,   114,   389,   368,   115,    -1,   152,    -1,   153,    -1,
     118,    -1,   119,    -1,   151,    -1,   112,    -1,   120,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   196,   196,   198,   203,   204,   205,   211,   211,   221,
     221,   231,   235,   235,   246,   246,   257,   268,   268,   273,
     278,   311,   312,   320,   330,   331,   341,   342,   349,   359,
     358,   365,   366,   369,   373,   377,   380,   380,   385,   385,
     392,   393,   396,   397,   400,   406,   406,   413,   413,   415,
     415,   419,   420,   423,   424,   427,   428,   428,   430,   430,
     432,   432,   439,   441,   439,   453,   454,   464,   476,   477,
     480,   481,   491,   491,   494,   495,   498,   505,   505,   508,
     508,   511,   513,   515,   517,   518,   517,   521,   522,   523,
     521,   526,   527,   526,   530,   531,   532,   530,   535,   536,
     535,   539,   540,   541,   539,   544,   549,   555,   554,   561,
     561,   564,   575,   576,   579,   580,   583,   588,   589,   592,
     592,   594,   594,   598,   599,   602,   608,   608,   612,   619,
     620,   623,   624,   627,   628,   631,   637,   637,   644,   645,
     648,   649,   652,   653,   656,   660,   664,   670,   674,   678,
     678,   680,   684,   688,   689,   689,   691,   691,   693,   693,
     695,   695,   697,   701,   705,   710,   710,   712,   716,   720,
     724,   728,   728,   730,   731,   737,   738,   741,   742,   745,
     750,   750,   755,   755,   760,   760,   770,   771,   774,   775,
     776,   776,   783,   783,   785,   786,   789,   789,   791,   792,
     795,   795,   797,   798,   801,   801,   803,   804,   807,   807,
     809,   810,   813,   813,   815,   816,   819,   819,   821,   822,
     825,   826,   827,   830,   830,   832,   832,   834,   835,   836,
     842,   843,   846,   846,   846,   846,   847,   847,   854,   854,
     854,   854,   854,   857,   857,   857,   857,   857,   857,   857,
     858,   858,   858,   861,   861,   861,   861,   861,   861,   861,
     862,   862,   865,   865,   865,   865,   866,   866,   866,   866,
     866,   866,   866,   869,   869,   869,   869,   870,   870,   870,
     870,   870,   870,   870,   873,   873,   873,   873,   874,   874,
     874,   874,   874,   874,   874,   877,   877,   877,   877,   878,
     878,   878,   878,   878,   878,   878,   881,   881,   881,   881,
     881,   881,   881,   882,   882,   882,   883,   883,   883,   883,
     883,   883,   883,   886,   886,   886,   886,   886,   886,   886,
     887,   887,   887,   887,   887,   890,   890,   890,   891,   891,
     891,   891,   892,   892,   892,   892,   892,   895,   895,   901,
     901,   901,   901,   901,   901,   901,   901,   904,   904,   907,
     907,   907,   907,   907,   907,   908,   908,   908,   909,   909,
     909,   909,   909,   909,   909,   912,   912,   912,   912,   912,
     912,   912,   912,   915,   915,   915,   918,   918,   918,   918,
     918,   918,   918,   919,   919,   919,   919,   919,   919,   920,
     920,   920,   920,   921,   921,   921,   921,   922,   922,   922,
     949,   950,   949,   956,   957,   956,   965,   964,   978,   977,
     991,   990,  1004,  1003,  1017,  1016,  1031,  1030,  1045,  1044,
    1058,  1057,  1070,  1075,  1074,  1086,  1086,  1095,  1095,  1101,
    1101,  1107,  1107,  1113,  1113,  1119,  1127,  1127,  1134,  1134,
    1141,  1141,  1148,  1152,  1152,  1159,  1159,  1166,  1166,  1173,
    1173,  1180,  1180,  1187,  1187,  1194,  1194,  1201,  1201,  1208,
    1212,  1216,  1220,  1220,  1230,  1234,  1238,  1242,  1246,  1250,
    1254,  1258,  1262,  1266,  1270,  1274,  1278,  1282,  1286,  1290,
    1294,  1298,  1302,  1306,  1310,  1314,  1318,  1322,  1326,  1330,
    1334,  1338,  1342,  1343,  1342,  1348,  1349,  1348,  1354,  1358,
    1362,  1366,  1370,  1374,  1381,  1385,  1389,  1393,  1400,  1404,
    1411,  1411,  1418,  1419,  1422,  1423,  1426,  1427,  1430,  1431,
    1434,  1435,  1438,  1439,  1442,  1443,  1446,  1447,  1448,  1456,
    1456,  1458,  1458,  1462,  1463,  1462,  1465,  1474,  1474,  1476,
    1476,  1478,  1478,  1483,  1483,  1485,  1485,  1487,  1492,  1491,
    1497,  1497,  1499,  1508,  1508,  1510,  1510,  1512,  1512,  1517,
    1517,  1519,  1519,  1521,  1526,  1525,  1531,  1531,  1533,  1533,
    1535,  1539,  1539,  1541,  1541,  1543,  1548,  1547,  1554,  1554,
    1556,  1562,  1563,  1566,  1567,  1571,  1572,  1578,  1578,  1578,
    1578,  1578,  1578,  1578,  1578,  1579,  1579,  1583,  1583,  1583,
    1583,  1583,  1583,  1583,  1584,  1584,  1589,  1589,  1589,  1589,
    1589,  1589,  1590,  1590,  1594,  1594,  1594,  1594,  1594,  1594,
    1594,  1595,  1595,  1599,  1599,  1599,  1599,  1599,  1599,  1600,
    1600,  1605,  1605,  1605,  1605,  1605,  1605,  1606,  1606,  1611,
    1611,  1611,  1611,  1611,  1611,  1612,  1612,  1617,  1617,  1617,
    1617,  1617,  1618,  1618,  1625,  1626,  1629,  1635,  1635,  1643,
    1643,  1643,  1643,  1643,  1643,  1643
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FILE_NAME_STRING", "UNINTERPRETED_STRING", 
  "LATEX_STRING", "KW_MOD", "KW_OMOD", "KW_PARSE", "KW_NORMALIZE", 
  "KW_REDUCE", "KW_REWRITE", "KW_LOOP", "KW_NARROW", "KW_MATCH", 
  "KW_XMATCH", "KW_UNIFY", "KW_XUNIFY", "KW_EREWRITE", "KW_FREWRITE", 
  "KW_OREWRITE", "KW_CONTINUE", "KW_SEARCH", "KW_SET", "KW_SHOW", "KW_ON", 
  "KW_OFF", "KW_TRACE", "KW_CONTEXT", "KW_WHOLE", "KW_SELECT", 
  "KW_DESELECT", "KW_CONDITION", "KW_SUBSTITUTION", "KW_PRINT", 
  "KW_GRAPH", "KW_MIXFIX", "KW_FLAT", "KW_WITH", "KW_PARENS", 
  "KW_ALIASES", "KW_GC", "KW_TIME", "KW_STATS", "KW_TIMING", "KW_CMD", 
  "KW_BREAKDOWN", "KW_BREAK", "KW_PATH", "KW_MODULE", "KW_MODULES", 
  "KW_ALL", "KW_SORTS", "KW_OPS", "KW_VARS", "KW_MBS", "KW_EQS", "KW_RLS", 
  "KW_SUMMARY", "KW_KINDS", "KW_ADVISE", "KW_VERBOSE", "KW_DO", 
  "KW_CLEAR", "KW_PROTECT", "KW_EXTEND", "KW_INCLUDE", "KW_EXCLUDE", 
  "KW_CONCEAL", "KW_REVEAL", "KW_COMPILE", "KW_COUNT", "KW_DEBUG", 
  "KW_RESUME", "KW_ABORT", "KW_STEP", "KW_WHERE", "KW_CREDUCE", "KW_DUMP", 
  "KW_PROFILE", "KW_NUMBER", "KW_RAT", "KW_COLOR", "SIMPLE_NUMBER", 
  "KW_PWD", "KW_CD", "KW_PUSHD", "KW_POPD", "KW_LS", "KW_LOAD", "KW_QUIT", 
  "KW_EOF", "KW_ENDM", "KW_IMPORT", "KW_SORT", "KW_SUBSORT", "KW_OP", 
  "KW_MSGS", "KW_VAR", "KW_CLASS", "KW_SUBCLASS", "KW_MB", "KW_CMB", 
  "KW_EQ", "KW_CEQ", "KW_RL", "KW_CRL", "KW_IS", "KW_ARROW", "KW_ARROW2", 
  "KW_PARTIAL", "KW_IF", "':'", "'='", "'('", "')'", "'.'", "'<'", "'['", 
  "']'", "','", "'|'", "KW_LABEL", "KW_TO", "'+'", "'*'", "KW_ASSOC", 
  "KW_COMM", "KW_ID", "KW_IDEM", "KW_ITER", "KW_LEFT", "KW_RIGHT", 
  "KW_PREC", "KW_GATHER", "KW_METADATA", "KW_STRAT", "KW_POLY", "KW_MEMO", 
  "KW_FROZEN", "KW_CTOR", "KW_LATEX", "KW_SPECIAL", "KW_CONFIG", "KW_OBJ", 
  "KW_MSG", "KW_DITTO", "KW_FORMAT", "KW_ID_HOOK", "KW_OP_HOOK", 
  "KW_TERM_HOOK", "KW_IN", "IDENTIFIER", "NUMERIC_ID", "ENDS_IN_DOT", 
  "$accept", "top", "item", "directive", "@1", "@2", "@3", "@4", "@5", 
  "moduleExprDot", "moduleExpr", "moduleExpr2", "renaming", "@6", 
  "mappingList", "mapping", "fromOpName", "@7", "@8", "fromSpec", 
  "fromTypeList", "fromType", "@9", "toOpName", "@10", "@11", 
  "toAttributes", "toAttributeList", "toAttribute", "@12", "@13", "@14", 
  "module", "@15", "@16", "dot", "badType", "typeDot", "endStatement", 
  "startModule", "decList", "declaration", "@17", "@18", "@19", "@20", 
  "@21", "@22", "@23", "@24", "@25", "@26", "@27", "@28", "@29", "@30", 
  "@31", "@32", "@33", "@34", "@35", "classDef", "cPairList", "cPair", 
  "varNameList", "opName", "@36", "@37", "opNameList", "simpleOpName", 
  "@38", "domainRangeAttr", "typeAttr", "arrow", "typeList", "type", 
  "@39", "sortTokens", "attributes", "attributeList", "idKeyword", 
  "attribute", "@40", "@41", "@42", "@43", "@44", "@45", "@46", "idList", 
  "hookList", "hook", "@47", "@48", "@49", "sortTokenList", "subsortList", 
  "@50", "tokens", "@51", "tokensBarColon", "@52", "tokensBarColonTo", 
  "@53", "tokensBarCommaLeft", "@54", "tokensBarEqual", "@55", 
  "tokensBarArrow2", "@56", "tokensBarIf", "@57", "endTokens", 
  "noTrailingDot", "@58", "@59", "identity", "identityChunk", "@60", 
  "token", "tokenBarDot", "endToken", "tokenBarArrow2", "tokenBarEqual", 
  "tokenBarIf", "tokenBarColon", "tokenBarColonTo", "tokenBarCommaLeft", 
  "sortToken", "endsInDot", "identifier", "startKeyword", "startKeyword2", 
  "midKeyword", "attrKeyword", "attrKeyword2", "command", "@61", "@62", 
  "@63", "@64", "@65", "@66", "@67", "@68", "@69", "@70", "@71", "@72", 
  "@73", "@74", "@75", "@76", "@77", "@78", "@79", "@80", "@81", "@82", 
  "@83", "@84", "@85", "@86", "@87", "@88", "@89", "@90", "@91", "@92", 
  "@93", "@94", "@95", "polarity", "select", "exclude", "conceal", 
  "match", "optDebug", "optNumber", "importMode", "moduleAndTerm", "@96", 
  "@97", "inEnd", "@98", "@99", "numberModuleTerm", "@100", "@101", 
  "@102", "numberModuleTerm1", "@103", "@104", "numberModuleTerm2", 
  "@105", "@106", "numbersModuleTerm", "@107", "@108", "@109", 
  "numbersModuleTerm1", "@110", "@111", "numbersModuleTerm2", "@112", 
  "@113", "@114", "numbersModuleTerm3", "@115", "@116", 
  "numbersModuleTerm4", "@117", "@118", "cTokens", "cTokensBarDot", 
  "cTokensBarDotColon", "cToken", "@119", "cTokenBarDot", "@120", 
  "cTokenBarDotColon", "@121", "cTokenBarIn", "@122", "cTokenBarLeftIn", 
  "@123", "cTokenBarDotNumber", "@124", "cTokenBarDotRight", "@125", 
  "cTokenBarDotCommaRight", "@126", "cOpNameList", "cSimpleOpName", 
  "@127", "cSimpleTokenBarDot", 0
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
     365,   366,    58,    61,    40,    41,    46,    60,    91,    93,
      44,   124,   367,   368,    43,    42,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   155,   156,   156,   157,   157,   157,   159,   158,   160,
     158,   158,   161,   158,   162,   158,   158,   163,   158,   158,
     158,   164,   164,   164,   165,   165,   166,   166,   166,   168,
     167,   169,   169,   170,   170,   170,   172,   171,   173,   171,
     174,   174,   175,   175,   176,   177,   176,   179,   178,   180,
     178,   181,   181,   182,   182,   183,   184,   183,   185,   183,
     186,   183,   188,   189,   187,   190,   190,   191,   192,   192,
     193,   193,   194,   194,   195,   195,   196,   197,   196,   198,
     196,   196,   196,   196,   199,   200,   196,   201,   202,   203,
     196,   204,   205,   196,   206,   207,   208,   196,   209,   210,
     196,   211,   212,   213,   196,   196,   196,   214,   196,   215,
     196,   196,   216,   216,   217,   217,   218,   219,   219,   221,
     220,   222,   220,   223,   223,   224,   225,   224,   226,   227,
     227,   228,   228,   229,   229,   230,   231,   230,   232,   232,
     233,   233,   234,   234,   235,   235,   235,   236,   236,   237,
     236,   236,   236,   236,   238,   236,   239,   236,   240,   236,
     241,   236,   236,   236,   236,   242,   236,   236,   236,   236,
     236,   243,   236,   236,   236,   244,   244,   245,   245,   246,
     247,   246,   248,   246,   249,   246,   250,   250,   251,   251,
     252,   251,   254,   253,   253,   253,   256,   255,   255,   255,
     258,   257,   257,   257,   260,   259,   259,   259,   262,   261,
     261,   261,   264,   263,   263,   263,   266,   265,   265,   265,
     267,   267,   267,   269,   268,   270,   268,   268,   268,   268,
     271,   271,   272,   272,   272,   272,   273,   272,   274,   274,
     274,   274,   274,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   284,   284,   285,
     285,   285,   285,   285,   285,   285,   285,   286,   286,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   288,   288,   288,   288,   288,
     288,   288,   288,   289,   289,   289,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     292,   293,   291,   294,   295,   291,   296,   291,   297,   291,
     298,   291,   299,   291,   300,   291,   301,   291,   302,   291,
     303,   291,   291,   304,   291,   305,   291,   306,   291,   307,
     291,   308,   291,   309,   291,   291,   310,   291,   311,   291,
     312,   291,   291,   313,   291,   314,   291,   315,   291,   316,
     291,   317,   291,   318,   291,   319,   291,   320,   291,   291,
     291,   291,   321,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   322,   323,   291,   324,   325,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     326,   291,   327,   327,   328,   328,   329,   329,   330,   330,
     331,   331,   332,   332,   333,   333,   334,   334,   334,   336,
     335,   337,   335,   339,   340,   338,   338,   342,   341,   343,
     341,   344,   341,   346,   345,   347,   345,   345,   349,   348,
     350,   348,   348,   352,   351,   353,   351,   354,   351,   356,
     355,   357,   355,   355,   359,   358,   360,   358,   361,   358,
     358,   363,   362,   364,   362,   362,   366,   365,   367,   365,
     365,   368,   368,   369,   369,   370,   370,   371,   371,   371,
     371,   371,   371,   371,   371,   372,   371,   373,   373,   373,
     373,   373,   373,   373,   374,   373,   375,   375,   375,   375,
     375,   375,   376,   375,   377,   377,   377,   377,   377,   377,
     377,   378,   377,   379,   379,   379,   379,   379,   379,   380,
     379,   381,   381,   381,   381,   381,   381,   382,   381,   383,
     383,   383,   383,   383,   383,   384,   383,   385,   385,   385,
     385,   385,   386,   385,   387,   387,   388,   389,   388,   390,
     390,   390,   390,   390,   390,   390
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     1,     0,     3,     1,
       1,     2,     3,     1,     1,     3,     3,     3,     1,     0,
       4,     3,     1,     4,     4,     6,     0,     3,     0,     4,
       4,     0,     2,     0,     1,     0,     4,     0,     3,     0,
       4,     3,     0,     2,     1,     2,     0,     5,     0,     5,
       0,     5,     0,     0,     7,     1,     1,     1,     2,     1,
       2,     1,     1,     1,     2,     0,     2,     0,     4,     0,
       4,     3,     3,     4,     0,     0,     6,     0,     0,     0,
       9,     0,     0,     6,     0,     0,     0,     9,     0,     0,
       6,     0,     0,     0,     9,     3,     3,     0,     5,     0,
       4,     2,     1,     2,     1,     3,     3,     2,     1,     0,
       3,     0,     4,     2,     1,     1,     0,     4,     4,     3,
       1,     1,     1,     2,     0,     1,     0,     4,     3,     1,
       3,     0,     2,     1,     1,     2,     2,     1,     1,     0,
       3,     1,     1,     2,     0,     5,     0,     5,     0,     5,
       0,     5,     1,     1,     1,     0,     5,     1,     1,     1,
       2,     0,     5,     4,     1,     2,     1,     2,     1,     2,
       0,     6,     0,     6,     0,     6,     2,     0,     2,     2,
       0,     4,     0,     5,     2,     0,     0,     5,     2,     0,
       0,     5,     2,     0,     0,     5,     2,     0,     0,     5,
       2,     0,     0,     5,     2,     0,     0,     5,     2,     0,
       1,     2,     1,     0,     4,     0,     5,     2,     2,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     6,     0,     0,     6,     0,     3,     0,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     3,
       0,     3,     4,     0,     3,     0,     4,     0,     5,     0,
       5,     0,     5,     0,     5,     4,     0,     5,     0,     5,
       0,     5,     3,     0,     5,     0,     5,     0,     5,     0,
       5,     0,     5,     0,     5,     0,     5,     0,     5,     4,
       5,     4,     0,     5,     5,     5,     6,     5,     5,     6,
       5,     5,     5,     5,     6,     6,     5,     5,     5,     5,
       5,     5,     4,     5,     5,     5,     5,     5,     5,     5,
       5,     4,     0,     0,     7,     0,     0,     8,     4,     5,
       5,     5,     4,     5,     2,     2,     2,     2,     5,     4,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
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
       0,   520,    72,    73,   416,   433,   531,   530,   428,     0,
       0,     0,   410,     0,     0,     0,   532,     0,     0,     0,
       0,   418,   413,    11,    12,    14,    16,    17,     9,    19,
      20,   435,     7,     0,     2,     5,     4,    62,     6,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536,   537,   538,     0,     0,   502,
     446,     0,     0,   448,     0,   450,   453,   455,   457,   459,
     461,   463,   465,   467,   472,   524,   525,   527,   526,   437,
     439,     0,   528,   529,   443,   441,     0,   514,   515,   516,
     517,     0,     0,     0,     0,     0,     0,   592,     0,     1,
       0,     0,   420,   422,   424,   426,   535,   521,   628,   631,
     629,   626,   627,   630,   539,   624,   625,   417,   541,   434,
     636,   639,   637,   547,   635,   638,   549,   633,   634,   429,
     551,   505,     0,     0,     0,     0,     0,     0,     0,   522,
     523,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
       0,     0,     0,   594,   452,   594,   594,   594,   594,   594,
     594,   594,   594,   594,   594,     0,     0,   602,   605,   603,
     599,   600,   604,   601,   597,   598,   411,     0,     0,     0,
     419,   414,    13,    15,    18,    10,     0,     8,   363,   374,
     359,   360,   361,   362,   365,   364,   366,   367,   368,   369,
     370,   371,   372,   373,   382,   377,   380,   378,   381,   376,
     379,   242,   375,   383,   384,   351,   352,   353,   354,   355,
     356,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     402,   395,   396,   397,   401,   398,   399,   400,   403,   404,
     357,   405,   406,   407,   408,   409,   349,   350,     0,   238,
     239,   358,   240,   241,   385,   431,     0,     0,     0,     0,
     534,     0,   592,   596,   594,   592,     0,   596,   594,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   492,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   519,   501,
     508,     0,     0,     0,     0,   512,   674,   671,   672,   675,
     673,   669,   670,   503,     0,   471,   469,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   667,
       0,   665,   666,     0,   592,   594,     0,     0,   445,   594,
     436,   591,    63,   421,   423,   425,   563,   565,   427,   567,
     432,     0,     0,     0,     0,   645,   647,   557,   642,   643,
     646,   644,   641,   553,   548,   555,     0,     0,   506,     0,
       0,   481,   475,   477,   480,   478,   474,   494,   495,   497,
     493,   496,   498,   499,   500,   486,   482,   483,     0,     0,
     487,   488,   489,   490,   491,   518,   510,   513,   509,   511,
       0,   612,   614,   447,   609,   610,   613,   611,   607,   608,
     593,   470,   449,   451,   454,   456,   458,   460,   462,   464,
     466,   468,   473,   592,   438,   664,   440,     0,     0,   444,
     442,     0,    75,     0,   596,   594,   632,   543,   622,   546,
     618,   619,   621,   620,   616,   617,   540,   595,   542,   640,
     592,     0,   594,   550,   552,     0,   476,   479,   485,   484,
       0,   592,     0,   606,   412,   415,     0,   573,   569,   564,
     571,     0,     0,     0,   592,     0,   653,   655,   562,   651,
     558,   654,   652,   649,   650,   554,   560,     0,     0,   504,
       0,   668,     0,     0,    64,     0,    77,    79,     0,     0,
       0,     0,   109,    84,    87,    91,    94,    98,   101,     0,
      74,     0,   594,   566,   568,   544,     0,   648,   592,     0,
     594,   556,   507,   615,   111,   305,   300,   303,   301,   304,
     302,   126,   298,   299,     0,   124,   125,   295,   296,   297,
       0,    23,    76,     0,    24,    28,   187,     0,   121,     0,
     119,     0,     0,   118,   107,     0,   199,   199,   211,   211,
     215,   215,     0,   661,   662,   580,   659,   574,   576,   660,
     657,   658,   570,   578,     0,   594,   623,     0,   559,     0,
     195,   134,   123,    82,     0,    24,     0,    21,     0,     0,
     344,   342,   343,   338,   339,   345,   346,   340,   341,   335,
       0,   190,   336,   337,   195,    81,   199,   106,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   592,
       0,     0,   594,   572,     0,   656,   561,     0,     0,    26,
       0,    22,    25,    29,    27,    65,    66,    78,   186,   189,
      80,   188,   187,     0,   120,   136,    67,    69,    83,     0,
     135,   112,     0,   110,    85,   196,   198,    88,   283,   279,
     281,   280,   282,   278,    92,   208,   276,   277,   210,   273,
     274,   275,    95,   272,   268,    99,   269,   271,   267,   270,
     212,   265,   266,   214,   262,   263,   264,   102,     0,   575,
     585,   581,   577,   583,     0,   545,   192,   127,   194,   131,
     132,     0,   133,    25,     0,     0,   122,     0,    68,   244,
     245,   246,   247,   248,   249,   243,   113,   114,     0,   250,
     251,   252,   108,     0,   195,   219,     0,   195,   219,     0,
     195,   219,   663,     0,   594,   579,   195,   130,   128,   141,
       0,     0,     0,     0,    32,   191,     0,   139,     0,     0,
     223,   347,   348,    86,     0,   220,   229,   222,     0,     0,
      93,     0,     0,   100,     0,     0,   590,   586,   582,   588,
       0,     0,     0,     0,     0,    38,    41,    36,     0,    30,
       0,   137,     0,   115,   116,   195,   225,   347,   254,   255,
     256,   257,   258,   259,   253,   348,    70,   228,   221,   260,
     261,   227,   197,   294,   290,   293,   291,    89,   289,   292,
     216,   287,   288,   218,   284,   285,   286,   209,    96,   213,
     103,     0,   594,   584,   193,   147,   148,   144,   151,   152,
       0,     0,     0,     0,     0,     0,     0,   162,   164,   163,
       0,     0,   167,   168,   169,   174,     0,     0,   149,   143,
     129,     0,   195,    43,     0,   203,     0,    31,   138,     0,
     195,     0,   195,     0,     0,   587,     0,   145,   146,   153,
     154,   170,   158,   160,   165,   171,     0,   156,   140,   142,
       0,    33,     0,     0,     0,    37,    34,   224,     0,    90,
       0,    97,   104,   589,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   178,     0,   236,   235,   150,   230,   232,
     233,   234,    39,    45,    42,     0,    44,    49,    52,    47,
     322,   317,   320,   318,   321,   319,   200,   315,   316,   308,
     309,   310,   311,   312,   306,   307,   202,   313,   314,   226,
     217,   176,     0,     0,     0,     0,     0,   179,     0,     0,
     173,   177,     0,   195,   231,     0,    40,   195,     0,    35,
     207,   195,   155,   175,   159,   161,   166,   172,   180,   182,
     184,   157,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    48,     0,   195,   195,   195,   237,    46,    50,    55,
      56,    60,    58,    51,    53,   204,   332,   333,   325,   326,
     327,   328,   329,   323,   324,   206,   330,   334,   331,   201,
       0,     0,     0,     0,     0,     0,   195,   181,   183,   185,
       0,     0,     0,     0,    57,    61,    59,   205
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    33,    34,    35,    98,    96,    93,    94,    95,   562,
     563,   564,   654,   724,   763,   764,   796,   875,   872,   874,
     903,   934,   975,   938,   980,   977,   979,   999,  1000,  1033,
    1035,  1034,    36,   100,   452,   657,   667,   668,   773,    37,
     486,   530,   566,   567,   576,   743,   577,   745,   881,   578,
     746,   579,   748,   883,   580,   749,   581,   751,   884,   630,
     575,   672,   736,   737,   572,   569,   626,   624,   554,   555,
     600,   603,   758,   721,   648,   669,   727,   766,   793,   867,
     868,   869,   900,   914,   924,   915,   916,   917,   918,   962,
     922,   923,  1003,  1004,  1005,   609,   620,   662,   647,   756,
     632,   744,   905,   981,  1001,  1036,   634,   747,   636,   750,
     779,   882,   774,   775,   805,   880,   927,   928,   973,   718,
     776,   817,   703,   688,   833,   556,   956,  1025,   670,   777,
     269,   270,   271,   272,   273,   274,    38,    81,   355,    92,
     359,    42,    91,   276,   277,   278,   279,    44,   101,    43,
      97,   185,   186,   198,   197,   169,   173,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   168,   420,   289,
     475,    41,   149,    79,    80,    84,    39,    40,   281,    59,
     117,   283,   284,   466,   493,   595,   129,   286,   287,   288,
     384,   471,   472,   505,   539,   540,   368,   453,   454,   455,
     489,   531,   532,   592,   640,   641,   642,   712,   753,   754,
     788,   841,   842,   206,   334,   372,   361,   354,   430,   481,
     467,   494,   118,   282,   130,   285,   385,   470,   506,   538,
     593,   639,   350,   351,   443,   352
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -882
static const short yypact[] =
{
     667,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  5349,
     790,    11,  -882,    37,   139,    -3,  -882,    -4,     7,    41,
      44,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,    66,  -882,  -882,  -882,  -882,  -882,  -882,
     188,    50,   144,   144,   437,    61,   167,   759,    16,   154,
     148,   148,   148,   -18,  -882,  -882,  -882,   112,   148,  -882,
    -882,   151,   -27,  -882,    73,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  5381,  -882,  -882,  -882,  -882,    56,  -882,  -882,  -882,
    -882,   144,  5381,   193,   213,   217,   226,  -882,   230,  -882,
    4018,   437,  -882,  -882,  -882,  -882,   155,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,   175,   148,   148,   148,   148,   148,   148,  -882,
    -882,   148,   148,   148,   148,   148,   148,   148,   148,   127,
     148,   148,   148,   201,   148,   148,   148,   148,   148,   148,
     132,   152,   157,   148,   148,   148,   148,   158,   258,  -882,
     159,   161,   168,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  6005,  6005,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  6005,  6005,   162,
    -882,  -882,  -882,  -882,  -882,  -882,   423,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,   160,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,   144,   437,   437,  5423,
    -882,   163,  -882,  -882,  -882,  -882,  5432,  -882,  -882,   258,
     148,   148,   165,   166,   169,   171,   172,   174,   176,   177,
     178,   182,   183,   184,   186,   189,  -882,   196,   197,   206,
     148,   148,   218,   219,   224,   227,   228,   229,  -882,  -882,
    -882,   233,   235,   240,   241,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  5441,  -882,  -882,   243,  5450,  5492,
    5501,  5510,  5519,  5561,  5570,  5579,  5588,  5630,  5639,  -882,
    5648,  -882,  -882,  5657,  -882,  -882,  5699,  5708,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,   466,  5717,  5726,   584,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  5717,  5768,  -882,   244,
     247,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,   248,   250,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
     148,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,   597,  5777,  -882,
    -882,  5786,  -882,  5795,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  5837,  -882,  -882,  -882,   148,  -882,  -882,  -882,  -882,
     251,  -882,   608,  -882,  -882,  -882,   427,  -882,  -882,  -882,
    -882,  5717,  5846,  5381,  -882,   654,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  5855,   263,  -882,
    5246,  -882,   264,  4116,  -882,  2450,  -882,  -882,  2548,  4116,
    4410,  4018,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  2548,
    -882,  5864,  -882,  -882,  -882,  -882,  5354,  -882,  -882,   144,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  2646,  -882,  -882,  -882,  -882,  -882,
    2744,    31,  -882,   147,    -7,  -882,  -882,  5205,  -882,   179,
    -882,  2646,  4214,  -882,  -882,  5205,  -882,  -882,  -882,  -882,
    -882,  -882,   179,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  5906,  -882,  -882,  5363,  -882,  5915,
    -882,  -882,  -882,  -882,     1,   145,  2450,  -882,   190,  4708,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    4643,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  4772,  -882,
     212,  4643,  2842,  2940,  3038,  3136,  3234,  3332,  -882,  -882,
     144,  5924,  -882,  -882,  5933,  -882,  -882,   784,  4961,  -882,
    2744,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,   882,  4312,  -882,  -882,  -882,  -882,   265,
    -882,  4900,   267,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  5372,  -882,
    -882,  -882,  -882,  -882,  5975,  -882,  -882,  -882,  -882,  -882,
    -882,  4772,  -882,  -882,   -14,  5083,  -882,  5205,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,   222,  -882,   234,  -882,
    -882,  -882,  -882,  3430,  -882,  -882,  3430,  -882,  -882,  3430,
    -882,  -882,  -882,  5984,  -882,  -882,  -882,  -882,  -882,   269,
    5205,  3528,  4018,    28,  -882,  -882,   135,  -882,  4900,  4018,
    -882,  -882,   508,  -882,  5313,  4870,  -882,  -882,   980,  3626,
    -882,  1078,  3724,  -882,  1176,  3822,  -882,  -882,  -882,  -882,
    5993,  1274,   911,   272,   266,  -882,   279,  -882,   270,  -882,
     -14,  -882,  5205,  -882,  -882,  -882,  -882,   539,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,   730,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,   144,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
     268,   274,   137,   278,   245,   281,   289,  -882,   293,  -882,
     294,   298,  -882,  -882,  -882,  -882,   299,   818,  -882,  -882,
    -882,  5205,  -882,  -882,   291,  -882,  4018,  -882,  -882,  1372,
    -882,  3430,  -882,  3430,  3430,  -882,  6002,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,    87,  -882,  -882,  -882,
    4835,  -882,  1470,  5022,  3920,  4508,  -882,  -882,  1568,  -882,
    1666,  -882,  -882,  -882,   273,   273,   273,   273,   411,  4018,
    4018,  4018,   -57,  -882,   273,  -882,  -882,  4835,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  5144,  -882,  -882,   301,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,   -83,   -58,   -53,   -52,   302,   306,   308,   312,
    -882,  -882,   -50,  -882,  -882,  5205,  -882,  -882,    17,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  1764,   146,  1862,   280,   317,   319,   320,    34,
    -882,  4578,  1960,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    2058,  2156,  2254,   273,   432,   273,  -882,  -882,  -882,  -882,
     -45,   323,   -41,  2352,  -882,  -882,  -882,  -882
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -167,
    -535,  -522,  -882,  -882,  -882,  -360,  -882,  -882,  -882,  -882,
    -882,  -494,  -882,  -882,  -882,  -882,  -882,  -882,  -557,  -882,
    -882,  -882,  -882,  -882,  -882,  -603,  -277,  -882,  -722,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -322,  -882,   -82,  -882,  -882,   -71,  -504,
    -882,  -523,  -882,  -454,  -882,  -617,  -882,  -525,  -882,  -882,
    -882,  -416,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -881,
    -882,  -468,  -882,  -882,  -882,  -207,  -118,  -882,  -382,  -882,
    -537,  -882,  -882,  -882,  -882,  -882,  -121,  -882,  -122,  -882,
    -704,  -882,  -882,  -882,  -882,  -882,  -882,  -466,  -882,  -100,
    -642,  -882,  -882,  -882,  -882,  -487,  -882,  -882,  -530,  -312,
    -432,  -499,  -786,  -529,  -119,  -545,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,   173,   451,  -882,  -882,  -882,  -882,  -882,  -882,
     -42,  -882,  -882,  -367,  -882,  -882,   -85,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,   -95,  -171,  -269,   -66,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,   187,  -882,  -450,  -882,  -286,  -882,
    -882,  -882,   -67,  -104,  -882,  -145
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -534
static const short yytable[] =
{
     268,   119,   338,   490,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   558,   196,   275,   660,   386,   473,
     558,   558,   623,   333,   780,   604,   201,   783,   673,   738,
     623,   722,   982,   573,   963,   964,   965,   621,   605,   163,
     633,    75,    76,   972,   782,   621,   625,   785,   627,   200,
     602,   150,   151,   152,   153,   558,   171,   984,   970,   638,
      86,   164,   985,   986,   623,   991,    99,   602,   622,   983,
    1044,   652,   558,   558,  1046,   623,   622,    77,    78,   658,
     760,   557,   761,   623,   154,   629,   623,   557,   557,   664,
     661,   919,   920,   921,   983,   172,   155,   156,   157,   983,
     983,   661,   983,   623,   759,    82,    83,   983,   762,   607,
     622,   983,    87,   373,   930,   723,   649,   387,   608,   353,
     165,   622,   557,    88,   533,   650,   738,   131,   605,   622,
     356,   357,   622,   558,   558,   690,   690,   705,   705,   557,
     557,   930,   740,   799,   388,   676,   676,  -350,   800,   622,
     995,   996,  1040,  1013,  1042,  -350,  -350,    89,   997,   909,
      90,   911,   912,   158,   998,   558,   107,   995,   996,    75,
      76,   816,   739,   139,   140,   997,   623,   676,   159,   132,
     623,   998,   623,   166,   448,   491,   170,   371,   451,   174,
     374,   713,   364,   365,   199,   658,   202,   767,   102,   103,
     557,   557,   689,   689,   704,   704,   104,   105,   133,   106,
     134,   135,   136,   137,   740,   623,   203,   740,   290,   291,
     740,   204,   622,   160,   161,   162,   622,   138,   622,   205,
     794,   167,   557,   207,   363,   919,   920,   921,   280,   740,
     310,   311,   663,   306,   739,   819,   445,   739,   318,   445,
     739,   337,   445,   445,   801,   802,   108,   623,   109,   447,
     110,   622,   111,   112,   113,  1007,   802,   362,   319,   739,
     608,   606,   878,   320,   325,   335,   821,   336,   358,   370,
     835,   391,   392,   835,   492,   393,   835,   394,   395,   889,
     396,   601,   397,   398,   399,   114,   115,   116,   400,   401,
     402,   507,   403,   622,   653,   404,   292,   293,   294,   295,
     296,   297,   405,   406,   298,   299,   300,   301,   302,   303,
     304,   305,   407,   307,   308,   309,   623,   312,   313,   314,
     315,   316,   317,   671,   410,   411,   321,   322,   323,   324,
     412,   901,   768,   413,   414,   415,   769,   834,   482,   416,
     834,   417,   740,   834,   740,   740,   418,   419,   623,   431,
     476,   594,   778,   477,   478,   781,   479,   509,   784,   599,
     326,   931,   622,   936,   791,   495,   327,   328,   329,   542,
     544,   728,   739,   742,   739,   739,   510,   792,   870,   871,
     623,   873,   890,   876,   559,   892,   887,   891,   931,   536,
     559,   559,   888,   893,   622,   936,   957,   894,   895,   330,
     331,   332,   896,   897,   904,   565,   966,   987,   570,   978,
     988,   574,   989,   879,   644,   961,   990,   535,   512,   570,
     623,  1010,  1009,  1011,  1012,   559,   622,  1041,  1045,   651,
     877,   976,  1014,   597,   757,   767,   803,   582,   571,   935,
     993,   899,   559,   559,   971,   725,  1028,   631,   635,   637,
     565,   974,   818,   389,   390,    85,   369,   789,   929,     0,
       0,   714,  1027,     0,     0,     0,   622,     0,     0,     0,
     513,     0,     0,   408,   409,     0,     0,     0,     0,     0,
     902,     0,     0,     0,     0,   929,     0,   598,   908,     0,
     910,     0,  1026,     0,     0,     0,   565,     0,     0,   -71,
       0,     0,     0,   559,   559,   691,   691,   706,   706,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,     0,   187,     0,   188,   360,   189,
     -65,   190,   191,   192,   708,   559,     0,     0,     0,   120,
     565,   121,   741,   122,     0,   123,   124,   125,     0,     0,
       0,   -71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   529,     0,   193,   194,   195,     0,   187,     0,
     188,   456,   189,   790,   190,   191,   192,     0,   126,   127,
     128,   992,   -65,   480,     0,   994,     0,     0,   709,  1002,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,     0,     0,   193,   194,   195,
       0,  1030,  1031,  1032,   741,     0,     0,   741,     0,     0,
     741,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,     0,     0,   508,   741,
       0,     0,     0,   -71,  1043,   820,     0,     0,     0,     0,
     836,   797,   798,   836,     0,     0,   836,    -3,     1,   804,
       0,   886,     0,     2,     3,     4,     0,  -533,  -533,     5,
       0,     6,     7,     0,   -65,  -533,  -533,     0,  -533,     8,
       9,    10,     0,     0,    11,     0,   187,    12,   188,   469,
     189,    13,   190,   191,   192,     0,     0,     0,     0,   187,
       0,   188,   483,   189,    14,   190,   191,   192,     0,     0,
     187,     0,   188,   511,   189,     0,   190,   191,   192,    15,
       0,   -66,     0,     0,     0,   193,   194,   195,     0,    16,
      17,    18,    19,    20,    21,    22,     0,     0,   193,   194,
     195,    23,    24,    25,    26,    27,    28,    29,    30,   193,
     194,   195,   741,     0,   741,   741,   187,     0,   188,   537,
     189,     0,   190,   191,   192,     0,   906,     0,     0,     0,
       0,    31,     0,   -66,   139,   140,   958,   141,   142,   143,
       0,   144,   145,     0,     0,     0,    60,     0,     0,   885,
       0,     0,     0,     0,   939,   193,   194,   195,     0,     0,
       0,     0,    61,     0,   146,   147,   148,     0,    32,   967,
     968,   969,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   208,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,     0,     0,     0,     0,   -66,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   716,   717,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   208,   266,   898,   267,     0,
       0,     0,     0,     0,   845,   846,   847,   848,   849,   850,
     851,   852,   853,   854,   855,   856,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   866,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   716,   726,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   208,   266,     0,   267,   845,   846,   847,
     848,   849,   850,   851,   852,   853,   854,   855,   856,   857,
     858,   859,   860,   861,   862,   863,   864,   865,   866,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   716,   822,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   208,   266,     0,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   716,   837,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   208,
     266,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     716,   839,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   208,   266,     0,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   716,   844,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   208,   266,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   716,   907,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   208,   266,     0,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   716,   932,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   208,   266,     0,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   716,   959,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   208,
     266,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     716,   960,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   208,   266,     0,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   716,  1006,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   208,   266,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   716,  1008,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   208,   266,     0,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   716,  1029,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   208,   266,     0,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   716,  1037,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   208,
     266,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     716,  1038,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   208,   266,     0,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   716,  1039,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   208,   266,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   716,  1047,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   208,   266,     0,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   560,     0,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   208,   266,     0,   561,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   568,     0,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   208,
     266,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   545,   546,   547,   548,   549,   601,   550,
     551,     0,   552,   553,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   208,   266,     0,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   560,     0,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   208,   266,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   545,
     546,   547,   548,   549,   674,   550,   675,     0,   552,   553,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   208,   266,     0,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   545,   546,   547,
     548,   549,   677,   550,   675,     0,   552,   553,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   208,   266,     0,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   678,   679,   680,   681,   682,
     683,   684,   685,     0,   686,   687,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   208,
     266,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   678,   679,   680,   681,   682,   683,   692,
     685,     0,   686,   687,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   208,   266,     0,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   693,   694,   695,   696,   697,   698,   699,   700,     0,
     701,   702,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   208,   266,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   693,
     694,   707,   696,   697,   698,   699,   700,     0,   701,   702,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   208,   266,     0,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   770,     0,   771,   232,   233,   234,
     729,   730,   731,   732,   733,   734,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   208,   735,     0,   772,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   795,     0,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   208,
     266,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   823,   824,   825,   826,   827,   828,   829,
     830,     0,   831,   832,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   208,   266,     0,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   823,   824,   825,   826,   838,   828,   829,   830,     0,
     831,   832,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   208,   266,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   823,
     824,   825,   826,   840,   828,   829,   830,     0,   831,   832,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   208,   266,     0,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   937,     0,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   208,   266,     0,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,     0,     0,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   208,
     266,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   545,   546,   547,   548,   549,     0,   550,
     551,     0,   552,   553,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   208,   266,     0,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   545,   546,   547,   548,   549,   628,   550,     0,     0,
     552,   553,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   208,   266,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   545,
     546,   547,   548,   549,     0,   550,   675,     0,   552,   553,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   208,   266,     0,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   545,   546,   547,
     548,   549,     0,   550,     0,     0,   552,   553,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   208,   266,     0,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   940,   941,   942,   943,   944,
       0,   945,   946,     0,   947,   948,   233,   234,   949,   950,
     951,   208,   952,   953,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     954,     0,   955,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,  1015,     0,  1016,   232,   208,  1017,     0,  1018,
    1019,  1020,  1021,  1022,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
    1023,     0,  1024,     0,     0,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     610,     0,   611,     0,   612,     0,   613,     0,     0,   655,
     659,   208,     0,     0,   614,   615,   616,   617,   618,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,     0,   619,     0,   656,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   610,     0,   611,     0,   612,
       0,   613,     0,     0,   655,   208,     0,     0,     0,   614,
     615,   616,   617,   618,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     619,     0,   656,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   610,
       0,   611,     0,   612,     0,   613,     0,     0,   208,     0,
     665,     0,     0,   614,   615,   616,   617,   618,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   208,   619,     0,   666,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   925,
       0,   926,   232,   208,     0,   235,   236,   237,   238,   239,
     240,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,   267,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   208,   260,     0,   232,   233,   234,
     729,   730,   731,   732,   733,   734,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,     0,   735,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   610,   719,
     611,   720,   612,     0,   613,   208,     0,     0,     0,   665,
       0,     0,   614,   615,   616,   617,   618,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,     0,   619,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   610,
     719,   611,   720,   612,     0,   613,   208,     0,     0,     0,
     933,     0,     0,   614,   615,   616,   617,   618,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,     0,   619,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     610,     0,   611,     0,   612,     0,   613,   208,     0,     0,
     765,     0,     0,     0,   614,   615,   616,   617,   618,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,     0,   619,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   610,     0,   611,     0,   612,     0,   613,   208,     0,
       0,     0,   933,     0,     0,   614,   615,   616,   617,   618,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,     0,   619,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   610,     0,   611,     0,   612,     0,   613,     0,
       0,     0,     0,     0,     0,     0,   614,   615,   616,   617,
     618,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,    45,   619,   187,     0,
     188,   543,   189,     0,   190,   191,   192,     0,     0,     0,
       0,     0,     0,    46,     0,     0,    47,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
      49,     0,    50,     0,     0,     0,    51,   193,   194,   195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,    53,    54,    55,    56,     0,     0,     0,    57,
     224,   225,   226,   227,   228,   229,   230,   806,    58,   807,
     232,   233,   234,   808,   809,   810,   811,   812,   813,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,     0,   261,
     262,   263,   264,   265,     0,   814,   187,   815,   188,   596,
     189,     0,   190,   191,   192,   187,     0,   188,   645,   189,
       0,   190,   191,   192,   187,     0,   188,   752,   189,     0,
     190,   191,   192,   187,     0,   188,     0,   189,     0,   190,
     191,   192,     0,     0,     0,   193,   194,   195,     0,     0,
       0,     0,     0,     0,   193,   194,   195,     0,     0,     0,
       0,     0,     0,   193,   194,   195,     0,     0,     0,     0,
       0,     0,   193,   194,   195,   120,     0,   121,     0,   122,
       0,   366,   124,   125,   375,     0,   376,     0,   377,     0,
     378,   379,   380,   421,     0,   422,     0,   423,     0,   424,
     425,   426,   421,     0,   422,     0,   432,     0,   424,   425,
     426,     0,     0,     0,   367,   127,   128,     0,     0,     0,
       0,     0,     0,   381,   382,   383,     0,     0,     0,     0,
       0,     0,   427,   428,   429,     0,     0,     0,     0,     0,
       0,   427,   428,   429,   421,     0,   422,     0,   433,     0,
     424,   425,   426,   421,     0,   422,     0,   434,     0,   424,
     425,   426,   421,     0,   422,     0,   435,     0,   424,   425,
     426,   421,     0,   422,     0,   436,     0,   424,   425,   426,
       0,     0,     0,   427,   428,   429,     0,     0,     0,     0,
       0,     0,   427,   428,   429,     0,     0,     0,     0,     0,
       0,   427,   428,   429,     0,     0,     0,     0,     0,     0,
     427,   428,   429,   421,     0,   422,     0,   437,     0,   424,
     425,   426,   421,     0,   422,     0,   438,     0,   424,   425,
     426,   421,     0,   422,     0,   439,     0,   424,   425,   426,
     421,     0,   422,     0,   440,     0,   424,   425,   426,     0,
       0,     0,   427,   428,   429,     0,     0,     0,     0,     0,
       0,   427,   428,   429,     0,     0,     0,     0,     0,     0,
     427,   428,   429,     0,     0,     0,     0,     0,     0,   427,
     428,   429,   421,     0,   422,     0,   441,     0,   424,   425,
     426,   421,     0,   422,     0,   442,     0,   424,   425,   426,
     326,     0,   349,     0,   444,     0,   327,   328,   329,   326,
       0,   349,     0,   446,     0,   327,   328,   329,     0,     0,
       0,   427,   428,   429,     0,     0,     0,     0,     0,     0,
     427,   428,   429,     0,     0,     0,     0,     0,     0,   330,
     331,   332,     0,     0,     0,     0,     0,     0,   330,   331,
     332,   326,     0,   349,     0,   449,     0,   327,   328,   329,
     326,     0,   349,     0,   450,     0,   327,   328,   329,   457,
       0,   458,     0,   459,     0,   460,   461,   462,   421,     0,
     422,     0,   468,     0,   424,   425,   426,     0,     0,     0,
     330,   331,   332,     0,     0,     0,     0,     0,     0,   330,
     331,   332,     0,     0,     0,     0,     0,     0,   463,   464,
     465,     0,     0,     0,     0,     0,     0,   427,   428,   429,
     421,     0,   422,     0,   474,     0,   424,   425,   426,   421,
       0,   422,     0,   484,     0,   424,   425,   426,   421,     0,
     422,     0,   485,     0,   424,   425,   426,   375,     0,   376,
       0,   487,     0,   378,   379,   380,     0,     0,     0,   427,
     428,   429,     0,     0,     0,     0,     0,     0,   427,   428,
     429,     0,     0,     0,     0,     0,     0,   427,   428,   429,
       0,     0,     0,     0,     0,     0,   381,   382,   488,   496,
       0,   497,     0,   498,     0,   499,   500,   501,   421,     0,
     422,     0,   534,     0,   424,   425,   426,   421,     0,   422,
       0,   541,     0,   424,   425,   426,   583,     0,   584,     0,
     585,     0,   586,   587,   588,     0,     0,     0,   502,   503,
     504,     0,     0,     0,     0,     0,     0,   427,   428,   429,
       0,     0,     0,     0,     0,     0,   427,   428,   429,     0,
       0,     0,     0,     0,     0,   589,   590,   591,   421,     0,
     422,     0,   643,     0,   424,   425,   426,   421,     0,   422,
       0,   646,     0,   424,   425,   426,   375,     0,   376,     0,
     710,     0,   378,   379,   380,   421,     0,   422,     0,   715,
       0,   424,   425,   426,     0,     0,     0,   427,   428,   429,
       0,     0,     0,     0,     0,     0,   427,   428,   429,     0,
       0,     0,     0,     0,     0,   381,   382,   711,     0,     0,
       0,     0,     0,     0,   427,   428,   429,   421,     0,   422,
       0,   755,     0,   424,   425,   426,   496,     0,   497,     0,
     786,     0,   499,   787,   501,   421,     0,   422,     0,   843,
       0,   424,   425,   426,   421,     0,   422,   326,   913,   349,
     424,   425,   426,   327,   328,   329,   427,   428,   429,     0,
       0,     0,     0,     0,     0,   502,   503,   504,     0,     0,
       0,     0,     0,     0,   427,   428,   429,     0,     0,     0,
       0,     0,     0,   427,   428,   429,   330,   331,   332
};

static const short yycheck[] =
{
     100,    43,   173,   453,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   513,    81,   101,   620,   287,   386,
     519,   520,   567,   168,   746,   560,    92,   749,   631,   671,
     575,   648,   115,   520,   915,   916,   917,   567,   560,    57,
     577,    30,    31,   924,   748,   575,   569,   751,   571,    91,
     554,    35,    36,    37,    38,   554,    83,   115,   115,   582,
      63,    79,   115,   115,   609,   115,     0,   571,   567,   152,
     115,   606,   571,   572,   115,   620,   575,    66,    67,   609,
      94,   513,    96,   628,    68,   572,   631,   519,   520,   626,
     620,   148,   149,   150,   152,   122,    80,    81,    82,   152,
     152,   631,   152,   648,   721,    68,    69,   152,   122,   116,
     609,   152,   116,   284,   900,   650,   115,   288,   125,   186,
     138,   620,   554,   116,   491,   124,   768,    66,   650,   628,
     197,   198,   631,   632,   633,   634,   635,   636,   637,   571,
     572,   927,   671,   115,   289,   632,   633,   116,   120,   648,
     133,   134,  1033,   119,  1035,   124,   125,   116,   141,   881,
     116,   883,   884,   147,   147,   664,   116,   133,   134,    30,
      31,   774,   671,    25,    26,   141,   721,   664,    24,    12,
     725,   147,   727,    71,   355,   454,    35,   282,   359,   116,
     285,   641,   277,   278,   138,   725,     3,   727,    10,    11,
     632,   633,   634,   635,   636,   637,    18,    19,    41,    21,
      43,    44,    45,    46,   743,   760,     3,   746,    43,    44,
     749,     4,   721,    50,    51,    52,   725,    60,   727,     3,
     760,    58,   664,     3,   276,   148,   149,   150,    83,   768,
      39,    40,   624,   116,   743,   774,   350,   746,   116,   353,
     749,    83,   356,   357,   119,   120,   112,   802,   114,   354,
     116,   760,   118,   119,   120,   119,   120,   107,   116,   768,
     125,   124,   802,   116,   116,   116,   775,   116,   116,   116,
     779,   116,   116,   782,   455,   116,   785,   116,   116,   152,
     116,   112,   116,   116,   116,   151,   152,   153,   116,   116,
     116,   472,   116,   802,   114,   116,   133,   134,   135,   136,
     137,   138,   116,   116,   141,   142,   143,   144,   145,   146,
     147,   148,   116,   150,   151,   152,   871,   154,   155,   156,
     157,   158,   159,   121,   116,   116,   163,   164,   165,   166,
     116,   871,   120,   116,   116,   116,   112,   779,   443,   116,
     782,   116,   881,   785,   883,   884,   116,   116,   903,   116,
     116,   532,   744,   116,   116,   747,   116,   116,   750,   540,
     112,   900,   871,   903,   756,   470,   118,   119,   120,   116,
     116,   116,   881,   116,   883,   884,   481,   118,   116,   123,
     935,   112,   114,   123,   513,   114,   128,   152,   927,   494,
     519,   520,   128,   114,   903,   935,   905,   114,   114,   151,
     152,   153,   114,   114,   123,   515,     5,   115,   518,   118,
     114,   521,   114,   805,   595,   152,   114,   493,     1,   529,
     975,   114,   152,   114,   114,   554,   935,     5,   115,   606,
     800,   935,   999,   538,   721,   975,   768,   529,   519,   903,
     975,   867,   571,   572,   922,   662,  1001,   575,   579,   581,
     560,   927,   774,   290,   291,    14,   279,   753,   900,    -1,
      -1,   642,  1001,    -1,    -1,    -1,   975,    -1,    -1,    -1,
      53,    -1,    -1,   310,   311,    -1,    -1,    -1,    -1,    -1,
     872,    -1,    -1,    -1,    -1,   927,    -1,   539,   880,    -1,
     882,    -1,  1001,    -1,    -1,    -1,   606,    -1,    -1,     1,
      -1,    -1,    -1,   632,   633,   634,   635,   636,   637,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,   112,    -1,   114,   115,   116,
       1,   118,   119,   120,   639,   664,    -1,    -1,    -1,   112,
     650,   114,   671,   116,    -1,   118,   119,   120,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    -1,   151,   152,   153,    -1,   112,    -1,
     114,   115,   116,   754,   118,   119,   120,    -1,   151,   152,
     153,   973,    53,   420,    -1,   977,    -1,    -1,   640,   981,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,   151,   152,   153,
      -1,  1003,  1004,  1005,   743,    -1,    -1,   746,    -1,    -1,
     749,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    -1,    -1,   475,   768,
      -1,    -1,    -1,   145,  1036,   774,    -1,    -1,    -1,    -1,
     779,   761,   762,   782,    -1,    -1,   785,     0,     1,   769,
      -1,   842,    -1,     6,     7,     8,    -1,    10,    11,    12,
      -1,    14,    15,    -1,   145,    18,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    27,    -1,   112,    30,   114,   115,
     116,    34,   118,   119,   120,    -1,    -1,    -1,    -1,   112,
      -1,   114,   115,   116,    47,   118,   119,   120,    -1,    -1,
     112,    -1,   114,   115,   116,    -1,   118,   119,   120,    62,
      -1,     1,    -1,    -1,    -1,   151,   152,   153,    -1,    72,
      73,    74,    75,    76,    77,    78,    -1,    -1,   151,   152,
     153,    84,    85,    86,    87,    88,    89,    90,    91,   151,
     152,   153,   881,    -1,   883,   884,   112,    -1,   114,   115,
     116,    -1,   118,   119,   120,    -1,   876,    -1,    -1,    -1,
      -1,   114,    -1,    53,    25,    26,   905,    28,    29,    30,
      -1,    32,    33,    -1,    -1,    -1,     6,    -1,    -1,   841,
      -1,    -1,    -1,    -1,   904,   151,   152,   153,    -1,    -1,
      -1,    -1,    22,    -1,    55,    56,    57,    -1,   151,   919,
     920,   921,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    53,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,   145,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    53,   152,   119,   154,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    53,   152,    -1,   154,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    53,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    53,
     152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    53,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    53,   152,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    53,   152,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    53,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    53,
     152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    53,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    53,   152,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    53,   152,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    53,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    53,
     152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    53,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    53,   152,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    53,   152,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    53,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    53,
     152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    53,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    53,   152,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    53,   152,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    53,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    53,
     152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    53,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    53,   152,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    53,   152,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    53,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    53,
     152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    53,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    53,   152,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    53,   152,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    53,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    53,
     152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,   113,
     114,    -1,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    53,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    53,   152,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,   113,   114,    -1,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    53,   152,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,   113,    -1,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    53,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
     122,    53,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
     152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,   116,   117,    53,   119,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
     152,    -1,   154,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,   109,    -1,   111,    -1,   113,    -1,    -1,   116,
     117,    53,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,   152,    -1,   154,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,    -1,   111,
      -1,   113,    -1,    -1,   116,    53,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
     152,    -1,   154,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      -1,   109,    -1,   111,    -1,   113,    -1,    -1,    53,    -1,
     118,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    53,   152,    -1,   154,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,   117,    53,    -1,   120,   121,   122,   123,   124,
     125,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,   154,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    53,   145,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,   152,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    -1,   113,    53,    -1,    -1,    -1,   118,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,   152,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,   113,    53,    -1,    -1,    -1,
     118,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,   152,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,   109,    -1,   111,    -1,   113,    53,    -1,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,   152,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,    -1,   109,    -1,   111,    -1,   113,    53,    -1,
      -1,    -1,   118,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,   152,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,    -1,   111,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     7,   152,   112,    -1,
     114,   115,   116,    -1,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    -1,    -1,    47,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    63,    64,    65,    66,    -1,    -1,    -1,    70,
     107,   108,   109,   110,   111,   112,   113,   114,    79,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,    -1,   152,   112,   154,   114,   115,
     116,    -1,   118,   119,   120,   112,    -1,   114,   115,   116,
      -1,   118,   119,   120,   112,    -1,   114,   115,   116,    -1,
     118,   119,   120,   112,    -1,   114,    -1,   116,    -1,   118,
     119,   120,    -1,    -1,    -1,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,   151,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,   153,   112,    -1,   114,    -1,   116,
      -1,   118,   119,   120,   112,    -1,   114,    -1,   116,    -1,
     118,   119,   120,   112,    -1,   114,    -1,   116,    -1,   118,
     119,   120,   112,    -1,   114,    -1,   116,    -1,   118,   119,
     120,    -1,    -1,    -1,   151,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   112,    -1,   114,    -1,   116,    -1,
     118,   119,   120,   112,    -1,   114,    -1,   116,    -1,   118,
     119,   120,   112,    -1,   114,    -1,   116,    -1,   118,   119,
     120,   112,    -1,   114,    -1,   116,    -1,   118,   119,   120,
      -1,    -1,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,   153,   112,    -1,   114,    -1,   116,    -1,   118,
     119,   120,   112,    -1,   114,    -1,   116,    -1,   118,   119,
     120,   112,    -1,   114,    -1,   116,    -1,   118,   119,   120,
     112,    -1,   114,    -1,   116,    -1,   118,   119,   120,    -1,
      -1,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   112,    -1,   114,    -1,   116,    -1,   118,   119,
     120,   112,    -1,   114,    -1,   116,    -1,   118,   119,   120,
     112,    -1,   114,    -1,   116,    -1,   118,   119,   120,   112,
      -1,   114,    -1,   116,    -1,   118,   119,   120,    -1,    -1,
      -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,
     153,   112,    -1,   114,    -1,   116,    -1,   118,   119,   120,
     112,    -1,   114,    -1,   116,    -1,   118,   119,   120,   112,
      -1,   114,    -1,   116,    -1,   118,   119,   120,   112,    -1,
     114,    -1,   116,    -1,   118,   119,   120,    -1,    -1,    -1,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,
     112,    -1,   114,    -1,   116,    -1,   118,   119,   120,   112,
      -1,   114,    -1,   116,    -1,   118,   119,   120,   112,    -1,
     114,    -1,   116,    -1,   118,   119,   120,   112,    -1,   114,
      -1,   116,    -1,   118,   119,   120,    -1,    -1,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,   112,
      -1,   114,    -1,   116,    -1,   118,   119,   120,   112,    -1,
     114,    -1,   116,    -1,   118,   119,   120,   112,    -1,   114,
      -1,   116,    -1,   118,   119,   120,   112,    -1,   114,    -1,
     116,    -1,   118,   119,   120,    -1,    -1,    -1,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   152,   153,   112,    -1,
     114,    -1,   116,    -1,   118,   119,   120,   112,    -1,   114,
      -1,   116,    -1,   118,   119,   120,   112,    -1,   114,    -1,
     116,    -1,   118,   119,   120,   112,    -1,   114,    -1,   116,
      -1,   118,   119,   120,    -1,    -1,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,   151,   152,   153,   112,    -1,   114,
      -1,   116,    -1,   118,   119,   120,   112,    -1,   114,    -1,
     116,    -1,   118,   119,   120,   112,    -1,   114,    -1,   116,
      -1,   118,   119,   120,   112,    -1,   114,   112,   116,   114,
     118,   119,   120,   118,   119,   120,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,   151,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,   151,   152,   153
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     1,     6,     7,     8,    12,    14,    15,    22,    23,
      24,    27,    30,    34,    47,    62,    72,    73,    74,    75,
      76,    77,    78,    84,    85,    86,    87,    88,    89,    90,
      91,   114,   151,   156,   157,   158,   187,   194,   291,   331,
     332,   326,   296,   304,   302,     7,    24,    27,    34,    41,
      43,    47,    61,    63,    64,    65,    66,    70,    79,   334,
       6,    22,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    79,    30,    31,    66,    67,   328,
     329,   292,    68,    69,   330,   328,    63,   116,   116,   116,
     116,   297,   294,   161,   162,   163,   160,   305,   159,     0,
     188,   303,    10,    11,    18,    19,    21,   116,   112,   114,
     116,   118,   119,   120,   151,   152,   153,   335,   377,   335,
     112,   114,   116,   118,   119,   120,   151,   152,   153,   341,
     379,    66,    12,    41,    43,    44,    45,    46,    60,    25,
      26,    28,    29,    30,    32,    33,    55,    56,    57,   327,
      35,    36,    37,    38,    68,    80,    81,    82,   147,    24,
     327,   327,   327,    57,    79,   138,    71,   327,   322,   310,
      35,    83,   122,   311,   116,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   306,   307,   112,   114,   116,
     118,   119,   120,   151,   152,   153,   371,   309,   308,   138,
     335,   371,     3,     3,     4,     3,   368,     3,    53,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   152,   154,   274,   285,
     286,   287,   288,   289,   290,   341,   298,   299,   300,   301,
      83,   333,   378,   336,   337,   380,   342,   343,   344,   324,
      43,    44,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   116,   327,   327,   327,
      39,    40,   327,   327,   327,   327,   327,   327,   116,   116,
     116,   327,   327,   327,   327,   116,   112,   118,   119,   120,
     151,   152,   153,   390,   369,   116,   116,    83,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   114,
     387,   388,   390,   387,   372,   293,   387,   387,   116,   295,
     115,   371,   107,   335,   341,   341,   118,   151,   351,   379,
     116,   368,   370,   369,   368,   112,   114,   116,   118,   119,
     120,   151,   152,   153,   345,   381,   370,   369,   390,   327,
     327,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   327,   327,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     323,   112,   114,   116,   118,   119,   120,   151,   152,   153,
     373,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   389,   116,   388,   116,   368,   369,   116,
     116,   369,   189,   352,   353,   354,   115,   112,   114,   116,
     118,   119,   120,   151,   152,   153,   338,   375,   116,   115,
     382,   346,   347,   338,   116,   325,   116,   116,   116,   116,
     327,   374,   368,   115,   116,   116,   195,   116,   153,   355,
     381,   370,   369,   339,   376,   368,   112,   114,   116,   118,
     119,   120,   151,   152,   153,   348,   383,   369,   327,   116,
     368,   115,     1,    53,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   145,
     196,   356,   357,   338,   116,   371,   368,   115,   384,   349,
     350,   116,   116,   115,   116,   107,   108,   109,   110,   111,
     113,   114,   116,   117,   223,   224,   280,   285,   286,   289,
     114,   154,   164,   165,   166,   274,   197,   198,   114,   220,
     274,   223,   219,   280,   274,   215,   199,   201,   204,   206,
     209,   211,   220,   112,   114,   116,   118,   119,   120,   151,
     152,   153,   358,   385,   369,   340,   115,   368,   335,   369,
     225,   112,   224,   226,   165,   166,   124,   116,   125,   250,
     107,   109,   111,   113,   121,   122,   123,   124,   125,   152,
     251,   283,   286,   290,   222,   226,   221,   226,   112,   280,
     214,   251,   255,   255,   261,   261,   263,   263,   226,   386,
     359,   360,   361,   116,   369,   115,   116,   253,   229,   115,
     124,   164,   165,   114,   167,   116,   154,   190,   283,   117,
     190,   283,   252,   253,   255,   118,   154,   191,   192,   230,
     283,   121,   216,   190,   112,   114,   280,   112,   107,   108,
     109,   110,   111,   112,   113,   114,   116,   117,   278,   285,
     286,   289,   113,   107,   108,   109,   110,   111,   112,   113,
     114,   116,   117,   277,   285,   286,   289,   109,   368,   335,
     116,   153,   362,   381,   369,   116,   114,   115,   274,   108,
     110,   228,   230,   165,   168,   250,   115,   231,   116,   120,
     121,   122,   123,   124,   125,   152,   217,   218,   275,   286,
     288,   289,   116,   200,   256,   202,   205,   262,   207,   210,
     264,   212,   115,   363,   364,   116,   254,   191,   227,   230,
      94,    96,   122,   169,   170,   117,   232,   283,   120,   112,
     114,   116,   154,   193,   267,   268,   275,   284,   253,   265,
     193,   253,   265,   193,   253,   265,   116,   119,   365,   383,
     369,   253,   118,   233,   283,   114,   171,   274,   274,   115,
     120,   119,   120,   218,   274,   269,   114,   116,   120,   121,
     122,   123,   124,   125,   152,   154,   190,   276,   284,   288,
     289,   286,   115,   107,   108,   109,   110,   111,   112,   113,
     114,   116,   117,   279,   285,   286,   289,   115,   111,   115,
     111,   366,   367,   116,   115,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   234,   235,   236,
     116,   123,   173,   112,   174,   172,   123,   170,   283,   253,
     270,   203,   266,   208,   213,   335,   369,   128,   128,   152,
     114,   152,   114,   114,   114,   114,   114,   114,   119,   236,
     237,   283,   253,   175,   123,   257,   274,   115,   253,   193,
     253,   193,   193,   116,   238,   240,   241,   242,   243,   148,
     149,   150,   245,   246,   239,   114,   116,   271,   272,   285,
     287,   288,   115,   118,   176,   228,   283,   114,   178,   274,
     107,   108,   109,   110,   111,   113,   114,   116,   117,   120,
     121,   122,   124,   125,   152,   154,   281,   286,   289,   115,
     115,   152,   244,   244,   244,   244,     5,   274,   274,   274,
     115,   246,   244,   273,   272,   177,   176,   180,   118,   181,
     179,   258,   115,   152,   115,   115,   115,   115,   114,   114,
     114,   115,   253,   232,   253,   133,   134,   141,   147,   182,
     183,   259,   253,   247,   248,   249,   115,   119,   115,   152,
     114,   114,   114,   119,   183,   114,   116,   119,   121,   122,
     123,   124,   125,   152,   154,   282,   286,   288,   290,   115,
     253,   253,   253,   184,   186,   185,   260,   115,   115,   115,
     244,     5,   244,   253,   115,   115,   115,   115
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
#line 196 "surface.yy"
    { YYACCEPT; ;}
    break;

  case 3:
#line 198 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			;}
    break;

  case 7:
#line 211 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 8:
#line 213 "surface.yy"
    {
			  int lineNr = lineNumber;
			  eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile(yyvsp[0].yyString, directory, fileName, lineNr))
			    includeFile(directory, fileName, false, lineNr);
			;}
    break;

  case 9:
#line 221 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 10:
#line 223 "surface.yy"
    {
			  int lineNr = lineNumber;
			  eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile(yyvsp[0].yyString, directory, fileName, lineNr))
			    includeFile(directory, fileName, true, lineNr);
			;}
    break;

  case 11:
#line 232 "surface.yy"
    {
			  cout << directoryManager.getCwd() << '\n';
			;}
    break;

  case 12:
#line 235 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 13:
#line 237 "surface.yy"
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

  case 14:
#line 246 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 15:
#line 248 "surface.yy"
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

  case 16:
#line 258 "surface.yy"
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

  case 17:
#line 268 "surface.yy"
    { lexerStringMode(); ;}
    break;

  case 18:
#line 270 "surface.yy"
    {
			  system((string("ls") + yyvsp[0].yyString).c_str());
			;}
    break;

  case 19:
#line 274 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			;}
    break;

  case 20:
#line 279 "surface.yy"
    {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			;}
    break;

  case 22:
#line 313 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			;}
    break;

  case 23:
#line 321 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  moduleExpressions.push(new ModuleExpression(t));
			;}
    break;

  case 25:
#line 332 "surface.yy"
    {
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			;}
    break;

  case 26:
#line 341 "surface.yy"
    {;}
    break;

  case 27:
#line 343 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			;}
    break;

  case 28:
#line 350 "surface.yy"
    {
			  moduleExpressions.push(new ModuleExpression(yyvsp[0].yyToken));
			;}
    break;

  case 29:
#line 359 "surface.yy"
    {
			  currentRenaming = new Renaming;
			;}
    break;

  case 33:
#line 370 "surface.yy"
    {
			  currentRenaming->addSortMapping(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 34:
#line 374 "surface.yy"
    {
			  currentRenaming->addLabelMapping(yyvsp[-2].yyToken, yyvsp[0].yyToken);
			;}
    break;

  case 35:
#line 377 "surface.yy"
    {;}
    break;

  case 36:
#line 380 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 37:
#line 382 "surface.yy"
    {
			  currentRenaming->addOpMapping(bubble);
			;}
    break;

  case 38:
#line 385 "surface.yy"
    { clear(); ;}
    break;

  case 39:
#line 387 "surface.yy"
    {
			  currentRenaming->addOpMapping(bubble);
			;}
    break;

  case 40:
#line 392 "surface.yy"
    {;}
    break;

  case 44:
#line 401 "surface.yy"
    {
			  clear();
			  bubble.append(yyvsp[0].yyToken);
			  currentRenaming->addType(bubble);
			;}
    break;

  case 45:
#line 406 "surface.yy"
    { clear(); ;}
    break;

  case 46:
#line 408 "surface.yy"
    {
			  currentRenaming->addType(bubble);
			;}
    break;

  case 47:
#line 413 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 48:
#line 414 "surface.yy"
    { currentRenaming->addOpTarget(bubble); ;}
    break;

  case 49:
#line 415 "surface.yy"
    { clear(); ;}
    break;

  case 50:
#line 416 "surface.yy"
    { currentRenaming->addOpTarget(bubble); ;}
    break;

  case 51:
#line 419 "surface.yy"
    {;}
    break;

  case 55:
#line 427 "surface.yy"
    { currentRenaming->setPrec(yyvsp[0].yyToken); ;}
    break;

  case 56:
#line 428 "surface.yy"
    { clear(); ;}
    break;

  case 57:
#line 429 "surface.yy"
    { currentRenaming->setGather(bubble); ;}
    break;

  case 58:
#line 430 "surface.yy"
    { clear(); ;}
    break;

  case 59:
#line 431 "surface.yy"
    { currentRenaming->setFormat(bubble); ;}
    break;

  case 60:
#line 432 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 61:
#line 433 "surface.yy"
    { currentRenaming->setLatexMacro(yyvsp[-1].yyString); ;}
    break;

  case 62:
#line 439 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 63:
#line 441 "surface.yy"
    {
			  interpreter.setCurrentModule(new PreModule(yyvsp[-3].yyToken, yyvsp[-1].yyToken));
			  fileTable.beginModule(yyvsp[-3].yyToken, yyvsp[-1].yyToken);
			;}
    break;

  case 64:
#line 446 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule(yyvsp[0].yyToken);
			;}
    break;

  case 65:
#line 453 "surface.yy"
    {;}
    break;

  case 66:
#line 455 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  store(t);
			;}
    break;

  case 67:
#line 465 "surface.yy"
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

  case 71:
#line 482 "surface.yy"
    {
			  IssueWarning(LineNumber(yyvsp[0].yyToken.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar(yyvsp[0].yyToken);
			  store(t);
			;}
    break;

  case 76:
#line 499 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport(yyvsp[-1].yyToken, me);
			;}
    break;

  case 77:
#line 505 "surface.yy"
    { clear(); ;}
    break;

  case 78:
#line 506 "surface.yy"
    { CM->addSortDecl(bubble); ;}
    break;

  case 79:
#line 508 "surface.yy"
    { clear(); ;}
    break;

  case 80:
#line 509 "surface.yy"
    { CM->addSubsortDecl(bubble); ;}
    break;

  case 81:
#line 511 "surface.yy"
    {;}
    break;

  case 82:
#line 513 "surface.yy"
    {;}
    break;

  case 83:
#line 515 "surface.yy"
    {;}
    break;

  case 84:
#line 517 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 85:
#line 518 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 86:
#line 519 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 87:
#line 521 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 88:
#line 522 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 89:
#line 523 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 90:
#line 524 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 91:
#line 526 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 92:
#line 527 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 93:
#line 528 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 94:
#line 530 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 95:
#line 531 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 96:
#line 532 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 97:
#line 533 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 98:
#line 535 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 99:
#line 536 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 100:
#line 537 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 101:
#line 539 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 102:
#line 540 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 103:
#line 541 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 104:
#line 542 "surface.yy"
    { CM->addStatement(bubble); ;}
    break;

  case 105:
#line 545 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 106:
#line 550 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 107:
#line 555 "surface.yy"
    {
			;}
    break;

  case 108:
#line 558 "surface.yy"
    {
			;}
    break;

  case 109:
#line 561 "surface.yy"
    { clear(); ;}
    break;

  case 110:
#line 562 "surface.yy"
    { CM->addSubsortDecl(bubble); ;}
    break;

  case 111:
#line 565 "surface.yy"
    {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeOpDeclsConsistent();
			;}
    break;

  case 112:
#line 575 "surface.yy"
    {;}
    break;

  case 113:
#line 576 "surface.yy"
    {;}
    break;

  case 116:
#line 584 "surface.yy"
    {
			;}
    break;

  case 117:
#line 588 "surface.yy"
    { CM->addVarDecl(yyvsp[0].yyToken); ;}
    break;

  case 118:
#line 589 "surface.yy"
    { CM->addVarDecl(yyvsp[0].yyToken); ;}
    break;

  case 119:
#line 592 "surface.yy"
    { clear(); store(yyvsp[0].yyToken); ;}
    break;

  case 120:
#line 593 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 121:
#line 594 "surface.yy"
    { clear(); ;}
    break;

  case 122:
#line 595 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 125:
#line 603 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  CM->addOpDecl(bubble);
			;}
    break;

  case 126:
#line 608 "surface.yy"
    { clear(); ;}
    break;

  case 127:
#line 609 "surface.yy"
    { CM->addOpDecl(bubble); ;}
    break;

  case 128:
#line 613 "surface.yy"
    {
			  if (yyvsp[-1].yyBool)
			    CM->convertSortsToKinds();
			;}
    break;

  case 131:
#line 623 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 132:
#line 624 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 135:
#line 632 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  CM->addType(false, bubble);
			;}
    break;

  case 136:
#line 637 "surface.yy"
    { clear(); ;}
    break;

  case 137:
#line 639 "surface.yy"
    {
			  CM->addType(true, bubble);
			;}
    break;

  case 138:
#line 644 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 139:
#line 645 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 140:
#line 648 "surface.yy"
    {;}
    break;

  case 144:
#line 657 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			;}
    break;

  case 145:
#line 661 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			;}
    break;

  case 146:
#line 665 "surface.yy"
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			;}
    break;

  case 147:
#line 671 "surface.yy"
    {
			  CM->setFlag(SymbolType::ASSOC);
			;}
    break;

  case 148:
#line 675 "surface.yy"
    {
			  CM->setFlag(SymbolType::COMM);
			;}
    break;

  case 149:
#line 678 "surface.yy"
    { clear(); ;}
    break;

  case 150:
#line 679 "surface.yy"
    { CM->setIdentity(bubble); ;}
    break;

  case 151:
#line 681 "surface.yy"
    {
			  CM->setFlag(SymbolType::IDEM);
			;}
    break;

  case 152:
#line 685 "surface.yy"
    {
			  CM->setFlag(SymbolType::ITER);
			;}
    break;

  case 153:
#line 688 "surface.yy"
    { CM->setPrec(yyvsp[0].yyToken); ;}
    break;

  case 154:
#line 689 "surface.yy"
    { clear(); ;}
    break;

  case 155:
#line 690 "surface.yy"
    { CM->setGather(bubble); ;}
    break;

  case 156:
#line 691 "surface.yy"
    { clear(); ;}
    break;

  case 157:
#line 692 "surface.yy"
    { CM->setFormat(bubble); ;}
    break;

  case 158:
#line 693 "surface.yy"
    { clear(); ;}
    break;

  case 159:
#line 694 "surface.yy"
    { CM->setStrat(bubble); ;}
    break;

  case 160:
#line 695 "surface.yy"
    { clear(); ;}
    break;

  case 161:
#line 696 "surface.yy"
    { CM->setPoly(bubble); ;}
    break;

  case 162:
#line 698 "surface.yy"
    {
			  CM->setFlag(SymbolType::MEMO);
			;}
    break;

  case 163:
#line 702 "surface.yy"
    {
			  CM->setFlag(SymbolType::CTOR);
			;}
    break;

  case 164:
#line 706 "surface.yy"
    {
			  clear();
			  CM->setFrozen(bubble);
			;}
    break;

  case 165:
#line 710 "surface.yy"
    { clear(); ;}
    break;

  case 166:
#line 711 "surface.yy"
    { CM->setFrozen(bubble); ;}
    break;

  case 167:
#line 713 "surface.yy"
    {
			  CM->setFlag(SymbolType::CONFIG);
			;}
    break;

  case 168:
#line 717 "surface.yy"
    {
			  CM->setFlag(SymbolType::OBJECT);
			;}
    break;

  case 169:
#line 721 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 170:
#line 725 "surface.yy"
    {
			  CM->setMetadata(yyvsp[0].yyToken);
			;}
    break;

  case 171:
#line 728 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 172:
#line 729 "surface.yy"
    { CM->setLatexMacro(yyvsp[-1].yyString); ;}
    break;

  case 173:
#line 730 "surface.yy"
    {;}
    break;

  case 174:
#line 732 "surface.yy"
    {
			  CM->setFlag(SymbolType::DITTO);
			;}
    break;

  case 175:
#line 737 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 176:
#line 738 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 179:
#line 746 "surface.yy"
    {
			  clear();
			  CM->addHook(PreModule::ID_HOOK, yyvsp[0].yyToken, bubble);
			;}
    break;

  case 180:
#line 750 "surface.yy"
    { clear(); ;}
    break;

  case 181:
#line 752 "surface.yy"
    {
			  CM->addHook(PreModule::ID_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 182:
#line 755 "surface.yy"
    { clear(); ;}
    break;

  case 183:
#line 757 "surface.yy"
    {
			  CM->addHook(PreModule::OP_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 184:
#line 760 "surface.yy"
    { clear(); ;}
    break;

  case 185:
#line 762 "surface.yy"
    {
			  CM->addHook(PreModule::TERM_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 186:
#line 770 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 188:
#line 774 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 189:
#line 775 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 190:
#line 776 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 191:
#line 777 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 192:
#line 783 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 193:
#line 784 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 194:
#line 785 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 196:
#line 789 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 197:
#line 790 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 198:
#line 791 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 200:
#line 795 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 201:
#line 796 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 202:
#line 797 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 204:
#line 801 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 205:
#line 802 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 206:
#line 803 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 208:
#line 807 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 209:
#line 808 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 210:
#line 809 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 212:
#line 813 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 213:
#line 814 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 214:
#line 815 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 216:
#line 819 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 217:
#line 820 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 218:
#line 821 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 221:
#line 826 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 222:
#line 827 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 223:
#line 830 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 224:
#line 831 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 225:
#line 832 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 226:
#line 833 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 227:
#line 834 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 228:
#line 835 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 229:
#line 836 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 230:
#line 842 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 231:
#line 843 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 236:
#line 847 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 237:
#line 848 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 410:
#line 949 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 411:
#line 950 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 412:
#line 952 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.setCurrentModule(bubble);
			;}
    break;

  case 413:
#line 956 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 414:
#line 957 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 415:
#line 959 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->dump();
			;}
    break;

  case 416:
#line 965 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 417:
#line 971 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(bubble);
			;}
    break;

  case 418:
#line 978 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 419:
#line 984 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(bubble);
			;}
    break;

  case 420:
#line 991 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 421:
#line 997 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(bubble, yyvsp[-3].yyBool);
			;}
    break;

  case 422:
#line 1004 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 423:
#line 1011 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(bubble, number, yyvsp[-3].yyBool);
			;}
    break;

  case 424:
#line 1017 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 425:
#line 1025 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 426:
#line 1031 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 427:
#line 1039 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 428:
#line 1045 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 429:
#line 1052 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(bubble, number);
			;}
    break;

  case 430:
#line 1058 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 431:
#line 1065 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(bubble, yyvsp[-2].yyBool, number);
			;}
    break;

  case 432:
#line 1071 "surface.yy"
    {
			  interpreter.cont(yyvsp[-1].yyInt64, yyvsp[-3].yyBool);
			;}
    break;

  case 433:
#line 1075 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 434:
#line 1081 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(bubble);
			;}
    break;

  case 435:
#line 1086 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 436:
#line 1088 "surface.yy"
    {
			  lexerInitialMode();
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(bubble);
			;}
    break;

  case 437:
#line 1095 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 438:
#line 1097 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 439:
#line 1101 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 440:
#line 1103 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude(yyvsp[-3].yyBool);
			;}
    break;

  case 441:
#line 1107 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 442:
#line 1109 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 443:
#line 1113 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 444:
#line 1115 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal(yyvsp[-3].yyBool);
			;}
    break;

  case 445:
#line 1120 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			;}
    break;

  case 446:
#line 1127 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 447:
#line 1129 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 448:
#line 1134 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 449:
#line 1136 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 450:
#line 1141 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 451:
#line 1143 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showModule(true);
			;}
    break;

  case 452:
#line 1149 "surface.yy"
    {
			  interpreter.showModules(true);
			;}
    break;

  case 453:
#line 1152 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 454:
#line 1154 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSortsAndSubsorts();
			;}
    break;

  case 455:
#line 1159 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 456:
#line 1161 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showOps();
			;}
    break;

  case 457:
#line 1166 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 458:
#line 1168 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showVars();
			;}
    break;

  case 459:
#line 1173 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 460:
#line 1175 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showMbs();
			;}
    break;

  case 461:
#line 1180 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 462:
#line 1182 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showEqs();
			;}
    break;

  case 463:
#line 1187 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 464:
#line 1189 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showRls();
			;}
    break;

  case 465:
#line 1194 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 466:
#line 1196 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSummary();
			;}
    break;

  case 467:
#line 1201 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 468:
#line 1203 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showKinds();
			;}
    break;

  case 469:
#line 1209 "surface.yy"
    {
			  interpreter.showSearchPath(yyvsp[-1].yyInt64);
			;}
    break;

  case 470:
#line 1213 "surface.yy"
    {
			  interpreter.showSearchPathLabels(yyvsp[-1].yyInt64);
			;}
    break;

  case 471:
#line 1217 "surface.yy"
    {
			  interpreter.showSearchGraph();
			;}
    break;

  case 472:
#line 1220 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 473:
#line 1222 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showProfile();
			;}
    break;

  case 474:
#line 1231 "surface.yy"
    {
			  globalAdvisoryFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 475:
#line 1235 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 476:
#line 1239 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 477:
#line 1243 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 478:
#line 1247 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, yyvsp[-1].yyBool);
			;}
    break;

  case 479:
#line 1251 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 480:
#line 1255 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, yyvsp[-1].yyBool);
			;}
    break;

  case 481:
#line 1259 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 482:
#line 1263 "surface.yy"
    {
			  MixfixModule::setPrintMixfix(yyvsp[-1].yyBool);
			;}
    break;

  case 483:
#line 1267 "surface.yy"
    {
			  MixfixModule::setPrintFlat(yyvsp[-1].yyBool);
			;}
    break;

  case 484:
#line 1271 "surface.yy"
    {
			  MixfixModule::setPrintWithAliases(yyvsp[-1].yyBool);
			;}
    break;

  case 485:
#line 1275 "surface.yy"
    {
			  MixfixModule::setPrintWithParens(yyvsp[-1].yyBool);
			;}
    break;

  case 486:
#line 1279 "surface.yy"
    {
			  MixfixModule::setPrintGraph(yyvsp[-1].yyBool);
			;}
    break;

  case 487:
#line 1283 "surface.yy"
    {
			  MixfixModule::setPrintConceal(yyvsp[-1].yyBool);
			;}
    break;

  case 488:
#line 1287 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_NUMBER, yyvsp[-1].yyBool);
			;}
    break;

  case 489:
#line 1291 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_RAT, yyvsp[-1].yyBool);
			;}
    break;

  case 490:
#line 1295 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_COLOR, yyvsp[-1].yyBool);
			;}
    break;

  case 491:
#line 1299 "surface.yy"
    {
			  MixfixModule::setPrintFormat(yyvsp[-1].yyBool);
			;}
    break;

  case 492:
#line 1303 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::TRACE, yyvsp[-1].yyBool);
			;}
    break;

  case 493:
#line 1307 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceConditionFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 494:
#line 1311 "surface.yy"
    {
			// ??? what is this supposed to do?
			;}
    break;

  case 495:
#line 1315 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceWholeFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 496:
#line 1319 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceSubstitutionFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 497:
#line 1323 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceSelectFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 498:
#line 1327 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceScFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 499:
#line 1331 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceEqFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 500:
#line 1335 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceRuleFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 501:
#line 1339 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, yyvsp[-1].yyBool);
			;}
    break;

  case 502:
#line 1342 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 503:
#line 1343 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 504:
#line 1345 "surface.yy"
    {
			  interpreter.setAutoImport(yyvsp[-5].yyImportMode, yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 505:
#line 1348 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 506:
#line 1349 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 507:
#line 1351 "surface.yy"
    {
			  interpreter.setOmodInclude(yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 508:
#line 1355 "surface.yy"
    {
			  globalVerboseFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 509:
#line 1359 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, yyvsp[-1].yyBool);
			;}
    break;

  case 510:
#line 1363 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, yyvsp[-1].yyBool);
			;}
    break;

  case 511:
#line 1367 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, yyvsp[-1].yyBool);
			;}
    break;

  case 512:
#line 1371 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 513:
#line 1375 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 514:
#line 1382 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			;}
    break;

  case 515:
#line 1386 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			;}
    break;

  case 516:
#line 1390 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			;}
    break;

  case 517:
#line 1394 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			;}
    break;

  case 518:
#line 1401 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 519:
#line 1405 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 520:
#line 1411 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 522:
#line 1418 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 523:
#line 1419 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 524:
#line 1422 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 525:
#line 1423 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 526:
#line 1426 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 527:
#line 1427 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 528:
#line 1430 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 529:
#line 1431 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 530:
#line 1434 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 531:
#line 1435 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 532:
#line 1438 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 533:
#line 1439 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 534:
#line 1442 "surface.yy"
    { yyval.yyInt64 = yyvsp[0].yyInt64; ;}
    break;

  case 535:
#line 1443 "surface.yy"
    { yyval.yyInt64 = NONE; ;}
    break;

  case 536:
#line 1446 "surface.yy"
    { yyval.yyImportMode = ImportModule::PROTECTING; ;}
    break;

  case 537:
#line 1447 "surface.yy"
    { yyval.yyImportMode = ImportModule::EXTENDING; ;}
    break;

  case 538:
#line 1448 "surface.yy"
    { yyval.yyImportMode = ImportModule::INCLUDING; ;}
    break;

  case 539:
#line 1456 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 541:
#line 1458 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 543:
#line 1462 "surface.yy"
    { moduleExpr = bubble; clear(); ;}
    break;

  case 544:
#line 1463 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 545:
#line 1464 "surface.yy"
    {;}
    break;

  case 546:
#line 1465 "surface.yy"
    {;}
    break;

  case 547:
#line 1474 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 549:
#line 1476 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 551:
#line 1478 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 553:
#line 1483 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 555:
#line 1485 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 557:
#line 1487 "surface.yy"
    {;}
    break;

  case 558:
#line 1492 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 560:
#line 1497 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 562:
#line 1499 "surface.yy"
    {;}
    break;

  case 563:
#line 1508 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 565:
#line 1510 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 567:
#line 1512 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 569:
#line 1517 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 571:
#line 1519 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 573:
#line 1521 "surface.yy"
    {;}
    break;

  case 574:
#line 1526 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 576:
#line 1531 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 578:
#line 1533 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 580:
#line 1535 "surface.yy"
    {;}
    break;

  case 581:
#line 1539 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 583:
#line 1541 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 585:
#line 1543 "surface.yy"
    {;}
    break;

  case 586:
#line 1548 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  number2 = Token::codeToInt64(bubble[3].code());
			  clear();
			;}
    break;

  case 588:
#line 1554 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 590:
#line 1556 "surface.yy"
    {;}
    break;

  case 591:
#line 1562 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 593:
#line 1566 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 595:
#line 1571 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 605:
#line 1579 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 606:
#line 1580 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 614:
#line 1584 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 615:
#line 1585 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 622:
#line 1590 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 623:
#line 1591 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 631:
#line 1595 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 632:
#line 1596 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 639:
#line 1600 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 640:
#line 1601 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 647:
#line 1606 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 648:
#line 1607 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 655:
#line 1612 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 656:
#line 1613 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 662:
#line 1618 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 663:
#line 1619 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 666:
#line 1630 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  interpreter.addSelected(bubble);
			;}
    break;

  case 667:
#line 1635 "surface.yy"
    { clear(); ;}
    break;

  case 668:
#line 1637 "surface.yy"
    {
			  interpreter.addSelected(bubble);
			;}
    break;


    }

/* Line 999 of yacc.c.  */
#line 5741 "surface.c"

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


#line 1667 "surface.yy"


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

