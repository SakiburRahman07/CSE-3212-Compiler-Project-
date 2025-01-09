
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "pf.y"

	// Adding all the header files and function definations
	
	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	#include<string.h>
	int yylex(void);
	void yyerror(char *s);
	extern FILE *yyin; // Add this line
	extern FILE *yyout;
	
	int no_var = 0;		// This variable will keep track of the total variables used.
	
	// Defining a structure to handle the properties of variables.
	
	struct variable_structure{
		char var_name[20];
		int var_type;
		union {
			int ival;
			float fval;
			char cval;
			char* sval;  // Add string value
		} value;
	}variable[100];
	
	// Structure to store function information
	struct function_structure {
	    char func_name[20];
	    int return_type;
	    char* code_block;
	    double return_value;
	} functions[100];

	int func_count = 0;

	// Function to find a function by name
	int get_function_index(char* name) {
	    for(int i = 0; i < func_count; i++) {
	        if(!strcmp(functions[i].func_name, name)) {
	            return i;
	        }
	    }
	    return -1;
	}

	// Function for searching if the present variable name has already been used.
	
	int search_var(char name[20]){
		int i;
		for(i=0; i<no_var; i++){
			if(!strcmp(variable[i].var_name, name)){
				return 1;
			}
		}
		return 0;
	}
	
	// Setting the type of a variable (in integer value)
	
	void set_var_type(int type){
		int i;
		for(i=0; i<no_var; i++){
			if(variable[i].var_type == -1){
				variable[i].var_type = type;
			}
		}
	}
	
	// Finind the index of any variable
	
	int get_var_index(char name[20]){
		int i;
		for(i=0; i<no_var; i++){
			if(!strcmp(variable[i].var_name, name)){
				return i;
			}
		}
		return -1;
	}
	


/* Line 189 of yacc.c  */
#line 158 "pf.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MAIN = 258,
     INT = 259,
     CHAR = 260,
     FLOAT = 261,
     POWER = 262,
     FACTO = 263,
     PRIME = 264,
     READ = 265,
     PRINT = 266,
     IF = 267,
     ELIF = 268,
     ELSE = 269,
     SWITCH = 270,
     CASE = 271,
     DEFAULT = 272,
     FROM = 273,
     TO = 274,
     INC = 275,
     DEC = 276,
     MAX = 277,
     MIN = 278,
     ID = 279,
     NUM = 280,
     PLUS = 281,
     MINUS = 282,
     MUL = 283,
     DIV = 284,
     EQUAL = 285,
     NOTEQUAL = 286,
     GT = 287,
     GOE = 288,
     LT = 289,
     LOE = 290,
     STRING = 291,
     STRING_LITERAL = 292,
     FUNCTION = 293,
     RETURN = 294,
     MOD = 295,
     POW = 296,
     SQRT = 297,
     ABS = 298,
     LOG = 299,
     SIN = 300,
     COS = 301,
     TAN = 302,
     INCREMENT = 303,
     DECREMENT = 304,
     UMINUS = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 85 "pf.y"

	double val;
	char* stringValue;



