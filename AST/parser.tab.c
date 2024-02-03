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

/* "%code top" blocks.  */
#line 6 "parser.y"
 #include "symbol_table.h"
            #include <stdlib.h> 

#line 72 "parser.tab.c"



/* First part of user prologue.  */
#line 10 "parser.y"

    int yylex(void);
    void yyerror (char const *mensagem);
    extern void *arvore;
    extern TableStack stack; 
    char *varList[100] = {NULL};
    int lineList[100] = {-1};

#line 86 "parser.tab.c"

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
  YYSYMBOL_init = 40,                      /* init  */
  YYSYMBOL_push_scope = 41,                /* push_scope  */
  YYSYMBOL_pop_scope = 42,                 /* pop_scope  */
  YYSYMBOL_element = 43,                   /* element  */
  YYSYMBOL_global_declaration = 44,        /* global_declaration  */
  YYSYMBOL_type = 45,                      /* type  */
  YYSYMBOL_list_vars = 46,                 /* list_vars  */
  YYSYMBOL_function = 47,                  /* function  */
  YYSYMBOL_header = 48,                    /* header  */
  YYSYMBOL_param_list = 49,                /* param_list  */
  YYSYMBOL_param = 50,                     /* param  */
  YYSYMBOL_no_scope_body = 51,             /* no_scope_body  */
  YYSYMBOL_command_list = 52,              /* command_list  */
  YYSYMBOL_command = 53,                   /* command  */
  YYSYMBOL_open_block = 54,                /* open_block  */
  YYSYMBOL_local_var_dec = 55,             /* local_var_dec  */
  YYSYMBOL_attrib = 56,                    /* attrib  */
  YYSYMBOL_function_call = 57,             /* function_call  */
  YYSYMBOL_arg_list = 58,                  /* arg_list  */
  YYSYMBOL_arg = 59,                       /* arg  */
  YYSYMBOL_return = 60,                    /* return  */
  YYSYMBOL_conditional = 61,               /* conditional  */
  YYSYMBOL_while = 62,                     /* while  */
  YYSYMBOL_expr = 63,                      /* expr  */
  YYSYMBOL_logical_or_expr = 64,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 65,          /* logical_and_expr  */
  YYSYMBOL_equality_expr = 66,             /* equality_expr  */
  YYSYMBOL_relational_expr = 67,           /* relational_expr  */
  YYSYMBOL_add_sub_expr = 68,              /* add_sub_expr  */
  YYSYMBOL_mult_div_mod_expr = 69,         /* mult_div_mod_expr  */
  YYSYMBOL_unary_expr = 70,                /* unary_expr  */
  YYSYMBOL_primary_expr = 71               /* primary_expr  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

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
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    72,    73,    84,    86,    88,    89,    91,
     107,   108,   109,   111,   126,   141,   145,   148,   152,   153,
     155,   158,   159,   161,   162,   177,   178,   179,   180,   181,
     182,   183,   185,   186,   189,   204,   216,   231,   247,   248,
     250,   252,   257,   263,   272,   278,   280,   281,   288,   289,
     296,   297,   304,   311,   312,   319,   326,   333,   340,   341,
     350,   357,   358,   365,   372,   377,   378,   382,   386,   403,
     411,   412,   413,   414,   415
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
  "'*'", "'/'", "'%'", "$accept", "program", "init", "push_scope",
  "pop_scope", "element", "global_declaration", "type", "list_vars",
  "function", "header", "param_list", "param", "no_scope_body",
  "command_list", "command", "open_block", "local_var_dec", "attrib",
  "function_call", "arg_list", "arg", "return", "conditional", "while",
  "expr", "logical_or_expr", "logical_and_expr", "equality_expr",
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

#define YYTABLE_NINF (-6)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -105,     6,    57,  -105,  -105,  -105,  -105,  -105,    -1,    57,
    -105,    11,  -105,  -105,    44,     2,  -105,  -105,    -5,    28,
      26,    13,  -105,    50,  -105,  -105,    41,    60,  -105,    60,
      81,    69,    70,    82,   -17,    75,  -105,    11,    77,    16,
    -105,    85,    87,    88,    89,    90,    91,  -105,  -105,    92,
    -105,    60,    82,    82,    93,  -105,  -105,  -105,  -105,    82,
      82,    82,  -105,  -105,    99,   102,    55,     4,    47,    40,
    -105,  -105,    71,    82,    97,    16,    98,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,   104,    96,   100,   101,   103,
    -105,  -105,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,  -105,   105,   106,  -105,  -105,
    -105,  -105,  -105,   107,     2,     2,  -105,   102,    55,     4,
       4,    47,    47,    47,    47,    40,    40,  -105,  -105,  -105,
    -105,    82,   108,  -105,   117,  -105,  -105,   109,     2,  -105,
    -105
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     3,     1,    10,    11,    12,     6,     0,     3,
       8,     0,     7,     2,     0,     0,     4,    13,     0,     0,
       0,     0,    18,     0,     6,     9,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     5,    21,     0,     0,    23,
      31,     0,     0,     0,     0,     0,     0,    15,    14,     0,
      19,     0,     0,     0,    68,    69,    70,    72,    71,     0,
       0,     0,    73,    41,    45,    46,    48,    50,    53,    58,
      61,    65,     0,     0,     0,     0,    34,    22,    24,    25,
      26,    30,    29,    27,    28,     0,     0,     0,     0,     0,
      67,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    38,    40,    35,
      32,     6,    17,     0,     0,     0,    74,    47,    49,    51,
      52,    56,    57,    54,    55,    59,    60,    62,    63,    64,
      36,     0,     0,    16,    42,    44,    39,     0,     0,    33,
      43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -105,  -105,   119,     7,   -24,  -105,  -105,     0,   110,  -105,
    -105,  -105,   111,  -104,   -34,  -105,  -105,  -105,  -105,   -22,
       3,  -105,  -105,  -105,  -105,   -21,  -105,    43,    45,   -11,
     -25,   -15,   -57,  -105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     7,     8,    13,     9,    10,    37,    18,    12,
      15,    21,    22,    24,    38,    39,    40,    41,    42,    62,
     106,   107,    44,    45,    46,   108,    64,    65,    66,    67,
      68,    69,    70,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    43,    11,    90,    91,    78,     3,     2,    72,    11,
     134,   135,    63,    73,    20,    96,    97,    43,    25,    26,
       4,     5,     6,    31,    14,    32,    33,    49,    17,    20,
      23,    87,    88,    34,   140,    98,    99,    29,    89,    30,
      27,   111,    75,    28,    35,   127,   128,   129,     4,     5,
       6,    86,   109,    43,     4,     5,     6,    31,    48,    32,
      33,     4,     5,     6,     4,     5,     6,    34,    94,    95,
      19,   121,   122,   123,   124,   102,   103,   104,    35,    36,
     100,   101,    -5,   119,   120,   125,   126,   132,    54,    55,
      56,    57,    58,    51,    52,    53,    59,   105,    60,    54,
      55,    56,    57,    58,    74,    61,    77,    59,    79,    60,
      80,    81,    82,    83,    84,    92,    61,    93,    72,    85,
     110,   112,    26,   113,   133,   138,   114,   115,    16,   116,
     131,   130,   139,     0,   136,   117,     0,   137,   118,     0,
      50,     0,     0,     0,     0,     0,     0,    76
};

static const yytype_int16 yycheck[] =
{
      24,    23,     2,    60,    61,    39,     0,     0,    25,     9,
     114,   115,    33,    30,    14,    11,    12,    39,    23,    24,
       4,     5,     6,     7,    25,     9,    10,    27,    17,    29,
      28,    52,    53,    17,   138,    31,    32,    24,    59,    26,
      12,    75,    35,    17,    28,   102,   103,   104,     4,     5,
       6,    51,    73,    75,     4,     5,     6,     7,    17,     9,
      10,     4,     5,     6,     4,     5,     6,    17,    13,    14,
      26,    96,    97,    98,    99,    35,    36,    37,    28,    29,
      33,    34,    25,    94,    95,   100,   101,   111,    17,    18,
      19,    20,    21,    12,    25,    25,    25,    26,    27,    17,
      18,    19,    20,    21,    29,    34,    29,    25,    23,    27,
      23,    23,    23,    23,    23,    16,    34,    15,    25,    27,
      23,    17,    24,    27,    17,     8,    26,    26,     9,    26,
      24,    26,    23,    -1,   131,    92,    -1,    29,    93,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    41,     0,     4,     5,     6,    40,    41,    43,
      44,    45,    47,    42,    25,    48,    40,    17,    46,    26,
      45,    49,    50,    28,    51,    23,    24,    12,    17,    24,
      26,     7,     9,    10,    17,    28,    29,    45,    52,    53,
      54,    55,    56,    57,    60,    61,    62,    42,    17,    45,
      50,    12,    25,    25,    17,    18,    19,    20,    21,    25,
      27,    34,    57,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    25,    30,    29,    41,    46,    29,    52,    23,
      23,    23,    23,    23,    23,    27,    45,    63,    63,    63,
      70,    70,    16,    15,    13,    14,    11,    12,    31,    32,
      33,    34,    35,    36,    37,    26,    58,    59,    63,    63,
      23,    52,    17,    27,    26,    26,    26,    65,    66,    67,
      67,    68,    68,    68,    68,    69,    69,    70,    70,    70,
      26,    24,    42,    17,    51,    51,    58,    29,     8,    23,
      51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    42,    43,    43,    44,
      45,    45,    45,    46,    46,    47,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    54,    54,    55,    56,    57,    57,    58,    58,
      59,    60,    61,    61,    62,    63,    64,    64,    65,    65,
      66,    66,    66,    67,    67,    67,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    70,    70,    70,    71,    71,
      71,    71,    71,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     2,     0,     0,     1,     1,     3,
       1,     1,     1,     1,     3,     4,     7,     6,     1,     3,
       2,     2,     3,     1,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     6,     2,     3,     4,     3,     1,     3,
       1,     2,     5,     7,     5,     1,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     3
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
  case 2: /* program: push_scope init pop_scope  */
