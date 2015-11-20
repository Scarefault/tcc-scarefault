DIGIT   [[:digit:]]
INTEGER {DIGIT}+
REAL    -?{INTEGER}+("."{INTEGER}+)?

CHARACTER .
LITERAL   \".*\"

WHITESPACE [[:blank:]]+

WORD       [_0-9a-zA-Z]+
NOT_DIGIT  [^?0-9]
NOT_DOLLAR [^?"$"]
IDENTIFIER _?[a-zA-Z0-9][a-zA-Z0-9]* 

TRUE    "true"
FALSE   "false"
BOOLEAN {TRUE}|{FALSE}


%%


//---------------------------- Importation --------------------------------- //
//
"import" {
  *d_val = matched();
  return Parser::IMPORT;
}

"package" {
  *d_val = matched();
  return Parser::PACKAGE;
}

//-------------------------------- classes --------------------------------- //
//
"def" {
  *d_val = matched();
  return Parser::DEF;
}

"return" {
  *d_val = matched();
  return Parser::RETURN;
}

// --------------------------- Type of Data -------------------------------- //
//
"Integer" {
  *d_val = matched();
  return Parser::TYPE_INTEGER;
}

//-------------------------- Punctuation Marks ----------------------------- //
//
"(" {
  *d_val = matched();
  return Parser::LEFT_PARENTHESES;
}

")" {
  *d_val = matched();
  return Parser::RIGHT_PARENTHESES;
}

"[" {
  *d_val = matched();
  return Parser::LEFT_BRACKETS;
}

"]" {
  *d_val = matched();
  return Parser::RIGHT_BRACKETS;
}

"{" {
  *d_val = matched();
  return Parser::LEFT_CURLY_BRACKETS;
}

"}" {
  *d_val = matched();
  return Parser::RIGHT_CURLY_BRACKETS;
}

";" {
  *d_val = matched();
  return Parser::SEMICOLON;
}

":" {
  *d_val = matched();
  return Parser::COLON;
}

"." {
  *d_val = matched();
  return Parser::DOT;
}

"," {
  *d_val = matched();
  return Parser::COMMA;
}

//----------------------------- Scarefault Marks --------------------------- //
//
"scarefault" {
  *d_val = matched();
  return Parser::SCAREFAULT;
}

"test" {
  *d_val = matched();
  return Parser::TEST;
}

"scenario" {
  *d_val = matched();
  return Parser::SCENARIO;
}

"entries" {
  *d_val = matched();
  return Parser::ENTRIES;
}

"out" {
  *d_val = matched();
  return Parser::OUT;
}

//------------------------------- Data Values ------------------------------ //
//
{DIGIT}       |
{INTEGER}     |
{REAL} {
  *d_val = matched();
  return Parser::NUMBER;
}

{LITERAL} {
  *d_val = matched();
  return Parser::STRING;
}

{IDENTIFIER} {
  *d_val = matched();
  return Parser::IDENTIFIER;
}
