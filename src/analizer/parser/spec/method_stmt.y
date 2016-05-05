method_stmt:
  method_prototype
| method_definition
| identifier '.' method_call
| method_call
;

method_definition:
  method_prototype content_stmt
| identifier '.' method_call content_stmt
;

method_call:
  method_header
| method_call '.' method_header
;

method_prototype:
  DEF method_header
| typed_method_header
| modifier method_prototype
;

typed_method_header:
  type method_header
| identifier method_header
;

method_header:
  IDENTIFIER '(' param_list ')'
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
