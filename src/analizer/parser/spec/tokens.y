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
%left '*' '/'
%left '+' '-'
%right ASSIGN_OP
%token COMPARISON_OP
%token LOGICAL_OP
%token INCR_OP
%token COERCION_OP
%token BITWISE_OP
%token ELVIS_OP
%token MTD_PTR_OP
%token FIND_RGX_OP
%token MATCH_RGX_OP
%token SPD_OP
%token RNG_OP
%token CREATION_OP
%token MEMBER_OP
%token ID_OP
%token INSTANCEOF_OP
