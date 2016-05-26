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
"!" |
"?" |
"(" |
")" |
"[" |
"]" |
"{" |
"}" |
":" |
";" |
"," |
"." |
"+" |
"-" |
"*" |
"/" |
"&" |
"|" |
"^" |
"~" {
  return matched()[ 0 ];
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

// We remove it for now, because it have a conflict with some parameters of grails.
//
//"default" {
//  *d_val = matched();
//  return Parser::DEFAULT;
//}

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

"+=" |
"-=" |
"*=" |
"/=" |
"%=" |
"=" {
  *d_val = matched();
  return Parser::ASSIGN_OP;
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

"?:" {
  *d_val = matched();
  return Parser::ELVIS_OP;
}

"&." {
  *d_val = matched();
  return Parser::MTD_PTR_OP;
}

"as" {
  *d_val = matched();
  return Parser::COERCION_OP;
}

"new" {
  *d_val = matched();
  return Parser::CREATION_OP;
}

"in" {
  *d_val = matched();
  return Parser::MEMBER_OP;
}

"?." {
  *d_val = matched();
  return Parser::SAFE_NAV_OP;
}

"try" {
  *d_val = matched();
  return Parser::TRY;
}

"catch" {
  *d_val = matched();
  return Parser::CATCH;
}

// --------------- End of Operators -----------------------

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
"\'" {
  more();
  begin( StartCondition__::oneline_string );
}

"\'\'\'" |
"\"\"\"" {
  more();
  begin( StartCondition__::multiline_string );
}

// --------------- End of Data Values ---------------------

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

// --------------- Mini-Scanners --------------------------

<oneline_string> {
  "\"" |
  "\'" {
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

  //--------------------------Scarefault--------------------------
  //
  "@param" {
    *d_val = matched();
    return Parser::SCAREFAULT_PARAM;
  }

  "@return" {
    *d_val = matched();
    return Parser::SCAREFAULT_RETURN;
  }

  "@range" {
    *d_val = matched();
    return Parser::SCAREFAULT_RANGE;
  }

  "@invalid" {
    *d_val = matched();
    return Parser::SCAREFAULT_INVALID;
  }

  "@expected" {
    *d_val = matched();
    return Parser::SCAREFAULT_EXPECTED;
  }

  //--------------------------Types--------------------------
  //
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

  //--------------------------Data Values--------------------------
  //
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
    return Parser::WORD;
  }

  //----------------------Operators-------------------------------
  //
  ".." {
    *d_val = matched();
    return Parser::RANGE_OP;
  }

  .|\n {
    more();
  }
}
