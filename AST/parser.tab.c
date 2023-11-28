/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "parser.y"

    int yylex(void);
    void yyerror (char const *mensagem);
    extern void *arvore;

#line 77 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_UMINUS = 3,                     /* UMINUS  */
  YYSYMBOL_TK_PR_INT = 4,                  /* TK_PR_INT  */
  YYSYMBOL_TK_PR_FLOAT = 5,                /* TK_PR_FLOAT  */
  YYSYMBOL_TK_PR_BOOL = 6,                 /* TK_PR_BOOL  */
  YYSYMBOL_TK_PR_IF = 7,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_ELSE = 8,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 9,                /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_RETURN = 10,              /* TK_PR_RETURN  */
  YYSYMBOL_TK_OC_LE = 11,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 12,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 13,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 14,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 15,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 16,                  /* TK_OC_OR  */
  YYSYMBOL_TK_IDENTIFICADOR = 17,          /* TK_IDENTIFICADOR  */
  YYSYMBOL_TK_LIT_INT = 18,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 19,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_FALSE = 20,              /* TK_LIT_FALSE  */
  YYSYMBOL_TK_LIT_TRUE = 21,               /* TK_LIT_TRUE  */
  YYSYMBOL_TK_ERRO = 22,                   /* TK_ERRO  */
  YYSYMBOL_23_ = 23,                       /* ';'  */
  YYSYMBOL_24_ = 24,                       /* ','  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* '!'  */
  YYSYMBOL_28_ = 28,                       /* '{'  */
  YYSYMBOL_29_ = 29,                       /* '}'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_program = 39,                   /* program  */
  YYSYMBOL_element = 40,                   /* element  */
  YYSYMBOL_global_declaration = 41,        /* global_declaration  */
  YYSYMBOL_type = 42,                      /* type  */
  YYSYMBOL_list_vars = 43,                 /* list_vars  */
  YYSYMBOL_function = 44,                  /* function  */
  YYSYMBOL_header = 45,                    /* header  */
  YYSYMBOL_function_name = 46,             /* function_name  */
  YYSYMBOL_param_list = 47,                /* param_list  */
  YYSYMBOL_param = 48,                     /* param  */
  YYSYMBOL_body = 49,                      /* body  */
  YYSYMBOL_command_list = 50,              /* command_list  */
  YYSYMBOL_command = 51,                   /* command  */
  YYSYMBOL_open_block = 52,                /* open_block  */
  YYSYMBOL_local_var_dec = 53,             /* local_var_dec  */
  YYSYMBOL_attrib = 54,                    /* attrib  */
  YYSYMBOL_function_call = 55,             /* function_call  */
  YYSYMBOL_arg_list = 56,                  /* arg_list  */
  YYSYMBOL_arg = 57,                       /* arg  */
  YYSYMBOL_return = 58,                    /* return  */
  YYSYMBOL_conditional = 59,               /* conditional  */
  YYSYMBOL_while = 60,                     /* while  */
  YYSYMBOL_expr = 61,                      /* expr  */
  YYSYMBOL_logical_or_expr = 62,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 63,          /* logical_and_expr  */
  YYSYMBOL_equality_expr = 64,             /* equality_expr  */
  YYSYMBOL_relational_expr = 65,           /* relational_expr  */
  YYSYMBOL_add_sub_expr = 66,              /* add_sub_expr  */
  YYSYMBOL_mult_div_mod_expr = 67,         /* mult_div_mod_expr  */
  YYSYMBOL_unary_expr = 68,                /* unary_expr  */
  YYSYMBOL_primary_expr = 69               /* primary_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,     2,     2,    37,     2,     2,
      25,    26,    35,    33,    24,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
      31,    30,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    63,    71,    72,    74,    76,    77,    78,
      80,    81,    83,    85,    86,    88,    90,    91,    93,    95,
      96,    98,    99,   120,   121,   122,   123,   124,   125,   126,
     128,   129,   132,   134,   136,   145,   154,   155,   157,   159,
     161,   162,   164,   166,   168,   169,   171,   172,   174,   175,
     176,   178,   179,   180,   181,   182,   184,   185,   186,   188,
     189,   190,   191,   193,   194,   195,   197,   198,   199,   200,
     201,   202,   203
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "UMINUS", "TK_PR_INT",
  "TK_PR_FLOAT", "TK_PR_BOOL", "TK_PR_IF", "TK_PR_ELSE", "TK_PR_WHILE",
  "TK_PR_RETURN", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE",
  "TK_OC_AND", "TK_OC_OR", "TK_IDENTIFICADOR", "TK_LIT_INT",
  "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE", "TK_ERRO", "';'", "','",
  "'('", "')'", "'!'", "'{'", "'}'", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "$accept", "program", "element",
  "global_declaration", "type", "list_vars", "function", "header",
  "function_name", "param_list", "param", "body", "command_list",
  "command", "open_block", "local_var_dec", "attrib", "function_call",
  "arg_list", "arg", "return", "conditional", "while", "expr",
  "logical_or_expr", "logical_and_expr", "equality_expr",
  "relational_expr", "add_sub_expr", "mult_div_mod_expr", "unary_expr",
  "primary_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -105,    34,  -105,  -105,  -105,  -105,    26,  -105,  -105,    -8,
    -105,   -10,    10,    12,    71,  -105,  -105,    61,     7,  -105,
      65,  -105,    65,    25,  -105,    24,    21,    30,    73,    -5,
      44,  -105,    -8,    29,    58,  -105,    37,    43,    51,    55,
      76,    85,    87,  -105,    65,  -105,    73,    73,    94,  -105,
    -105,  -105,  -105,    73,    73,    73,  -105,  -105,   104,   106,
      92,    45,    79,    74,  -105,  -105,    62,    73,    99,    95,
     101,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   109,
      96,   102,   103,   105,  -105,  -105,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,  -105,
     107,   108,  -105,  -105,  -105,   111,  -105,   110,   -10,   -10,
    -105,   106,    92,    45,    45,    79,    79,    79,    79,    74,
      74,  -105,  -105,  -105,  -105,    73,  -105,  -105,  -105,   122,
    -105,  -105,   -10,  -105
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     7,     8,     9,     0,     3,     5,     0,
       4,     0,     0,     0,     0,    16,    10,     0,     0,    12,
       0,    18,     0,     0,     6,     0,     0,     0,     0,     0,
       0,    19,     0,     0,    21,    29,     0,     0,     0,     0,
       0,     0,     0,    17,     0,    11,     0,     0,    66,    67,
      68,    70,    69,     0,     0,     0,    71,    39,    43,    44,
      46,    48,    51,    56,    59,    63,     0,     0,     0,     0,
      32,    20,    22,    23,    24,    28,    27,    25,    26,     0,
       0,     0,     0,     0,    65,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,    36,    38,    33,    30,     0,    14,     0,     0,     0,
      72,    45,    47,    49,    50,    54,    55,    52,    53,    57,
      58,    60,    61,    62,    34,     0,    31,    15,    13,    40,
      42,    37,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -105,  -105,  -105,  -105,     1,   112,  -105,  -105,  -105,  -105,
     113,  -104,   -24,  -105,  -105,  -105,  -105,   -15,    13,  -105,
    -105,  -105,  -105,   -20,  -105,    50,    52,    27,    11,    23,
     -54,  -105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,     8,    32,    17,    10,    11,   128,    14,
      15,    19,    33,    34,    35,    36,    37,    56,   100,   101,
      39,    40,    41,   102,    58,    59,    60,    61,    62,    63,
      64,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      84,    85,     9,    38,   129,   130,    69,    13,    57,    16,
      72,     3,     4,     5,    26,    38,    27,    28,    18,    38,
      66,    42,    20,    13,    29,    67,    81,    82,   133,    21,
       3,     4,     5,    83,     2,    30,    31,    44,     3,     4,
       5,    45,   121,   122,   123,    80,    46,   103,     3,     4,
       5,    26,    12,    27,    28,    47,    90,    91,    71,     6,
      73,    29,     3,     4,     5,    26,    74,    27,    28,     3,
       4,     5,    30,    68,    75,    29,    92,    93,    76,    48,
      49,    50,    51,    52,    24,    25,    30,    53,    99,    54,
      48,    49,    50,    51,    52,    22,    55,    23,    53,    77,
      54,   115,   116,   117,   118,    88,    89,    55,    78,    96,
      97,    98,    94,    95,    79,   113,   114,   119,   120,    66,
      86,    87,   104,   107,   105,    25,   106,   127,   108,   109,
     132,   110,   125,   124,   126,    43,   111,     0,   131,   112,
       0,     0,     0,     0,    70
};

static const yytype_int16 yycheck[] =
{
      54,    55,     1,    18,   108,   109,    30,     6,    28,    17,
      34,     4,     5,     6,     7,    30,     9,    10,    28,    34,
      25,    20,    12,    22,    17,    30,    46,    47,   132,    17,
       4,     5,     6,    53,     0,    28,    29,    12,     4,     5,
       6,    17,    96,    97,    98,    44,    25,    67,     4,     5,
       6,     7,    26,     9,    10,    25,    11,    12,    29,    25,
      23,    17,     4,     5,     6,     7,    23,     9,    10,     4,
       5,     6,    28,    29,    23,    17,    31,    32,    23,    17,
      18,    19,    20,    21,    23,    24,    28,    25,    26,    27,
      17,    18,    19,    20,    21,    24,    34,    26,    25,    23,
      27,    90,    91,    92,    93,    13,    14,    34,    23,    35,
      36,    37,    33,    34,    27,    88,    89,    94,    95,    25,
      16,    15,    23,    27,    29,    24,    17,    17,    26,    26,
       8,    26,    24,    26,    23,    22,    86,    -1,   125,    87,
      -1,    -1,    -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,     0,     4,     5,     6,    25,    40,    41,    42,
      44,    45,    26,    42,    47,    48,    17,    43,    28,    49,
      12,    17,    24,    26,    23,    24,     7,     9,    10,    17,
      28,    29,    42,    50,    51,    52,    53,    54,    55,    58,
      59,    60,    42,    48,    12,    17,    25,    25,    17,    18,
      19,    20,    21,    25,    27,    34,    55,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    25,    30,    29,    50,
      43,    29,    50,    23,    23,    23,    23,    23,    23,    27,
      42,    61,    61,    61,    68,    68,    16,    15,    13,    14,
      11,    12,    31,    32,    33,    34,    35,    36,    37,    26,
      56,    57,    61,    61,    23,    29,    17,    27,    26,    26,
      26,    63,    64,    65,    65,    66,    66,    66,    66,    67,
      67,    68,    68,    68,    26,    24,    23,    17,    46,    49,
      49,    56,     8,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    41,    42,    42,    42,
      43,    43,    44,    45,    45,    46,    47,    47,    48,    49,
      49,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      52,    52,    53,    54,    55,    55,    56,    56,    57,    58,
      59,    59,    60,    61,    62,    62,    63,    63,    64,    64,
      64,    65,    65,    65,    65,    65,    66,    66,    66,    67,
      67,    67,    67,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     3,     1,     1,     1,
       1,     3,     2,     7,     6,     1,     1,     3,     2,     2,
       3,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       3,     4,     2,     3,     4,     3,     1,     3,     1,     2,
       5,     7,     5,     1,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: %empty  */
