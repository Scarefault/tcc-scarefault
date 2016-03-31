%scanner                  ../scanner/Scanner.h
%scanner-token-function   d_scanner.lex()
%baseclass-preinclude     ParserPreinclude.h


%stype std::string
%start startrule
%expect 5

%include spec/tokens.y

%%

startrule:
  // Empty Rule.
|
  startrule content
;

%include spec/values.y
%include spec/types_modifiers.y
%include spec/content_stmt.y
%include spec/content.y
