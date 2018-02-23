/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "specbison.y" /* yacc.c:339  */

	
	extern Nodo * apID;
	extern Nodo * apFun;
	extern int valorNum;
	extern int flagDecl;
	extern int flagGlobal;
	extern int flagTipo;
	extern int flagFun;
    
	extern void yyerror(char* s);
	extern void purgeTabla(Nodo * tabla[]);
	extern void printTabla(Nodo * tabla[]);

	extern FILE *output;

	int tipoLadoIzq;
	char nombreBib[20];


#line 87 "specbison.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "specbison.tab.h".  */
#ifndef YY_YY_SPECBISON_TAB_H_INCLUDED
# define YY_YY_SPECBISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IFX = 258,
    otro = 8,
    id = 1,
    numero = 2,
    entero = 3,
    flotante = 4,
    caracter = 5,
    si = 6,
    entonces = 7,
    mientras = 9,
    haz = 10,
    regresa = 11,
    directiva = 12,
    paraleliza = 13,
    incluye = 14,
    define = 15,
    funcion = 16,
    funcionprincipal = 17,
    punto = 18,
    punto_coma = 19,
    coma = 20,
    paren_open = 22,
    paren_close = 23,
    llave_open = 24,
    llave_close = 25,
    mayor_igual = 26,
    menor_igual = 27,
    mayor = 28,
    menor = 29,
    igual = 30,
    no_igual = 31,
    mas = 32,
    menos = 33,
    por = 34,
    entre = 35
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SPECBISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 176 "specbison.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   258

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     5,     6,     7,     8,     9,    10,    11,     4,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     2,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    62,    62,    62,    62,    62,    65,    65,
      65,    65,    65,    65,    66,    69,    70,    70,    73,    73,
      73,    74,    77,    77,    78,    78,    79,    79,    82,    82,
      85,    85,    86,    89,    89,    90,    93,    93,    96,    99,
      99,    99,    99,   102,   103,   104,   107,   107,   108,   111,
     112,   112,   112,   115,   115,   118,   118,   121,   122,   125,
     125,   125,   125,   126,   127,   127,   127,   128,   128,   129,
     129,   132,   133,   136,   137,   140,   143,   144,   147,   148,
     151,   152,   153,   153,   154,   155,   155,   158,   159,   159,
     162,   163,   164,   165,   166,   167,   170,   171,   174,   175
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IFX", "otro", "id", "numero", "entero",
  "flotante", "caracter", "si", "entonces", "mientras", "haz", "regresa",
  "directiva", "paraleliza", "incluye", "define", "funcion",
  "funcionprincipal", "punto", "punto_coma", "coma", "paren_open",
  "paren_close", "llave_open", "llave_close", "mayor_igual", "menor_igual",
  "mayor", "menor", "igual", "no_igual", "mas", "menos", "por", "entre",
  "$accept", "PROGRAMA", "$@1", "$@2", "$@3", "$@4", "$@5", "PROTOTIPOS",
  "$@6", "$@7", "$@8", "$@9", "$@10", "CTES", "$@11", "DECLS", "$@12",
  "$@13", "DECL", "$@14", "$@15", "$@16", "LISTA_ID", "$@17", "L", "$@18",
  "FUN_DECLS", "$@19", "FUN_PRINCIPAL", "$@20", "FUN_DECL", "ENCA", "$@21",
  "$@22", "$@23", "TIPO", "F", "$@24", "ARGS", "$@25", "$@26", "CUERPOFUN",
  "$@27", "CUERPO", "$@28", "LISTA_INS", "INS", "$@29", "$@30", "$@31",
  "$@32", "$@33", "$@34", "$@35", "H", "INSTS", "COND", "EXP", "TERMINO",
  "FACTOR", "$@36", "$@37", "LISTA_EXP", "$@38", "RELOP", "ADOP", "MULOP", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,     8,     1,     2,     3,     4,     5,
       6,     7,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -124,    13,    -2,  -124,   -12,  -124,  -124,  -124,    19,     4,
    -124,    64,    18,    35,  -124,  -124,    46,  -124,    65,    50,
    -124,  -124,  -124,    52,    67,  -124,  -124,    56,    68,    68,
      68,  -124,  -124,    57,    51,    50,    53,  -124,  -124,  -124,
    -124,    54,    48,    58,  -124,  -124,  -124,  -124,    71,  -124,
    -124,  -124,    60,  -124,  -124,    55,  -124,    54,    76,  -124,
      -2,  -124,    61,    21,  -124,  -124,    53,  -124,  -124,  -124,
    -124,    62,    72,    63,    21,    60,  -124,  -124,    59,    -1,
      -1,  -124,    70,  -124,  -124,  -124,    69,  -124,    73,  -124,
    -124,    78,    17,    28,  -124,    74,    -1,  -124,  -124,  -124,
      51,    -1,    75,    -1,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,    -1,    -1,  -124,  -124,    -1,     2,     5,
      79,    77,     7,  -124,    -1,     9,     2,     7,    28,  -124,
    -124,  -124,  -124,  -124,    81,    82,  -124,    84,   -14,    83,
    -124,    89,    21,  -124,    86,  -124,  -124,  -124,     2,  -124,
      80,  -124,    -1,  -124,  -124,    51,  -124,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    14,     1,     0,     3,     8,    15,     0,     4,
       9,     0,    18,     0,    16,     5,     0,    10,     0,    33,
      22,    24,    26,     0,     0,    17,     6,     0,     0,     0,
       0,    19,    11,     0,     0,    33,     0,    28,    23,    25,
      27,    21,     0,     0,     7,    43,    44,    45,     0,    34,
      53,    38,    32,    20,    12,     0,    39,    21,     0,    29,
      14,    36,     0,     0,    30,    13,     0,    40,    59,    64,
      67,     0,     0,     0,    57,    32,    37,    41,     0,     0,
       0,    69,     0,    54,    58,    31,    46,    60,    80,    84,
      85,     0,     0,    76,    78,     0,     0,    63,    48,    42,
       0,     0,    82,     0,    65,    90,    91,    92,    93,    94,
      95,    96,    97,     0,     0,    98,    99,     0,     0,     0,
       0,     0,    61,    81,     0,     0,     0,    75,    77,    79,
      55,    74,    73,    68,     0,    49,    47,     0,    87,     0,
      86,    71,     0,    70,     0,    62,    88,    83,     0,    66,
       0,    51,     0,    72,    56,     0,    89,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -124,  -124,  -124,  -124,  -124,  -124,  -124,    36,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,   -30,  -124,  -124,  -124,  -124,
    -124,  -124,    37,  -124,    20,  -124,    66,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,    85,  -124,  -124,   -57,  -124,
    -124,    33,  -124,  -124,  -124,   -74,  -116,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -123,    24,   -95,    -4,    -6,
    -124,  -124,   -40,  -124,  -124,  -124,  -124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    12,    19,    33,     5,     8,    13,
      24,    42,    60,     9,    18,    15,    16,    41,    23,    28,
      29,    30,    38,    52,    59,    75,    26,    27,    44,    66,
      35,    36,    62,    77,    86,   120,    99,   100,   121,   144,
     155,    51,    57,   131,   142,    73,    74,    78,   101,   137,
      79,   126,    80,    96,   149,   133,    91,    92,    93,    94,
     124,   103,   139,   152,   113,   114,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,   119,   132,   141,    88,    89,   122,    68,   125,   146,
     132,    53,    69,     3,    70,     4,    71,    72,   127,     6,
     111,   112,    11,    90,    10,   153,    68,    63,   130,   138,
     134,    69,   132,    70,   140,    71,    72,   -21,   -21,   111,
     112,   111,   112,   111,   112,   105,   106,   107,   108,   109,
     110,   111,   112,    20,    21,    22,    17,   138,    45,    46,
      47,   -18,   -18,   -18,   115,   116,    39,    40,   150,    14,
     -35,    25,    32,    37,    31,    34,    56,    43,    54,    50,
      61,    64,    55,    58,   135,    67,    81,   118,    82,   104,
      83,    87,    97,   148,    98,    85,    65,   102,   157,    76,
     123,    49,   136,   143,    95,   -50,   145,   154,   147,   151,
     128,   129,   156,     0,     0,     0,     0,     0,     0,    48
};

