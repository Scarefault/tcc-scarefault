DIGIT   [[:digit:]]
INTEGER {DIGIT}+
REAL    -?{WHITESPACE}?{INTEGER}+("."{INTEGER}+)?

WHITESPACE [[:blank:]]+

IDENTIFIER _?[a-zA-Z0-9][a-zA-Z0-9]*

TRUE    true
FALSE   false
BOOLEAN {TRUE}|{FALSE}

%x quot_string
%x t_quot_string
%x t_d_quot_string
%x slashy_string
%x comment


%%


//---------------------------- Importation --------------------------------- //
//
"import" {
  *d_val = matched();
  return Parser::IMPORT;
}

"package" {
  *d_val = matched();
  return Parser::PACKAGE;
}

//-------------------------------- Classes --------------------------------- //
//
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

"new" {
  *d_val = matched();
  return Parser::NEW;
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


// ------------------------------ Methods ---------------------------------- //
//
"def" {
  *d_val = matched();
  return Parser::DEF;
}


// --------------------------- Type of Data -------------------------------- //
//
"Integer"   |
"int" {
  *d_val = matched();
  return Parser::TYPE_INTEGER;
}

"Long"      |
"long" {
  *d_val = matched();
  return Parser::TYPE_LONG;
}

"Short"     |
"short" {
  *d_val = matched();
  return Parser::TYPE_SHORT;
}

"Double"    |
"double" {
  *d_val = matched();
  return Parser::TYPE_DOUBLE;
}

"Float"     |
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

"Boolean"   |
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

//-------------------------- Punctuation Marks ----------------------------- //
//
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

";" {
  *d_val = matched();
  return Parser::SEMICOLON;
}

":" {
  *d_val = matched();
  return Parser::COLON;
}

"." {
  *d_val = matched();
  return Parser::DOT;
}

"..." {
  *d_val = matched();
  return Parser::SUSPN_DOTS;
}

"," {
  *d_val = matched();
  return Parser::COMMA;
}

"=" {
  *d_val = matched();
  return Parser::EQUAL;
}

"*" {
  *d_val = matched();
  return Parser::STAR;
}


//----------------------------- Scarefault Marks --------------------------- //
//
"scarefault" {
  *d_val = matched();
  return Parser::SCAREFAULT;
}

"scenario" {
  *d_val = matched();
  return Parser::SCENARIO;
}

"entries" {
  *d_val = matched();
  return Parser::ENTRIES;
}

"out" {
  *d_val = matched();
  return Parser::OUT;
}

//-------------------------- Control Strutucture --------------------------- //
//
"if" {
  *d_val = matched();
  return Parser::IF;
}

"else" {
  *d_val = matched();
  return Parser::ELSE;
}

"?" {
  *d_val = matched();
  return Parser::QUESTION_MARK;
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

"in" {
  *d_val = matched();
  return Parser::IN;
}

"while" {
  *d_val = matched();
  return Parser::WHILE;
}


//------------------------------ Operators --------------------------------- //
"=="    |
"!="    |
"<="    |
">="    |
">"     |
"<" {
  *d_val = matched();
  return Parser::COMPARISON_OP;
}

"&&"    |
"||" {
  *d_val = matched();
  return Parser::LOGICAL_OP;
}

"++"    |
"--" {
  *d_val = matched();
  return Parser::INCR_OP;
}

"as" {
  *d_val = matched();
  return Parser::COERCION_OP;
}


//------------------------------- Data Values ------------------------------ //
//
{DIGIT}       |
{INTEGER}     |
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

"\""      |
"\'"  {
  more();
  begin( StartCondition__::quot_string );
}
<quot_string> {
  "\""    |
  "\'" {
    begin( StartCondition__::INITIAL );
    *d_val = matched();
    return Parser::STRING;
  }

  \\.|. {
    more();
  }
}

"\'\'\'" {
  more();
  begin( StartCondition__::t_quot_string );
}
<t_quot_string> {
  "\'\'\'" {
    begin( StartCondition__::INITIAL );
    *d_val = matched();
    return Parser::STRING;
  }

  \\.|. {
    more();
  }

  "\n" {
    more();
  }
}

"\"\"\"" {
  more();
  begin( StartCondition__::t_d_quot_string );
}
<t_d_quot_string> {
  "\"\"\"" {
    begin( StartCondition__::INITIAL );
    *d_val = matched();
    return Parser::STRING;
  }

  \\.|. {
    more();
  }

  "\n" {
    more();
  }
}

"\/" {
  more();
  begin( StartCondition__::slashy_string );
}
<slashy_string> {
  "\/" {
    begin( StartCondition__::INITIAL );
    *d_val = matched();
    return Parser::STRING;
  }

  \\.|. {
    more();
  }
}

"/*"   |
"/**" {
  more();
  begin( StartCondition__::comment );
}
<comment> {
  "*/" {
    begin( StartCondition__::INITIAL );
    *d_val = matched();
    return Parser::COMMENT;
  }

  \\.|. {
    more();
  }

  "\n" {
    more();
  }
}
