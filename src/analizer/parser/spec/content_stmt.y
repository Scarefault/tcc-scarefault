content_stmt:
  '{' stmt_list '}'
;

stmt_list:
  stmt
| stmt_list stmt
;

stmt:
  variable_declaration
| comment_stmt
| control_structure_stmt
;

variable_declaration:
  type variable
| modifier variable_declaration
;

variable:
  identifier
;

comment_stmt:
  COMMENT
;

control_structure_stmt:
  conditional_structure_stmt
;

conditional_structure_stmt:
  if_stmt
;

if_stmt:
  IF '(' identifier ')' content_stmt
| if_stmt ELSE content_stmt
| if_stmt ELSE if_stmt
;
