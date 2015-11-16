%scanner                  ../scanner/Scanner.h
%scanner-token-function   d_scanner.lex()
%baseclass-preinclude     ParserPreinclude.h

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

startrule:
  // Empty Rule.
|
  startrule content
;

content:
  type
|
  text
;

type:
  TYPE_INTEGER {
    char none[10] = "NONE";
    $<text>$ = none;

    string const Integer( d_scanner.matched() );

    strcpy( $<text>$, Integer.c_str() );
    cout << $<text>$ << endl;
  }
;

text:
  STRING {
    char none[100] = "NONE";
    $<text>$ = none;

    string const matched_string( d_scanner.matched() );
    strcpy( $<text>$, matched_string.c_str() );
    cout << $<text>$ << endl;
  }
;
