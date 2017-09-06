/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Bison version.  */
#define YYBISON_VERSION "2.1"

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
     KW_WITH = 295,
     KW_PARENS = 296,
     KW_ALIASES = 297,
     KW_GC = 298,
     KW_TIME = 299,
     KW_STATS = 300,
     KW_TIMING = 301,
     KW_CMD = 302,
     KW_BREAKDOWN = 303,
     KW_BREAK = 304,
     KW_PATH = 305,
     KW_MODULE = 306,
     KW_MODULES = 307,
     KW_VIEWS = 308,
     KW_ALL = 309,
     KW_SORTS = 310,
     KW_OPS = 311,
     KW_VARS = 312,
     KW_MBS = 313,
     KW_EQS = 314,
     KW_RLS = 315,
     KW_SUMMARY = 316,
     KW_KINDS = 317,
     KW_ADVISE = 318,
     KW_VERBOSE = 319,
     KW_DO = 320,
     KW_CLEAR = 321,
     KW_PROTECT = 322,
     KW_EXTEND = 323,
     KW_INCLUDE = 324,
     KW_EXCLUDE = 325,
     KW_CONCEAL = 326,
     KW_REVEAL = 327,
     KW_COMPILE = 328,
     KW_COUNT = 329,
     KW_DEBUG = 330,
     KW_RESUME = 331,
     KW_ABORT = 332,
     KW_STEP = 333,
     KW_WHERE = 334,
     KW_CREDUCE = 335,
     KW_DUMP = 336,
     KW_PROFILE = 337,
     KW_NUMBER = 338,
     KW_RAT = 339,
     KW_COLOR = 340,
     SIMPLE_NUMBER = 341,
     KW_PWD = 342,
     KW_CD = 343,
     KW_PUSHD = 344,
     KW_POPD = 345,
     KW_LS = 346,
     KW_LOAD = 347,
     KW_QUIT = 348,
     KW_EOF = 349,
     KW_ENDM = 350,
     KW_IMPORT = 351,
     KW_ENDV = 352,
     KW_SORT = 353,
     KW_SUBSORT = 354,
     KW_OP = 355,
     KW_MSGS = 356,
     KW_VAR = 357,
     KW_CLASS = 358,
     KW_SUBCLASS = 359,
     KW_MB = 360,
     KW_CMB = 361,
     KW_EQ = 362,
     KW_CEQ = 363,
     KW_RL = 364,
     KW_CRL = 365,
     KW_IS = 366,
     KW_FROM = 367,
     KW_ARROW = 368,
     KW_ARROW2 = 369,
     KW_PARTIAL = 370,
     KW_IF = 371,
     KW_LABEL = 372,
     KW_TO = 373,
     KW_COLON2 = 374,
     KW_ASSOC = 375,
     KW_COMM = 376,
     KW_ID = 377,
     KW_IDEM = 378,
     KW_ITER = 379,
     KW_LEFT = 380,
     KW_RIGHT = 381,
     KW_PREC = 382,
     KW_GATHER = 383,
     KW_METADATA = 384,
     KW_STRAT = 385,
     KW_POLY = 386,
     KW_MEMO = 387,
     KW_FROZEN = 388,
     KW_CTOR = 389,
     KW_LATEX = 390,
     KW_SPECIAL = 391,
     KW_CONFIG = 392,
     KW_OBJ = 393,
     KW_MSG = 394,
     KW_DITTO = 395,
     KW_FORMAT = 396,
     KW_ID_HOOK = 397,
     KW_OP_HOOK = 398,
     KW_TERM_HOOK = 399,
     KW_IN = 400,
     IDENTIFIER = 401,
     NUMERIC_ID = 402,
     ENDS_IN_DOT = 403,
     FORCE_LOOKAHEAD = 404
   };