#line 62 "parser.y"
                     { (yyval.tree) = NULL;  }
#line 1497 "parser.tab.c"
    break;

  case 3: /* program: program element  */
#line 63 "parser.y"
                      { if((yyvsp[-1].tree) != NULL) {
                            (yyval.tree) = (yyvsp[-1].tree); 
                            asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                        } else {
                            (yyval.tree) = (yyvsp[0].tree);
                        } 
                        arvore = (yyval.tree); }
#line 1509 "parser.tab.c"
    break;

  case 4: /* element: function  */
#line 71 "parser.y"
                  { (yyval.tree) = (yyvsp[0].tree); }
#line 1515 "parser.tab.c"
    break;

  case 5: /* element: global_declaration  */
#line 72 "parser.y"
                         { (yyval.tree) = (yyvsp[0].tree); }
#line 1521 "parser.tab.c"
    break;

  case 6: /* global_declaration: type list_vars ';'  */
#line 74 "parser.y"
                                       { (yyval.tree) = (yyvsp[-1].tree); }
#line 1527 "parser.tab.c"
    break;

  case 7: /* type: TK_PR_INT  */
#line 76 "parser.y"
                {  }
#line 1533 "parser.tab.c"
    break;

  case 8: /* type: TK_PR_FLOAT  */
