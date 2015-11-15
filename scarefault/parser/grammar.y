%scanner                ../scanner/Scanner.h
%scanner-token-function d_scanner.lex()

%union {
  char *text;
}

%token<text> IMPORT
%token<text> PACKAGE
%token<text> DEF

%token<text> LEFT_PARENTHESES
%token<text> RIGHT_PARENTHESES

%token<text> LEFT_BRACKETS
%token<text> RIGHT_BRACKETS

%token<text> LEFT_CURLY_BRACKETS
%token<text> RIGHT_CURLY_BRACKETS

%token<text> SEMICOLON
%token<text> DOT