#endif
/* Tokens.  */
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
#define KW_XG_NARROW 270
#define KW_MATCH 271
#define KW_XMATCH 272
#define KW_UNIFY 273
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
#define KW_BUILTIN 285
#define KW_WHOLE 286
#define KW_SELECT 287
#define KW_DESELECT 288
#define KW_CONDITION 289
#define KW_SUBSTITUTION 290
#define KW_PRINT 291
#define KW_GRAPH 292
#define KW_MIXFIX 293
#define KW_FLAT 294
#define KW_WITH 295
#define KW_PARENS 296
#define KW_ALIASES 297
#define KW_GC 298
#define KW_TIME 299
#define KW_STATS 300
#define KW_TIMING 301
#define KW_CMD 302
#define KW_BREAKDOWN 303
#define KW_BREAK 304
#define KW_PATH 305
#define KW_MODULE 306
#define KW_MODULES 307
#define KW_VIEWS 308
#define KW_ALL 309
#define KW_SORTS 310
#define KW_OPS 311
#define KW_VARS 312
#define KW_MBS 313
#define KW_EQS 314
#define KW_RLS 315
#define KW_SUMMARY 316
#define KW_KINDS 317
#define KW_ADVISE 318
#define KW_VERBOSE 319
#define KW_DO 320
#define KW_CLEAR 321
#define KW_PROTECT 322
#define KW_EXTEND 323
#define KW_INCLUDE 324
#define KW_EXCLUDE 325
#define KW_CONCEAL 326
#define KW_REVEAL 327
#define KW_COMPILE 328
#define KW_COUNT 329
#define KW_DEBUG 330
#define KW_RESUME 331
#define KW_ABORT 332
#define KW_STEP 333
#define KW_WHERE 334
#define KW_CREDUCE 335
#define KW_DUMP 336
#define KW_PROFILE 337
#define KW_NUMBER 338
#define KW_RAT 339
#define KW_COLOR 340
#define SIMPLE_NUMBER 341
#define KW_PWD 342
#define KW_CD 343
#define KW_PUSHD 344
#define KW_POPD 345
#define KW_LS 346
#define KW_LOAD 347
#define KW_QUIT 348
#define KW_EOF 349
#define KW_ENDM 350
#define KW_IMPORT 351
#define KW_ENDV 352
#define KW_SORT 353
#define KW_SUBSORT 354
#define KW_OP 355
#define KW_MSGS 356
#define KW_VAR 357
#define KW_CLASS 358
#define KW_SUBCLASS 359
#define KW_MB 360
#define KW_CMB 361
#define KW_EQ 362
#define KW_CEQ 363
#define KW_RL 364
#define KW_CRL 365
#define KW_IS 366
#define KW_FROM 367
#define KW_ARROW 368
#define KW_ARROW2 369
#define KW_PARTIAL 370
#define KW_IF 371
#define KW_LABEL 372
#define KW_TO 373
#define KW_COLON2 374
#define KW_ASSOC 375
#define KW_COMM 376
#define KW_ID 377
#define KW_IDEM 378
#define KW_ITER 379
#define KW_LEFT 380
#define KW_RIGHT 381
#define KW_PREC 382
#define KW_GATHER 383
#define KW_METADATA 384
#define KW_STRAT 385
#define KW_POLY 386
#define KW_MEMO 387
#define KW_FROZEN 388
#define KW_CTOR 389
#define KW_LATEX 390
#define KW_SPECIAL 391
#define KW_CONFIG 392
#define KW_OBJ 393
#define KW_MSG 394
#define KW_DITTO 395
#define KW_FORMAT 396
#define KW_ID_HOOK 397
#define KW_OP_HOOK 398
#define KW_TERM_HOOK 399
#define KW_IN 400
#define IDENTIFIER 401
#define NUMERIC_ID 402
#define ENDS_IN_DOT 403
#define FORCE_LOOKAHEAD 404




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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 103 "surface.yy"
typedef union YYSTYPE {
  bool yyBool;
  Int64 yyInt64;
  const char* yyString;
  Token yyToken;
  ImportModule::ImportMode yyImportMode;
  Interpreter::Flags yyFlags;
  Interpreter::PrintFlags yyPrintFlags;
  Interpreter::SearchKind yySearchKind;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 468 "surface.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 114 "surface.yy"

int yylex(YYSTYPE* lvalp);


/* Line 219 of yacc.c.  */
#line 483 "surface.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  109
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2575

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  164
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  238
/* YYNRULES -- Number of rules. */
#define YYNRULES  600
/* YYNRULES -- Number of states. */
#define YYNSTATES  896

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   404

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     119,   120,   131,   130,   125,     2,   121,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   117,     2,
     122,   118,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   123,     2,   124,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   132,   126,   133,     2,     2,     2,     2,
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
     115,   116,   127,   128,   129,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
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
     280,   284,   286,   289,   291,   293,   295,   298,   299,   302,
     303,   308,   309,   314,   315,   316,   322,   327,   332,   333,
     334,   340,   341,   342,   343,   351,   352,   353,   359,   360,
     361,   362,   370,   371,   372,   378,   379,   380,   381,   389,
     390,   391,   397,   402,   403,   409,   410,   415,   418,   420,
     423,   425,   429,   433,   436,   438,   441,   443,   445,   447,
     451,   453,   455,   457,   459,   461,   464,   468,   470,   472,
     474,   477,   478,   480,   481,   486,   490,   492,   496,   497,
     500,   502,   504,   507,   510,   512,   514,   515,   519,   521,
     523,   526,   527,   533,   534,   540,   541,   547,   548,   554,
     556,   558,   560,   561,   567,   569,   571,   573,   576,   577,
     583,   588,   590,   592,   593,   596,   598,   601,   603,   606,
     610,   614,   618,   620,   621,   623,   624,   627,   628,   631,
     634,   635,   640,   642,   644,   645,   651,   652,   657,   659,
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
     861,   863,   864,   868,   869,   873,   874,   878,   879,   883,
     884,   889,   890,   895,   896,   901,   902,   907,   908,   913,
     914,   918,   919,   923,   924,   928,   933,   934,   938,   940,
     941,   946,   947,   952,   953,   958,   959,   964,   969,   970,
     975,   976,   981,   982,   987,   988,   993,   997,  1001,  1002,
    1007,  1008,  1013,  1014,  1019,  1020,  1025,  1026,  1031,  1032,
    1037,  1038,  1043,  1044,  1049,  1054,  1060,  1065,  1066,  1071,
    1077,  1083,  1090,  1096,  1102,  1109,  1115,  1121,  1127,  1133,
    1138,  1139,  1140,  1148,  1149,  1150,  1159,  1164,  1170,  1176,
    1182,  1187,  1193,  1196,  1199,  1202,  1205,  1211,  1216,  1217,
    1221,  1223,  1225,  1228,  1231,  1233,  1235,  1237,  1239,  1241,
    1243,  1244,  1246,  1248,  1250,  1252,  1254,  1256,  1258,  1260,
    1262,  1264,  1266,  1268,  1270,  1272,  1274,  1276,  1278,  1280,
    1282,  1284,  1286,  1288,  1290,  1292,  1294,  1295,  1297,  1298,
    1300,  1302,  1304,  1306,  1307,  1311,  1312,  1316,  1318,  1319,
    1323,  1325,  1326,  1330,  1331,  1335,  1336,  1340,  1342,  1343,
    1347,  1348,  1352,  1354,  1355,  1359,  1361,  1362,  1366,  1367,
    1371,  1372,  1376,  1377,  1381,  1383,  1384,  1388,  1389,  1393,
    1394,  1398,  1400,  1401,  1405,  1406,  1410,  1412,  1413,  1417,
    1418,  1422,  1424,  1425,  1429,  1430,  1434,  1436,  1437,  1441,
    1442,  1446,  1448,  1449,  1453,  1455,  1456,  1460,  1461,  1465,
    1467,  1469,  1471,  1473,  1475,  1477,  1479,  1481,  1483,  1485,
    1487,  1489,  1491,  1493,  1495,  1497,  1499,  1501,  1503,  1505,
    1507,  1509,  1511,  1513,  1515,  1517,  1519,  1521,  1523,  1525,
    1527,  1529,  1531,  1533,  1535,  1537,  1540,  1542,  1544,  1546,
    1548,  1551,  1553,  1555,  1557,  1559,  1561,  1563,  1565,  1567,
    1569
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     165,     0,    -1,   166,    -1,    -1,   214,    -1,   199,    -1,
     167,    -1,   301,    -1,    -1,   159,   168,     3,    -1,    -1,
      92,   169,     3,    -1,    87,    -1,    -1,    88,   170,     3,
      -1,    -1,    89,   171,     3,    -1,    90,    -1,    -1,    91,
     172,     4,    -1,    93,    -1,    94,    -1,   290,   280,    -1,
     293,   121,    -1,   180,   280,    -1,   177,   280,    -1,   178,
     280,    -1,   174,   130,   173,    -1,   162,    -1,   175,    -1,
     174,   130,   174,    -1,   176,    -1,   177,    -1,   180,    -1,
     178,    -1,   289,    -1,   175,   131,   182,    -1,    -1,   176,
     132,   179,   181,   133,    -1,   119,   174,   120,    -1,   181,
     125,   289,    -1,   289,    -1,    -1,    -1,   119,   183,   185,
     184,   120,    -1,   186,    -1,     1,    -1,   186,   125,   187,
      -1,   187,    -1,    98,   284,   128,   284,    -1,   127,   289,
     128,   289,    -1,    -1,    -1,   100,   188,   190,   128,   189,
     192,    -1,    -1,   117,   191,   260,   259,   261,    -1,    -1,
      -1,   123,   193,   194,   124,    -1,    -1,   194,   195,    -1,
     195,    -1,   141,   160,    -1,    -1,   142,   119,   196,   276,
     120,    -1,    -1,   155,   119,   197,   276,   120,    -1,    -1,
     149,   119,   198,     5,   120,    -1,    -1,    -1,    -1,     8,
     200,   289,   112,   174,   201,   128,   174,   202,   279,   203,
      97,    -1,   203,   204,    -1,    -1,    98,   284,   128,   206,
      -1,   102,   252,   117,   222,    -1,    -1,   100,   205,   207,
      -1,     1,   121,    -1,   284,   280,    -1,   162,    -1,    -1,
      -1,   117,   208,   260,   259,   261,   128,   209,   211,    -1,
      -1,   128,   210,   211,    -1,   121,    -1,   162,    -1,    -1,
     119,   213,   120,    -1,    -1,    -1,   223,   215,   289,   216,
     218,   279,   224,    95,    -1,   121,    -1,   162,    -1,   132,
     219,   133,    -1,    -1,   219,   125,   220,    -1,   220,    -1,
     289,   129,   174,    -1,   162,    -1,   261,   280,    -1,   221,
      -1,     6,    -1,     7,    -1,   224,   225,    -1,    -1,    96,
     173,    -1,    -1,    98,   226,   281,   217,    -1,    -1,    99,
     227,   282,   217,    -1,    -1,    -1,   100,   228,   117,   229,
     255,    -1,    56,   253,   117,   255,    -1,   102,   252,   117,
     222,    -1,    -1,    -1,   105,   230,   117,   231,   211,    -1,
      -1,    -1,    -1,   106,   232,   117,   233,   116,   234,   211,
      -1,    -1,    -1,   107,   235,   118,   236,   211,    -1,    -1,
      -1,    -1,   108,   237,   118,   238,   116,   239,   211,    -1,
      -1,    -1,   109,   240,   114,   241,   211,    -1,    -1,    -1,
      -1,   110,   242,   114,   243,   116,   244,   211,    -1,    -1,
      -1,   153,   245,   117,   246,   255,    -1,   101,   253,   117,
     255,    -1,    -1,   103,   289,   247,   249,   121,    -1,    -1,
     104,   248,   282,   217,    -1,     1,   121,    -1,   126,    -1,
     126,   250,    -1,   251,    -1,   250,   125,   251,    -1,   290,
     117,   289,    -1,   252,   291,    -1,   291,    -1,   253,   254,
      -1,   254,    -1,   291,    -1,   212,    -1,   261,   260,   256,
      -1,   257,    -1,   221,    -1,   257,    -1,   121,    -1,   221,
      -1,   259,   258,    -1,   261,   264,   280,    -1,   221,    -1,
     113,    -1,   115,    -1,   260,   261,    -1,    -1,   284,    -1,
      -1,   123,   262,   263,   124,    -1,   263,   125,   284,    -1,
     284,    -1,   123,   265,   124,    -1,    -1,   265,   267,    -1,
     267,    -1,   136,    -1,   139,   136,    -1,   140,   136,    -1,
     134,    -1,   135,    -1,    -1,   266,   268,   275,    -1,   137,
      -1,   138,    -1,   141,   160,    -1,    -1,   142,   119,   269,
     276,   120,    -1,    -1,   155,   119,   270,   276,   120,    -1,
      -1,   144,   119,   271,   276,   120,    -1,    -1,   145,   119,
     272,   276,   120,    -1,   146,    -1,   148,    -1,   147,    -1,
      -1,   147,   119,   273,   276,   120,    -1,   151,    -1,   152,
      -1,   153,    -1,   143,   160,    -1,    -1,   149,   119,   274,
       5,   120,    -1,   150,   119,   277,   120,    -1,   154,    -1,
     163,    -1,    -1,   276,   160,    -1,   160,    -1,   277,   278,
      -1,   278,    -1,   156,   289,    -1,   156,   289,   212,    -1,
     157,   289,   212,    -1,   158,   289,   212,    -1,   111,    -1,
      -1,   121,    -1,    -1,   281,   284,    -1,    -1,   282,   284,
      -1,   282,   122,    -1,    -1,   284,   283,   281,   122,    -1,
     285,    -1,   292,    -1,    -1,   285,   132,   286,   287,   133,
      -1,    -1,   287,   125,   288,   285,    -1,   285,    -1,   295,
      -1,   296,    -1,   298,    -1,   299,    -1,   121,    -1,   294,
      -1,   125,    -1,   128,    -1,   296,    -1,   298,    -1,   299,
      -1,   295,    -1,   296,    -1,   299,    -1,   121,    -1,   122,
      -1,   113,    -1,   115,    -1,   118,    -1,   114,    -1,   116,
      -1,   160,    -1,   296,    -1,   300,    -1,   118,    -1,   126,
      -1,   130,    -1,   131,    -1,   114,    -1,   116,    -1,   111,
      -1,   127,    -1,   128,    -1,   121,    -1,   162,    -1,   160,
      -1,   132,    -1,   133,    -1,   130,    -1,   131,    -1,   126,
      -1,   129,    -1,   127,    -1,   112,    -1,   111,    -1,   294,
      -1,   162,    -1,   125,    -1,   128,    -1,   153,    -1,   297,
      -1,    96,    -1,    98,    -1,    99,    -1,   100,    -1,    56,
      -1,   102,    -1,   101,    -1,   103,    -1,   104,    -1,   105,
      -1,   106,    -1,   107,    -1,   108,    -1,   109,    -1,   110,
      -1,    95,    -1,    97,    -1,   122,    -1,   117,    -1,   113,
      -1,   115,    -1,   118,    -1,   114,    -1,   116,    -1,   123,
      -1,   124,    -1,   300,    -1,   134,    -1,   135,    -1,   136,
      -1,   137,    -1,   138,    -1,   139,    -1,   140,    -1,   141,
      -1,   142,    -1,   144,    -1,   145,    -1,   146,    -1,   148,
      -1,   149,    -1,   150,    -1,   147,    -1,   143,    -1,   151,
      -1,   152,    -1,   154,    -1,   155,    -1,   156,    -1,   157,
      -1,   158,    -1,    -1,    32,   302,   211,    -1,    -1,    81,
     303,   211,    -1,    -1,     9,   304,   349,    -1,    -1,    80,
     305,   349,    -1,    -1,   346,    11,   306,   349,    -1,    -1,
     346,    12,   307,   353,    -1,    -1,   346,    19,   308,   362,
      -1,    -1,   346,    20,   309,   362,    -1,    -1,   346,    21,
     310,   353,    -1,    -1,   343,   311,   362,    -1,    -1,   344,
     312,   353,    -1,    -1,   345,   313,   353,    -1,   346,    22,
     347,   121,    -1,    -1,    13,   314,   349,    -1,   212,    -1,
      -1,    28,   340,   315,   396,    -1,    -1,    28,   341,   316,
     396,    -1,    -1,    49,   340,   317,   396,    -1,    -1,    36,
     342,   318,   396,    -1,    65,    66,   146,   121,    -1,    -1,
      25,     6,   319,   211,    -1,    -1,    25,    51,   320,   211,
      -1,    -1,    25,    54,   321,   211,    -1,    -1,    25,     8,
     322,   211,    -1,    25,    52,   121,    -1,    25,    53,   121,
      -1,    -1,    25,    55,   323,   211,    -1,    -1,    25,    56,
     324,   211,    -1,    -1,    25,    57,   325,   211,    -1,    -1,
      25,    58,   326,   211,    -1,    -1,    25,    59,   327,   211,
      -1,    -1,    25,    60,   328,   211,    -1,    -1,    25,    61,
     329,   211,    -1,    -1,    25,    62,   330,   211,    -1,    25,
      50,    86,   121,    -1,    25,    50,   127,    86,   121,    -1,
      25,    23,    37,   121,    -1,    -1,    25,    82,   331,   211,
      -1,    24,    25,    63,   339,   121,    -1,    24,    25,    45,
     339,   121,    -1,    24,    25,    13,    45,   339,   121,    -1,
      24,    25,    46,   339,   121,    -1,    24,    25,    48,   339,
     121,    -1,    24,    25,    13,    46,   339,   121,    -1,    24,
      25,    47,   339,   121,    -1,    24,    25,    43,   339,   121,
      -1,    24,    36,   337,   339,   121,    -1,    24,    28,   338,
     339,   121,    -1,    24,    49,   339,   121,    -1,    -1,    -1,
      24,   348,   332,   401,   333,   339,   121,    -1,    -1,    -1,
      24,     7,    69,   334,   401,   335,   339,   121,    -1,    24,
      64,   339,   121,    -1,    24,    66,   146,   339,   121,    -1,
      24,    66,    60,   339,   121,    -1,    24,    73,    74,   339,
     121,    -1,    24,    82,   339,   121,    -1,    24,    66,    82,
     339,   121,    -1,    76,   121,    -1,    77,   121,    -1,    78,
     121,    -1,    79,   121,    -1,    24,    43,    25,   339,   121,
      -1,    24,    45,   339,   121,    -1,    -1,     1,   336,   121,
      -1,    38,    -1,    39,    -1,    40,    42,    -1,    40,    41,
      -1,    37,    -1,    71,    -1,    83,    -1,    84,    -1,    85,
      -1,   155,    -1,    -1,    34,    -1,    31,    -1,    35,    -1,
      32,    -1,    58,    -1,    59,    -1,    60,    -1,    12,    -1,
      29,    -1,    30,    -1,    26,    -1,    27,    -1,    32,    -1,
      33,    -1,    70,    -1,    69,    -1,    71,    -1,    72,    -1,
      14,    -1,    15,    -1,    23,    -1,    17,    -1,    16,    -1,
      18,    -1,    75,    -1,    -1,    86,    -1,    -1,    67,    -1,
      68,    -1,    69,    -1,   387,    -1,    -1,   390,   350,   211,
      -1,    -1,   117,   352,   211,    -1,   211,    -1,    -1,   123,
     354,   356,    -1,   387,    -1,    -1,   391,   355,   211,    -1,
      -1,   161,   357,   359,    -1,    -1,   392,   358,   211,    -1,
     385,    -1,    -1,   124,   360,   349,    -1,    -1,   393,   361,
     211,    -1,   385,    -1,    -1,   123,   363,   365,    -1,   387,
      -1,    -1,   391,   364,   211,    -1,    -1,   161,   366,   369,
      -1,    -1,   125,   367,   379,    -1,    -1,   394,   368,   211,
      -1,   385,    -1,    -1,   124,   370,   349,    -1,    -1,   125,
     371,   373,    -1,    -1,   395,   372,   211,    -1,   385,    -1,
      -1,   161,   374,   376,    -1,    -1,   392,   375,   211,    -1,
     385,    -1,    -1,   124,   377,   349,    -1,    -1,   393,   378,
     211,    -1,   385,    -1,    -1,   161,   380,   382,    -1,    -1,
     392,   381,   211,    -1,   385,    -1,    -1,   124,   383,   349,
      -1,    -1,   393,   384,   211,    -1,   385,    -1,    -1,   119,
     386,   211,    -1,   211,    -1,    -1,   119,   388,   211,    -1,
      -1,   159,   389,   351,    -1,   162,    -1,   160,    -1,   161,
      -1,   123,    -1,   124,    -1,   117,    -1,   121,    -1,   125,
      -1,   160,    -1,   161,    -1,   124,    -1,   117,    -1,   121,
      -1,   125,    -1,   160,    -1,   123,    -1,   124,    -1,   159,
      -1,   117,    -1,   125,    -1,   160,    -1,   161,    -1,   123,
      -1,   159,    -1,   117,    -1,   125,    -1,   160,    -1,   123,
      -1,   124,    -1,   159,    -1,   117,    -1,   160,    -1,   161,
      -1,   123,    -1,   159,    -1,   117,    -1,   399,   397,    -1,
     398,    -1,   121,    -1,   398,    -1,   162,    -1,   399,   400,
      -1,   400,    -1,   401,    -1,   212,    -1,   160,    -1,   161,
      -1,   123,    -1,   124,    -1,   159,    -1,   117,    -1,   125,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
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
     639,   647,   656,   657,   660,   660,   663,   664,   667,   674,
     674,   677,   677,   680,   681,   680,   684,   686,   688,   689,
     688,   692,   693,   694,   692,   697,   698,   697,   701,   702,
     703,   701,   706,   707,   706,   710,   711,   712,   710,   715,
     716,   715,   719,   725,   724,   731,   731,   734,   745,   746,
     749,   750,   753,   758,   759,   762,   763,   766,   767,   770,
     771,   772,   779,   780,   785,   792,   799,   800,   803,   804,
     807,   808,   811,   816,   816,   823,   824,   827,   828,   831,
     832,   835,   839,   843,   849,   853,   857,   857,   859,   863,
     867,   868,   868,   870,   870,   872,   872,   874,   874,   876,
     880,   884,   889,   889,   891,   895,   899,   903,   907,   907,
     909,   910,   920,   921,   924,   925,   928,   929,   932,   933,
     934,   935,   941,   943,   949,   951,   959,   960,   963,   964,
     965,   965,   972,   984,   985,   985,   989,   989,   991,   997,
     997,   997,   997,   997,  1000,  1000,  1000,  1001,  1001,  1001,
    1004,  1004,  1004,  1004,  1005,  1005,  1005,  1005,  1005,  1005,
    1008,  1008,  1008,  1009,  1009,  1009,  1009,  1010,  1010,  1010,
    1010,  1010,  1013,  1013,  1019,  1019,  1019,  1019,  1019,  1019,
    1019,  1019,  1020,  1020,  1023,  1023,  1023,  1023,  1026,  1026,
    1029,  1029,  1029,  1029,  1029,  1029,  1030,  1030,  1030,  1031,
    1031,  1031,  1031,  1031,  1031,  1031,  1031,  1034,  1034,  1034,
    1034,  1034,  1034,  1034,  1037,  1037,  1037,  1040,  1040,  1040,
    1040,  1040,  1040,  1040,  1041,  1041,  1041,  1041,  1041,  1041,
    1042,  1042,  1042,  1042,  1043,  1043,  1043,  1043,  1044,  1044,
    1044,  1071,  1071,  1076,  1076,  1083,  1082,  1095,  1094,  1107,
    1106,  1119,  1118,  1131,  1130,  1144,  1143,  1157,  1156,  1169,
    1168,  1182,  1181,  1194,  1193,  1205,  1210,  1209,  1220,  1226,
    1226,  1232,  1232,  1238,  1238,  1244,  1244,  1250,  1258,  1258,
    1264,  1264,  1270,  1270,  1276,  1276,  1282,  1286,  1290,  1290,
    1296,  1296,  1302,  1302,  1308,  1308,  1314,  1314,  1320,  1320,
    1326,  1326,  1332,  1332,  1338,  1342,  1346,  1350,  1350,  1359,
    1363,  1367,  1371,  1375,  1379,  1383,  1387,  1391,  1395,  1399,
    1403,  1404,  1403,  1409,  1410,  1409,  1415,  1419,  1423,  1427,
    1431,  1435,  1442,  1446,  1450,  1454,  1461,  1465,  1472,  1472,
    1479,  1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,
    1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,
    1501,  1504,  1505,  1508,  1509,  1512,  1513,  1516,  1517,  1522,
    1523,  1524,  1527,  1528,  1532,  1535,  1536,  1539,  1540,  1543,
    1544,  1545,  1554,  1555,  1555,  1559,  1559,  1561,  1571,  1571,
    1573,  1574,  1574,  1579,  1579,  1581,  1581,  1583,  1587,  1587,
    1589,  1589,  1591,  1604,  1604,  1606,  1607,  1607,  1616,  1616,
    1618,  1618,  1620,  1620,  1622,  1630,  1630,  1632,  1632,  1634,
    1634,  1636,  1644,  1644,  1646,  1646,  1648,  1657,  1656,  1663,
    1663,  1665,  1673,  1673,  1675,  1675,  1677,  1685,  1685,  1687,
    1687,  1689,  1692,  1692,  1694,  1698,  1698,  1700,  1700,  1702,
    1713,  1713,  1713,  1713,  1713,  1713,  1713,  1716,  1716,  1716,
    1716,  1716,  1716,  1720,  1720,  1720,  1720,  1720,  1720,  1724,
    1724,  1724,  1724,  1724,  1724,  1728,  1728,  1728,  1728,  1728,
    1732,  1732,  1732,  1732,  1732,  1738,  1739,  1742,  1743,  1746,
    1753,  1754,  1757,  1762,  1769,  1769,  1769,  1769,  1769,  1769,
    1769
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
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
  "KW_WITH", "KW_PARENS", "KW_ALIASES", "KW_GC", "KW_TIME", "KW_STATS",
  "KW_TIMING", "KW_CMD", "KW_BREAKDOWN", "KW_BREAK", "KW_PATH",
  "KW_MODULE", "KW_MODULES", "KW_VIEWS", "KW_ALL", "KW_SORTS", "KW_OPS",
  "KW_VARS", "KW_MBS", "KW_EQS", "KW_RLS", "KW_SUMMARY", "KW_KINDS",
  "KW_ADVISE", "KW_VERBOSE", "KW_DO", "KW_CLEAR", "KW_PROTECT",
  "KW_EXTEND", "KW_INCLUDE", "KW_EXCLUDE", "KW_CONCEAL", "KW_REVEAL",
  "KW_COMPILE", "KW_COUNT", "KW_DEBUG", "KW_RESUME", "KW_ABORT", "KW_STEP",
  "KW_WHERE", "KW_CREDUCE", "KW_DUMP", "KW_PROFILE", "KW_NUMBER", "KW_RAT",
  "KW_COLOR", "SIMPLE_NUMBER", "KW_PWD", "KW_CD", "KW_PUSHD", "KW_POPD",
  "KW_LS", "KW_LOAD", "KW_QUIT", "KW_EOF", "KW_ENDM", "KW_IMPORT",
  "KW_ENDV", "KW_SORT", "KW_SUBSORT", "KW_OP", "KW_MSGS", "KW_VAR",
  "KW_CLASS", "KW_SUBCLASS", "KW_MB", "KW_CMB", "KW_EQ", "KW_CEQ", "KW_RL",
  "KW_CRL", "KW_IS", "KW_FROM", "KW_ARROW", "KW_ARROW2", "KW_PARTIAL",
  "KW_IF", "':'", "'='", "'('", "')'", "'.'", "'<'", "'['", "']'", "','",
  "'|'", "KW_LABEL", "KW_TO", "KW_COLON2", "'+'", "'*'", "'{'", "'}'",
  "KW_ASSOC", "KW_COMM", "KW_ID", "KW_IDEM", "KW_ITER", "KW_LEFT",
  "KW_RIGHT", "KW_PREC", "KW_GATHER", "KW_METADATA", "KW_STRAT", "KW_POLY",
  "KW_MEMO", "KW_FROZEN", "KW_CTOR", "KW_LATEX", "KW_SPECIAL", "KW_CONFIG",
  "KW_OBJ", "KW_MSG", "KW_DITTO", "KW_FORMAT", "KW_ID_HOOK", "KW_OP_HOOK",
  "KW_TERM_HOOK", "KW_IN", "IDENTIFIER", "NUMERIC_ID", "ENDS_IN_DOT",
  "FORCE_LOOKAHEAD", "$accept", "top", "item", "directive", "@1", "@2",
  "@3", "@4", "@5", "moduleExprDot", "moduleExpr", "moduleExpr2",
  "moduleExpr3", "renameExpr", "instantExpr", "@6", "parenExpr", "argList",
  "renaming", "@7", "@8", "renaming2", "mappingList", "mapping", "@9",
  "@10", "fromSpec", "@11", "toAttributes", "@12", "toAttributeList",
  "toAttribute", "@13", "@14", "@15", "view", "@16", "@17", "@18",
  "viewDecList", "viewDeclaration", "@19", "sortDot", "viewEndOpMap",
  "@20", "@21", "@22", "endBubble", "parenBubble", "@23", "module", "@24",
  "@25", "dot", "parameters", "parameterList", "parameter", "badType",
  "typeDot", "startModule", "decList", "declaration", "@26", "@27", "@28",
  "@29", "@30", "@31", "@32", "@33", "@34", "@35", "@36", "@37", "@38",
  "@39", "@40", "@41", "@42", "@43", "@44", "@45", "@46", "@47", "@48",
  "classDef", "cPairList", "cPair", "varNameList", "opNameList",
  "simpleOpName", "domainRangeAttr", "dra2", "rangeAttr", "typeAttr",
  "arrow", "typeList", "typeName", "@49", "sortNames", "attributes",
  "attributeList", "idKeyword", "attribute", "@50", "@51", "@52", "@53",
  "@54", "@55", "@56", "identity", "idList", "hookList", "hook",
  "expectedIs", "expectedDot", "sortNameList", "subsortList", "@57",
  "sortName", "sortNameFrag", "@58", "sortNameFrags", "@59", "token",
  "tokenBarDot", "tokenBarColon", "sortToken", "endsInDot", "inert",
  "identifier", "startKeyword", "startKeyword2", "midKeyword",
  "attrKeyword", "attrKeyword2", "command", "@60", "@61", "@62", "@63",
  "@64", "@65", "@66", "@67", "@68", "@69", "@70", "@71", "@72", "@73",
  "@74", "@75", "@76", "@77", "@78", "@79", "@80", "@81", "@82", "@83",
  "@84", "@85", "@86", "@87", "@88", "@89", "@90", "@91", "@92", "@93",
  "@94", "printOption", "traceOption", "polarity", "select", "exclude",
  "conceal", "search", "match", "unify", "optDebug", "optNumber",
  "importMode", "moduleAndTerm", "@95", "inEnd", "@96", "numberModuleTerm",
  "@97", "@98", "numberModuleTerm1", "@99", "@100", "numberModuleTerm2",
  "@101", "@102", "numbersModuleTerm", "@103", "@104",
  "numbersModuleTerm1", "@105", "@106", "@107", "numbersModuleTerm2",
  "@108", "@109", "@110", "numbersModuleTerm3", "@111", "@112",
  "numbersModuleTerm4", "@113", "@114", "numbersModuleTerm5", "@115",
  "@116", "numbersModuleTerm6", "@117", "@118", "miscEndBubble", "@119",
  "initialEndBubble", "@120", "@121", "cTokenBarIn", "cTokenBarLeftIn",
  "cTokenBarDotNumber", "cTokenBarDotRight", "cTokenBarDotCommaNumber",
  "cTokenBarDotCommaRight", "opSelect", "endSelect", "badSelect",
  "cOpNameList", "cSimpleOpName", "cSimpleTokenBarDot", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
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
     365,   366,   367,   368,   369,   370,   371,    58,    61,    40,
      41,    46,    60,    91,    93,    44,   124,   372,   373,   374,
      43,    42,   123,   125,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   164,   165,   165,   166,   166,   166,   166,   168,   167,
     169,   167,   167,   170,   167,   171,   167,   167,   172,   167,
     167,   167,   173,   173,   173,   173,   173,   173,   173,   174,
     174,   175,   175,   176,   176,   176,   177,   179,   178,   180,
     181,   181,   183,   184,   182,   185,   185,   186,   186,   187,
     187,   188,   189,   187,   191,   190,   190,   193,   192,   192,
     194,   194,   195,   196,   195,   197,   195,   198,   195,   200,
     201,   202,   199,   203,   203,   204,   204,   205,   204,   204,
     206,   206,   208,   209,   207,   210,   207,   211,   211,   213,
     212,   215,   216,   214,   217,   217,   218,   218,   219,   219,
     220,   221,   222,   222,   223,   223,   224,   224,   225,   226,
     225,   227,   225,   228,   229,   225,   225,   225,   230,   231,
     225,   232,   233,   234,   225,   235,   236,   225,   237,   238,
     239,   225,   240,   241,   225,   242,   243,   244,   225,   245,
     246,   225,   225,   247,   225,   248,   225,   225,   249,   249,
     250,   250,   251,   252,   252,   253,   253,   254,   254,   255,
     255,   255,   256,   256,   256,   257,   258,   258,   259,   259,
     260,   260,   261,   262,   261,   263,   263,   264,   264,   265,
     265,   266,   266,   266,   267,   267,   268,   267,   267,   267,
     267,   269,   267,   270,   267,   271,   267,   272,   267,   267,
     267,   267,   273,   267,   267,   267,   267,   267,   274,   267,
     267,   267,   275,   275,   276,   276,   277,   277,   278,   278,
     278,   278,   279,   279,   280,   280,   281,   281,   282,   282,
     283,   282,   284,   285,   286,   285,   288,   287,   287,   289,
     289,   289,   289,   289,   290,   290,   290,   290,   290,   290,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   293,   293,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   295,   295,   295,   295,   296,   296,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   298,   298,   298,
     298,   298,   298,   298,   299,   299,   299,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   302,   301,   303,   301,   304,   301,   305,   301,   306,
     301,   307,   301,   308,   301,   309,   301,   310,   301,   311,
     301,   312,   301,   313,   301,   301,   314,   301,   301,   315,
     301,   316,   301,   317,   301,   318,   301,   301,   319,   301,
     320,   301,   321,   301,   322,   301,   301,   301,   323,   301,
     324,   301,   325,   301,   326,   301,   327,   301,   328,   301,
     329,   301,   330,   301,   301,   301,   301,   331,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     332,   333,   301,   334,   335,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   336,   301,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   339,   339,   340,   340,   341,   341,   342,   342,   343,
     343,   343,   344,   344,   345,   346,   346,   347,   347,   348,
     348,   348,   349,   350,   349,   352,   351,   351,   354,   353,
     353,   355,   353,   357,   356,   358,   356,   356,   360,   359,
     361,   359,   359,   363,   362,   362,   364,   362,   366,   365,
     367,   365,   368,   365,   365,   370,   369,   371,   369,   372,
     369,   369,   374,   373,   375,   373,   373,   377,   376,   378,
     376,   376,   380,   379,   381,   379,   379,   383,   382,   384,
     382,   382,   386,   385,   385,   388,   387,   389,   387,   387,
     390,   390,   390,   390,   390,   390,   390,   391,   391,   391,
     391,   391,   391,   392,   392,   392,   392,   392,   392,   393,
     393,   393,   393,   393,   393,   394,   394,   394,   394,   394,
     395,   395,   395,   395,   395,   396,   396,   397,   397,   398,
     399,   399,   400,   400,   401,   401,   401,   401,   401,   401,
     401
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
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
       3,     1,     2,     1,     1,     1,     2,     0,     2,     0,
       4,     0,     4,     0,     0,     5,     4,     4,     0,     0,
       5,     0,     0,     0,     7,     0,     0,     5,     0,     0,
       0,     7,     0,     0,     5,     0,     0,     0,     7,     0,
       0,     5,     4,     0,     5,     0,     4,     2,     1,     2,
       1,     3,     3,     2,     1,     2,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     3,     1,     1,     1,
       2,     0,     1,     0,     4,     3,     1,     3,     0,     2,
       1,     1,     2,     2,     1,     1,     0,     3,     1,     1,
       2,     0,     5,     0,     5,     0,     5,     0,     5,     1,
       1,     1,     0,     5,     1,     1,     1,     2,     0,     5,
       4,     1,     1,     0,     2,     1,     2,     1,     2,     3,
       3,     3,     1,     0,     1,     0,     2,     0,     2,     2,
       0,     4,     1,     1,     0,     5,     0,     4,     1,     1,
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
       1,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       3,     0,     3,     0,     3,     4,     0,     3,     1,     0,
       4,     0,     4,     0,     4,     0,     4,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     3,     3,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     4,     5,     4,     0,     4,     5,
       5,     6,     5,     5,     6,     5,     5,     5,     5,     4,
       0,     0,     7,     0,     0,     8,     4,     5,     5,     5,
       4,     5,     2,     2,     2,     2,     5,     4,     0,     3,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     1,
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       0,   438,   104,   105,    69,   345,   366,   469,   470,   473,
     472,   474,   471,     0,     0,     0,   341,     0,     0,     0,
     475,     0,     0,     0,     0,   347,   343,    12,    13,    15,
      17,    18,    10,    20,    21,    89,     8,     0,     2,     6,
       5,   368,     4,    91,     7,   359,   361,   363,     0,     0,
       0,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,   479,   480,   481,     0,     0,   420,   378,   384,
       0,     0,   380,     0,     0,   382,   388,   390,   392,   394,
     396,   398,   400,   402,   407,   463,   464,   466,   465,   369,
     371,     0,   467,   468,   375,   373,     0,   432,   433,   434,
     435,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,   349,   351,   353,   355,   357,   478,
     439,   294,   305,   290,   306,   291,   292,   293,   296,   295,
     297,   298,   299,   300,   301,   302,   303,   304,   283,   282,
     309,   312,   310,   313,   308,   311,   243,   307,   314,   315,
     286,   279,   281,   287,   280,   277,   278,   275,   276,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   333,   326,
     327,   328,   332,   329,   330,   331,   334,   335,   288,   336,
     337,   338,   339,   340,   274,   285,     0,   284,   239,   240,
     289,   241,   242,   316,   554,   545,   555,   552,   553,   556,
     547,   550,   551,   549,   346,   482,   483,   367,   423,     0,
       0,     0,     0,     0,     0,     0,   458,   459,   460,   452,
     454,   451,   453,   455,   456,   457,     0,   444,   440,   441,
       0,   445,   446,   447,   448,   449,     0,     0,   461,   462,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   386,   387,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,   342,     0,     0,     0,   348,   344,    14,    16,    19,
      11,    90,     9,    92,   560,   561,   503,   559,   562,   557,
     558,   360,   505,   506,   488,   362,   490,   491,   364,     0,
       0,     0,     0,     0,   477,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     443,   442,     0,     0,   437,   419,   426,     0,     0,     0,
       0,   430,   599,   596,   597,   600,   598,   594,   595,   421,
     379,   385,   406,   404,     0,   381,   383,   389,   391,   393,
     395,   397,   399,   401,   403,   408,   589,   593,   370,   586,
       0,   591,   592,   372,   376,   374,   377,    97,     0,     0,
       0,     0,   350,   352,   354,   356,   358,   365,     0,    70,
      29,    31,    32,    34,    33,    35,   546,   485,   487,   548,
     484,   424,     0,     0,   416,   410,   412,   415,   413,   409,
     418,   417,   436,   428,   431,   427,   429,     0,   405,   587,
     585,   588,   590,     0,   223,   579,   542,   576,   577,   510,
     578,   575,   508,   544,   504,   514,   512,   507,   567,   564,
     565,   568,   566,   563,   493,   489,   497,   495,   492,     0,
       0,     0,     0,    37,     0,     0,   411,   414,     0,     0,
      99,     0,   222,   107,     0,     0,     0,     0,     0,     0,
      39,    30,     0,    42,    36,     0,   486,     0,   422,     0,
      96,     0,     0,   543,   532,   511,   536,   534,   584,   582,
     515,   517,   583,   580,   581,   509,   521,   519,   513,   573,
     571,   498,   574,   572,   569,   570,   494,   502,   500,   496,
      71,     0,     0,    41,   425,    98,   100,     0,     0,    93,
       0,   109,   111,   113,     0,     0,     0,   145,   118,   121,
     125,   128,   132,   135,   139,   106,     0,     0,     0,     0,
       0,     0,     0,   223,    46,     0,    51,     0,    43,    45,
      48,     0,    38,   147,   255,   258,   256,   259,   257,   253,
     254,   158,     0,   156,   157,   250,   251,   252,   243,   245,
     246,    28,   108,     0,   225,   225,   225,   225,     0,   244,
     247,   248,   249,   227,     0,     0,     0,     0,   154,   143,
       0,     0,     0,     0,     0,     0,     0,     0,   537,   533,
     541,   539,   535,   516,   522,   518,   526,   524,   520,   499,
     501,    74,   269,   267,   268,   263,   264,   270,   271,   265,
     266,   260,     0,   232,   233,   261,   262,    56,     0,     0,
       0,    40,     0,   155,     0,   224,    25,    26,    24,    22,
      23,     0,     0,   230,   114,     0,     0,   153,     0,     0,
     119,   122,   126,   129,   133,   136,   140,     0,     0,     0,
       0,     0,     0,   234,    54,     0,     0,    44,    47,   168,
     169,   173,   101,   161,   116,   160,     0,   171,   172,    27,
      30,    94,    95,   110,   226,   229,   112,   228,   227,     0,
     142,   103,   117,   225,   148,     0,   146,     0,     0,     0,
       0,     0,     0,     0,   538,   540,   527,   523,   531,   529,
     525,     0,    72,     0,    77,     0,    73,    49,     0,   171,
      52,    50,     0,   167,   165,   178,     0,     0,   115,   102,
     245,   246,   149,   150,     0,   244,   247,   248,   249,   144,
     120,   123,   127,   130,   134,   137,   141,     0,     0,    79,
       0,     0,     0,   238,     0,     0,    59,     0,   176,     0,
     225,   163,   164,   159,   162,   170,   231,     0,     0,     0,
       0,     0,   528,   530,     0,    82,    85,    78,     0,   236,
     235,     0,    57,    53,   174,     0,   184,   185,   181,   188,
     189,     0,     0,     0,     0,     0,     0,     0,   199,   201,
     200,     0,     0,   204,   205,   206,   211,     0,     0,   186,
     180,   166,   151,   152,   124,   131,   138,    81,    75,   225,
     171,     0,    76,     0,    55,     0,   175,   182,   183,   190,
     191,   207,   195,   197,   202,   208,     0,   193,   177,   179,
     213,    80,     0,    86,   237,     0,     0,     0,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,     0,   212,   187,     0,    62,    63,    67,    65,    58,
      60,   215,     0,     0,     0,     0,     0,   218,     0,     0,
     210,   216,     0,     0,     0,     0,     0,   192,   214,   196,
     198,   203,   209,   219,   220,   221,   194,    83,     0,     0,
       0,     0,    64,    68,    66,    84
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,    37,    38,    39,   108,   106,   103,   104,   105,   562,
     379,   380,   381,   382,   383,   465,   384,   502,   464,   501,
     619,   538,   539,   540,   617,   746,   655,   709,   773,   815,
     839,   840,   874,   876,   875,    40,    50,   441,   533,   651,
     706,   741,   808,   767,   810,   891,   811,   423,   357,   107,
      42,   110,   367,   673,   414,   449,   450,   663,   682,    43,
     472,   525,   573,   574,   575,   679,   581,   687,   582,   688,
     759,   583,   689,   584,   690,   760,   585,   691,   586,   692,
     761,   587,   693,   638,   580,   685,   722,   723,   577,   552,
     553,   664,   753,   665,   714,   666,   716,   667,   712,   747,
     750,   798,   799,   800,   830,   841,   851,   842,   843,   844,
     845,   853,   862,   849,   850,   453,   626,   631,   632,   678,
     668,   613,   708,   744,   813,   385,   567,   554,   614,   568,
     187,   188,   615,   190,   191,   192,   193,    44,    91,   102,
      51,   101,   299,   300,   301,   302,   303,   111,   112,   113,
      52,   267,   268,   273,   272,   249,   254,   257,   250,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   248,   407,
     310,   445,    49,   236,   226,   240,    89,    90,    94,    45,
      46,    47,    48,   305,    67,   204,   309,   389,   444,   295,
     370,   371,   435,   458,   459,   496,   531,   532,   291,   368,
     369,   424,   456,   455,   457,   485,   528,   529,   530,   595,
     649,   650,   697,   737,   738,   475,   526,   527,   589,   647,
     648,   425,   454,   205,   307,   308,   206,   297,   437,   498,
     426,   487,   358,   410,   359,   360,   361,   362
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -716
static const short int yypact[] =
{
     603,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,   781,   468,   114,  -716,   125,   153,    -7,
    -716,   -45,   -18,    -9,     3,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,    97,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,   543,     9,
    1187,   270,   270,    70,    27,   282,    44,   124,   199,   199,
     199,   -26,  -716,  -716,  -716,    83,   199,  -716,  -716,  -716,
     140,   -50,  -716,    59,    73,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,   -73,  -716,  -716,  -716,  -716,    84,  -716,  -716,  -716,
    -716,   270,   -73,   200,   229,   237,   251,    85,   253,  -716,
    1187,   324,   378,   378,  -716,  -716,  -716,  -716,  -716,   172,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,   155,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,   202,
     199,   199,   199,   199,   199,   199,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,   199,  -716,  -716,  -716,
     241,  -716,  -716,  -716,  -716,  -716,   199,   199,  -716,  -716,
     144,   148,   154,   199,   199,   199,   199,   159,   178,   -73,
     -73,   167,   197,   250,   -73,  -716,  -716,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   147,   147,  -716,
    -716,  -716,   147,   147,   232,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,   270,
     378,   324,   324,   378,  -716,   234,   775,   -73,   -52,   -73,
     178,   199,   199,   236,   245,   247,   255,   256,   258,   259,
    -716,  -716,   263,   265,  -716,  -716,  -716,   267,   269,   271,
     275,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,   279,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
     424,  -716,  -716,  -716,  -716,  -716,  -716,   286,   513,   -73,
     542,   -73,  -716,  -716,  -716,  -716,  -716,  -716,   775,   294,
     296,   293,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,   312,   317,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,   199,  -716,  -716,
    -716,  -716,  -716,  1187,   333,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,   -81,
     775,   318,   338,  -716,   -73,   199,  -716,  -716,   337,   -82,
    -716,   330,  -716,  -716,   -73,   697,  1662,   -73,  2386,   -73,
    -716,  -716,   775,  -716,  -716,  1187,  -716,   339,  -716,  1187,
    -716,   775,   303,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
     294,     7,   -65,  -716,  -716,  -716,   294,   341,  1290,  -716,
     878,  -716,  -716,  -716,  1290,  1599,  1187,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  2395,   -73,   270,  2404,
     -73,   270,   -73,   333,  -716,  2344,  -716,  1187,  -716,   344,
    -716,  1187,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,   981,  -716,  -716,  -716,  -716,  -716,   342,   130,
     216,    79,  -716,   334,   166,   201,   242,   345,   349,   230,
     284,   304,   320,  -716,  2344,   358,  1084,  1393,  -716,  -716,
    2344,   360,   361,   362,   363,   373,   374,   375,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,   368,   372,  -716,  -716,  -716,   383,   377,   370,
      23,  -716,  1702,  -716,   878,  -716,  -716,  -716,  -716,  -716,
    -716,  1838,  1770,  -716,  -716,  1702,  1906,  -716,   380,  1770,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,   270,   -73,  2413,
     -73,    56,  2344,  -716,  -716,   379,  1187,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  1906,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  1702,
    -716,  -716,  -716,   345,  2042,   389,  -716,   -73,   395,   -73,
     396,   -73,   397,  1702,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,   394,  -716,  2344,  -716,  1599,  -716,  -716,  2344,  -716,
    -716,  -716,  2344,  -716,  -716,   393,   629,  2211,  -716,  -716,
    -716,  -716,   392,  -716,   414,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,   270,   -73,  -716,
     404,   -75,  1496,   372,   -11,  2145,   412,   219,  -716,   907,
     345,  -716,  -716,  -716,  -716,  -716,  -716,  2042,  1187,   -73,
     -73,   -73,  -716,  -716,  1974,  -716,  -716,  -716,  1906,  -716,
    -716,  2278,  -716,  -716,  -716,  2344,  -716,  -716,  -716,  -716,
    -716,   400,   406,   384,   427,   391,   434,   437,  -716,   438,
    -716,   440,   442,  -716,  -716,  -716,  -716,   447,   812,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,   345,
    -716,   -73,  -716,  2344,  -716,   179,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,   297,  -716,  -716,  -716,
     405,  -716,  2145,  -716,   372,   407,   450,   451,   452,   150,
    -716,   413,   413,   413,   413,   567,  1187,  1187,  1187,   120,
    -716,   413,  -716,  -716,  2278,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,   -62,   -56,   -54,   -35,   454,   456,   456,   456,
    -716,  -716,   -34,   449,   413,   573,   413,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,   -24,   459,
     -12,   -73,  -716,  -716,  -716,  -716
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,   -44,
    -369,  -716,  -716,  -487,  -486,  -716,  -481,  -716,  -716,  -716,
    -716,  -716,  -716,   -38,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -252,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,   -90,     0,  -716,
    -716,  -716,  -716,  -488,  -716,  -716,   119,  -616,  -179,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -167,  -114,    78,
    -370,  -580,  -716,  -123,  -716,  -715,  -677,  -605,  -716,  -716,
    -716,  -716,  -716,  -204,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -493,  -716,  -254,    63,  -552,   -78,    22,  -716,
    -419,  -681,  -716,  -716,  -716,   -48,  -656,  -497,  -716,  -716,
    -506,  -498,   -43,  -716,  -505,  -489,  -393,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,   -22,   587,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,   -49,  -716,  -716,  -716,   -72,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,    25,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,  -716,
    -716,  -364,  -716,   -66,  -716,  -716,  -716,  -100,  -420,  -504,
    -716,  -716,    57,  -716,   246,  -716,   273,  -215
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -477
static const short int yytable[] =
{
      41,   271,   186,   207,   569,   571,   436,   189,   534,   439,
     555,   293,   276,   627,   628,   629,   555,   555,   578,   557,
     681,   572,   591,   564,   565,   557,   557,   743,   724,   566,
     771,   683,   745,   339,   243,   477,   252,   241,   242,   460,
     209,   298,   765,   469,   247,   292,   296,   296,   269,   440,
     713,   470,   275,   766,   555,   680,   244,   701,   877,    96,
     541,   715,   283,   557,   879,   387,   880,   189,   542,   269,
     210,   461,   211,   212,   213,   214,    97,   253,   555,   555,
     637,   227,   228,   229,   230,   881,   886,   557,   557,   270,
     215,   476,   486,   500,   497,   391,   892,   109,   878,   718,
     752,   724,   506,    98,   878,   535,   878,   536,   894,   597,
     270,   755,    99,   736,   769,   231,   612,   854,   569,   571,
     245,   535,   770,   536,   100,   878,   878,   232,   233,   234,
     120,   719,   834,   832,   537,   572,   878,   564,   565,   208,
     755,   563,   616,   566,   676,   699,    85,    86,   878,   237,
     537,   686,   681,   702,   703,   633,   704,   246,   705,   340,
     341,   633,   590,   683,   345,   596,   814,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   251,   725,   727,
     255,   616,   623,    87,    88,    85,    86,   616,   313,   314,
     315,   316,   317,   318,   256,   728,    92,    93,   801,   235,
    -273,   293,   293,   277,   319,   281,   623,   555,   578,  -285,
    -285,  -285,   674,   677,   322,   323,   557,   386,   388,   390,
     677,   327,   328,   329,   330,   238,   239,   755,   373,   616,
     274,   376,   278,   707,   296,   292,   292,   296,   616,   616,
     870,   279,   616,   616,   555,   637,   616,   311,   312,   873,
     372,   725,   727,   557,   280,   670,   282,   831,   304,   616,
    -286,  -286,  -286,   189,   332,   324,    35,   306,   728,   325,
     333,   334,   335,   616,   859,   326,   846,   847,   848,   427,
     331,   438,   320,   321,   740,   698,   616,   625,   342,   392,
     393,   835,   836,   748,   216,   332,   -32,   -32,   674,   837,
     616,   333,   334,   335,   507,   838,   336,   337,   338,   356,
     616,   217,   218,   219,   220,   616,   221,   222,   343,   616,
     835,   836,   625,   616,   616,   363,   374,   375,   837,   364,
     365,   -34,   -34,   -34,   838,   189,   344,   336,   337,   338,
     223,   224,   225,   774,   775,   809,  -287,  -287,  -287,   863,
     864,   865,   616,   366,   466,   377,   816,   394,   872,   508,
    -284,  -284,  -284,   625,   473,   451,   395,   488,   396,   499,
     189,   616,   -33,   -33,   -33,   616,   397,   398,   616,   399,
     400,   888,   616,   890,   401,   448,   402,   194,   403,   195,
     404,   196,   405,   197,   198,   199,   406,   189,   509,   510,
     408,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,  -240,  -240,  -240,   503,   413,   189,
     616,   451,   189,   467,   440,   443,   189,   442,   189,   200,
     201,   202,   203,   446,  -241,  -241,  -241,   592,   447,   616,
     598,   284,   600,   195,   452,   285,   462,   286,   287,   288,
    -242,  -242,  -242,   846,   847,   848,   524,   463,   468,   471,
     504,   616,   543,  -272,   624,   556,   625,   570,   579,   620,
     630,   556,   556,   189,    68,   634,    69,   640,   641,   593,
     642,   643,   599,   200,   289,   290,   203,   644,   645,   618,
     657,    70,   646,   621,   189,   284,   652,   195,   189,   285,
     654,   294,   287,   288,   653,   656,   684,   710,   551,   556,
     729,   731,   733,   735,   551,   739,   749,   757,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   758,   764,   556,   556,   772,   817,   200,   289,   290,
     203,   332,   818,    35,   819,   409,   820,   333,   334,   335,
      84,   821,   551,   822,   114,   115,   823,   824,   695,   825,
     700,   826,   116,   117,   118,   119,   827,   855,   852,   856,
     857,   858,   866,   861,   882,    35,   551,   887,   889,   893,
     669,   570,   658,   336,   337,   338,   356,   860,   505,   812,
     802,   742,   576,   754,   829,   871,   601,   730,   694,   732,
     717,   734,   639,    -3,     1,    95,   411,     0,   711,     2,
       3,     4,     5,   189,  -476,  -476,     6,     7,     8,     9,
      10,    11,  -476,  -476,  -476,  -476,    12,    13,    14,     0,
     415,    15,   416,   412,   269,    16,   417,   418,   419,    17,
       0,   726,     0,     0,     0,     0,     0,     0,   763,     0,
       0,     0,    18,     0,     0,     0,     0,     0,     0,   428,
       0,   416,   556,   269,     0,   429,   430,   431,    19,   804,
     805,   806,   420,   421,   422,   270,     0,     0,    20,    21,
      22,    23,    24,    25,    26,   121,     0,     0,   762,     0,
      27,    28,    29,    30,    31,    32,    33,    34,     0,   556,
       0,   432,   433,   434,   270,     0,     0,     0,     0,     0,
     803,     0,     0,     0,   726,   189,     0,     0,     0,     0,
       0,   833,    35,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     602,     0,   659,   603,   660,   604,     0,   605,     0,     0,
     751,     0,   661,     0,     0,   606,   607,   608,     0,   609,
     610,     0,    36,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    53,   611,
       0,   662,     0,     0,     0,     0,     0,     0,   867,   868,
     869,   895,     0,   189,   189,   189,    54,     0,     0,    55,
       0,     0,     0,     0,   428,     0,   416,    56,   269,     0,
     429,   430,   431,     0,    57,     0,    58,     0,     0,     0,
      59,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,     0,    61,    62,    63,
      64,     0,     0,     0,    65,     0,   432,   433,   474,   270,
       0,     0,     0,    66,     0,     0,     0,   883,   884,   885,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   378,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   121,   184,   828,   185,     0,     0,
       0,     0,     0,     0,     0,     0,   776,   777,   778,   779,
     780,   781,   782,   783,   784,   785,   786,   787,   788,   789,
     790,   791,   792,   793,   794,   795,   796,   797,     0,     0,
       0,     0,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   378,     0,   558,
     147,   148,   149,   559,   151,   152,   560,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   121,   184,     0,
     561,   776,   777,   778,   779,   780,   781,   782,   783,   784,
     785,   786,   787,   788,   789,   790,   791,   792,   793,   794,
     795,   796,   797,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   544,   545,   546,   547,   622,   548,
      35,     0,   549,   550,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     121,   184,     0,   185,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   544,   545,   546,
     547,   635,   548,    35,     0,   549,   550,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   121,   184,     0,   185,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   121,   184,     0,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   544,   545,   546,   547,     0,   548,    35,
       0,   549,   550,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   121,
     184,     0,   185,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   544,   545,   546,   547,
     636,   548,     0,     0,   549,   550,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   121,   184,     0,   185,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   544,
     545,   546,   547,   768,   548,     0,     0,   549,   550,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   121,   184,     0,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   544,   545,   546,   547,     0,   548,     0,     0,
     549,   550,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   121,   184,
       0,   185,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   478,
       0,   416,     0,   269,     0,   479,   480,   481,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   602,     0,   659,   603,   660,   604,     0,
     605,   482,   483,   484,   270,   661,   121,     0,   606,   607,
     608,     0,   609,   610,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,     0,   611,     0,   662,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   602,     0,     0,   603,     0,   604,     0,   605,     0,
       0,   671,   675,     0,   121,     0,   606,   607,   608,     0,
     609,   610,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,     0,
     611,     0,   672,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   602,
       0,     0,   603,     0,   604,     0,   605,     0,     0,   671,
       0,     0,   121,     0,   606,   607,   608,     0,   609,   610,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,     0,   611,     0,
     672,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   602,     0,     0,
     603,     0,   604,     0,   605,     0,     0,     0,     0,   661,
     121,     0,   606,   607,   608,     0,   609,   610,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,     0,   611,     0,   662,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   602,     0,     0,   603,     0,
     604,     0,   605,     0,     0,     0,     0,     0,   121,     0,
     606,   607,   608,     0,   609,   610,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,     0,   611,     0,   807,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,     0,   147,   148,   149,   720,   151,   152,
     721,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   121,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   602,     0,   659,   603,
     660,   604,     0,   605,     0,     0,     0,   121,   661,     0,
       0,   606,   607,   608,     0,   609,   610,     0,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,     0,   611,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   602,     0,     0,   603,     0,   604,     0,   605,
       0,     0,     0,   756,   121,     0,     0,   606,   607,   608,
       0,   609,   610,     0,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
       0,   611,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   602,
       0,     0,   603,     0,   604,     0,   605,     0,     0,     0,
     121,   661,     0,     0,   606,   607,   608,     0,   609,   610,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,     0,   611,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   602,     0,     0,   603,     0,
     604,     0,   605,     0,     0,     0,     0,     0,     0,     0,
     606,   607,   608,     0,   609,   610,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   489,   611,   416,     0,   269,     0,   490,
     491,   492,   489,     0,   416,     0,   269,     0,   490,   588,
     492,   428,     0,   416,     0,   269,     0,   429,   430,   431,
     489,     0,   416,     0,   269,     0,   490,   696,   492,     0,
       0,     0,     0,     0,     0,   493,   494,   495,   270,     0,
       0,     0,     0,     0,   493,   494,   495,   270,     0,     0,
       0,     0,     0,   432,   433,   594,   270,     0,     0,     0,
       0,     0,   493,   494,   495,   270
};

static const short int yycheck[] =
{
       0,    91,    50,    52,   510,   510,   370,    50,     1,   378,
     508,   111,   102,   565,   566,   567,   514,   515,   515,   508,
     636,   510,   526,   510,   510,   514,   515,   708,   684,   510,
     745,   636,   709,   248,    60,   455,    86,    59,    60,   120,
      13,   113,   117,   125,    66,   111,   112,   113,   121,   130,
     666,   133,   101,   128,   552,   635,    82,     1,   120,    66,
     125,   666,   110,   552,   120,   117,   120,   110,   133,   121,
      43,   440,    45,    46,    47,    48,   121,   127,   576,   577,
     577,    37,    38,    39,    40,   120,   120,   576,   577,   162,
      63,   455,   456,   462,   458,   310,   120,     0,   160,   679,
     716,   757,   471,   121,   160,    98,   160,   100,   120,   529,
     162,   716,   121,   693,   125,    71,   535,   832,   624,   624,
     146,    98,   133,   100,   121,   160,   160,    83,    84,    85,
     121,   683,   813,   810,   127,   624,   160,   624,   624,    69,
     745,   510,   535,   624,   632,   649,    32,    33,   160,    25,
     127,   639,   768,    97,    98,   574,   100,    74,   102,   249,
     250,   580,   526,   768,   254,   529,   771,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,    37,   684,   684,
     121,   574,   552,    69,    70,    32,    33,   580,   210,   211,
     212,   213,   214,   215,   121,   684,    71,    72,   750,   155,
     121,   301,   302,     3,   226,   120,   576,   705,   705,   130,
     131,   132,   631,   632,   236,   237,   705,   307,   308,   309,
     639,   243,   244,   245,   246,    26,    27,   832,   300,   622,
     146,   303,     3,   652,   300,   301,   302,   303,   631,   632,
     120,     4,   635,   636,   742,   742,   639,    45,    46,   854,
     299,   757,   757,   742,     3,   624,     3,   809,    86,   652,
     130,   131,   132,   306,   117,   121,   119,   112,   757,   121,
     123,   124,   125,   666,   124,   121,   156,   157,   158,   369,
     121,   371,    41,    42,   703,   649,   679,   121,   121,   311,
     312,   141,   142,   712,    12,   117,   130,   131,   717,   149,
     693,   123,   124,   125,     1,   155,   159,   160,   161,   162,
     703,    29,    30,    31,    32,   708,    34,    35,   121,   712,
     141,   142,   121,   716,   717,   268,   301,   302,   149,   272,
     273,   130,   131,   132,   155,   378,    86,   159,   160,   161,
      58,    59,    60,   124,   125,   764,   130,   131,   132,   842,
     843,   844,   745,   121,   444,   121,   775,   121,   851,    56,
     130,   131,   132,   121,   454,   413,   121,   457,   121,   459,
     413,   764,   130,   131,   132,   768,   121,   121,   771,   121,
     121,   874,   775,   876,   121,   407,   121,   117,   121,   119,
     121,   121,   121,   123,   124,   125,   121,   440,    95,    96,
     121,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   130,   131,   132,   465,   132,   462,
     813,   469,   465,   445,   130,   132,   469,   131,   471,   159,
     160,   161,   162,   121,   130,   131,   132,   527,   121,   832,
     530,   117,   532,   119,   111,   121,   128,   123,   124,   125,
     130,   131,   132,   156,   157,   158,   153,   119,   121,   129,
     121,   854,   121,   121,   130,   508,   121,   510,   516,   125,
     121,   514,   515,   516,     6,   117,     8,   117,   117,   528,
     118,   118,   531,   159,   160,   161,   162,   114,   114,   537,
     120,    23,   117,   541,   537,   117,   128,   119,   541,   121,
     117,   123,   124,   125,   132,   128,   126,   128,   508,   552,
     121,   116,   116,   116,   514,   121,   123,   125,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,   117,   128,   576,   577,   123,   136,   159,   160,   161,
     162,   117,   136,   119,   160,   121,   119,   123,   124,   125,
      82,   160,   552,   119,    11,    12,   119,   119,   648,   119,
     650,   119,    19,    20,    21,    22,   119,   160,   163,   119,
     119,   119,     5,   160,   120,   119,   576,   128,     5,   120,
     624,   624,   620,   159,   160,   161,   162,   839,   469,   768,
     757,   705,   514,   716,   798,   849,   533,   687,   647,   689,
     678,   691,   580,     0,     1,    18,   360,    -1,   656,     6,
       7,     8,     9,   656,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
     117,    28,   119,   360,   121,    32,   123,   124,   125,    36,
      -1,   684,    -1,    -1,    -1,    -1,    -1,    -1,   738,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   119,   705,   121,    -1,   123,   124,   125,    65,   759,
     760,   761,   159,   160,   161,   162,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    56,    -1,    -1,   737,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,   742,
      -1,   159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,
     758,    -1,    -1,    -1,   757,   758,    -1,    -1,    -1,    -1,
      -1,   811,   119,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,    -1,   113,   114,   115,   116,    -1,   118,    -1,    -1,
     121,    -1,   123,    -1,    -1,   126,   127,   128,    -1,   130,
     131,    -1,   159,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     7,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,   846,   847,
     848,   891,    -1,   846,   847,   848,    25,    -1,    -1,    28,
      -1,    -1,    -1,    -1,   117,    -1,   119,    36,   121,    -1,
     123,   124,   125,    -1,    43,    -1,    45,    -1,    -1,    -1,
      49,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    67,    68,
      69,    -1,    -1,    -1,    73,    -1,   159,   160,   161,   162,
      -1,    -1,    -1,    82,    -1,    -1,    -1,   867,   868,   869,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    56,   160,   124,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    56,   160,    -1,
     162,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      56,   160,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    56,   160,    -1,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    56,   160,    -1,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,   118,   119,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    56,
     160,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    56,   160,    -1,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    56,   160,    -1,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   118,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    56,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   119,    -1,   121,    -1,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,   113,   114,   115,   116,    -1,
     118,   159,   160,   161,   162,   123,    56,    -1,   126,   127,
     128,    -1,   130,   131,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,   160,    -1,   162,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,
      -1,   121,   122,    -1,    56,    -1,   126,   127,   128,    -1,
     130,   131,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
     160,    -1,   162,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,   114,    -1,   116,    -1,   118,    -1,    -1,   121,
      -1,    -1,    56,    -1,   126,   127,   128,    -1,   130,   131,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,   160,    -1,
     162,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    -1,
     114,    -1,   116,    -1,   118,    -1,    -1,    -1,    -1,   123,
      56,    -1,   126,   127,   128,    -1,   130,   131,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,   160,    -1,   162,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,   114,    -1,
     116,    -1,   118,    -1,    -1,    -1,    -1,    -1,    56,    -1,
     126,   127,   128,    -1,   130,   131,    -1,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,   160,    -1,   162,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    56,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,   116,    -1,   118,    -1,    -1,    -1,    56,   123,    -1,
      -1,   126,   127,   128,    -1,   130,   131,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,   160,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    -1,    -1,   114,    -1,   116,    -1,   118,
      -1,    -1,    -1,   122,    56,    -1,    -1,   126,   127,   128,
      -1,   130,   131,    -1,    -1,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,   160,    -1,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,   114,    -1,   116,    -1,   118,    -1,    -1,    -1,
      56,   123,    -1,    -1,   126,   127,   128,    -1,   130,   131,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,   160,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,   114,    -1,
     116,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,    -1,   130,   131,    -1,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   117,   160,   119,    -1,   121,    -1,   123,
     124,   125,   117,    -1,   119,    -1,   121,    -1,   123,   124,
     125,   117,    -1,   119,    -1,   121,    -1,   123,   124,   125,
     117,    -1,   119,    -1,   121,    -1,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,    -1,   159,   160,   161,   162
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    14,    15,    16,
      17,    18,    23,    24,    25,    28,    32,    36,    49,    65,
      75,    76,    77,    78,    79,    80,    81,    87,    88,    89,
      90,    91,    92,    93,    94,   119,   159,   165,   166,   167,
     199,   212,   214,   223,   301,   343,   344,   345,   346,   336,
     200,   304,   314,     7,    25,    28,    36,    43,    45,    49,
      64,    66,    67,    68,    69,    73,    82,   348,     6,     8,
      23,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    82,    32,    33,    69,    70,   340,
     341,   302,    71,    72,   342,   340,    66,   121,   121,   121,
     121,   305,   303,   170,   171,   172,   169,   213,   168,     0,
     215,   311,   312,   313,    11,    12,    19,    20,    21,    22,
     121,    56,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   160,   162,   289,   294,   295,   296,
     297,   298,   299,   300,   117,   119,   121,   123,   124,   125,
     159,   160,   161,   162,   349,   387,   390,   349,    69,    13,
      43,    45,    46,    47,    48,    63,    12,    29,    30,    31,
      32,    34,    35,    58,    59,    60,   338,    37,    38,    39,
      40,    71,    83,    84,    85,   155,   337,    25,    26,    27,
     339,   339,   339,    60,    82,   146,    74,   339,   332,   319,
     322,    37,    86,   127,   320,   121,   121,   321,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   315,   316,   121,
     162,   211,   318,   317,   146,   349,   211,     3,     3,     4,
       3,   120,     3,   289,   117,   121,   123,   124,   125,   160,
     161,   362,   387,   391,   123,   353,   387,   391,   353,   306,
     307,   308,   309,   310,    86,   347,   112,   388,   389,   350,
     334,    45,    46,   339,   339,   339,   339,   339,   339,   339,
      41,    42,   339,   339,   121,   121,   121,   339,   339,   339,
     339,   121,   117,   123,   124,   125,   159,   160,   161,   401,
     211,   211,   121,   121,    86,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   162,   212,   396,   398,
     399,   400,   401,   396,   396,   396,   121,   216,   363,   364,
     354,   355,   349,   353,   362,   362,   353,   121,   119,   174,
     175,   176,   177,   178,   180,   289,   211,   117,   211,   351,
     211,   401,   339,   339,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   333,   121,   121,
     397,   398,   400,   132,   218,   117,   119,   123,   124,   125,
     159,   160,   161,   211,   365,   385,   394,   211,   117,   123,
     124,   125,   159,   160,   161,   356,   385,   392,   211,   174,
     130,   201,   131,   132,   352,   335,   121,   121,   339,   219,
     220,   289,   111,   279,   386,   367,   366,   368,   357,   358,
     120,   174,   128,   119,   182,   179,   211,   339,   121,   125,
     133,   129,   224,   211,   161,   379,   385,   392,   117,   123,
     124,   125,   159,   160,   161,   369,   385,   395,   211,   117,
     123,   124,   125,   159,   160,   161,   359,   385,   393,   211,
     174,   183,   181,   289,   121,   220,   174,     1,    56,    95,
      96,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   153,   225,   380,   381,   370,   371,
     372,   360,   361,   202,     1,    98,   100,   127,   185,   186,
     187,   125,   133,   121,   113,   114,   115,   116,   118,   121,
     122,   212,   253,   254,   291,   295,   296,   299,   121,   125,
     128,   162,   173,   174,   177,   178,   180,   290,   293,   294,
     296,   298,   299,   226,   227,   228,   253,   252,   291,   289,
     248,   230,   232,   235,   237,   240,   242,   245,   124,   382,
     385,   393,   211,   349,   161,   373,   385,   392,   211,   349,
     211,   279,   111,   114,   116,   118,   126,   127,   128,   130,
     131,   160,   284,   285,   292,   296,   300,   188,   289,   184,
     125,   289,   117,   254,   130,   121,   280,   280,   280,   280,
     121,   281,   282,   284,   117,   117,   117,   291,   247,   282,
     117,   117,   118,   118,   114,   114,   117,   383,   384,   374,
     375,   203,   128,   132,   117,   190,   128,   120,   187,   113,
     115,   123,   162,   221,   255,   257,   259,   261,   284,   173,
     174,   121,   162,   217,   284,   122,   217,   284,   283,   229,
     255,   221,   222,   261,   126,   249,   217,   231,   233,   236,
     238,   241,   243,   246,   349,   211,   124,   376,   385,   393,
     211,     1,    97,    98,   100,   102,   204,   284,   286,   191,
     128,   289,   262,   221,   258,   261,   260,   281,   255,   280,
     125,   128,   250,   251,   290,   294,   296,   298,   299,   121,
     211,   116,   211,   116,   211,   116,   255,   377,   378,   121,
     284,   205,   252,   285,   287,   260,   189,   263,   284,   123,
     264,   121,   221,   256,   257,   261,   122,   125,   117,   234,
     239,   244,   349,   211,   128,   117,   128,   207,   117,   125,
     133,   259,   123,   192,   124,   125,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   265,   266,
     267,   280,   251,   289,   211,   211,   211,   162,   206,   284,
     208,   210,   222,   288,   261,   193,   284,   136,   136,   160,
     119,   160,   119,   119,   119,   119,   119,   119,   124,   267,
     268,   280,   260,   211,   285,   141,   142,   149,   155,   194,
     195,   269,   271,   272,   273,   274,   156,   157,   158,   277,
     278,   270,   163,   275,   259,   160,   119,   119,   119,   124,
     195,   160,   276,   276,   276,   276,     5,   289,   289,   289,
     120,   278,   276,   261,   196,   198,   197,   120,   160,   120,
     120,   120,   120,   212,   212,   212,   120,   128,   276,     5,
     276,   209,   120,   120,   120,   211
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
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
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
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
  const char *yys = yystr;

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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



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
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



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
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
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
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

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
#line 232 "surface.yy"
    { YYACCEPT; ;}
    break;

  case 3:
#line 234 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			;}
    break;

  case 8:
#line 248 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 9:
#line 250 "surface.yy"
    {
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile((yyvsp[0].yyString), directory, fileName, lineNr))
			    includeFile(directory, fileName, false, lineNr);
			;}
    break;

  case 10:
#line 258 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 11:
#line 260 "surface.yy"
    {
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile((yyvsp[0].yyString), directory, fileName, lineNr))
			    includeFile(directory, fileName, true, lineNr);
			;}
    break;

  case 12:
#line 269 "surface.yy"
    {
			  cout << directoryManager.getCwd() << '\n';
			;}
    break;

  case 13:
#line 272 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 14:
#line 274 "surface.yy"
    {
			  string directory;
			  directoryManager.realPath((yyvsp[0].yyString), directory);
			  if (!directoryManager.cd(directory))
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": cd failed");
			    }
			;}
    break;

  case 15:
