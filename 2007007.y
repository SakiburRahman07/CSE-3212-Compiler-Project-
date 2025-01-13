%{
	
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

%}

%union {
	double val;
	char* stringValue;
	char* type;
}

	// Defining all the used tokens and precendences of the required ones.

%error-verbose
%token MAIN INT CHAR FLOAT POWER FACTO PRIME READ PRINT IF ELIF ELSE SWITCH CASE DEFAULT FROM TO INC DEC MAX MIN ID NUM PLUS MINUS MUL DIV EQUAL NOTEQUAL GT GOE LT LOE STRING STRING_LITERAL FUNCTION RETURN MOD POW SQRT ABS LOG SIN COS TAN INCREMENT DECREMENT AND OR NOT NEQ STRICT_EQUAL STRICT_NEQ WHILE
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
%token DICT GET SET CONCAT COPY SIZE COMPARE
%token STACK PUSH POP TOP ISEMPTY
%token STACKSIZE  
%token QUEUE ENQUEUE DEQUEUE FRONT REAR QSIZE QEMPTY
	// Defining token type

%type<val> prime_code factorial_code casenum_code default_code case_code switch_code e f t expression bool_expression power_code min_code max_code declaration assignment condition for_code print_code read_code program code TYPE MAIN INT CHAR FLOAT POWER FACTO PRIME READ PRINT SWITCH CASE DEFAULT IF ELIF ELSE FROM TO INC DEC MAX MIN NUM PLUS MINUS MUL DIV EQUAL NOTEQUAL GT GOE LT LOE STRING return_statement function_call function_list function main if_statement elif_list
%type<val>while_code
%type<val>dict_operation
%type<val>stack_operation
%type<val>queue_operation
%type<stringValue> ID STRING_LITERAL

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

main: MAIN '{' code '}' {
    $$ = $3;  
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
        if (get_function_index($2) != -1) {
            printf("\nError: Function %s already defined", $2);
        } else {
            strcpy(functions[func_count].func_name, $2);
            functions[func_count].return_value = $7;
            
            strcpy(function_results[result_count].name, $2);
            function_results[result_count].value = $7;
            
            func_count++;
            result_count++;
            
            printf("\nFunction defined: %s with return value: %f", $2, $7);
        }
    }
}
;

return_statement: RETURN expression ';' {
    $$ = $2;
    printf("\nFunction returning value: %f", $2);
}
;

code: declaration code    { $$ = $1; }
    | assignment code     { $$ = $1; }
    | dict_operation code { $$ = $1; }
    | condition code      { $$ = $1; }
    | for_code code       { $$ = $1; }
    | while_code code     { $$ = $1; }
    | switch_code code    { $$ = $1; }
    | print_code code     { $$ = $1; }
    | read_code code      { $$ = $1; }
    | power_code code     { $$ = $1; }
    | factorial_code code { $$ = $1; }
    | prime_code code     { $$ = $1; }
    | min_code code       { $$ = $1; }
    | max_code code       { $$ = $1; }
    | function_call code  { $$ = $1; }
    | stack_operation code { $$ = $1; }
    | queue_operation code { $$ = $1; }
    | /* empty */         { $$ = 0; }
    ;

function_call: ID '(' ')' ';' {
    int idx = get_function_index($1);
    if(idx != -1) {
        printf("\nFunction %s called and returned: %f", 
               functions[idx].func_name, functions[idx].return_value);
        $$ = functions[idx].return_value;
    } else {
        printf("\nError: Function %s not defined", $1);
        $$ = 0;
    }
}
;

	// CFG for power() funtion
	
