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
//%token DEFAULT
%token FOR
%token WHILE


/*
 * ********** Operators ******************
 */
%left '*' '/'
%left '+' '-'
%right ASSIGN_OP
%left COMPARISON_OP
%left LOGICAL_OP
%left INCR_OP
%token COERCION_OP
%left ELVIS_OP
%left MTD_PTR_OP
%token CREATION_OP
%token MEMBER_OP
%left SAFE_NAV_OP
%token TRY
%token CATCH


/*
 * ********** Punctuation Marks **********
 */
%right '.'
%left '(' ')' '[' ']' '{' '}'
%token SUSPN_DOTS

/*
 * ********** Scarefault Marks **********
 */
%token SCAREFAULT_PARAM
%token SCAREFAULT_RANGE
%token SCAREFAULT_RETURN
%token SCAREFAULT_INVALID
%token SCAREFAULT_EXPECTED