#line 77 "parser.y"
                  {  }
#line 1539 "parser.tab.c"
    break;

  case 9: /* type: TK_PR_BOOL  */
#line 78 "parser.y"
                 {  }
#line 1545 "parser.tab.c"
    break;

  case 10: /* list_vars: TK_IDENTIFICADOR  */
#line 80 "parser.y"
                            { (yyval.tree) = NULL; free((yyvsp[0].lexical_value).token_value);}
#line 1551 "parser.tab.c"
    break;

  case 11: /* list_vars: list_vars ',' TK_IDENTIFICADOR  */
#line 81 "parser.y"
                                         { (yyval.tree) = (yyvsp[-2].tree); free((yyvsp[0].lexical_value).token_value);}
#line 1557 "parser.tab.c"
    break;

  case 12: /* function: header body  */
#line 83 "parser.y"
                      { (yyval.tree) = (yyvsp[-1].tree); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1563 "parser.tab.c"
    break;

  case 13: /* header: '(' param_list ')' TK_OC_GE type '!' function_name  */
#line 85 "parser.y"
                                                           { (yyval.tree) = (yyvsp[0].tree); }
#line 1569 "parser.tab.c"
    break;

  case 14: /* header: '(' ')' TK_OC_GE type '!' TK_IDENTIFICADOR  */
#line 86 "parser.y"
                                                    { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); free((yyvsp[0].lexical_value).token_value); }
