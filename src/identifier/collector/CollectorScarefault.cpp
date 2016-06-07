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

    this->insert_test_case();
    this->print_collected_result(); // TODO: Temporary
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

  void CollectorScarefault::insert_test_case()
  {
    if( !( this->collected_case.get_expected_result().empty() &&
           this->collected_case.get_arguments()->empty() ) )
    {
      this->test_cases.push_back( this->collected_case );
      this->clear_collected_case();
    } else
    {
      // Nothing to do
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

  void CollectorScarefault::clear_collected_case()
  {
    this->collected_case.get_arguments()->clear();
    this->collected_case.get_expected_result().clear();
    this->collected_case.get_bound_method().clear();
  }

  // TODO: Temporary
  //
  void CollectorScarefault::print_collected_result()
  {
    std::cout << "Collected Test Cases:" << "\n";

    for( int i = 0; i < this->test_cases.size(); i++ )
    {
      std::cout << "Number [" << i << "]:" << "\n";
      std::cout << "\tBound Method: " << this->test_cases[i].get_bound_method() << "\n";
      std::cout << "\tExpected Result: " << this->test_cases[i].get_expected_result() << "\n";
      std::cout << "\tArguments:" << "\n";
      for( int j = 0; j < this->test_cases[i].get_arguments()->size(); j++ )
      {
        std::cout << "\tArg[" << j << "]:" << "\n";
        std::cout << "\t\tBound Param: " << this->test_cases[i].get_argument(j).bound_param << "\n";
        std::cout << "\t\tValue: " << this->test_cases[i].get_argument(j).value << "\n";
      }
      std::cout << "\n";
    }
  }
}
