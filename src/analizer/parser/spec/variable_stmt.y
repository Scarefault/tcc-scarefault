variable_declaration:
  variable
| typed_variable
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

variable:
  identifier
;
