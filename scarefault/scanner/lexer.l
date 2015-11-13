DIGIT [[:digit:]]
INTEGER [[:digit:]]+
REAL -?[[:digit:]]+("."[[:digit:]])?

%%

{DIGIT}   return 1;
{INTEGER} return 1;
{REAL}    return 1;
