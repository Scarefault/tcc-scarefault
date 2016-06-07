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
          this->insert_param( va_arg( arguments, char * ) );
          break;
        case RANGE:
          this->set_range( va_arg( arguments, char * ) );
          break;
        case TEST_CASE:

          break;
      }

      format++;
    }
  }

  void CollectorScarefault::insert_param( std::string name )
  {
    Collector::Param param;
    param.name = Helper::remove_spaces( name );

    this->params.push_back( param );
  }

  void CollectorScarefault::set_range(std::string range )
  {
    std::size_t range_op_position = range.find( ".." );
    std::string min = range.substr( 0, range_op_position );
    std::string max = range.substr( range_op_position+2 );

    int last_param = this->params.size()-1;

    std::get<0>( this->params[ last_param ].range ) = std::stoi( min );
    std::get<1>( this->params[ last_param ].range ) = std::stoi( max );
  }

  std::vector<Collector::Param> * CollectorScarefault::get_params()
  {
    return &params;
  }

  Collector::Param CollectorScarefault::get_param( int index )
  {
    return this->params[ index ];
  }
}
