#include "TesterDomain.hpp"

namespace Tester
{
  TesterDomain::TesterDomain( Helper::Data * ptr_data )
  {
    this->set_data( ptr_data );
  }

  void TesterDomain::write_data()
  {
    std::fstream test_stream;

    test_stream.open( TESTFILE, WRITE|APPEND );

    if( test_stream.is_open() )
    {
      make_header( &test_stream );
      test_methods( &test_stream );
      TesterBase::conclude_data( &test_stream );

      test_stream.close();
    } else
    {
      std::cout << "Unable to open TESTFILE..." << std::endl;
    }
  }

  void TesterDomain::make_header( std::fstream * test_stream )
  {
    (* test_stream) << "package " << data_ptr->package_name
                    << std::endl
                    << std::endl
                    << "import org.junit.*"
                    << std::endl
                    << "import grails.test.mixin.*"
                    << std::endl
                    << std::endl
                    << "@TestFor(" << data_ptr->class_name << ")"
                    << std::endl
                    << "class " << data_ptr->class_name << "Tests {"
                    << std::endl
                    << std::endl;
  }

  void TesterDomain::test_methods( std::fstream * test_stream )
  {
  }
}