#line 68 "parser.y"
                                   {
    (yyval.tree) = (yyvsp[-1].tree);
}
#line 1513 "parser.tab.c"
    break;

  case 3: /* init: %empty  */
#line 72 "parser.y"
                  { (yyval.tree) = NULL; }
#line 1519 "parser.tab.c"
    break;

  case 4: /* init: element init  */
#line 73 "parser.y"
                    {
                        if((yyvsp[-1].tree) != NULL) {
                            (yyval.tree) = (yyvsp[-1].tree); 
                            asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                        } else {
                            (yyval.tree) = (yyvsp[0].tree);
                        } 

                        arvore = (yyval.tree);
                        }
#line 1534 "parser.tab.c"
    break;

  case 5: /* push_scope: %empty  */
#line 84 "parser.y"
            { pushScope(&stack); }
#line 1540 "parser.tab.c"
    break;

  case 6: /* pop_scope: %empty  */
#line 86 "parser.y"
           { popScope(&stack); }
#line 1546 "parser.tab.c"
    break;

  case 7: /* element: function  */
#line 88 "parser.y"
                  { (yyval.tree) = (yyvsp[0].tree); }
#line 1552 "parser.tab.c"
    break;

  case 8: /* element: global_declaration  */
#line 89 "parser.y"
                         { (yyval.tree) = (yyvsp[0].tree); }
