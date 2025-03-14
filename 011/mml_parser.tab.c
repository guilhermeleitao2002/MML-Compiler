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
#line 1 "mml_parser.y"

//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!

#line 85 "mml_parser.tab.c"

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

#include "mml_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tINTEGER = 3,                   /* tINTEGER  */
  YYSYMBOL_tREAL = 4,                      /* tREAL  */
  YYSYMBOL_tIDENTIFIER = 5,                /* tIDENTIFIER  */
  YYSYMBOL_tSTRING = 6,                    /* tSTRING  */
  YYSYMBOL_tWHILE = 7,                     /* tWHILE  */
  YYSYMBOL_tIF = 8,                        /* tIF  */
  YYSYMBOL_tPRINT = 9,                     /* tPRINT  */
  YYSYMBOL_tPRINTLN = 10,                  /* tPRINTLN  */
  YYSYMBOL_tREAD = 11,                     /* tREAD  */
  YYSYMBOL_tBEGIN = 12,                    /* tBEGIN  */
  YYSYMBOL_tEND = 13,                      /* tEND  */
  YYSYMBOL_tSIZEOF = 14,                   /* tSIZEOF  */
  YYSYMBOL_tNULL = 15,                     /* tNULL  */
  YYSYMBOL_tINPUT = 16,                    /* tINPUT  */
  YYSYMBOL_tRETURN = 17,                   /* tRETURN  */
  YYSYMBOL_tSTOP = 18,                     /* tSTOP  */
  YYSYMBOL_tNEXT = 19,                     /* tNEXT  */
  YYSYMBOL_tARROW = 20,                    /* tARROW  */
  YYSYMBOL_tTYPE_STRING = 21,              /* tTYPE_STRING  */
  YYSYMBOL_tTYPE_INT = 22,                 /* tTYPE_INT  */
  YYSYMBOL_tTYPE_REAL = 23,                /* tTYPE_REAL  */
  YYSYMBOL_tTYPE_AUTO = 24,                /* tTYPE_AUTO  */
  YYSYMBOL_tTYPE_VOID = 25,                /* tTYPE_VOID  */
  YYSYMBOL_tPUBLIC = 26,                   /* tPUBLIC  */
  YYSYMBOL_tFOREIGN = 27,                  /* tFOREIGN  */
  YYSYMBOL_tFORWARD = 28,                  /* tFORWARD  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* '['  */
  YYSYMBOL_32_ = 32,                       /* ']'  */
  YYSYMBOL_tELSE = 33,                     /* tELSE  */
  YYSYMBOL_tIFX = 34,                      /* tIFX  */
  YYSYMBOL_35_ = 35,                       /* '='  */
  YYSYMBOL_tAND = 36,                      /* tAND  */
  YYSYMBOL_tOR = 37,                       /* tOR  */
  YYSYMBOL_tNOT = 38,                      /* tNOT  */
  YYSYMBOL_tEQ = 39,                       /* tEQ  */
  YYSYMBOL_tNE = 40,                       /* tNE  */
  YYSYMBOL_41_ = 41,                       /* '>'  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_tGE = 43,                       /* tGE  */
  YYSYMBOL_tLE = 44,                       /* tLE  */
  YYSYMBOL_45_ = 45,                       /* '+'  */
  YYSYMBOL_46_ = 46,                       /* '-'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '/'  */
  YYSYMBOL_49_ = 49,                       /* '%'  */
  YYSYMBOL_tUNARY = 50,                    /* tUNARY  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* '?'  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_54_ = 54,                       /* '{'  */
  YYSYMBOL_55_ = 55,                       /* '}'  */
  YYSYMBOL_56_ = 56,                       /* '@'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_file = 58,                      /* file  */
  YYSYMBOL_list = 59,                      /* list  */
  YYSYMBOL_stmt = 60,                      /* stmt  */
  YYSYMBOL_iffalse = 61,                   /* iffalse  */
  YYSYMBOL_expr = 62,                      /* expr  */
  YYSYMBOL_exprs = 63,                     /* exprs  */
  YYSYMBOL_vardec = 64,                    /* vardec  */
  YYSYMBOL_vardecs = 65,                   /* vardecs  */
  YYSYMBOL_data_type = 66,                 /* data_type  */
  YYSYMBOL_func_type = 67,                 /* func_type  */
  YYSYMBOL_output_type = 68,               /* output_type  */
  YYSYMBOL_var_types = 69,                 /* var_types  */
  YYSYMBOL_lval = 70,                      /* lval  */
  YYSYMBOL_return = 71,                    /* return  */
  YYSYMBOL_block = 72,                     /* block  */
  YYSYMBOL_call = 73,                      /* call  */
  YYSYMBOL_definition = 74,                /* definition  */
  YYSYMBOL_vars = 75,                      /* vars  */
  YYSYMBOL_var = 76,                       /* var  */
  YYSYMBOL_string = 77                     /* string  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 67 "mml_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 200 "mml_parser.tab.c"


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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
       2,     2,     2,     2,     2,     2,     2,    49,     2,     2,
      29,    30,    47,    45,    53,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      42,    35,    41,    52,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      25,    26,    27,    28,    33,    34,    36,    37,    38,    39,
      40,    43,    44,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    73,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    85,    86,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   103,   104,   105,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   139,   140,
     143,   144,   145,   146,   147,   148,   149,   150,   153,   154,
     157,   158,   159,   160,   161,   162,   163,   166,   167,   170,
     173,   174,   177,   178,   181,   182,   185,   186,   187,   188,
     191,   192,   193,   194,   197,   198,   201,   202,   205,   208,
     209
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tINTEGER", "tREAL",
  "tIDENTIFIER", "tSTRING", "tWHILE", "tIF", "tPRINT", "tPRINTLN", "tREAD",
  "tBEGIN", "tEND", "tSIZEOF", "tNULL", "tINPUT", "tRETURN", "tSTOP",
  "tNEXT", "tARROW", "tTYPE_STRING", "tTYPE_INT", "tTYPE_REAL",
  "tTYPE_AUTO", "tTYPE_VOID", "tPUBLIC", "tFOREIGN", "tFORWARD", "'('",
  "')'", "'['", "']'", "tELSE", "tIFX", "'='", "tAND", "tOR", "tNOT",
  "tEQ", "tNE", "'>'", "'<'", "tGE", "tLE", "'+'", "'-'", "'*'", "'/'",
  "'%'", "tUNARY", "';'", "'?'", "','", "'{'", "'}'", "'@'", "$accept",
  "file", "list", "stmt", "iffalse", "expr", "exprs", "vardec", "vardecs",
  "data_type", "func_type", "output_type", "var_types", "lval", "return",
  "block", "call", "definition", "vars", "var", "string", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     150,   185,   -84,   -84,   -84,   -84,   -84,   105,   129,   129,
     129,     8,   -84,   448,    11,   -84,   -22,   -84,   -84,   -84,
     -84,    20,    57,   -84,    62,   -84,   -84,   768,    22,    36,
      78,   732,   825,   825,   825,   229,    75,   449,   -84,   843,
      19,   273,   -33,   -84,   -84,   -84,   -84,    42,    16,    73,
     107,   108,    82,   -84,   317,   -84,    -9,   124,   825,   825,
     825,   825,   -84,   864,    64,   -84,    71,   -84,   112,   971,
     120,   -17,   -84,   992,  1143,   -84,   -84,   -84,   493,   361,
     787,   -84,   -84,   806,   825,   825,   825,   825,   825,   825,
     825,   825,   825,   825,   825,   825,   825,   825,   -84,   -84,
     -84,   825,   -84,   537,   825,   -84,   -84,   825,    -8,    44,
      84,   -84,   -84,   581,   405,   825,   -84,   -84,    96,    -1,
    1013,  1034,  1055,   -84,   -84,   -84,   129,   -84,   -84,   119,
     129,   -84,   -84,   -84,   625,   -84,  1118,   -16,   -84,   -12,
    1076,  1143,  1143,   472,   472,    72,    72,    72,    72,    49,
      49,   -84,   -84,   -84,  1118,   -84,  1132,   885,   825,   -84,
     825,   -84,   -84,   -84,   -84,   669,   906,   -84,   129,   713,
     713,   -84,    89,   129,   -84,   -84,   -84,   -84,   -84,   -84,
     927,   948,   -84,   -84,    96,   -84,    13,   -84,    89,   -84,
     -84,   713,   127,   -84,   -84,   -84,   825,  1097,   713,    13,
     -84
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      11,     0,    72,    70,    71,    74,    73,     0,     0,     0,
       0,     0,    68,     6,    79,    76,     0,    49,    50,    82,
      99,     0,     0,    10,     0,    52,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    58,
       0,     0,    55,    21,    25,    57,    56,    51,     0,    79,
      79,    79,    79,     1,     0,    69,     0,     0,     0,     0,
       0,     0,    84,     0,     0,    18,     0,    20,     0,     0,
      79,     0,    96,     0,    45,    31,    32,    89,     0,     0,
       0,     9,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
      16,     0,     8,     0,     0,    33,   100,     0,     0,     0,
       0,    75,     5,     0,     0,     0,    67,    78,    80,     0,
       0,     0,     0,    85,    17,    19,     0,    29,    98,     0,
       0,    30,    87,    88,     0,    93,    58,     0,    91,     0,
       0,    46,    47,    43,    44,    40,    39,    42,    41,    37,
      38,    34,    35,    36,    59,     7,    48,     0,     0,    64,
       0,    61,    62,     4,     3,     0,     0,    77,     0,     0,
       0,    53,    79,     0,    97,    86,    92,    90,    83,    65,
       0,     0,     2,    66,    81,    24,    22,    95,    79,    63,
      60,     0,     0,    23,    94,    26,     0,     0,     0,    27,
      28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   -24,   -28,   -42,   -27,   -68,    -3,     0,    14,
     -84,   -84,   -84,   -84,   -84,   -83,   -84,   -84,   -84,    28,
     -84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,    37,    38,   193,    39,    40,    12,    13,    14,
      15,    16,   119,    42,    43,    44,    45,    46,    71,    72,
      47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    41,   104,    69,    73,    74,    75,    76,    53,    82,
      55,    78,   137,   129,   176,   139,    56,   103,   177,   105,
      57,    49,    50,    51,    52,    64,   115,   158,    99,   100,
     113,   120,   121,   122,    73,    79,   130,   101,    55,    66,
     167,   101,   116,   159,    70,    52,   191,   192,   106,    58,
      82,   107,   168,   136,   114,   134,   136,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   118,   101,    65,   154,    82,    55,   156,   108,   160,
     157,    17,    18,    19,    20,    82,    59,    67,   166,   187,
     165,    60,    24,    25,    26,   161,    95,    96,    97,     2,
       3,     4,     5,     6,    80,   194,    82,    30,    68,    31,
      48,    55,   109,   110,   111,   124,    32,    93,    94,    95,
      96,    97,   125,    33,    34,   128,     2,     3,     4,     5,
       6,   180,   126,   181,    36,   162,    10,    82,   -79,   173,
     172,   185,   186,    35,    70,     2,     3,     4,     5,     6,
       2,     3,     4,     5,     6,    10,   196,   200,   174,     0,
      10,     0,     1,   195,     0,   117,     0,     0,     0,   197,
     199,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,    10,   184,     0,     0,     0,     0,   188,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,    29,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    30,     0,    31,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     0,     0,     0,     0,
      33,    34,    17,    18,    19,    20,    21,    22,     0,    35,
       0,    36,     0,    24,    25,    26,    27,    28,    29,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    30,     0,
      31,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,    33,    34,    17,    18,    19,    20,
      21,    22,     0,    35,    77,    36,   102,    24,    25,    26,
      27,    28,    29,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    30,     0,    31,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,    33,    34,
      17,    18,    19,    20,    21,    22,     0,    35,     0,    36,
     112,    24,    25,    26,    27,    28,    29,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    30,     0,    31,     0,
       0,     0,     0,     0,     0,    32,     0,     0,     0,     0,
       0,     0,    33,    34,    17,    18,    19,    20,    21,    22,
       0,    35,     0,    36,     0,    24,    25,    26,    27,    28,
      29,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      30,     0,    31,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,    33,    34,    17,    18,
      19,    20,    21,    22,     0,    35,   133,    36,   164,    24,
      25,    26,    27,    28,    29,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    30,     0,    31,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     0,     0,     0,     0,
      33,    34,    17,    18,    19,    20,    21,    22,     0,    35,
      54,    36,    81,    24,    25,    26,    27,    28,    29,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    30,    10,
      61,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,    33,    34,    17,    18,    19,    20,
      21,    22,     0,    35,     0,    36,     0,    24,    25,    26,
      27,    28,    29,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    30,     0,    61,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,    33,    34,
      17,    18,    19,    20,    21,    22,     0,    35,   132,    36,
     155,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    61,     0,
       0,     0,     0,     0,     0,    32,     0,     0,     0,     0,
       0,     0,    33,    34,    17,    18,    19,    20,    21,    22,
       0,    35,     0,    36,   163,    24,    25,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,     0,    61,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,    33,    34,    17,    18,
      19,    20,    21,    22,     0,    35,     0,    36,     0,    24,
      25,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,    61,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     0,     0,     0,     0,
      33,    34,    17,    18,    19,    20,    21,    22,     0,    35,
     175,    36,   182,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
      61,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,    33,    34,    17,    18,    19,    20,
      21,    22,     0,    35,     0,    36,     0,    24,    25,    26,
      27,    28,    29,     0,     0,    17,    18,    19,    20,     0,
       0,     0,    30,     0,    61,     0,    24,    25,    26,     0,
       0,    32,     0,     2,     3,     4,     5,     6,    33,    34,
       0,    30,     0,    31,     0,     0,     0,    35,     0,    36,
      32,    17,    18,    19,    20,     0,     0,    33,    34,     0,
       0,     0,    24,    25,    26,     0,     0,     0,    36,     0,
      17,    18,    19,    20,     0,     0,     0,    30,     0,    61,
       0,    24,    25,    26,     0,     0,    32,     0,     0,    17,
      18,    19,    20,    33,    34,     0,    30,   135,    61,    62,
      24,    25,    26,     0,    36,    32,     0,     0,    17,    18,
      19,    20,    33,    34,     0,    30,   138,    61,     0,    24,
      25,    26,     0,    36,    32,     0,     0,     0,     0,     0,
       0,    33,    34,     0,    30,     0,    61,     0,     0,     0,
       0,     0,    36,    32,     0,     0,     0,     0,     0,     0,
      33,    34,    83,     0,    84,     0,     0,     0,     0,    85,
      86,    36,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    83,    98,    84,     0,     0,     0,     0,
      85,    86,     0,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    83,   123,    84,     0,     0,     0,
       0,    85,    86,     0,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    83,   179,    84,     0,     0,
       0,     0,    85,    86,     0,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    83,   183,    84,     0,
       0,     0,     0,    85,    86,     0,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    83,   189,    84,
       0,     0,     0,     0,    85,    86,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     0,   190,
      83,   127,    84,     0,     0,     0,     0,    85,    86,     0,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    83,     0,    84,   131,     0,     0,     0,    85,    86,
       0,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    83,   169,    84,     0,     0,     0,     0,    85,
      86,     0,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    83,   170,    84,     0,     0,     0,     0,
      85,    86,     0,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    83,   171,    84,     0,     0,     0,
       0,    85,    86,     0,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    83,     0,    84,   178,     0,
       0,     0,    85,    86,     0,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    83,   198,    84,     0,
       0,     0,     0,    85,    86,     0,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    83,     0,    84,
       0,     0,     0,     0,    85,    86,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    85,    86,
       0,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97
};

static const yytype_int16 yycheck[] =
{
      27,     1,    35,    30,    31,    32,    33,    34,     0,    37,
      13,    35,    80,    30,    30,    83,     5,    41,    30,    52,
      42,     7,     8,     9,    10,     3,    35,    35,     9,    10,
      54,    58,    59,    60,    61,    35,    53,    53,    41,     3,
      41,    53,    51,    51,    30,    31,    33,    34,     6,    29,
      78,    35,    53,    80,    54,    79,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    57,    53,    51,   101,   103,    79,   104,     5,    35,
     107,     3,     4,     5,     6,   113,    29,    51,   115,   172,
     114,    29,    14,    15,    16,    51,    47,    48,    49,    21,
      22,    23,    24,    25,    29,   188,   134,    29,    30,    31,
       5,   114,     5,     5,    32,    51,    38,    45,    46,    47,
      48,    49,    51,    45,    46,     5,    21,    22,    23,    24,
      25,   158,    20,   160,    56,    51,    31,   165,    42,    20,
     126,   169,   170,    54,   130,    21,    22,    23,    24,    25,
      21,    22,    23,    24,    25,    31,    29,   199,   130,    -1,
      31,    -1,    12,   191,    -1,    41,    -1,    -1,    -1,   196,
     198,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,   168,    -1,    -1,    -1,    -1,   173,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,     3,     4,     5,     6,     7,     8,    -1,    54,
      -1,    56,    -1,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,     3,     4,     5,     6,
       7,     8,    -1,    54,    55,    56,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
       3,     4,     5,     6,     7,     8,    -1,    54,    -1,    56,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,     3,     4,     5,     6,     7,     8,
      -1,    54,    -1,    56,    -1,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,     3,     4,
       5,     6,     7,     8,    -1,    54,    55,    56,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,     3,     4,     5,     6,     7,     8,    -1,    54,
      12,    56,    13,    14,    15,    16,    17,    18,    19,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    29,    31,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,     3,     4,     5,     6,
       7,     8,    -1,    54,    -1,    56,    -1,    14,    15,    16,
      17,    18,    19,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
       3,     4,     5,     6,     7,     8,    -1,    54,    55,    56,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,     3,     4,     5,     6,     7,     8,
      -1,    54,    -1,    56,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,     3,     4,
       5,     6,     7,     8,    -1,    54,    -1,    56,    -1,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,     3,     4,     5,     6,     7,     8,    -1,    54,
      55,    56,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,     3,     4,     5,     6,
       7,     8,    -1,    54,    -1,    56,    -1,    14,    15,    16,
      17,    18,    19,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    29,    -1,    31,    -1,    14,    15,    16,    -1,
      -1,    38,    -1,    21,    22,    23,    24,    25,    45,    46,
      -1,    29,    -1,    31,    -1,    -1,    -1,    54,    -1,    56,
      38,     3,     4,     5,     6,    -1,    -1,    45,    46,    -1,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,    56,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    29,    -1,    31,
      -1,    14,    15,    16,    -1,    -1,    38,    -1,    -1,     3,
       4,     5,     6,    45,    46,    -1,    29,    30,    31,    51,
      14,    15,    16,    -1,    56,    38,    -1,    -1,     3,     4,
       5,     6,    45,    46,    -1,    29,    30,    31,    -1,    14,
      15,    16,    -1,    56,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    56,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    29,    -1,    31,    -1,    -1,    -1,    -1,    36,
      37,    56,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    29,    51,    31,    -1,    -1,    -1,    -1,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    29,    51,    31,    -1,    -1,    -1,
      -1,    36,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    29,    51,    31,    -1,    -1,
      -1,    -1,    36,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    29,    51,    31,    -1,
      -1,    -1,    -1,    36,    37,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    29,    51,    31,
      -1,    -1,    -1,    -1,    36,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      29,    30,    31,    -1,    -1,    -1,    -1,    36,    37,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    29,    -1,    31,    32,    -1,    -1,    -1,    36,    37,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    29,    30,    31,    -1,    -1,    -1,    -1,    36,
      37,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    29,    30,    31,    -1,    -1,    -1,    -1,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    29,    30,    31,    -1,    -1,    -1,
      -1,    36,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    29,    -1,    31,    32,    -1,
      -1,    -1,    36,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    29,    30,    31,    -1,
      -1,    -1,    -1,    36,    37,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    29,    -1,    31,
      -1,    -1,    -1,    -1,    36,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    36,    37,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    21,    22,    23,    24,    25,    26,    27,    28,
      31,    58,    64,    65,    66,    67,    68,     3,     4,     5,
       6,     7,     8,    13,    14,    15,    16,    17,    18,    19,
      29,    31,    38,    45,    46,    54,    56,    59,    60,    62,
      63,    65,    70,    71,    72,    73,    74,    77,     5,    66,
      66,    66,    66,     0,    12,    64,     5,    42,    29,    29,
      29,    31,    51,    62,     3,    51,     3,    51,    30,    62,
      66,    75,    76,    62,    62,    62,    62,    55,    59,    65,
      29,    13,    60,    29,    31,    36,    37,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    51,     9,
      10,    53,    13,    59,    35,    52,     6,    35,     5,     5,
       5,    32,    13,    59,    65,    35,    51,    41,    66,    69,
      62,    62,    62,    51,    51,    51,    20,    30,     5,    30,
      53,    32,    55,    55,    59,    30,    62,    63,    30,    63,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    13,    62,    62,    35,    51,
      35,    51,    51,    13,    13,    59,    62,    41,    53,    30,
      30,    30,    66,    20,    76,    55,    30,    30,    32,    51,
      62,    62,    13,    51,    66,    60,    60,    72,    66,    51,
      51,    33,    34,    61,    72,    60,    29,    62,    30,    60,
      61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    72,    72,
      73,    73,    73,    73,    74,    74,    75,    75,    76,    77,
      77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     4,     3,     1,     4,     3,     3,
       2,     0,     1,     2,     2,     2,     2,     3,     2,     3,
       2,     1,     5,     6,     5,     1,     2,     5,     6,     3,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     3,
       6,     4,     4,     6,     4,     5,     5,     3,     1,     2,
       1,     1,     1,     1,     1,     3,     1,     4,     3,     1,
       1,     3,     1,     4,     2,     3,     4,     3,     3,     2,
       4,     3,     4,     3,     6,     5,     1,     3,     2,     1,
       2
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
        yyerror (compiler, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (compiler);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, compiler);
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
                 int yyrule, std::shared_ptr<cdk::compiler> compiler)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YY_USE (yyvaluep);
  YY_USE (compiler);
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
yyparse (std::shared_ptr<cdk::compiler> compiler)
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
  case 2: /* file: vardecs tBEGIN vardecs list tEND  */
