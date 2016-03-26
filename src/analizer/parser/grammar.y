%scanner                  ../scanner/Scanner.h
%scanner-token-function   d_scanner.lex()
%baseclass-preinclude     ParserPreinclude.h

%stype std::string
%start startrule

%include spec/declare_session.y

%%

identifier:
  IDENTIFIER
;

startrule:
  // Empty Rule.
|
  startrule content
;

content:
  initial_definition
;

initial_definition:
  package_declaration
| import_declaration
;

package_declaration:
  PACKAGE package_name
;

import_declaration:
  IMPORT package_name
| IMPORT STATIC package_name
| import_declaration COERCION_OP identifier
;

package_name:
  identifier
| package_name '.' identifier
| package_name '.' '*'
;