#line 1558 "parser.tab.c"
    break;

  case 9: /* global_declaration: type list_vars ';'  */
#line 91 "parser.y"
                                       { 
    (yyval.tree) = (yyvsp[-1].tree); 
    int i = 0;
    while(varList[i] != NULL && i < 100){
        insertSymbolGlobal(&stack, varList[i], lineList[i], IDENTIFIER, (yyvsp[-2].type), "");
        i++;
    }
    for(i = 0; i < 100; i++){
        if(varList[i] != NULL){
            free(varList[i]);
            lineList[i] = -1;
            varList[i] = NULL;
        }
    }
}
#line 1578 "parser.tab.c"
    break;

  case 10: /* type: TK_PR_INT  */
#line 107 "parser.y"
                { (yyval.type) = INT; }
#line 1584 "parser.tab.c"
    break;

  case 11: /* type: TK_PR_FLOAT  */
#line 108 "parser.y"
                  { (yyval.type) = FLOAT; }
#line 1590 "parser.tab.c"
    break;

  case 12: /* type: TK_PR_BOOL  */
#line 109 "parser.y"
                 { (yyval.type) = BOOL; }
#line 1596 "parser.tab.c"
    break;

  case 13: /* list_vars: TK_IDENTIFICADOR  */
#line 111 "parser.y"
                            {   (yyval.tree) = NULL; 
                                int i = 0;
                                while(varList[i] != NULL){
                                    i++;
                                    if(i == 100){
                                        printf("too many variables declared!");
                                        exit(-1);
                                    }
                                }
                                varList[i] = malloc(strlen((yyvsp[0].lexical_value).token_value) + 1);
                                strncpy(varList[i], (yyvsp[0].lexical_value).token_value, strlen((yyvsp[0].lexical_value).token_value));
                                varList[i][strlen((yyvsp[0].lexical_value).token_value)] = '\0';
                                lineList[i] = (yyvsp[0].lexical_value).lineno;
                                free((yyvsp[0].lexical_value).token_value);
                                }
