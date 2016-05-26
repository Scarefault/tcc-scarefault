scarefault_stmt:
  param_scarefault
;

param_scarefault:
  SCAREFAULT_PARAM value {
    log.message( LogSystem::INFO, "stmt: scarefault param" );
  }
;
