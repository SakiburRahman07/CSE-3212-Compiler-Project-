%{
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
	
	// Helper function to determine expression type
	int get_expression_type(double value) {
		// Check if value is an integer
		if(value == (int)value) {
			return 1;  // Integer type
		}
		return 2;  // Float type
	}
	
%}

%union{
	double val;
	char* stringValue;
}

	// Defining all the used tokens and precendences of the required ones.

%error-verbose
%token MAIN INT CHAR FLOAT POWER FACTO PRIME READ PRINT IF ELIF ELSE SWITCH CASE DEFAULT FROM TO INC DEC MAX MIN ID NUM PLUS MINUS MUL DIV EQUAL NOTEQUAL GT GOE LT LOE STRING STRING_LITERAL FUNCTION RETURN MOD POW SQRT ABS LOG SIN COS TAN INCREMENT DECREMENT AND OR NOT NEQ STRICT_EQUAL STRICT_NEQ
%left OR
%left AND
%right NOT
%left EQUAL NOTEQUAL NEQ STRICT_EQUAL STRICT_NEQ
%left GT GOE LT LOE
%left PLUS MINUS
%left MUL DIV MOD
%right POW
%right UMINUS
%right INCREMENT DECREMENT

	// Defining token type

%type<val>prime_code factorial_code casenum_code default_code case_code switch_code e f t expression else_if elsee bool_expression power_code min_code max_code declaration assignment condition for_code print_code read_code program code TYPE MAIN INT CHAR FLOAT POWER FACTO PRIME READ PRINT SWITCH CASE DEFAULT IF ELIF ELSE FROM TO INC DEC MAX MIN NUM PLUS MINUS MUL DIV EQUAL NOTEQUAL GT GOE LT LOE STRING return_statement function_call function_list function main

%type<stringValue> ID1 ID STRING_LITERAL

%%

	// Rules for the code using tokens

program: function_list main {
            printf("\nValid program\n");
            printf("\nNo of variables--> %d", no_var);
            $$ = $1;
        }
        | main {
            printf("\nValid program\n");
            printf("\nNo of variables--> %d", no_var);
            $$ = $1;
        }
        ;

// Update the main rule to handle both syntaxes
main: MAIN '{' code '}' {
    $$ = $3;  // Pass up the value from code
}
    | MAIN '(' ')' '{' code '}' {  // Add this rule to handle ()
    $$ = $5;
}
    ;

function_list: function_list function {
        $$ = $2;
    }
    | function {
        $$ = $1;
    }
    ;

function: FUNCTION ID '(' ')' '{' code return_statement '}' {
            if (func_count < 100) {
                strcpy(functions[func_count].func_name, $2);
                functions[func_count].return_value = $7;
                func_count++;
                printf("\nFunction defined: %s", $2);
            }
        }
        ;

return_statement: RETURN expression ';' {
            $$ = $2;
        }
        ;

code: declaration code    { $$ = $1; }
    | assignment code     { $$ = $1; }
    | condition code      { $$ = $1; }
    | for_code code       { $$ = $1; }
    | switch_code code    { $$ = $1; }
    | print_code code     { $$ = $1; }
    | read_code code      { $$ = $1; }
    | power_code code     { $$ = $1; }
    | factorial_code code { $$ = $1; }
    | prime_code code     { $$ = $1; }
    | min_code code       { $$ = $1; }
    | max_code code       { $$ = $1; }
    | function_call code  { $$ = $1; }
    | /* empty */         { $$ = 0; }  // Add action for empty rule
    ;

function_call: ID '(' ')' ';' {
    int idx = get_function_index($1);
    if(idx != -1) {
        printf("\nFunction called: %s", functions[idx].func_name);
        $$ = functions[idx].return_value;  // Set the return value
    } else {
        yyerror("Function not defined");
        $$ = 0;  // Default value on error
    }
}
;

	// CFG for power() funtion
	
power_code: POWER '(' NUM ',' NUM ')'';'	{		
	int i;
	i = pow($3, $5);
	printf("\nPower function value--> %d ", i);
}
	;

	//CFG for calculating factorial of a number

factorial_code: FACTO '(' NUM ')' ';'	{
	int j = $3;
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
	
}
	;
	
	//CFG for checking if a number is prime or not
	
prime_code: PRIME '(' NUM ')' ';'{
	int n, i, flag = 0;
	n = $3;
	for (i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			flag = 1;
			break;
		}
	}
    printf("\n%d", flag);

}
	;

	//CFG for max() funtion

max_code: MAX '(' ID ',' ID')'';'{
	int i = get_var_index($3);
	int j = get_var_index($5);
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
}
	;
	
	//CFG for min() function
	
min_code: MIN '(' ID ',' ID')'';'{
	int i = get_var_index($3);
	int j = get_var_index($5);
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
}
	;
	
	//CFG for print() function
	