#line 1616 "parser.tab.c"
    break;

  case 14: /* list_vars: list_vars ',' TK_IDENTIFICADOR  */
#line 126 "parser.y"
                                         { (yyval.tree) = (yyvsp[-2].tree); 
                                            int i = 0;
                                            while(varList[i] != NULL){
                                                i++;
                                                if(i == 100){
                                                    printf("too many variables declared!");
                                                    exit(-1);
                                                }
                                            }
                                            varList[i] = malloc(strlen((yyvsp[0].lexical_value).token_value) + 1);
                                            strncpy(varList[i], (yyvsp[0].lexical_value).token_value, strlen((yyvsp[0].lexical_value).token_value));
                                            varList[i][strlen((yyvsp[0].lexical_value).token_value)] = '\0';
                                            lineList[i] = (yyvsp[0].lexical_value).lineno;
                                            free((yyvsp[0].lexical_value).token_value); }
#line 1635 "parser.tab.c"
    break;

  case 15: /* function: push_scope header no_scope_body pop_scope  */
#line 141 "parser.y"
                                                    { (yyval.tree) = (yyvsp[-2].tree); 
                                                      asd_add_child((yyval.tree), (yyvsp[-1].tree));
                                                      append_program((yyval.tree)->code, (yyvsp[-1].tree)->code); }
#line 1643 "parser.tab.c"
    break;

  case 16: /* header: '(' param_list ')' TK_OC_GE type '!' TK_IDENTIFICADOR  */
#line 145 "parser.y"
                                                              { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); 
                                                                insertSymbolGlobal(&stack, (yyvsp[0].lexical_value).token_value, (yyvsp[0].lexical_value).lineno, FUNCTION, (yyvsp[-2].type), "");
                                                                free((yyvsp[0].lexical_value).token_value);}
#line 1651 "parser.tab.c"
    break;

  case 17: /* header: '(' ')' TK_OC_GE type '!' TK_IDENTIFICADOR  */
#line 148 "parser.y"
                                                     { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); 
                                                       insertSymbolGlobal(&stack, (yyvsp[0].lexical_value).token_value, (yyvsp[0].lexical_value).lineno, FUNCTION, (yyvsp[-2].type), ""); 
                                                       free((yyvsp[0].lexical_value).token_value); }
#line 1659 "parser.tab.c"
    break;

  case 18: /* param_list: param  */
#line 152 "parser.y"
                  {  }
#line 1665 "parser.tab.c"
    break;

  case 19: /* param_list: param_list ',' param  */
#line 153 "parser.y"
                                   {  }
#line 1671 "parser.tab.c"
    break;

  case 20: /* param: type TK_IDENTIFICADOR  */
#line 155 "parser.y"
                             { insertSymbolWithScope(&stack, (yyvsp[0].lexical_value).token_value, (yyvsp[0].lexical_value).lineno, IDENTIFIER, (yyvsp[-1].type), "");
                               free((yyvsp[0].lexical_value).token_value); }
#line 1678 "parser.tab.c"
    break;

  case 21: /* no_scope_body: '{' '}'  */
#line 158 "parser.y"
                       { (yyval.tree) = NULL; }
#line 1684 "parser.tab.c"
    break;

  case 22: /* no_scope_body: '{' command_list '}'  */
#line 159 "parser.y"
                             { (yyval.tree) = (yyvsp[-1].tree); }
#line 1690 "parser.tab.c"
    break;

  case 23: /* command_list: command  */
#line 161 "parser.y"
                      { (yyval.tree) = (yyvsp[0].tree); }
#line 1696 "parser.tab.c"
    break;

  case 24: /* command_list: command command_list  */
#line 162 "parser.y"
                                   {if ((yyvsp[-1].tree) == NULL){
                                        (yyval.tree) = (yyvsp[0].tree); }
                                    else {
                                        (yyval.tree) = (yyvsp[-1].tree);
                                        while ((yyval.tree)->next!=NULL) {
                                            (yyval.tree) = (yyval.tree)->next;
                                        }
                                        asd_add_child((yyval.tree), (yyvsp[0].tree));
                                        append_program((yyval.tree)->code, (yyvsp[0].tree)->code);
                                        (yyval.tree)->next=(yyvsp[0].tree);
                                        (yyval.tree) = (yyvsp[-1].tree);
                                    };}
