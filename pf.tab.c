
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
	
	int get_var_index(const char* name) {
		int i;
		for(i=0; i<no_var; i++){
			if(strcmp(variable[i].var_name, name) == 0){
				return i;
			}
		}
		return -1;
	}
	
	// Helper function to determine expression type
	int get_expression_type(double value) {
		// Check if value is an integer
		if(value == (int)value) {
			return 1;  // Integer type
		}
		return 2;  // Float type
	}
	
	int if_executed = 0;  // Global flag to track if any if/elif block was executed

	int code_result = 0;  // To store code block execution results

	// Add this to the global declarations at the top
	struct function_result {
	    char name[50];
	    double value;
	} function_results[100];

	int result_count = 0;



/* Line 189 of yacc.c  */
#line 179 "pf.tab.c"

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
     AND = 305,
     OR = 306,
     NOT = 307,
     NEQ = 308,
     STRICT_EQUAL = 309,
     STRICT_NEQ = 310,
     WHILE = 311,
     UMINUS = 312
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 106 "pf.y"

	double val;
	char* stringValue;



/* Line 214 of yacc.c  */
#line 279 "pf.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 291 "pf.tab.c"

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
#define YYLAST   262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  258

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      60,    61,     2,     2,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    62,
       2,    64,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    13,    20,    23,    25,    34,
      38,    41,    44,    47,    50,    53,    56,    59,    62,    65,
      68,    71,    74,    77,    80,    81,    86,    94,   100,   106,
     114,   122,   128,   134,   140,   148,   151,   158,   159,   164,
     174,   184,   193,   198,   207,   208,   210,   214,   218,   220,
     224,   228,   232,   236,   238,   242,   247,   252,   257,   262,
     267,   272,   274,   276,   280,   284,   287,   291,   295,   299,
     303,   307,   311,   315,   319,   323,   327,   331,   333,   335,
     337,   339,   343,   345,   350,   354,   358,   363
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      66,     0,    -1,    68,    67,    -1,    67,    -1,     3,    58,
      71,    59,    -1,     3,    60,    61,    58,    71,    59,    -1,
      68,    69,    -1,    69,    -1,    38,    24,    60,    61,    58,
      71,    70,    59,    -1,    39,    87,    62,    -1,    92,    71,
      -1,    95,    71,    -1,    85,    71,    -1,    84,    71,    -1,
      96,    71,    -1,    80,    71,    -1,    78,    71,    -1,    79,
      71,    -1,    73,    71,    -1,    74,    71,    -1,    75,    71,
      -1,    77,    71,    -1,    76,    71,    -1,    72,    71,    -1,
      -1,    24,    60,    61,    62,    -1,     7,    60,    25,    63,
      25,    61,    62,    -1,     8,    60,    25,    61,    62,    -1,
       9,    60,    25,    61,    62,    -1,    22,    60,    24,    63,
      24,    61,    62,    -1,    23,    60,    24,    63,    24,    61,
      62,    -1,    11,    60,    24,    61,    62,    -1,    11,    60,
      37,    61,    62,    -1,    10,    60,    24,    61,    62,    -1,
      15,    60,    24,    61,    58,    81,    59,    -1,    82,    83,
      -1,    16,    25,    58,    71,    59,    82,    -1,    -1,    17,
      58,    71,    59,    -1,    18,    24,    19,    25,    20,    25,
      58,    71,    59,    -1,    18,    24,    19,    25,    21,    25,
      58,    71,    59,    -1,    12,    60,    91,    61,    58,    71,
      59,    86,    -1,    14,    58,    71,    59,    -1,    13,    60,
      91,    61,    58,    71,    59,    86,    -1,    -1,    88,    -1,
      88,    26,    89,    -1,    88,    27,    89,    -1,    89,    -1,
      89,    28,    90,    -1,    89,    29,    90,    -1,    89,    40,
      90,    -1,    90,    41,    89,    -1,    90,    -1,    60,    88,
      61,    -1,    42,    60,    88,    61,    -1,    43,    60,    88,
      61,    -1,    44,    60,    88,    61,    -1,    45,    60,    88,
      61,    -1,    46,    60,    88,    61,    -1,    47,    60,    88,
      61,    -1,    24,    -1,    25,    -1,    91,    50,    91,    -1,
      91,    51,    91,    -1,    52,    91,    -1,    60,    91,    61,
      -1,    87,    32,    87,    -1,    87,    34,    87,    -1,    87,
      33,    87,    -1,    87,    35,    87,    -1,    87,    30,    87,
      -1,    87,    54,    87,    -1,    87,    55,    87,    -1,    87,
      31,    87,    -1,    87,    53,    87,    -1,    93,    94,    62,
      -1,     4,    -1,     6,    -1,     5,    -1,    36,    -1,    94,
      63,    24,    -1,    24,    -1,    24,    64,    87,    62,    -1,
      24,    48,    62,    -1,    24,    49,    62,    -1,    24,    64,
      37,    62,    -1,    56,    60,    24,    35,    25,    61,    58,
      71,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   142,   150,   153,   158,   161,   166,   189,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   212,   227,   236,   255,   271,
     303,   335,   357,   365,   373,   377,   380,   384,   388,   392,
     431,   486,   494,   497,   504,   511,   513,   514,   515,   517,
     518,   526,   534,   537,   539,   540,   548,   549,   557,   558,
     559,   560,   575,   579,   582,   585,   588,   591,   598,   605,
     612,   619,   626,   633,   640,   647,   657,   678,   679,   680,
     681,   683,   694,   709,   730,   748,   766,   785
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
  "AND", "OR", "NOT", "NEQ", "STRICT_EQUAL", "STRICT_NEQ", "WHILE",
  "UMINUS", "'{'", "'}'", "'('", "')'", "';'", "','", "'='", "$accept",
  "program", "main", "function_list", "function", "return_statement",
  "code", "function_call", "power_code", "factorial_code", "prime_code",
  "max_code", "min_code", "print_code", "read_code", "switch_code",
  "case_code", "casenum_code", "default_code", "for_code", "condition",
  "elsee", "expression", "e", "f", "t", "bool_expression", "declaration",
  "TYPE", "ID1", "assignment", "while_code", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   123,   125,
      40,    41,    59,    44,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    68,    68,    69,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    73,    74,    75,    76,
      77,    78,    78,    79,    80,    81,    82,    82,    83,    84,
      84,    85,    86,    86,    86,    87,    88,    88,    88,    89,
      89,    89,    89,    89,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    92,    93,    93,    93,
      93,    94,    94,    95,    95,    95,    95,    96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     4,     6,     2,     1,     8,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     0,     4,     7,     5,     5,     7,
       7,     5,     5,     5,     7,     2,     6,     0,     4,     9,
       9,     8,     4,     8,     0,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     4,     4,     4,     4,     4,
       4,     1,     1,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     1,     4,     3,     3,     4,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     0,     7,    24,     0,     0,
       1,     2,     6,    77,    79,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,     0,    24,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,    23,    18,    19,    20,    22,    21,    16,
      17,    15,    13,    12,    10,    82,     0,    11,    14,    24,
       0,     0,     0,     0,     0,     0,     0,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    48,
      53,     0,     0,     0,     0,     0,    84,    85,     0,     0,
       0,     0,     0,    76,     0,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    86,     0,    83,     0,    81,
       5,     0,     0,    27,    28,    33,    31,    32,     0,     0,
       0,     0,     0,     0,    54,    66,    71,    74,    67,    69,
      68,    70,    75,    72,    73,    46,    47,    49,    50,    51,
      52,    63,    64,    24,    37,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
      26,    44,     0,    34,     0,    35,    24,    24,    29,    30,
      24,     9,     0,     0,    41,    24,    24,     0,     0,     0,
       0,    24,     0,     0,    39,    40,    87,     0,     0,    37,
      38,     0,    42,    36,    24,     0,    44,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,   201,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,   211,   212,   225,    39,
      40,   234,    97,    98,    99,   100,   101,    41,    42,    76,
      43,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -81
