/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse nqyyparse
#define yylex   nqyylex
#define yyerror nqyyerror
#define yylval  nqyylval
#define yychar  nqyychar
#define yydebug nqyydebug
#define yynerrs nqyynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     __TTL_PUNCT_BEGIN = 258,
     _CARET_WS = 259,
     _CARET_NOWS = 260,
     _CARET_CARET = 261,
     _COLON = 262,
     _COMMA = 263,
     _DOT_WS = 264,
     _LBRA = 265,
     _LBRA_TOP_TRIG = 266,
     _LPAR = 267,
     _LSQBRA = 268,
     _LSQBRA_RSQBRA = 269,
     _RBRA = 270,
     _RPAR = 271,
     _RSQBRA = 272,
     _SEMI = 273,
     _EQ = 274,
     _EQ_TOP_TRIG = 275,
     _EQ_GT = 276,
     _LT_EQ = 277,
     _BANG = 278,
     _AT_a_L = 279,
     _AT_base_L = 280,
     _AT_has_L = 281,
     _AT_is_L = 282,
     _AT_keywords_L = 283,
     _AT_of_L = 284,
     _AT_prefix_L = 285,
     _AT_this_L = 286,
     false_L = 287,
     true_L = 288,
     __TTL_PUNCT_END = 289,
     __TTL_NONPUNCT_START = 290,
     TURTLE_INTEGER = 291,
     TURTLE_DECIMAL = 292,
     TURTLE_DOUBLE = 293,
     TURTLE_STRING = 294,
     KEYWORD = 295,
     LANGTAG = 296,
     QNAME = 297,
     QNAME_NS = 298,
     VARIABLE = 299,
     BLANK_NODE_LABEL = 300,
     Q_IRI_REF = 301,
     _GARBAGE_BEFORE_DOT_WS = 302,
     TTL_RECOVERABLE_ERROR = 303,
     __NQUAD_NONPUNCT_END = 304
   };
#endif
/* Tokens.  */
#define __TTL_PUNCT_BEGIN 258
#define _CARET_WS 259
#define _CARET_NOWS 260
#define _CARET_CARET 261
#define _COLON 262
#define _COMMA 263
#define _DOT_WS 264
#define _LBRA 265
#define _LBRA_TOP_TRIG 266
#define _LPAR 267
#define _LSQBRA 268
#define _LSQBRA_RSQBRA 269
#define _RBRA 270
#define _RPAR 271
#define _RSQBRA 272
#define _SEMI 273
#define _EQ 274
#define _EQ_TOP_TRIG 275
#define _EQ_GT 276
#define _LT_EQ 277
#define _BANG 278
#define _AT_a_L 279
#define _AT_base_L 280
#define _AT_has_L 281
#define _AT_is_L 282
#define _AT_keywords_L 283
#define _AT_of_L 284
#define _AT_prefix_L 285
#define _AT_this_L 286
#define false_L 287
#define true_L 288
#define __TTL_PUNCT_END 289
#define __TTL_NONPUNCT_START 290
#define TURTLE_INTEGER 291
#define TURTLE_DECIMAL 292
#define TURTLE_DOUBLE 293
#define TURTLE_STRING 294
#define KEYWORD 295
#define LANGTAG 296
#define QNAME 297
#define QNAME_NS 298
#define VARIABLE 299
#define BLANK_NODE_LABEL 300
#define Q_IRI_REF 301
#define _GARBAGE_BEFORE_DOT_WS 302
#define TTL_RECOVERABLE_ERROR 303
#define __NQUAD_NONPUNCT_END 304




/* Copy the first part of user declarations.  */
#line 31 "./nquad_p.y"


#include "libutil.h"
#include "sqlnode.h"
#include "sqlparext.h"
#include "rdf_core.h"
#include "xmltree.h"
/*#include "langfunc.h"*/
#include "turtle_p.h"
#define nqyylex ttlyylex
#define nqyyerror ttlyyerror


#ifdef DEBUG
#define ttlyyerror(ttlp_arg,yyscan,strg) ttlyyerror_impl_1(ttlp_arg, NULL, yystate, yyssa, yyssp, (strg))
#define ttlyyerror_action(strg) ttlyyerror_impl_1(ttlp_arg, NULL, yystate, yyssa, yyssp, (strg))
#else
#define ttlyyerror(ttlp_arg,yyscan,strg) ttlyyerror_impl(ttlp_arg, NULL, (strg))
#define ttlyyerror_action(strg) ttlyyerror_impl(ttlp_arg, NULL, (strg))
#endif