#line 1713 "parser.tab.c"
    break;

  case 25: /* command: local_var_dec ';'  */
#line 177 "parser.y"
                           { (yyval.tree) = (yyvsp[-1].tree); }
#line 1719 "parser.tab.c"
    break;

  case 26: /* command: attrib ';'  */
#line 178 "parser.y"
                     { (yyval.tree) = (yyvsp[-1].tree); }
#line 1725 "parser.tab.c"
    break;

  case 27: /* command: conditional ';'  */
#line 179 "parser.y"
                          { (yyval.tree) = (yyvsp[-1].tree); }
#line 1731 "parser.tab.c"
    break;

  case 28: /* command: while ';'  */
#line 180 "parser.y"
                    { (yyval.tree) = (yyvsp[-1].tree); }
#line 1737 "parser.tab.c"
    break;

  case 29: /* command: return ';'  */
#line 181 "parser.y"
                     { (yyval.tree) = (yyvsp[-1].tree); }
#line 1743 "parser.tab.c"
    break;

  case 30: /* command: function_call ';'  */
#line 182 "parser.y"
                            { (yyval.tree) = (yyvsp[-1].tree); }
#line 1749 "parser.tab.c"
    break;

  case 31: /* command: open_block  */
#line 183 "parser.y"
                     { (yyval.tree) = (yyvsp[0].tree); }
#line 1755 "parser.tab.c"
    break;

  case 32: /* open_block: '{' '}' ';'  */
#line 185 "parser.y"
                      { (yyval.tree) = NULL; }
#line 1761 "parser.tab.c"
    break;

  case 33: /* open_block: '{' push_scope command_list pop_scope '}' ';'  */
#line 186 "parser.y"
                                                           { (yyval.tree) = (yyvsp[-3].tree); }
#line 1767 "parser.tab.c"
    break;

  case 34: /* local_var_dec: type list_vars  */
#line 189 "parser.y"
                              { 
    (yyval.tree) = (yyvsp[0].tree); 
    int i = 0;
    while(varList[i] != NULL && i < 100){
        insertSymbolWithScope(&stack, varList[i], lineList[i], IDENTIFIER, (yyvsp[-1].type), "");
        i++;
    }
    for(i = 0; i < 100; i++){
        if(varList[i] != NULL){
            free(varList[i]);
            varList[i] = NULL;
            lineList[i] = -1;
        }
    } }
#line 1786 "parser.tab.c"
    break;

  case 35: /* attrib: TK_IDENTIFICADOR '=' expr  */
#line 204 "parser.y"
                                  { (yyval.tree) = asd_new("="); 
                                    asd_add_child((yyval.tree), asd_new((yyvsp[-2].lexical_value).token_value));
                                    asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                    SymbolData *var = lookupSymbolWhenUsed(&stack, (yyvsp[-2].lexical_value).token_value, (yyvsp[-2].lexical_value).lineno, IDENTIFIER, (yyvsp[-2].lexical_value).token_type, "");
                                    if(var->nature == FUNCTION){
                                            printf("Error: invalid expression! using %s of nature FUNCAO in line %d in left side of expression. Function originally declared in line %d\n", (yyvsp[-2].lexical_value).token_value, (yyvsp[-2].lexical_value).lineno, var->line);
                                            exit(ERR_FUNCTION);
                                        }
                                    (yyval.tree)->type = var->type;
                                    free((yyvsp[-2].lexical_value).token_value);
                                    }
#line 1802 "parser.tab.c"
    break;

  case 36: /* function_call: TK_IDENTIFICADOR '(' arg_list ')'  */
#line 216 "parser.y"
                                                 { 
                    char *buffer = malloc((strlen("call ") + strlen((yyvsp[-3].lexical_value).token_value) + 1)* sizeof(char));
                    strcpy(buffer, "call ");
                    strcat(buffer, (yyvsp[-3].lexical_value).token_value);
                    (yyval.tree) = asd_new(buffer);
                    asd_add_child((yyval.tree), (yyvsp[-1].tree));
                    free(buffer);
                    SymbolData *var = lookupSymbolWhenUsed(&stack, (yyvsp[-3].lexical_value).token_value, (yyvsp[-3].lexical_value).lineno, FUNCTION, (yyvsp[-3].lexical_value).token_type, "");
                    if(var->nature == IDENTIFIER){
                        printf("Error: invalid function call %s() in line %d. Identifier was originally declared in line %d\n", (yyvsp[-3].lexical_value).token_value, (yyvsp[-3].lexical_value).lineno, var->line);
                        exit(ERR_VARIABLE);
                        }
                    (yyval.tree)->type = var->type; 
                    free((yyvsp[-3].lexical_value).token_value);
                    }
