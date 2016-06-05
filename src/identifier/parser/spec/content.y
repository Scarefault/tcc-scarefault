content:
  package_declaration {
    log.message( LogSystem::INFO, "stmt: package declaration" );
  }
| import_declaration {
    log.message( LogSystem::INFO, "stmt: import declaration" );
  }
| class_declaration
| interface_declaration
| comment_stmt
| scarefault_stmt
;

package_declaration:
  PACKAGE package_name {
    std::string package_token( $2 );
    collector->collect_data( "P", package_token.c_str() );
  }
;

import_declaration:
  IMPORT package_name
| IMPORT STATIC package_name
| import_declaration COERCION_OP IDENTIFIER
;

class_declaration:
  class_definition content_stmt {
    log.message( LogSystem::INFO, "stmt: class declaration" );
  }
;

class_definition:
  CLASS IDENTIFIER {
    std::string identifier_token( $2 );
    collector->collect_data( "c", identifier_token.c_str() );
  }
| ABSTRACT class_definition
| class_definition class_complements
;

class_complements:
  IMPLEMENTS IDENTIFIER
| EXTENDS IDENTIFIER
;

interface_declaration:
  INTERFACE IDENTIFIER content_stmt {
    log.message( LogSystem::INFO, "stmt: interface declaration" );
  }
;

package_name:
  IDENTIFIER
| package_name '.' IDENTIFIER
| package_name '.' '*'
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
| scarefault_stmt
;

untyped_identifier_stmt:
  untyped_identifier_declaration {
    log.message( LogSystem::INFO, "stmt: untyped identifier declaration" );
  }
| untyped_identifier_declaration ASSIGN_OP expr {
    log.message( LogSystem::INFO, "stmt: untyped identifier assignment" );
  }
;

untyped_identifier_declaration:
  IDENTIFIER
| DEF untyped_identifier_declaration
| modifier untyped_identifier_declaration
;

comment_stmt:
  COMMENT {
    log.message( LogSystem::INFO, "stmt: comment statement" );
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
    log.message( LogSystem::INFO, "stmt: typed variable declaration" );
  }
;

typed_variable_declaration:
  type IDENTIFIER {
    std::string declaration( $1 );

    declaration.append( " " );
    declaration.append( $2 );

    $$ = declaration;
  }
| modifier typed_variable_declaration
;

variable_assignment:
  typed_variable_declaration ASSIGN_OP expr {
    log.message( LogSystem::INFO, "stmt: typed variable assignment" );
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
    log.message( LogSystem::INFO, "stmt: if statement" );
  }
| if_stmt ELSE if_stmt {
  log.message( LogSystem::INFO, "stmt: elseif statement" );
  }
| if_stmt ELSE content_stmt {
  log.message( LogSystem::INFO, "stmt: else statement" );
  }
;

ternary_stmt:
  expr '?' expr ':' expr
;

switch_stmt:
  SWITCH '(' conditional_argument ')' switch_content  {
    log.message( LogSystem::INFO, "stmt: switch statement" );
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
    log.message( LogSystem::INFO, "stmt: case statement" );
  }
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
    log.message( LogSystem::INFO, "stmt: for statement" );
  }
;

for_argument:
  variable_assignment ';' conditional_argument ';' expr
;

while_stmt:
  WHILE '(' conditional_argument ')' content_stmt {
    log.message( LogSystem::INFO, "stmt: while statement" );
  }
;

oop_stmt:
  object_stmt
| method_stmt
| list_stmt
| try_catch_stmt
;

object_stmt:
  object_instantiate
| object_assignment
| object_call
| method_prototype {
  log.message( LogSystem::INFO, "stmt: method called" );
  }
;

object_instantiate:
  typed_object_instantiate {
    log.message( LogSystem::INFO, "stmt: typed object instantiate" );
  }
;

typed_object_instantiate:
  identifier IDENTIFIER
| modifier typed_object_instantiate
;

object_assignment:
  typed_object_instantiate ASSIGN_OP expr {
    log.message( LogSystem::INFO, "stmt: typed object assignment" );
  }
;

object_call:
  caller '.' IDENTIFIER {
    log.message( LogSystem::INFO, "stmt: propriety called" );
  }
| caller '.' method_prototype {
  log.message( LogSystem::INFO, "stmt: method called" );
  }
;

caller:
  IDENTIFIER
| method_prototype
| caller '.' IDENTIFIER
| caller '.' method_prototype
;

method_prototype:
  identifier '(' args_list ')'
;

args_list:
  // Empty
| args
;

args:
  arg
| args ',' arg {
  std::string args_token( $1 );
  args_token.append( "," );
  args_token.append( $3 );

  $$ = args_token;
}
;

arg:
  expr
| item_map
;

method_stmt:
  typed_method_stmt content_stmt {
    log.message( LogSystem::INFO, "stmt: typed method declaration" );
  }
| untyped_method_stmt content_stmt {
    log.message( LogSystem::INFO, "stmt: untyped method declaration" );
  }
;

typed_method_stmt:
  type IDENTIFIER '(' param_list ')' {
    std::string identifier_token( $2 );
    std::string params_token( $4 );

    collector->collect_data( "mp", identifier_token.c_str(), params_token.c_str() );
  }
| modifier typed_method_stmt
;

untyped_method_stmt:
  DEF IDENTIFIER '(' param_list ')' {
    std::string identifier_token( $2 );
    std::string params_token( $4 );

    collector->collect_data( "mp", identifier_token.c_str(), params_token.c_str() );
  }
;

param_list:
  // Empty
| params
;

params:
  param
| params ',' param {
    std::string params_token( $1 );
    params_token.append( "," );
    params_token.append( $3 );

    $$ = params_token;
  }
;

param:
  variable_stmt
;

list_stmt:
  '[' item_list ']' {
    log.message( LogSystem::INFO, "stmt: list declaration" );
  }
| '[' maps_list ']' {
    log.message( LogSystem::INFO, "stmt: map declaration" );
  }
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

try_catch_stmt:
  TRY content_stmt {
    log.message( LogSystem::INFO, "stmt: try statement");
  }
| CATCH '(' object_instantiate ')' content_stmt {
    log.message( LogSystem::INFO, "stmt: catch statement");
  }
;

expr:
  value
| arithmetical_expr {
  log.message( LogSystem::INFO, "stmt: arithmetical expression" );
  }
| relational_expr
| creation_expr
| increment_expr
| oop_stmt
| elvis_expr
| safe_nav_expr
| mtd_ptr_expr
| '(' expr ')'
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
    log.message( LogSystem::INFO, "stmt: comparison expression" );
  }
| logical_expr {
  log.message( LogSystem::INFO, "stmt: logical expression" );
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
  CREATION_OP method_prototype {
    log.message( LogSystem::INFO, "stmt: creation expression" );
  }
;

increment_expr:
  expr INCR_OP
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