/* Line 214 of yacc.c  */
#line 251 "pf.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 263 "pf.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  232

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      53,    54,     2,     2,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
       2,    57,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    13,    20,    23,    25,    34,
      38,    41,    44,    47,    50,    53,    56,    59,    62,    65,
      68,    71,    74,    77,    78,    83,    91,    97,   103,   111,
     119,   125,   131,   137,   145,   148,   155,   156,   161,   171,
     181,   191,   200,   201,   206,   207,   211,   215,   219,   223,
     227,   231,   235,   237,   239,   241,   243,   247,   249,   254,
     258,   262,   267,   269,   273,   277,   279,   283,   287,   291,
     295,   297,   301,   306,   311,   316,   321,   326,   331,   333
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    61,    60,    -1,    60,    -1,     3,    51,
      64,    52,    -1,     3,    53,    54,    51,    64,    52,    -1,
      61,    62,    -1,    62,    -1,    38,    24,    53,    54,    51,
      64,    63,    52,    -1,    39,    86,    55,    -1,    82,    64,
      -1,    85,    64,    -1,    78,    64,    -1,    77,    64,    -1,
      73,    64,    -1,    71,    64,    -1,    72,    64,    -1,    66,
      64,    -1,    67,    64,    -1,    68,    64,    -1,    70,    64,
      -1,    69,    64,    -1,    65,    64,    -1,    -1,    24,    53,
      54,    55,    -1,     7,    53,    25,    56,    25,    54,    55,
      -1,     8,    53,    25,    54,    55,    -1,     9,    53,    25,
      54,    55,    -1,    22,    53,    24,    56,    24,    54,    55,
      -1,    23,    53,    24,    56,    24,    54,    55,    -1,    11,
      53,    24,    54,    55,    -1,    11,    53,    37,    54,    55,
      -1,    10,    53,    24,    54,    55,    -1,    15,    53,    24,
      54,    51,    74,    52,    -1,    75,    76,    -1,    16,    25,
      51,    64,    52,    75,    -1,    -1,    17,    51,    64,    52,
      -1,    18,    24,    19,    25,    20,    25,    51,    64,    52,
      -1,    18,    24,    19,    25,    21,    25,    51,    64,    52,
      -1,    12,    53,    81,    54,    51,    64,    52,    79,    80,
      -1,    13,    53,    81,    54,    51,    64,    52,    79,    -1,
      -1,    14,    51,    64,    52,    -1,    -1,    86,    30,    86,
      -1,    86,    31,    86,    -1,    86,    32,    86,    -1,    86,
      33,    86,    -1,    86,    34,    86,    -1,    86,    35,    86,
      -1,    83,    84,    55,    -1,     4,    -1,     6,    -1,     5,
      -1,    36,    -1,    84,    56,    24,    -1,    24,    -1,    24,
      57,    86,    55,    -1,    24,    48,    55,    -1,    24,    49,
      55,    -1,    24,    57,    37,    55,    -1,    87,    -1,    87,
      26,    88,    -1,    87,    27,    88,    -1,    88,    -1,    88,
      28,    89,    -1,    88,    29,    89,    -1,    88,    40,    89,
      -1,    89,    41,    88,    -1,    89,    -1,    53,    87,    54,
      -1,    42,    53,    87,    54,    -1,    43,    53,    87,    54,
      -1,    44,    53,    87,    54,    -1,    45,    53,    87,    54,
      -1,    46,    53,    87,    54,    -1,    47,    53,    87,    54,
      -1,    24,    -1,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   110,   110,   115,   123,   126,   131,   134,   139,   149,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   170,   184,   193,   212,   228,   260,
     292,   307,   314,   322,   326,   329,   333,   337,   341,   353,
     380,   391,   400,   404,   408,   415,   423,   431,   439,   447,
     455,   466,   470,   471,   472,   473,   475,   487,   503,   521,
     534,   547,   564,   566,   567,   568,   570,   571,   579,   587,
     590,   592,   593,   601,   602,   610,   611,   612,   613,   628
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "INT", "CHAR", "FLOAT", "POWER",
  "FACTO", "PRIME", "READ", "PRINT", "IF", "ELIF", "ELSE", "SWITCH",
  "CASE", "DEFAULT", "FROM", "TO", "INC", "DEC", "MAX", "MIN", "ID", "NUM",
  "PLUS", "MINUS", "MUL", "DIV", "EQUAL", "NOTEQUAL", "GT", "GOE", "LT",
  "LOE", "STRING", "STRING_LITERAL", "FUNCTION", "RETURN", "MOD", "POW",
  "SQRT", "ABS", "LOG", "SIN", "COS", "TAN", "INCREMENT", "DECREMENT",
  "UMINUS", "'{'", "'}'", "'('", "')'", "';'", "','", "'='", "$accept",
  "program", "main", "function_list", "function", "return_statement",
  "code", "function_call", "power_code", "factorial_code", "prime_code",
  "max_code", "min_code", "print_code", "read_code", "switch_code",
  "case_code", "casenum_code", "default_code", "for_code", "condition",
  "else_if", "elsee", "bool_expression", "declaration", "TYPE", "ID1",
  "assignment", "expression", "e", "f", "t", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   123,   125,    40,    41,    59,    44,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    61,    62,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    65,    66,    67,    68,    69,    70,
      71,    71,    72,    73,    74,    75,    75,    76,    77,    77,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    82,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    85,    86,    87,    87,    87,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     4,     6,     2,     1,     8,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     0,     4,     7,     5,     5,     7,     7,
       5,     5,     5,     7,     2,     6,     0,     4,     9,     9,
       9,     8,     0,     4,     0,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     3,     1,     4,     3,
       3,     4,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     4,     4,     4,     4,     4,     4,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     0,     7,    23,     0,     0,
       1,     2,     6,    52,    54,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
      22,    17,    18,    19,    21,    20,    15,    16,    14,    13,
      12,    10,    57,     0,    11,    23,     0,     0,     0,     0,
       0,     0,     0,    78,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    65,    70,     0,     0,     0,
       0,    59,    60,     0,     0,     0,    51,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    61,    58,    56,     5,     0,     0,    26,    27,    32,
      30,    31,     0,     0,     0,     0,     0,     0,    71,    23,
      45,    46,    47,    48,    49,    50,    63,    64,    66,    67,
      68,    69,    36,     0,     0,     0,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,    25,    42,     0,    33,
       0,    34,    23,    23,    28,    29,     9,     0,    44,    23,
      23,     0,     0,     0,     0,    40,     0,     0,    38,    39,
       0,    23,    36,    37,     0,     0,    35,    23,    43,     0,
      42,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,   178,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,   188,   189,   201,    38,
      39,   208,   215,    92,    40,    41,    73,    42,    93,    94,
      95,    96
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
       9,    58,     7,    93,   -78,     9,   -78,    12,    47,    57,
     -78,   -78,   -78,   -78,   -78,   -78,    60,    70,    71,    72,
      73,    74,    75,    79,    76,    78,    59,   -78,    53,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,   108,    12,    82,    81,   111,   112,   113,   115,    25,
      45,   116,    80,   117,   118,    89,    90,    92,     8,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -30,   -78,    12,    96,    94,    95,    97,
      98,    99,   100,   -78,   -78,   102,   103,   104,   105,   106,
     107,    45,   109,    87,    88,    31,   120,   110,   123,   114,
     119,   -78,   -78,   121,   122,   124,   -78,   138,    91,    12,
     140,   127,   128,   129,   130,   131,    45,    45,    45,    45,
      45,    45,     2,   136,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,   137,    37,   142,   143,
     -78,   -78,   -78,   -78,   -78,   132,   135,   -78,   -78,   -78,
     -78,   -78,    11,    40,    46,    48,    50,    52,   -78,    12,
     -78,   -78,   -78,   -78,   -78,   -78,    31,    31,   -78,   -78,
     -78,   -78,   152,   144,   147,   139,   141,    45,   126,   145,
     -78,   -78,   -78,   -78,   -78,   -78,   149,   165,   150,   174,
     146,   148,   151,   153,   154,   -78,   -78,   181,   156,   -78,
     159,   -78,    12,    12,   -78,   -78,   -78,   158,   182,    12,
      12,   160,   161,    45,   163,   -78,   164,   166,   -78,   -78,
     167,    12,   152,   -78,   168,   170,   -78,    12,   -78,   171,
     181,   -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   198,   -78,   199,   -78,   -29,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -17,   -78,   -78,
     -78,   -15,   -78,     4,   -78,   -78,   -78,   -78,   -43,   -77,
     -67,   -37
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     1,    74,   122,   105,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   106,   107,    22,   130,   131,
      23,     9,    83,    84,    24,    25,    26,   130,   131,   152,
     153,   154,   155,   156,   157,   104,   108,     2,    27,    81,
      85,    86,    87,    88,    89,    90,   158,   173,   174,   132,
     133,    91,    82,   166,   167,   180,   130,   131,   171,    83,
      84,   134,   130,   131,   130,   131,   130,   131,   130,   131,
     145,   160,   161,   162,   163,   164,   165,    85,    86,    87,
      88,    89,    90,    10,   181,   168,   169,   170,    91,    98,
     182,    43,   183,    52,   184,    59,   185,    55,    56,     7,
      44,     8,    57,    45,   130,   131,    58,   124,   125,   126,
     127,   128,   129,    46,    47,    48,    49,    50,    51,    53,
     186,    54,    72,    75,   194,    76,    77,    78,    79,    80,
      97,    99,   100,   144,   101,   102,   103,   109,   137,   111,
     110,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   135,   143,   123,   136,   146,   175,   176,   187,   190,
     138,   177,   191,   211,   212,   139,   140,   141,   195,   142,
     216,   217,   147,   148,   149,   150,   151,   159,   172,   179,
     198,   200,   225,   192,   207,   193,   214,   202,   229,   203,
     196,   197,   199,    11,    12,   226,   204,   209,   205,   206,
     210,   213,   218,   219,   221,   231,   222,   220,   223,   227,
       0,   224,   228,   230
};

