DIGIT [:digit:]
INTEGER {DIGIT+}
REAL -?{INTEGER}("."{INTEGER})?

CHARACTER [:alpha:]
LITERAL \"[:alnum:][:alnum:].*\"

IDENTIFIER (\s*def\s+(\$\w+|(?!\d)\w+(?!\$))\s*$)
WHITESPACE []+

TRUE "true"
FALSE "false"
BOOLEAN {TRUE}|{FALSE}

%%
// Keywords
//        Keywords to Bib's Importations
//
import      return PARSER::IMPORT;
package     return PARSER::PACKAGE;

//        Keywords to Classes
//
def         return PARSER::DEF;

// Types of Variables
//
Integer     return PARSER::INTEGER;

// Brackets
//
"("         return PARSER::OPEN_PARENTHESES;
")"         return PARSER::CLOSE_PARENTHESES;
"["         return PARSER::OPEN_BRACKETS;
"]"         return PARSER::CLOSE_BRACKETS;
"{"         return PARSER::OPEN_CURLY_BRACKETS;
"}"         return PARSER::CLOSE_CURLY_BRACKTES;
