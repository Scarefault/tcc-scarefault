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
 * ************* Classes *****************
 */
%token CLASS
%token INTERFACE
%token IMPLEMENTS
%token EXTENDS
%token ABSTRACT
%token PUBLIC
%token PROTECTED
%token PRIVATE
%token STATIC
%token FINAL
%token COMMENT
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
%token TYPE_CHAR
%token TYPE_BOOLEAN
%token TYPE_LIST
%token TYPE_DATE


/*
 * ********** Punctuation Marks **********
 */
%token QUESTION_MARK
%token L_PAR
%token R_PAR
%token L_BRKT
%token R_BRKT
%token L_BRACE
%token R_BRACE
%token STAR
%token COLON
%token SEMICOLON
%token COMMA
%token DOT
%token SUSPN_DOTS


/*
 * ********** Data Values ****************
 */
%token NUMBER
%token STRING
%token IDENTIFIER
%token BOOL

/*
 * ********** Control Structures *********
 */
%token IF
%token ELSE
%token SWITCH
%token CASE
%token DEFAULT
%token FOR
%token WHILE

/*
 * ********** Operators ******************
 */
%token EQUAL
%token COMPARISON_OP
%token LOGICAL_OP
%token INCR_OP
%token COERCION_OP
%token NEW
%token IN


%%


/******************************* General Rules *****************************/

startrule:
  /* Empty Rule */
|
  startrule content
;

content:
  initial_stmt { log.info( "Pass stmt: import/package" ); }
| variable_stmt { log.info( "Pass stmt: variable" ); }
| assignment_stmt { log.info( "Pass stmt: assignment" ); }
| main_body_code_stmt { log.info( "Pass stmt: class/interface" ); }
| method_stmt { log.info( "Pass stmt: method/constructor" ); }
| conditional_structure_stmt {
    log.info( "Pass stmt: condicional structure" );
  }
|
  looping_structure_stmt { log.info( "Pass stmt: looping structure" ); }
| comment_stmt { log.info( "Pass stmt: comment/groovy doc" ); }
;

/************************* End of General Rules ****************************/


/******************* Rules for Groovy Programming Language *****************/
initial_stmt:
  package_stmt
| import_stmt
;

import_stmt:
  IMPORT package_name {
    const string identifier_token( $2 );
    test_generator.add_import_name( identifier_token );
  }
|
  IMPORT STATIC package_name {
  }
|
  import_stmt COERCION_OP IDENTIFIER {
  }
;

package_stmt:
  PACKAGE package_name {
    const string identifier_token( $2 );
    test_generator.set_package_name( identifier_token );
  }
;

/*
 * Represents the structure of the name of a package or file that we need
 *   import.
 */
package_name:
  IDENTIFIER
| package_name DOT package_name
| package_name DOT STAR
;



comment_stmt:
  COMMENT
;



main_body_code_stmt:
  class_stmt
| interface_stmt
;

class_stmt:
  CLASS IDENTIFIER {
  }
|
  ABSTRACT class_stmt {
  }
|
  class_stmt IMPLEMENTS IDENTIFIER {
  }
|
  class_stmt EXTENDS IDENTIFIER {
  }
;

interface_stmt:
  INTERFACE IDENTIFIER
;

modifier:
  PUBLIC
| PROTECTED
| PRIVATE
| STATIC
| FINAL
;



method_stmt:
  IDENTIFIER L_PAR params_stmt R_PAR {
  }
|
  DEF method_stmt {
  }
|
  type method_stmt {
  }
|
  modifier method_stmt {
  }
;

params_stmt:
  /* Empty Rule. */
| type IDENTIFIER
| params_stmt EQUAL value
| type SUSPN_DOTS IDENTIFIER
| IDENTIFIER
| params_stmt COMMA params_stmt
;



conditional_structure_stmt:
  if_stmt
| ternary_stmt
| switch_stmt
;

if_stmt:
  IF L_PAR logical_expression R_PAR {
  }
|
  ELSE if_stmt {
  }
|
  ELSE L_PAR logical_expression R_PAR {
  }
;

ternary_stmt:
  logical_expression QUESTION_MARK value COLON value {
  }
;

switch_stmt:
  SWITCH L_PAR IDENTIFIER R_PAR {
  }
|
  switch_component
;

switch_component:
  CASE value COLON
| DEFAULT COLON
;

logical_expression:
  value LOGICAL_OP value
| value COMPARISON_OP value
| logical_expression LOGICAL_OP logical_expression
| logical_expression COMPARISON_OP logical_expression
;



looping_structure_stmt:
  for_stmt
| while_stmt
;

for_stmt:
  FOR L_PAR assignment_stmt SEMICOLON comparison_expression
  SEMICOLON increments_expression R_PAR {
  }
|
  FOR L_PAR variable_stmt COLON IDENTIFIER R_PAR {
  }
|
  FOR L_PAR IDENTIFIER IN IDENTIFIER R_PAR {
  }
;

while_stmt:
  WHILE L_PAR comparison_expression R_PAR {
  }
;

comparison_expression:
  value COMPARISON_OP value
;

increments_expression:
  IDENTIFIER INCR_OP
| INCR_OP IDENTIFIER
;



variable_stmt:
  type IDENTIFIER
| modifier variable_stmt
;

type:
  TYPE_INTEGER { $$ = $1; }
| TYPE_LONG { $$ = $1; }
| TYPE_SHORT { $$ = $1; }
| TYPE_DOUBLE { $$ = $1; }
| TYPE_FLOAT { $$ = $1; }
| TYPE_STRING { $$ = $1; }
| TYPE_CHAR { $$ = $1; }
| TYPE_BOOLEAN { $$ = $1; }
| TYPE_LIST { $$ = $1; }
| TYPE_DATE { $$ = $1; }
| IDENTIFIER { $$ = $1; }
| type L_BRKT R_BRKT { $$ = $1; }
;



assignment_stmt:
  IDENTIFIER EQUAL assignment_expression {
  }
|
  type IDENTIFIER EQUAL assignment_expression {
  }
|
  DEF assignment_stmt {
  }
;

assignment_expression:
| value
| assignment_constructor_expression
;

assignment_constructor_expression:
  L_BRKT params_constructor_stmt R_BRKT
| assignment_constructor_expression COERCION_OP IDENTIFIER
| assignment_constructor_expression COERCION_OP type L_BRKT R_BRKT
| NEW IDENTIFIER L_PAR params_constructor_stmt R_PAR
| NEW IDENTIFIER L_PAR R_PAR
;

params_constructor_stmt:
  value
| IDENTIFIER COLON value
| params_constructor_stmt COMMA params_constructor_stmt
;

value:
  NUMBER
| string
| BOOL
| IDENTIFIER
;

string:
  STRING { $$ = $1; }
;



/*************** End of Rules for Groovy Programming Language **************/
