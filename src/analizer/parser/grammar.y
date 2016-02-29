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
%token DEF
%token RETURN


/*
 * ********* Type of Data ****************
 */
%token TYPE_INTEGER


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
%token COMMA


/*
 * ********** Scarefault Marks ***********
 */
%token SCAREFAULT
%token TEST
%token SCENARIO
%token ENTRIES
%token OUT


/*
 * ********** Data Values ****************
 */
%token NUMBER;
%token STRING;
%token IDENTIFIER;


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
  type
| text
| initial_declaration
| method_declaration
| scenario_declaration
| entries_declaration
| out_declaration
;

/************************* End of General Rules ****************************/


/******************* Rules for Groovy Programming Language *****************/

/*
 * Represents the various possible types of data. Currently, there are only
 *   one of type: INTEGER.
 */
type:
  TYPE_INTEGER {
    $$ = $1;
  }
;

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
  }
;

/*
 * Represents the declaration of package associate with source file.
 */
package_declaration:
  PACKAGE parcel_initial_declaration {
    const string identifier_token( $2 );
    test_generator.set_package_name( identifier_token );
  }
;

/*
 * Represents the structure of the name of a package or file that we need
 *   import.
 */
parcel_initial_declaration:
  IDENTIFIER {
    /* Empty Rule. */
  }
|
  parcel_initial_declaration DOT parcel_initial_declaration {
    /* Empty Rule. */
  }
;

/*
 * Represents the declaration of the method in Groovy programming language.
 */
method_declaration:
  DEF IDENTIFIER LEFT_PARENTHESES RIGHT_PARENTHESES {
    const string identifier_token( $2 );
    test_generator.set_method_name( identifier_token );
  }
|
  DEF IDENTIFIER LEFT_PARENTHESES params_declaration RIGHT_PARENTHESES {
    const string identifier_token( $2 );
    test_generator.set_method_name( identifier_token );
  }
;

/*
 * Represents the declaration of the parameters in declaration of a method.
 */
params_declaration:
  type IDENTIFIER {
    /* Empty Rule */
  }
|
  params_declaration COMMA params_declaration {
    /* Empty Rule */
  }
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