#line 1822 "parser.tab.c"
    break;

  case 37: /* function_call: TK_IDENTIFICADOR '(' ')'  */
#line 231 "parser.y"
                                           { 
                        char *buffer = malloc((strlen("call ") + strlen((yyvsp[-2].lexical_value).token_value) + 1)* sizeof(char));
                        strcpy(buffer, "call ");
                        strcat(buffer, (yyvsp[-2].lexical_value).token_value);
                        (yyval.tree) = asd_new(buffer);
                        free(buffer);
                        SymbolData *var = lookupSymbolWhenUsed(&stack, (yyvsp[-2].lexical_value).token_value, (yyvsp[-2].lexical_value).lineno, FUNCTION, (yyvsp[-2].lexical_value).token_type, "");
                        if(var->nature == IDENTIFIER){
                        printf("Error: invalid function call %s() in line %d. Identifier was originally declared in line %d\n", (yyvsp[-2].lexical_value).token_value, (yyvsp[-2].lexical_value).lineno, var->line);
                        exit(ERR_VARIABLE);
                        }
                        (yyval.tree)->type = var->type; 
                        free((yyvsp[-2].lexical_value).token_value);
                    }
#line 1841 "parser.tab.c"
    break;

  case 38: /* arg_list: arg  */
#line 247 "parser.y"
              { (yyval.tree) = (yyvsp[0].tree); }
#line 1847 "parser.tab.c"
    break;

  case 39: /* arg_list: arg ',' arg_list  */
#line 248 "parser.y"
                       { (yyval.tree) = (yyvsp[-2].tree); asd_add_child((yyval.tree), (yyvsp[0].tree)); append_program((yyval.tree)->code, (yyvsp[0].tree)->code); }
#line 1853 "parser.tab.c"
    break;

  case 40: /* arg: expr  */
#line 250 "parser.y"
          { (yyval.tree) = (yyvsp[0].tree); }
#line 1859 "parser.tab.c"
    break;

  case 41: /* return: TK_PR_RETURN expr  */
#line 252 "parser.y"
                          { (yyval.tree) = asd_new("return");
                            asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                            (yyval.tree)->type = (yyvsp[0].tree)->type; 
                            append_program((yyval.tree)->code, (yyvsp[0].tree)->code);}
#line 1868 "parser.tab.c"
    break;

  case 42: /* conditional: TK_PR_IF '(' expr ')' no_scope_body  */
#line 257 "parser.y"
                                                 { (yyval.tree) = asd_new("if"); 
                                                   asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                                   asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                                   (yyval.tree)->type = (yyvsp[-2].tree)->type; 
                                                   add_if((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1878 "parser.tab.c"
    break;

  case 43: /* conditional: TK_PR_IF '(' expr ')' no_scope_body TK_PR_ELSE no_scope_body  */
#line 263 "parser.y"
                                                                            { (yyval.tree) = asd_new("if"); 
                                                                              asd_add_child((yyval.tree), (yyvsp[-4].tree)); 
                                                                              asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                                                              asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                                                              (yyval.tree)->type = (yyvsp[-4].tree)->type;
                                                                              add_if_else((yyval.tree), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1889 "parser.tab.c"
    break;

  case 44: /* while: TK_PR_WHILE '(' expr ')' no_scope_body  */
#line 272 "parser.y"
                                              { (yyval.tree) = asd_new("while"); 
                                                asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                                asd_add_child((yyval.tree), (yyvsp[0].tree));
                                                add_while((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree));
                                                (yyval.tree)->type = (yyvsp[-2].tree)->type;}
#line 1899 "parser.tab.c"
    break;

  case 45: /* expr: logical_or_expr  */
#line 278 "parser.y"
                      { (yyval.tree) = (yyvsp[0].tree); }
#line 1905 "parser.tab.c"
    break;

  case 46: /* logical_or_expr: logical_and_expr  */
#line 280 "parser.y"
                                  { (yyval.tree) = (yyvsp[0].tree); }
#line 1911 "parser.tab.c"
    break;

  case 47: /* logical_or_expr: logical_or_expr TK_OC_OR logical_and_expr  */
#line 281 "parser.y"
                                                {(yyval.tree) = asd_new("|"); 
                                                asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                                asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                                (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                                add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), or); 
                                                }
#line 1922 "parser.tab.c"
    break;

  case 48: /* logical_and_expr: equality_expr  */
#line 288 "parser.y"
                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1928 "parser.tab.c"
    break;

  case 49: /* logical_and_expr: logical_and_expr TK_OC_AND equality_expr  */
#line 289 "parser.y"
                                               { (yyval.tree) = asd_new("&"); 
                                                 asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                                 asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                                 (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                                 add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), and); 
                                                 }
#line 1939 "parser.tab.c"
    break;

  case 50: /* equality_expr: relational_expr  */
#line 296 "parser.y"
                               { (yyval.tree) = (yyvsp[0].tree); }
#line 1945 "parser.tab.c"
    break;

  case 51: /* equality_expr: equality_expr TK_OC_EQ relational_expr  */
#line 297 "parser.y"
                                             { (yyval.tree) = asd_new("=="); 
                                               asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                               asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                               (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                               add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), cmp_eq); 
                                               }
#line 1956 "parser.tab.c"
    break;

  case 52: /* equality_expr: equality_expr TK_OC_NE relational_expr  */
#line 304 "parser.y"
                                             { (yyval.tree) = asd_new("!="); 
                                               asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                               asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                               (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                               add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), cmp_ne);
                                               }
#line 1967 "parser.tab.c"
    break;

  case 53: /* relational_expr: add_sub_expr  */
#line 311 "parser.y"
                              { (yyval.tree) = (yyvsp[0].tree); }
#line 1973 "parser.tab.c"
    break;

  case 54: /* relational_expr: relational_expr '<' add_sub_expr  */
#line 312 "parser.y"
                                       { (yyval.tree) = asd_new("<"); 
                                         asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                         asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                         (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                         add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), lt);
                                          }
