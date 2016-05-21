control_structure_stmt:
  conditional_structure_stmt { log.message( LogSystem::INFO, "stmt: conditional structure" ); }
| looping_structure_stmt { log.message( LogSystem::INFO, "stmt: looping structure" ); }
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
//| DEFAULT ':' content_case
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
| FOR '(' instantiate_object ':' identifier ')' content_stmt
| FOR '(' variable MEMBER_OP identifier ')' content_stmt
;

while_stmt:
  WHILE '(' expr ')' content_stmt
;
