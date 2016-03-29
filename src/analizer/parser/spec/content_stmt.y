content_stmt:
  '{' stmt_list '}'
;

stmt_list:
  stmt
| stmt_list stmt
;

stmt:
  comment_stmt
| variable_declaration
| assign_stmt
| control_structure_stmt
| method_stmt
;

variable_declaration:
  type variable
| modifier variable_declaration
;

variable:
  identifier
;

assign_stmt:
  variable ASSIGN_OP expr
| DEF assign_stmt
;

control_structure_stmt:
  conditional_structure_stmt
| looping_structure_stmt
;

conditional_structure_stmt:
  if_stmt
| ternary_stmt
| switch_stmt
;

if_stmt:
  IF '(' expr ')' content_stmt
| if_stmt ELSE content_stmt
| if_stmt ELSE if_stmt content_stmt
;

ternary_stmt:
  expr '?' expr ':' expr
;

switch_stmt:
  SWITCH '(' expr ')' content_switch
;

content_switch:
  '{' case_list '}'
;

case_list:
  case_stmt
| case_list case_stmt
;

case_stmt:
  CASE expr ':' content_case
| DEFAULT ':' content_case
;

content_case:
  stmt
| content_case stmt
;

looping_structure_stmt:
  for_stmt
| while_stmt
;

for_stmt:
  FOR '(' variable_declaration ';' expr ';' expr ')' content_stmt
| FOR '(' variable_declaration ':' identifier ')' content_stmt
| FOR '(' variable ':' identifier ')' content_stmt
;

while_stmt:
  WHILE '(' expr ')' content_stmt
;

method_stmt:
  method_header
| method_stmt content_stmt
;

method_header:
  identifier '(' param_list ')'
| DEF method_header
| type method_header
| modifier method_header
;

param_list:
  // Empty.
|
  params
;

params:
  param
|
  params ',' param
;

param:
  variable
| type variable
| type variable ASSIGN_OP expr
| type SUSPN_DOTS variable
;

expr:
  number
| string
| boolean
| identifier
| '(' expr ')'
;