#line 1984 "parser.tab.c"
    break;

  case 55: /* relational_expr: relational_expr '>' add_sub_expr  */
#line 319 "parser.y"
                                       { (yyval.tree) = asd_new(">"); 
                                         asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                         asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                         (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                         add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), gt);
                                         }
#line 1995 "parser.tab.c"
    break;

  case 56: /* relational_expr: relational_expr TK_OC_LE add_sub_expr  */
#line 326 "parser.y"
                                            { (yyval.tree) = asd_new("<="); 
                                              asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                              asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                              (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                              add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), le);
                                              }
#line 2006 "parser.tab.c"
    break;

  case 57: /* relational_expr: relational_expr TK_OC_GE add_sub_expr  */
#line 333 "parser.y"
                                            { (yyval.tree) = asd_new(">="); 
                                              asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                              asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                              (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                              add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), ge);
                                              }
#line 2017 "parser.tab.c"
    break;

  case 58: /* add_sub_expr: mult_div_mod_expr  */
#line 340 "parser.y"
                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2023 "parser.tab.c"
    break;

  case 59: /* add_sub_expr: add_sub_expr '+' mult_div_mod_expr  */
#line 341 "parser.y"
                                         { (yyval.tree) = asd_new("+"); 
                                           asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                           //append_program($$->code, $1->code);
                                           asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                           //append_program($$->code, $3->code);
                                           (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                           add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), add);
                                           }
#line 2036 "parser.tab.c"
    break;

  case 60: /* add_sub_expr: add_sub_expr '-' mult_div_mod_expr  */
#line 350 "parser.y"
                                         { (yyval.tree) = asd_new("-"); 
                                           asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                           asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                           (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                           add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), sub);
                                            }
#line 2047 "parser.tab.c"
    break;

  case 61: /* mult_div_mod_expr: unary_expr  */
#line 357 "parser.y"
                              { (yyval.tree) = (yyvsp[0].tree); }
#line 2053 "parser.tab.c"
    break;

  case 62: /* mult_div_mod_expr: mult_div_mod_expr '*' unary_expr  */
#line 358 "parser.y"
                                       { (yyval.tree) = asd_new("*"); 
                                         asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                         asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                         (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                         add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), mul);
                                         }
#line 2064 "parser.tab.c"
    break;

  case 63: /* mult_div_mod_expr: mult_div_mod_expr '/' unary_expr  */
#line 365 "parser.y"
                                       { (yyval.tree) = asd_new("/"); 
                                         asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                         asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                         (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);
                                         add_binop((yyval.tree), (yyvsp[-2].tree), (yyvsp[0].tree), divi); 
                                         }
#line 2075 "parser.tab.c"
    break;

  case 64: /* mult_div_mod_expr: mult_div_mod_expr '%' unary_expr  */
