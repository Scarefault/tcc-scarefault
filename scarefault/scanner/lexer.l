DIGIT [[:digit:]]
INTEGER [[:digit:]]+

%%

DIGIT   return 1;
INTEGER return 1;
