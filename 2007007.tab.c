
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
#line 1 "2007007.y"

	
	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	#include<string.h>
	int yylex(void);
	void yyerror(char *s);
	extern FILE *yyin; 
	extern FILE *yyout;
	
	int no_var = 0;		
	
	struct variable_structure{
		char var_name[20];
		int var_type;
		union {
			int ival;
			float fval;
			char cval;
			char* sval;  
			struct {
				double values[100];  
				int size;           
			} dict;
			struct {
				double values[100];  
				int top;            
			} stack;
			struct {
				double values[100];  
				int front;          
				int rear;           
				int size;           
			} queue;
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
		if(value == (int)value) {
			return 1;  // Integer type
		}
		return 2;  // Float type
	}
	
	int if_executed = 0;  // Global flag to track if any if/elif block was executed
	int first_true_printed = 0;  // Flag to track if we've printed a true block message
	int nesting_level = 0;  // Track nesting level of if blocks

	int code_result = 0;  // To store code block execution results

	// Add this to the global declarations at the top
	struct function_result {
	    char name[50];
	    double value;
	} function_results[100];

	int result_count = 0;

	int conditionMatched = 0;  // Flag to track if any condition has been matched

	void init_stack(int idx) {
	    variable[idx].value.stack.top = -1;  // Initialize empty stack
	}

	int push(int stack_idx, double value) {
	    if(variable[stack_idx].value.stack.top >= 99) {
	        printf("\nStack overflow! Cannot push %f", value);
	        return 0;
	    }
	    variable[stack_idx].value.stack.top++;
	    variable[stack_idx].value.stack.values[variable[stack_idx].value.stack.top] = value;
	    printf("\nPushed %f to stack (position: %d)", value, variable[stack_idx].value.stack.top);
	    return 1;
	}

	double pop(int stack_idx) {
	    if(variable[stack_idx].value.stack.top < 0) {
	        printf("\nStack underflow! Cannot pop from empty stack");
	        return 0;
	    }
	    double value = variable[stack_idx].value.stack.values[variable[stack_idx].value.stack.top];
	    variable[stack_idx].value.stack.top--;
	    printf("\nPopped %f from stack (new top: %d)", value, variable[stack_idx].value.stack.top);
	    return value;
	}

	double top(int stack_idx) {
	    if(variable[stack_idx].value.stack.top < 0) {
	        printf("\nStack is empty! No top element");
	        return 0;
	    }
	    return variable[stack_idx].value.stack.values[variable[stack_idx].value.stack.top];
	}

	int is_empty(int stack_idx) {
	    if (stack_idx < 0 || stack_idx >= no_var) {
	        return 1;  
	    }
	    return (variable[stack_idx].value.stack.top == -1);
	}

	int stack_size(int stack_idx) {
	    if(stack_idx < 0 || stack_idx >= no_var) {
	        printf("\nError: Invalid stack index");
	        return 0;
	    }
	    return variable[stack_idx].value.stack.top;  
	}

	void init_queue(int idx) {
	    variable[idx].value.queue.front = 0;
	    variable[idx].value.queue.rear = -1;
	    variable[idx].value.queue.size = 0;
        
	}

	int enqueue(int queue_idx, double value) {
	    if(variable[queue_idx].value.queue.size >= 100) {
	        printf("\nQueue overflow! Cannot enqueue %f", value);
	        return 0;
	    }
	    variable[queue_idx].value.queue.rear = (variable[queue_idx].value.queue.rear + 1) % 100;
	    variable[queue_idx].value.queue.values[variable[queue_idx].value.queue.rear] = value;
	    variable[queue_idx].value.queue.size++;
	    printf("\nEnqueued %f to queue (rear: %d)", value, variable[queue_idx].value.queue.rear);
	    return 1;
	}

	double dequeue(int queue_idx) {
	    if(variable[queue_idx].value.queue.size <= 0) {
	        printf("\nQueue underflow! Cannot dequeue from empty queue");
	        return 0;
	    }
	    double value = variable[queue_idx].value.queue.values[variable[queue_idx].value.queue.front];
	    variable[queue_idx].value.queue.front = (variable[queue_idx].value.queue.front + 1) % 100;
	    variable[queue_idx].value.queue.size--;
	    printf("\nDequeued %f from queue (new front: %d)", value, variable[queue_idx].value.queue.front);
	    return value;
	}

	double get_front(int queue_idx) {
	    if(variable[queue_idx].value.queue.size <= 0) {
	        printf("\nQueue is empty! No front element");
	        return 0;
	    }
	    return variable[queue_idx+1].value.queue.values[variable[queue_idx+1].value.queue.front];
	}

	double get_rear(int queue_idx) {
	    if(variable[queue_idx].value.queue.size <= 0) {
	        printf("\nQueue is empty! No rear element");
	        return 0;
	    }
	    return variable[queue_idx].value.queue.values[variable[queue_idx].value.queue.rear];
	}

	int is_queue_empty(int queue_idx) {
	    return (variable[queue_idx].value.queue.size == 0);
	}

	int queue_size(int queue_idx) {
	    return variable[queue_idx].value.queue.size;
	}



/* Line 189 of yacc.c  */
#line 297 "2007007.tab.c"

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
     UMINUS = 312,
     DICT = 313,
     GET = 314,
     SET = 315,
     CONCAT = 316,
     COPY = 317,
     SIZE = 318,
     COMPARE = 319,
     STACK = 320,
     PUSH = 321,
     POP = 322,
     TOP = 323,
     ISEMPTY = 324,
     STACKSIZE = 325,
     QUEUE = 326,
     ENQUEUE = 327,
     DEQUEUE = 328,
     FRONT = 329,
     REAR = 330,
     QSIZE = 331,
     QEMPTY = 332
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 224 "2007007.y"

	double val;
	char* stringValue;
	char* type;



/* Line 214 of yacc.c  */
#line 418 "2007007.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 430 "2007007.tab.c"

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
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNRULES -- Number of states.  */
#define YYNSTATES  383

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   332

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      80,    81,     2,     2,    83,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    82,
       2,    84,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,    79,     2,     2,     2,     2,
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
      75,    76,    77
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    13,    20,    23,    25,    34,
      38,    41,    44,    47,    50,    53,    56,    59,    62,    65,
      68,    71,    74,    77,    80,    83,    86,    89,    90,    95,
     103,   109,   115,   123,   131,   137,   143,   149,   157,   160,
     167,   168,   173,   183,   193,   195,   203,   215,   228,   237,
     246,   254,   256,   260,   264,   266,   270,   274,   278,   282,
     284,   288,   290,   292,   297,   302,   307,   312,   317,   322,
     326,   330,   333,   337,   341,   345,   349,   353,   357,   361,
     365,   369,   373,   377,   381,   383,   385,   389,   393,   398,
     402,   406,   411,   413,   415,   417,   419,   421,   423,   425,
     435,   445,   453,   461,   469,   475,   483,   491,   497,   503,
     509,   515,   523,   529,   535,   541,   547
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      86,     0,    -1,    88,    87,    -1,    87,    -1,     3,    78,
      91,    79,    -1,     3,    80,    81,    78,    91,    79,    -1,
      88,    89,    -1,    89,    -1,    38,    24,    80,    81,    78,
      91,    90,    79,    -1,    39,   108,    82,    -1,   113,    91,
      -1,   116,    91,    -1,   119,    91,    -1,   105,    91,    -1,
     104,    91,    -1,   118,    91,    -1,   100,    91,    -1,    98,
      91,    -1,    99,    91,    -1,    93,    91,    -1,    94,    91,
      -1,    95,    91,    -1,    97,    91,    -1,    96,    91,    -1,
      92,    91,    -1,   120,    91,    -1,   121,    91,    -1,    -1,
      24,    80,    81,    82,    -1,     7,    80,    25,    83,    25,
      81,    82,    -1,     8,    80,    25,    81,    82,    -1,     9,
      80,    25,    81,    82,    -1,    22,    80,    24,    83,    24,
      81,    82,    -1,    23,    80,    24,    83,    24,    81,    82,
      -1,    11,    80,    24,    81,    82,    -1,    11,    80,    37,
      81,    82,    -1,    10,    80,    24,    81,    82,    -1,    15,
      80,    24,    81,    78,   101,    79,    -1,   102,   103,    -1,
      16,    25,    78,    91,    79,   102,    -1,    -1,    17,    78,
      91,    79,    -1,    18,    24,    19,    25,    20,    25,    78,
      91,    79,    -1,    18,    24,    19,    25,    21,    25,    78,
      91,    79,    -1,   106,    -1,    12,    80,   112,    81,    78,
      91,    79,    -1,    12,    80,   112,    81,    78,    91,    79,
      14,    78,    91,    79,    -1,    12,    80,   112,    81,    78,
      91,    79,   107,    14,    78,    91,    79,    -1,    12,    80,
     112,    81,    78,    91,    79,   107,    -1,   107,    13,    80,
     112,    81,    78,    91,    79,    -1,    13,    80,   112,    81,
      78,    91,    79,    -1,   109,    -1,   109,    26,   110,    -1,
     109,    27,   110,    -1,   110,    -1,   110,    28,   111,    -1,
     110,    29,   111,    -1,   110,    40,   111,    -1,   111,    41,
     110,    -1,   111,    -1,    80,   109,    81,    -1,    25,    -1,
      24,    -1,    42,    80,   109,    81,    -1,    43,    80,   109,
      81,    -1,    44,    80,   109,    81,    -1,    45,    80,   109,
      81,    -1,    46,    80,   109,    81,    -1,    47,    80,   109,
      81,    -1,   112,    50,   112,    -1,   112,    51,   112,    -1,
      52,   112,    -1,    80,   112,    81,    -1,   108,    32,   108,
      -1,   108,    34,   108,    -1,   108,    33,   108,    -1,   108,
      35,   108,    -1,   108,    30,   108,    -1,   108,    54,   108,
      -1,   108,    55,   108,    -1,   108,    31,   108,    -1,   108,
      53,   108,    -1,   117,   114,    82,    -1,   114,    83,   115,
      -1,   115,    -1,    24,    -1,    24,    84,   108,    -1,    24,
      84,    37,    -1,    24,    84,   108,    82,    -1,    24,    48,
      82,    -1,    24,    49,    82,    -1,    24,    84,    37,    82,
      -1,     4,    -1,     6,    -1,     5,    -1,    36,    -1,    58,
      -1,    65,    -1,    71,    -1,    56,    80,    24,    35,    25,
      81,    78,    91,    79,    -1,    60,    80,    24,    83,    25,
      83,   108,    81,    82,    -1,    59,    80,    24,    83,    25,
      81,    82,    -1,    61,    80,    24,    83,    24,    81,    82,
      -1,    62,    80,    24,    83,    24,    81,    82,    -1,    63,
      80,    24,    81,    82,    -1,    64,    80,    24,    83,    24,
      81,    82,    -1,    66,    80,    24,    83,   108,    81,    82,
      -1,    67,    80,    24,    81,    82,    -1,    68,    80,    24,
      81,    82,    -1,    69,    80,    24,    81,    82,    -1,    70,
      80,    24,    81,    82,    -1,    72,    80,    24,    83,   108,
      81,    82,    -1,    73,    80,    24,    81,    82,    -1,    74,
      80,    24,    81,    82,    -1,    75,    80,    24,    81,    82,
      -1,    77,    80,    24,    81,    82,    -1,    76,    80,    24,
      81,    82,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   261,   261,   266,   273,   276,   281,   284,   289,   309,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   335,   350,
     359,   378,   394,   426,   458,   480,   488,   496,   500,   503,
     507,   511,   515,   549,   600,   607,   616,   630,   646,   658,
     671,   687,   690,   693,   696,   701,   704,   712,   721,   725,
     730,   733,   736,   759,   768,   772,   781,   785,   789,   796,
     799,   802,   805,   808,   815,   822,   829,   836,   843,   850,
     857,   864,   874,   883,   886,   891,   917,   944,   965,   988,
    1006,  1024,  1042,  1043,  1044,  1045,  1046,  1050,  1067,  1081,
    1101,  1118,  1133,  1152,  1167,  1176,  1200,  1211,  1227,  1244,
    1262,  1280,  1291,  1302,  1313,  1324,  1336
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
  "UMINUS", "DICT", "GET", "SET", "CONCAT", "COPY", "SIZE", "COMPARE",
  "STACK", "PUSH", "POP", "TOP", "ISEMPTY", "STACKSIZE", "QUEUE",
  "ENQUEUE", "DEQUEUE", "FRONT", "REAR", "QSIZE", "QEMPTY", "'{'", "'}'",
  "'('", "')'", "';'", "','", "'='", "$accept", "program", "main",
  "function_list", "function", "return_statement", "code", "function_call",
  "power_code", "factorial_code", "prime_code", "max_code", "min_code",
  "print_code", "read_code", "switch_code", "case_code", "casenum_code",
  "default_code", "for_code", "condition", "if_statement", "elif_list",
  "expression", "e", "f", "t", "bool_expression", "declaration",
  "init_list", "init_item", "assignment", "TYPE", "while_code",
  "dict_operation", "stack_operation", "queue_operation", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   123,   125,
      40,    41,    59,    44,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    87,    87,    88,    88,    89,    90,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    93,
      94,    95,    96,    97,    98,    98,    99,   100,   101,   102,
     102,   103,   104,   104,   105,   106,   106,   106,   106,   107,
     107,   108,   109,   109,   109,   110,   110,   110,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   113,   114,   114,   115,   115,   115,   116,   116,
     116,   116,   117,   117,   117,   117,   117,   117,   117,   118,
     119,   119,   119,   119,   119,   119,   120,   120,   120,   120,
     120,   121,   121,   121,   121,   121,   121
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     4,     6,     2,     1,     8,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     4,     7,
       5,     5,     7,     7,     5,     5,     5,     7,     2,     6,
       0,     4,     9,     9,     1,     7,    11,    12,     8,     8,
       7,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     1,     4,     4,     4,     4,     4,     4,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     3,     4,     3,
       3,     4,     1,     1,     1,     1,     1,     1,     1,     9,
       9,     7,     7,     7,     5,     7,     7,     5,     5,     5,
       5,     7,     5,     5,     5,     5,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     0,     7,    27,     0,     0,
       1,     2,     6,    92,    94,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,    96,
       0,     0,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    44,    27,    27,     0,    27,    27,    27,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,    24,    19,    20,    21,    23,    22,
      17,    18,    16,    14,    13,    10,    11,    85,     0,    84,
      15,    12,    25,    26,    27,     0,     0,     0,     0,     0,
       0,     0,    62,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    54,    59,     0,     0,     0,     0,
       0,    89,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    91,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      86,    83,     5,     0,     0,    30,    31,    36,    34,    35,
       0,     0,     0,     0,     0,     0,    60,    72,    77,    80,
      73,    75,    74,    76,    81,    78,    79,    52,    53,    55,
      56,    57,    58,    69,    70,    27,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   107,
     108,   109,   110,     0,   112,   113,   114,   116,   115,     0,
       0,     0,    63,    64,    65,    66,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,    29,    45,     0,    37,
       0,    38,    27,    27,    32,    33,    27,   101,     0,   102,
     103,   105,   106,   111,     9,     0,     0,    48,    27,    27,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
      42,    43,    99,   100,     0,     0,     0,    27,    40,    41,
       0,    46,     0,     0,    39,    27,     0,    47,     0,    27,
      50,     0,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,   300,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,   310,   311,   331,    59,
      60,    61,   347,   142,   143,   144,   145,   146,    62,   118,
     119,    63,    64,    65,    66,    67,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -120
static const yytype_int16 yypact[] =
{
      27,    25,   -13,    20,  -120,    27,  -120,   135,   -48,   -44,
    -120,  -120,  -120,  -120,  -120,  -120,   -40,   -30,    -2,    18,
      37,    39,    48,   102,    72,    80,   -20,  -120,    89,  -120,
      90,    92,    93,    94,    95,    96,  -120,    97,    98,    99,
     100,   101,  -120,   104,   107,   108,   109,   110,   140,    69,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,  -120,   135,   135,   161,   135,   135,   135,   135,   143,
     141,   198,   199,   201,   203,   -10,    -1,   204,   210,   206,
     207,   150,   154,   152,    10,   216,   217,   218,   219,   220,
     221,   222,   224,   225,   226,   227,   228,   230,   231,   232,
     233,   234,   235,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,   176,    29,  -120,
    -120,  -120,  -120,  -120,   135,   183,   179,   182,   185,   186,
     187,   188,  -120,  -120,   190,   191,   192,   193,   194,   195,
      -1,    -1,   184,    61,    -3,   223,    26,   196,   240,   197,
     202,  -120,  -120,   205,   208,    38,   209,   241,   211,   212,
     213,   214,   200,   229,   236,   237,   239,   242,   243,   238,
     245,   246,   247,   249,   250,    24,  -120,   161,   253,   135,
     254,   251,   252,   255,   256,   257,    38,    38,    38,    38,
      38,    38,  -120,     5,   105,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      -1,    -1,   215,   244,    88,   260,   264,  -120,  -120,     5,
    -120,   267,   275,   276,   265,   278,   258,   279,    38,   259,
     261,   262,   263,    38,   266,   268,   269,   270,   271,  -120,
    -120,  -120,  -120,   272,   273,  -120,  -120,  -120,  -120,  -120,
      12,    32,    46,    68,    70,    73,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,    -3,    -3,  -120,
    -120,  -120,  -120,  -120,   285,   135,   288,   281,   282,   274,
     277,   280,   283,   284,   287,   289,  -120,   290,   291,  -120,
    -120,  -120,  -120,   292,  -120,  -120,  -120,  -120,  -120,    38,
     286,   293,  -120,  -120,  -120,  -120,  -120,  -120,   295,   311,
     297,   296,   299,   300,   298,   301,   303,   302,    38,   304,
     305,   306,   307,   308,   309,  -120,  -120,   151,   314,  -120,
     315,  -120,   135,   135,  -120,  -120,   135,  -120,   313,  -120,
    -120,  -120,  -120,  -120,  -120,   316,   317,   153,   135,   135,
     318,   319,   320,   321,    -1,   135,   322,   323,   325,   326,
    -120,  -120,  -120,  -120,   111,   327,    -1,   135,   288,  -120,
     329,  -120,   132,   330,  -120,   135,   332,  -120,   333,   135,
    -120,   334,  -120
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,   310,  -120,   337,  -120,   -50,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,   -90,  -120,  -120,
    -120,  -120,  -120,   -65,   -66,  -103,   -92,  -119,  -120,  -120,
     131,  -120,  -120,  -120,  -120,  -120,  -120
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     9,   115,   116,   130,   120,   121,   122,   123,   156,
      10,   192,   194,   132,   133,   206,   207,   131,    81,    82,
       1,   204,   205,    69,   132,   133,    70,   208,   204,   205,
      71,   134,   135,   136,   137,   138,   139,   154,   132,   133,
      72,   140,   134,   135,   136,   137,   138,   139,   204,   205,
      83,   239,   132,   133,    84,     2,   134,   135,   136,   137,
     138,   139,   204,   205,   178,   193,   210,   211,    73,   141,
     134,   135,   136,   137,   138,   139,   256,   204,   205,   219,
     155,   273,   274,   302,   204,   205,   204,   205,    74,   204,
     205,   267,   268,     7,   155,     8,   272,   212,   277,   278,
     240,   176,   177,   303,   269,   270,   271,    75,   155,    76,
     250,   251,   252,   253,   254,   255,    78,   304,    77,   243,
     258,   259,   260,   261,   262,   263,   264,   265,   266,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   103,   305,
      22,   306,    79,    23,   307,   210,   211,    24,    25,    26,
      80,   210,   211,   288,   345,   346,   356,   357,   293,    85,
      86,    27,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   210,   211,    97,   117,   257,    98,    99,   100,
     101,    28,   370,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   376,   195,   196,   197,   198,   199,   200,
     102,   124,   125,   126,   127,   308,   128,   129,   147,   148,
     149,   150,   151,   153,   324,   364,   152,   201,   202,   203,
     157,   158,   159,   160,   161,   162,   163,   372,   164,   165,
     166,   167,   168,   338,   169,   170,   171,   172,   173,   174,
     175,   179,   180,   181,   209,   214,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   221,   213,   374,   244,
     215,   226,   350,   351,   279,   216,   352,   217,   280,   284,
     218,   220,   281,   275,   222,   223,   224,   225,   358,   359,
     282,   283,   285,   287,   309,   365,   312,   313,   241,     0,
       0,   299,   227,   330,     0,    11,     0,   373,   229,   228,
     230,   233,   276,   231,   232,   378,   234,   235,   236,   381,
     237,   238,   242,   245,   246,   210,   328,   247,   248,   249,
     286,   289,    12,   290,   291,   292,     0,     0,   294,     0,
     295,   296,   297,   298,   301,   314,     0,     0,   315,     0,
       0,   316,     0,     0,   317,   325,     0,   318,   319,     0,
     320,   321,   322,   323,   327,   326,   329,   332,   333,     0,
     334,   336,     0,   335,   337,     0,   339,   340,   341,   342,
     343,   344,   348,   349,   353,   355,   354,   360,   361,   362,
       0,   367,   366,   363,   368,   369,   371,   375,     0,   377,
     379,     0,   380,   382
};

static const yytype_int16 yycheck[] =
{
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    24,    62,    63,    24,    65,    66,    67,    68,    84,
       0,   140,   141,    24,    25,    28,    29,    37,    48,    49,
       3,    26,    27,    81,    24,    25,    80,    40,    26,    27,
      80,    42,    43,    44,    45,    46,    47,    37,    24,    25,
      80,    52,    42,    43,    44,    45,    46,    47,    26,    27,
      80,    37,    24,    25,    84,    38,    42,    43,    44,    45,
      46,    47,    26,    27,   124,   141,    50,    51,    80,    80,
      42,    43,    44,    45,    46,    47,    81,    26,    27,   155,
      80,   210,   211,    81,    26,    27,    26,    27,    80,    26,
      27,   204,   205,    78,    80,    80,   209,    81,    20,    21,
     175,    82,    83,    81,   206,   207,   208,    80,    80,    80,
     186,   187,   188,   189,   190,   191,    24,    81,    80,   179,
     195,   196,   197,   198,   199,   200,   201,   202,   203,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    79,    81,
      15,    81,    80,    18,    81,    50,    51,    22,    23,    24,
      80,    50,    51,   228,    13,    14,    13,    14,   233,    80,
      80,    36,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    50,    51,    80,    24,    81,    80,    80,    80,
      80,    56,    81,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    81,    30,    31,    32,    33,    34,    35,
      80,    78,    81,    25,    25,   275,    25,    24,    24,    19,
      24,    24,    82,    81,   299,   354,    82,    53,    54,    55,
      24,    24,    24,    24,    24,    24,    24,   366,    24,    24,
      24,    24,    24,   318,    24,    24,    24,    24,    24,    24,
      84,    78,    83,    81,    41,    25,    81,    81,    81,    81,
      80,    80,    80,    80,    80,    80,    35,    81,   368,    25,
      83,    81,   332,   333,    24,    83,   336,    82,    24,    24,
      82,    82,    25,    78,    83,    83,    83,    83,   348,   349,
      25,    25,    24,    24,    16,   355,    25,    25,   177,    -1,
      -1,    39,    83,    17,    -1,     5,    -1,   367,    81,    83,
      81,    83,    78,    81,    81,   375,    81,    81,    81,   379,
      81,    81,    79,    82,    82,    50,    25,    82,    82,    82,
      82,    82,     5,    82,    82,    82,    -1,    -1,    82,    -1,
      82,    82,    82,    82,    81,    81,    -1,    -1,    81,    -1,
      -1,    81,    -1,    -1,    81,    79,    -1,    83,    81,    -1,
      81,    81,    81,    81,    79,    82,    79,    78,    78,    -1,
      82,    78,    -1,    82,    82,    -1,    82,    82,    82,    82,
      82,    82,    78,    78,    81,    78,    80,    79,    79,    79,
      -1,    78,    80,    82,    79,    79,    79,    78,    -1,    79,
      78,    -1,    79,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    38,    86,    87,    88,    89,    78,    80,    24,
       0,    87,    89,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    15,    18,    22,    23,    24,    36,    56,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   104,
     105,   106,   113,   116,   117,   118,   119,   120,   121,    81,
      80,    80,    80,    80,    80,    80,    80,    80,    24,    80,
      80,    48,    49,    80,    84,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    79,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    24,   114,   115,
      91,    91,    91,    91,    78,    81,    25,    25,    25,    24,
      24,    37,    24,    25,    42,    43,    44,    45,    46,    47,
      52,    80,   108,   109,   110,   111,   112,    24,    19,    24,
      24,    82,    82,    81,    37,    80,   108,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    84,    82,    83,    91,    78,
      83,    81,    81,    81,    81,    81,    80,    80,    80,    80,
      80,    80,   112,   109,   112,    30,    31,    32,    33,    34,
      35,    53,    54,    55,    26,    27,    28,    29,    40,    41,
      50,    51,    81,    81,    25,    83,    83,    82,    82,   109,
      82,    35,    83,    83,    83,    83,    81,    83,    83,    81,
      81,    81,    81,    83,    81,    81,    81,    81,    81,    37,
     108,   115,    79,    91,    25,    82,    82,    82,    82,    82,
     109,   109,   109,   109,   109,   109,    81,    81,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   110,   110,   111,
     111,   111,   110,   112,   112,    78,    78,    20,    21,    24,
      24,    25,    25,    25,    24,    24,    82,    24,   108,    82,
      82,    82,    82,   108,    82,    82,    82,    82,    82,    39,
      90,    81,    81,    81,    81,    81,    81,    81,    91,    16,
     101,   102,    25,    25,    81,    81,    81,    81,    83,    81,
      81,    81,    81,    81,   108,    79,    82,    79,    25,    79,
      17,   103,    78,    78,    82,    82,    78,    82,   108,    82,
      82,    82,    82,    82,    82,    13,    14,   107,    78,    78,
      91,    91,    91,    81,    80,    78,    13,    14,    91,    91,
      79,    79,    79,    82,   112,    91,    80,    78,    79,    79,
      81,    79,   112,    91,   102,    78,    81,    79,    91,    78,
      79,    91,    79
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
#line 261 "2007007.y"
    {
            printf("\nValid program\n");
            printf("\nNo of variables--> %d", no_var);
            (yyval.val) = (yyvsp[(1) - (2)].val);
        ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 266 "2007007.y"
    {
            printf("\nValid program\n");
            printf("\nNo of variables--> %d", no_var);
            (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 273 "2007007.y"
    {
    (yyval.val) = (yyvsp[(3) - (4)].val);  
;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 276 "2007007.y"
    {  // Add this rule to handle ()
    (yyval.val) = (yyvsp[(5) - (6)].val);
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 281 "2007007.y"
    {
        (yyval.val) = (yyvsp[(2) - (2)].val);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 284 "2007007.y"
    {
        (yyval.val) = (yyvsp[(1) - (1)].val);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 289 "2007007.y"
    {
    if (func_count < 100) {
        if (get_function_index((yyvsp[(2) - (8)].stringValue)) != -1) {
            printf("\nError: Function %s already defined", (yyvsp[(2) - (8)].stringValue));
        } else {
            strcpy(functions[func_count].func_name, (yyvsp[(2) - (8)].stringValue));
            functions[func_count].return_value = (yyvsp[(7) - (8)].val);
            
            strcpy(function_results[result_count].name, (yyvsp[(2) - (8)].stringValue));
            function_results[result_count].value = (yyvsp[(7) - (8)].val);
            
            func_count++;
            result_count++;
            
            printf("\nFunction defined: %s with return value: %f", (yyvsp[(2) - (8)].stringValue), (yyvsp[(7) - (8)].val));
        }
    }
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 309 "2007007.y"
    {
    (yyval.val) = (yyvsp[(2) - (3)].val);
    printf("\nFunction returning value: %f", (yyvsp[(2) - (3)].val));
;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 315 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 316 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 317 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 318 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 319 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 320 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 321 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 322 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 323 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 324 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 325 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 326 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 327 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 328 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 329 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 330 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 331 "2007007.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 332 "2007007.y"
    { (yyval.val) = 0; ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 335 "2007007.y"
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

  case 29:

/* Line 1455 of yacc.c  */
#line 350 "2007007.y"
    {		
	double result = pow((yyvsp[(3) - (7)].val), (yyvsp[(5) - (7)].val));
	printf("\nPower function value--> %f", result);
	(yyval.val) = result;
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 359 "2007007.y"
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

  case 31:

/* Line 1455 of yacc.c  */
#line 378 "2007007.y"
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

  case 32:

/* Line 1455 of yacc.c  */
#line 394 "2007007.y"
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

  case 33:

/* Line 1455 of yacc.c  */
#line 426 "2007007.y"
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

  case 34:

/* Line 1455 of yacc.c  */
#line 458 "2007007.y"
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

  case 35:

/* Line 1455 of yacc.c  */
#line 480 "2007007.y"
    {
    printf("\n%s", (yyvsp[(3) - (5)].stringValue));
    (yyval.val) = 1;
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 488 "2007007.y"
    {
	int i = get_var_index((yyvsp[(3) - (5)].stringValue));
	printf("\nRead command found for variabale--> %s, but no further implementaion\n",variable[i].var_name);
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 496 "2007007.y"
    {
	printf("\nSwitch-case structure detected.");
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 503 "2007007.y"
    {
        printf("\nCase no--> %d", (yyvsp[(2) - (6)].val));
        (yyval.val) = (yyvsp[(4) - (6)].val);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 507 "2007007.y"
    {
        (yyval.val) = 0;  // Add action for empty rule
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 515 "2007007.y"
    {
    printf("\nFor loop detected");
    int ii = get_var_index((yyvsp[(2) - (9)].stringValue));
    if(ii == -1) {
        printf("\nWarning: Loop variable '%s' not declared", (yyvsp[(2) - (9)].stringValue));
        (yyval.val) = 0;
    } else if(variable[ii].var_type != 1) {  
        printf("\nWarning: Loop variable must be an integer");
        (yyval.val) = 0;
    } else {
        int i = variable[ii].value.ival;
        int j = (yyvsp[(4) - (9)].val);
        int inc = (yyvsp[(6) - (9)].val);
        
        printf("\nStarting loop with %s = %d to %d increment %d", 
               variable[ii].var_name, i, j, inc);
        
        int original_value = variable[ii].value.ival;
        
        for(int k=i; k<j; k=k+inc){
            variable[ii].value.ival = k;
            
            code_result = (yyvsp[(8) - (9)].val);
            
            printf("\nLoop iteration %d: %s = %d", 
                   k, variable[ii].var_name, variable[ii].value.ival);
        }
        
        variable[ii].value.ival = j;
        printf("\nLoop completed. Final value of %s = %d", 
               variable[ii].var_name, variable[ii].value.ival);
        (yyval.val) = variable[ii].value.ival;
    }
;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 549 "2007007.y"
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
        
        int original_value = variable[ii].value.ival;
        
        for(int k=i; k>j; k=k-dec){
            variable[ii].value.ival = k;
            
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

  case 44:

/* Line 1455 of yacc.c  */
#line 600 "2007007.y"
    {
        conditionMatched = 0;  // Reset for next if chain
        (yyval.val) = (yyvsp[(1) - (1)].val);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 607 "2007007.y"
    {
        if((yyvsp[(3) - (7)].val) == 1) {
            printf("\n-->IF block is true");
            (yyval.val) = (yyvsp[(6) - (7)].val);
            conditionMatched = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 616 "2007007.y"
    {
        if((yyvsp[(3) - (11)].val) == 1) {
            printf("\n-->IF block is true");
            (yyval.val) = (yyvsp[(6) - (11)].val);
            conditionMatched = 1;
        } else if(!conditionMatched) {
            printf("\n-->OTHERWISE block is true");
            (yyval.val) = (yyvsp[(10) - (11)].val);
            conditionMatched = 1;
        } else {
            printf("\nCondition already fulfilled. Ignoring otherwise block.");
            (yyval.val) = 0;
        }
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 630 "2007007.y"
    {
        if((yyvsp[(3) - (12)].val) == 1) {
            printf("\n-->IF block is true");
            (yyval.val) = (yyvsp[(6) - (12)].val);
            conditionMatched = 1;
        } else {
            (yyval.val) = (yyvsp[(8) - (12)].val);  // Value from elif_list
            if(!conditionMatched) {
                printf("\n-->OTHERWISE block is true");
                (yyval.val) = (yyvsp[(11) - (12)].val);
                conditionMatched = 1;
            } else {
                printf("\nCondition already fulfilled. Ignoring otherwise block.");
            }
        }
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 646 "2007007.y"
    {
        if((yyvsp[(3) - (8)].val) == 1) {
            printf("\n-->IF block is true");
            (yyval.val) = (yyvsp[(6) - (8)].val);
            conditionMatched = 1;
        } else {
            (yyval.val) = (yyvsp[(8) - (8)].val);  // Value from elif_list
        }
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 658 "2007007.y"
    {
        if(!conditionMatched && (yyvsp[(4) - (8)].val) == 1) {
            printf("\n-->ELIF block is true");
            (yyval.val) = (yyvsp[(7) - (8)].val);
            conditionMatched = 1;
        } else if(conditionMatched) {
            printf("\nCondition already fulfilled. Ignoring elif block.");
            (yyval.val) = (yyvsp[(1) - (8)].val);  // Keep previous value
        } else {
            (yyval.val) = 0;
        }

    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 671 "2007007.y"
    {
        if(!conditionMatched && (yyvsp[(3) - (7)].val) == 1) {
            printf("\n-->ELIF block is true");
            (yyval.val) = (yyvsp[(6) - (7)].val);
            conditionMatched = 1;
        } else if(conditionMatched) {
            printf("\nCondition already fulfilled. Ignoring elif block.");
            (yyval.val) = 0;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 687 "2007007.y"
    {(yyval.val) = (yyvsp[(1) - (1)].val);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 690 "2007007.y"
    {
        (yyval.val) = (yyvsp[(1) - (3)].val) + (yyvsp[(3) - (3)].val);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 693 "2007007.y"
    {
        (yyval.val) = (yyvsp[(1) - (3)].val) - (yyvsp[(3) - (3)].val);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 696 "2007007.y"
    {
        (yyval.val) = (yyvsp[(1) - (1)].val);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 701 "2007007.y"
    {
        (yyval.val) = (yyvsp[(1) - (3)].val) * (yyvsp[(3) - (3)].val);
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 704 "2007007.y"
    {
        if((yyvsp[(3) - (3)].val) != 0) {
            (yyval.val) = (yyvsp[(1) - (3)].val) / (yyvsp[(3) - (3)].val);
        } else {
            printf("\nError: Division by zero");
            (yyval.val) = 0;
        }
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 712 "2007007.y"
    {
        if((yyvsp[(3) - (3)].val) != 0) {
            (yyval.val) = (int)(yyvsp[(1) - (3)].val) % (int)(yyvsp[(3) - (3)].val); 
            printf("\nModulo operation: %d", (int)(yyval.val));
        } else {
            printf("\nError: Modulo by zero");
            (yyval.val) = 0;
        }
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 721 "2007007.y"
    {
        (yyval.val) = pow((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val));
        printf("\nPower operation: %f ^ %f = %f", (yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), (yyval.val));
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 725 "2007007.y"
    {
        (yyval.val) = (yyvsp[(1) - (1)].val);
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 730 "2007007.y"
    {
        (yyval.val) = (yyvsp[(2) - (3)].val);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 733 "2007007.y"
    {
        (yyval.val) = (yyvsp[(1) - (1)].val);
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 736 "2007007.y"
    {
        int i = get_var_index((yyvsp[(1) - (1)].stringValue));
        if(i != -1) {
            switch(variable[i].var_type) {
                case 1: // INT
                    (yyval.val) = (double)variable[i].value.ival;
                    break;
                case 2: // FLOAT
                    (yyval.val) = variable[i].value.fval;
                    break;
                case 0: // CHAR
                    (yyval.val) = (double)variable[i].value.cval;
                    break;
                default:
                    printf("\nError: Invalid type for mathematical operation");
                    (yyval.val) = 0;
                    break;
            }
        } else {
            printf("\nError: Variable '%s' not declared", (yyvsp[(1) - (1)].stringValue));
            (yyval.val) = 0;
        }
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 759 "2007007.y"
    {
        if((yyvsp[(3) - (4)].val) >= 0) {
            (yyval.val) = sqrt((yyvsp[(3) - (4)].val));
            printf("\nSquare root operation: sqrt(%f) = %f", (yyvsp[(3) - (4)].val), (yyval.val));
        } else {
            printf("\nError: Square root of negative number");
            (yyval.val) = 0;
        }
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 768 "2007007.y"
    {
        (yyval.val) = fabs((yyvsp[(3) - (4)].val));
        printf("\nAbsolute value operation: |%f| = %f", (yyvsp[(3) - (4)].val), (yyval.val));
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 772 "2007007.y"
    {
        if((yyvsp[(3) - (4)].val) > 0) {
            (yyval.val) = log((yyvsp[(3) - (4)].val));
            printf("\nLogarithm operation: log(%f) = %f", (yyvsp[(3) - (4)].val), (yyval.val));
        } else {
            printf("\nError: Logarithm of non-positive number");
            (yyval.val) = 0;
        }
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 781 "2007007.y"
    {
        (yyval.val) = sin((yyvsp[(3) - (4)].val));
        printf("\nSine operation: sin(%f) = %f", (yyvsp[(3) - (4)].val), (yyval.val));
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 785 "2007007.y"
    {
        (yyval.val) = cos((yyvsp[(3) - (4)].val));
        printf("\nCosine operation: cos(%f) = %f", (yyvsp[(3) - (4)].val), (yyval.val));
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 789 "2007007.y"
    {
        (yyval.val) = tan((yyvsp[(3) - (4)].val));
        printf("\nTangent operation: tan(%f) = %f", (yyvsp[(3) - (4)].val), (yyval.val));
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 796 "2007007.y"
    {
        (yyval.val) = ((yyvsp[(1) - (3)].val) && (yyvsp[(3) - (3)].val)) ? 1 : 0;
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 799 "2007007.y"
    {
        (yyval.val) = ((yyvsp[(1) - (3)].val) || (yyvsp[(3) - (3)].val)) ? 1 : 0;
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 802 "2007007.y"
    {
        (yyval.val) = !(yyvsp[(2) - (2)].val) ? 1 : 0;
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 805 "2007007.y"
    {
        (yyval.val) = (yyvsp[(2) - (3)].val);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 808 "2007007.y"
    {
        if((yyvsp[(1) - (3)].val) > (yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 815 "2007007.y"
    {
        if((yyvsp[(1) - (3)].val) < (yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 822 "2007007.y"
    {
        if((yyvsp[(1) - (3)].val) >= (yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 829 "2007007.y"
    {
        if((yyvsp[(1) - (3)].val) <= (yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 836 "2007007.y"
    {
        if((yyvsp[(1) - (3)].val)==(yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 843 "2007007.y"
    {
        if((yyvsp[(1) - (3)].val)==(yyvsp[(3) - (3)].val) && get_expression_type((yyvsp[(1) - (3)].val)) == get_expression_type((yyvsp[(3) - (3)].val))) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 850 "2007007.y"
    {
        if((yyvsp[(1) - (3)].val)!=(yyvsp[(3) - (3)].val) || get_expression_type((yyvsp[(1) - (3)].val)) != get_expression_type((yyvsp[(3) - (3)].val))) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 857 "2007007.y"
    {
        if((yyvsp[(1) - (3)].val)!=(yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 864 "2007007.y"
    {
        if((yyvsp[(1) - (3)].val)!=(yyvsp[(3) - (3)].val)) {
            (yyval.val) = 1;
        } else {
            (yyval.val) = 0;
        }
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 874 "2007007.y"
    {
    (yyval.val) = (yyvsp[(1) - (3)].val);  // Store the type for init_list to use
    set_var_type((yyvsp[(1) - (3)].val));
    printf("\nVariable(s) declared and initialized");
    (yyval.val) = 0;
;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 883 "2007007.y"
    {
    (yyval.val) = (yyvsp[(0) - (3)].val);  // Pass the type down
;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 886 "2007007.y"
    {
    (yyval.val) = (yyvsp[(0) - (1)].val);  // Pass the type down
;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 891 "2007007.y"
    {
    if(search_var((yyvsp[(1) - (1)].stringValue))==0){
        strcpy(variable[no_var].var_name, (yyvsp[(1) - (1)].stringValue));
        variable[no_var].var_type = (yyvsp[(0) - (1)].val);  // Get type from parent
        printf("\nDeclared variable: %s", (yyvsp[(1) - (1)].stringValue));
        
        switch(variable[no_var].var_type) {
            case 1: // INT
                variable[no_var].value.ival = 0;
                break;
            case 2: // FLOAT
                variable[no_var].value.fval = 0.0;
                break;
            case 0: // CHAR
                variable[no_var].value.cval = '\0';
                break;
            case 3: // STRING
                variable[no_var].value.sval = strdup("");
                break;
        }
        no_var++;
    }
    else{
        printf("\nWarning: Variable '%s' already declared", (yyvsp[(1) - (1)].stringValue));
    }
;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 917 "2007007.y"
    {
    if(search_var((yyvsp[(1) - (3)].stringValue))==0){
        strcpy(variable[no_var].var_name, (yyvsp[(1) - (3)].stringValue));
        variable[no_var].var_type = (yyvsp[(0) - (3)].val);  
        printf("\nDeclared variable: %s with initialization", (yyvsp[(1) - (3)].stringValue));
        
        // Initialize based on type
        switch(variable[no_var].var_type) {
            case 1: // INT
                variable[no_var].value.ival = (int)(yyvsp[(3) - (3)].val);
                printf("\nInitialized to integer: %d", variable[no_var].value.ival);
                break;
            case 2: // FLOAT
                variable[no_var].value.fval = (float)(yyvsp[(3) - (3)].val);
                printf("\nInitialized to float: %f", variable[no_var].value.fval);
                break;
            case 0: // CHAR
                variable[no_var].value.cval = (char)(yyvsp[(3) - (3)].val);
                printf("\nInitialized to char: %c", variable[no_var].value.cval);
                break;
        }
        no_var++;
    }
    else{
        printf("\nWarning: Variable '%s' already declared", (yyvsp[(1) - (3)].stringValue));
    }
;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 944 "2007007.y"
    {
    if(search_var((yyvsp[(1) - (3)].stringValue))==0){
        strcpy(variable[no_var].var_name, (yyvsp[(1) - (3)].stringValue));
        variable[no_var].var_type = (yyvsp[(0) - (3)].val);  // Get type from parent
        
        if(variable[no_var].var_type == 3) { // STRING
            variable[no_var].value.sval = strdup((yyvsp[(3) - (3)].stringValue));
            printf("\nDeclared string variable: %s with initialization", (yyvsp[(1) - (3)].stringValue));
            printf("\nInitialized to string: %s", (yyvsp[(3) - (3)].stringValue));
        } else {
            printf("\nError: Type mismatch - cannot assign string to non-string variable");
        }
        no_var++;
    }
    else{
        printf("\nWarning: Variable '%s' already declared", (yyvsp[(1) - (3)].stringValue));
    }
;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 965 "2007007.y"
    {
    int i = get_var_index((yyvsp[(1) - (4)].stringValue));
    if(i == -1) {
        printf("\nError: Variable '%s' not declared", (yyvsp[(1) - (4)].stringValue));
        (yyval.val) = 0;
    } else {
        switch(variable[i].var_type) {
            case 1: // INT
                variable[i].value.ival = (int)(yyvsp[(3) - (4)].val);
                printf("\nAssigning value %d to %s", variable[i].value.ival, variable[i].var_name);
                break;
            case 2: // FLOAT
                variable[i].value.fval = (float)(yyvsp[(3) - (4)].val);
                printf("\nAssigning value %f to %s", variable[i].value.fval, variable[i].var_name);
                break;
            case 0: // CHAR
                variable[i].value.cval = (char)(yyvsp[(3) - (4)].val);
                //printf("\nAssigning character value: %c", variable[i].value.cval);
                break;
        }
        (yyval.val) = (yyvsp[(3) - (4)].val);
    }
;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 988 "2007007.y"
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

  case 90:

/* Line 1455 of yacc.c  */
#line 1006 "2007007.y"
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

  case 91:

/* Line 1455 of yacc.c  */
#line 1024 "2007007.y"
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

  case 92:

/* Line 1455 of yacc.c  */
#line 1042 "2007007.y"
    {(yyval.val) = 1; printf("\nVariable type--> Integer");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1043 "2007007.y"
    {(yyval.val) = 2; printf("\nVariable type--> Float");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1044 "2007007.y"
    {(yyval.val) = 0; printf("\nVariable type--> Character");;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1045 "2007007.y"
    {(yyval.val) = 3; printf("\nVariable type--> String");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1046 "2007007.y"
    {
		(yyval.val) = 4;  // 4 for dictionary type
		printf("\nVariable type--> Dictionary");
	;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1050 "2007007.y"
    {
		(yyval.val) = 5;  // 5 for stack type
		printf("\nVariable type--> Stack");
		// Initialize stack for all newly declared variables
		for(int i=0; i<no_var; i++){
			if(variable[i].var_type == -1){
				variable[i].var_type = 5;  // Set type first
				variable[i].value.stack.top = -1;  
				for(int j = 0; j < 100; j++) {
					variable[i].value.stack.values[j] = 0;
				}
				printf("\nInitialized empty stack %s (top: %d)", 
					   variable[i].var_name, 
					   variable[i].value.stack.top);
			}
		}
	;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1067 "2007007.y"
    {
		(yyval.val) = 6; 
		printf("\nVariable type--> Queue");
		for(int i=0; i<no_var; i++){
			if(variable[i].var_type == -1){
				variable[i].var_type = 6;
				init_queue(i);
				printf("\nInitialized empty queue %s", variable[i].var_name);
			}
		}
	;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1081 "2007007.y"
    {
    printf("\nWhile loop detected");
    int i = get_var_index((yyvsp[(3) - (9)].stringValue));  
    int limit = (yyvsp[(5) - (9)].val);             
    
    if(i != -1) {
        for(int j = variable[i].value.ival; j <= limit; j++) {
            variable[i].value.ival = j;
            printf("\nwhile Looping with %s = %d", variable[i].var_name, j);
            
            code_result = (yyvsp[(8) - (9)].val);
        }
    }
    printf("\nWhile loop finished\n");
    (yyval.val) = code_result;
;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1101 "2007007.y"
    {
        int i = get_var_index((yyvsp[(3) - (9)].stringValue));
        if(i != -1 && variable[i].var_type == 4) {
            int index = (int)(yyvsp[(5) - (9)].val);
            if(index >= 0 && index < 100) {
                variable[i].value.dict.values[index] = (yyvsp[(7) - (9)].val);
                if(index >= variable[i].value.dict.size) {
                    variable[i].value.dict.size = index + 1;
                }
                printf("\nSet value %f at index %d in dictionary %s", (yyvsp[(7) - (9)].val), index, variable[i].var_name);
            } else {
                printf("\nError: Index out of bounds");
            }
        }
        (yyval.val) = 0;
    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1118 "2007007.y"
    {
        int i = get_var_index((yyvsp[(3) - (7)].stringValue));
        if(i != -1 && variable[i].var_type == 4) {
            int index = (int)(yyvsp[(5) - (7)].val);
            if(index >= 0 && index < variable[i].value.dict.size) {
                printf("\nValue at index %d in dictionary %s: %f", 
                       index, variable[i].var_name, 
                       variable[i].value.dict.values[index]);
            } else {
                printf("\nError: Index out of bounds");
            }
        }
        (yyval.val) = 0;
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1133 "2007007.y"
    {
        int i1 = get_var_index((yyvsp[(3) - (7)].stringValue));
        int i2 = get_var_index((yyvsp[(5) - (7)].stringValue));
        if(i1 != -1 && i2 != -1 && 
           variable[i1].var_type == 4 && variable[i2].var_type == 4) {
            int new_size = variable[i1].value.dict.size + variable[i2].value.dict.size;
            if(new_size <= 100) {
                for(int j = 0; j < variable[i2].value.dict.size; j++) {
                    variable[i1].value.dict.values[variable[i1].value.dict.size + j] = 
                        variable[i2].value.dict.values[j];
                }
                variable[i1].value.dict.size = new_size;
                printf("\nConcatenated dictionary %s to %s", 
                       variable[i2].var_name, variable[i1].var_name);
            }
        }
        (yyval.val) = 0;
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1152 "2007007.y"
    {
        int i1 = get_var_index((yyvsp[(3) - (7)].stringValue));
        int i2 = get_var_index((yyvsp[(5) - (7)].stringValue));
        if(i1 != -1 && i2 != -1 && 
           variable[i1].var_type == 4 && variable[i2].var_type == 4) {
            variable[i2].value.dict.size = variable[i1].value.dict.size;
            for(int j = 0; j < variable[i1].value.dict.size; j++) {
                variable[i2].value.dict.values[j] = variable[i1].value.dict.values[j];
            }
            printf("\nCopied dictionary %s to %s", 
                   variable[i1].var_name, variable[i2].var_name);
        }
        (yyval.val) = 0;
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1167 "2007007.y"
    {
        int i = get_var_index((yyvsp[(3) - (5)].stringValue));
        if(i != -1 && variable[i].var_type == 4) {
            printf("\nSize of dictionary %s: %d", 
                   variable[i].var_name, variable[i].value.dict.size);
        }
        (yyval.val) = 0;
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1176 "2007007.y"
    {
        int i1 = get_var_index((yyvsp[(3) - (7)].stringValue));
        int i2 = get_var_index((yyvsp[(5) - (7)].stringValue));
        if(i1 != -1 && i2 != -1 && 
           variable[i1].var_type == 4 && variable[i2].var_type == 4) {
            if(variable[i1].value.dict.size != variable[i2].value.dict.size) {
                printf("\nDictionaries are different (different sizes)");
            } else {
                int same = 1;
                for(int j = 0; j < variable[i1].value.dict.size; j++) {
                    if(variable[i1].value.dict.values[j] != 
                       variable[i2].value.dict.values[j]) {
                        same = 0;
                        break;
                    }
                }
                printf("\nDictionaries are %s", same ? "same" : "different");
            }
        }
        (yyval.val) = 0;
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1200 "2007007.y"
    {
        int idx = get_var_index((yyvsp[(3) - (7)].stringValue));
        if(idx != -1 && variable[idx].var_type == 5) {
            if(push(idx, (yyvsp[(5) - (7)].val))) {
                printf("\nSuccessfully pushed %f to stack %s", (yyvsp[(5) - (7)].val), variable[idx].var_name);
            }
        } else {
            printf("\nError: Invalid stack operation - %s is not a stack", (yyvsp[(3) - (7)].stringValue));
        }
        (yyval.val) = (yyvsp[(5) - (7)].val);
    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1211 "2007007.y"
    {
        int idx = get_var_index((yyvsp[(3) - (5)].stringValue));
        if(idx != -1 && variable[idx].var_type == 5) {
            if(variable[idx].value.stack.top >= 0) {
                double value = pop(idx);
                printf("\nSuccessfully popped %f from stack %s", value, variable[idx].var_name);
                (yyval.val) = value;
            } else {
                printf("\nError: Cannot pop from empty stack %s", variable[idx].var_name);
                (yyval.val) = 0;
            }
        } else {
            printf("\nError: Invalid stack operation - %s is not a stack", (yyvsp[(3) - (5)].stringValue));
            (yyval.val) = 0;
        }
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1227 "2007007.y"
    {
        int idx = get_var_index((yyvsp[(3) - (5)].stringValue));
        if(idx != -1 && variable[idx].var_type == 5) {
            if(variable[idx].value.stack.top >= 0) {
                double value = top(idx);
                printf("\nTop of stack %s: %f (position: %d)", 
                       variable[idx].var_name, value, variable[idx].value.stack.top);
                (yyval.val) = value;
            } else {
                printf("\nError: Stack %s is empty", variable[idx].var_name);
                (yyval.val) = 0;
            }
        } else {
            printf("\nError: Invalid stack operation - %s is not a stack", (yyvsp[(3) - (5)].stringValue));
            (yyval.val) = 0;
        }
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1244 "2007007.y"
    {
        int idx = get_var_index((yyvsp[(3) - (5)].stringValue));
        if(idx != -1 && variable[idx].var_type == 5) {
            int empty = is_empty(idx);
            printf("\nStack %s is %s (top: %d)", 
                   variable[idx].var_name, 
                   empty ? "empty" : "not empty",
                   variable[idx].value.stack.top);
            (yyval.val) = empty;
        } else {
            if(idx == -1) {
                printf("\nError: Stack %s not declared", (yyvsp[(3) - (5)].stringValue));
            } else {
                printf("\nError: Variable %s is not a stack", (yyvsp[(3) - (5)].stringValue));
            }
            (yyval.val) = 1;  // Consider non-existent or invalid stacks as empty
        }
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1262 "2007007.y"
    {
        int idx = get_var_index((yyvsp[(3) - (5)].stringValue));
        if(idx != -1 && variable[idx].var_type == 5) {
            int size = stack_size(idx);
            printf("\nStack %s size: %d", variable[idx].var_name, size);
            (yyval.val) = size;
        } else {
            if(idx == -1) {
                printf("\nError: Stack %s not declared", (yyvsp[(3) - (5)].stringValue));
            } else {
                printf("\nError: Variable %s is not a stack", (yyvsp[(3) - (5)].stringValue));
            }
            (yyval.val) = 0;
        }
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1280 "2007007.y"
    {
        int idx = get_var_index((yyvsp[(3) - (7)].stringValue));
        if(idx != -1 && variable[idx].var_type == 6) {
            if(enqueue(idx, (yyvsp[(5) - (7)].val))) {
                printf("\nSuccessfully enqueued %f to queue %s", (yyvsp[(5) - (7)].val), variable[idx].var_name);
            }
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", (yyvsp[(3) - (7)].stringValue));
        }
        (yyval.val) = (yyvsp[(5) - (7)].val);
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1291 "2007007.y"
    {
        int idx = get_var_index((yyvsp[(3) - (5)].stringValue));
        if(idx != -1 && variable[idx].var_type == 6) {
            double value = dequeue(idx);
            printf("\nSuccessfully dequeued %f from queue %s", value, variable[idx].var_name);
            (yyval.val) = value;
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", (yyvsp[(3) - (5)].stringValue));
            (yyval.val) = 0;
        }
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1302 "2007007.y"
    {
        int idx = get_var_index((yyvsp[(3) - (5)].stringValue));
        if(idx != -1 && variable[idx].var_type == 6) {
            double value = get_front(idx);
            printf("\nFront of queue %s: %f", variable[idx].var_name, value);
            (yyval.val) = value;
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", (yyvsp[(3) - (5)].stringValue));
            (yyval.val) = 0;
        }
    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1313 "2007007.y"
    {
        int idx = get_var_index((yyvsp[(3) - (5)].stringValue));
        if(idx != -1 && variable[idx].var_type == 6) {
            double value = get_rear(idx);
            printf("\nRear of queue %s: %f", variable[idx].var_name, value);
            (yyval.val) = value;
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", (yyvsp[(3) - (5)].stringValue));
            (yyval.val) = 0;
        }
    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1324 "2007007.y"
    {
        int idx = get_var_index((yyvsp[(3) - (5)].stringValue));
        if(idx != -1 && variable[idx].var_type == 6) {
            int empty = is_queue_empty(idx);
            printf("\nQueue %s is %s", variable[idx].var_name, 
                   empty ? "empty" : "not empty");
            (yyval.val) = empty;
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", (yyvsp[(3) - (5)].stringValue));
            (yyval.val) = 1;
        }
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1336 "2007007.y"
    {
        int idx = get_var_index((yyvsp[(3) - (5)].stringValue));
        if(idx != -1 && variable[idx].var_type == 6) {
            int size = queue_size(idx);
            printf("\nQueue %s size: %d", variable[idx].var_name, size);
            (yyval.val) = size;
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", (yyvsp[(3) - (5)].stringValue));
            (yyval.val) = 0;
        }
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 3585 "2007007.tab.c"
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
#line 1349 "2007007.y"


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

