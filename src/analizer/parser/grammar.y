%scanner                  ../scanner/Scanner.h
%scanner-token-function   d_scanner.lex()
%baseclass-preinclude     ParserPreinclude.h

%stype std::string


/*
 * Section of Directives:
 *   In this section are specified some options for the parser. In addition,
 *   this section is it necessary to determine the names of all the tokens,
 *   except those with the name consisting of a single character. The inclusion
 *   of external libraries is also made to this section.
 */


/*
 * ************ Importation **************
 */
%token IMPORT
%token PACKAGE


/*
 * ********* Classes *********************
 */
%token CLASS
%token INTERFACE
%token IMPLEMENTS
%token EXTENDS
%token ABSTRACT
%token NEW
%token PUBLIC
%token PROTECTED
%token PRIVATE
%token STATIC
%token FINAL


/*
 * *********** Methods *******************
 */
%token DEF


/*
 * ********* Type of Data ****************
 */
%token TYPE_INTEGER
%token TYPE_LONG
%token TYPE_SHORT
%token TYPE_DOUBLE
%token TYPE_FLOAT
%token TYPE_STRING
%token TYPE_BOOLEAN
%token TYPE_LIST
%token TYPE_DATE


/*
 * ********** Punctuation Marks **********
 */
%token LEFT_PARENTHESES
%token RIGHT_PARENTHESES
%token LEFT_BRACKETS
%token RIGHT_BRACKETS
%token LEFT_CURLY_BRACKETS
%token RIGHT_CURLY_BRACKETS
%token SEMICOLON
%token COLON
%token DOT
%token SUSPENSION_DOTS
%token COMMA
%token EQUAL


/*
 * ********** Scarefault Marks ***********
 */
%token SCAREFAULT
%token SCENARIO
%token ENTRIES
%token OUT


/*
 * ********** Data Values ****************
 */
%token NUMBER;
%token STRING;
%token IDENTIFIER;
%token BOOL;

/*
 * ********** Control Structures *********
 */
%token IF
%token ELSE
%token QUESTION_MARK
%token SWITCH
%token CASE
%token DEFAULT
%token FOR
%token IN
%token WHILE

/*
 * ********** Operators ******************
 */
%token LOGICAL_OPERATOR
%token COMPARISON_OPERATOR
%token INCREMENT_OPERATOR


%%


/******************************* General Rules *****************************/

/*
 * It is the initial rule. Formed essentially by the rules establishing the
 *   content of the test file.
 */
startrule:
  /* Empty Rule */
|
  startrule content
;

/*
 * This rule represents the content of the test file.
 */
content:
  initial_statement 
| variable_statement
| assignment_statement
| main_body_code_statement
| method_statement
| conditional_structure_statement
| looping_structure_statement
| scenario_declaration
| entries_declaration
| out_declaration
;

/************************* End of General Rules ****************************/


/******************* Rules for Groovy Programming Language *****************/

/*
 * Represents every type of text catched. Currently, there are only STRING.
 */
text:
  STRING {
    $$ = $1;
  }
;



initial_statement:
  package_statement
| import_statement
;

import_statement:
  IMPORT parcel_initial_statement {
    const string identifier_token( $2 );
    test_generator.add_import_name( identifier_token );
  }
;

package_statement:
  PACKAGE parcel_initial_statement {
    const string identifier_token( $2 );
    test_generator.set_package_name( identifier_token );
  }
;

/*
 * Represents the structure of the name of a package or file that we need
 *   import.
 */
parcel_initial_statement:
  IDENTIFIER
| parcel_initial_statement DOT parcel_initial_statement
;



main_body_code_statement:
  class_statement
| interface_statement
;

class_statement:
  CLASS IDENTIFIER
| ABSTRACT CLASS IDENTIFIER
| class_statement IMPLEMENTS IDENTIFIER
| class_statement EXTENDS IDENTIFIER
;

interface_statement:
  INTERFACE IDENTIFIER
;

modifier:
  PUBLIC 
| PROTECTED
| PRIVATE
| STATIC
| FINAL
;



method_statement:
  method_no_return_statement
| method_with_return_statement
;

method_no_return_statement:
  DEF IDENTIFIER LEFT_PARENTHESES RIGHT_PARENTHESES {
    const string identifier_token( $2 );
    test_generator.set_method_name( identifier_token );
  }
