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
  initial_declaration
| variable_declaration
| assignment_declaration
| main_body_code_declaration
| method_declaration
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



initial_declaration:
  package_declaration
| import_declaration
;

import_declaration:
  IMPORT parcel_initial_declaration {
    const string identifier_token( $2 );
    test_generator.add_import_name( identifier_token );

    std::cout << "import_declaration passed" << std::endl;
  }
;

package_declaration:
  PACKAGE parcel_initial_declaration {
    const string identifier_token( $2 );
    test_generator.set_package_name( identifier_token );

    std::cout << "package_declaration passed" << std::endl;
  }
;

/*
 * Represents the structure of the name of a package or file that we need
 *   import.
 */
parcel_initial_declaration:
  IDENTIFIER {
    /* Empty Rule. */
    std::cout << "parcel_initial_declaration passed, simple" << std::endl;
  }
|
  parcel_initial_declaration DOT parcel_initial_declaration {
    /* Empty Rule. */
    std::cout << "parcel_initial_declaration passed, composed" << std::endl;
  }
;



main_body_code_declaration:
  class_declaration
| interface_declaration
;

class_declaration:
  CLASS IDENTIFIER {
    std::cout << "class_declaration passed" << std::endl;
  }
|
  ABSTRACT CLASS IDENTIFIER {
    std::cout << "class_declaration passed, with abstract" << std::endl;
  }
|
  class_declaration IMPLEMENTS IDENTIFIER {
    std::cout << "class_declaration passed, with implements" << std::endl;
  }
|
  class_declaration EXTENDS IDENTIFIER {
    std::cout << "class_declaration passed, with extends" << std::endl;
  }
;

interface_declaration:
  INTERFACE IDENTIFIER {
    std::cout << "interface_declaration passed" << std::endl;
  }
;

modifier:
  PUBLIC { std::cout << "modifier public passed" << std::endl; }
| PROTECTED { std::cout << "modifier protected passed" << std::endl; }
| PRIVATE { std::cout << "modifier private passed" << std::endl; }
| STATIC { std::cout << "modifier static passed" << std::endl; }
| FINAL { std::cout << "modifier final passed" << std::endl; }
;



method_declaration:
  method_no_return_declaration
| method_with_return_declaration
;

method_no_return_declaration:
  DEF IDENTIFIER LEFT_PARENTHESES RIGHT_PARENTHESES {
    const string identifier_token( $2 );
    test_generator.set_method_name( identifier_token );

    std::cout << "method_no_return_declaration passed, no params" << std::endl;
  }
|
  DEF IDENTIFIER LEFT_PARENTHESES params_declaration RIGHT_PARENTHESES {
    const string identifier_token( $2 );
    test_generator.set_method_name( identifier_token );

    std::cout << "method_no_return_declaration passed, with params"
              << std::endl;
  }
|
  modifier method_no_return_declaration {
    std::cout << "method_no_return_declaration passed, with modifer"
              << std::endl;
  }
;

method_with_return_declaration:
  type IDENTIFIER LEFT_PARENTHESES RIGHT_PARENTHESES {
    std::cout << "method_with_return_declaration passed, no params"
              << std::endl;
  }
|
  type IDENTIFIER LEFT_PARENTHESES params_declaration RIGHT_PARENTHESES {
    std::cout << "method_with_return_declaration passed, with params"
              << std::endl;
  }
|
  modifier method_with_return_declaration {
    std::cout << "method_with_return_declaration passed, with modifier"
              << std::endl;
  }
;
  
params_declaration:
  type IDENTIFIER {
    /* Empty Rule. */
    std::cout << "params_declaration passed, with type" << std::endl;
  }
|
  params_declaration EQUAL value {
    /* Empty Rule. */
    std::cout << "params_declaration passed, with default value" << std::endl;
  }
|
  type SUSPENSION_DOTS IDENTIFIER {
    /* Empty Rule. */
    std::cout << "params_declaration passed, varargs" << std::endl;
  }
|
  IDENTIFIER {
    /* Empty Rule. */
    std::cout << "params_declaration passed, no type" << std::endl;
  }
|
  params_declaration COMMA params_declaration {
    /* Empty Rule. */
    std::cout << "params_declaration passed, many params" << std::endl;
  }
;



variable_declaration:
  type IDENTIFIER {
    /* Empty Rule. */
    std::cout << "variable_declaration passed" << std::endl;
  }
| modifier variable_declaration {
    std::cout << "variable_declaration passed, with modifier" << std::endl;
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



assignment_declaration:
  IDENTIFIER EQUAL value {
    /* Empty Rule. */
    std::cout << "assignment_declaration passed" << std::endl;
  }
|
  IDENTIFIER EQUAL NEW IDENTIFIER LEFT_PARENTHESES RIGHT_PARENTHESES {
    /* Empty Rule. */
    std::cout << "assignment_declaration passed, class instance" << std::endl;
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
