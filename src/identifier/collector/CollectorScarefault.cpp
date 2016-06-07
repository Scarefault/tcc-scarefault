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
        case ARGUMENTS_FOR_TEST_CASE:
          this->collect_arguments( va_arg( arguments, char * ) );
          break;
        case EXPECTED_RESULT:
          this->collect_expected_result( va_arg( arguments, char * ) );
          break;
      }

      format++;
    }
  }

  Collector::Param CollectorScarefault::get_param( int index )
  {
    return this->params[ index ];
  }

  std::vector<Collector::Param> * CollectorScarefault::get_params()
  {
    return &params;
  }

  void CollectorScarefault::collect_arguments( std::string arguments )
  {
    if( !arguments.empty() )
    {
      std::vector<std::string> args = Helper::extract_words( arguments, " ," );

      while( !args.empty() )
      {
        Tester::Arg arg;
        arg.value = args.front();

        this->collected_case.insert_argument( arg );

        args.erase( args.begin() );
      }
    } else
    {
      // Nothing to do
    }
  }

  void CollectorScarefault::collect_expected_result( std::string result )
  {
    this->collected_case.set_expected_result( result );
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
}