static const yytype_int16 yycheck[] =
{
      74,    96,   118,   126,     5,     6,   101,     5,   103,    23,
     126,    41,    10,     0,    12,    17,    14,    15,   113,    31,
      34,    35,    18,    24,     5,   148,     5,    57,    26,   124,
      25,    10,   148,    12,    25,    14,    15,    19,    20,    34,
      35,    34,    35,    34,    35,    28,    29,    30,    31,    32,
      33,    34,    35,     7,     8,     9,    21,   152,     7,     8,
       9,     7,     8,     9,    36,    37,    29,    30,   142,     5,
      20,     6,     5,     5,    22,    19,     5,    20,    30,    26,
      25,     5,    24,    23,     5,    24,    24,    13,    16,    11,
      27,    32,    22,     4,    25,    75,    60,    24,   155,    66,
      25,    35,    25,    22,    80,    23,    22,    27,    25,    23,
     114,   117,   152,    -1,    -1,    -1,    -1,    -1,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    40,     0,    17,    45,    31,    41,    46,    51,
       5,    18,    42,    47,     5,    53,    54,    21,    52,    43,
       7,     8,     9,    56,    48,     6,    64,    65,    57,    58,
      59,    22,     5,    44,    19,    68,    69,     5,    60,    60,
      60,    55,    49,    20,    66,     7,     8,     9,    73,    64,
      26,    79,    61,    53,    30,    24,     5,    80,    23,    62,
      50,    25,    70,    53,     5,    45,    67,    24,     5,    10,
      12,    14,    15,    83,    84,    63,    79,    71,    85,    88,
      90,    24,    16,    27,    83,    62,    72,    32,     5,     6,
      24,    94,    95,    96,    97,    94,    91,    22,    25,    74,
      75,    86,    24,    99,    11,    28,    29,    30,    31,    32,
      33,    34,    35,   102,   103,    36,    37,   104,    13,    95,
      73,    76,    95,    25,    98,    95,    89,    95,    96,    97,
      26,    81,    84,    93,    25,     5,    25,    87,    95,   100,
      25,    93,    82,    22,    77,    22,    23,    25,     4,    92,
      83,    23,   101,    93,    27,    78,   100,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    40,    41,    42,    43,    44,    39,    46,    47,
      48,    49,    50,    45,    45,    51,    52,    51,    54,    55,
      53,    53,    57,    56,    58,    56,    59,    56,    61,    60,
      63,    62,    62,    65,    64,    64,    67,    66,    68,    70,
      71,    72,    69,    73,    73,    73,    75,    74,    74,    76,
      77,    78,    76,    80,    79,    82,    81,    83,    83,    85,
      86,    87,    84,    84,    88,    89,    84,    90,    84,    91,
      84,    92,    92,    93,    93,    94,    95,    95,    96,    96,
      97,    97,    98,    97,    97,    99,    97,   100,   101,   100,
     102,   102,   102,   102,   102,   102,   103,   103,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     5,     0,     0,
       5,     0,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     4,     0,     0,     3,     0,     0,     5,     2,     0,
       0,     0,     8,     1,     1,     1,     0,     3,     1,     2,
       0,     0,     6,     0,     5,     0,     4,     1,     2,     0,
       0,     0,     7,     3,     0,     0,     7,     0,     5,     0,
       6,     0,     2,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     0,     5,     1,     0,     4,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 62 "specbison.y" /* yacc.c:1646  */
    {flagGlobal = 1; flagDecl = 1; flagFun = 0;}
#line 1362 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "specbison.y" /* yacc.c:1646  */
    {flagTipo = 3; fprintf(output, "\n");}
#line 1368 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 62 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "\n");}
#line 1374 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 62 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "\n");}
#line 1380 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "specbison.y" /* yacc.c:1646  */
    {flagDecl = 0;}
#line 1386 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 65 "specbison.y" /* yacc.c:1646  */
    {flagDecl = -1; fprintf(output, "#include<");}
#line 1392 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "specbison.y" /* yacc.c:1646  */
    {strcpy(nombreBib, yytext);}
#line 1398 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 65 "specbison.y" /* yacc.c:1646  */
    {strcat(nombreBib, ".");}
#line 1404 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 65 "specbison.y" /* yacc.c:1646  */
    {strcat(nombreBib, yytext);}
#line 1410 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 65 "specbison.y" /* yacc.c:1646  */
    {flagDecl = 1; flagGlobal = -1; manejaID(nombreBib); flagGlobal = 1; fprintf(output, "%s>\n", apID->info->nombre);}
#line 1416 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 70 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "#define %s ", yytext, valorNum);}
#line 1422 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 70 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "%d\n", valorNum);}
#line 1428 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 73 "specbison.y" /* yacc.c:1646  */
    {flagDecl = 1; flagFun = 0;}
#line 1434 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 73 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, ";\n");flagDecl = 0;}
#line 1440 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 77 "specbison.y" /* yacc.c:1646  */
    {flagTipo = 3; fprintf(output, "int ");}
#line 1446 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 78 "specbison.y" /* yacc.c:1646  */
    {flagTipo = 4; fprintf(output, "float ");}
#line 1452 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 79 "specbison.y" /* yacc.c:1646  */
    {flagTipo = 5; fprintf(output, "char ");}
#line 1458 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 82 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "%s", yytext);}
#line 1464 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 85 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, ", %s", yytext);}
#line 1470 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 89 "specbison.y" /* yacc.c:1646  */
    {flagDecl = 1; flagGlobal =1; flagFun = 1;}
#line 1476 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 93 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "int main()");}
#line 1482 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 99 "specbison.y" /* yacc.c:1646  */
    {apFun = apID; fprintf(output, "%s", apFun->info->nombre);}
#line 1488 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 99 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "(");}
#line 1494 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 99 "specbison.y" /* yacc.c:1646  */
    {flagGlobal = 0; flagDecl = 1;}
#line 1500 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 102 "specbison.y" /* yacc.c:1646  */
    {flagTipo = 3; fprintf(output, "int ");}
#line 1506 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 103 "specbison.y" /* yacc.c:1646  */
    {flagTipo = 4; fprintf(output, "float ");}
#line 1512 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 104 "specbison.y" /* yacc.c:1646  */
    {flagTipo = 5; fprintf(output, "char ");}
#line 1518 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 107 "specbison.y" /* yacc.c:1646  */
    {flagFun = 0;}
#line 1524 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 107 "specbison.y" /* yacc.c:1646  */
    {apFun->info->numArgs = (yyvsp[-1]); flagDecl = 0; fprintf(output, ")");}
#line 1530 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 108 "specbison.y" /* yacc.c:1646  */
    {apFun->info->numArgs = 0; flagDecl = 0; fprintf(output, ")");}
#line 1536 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 111 "specbison.y" /* yacc.c:1646  */
    {(yyval) = 1; fprintf(output, "%s", apID->info->nombre);}
#line 1542 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 112 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "%s", apID->info->nombre);}
#line 1548 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 112 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, ", ");}
#line 1554 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 112 "specbison.y" /* yacc.c:1646  */
    {(yyval) = 1 + (yyvsp[0]);}
#line 1560 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 115 "specbison.y" /* yacc.c:1646  */
    {flagGlobal = 0; fprintf(output, "{\n");}
#line 1566 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 115 "specbison.y" /* yacc.c:1646  */
    {purgeTabla(tablaLocal); flagGlobal = 1; fprintf(output, "\n}\n\n");}
#line 1572 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 118 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "{\n");}
#line 1578 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 118 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "\n}\n");}
#line 1584 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 125 "specbison.y" /* yacc.c:1646  */
    {tipoLadoIzq = apID->info->tipo; fprintf(output, "%s", apID->info->nombre);}
#line 1590 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 125 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, " = ");}
#line 1596 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 125 "specbison.y" /* yacc.c:1646  */
    {if ((yyvsp[0]) != tipoLadoIzq) errorHandler(-4);}
#line 1602 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 125 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, ";\n");}
#line 1608 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 126 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, ";\n");}
#line 1614 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 127 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "if (");}
#line 1620 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 127 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, ") ");}
#line 1626 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 128 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "while (");}
#line 1632 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 129 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "return (");}
#line 1638 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 129 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, ");"); if ((yyvsp[-2]) != apFun->info->tipo) {errorHandler(-8);}}
#line 1644 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 140 "specbison.y" /* yacc.c:1646  */
    {if ((yyvsp[-2]) != (yyvsp[0])) errorHandler(-4); }
#line 1650 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 143 "specbison.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1656 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 144 "specbison.y" /* yacc.c:1646  */
    {if (((yyvsp[-2]) == 3) && ((yyvsp[0]) == 3)) (yyval) = 3; else if (((yyvsp[-2]) == 4) && ((yyvsp[0]) == 4)) (yyval) = 4; else errorHandler(-4);}
#line 1662 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 147 "specbison.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1668 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 148 "specbison.y" /* yacc.c:1646  */
    {if (((yyvsp[-2]) == 3) && ((yyvsp[0]) == 3)) (yyval) = 3; else if (((yyvsp[-2]) == 4) && ((yyvsp[0]) == 4)) (yyval) = 4; else errorHandler(-4);}
#line 1674 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 151 "specbison.y" /* yacc.c:1646  */
    {(yyval) = apID->info->tipo; fprintf(output, "%s", apID->info->nombre);}
#line 1680 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 152 "specbison.y" /* yacc.c:1646  */
    {apFun = apID; (yyval) = apFun->info->tipo; fprintf(output, "%s ()", apFun->info->nombre); if (apFun->info->numArgs != 0) errorHandler(-5);}
#line 1686 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 153 "specbison.y" /* yacc.c:1646  */
    {apFun = apID; fprintf(output, "%s(", apFun->info->nombre);}
#line 1692 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 153 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, ")"); (yyval) = apFun->info->tipo; if (apFun->info->numArgs != (yyvsp[-1])) errorHandler(-5);}
#line 1698 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 154 "specbison.y" /* yacc.c:1646  */
    { (yyval) = 3; fprintf(output, "%d", valorNum);}
#line 1704 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 155 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, "(");}
#line 1710 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 155 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, ")"); (yyval) = (yyvsp[-1]);}
#line 1716 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 158 "specbison.y" /* yacc.c:1646  */
    {(yyval) = 1;}
#line 1722 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 159 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, ", ");}
#line 1728 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 159 "specbison.y" /* yacc.c:1646  */
    {(yyval) = 1 + (yyvsp[0]);}
#line 1734 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 162 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, " >= ");}
#line 1740 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 163 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, " <= ");}
#line 1746 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 164 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, " > ");}
#line 1752 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 165 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, " < ");}
#line 1758 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 166 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, " == ");}
#line 1764 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 167 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, " != ");}
#line 1770 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 170 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, " + ");}
#line 1776 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 171 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, " - ");}
#line 1782 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 174 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, " * ");}
#line 1788 "specbison.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 175 "specbison.y" /* yacc.c:1646  */
    {fprintf(output, " / ");}
#line 1794 "specbison.tab.c" /* yacc.c:1646  */
    break;


#line 1798 "specbison.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
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
  return yyresult;
}
#line 177 "specbison.y" /* yacc.c:1906  */


void yyerror(char *cadena){
	errorHandler(-6);
	
}
