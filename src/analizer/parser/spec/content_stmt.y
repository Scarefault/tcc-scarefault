content_stmt:
  '{' stmt_list '}'
;

stmt_list:
  stmt
| stmt_list stmt
;

stmt:
  variable_declaration
;

variable_declaration:
  type variable
| modifier variable_declaration
;

variable:
  identifier
;
