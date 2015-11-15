DIGIT   [[:digit:]]
INTEGER {DIGIT}+
REAL    -?{INTEGER}+("."{INTEGER}+)?

CHARACTER .
LITERAL   \".*\"

WHITESPACE [[:blank:]]+

WORD       [_0-9a-zA-Z]
NOT_DIGIT  [^?0-9]
NOT_DOLLAR [^?"$"]
IDENTIFIER {WHITESPACE}+("$"{WORD}+|{NOT_DIGIT}{WORD}+{NOT_DOLLAR})

TRUE    "true"
FALSE   "false"
BOOLEAN {TRUE}|{FALSE}
%%

//--------------------- Importation -----------------------//
//
"import"      return PARSER::IMPORT;
"package"     return PARSER::PACKAGE;

//----------------------- classes -------------------------//
//
"def"         return PARSER::DEF;

//--------------------- Type of Data ----------------------//
//
"Integer"     return PARSER::TYPE_INTEGER;

//------------------- Punctuation Marks -------------------//
//
"("           return PARSER::LEFT_PARENTHESES;
")"           return PARSER::RIGHT_PARENTHESES;
"["           return PARSER::LEFT_BRACKETS;
"]"           return PARSER::RIGHT_BRACKETS;
"{"           return PARSER::LEFT_CURLY_BRACKETS;
"}"           return PARSER::RIGHT_CURLY_BRACKETS;
";"           return PARSER::SEMICOLON;
":"           return PARSER::COLON;
"."           return PARSER::DOT;

//------------------- Scarefault Marks -------------------//
//
"scarefault"  return PARSER::SCAREFAULT;
"test"        return PARSER::TEST;
"scenario"    return PARSER::SCENARIO;
"entries"     return PARSER::ENTRIES;
"out"         return PARSER::OUT;

//------------------- Data Values ------------------------//
//
{DIGIT}       |
{INTEGER}     |
{REAL}        return PARSER::NUMBER;
{CHARACTER}   return PARSER::CHAR;
{LITERAL}     return PARSER::STRING;
{BOOLEAN}     return PARSER::BOOL;
{IDENTIFIER}  return IDENTIFIER;