#line 73 "mml_parser.y"
                                                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)), cdk::primitive_type::create(4, cdk::TYPE_INT), true)), (yyvsp[-4].sequence))); }
#line 1488 "mml_parser.tab.c"
    break;

  case 3: /* file: vardecs tBEGIN vardecs tEND  */
#line 74 "mml_parser.y"
                                                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, (yyvsp[-1].sequence), nullptr), cdk::primitive_type::create(4, cdk::TYPE_INT), true)), (yyvsp[-3].sequence))); }
#line 1494 "mml_parser.tab.c"
    break;

  case 4: /* file: vardecs tBEGIN list tEND  */
#line 75 "mml_parser.y"
                                                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, nullptr, (yyvsp[-1].sequence)), cdk::primitive_type::create(4, cdk::TYPE_INT), true)), (yyvsp[-3].sequence))); }
#line 1500 "mml_parser.tab.c"
    break;

  case 5: /* file: vardecs tBEGIN tEND  */
#line 76 "mml_parser.y"
                                                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, nullptr, nullptr), cdk::primitive_type::create(4, cdk::TYPE_INT), true)), (yyvsp[-2].sequence))); }
#line 1506 "mml_parser.tab.c"
    break;

  case 6: /* file: vardecs  */
#line 77 "mml_parser.y"
                                                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].sequence))); }
