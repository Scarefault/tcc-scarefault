oop_stmt:
  attribute_call
| attribute_assign
| instantiate_object
| list_literals_declaration
;

attribute_call:
  identifier '.' attribute
;

attribute_assign:
  attribute_call ASSIGN_OP expr
| attribute_call ASSIGN_OP attribute_call
| attribute_call ASSIGN_OP method_stmt
;

list_literals_declaration:
  '[' item_list ']'
| '[' maps_list ']'
;

item_list:
  expr
| method_stmt
| item_list ',' expr
| item_list ',' method_stmt
| item_list ',' attribute_call
;

maps_list:
  item_map
| maps_list ',' item_map
;

item_map:
  expr ':' expr
| expr ':' method_stmt
;

instantiate_object:
  identifier object
;

object:
  identifier
;

attribute:
  identifier
;
