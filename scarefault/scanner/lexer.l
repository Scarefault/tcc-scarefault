DIGIT [[:digit:]]
INTEGER [[:digit:]]+
REAL -?[[:digit:]]+("."[[:digit:]])?

CHARACTER .
LITERAL \".*\"
%%

{DIGIT}     return 1;
{INTEGER}   return 1;
{REAL}      return 1;
{CHARACTER} return 1;
{LITERAL}   return 1;