#line 1512 "mml_parser.tab.c"
    break;

  case 7: /* file: tBEGIN vardecs list tEND  */
#line 78 "mml_parser.y"
                                                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)), cdk::primitive_type::create(4, cdk::TYPE_INT), true))); }
#line 1518 "mml_parser.tab.c"
    break;

  case 8: /* file: tBEGIN vardecs tEND  */
#line 79 "mml_parser.y"
                                                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, (yyvsp[-1].sequence), nullptr), cdk::primitive_type::create(4, cdk::TYPE_INT), true))); }
#line 1524 "mml_parser.tab.c"
    break;

  case 9: /* file: tBEGIN list tEND  */
#line 80 "mml_parser.y"
                                                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, nullptr, (yyvsp[-1].sequence)), cdk::primitive_type::create(4, cdk::TYPE_INT), true))); }
#line 1530 "mml_parser.tab.c"
    break;

  case 10: /* file: tBEGIN tEND  */
#line 81 "mml_parser.y"
                                                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, nullptr, nullptr), cdk::primitive_type::create(4, cdk::TYPE_INT), true))); }
#line 1536 "mml_parser.tab.c"
    break;

  case 11: /* file: %empty  */
#line 82 "mml_parser.y"
                                                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE)); }
#line 1542 "mml_parser.tab.c"
    break;

  case 12: /* list: stmt  */
