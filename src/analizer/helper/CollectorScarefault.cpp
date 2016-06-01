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
          this->insert_param( va_arg( arguments, char * ) )
          break;
        case RANGE:
          this->set_range( var_arg( arguments, char * ) );
          break;
      }

      format++;
    }
  }

  void CollectorScarefault::insert_param( std::string name )
  {
    Helper::Param param;
    param.param_name = name;

    this->params.push_back( param );
  }

  void CollectorScarefault::set_range(std::string range )
  {
    std::size_t range_op_position = range.find( ".." );
    std::string min = range.substr( 0, range_op_position );
    std::string max = range.substr( range_op_position+2 );

    std::get<0>( this->params[ this->params.size() ].range ) = min;
    std::get<1>( this->params[ this->params.size() ].range ) = max;
  }

  std::vector<Helper::Param> CollectorScarefault::get_params()
  {
    return this->params;
  }

  Helper::Param CollectorScarefault::get_param( int index )
  {
    return this->params[ index ];
  }
}