#define TTLYYERROR_ACTION_COND(flag,strg) do { \
    if (!((flag) & ttlp_arg->ttlp_flags)) \
      ttlyyerror_action(strg); \
    else \
      tf_report (ttlp_arg->ttlp_tf, 'W', NULL, NULL, (strg)); \
  } while (0)


extern int ttlyylex (void *yylval_param, ttlp_t *ttlp_arg, yyscan_t yyscanner);


#ifdef TTLDEBUG
#define YYDEBUG 1
#endif

#define TTLP_URI_RESOLVE_IF_NEEDED(rel) \
  do { \
    if ((NULL != ttlp_arg->ttlp_tf->tf_base_uri) && strncmp ((rel), "http://", 7)) \
      (rel) = ttlp_uri_resolve (ttlp_arg, (rel)); \
    } while (0)



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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 76 "./nquad_p.y"
{
  caddr_t box;
  ptrlong token_type;
  void *nothing;
}
/* Line 187 of yacc.c.  */
#line 252 "nquad_p.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 265 "nquad_p.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  111

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    13,    17,    22,    27,
      32,    37,    41,    44,    46,    47,    49,    51,    53,    55,
      57,    59,    61,    65,    67,    69,    71,    73,    75,    77,
      79,    81,    83,    85,    87,    89,    91,    95,    99,   101,
     103,   105,   107,   109,   111,   113,   116,   120,   121,   125,
     126,   130,   131,   135,   138,   141,   144,   147,   150,   153,
     157,   158,   164,   167,   172,   173,   179,   184,   185,   187,
     189,   191,   193,   195,   197,   199
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    -1,    51,    52,    -1,    -1,    28,    53,
      56,    54,    -1,    25,    46,    54,    -1,    30,    43,    46,
      54,    -1,    30,     7,    46,    54,    -1,    55,    58,    60,
       9,    -1,    55,    58,    47,     9,    -1,    55,    47,     9,
      -1,    47,     9,    -1,     1,    -1,    -1,     9,    -1,    68,
      -1,    44,    -1,    67,    -1,    59,    -1,    48,    -1,    57,
      -1,    56,     8,    57,    -1,    42,    -1,    24,    -1,    26,
      -1,    27,    -1,    29,    -1,    31,    -1,    68,    -1,    44,
      -1,    24,    -1,    19,    -1,    21,    -1,    14,    -1,    45,
      -1,    27,    68,    29,    -1,    27,    44,    29,    -1,    22,
      -1,    33,    -1,    32,    -1,    36,    -1,    37,    -1,    38,
      -1,    39,    -1,    39,    41,    -1,    39,     6,    68,    -1,
      -1,    68,    61,    66,    -1,    -1,    44,    62,    66,    -1,
      -1,    67,    63,    66,    -1,    33,    66,    -1,    32,    66,
      -1,    36,    66,    -1,    37,    66,    -1,    38,    66,    -1,
      39,    66,    -1,    39,    41,    66,    -1,    -1,    39,     6,
      68,    64,    66,    -1,    48,    66,    -1,    39,     6,    48,
      66,    -1,    -1,    48,     6,    68,    65,    66,    -1,    48,
       6,    48,    66,    -1,    -1,    68,    -1,    48,    -1,    47,
      -1,    45,    -1,    14,    -1,    46,    -1,    42,    -1,    43,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   151,   155,   155,   156,   157,   176,   179,
     180,   181,   182,   183,   186,   188,   192,   195,   197,   199,
     202,   207,   208,   212,   213,   214,   215,   216,   217,   221,
     222,   223,   224,   225,   226,   230,   239,   240,   241,   245,
     246,   247,   248,   249,   250,   251,   252,   258,   258,   264,
     264,   269,   269,   274,   276,   278,   282,   286,   290,   294,
     300,   300,   308,   309,   312,   312,   316,   320,   325,   332,
     333,   338,   345,   349,   356,   364
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "__TTL_PUNCT_BEGIN", "_CARET_WS",
  "_CARET_NOWS", "_CARET_CARET", "_COLON", "_COMMA", "_DOT_WS", "_LBRA",
  "_LBRA_TOP_TRIG", "_LPAR", "_LSQBRA", "_LSQBRA_RSQBRA", "_RBRA", "_RPAR",
  "_RSQBRA", "_SEMI", "_EQ", "_EQ_TOP_TRIG", "_EQ_GT", "_LT_EQ", "_BANG",
  "_AT_a_L", "_AT_base_L", "_AT_has_L", "_AT_is_L", "_AT_keywords_L",
  "_AT_of_L", "_AT_prefix_L", "_AT_this_L", "false_L", "true_L",
  "__TTL_PUNCT_END", "__TTL_NONPUNCT_START", "TURTLE_INTEGER",
  "TURTLE_DECIMAL", "TURTLE_DOUBLE", "TURTLE_STRING", "KEYWORD", "LANGTAG",
  "QNAME", "QNAME_NS", "VARIABLE", "BLANK_NODE_LABEL", "Q_IRI_REF",
  "_GARBAGE_BEFORE_DOT_WS", "TTL_RECOVERABLE_ERROR",
  "__NQUAD_NONPUNCT_END", "$accept", "nquaddoc", "clause", "@1", "dot_opt",
  "subject", "keyword_list", "keyword", "pred", "literal_subject",
  "object_with_ctx", "@2", "@3", "@4", "@5", "@6", "ctx_opt", "blank",
  "q_complete", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    53,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    54,    54,    55,    55,    55,    55,
      55,    56,    56,    57,    57,    57,    57,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    61,    60,    62,
      60,    63,    60,    60,    60,    60,    60,    60,    60,    60,
      64,    60,    60,    60,    65,    60,    60,    66,    66,    66,
      66,    67,    67,    68,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     4,     3,     4,     4,     4,
       4,     3,     2,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     0,     3,     0,
       3,     0,     3,     2,     2,     2,     2,     2,     2,     3,
       0,     5,     2,     4,     0,     5,     4,     0,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    13,    72,     0,     4,     0,    40,    39,
      41,    42,    43,    44,    74,    75,    17,    71,    73,     0,
      20,     3,     0,    19,    18,    16,    14,     0,     0,     0,
       0,    45,    12,    34,    32,    33,    38,    31,     0,    30,
      35,     0,     0,    29,    15,     6,    24,    25,    26,    27,
      28,    23,    14,    21,    14,    14,    46,     0,     0,    11,
      67,    67,    67,    67,    67,    67,    49,     0,    67,     0,
      51,    47,     0,     5,     8,     7,    37,    36,    70,    69,
      54,    68,    53,    55,    56,    57,     0,    67,    58,    67,
      10,     0,    62,     9,    67,    67,    22,    67,    60,    59,
      50,    67,    64,    52,    48,    63,    67,    66,    67,    61,
      65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    21,    27,    45,    22,    52,    53,    42,    23,
      69,    95,    89,    94,   106,   108,    80,    24,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -42
