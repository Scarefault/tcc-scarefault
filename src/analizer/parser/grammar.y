%scanner                  ../scanner/Scanner.h
%scanner-token-function   d_scanner.lex()
%baseclass-preinclude     ParserPreinclude.h

%stype std::string
%start startrule

%include spec/tokens.y

%%

startrule:
  // Empty Rule.
|
  startrule content
;

%include spec/content.y
%include spec/scarefault.y
