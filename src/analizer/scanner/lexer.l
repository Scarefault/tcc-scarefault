DIGIT   [[:digit:]]
INTEGER {DIGIT}+
REAL    -?{WHITESPACE}?{INTEGER}+("."{INTEGER}+)?

WHITESPACE [[:blank:]]+

IDENTIFIER _?[a-zA-Z0-9][a-zA-Z0-9]*

TRUE    true
FALSE   false
BOOLEAN {TRUE}|{FALSE}

%x oneline_string
%x multiline_string
%x multiline_comment


%%


// -------------- Importation -----------------------------

"import" {
  *d_val = matched();
  return Parser::IMPORT;
}

"package" {
  *d_val = matched();
  return Parser::PACKAGE;
}

// --------------- End of Importation ---------------------

// --------------- Classes --------------------------------

"class" {
  *d_val = matched();
  return Parser::CLASS;
}

"interface" {
  *d_val = matched();
  return Parser::INTERFACE;
}

"implements" {
  *d_val = matched();
  return Parser::IMPLEMENTS;
}

"extends" {
  *d_val = matched();
  return Parser::EXTENDS;
}

"abstract" {
  *d_val = matched();
  return Parser::ABSTRACT;
}

"public" {
  *d_val = matched();
  return Parser::PUBLIC;
}

"protected" {
  *d_val = matched();
  return Parser::PROTECTED;
}

"private" {
  *d_val = matched();
  return Parser::PRIVATE;
}

"static" {
  *d_val = matched();
  return Parser::STATIC;
}

"final" {
  *d_val = matched();
  return Parser::FINAL;
}

"def" {
  *d_val = matched();
  return Parser::DEF;
}

// --------------- End of Classes -------------------------

// --------------- Type of Data ---------------------------

"Integer" |
"int" {
  *d_val = matched();
  return Parser::TYPE_INTEGER;
}

"Long" |
"long" {
  *d_val = matched();
  return Parser::TYPE_LONG;
}

"Short" |
"short" {
  *d_val = matched();
  return Parser::TYPE_SHORT;
}

"Double" |
"double" {
  *d_val = matched();
  return Parser::TYPE_DOUBLE;
}

"Float" |
"float" {
  *d_val = matched();
  return Parser::TYPE_FLOAT;
}

"String" {
  *d_val = matched();
  return Parser::TYPE_STRING;
}

"Character" |
"char" {
  *d_val = matched();
  return Parser::TYPE_CHAR;
}

"Boolean" |
"boolean" {
  *d_val = matched();
  return Parser::TYPE_BOOLEAN;
}

"List" {
  *d_val = matched();
  return Parser::TYPE_LIST;
}

"Date" {
  *d_val = matched();
  return Parser:: TYPE_DATE;
}

// -------------- End of Type of Data ---------------------

// -------------- Punctuation Marks -----------------------

"?" {
  *d_val = matched();
  return Parser::QUESTION_MARK;
}

"(" {
  *d_val = matched();
  return Parser::L_PAR;
}

")" {
  *d_val = matched();
  return Parser::R_PAR;
}

"[" {
  *d_val = matched();
  return Parser::L_BRKT;
}

"]" {
  *d_val = matched();
  return Parser::R_BRKT;
}

"{" {
  *d_val = matched();
  return Parser::L_BRACE;
}

"}" {
  *d_val = matched();
  return Parser::R_BRACE;
}

"/" {
  *d_val = matched();
  return Parser::SLASH;
}

"*" {
  *d_val = matched();
  return Parser::STAR;
}

":" {
  *d_val = matched();
  return Parser::COLON;
}

";" {
  *d_val = matched();
  return Parser::SEMICOLON;
}

"," {
  *d_val = matched();
  return Parser::COMMA;
}

"." {
  *d_val = matched();
  return Parser::DOT;
}

"..." {
  *d_val = matched();
  return Parser::SUSPN_DOTS;
}

// --------------- End of Punctuation Marks ---------------

// --------------- Control Strutuctures -------------------

"if" {
  *d_val = matched();
  return Parser::IF;
}

"else" {
  *d_val = matched();
  return Parser::ELSE;
}

"switch" {
  *d_val = matched();
  return Parser::SWITCH;
}

"case" {
  *d_val = matched();
  return Parser::CASE;
}

"default" {
  *d_val = matched();
  return Parser::DEFAULT;
}

"for" {
  *d_val = matched();
  return Parser::FOR;
}

"while" {
  *d_val = matched();
  return Parser::WHILE;
}

// --------------- End of Control Structures --------------

// --------------- Operators ------------------------------

"=" {
  *d_val = matched();
  return Parser::EQUAL;
}

"==" |
"!=" |
"<=" |
">=" |
">"  |
"<" {
  *d_val = matched();
  return Parser::COMPARISON_OP;
}

"&&" |
"||" {
  *d_val = matched();
  return Parser::LOGICAL_OP;
}

"++" |
"--" {
  *d_val = matched();
  return Parser::INCR_OP;
}

"as" {
  *d_val = matched();
  return Parser::COERCION_OP;
}

"new" {
  *d_val = matched();
  return Parser::NEW;
}

"in" {
  *d_val = matched();
  return Parser::IN;
}

"+" {
  *d_val = matched();
  return Parser::PLUS;
}

"-" {
  *d_val = matched();
  return Parser::MINUS;
}

// --------------- End of Operators -----------------------

// --------------- Comments -------------------------------

\/\/.*$ {
  /* Ignore Comment. */
}

"/*" |
"/**" {
  more();
  begin( StartCondition__::multiline_comment );
}

// --------------- End of Comments ------------------------

// --------------- Data Values ----------------------------

{DIGIT}   |
{INTEGER} |
{REAL} {
  *d_val = matched();
  return Parser::NUMBER;
}

{BOOLEAN} {
  *d_val = matched();
  return Parser::BOOL;
}

{IDENTIFIER} {
  *d_val = matched();
  return Parser::IDENTIFIER;
}

"\"" |
"\'" |
"\/" {
  more();
  begin( StartCondition__::oneline_string );
}

"\'\'\'" |
"\"\"\"" {
  more();
  begin( StartCondition__::multiline_string );
}

// --------------- End of Data Values ---------------------

// --------------- Mini-Scanners --------------------------

<oneline_string> {
  "\"" |
  "\'" |
  "\/" {
    begin( StartCondition__::INITIAL );
    *d_val = matched();
    return Parser::STRING;
  }

  . {
    more();
  }
}


<multiline_string> {
  "\'\'\'"  |
  "\"\"\"" {
    begin( StartCondition__::INITIAL );
    *d_val = matched();
    return Parser::STRING;
  }

  .|\n {
    more();
  }
}


<multiline_comment> {
  "*/" {
    begin( StartCondition__::INITIAL );
    *d_val = matched();
    return Parser::COMMENT;
  }

  .|\n {
    more();
  }
}
 