#line 283 "surface.yy"
    { lexerFileNameMode(); ;}
    break;

  case 16:
#line 285 "surface.yy"
    {
			  string directory;
			  directoryManager.realPath((yyvsp[0].yyString), directory);
			  if (directoryManager.pushd(directory) == UNDEFINED)
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": pushd failed");
			    }
			;}
    break;

  case 17:
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
#line 305 "surface.yy"
    { lexerStringMode(); ;}
    break;

  case 19:
#line 307 "surface.yy"
    {
			  system((string("ls") + (yyvsp[0].yyString)).c_str());
			;}
    break;

  case 20:
#line 311 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			;}
    break;

  case 21:
#line 316 "surface.yy"
    {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			;}
    break;

  case 22:
#line 349 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[-1].yyToken)));
                        ;}
    break;

  case 23:
#line 353 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[-1].yyToken)));
                        ;}
    break;

  case 27:
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
#line 368 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  moduleExpressions.push(new ModuleExpression(t));
			;}
    break;

  case 30:
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
#line 394 "surface.yy"
    {
                          moduleExpressions.push(new ModuleExpression((yyvsp[0].yyToken)));
                        ;}
    break;

  case 36:
#line 401 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			;}
    break;

  case 37:
#line 409 "surface.yy"
    { clear(); ;}
    break;

  case 38:
