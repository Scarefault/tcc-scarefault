%scanner                ../scanner/Scanner.h
%scanner-token-function d_scanner.lex()

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
%token<text> DOT


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
%token<text> BOOL;
%token<text> CHAR;
%%