#line 372 "parser.y"
                                       { (yyval.tree) = asd_new("%"); 
                                         asd_add_child((yyval.tree), (yyvsp[-2].tree)); 
                                         asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                         (yyval.tree)->type = inferType((yyvsp[-2].tree)->type, (yyvsp[0].tree)->type);}
#line 2084 "parser.tab.c"
    break;

  case 65: /* unary_expr: primary_expr  */
#line 377 "parser.y"
                         { (yyval.tree) = (yyvsp[0].tree); }
#line 2090 "parser.tab.c"
    break;

  case 66: /* unary_expr: '-' unary_expr  */
#line 378 "parser.y"
                                      { (yyval.tree) = asd_new("-"); 
                                        asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                                        (yyval.tree)->type = (yyvsp[0].tree)->type; }
#line 2098 "parser.tab.c"
    break;

  case 67: /* unary_expr: '!' unary_expr  */
#line 382 "parser.y"
                         { (yyval.tree) = asd_new("!"); 
                           asd_add_child((yyval.tree), (yyvsp[0].tree)); 
                           (yyval.tree)->type = (yyvsp[0].tree)->type; }
#line 2106 "parser.tab.c"
    break;

  case 68: /* primary_expr: TK_IDENTIFICADOR  */
#line 386 "parser.y"
                               { 
        (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value);     
        SymbolData *var = lookupSymbolWhenUsed(&stack, (yyvsp[0].lexical_value).token_value, (yyvsp[0].lexical_value).lineno, IDENTIFIER, (yyvsp[0].lexical_value).token_type, "");
        if(var->nature == FUNCTION){
            printf("Error: invalid expression! using %s of nature FUNCAO in line %d in left side of expression.. Function originally declared in line %d\n", (yyvsp[0].lexical_value).token_value, (yyvsp[0].lexical_value).lineno, var->line);
            exit(ERR_FUNCTION);
        }
        (yyval.tree)->type = var->type; 
        (yyval.tree)->offset = var->memory_offset;
        (yyval.tree)->is_global = var->is_global;
        char* temp_register = generate_register();
        char temp_offset[80];
        sprintf(temp_offset, "%i", (yyval.tree)->offset);
        add_instruction_to_program((yyval.tree)->code, create_instruction(loadAI, (yyval.tree)->is_global ? "rbss" : "rfp", temp_offset, temp_register, NULL, 3));
        (yyval.tree)->temp = temp_register;
        free((yyvsp[0].lexical_value).token_value); 
        }
#line 2128 "parser.tab.c"
    break;

  case 69: /* primary_expr: TK_LIT_INT  */
#line 403 "parser.y"
                 { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value);  (yyval.tree)->type = INT; 
                    char* temp_register = generate_register();
  
    add_instruction_to_program((yyval.tree)->code, create_instruction(loadI, (yyvsp[0].lexical_value).token_value, temp_register, NULL, NULL, 2));
    (yyval.tree)->temp = temp_register;
    free((yyvsp[0].lexical_value).token_value);
    //free(temp_register);
    }
#line 2141 "parser.tab.c"
    break;

  case 70: /* primary_expr: TK_LIT_FLOAT  */
#line 411 "parser.y"
                   { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); free((yyvsp[0].lexical_value).token_value); (yyval.tree)->type = FLOAT; }
#line 2147 "parser.tab.c"
    break;

  case 71: /* primary_expr: TK_LIT_TRUE  */
#line 412 "parser.y"
                  { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); free((yyvsp[0].lexical_value).token_value); (yyval.tree)->type = BOOL; }
#line 2153 "parser.tab.c"
    break;

  case 72: /* primary_expr: TK_LIT_FALSE  */
#line 413 "parser.y"
                   { (yyval.tree) = asd_new((yyvsp[0].lexical_value).token_value); free((yyvsp[0].lexical_value).token_value); (yyval.tree)->type = BOOL; }
#line 2159 "parser.tab.c"
    break;

  case 73: /* primary_expr: function_call  */
#line 414 "parser.y"
                    { (yyval.tree) = (yyvsp[0].tree); }
#line 2165 "parser.tab.c"
    break;

  case 74: /* primary_expr: '(' expr ')'  */
#line 415 "parser.y"
                   { (yyval.tree) = (yyvsp[-1].tree); }
#line 2171 "parser.tab.c"
    break;


#line 2175 "parser.tab.c"

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

#line 417 "parser.y"
