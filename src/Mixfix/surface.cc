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
     KW_STRAT = 378,
     KW_POLY = 379,
     KW_MEMO = 380,
     KW_FROZEN = 381,
     KW_CTOR = 382,
     KW_LATEX = 383,
     KW_SPECIAL = 384,
     KW_CONFIG = 385,
     KW_OBJ = 386,
     KW_MSG = 387,
     KW_DITTO = 388,
     KW_FORMAT = 389,
     KW_ID_HOOK = 390,
     KW_OP_HOOK = 391,
     KW_TERM_HOOK = 392,
     KW_IN = 393,
     IDENTIFIER = 394,
     NUMERIC_ID = 395,
     ENDS_IN_DOT = 396
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
#define KW_STRAT 378
#define KW_POLY 379
#define KW_MEMO 380
#define KW_FROZEN 381
#define KW_CTOR 382
#define KW_LATEX 383
#define KW_SPECIAL 384
#define KW_CONFIG 385
#define KW_OBJ 386
#define KW_MSG 387
#define KW_DITTO 388
#define KW_FORMAT 389
#define KW_ID_HOOK 390
#define KW_OP_HOOK 391
#define KW_TERM_HOOK 392
#define KW_IN 393
#define IDENTIFIER 394
#define NUMERIC_ID 395
#define ENDS_IN_DOT 396




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
#line 425 "surface.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 97 "surface.yy"

int yylex(YYSTYPE* lvalp);