|
  DEF IDENTIFIER LEFT_PARENTHESES params_statement RIGHT_PARENTHESES {
    const string identifier_token( $2 );
    test_generator.set_method_name( identifier_token );
  }
|
  modifier method_no_return_statement {
  }
;

method_with_return_statement:
  type IDENTIFIER LEFT_PARENTHESES RIGHT_PARENTHESES
| type IDENTIFIER LEFT_PARENTHESES params_statement RIGHT_PARENTHESES
| modifier method_with_return_statement
;
  
params_statement:
  type IDENTIFIER
| params_statement EQUAL value
| type SUSPENSION_DOTS IDENTIFIER
| IDENTIFIER
| params_statement COMMA params_statement
;



conditional_structure_statement:
  if_statement
| ternary_statement
| switch_statement
;

if_statement:
  IF LEFT_PARENTHESES logical_expression RIGHT_PARENTHESES
| ELSE if_statement
| ELSE LEFT_PARENTHESES logical_expression RIGHT_PARENTHESES
;

ternary_statement:
  logical_expression QUESTION_MARK value COLON value
;

switch_statement:
  SWITCH LEFT_PARENTHESES IDENTIFIER RIGHT_PARENTHESES
| switch_component
;

switch_component:
  CASE value COLON
| DEFAULT COLON
;

logical_expression:
  value LOGICAL_OPERATOR value
| value COMPARISON_OPERATOR value
| logical_expression LOGICAL_OPERATOR logical_expression
| logical_expression COMPARISON_OPERATOR logical_expression
;



looping_structure_statement:
  for_statement
| while_statement
;

for_statement:
  FOR LEFT_PARENTHESES assignment_statement SEMICOLON comparison_expression
  SEMICOLON increments_expression RIGHT_PARENTHESES
| FOR LEFT_PARENTHESES variable_statement COLON IDENTIFIER RIGHT_PARENTHESES
| FOR LEFT_PARENTHESES IDENTIFIER IN IDENTIFIER RIGHT_PARENTHESES
;

while_statement:
  WHILE LEFT_PARENTHESES comparison_expression RIGHT_PARENTHESES
;

comparison_expression:
  value COMPARISON_OPERATOR value
;

increments_expression:
  IDENTIFIER INCREMENT_OPERATOR
;



variable_statement:
  type IDENTIFIER
| modifier variable_statement
;

type:
  TYPE_INTEGER { $$ = $1; }
| TYPE_LONG { $$ = $1; }
| TYPE_SHORT { $$ = $1; }
| TYPE_DOUBLE { $$ = $1; }
| TYPE_FLOAT { $$ = $1; }
| TYPE_STRING { $$ = $1; }
| TYPE_BOOLEAN { $$ = $1; }
| TYPE_LIST { $$ = $1; }
| TYPE_DATE { $$ = $1; }
| IDENTIFIER { $$ = $1; }
| type LEFT_BRACKETS RIGHT_BRACKETS { $$ = $1; }
;



assignment_statement:
  IDENTIFIER EQUAL value
| IDENTIFIER EQUAL NEW IDENTIFIER LEFT_PARENTHESES RIGHT_PARENTHESES
;

value:
  NUMBER
| STRING
| BOOL
;



/*************** End of Rules for Groovy Programming Language **************/


/************************* Rules for Scarefault ****************************/

/*
 * Represents the description of the scenario of the test to implement by
 *   the Scarefault.
 */
scenario_declaration:
  SCENARIO COLON text {
    const string text_token( $3 );
  
    test_generator.set_scenario_name( text_token );
  }
;

/*
 * Represents the description of the entries of test scenario.
 */
entries_declaration:
  SCAREFAULT DOT ENTRIES COLON test_input SEMICOLON {
    /* Empty Rule */
  }
;

/*
 * Represents the data of input. 
 */
test_input:
  test_input COMMA test_input {
    /* Empty Rule */
  }
|
  NUMBER {
    const string input_token( $1 );
    int input = stoi( input_token );

    test_generator.add_scenario_entry( input );
  }  
;

/*
 * Represents the description of the output of the test scenario.
 */
out_declaration:
  SCAREFAULT DOT OUT COLON test_output SEMICOLON {
    /* Empty Rule */
  }
;

/*
 * Represents the data of output.
 */
test_output:
  NUMBER {
    const string output_token( $1 );
    int output = stoi( output_token );

    test_generator.set_scenario_out( output );
  }
;

/********************** End of Rules for Scarefault ************************/
