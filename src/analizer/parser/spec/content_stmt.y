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
| ternary_stmt
| switch_stmt
;

if_stmt:
  IF '(' identifier ')' content_stmt
| if_stmt ELSE content_stmt
| if_stmt ELSE if_stmt
;

ternary_stmt:
  identifier '?' identifier ':' identifier
;

switch_stmt:
  SWITCH '(' identifier ')' content_switch
;

content_switch:
  '{' case_list '}'
;

case_list:
  case_stmt
| case_list case_stmt
;

case_stmt:
  CASE identifier ':' content_case
| DEFAULT ':' content_case
;

content_case:
  stmt
| content_case stmt
;
