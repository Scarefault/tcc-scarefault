content_stmt:
  '{' stmt_list '}'
;

stmt_list:
  stmt
| stmt_list stmt
;

stmt:
  comment_stmt { log.info( "stmt: comment/ GroovyDoc" ); }
| variable_declaration { log.info( "stmt: variable declaration" ); }
| control_structure_stmt { log.info( "stmt: control structure" ); }
| method_stmt { log.info( "stmt: method declaration" ); }
;

variable_declaration:
  IDENTIFIER
| identifier variable
| type variable
| modifier variable_declaration
| variable_declaration ASSIGN_OP expr
| DEF variable_declaration
| variable_declaration ASSIGN_OP content_stmt
;

variable:
  identifier
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
| if_stmt ELSE if_stmt
| if_stmt ELSE content_stmt
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
| FOR '(' variable MEMBER_OP identifier ')' content_stmt
;

while_stmt:
  WHILE '(' expr ')' content_stmt
;

method_stmt:
  method_prototype
| method_definition
| identifier '.' method_call
| method_call
;

method_definition:
  method_prototype content_stmt
;

method_call:
  method_header
| method_call '.' method_header
;

method_prototype:
  DEF method_header
| type method_header
| modifier method_header
;

method_header:
  identifier '(' param_list ')'
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
  expr
| type expr
| param ASSIGN_OP expr
| param ':' expr
| type SUSPN_DOTS variable
;

expr:
  number
| string
| boolean
| variable
| '(' expr ')'
| list_literals_expr
| arithmetic_expr
| relational_expr
| elvis_expr
| safe_nav_expr
| mtd_ptr_expr
| increment_expr
;

list_literals_expr:
  '[' item_list ']'
| '[' maps_list ']'
;

item_list:
  expr
| item_list ',' expr
;

maps_list:
  item_map
| maps_list ',' item_map
;

item_map:
  expr ':' expr
;

arithmetic_expr:
  expr '*' expr
| expr '/' expr
| expr '+' expr
| expr '-' expr
;

relational_expr:
  comparison_expr
| logical_expr
| bitwise_expr
;

comparison_expr:
  expr COMPARISON_OP expr
;

logical_expr:
  expr LOGICAL_OP expr
;

bitwise_expr:
  expr BITWISE_OP expr
;

elvis_expr:
  expr ELVIS_OP expr
;

safe_nav_expr:
  expr SAFE_NAV_OP expr
;

mtd_ptr_expr:
  expr MTD_PTR_OP expr
;

increment_expr:
  variable INCR_OP
;