#line 85 "mml_parser.y"
                                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1548 "mml_parser.tab.c"
    break;

  case 13: /* list: list stmt  */
#line 86 "mml_parser.y"
                                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1554 "mml_parser.tab.c"
    break;

  case 14: /* stmt: expr ';'  */
#line 89 "mml_parser.y"
                                                            { (yyval.node) = new mml::evaluation_node(LINE, (yyvsp[-1].expression)); }
#line 1560 "mml_parser.tab.c"
    break;

  case 15: /* stmt: exprs tPRINT  */
#line 90 "mml_parser.y"
                                                            { (yyval.node) = new mml::print_node(LINE, (yyvsp[-1].sequence)); }
#line 1566 "mml_parser.tab.c"
    break;

  case 16: /* stmt: exprs tPRINTLN  */
#line 91 "mml_parser.y"
                                                            { (yyval.node) = new mml::print_node(LINE, (yyvsp[-1].sequence), true); }
#line 1572 "mml_parser.tab.c"
    break;

  case 17: /* stmt: tSTOP tINTEGER ';'  */
#line 92 "mml_parser.y"
                                                            { (yyval.node) = new mml::stop_node(LINE, (yyvsp[-1].i)); }
#line 1578 "mml_parser.tab.c"
    break;

  case 18: /* stmt: tSTOP ';'  */