#line 1575 "parser.tab.c"
    break;

  case 15: /* function_name: TK_IDENTIFICADOR  */
#line 88 "parser.y"
                                { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); free((yyvsp[0].lexical_value).token_value); }
#line 1581 "parser.tab.c"
    break;

  case 16: /* param_list: param  */
#line 90 "parser.y"
                  {  }
#line 1587 "parser.tab.c"
    break;

  case 17: /* param_list: param_list ',' param  */
#line 91 "parser.y"
                                  {  }
#line 1593 "parser.tab.c"
    break;

  case 18: /* param: type TK_IDENTIFICADOR  */
#line 93 "parser.y"
                             { free((yyvsp[0].lexical_value).token_value); }
#line 1599 "parser.tab.c"
    break;

  case 19: /* body: '{' '}'  */
#line 95 "parser.y"
              { (yyval.tree) = NULL; }
#line 1605 "parser.tab.c"
    break;

  case 20: /* body: '{' command_list '}'  */
#line 96 "parser.y"
                           { (yyval.tree) = (yyvsp[-1].tree); }
#line 1611 "parser.tab.c"
    break;

  case 21: /* command_list: command  */
#line 98 "parser.y"
                      { (yyval.tree) = (yyvsp[0].tree); }
#line 1617 "parser.tab.c"
    break;

  case 22: /* command_list: command command_list  */