power_code: POWER '(' NUM ',' NUM ')'';'	{		
	double result = pow($3, $5);
	printf("\nPower function value--> %f", result);
	$$ = result;
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
    if(i == -1) {
        printf("\nWarning: Variable '%s' not found in print statement", $3);
        $$ = 0;
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
        $$ = 1;
    }
}
| PRINT '(' STRING_LITERAL ')'';' {
    printf("\n%s", $3);
    $$ = 1;
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
    if(ii == -1) {
        printf("\nWarning: Loop variable '%s' not declared", $2);
        $$ = 0;
    } else if(variable[ii].var_type != 1) {  
        printf("\nWarning: Loop variable must be an integer");
        $$ = 0;
    } else {
        int i = variable[ii].value.ival;
        int j = $4;
        int inc = $6;
        
        printf("\nStarting loop with %s = %d to %d increment %d", 
               variable[ii].var_name, i, j, inc);
        
        int original_value = variable[ii].value.ival;
        
        for(int k=i; k<j; k=k+inc){
            variable[ii].value.ival = k;
            
            code_result = $8;
            
            printf("\nLoop iteration %d: %s = %d", 
                   k, variable[ii].var_name, variable[ii].value.ival);
        }
        
        variable[ii].value.ival = j;
        printf("\nLoop completed. Final value of %s = %d", 
               variable[ii].var_name, variable[ii].value.ival);
        $$ = variable[ii].value.ival;
    }
}
| FROM ID TO NUM DEC NUM '{' code '}' {
    printf("\nFor loop detected");
    int ii = get_var_index($2);
    if(ii == -1) {
        printf("\nWarning: Loop variable '%s' not declared", $2);
        $$ = 0;
    } else if(variable[ii].var_type != 1) {  // Check if it's an integer
        printf("\nWarning: Loop variable must be an integer");
        $$ = 0;
    } else {
        int i = variable[ii].value.ival;
        int j = $4;
        int dec = $6;
        
        printf("\nStarting loop with %s = %d to %d decrement %d", 
               variable[ii].var_name, i, j, dec);
        
        int original_value = variable[ii].value.ival;
        
        for(int k=i; k>j; k=k-dec){
            variable[ii].value.ival = k;
            
            code_result = $8;
            
            printf("\nLoop iteration %d: %s = %d", 
                   k, variable[ii].var_name, variable[ii].value.ival);
        }
        
        // Set final value
        variable[ii].value.ival = j;
        printf("\nLoop completed. Final value of %s = %d", 
               variable[ii].var_name, variable[ii].value.ival);
        $$ = variable[ii].value.ival;
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
	
condition: if_statement {
        conditionMatched = 0;  // Reset for next if chain
        $$ = $1;
    }
    ;

if_statement: 
    IF '(' bool_expression ')' '{' code '}' {
        if($3 == 1) {
            printf("\n-->IF block is true");
            $$ = $6;
            conditionMatched = 1;
        } else {
            $$ = 0;
        }
    }
    | IF '(' bool_expression ')' '{' code '}' ELSE '{' code '}' {
        if($3 == 1) {
            printf("\n-->IF block is true");
            $$ = $6;
            conditionMatched = 1;
        } else if(!conditionMatched) {
            printf("\n-->OTHERWISE block is true");
            $$ = $10;
            conditionMatched = 1;
        } else {
            printf("\nCondition already fulfilled. Ignoring otherwise block.");
            $$ = 0;
        }
    }
    | IF '(' bool_expression ')' '{' code '}' elif_list ELSE '{' code '}' {
        if($3 == 1) {
            printf("\n-->IF block is true");
            $$ = $6;
            conditionMatched = 1;
        } else {
            $$ = $8;  // Value from elif_list
            if(!conditionMatched) {
                printf("\n-->OTHERWISE block is true");
                $$ = $11;
                conditionMatched = 1;
            } else {
                printf("\nCondition already fulfilled. Ignoring otherwise block.");
            }
        }
    }
    | IF '(' bool_expression ')' '{' code '}' elif_list {
        if($3 == 1) {
            printf("\n-->IF block is true");
            $$ = $6;
            conditionMatched = 1;
        } else {
            $$ = $8;  // Value from elif_list
        }
    }
    ;

elif_list: 
    elif_list ELIF '(' bool_expression ')' '{' code '}' {
        if(!conditionMatched && $4 == 1) {
            printf("\n-->ELIF block is true");
            $$ = $7;
            conditionMatched = 1;
        } else if(conditionMatched) {
            printf("\nCondition already fulfilled. Ignoring elif block.");
            $$ = $1;  // Keep previous value
        } else {
            $$ = 0;
        }

    }
    | ELIF '(' bool_expression ')' '{' code '}' {
        if(!conditionMatched && $3 == 1) {
            printf("\n-->ELIF block is true");
            $$ = $6;
            conditionMatched = 1;
        } else if(conditionMatched) {
            printf("\nCondition already fulfilled. Ignoring elif block.");
            $$ = 0;
        } else {
            $$ = 0;
        }
    }
    ;
	
	//CFG for evaluating boolian expression

expression: e {$$ = $1;}
    ;

e: e PLUS f {
        $$ = $1 + $3;
    }
    | e MINUS f {
        $$ = $1 - $3;
    }
    | f {
        $$ = $1;
    }
    ;

f: f MUL t {
        $$ = $1 * $3;
    }
    | f DIV t {
        if($3 != 0) {
            $$ = $1 / $3;
        } else {
            printf("\nError: Division by zero");
            $$ = 0;
        }
    }
    | f MOD t {
        if($3 != 0) {
            $$ = (int)$1 % (int)$3; 
            printf("\nModulo operation: %d", (int)$$);
        } else {
            printf("\nError: Modulo by zero");
            $$ = 0;
        }
    }
    | t POW f {
        $$ = pow($1, $3);
        printf("\nPower operation: %f ^ %f = %f", $1, $3, $$);
    }
    | t {
        $$ = $1;
    }
    ;

t: '(' e ')' {
        $$ = $2;
    }
    | NUM {
        $$ = $1;
    }
    | ID {
        int i = get_var_index($1);
        if(i != -1) {
            switch(variable[i].var_type) {
                case 1: // INT
                    $$ = (double)variable[i].value.ival;
                    break;
                case 2: // FLOAT
                    $$ = variable[i].value.fval;
                    break;
                case 0: // CHAR
                    $$ = (double)variable[i].value.cval;
                    break;
                default:
                    printf("\nError: Invalid type for mathematical operation");
                    $$ = 0;
                    break;
            }
        } else {
            printf("\nError: Variable '%s' not declared", $1);
            $$ = 0;
        }
    }
    | SQRT '(' e ')' {
        if($3 >= 0) {
            $$ = sqrt($3);
            printf("\nSquare root operation: sqrt(%f) = %f", $3, $$);
        } else {
            printf("\nError: Square root of negative number");
            $$ = 0;
        }
    }
    | ABS '(' e ')' {
        $$ = fabs($3);
        printf("\nAbsolute value operation: |%f| = %f", $3, $$);
    }
    | LOG '(' e ')' {
        if($3 > 0) {
            $$ = log($3);
            printf("\nLogarithm operation: log(%f) = %f", $3, $$);
        } else {
            printf("\nError: Logarithm of non-positive number");
            $$ = 0;
        }
    }
    | SIN '(' e ')' {
        $$ = sin($3);
        printf("\nSine operation: sin(%f) = %f", $3, $$);
    }
    | COS '(' e ')' {
        $$ = cos($3);
        printf("\nCosine operation: cos(%f) = %f", $3, $$);
    }
    | TAN '(' e ')' {
        $$ = tan($3);
        printf("\nTangent operation: tan(%f) = %f", $3, $$);
    }
    ;

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
declaration: TYPE init_list ';' {
    $<val>$ = $1;  // Store the type for init_list to use
    set_var_type($1);
    printf("\nVariable(s) declared and initialized");
    $$ = 0;
}
;

// Add new rules for initialization
init_list: init_list ',' init_item {
    $<val>$ = $<val>0;  // Pass the type down
}
| init_item {
    $<val>$ = $<val>0;  // Pass the type down
}
;

init_item: ID {
    if(search_var($1)==0){
        strcpy(variable[no_var].var_name, $1);
        variable[no_var].var_type = $<val>0;  // Get type from parent
        printf("\nDeclared variable: %s", $1);
        
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
        printf("\nWarning: Variable '%s' already declared", $1);
    }
}
| ID '=' expression {
    if(search_var($1)==0){
        strcpy(variable[no_var].var_name, $1);
        variable[no_var].var_type = $<val>0;  
        printf("\nDeclared variable: %s with initialization", $1);
        
        // Initialize based on type
        switch(variable[no_var].var_type) {
            case 1: // INT
                variable[no_var].value.ival = (int)$3;
                printf("\nInitialized to integer: %d", variable[no_var].value.ival);
                break;
            case 2: // FLOAT
                variable[no_var].value.fval = (float)$3;
                printf("\nInitialized to float: %f", variable[no_var].value.fval);
                break;
            case 0: // CHAR
                variable[no_var].value.cval = (char)$3;
                printf("\nInitialized to char: %c", variable[no_var].value.cval);
                break;
        }
        no_var++;
    }
    else{
        printf("\nWarning: Variable '%s' already declared", $1);
    }
}
| ID '=' STRING_LITERAL {
    if(search_var($1)==0){
        strcpy(variable[no_var].var_name, $1);
        variable[no_var].var_type = $<val>0;  // Get type from parent
        
        if(variable[no_var].var_type == 3) { // STRING
            variable[no_var].value.sval = strdup($3);
            printf("\nDeclared string variable: %s with initialization", $1);
            printf("\nInitialized to string: %s", $3);
        } else {
            printf("\nError: Type mismatch - cannot assign string to non-string variable");
        }
        no_var++;
    }
    else{
        printf("\nWarning: Variable '%s' already declared", $1);
    }
}
;

// CFG for assigning value
assignment: ID '=' expression ';' {
    int i = get_var_index($1);
    if(i == -1) {
        printf("\nError: Variable '%s' not declared", $1);
        $$ = 0;
    } else {
        switch(variable[i].var_type) {
            case 1: // INT
                variable[i].value.ival = (int)$3;
                printf("\nAssigning value %d to %s", variable[i].value.ival, variable[i].var_name);
                break;
            case 2: // FLOAT
                variable[i].value.fval = (float)$3;
                printf("\nAssigning value %f to %s", variable[i].value.fval, variable[i].var_name);
                break;
            case 0: // CHAR
                variable[i].value.cval = (char)$3;
                //printf("\nAssigning character value: %c", variable[i].value.cval);
                break;
        }
        $$ = $3;
    }
}
| ID INCREMENT ';' {
    int i = get_var_index($1);
    if(i == -1) {
        printf("\nError: Variable '%s' not declared", $1);
        $$ = 0;
    } else {
        if(variable[i].var_type==1){
            variable[i].value.ival++;
            printf("\nIncrementing %s to %d", variable[i].var_name, variable[i].value.ival);
            $$ = variable[i].value.ival;
        }
        else if(variable[i].var_type==2){
            variable[i].value.fval++;
            printf("\nIncrementing %s to %f", variable[i].var_name, variable[i].value.fval);
            $$ = variable[i].value.fval;
        }
    }
}
| ID DECREMENT ';' {
    int i = get_var_index($1);
    if(i == -1) {
        printf("\nError: Variable '%s' not declared", $1);
        $$ = 0;
    } else {
        if(variable[i].var_type==1){
            variable[i].value.ival--;
            printf("\nDecrementing %s to %d", variable[i].var_name, variable[i].value.ival);
            $$ = variable[i].value.ival;
        }
        else if(variable[i].var_type==2){
            variable[i].value.fval--;
            printf("\nDecrementing %s to %f", variable[i].var_name, variable[i].value.fval);
            $$ = variable[i].value.fval;
        }
    }
}
| ID '=' STRING_LITERAL ';' {
    int i = get_var_index($1);
    if(i == -1) {
        printf("\nError: Variable '%s' not declared", $1);
        $$ = 0;
    } else {
        if(variable[i].var_type == 3){  // Check if it's a string type
            variable[i].value.sval = strdup($3);
            printf("\nAssigning string value: %s to %s", variable[i].value.sval, variable[i].var_name);
            $$ = 1;
        } else {
            printf("\nError: Type mismatch - cannot assign string to non-string variable");
            $$ = 0;
        }
    }
}
;

TYPE: INT	{$$ = 1; printf("\nVariable type--> Integer");}
	| FLOAT	{$$ = 2; printf("\nVariable type--> Float");}
	| CHAR	{$$ = 0; printf("\nVariable type--> Character");}
	| STRING {$$ = 3; printf("\nVariable type--> String");}
	| DICT {
		$$ = 4;  // 4 for dictionary type
		printf("\nVariable type--> Dictionary");
	}
	| STACK {
		$$ = 5;  // 5 for stack type
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
	}
	| QUEUE {
		$$ = 6; 
		printf("\nVariable type--> Queue");
		for(int i=0; i<no_var; i++){
			if(variable[i].var_type == -1){
				variable[i].var_type = 6;
				init_queue(i);
				printf("\nInitialized empty queue %s", variable[i].var_name);
			}
		}
	}
	;

// Finally the while_code rule that uses bool_expression
while_code: WHILE '(' ID LOE NUM ')' '{' code '}' {
    printf("\nWhile loop detected");
    int i = get_var_index($3);  
    int limit = $5;             
    
    if(i != -1) {
        for(int j = variable[i].value.ival; j <= limit; j++) {
            variable[i].value.ival = j;
            printf("\nwhile Looping with %s = %d", variable[i].var_name, j);
            
            code_result = $8;
        }
    }
    printf("\nWhile loop finished\n");
    $$ = code_result;
}
;

// Add dictionary operations
dict_operation: 
    SET '(' ID ',' NUM ',' expression ')' ';' {
        int i = get_var_index($3);
        if(i != -1 && variable[i].var_type == 4) {
            int index = (int)$5;
            if(index >= 0 && index < 100) {
                variable[i].value.dict.values[index] = $7;
                if(index >= variable[i].value.dict.size) {
                    variable[i].value.dict.size = index + 1;
                }
                printf("\nSet value %f at index %d in dictionary %s", $7, index, variable[i].var_name);
            } else {
                printf("\nError: Index out of bounds");
            }
        }
        $$ = 0;
    }
    // Get value at index
    | GET '(' ID ',' NUM ')' ';' {
        int i = get_var_index($3);
        if(i != -1 && variable[i].var_type == 4) {
            int index = (int)$5;
            if(index >= 0 && index < variable[i].value.dict.size) {
                printf("\nValue at index %d in dictionary %s: %f", 
                       index, variable[i].var_name, 
                       variable[i].value.dict.values[index]);
            } else {
                printf("\nError: Index out of bounds");
            }
        }
        $$ = 0;
    }
    // Concatenate two dictionaries
    | CONCAT '(' ID ',' ID ')' ';' {
        int i1 = get_var_index($3);
        int i2 = get_var_index($5);
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
        $$ = 0;
    }
    // Copy dictionary
    | COPY '(' ID ',' ID ')' ';' {
        int i1 = get_var_index($3);
        int i2 = get_var_index($5);
        if(i1 != -1 && i2 != -1 && 
           variable[i1].var_type == 4 && variable[i2].var_type == 4) {
            variable[i2].value.dict.size = variable[i1].value.dict.size;
            for(int j = 0; j < variable[i1].value.dict.size; j++) {
                variable[i2].value.dict.values[j] = variable[i1].value.dict.values[j];
            }
            printf("\nCopied dictionary %s to %s", 
                   variable[i1].var_name, variable[i2].var_name);
        }
        $$ = 0;
    }
    // Get size of dictionary
    | SIZE '(' ID ')' ';' {
        int i = get_var_index($3);
        if(i != -1 && variable[i].var_type == 4) {
            printf("\nSize of dictionary %s: %d", 
                   variable[i].var_name, variable[i].value.dict.size);
        }
        $$ = 0;
    }
    // Compare dictionaries
    | COMPARE '(' ID ',' ID ')' ';' {
        int i1 = get_var_index($3);
        int i2 = get_var_index($5);
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
        $$ = 0;
    }
    ;

stack_operation:
    PUSH '(' ID ',' expression ')' ';' {
        int idx = get_var_index($3);
        if(idx != -1 && variable[idx].var_type == 5) {
            if(push(idx, $5)) {
                printf("\nSuccessfully pushed %f to stack %s", $5, variable[idx].var_name);
            }
        } else {
            printf("\nError: Invalid stack operation - %s is not a stack", $3);
        }
        $$ = $5;
    }
    | POP '(' ID ')' ';' {
        int idx = get_var_index($3);
        if(idx != -1 && variable[idx].var_type == 5) {
            if(variable[idx].value.stack.top >= 0) {
                double value = pop(idx);
                printf("\nSuccessfully popped %f from stack %s", value, variable[idx].var_name);
                $$ = value;
            } else {
                printf("\nError: Cannot pop from empty stack %s", variable[idx].var_name);
                $$ = 0;
            }
        } else {
            printf("\nError: Invalid stack operation - %s is not a stack", $3);
            $$ = 0;
        }
    }
    | TOP '(' ID ')' ';' {
        int idx = get_var_index($3);
        if(idx != -1 && variable[idx].var_type == 5) {
            if(variable[idx].value.stack.top >= 0) {
                double value = top(idx);
                printf("\nTop of stack %s: %f (position: %d)", 
                       variable[idx].var_name, value, variable[idx].value.stack.top);
                $$ = value;
            } else {
                printf("\nError: Stack %s is empty", variable[idx].var_name);
                $$ = 0;
            }
        } else {
            printf("\nError: Invalid stack operation - %s is not a stack", $3);
            $$ = 0;
        }
    }
    | ISEMPTY '(' ID ')' ';' {
        int idx = get_var_index($3);
        if(idx != -1 && variable[idx].var_type == 5) {
            int empty = is_empty(idx);
            printf("\nStack %s is %s (top: %d)", 
                   variable[idx].var_name, 
                   empty ? "empty" : "not empty",
                   variable[idx].value.stack.top);
            $$ = empty;
        } else {
            if(idx == -1) {
                printf("\nError: Stack %s not declared", $3);
            } else {
                printf("\nError: Variable %s is not a stack", $3);
            }
            $$ = 1;  // Consider non-existent or invalid stacks as empty
        }
    }
    | STACKSIZE '(' ID ')' ';' {
        int idx = get_var_index($3);
        if(idx != -1 && variable[idx].var_type == 5) {
            int size = stack_size(idx);
            printf("\nStack %s size: %d", variable[idx].var_name, size);
            $$ = size;
        } else {
            if(idx == -1) {
                printf("\nError: Stack %s not declared", $3);
            } else {
                printf("\nError: Variable %s is not a stack", $3);
            }
            $$ = 0;
        }
    }
    ;

queue_operation:
    ENQUEUE '(' ID ',' expression ')' ';' {
        int idx = get_var_index($3);
        if(idx != -1 && variable[idx].var_type == 6) {
            if(enqueue(idx, $5)) {
                printf("\nSuccessfully enqueued %f to queue %s", $5, variable[idx].var_name);
            }
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", $3);
        }
        $$ = $5;
    }
    | DEQUEUE '(' ID ')' ';' {
        int idx = get_var_index($3);
        if(idx != -1 && variable[idx].var_type == 6) {
            double value = dequeue(idx);
            printf("\nSuccessfully dequeued %f from queue %s", value, variable[idx].var_name);
            $$ = value;
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", $3);
            $$ = 0;
        }
    }
    | FRONT '(' ID ')' ';' {
        int idx = get_var_index($3);
        if(idx != -1 && variable[idx].var_type == 6) {
            double value = get_front(idx);
            printf("\nFront of queue %s: %f", variable[idx].var_name, value);
            $$ = value;
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", $3);
            $$ = 0;
        }
    }
    | REAR '(' ID ')' ';' {
        int idx = get_var_index($3);
        if(idx != -1 && variable[idx].var_type == 6) {
            double value = get_rear(idx);
            printf("\nRear of queue %s: %f", variable[idx].var_name, value);
            $$ = value;
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", $3);
            $$ = 0;
        }
    }
    | QEMPTY '(' ID ')' ';' {
        int idx = get_var_index($3);
        if(idx != -1 && variable[idx].var_type == 6) {
            int empty = is_queue_empty(idx);
            printf("\nQueue %s is %s", variable[idx].var_name, 
                   empty ? "empty" : "not empty");
            $$ = empty;
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", $3);
            $$ = 1;
        }
    }
    | QSIZE '(' ID ')' ';' {
        int idx = get_var_index($3);
        if(idx != -1 && variable[idx].var_type == 6) {
            int size = queue_size(idx);
            printf("\nQueue %s size: %d", variable[idx].var_name, size);
            $$ = size;
        } else {
            printf("\nError: Invalid queue operation - %s is not a queue", $3);
            $$ = 0;
        }
    }
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
