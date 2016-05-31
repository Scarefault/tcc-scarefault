#include "CollectorScarefault.hpp"

namespace Collector
{
  void CollectorScarefault::collect_data( const char * format, ... )
  {
    va_list arguments;
    va_start( arguments, format );

    while( *format != EOL )
    {
      switch( *format )
      {
      case PARAM:
          this->insert_param( var_arg( arguments, char * ) );
          break;
        case RANGE:
          this->set_range( var_arg( arguments, char * ) );
          break;
      }

      format++;
    }
  }
}
