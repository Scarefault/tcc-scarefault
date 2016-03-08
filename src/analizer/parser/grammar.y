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

    std::cout << "import_statement passed" << std::endl;
  }
;

package_statement:
  PACKAGE parcel_initial_statement {
    const string identifier_token( $2 );
    test_generator.set_package_name( identifier_token );

    std::cout << "package_statement passed" << std::endl;
  }
;

/*
 * Represents the structure of the name of a package or file that we need
 *   import.
 */
parcel_initial_statement:
  IDENTIFIER {
    /* Empty Rule. */
    std::cout << "parcel_initial_statement passed, simple" << std::endl;
  }
|
  parcel_initial_statement DOT parcel_initial_statement {
    /* Empty Rule. */
    std::cout << "parcel_initial_statement passed, composed" << std::endl;
  }
;



main_body_code_statement:
  class_statement
| interface_statement
;

class_statement:
  CLASS IDENTIFIER {
    std::cout << "class_statement passed" << std::endl;
  }
|
  ABSTRACT CLASS IDENTIFIER {
    std::cout << "class_statement passed, with abstract" << std::endl;
  }
|
  class_statement IMPLEMENTS IDENTIFIER {
    std::cout << "class_statement passed, with implements" << std::endl;
  }
|
  class_statement EXTENDS IDENTIFIER {
    std::cout << "class_statement passed, with extends" << std::endl;
  }
;

interface_statement:
  INTERFACE IDENTIFIER {
    std::cout << "interface_statement passed" << std::endl;
  }
;

modifier:
  PUBLIC { std::cout << "modifier public passed" << std::endl; }
| PROTECTED { std::cout << "modifier protected passed" << std::endl; }
| PRIVATE { std::cout << "modifier private passed" << std::endl; }
| STATIC { std::cout << "modifier static passed" << std::endl; }
| FINAL { std::cout << "modifier final passed" << std::endl; }
;



method_statement:
  method_no_return_statement
| method_with_return_statement
;

method_no_return_statement:
  DEF IDENTIFIER LEFT_PARENTHESES RIGHT_PARENTHESES {
    const string identifier_token( $2 );
    test_generator.set_method_name( identifier_token );

    std::cout << "method_no_return_statement passed, no params" << std::endl;
  }
|
  DEF IDENTIFIER LEFT_PARENTHESES params_statement RIGHT_PARENTHESES {
    const string identifier_token( $2 );
    test_generator.set_method_name( identifier_token );

    std::cout << "method_no_return_statement passed, with params"
              << std::endl;
  }
|
  modifier method_no_return_statement {
    std::cout << "method_no_return_statement passed, with modifer"
              << std::endl;
  }
;

method_with_return_statement:
  type IDENTIFIER LEFT_PARENTHESES RIGHT_PARENTHESES {
    std::cout << "method_with_return_statement passed, no params"
              << std::endl;
  }
|
  type IDENTIFIER LEFT_PARENTHESES params_statement RIGHT_PARENTHESES {
    std::cout << "method_with_return_statement passed, with params"
              << std::endl;
  }
|
  modifier method_with_return_statement {
    std::cout << "method_with_return_statement passed, with modifier"
              << std::endl;
  }
;
  
params_statement:
  type IDENTIFIER {
    /* Empty Rule. */
    std::cout << "params_statement passed, with type" << std::endl;
  }
|
  params_statement EQUAL value {
    /* Empty Rule. */
    std::cout << "params_statement passed, with default value" << std::endl;
  }
|
  type SUSPENSION_DOTS IDENTIFIER {
    /* Empty Rule. */
    std::cout << "params_statement passed, varargs" << std::endl;
  }
|
  IDENTIFIER {
    /* Empty Rule. */
    std::cout << "params_statement passed, no type" << std::endl;
  }
|
  params_statement COMMA params_statement {
    /* Empty Rule. */
    std::cout << "params_statement passed, many params" << std::endl;
  }
;



conditional_structure_statement:
  if_statement
| ternary_statement
| switch_statement
;

