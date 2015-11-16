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
  startrule tokenshow
|
  tokenshow
;

tokenshow:
  token
  {
    if( d_scanner.matched() == "import" )
    {
      std::cout << "Found Token: IMPORT" << std::endl;
    } else if( d_scanner.matched() == "package" )
    {
      std::cout << "Found Token: PACKAGE" << std::endl;
    } else if( d_scanner.matched() == "def" )
    {
      std::cout << "Found Token: DEF" << std::endl;
    } else if( d_scanner.matched() == "return" )
    {
      std::cout << "Found Token: RETURN" << std::endl;
    } else if( d_scanner.matched() == "Integer" )
    {
      std::cout << "Found Token: TYPE_INTEGER" << std::endl;
    } else if( d_scanner.matched() == "(" )
    {
      std::cout << "Found Token: LEFT_PARENTHESES" << std::endl;
    } else if( d_scanner.matched() == ")" )
    {
      std::cout << "Found Token: RIGHT_PARENTHESES" << std::endl;
    } else if( d_scanner.matched() == "[" )
    {
      std::cout << "Found Token: LEFT_BRACKETS" << std::endl;
    } else if( d_scanner.matched() == "]" )
    {
      std::cout << "Found Token: RIGHT_BRACKETS" << std::endl;
    } else if( d_scanner.matched() == "{" )
    {
      std::cout << "Found Token: LEFT_CURLY_BRACKETS" << std::endl;
    } else if( d_scanner.matched() == "}" )
    {
      std::cout << "Found Token: RIGHT_CURLY_BRACKETS" << std::endl;
    } else if( d_scanner.matched() == ";" )
    {
      std::cout << "Found Token: SEMICOLON" << std::endl;
    } else if( d_scanner.matched() == ":" )
    {
      std::cout << "Found Token: COLON" << std::endl;
    } else if( d_scanner.matched() == "." )
    {
      std::cout << "Found Token: DOT" << std::endl;
    } else if( d_scanner.matched() == "," )
    {
      std::cout << "Found Token: COMMA" << std::endl;
    } else if( d_scanner.matched() == "scarefault" )
    {
      std::cout << "Found Token: SCAREFAULT" << std::endl;
    } else if( d_scanner.matched() == "test" )
    {
      std::cout << "Found Token: TEST" << std::endl;
    } else if( d_scanner.matched() == "scenario" )
    {
      std::cout << "Found Token: SCENARIO" << std::endl;
    } else if( d_scanner.matched() == "entries" )
    {
      std::cout << "Found Token: ENTRIES" << std::endl;
    } else if( d_scanner.matched() == "out" )
    {
      std::cout << "Found Token: OUT" << std::endl;
    } else
    {
      std::cout << "Found Token: IDENTIFIER" << std::endl;
    }
    
    std::cout << "Matched: " << d_scanner.matched() << "\n";
  }
;

token:
  IMPORT
|
  PACKAGE
|
  DEF
|
  RETURN
|
  TYPE_INTEGER
|
  LEFT_PARENTHESES
|
  RIGHT_PARENTHESES
|
  LEFT_BRACKETS
|
  RIGHT_BRACKETS
|
  LEFT_CURLY_BRACKETS
|
  RIGHT_CURLY_BRACKETS
|
  SEMICOLON
|
  COLON
|
  DOT
|
  COMMA
|
  SCAREFAULT
|
  TEST
|
  SCENARIO
|
  ENTRIES
|
  OUT
|
  NUMBER
|
  STRING
|
  IDENTIFIER
;
