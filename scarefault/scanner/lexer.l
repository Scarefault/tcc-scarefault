DIGIT [[:digit:]]
INTEGER {DIGIT}+
REAL -?{INTEGER}+("."{INTEGER}+)?

CHARACTER .
LITERAL \".*\"

WHITESPACE [[:blank:]]+

TRUE "true"
FALSE "false"
BOOLEAN {TRUE}|{FALSE}
%%

{DIGIT}       return 1;
{INTEGER}     return 1;
{REAL}        return 1;
{CHARACTER}   return 1;
{LITERAL}     return 1;
{WHITESPACE}  return 1;
{BOOLEAN}     return 1;
