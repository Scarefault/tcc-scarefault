expr:
  number
| string
| boolean
| variable
| '(' expr ')'
| list_literals_declaration
| arithmetic_expr
| relational_expr
| elvis_expr
| safe_nav_expr
| mtd_ptr_expr
| increment_expr
| creation_expr
| inverse_logic_expr
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

creation_expr:
  CREATION_OP method_header
;

inverse_logic_expr:
  '!' expr
| '!' method_stmt
;