#line 411 "surface.yy"
    {
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, tokenSequence));
			;}
    break;

  case 39:
#line 418 "surface.yy"
    {;}
    break;

  case 40:
#line 421 "surface.yy"
    { store((yyvsp[0].yyToken)); ;}
    break;

  case 41:
#line 422 "surface.yy"
    { store((yyvsp[0].yyToken)); ;}
    break;

  case 42:
#line 429 "surface.yy"
    {
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			;}
    break;

  case 43:
#line 434 "surface.yy"
    {
			  currentSyntaxContainer = oldSyntaxContainer;
			;}
    break;

  case 49:
#line 449 "surface.yy"
    {
			  currentRenaming->addSortMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			;}
    break;

  case 50:
#line 453 "surface.yy"
    {
			  currentRenaming->addLabelMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			;}
    break;

  case 51:
#line 456 "surface.yy"
    { lexBubble(BAR_COLON | BAR_TO, 1); ;}
    break;

  case 52:
#line 457 "surface.yy"
    { lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1); ;}
    break;

  case 53:
#line 458 "surface.yy"
    {;}
    break;

  case 54:
#line 463 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); ;}
    break;

  case 55:
#line 464 "surface.yy"
    {;}
    break;

  case 56:
#line 465 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); ;}
    break;

  case 57:
#line 471 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); ;}
    break;

  case 58:
#line 472 "surface.yy"
    {;}
    break;

  case 59:
#line 473 "surface.yy"
    { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); ;}
    break;

  case 62:
#line 480 "surface.yy"
    { currentRenaming->setPrec((yyvsp[0].yyToken)); ;}
    break;

  case 63:
#line 481 "surface.yy"
    { clear(); ;}
    break;

  case 64:
#line 482 "surface.yy"
    { currentRenaming->setGather(tokenSequence); ;}
    break;

  case 65:
#line 483 "surface.yy"
    { clear(); ;}
    break;

  case 66:
#line 484 "surface.yy"
    { currentRenaming->setFormat(tokenSequence); ;}
    break;

  case 67:
#line 485 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 68:
#line 486 "surface.yy"
    { currentRenaming->setLatexMacro((yyvsp[-1].yyString)); ;}
    break;

  case 69:
#line 492 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 70:
#line 494 "surface.yy"
    {
			  fileTable.beginModule((yyvsp[-4].yyToken), (yyvsp[-2].yyToken));
			  interpreter.setCurrentView(new View((yyvsp[-2].yyToken)));
			  currentSyntaxContainer = CV;
			  CV->addFrom(moduleExpressions.top());
			  moduleExpressions.pop();
			;}
    break;

  case 71:
#line 502 "surface.yy"
    {
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			;}
    break;

  case 72:
#line 507 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  interpreter.insertView(((yyvsp[-9].yyToken)).code(), CV);
			  CV->finishView();
			;}
    break;

  case 75:
#line 520 "surface.yy"
    {
			  CV->addSortMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			;}
    break;

  case 76:
#line 523 "surface.yy"
    {;}
    break;

  case 77:
#line 524 "surface.yy"
    { lexBubble(BAR_COLON | BAR_TO, 1); ;}
    break;

  case 80:
#line 529 "surface.yy"
    { (yyval.yyToken) = (yyvsp[-1].yyToken); ;}
    break;

  case 81:
#line 531 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  (yyval.yyToken) = t;
			;}
    break;

  case 82:
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
#line 548 "surface.yy"
    {
			  lexBubble(END_STATEMENT, 1);
			;}
    break;

  case 84:
#line 552 "surface.yy"
    {
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			;}
    break;

  case 85:
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
#line 589 "surface.yy"
    {;}
    break;

  case 88:
#line 591 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  lexerBubble.append(t);
			;}
    break;

  case 89:
#line 599 "surface.yy"
    { lexBubble(BAR_RIGHT_PAREN, 1); ;}
    break;

  case 90:
#line 600 "surface.yy"
    {;}
    break;

  case 91:
#line 606 "surface.yy"
    { lexerIdMode(); ;}
    break;

  case 92:
#line 608 "surface.yy"
    {
			  interpreter.setCurrentModule(new PreModule((yyvsp[-2].yyToken), (yyvsp[0].yyToken)));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			;}
    break;

  case 93:
#line 614 "surface.yy"
    {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule((yyvsp[0].yyToken));
			;}
    break;

  case 94:
#line 621 "surface.yy"
    {;}
    break;

  case 95:
#line 623 "surface.yy"
    {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  store(t);
			;}
    break;

  case 96:
#line 631 "surface.yy"
    {;}
    break;

  case 100:
#line 640 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter((yyvsp[-2].yyToken), me);
			;}
    break;

  case 101:
#line 648 "surface.yy"
    {
			  singleton[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(singleton[0]);
			  currentSyntaxContainer->addType(false, singleton);
			  (yyval.yyToken) = (yyvsp[0].yyToken);  // needed for line number
			;}
    break;

  case 103:
#line 657 "surface.yy"
    {;}
    break;

  case 108:
#line 668 "surface.yy"
    {
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport((yyvsp[-1].yyToken), me);
			;}
    break;

  case 109:
#line 674 "surface.yy"
    { clear(); ;}
    break;

  case 110:
#line 675 "surface.yy"
    { CM->addSortDecl(tokenSequence); ;}
    break;

  case 111:
#line 677 "surface.yy"
    { clear(); ;}
    break;

  case 112:
#line 678 "surface.yy"
    { CM->addSubsortDecl(tokenSequence); ;}
    break;

  case 113:
#line 680 "surface.yy"
    { lexBubble(BAR_COLON, 1); ;}
    break;

  case 114:
#line 681 "surface.yy"
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); ;}
    break;

  case 115:
#line 682 "surface.yy"
    {;}
    break;

  case 116:
#line 684 "surface.yy"
    {;}
    break;

  case 117:
#line 686 "surface.yy"
    {;}
    break;

  case 118:
#line 688 "surface.yy"
    { lexBubble((yyvsp[0].yyToken), BAR_COLON, 1); ;}
    break;

  case 119:
#line 689 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); ;}
    break;

  case 120:
#line 690 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 121:
#line 692 "surface.yy"
    { lexBubble((yyvsp[0].yyToken), BAR_COLON, 1);  ;}
    break;

  case 122:
#line 693 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); ;}
    break;

  case 123:
#line 694 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); ;}
    break;

  case 124:
#line 695 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 125:
#line 697 "surface.yy"
    { lexBubble((yyvsp[0].yyToken), BAR_EQUALS, 1); ;}
    break;

  case 126:
#line 698 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); ;}
    break;

  case 127:
#line 699 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 128:
#line 701 "surface.yy"
    { lexBubble((yyvsp[0].yyToken), BAR_EQUALS, 1); ;}
    break;

  case 129:
#line 702 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); ;}
    break;

  case 130:
#line 703 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); ;}
    break;

  case 131:
#line 704 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 132:
#line 706 "surface.yy"
    { lexBubble((yyvsp[0].yyToken), BAR_ARROW2, 1); ;}
    break;

  case 133:
#line 707 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); ;}
    break;

  case 134:
#line 708 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 135:
#line 710 "surface.yy"
    { lexBubble((yyvsp[0].yyToken), BAR_ARROW2, 1); ;}
    break;

  case 136:
#line 711 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); ;}
    break;

  case 137:
#line 712 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); ;}
    break;

  case 138:
#line 713 "surface.yy"
    { CM->addStatement(lexerBubble); ;}
    break;

  case 139:
#line 715 "surface.yy"
    { lexBubble(BAR_COLON, 1); ;}
    break;

  case 140:
#line 716 "surface.yy"
    { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); ;}
    break;

  case 141:
#line 717 "surface.yy"
    { CM->setFlag(SymbolType::MESSAGE); ;}
    break;

  case 142:
#line 720 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 143:
#line 725 "surface.yy"
    {
			;}
    break;

  case 144:
#line 728 "surface.yy"
    {
			;}
    break;

  case 145:
#line 731 "surface.yy"
    { clear(); ;}
    break;

  case 146:
#line 732 "surface.yy"
    { CM->addSubsortDecl(tokenSequence); ;}
    break;

  case 147:
#line 735 "surface.yy"
    {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeOpDeclsConsistent();
			;}
    break;

  case 148:
#line 745 "surface.yy"
    {;}
    break;

  case 149:
#line 746 "surface.yy"
    {;}
    break;

  case 152:
#line 754 "surface.yy"
    {
			;}
    break;

  case 153:
#line 758 "surface.yy"
    { currentSyntaxContainer->addVarDecl((yyvsp[0].yyToken)); ;}
    break;

  case 154:
#line 759 "surface.yy"
    { currentSyntaxContainer->addVarDecl((yyvsp[0].yyToken)); ;}
    break;

  case 157:
#line 766 "surface.yy"
    { singleton[0] = (yyvsp[0].yyToken); CM->addOpDecl(singleton); ;}
    break;

  case 158:
#line 767 "surface.yy"
    { CM->addOpDecl(lexerBubble); ;}
    break;

  case 161:
#line 773 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) <<
				       ": missing " << QUOTE("->") << " in constant declaration.");
			;}
    break;

  case 163:
#line 781 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			;}
    break;

  case 164:
#line 786 "surface.yy"
    {
			  IssueWarning(LineNumber((yyvsp[0].yyToken).lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			;}
    break;

  case 165:
#line 793 "surface.yy"
    {
			  if ((yyvsp[-1].yyBool))
			    CM->convertSortsToKinds();
			;}
    break;

  case 167:
#line 800 "surface.yy"
    {;}
    break;

  case 168:
#line 803 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 169:
#line 804 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 172:
#line 812 "surface.yy"
    {
			  singleton[0] = (yyvsp[0].yyToken);
			  currentSyntaxContainer->addType(false, singleton);
			;}
    break;

  case 173:
#line 816 "surface.yy"
    { clear(); ;}
    break;

  case 174:
#line 818 "surface.yy"
    {
			  currentSyntaxContainer->addType(true, tokenSequence);
			;}
    break;

  case 175:
#line 823 "surface.yy"
    { store((yyvsp[0].yyToken)); ;}
    break;

  case 176:
#line 824 "surface.yy"
    { store((yyvsp[0].yyToken)); ;}
    break;

  case 177:
#line 827 "surface.yy"
    {;}
    break;

  case 181:
#line 836 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			;}
    break;

  case 182:
#line 840 "surface.yy"
    {
			  CM->setFlag(SymbolType::LEFT_ID);
			;}
    break;

  case 183:
#line 844 "surface.yy"
    {
			  CM->setFlag(SymbolType::RIGHT_ID);
			;}
    break;

  case 184:
#line 850 "surface.yy"
    {
			  CM->setFlag(SymbolType::ASSOC);
			;}
    break;

  case 185:
#line 854 "surface.yy"
    {
			  CM->setFlag(SymbolType::COMM);
			;}
    break;

  case 186:
#line 857 "surface.yy"
    { lexBubble(BAR_RIGHT_BRACKET | BAR_OP_ATTRIBUTE, 1); ;}
    break;

  case 187:
#line 858 "surface.yy"
    { CM->setIdentity(lexerBubble); ;}
    break;

  case 188:
#line 860 "surface.yy"
    {
			  CM->setFlag(SymbolType::IDEM);
			;}
    break;

  case 189:
#line 864 "surface.yy"
    {
			  CM->setFlag(SymbolType::ITER);
			;}
    break;

  case 190:
#line 867 "surface.yy"
    { CM->setPrec((yyvsp[0].yyToken)); ;}
    break;

  case 191:
#line 868 "surface.yy"
    { clear(); ;}
    break;

  case 192:
#line 869 "surface.yy"
    { CM->setGather(tokenSequence); ;}
    break;

  case 193:
#line 870 "surface.yy"
    { clear(); ;}
    break;

  case 194:
#line 871 "surface.yy"
    { CM->setFormat(tokenSequence); ;}
    break;

  case 195:
#line 872 "surface.yy"
    { clear(); ;}
    break;

  case 196:
#line 873 "surface.yy"
    { CM->setStrat(tokenSequence); ;}
    break;

  case 197:
#line 874 "surface.yy"
    { clear(); ;}
    break;

  case 198:
#line 875 "surface.yy"
    { CM->setPoly(tokenSequence); ;}
    break;

  case 199:
#line 877 "surface.yy"
    {
			  CM->setFlag(SymbolType::MEMO);
			;}
    break;

  case 200:
#line 881 "surface.yy"
    {
			  CM->setFlag(SymbolType::CTOR);
			;}
    break;

  case 201:
#line 885 "surface.yy"
    {
			  clear();
			  CM->setFrozen(tokenSequence);
			;}
    break;

  case 202:
#line 889 "surface.yy"
    { clear(); ;}
    break;

  case 203:
#line 890 "surface.yy"
    { CM->setFrozen(tokenSequence); ;}
    break;

  case 204:
#line 892 "surface.yy"
    {
			  CM->setFlag(SymbolType::CONFIG);
			;}
    break;

  case 205:
#line 896 "surface.yy"
    {
			  CM->setFlag(SymbolType::OBJECT);
			;}
    break;

  case 206:
#line 900 "surface.yy"
    {
			  CM->setFlag(SymbolType::MESSAGE);
			;}
    break;

  case 207:
#line 904 "surface.yy"
    {
			  CM->setMetadata((yyvsp[0].yyToken));
			;}
    break;

  case 208:
#line 907 "surface.yy"
    { lexerLatexMode(); ;}
    break;

  case 209:
#line 908 "surface.yy"
    { CM->setLatexMacro((yyvsp[-1].yyString)); ;}
    break;

  case 210:
#line 909 "surface.yy"
    {;}
    break;

  case 211:
#line 911 "surface.yy"
    {
			  CM->setFlag(SymbolType::DITTO);
			;}
    break;

  case 214:
#line 924 "surface.yy"
    { store((yyvsp[0].yyToken)); ;}
    break;

  case 215:
#line 925 "surface.yy"
    { store((yyvsp[0].yyToken)); ;}
    break;

  case 218:
#line 932 "surface.yy"
    { clear(); CM->addHook(PreModule::ID_HOOK, (yyvsp[0].yyToken), tokenSequence); ;}
    break;

  case 219:
#line 933 "surface.yy"
    { CM->addHook(PreModule::ID_HOOK, (yyvsp[-1].yyToken), lexerBubble); ;}
    break;

  case 220:
#line 934 "surface.yy"
    { CM->addHook(PreModule::OP_HOOK, (yyvsp[-1].yyToken), lexerBubble); ;}
    break;

  case 221:
#line 935 "surface.yy"
    { CM->addHook(PreModule::TERM_HOOK, (yyvsp[-1].yyToken), lexerBubble); ;}
    break;

  case 222:
#line 941 "surface.yy"
    {;}
    break;

  case 223:
#line 943 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing " <<
				       QUOTE("is") << " keyword.");
			;}
    break;

  case 224:
#line 949 "surface.yy"
    {;}
    break;

  case 225:
#line 951 "surface.yy"
    {
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			;}
    break;

  case 226:
#line 959 "surface.yy"
    { store((yyvsp[0].yyToken)); ;}
    break;

  case 228:
#line 963 "surface.yy"
    { store((yyvsp[0].yyToken)); ;}
    break;

  case 229:
#line 964 "surface.yy"
    { store((yyvsp[0].yyToken)); ;}
    break;

  case 230:
#line 965 "surface.yy"
    { store((yyvsp[0].yyToken)); ;}
    break;

  case 231:
#line 966 "surface.yy"
    { store((yyvsp[0].yyToken)); ;}
    break;

  case 232:
#line 973 "surface.yy"
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

  case 233:
#line 984 "surface.yy"
    { fragStore((yyvsp[0].yyToken)); ;}
    break;

  case 234:
#line 985 "surface.yy"
    { fragStore((yyvsp[0].yyToken)); ;}
    break;

  case 235:
#line 986 "surface.yy"
    { fragStore((yyvsp[0].yyToken)); ;}
    break;

  case 236:
#line 989 "surface.yy"
    { fragStore((yyvsp[0].yyToken)); ;}
    break;

  case 237:
#line 990 "surface.yy"
    {;}
    break;

  case 238:
#line 991 "surface.yy"
    {;}
    break;

  case 341:
#line 1071 "surface.yy"
    { lexBubble(END_COMMAND, 1) ;}
    break;

  case 342:
#line 1073 "surface.yy"
    {
			  interpreter.setCurrentModule(lexerBubble);
			;}
    break;

  case 343:
#line 1076 "surface.yy"
    { lexBubble(END_COMMAND, 1) ;}
    break;

  case 344:
#line 1078 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->dump();
			;}
    break;

  case 345:
#line 1083 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 346:
#line 1088 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(lexerBubble);
			;}
    break;

  case 347:
#line 1095 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 348:
#line 1100 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(lexerBubble);
			;}
    break;

  case 349:
#line 1107 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 350:
#line 1112 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(lexerBubble, (yyvsp[-3].yyBool));
			;}
    break;

  case 351:
#line 1119 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 352:
#line 1125 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(lexerBubble, number, (yyvsp[-3].yyBool));
			;}
    break;

  case 353:
#line 1131 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 354:
#line 1138 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(lexerBubble, number, number2, (yyvsp[-3].yyBool));
			;}
    break;

  case 355:
#line 1144 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 356:
#line 1151 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(lexerBubble, number, number2, (yyvsp[-3].yyBool));
			;}
    break;

  case 357:
#line 1157 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 358:
#line 1163 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, (yyvsp[-3].yyBool));
			;}
    break;

  case 359:
#line 1169 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			;}
    break;

  case 360:
#line 1176 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, (yyvsp[-2].yySearchKind));
			;}
    break;

  case 361:
#line 1182 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 362:
#line 1188 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(lexerBubble, (yyvsp[-2].yyBool), number);
			;}
    break;

  case 363:
#line 1194 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			;}
    break;

  case 364:
#line 1200 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.unify(lexerBubble, (yyvsp[-2].yyBool), number);
			;}
    break;

  case 365:
#line 1206 "surface.yy"
    {
			  interpreter.cont((yyvsp[-1].yyInt64), (yyvsp[-3].yyBool));
			;}
    break;

  case 366:
#line 1210 "surface.yy"
    {
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			;}
    break;

  case 367:
#line 1215 "surface.yy"
    {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(lexerBubble);
			;}
    break;

  case 368:
#line 1221 "surface.yy"
    {
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(lexerBubble);
			;}
    break;

  case 369:
#line 1226 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 370:
#line 1228 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceSelect((yyvsp[-2].yyBool));
			;}
    break;

  case 371:
#line 1232 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 372:
#line 1234 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.traceExclude((yyvsp[-2].yyBool));
			;}
    break;

  case 373:
#line 1238 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 374:
#line 1240 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.breakSelect((yyvsp[-2].yyBool));
			;}
    break;

  case 375:
#line 1244 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 376:
#line 1246 "surface.yy"
    {
			  lexerInitialMode();
			  interpreter.printConceal((yyvsp[-2].yyBool));
			;}
    break;

  case 377:
#line 1251 "surface.yy"
    {
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			;}
    break;

  case 378:
#line 1258 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 379:
#line 1260 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			;}
    break;

  case 380:
#line 1264 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 381:
#line 1266 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			;}
    break;

  case 382:
#line 1270 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 383:
#line 1272 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(true);
			;}
    break;

  case 384:
#line 1276 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 385:
#line 1278 "surface.yy"
    {
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showView();
			;}
    break;

  case 386:
#line 1283 "surface.yy"
    {
			  interpreter.showModules(true);
			;}
    break;

  case 387:
#line 1287 "surface.yy"
    {
			  interpreter.showNamedViews();
			;}
    break;

  case 388:
#line 1290 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 389:
#line 1292 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSortsAndSubsorts();
			;}
    break;

  case 390:
#line 1296 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 391:
#line 1298 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showOps();
			;}
    break;

  case 392:
#line 1302 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 393:
#line 1304 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showVars();
			;}
    break;

  case 394:
#line 1308 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 395:
#line 1310 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showMbs();
			;}
    break;

  case 396:
#line 1314 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 397:
#line 1316 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showEqs();
			;}
    break;

  case 398:
#line 1320 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 399:
#line 1322 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showRls();
			;}
    break;

  case 400:
#line 1326 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 401:
#line 1328 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSummary();
			;}
    break;

  case 402:
#line 1332 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 403:
#line 1334 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showKinds();
			;}
    break;

  case 404:
#line 1339 "surface.yy"
    {
			  interpreter.showSearchPath((yyvsp[-1].yyInt64));
			;}
    break;

  case 405:
#line 1343 "surface.yy"
    {
			  interpreter.showSearchPathLabels((yyvsp[-1].yyInt64));
			;}
    break;

  case 406:
#line 1347 "surface.yy"
    {
			  interpreter.showSearchGraph();
			;}
    break;

  case 407:
#line 1350 "surface.yy"
    { lexBubble(END_COMMAND, 0); ;}
    break;

  case 408:
#line 1352 "surface.yy"
    {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showProfile();
			;}
    break;

  case 409:
#line 1360 "surface.yy"
    {
			  globalAdvisoryFlag = (yyvsp[-1].yyBool);
			;}
    break;

  case 410:
#line 1364 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[-1].yyBool));
			;}
    break;

  case 411:
#line 1368 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, (yyvsp[-1].yyBool));
			;}
    break;

  case 412:
#line 1372 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, (yyvsp[-1].yyBool));
			;}
    break;

  case 413:
#line 1376 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, (yyvsp[-1].yyBool));
			;}
    break;

  case 414:
#line 1380 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, (yyvsp[-1].yyBool));
			;}
    break;

  case 415:
#line 1384 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, (yyvsp[-1].yyBool));
			;}
    break;

  case 416:
#line 1388 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[-1].yyBool));
			;}
    break;

  case 417:
#line 1392 "surface.yy"
    {
			  interpreter.setPrintFlag((yyvsp[-2].yyPrintFlags), (yyvsp[-1].yyBool));
			;}
    break;

  case 418:
#line 1396 "surface.yy"
    {
			  interpreter.setFlag((yyvsp[-2].yyFlags), (yyvsp[-1].yyBool));
			;}
    break;

  case 419:
#line 1400 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::BREAK, (yyvsp[-1].yyBool));
			;}
    break;

  case 420:
#line 1403 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 421:
#line 1404 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 422:
#line 1406 "surface.yy"
    {
			  interpreter.setAutoImport((yyvsp[-5].yyImportMode), (yyvsp[-3].yyToken), (yyvsp[-1].yyBool));
			;}
    break;

  case 423:
#line 1409 "surface.yy"
    { lexerCmdMode(); ;}
    break;

  case 424:
#line 1410 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 425:
#line 1412 "surface.yy"
    {
			  interpreter.setOmodInclude((yyvsp[-3].yyToken), (yyvsp[-1].yyBool));
			;}
    break;

  case 426:
#line 1416 "surface.yy"
    {
			  globalVerboseFlag = (yyvsp[-1].yyBool);
			;}
    break;

  case 427:
#line 1420 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, (yyvsp[-1].yyBool));
			;}
    break;

  case 428:
#line 1424 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, (yyvsp[-1].yyBool));
			;}
    break;

  case 429:
#line 1428 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, (yyvsp[-1].yyBool));
			;}
    break;

  case 430:
#line 1432 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::PROFILE, (yyvsp[-1].yyBool));
			;}
    break;

  case 431:
#line 1436 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, (yyvsp[-1].yyBool));
			;}
    break;

  case 432:
#line 1443 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			;}
    break;

  case 433:
#line 1447 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			;}
    break;

  case 434:
#line 1451 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			;}
    break;

  case 435:
#line 1455 "surface.yy"
    {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			;}
    break;

  case 436:
#line 1462 "surface.yy"
    {
			  MemoryCell::setShowGC((yyvsp[-1].yyBool));
			;}
    break;

  case 437:
#line 1466 "surface.yy"
    {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[-1].yyBool));
			;}
    break;

  case 438:
#line 1472 "surface.yy"
    { lexerInitialMode(); ;}
    break;

  case 440:
#line 1479 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_MIXFIX; ;}
    break;

  case 441:
#line 1480 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FLAT; ;}
    break;

  case 442:
#line 1481 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_ALIASES; ;}
    break;

  case 443:
#line 1482 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_WITH_PARENS; ;}
    break;

  case 444:
#line 1483 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_GRAPH; ;}
    break;

  case 445:
#line 1484 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_CONCEAL; ;}
    break;

  case 446:
#line 1485 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_NUMBER; ;}
    break;

  case 447:
#line 1486 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_RAT; ;}
    break;

  case 448:
#line 1487 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_COLOR; ;}
    break;

  case 449:
#line 1488 "surface.yy"
    { (yyval.yyPrintFlags) = Interpreter::PRINT_FORMAT; ;}
    break;

  case 450:
#line 1491 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE; ;}
    break;

  case 451:
#line 1492 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_CONDITION; ;}
    break;

  case 452:
#line 1493 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_WHOLE; ;}
    break;

  case 453:
#line 1494 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SUBSTITUTION; ;}
    break;

  case 454:
#line 1495 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_SELECT; ;}
    break;

  case 455:
#line 1496 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_MB; ;}
    break;

  case 456:
#line 1497 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_EQ; ;}
    break;

  case 457:
#line 1498 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_RL; ;}
    break;

  case 458:
#line 1499 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_REWRITE; ;}
    break;

  case 459:
#line 1500 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BODY; ;}
    break;

  case 460:
#line 1501 "surface.yy"
    { (yyval.yyFlags) = Interpreter::TRACE_BUILTIN; ;}
    break;

  case 461:
#line 1504 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 462:
#line 1505 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 463:
#line 1508 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 464:
#line 1509 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 465:
#line 1512 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 466:
#line 1513 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 467:
#line 1516 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 468:
#line 1517 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 469:
#line 1522 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::NARROW; ;}
    break;

  case 470:
#line 1523 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::XG_NARROW; ;}
    break;

  case 471:
#line 1524 "surface.yy"
    { (yyval.yySearchKind) = Interpreter::SEARCH; ;}
    break;

  case 472:
#line 1527 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 473:
#line 1528 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 474:
#line 1532 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 475:
#line 1535 "surface.yy"
    { (yyval.yyBool) = true; ;}
    break;

  case 476:
#line 1536 "surface.yy"
    { (yyval.yyBool) = false; ;}
    break;

  case 477:
#line 1539 "surface.yy"
    { (yyval.yyInt64) = (yyvsp[0].yyInt64); ;}
    break;

  case 478:
#line 1540 "surface.yy"
    { (yyval.yyInt64) = NONE; ;}
    break;

  case 479:
#line 1543 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::PROTECTING; ;}
    break;

  case 480:
#line 1544 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::EXTENDING; ;}
    break;

  case 481:
#line 1545 "surface.yy"
    { (yyval.yyImportMode) = ImportModule::INCLUDING; ;}
    break;

  case 483:
#line 1555 "surface.yy"
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0); ;}
    break;

  case 485:
#line 1559 "surface.yy"
    { moduleExpr = lexerBubble; lexBubble(END_COMMAND, 1); ;}
    break;

  case 488:
#line 1571 "surface.yy"
    { lexSave((yyvsp[0].yyToken)); ;}
    break;

  case 491:
#line 1574 "surface.yy"
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0);  ;}
    break;

  case 493:
#line 1579 "surface.yy"
    { lexContinueSave((yyvsp[0].yyToken)); ;}
    break;

  case 495:
#line 1581 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); ;}
    break;

  case 498:
#line 1587 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); ;}
    break;

  case 500:
#line 1589 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); ;}
    break;

  case 503:
#line 1604 "surface.yy"
    { lexSave((yyvsp[0].yyToken)); ;}
    break;

  case 506:
#line 1607 "surface.yy"
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0); ;}
    break;

  case 508:
#line 1616 "surface.yy"
    { lexContinueSave((yyvsp[0].yyToken)); ;}
    break;

  case 510:
#line 1618 "surface.yy"
    { lexContinueSave((yyvsp[0].yyToken)); ;}
    break;

  case 512:
#line 1620 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); ;}
    break;

  case 515:
#line 1630 "surface.yy"
    { number = Token::codeToInt64(lexerBubble[1].code()); ;}
    break;

  case 517:
#line 1632 "surface.yy"
    { lexContinueSave((yyvsp[0].yyToken)); ;}
    break;

  case 519:
#line 1634 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); ;}
    break;

  case 522:
#line 1644 "surface.yy"
    { lexContinueSave((yyvsp[0].yyToken)); ;}
    break;

  case 524:
#line 1646 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); ;}
    break;

  case 527:
#line 1657 "surface.yy"
    {
			  number = Token::codeToInt64(lexerBubble[1].code());
			  number2 = Token::codeToInt64(lexerBubble[3].code());
			  clear();
			;}
    break;

  case 529:
#line 1663 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); ;}
    break;

  case 532:
#line 1673 "surface.yy"
    { lexContinueSave((yyvsp[0].yyToken)); ;}
    break;

  case 534:
#line 1675 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); ;}
    break;

  case 537:
#line 1685 "surface.yy"
    { number2 = Token::codeToInt64(lexerBubble[2].code()); ;}
    break;

  case 539:
#line 1687 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); ;}
    break;

  case 542:
#line 1692 "surface.yy"
    { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0, 1); ;}
    break;

  case 545:
#line 1698 "surface.yy"
    { lexBubble((yyvsp[0].yyToken), END_COMMAND, 1, 1); ;}
    break;

  case 547:
#line 1700 "surface.yy"
    { lexBubble((yyvsp[0].yyToken), BAR_COLON | END_COMMAND, 0); ;}
    break;

  case 549:
#line 1703 "surface.yy"
    {
			  lexerBubble.resize(1);
			  lexerBubble[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(lexerBubble[0]);
			;}
    break;

  case 587:
#line 1742 "surface.yy"
    {;}
    break;

  case 589:
#line 1747 "surface.yy"
    {
			  singleton[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(singleton[0]);
			  interpreter.addSelected(singleton);
			;}
    break;

  case 592:
#line 1758 "surface.yy"
    {
			  singleton[0] = (yyvsp[0].yyToken);
			  interpreter.addSelected(singleton);
			;}
    break;

  case 593:
#line 1763 "surface.yy"
    {
			  interpreter.addSelected(lexerBubble);
			;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 5060 "surface.c"

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
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1793 "surface.yy"


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

void
missingSpace(const Token& token)
{
  IssueWarning(LineNumber(token.lineNumber()) << ": missing space between " <<
	       QUOTE(token) << " and period.");
}