print_code: PRINT '(' ID ')'';' {
        int i = get_var_index($3);
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
    }
    | PRINT '(' STRING_LITERAL ')'';' {
        printf("\n%s", $3);  // Print the string literal directly
    }
    ;
	
	//CFG for read() funtion
	
read_code: READ'(' ID ')'';'{
	int i = get_var_index($3);
	printf("\nRead command found for variabale--> %s, but no further implementaion\n",variable[i].var_name);
}
	;
	
	// CFG for from-to loop (For Loop)

switch_code: SWITCH '(' ID ')' '{' case_code '}' {
	printf("\nSwitch-case structure detected.");
}
	;
case_code: casenum_code default_code
	;

casenum_code: CASE NUM '{' code '}' casenum_code {
        printf("\nCase no--> %d", $2);
        $$ = $4;
    }
    | /* empty */ {
        $$ = 0;  // Add action for empty rule
    }
    ;
default_code: DEFAULT '{' code '}'
	;


for_code: FROM ID TO NUM INC NUM '{' code '}' {
	printf("\nFor loop detected");
	int ii = get_var_index($2);
	int i = variable[ii].value.ival;  // Changed from variable[ii].ival
	int j = $4;
	int inc = $6;
	int k;
	for(k=i; k<j; k=k+inc){
		printf("\nFrom-To Loop running-->");
	}
		
}
		| FROM ID TO NUM DEC NUM '{' code '}'{
	printf("\nFor loop detected");
	int ii = get_var_index($2);
	int i = variable[ii].value.ival;  // Changed from variable[ii].ival
	int j = $4;
	int dec = $6;
	int k;
	for(k=i; k<j; k=k-dec){
		printf("\nFrom-To Loop running-->");
	}
}
	;
	
	//CFG for while loop
	/*
while_code: WHILE'(' bool_expression ')''{' code '}'{
	printf("\nwhile loop detected\n");
	int i = $3;
	while(i==1){
		printf("\nWhile Loop running--> %d", $6);
	}
	
}
	;
	*/
	//CFG for if-elif-else structure
	
condition: IF'(' bool_expression ')''{'code'}' else_if elsee {
	printf("\nIF condition detected");
	int i = $3;
	if(i==1){
		printf("\nIF condition is true");
	}
	else{
		printf("\nIF condition false");
	}
}
	;
else_if: ELIF '(' bool_expression ')' '{' code '}' else_if {
        if($3 == 1) {
            $$ = $6;  // Use value from if block
            printf("\nELIF condition true");
        } else {
            $$ = $8;  // Use value from next else_if
            printf("\nELIF condition false");
        }
    }
    | /* empty */ { 
        $$ = 0;  // Return 0 for no elif
    }
    ;
elsee: ELSE '{' code '}' {
        $$ = $3;  // Return value from else block
        printf("\nELSE condition is detected");
    }
    | /* empty */ { 
        $$ = 0;  // Return 0 for no else
    }
    ;
	
	//CFG for evaluating boolian expression

bool_expression: 
    bool_expression AND bool_expression {
        $$ = ($1 && $3) ? 1 : 0;
    }
    | bool_expression OR bool_expression {
        $$ = ($1 || $3) ? 1 : 0;
    }
    | NOT bool_expression {
        $$ = !$2 ? 1 : 0;
    }
    | '(' bool_expression ')' {
        $$ = $2;
    }
    | expression GT expression {
        if($1 > $3) {
            $$ = 1;
        } else {
            $$ = 0;
        }
    }
    | expression LT expression {
        if($1 < $3) {
            $$ = 1;
        } else {
            $$ = 0;
        }
    }
    | expression GOE expression {
        if($1 >= $3) {
            $$ = 1;
        } else {
            $$ = 0;
        }
    }
    | expression LOE expression {
        if($1 <= $3) {
            $$ = 1;
        } else {
            $$ = 0;
        }
    }
    | expression EQUAL expression {
        if($1==$3) {
            $$ = 1;
        } else {
            $$ = 0;
        }
    }
    | expression STRICT_EQUAL expression {
        if($1==$3 && get_expression_type($1) == get_expression_type($3)) {
            $$ = 1;
        } else {
            $$ = 0;
        }
    }
    | expression STRICT_NEQ expression {
        if($1!=$3 || get_expression_type($1) != get_expression_type($3)) {
            $$ = 1;
        } else {
            $$ = 0;
        }
    }
    | expression NOTEQUAL expression {
        if($1!=$3) {
            $$ = 1;
        } else {
            $$ = 0;
        }
    }
    | expression NEQ expression {
        if($1!=$3) {
            $$ = 1;
        } else {
            $$ = 0;
        }
    }
    ;

	// CFG for variable declaration
declaration: TYPE ID1 ';' {
	set_var_type($1);
}
	;