static const yytype_int16 yypact[] =
{
      74,     6,   -12,    45,   -81,    74,   -81,    14,    -3,    19,
     -81,   -81,   -81,   -81,   -81,   -81,    51,    53,    57,    60,
      64,    96,   101,   109,   102,   104,    67,   -81,   105,    76,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,   113,    14,    14,   108,   106,   143,   144,   148,
     150,    11,     9,   151,   157,   153,   154,   118,   120,   122,
      38,   155,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -35,   -81,   -81,    14,
     123,   121,   124,   125,   126,   127,   128,   -81,   -81,   130,
     131,   132,   133,   134,   135,     9,     9,   117,    46,    31,
     158,    -4,   137,   176,   139,   140,   -81,   -81,   142,   146,
      63,   147,   172,   -81,   186,   156,    14,   187,   152,   159,
     160,   161,   163,    63,    63,    63,    63,    63,    63,   -81,
       4,    68,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,     9,     9,   162,
     168,   119,   189,   192,   -81,   -81,     4,   -81,   193,   -81,
     -81,   178,   166,   -81,   -81,   -81,   -81,   -81,    13,    15,
      17,    73,    75,    77,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,    31,    31,   -81,   -81,   -81,
     -81,   -81,   169,    14,   212,   204,   205,   170,   171,   173,
      63,   174,   175,   -81,   -81,   -81,   -81,   -81,   -81,   177,
     210,   179,   222,   182,   183,   180,   181,   188,   185,   -81,
     -81,   145,   190,   -81,   191,   -81,    14,    14,   -81,   -81,
      14,   -81,   184,   194,   -81,    14,    14,   195,   196,   197,
       9,    14,   198,   199,   -81,   -81,   -81,    71,   200,   212,
     -81,   202,   -81,   -81,    14,   203,   145,   -81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   240,   -81,   245,   -81,   -30,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,     2,   -81,   -81,
     -81,     5,   -43,    18,   -16,    10,   -80,   -81,   -81,   -81,
     -81,   -81
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     9,    77,    78,   129,   131,   111,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   113,   114,    22,
     141,   142,    23,    87,    88,    85,    24,    25,    26,   141,
     142,   141,   142,   141,   142,    10,   147,   148,    86,   115,
      27,    89,    90,    91,    92,    93,    94,   149,    45,   143,
     144,    95,    87,    88,     7,   174,     8,   191,   192,    96,
      28,   145,   141,   142,   203,   109,   204,     1,   205,    46,
      89,    90,    91,    92,    93,    94,   161,    87,    88,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   110,   141,
     142,   141,   142,   141,   142,    89,    90,    91,    92,    93,
      94,    47,     2,    48,   130,    57,    58,    49,   147,   148,
      50,   147,   148,   110,    51,   185,   186,    59,   156,   175,
     190,    60,   251,    54,   206,    62,   207,    75,   208,   195,
     196,   168,   169,   170,   171,   172,   173,   132,   133,   134,
     135,   136,   137,   187,   188,   189,    52,   218,   232,   233,
     247,    53,    55,   209,    56,    61,    79,    80,    81,    82,
     138,   139,   140,    83,    84,   102,   103,   104,   105,   112,
     106,   116,   107,   108,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   237,   238,   150,   146,
     239,   151,   152,   153,   154,   242,   243,   158,   155,   157,
     159,   248,   162,   197,   163,   160,   198,   200,   199,   147,
     193,   164,   165,   166,   255,   167,   194,   202,   210,   213,
     214,   215,   216,   219,   217,   222,   221,   220,   223,   224,
     226,   227,   228,   229,   240,    11,   230,   231,   235,   236,
      12,   253,   241,     0,   244,   245,   246,   249,   250,   252,
     254,   257,   256
};