#line 99 "parser.y"
                                   {if ((yyvsp[-1].tree) == NULL){
                    (yyval.tree) = (yyvsp[0].tree);
                }
                else {
                    (yyval.tree) = (yyvsp[-1].tree);
                    while ((yyval.tree)->next!=NULL) {
                        (yyval.tree) = (yyval.tree)->next;
                    }
                    // percorre lista de comandos chamados
                    // quando não tem outro comando encadeado
                    // só adiciona o próximo como filho
                    asd_add_child((yyval.tree), (yyvsp[0].tree));
                    // aponta como próximo o segundo comando da produção
                    (yyval.tree)->next=(yyvsp[0].tree);
                    // retorna ao começo da lista de comandos
                    // pra não perder a referência do bloco da função principal
                    (yyval.tree) = (yyvsp[-1].tree);
                };}
#line 1640 "parser.tab.c"
    break;

  case 23: /* command: local_var_dec ';'  */
#line 120 "parser.y"
                           { (yyval.tree) = (yyvsp[-1].tree); }
#line 1646 "parser.tab.c"
    break;

  case 24: /* command: attrib ';'  */
#line 121 "parser.y"
                    { (yyval.tree) = (yyvsp[-1].tree); }
#line 1652 "parser.tab.c"
    break;

  case 25: /* command: conditional ';'  */
#line 122 "parser.y"
                         { (yyval.tree) = (yyvsp[-1].tree); }
#line 1658 "parser.tab.c"
    break;

  case 26: /* command: while ';'  */
#line 123 "parser.y"
                   { (yyval.tree) = (yyvsp[-1].tree); }
#line 1664 "parser.tab.c"
    break;

  case 27: /* command: return ';'  */
#line 124 "parser.y"
                    { (yyval.tree) = (yyvsp[-1].tree); }
#line 1670 "parser.tab.c"
    break;

  case 28: /* command: function_call ';'  */
#line 125 "parser.y"
                           { (yyval.tree) = (yyvsp[-1].tree); }
#line 1676 "parser.tab.c"
    break;

  case 29: /* command: open_block  */
#line 126 "parser.y"
                    { (yyval.tree) = (yyvsp[0].tree); }
#line 1682 "parser.tab.c"
    break;

  case 30: /* open_block: '{' '}' ';'  */
#line 128 "parser.y"
                      { (yyval.tree) = NULL; }
#line 1688 "parser.tab.c"
    break;

  case 31: /* open_block: '{' command_list '}' ';'  */
#line 129 "parser.y"
                                    { (yyval.tree) = (yyvsp[-2].tree); }
#line 1694 "parser.tab.c"
    break;

  case 32: /* local_var_dec: type list_vars  */
#line 132 "parser.y"
                              { (yyval.tree) = (yyvsp[0].tree); }
#line 1700 "parser.tab.c"
    break;

  case 33: /* attrib: TK_IDENTIFICADOR '=' expr  */
#line 134 "parser.y"
                                  { (yyval.tree) = asd_new("="); asd_add_child((yyval.tree), asd_new((yyvsp[-2].lexical_value).token_value)); asd_add_child((yyval.tree), (yyvsp[0].tree)); free((yyvsp[-2].lexical_value).token_value);}
#line 1706 "parser.tab.c"
    break;

  case 34: /* function_call: TK_IDENTIFICADOR '(' arg_list ')'  */
#line 136 "parser.y"
                                                 { 
                    char *buffer = malloc((strlen("call ") + strlen((yyvsp[-3].lexical_value).token_value) + 1)* sizeof(char));
                    strcpy(buffer, "call ");
                    strcat(buffer, (yyvsp[-3].lexical_value).token_value);
                    (yyval.tree) = asd_new(buffer);
                    asd_add_child((yyval.tree), (yyvsp[-1].tree));
                    free(buffer);
                    free((yyvsp[-3].lexical_value).token_value);
                    }
#line 1720 "parser.tab.c"
    break;

  case 35: /* function_call: TK_IDENTIFICADOR '(' ')'  */
#line 145 "parser.y"
                               { 
                        char *buffer = malloc((strlen("call ") + strlen((yyvsp[-2].lexical_value).token_value) + 1)* sizeof(char));
                        strcpy(buffer, "call ");
                        strcat(buffer, (yyvsp[-2].lexical_value).token_value);
                        (yyval.tree) = asd_new(buffer);
                        free(buffer);
                        free((yyvsp[-2].lexical_value).token_value);
                    }
