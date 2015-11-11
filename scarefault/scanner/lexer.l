DIGIT [0-9]
INTEGER {DIGIT+}
REAL -?{INTEGER}("."{INTEGER})?

CHARACTER [a-z-A-Z]
LITERAL \"[a-zA-Z0-9][a-zA-Z0-9].*\"

IDENTIFIER \s*def\s+(\$\w+|(?!\d)\w+(?!\$))\s*$
WHITESPACE []+

TRUE "true"
FALSE "false"
BOOLEAN {TRUE}|{FALSE}

%%
// Keywords
assert      return PARSER::ASSERT;
const       return PARSER::CONST;
extends     return PARSER::EXTENDS;
new         return PARSER::NEW;
return      return PARSER::RETURN;

//    Keywords to Definition
//
class       return PARSER::CLASSE;
def         return PARSER::DEF;

//    Keywords to Include bibs
//
import      return PARSER::IMPORT;
package     return PARSER::PACKAGE;