static const yytype_int8 yypact[] =
{
     -42,     6,   -42,   -42,   -42,   -38,   -42,    -3,   -42,   -42,
     -42,   -42,   -42,     5,   -42,   -42,   -42,   -42,   -42,     7,
     -42,   -42,   107,   -42,   -42,   -42,     9,   -12,   -23,   -14,
     -33,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -41,   -42,
     -42,    24,    72,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,    18,   -42,     9,     9,   -42,    31,    32,   -42,
      50,    50,    50,    50,    50,    22,   -42,    38,    29,    57,
     -42,   -42,   -12,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,    36,    50,   -42,    50,
     -42,    90,   -42,   -42,    50,    50,   -42,    50,   -42,   -42,
     -42,    50,   -42,   -42,   -42,   -42,    50,   -42,    50,   -42,
     -42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,   -42,   -30,   -42,   -42,    -5,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,    -6,    45,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      25,    14,    15,    57,    28,    18,     2,     3,    26,    14,
      15,    30,    46,    18,    47,    48,    32,    49,    44,    50,
       4,    43,    73,    54,    74,    75,    72,    44,    86,    56,
      51,     5,    55,    59,     6,    91,     7,    58,     8,     9,
      29,    71,    10,    11,    12,    13,    31,    90,    14,    15,
      16,    17,    18,    19,    20,    82,    83,    84,    85,    88,
      76,    77,    92,    87,    14,    15,    93,    96,    18,    78,
      79,    14,    15,     0,     0,    18,    78,    79,    14,    15,
       0,    99,    18,   100,    97,    98,     4,    70,   103,   104,
     102,   105,    14,    15,     0,   107,    18,    78,    79,     0,
     109,     0,   110,     0,    60,    61,     0,     0,    62,    63,
      64,    65,     0,     0,    14,    15,    66,    17,    18,    67,
      68,    33,     0,     0,     0,     0,    34,     0,    35,    36,
       0,    37,    14,    15,    38,     0,    18,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,    39,    40,    18,    41
};