if_statement:
  IF LEFT_PARENTHESES logical_expression RIGHT_PARENTHESES {
    std::cout << "if_statement passed, if" << std::endl;
  }
|
  ELSE if_statement {
    std::cout << "if_statement passed, else-if" << std::endl;
  }
|
  ELSE LEFT_PARENTHESES logical_expression RIGHT_PARENTHESES {
    std::cout << "if_statement passed, else" << std::endl;
  }
;

ternary_statement:
  logical_expression QUESTION_MARK value COLON value {
    std::cout << "ternary_statement passed" << std::endl;
  }
;

switch_statement:
  SWITCH LEFT_PARENTHESES IDENTIFIER RIGHT_PARENTHESES {
    std::cout << "switch_statement passed" << std::endl;
  }
|
  switch_component {
    std::cout << "switch_component passed" << std::endl;
  }
;

switch_component:
  CASE value COLON {
    std::cout << "case passed" << std::endl;
  }
|
  DEFAULT COLON {
    std::cout << "default passed" << std::endl;
  }
;

logical_expression:
  value LOGICAL_OPERATOR value {
    std::cout << "logical expression passed" << std::endl;
  }
|
  value COMPARISON_OPERATOR value {
    std::cout << "logical expression passed" << std::endl;
  }
|
  logical_expression LOGICAL_OPERATOR logical_expression {
    std::cout << "logical expression passed" << std::endl;
  }
|
  logical_expression COMPARISON_OPERATOR logical_expression {
    std::cout << "logical_expression passed" << std::endl;
  }
;



looping_structure_statement:
  for_statement
;

for_statement:
  FOR LEFT_PARENTHESES assignment_statement SEMICOLON comparison_expression
  SEMICOLON increments_expression RIGHT_PARENTHESES {
    std::cout << "for_statement passed" << std::endl;
  }
;

comparison_expression:
  value COMPARISON_OPERATOR value {
    std::cout << "comparison_expression passed" << std::endl;
  }
;

increments_expression:
  IDENTIFIER INCREMENT_OPERATOR {
    std::cout << "increments_expression passed" << std::endl;
  }
;



variable_statement:
  type IDENTIFIER {
    /* Empty Rule. */
    std::cout << "variable_statement passed" << std::endl;
  }
| modifier variable_statement {
    std::cout << "variable_statement passed, with modifier" << std::endl;
  }
;

type:
  TYPE_INTEGER { $$ = $1; std::cout << "integer passed" << std::endl; }
| TYPE_LONG { $$ = $1; std::cout << "long passed" << std::endl; }
| TYPE_SHORT { $$ = $1; std::cout << "short passed" << std::endl; }
| TYPE_DOUBLE { $$ = $1; std::cout << "double passed" << std::endl; }
| TYPE_FLOAT { $$ = $1; std::cout << "float passed" << std::endl; }
| TYPE_STRING { $$ = $1; std::cout << "string passed" << std::endl; }
| TYPE_BOOLEAN { $$ = $1; std::cout << "boolean passed" << std::endl; }
| TYPE_LIST { $$ = $1; std::cout << "list passed" << std::endl; }
| TYPE_DATE { $$ = $1; std::cout << "date passed" << std::endl; }
| IDENTIFIER { $$ = $1; std::cout << "user-type passed" << std::endl; }
| type LEFT_BRACKETS RIGHT_BRACKETS {
    $$ = $1; std::cout << "array passed" << std::endl;
  }
;



assignment_statement:
  IDENTIFIER EQUAL value {
    /* Empty Rule. */
    std::cout << "assignment_statement passed" << std::endl;
  }
|
  IDENTIFIER EQUAL NEW IDENTIFIER LEFT_PARENTHESES RIGHT_PARENTHESES {
    /* Empty Rule. */
    std::cout << "assignment_statement passed, class instance" << std::endl;
  }
;

value:
  NUMBER { std::cout << "number passed" << std::endl; }
| STRING { std::cout << "string passed" << std::endl; }
| BOOL { std::cout << "bool passed" << std::endl; }
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