/* Line 214 of yacc.c.  */
#line 440 "surface.c"

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
#define YYLAST   5376

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  154
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  236
/* YYNRULES -- Number of rules. */
#define YYNRULES  673
/* YYNRULES -- Number of states. */
#define YYNSTATES  1045

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   396

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
     147,   148,   149,   150,   151,   152,   153
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
     483,   484,   490,   495,   497,   500,   502,   505,   507,   510,
     511,   518,   519,   526,   527,   534,   537,   538,   541,   544,
     545,   550,   551,   557,   560,   561,   562,   568,   571,   572,
     573,   579,   582,   583,   584,   590,   593,   594,   595,   601,
     604,   605,   606,   612,   615,   616,   617,   623,   626,   627,
     629,   632,   634,   635,   640,   641,   647,   650,   653,   655,
     657,   660,   662,   664,   666,   668,   669,   674,   676,   678,
     680,   682,   684,   686,   688,   690,   692,   694,   696,   698,
     700,   702,   704,   706,   708,   710,   712,   714,   716,   718,
     720,   722,   724,   726,   728,   730,   732,   734,   736,   738,
     740,   742,   744,   746,   748,   750,   752,   754,   756,   758,
     760,   762,   764,   766,   768,   770,   772,   774,   776,   778,
     780,   782,   784,   786,   788,   790,   792,   794,   796,   798,
     800,   802,   804,   806,   808,   810,   812,   814,   816,   818,
     820,   822,   824,   826,   828,   830,   832,   834,   836,   838,
     840,   842,   844,   846,   848,   850,   852,   854,   856,   858,
     860,   862,   864,   866,   868,   870,   872,   874,   876,   878,
     880,   882,   884,   886,   888,   890,   892,   894,   896,   898,
     900,   902,   904,   906,   908,   910,   912,   914,   916,   918,
     920,   922,   924,   926,   928,   930,   932,   934,   936,   938,
     940,   942,   944,   946,   948,   950,   952,   954,   956,   958,
     960,   962,   964,   966,   968,   970,   972,   974,   976,   978,
     980,   982,   984,   986,   988,   990,   992,   994,   996,   998,
    1000,  1002,  1004,  1006,  1008,  1010,  1012,  1014,  1016,  1017,
    1018,  1025,  1026,  1027,  1034,  1035,  1039,  1040,  1044,  1045,
    1050,  1051,  1056,  1057,  1062,  1063,  1068,  1069,  1073,  1074,
    1078,  1083,  1084,  1088,  1089,  1094,  1095,  1101,  1102,  1108,
    1109,  1115,  1116,  1122,  1127,  1128,  1134,  1135,  1141,  1142,
    1148,  1152,  1153,  1159,  1160,  1166,  1167,  1173,  1174,  1180,
    1181,  1187,  1188,  1194,  1195,  1201,  1202,  1208,  1213,  1219,
    1224,  1225,  1231,  1237,  1243,  1250,  1256,  1262,  1269,  1275,
    1281,  1287,  1293,  1300,  1307,  1313,  1319,  1325,  1331,  1337,
    1343,  1348,  1354,  1360,  1366,  1372,  1378,  1384,  1390,  1396,
    1401,  1402,  1403,  1411,  1412,  1413,  1422,  1427,  1433,  1439,
    1445,  1450,  1456,  1459,  1462,  1465,  1468,  1474,  1479,  1480,
    1484,  1486,  1488,  1490,  1492,  1494,  1496,  1498,  1500,  1502,
    1504,  1506,  1507,  1509,  1510,  1512,  1514,  1516,  1517,  1522,
    1523,  1528,  1529,  1530,  1537,  1539,  1540,  1544,  1545,  1550,
    1551,  1556,  1557,  1561,  1562,  1567,  1569,  1570,  1574,  1575,
    1580,  1582,  1583,  1587,  1588,  1593,  1594,  1599,  1600,  1604,
    1605,  1610,  1612,  1613,  1617,  1618,  1622,  1623,  1628,  1630,
    1631,  1635,  1636,  1641,  1643,  1644,  1648,  1649,  1654,  1656,
    1659,  1660,  1663,  1664,  1667,  1668,  1670,  1672,  1674,  1676,
    1678,  1680,  1682,  1684,  1685,  1690,  1692,  1694,  1696,  1698,
    1700,  1702,  1704,  1705,  1710,  1712,  1714,  1716,  1718,  1720,
    1722,  1723,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,
    1743,  1748,  1750,  1752,  1754,  1756,  1758,  1760,  1761,  1766,
    1768,  1770,  1772,  1774,  1776,  1778,  1779,  1784,  1786,  1788,
    1790,  1792,  1794,  1796,  1797,  1802,  1804,  1806,  1808,  1810,
    1812,  1813,  1818,  1821,  1823,  1825,  1826,  1831,  1833,  1835,
    1837,  1839,  1841,  1843
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     155,     0,    -1,   156,    -1,    -1,   186,    -1,   157,    -1,
     290,    -1,    -1,   150,   158,     3,    -1,    -1,    89,   159,
       3,    -1,    84,    -1,    -1,    85,   160,     3,    -1,    -1,
      86,   161,     3,    -1,    87,    -1,    -1,    88,   162,     4,
      -1,    90,    -1,    91,    -1,   165,   116,    -1,   164,   124,
     163,    -1,   153,    -1,   165,    -1,   164,   124,   164,    -1,
     114,   164,   115,    -1,   165,   125,   166,    -1,   273,    -1,
      -1,   114,   167,   168,   115,    -1,   168,   120,   169,    -1,
     169,    -1,    94,   282,   123,   282,    -1,   122,   273,   123,
     273,    -1,    96,   170,   173,   123,   177,   180,    -1,    -1,
     273,   171,   256,    -1,    -1,   114,   172,   252,   115,    -1,
     112,   174,   227,   175,    -1,    -1,   174,   175,    -1,    -1,
     282,    -1,    -1,   118,   176,   231,   119,    -1,    -1,   273,
     178,   258,    -1,    -1,   114,   179,   252,   115,    -1,   118,
     181,   119,    -1,    -1,   181,   182,    -1,   182,    -1,   133,
     151,    -1,    -1,   134,   114,   183,   243,   115,    -1,    -1,
     146,   114,   184,   243,   115,    -1,    -1,   140,   114,   185,
       5,   115,    -1,    -1,    -1,   193,   187,   273,   107,   188,
     194,    92,    -1,   116,    -1,   153,    -1,   153,    -1,   229,
     116,    -1,   190,    -1,   266,   189,    -1,   153,    -1,     6,
      -1,     7,    -1,   194,   195,    -1,    -1,    93,   163,    -1,
      -1,    94,   196,   249,   189,    -1,    -1,    95,   197,   250,
     189,    -1,    96,   219,   225,    -1,    53,   222,   225,    -1,
      98,   218,   112,   191,    -1,    -1,    -1,   101,   198,   254,
     112,   199,   192,    -1,    -1,    -1,    -1,   102,   200,   254,
     112,   201,   264,   111,   202,   192,    -1,    -1,    -1,   103,
     203,   260,   113,   204,   192,    -1,    -1,    -1,    -1,   104,
     205,   260,   113,   206,   264,   111,   207,   192,    -1,    -1,
      -1,   105,   208,   262,   109,   209,   192,    -1,    -1,    -1,
      -1,   106,   210,   262,   109,   211,   264,   111,   212,   192,
      -1,   144,   219,   225,    -1,    97,   222,   225,    -1,    -1,
      99,   273,   213,   215,   116,    -1,    -1,   100,   214,   250,
     189,    -1,     1,   116,    -1,   121,    -1,   121,   216,    -1,
     217,    -1,   216,   120,   217,    -1,   274,   112,   273,    -1,
     218,   279,    -1,   279,    -1,    -1,   273,   220,   254,    -1,
      -1,   114,   221,   252,   115,    -1,   222,   223,    -1,   223,
      -1,   279,    -1,    -1,   114,   224,   252,   115,    -1,   112,
     228,   227,   226,    -1,   229,   232,   116,    -1,   190,    -1,
     108,    -1,   110,    -1,   228,   229,    -1,    -1,   282,    -1,
      -1,   118,   230,   231,   119,    -1,   231,   120,   282,    -1,
     282,    -1,   118,   233,   119,    -1,    -1,   233,   235,    -1,
     235,    -1,   128,    -1,   131,   128,    -1,   132,   128,    -1,
     126,    -1,   127,    -1,    -1,   234,   236,   270,    -1,   129,
      -1,   130,    -1,   133,   151,    -1,    -1,   134,   114,   237,
     243,   115,    -1,    -1,   146,   114,   238,   243,   115,    -1,
      -1,   135,   114,   239,   243,   115,    -1,    -1,   136,   114,
     240,   243,   115,    -1,   137,    -1,   139,    -1,   138,    -1,
      -1,   138,   114,   241,   243,   115,    -1,   142,    -1,   143,
      -1,   144,    -1,    -1,   140,   114,   242,     5,   115,    -1,
     141,   114,   244,   115,    -1,   145,    -1,   243,   151,    -1,
     151,    -1,   244,   245,    -1,   245,    -1,   147,   273,    -1,
      -1,   147,   273,   114,   246,   252,   115,    -1,    -1,   148,
     273,   114,   247,   252,   115,    -1,    -1,   149,   273,   114,
     248,   252,   115,    -1,   249,   282,    -1,    -1,   250,   282,
      -1,   250,   117,    -1,    -1,   282,   251,   249,   117,    -1,
      -1,   252,   114,   253,   252,   115,    -1,   252,   273,    -1,
      -1,    -1,   254,   114,   255,   252,   115,    -1,   254,   279,
      -1,    -1,    -1,   256,   114,   257,   252,   115,    -1,   256,
     280,    -1,    -1,    -1,   258,   114,   259,   252,   115,    -1,
     258,   281,    -1,    -1,    -1,   260,   114,   261,   252,   115,
      -1,   260,   277,    -1,    -1,    -1,   262,   114,   263,   252,
     115,    -1,   262,   276,    -1,    -1,    -1,   264,   114,   265,
     252,   115,    -1,   264,   278,    -1,    -1,   267,    -1,   266,
     283,    -1,   283,    -1,    -1,   114,   268,   252,   115,    -1,
      -1,   266,   114,   269,   252,   115,    -1,   267,   285,    -1,
     266,   275,    -1,   274,    -1,   271,    -1,   270,   271,    -1,
     284,    -1,   286,    -1,   287,    -1,   116,    -1,    -1,   114,
     272,   252,   115,    -1,   284,    -1,   285,    -1,   287,    -1,
     288,    -1,   116,    -1,   151,    -1,   120,    -1,   121,    -1,
     122,    -1,   123,    -1,   124,    -1,   125,    -1,   285,    -1,
     287,    -1,   288,    -1,   151,    -1,   120,    -1,   121,    -1,
     122,    -1,   123,    -1,   124,    -1,   125,    -1,   287,    -1,
     288,    -1,   284,    -1,   285,    -1,   288,    -1,   116,    -1,
     117,    -1,   112,    -1,   108,    -1,   110,    -1,   113,    -1,
     111,    -1,   107,    -1,   284,    -1,   285,    -1,   288,    -1,
     116,    -1,   117,    -1,   112,    -1,   108,    -1,   110,    -1,
     109,    -1,   111,    -1,   107,    -1,   284,    -1,   285,    -1,
     288,    -1,   116,    -1,   117,    -1,   112,    -1,   108,    -1,
     110,    -1,   113,    -1,   109,    -1,   107,    -1,   284,    -1,
     285,    -1,   288,    -1,   116,    -1,   117,    -1,   108,    -1,
     110,    -1,   113,    -1,   109,    -1,   111,    -1,   107,    -1,
     151,    -1,   153,    -1,   120,    -1,   121,    -1,   122,    -1,
     124,    -1,   125,    -1,   285,    -1,   288,    -1,   116,    -1,
     117,    -1,   108,    -1,   110,    -1,   113,    -1,   109,    -1,
     111,    -1,   107,    -1,   151,    -1,   153,    -1,   121,    -1,
     122,    -1,   123,    -1,   124,    -1,   125,    -1,   285,    -1,
     289,    -1,   116,    -1,   119,    -1,   287,    -1,   151,    -1,
     285,    -1,   289,    -1,   113,    -1,   121,    -1,   124,    -1,
     125,    -1,   109,    -1,   111,    -1,   107,    -1,   122,    -1,
     123,    -1,   116,    -1,   153,    -1,   151,    -1,   153,    -1,
     120,    -1,   121,    -1,   122,    -1,   123,    -1,   124,    -1,
     125,    -1,   144,    -1,   286,    -1,    93,    -1,    94,    -1,
      95,    -1,    96,    -1,    53,    -1,    98,    -1,    97,    -1,
      99,    -1,   100,    -1,   101,    -1,   102,    -1,   103,    -1,
     104,    -1,   105,    -1,   106,    -1,    92,    -1,   117,    -1,
     112,    -1,   108,    -1,   110,    -1,   113,    -1,   109,    -1,
     111,    -1,   107,    -1,   118,    -1,   119,    -1,   289,    -1,
     126,    -1,   127,    -1,   128,    -1,   129,    -1,   130,    -1,
     131,    -1,   132,    -1,   133,    -1,   134,    -1,   135,    -1,
     136,    -1,   137,    -1,   139,    -1,   140,    -1,   141,    -1,
     138,    -1,   142,    -1,   143,    -1,   145,    -1,   146,    -1,
     147,    -1,   148,    -1,   149,    -1,    -1,    -1,    30,   291,
     370,   292,   368,   116,    -1,    -1,    -1,    78,   293,   370,
     294,   368,   116,    -1,    -1,     8,   295,   334,    -1,    -1,
      77,   296,   334,    -1,    -1,   331,    10,   297,   334,    -1,
      -1,   331,    11,   298,   340,    -1,    -1,   331,    18,   299,
     340,    -1,    -1,   331,    19,   300,   350,    -1,    -1,    22,
     301,   340,    -1,    -1,   330,   302,   340,    -1,   331,    21,
     332,   116,    -1,    -1,    12,   303,   334,    -1,    -1,   114,
     304,   367,   115,    -1,    -1,    27,   327,   305,   386,   116,
      -1,    -1,    27,   328,   306,   386,   116,    -1,    -1,    47,
     327,   307,   386,   116,    -1,    -1,    34,   329,   308,   386,
     116,    -1,    62,    63,   137,   116,    -1,    -1,    24,     6,
     309,   368,   116,    -1,    -1,    24,    49,   310,   368,   116,
      -1,    -1,    24,    51,   311,   368,   116,    -1,    24,    50,
     116,    -1,    -1,    24,    52,   312,   368,   116,    -1,    -1,
      24,    53,   313,   368,   116,    -1,    -1,    24,    54,   314,
     368,   116,    -1,    -1,    24,    55,   315,   368,   116,    -1,
      -1,    24,    56,   316,   368,   116,    -1,    -1,    24,    57,
     317,   368,   116,    -1,    -1,    24,    58,   318,   368,   116,
      -1,    -1,    24,    59,   319,   368,   116,    -1,    24,    48,
      83,   116,    -1,    24,    48,   122,    83,   116,    -1,    24,
      22,    35,   116,    -1,    -1,    24,    79,   320,   368,   116,
      -1,    23,    24,    60,   326,   116,    -1,    23,    24,    43,
     326,   116,    -1,    23,    24,    12,    43,   326,   116,    -1,
      23,    24,    44,   326,   116,    -1,    23,    24,    46,   326,
     116,    -1,    23,    24,    12,    44,   326,   116,    -1,    23,
      24,    45,   326,   116,    -1,    23,    24,    41,   326,   116,
      -1,    23,    34,    36,   326,   116,    -1,    23,    34,    37,
     326,   116,    -1,    23,    34,    38,    40,   326,   116,    -1,
      23,    34,    38,    39,   326,   116,    -1,    23,    34,    35,
     326,   116,    -1,    23,    34,    68,   326,   116,    -1,    23,
      34,    80,   326,   116,    -1,    23,    34,    81,   326,   116,
      -1,    23,    34,    82,   326,   116,    -1,    23,    34,   146,
     326,   116,    -1,    23,    27,   326,   116,    -1,    23,    27,
      32,   326,   116,    -1,    23,    27,    28,   326,   116,    -1,
      23,    27,    29,   326,   116,    -1,    23,    27,    33,   326,
     116,    -1,    23,    27,    30,   326,   116,    -1,    23,    27,
      55,   326,   116,    -1,    23,    27,    56,   326,   116,    -1,
      23,    27,    57,   326,   116,    -1,    23,    47,   326,   116,
      -1,    -1,    -1,    23,   333,   321,   389,   322,   326,   116,
      -1,    -1,    -1,    23,     7,    66,   323,   389,   324,   326,
     116,    -1,    23,    61,   326,   116,    -1,    23,    63,   137,
     326,   116,    -1,    23,    63,    57,   326,   116,    -1,    23,
      70,    71,   326,   116,    -1,    23,    79,   326,   116,    -1,
      23,    63,    79,   326,   116,    -1,    73,   116,    -1,    74,
     116,    -1,    75,   116,    -1,    76,   116,    -1,    23,    41,
      24,   326,   116,    -1,    23,    43,   326,   116,    -1,    -1,
       1,   325,   116,    -1,    25,    -1,    26,    -1,    30,    -1,
      31,    -1,    67,    -1,    66,    -1,    68,    -1,    69,    -1,
      15,    -1,    14,    -1,    72,    -1,    -1,    83,    -1,    -1,
      64,    -1,    65,    -1,    66,    -1,    -1,   150,   335,   369,
     337,    -1,    -1,   376,   336,   368,   116,    -1,    -1,    -1,
     112,   338,   370,   339,   368,   116,    -1,   116,    -1,    -1,
     118,   341,   344,    -1,    -1,   150,   342,   369,   337,    -1,
      -1,   378,   343,   368,   116,    -1,    -1,   152,   345,   347,
      -1,    -1,   380,   346,   368,   116,    -1,   116,    -1,    -1,
     119,   348,   334,    -1,    -1,   382,   349,   368,   116,    -1,
     116,    -1,    -1,   118,   351,   354,    -1,    -1,   150,   352,
     369,   337,    -1,    -1,   378,   353,   368,   116,    -1,    -1,
     152,   355,   357,    -1,    -1,   380,   356,   368,   116,    -1,
     116,    -1,    -1,   119,   358,   334,    -1,    -1,   120,   359,
     361,    -1,    -1,   384,   360,   368,   116,    -1,   116,    -1,
      -1,   152,   362,   364,    -1,    -1,   380,   363,   368,   116,
      -1,   116,    -1,    -1,   119,   365,   334,    -1,    -1,   382,
     366,   368,   116,    -1,   116,    -1,   367,   370,    -1,    -1,
     368,   372,    -1,    -1,   369,   374,    -1,    -1,   151,    -1,
     152,    -1,   118,    -1,   119,    -1,   150,    -1,   112,    -1,
     116,    -1,   120,    -1,    -1,   114,   371,   367,   115,    -1,
     151,    -1,   152,    -1,   118,    -1,   119,    -1,   150,    -1,
     112,    -1,   120,    -1,    -1,   114,   373,   367,   115,    -1,
     151,    -1,   152,    -1,   118,    -1,   119,    -1,   150,    -1,
     120,    -1,    -1,   114,   375,   367,   115,    -1,   151,    -1,
     152,    -1,   118,    -1,   119,    -1,   112,    -1,   116,    -1,
     120,    -1,    -1,   114,   377,   367,   115,    -1,   151,    -1,
     152,    -1,   119,    -1,   112,    -1,   116,    -1,   120,    -1,
      -1,   114,   379,   367,   115,    -1,   151,    -1,   118,    -1,
     119,    -1,   150,    -1,   112,    -1,   120,    -1,    -1,   114,
     381,   367,   115,    -1,   151,    -1,   152,    -1,   118,    -1,
     150,    -1,   112,    -1,   120,    -1,    -1,   114,   383,   367,
     115,    -1,   151,    -1,   152,    -1,   118,    -1,   150,    -1,
     112,    -1,    -1,   114,   385,   367,   115,    -1,   386,   387,
      -1,   387,    -1,   389,    -1,    -1,   114,   388,   367,   115,
      -1,   151,    -1,   152,    -1,   118,    -1,   119,    -1,   150,
      -1,   112,    -1,   120,    -1
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
     724,   724,   726,   727,   733,   734,   737,   738,   741,   746,
     746,   751,   751,   756,   756,   766,   767,   770,   771,   772,
     772,   779,   779,   781,   782,   785,   785,   787,   788,   791,
     791,   793,   794,   797,   797,   799,   800,   803,   803,   805,
     806,   809,   809,   811,   812,   815,   815,   817,   818,   821,
     822,   823,   826,   826,   828,   828,   830,   831,   832,   838,
     839,   842,   842,   842,   842,   843,   843,   850,   850,   850,
     850,   850,   853,   853,   853,   853,   853,   853,   853,   854,
     854,   854,   857,   857,   857,   857,   857,   857,   857,   858,
     858,   861,   861,   861,   861,   862,   862,   862,   862,   862,
     862,   862,   865,   865,   865,   865,   866,   866,   866,   866,
     866,   866,   866,   869,   869,   869,   869,   870,   870,   870,
     870,   870,   870,   870,   873,   873,   873,   873,   874,   874,
     874,   874,   874,   874,   874,   877,   877,   877,   877,   877,
     877,   877,   878,   878,   878,   879,   879,   879,   879,   879,
     879,   879,   882,   882,   882,   882,   882,   882,   882,   883,
     883,   883,   883,   883,   886,   886,   886,   887,   887,   887,
     887,   888,   888,   888,   888,   888,   891,   891,   897,   897,
     897,   897,   897,   897,   897,   897,   900,   900,   903,   903,
     903,   903,   903,   903,   904,   904,   904,   905,   905,   905,
     905,   905,   905,   905,   908,   908,   908,   908,   908,   908,
     908,   908,   911,   911,   911,   914,   914,   914,   914,   914,
     914,   914,   915,   915,   915,   915,   915,   915,   916,   916,
     916,   917,   917,   917,   917,   918,   918,   918,   945,   946,
     945,   952,   953,   952,   961,   960,   974,   973,   987,   986,
    1000,   999,  1013,  1012,  1026,  1025,  1040,  1039,  1053,  1052,
    1065,  1070,  1069,  1081,  1081,  1090,  1090,  1096,  1096,  1102,
    1102,  1108,  1108,  1114,  1122,  1122,  1129,  1129,  1136,  1136,
    1143,  1147,  1147,  1154,  1154,  1161,  1161,  1168,  1168,  1175,
    1175,  1182,  1182,  1189,  1189,  1196,  1196,  1203,  1207,  1211,
    1215,  1215,  1225,  1229,  1233,  1237,  1241,  1245,  1249,  1253,
    1257,  1261,  1265,  1269,  1273,  1277,  1281,  1285,  1289,  1293,
    1297,  1301,  1305,  1309,  1313,  1317,  1321,  1325,  1329,  1333,
    1337,  1338,  1337,  1343,  1344,  1343,  1349,  1353,  1357,  1361,
    1365,  1369,  1376,  1380,  1384,  1388,  1395,  1399,  1406,  1406,
    1413,  1414,  1417,  1418,  1421,  1422,  1425,  1426,  1429,  1430,
    1433,  1434,  1437,  1438,  1441,  1442,  1443,  1451,  1451,  1453,
    1453,  1457,  1458,  1457,  1460,  1469,  1469,  1471,  1471,  1473,
    1473,  1478,  1478,  1480,  1480,  1482,  1487,  1486,  1492,  1492,
    1494,  1503,  1503,  1505,  1505,  1507,  1507,  1512,  1512,  1514,
    1514,  1516,  1521,  1520,  1526,  1526,  1528,  1528,  1530,  1534,
    1534,  1536,  1536,  1538,  1543,  1542,  1549,  1549,  1551,  1557,
    1558,  1561,  1562,  1566,  1567,  1573,  1573,  1573,  1573,  1573,
    1573,  1573,  1573,  1574,  1574,  1578,  1578,  1578,  1578,  1578,
    1578,  1578,  1579,  1579,  1584,  1584,  1584,  1584,  1584,  1584,
    1585,  1585,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1590,
    1590,  1594,  1594,  1594,  1594,  1594,  1594,  1595,  1595,  1600,
    1600,  1600,  1600,  1600,  1600,  1601,  1601,  1606,  1606,  1606,
    1606,  1606,  1606,  1607,  1607,  1612,  1612,  1612,  1612,  1612,
    1613,  1613,  1620,  1621,  1624,  1630,  1630,  1638,  1638,  1638,
    1638,  1638,  1638,  1638
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
  "KW_PREC", "KW_GATHER", "KW_STRAT", "KW_POLY", "KW_MEMO", "KW_FROZEN", 
  "KW_CTOR", "KW_LATEX", "KW_SPECIAL", "KW_CONFIG", "KW_OBJ", "KW_MSG", 
  "KW_DITTO", "KW_FORMAT", "KW_ID_HOOK", "KW_OP_HOOK", "KW_TERM_HOOK", 
  "KW_IN", "IDENTIFIER", "NUMERIC_ID", "ENDS_IN_DOT", "$accept", "top", 
  "item", "directive", "@1", "@2", "@3", "@4", "@5", "moduleExprDot", 
  "moduleExpr", "moduleExpr2", "renaming", "@6", "mappingList", "mapping", 
  "fromOpName", "@7", "@8", "fromSpec", "fromTypeList", "fromType", "@9", 
  "toOpName", "@10", "@11", "toAttributes", "toAttributeList", 
  "toAttribute", "@12", "@13", "@14", "module", "@15", "@16", "dot", 
  "badType", "typeDot", "endStatement", "startModule", "decList", 
  "declaration", "@17", "@18", "@19", "@20", "@21", "@22", "@23", "@24", 
  "@25", "@26", "@27", "@28", "@29", "@30", "@31", "@32", "@33", "@34", 
  "@35", "classDef", "cPairList", "cPair", "varNameList", "opName", "@36", 
  "@37", "opNameList", "simpleOpName", "@38", "domainRangeAttr", 
  "typeAttr", "arrow", "typeList", "type", "@39", "sortTokens", 
  "attributes", "attributeList", "idKeyword", "attribute", "@40", "@41", 
  "@42", "@43", "@44", "@45", "@46", "idList", "hookList", "hook", "@47", 
  "@48", "@49", "sortTokenList", "subsortList", "@50", "tokens", "@51", 
  "tokensBarColon", "@52", "tokensBarColonTo", "@53", 
  "tokensBarCommaLeft", "@54", "tokensBarEqual", "@55", "tokensBarArrow2", 
  "@56", "tokensBarIf", "@57", "endTokens", "noTrailingDot", "@58", "@59", 
  "identity", "identityChunk", "@60", "token", "tokenBarDot", "endToken", 
  "tokenBarArrow2", "tokenBarEqual", "tokenBarIf", "tokenBarColon", 
  "tokenBarColonTo", "tokenBarCommaLeft", "sortToken", "endsInDot", 
  "identifier", "startKeyword", "startKeyword2", "midKeyword", 
  "attrKeyword", "attrKeyword2", "command", "@61", "@62", "@63", "@64", 
  "@65", "@66", "@67", "@68", "@69", "@70", "@71", "@72", "@73", "@74", 
  "@75", "@76", "@77", "@78", "@79", "@80", "@81", "@82", "@83", "@84", 
  "@85", "@86", "@87", "@88", "@89", "@90", "@91", "@92", "@93", "@94", 
  "@95", "polarity", "select", "exclude", "conceal", "match", "optDebug", 
  "optNumber", "importMode", "moduleAndTerm", "@96", "@97", "inEnd", 
  "@98", "@99", "numberModuleTerm", "@100", "@101", "@102", 
  "numberModuleTerm1", "@103", "@104", "numberModuleTerm2", "@105", 
  "@106", "numbersModuleTerm", "@107", "@108", "@109", 
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
     393,   394,   395,   396
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   154,   155,   155,   156,   156,   156,   158,   157,   159,
     157,   157,   160,   157,   161,   157,   157,   162,   157,   157,
     157,   163,   163,   163,   164,   164,   165,   165,   165,   167,
     166,   168,   168,   169,   169,   169,   171,   170,   172,   170,
     173,   173,   174,   174,   175,   176,   175,   178,   177,   179,
     177,   180,   180,   181,   181,   182,   183,   182,   184,   182,
     185,   182,   187,   188,   186,   189,   189,   190,   191,   191,
     192,   192,   193,   193,   194,   194,   195,   196,   195,   197,
     195,   195,   195,   195,   198,   199,   195,   200,   201,   202,
     195,   203,   204,   195,   205,   206,   207,   195,   208,   209,
     195,   210,   211,   212,   195,   195,   195,   213,   195,   214,
     195,   195,   215,   215,   216,   216,   217,   218,   218,   220,
     219,   221,   219,   222,   222,   223,   224,   223,   225,   226,
     226,   227,   227,   228,   228,   229,   230,   229,   231,   231,
     232,   232,   233,   233,   234,   234,   234,   235,   235,   236,
     235,   235,   235,   235,   237,   235,   238,   235,   239,   235,
     240,   235,   235,   235,   235,   241,   235,   235,   235,   235,
     242,   235,   235,   235,   243,   243,   244,   244,   245,   246,
     245,   247,   245,   248,   245,   249,   249,   250,   250,   251,
     250,   253,   252,   252,   252,   255,   254,   254,   254,   257,
     256,   256,   256,   259,   258,   258,   258,   261,   260,   260,
     260,   263,   262,   262,   262,   265,   264,   264,   264,   266,
     266,   266,   268,   267,   269,   267,   267,   267,   267,   270,
     270,   271,   271,   271,   271,   272,   271,   273,   273,   273,
     273,   273,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   283,   283,   284,   284,
     284,   284,   284,   284,   284,   284,   285,   285,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   287,   287,   287,   287,   287,   287,
     287,   287,   288,   288,   288,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   291,   292,
     290,   293,   294,   290,   295,   290,   296,   290,   297,   290,
     298,   290,   299,   290,   300,   290,   301,   290,   302,   290,
     290,   303,   290,   304,   290,   305,   290,   306,   290,   307,
     290,   308,   290,   290,   309,   290,   310,   290,   311,   290,
     290,   312,   290,   313,   290,   314,   290,   315,   290,   316,
     290,   317,   290,   318,   290,   319,   290,   290,   290,   290,
     320,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     321,   322,   290,   323,   324,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   325,   290,
     326,   326,   327,   327,   328,   328,   329,   329,   330,   330,
     331,   331,   332,   332,   333,   333,   333,   335,   334,   336,
     334,   338,   339,   337,   337,   341,   340,   342,   340,   343,
     340,   345,   344,   346,   344,   344,   348,   347,   349,   347,
     347,   351,   350,   352,   350,   353,   350,   355,   354,   356,
     354,   354,   358,   357,   359,   357,   360,   357,   357,   362,
     361,   363,   361,   361,   365,   364,   366,   364,   364,   367,
     367,   368,   368,   369,   369,   370,   370,   370,   370,   370,
     370,   370,   370,   371,   370,   372,   372,   372,   372,   372,
     372,   372,   373,   372,   374,   374,   374,   374,   374,   374,
     375,   374,   376,   376,   376,   376,   376,   376,   376,   377,
     376,   378,   378,   378,   378,   378,   378,   379,   378,   380,
     380,   380,   380,   380,   380,   381,   380,   382,   382,   382,
     382,   382,   382,   383,   382,   384,   384,   384,   384,   384,
     385,   384,   386,   386,   387,   388,   387,   389,   389,   389,
     389,   389,   389,   389
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
       0,     5,     4,     1,     2,     1,     2,     1,     2,     0,
       6,     0,     6,     0,     6,     2,     0,     2,     2,     0,
       4,     0,     5,     2,     0,     0,     5,     2,     0,     0,
       5,     2,     0,     0,     5,     2,     0,     0,     5,     2,
       0,     0,     5,     2,     0,     0,     5,     2,     0,     1,
       2,     1,     0,     4,     0,     5,     2,     2,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       6,     0,     0,     6,     0,     3,     0,     3,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     3,     0,     3,
       4,     0,     3,     0,     4,     0,     5,     0,     5,     0,
       5,     0,     5,     4,     0,     5,     0,     5,     0,     5,
       3,     0,     5,     0,     5,     0,     5,     0,     5,     0,
       5,     0,     5,     0,     5,     0,     5,     4,     5,     4,
       0,     5,     5,     5,     6,     5,     5,     6,     5,     5,
       5,     5,     6,     6,     5,     5,     5,     5,     5,     5,
       4,     5,     5,     5,     5,     5,     5,     5,     5,     4,
       0,     0,     7,     0,     0,     8,     4,     5,     5,     5,
       4,     5,     2,     2,     2,     2,     5,     4,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     0,     1,     1,     1,     0,     4,     0,
       4,     0,     0,     6,     1,     0,     3,     0,     4,     0,
       4,     0,     3,     0,     4,     1,     0,     3,     0,     4,
       1,     0,     3,     0,     4,     0,     4,     0,     3,     0,
       4,     1,     0,     3,     0,     3,     0,     4,     1,     0,
       3,     0,     4,     1,     0,     3,     0,     4,     1,     2,
       0,     2,     0,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       0,     4,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     1,     1,     1,     1,     1,     1,     0,     4,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     1,     1,     1,
       0,     4,     2,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,   518,    72,    73,   414,   431,   529,   528,   426,     0,
       0,     0,   408,     0,     0,     0,   530,     0,     0,     0,
       0,   416,   411,    11,    12,    14,    16,    17,     9,    19,
      20,   433,     7,     0,     2,     5,     4,    62,     6,   428,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   534,   535,   536,     0,     0,   500,
     444,     0,     0,   446,     0,   448,   451,   453,   455,   457,
     459,   461,   463,   465,   470,   522,   523,   525,   524,   435,
     437,     0,   526,   527,   441,   439,     0,   512,   513,   514,
     515,     0,     0,     0,     0,     0,     0,   590,     0,     1,
       0,     0,   418,   420,   422,   424,   533,   519,   626,   629,
     627,   624,   625,   628,   537,   622,   623,   415,   539,   432,
     634,   637,   635,   545,   633,   636,   547,   631,   632,   427,
     549,   503,     0,     0,     0,     0,     0,     0,     0,   520,
     521,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   592,
       0,     0,     0,   592,   450,   592,   592,   592,   592,   592,
     592,   592,   592,   592,   592,     0,     0,   600,   603,   601,
     597,   598,   602,   599,   595,   596,   409,     0,     0,     0,
     417,   412,    13,    15,    18,    10,     0,     8,   362,   373,
     358,   359,   360,   361,   364,   363,   365,   366,   367,   368,
     369,   370,   371,   372,   381,   376,   379,   377,   380,   375,
     378,   241,   374,   382,   383,   350,   351,   352,   353,   354,
     355,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   400,   397,   398,   399,   401,   402,   356,
     403,   404,   405,   406,   407,   348,   349,     0,   237,   238,
     357,   239,   240,   384,   429,     0,     0,     0,     0,   532,
       0,   590,   594,   592,   590,     0,   594,   592,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   517,   499,   506,
       0,     0,     0,     0,   510,   672,   669,   670,   673,   671,
     667,   668,   501,     0,   469,   467,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   665,     0,
     663,   664,     0,   590,   592,     0,     0,   443,   592,   434,
     589,    63,   419,   421,   423,   561,   563,   425,   565,   430,
       0,     0,     0,     0,   643,   645,   555,   640,   641,   644,
     642,   639,   551,   546,   553,     0,     0,   504,     0,     0,
     479,   473,   475,   478,   476,   472,   492,   493,   495,   491,
     494,   496,   497,   498,   484,   480,   481,     0,     0,   485,
     486,   487,   488,   489,   516,   508,   511,   507,   509,     0,
     610,   612,   445,   607,   608,   611,   609,   605,   606,   591,
     468,   447,   449,   452,   454,   456,   458,   460,   462,   464,
     466,   471,   590,   436,   662,   438,     0,     0,   442,   440,
       0,    75,     0,   594,   592,   630,   541,   620,   544,   616,
     617,   619,   618,   614,   615,   538,   593,   540,   638,   590,
       0,   592,   548,   550,     0,   474,   477,   483,   482,     0,
     590,     0,   604,   410,   413,     0,   571,   567,   562,   569,
       0,     0,     0,   590,     0,   651,   653,   560,   649,   556,
     652,   650,   647,   648,   552,   558,     0,     0,   502,     0,
     666,     0,     0,    64,     0,    77,    79,     0,     0,     0,
       0,   109,    84,    87,    91,    94,    98,   101,     0,    74,
       0,   592,   564,   566,   542,     0,   646,   590,     0,   592,
     554,   505,   613,   111,   304,   299,   302,   300,   303,   301,
     126,   297,   298,     0,   124,   125,   294,   295,   296,     0,
      23,    76,     0,    24,    28,   186,     0,   121,     0,   119,
       0,     0,   118,   107,     0,   198,   198,   210,   210,   214,
     214,     0,   659,   660,   578,   657,   572,   574,   658,   655,
     656,   568,   576,     0,   592,   621,     0,   557,     0,   194,
     134,   123,    82,     0,    24,     0,    21,     0,     0,   343,
     341,   342,   337,   338,   344,   345,   339,   340,   334,     0,
     189,   335,   336,   194,    81,   198,   106,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,   105,   590,     0,
       0,   592,   570,     0,   654,   559,     0,     0,    26,     0,
      22,    25,    29,    27,    65,    66,    78,   185,   188,    80,
     187,   186,     0,   120,   136,    67,    69,    83,     0,   135,
     112,     0,   110,    85,   195,   197,    88,   282,   278,   280,
     279,   281,   277,    92,   207,   275,   276,   209,   272,   273,
     274,    95,   271,   267,    99,   268,   270,   266,   269,   211,
     264,   265,   213,   261,   262,   263,   102,     0,   573,   583,
     579,   575,   581,     0,   543,   191,   127,   193,   131,   132,
       0,   133,    25,     0,     0,   122,     0,    68,   243,   244,
     245,   246,   247,   248,   242,   113,   114,     0,   249,   250,
     251,   108,     0,   194,   218,     0,   194,   218,     0,   194,
     218,   661,     0,   592,   577,   194,   130,   128,   141,     0,
       0,     0,     0,    32,   190,     0,   139,     0,     0,   222,
     346,   347,    86,     0,   219,   228,   221,     0,     0,    93,
       0,     0,   100,     0,     0,   588,   584,   580,   586,     0,
       0,     0,     0,     0,    38,    41,    36,     0,    30,     0,
     137,     0,   115,   116,   194,   224,   346,   253,   254,   255,
     256,   257,   258,   252,   347,    70,   227,   220,   259,   260,
     226,   196,   293,   289,   292,   290,    89,   288,   291,   215,
     286,   287,   217,   283,   284,   285,   208,    96,   212,   103,
       0,   592,   582,   192,   147,   148,   144,   151,   152,     0,
       0,     0,     0,     0,     0,   162,   164,   163,     0,     0,
     167,   168,   169,   173,     0,     0,   149,   143,   129,     0,
     194,    43,     0,   202,     0,    31,   138,     0,   194,     0,
     194,     0,     0,   585,     0,   145,   146,   153,   154,   158,
     160,   165,   170,     0,   156,   140,   142,     0,    33,     0,
       0,     0,    37,    34,   223,     0,    90,     0,    97,   104,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,     0,   235,   234,   150,   229,   231,   232,   233,    39,
      45,    42,     0,    44,    49,    52,    47,   321,   316,   319,
     317,   320,   318,   199,   314,   315,   307,   308,   309,   310,
     311,   305,   306,   201,   312,   313,   225,   216,   175,     0,
       0,     0,     0,     0,   178,     0,     0,   172,   176,     0,
     194,   230,     0,    40,   194,     0,    35,   206,   194,   155,
     174,   159,   161,   166,   171,   179,   181,   183,   157,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    48,     0,
     194,   194,   194,   236,    46,    50,    55,    56,    60,    58,
      51,    53,   203,   331,   332,   324,   325,   326,   327,   328,
     322,   323,   205,   329,   333,   330,   200,     0,     0,     0,
       0,     0,     0,   194,   180,   182,   184,     0,     0,     0,
       0,    57,    61,    59,   204
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    33,    34,    35,    98,    96,    93,    94,    95,   561,
     562,   563,   653,   723,   762,   763,   795,   873,   870,   872,
     900,   931,   972,   935,   977,   974,   976,   996,   997,  1030,
    1032,  1031,    36,   100,   451,   656,   666,   667,   772,    37,
     485,   529,   565,   566,   575,   742,   576,   744,   879,   577,
     745,   578,   747,   881,   579,   748,   580,   750,   882,   629,
     574,   671,   735,   736,   571,   568,   625,   623,   553,   554,
     599,   602,   757,   720,   647,   668,   726,   765,   792,   865,
     866,   867,   897,   911,   921,   912,   913,   914,   915,   959,
     919,   920,  1000,  1001,  1002,   608,   619,   661,   646,   755,
     631,   743,   902,   978,   998,  1033,   633,   746,   635,   749,
     778,   880,   773,   774,   804,   878,   924,   925,   970,   717,
     775,   816,   702,   687,   832,   555,   953,  1022,   669,   776,
     268,   269,   270,   271,   272,   273,    38,    81,   354,    92,
     358,    42,    91,   275,   276,   277,   278,    44,   101,    43,
      97,   185,   186,   198,   197,   169,   173,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   168,   419,   288,
     474,    41,   149,    79,    80,    84,    39,    40,   280,    59,
     117,   282,   283,   465,   492,   594,   129,   285,   286,   287,
     383,   470,   471,   504,   538,   539,   367,   452,   453,   454,
     488,   530,   531,   591,   639,   640,   641,   711,   752,   753,
     787,   840,   841,   206,   333,   371,   360,   353,   429,   480,
     466,   493,   118,   281,   130,   284,   384,   469,   505,   537,
     592,   638,   349,   350,   442,   351
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -874
static const short yypact[] =
{
     603,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  4540,
     521,    12,  -874,    99,   154,    -6,  -874,   -41,     3,    11,
      38,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,   121,  -874,  -874,  -874,  -874,  -874,  -874,
     255,    49,   288,   288,  4571,   108,    50,   616,   221,   152,
     205,   205,   205,   -13,  -874,  -874,  -874,   109,   205,  -874,
    -874,   174,   -37,  -874,    73,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  4612,  -874,  -874,  -874,  -874,    77,  -874,  -874,  -874,
    -874,   288,  4612,   217,   234,   220,   244,  -874,   257,  -874,
    3434,  4571,  -874,  -874,  -874,  -874,   178,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,   196,   205,   205,   205,   205,   205,   205,  -874,
    -874,   205,   205,   205,   205,   205,   205,   205,   205,   148,
     205,   205,   205,   210,   205,   205,   205,   205,   205,   205,
     151,   156,   162,   205,   205,   205,   205,   163,   604,  -874,
     164,   166,   185,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,   661,   661,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,   661,   661,   170,
    -874,  -874,  -874,  -874,  -874,  -874,   239,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,   181,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,   288,  4571,  4571,  4621,  -874,
     175,  -874,  -874,  -874,  -874,  4630,  -874,  -874,   604,   205,
     205,   176,   179,   182,   183,   189,   190,   192,   193,   214,
     218,   223,   224,   225,   226,  -874,   227,   228,   230,   205,
     205,   232,   233,   236,   240,   245,   247,  -874,  -874,  -874,
     248,   249,   253,   258,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  4639,  -874,  -874,   259,  4680,  4689,  4698,
    4707,  4748,  4757,  4766,  4775,  4816,  4825,  4834,  -874,  4843,
    -874,  -874,  4884,  -874,  -874,  4893,  4902,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
     436,  4911,  4952,   591,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  4911,  4961,  -874,   260,   261,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,   262,   264,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,   205,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,   632,  4970,  -874,  -874,
    4979,  -874,  5020,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    5029,  -874,  -874,  -874,   205,  -874,  -874,  -874,  -874,   265,
    -874,   707,  -874,  -874,  -874,   102,  -874,  -874,  -874,  -874,
    4911,  5038,  4612,  -874,  4438,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  5047,   267,  -874,  4457,
    -874,   276,  3496,  -874,  2442,  -874,  -874,  2504,  3496,  3682,
    3434,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  2504,  -874,
    5088,  -874,  -874,  -874,  -874,  4544,  -874,  -874,   288,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  2566,  -874,  -874,  -874,  -874,  -874,  2628,
      54,  -874,   173,   -62,  -874,  -874,  4397,  -874,   200,  -874,
    2566,  3558,  -874,  -874,  4397,  -874,  -874,  -874,  -874,  -874,
    -874,   200,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  5097,  -874,  -874,  4553,  -874,  5106,  -874,
    -874,  -874,  -874,   -17,   169,  2442,  -874,   219,  3930,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  3868,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  3992,  -874,   229,
    3868,  2690,  2752,  2814,  2876,  2938,  3000,  -874,  -874,   288,
    5115,  -874,  -874,  5156,  -874,  -874,   793,  4153,  -874,  2628,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,   890,  3620,  -874,  -874,  -874,  -874,   277,  -874,
    4091,   279,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  4562,  -874,  -874,
    -874,  -874,  -874,  5165,  -874,  -874,  -874,  -874,  -874,  -874,
    3992,  -874,  -874,   -35,  4275,  -874,  4397,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,   251,  -874,   284,  -874,  -874,
    -874,  -874,  3062,  -874,  -874,  3062,  -874,  -874,  3062,  -874,
    -874,  -874,  5174,  -874,  -874,  -874,  -874,  -874,   280,  4397,
    3124,  3434,   -60,  -874,  -874,   133,  -874,  4091,  3434,  -874,
    -874,   633,  -874,  4504,   222,  -874,  -874,   987,  3186,  -874,
    1084,  3248,  -874,  1181,  3310,  -874,  -874,  -874,  -874,  5183,
    1278,   821,   281,   250,  -874,   287,  -874,   278,  -874,   -35,
    -874,  4397,  -874,  -874,  -874,  -874,   665,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,   739,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
     288,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,   283,
     285,   268,   298,   301,   302,  -874,   304,  -874,   307,   308,
    -874,  -874,  -874,  -874,   315,   734,  -874,  -874,  -874,  4397,
    -874,  -874,   310,  -874,  3434,  -874,  -874,  1375,  -874,  3062,
    -874,  3062,  3062,  -874,  5224,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,    95,  -874,  -874,  -874,  4054,  -874,  1472,
    4214,  3372,  3744,  -874,  -874,  1569,  -874,  1666,  -874,  -874,
    -874,   292,   292,   292,   292,   425,  3434,  3434,  3434,    13,
    -874,   292,  -874,  -874,  4054,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  4336,  -874,  -874,   313,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,   -63,
     -51,   -47,   -43,   339,   341,   342,   343,  -874,  -874,    -9,
    -874,  -874,  4397,  -874,  -874,    18,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  1763,
     135,  1860,   312,   344,   347,   350,    92,  -874,  3806,  1957,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  2054,  2151,  2248,
     292,   460,   292,  -874,  -874,  -874,  -874,    -2,   351,     5,
    2345,  -874,  -874,  -874,  -874
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -134,
    -508,  -534,  -874,  -874,  -874,  -327,  -874,  -874,  -874,  -874,
    -874,  -459,  -874,  -874,  -874,  -874,  -874,  -874,  -522,  -874,
    -874,  -874,  -874,  -874,  -874,  -596,  -244,  -874,  -710,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -290,  -874,   -50,  -874,  -874,   -39,  -503,
    -874,  -523,  -874,  -419,  -874,  -621,  -874,  -489,  -874,  -874,
    -874,  -381,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -873,
    -874,  -434,  -874,  -874,  -874,  -175,   -86,  -874,  -533,  -874,
    -539,  -874,  -874,  -874,  -874,  -874,   -88,  -874,   -89,  -874,
    -645,  -874,  -874,  -874,  -874,  -874,  -874,  -432,  -874,  -100,
    -650,  -874,  -874,  -874,  -874,  -500,  -874,  -874,  -490,  -280,
    -488,  -497,  -844,  -435,  -183,  -538,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,   374,   480,  -874,  -874,  -874,  -874,  -874,  -874,
     -42,  -874,  -874,  -367,  -874,  -874,   -84,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,  -874,
    -874,  -874,  -874,  -252,  -171,  -272,   -65,  -874,  -874,  -874,
    -874,  -874,  -874,  -874,   235,  -874,  -449,  -874,  -257,  -874,
    -874,  -874,   -72,  -137,  -874,  -135
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -532
static const short yytable[] =
{
     267,   119,   337,   489,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   385,   557,   196,   274,   472,   572,
     737,   557,   557,   659,   556,   604,   721,   201,   622,   370,
     556,   556,   373,   332,   672,   779,   622,   632,   782,   960,
     961,   962,    75,    76,   163,   624,   171,   626,   969,   200,
     601,   603,   979,   927,   606,   798,   557,    86,   637,   759,
     799,   760,   132,   607,   981,   556,   164,   601,   982,   621,
     622,   628,   983,   557,   557,    87,   620,   621,    77,    78,
     927,   622,   556,   556,   620,   172,   663,   761,   980,   622,
     662,   133,   622,   134,   135,   136,   137,   651,   648,   758,
     980,   446,   781,   511,   980,   784,   988,   649,   980,   622,
     138,   621,   372,  1041,   352,   604,   386,   737,   657,    88,
    1043,    99,   621,   532,   165,   355,   356,    89,   967,   660,
     621,   675,   675,   621,   557,   557,   689,   689,   704,   704,
     660,   722,   980,   556,   556,   688,   688,   703,   703,   980,
     621,   992,   993,   387,    90,   512,   980,  1037,   994,  1039,
     916,   917,   918,   675,   995,   107,   557,    82,    83,   906,
    -349,   908,   909,   738,   131,   556,   159,   815,  -349,  -349,
     166,   490,   622,   447,    75,    76,   622,   450,   622,   174,
     481,   712,   363,   364,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   170,
     777,  1010,   444,   780,   199,   444,   783,   494,   444,   444,
     202,   622,   790,   621,   204,   992,   993,   621,   509,   621,
     139,   140,   994,   362,   657,   739,   766,   203,   995,   289,
     290,   535,   916,   917,   918,   738,   528,   205,   738,   309,
     310,   738,   800,   801,  1004,   801,   150,   151,   152,   153,
     207,   279,   621,   622,   305,   102,   103,   317,   336,   793,
     738,   877,   318,   104,   105,   208,   106,   820,   319,   324,
     334,   834,   335,   491,   834,   596,   357,   834,   361,   154,
     833,   369,   390,   833,   607,   391,   833,   605,   392,   393,
     506,   155,   156,   157,   621,   394,   395,   739,   396,   397,
     739,   876,   600,   739,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   558,
     398,   622,   739,   652,   399,   558,   558,   899,   818,   400,
     401,   402,   403,   404,   405,   905,   406,   907,   409,   410,
     670,   187,   411,   188,   359,   189,   412,   190,   191,   192,
     593,   413,   622,   414,   415,   416,   259,   158,   598,   417,
     558,   767,   621,   869,   418,   430,   475,   476,   477,   898,
     478,   508,   738,   541,   738,   738,   707,   558,   558,   193,
     194,   195,   543,   727,   622,   741,   768,   868,   791,   871,
     108,   874,   109,   621,   110,   954,   111,   112,   113,   926,
     933,   885,   888,   886,   564,   889,   890,   569,   891,   887,
     573,   892,   893,   643,   160,   161,   162,   534,   569,   894,
     963,   975,   167,   901,   622,   621,   926,   989,   114,   115,
     116,   991,   933,   958,   739,   999,   739,   739,   558,   558,
     690,   690,   705,   705,   984,   985,   986,   987,  1007,   564,
    1025,  1008,   928,  1006,  1009,  1038,  1042,  1027,  1028,  1029,
     713,   650,   875,   973,  1011,   621,   756,   802,   581,   570,
     558,   932,   766,   990,   896,   968,   724,   740,   630,   928,
     634,   636,   971,   817,    85,   788,   597,     0,     0,     0,
    1040,  1023,     0,     0,     0,   564,     0,   291,   292,   293,
     294,   295,   296,   368,     0,   297,   298,   299,   300,   301,
     302,   303,   304,     0,   306,   307,   308,    60,   311,   312,
     313,   314,   315,   316,     0,     0,     0,   320,   321,   322,
     323,     0,     0,    61,     0,     0,     0,     0,   187,   564,
     188,   455,   189,     0,   190,   191,   192,     0,     0,   740,
       0,     0,   740,  1024,     0,   740,     0,     0,     0,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,   789,     0,   740,     0,   193,   194,   195,     0,
     819,     0,     0,     0,     0,   835,     0,   708,   835,     0,
      74,   835,     0,    -3,     1,     0,     0,     0,     0,     2,
       3,     4,     0,  -531,  -531,     5,     0,     6,     7,     0,
       0,  -531,  -531,     0,  -531,     8,     9,    10,     0,     0,
      11,     0,     0,    12,   -71,     0,     0,    13,     0,     0,
       0,   139,   140,     0,   141,   142,   143,     0,   144,   145,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     796,   797,     0,   388,   389,    15,   -65,     0,   803,     0,
     884,   146,   147,   148,     0,    16,    17,    18,    19,    20,
      21,    22,     0,   407,   408,     0,   -71,    23,    24,    25,
      26,    27,    28,    29,    30,     0,   740,     0,   740,   740,
       0,     0,     0,   187,     0,   188,   468,   189,     0,   190,
     191,   192,     0,     0,     0,     0,   325,    31,   -65,   955,
       0,     0,   326,   327,   328,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -66,   193,   194,   195,   187,     0,   188,   482,   189,     0,
     190,   191,   192,    32,   329,   330,   331,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,     0,   325,   903,   348,     0,   -71,     0,   326,
     327,   328,   193,   194,   195,     0,     0,     0,     0,     0,
       0,     0,   -66,   479,     0,     0,     0,     0,   883,     0,
       0,   936,     0,     0,     0,     0,     0,     0,     0,   -65,
       0,   329,   330,   331,     0,     0,   964,   965,   966,   187,
       0,   188,   510,   189,     0,   190,   191,   192,     0,     0,
       0,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   208,     0,   507,     0,
       0,     0,     0,   895,     0,     0,     0,   193,   194,   195,
     844,   845,   846,   847,   848,   849,   850,   851,   852,   853,
     854,   855,   856,   857,   858,   859,   860,   861,   862,   863,
     864,     0,     0,   -66,     0,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   715,   716,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   208,   265,     0,   266,   844,   845,   846,
     847,   848,   849,   850,   851,   852,   853,   854,   855,   856,
     857,   858,   859,   860,   861,   862,   863,   864,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   715,   725,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     208,   265,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   715,   821,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   208,   265,     0,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   715,   836,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   208,   265,     0,   266,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   715,   838,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   208,   265,     0,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   715,   843,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   208,   265,
       0,   266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   715,
     904,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   208,   265,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   715,   929,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   208,   265,     0,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   715,   956,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   208,
     265,     0,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     715,   957,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   208,   265,     0,   266,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   715,  1003,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   208,   265,     0,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   715,  1005,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     208,   265,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   715,  1026,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   208,   265,     0,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   715,  1034,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   208,   265,     0,   266,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   715,  1035,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   208,   265,     0,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   715,  1036,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   208,   265,
       0,   266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   715,
    1044,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   208,   265,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   559,   208,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,     0,   265,     0,   560,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   567,   208,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,     0,   265,     0,   266,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   544,   545,   546,   547,   548,   600,   549,
     550,   208,   551,   552,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,     0,   265,     0,   266,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   559,   208,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,     0,   265,
       0,   266,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   544,   545,   546,
     547,   548,   673,   549,   674,   208,   551,   552,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
       0,   265,     0,   266,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   544,
     545,   546,   547,   548,   676,   549,   674,   208,   551,   552,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,     0,   265,     0,   266,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   677,   678,   679,   680,   681,   682,   683,   684,   208,
     685,   686,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,     0,   265,     0,   266,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   677,   678,   679,   680,   681,   682,   691,
     684,   208,   685,   686,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,     0,   265,     0,   266,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   692,   693,   694,   695,   696,
     697,   698,   699,   208,   700,   701,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,     0,   265,
       0,   266,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   692,   693,   706,
     695,   696,   697,   698,   699,   208,   700,   701,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
       0,   265,     0,   266,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   769,   208,   770,   232,
     233,   234,   728,   729,   730,   731,   732,   733,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,     0,   734,     0,   771,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   794,   208,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,     0,   265,     0,   266,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   822,   823,   824,   825,   826,   827,   828,
     829,   208,   830,   831,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,     0,   265,     0,   266,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   822,   823,   824,   825,   837,
     827,   828,   829,   208,   830,   831,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,     0,   265,
       0,   266,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   822,   823,   824,
     825,   839,   827,   828,   829,   208,   830,   831,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
       0,   265,     0,   266,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   934,   208,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,     0,   265,     0,   266,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,     0,   208,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,     0,   265,     0,   266,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   544,   545,   546,   547,   548,     0,   549,
     550,   208,   551,   552,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,     0,   265,     0,   266,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   544,   545,   546,   547,   548,
     627,   549,     0,   208,   551,   552,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,     0,   265,
       0,   266,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   544,   545,   546,
     547,   548,     0,   549,   674,   208,   551,   552,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
       0,   265,     0,   266,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   544,
     545,   546,   547,   548,     0,   549,     0,   208,   551,   552,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,     0,   265,     0,   266,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   937,   938,   939,   940,   941,     0,   942,   943,   208,
     944,   945,   233,   234,   946,   947,   948,     0,   949,   950,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,     0,   951,     0,   952,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
    1012,   208,  1013,   232,     0,  1014,     0,  1015,  1016,  1017,
    1018,  1019,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,     0,  1020,     0,  1021,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   609,     0,   610,     0,   611,
       0,   612,     0,   208,   654,   658,     0,     0,     0,   613,
     614,   615,   616,   617,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,     0,   618,
       0,   655,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   609,     0,   610,
       0,   611,     0,   612,     0,   208,   654,     0,     0,     0,
       0,   613,   614,   615,   616,   617,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
       0,   618,     0,   655,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   609,
       0,   610,     0,   611,     0,   612,     0,   208,     0,     0,
     664,     0,     0,   613,   614,   615,   616,   617,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,     0,   618,   208,   665,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   922,     0,
     923,   232,     0,     0,   235,   236,   237,   238,   239,   240,
       0,     0,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   265,   208,   266,   232,   233,
     234,   728,   729,   730,   731,   732,   733,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,     0,   734,     0,     0,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     609,   718,   610,   719,   611,     0,   612,   208,     0,     0,
       0,   664,     0,     0,   613,   614,   615,   616,   617,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,     0,   618,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   609,   718,   610,   719,   611,     0,   612,   208,     0,
       0,     0,   930,     0,     0,   613,   614,   615,   616,   617,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,     0,   618,     0,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   609,     0,   610,     0,   611,     0,   612,   208,
       0,     0,   764,     0,     0,     0,   613,   614,   615,   616,
     617,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,     0,   618,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   609,     0,   610,     0,   611,     0,   612,
     208,     0,     0,     0,   930,     0,     0,   613,   614,   615,
     616,   617,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,     0,   618,     0,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   609,     0,   610,     0,   611,     0,
     612,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,   617,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,    45,   618,     0,
     187,     0,   188,   536,   189,     0,   190,   191,   192,     0,
       0,     0,     0,     0,    46,     0,     0,    47,     0,   187,
       0,   188,   542,   189,    48,   190,   191,   192,     0,     0,
       0,    49,     0,    50,     0,     0,     0,    51,   193,   194,
     195,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     0,    53,    54,    55,    56,   193,   194,   195,
      57,   224,   225,   226,   227,   228,   229,   230,   805,    58,
     806,   232,   233,   234,   807,   808,   809,   810,   811,   812,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,     0,   260,
     261,   262,   263,   264,     0,   813,   187,   814,   188,   595,
     189,     0,   190,   191,   192,   187,     0,   188,   644,   189,
       0,   190,   191,   192,   187,     0,   188,   751,   189,     0,
     190,   191,   192,   120,     0,   121,     0,   122,     0,   123,
     124,   125,     0,     0,   193,   194,   195,     0,     0,     0,
       0,     0,     0,   193,   194,   195,     0,     0,     0,     0,
       0,     0,   193,   194,   195,     0,     0,     0,     0,     0,
       0,   126,   127,   128,   187,     0,   188,     0,   189,     0,
     190,   191,   192,   120,     0,   121,     0,   122,     0,   365,
     124,   125,   374,     0,   375,     0,   376,     0,   377,   378,
     379,   420,     0,   421,     0,   422,     0,   423,   424,   425,
       0,     0,   193,   194,   195,     0,     0,     0,     0,     0,
       0,   366,   127,   128,     0,     0,     0,     0,     0,     0,
     380,   381,   382,     0,     0,     0,     0,     0,     0,   426,
     427,   428,   420,     0,   421,     0,   431,     0,   423,   424,
     425,   420,     0,   421,     0,   432,     0,   423,   424,   425,
     420,     0,   421,     0,   433,     0,   423,   424,   425,   420,
       0,   421,     0,   434,     0,   423,   424,   425,     0,     0,
     426,   427,   428,     0,     0,     0,     0,     0,     0,   426,
     427,   428,     0,     0,     0,     0,     0,     0,   426,   427,
     428,     0,     0,     0,     0,     0,     0,   426,   427,   428,
     420,     0,   421,     0,   435,     0,   423,   424,   425,   420,
       0,   421,     0,   436,     0,   423,   424,   425,   420,     0,
     421,     0,   437,     0,   423,   424,   425,   420,     0,   421,
       0,   438,     0,   423,   424,   425,     0,     0,   426,   427,
     428,     0,     0,     0,     0,     0,     0,   426,   427,   428,
       0,     0,     0,     0,     0,     0,   426,   427,   428,     0,
       0,     0,     0,     0,     0,   426,   427,   428,   420,     0,
     421,     0,   439,     0,   423,   424,   425,   420,     0,   421,
       0,   440,     0,   423,   424,   425,   420,     0,   421,     0,
     441,     0,   423,   424,   425,   325,     0,   348,     0,   443,
       0,   326,   327,   328,     0,     0,   426,   427,   428,     0,
       0,     0,     0,     0,     0,   426,   427,   428,     0,     0,
       0,     0,     0,     0,   426,   427,   428,     0,     0,     0,
       0,     0,     0,   329,   330,   331,   325,     0,   348,     0,
     445,     0,   326,   327,   328,   325,     0,   348,     0,   448,
       0,   326,   327,   328,   325,     0,   348,     0,   449,     0,
     326,   327,   328,   456,     0,   457,     0,   458,     0,   459,
     460,   461,     0,     0,   329,   330,   331,     0,     0,     0,
       0,     0,     0,   329,   330,   331,     0,     0,     0,     0,
       0,     0,   329,   330,   331,     0,     0,     0,     0,     0,
       0,   462,   463,   464,   420,     0,   421,     0,   467,     0,
     423,   424,   425,   420,     0,   421,     0,   473,     0,   423,
     424,   425,   420,     0,   421,     0,   483,     0,   423,   424,
     425,   420,     0,   421,     0,   484,     0,   423,   424,   425,
       0,     0,   426,   427,   428,     0,     0,     0,     0,     0,
       0,   426,   427,   428,     0,     0,     0,     0,     0,     0,
     426,   427,   428,     0,     0,     0,     0,     0,     0,   426,
     427,   428,   374,     0,   375,     0,   486,     0,   377,   378,
     379,   495,     0,   496,     0,   497,     0,   498,   499,   500,
     420,     0,   421,     0,   533,     0,   423,   424,   425,   420,
       0,   421,     0,   540,     0,   423,   424,   425,     0,     0,
     380,   381,   487,     0,     0,     0,     0,     0,     0,   501,
     502,   503,     0,     0,     0,     0,     0,     0,   426,   427,
     428,     0,     0,     0,     0,     0,     0,   426,   427,   428,
     582,     0,   583,     0,   584,     0,   585,   586,   587,   420,
       0,   421,     0,   642,     0,   423,   424,   425,   420,     0,
     421,     0,   645,     0,   423,   424,   425,   374,     0,   375,
       0,   709,     0,   377,   378,   379,     0,     0,   588,   589,
     590,     0,     0,     0,     0,     0,     0,   426,   427,   428,
       0,     0,     0,     0,     0,     0,   426,   427,   428,     0,
       0,     0,     0,     0,     0,   380,   381,   710,   420,     0,
     421,     0,   714,     0,   423,   424,   425,   420,     0,   421,
       0,   754,     0,   423,   424,   425,   495,     0,   496,     0,
     785,     0,   498,   786,   500,   420,     0,   421,     0,   842,
       0,   423,   424,   425,     0,     0,   426,   427,   428,     0,
       0,     0,     0,     0,     0,   426,   427,   428,     0,     0,
       0,     0,     0,     0,   501,   502,   503,     0,     0,     0,
       0,     0,     0,   426,   427,   428,   420,     0,   421,     0,
     910,     0,   423,   424,   425,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   426,   427,   428
};

static const short yycheck[] =
{
     100,    43,   173,   452,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   286,   512,    81,   101,   385,   519,
     670,   518,   519,   619,   512,   559,   647,    92,   566,   281,
     518,   519,   284,   168,   630,   745,   574,   576,   748,   912,
     913,   914,    30,    31,    57,   568,    83,   570,   921,    91,
     553,   559,   115,   897,   116,   115,   553,    63,   581,    94,
     120,    96,    12,   125,   115,   553,    79,   570,   115,   566,
     608,   571,   115,   570,   571,   116,   566,   574,    66,    67,
     924,   619,   570,   571,   574,   122,   625,   122,   151,   627,
     623,    41,   630,    43,    44,    45,    46,   605,   115,   720,
     151,   353,   747,     1,   151,   750,   115,   124,   151,   647,
      60,   608,   283,   115,   186,   649,   287,   767,   608,   116,
     115,     0,   619,   490,   137,   197,   198,   116,   115,   619,
     627,   631,   632,   630,   631,   632,   633,   634,   635,   636,
     630,   649,   151,   631,   632,   633,   634,   635,   636,   151,
     647,   133,   134,   288,   116,    53,   151,  1030,   140,  1032,
     147,   148,   149,   663,   146,   116,   663,    68,    69,   879,
     116,   881,   882,   670,    66,   663,    24,   773,   124,   125,
      71,   453,   720,   354,    30,    31,   724,   358,   726,   116,
     442,   640,   276,   277,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    35,
     743,   119,   349,   746,   137,   352,   749,   469,   355,   356,
       3,   759,   755,   720,     4,   133,   134,   724,   480,   726,
      25,    26,   140,   275,   724,   670,   726,     3,   146,    43,
      44,   493,   147,   148,   149,   742,   144,     3,   745,    39,
      40,   748,   119,   120,   119,   120,    35,    36,    37,    38,
       3,    83,   759,   801,   116,    10,    11,   116,    83,   759,
     767,   804,   116,    18,    19,    53,    21,   774,   116,   116,
     116,   778,   116,   454,   781,   537,   116,   784,   107,    68,
     778,   116,   116,   781,   125,   116,   784,   124,   116,   116,
     471,    80,    81,    82,   801,   116,   116,   742,   116,   116,
     745,   801,   112,   748,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   512,
     116,   869,   767,   114,   116,   518,   519,   870,   773,   116,
     116,   116,   116,   116,   116,   878,   116,   880,   116,   116,
     121,   112,   116,   114,   115,   116,   116,   118,   119,   120,
     531,   116,   900,   116,   116,   116,   144,   146,   539,   116,
     553,   120,   869,   123,   116,   116,   116,   116,   116,   869,
     116,   116,   879,   116,   881,   882,   638,   570,   571,   150,
     151,   152,   116,   116,   932,   116,   112,   116,   118,   112,
     112,   123,   114,   900,   116,   902,   118,   119,   120,   897,
     900,   128,   114,   128,   514,   114,   114,   517,   114,   151,
     520,   114,   114,   594,    50,    51,    52,   492,   528,   114,
       5,   118,    58,   123,   972,   932,   924,   970,   150,   151,
     152,   974,   932,   151,   879,   978,   881,   882,   631,   632,
     633,   634,   635,   636,   115,   114,   114,   114,   114,   559,
     998,   114,   897,   151,   114,     5,   115,  1000,  1001,  1002,
     641,   605,   799,   932,   996,   972,   720,   767,   528,   518,
     663,   900,   972,   972,   865,   919,   661,   670,   574,   924,
     578,   580,   924,   773,    14,   752,   538,    -1,    -1,    -1,
    1033,   998,    -1,    -1,    -1,   605,    -1,   133,   134,   135,
     136,   137,   138,   278,    -1,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,   150,   151,   152,     6,   154,   155,
     156,   157,   158,   159,    -1,    -1,    -1,   163,   164,   165,
     166,    -1,    -1,    22,    -1,    -1,    -1,    -1,   112,   649,
     114,   115,   116,    -1,   118,   119,   120,    -1,    -1,   742,
      -1,    -1,   745,   998,    -1,   748,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,   753,    -1,   767,    -1,   150,   151,   152,    -1,
     773,    -1,    -1,    -1,    -1,   778,    -1,   639,   781,    -1,
      79,   784,    -1,     0,     1,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    -1,    14,    15,    -1,
      -1,    18,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    30,     1,    -1,    -1,    34,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    -1,    32,    33,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     760,   761,    -1,   289,   290,    62,     1,    -1,   768,    -1,
     841,    55,    56,    57,    -1,    72,    73,    74,    75,    76,
      77,    78,    -1,   309,   310,    -1,    53,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,   879,    -1,   881,   882,
      -1,    -1,    -1,   112,    -1,   114,   115,   116,    -1,   118,
     119,   120,    -1,    -1,    -1,    -1,   112,   114,    53,   902,
      -1,    -1,   118,   119,   120,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       1,   150,   151,   152,   112,    -1,   114,   115,   116,    -1,
     118,   119,   120,   150,   150,   151,   152,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,   112,   874,   114,    -1,   144,    -1,   118,
     119,   120,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,   419,    -1,    -1,    -1,    -1,   840,    -1,
      -1,   901,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
      -1,   150,   151,   152,    -1,    -1,   916,   917,   918,   112,
      -1,   114,   115,   116,    -1,   118,   119,   120,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    53,    -1,   474,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,   150,   151,   152,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,   144,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    53,   151,    -1,   153,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      53,   151,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    53,   151,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    53,   151,    -1,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    53,   151,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    53,   151,
      -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    53,   151,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    53,   151,    -1,   153,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    53,
     151,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    53,   151,    -1,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    53,   151,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      53,   151,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    53,   151,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    53,   151,    -1,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    53,   151,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    53,   151,
      -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    53,   151,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    53,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,    -1,   153,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    53,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,    -1,   153,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    53,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,   151,    -1,   153,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    53,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   151,
      -1,   153,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    53,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,    -1,   153,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    53,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,    -1,   153,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    53,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,    -1,   153,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    53,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,   151,    -1,   153,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    53,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   151,
      -1,   153,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    53,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,    -1,   153,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    53,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,    -1,   153,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    53,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,    -1,   153,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    53,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,   151,    -1,   153,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    53,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   151,
      -1,   153,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    53,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,    -1,   153,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    53,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,    -1,   153,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    53,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,    -1,   153,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,   113,
     114,    53,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,   151,    -1,   153,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    53,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   151,
      -1,   153,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,   113,   114,    53,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,    -1,   153,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,   113,    -1,    53,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,    -1,   153,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,   113,   114,    53,
     116,   117,   118,   119,   120,   121,   122,    -1,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,    -1,   153,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    53,   116,   117,    -1,   119,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,   151,    -1,   153,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,    -1,   111,
      -1,   113,    -1,    53,   116,   117,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   151,
      -1,   153,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,   109,
      -1,   111,    -1,   113,    -1,    53,   116,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,    -1,   153,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      -1,   109,    -1,   111,    -1,   113,    -1,    53,    -1,    -1,
     118,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,    53,   153,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
     116,   117,    -1,    -1,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   151,    53,   153,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,   151,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    -1,   113,    53,    -1,    -1,
      -1,   118,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,   151,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,   113,    53,    -1,
      -1,    -1,   118,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,    -1,   111,    -1,   113,    53,
      -1,    -1,   117,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,   151,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,   109,    -1,   111,    -1,   113,
      53,    -1,    -1,    -1,   118,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,   151,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,    -1,   111,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     7,   151,    -1,
     112,    -1,   114,   115,   116,    -1,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,   112,
      -1,   114,   115,   116,    34,   118,   119,   120,    -1,    -1,
      -1,    41,    -1,    43,    -1,    -1,    -1,    47,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    63,    64,    65,    66,   150,   151,   152,
      70,   107,   108,   109,   110,   111,   112,   113,   114,    79,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,   145,
     146,   147,   148,   149,    -1,   151,   112,   153,   114,   115,
     116,    -1,   118,   119,   120,   112,    -1,   114,   115,   116,
      -1,   118,   119,   120,   112,    -1,   114,   115,   116,    -1,
     118,   119,   120,   112,    -1,   114,    -1,   116,    -1,   118,
     119,   120,    -1,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,   152,   112,    -1,   114,    -1,   116,    -1,
     118,   119,   120,   112,    -1,   114,    -1,   116,    -1,   118,
     119,   120,   112,    -1,   114,    -1,   116,    -1,   118,   119,
     120,   112,    -1,   114,    -1,   116,    -1,   118,   119,   120,
      -1,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,   152,   112,    -1,   114,    -1,   116,    -1,   118,   119,
     120,   112,    -1,   114,    -1,   116,    -1,   118,   119,   120,
     112,    -1,   114,    -1,   116,    -1,   118,   119,   120,   112,
      -1,   114,    -1,   116,    -1,   118,   119,   120,    -1,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
     112,    -1,   114,    -1,   116,    -1,   118,   119,   120,   112,
      -1,   114,    -1,   116,    -1,   118,   119,   120,   112,    -1,
     114,    -1,   116,    -1,   118,   119,   120,   112,    -1,   114,
      -1,   116,    -1,   118,   119,   120,    -1,    -1,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,   112,    -1,
     114,    -1,   116,    -1,   118,   119,   120,   112,    -1,   114,
      -1,   116,    -1,   118,   119,   120,   112,    -1,   114,    -1,
     116,    -1,   118,   119,   120,   112,    -1,   114,    -1,   116,
      -1,   118,   119,   120,    -1,    -1,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   112,    -1,   114,    -1,
     116,    -1,   118,   119,   120,   112,    -1,   114,    -1,   116,
      -1,   118,   119,   120,   112,    -1,   114,    -1,   116,    -1,
     118,   119,   120,   112,    -1,   114,    -1,   116,    -1,   118,
     119,   120,    -1,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,   152,   112,    -1,   114,    -1,   116,    -1,
     118,   119,   120,   112,    -1,   114,    -1,   116,    -1,   118,
     119,   120,   112,    -1,   114,    -1,   116,    -1,   118,   119,
     120,   112,    -1,   114,    -1,   116,    -1,   118,   119,   120,
      -1,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,   152,   112,    -1,   114,    -1,   116,    -1,   118,   119,
     120,   112,    -1,   114,    -1,   116,    -1,   118,   119,   120,
     112,    -1,   114,    -1,   116,    -1,   118,   119,   120,   112,
      -1,   114,    -1,   116,    -1,   118,   119,   120,    -1,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
     112,    -1,   114,    -1,   116,    -1,   118,   119,   120,   112,
      -1,   114,    -1,   116,    -1,   118,   119,   120,   112,    -1,
     114,    -1,   116,    -1,   118,   119,   120,   112,    -1,   114,
      -1,   116,    -1,   118,   119,   120,    -1,    -1,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,   112,    -1,
     114,    -1,   116,    -1,   118,   119,   120,   112,    -1,   114,
      -1,   116,    -1,   118,   119,   120,   112,    -1,   114,    -1,
     116,    -1,   118,   119,   120,   112,    -1,   114,    -1,   116,
      -1,   118,   119,   120,    -1,    -1,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   112,    -1,   114,    -1,
     116,    -1,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   150,   151,   152
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     1,     6,     7,     8,    12,    14,    15,    22,    23,
      24,    27,    30,    34,    47,    62,    72,    73,    74,    75,
      76,    77,    78,    84,    85,    86,    87,    88,    89,    90,
      91,   114,   150,   155,   156,   157,   186,   193,   290,   330,
     331,   325,   295,   303,   301,     7,    24,    27,    34,    41,
      43,    47,    61,    63,    64,    65,    66,    70,    79,   333,
       6,    22,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    79,    30,    31,    66,    67,   327,
     328,   291,    68,    69,   329,   327,    63,   116,   116,   116,
     116,   296,   293,   160,   161,   162,   159,   304,   158,     0,
     187,   302,    10,    11,    18,    19,    21,   116,   112,   114,
     116,   118,   119,   120,   150,   151,   152,   334,   376,   334,
     112,   114,   116,   118,   119,   120,   150,   151,   152,   340,
     378,    66,    12,    41,    43,    44,    45,    46,    60,    25,
      26,    28,    29,    30,    32,    33,    55,    56,    57,   326,
      35,    36,    37,    38,    68,    80,    81,    82,   146,    24,
     326,   326,   326,    57,    79,   137,    71,   326,   321,   309,
      35,    83,   122,   310,   116,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   305,   306,   112,   114,   116,
     118,   119,   120,   150,   151,   152,   370,   308,   307,   137,
     334,   370,     3,     3,     4,     3,   367,     3,    53,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   151,   153,   273,   284,   285,
     286,   287,   288,   289,   340,   297,   298,   299,   300,    83,
     332,   377,   335,   336,   379,   341,   342,   343,   323,    43,
      44,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   116,   326,   326,   326,    39,
      40,   326,   326,   326,   326,   326,   326,   116,   116,   116,
     326,   326,   326,   326,   116,   112,   118,   119,   120,   150,
     151,   152,   389,   368,   116,   116,    83,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   114,   386,
     387,   389,   386,   371,   292,   386,   386,   116,   294,   115,
     370,   107,   334,   340,   340,   118,   150,   350,   378,   116,
     367,   369,   368,   367,   112,   114,   116,   118,   119,   120,
     150,   151,   152,   344,   380,   369,   368,   389,   326,   326,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   326,   326,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   322,
     112,   114,   116,   118,   119,   120,   150,   151,   152,   372,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   388,   116,   387,   116,   367,   368,   116,   116,
     368,   188,   351,   352,   353,   115,   112,   114,   116,   118,
     119,   120,   150,   151,   152,   337,   374,   116,   115,   381,
     345,   346,   337,   116,   324,   116,   116,   116,   116,   326,
     373,   367,   115,   116,   116,   194,   116,   152,   354,   380,
     369,   368,   338,   375,   367,   112,   114,   116,   118,   119,
     120,   150,   151,   152,   347,   382,   368,   326,   116,   367,
     115,     1,    53,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   144,   195,
     355,   356,   337,   116,   370,   367,   115,   383,   348,   349,
     116,   116,   115,   116,   107,   108,   109,   110,   111,   113,
     114,   116,   117,   222,   223,   279,   284,   285,   288,   114,
     153,   163,   164,   165,   273,   196,   197,   114,   219,   273,
     222,   218,   279,   273,   214,   198,   200,   203,   205,   208,
     210,   219,   112,   114,   116,   118,   119,   120,   150,   151,
     152,   357,   384,   368,   339,   115,   367,   334,   368,   224,
     112,   223,   225,   164,   165,   124,   116,   125,   249,   107,
     109,   111,   113,   121,   122,   123,   124,   125,   151,   250,
     282,   285,   289,   221,   225,   220,   225,   112,   279,   213,
     250,   254,   254,   260,   260,   262,   262,   225,   385,   358,
     359,   360,   116,   368,   115,   116,   252,   228,   115,   124,
     163,   164,   114,   166,   116,   153,   189,   282,   117,   189,
     282,   251,   252,   254,   118,   153,   190,   191,   229,   282,
     121,   215,   189,   112,   114,   279,   112,   107,   108,   109,
     110,   111,   112,   113,   114,   116,   117,   277,   284,   285,
     288,   113,   107,   108,   109,   110,   111,   112,   113,   114,
     116,   117,   276,   284,   285,   288,   109,   367,   334,   116,
     152,   361,   380,   368,   116,   114,   115,   273,   108,   110,
     227,   229,   164,   167,   249,   115,   230,   116,   120,   121,
     122,   123,   124,   125,   151,   216,   217,   274,   285,   287,
     288,   116,   199,   255,   201,   204,   261,   206,   209,   263,
     211,   115,   362,   363,   116,   253,   190,   226,   229,    94,
      96,   122,   168,   169,   117,   231,   282,   120,   112,   114,
     116,   153,   192,   266,   267,   274,   283,   252,   264,   192,
     252,   264,   192,   252,   264,   116,   119,   364,   382,   368,
     252,   118,   232,   282,   114,   170,   273,   273,   115,   120,
     119,   120,   217,   273,   268,   114,   116,   120,   121,   122,
     123,   124,   125,   151,   153,   189,   275,   283,   287,   288,
     285,   115,   107,   108,   109,   110,   111,   112,   113,   114,
     116,   117,   278,   284,   285,   288,   115,   111,   115,   111,
     365,   366,   116,   115,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   233,   234,   235,   116,   123,
     172,   112,   173,   171,   123,   169,   282,   252,   269,   202,
     265,   207,   212,   334,   368,   128,   128,   151,   114,   114,
     114,   114,   114,   114,   114,   119,   235,   236,   282,   252,
     174,   123,   256,   273,   115,   252,   192,   252,   192,   192,
     116,   237,   239,   240,   241,   242,   147,   148,   149,   244,
     245,   238,   114,   116,   270,   271,   284,   286,   287,   115,
     118,   175,   227,   282,   114,   177,   273,   107,   108,   109,
     110,   111,   113,   114,   116,   117,   120,   121,   122,   124,
     125,   151,   153,   280,   285,   288,   115,   115,   151,   243,
     243,   243,   243,     5,   273,   273,   273,   115,   245,   243,
     272,   271,   176,   175,   179,   118,   180,   178,   257,   115,
     151,   115,   115,   115,   115,   114,   114,   114,   115,   252,
     231,   252,   133,   134,   140,   146,   181,   182,   258,   252,
     246,   247,   248,   115,   119,   115,   151,   114,   114,   114,
     119,   182,   114,   116,   119,   121,   122,   123,   124,   125,
     151,   153,   281,   285,   287,   289,   115,   252,   252,   252,
     183,   185,   184,   259,   115,   115,   115,   243,     5,   243,
     252,   115,   115,   115,   115
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
#line 724 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 171:
#line 725 "surface.yy"
    { CM->setLatexMacro(yyvsp[-1].yyString); ;}
    break;

  case 172:
#line 726 "surface.yy"
    {;}
    break;

  case 173:
#line 728 "surface.yy"
    {
			  CM->setFlag(SymbolType::DITTO);
			;}
    break;

  case 174:
#line 733 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 175:
#line 734 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 178:
#line 742 "surface.yy"
    {
			  clear();
			  CM->addHook(PreModule::ID_HOOK, yyvsp[0].yyToken, bubble);
			;}
    break;

  case 179:
#line 746 "surface.yy"
    { clear(); ;}
    break;

  case 180:
#line 748 "surface.yy"
    {
			  CM->addHook(PreModule::ID_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 181:
#line 751 "surface.yy"
    { clear(); ;}
    break;

  case 182:
#line 753 "surface.yy"
    {
			  CM->addHook(PreModule::OP_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 183:
#line 756 "surface.yy"
    { clear(); ;}
    break;

  case 184:
#line 758 "surface.yy"
    {
			  CM->addHook(PreModule::TERM_HOOK, yyvsp[-4].yyToken, bubble);
			;}
    break;

  case 185:
#line 766 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 187:
#line 770 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 188:
#line 771 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 189:
#line 772 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 190:
#line 773 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 191:
#line 779 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 192:
#line 780 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 193:
#line 781 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 195:
#line 785 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 196:
#line 786 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 197:
#line 787 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 199:
#line 791 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 200:
#line 792 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 201:
#line 793 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 203:
#line 797 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 204:
#line 798 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 205:
#line 799 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 207:
#line 803 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 208:
#line 804 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 209:
#line 805 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 211:
#line 809 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 212:
#line 810 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 213:
#line 811 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 215:
#line 815 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 216:
#line 816 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 217:
#line 817 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 220:
#line 822 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 221:
#line 823 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 222:
#line 826 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 223:
#line 827 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 224:
#line 828 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 225:
#line 829 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 226:
#line 830 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 227:
#line 831 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 228:
#line 832 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 229:
#line 838 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 230:
#line 839 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 235:
#line 843 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 236:
#line 844 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 408:
#line 945 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 409:
#line 946 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 410:
#line 948 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.setCurrentModule(bubble);
			;}
    break;

  case 411:
#line 952 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 412:
#line 953 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 413:
#line 955 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->dump();
			;}
    break;

  case 414:
#line 961 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 415:
#line 967 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(bubble);
			;}
    break;

  case 416:
#line 974 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 417:
#line 980 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(bubble);
			;}
    break;

  case 418:
#line 987 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 419:
#line 993 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(bubble, yyvsp[-3].yyBool);
			;}
    break;

  case 420:
#line 1000 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 421:
#line 1007 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(bubble, number, yyvsp[-3].yyBool);
			;}
    break;

  case 422:
#line 1013 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 423:
#line 1020 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 424:
#line 1026 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 425:
#line 1034 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(bubble, number, number2, yyvsp[-3].yyBool);
			;}
    break;

  case 426:
#line 1040 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 427:
#line 1047 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(bubble, number);
			;}
    break;

  case 428:
#line 1053 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 429:
#line 1060 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(bubble, yyvsp[-2].yyBool, number);
			;}
    break;

  case 430:
#line 1066 "surface.yy"
    {
			  interpreter.cont(yyvsp[-1].yyInt64, yyvsp[-3].yyBool);
			;}
    break;

  case 431:
#line 1070 "surface.yy"
    {
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 432:
#line 1076 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(bubble);
			;}
    break;

  case 433:
#line 1081 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 434:
#line 1083 "surface.yy"
    {
			  lexerInitialMode();
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(bubble);
			;}
    break;

  case 435:
#line 1090 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 436:
#line 1092 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 437:
#line 1096 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 438:
#line 1098 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude(yyvsp[-3].yyBool);
			;}
    break;

  case 439:
#line 1102 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 440:
#line 1104 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect(yyvsp[-3].yyBool);
			;}
    break;

  case 441:
#line 1108 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 442:
#line 1110 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal(yyvsp[-3].yyBool);
			;}
    break;

  case 443:
#line 1115 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			;}
    break;

  case 444:
#line 1122 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 445:
#line 1124 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 446:
#line 1129 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 447:
#line 1131 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			;}
    break;

  case 448:
#line 1136 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 449:
#line 1138 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showModule(true);
			;}
    break;

  case 450:
#line 1144 "surface.yy"
    {
			  interpreter.showModules(true);
			;}
    break;

  case 451:
#line 1147 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 452:
#line 1149 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSortsAndSubsorts();
			;}
    break;

  case 453:
#line 1154 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 454:
#line 1156 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showOps();
			;}
    break;

  case 455:
#line 1161 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 456:
#line 1163 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showVars();
			;}
    break;

  case 457:
#line 1168 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 458:
#line 1170 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showMbs();
			;}
    break;

  case 459:
#line 1175 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 460:
#line 1177 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showEqs();
			;}
    break;

  case 461:
#line 1182 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 462:
#line 1184 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showRls();
			;}
    break;

  case 463:
#line 1189 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 464:
#line 1191 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSummary();
			;}
    break;

  case 465:
#line 1196 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 466:
#line 1198 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showKinds();
			;}
    break;

  case 467:
#line 1204 "surface.yy"
    {
			  interpreter.showSearchPath(yyvsp[-1].yyInt64);
			;}
    break;

  case 468:
#line 1208 "surface.yy"
    {
			  interpreter.showSearchPathLabels(yyvsp[-1].yyInt64);
			;}
    break;

  case 469:
#line 1212 "surface.yy"
    {
			  interpreter.showSearchGraph();
			;}
    break;

  case 470:
#line 1215 "surface.yy"
    { lexerCmdMode(); clear(); ;}
    break;

  case 471:
#line 1217 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showProfile();
			;}
    break;

  case 472:
#line 1226 "surface.yy"
    {
			  globalAdvisoryFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 473:
#line 1230 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 474:
#line 1234 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 475:
#line 1238 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 476:
#line 1242 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, yyvsp[-1].yyBool);
			;}
    break;

  case 477:
#line 1246 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, yyvsp[-1].yyBool);
			;}
    break;

  case 478:
#line 1250 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, yyvsp[-1].yyBool);
			;}
    break;

  case 479:
#line 1254 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 480:
#line 1258 "surface.yy"
    {
			  MixfixModule::setPrintMixfix(yyvsp[-1].yyBool);
			;}
    break;

  case 481:
#line 1262 "surface.yy"
    {
			  MixfixModule::setPrintFlat(yyvsp[-1].yyBool);
			;}
    break;

  case 482:
#line 1266 "surface.yy"
    {
			  MixfixModule::setPrintWithAliases(yyvsp[-1].yyBool);
			;}
    break;

  case 483:
#line 1270 "surface.yy"
    {
			  MixfixModule::setPrintWithParens(yyvsp[-1].yyBool);
			;}
    break;

  case 484:
#line 1274 "surface.yy"
    {
			  MixfixModule::setPrintGraph(yyvsp[-1].yyBool);
			;}
    break;

  case 485:
#line 1278 "surface.yy"
    {
			  MixfixModule::setPrintConceal(yyvsp[-1].yyBool);
			;}
    break;

  case 486:
#line 1282 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_NUMBER, yyvsp[-1].yyBool);
			;}
    break;

  case 487:
#line 1286 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_RAT, yyvsp[-1].yyBool);
			;}
    break;

  case 488:
#line 1290 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PRINT_COLOR, yyvsp[-1].yyBool);
			;}
    break;

  case 489:
#line 1294 "surface.yy"
    {
			  MixfixModule::setPrintFormat(yyvsp[-1].yyBool);
			;}
    break;

  case 490:
#line 1298 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::TRACE, yyvsp[-1].yyBool);
			;}
    break;

  case 491:
#line 1302 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceConditionFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 492:
#line 1306 "surface.yy"
    {
			// ??? what is this supposed to do?
			;}
    break;

  case 493:
#line 1310 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceWholeFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 494:
#line 1314 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceSubstitutionFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 495:
#line 1318 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceSelectFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 496:
#line 1322 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceScFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 497:
#line 1326 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceEqFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 498:
#line 1330 "surface.yy"
    {
			  UserLevelRewritingContext::setTraceRuleFlag(yyvsp[-1].yyBool);
			;}
    break;

  case 499:
#line 1334 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, yyvsp[-1].yyBool);
			;}
    break;

  case 500:
#line 1337 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 501:
#line 1338 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 502:
#line 1340 "surface.yy"
    {
			  interpreter.setAutoImport(yyvsp[-5].yyImportMode, yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 503:
#line 1343 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 504:
#line 1344 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 505:
#line 1346 "surface.yy"
    {
			  interpreter.setOmodInclude(yyvsp[-3].yyToken, yyvsp[-1].yyBool);
			;}
    break;

  case 506:
#line 1350 "surface.yy"
    {
			  globalVerboseFlag = yyvsp[-1].yyBool;
			;}
    break;

  case 507:
#line 1354 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, yyvsp[-1].yyBool);
			;}
    break;

  case 508:
#line 1358 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, yyvsp[-1].yyBool);
			;}
    break;

  case 509:
#line 1362 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, yyvsp[-1].yyBool);
			;}
    break;

  case 510:
#line 1366 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 511:
#line 1370 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, yyvsp[-1].yyBool);
			;}
    break;

  case 512:
#line 1377 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			;}
    break;

  case 513:
#line 1381 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			;}
    break;

  case 514:
#line 1385 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			;}
    break;

  case 515:
#line 1389 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			;}
    break;

  case 516:
#line 1396 "surface.yy"
    {
			  MemoryCell::setShowGC(yyvsp[-1].yyBool);
			;}
    break;

  case 517:
#line 1400 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, yyvsp[-1].yyBool);
			;}
    break;

  case 518:
#line 1406 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 520:
#line 1413 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 521:
#line 1414 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 522:
#line 1417 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 523:
#line 1418 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 524:
#line 1421 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 525:
#line 1422 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 526:
#line 1425 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 527:
#line 1426 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 528:
#line 1429 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 529:
#line 1430 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 530:
#line 1433 "surface.yy"
    { yyval.yyBool = true; ;}
    break;

  case 531:
#line 1434 "surface.yy"
    { yyval.yyBool = false; ;}
    break;

  case 532:
#line 1437 "surface.yy"
    { yyval.yyInt64 = yyvsp[0].yyInt64; ;}
    break;

  case 533:
#line 1438 "surface.yy"
    { yyval.yyInt64 = NONE; ;}
    break;

  case 534:
#line 1441 "surface.yy"
    { yyval.yyImportMode = ImportModule::PROTECTING; ;}
    break;

  case 535:
#line 1442 "surface.yy"
    { yyval.yyImportMode = ImportModule::EXTENDING; ;}
    break;

  case 536:
#line 1443 "surface.yy"
    { yyval.yyImportMode = ImportModule::INCLUDING; ;}
    break;

  case 537:
#line 1451 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 539:
#line 1453 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 541:
#line 1457 "surface.yy"
    { moduleExpr = bubble; clear(); ;}
    break;

  case 542:
#line 1458 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 543:
#line 1459 "surface.yy"
    {;}
    break;

  case 544:
#line 1460 "surface.yy"
    {;}
    break;

  case 545:
#line 1469 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 547:
#line 1471 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 549:
#line 1473 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 551:
#line 1478 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 553:
#line 1480 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 555:
#line 1482 "surface.yy"
    {;}
    break;

  case 556:
#line 1487 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 558:
#line 1492 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 560:
#line 1494 "surface.yy"
    {;}
    break;

  case 561:
#line 1503 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 563:
#line 1505 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 565:
#line 1507 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 567:
#line 1512 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 569:
#line 1514 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 571:
#line 1516 "surface.yy"
    {;}
    break;

  case 572:
#line 1521 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			;}
    break;

  case 574:
#line 1526 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 576:
#line 1528 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 578:
#line 1530 "surface.yy"
    {;}
    break;

  case 579:
#line 1534 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 581:
#line 1536 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 583:
#line 1538 "surface.yy"
    {;}
    break;

  case 584:
#line 1543 "surface.yy"
    {
			  number = Token::codeToInt64(bubble[1].code());
			  number2 = Token::codeToInt64(bubble[3].code());
			  clear();
			;}
    break;

  case 586:
#line 1549 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 588:
#line 1551 "surface.yy"
    {;}
    break;

  case 589:
#line 1557 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 591:
#line 1561 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 593:
#line 1566 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 603:
#line 1574 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 604:
#line 1575 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 612:
#line 1579 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 613:
#line 1580 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 620:
#line 1585 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 621:
#line 1586 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 629:
#line 1590 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 630:
#line 1591 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 637:
#line 1595 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 638:
#line 1596 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 645:
#line 1601 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 646:
#line 1602 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 653:
#line 1607 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 654:
#line 1608 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 660:
#line 1613 "surface.yy"
    { store(yyvsp[0].yyToken); ;}
    break;

  case 661:
#line 1614 "surface.yy"
    { yyval.yyToken = yyvsp[0].yyToken; ;}
    break;

  case 664:
#line 1625 "surface.yy"
    {
			  clear();
			  store(yyvsp[0].yyToken);
			  interpreter.addSelected(bubble);
			;}
    break;

  case 665:
#line 1630 "surface.yy"
    { clear(); ;}
    break;

  case 666:
#line 1632 "surface.yy"
    {
			  interpreter.addSelected(bubble);
			;}
    break;


    }

/* Line 999 of yacc.c.  */
#line 5575 "surface.c"

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


#line 1662 "surface.yy"


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

