content:
  package_declaration
| import_declaration
| class_declaration
| comment_stmt
;

package_declaration:
  PACKAGE package_name
;

import_declaration:
  IMPORT package_name
;

class_declaration:
  CLASS IDENTIFIER content_stmt
;

package_name:
  IDENTIFIER
| package_name '.' IDENTIFIER
;

content_stmt:
  // Empty
| '{' stmt '}'
;

stmt:
  // Empty
| comment_stmt
| basic_stmt
| oop_stmt
;

comment_stmt:
  COMMENT
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
  typed_variable_declaration
| untyped_variable_declaration
;

typed_variable_declaration:
  type IDENTIFIER
| modifier typed_variable_declaration
;

untyped_variable_declaration:
  identifier
| DEF untyped_variable_declaration
| modifier untyped_variable_declaration
;

variable_assignment:
  typed_variable_declaration ASSIGN_OP expr
| untyped_variable_declaration ASSIGN_OP expr
;

control_structure_stmt:
  conditional_structure_stmt
| looping_structure_stmt
;

conditional_structure_stmt:
  if_stmt
| switch_stmt
;

if_stmt:
  IF '(' conditional_argument ')' content_stmt
| ELSE if_stmt
| ELSE '(' conditional_argument ')' content_stmt
;

switch_stmt:
  SWITCH '(' conditional_argument ')' switch_content
;

switch_content:
  '{' case_stmt '}'
;

case_stmt:
  CASE expr ':' stmt
;

conditional_argument:
  expr
| oop_stmt
;

looping_structure_stmt:
  for_stmt
| while_stmt
;

for_stmt:
  FOR '(' for_argument ')' content_stmt
;

for_argument:
  typed_variable_declaration ';' conditional_argument ';' expr
;

while_stmt:
  WHILE '(' conditional_argument ')' content_stmt
;

oop_stmt:
  object_stmt
| method_stmt
//| try_catch_stmt
;

object_stmt:
  object_instantiate
| object_assignment
| object_call
;

object_instantiate:
  typed_object_instantiate
| untyped_object_instantiate
;

typed_object_instantiate:
  IDENTIFIER IDENTIFIER
| modifier typed_object_instantiate
;

untyped_object_instantiate:
  identifier
| DEF untyped_object_instantiate
| modifier untyped_object_instantiate
;

object_assignment:
  typed_object_instantiate ASSIGN_OP expr
| untyped_object_instantiate ASSIGN_OP expr
;

object_call:
  called '.' IDENTIFIER
| called '.' method_prototype
;

called:
  propriety_call
| method_call
;

propriety_call:
  IDENTIFIER
| propriety_call '.' IDENTIFIER
;

method_call:
  method_prototype
| method_call '.' method_prototype
;

method_prototype:
  IDENTIFIER '(' args_list ')'
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
| object_call
;

method_stmt:
  typed_method_stmt content_stmt
| untyped_method_stmt content_stmt
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

expr:
  NUMBER
| STRING
| BOOL
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
