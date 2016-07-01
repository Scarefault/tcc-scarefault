scarefault_stmt:
  word
| param_scarefault
| range_scarefault
| return_scarefault
| invalid_scarefault
| test_scarefault
| use_scarefault
;

param_scarefault:
  SCAREFAULT_PARAM word {
    log.message( LogSystem::INFO, "stmt: scarefault param" );
    std::string param_token( $2 );

    collector->collector_scarefault.collect_data( "p", param_token.c_str() );
  }
;

return_scarefault:
  SCAREFAULT_RETURN word {
    log.message( LogSystem::INFO, "stmt: scarefault return" );
  }
;

range_scarefault:
  param_scarefault range_stmt
;

range_stmt:
  SCAREFAULT_RANGE val RANGE_OP val {
    log.message( LogSystem::INFO, "stmt: scarefault range" );
    std::string range( $2 );
    range.append( ".." );
    range.append( $4 );

    collector->collector_scarefault.collect_data( "r", range.c_str() );
  }
;

use_scarefault:
  param_scarefault use_stmt
;

use_stmt:
  SCAREFAULT_USE word {
    log.message( LogSystem::INFO, "stmt: scarefault use" );
    std::string propriety_token( $2 );

    collector->collector_scarefault.collect_data( "P", propriety_token.c_str() );
  }
;

invalid_scarefault:
  SCAREFAULT_INVALID value {
    log.message( LogSystem::INFO, "stmt: scarefault invalid" );
  }
;

expected_scarefault:
  SCAREFAULT_EXPECTED word {
    log.message( LogSystem::INFO, "stmt: scarefault expected" );
  }
;

test_scarefault:
  SCAREFAULT_TEST PAR_L values PAR_R SCAREFAULT_EXPECT val {
    log.message( LogSystem::INFO, "stmt: scarefault test" );

    std::string arguments_token( $3 );
    std::string result_token( $6 );

    collector->collector_scarefault.collect_data( "ae", arguments_token.c_str(),
        result_token.c_str() );
  }
;

values:
  val
| values COMMA val {
  std::string values_token( $1 );
  values_token.append( "," );
  values_token.append( $3 );

  $$ = values_token;
}
;

val:
  NUM
| BOOLEAN
| str
| word
;

str:
  QUOT word QUOT {
    std::string str_token( $1 );
    str_token.append( $2 );
    str_token.append( $3 );
    $$ = str_token;
  }
;

word:
  WORD
;
