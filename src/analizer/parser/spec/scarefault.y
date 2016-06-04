scarefault_stmt:
  word
| param_scarefault
| range_scarefault
| return_scarefault
| invalid_scarefault
| test_scarefault
;

param_scarefault:
  SCAREFAULT_PARAM word {
    log.message( LogSystem::INFO, "stmt: scarefault param" );
    std::string param_token( $2 );

    collector.collector_scarefault.collect_data( "p", param_token.c_str() );
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
  SCAREFAULT_RANGE value RANGE_OP value {
    log.message( LogSystem::INFO, "stmt: scarefault range" );
    std::string range( $2 );
    range.append( ".." );
    range.append( $4 );

    collector.collector_scarefault.collect_data( "r", range.c_str() );
  }
;

invalid_scarefault:
  SCAREFAULT_INVALID value {
    log.message( LogSystem::INFO, "stmt: scarefault invalid" );
  }
;

test_scarefault:
  test_stmt
;

test_stmt:
  SCAREFAULT_TEST '(' NUMBER_SCAREFAULT ')' {
    log.message( LogSystem::INFO, "stmt: scarefault test" );
  }
;

expect_scarefault:
  SCAREFAULT_EXPECT value {
    log.message( LogSystem::INFO, "stmt: scarefault expect" );
  }
;

argument:
  word
| NUMBER_SCAREFAULT
;

word:
  WORD  {
  log.message( LogSystem::INFO, "word" );
    $$ = $1;
  }
;