static const yytype_int8 yycheck[] =
{
       1,    42,    43,    44,     7,    46,     0,     1,    46,    42,
      43,     6,    24,    46,    26,    27,     9,    29,     9,    31,
      14,    22,    52,    46,    54,    55,     8,     9,     6,    30,
      42,    25,    46,     9,    28,     6,    30,    38,    32,    33,
      43,    42,    36,    37,    38,    39,    41,     9,    42,    43,
      44,    45,    46,    47,    48,    61,    62,    63,    64,    65,
      29,    29,    68,    41,    42,    43,     9,    72,    46,    47,
      48,    42,    43,    -1,    -1,    46,    47,    48,    42,    43,
      -1,    87,    46,    89,    48,    86,    14,    42,    94,    95,
      91,    97,    42,    43,    -1,   101,    46,    47,    48,    -1,
     106,    -1,   108,    -1,    32,    33,    -1,    -1,    36,    37,
      38,    39,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    14,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      -1,    24,    42,    43,    27,    -1,    46,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,     0,     1,    14,    25,    28,    30,    32,    33,
      36,    37,    38,    39,    42,    43,    44,    45,    46,    47,
      48,    52,    55,    59,    67,    68,    46,    53,     7,    43,
       6,    41,     9,    14,    19,    21,    22,    24,    27,    44,
      45,    47,    58,    68,     9,    54,    24,    26,    27,    29,
      31,    42,    56,    57,    46,    46,    68,    44,    68,     9,
      32,    33,    36,    37,    38,    39,    44,    47,    48,    60,
      67,    68,     8,    54,    54,    54,    29,    29,    47,    48,
      66,    68,    66,    66,    66,    66,     6,    41,    66,    62,
       9,     6,    66,     9,    63,    61,    57,    48,    68,    66,
      66,    48,    68,    66,    66,    66,    64,    66,    65,    66,
      66
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
      yyerror (ttlp_arg, yyscanner, YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (&yylval, ttlp_arg, yyscanner)
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
		  Type, Value, ttlp_arg, yyscanner); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, ttlp_t * ttlp_arg, yyscan_t yyscanner)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, ttlp_arg, yyscanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    ttlp_t * ttlp_arg;
    yyscan_t yyscanner;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (ttlp_arg);
  YYUSE (yyscanner);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, ttlp_t * ttlp_arg, yyscan_t yyscanner)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, ttlp_arg, yyscanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    ttlp_t * ttlp_arg;
    yyscan_t yyscanner;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, ttlp_arg, yyscanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, ttlp_t * ttlp_arg, yyscan_t yyscanner)
#else
static void
yy_reduce_print (yyvsp, yyrule, ttlp_arg, yyscanner)
    YYSTYPE *yyvsp;
    int yyrule;
    ttlp_t * ttlp_arg;
    yyscan_t yyscanner;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , ttlp_arg, yyscanner);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, ttlp_arg, yyscanner); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, ttlp_t * ttlp_arg, yyscan_t yyscanner)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, ttlp_arg, yyscanner)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    ttlp_t * ttlp_arg;
    yyscan_t yyscanner;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (ttlp_arg);
  YYUSE (yyscanner);

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
int yyparse (ttlp_t * ttlp_arg, yyscan_t yyscanner);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

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
yyparse (ttlp_t * ttlp_arg, yyscan_t yyscanner)
#else
int
yyparse (ttlp_arg, yyscanner)
    ttlp_t * ttlp_arg;
    yyscan_t yyscanner;
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
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 4:
#line 155 "./nquad_p.y"
    { ttlp_arg->ttlp_special_qnames = ~0; }
    break;

  case 6:
#line 156 "./nquad_p.y"
    { dk_free_box (ttlp_arg->ttlp_tf->tf_base_uri); ttlp_arg->ttlp_tf->tf_base_uri = (yyvsp[(2) - (3)].box); }
    break;

  case 7:
#line 157 "./nquad_p.y"
    {
		caddr_t *old_uri_ptr;
		if (NULL != ttlp_arg->ttlp_namespaces_prefix2iri)
		  old_uri_ptr = (caddr_t *)id_hash_get (ttlp_arg->ttlp_namespaces_prefix2iri, &((yyvsp[(2) - (4)].box)));
		else
		  {
		    ttlp_arg->ttlp_namespaces_prefix2iri = (id_hash_t *)box_dv_dict_hashtable (31);
		    old_uri_ptr = NULL;
		  }
		if (NULL != old_uri_ptr)
		  {
		    int err = strcmp (old_uri_ptr[0], (yyvsp[(3) - (4)].box));
		    dk_free_box ((yyvsp[(2) - (4)].box));
		    dk_free_box ((yyvsp[(3) - (4)].box));
		    if (err)
		      ttlyyerror_action ("Namespace prefix is re-used for a different namespace IRI");
		  }
		else
		  id_hash_set (ttlp_arg->ttlp_namespaces_prefix2iri, &((yyvsp[(2) - (4)].box)), &((yyvsp[(3) - (4)].box))); }
    break;

  case 8:
#line 176 "./nquad_p.y"
    {
		dk_free_box (ttlp_arg->ttlp_default_ns_uri);
		ttlp_arg->ttlp_default_ns_uri = (yyvsp[(3) - (4)].box); }
    break;

  case 13:
#line 183 "./nquad_p.y"
    { ttlyyerror_action ("Only a triple or a special clause (like prefix declaration) is allowed here"); }
    break;

  case 16:
#line 192 "./nquad_p.y"
    { dk_free_tree (ttlp_arg->ttlp_subj_uri);
		ttlp_arg->ttlp_subj_uri = ttlp_arg->ttlp_last_complete_uri;
		ttlp_arg->ttlp_last_complete_uri = NULL; }
    break;

  case 17:
#line 195 "./nquad_p.y"
    { dk_free_tree (ttlp_arg->ttlp_subj_uri);
		ttlp_arg->ttlp_subj_uri = (yyvsp[(1) - (1)].box); }
    break;

  case 18:
#line 197 "./nquad_p.y"
    { dk_free_tree (ttlp_arg->ttlp_subj_uri);
		ttlp_arg->ttlp_subj_uri = (yyvsp[(1) - (1)].box); }
    break;

  case 19:
#line 199 "./nquad_p.y"
    {
		TTLYYERROR_ACTION_COND (TTLP_SKIP_LITERAL_SUBJECTS, "Virtuoso does not support literal subjects");
		dk_free_tree (ttlp_arg->ttlp_subj_uri); ttlp_arg->ttlp_subj_uri = NULL; }
    break;

  case 20:
#line 202 "./nquad_p.y"
    { dk_free_tree (ttlp_arg->ttlp_subj_uri);
		ttlp_arg->ttlp_subj_uri = NULL; }
    break;

  case 21:
#line 207 "./nquad_p.y"
    { ttlp_arg->ttlp_special_qnames &= ~((yyvsp[(1) - (1)].token_type)); }
    break;

  case 22:
#line 208 "./nquad_p.y"
    { ttlp_arg->ttlp_special_qnames &= ~((yyvsp[(3) - (3)].token_type)); }
    break;

  case 23:
#line 212 "./nquad_p.y"
    { (yyval.token_type) = ttlp_bit_of_special_qname ((yyvsp[(1) - (1)].box)); }
    break;

  case 24:
#line 213 "./nquad_p.y"
    { (yyval.token_type) = TTLP_ALLOW_QNAME_A; }
    break;

  case 25:
#line 214 "./nquad_p.y"
    { (yyval.token_type) = TTLP_ALLOW_QNAME_HAS; }
    break;

  case 26:
#line 215 "./nquad_p.y"
    { (yyval.token_type) = TTLP_ALLOW_QNAME_IS; }
    break;

  case 27:
#line 216 "./nquad_p.y"
    { (yyval.token_type) = TTLP_ALLOW_QNAME_OF; }
    break;

  case 28:
#line 217 "./nquad_p.y"
    { (yyval.token_type) = TTLP_ALLOW_QNAME_THIS; }
    break;

  case 29:
