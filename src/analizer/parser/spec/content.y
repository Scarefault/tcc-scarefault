content:
  comment_stmt
| initial_definition
| class_definition
| interface_definition
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
| ABSTRACT class_definition
| class_definition class_complement
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
