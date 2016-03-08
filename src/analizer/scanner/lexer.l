DIGIT   [[:digit:]]
INTEGER {DIGIT}+
REAL    -?{WHITESPACE}?{INTEGER}+("."{INTEGER}+)?

CHARACTER .
LITERAL   \".*\"

WHITESPACE [[:blank:]]+

WORD       [_0-9a-zA-Z]+
NOT_DIGIT  [^?0-9]
NOT_DOLLAR [^?"$"]
IDENTIFIER _?[a-zA-Z0-9][a-zA-Z0-9]*

TRUE    true
FALSE   false
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

//-------------------------------- Classes --------------------------------- //
//
"class" {
  *d_val = matched();
  return Parser::CLASS;
}

"interface" {
  *d_val = matched();
  return Parser::INTERFACE;
}

"implements" {
  *d_val = matched();
  return Parser::IMPLEMENTS;
}

"extends" {
  *d_val = matched();
  return Parser::EXTENDS;
}

"abstract" {
  *d_val = matched();
  return Parser::ABSTRACT;
}

"new" {
  *d_val = matched();
  return Parser::NEW;
}

"public" {
  *d_val = matched();
  return Parser::PUBLIC;
}

"protected" {
  *d_val = matched();
  return Parser::PROTECTED;
}

"private" {
  *d_val = matched();
  return Parser::PRIVATE;
}

"static" {
  *d_val = matched();
  return Parser::STATIC;
}

"final" {
  *d_val = matched();
  return Parser::FINAL;
}


// ------------------------------ Methods ---------------------------------- //
//
"def" {
  *d_val = matched();
  return Parser::DEF;
}


// --------------------------- Type of Data -------------------------------- //
//
"Integer" {
  *d_val = matched();
  return Parser::TYPE_INTEGER;
}

"Long" {
  *d_val = matched();
  return Parser::TYPE_LONG;
}

"Short" {
  *d_val = matched();
  return Parser::TYPE_SHORT;
}

"Double" {
  *d_val = matched();
  return Parser::TYPE_DOUBLE;
}

"Float" {
  *d_val = matched();
  return Parser::TYPE_FLOAT;
}

"String" {
  *d_val = matched();
  return Parser::TYPE_STRING;
}

"Boolean" {
  *d_val = matched();
  return Parser::TYPE_BOOLEAN;
}

"List" {
  *d_val = matched();
  return Parser::TYPE_LIST;
}

"Date" {
  *d_val = matched();
  return Parser:: TYPE_DATE;
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

"..." {
  *d_val = matched();
  return Parser::SUSPENSION_DOTS;
}

"," {
  *d_val = matched();
  return Parser::COMMA;
}

"=" {
  *d_val = matched();
  return Parser::EQUAL;
}

//----------------------------- Scarefault Marks --------------------------- //
//
"scarefault" {
  *d_val = matched();
  return Parser::SCAREFAULT;
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

//-------------------------- Control Strutucture --------------------------- //
//
"if" {
  *d_val = matched();
  return Parser::IF;
}

//------------------------------ Operators --------------------------------- //
"=="    |
"!="    |
"<="    |
">="    |
"&&"    |
"||" {
  *d_val = matched();
  return Parser::LOGICAL_OPERATOR;
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

{BOOLEAN} {
  *d_val = matched();
  return Parser::BOOL;
}

{IDENTIFIER} {
  *d_val = matched();
  return Parser::IDENTIFIER;
}
