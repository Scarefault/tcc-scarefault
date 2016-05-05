variable_declaration:
  typed_variable
| variable
| attribute_call
| basic_variable_declaration
| DEF variable_declaration
;

basic_variable_declaration:
  modifier variable
| modifier typed_variable
| variable_declaration ASSIGN_OP content_variable
;

content_variable:
  expr
| content_stmt
;

typed_variable:
  type variable
| identifier variable
;

attribute_call:
  identifier '.' variable
;

variable:
  identifier
;
