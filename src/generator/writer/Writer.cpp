#include <iostream>


#include "Writer.hpp"


namespace Tester
{
  Writer::Writer( Tester::TesterDirector * tester_director )
  {
    this->tester = tester_director;
  }

  void Writer::write_testfile()
  {
    std::fstream test_stream;

    test_stream.open( TESTFILE, WRITE|APPEND );

    if( test_stream.is_open() )
    {
      test_stream << tester->get_testfile()->get_dependencies()
                  << tester->get_testfile()->get_test_class();

      for( int i = 0; i < tester->get_testfile()->get_valid_testcases()->size(); i++ )
      {
        test_stream << (* tester->get_testfile()->get_valid_testcase( i ) )
                    << std::endl;
      }

      test_stream.close();
    } else
    {
      std::cout << "Unable to open TESTFILE..." << std::endl;
    }
  }
}
