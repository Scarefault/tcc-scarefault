/*
 * ************ Importation **************
 */
%token IMPORT
%token PACKAGE


/*
 * ************* Classes *****************
 */
%token CLASS
%token INTERFACE
%left IMPLEMENTS
%left EXTENDS
%token ABSTRACT
%token PUBLIC
%token PROTECTED
%token PRIVATE
%token STATIC
%token FINAL
%token COMMENT
%token DEF


/*
 * ********* Type of Data ****************
 */
%token TYPE_INTEGER
%token TYPE_LONG
%token TYPE_SHORT
%token TYPE_DOUBLE
%token TYPE_FLOAT
%token TYPE_STRING
%token TYPE_CHAR
%token TYPE_BOOLEAN
%token TYPE_LIST
%token TYPE_DATE


/*
 * ********** Punctuation Marks **********
 */
%right '.'
%token SUSPN_DOTS


/*
 * ********** Data Values ****************
 */
%token NUMBER
%token STRING
%token IDENTIFIER
%token BOOL


/*
 * ********** Control Structures *********
 */
%token IF
%left ELSE
%token SWITCH
%token CASE
%token DEFAULT
%token FOR
%token WHILE


/*
 * ********** Operators ******************
 */
%token EQUAL
%token COMPARISON_OP
%token LOGICAL_OP
%token INCR_OP
%token COERCION_OP
%token NEW
%token IN
%token PLUS
%token MINUS