static const yytype_int16 yycheck[] =
{
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    24,    43,    44,    95,    96,    60,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    62,    63,    15,
      26,    27,    18,    24,    25,    24,    22,    23,    24,    26,
      27,    26,    27,    26,    27,     0,    50,    51,    37,    79,
      36,    42,    43,    44,    45,    46,    47,    61,    61,    28,
      29,    52,    24,    25,    58,    61,    60,   147,   148,    60,
      56,    40,    26,    27,    61,    37,    61,     3,    61,    60,
      42,    43,    44,    45,    46,    47,   116,    24,    25,   132,
     133,   134,   135,   136,   137,   138,   139,   140,    60,    26,
      27,    26,    27,    26,    27,    42,    43,    44,    45,    46,
      47,    60,    38,    60,    96,    48,    49,    60,    50,    51,
      60,    50,    51,    60,    60,   141,   142,    60,   110,    61,
     146,    64,    61,    24,    61,    59,    61,    24,    61,    20,
      21,   123,   124,   125,   126,   127,   128,    30,    31,    32,
      33,    34,    35,   143,   144,   145,    60,   200,    13,    14,
     240,    60,    60,   193,    60,    60,    58,    61,    25,    25,
      53,    54,    55,    25,    24,    24,    19,    24,    24,    24,
      62,    58,    62,    61,    63,    61,    61,    61,    61,    61,
      60,    60,    60,    60,    60,    60,   226,   227,    61,    41,
     230,    25,    63,    63,    62,   235,   236,    35,    62,    62,
      24,   241,    25,    24,    62,    59,    24,    39,    25,    50,
      58,    62,    62,    62,   254,    62,    58,    61,    16,    25,
      25,    61,    61,    59,    61,    25,    59,    62,    59,    17,
      58,    58,    62,    62,    60,     5,    58,    62,    58,    58,
       5,   249,    58,    -1,    59,    59,    59,    59,    59,    59,
      58,   256,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    38,    66,    67,    68,    69,    58,    60,    24,
       0,    67,    69,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    15,    18,    22,    23,    24,    36,    56,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    84,
      85,    92,    93,    95,    96,    61,    60,    60,    60,    60,
      60,    60,    60,    60,    24,    60,    60,    48,    49,    60,
      64,    60,    59,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    24,    94,    71,    71,    58,
      61,    25,    25,    25,    24,    24,    37,    24,    25,    42,
      43,    44,    45,    46,    47,    52,    60,    87,    88,    89,
      90,    91,    24,    19,    24,    24,    62,    62,    61,    37,
      60,    87,    24,    62,    63,    71,    58,    63,    61,    61,
      61,    61,    61,    60,    60,    60,    60,    60,    60,    91,
      88,    91,    30,    31,    32,    33,    34,    35,    53,    54,
      55,    26,    27,    28,    29,    40,    41,    50,    51,    61,
      61,    25,    63,    63,    62,    62,    88,    62,    35,    24,
      59,    71,    25,    62,    62,    62,    62,    62,    88,    88,
      88,    88,    88,    88,    61,    61,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    89,    89,    90,    90,    90,
      89,    91,    91,    58,    58,    20,    21,    24,    24,    25,
      39,    70,    61,    61,    61,    61,    61,    61,    61,    71,
      16,    81,    82,    25,    25,    61,    61,    61,    87,    59,
      62,    59,    25,    59,    17,    83,    58,    58,    62,    62,
      58,    62,    13,    14,    86,    58,    58,    71,    71,    71,
      60,    58,    71,    71,    59,    59,    59,    91,    71,    59,
      59,    61,    59,    82,    58,    71,    59,    86
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
#line 137 "pf.y"
    {
            printf("\nValid program\n");
            printf("\nNo of variables--> %d", no_var);
            (yyval.val) = (yyvsp[(1) - (2)].val);
        ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 142 "pf.y"
    {
            printf("\nValid program\n");
            printf("\nNo of variables--> %d", no_var);
            (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 150 "pf.y"
    {
    (yyval.val) = (yyvsp[(3) - (4)].val);  // Pass up the value from code
;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 153 "pf.y"
    {  // Add this rule to handle ()
    (yyval.val) = (yyvsp[(5) - (6)].val);
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 158 "pf.y"
    {
        (yyval.val) = (yyvsp[(2) - (2)].val);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 161 "pf.y"
    {
        (yyval.val) = (yyvsp[(1) - (1)].val);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 166 "pf.y"
    {
    if (func_count < 100) {
        // Check if function already exists
        if (get_function_index((yyvsp[(2) - (8)].stringValue)) != -1) {
            printf("\nError: Function %s already defined", (yyvsp[(2) - (8)].stringValue));
        } else {
            strcpy(functions[func_count].func_name, (yyvsp[(2) - (8)].stringValue));
            functions[func_count].return_value = (yyvsp[(7) - (8)].val);
            
            // Store the function result
            strcpy(function_results[result_count].name, (yyvsp[(2) - (8)].stringValue));
            function_results[result_count].value = (yyvsp[(7) - (8)].val);
            
            // Increment both counters
            func_count++;
            result_count++;
            
            printf("\nFunction defined: %s with return value: %f", (yyvsp[(2) - (8)].stringValue), (yyvsp[(7) - (8)].val));
        }
    }
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 189 "pf.y"
    {
    (yyval.val) = (yyvsp[(2) - (3)].val);
    printf("\nFunction returning value: %f", (yyvsp[(2) - (3)].val));
;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 195 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 196 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 197 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 198 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 199 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 200 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 201 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 202 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 203 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 204 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 205 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 206 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 207 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 208 "pf.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 209 "pf.y"
    { (yyval.val) = 0; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 212 "pf.y"
    {
    int idx = get_function_index((yyvsp[(1) - (4)].stringValue));
    if(idx != -1) {
        printf("\nFunction %s called and returned: %f", 
               functions[idx].func_name, functions[idx].return_value);
        (yyval.val) = functions[idx].return_value;
    } else {
        printf("\nError: Function %s not defined", (yyvsp[(1) - (4)].stringValue));
        (yyval.val) = 0;
    }
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 227 "pf.y"
    {		
	int i;
	i = pow((yyvsp[(3) - (7)].val), (yyvsp[(5) - (7)].val));
	printf("\nPower function value--> %d ", i);
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 236 "pf.y"
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

  case 28:

/* Line 1455 of yacc.c  */
#line 255 "pf.y"
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

  case 29:

/* Line 1455 of yacc.c  */
#line 271 "pf.y"
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

  case 30:

/* Line 1455 of yacc.c  */
#line 303 "pf.y"
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

  case 31:

/* Line 1455 of yacc.c  */
#line 335 "pf.y"
    {
    int i = get_var_index((yyvsp[(3) - (5)].stringValue));
    if(i == -1) {
        printf("\nWarning: Variable '%s' not found in print statement", (yyvsp[(3) - (5)].stringValue));
        (yyval.val) = 0;
    } else {
        printf("\nPrinting variable %s: ", variable[i].var_name);
        if(variable[i].var_type == 0){  // For char type
            printf("%c", variable[i].value.cval);
        }
        else if(variable[i].var_type == 1){
            printf("%d", variable[i].value.ival);
        }
        else if(variable[i].var_type == 2){
            printf("%f", variable[i].value.fval);
        }
        else if(variable[i].var_type == 3){
            printf("%s", variable[i].value.sval ? variable[i].value.sval : "");
        }
        (yyval.val) = 1;
    }
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 357 "pf.y"
    {
    printf("\n%s", (yyvsp[(3) - (5)].stringValue));
    (yyval.val) = 1;
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 365 "pf.y"
    {
	int i = get_var_index((yyvsp[(3) - (5)].stringValue));
	printf("\nRead command found for variabale--> %s, but no further implementaion\n",variable[i].var_name);
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 373 "pf.y"
    {
	printf("\nSwitch-case structure detected.");
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 380 "pf.y"
    {
        printf("\nCase no--> %d", (yyvsp[(2) - (6)].val));
        (yyval.val) = (yyvsp[(4) - (6)].val);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 384 "pf.y"
    {
        (yyval.val) = 0;  // Add action for empty rule
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 392 "pf.y"
    {
    printf("\nFor loop detected");
    int ii = get_var_index((yyvsp[(2) - (9)].stringValue));
    if(ii == -1) {
        printf("\nWarning: Loop variable '%s' not declared", (yyvsp[(2) - (9)].stringValue));
        (yyval.val) = 0;
    } else if(variable[ii].var_type != 1) {  // Check if it's an integer
        printf("\nWarning: Loop variable must be an integer");
        (yyval.val) = 0;
    } else {
        int i = variable[ii].value.ival;
        int j = (yyvsp[(4) - (9)].val);
        int inc = (yyvsp[(6) - (9)].val);
        
        printf("\nStarting loop with %s = %d to %d increment %d", 
               variable[ii].var_name, i, j, inc);
        
        // Store original value
        int original_value = variable[ii].value.ival;
        
        // Execute the loop body for each iteration
        for(int k=i; k<j; k=k+inc){
            // Update the loop variable
            variable[ii].value.ival = k;
            
            // Execute the code block
            code_result = (yyvsp[(8) - (9)].val);
            
            printf("\nLoop iteration %d: %s = %d", 
                   k, variable[ii].var_name, variable[ii].value.ival);
        }
        
        // Set final value
        variable[ii].value.ival = j;
        printf("\nLoop completed. Final value of %s = %d", 
               variable[ii].var_name, variable[ii].value.ival);
        (yyval.val) = variable[ii].value.ival;
    }
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 431 "pf.y"
    {
    printf("\nFor loop detected");
    int ii = get_var_index((yyvsp[(2) - (9)].stringValue));
    if(ii == -1) {
        printf("\nWarning: Loop variable '%s' not declared", (yyvsp[(2) - (9)].stringValue));
        (yyval.val) = 0;
    } else if(variable[ii].var_type != 1) {  // Check if it's an integer
        printf("\nWarning: Loop variable must be an integer");
        (yyval.val) = 0;
    } else {
        int i = variable[ii].value.ival;
        int j = (yyvsp[(4) - (9)].val);
        int dec = (yyvsp[(6) - (9)].val);
        
        printf("\nStarting loop with %s = %d to %d decrement %d", 
               variable[ii].var_name, i, j, dec);
        
        // Store original value
        int original_value = variable[ii].value.ival;
        
        // Execute the loop body for each iteration
        for(int k=i; k>j; k=k-dec){
            // Update the loop variable
            variable[ii].value.ival = k;
            
            // Execute the code block
            code_result = (yyvsp[(8) - (9)].val);
            
            printf("\nLoop iteration %d: %s = %d", 
                   k, variable[ii].var_name, variable[ii].value.ival);
        }
        
        // Set final value
        variable[ii].value.ival = j;
        printf("\nLoop completed. Final value of %s = %d", 
               variable[ii].var_name, variable[ii].value.ival);
        (yyval.val) = variable[ii].value.ival;
    }
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 486 "pf.y"
    {
        if((yyvsp[(3) - (8)].val) == 1) {
            (yyval.val) = (yyvsp[(6) - (8)].val);  // Execute if block
        } else {
            (yyval.val) = (yyvsp[(8) - (8)].val);  // Execute else block
        }
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 494 "pf.y"
    {
        (yyval.val) = (yyvsp[(3) - (4)].val);  // Simply return the else block's value
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 497 "pf.y"
    {
        if((yyvsp[(3) - (8)].val) == 1) {
            (yyval.val) = (yyvsp[(6) - (8)].val);  // Execute elif block
        } else {
            (yyval.val) = (yyvsp[(8) - (8)].val);  // Try next elif/else
        }
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 504 "pf.y"
    {
        (yyval.val) = 0;
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 511 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (1)].val);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 513 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (3)].val) + (yyvsp[(3) - (3)].val); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 514 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (3)].val) - (yyvsp[(3) - (3)].val);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 515 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (1)].val);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 517 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (3)].val) * (yyvsp[(3) - (3)].val);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 518 "pf.y"
    {
        if((yyvsp[(3) - (3)].val) != 0) {
            (yyval.val) = (yyvsp[(1) - (3)].val) / (yyvsp[(3) - (3)].val);
        } else {
            yyerror("Division by zero");
            (yyval.val) = 0;
        }
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 526 "pf.y"
    {
        if((yyvsp[(3) - (3)].val) != 0) {
            (yyval.val) = fmod((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val));
        } else {
            yyerror("Modulo by zero");
            (yyval.val) = 0;
        }
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 534 "pf.y"
    {
        (yyval.val) = pow((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val));
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 537 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (1)].val);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 539 "pf.y"
    {(yyval.val) = (yyvsp[(2) - (3)].val);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 540 "pf.y"
    {
        if((yyvsp[(3) - (4)].val) >= 0) {
            (yyval.val) = sqrt((yyvsp[(3) - (4)].val));
        } else {
            yyerror("Square root of negative number");
            (yyval.val) = 0;
        }
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 548 "pf.y"
    { (yyval.val) = fabs((yyvsp[(3) - (4)].val)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 549 "pf.y"
    {
        if((yyvsp[(3) - (4)].val) > 0) {
            (yyval.val) = log((yyvsp[(3) - (4)].val));
        } else {
            yyerror("Logarithm of non-positive number");
            (yyval.val) = 0;
        }
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 557 "pf.y"
    { (yyval.val) = sin((yyvsp[(3) - (4)].val)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 558 "pf.y"
    { (yyval.val) = cos((yyvsp[(3) - (4)].val)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 559 "pf.y"
    { (yyval.val) = tan((yyvsp[(3) - (4)].val)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 560 "pf.y"
    {
        int id_index = get_var_index((yyvsp[(1) - (1)].stringValue));
        if(id_index == -1) {
        //	yyerror("VARIABLE DOESN'T EXIST");
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

  case 62:

/* Line 1455 of yacc.c  */
#line 575 "pf.y"
    {(yyval.val) = (yyvsp[(1) - (1)].val);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 579 "pf.y"
    {
        (yyval.val) = ((yyvsp[(1) - (3)].val) && (yyvsp[(3) - (3)].val)) ? 1 : 0;
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 582 "pf.y"
    {
        (yyval.val) = ((yyvsp[(1) - (3)].val) || (yyvsp[(3) - (3)].val)) ? 1 : 0;
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 585 "pf.y"
    {
        (yyval.val) = !(yyvsp[(2) - (2)].val) ? 1 : 0;
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 588 "pf.y"
    {
        (yyval.val) = (yyvsp[(2) - (3)].val);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 591 "pf.y"
    {
        if((yyvsp[(1) - (3)].val) > (yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 598 "pf.y"
    {
        if((yyvsp[(1) - (3)].val) < (yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 605 "pf.y"
    {
        if((yyvsp[(1) - (3)].val) >= (yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 612 "pf.y"
    {
        if((yyvsp[(1) - (3)].val) <= (yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 619 "pf.y"
    {
        if((yyvsp[(1) - (3)].val)==(yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 626 "pf.y"
    {
        if((yyvsp[(1) - (3)].val)==(yyvsp[(3) - (3)].val) && get_expression_type((yyvsp[(1) - (3)].val)) == get_expression_type((yyvsp[(3) - (3)].val))) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 633 "pf.y"
    {
        if((yyvsp[(1) - (3)].val)!=(yyvsp[(3) - (3)].val) || get_expression_type((yyvsp[(1) - (3)].val)) != get_expression_type((yyvsp[(3) - (3)].val))) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 640 "pf.y"
    {
        if((yyvsp[(1) - (3)].val)!=(yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 647 "pf.y"
    {
        if((yyvsp[(1) - (3)].val)!=(yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 657 "pf.y"
    {
    set_var_type((yyvsp[(1) - (3)].val));
    // Initialize variables based on type
    for(int i = 0; i < no_var; i++) {
        if(variable[i].var_type == -1) {  // Only initialize newly declared variables
            variable[i].var_type = (yyvsp[(1) - (3)].val);
            if((yyvsp[(1) - (3)].val) == 1) { // INT
                variable[i].value.ival = 0;
            } else if((yyvsp[(1) - (3)].val) == 2) { // FLOAT
                variable[i].value.fval = 0.0;
            } else if((yyvsp[(1) - (3)].val) == 0) { // CHAR
                variable[i].value.cval = '\0';
            } else if((yyvsp[(1) - (3)].val) == 3) { // STRING
                variable[i].value.sval = strdup("");
            }
        }
    }
    printf("\nVariable(s) declared and initialized");
    (yyval.val) = 0;
;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 678 "pf.y"
    {(yyval.val) = 1; printf("\nVariable type--> Integer");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 679 "pf.y"
    {(yyval.val) = 2; printf("\nVariable type--> Float");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 680 "pf.y"
    {(yyval.val) = 0; printf("\nVariable type--> Character");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 681 "pf.y"
    {(yyval.val) = 3; printf("\nVariable type--> String");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 683 "pf.y"
    {
    if(search_var((yyvsp[(3) - (3)].stringValue))==0){
        strcpy(variable[no_var].var_name, (yyvsp[(3) - (3)].stringValue));
        variable[no_var].var_type = -1;  // Mark as uninitialized
        printf("\nDeclared variable: %s", (yyvsp[(3) - (3)].stringValue));
        no_var++;
    }
    else{
        printf("\nWarning: Variable '%s' already declared", (yyvsp[(3) - (3)].stringValue));
    }
;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 694 "pf.y"
    {
    if(search_var((yyvsp[(1) - (1)].stringValue))==0){
        strcpy(variable[no_var].var_name, (yyvsp[(1) - (1)].stringValue));
        variable[no_var].var_type = -1;  // Mark as uninitialized
        printf("\nDeclared variable: %s", (yyvsp[(1) - (1)].stringValue));
        no_var++;
    }
    else{
        printf("\nWarning: Variable '%s' already declared", (yyvsp[(1) - (1)].stringValue));
    }
    (yyval.stringValue) = strdup((yyvsp[(1) - (1)].stringValue));  // Use strdup to properly allocate memory
;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 709 "pf.y"
    {
    int i = get_var_index((yyvsp[(1) - (4)].stringValue));
    if(i == -1) {
        printf("\nError: Variable '%s' not declared", (yyvsp[(1) - (4)].stringValue));
        (yyval.val) = 0;
    } else {
        if(variable[i].var_type==0){
            variable[i].value.cval = (char)(yyvsp[(3) - (4)].val);
            printf("\nAssigning character value: %c", variable[i].value.cval);
        }
        else if(variable[i].var_type==1){
            variable[i].value.ival = (int)(yyvsp[(3) - (4)].val);
            printf("\nAssigning value %d to %s", variable[i].value.ival, variable[i].var_name);
        }
        else if(variable[i].var_type==2){
            variable[i].value.fval = (float)(yyvsp[(3) - (4)].val);
            printf("\nAssigning value %f to %s", variable[i].value.fval, variable[i].var_name);
        }
        (yyval.val) = (yyvsp[(3) - (4)].val);
    }
;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 730 "pf.y"
    {
    int i = get_var_index((yyvsp[(1) - (3)].stringValue));
    if(i == -1) {
        printf("\nError: Variable '%s' not declared", (yyvsp[(1) - (3)].stringValue));
        (yyval.val) = 0;
    } else {
        if(variable[i].var_type==1){
            variable[i].value.ival++;
            printf("\nIncrementing %s to %d", variable[i].var_name, variable[i].value.ival);
            (yyval.val) = variable[i].value.ival;
        }
        else if(variable[i].var_type==2){
            variable[i].value.fval++;
            printf("\nIncrementing %s to %f", variable[i].var_name, variable[i].value.fval);
            (yyval.val) = variable[i].value.fval;
        }
    }
;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 748 "pf.y"
    {
    int i = get_var_index((yyvsp[(1) - (3)].stringValue));
    if(i == -1) {
        printf("\nError: Variable '%s' not declared", (yyvsp[(1) - (3)].stringValue));
        (yyval.val) = 0;
    } else {
        if(variable[i].var_type==1){
            variable[i].value.ival--;
            printf("\nDecrementing %s to %d", variable[i].var_name, variable[i].value.ival);
            (yyval.val) = variable[i].value.ival;
        }
        else if(variable[i].var_type==2){
            variable[i].value.fval--;
            printf("\nDecrementing %s to %f", variable[i].var_name, variable[i].value.fval);
            (yyval.val) = variable[i].value.fval;
        }
    }
;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 766 "pf.y"
    {
    int i = get_var_index((yyvsp[(1) - (4)].stringValue));
    if(i == -1) {
        printf("\nError: Variable '%s' not declared", (yyvsp[(1) - (4)].stringValue));
        (yyval.val) = 0;
    } else {
        if(variable[i].var_type == 3){  // Check if it's a string type
            variable[i].value.sval = strdup((yyvsp[(3) - (4)].stringValue));
            printf("\nAssigning string value: %s to %s", variable[i].value.sval, variable[i].var_name);
            (yyval.val) = 1;
        } else {
            printf("\nError: Type mismatch - cannot assign string to non-string variable");
            (yyval.val) = 0;
        }
    }
;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 785 "pf.y"
    {
    printf("\nWhile loop detected");
    int i = get_var_index((yyvsp[(3) - (9)].stringValue));  // Get variable index
    int limit = (yyvsp[(5) - (9)].val);             // Get limit value
    
    if(i != -1) {
        for(int j = variable[i].value.ival; j <= limit; j++) {
            // Update the variable's value
            variable[i].value.ival = j;
            printf("\nwhile Looping with %s = %d", variable[i].var_name, j);
            
            // Execute code block
            code_result = (yyvsp[(8) - (9)].val);
        }
    }
    printf("\nWhile loop finished\n");
    (yyval.val) = code_result;
;}
    break;



/* Line 1455 of yacc.c  */
#line 2772 "pf.tab.c"
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
#line 805 "pf.y"


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