static const yytype_int16 yycheck[] =
{
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     3,    42,    91,    58,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    55,    56,    15,    26,    27,
      18,    24,    24,    25,    22,    23,    24,    26,    27,   116,
     117,   118,   119,   120,   121,    37,    75,    38,    36,    24,
      42,    43,    44,    45,    46,    47,    54,    20,    21,    28,
      29,    53,    37,   130,   131,    54,    26,    27,   135,    24,
      25,    40,    26,    27,    26,    27,    26,    27,    26,    27,
     109,   124,   125,   126,   127,   128,   129,    42,    43,    44,
      45,    46,    47,     0,    54,   132,   133,   134,    53,    19,
      54,    54,    54,    24,    54,    52,    54,    48,    49,    51,
      53,    53,    53,    53,    26,    27,    57,    30,    31,    32,
      33,    34,    35,    53,    53,    53,    53,    53,    53,    53,
     159,    53,    24,    51,   177,    54,    25,    25,    25,    24,
      24,    24,    24,    52,    55,    55,    54,    51,    25,    54,
      56,    54,    54,    54,    54,    53,    53,    53,    53,    53,
      53,    41,    24,    54,    54,    25,    24,    24,    16,    25,
      56,    39,    25,   202,   203,    56,    55,    55,    52,    55,
     209,   210,    55,    55,    55,    55,    55,    51,    51,    54,
      25,    17,   221,    54,    13,    54,    14,    51,   227,    51,
      55,    52,    52,     5,     5,   222,    55,    51,    55,    55,
      51,    53,    52,    52,    51,   230,    52,   213,    52,    51,
      -1,    54,    52,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    38,    59,    60,    61,    62,    51,    53,    24,
       0,    60,    62,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    15,    18,    22,    23,    24,    36,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    77,    78,
      82,    83,    85,    54,    53,    53,    53,    53,    53,    53,
      53,    53,    24,    53,    53,    48,    49,    53,    57,    52,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    24,    84,    64,    51,    54,    25,    25,    25,
      24,    24,    37,    24,    25,    42,    43,    44,    45,    46,
      47,    53,    81,    86,    87,    88,    89,    24,    19,    24,
      24,    55,    55,    54,    37,    86,    55,    56,    64,    51,
      56,    54,    54,    54,    54,    54,    53,    53,    53,    53,
      53,    53,    87,    54,    30,    31,    32,    33,    34,    35,
      26,    27,    28,    29,    40,    41,    54,    25,    56,    56,
      55,    55,    55,    24,    52,    64,    25,    55,    55,    55,
      55,    55,    87,    87,    87,    87,    87,    87,    54,    51,
      86,    86,    86,    86,    86,    86,    88,    88,    89,    89,
      89,    88,    51,    20,    21,    24,    24,    39,    63,    54,
      54,    54,    54,    54,    54,    54,    64,    16,    74,    75,
      25,    25,    54,    54,    86,    52,    55,    52,    25,    52,
      17,    76,    51,    51,    55,    55,    55,    13,    79,    51,
      51,    64,    64,    53,    14,    80,    64,    64,    52,    52,
      81,    51,    52,    52,    54,    64,    75,    51,    52,    64,
      52,    79
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
      yyerror (YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 2:

/* Line 1455 of yacc.c  */
#line 110 "pf.y"
    {
            printf("\nValid program\n");
            printf("\nNo of variables--> %d", no_var);
            (yyval.val) = (yyvsp[(1) - (2)].val);
        ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 115 "pf.y"
    {
            printf("\nValid program\n");
            printf("\nNo of variables--> %d", no_var);
            (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 123 "pf.y"
    {
    (yyval.val) = (yyvsp[(3) - (4)].val);  // Pass up the value from code
;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 126 "pf.y"
    {  // Add this rule to handle ()
    (yyval.val) = (yyvsp[(5) - (6)].val);
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 131 "pf.y"
    {
        (yyval.val) = (yyvsp[(2) - (2)].val);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 134 "pf.y"
    {
        (yyval.val) = (yyvsp[(1) - (1)].val);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 139 "pf.y"
    {
            if (func_count < 100) {
                strcpy(functions[func_count].func_name, (yyvsp[(2) - (8)].stringValue));
                functions[func_count].return_value = (yyvsp[(7) - (8)].val);
                func_count++;
                printf("\nFunction defined: %s", (yyvsp[(2) - (8)].stringValue));
            }
        ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 149 "pf.y"
    {
            (yyval.val) = (yyvsp[(2) - (3)].val);
        ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 154 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 155 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 156 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 157 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 158 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 159 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 160 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 161 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 162 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 163 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 164 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 165 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 166 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 167 "pf.y"
    { (yyval.val) = 0; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 170 "pf.y"
    {
    int idx = get_function_index((yyvsp[(1) - (4)].stringValue));
    if(idx != -1) {
        printf("\nFunction called: %s", functions[idx].func_name);
        (yyval.val) = functions[idx].return_value;  // Set the return value
    } else {
        yyerror("Function not defined");
        (yyval.val) = 0;  // Default value on error
    }
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 184 "pf.y"
    {		
	int i;
	i = pow((yyvsp[(3) - (7)].val), (yyvsp[(5) - (7)].val));
	printf("\nPower function value--> %d ", i);
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 193 "pf.y"
    {
	int j = (yyvsp[(3) - (5)].val);
	int i, result;
	result = 1;
	if(j==0){
		printf("\nFactorial of %d is %d", j, result);
	}
	else{
		for(i = 1; i <= j; i++){
			result = result*i;
		}
		printf("\nFactorial of %d is %d", j, result);
	}
	
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 212 "pf.y"
    {
	int n, i, flag = 0;
	n = (yyvsp[(3) - (5)].val);
	for (i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			flag = 1;
			break;
		}
	}
    printf("\n%d", flag);

;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 228 "pf.y"
    {
	int i = get_var_index((yyvsp[(3) - (7)].stringValue));
	int j = get_var_index((yyvsp[(5) - (7)].stringValue));
	int k,l;
	if((variable[i].var_type == 1) &&(variable[j].var_type == 1) ){
		k = variable[i].value.ival;
		l = variable[j].value.ival;
		if(l>k){
			printf("\nMax value is--> %d", l);
		}
		else{
			printf("\nMax value is--> %d", k);
		}
	}
	else if((variable[i].var_type == 2) &&(variable[j].var_type == 2) ){
		k = variable[i].value.fval;
		l = variable[j].value.fval;
		if(l>k){
			printf("\nMax value is--> %f", l);
		}
		else{
			printf("\nMax value is--> %f", k);
		}
	}
	else{
		printf("\nNot integer or float variable");
	}
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 260 "pf.y"
    {
	int i = get_var_index((yyvsp[(3) - (7)].stringValue));
	int j = get_var_index((yyvsp[(5) - (7)].stringValue));
	int k,l;
	if((variable[i].var_type == 1) &&(variable[j].var_type == 1) ){
		k = variable[i].value.ival;
		l = variable[j].value.ival;
		if(l<k){
			printf("\nMin value is--> %d", l);
		}
		else{
			printf("\nMin value is--> %d", k);
		}
	}
	else if((variable[i].var_type == 2) &&(variable[j].var_type == 2) ){
		k = variable[i].value.fval;
		l = variable[j].value.fval;
		if(l<k){
			printf("\nMin value is--> %f", l);
		}
		else{
			printf("\nMin value is--> %f", k);
		}
	}
	else{
		printf("\nNot integer or float variable");
	}
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 292 "pf.y"
    {
        int i = get_var_index((yyvsp[(3) - (5)].stringValue));
        if(variable[i].var_type == 0){  // For char type
            printf("\nVariable name--> %s, Value--> %c", variable[i].var_name, variable[i].value.cval);
        }
        else if(variable[i].var_type == 1){
            printf("\nVariable name--> %s, Value--> %d", variable[i].var_name, variable[i].value.ival);
        }
        else if(variable[i].var_type == 2){
            printf("\nVariable name--> %s, Value--> %f", variable[i].var_name, variable[i].value.fval);
        }
        else if(variable[i].var_type == 3){
            printf("\nVariable name--> %s, Value--> %s", variable[i].var_name, variable[i].value.sval);
        }
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 307 "pf.y"
    {
        printf("\n%s", (yyvsp[(3) - (5)].stringValue));  // Print the string literal directly
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 314 "pf.y"
    {
	int i = get_var_index((yyvsp[(3) - (5)].stringValue));
	printf("\nRead command found for variabale--> %s, but no further implementaion\n",variable[i].var_name);
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 322 "pf.y"
    {
	printf("\nSwitch-case structure detected.");
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 329 "pf.y"
    {
        printf("\nCase no--> %d", (yyvsp[(2) - (6)].val));
        (yyval.val) = (yyvsp[(4) - (6)].val);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 333 "pf.y"
    {
        (yyval.val) = 0;  // Add action for empty rule
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 341 "pf.y"
    {
	printf("\nFor loop detected");
	int ii = get_var_index((yyvsp[(2) - (9)].stringValue));
	int i = variable[ii].value.ival;  // Changed from variable[ii].ival
	int j = (yyvsp[(4) - (9)].val);
	int inc = (yyvsp[(6) - (9)].val);
	int k;
	for(k=i; k<j; k=k+inc){
		printf("\nFrom-To Loop running-->");
	}
		
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 353 "pf.y"
    {
	printf("\nFor loop detected");
	int ii = get_var_index((yyvsp[(2) - (9)].stringValue));
	int i = variable[ii].value.ival;  // Changed from variable[ii].ival
	int j = (yyvsp[(4) - (9)].val);
	int dec = (yyvsp[(6) - (9)].val);
	int k;
	for(k=i; k<j; k=k-dec){
		printf("\nFrom-To Loop running-->");
	}
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 380 "pf.y"
    {
	printf("\nIF condition detected");
	int i = (yyvsp[(3) - (9)].val);
	if(i==1){
		printf("\nIF condition is true");
	}
	else{
		printf("\nIF condition false");
	}
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 391 "pf.y"
    {
        if((yyvsp[(3) - (8)].val) == 1) {
            (yyval.val) = (yyvsp[(6) - (8)].val);  // Use value from if block
            printf("\nELIF condition true");
        } else {
            (yyval.val) = (yyvsp[(8) - (8)].val);  // Use value from next else_if
            printf("\nELIF condition false");
        }
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 400 "pf.y"
    { 
        (yyval.val) = 0;  // Return 0 for no elif
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 404 "pf.y"
    {
        (yyval.val) = (yyvsp[(3) - (4)].val);  // Return value from else block
        printf("\nELSE condition is detected");
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 408 "pf.y"
    { 
        (yyval.val) = 0;  // Return 0 for no else
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 415 "pf.y"
    {
	if((yyvsp[(1) - (3)].val)==(yyvsp[(3) - (3)].val)){
		(yyval.val) = 1;
	}
	else{
		(yyval.val) = 0;
	}
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 423 "pf.y"
    {
	if((yyvsp[(1) - (3)].val)!=(yyvsp[(3) - (3)].val)){
		(yyval.val) = 1;
	}
	else{
		(yyval.val) = 0;
	}
;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 431 "pf.y"
    {
	if((yyvsp[(1) - (3)].val)>(yyvsp[(3) - (3)].val)){
		(yyval.val) = 1;
	}
	else{
		(yyval.val) = 0;
	}
;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 439 "pf.y"
    {
	if((yyvsp[(1) - (3)].val)>=(yyvsp[(3) - (3)].val)){
		(yyval.val) = 1;
	}
	else{
		(yyval.val) = 0;
	}
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 447 "pf.y"
    {
	if((yyvsp[(1) - (3)].val)<(yyvsp[(3) - (3)].val)){
		(yyval.val) = 1;
	}
	else{
		(yyval.val) = 0;
	}
;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 455 "pf.y"
    {
	if((yyvsp[(1) - (3)].val)<=(yyvsp[(3) - (3)].val)){
		(yyval.val) = 1;
	}
	else{
		(yyval.val) = 0;
	}
;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 466 "pf.y"
    {
	set_var_type((yyvsp[(1) - (3)].val));
;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 470 "pf.y"
    {(yyval.val) = 1; printf("\nVariable type--> Integer");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 471 "pf.y"
    {(yyval.val) = 2; printf("\nVariable type--> Float");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 472 "pf.y"
    {(yyval.val) = 0; printf("\nVariable type--> Character");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 473 "pf.y"
    {(yyval.val) = 3; printf("\nVariable type--> String");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 475 "pf.y"
    {
	if(search_var((yyvsp[(3) - (3)].stringValue))==0){
		printf("\nValid declaration");
		strcpy(variable[no_var].var_name, (yyvsp[(3) - (3)].stringValue));
		printf("\nVariable name--> %s", (yyvsp[(3) - (3)].stringValue));
		variable[no_var].var_type =  -1;
		no_var = no_var + 1;
	}
	else{
		printf("\nVariable is already used");
	}
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 487 "pf.y"
    {
	if(search_var((yyvsp[(1) - (1)].stringValue))==0){
		printf("\nValid declaration");
		strcpy(variable[no_var].var_name, (yyvsp[(1) - (1)].stringValue));
		printf("\nVariable name--> %s", (yyvsp[(1) - (1)].stringValue));
		variable[no_var].var_type =  -1;
		no_var = no_var + 1;
	}
	else{
		printf("\nVariable is already used");
	}
	strcpy((yyval.stringValue), (yyvsp[(1) - (1)].stringValue));
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 503 "pf.y"
    {
        (yyval.val) = (yyvsp[(3) - (4)].val);
        if(search_var((yyvsp[(1) - (4)].stringValue))==1){
            int i = get_var_index((yyvsp[(1) - (4)].stringValue));
            if(variable[i].var_type==0){
                variable[i].value.cval = (char)(yyvsp[(3) - (4)].val);
                printf("\nAssigning character value: %c", variable[i].value.cval);
            }
            else if(variable[i].var_type==1){
                variable[i].value.ival = (int)(yyvsp[(3) - (4)].val);
                printf("\nVariable value--> %d", variable[i].value.ival);
            }
            else if(variable[i].var_type==2){
                variable[i].value.fval = (float)(yyvsp[(3) - (4)].val);
                printf("\nVariable value--> %f", variable[i].value.fval);
            }
        }
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 521 "pf.y"
    {
        if(search_var((yyvsp[(1) - (3)].stringValue))==1){
            int i = get_var_index((yyvsp[(1) - (3)].stringValue));
            if(variable[i].var_type==1){
                (yyval.val) = variable[i].value.ival++;
                printf("\nVariable value--> %d", variable[i].value.ival);
            }
            else if(variable[i].var_type==2){
                (yyval.val) = variable[i].value.fval++;
                printf("\nVariable value--> %f", variable[i].value.fval);
            }
        }
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 534 "pf.y"
    {
        if(search_var((yyvsp[(1) - (3)].stringValue))==1){
            int i = get_var_index((yyvsp[(1) - (3)].stringValue));
            if(variable[i].var_type==1){
                (yyval.val) = variable[i].value.ival--;
                printf("\nVariable value--> %d", variable[i].value.ival);
            }
            else if(variable[i].var_type==2){
                (yyval.val) = variable[i].value.fval--;
                printf("\nVariable value--> %f", variable[i].value.fval);
            }
        }
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 547 "pf.y"
    {
        if(search_var((yyvsp[(1) - (4)].stringValue))==1){
            int i = get_var_index((yyvsp[(1) - (4)].stringValue));
            if(variable[i].var_type==3){
                variable[i].value.sval = strdup((yyvsp[(3) - (4)].stringValue));
                printf("\nAssigning string value: %s", variable[i].value.sval);
            }
            else{
                printf("\nType mismatch error\n");
            }
        }
        else{
            printf("\nVariable is not declared\n");
        }
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 564 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (1)].val);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 566 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (3)].val) + (yyvsp[(3) - (3)].val); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 567 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (3)].val) - (yyvsp[(3) - (3)].val);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 568 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (1)].val);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 570 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (3)].val) * (yyvsp[(3) - (3)].val);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 571 "pf.y"
    {
		if((yyvsp[(3) - (3)].val) != 0) {
			(yyval.val) = (yyvsp[(1) - (3)].val) / (yyvsp[(3) - (3)].val);
		} else {
			yyerror("Division by zero");
			(yyval.val) = 0;
		}
	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 579 "pf.y"
    {
		if((yyvsp[(3) - (3)].val) != 0) {
			(yyval.val) = fmod((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val));
		} else {
			yyerror("Modulo by zero");
			(yyval.val) = 0;
		}
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 587 "pf.y"
    {
		(yyval.val) = pow((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val));
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 590 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (1)].val);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 592 "pf.y"
    {(yyval.val) = (yyvsp[(2) - (3)].val);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 593 "pf.y"
    {
		if((yyvsp[(3) - (4)].val) >= 0) {
			(yyval.val) = sqrt((yyvsp[(3) - (4)].val));
		} else {
			yyerror("Square root of negative number");
			(yyval.val) = 0;
		}
	;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 601 "pf.y"
    { (yyval.val) = fabs((yyvsp[(3) - (4)].val)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 602 "pf.y"
    {
		if((yyvsp[(3) - (4)].val) > 0) {
			(yyval.val) = log((yyvsp[(3) - (4)].val));
		} else {
			yyerror("Logarithm of non-positive number");
			(yyval.val) = 0;
		}
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 610 "pf.y"
    { (yyval.val) = sin((yyvsp[(3) - (4)].val)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 611 "pf.y"
    { (yyval.val) = cos((yyvsp[(3) - (4)].val)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 612 "pf.y"
    { (yyval.val) = tan((yyvsp[(3) - (4)].val)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 613 "pf.y"
    {
		int id_index = get_var_index((yyvsp[(1) - (1)].stringValue));
		if(id_index == -1) {
			yyerror("VARIABLE DOESN'T EXIST");
			(yyval.val) = 0;
		} else {
			if(variable[id_index].var_type == 0) {
				(yyval.val) = (double)variable[id_index].value.cval;
			} else if(variable[id_index].var_type == 1) {
				(yyval.val) = variable[id_index].value.ival;
			} else if(variable[id_index].var_type == 2) {
				(yyval.val) = variable[id_index].value.fval;
			}
		}
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 628 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (1)].val);;}
    break;



/* Line 1455 of yacc.c  */
#line 2527 "pf.tab.c"
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
      yyerror (YY_("syntax error"));
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
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 631 "pf.y"


void yyerror(char *s)
{
	fprintf(stderr, "\n%s", s);
}

int main(){
	yyin = fopen("test.txt", "r");
	yyout = freopen("testout.txt", "w", stdout);
	yyparse();
	return 0;
}
