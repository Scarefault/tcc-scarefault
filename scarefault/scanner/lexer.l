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

//--------------------- Importation -----------------------//
//
"import"      return Parser::IMPORT;
"package"     return Parser::PACKAGE;

//----------------------- classes -------------------------//
//
"def"         return Parser::DEF;
"return"      return Parser::RETURN;

//--------------------- Type of Data ----------------------//
//
"Integer"     return Parser::TYPE_INTEGER;

//------------------- Punctuation Marks -------------------//
//
"("           return Parser::LEFT_PARENTHESES;
")"           return Parser::RIGHT_PARENTHESES;
"["           return Parser::LEFT_BRACKETS;
"]"           return Parser::RIGHT_BRACKETS;
"{"           return Parser::LEFT_CURLY_BRACKETS;
"}"           return Parser::RIGHT_CURLY_BRACKETS;
";"           return Parser::SEMICOLON;
":"           return Parser::COLON;
"."           return Parser::DOT;
","           return Parser::COMMA;

//------------------- Scarefault Marks -------------------//
//
"scarefault"  return Parser::SCAREFAULT;
"test"        return Parser::TEST;
"scenario"    return Parser::SCENARIO;
"entries"     return Parser::ENTRIES;
"out"         return Parser::OUT;

//------------------- Data Values ------------------------//
//
{DIGIT}       |
{INTEGER}     |
{REAL}        return Parser::NUMBER;
{LITERAL}     return Parser::STRING;
{IDENTIFIER}  return Parser::IDENTIFIER;
