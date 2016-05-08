oop_stmt:
  attribute_call
| attribute_assign
| instantiate_object
;

attribute_call:
  identifier '.' attribute
;

attribute_assign:
  attribute_call ASSIGN_OP expr
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