TYPE: INT	{$$ = 1; printf("\nVariable type--> Integer");}
	| FLOAT	{$$ = 2; printf("\nVariable type--> Float");}
	| CHAR	{$$ = 0; printf("\nVariable type--> Character");}
	| STRING {$$ = 3; printf("\nVariable type--> String");}
	;
ID1: ID1 ',' ID {
	if(search_var($3)==0){
		printf("\nValid declaration");
		strcpy(variable[no_var].var_name, $3);
		printf("\nVariable name--> %s", $3);
		variable[no_var].var_type =  -1;
		no_var = no_var + 1;
	}
	else{
		printf("\nVariable is already used");
	}
} 
	| ID {
	if(search_var($1)==0){
		printf("\nValid declaration");
		strcpy(variable[no_var].var_name, $1);
		printf("\nVariable name--> %s", $1);
		variable[no_var].var_type =  -1;
		no_var = no_var + 1;
	}
	else{
		printf("\nVariable is already used");
	}
	strcpy($$, $1);
}
	;
	
	// CFG for assigning value
assignment: ID '=' expression ';' {
        $$ = $3;
        if(search_var($1)==1){
            int i = get_var_index($1);
            if(variable[i].var_type==0){
                variable[i].value.cval = (char)$3;
                printf("\nAssigning character value: %c", variable[i].value.cval);
            }
            else if(variable[i].var_type==1){
                variable[i].value.ival = (int)$3;
                printf("\nVariable value--> %d", variable[i].value.ival);
            }
            else if(variable[i].var_type==2){
                variable[i].value.fval = (float)$3;
                printf("\nVariable value--> %f", variable[i].value.fval);
            }
        }
    }
    | ID INCREMENT ';' {
        if(search_var($1)==1){
            int i = get_var_index($1);
            if(variable[i].var_type==1){
                $$ = variable[i].value.ival++;
                printf("\nVariable value--> %d", variable[i].value.ival);
            }
            else if(variable[i].var_type==2){
                $$ = variable[i].value.fval++;
                printf("\nVariable value--> %f", variable[i].value.fval);
            }
        }
    }
    | ID DECREMENT ';' {
        if(search_var($1)==1){
            int i = get_var_index($1);
            if(variable[i].var_type==1){
                $$ = variable[i].value.ival--;
                printf("\nVariable value--> %d", variable[i].value.ival);
            }
            else if(variable[i].var_type==2){
                $$ = variable[i].value.fval--;
                printf("\nVariable value--> %f", variable[i].value.fval);
            }
        }
    }
    | ID '=' STRING_LITERAL ';' {
        if(search_var($1)==1){
            int i = get_var_index($1);
            if(variable[i].var_type==3){
                variable[i].value.sval = strdup($3);
                printf("\nAssigning string value: %s", variable[i].value.sval);
            }
            else{
                printf("\nType mismatch error\n");
            }
        }
        else{
            printf("\nVariable is not declared\n");
        }
    }
    ;

expression: e {$$ = $1;}
	;
e: e PLUS f {$$ = $1 + $3; }
	| e MINUS f {$$ = $1 - $3;}
	| f      {$$ = $1;}
	;
f: f MUL t {$$ = $1 * $3;}
	| f DIV t {
		if($3 != 0) {
			$$ = $1 / $3;
		} else {
			yyerror("Division by zero");
			$$ = 0;
		}
	}
	| f MOD t {
		if($3 != 0) {
			$$ = fmod($1, $3);
		} else {
			yyerror("Modulo by zero");
			$$ = 0;
		}
	}
	| t POW f {
		$$ = pow($1, $3);
	}
	| t      {$$ = $1;}
	;
t: '(' e ')' {$$ = $2;}
	| SQRT '(' e ')' {
		if($3 >= 0) {
			$$ = sqrt($3);
		} else {
			yyerror("Square root of negative number");
			$$ = 0;
		}
	}
	| ABS '(' e ')'  { $$ = fabs($3); }
	| LOG '(' e ')'  {
		if($3 > 0) {
			$$ = log($3);
		} else {
			yyerror("Logarithm of non-positive number");
			$$ = 0;
		}
	}
	| SIN '(' e ')'  { $$ = sin($3); }
	| COS '(' e ')'  { $$ = cos($3); }
	| TAN '(' e ')'  { $$ = tan($3); }
	| ID    {
		int id_index = get_var_index($1);
		if(id_index == -1) {
			yyerror("VARIABLE DOESN'T EXIST");
			$$ = 0;
		} else {
			if(variable[id_index].var_type == 0) {
				$$ = (double)variable[id_index].value.cval;
			} else if(variable[id_index].var_type == 1) {
				$$ = variable[id_index].value.ival;
			} else if(variable[id_index].var_type == 2) {
				$$ = variable[id_index].value.fval;
			}
		}
	}
	| NUM  {$$ = $1;}
	;

%%

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