#line 221 "./nquad_p.y"
    { dk_free_tree (ttlp_arg->ttlp_pred_uri); ttlp_arg->ttlp_pred_uri = ttlp_arg->ttlp_last_complete_uri; ttlp_arg->ttlp_last_complete_uri = NULL; }
    break;

  case 30:
#line 222 "./nquad_p.y"
    { dk_free_tree (ttlp_arg->ttlp_pred_uri); ttlp_arg->ttlp_pred_uri = (yyvsp[(1) - (1)].box); }
    break;

  case 31:
#line 223 "./nquad_p.y"
    { dk_free_tree (ttlp_arg->ttlp_pred_uri); ttlp_arg->ttlp_pred_uri = uname_rdf_ns_uri_type; }
    break;

  case 32:
#line 224 "./nquad_p.y"
    { dk_free_tree (ttlp_arg->ttlp_pred_uri); ttlp_arg->ttlp_pred_uri = box_dv_uname_string ("http://www.w3.org/2002/07/owl#sameAs"); }
    break;

  case 33:
#line 225 "./nquad_p.y"
    { dk_free_tree (ttlp_arg->ttlp_pred_uri); ttlp_arg->ttlp_pred_uri = box_dv_uname_string ("http://www.w3.org/2000/10/swap/log#implies"); }
    break;

  case 34:
#line 227 "./nquad_p.y"
    {
		  TTLYYERROR_ACTION_COND (TTLP_VERB_MAY_BE_BLANK, "Blank node (written as '[]') can not be used as a predicate");
		  dk_free_tree (ttlp_arg->ttlp_pred_uri); ttlp_arg->ttlp_pred_uri = tf_bnode_iid (ttlp_arg->ttlp_tf, NULL); }
    break;

  case 35:
#line 231 "./nquad_p.y"
    {
		  TTLYYERROR_ACTION_COND (TTLP_VERB_MAY_BE_BLANK, "Blank node (written as '_:...' label) can not be used as a predicate");
                  dk_free_tree (ttlp_arg->ttlp_pred_uri);
                  if (ttlp_arg->ttlp_formula_iid)
		    ttlp_arg->ttlp_pred_uri = tf_formula_bnode_iid (ttlp_arg, (yyvsp[(1) - (1)].box));
                  else
		    ttlp_arg->ttlp_pred_uri = tf_bnode_iid (ttlp_arg->ttlp_tf, (yyvsp[(1) - (1)].box));
		}
    break;

  case 36:
#line 239 "./nquad_p.y"
    { ttlp_arg->ttlp_pred_is_reverse = 1; dk_free_tree (ttlp_arg->ttlp_pred_uri); ttlp_arg->ttlp_pred_uri = ttlp_arg->ttlp_last_complete_uri; ttlp_arg->ttlp_last_complete_uri = NULL; }
    break;

  case 37:
#line 240 "./nquad_p.y"
    { ttlp_arg->ttlp_pred_is_reverse = 1; dk_free_tree (ttlp_arg->ttlp_pred_uri); ttlp_arg->ttlp_pred_uri = (yyvsp[(2) - (3)].box); }
    break;

  case 38:
#line 241 "./nquad_p.y"
    { ttlp_arg->ttlp_pred_is_reverse = 1; dk_free_tree (ttlp_arg->ttlp_pred_uri); ttlp_arg->ttlp_pred_uri = box_dv_uname_string ("http://www.w3.org/2000/10/swap/log#implies"); /* Note this 'double reversed' meaning :) */ }
    break;

  case 46:
#line 252 "./nquad_p.y"
    {
			dk_free_tree (ttlp_arg->ttlp_last_complete_uri);
			ttlp_arg->ttlp_last_complete_uri = NULL; }
    break;

  case 47:
#line 258 "./nquad_p.y"
    {
		dk_free_tree (ttlp_arg->ttlp_obj);
		ttlp_arg->ttlp_obj = ttlp_arg->ttlp_last_complete_uri;
		ttlp_arg->ttlp_last_complete_uri = NULL; }
    break;

  case 48:
#line 262 "./nquad_p.y"
    {
		ttlp_triple_and_inf (ttlp_arg, ttlp_arg->ttlp_obj); }
    break;

  case 49:
#line 264 "./nquad_p.y"
    {
		dk_free_tree (ttlp_arg->ttlp_obj);
		ttlp_arg->ttlp_obj = (yyvsp[(1) - (1)].box); }
    break;

  case 50:
#line 267 "./nquad_p.y"
    {
		ttlp_triple_and_inf (ttlp_arg, (yyvsp[(1) - (3)].box)); }
    break;

  case 51:
#line 269 "./nquad_p.y"
    {
		dk_free_tree (ttlp_arg->ttlp_obj);
		ttlp_arg->ttlp_obj = (yyvsp[(1) - (1)].box); }
    break;

  case 52:
#line 272 "./nquad_p.y"
    {
		ttlp_triple_and_inf (ttlp_arg, (yyvsp[(1) - (3)].box)); }
    break;

  case 53:
#line 274 "./nquad_p.y"
    {
		ttlp_triple_l_and_inf (ttlp_arg, (caddr_t)((ptrlong)1), uname_xmlschema_ns_uri_hash_boolean, NULL); }
    break;

  case 54:
#line 276 "./nquad_p.y"
    {
		ttlp_triple_l_and_inf (ttlp_arg, (caddr_t)((ptrlong)0), uname_xmlschema_ns_uri_hash_boolean, NULL); }
    break;

  case 55:
#line 278 "./nquad_p.y"
    {
		dk_free_tree (ttlp_arg->ttlp_obj);
		ttlp_arg->ttlp_obj = (yyvsp[(1) - (2)].box);
		ttlp_triple_l_and_inf (ttlp_arg, (yyvsp[(1) - (2)].box), uname_xmlschema_ns_uri_hash_integer, NULL); }
    break;

  case 56:
#line 282 "./nquad_p.y"
    {
		dk_free_tree (ttlp_arg->ttlp_obj);
		ttlp_arg->ttlp_obj = (yyvsp[(1) - (2)].box);
		ttlp_triple_l_and_inf (ttlp_arg, (yyvsp[(1) - (2)].box), uname_xmlschema_ns_uri_hash_decimal, NULL); }
    break;

  case 57:
#line 286 "./nquad_p.y"
    {
		dk_free_tree (ttlp_arg->ttlp_obj);
		ttlp_arg->ttlp_obj = (yyvsp[(1) - (2)].box);
		ttlp_triple_l_and_inf (ttlp_arg, (yyvsp[(1) - (2)].box), uname_xmlschema_ns_uri_hash_double, NULL);	}
    break;

  case 58:
#line 290 "./nquad_p.y"
    {
		dk_free_tree (ttlp_arg->ttlp_obj);
		ttlp_arg->ttlp_obj = (yyvsp[(1) - (2)].box);
		ttlp_triple_l_and_inf (ttlp_arg, (yyvsp[(1) - (2)].box), NULL, NULL); }
    break;

  case 59:
#line 294 "./nquad_p.y"
    {
		dk_free_tree (ttlp_arg->ttlp_obj);
		ttlp_arg->ttlp_obj = (yyvsp[(1) - (3)].box);
		dk_free_tree (ttlp_arg->ttlp_obj_lang);
		ttlp_arg->ttlp_obj_lang = (yyvsp[(2) - (3)].box);
		ttlp_triple_l_and_inf (ttlp_arg, (yyvsp[(1) - (3)].box), NULL, (yyvsp[(2) - (3)].box));	}
    break;

  case 60:
#line 300 "./nquad_p.y"
    {
		dk_free_tree (ttlp_arg->ttlp_obj);
		ttlp_arg->ttlp_obj = (yyvsp[(1) - (3)].box);
		dk_free_tree (ttlp_arg->ttlp_obj_type);
		ttlp_arg->ttlp_obj_type = ttlp_arg->ttlp_last_complete_uri;
		ttlp_arg->ttlp_last_complete_uri = NULL; }
    break;

  case 61:
#line 306 "./nquad_p.y"
    {
		ttlp_triple_l_and_inf (ttlp_arg, ttlp_arg->ttlp_obj, ttlp_arg->ttlp_obj_type, NULL);	}
    break;

  case 62:
#line 308 "./nquad_p.y"
    { }
    break;

  case 63:
#line 309 "./nquad_p.y"
    {
		dk_free_tree (ttlp_arg->ttlp_obj);
		ttlp_arg->ttlp_obj = (yyvsp[(1) - (4)].box); }
    break;

  case 64:
#line 312 "./nquad_p.y"
    {
		dk_free_tree (ttlp_arg->ttlp_last_complete_uri);
		ttlp_arg->ttlp_last_complete_uri = NULL; }
    break;

  case 65:
#line 315 "./nquad_p.y"
    { }
    break;

  case 66:
#line 316 "./nquad_p.y"
    { }
    break;

  case 67:
#line 320 "./nquad_p.y"
    {
		triple_feed_t *tf = ttlp_arg->ttlp_tf;
		if ((NULL == tf->tf_current_graph_uri) || strcmp (tf->tf_current_graph_uri, tf->tf_default_graph_uri))
		  TF_CHANGE_GRAPH_TO_DEFAULT (tf);
		  }
    break;

  case 68:
#line 325 "./nquad_p.y"
    {
		triple_feed_t *tf = ttlp_arg->ttlp_tf;
		if ((NULL == tf->tf_current_graph_uri) || strcmp (tf->tf_current_graph_uri, ttlp_arg->ttlp_last_complete_uri))
		  TF_CHANGE_GRAPH (tf, ttlp_arg->ttlp_last_complete_uri);
                else {
		    dk_free_tree (ttlp_arg->ttlp_last_complete_uri);
		    ttlp_arg->ttlp_last_complete_uri = NULL; } }
    break;

  case 69:
#line 332 "./nquad_p.y"
    { }
    break;

  case 70:
#line 333 "./nquad_p.y"
    { }
    break;

  case 71:
#line 339 "./nquad_p.y"
    {
                  if (ttlp_arg->ttlp_formula_iid)
		    (yyval.box) = tf_formula_bnode_iid (ttlp_arg, (yyvsp[(1) - (1)].box));
                  else
		    (yyval.box) = tf_bnode_iid (ttlp_arg->ttlp_tf, (yyvsp[(1) - (1)].box));
		}
    break;

  case 72:
#line 345 "./nquad_p.y"
    { (yyval.box) = tf_bnode_iid (ttlp_arg->ttlp_tf, NULL); }
    break;

  case 73:
#line 350 "./nquad_p.y"
    {
                  if (NULL != ttlp_arg->ttlp_last_complete_uri)
		    ttlyyerror_action ("Internal error: proven memory leak");
		  ttlp_arg->ttlp_last_complete_uri = (yyvsp[(1) - (1)].box);
		  TTLP_URI_RESOLVE_IF_NEEDED(ttlp_arg->ttlp_last_complete_uri);
		 }
    break;

  case 74:
#line 357 "./nquad_p.y"
    {
                  if (NULL != ttlp_arg->ttlp_last_complete_uri)
		    ttlyyerror_action ("Internal error: proven memory leak");
		  ttlp_arg->ttlp_last_complete_uri = (yyvsp[(1) - (1)].box);
		  ttlp_arg->ttlp_last_complete_uri = ttlp_expand_qname_prefix (ttlp_arg, ttlp_arg->ttlp_last_complete_uri);
		  TTLP_URI_RESOLVE_IF_NEEDED(ttlp_arg->ttlp_last_complete_uri);
		}
    break;

  case 75:
#line 365 "./nquad_p.y"
    {
                  if (NULL != ttlp_arg->ttlp_last_complete_uri)
		    ttlyyerror_action ("Internal error: proven memory leak");
		  ttlp_arg->ttlp_last_complete_uri = (yyvsp[(1) - (1)].box);
		  ttlp_arg->ttlp_last_complete_uri = ttlp_expand_qname_prefix (ttlp_arg, ttlp_arg->ttlp_last_complete_uri);
		  TTLP_URI_RESOLVE_IF_NEEDED(ttlp_arg->ttlp_last_complete_uri);
		}
    break;


/* Line 1267 of yacc.c.  */
#line 1990 "nquad_p.c"
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
      yyerror (ttlp_arg, yyscanner, YY_("syntax error"));
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
	    yyerror (ttlp_arg, yyscanner, yymsg);
	  }
	else
	  {
	    yyerror (ttlp_arg, yyscanner, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, ttlp_arg, yyscanner);
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
		  yystos[yystate], yyvsp, ttlp_arg, yyscanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (ttlp_arg, yyscanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, ttlp_arg, yyscanner);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, ttlp_arg, yyscanner);
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