#line 1733 "parser.tab.c"
    break;

  case 36: /* arg_list: arg  */
#line 154 "parser.y"
              { (yyval.tree) = (yyvsp[0].tree); }
#line 1739 "parser.tab.c"
    break;

  case 37: /* arg_list: arg ',' arg_list  */
#line 155 "parser.y"
                       { (yyval.tree) = (yyvsp[-2].tree); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1745 "parser.tab.c"
    break;

  case 38: /* arg: expr  */
#line 157 "parser.y"
          { (yyval.tree) = (yyvsp[0].tree); }
#line 1751 "parser.tab.c"
    break;

  case 39: /* return: TK_PR_RETURN expr  */
#line 159 "parser.y"
                          { (yyval.tree) = asd_new("return"); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1757 "parser.tab.c"
    break;

  case 40: /* conditional: TK_PR_IF '(' expr ')' body  */
#line 161 "parser.y"
                                        { (yyval.tree) = asd_new("if"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1763 "parser.tab.c"
    break;

  case 41: /* conditional: TK_PR_IF '(' expr ')' body TK_PR_ELSE body  */
#line 162 "parser.y"
                                                          { (yyval.tree) = asd_new("if"); asd_add_child((yyval.tree), (yyvsp[-4].tree)); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1769 "parser.tab.c"
    break;

  case 42: /* while: TK_PR_WHILE '(' expr ')' body  */
#line 164 "parser.y"
                                     { (yyval.tree) = asd_new("while"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1775 "parser.tab.c"
    break;

  case 43: /* expr: logical_or_expr  */
#line 166 "parser.y"
                      { (yyval.tree) = (yyvsp[0].tree); }
#line 1781 "parser.tab.c"
    break;

  case 44: /* logical_or_expr: logical_and_expr  */
#line 168 "parser.y"
                                  { (yyval.tree) = (yyvsp[0].tree); }
#line 1787 "parser.tab.c"
    break;

  case 45: /* logical_or_expr: logical_or_expr TK_OC_OR logical_and_expr  */
#line 169 "parser.y"
                                                {(yyval.tree) = asd_new("||"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1793 "parser.tab.c"
    break;

  case 46: /* logical_and_expr: equality_expr  */
#line 171 "parser.y"
                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1799 "parser.tab.c"
    break;

  case 47: /* logical_and_expr: logical_and_expr TK_OC_AND equality_expr  */
#line 172 "parser.y"
                                               { (yyval.tree) = asd_new("&&"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1805 "parser.tab.c"
    break;

  case 48: /* equality_expr: relational_expr  */
#line 174 "parser.y"
                               { (yyval.tree) = (yyvsp[0].tree); }
#line 1811 "parser.tab.c"
    break;

  case 49: /* equality_expr: equality_expr TK_OC_EQ relational_expr  */
#line 175 "parser.y"
                                             { (yyval.tree) = asd_new("=="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1817 "parser.tab.c"
    break;

  case 50: /* equality_expr: equality_expr TK_OC_NE relational_expr  */
#line 176 "parser.y"
                                             { (yyval.tree) = asd_new("!="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1823 "parser.tab.c"
    break;

  case 51: /* relational_expr: add_sub_expr  */
#line 178 "parser.y"
                              { (yyval.tree) = (yyvsp[0].tree); }
#line 1829 "parser.tab.c"
    break;

  case 52: /* relational_expr: relational_expr '<' add_sub_expr  */
#line 179 "parser.y"
                                       { (yyval.tree) = asd_new("<"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1835 "parser.tab.c"
    break;

  case 53: /* relational_expr: relational_expr '>' add_sub_expr  */
#line 180 "parser.y"
                                       { (yyval.tree) = asd_new(">"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1841 "parser.tab.c"
    break;

  case 54: /* relational_expr: relational_expr TK_OC_LE add_sub_expr  */
#line 181 "parser.y"
                                            { (yyval.tree) = asd_new("<="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1847 "parser.tab.c"
    break;

  case 55: /* relational_expr: relational_expr TK_OC_GE add_sub_expr  */
#line 182 "parser.y"
                                            { (yyval.tree) = asd_new(">="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1853 "parser.tab.c"
    break;

  case 56: /* add_sub_expr: mult_div_mod_expr  */
#line 184 "parser.y"
                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1859 "parser.tab.c"
    break;

  case 57: /* add_sub_expr: add_sub_expr '+' mult_div_mod_expr  */
#line 185 "parser.y"
                                         { (yyval.tree) = asd_new("+"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1865 "parser.tab.c"
    break;

  case 58: /* add_sub_expr: add_sub_expr '-' mult_div_mod_expr  */
#line 186 "parser.y"
                                         { (yyval.tree) = asd_new("-"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1871 "parser.tab.c"
    break;

  case 59: /* mult_div_mod_expr: unary_expr  */
#line 188 "parser.y"
                              { (yyval.tree) = (yyvsp[0].tree); }
#line 1877 "parser.tab.c"
    break;

  case 60: /* mult_div_mod_expr: mult_div_mod_expr '*' unary_expr  */
#line 189 "parser.y"
                                       { (yyval.tree) = asd_new("*"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1883 "parser.tab.c"
    break;

  case 61: /* mult_div_mod_expr: mult_div_mod_expr '/' unary_expr  */
#line 190 "parser.y"
                                       { (yyval.tree) = asd_new("/"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1889 "parser.tab.c"
    break;

  case 62: /* mult_div_mod_expr: mult_div_mod_expr '%' unary_expr  */
#line 191 "parser.y"
                                       { (yyval.tree) = asd_new("%"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1895 "parser.tab.c"
    break;

  case 63: /* unary_expr: primary_expr  */
#line 193 "parser.y"
                         { (yyval.tree) = (yyvsp[0].tree); }
#line 1901 "parser.tab.c"
    break;

  case 64: /* unary_expr: '-' unary_expr  */
#line 194 "parser.y"
                                        { (yyval.tree) = asd_new("-"); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1907 "parser.tab.c"
    break;

  case 65: /* unary_expr: '!' unary_expr  */
#line 195 "parser.y"
                           { (yyval.tree) = asd_new("!"); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1913 "parser.tab.c"
    break;

  case 66: /* primary_expr: TK_IDENTIFICADOR  */
#line 197 "parser.y"
                               { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); free((yyvsp[0].lexical_value).token_value); }
#line 1919 "parser.tab.c"
    break;

  case 67: /* primary_expr: TK_LIT_INT  */
#line 198 "parser.y"
                 { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); free((yyvsp[0].lexical_value).token_value);}
#line 1925 "parser.tab.c"
    break;

  case 68: /* primary_expr: TK_LIT_FLOAT  */
#line 199 "parser.y"
                   { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); free((yyvsp[0].lexical_value).token_value);}
#line 1931 "parser.tab.c"
    break;

  case 69: /* primary_expr: TK_LIT_TRUE  */
#line 200 "parser.y"
                  { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); free((yyvsp[0].lexical_value).token_value);}
#line 1937 "parser.tab.c"
    break;

  case 70: /* primary_expr: TK_LIT_FALSE  */
#line 201 "parser.y"
                   { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); free((yyvsp[0].lexical_value).token_value);}
#line 1943 "parser.tab.c"
    break;

  case 71: /* primary_expr: function_call  */
#line 202 "parser.y"
                    { (yyval.tree) = (yyvsp[0].tree); }
#line 1949 "parser.tab.c"
    break;

  case 72: /* primary_expr: '(' expr ')'  */
#line 203 "parser.y"
                   { (yyval.tree) = (yyvsp[-1].tree); }
#line 1955 "parser.tab.c"
    break;


#line 1959 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 205 "parser.y"