#line 93 "mml_parser.y"
                                                            { (yyval.node) = new mml::stop_node(LINE, 0); }
#line 1584 "mml_parser.tab.c"
    break;

  case 19: /* stmt: tNEXT tINTEGER ';'  */
#line 94 "mml_parser.y"
                                                            { (yyval.node) = new mml::next_node(LINE, (yyvsp[-1].i)); }
#line 1590 "mml_parser.tab.c"
    break;

  case 20: /* stmt: tNEXT ';'  */
#line 95 "mml_parser.y"
                                                            { (yyval.node) = new mml::next_node(LINE, 1); }
#line 1596 "mml_parser.tab.c"
    break;

  case 21: /* stmt: return  */
#line 96 "mml_parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1602 "mml_parser.tab.c"
    break;

  case 22: /* stmt: tIF '(' expr ')' stmt  */
#line 97 "mml_parser.y"
                                                            { (yyval.node) = new mml::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1608 "mml_parser.tab.c"
    break;

  case 23: /* stmt: tIF '(' expr ')' stmt iffalse  */
#line 98 "mml_parser.y"
                                                            { (yyval.node) = new mml::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1614 "mml_parser.tab.c"
    break;

  case 24: /* stmt: tWHILE '(' expr ')' stmt  */
#line 99 "mml_parser.y"
                                                            { (yyval.node) = new mml::while_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1620 "mml_parser.tab.c"
    break;

  case 25: /* stmt: block  */
#line 100 "mml_parser.y"
                                                            { (yyval.node) = (yyvsp[0].blk); }
#line 1626 "mml_parser.tab.c"
    break;

  case 26: /* iffalse: tELSE stmt  */
#line 103 "mml_parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1632 "mml_parser.tab.c"
    break;

  case 27: /* iffalse: tIFX '(' expr ')' stmt  */
#line 104 "mml_parser.y"
                                                            { (yyval.node) = new mml::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1638 "mml_parser.tab.c"
    break;

  case 28: /* iffalse: tIFX '(' expr ')' stmt iffalse  */
#line 105 "mml_parser.y"
                                                            { (yyval.node) = new mml::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1644 "mml_parser.tab.c"
    break;

  case 29: /* expr: '(' expr ')'  */
#line 108 "mml_parser.y"
                                                            { (yyval.expression) = (yyvsp[-1].expression); }
#line 1650 "mml_parser.tab.c"
    break;

  case 30: /* expr: '[' expr ']'  */
#line 109 "mml_parser.y"
                                                            { (yyval.expression) = new mml::stack_alloc_node(LINE, (yyvsp[-1].expression)); }
#line 1656 "mml_parser.tab.c"
    break;

  case 31: /* expr: '+' expr  */
#line 110 "mml_parser.y"
                                                            { (yyval.expression) = new mml::identity_node(LINE, (yyvsp[0].expression)); }
#line 1662 "mml_parser.tab.c"
    break;

  case 32: /* expr: '-' expr  */
#line 111 "mml_parser.y"
                                                            { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression)); }
#line 1668 "mml_parser.tab.c"
    break;

  case 33: /* expr: lval '?'  */
#line 112 "mml_parser.y"
                                                            { (yyval.expression) = new mml::address_of_node(LINE, (yyvsp[-1].lvalue)); }
#line 1674 "mml_parser.tab.c"
    break;

  case 34: /* expr: expr '*' expr  */
#line 113 "mml_parser.y"
                                                           { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1680 "mml_parser.tab.c"
    break;

  case 35: /* expr: expr '/' expr  */
#line 114 "mml_parser.y"
                                                           { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1686 "mml_parser.tab.c"
    break;

  case 36: /* expr: expr '%' expr  */
#line 115 "mml_parser.y"
                                                           { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1692 "mml_parser.tab.c"
    break;

  case 37: /* expr: expr '+' expr  */
#line 116 "mml_parser.y"
                                                           { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1698 "mml_parser.tab.c"
    break;

  case 38: /* expr: expr '-' expr  */
#line 117 "mml_parser.y"
                                                           { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1704 "mml_parser.tab.c"
    break;

  case 39: /* expr: expr '<' expr  */
#line 118 "mml_parser.y"
                                                           { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1710 "mml_parser.tab.c"
    break;

  case 40: /* expr: expr '>' expr  */
#line 119 "mml_parser.y"
                                                           { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1716 "mml_parser.tab.c"
    break;

  case 41: /* expr: expr tLE expr  */
#line 120 "mml_parser.y"
                                                            { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1722 "mml_parser.tab.c"
    break;

  case 42: /* expr: expr tGE expr  */
#line 121 "mml_parser.y"
                                                           { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1728 "mml_parser.tab.c"
    break;

  case 43: /* expr: expr tEQ expr  */
#line 122 "mml_parser.y"
                                                           { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1734 "mml_parser.tab.c"
    break;

  case 44: /* expr: expr tNE expr  */
#line 123 "mml_parser.y"
                                                           { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1740 "mml_parser.tab.c"
    break;

  case 45: /* expr: tNOT expr  */
#line 124 "mml_parser.y"
                                                            { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 1746 "mml_parser.tab.c"
    break;

  case 46: /* expr: expr tAND expr  */
#line 125 "mml_parser.y"
                                                            { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1752 "mml_parser.tab.c"
    break;

  case 47: /* expr: expr tOR expr  */
#line 126 "mml_parser.y"
                                                            { (yyval.expression) = new cdk::or_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1758 "mml_parser.tab.c"
    break;

  case 48: /* expr: lval '=' expr  */
#line 127 "mml_parser.y"
                                                            { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 1764 "mml_parser.tab.c"
    break;

  case 49: /* expr: tINTEGER  */
#line 128 "mml_parser.y"
                                                            { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 1770 "mml_parser.tab.c"
    break;

  case 50: /* expr: tREAL  */
#line 129 "mml_parser.y"
                                                            { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 1776 "mml_parser.tab.c"
    break;

  case 51: /* expr: string  */
#line 130 "mml_parser.y"
                                                            { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1782 "mml_parser.tab.c"
    break;

  case 52: /* expr: tNULL  */
#line 131 "mml_parser.y"
                                                            { (yyval.expression) = new mml::null_node(LINE); }
#line 1788 "mml_parser.tab.c"
    break;

  case 53: /* expr: tSIZEOF '(' expr ')'  */
#line 132 "mml_parser.y"
                                                            { (yyval.expression) = new mml::sizeof_node(LINE, (yyvsp[-1].expression)); }
#line 1794 "mml_parser.tab.c"
    break;

  case 54: /* expr: tINPUT  */
#line 133 "mml_parser.y"
                                                            { (yyval.expression) = new mml::input_node(LINE); }
#line 1800 "mml_parser.tab.c"
    break;

  case 55: /* expr: lval  */
#line 134 "mml_parser.y"
                                                            { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 1806 "mml_parser.tab.c"
    break;

  case 56: /* expr: definition  */
#line 135 "mml_parser.y"
                                                            { (yyval.expression) = (yyvsp[0].expression); }
#line 1812 "mml_parser.tab.c"
    break;

  case 57: /* expr: call  */
#line 136 "mml_parser.y"
                                                            { (yyval.expression) = (yyvsp[0].expression); }
#line 1818 "mml_parser.tab.c"
    break;

  case 58: /* exprs: expr  */
#line 139 "mml_parser.y"
                                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression)); }
#line 1824 "mml_parser.tab.c"
    break;

  case 59: /* exprs: exprs ',' expr  */
#line 140 "mml_parser.y"
                                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 1830 "mml_parser.tab.c"
    break;

  case 60: /* vardec: tFOREIGN data_type tIDENTIFIER '=' expr ';'  */
#line 143 "mml_parser.y"
                                                            { (yyval.node) = new mml::variable_declaration_node(LINE, tFOREIGN,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1836 "mml_parser.tab.c"
    break;

  case 61: /* vardec: tFOREIGN data_type tIDENTIFIER ';'  */
#line 144 "mml_parser.y"
                                                            { (yyval.node) = new mml::variable_declaration_node(LINE, tFOREIGN,  (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); }
#line 1842 "mml_parser.tab.c"
    break;

  case 62: /* vardec: tFORWARD data_type tIDENTIFIER ';'  */
#line 145 "mml_parser.y"
                                                            { (yyval.node) = new mml::variable_declaration_node(LINE, tPUBLIC,  (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); }
#line 1848 "mml_parser.tab.c"
    break;

  case 63: /* vardec: tPUBLIC data_type tIDENTIFIER '=' expr ';'  */
#line 146 "mml_parser.y"
                                                            { (yyval.node) = new mml::variable_declaration_node(LINE, tPUBLIC,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1854 "mml_parser.tab.c"
    break;

  case 64: /* vardec: tPUBLIC data_type tIDENTIFIER ';'  */
#line 147 "mml_parser.y"
                                                            { (yyval.node) = new mml::variable_declaration_node(LINE, tPUBLIC,  (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); }
#line 1860 "mml_parser.tab.c"
    break;

  case 65: /* vardec: tPUBLIC tIDENTIFIER '=' expr ';'  */
#line 148 "mml_parser.y"
                                                            { (yyval.node) = new mml::variable_declaration_node(LINE, tPUBLIC,  cdk::primitive_type::create(0, cdk::TYPE_UNSPEC), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1866 "mml_parser.tab.c"
    break;

  case 66: /* vardec: data_type tIDENTIFIER '=' expr ';'  */
#line 149 "mml_parser.y"
                                                            { (yyval.node) = new mml::variable_declaration_node(LINE, tPUBLIC, (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1872 "mml_parser.tab.c"
    break;

  case 67: /* vardec: data_type tIDENTIFIER ';'  */
#line 150 "mml_parser.y"
                                                            { (yyval.node) = new mml::variable_declaration_node(LINE, tPUBLIC, (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); }
#line 1878 "mml_parser.tab.c"
    break;

  case 68: /* vardecs: vardec  */
#line 153 "mml_parser.y"
                                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1884 "mml_parser.tab.c"
    break;

  case 69: /* vardecs: vardecs vardec  */
#line 154 "mml_parser.y"
                                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1890 "mml_parser.tab.c"
    break;

  case 70: /* data_type: tTYPE_INT  */
#line 157 "mml_parser.y"
                                                            { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT); }
#line 1896 "mml_parser.tab.c"
    break;

  case 71: /* data_type: tTYPE_REAL  */
#line 158 "mml_parser.y"
                                                            { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
#line 1902 "mml_parser.tab.c"
    break;

  case 72: /* data_type: tTYPE_STRING  */
#line 159 "mml_parser.y"
                                                            { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING); }
#line 1908 "mml_parser.tab.c"
    break;

  case 73: /* data_type: tTYPE_VOID  */
#line 160 "mml_parser.y"
                                                            { (yyval.type) = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
#line 1914 "mml_parser.tab.c"
    break;

  case 74: /* data_type: tTYPE_AUTO  */
#line 161 "mml_parser.y"
                                                            { (yyval.type) = cdk::primitive_type::create(0, cdk::TYPE_UNSPEC); }
#line 1920 "mml_parser.tab.c"
    break;

  case 75: /* data_type: '[' data_type ']'  */
#line 162 "mml_parser.y"
                                                            { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1926 "mml_parser.tab.c"
    break;

  case 76: /* data_type: func_type  */
#line 163 "mml_parser.y"
                                                            { (yyval.type) = (yyvsp[0].type); }
#line 1932 "mml_parser.tab.c"
    break;

  case 77: /* func_type: output_type '<' var_types '>'  */
#line 166 "mml_parser.y"
                                                            { (yyval.type) = cdk::functional_type::create(*(yyvsp[-1].funcs), *(yyvsp[-3].funcs)); }
#line 1938 "mml_parser.tab.c"
    break;

  case 78: /* func_type: output_type '<' '>'  */
#line 167 "mml_parser.y"
                                                            { (yyval.type) = cdk::functional_type::create(std::vector<std::shared_ptr<cdk::basic_type>>(), *(yyvsp[-2].funcs)); }
#line 1944 "mml_parser.tab.c"
    break;

  case 79: /* output_type: data_type  */
#line 170 "mml_parser.y"
                                                            { (yyval.funcs) = new std::vector<std::shared_ptr<cdk::basic_type>>(); (yyval.funcs) -> push_back((yyvsp[0].type)); }
#line 1950 "mml_parser.tab.c"
    break;

  case 80: /* var_types: data_type  */
#line 173 "mml_parser.y"
                                                            { (yyval.funcs) = new std::vector<std::shared_ptr<cdk::basic_type>>(); (yyval.funcs) -> push_back((yyvsp[0].type)); }
#line 1956 "mml_parser.tab.c"
    break;

  case 81: /* var_types: var_types ',' data_type  */
#line 174 "mml_parser.y"
                                                            { (yyval.funcs) = (yyvsp[-2].funcs); (yyval.funcs) -> push_back((yyvsp[0].type)); }
#line 1962 "mml_parser.tab.c"
    break;

  case 82: /* lval: tIDENTIFIER  */
#line 177 "mml_parser.y"
                                                            { (yyval.lvalue) = new cdk::variable_node(LINE, (yyvsp[0].s)); }
#line 1968 "mml_parser.tab.c"
    break;

  case 83: /* lval: expr '[' expr ']'  */
#line 178 "mml_parser.y"
                                                            { (yyval.lvalue) = new mml::index_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1974 "mml_parser.tab.c"
    break;

  case 84: /* return: tRETURN ';'  */
#line 181 "mml_parser.y"
                                                            { (yyval.node) = new mml::return_node(LINE, nullptr); }
#line 1980 "mml_parser.tab.c"
    break;

  case 85: /* return: tRETURN expr ';'  */
#line 182 "mml_parser.y"
                                                            { (yyval.node) = new mml::return_node(LINE, (yyvsp[-1].expression)); }
#line 1986 "mml_parser.tab.c"
    break;

  case 86: /* block: '{' vardecs list '}'  */
#line 185 "mml_parser.y"
                                                            { (yyval.blk) = new mml::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1992 "mml_parser.tab.c"
    break;

  case 87: /* block: '{' list '}'  */
#line 186 "mml_parser.y"
                                                            { (yyval.blk) = new mml::block_node(LINE, nullptr, (yyvsp[-1].sequence)); }
#line 1998 "mml_parser.tab.c"
    break;

  case 88: /* block: '{' vardecs '}'  */
#line 187 "mml_parser.y"
                                                            { (yyval.blk) = new mml::block_node(LINE, nullptr, (yyvsp[-1].sequence)); }
#line 2004 "mml_parser.tab.c"
    break;

  case 89: /* block: '{' '}'  */
#line 188 "mml_parser.y"
                                                            { (yyval.blk) = new mml::block_node(LINE, nullptr, nullptr); }
#line 2010 "mml_parser.tab.c"
    break;

  case 90: /* call: expr '(' exprs ')'  */
#line 191 "mml_parser.y"
                                                            { (yyval.expression) = new mml::function_call_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].sequence)); }
#line 2016 "mml_parser.tab.c"
    break;

  case 91: /* call: expr '(' ')'  */
#line 192 "mml_parser.y"
                                                            { (yyval.expression) = new mml::function_call_node(LINE, (yyvsp[-2].expression), nullptr); }
#line 2022 "mml_parser.tab.c"
    break;

  case 92: /* call: '@' '(' exprs ')'  */
#line 193 "mml_parser.y"
                                                            { (yyval.expression) = new mml::function_call_node(LINE, nullptr, (yyvsp[-1].sequence)); }
#line 2028 "mml_parser.tab.c"
    break;

  case 93: /* call: '@' '(' ')'  */
#line 194 "mml_parser.y"
                                                            { (yyval.expression) = new mml::function_call_node(LINE, nullptr, nullptr); }
#line 2034 "mml_parser.tab.c"
    break;

  case 94: /* definition: '(' vars ')' tARROW data_type block  */
#line 197 "mml_parser.y"
                                                            { (yyval.expression) = new mml::function_definition_node(LINE, (yyvsp[-4].sequence), (yyvsp[0].blk), (yyvsp[-1].type)); }
#line 2040 "mml_parser.tab.c"
    break;

  case 95: /* definition: '(' ')' tARROW data_type block  */
#line 198 "mml_parser.y"
                                                            { (yyval.expression) = new mml::function_definition_node(LINE, nullptr, (yyvsp[0].blk), (yyvsp[-1].type)); }
#line 2046 "mml_parser.tab.c"
    break;

  case 96: /* vars: var  */
#line 201 "mml_parser.y"
                                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 2052 "mml_parser.tab.c"
    break;

  case 97: /* vars: vars ',' var  */
#line 202 "mml_parser.y"
                                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 2058 "mml_parser.tab.c"
    break;

  case 98: /* var: data_type tIDENTIFIER  */
#line 205 "mml_parser.y"
                                                            { (yyval.node) = new mml::variable_declaration_node(LINE, tPUBLIC, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 2064 "mml_parser.tab.c"
    break;

  case 99: /* string: tSTRING  */
#line 208 "mml_parser.y"
                                                            { (yyval.s) = (yyvsp[0].s); }
#line 2070 "mml_parser.tab.c"
    break;

  case 100: /* string: string tSTRING  */
#line 209 "mml_parser.y"
                                                            { (yyval.s) = (yyvsp[-1].s); (yyval.s) -> append(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2076 "mml_parser.tab.c"
    break;


#line 2080 "mml_parser.tab.c"

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
      yyerror (compiler, YY_("syntax error"));
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
                      yytoken, &yylval, compiler);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, compiler);
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
  yyerror (compiler, YY_("memory exhausted"));
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
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, compiler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 212 "mml_parser.y"

