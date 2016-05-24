content:
  package_declaration
| import_declaration
| class_declaration
| comment_stmt
;

package_declaration:
  PACKAGE package_name {
    log.message( LogSystem::INFO, "package declaration" );
  }
;

import_declaration:
  IMPORT package_name {
    log.message( LogSystem::INFO, "import declaration" );
  }
;

class_declaration:
  CLASS IDENTIFIER content_stmt {
    log.message( LogSystem::INFO, "class declaration" );
  }
;

package_name:
  IDENTIFIER
| package_name '.' IDENTIFIER
;

content_stmt:
  '{' stmt_list '}'
;

stmt_list:
  stmt
| stmt_list stmt
;

stmt:
  comment_stmt
| basic_stmt
| oop_stmt
| untyped_identifier_stmt
;

untyped_identifier_stmt:
  untyped_identifier_declaration {
    log.message( LogSystem::INFO, "untyped identifier declaration" );
  }
| untyped_identifier_declaration ASSIGN_OP expr {
    log.message( LogSystem::INFO, "untyped identifier expression" );
  }
;

untyped_identifier_declaration:
  IDENTIFIER
| DEF untyped_identifier_declaration
| modifier untyped_identifier_declaration
;

comment_stmt:
  COMMENT {
    log.message( LogSystem::INFO, "comment statement" );
  }
;

basic_stmt:
  variable_stmt
| control_structure_stmt
;

variable_stmt:
  variable_declaration
| variable_assignment
;

variable_declaration:
  typed_variable_declaration {
    log.message( LogSystem::INFO, "typed variable declaration" );
  }
;

typed_variable_declaration:
  type IDENTIFIER
| modifier typed_variable_declaration
;

variable_assignment:
  typed_variable_declaration ASSIGN_OP expr {
    log.message( LogSystem::INFO, "typed variable assignment" );
  }
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
  IF '(' conditional_argument ')' content_stmt {
    log.message( LogSystem::INFO, "if statement" );
  }
| if_stmt ELSE if_stmt {
  log.message( LogSystem::INFO, "elseif statement" );
  }
| if_stmt ELSE content_stmt {
  log.message( LogSystem::INFO, "else statement" );
  }
;

ternary_stmt:
  expr '?' expr ':' expr
;

switch_stmt:
  SWITCH '(' conditional_argument ')' switch_content  {
    log.message( LogSystem::INFO, "switch statement" );
  }
;

switch_content:
  '{' case_list '}'
;

case_list:
  case_stmt
| case_list case_stmt
;

case_stmt:
  CASE expr ':' stmt_list {
    log.message( LogSystem::INFO, "case statement" );
  }
//| DEFAULT ':' stmt_list
;

conditional_argument:
  expr
;

looping_structure_stmt:
  for_stmt
| while_stmt
;

for_stmt:
  FOR '(' for_argument ')' content_stmt {
    log.message( LogSystem::INFO, "for statement" );
  }
;

for_argument:
  variable_assignment ';' conditional_argument ';' expr
;

while_stmt:
  WHILE '(' conditional_argument ')' content_stmt {
    log.message( LogSystem::INFO, "while statement" );
  }
;

oop_stmt:
  object_stmt
| method_stmt
| list_stmt
//| try_catch_stmt
;

object_stmt:
  object_instantiate
| object_assignment
| object_call
;

object_instantiate:
  typed_object_instantiate {
    log.message( LogSystem::INFO, "typed object instantiate" );
  }
;

typed_object_instantiate:
  identifier IDENTIFIER
| modifier typed_object_instantiate
;

object_assignment:
  typed_object_instantiate ASSIGN_OP expr {
    log.message( LogSystem::INFO, "typed object assignment" );
  }
;

object_call:
  identifier '.' IDENTIFIER {
    log.message( LogSystem::INFO, "propriety called" );
  }
| identifier '.' method_prototype {
  log.message( LogSystem::INFO, "method called" );
  }
;

// TODO: Check how to make it work
//called:
//  propriety_call
//| method_call
//;

//propriety_call:
//  IDENTIFIER
//| propriety_call '.' IDENTIFIER
//;

//method_call:
//  method_prototype
//| method_call '.' method_prototype
//;

method_prototype:
  identifier '(' args_list ')'
;

args_list:
  // Empty
| args
;

args:
  arg
| args ',' arg
;

arg:
  expr
;

method_stmt:
  typed_method_stmt content_stmt {
    log.message( LogSystem::INFO, "typed method declaration" );
  }
| untyped_method_stmt content_stmt {
    log.message( LogSystem::INFO, "untyped method declaration" );
  }
;

typed_method_stmt:
  type IDENTIFIER '(' param_list ')'
| modifier typed_method_stmt
;

untyped_method_stmt:
  DEF IDENTIFIER '(' param_list ')'
;

param_list:
  // Empty
| params
;

params:
  param
| params ',' param
;

param:
  variable_stmt
;

list_stmt:
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

expr:
  value {
    log.message( LogSystem::INFO, "value" );
  }
| arithmetical_expr {
  log.message( LogSystem::INFO, "arithmetical expression" );
  }
| relational_expr
| creation_expr
| increment_expr
| oop_stmt
;

value:
  NUMBER
| STRING
| BOOL
| IDENTIFIER
;

arithmetical_expr:
  expr '*' expr
| expr '/' expr
| expr '+' expr
//| expr '-' expr
;

relational_expr:
  comparison_expr {
    log.message( LogSystem::INFO, "comparison expression" );
  }
| logical_expr {
  log.message( LogSystem::INFO, "logical expression" );
  }
;

comparison_expr:
  expr COMPARISON_OP expr
;

logical_expr:
  expr LOGICAL_OP expr
| '!' expr
;

creation_expr:
  CREATION_OP method_prototype
;

increment_expr:
  expr INCR_OP
;

type:
  TYPE_INTEGER { $$ = $1; }
| TYPE_LONG { $$ = $1; }
| TYPE_SHORT { $$ = $1; }
| TYPE_DOUBLE { $$ = $1; }
| TYPE_FLOAT { $$ = $1; }
| TYPE_STRING { $$ = $1; }
| TYPE_CHAR { $$ = $1; }
| TYPE_BOOLEAN { $$ = $1; }
| TYPE_LIST { $$ = $1; }
| TYPE_DATE { $$ = $1; }
;

modifier:
  PUBLIC
| PROTECTED
| PRIVATE
| STATIC
| FINAL
;

identifier:
  IDENTIFIER
;
