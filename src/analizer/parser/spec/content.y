content:
  comment_stmt { std::cout << "stmt: comment" << std::endl; }
| initial_definition { std::cout << "stmt: initial" << std::endl; }
| class_definition { std::cout << "stmt: class" << std::endl; }
| interface_definition { std::cout << "stmt: interface" << std::endl; }
;

comment_stmt:
  COMMENT
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

class_definition:
  class_header content_stmt
;

class_header:
  CLASS identifier
| ABSTRACT class_header
| class_header class_complement
;

class_complement:
  IMPLEMENTS identifier
| EXTENDS identifier
;

interface_definition:
  interface_header content_stmt
;

interface_header:
  INTERFACE identifier
;
