%scanner                  ../scanner/Scanner.h
%scanner-token-function   d_scanner.lex()
%baseclass-preinclude     ParserPreinclude.h


/*
 * Section of Directives:
 *   In this section are specified some options for the parser. In addition,
 *   this section is it necessary to determine the names of all the tokens,
 *   except those with the name consisting of a single character. The inclusion
 *   of external libraries is also made to this section.
 */


%union {
  char *text;
}


/*
 * ************ Importation **************
 */
%token<text> IMPORT
%token<text> PACKAGE


/*
 * ********* Classes *********************
 */
%token<text> DEF
%token<text> RETURN


/*
 * ********* Type of Data ****************
 */
%token<text> TYPE_INTEGER


/*
 * ********** Punctuation Marks **********
 */
%token<text> LEFT_PARENTHESES
%token<text> RIGHT_PARENTHESES
%token<text> LEFT_BRACKETS
%token<text> RIGHT_BRACKETS
%token<text> LEFT_CURLY_BRACKETS
%token<text> RIGHT_CURLY_BRACKETS
%token<text> SEMICOLON
%token<text> COLON
%token<text> DOT
%token<text> COMMA


/*
 * ********** Scarefault Marks ***********
 */
%token<text> SCAREFAULT
%token<text> TEST
%token<text> SCENARIO
%token<text> ENTRIES
%token<text> OUT


/*
 * ********** Data Values ****************
 */
%token<text> NUMBER;
%token<text> STRING;
%token<text> IDENTIFIER;


%%


/******************************* General Rules *****************************/

/*
 * It is the initial rule. Formed essentially by the rules establishing the
 *   content of the test file.
 */
startrule:
  // Empty Rule.
|
  startrule content
;

/*
 * This rule represents the content of the test file.
 */
content:
  type
| text
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
    char none[10] = "NONE";
    $<text>$ = none;

    string const Integer( d_scanner.matched() );

    strcpy( $<text>$, Integer.c_str() );
    cout << $<text>$ << endl;
  }
;

/*
 * Represents every type of text catched. Currently, there are only STRING.
 */
text:
  STRING {
    char none[100] = "NONE";
    $<text>$ = none;

    string const matched_string( d_scanner.matched() );
    strcpy( $<text>$, matched_string.c_str() );
    cout << $<text>$ << endl;
  }
;


/*
 * Represents the declaration of the method in Groovy programming language.
 */
method_declaration:
  DEF IDENTIFIER LEFT_PARENTHESES RIGHT_PARENTHESES {
    cout << "method_declaration, without params" << endl;
  }
|
  DEF IDENTIFIER LEFT_PARENTHESES params_declaration RIGHT_PARENTHESES {
    cout << "method_declaration, with params" << endl;
  }
;

/*
 * Represents the declaration of the parameters in declaration of a method.
 */
params_declaration:
  type IDENTIFIER {
    cout << "params_declaration, one param" << endl;
  }
|
  params_declaration COMMA params_declaration {
    cout << "params_declaration, more than one param" << endl;
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
    cout << "scenario_declaration" << endl;
  }
;

/*
 * Represents the description of the entries of test scenario.
 */
entries_declaration:
  SCAREFAULT DOT ENTRIES COLON test_input {
    cout << "entries_declaration" << endl;
  }
;

/*
 * Represents the data of input. 
 */
test_input:
  NUMBER {
    cout << "test_input, one input" << endl;
  }
|
  test_input COMMA test_input {
    cout << "test_input, more than one input" << endl;
  }
;

/*
 * Represents the description of the output of the test scenario.
 */
out_declaration:
  SCAREFAULT DOT OUT COLON test_output {
    cout << "out_declaration" << endl;
  }
;

/*
 * Represents the data of output.
 */
test_output:
  NUMBER {
    cout << "test_output" << endl;
  }
;

/********************** End of Rules for Scarefault ************************/
