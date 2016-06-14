#include "identifier/parser/Parser.h"
#include "identifier/collector/CollectorBase.hpp"
#include "identifier/collector/Language.hpp"
#include "generator/tester/TesterDirector.hpp"
#include "generator/tester/TestfileDomainBuilder.hpp"
#include "generator/tester/TestfileControllerBuilder.hpp"
#include "generator/tester/TestfileProduct.hpp"

#include <iostream>

using namespace Collector;
using namespace Tester;

int main( int argc, char **argv )
{
  srand( time( NULL ) );

  Parser parser( GRAILS );
  parser.parse();

  CollectorBase * collector_ptr = address_collector;

  TesterDirector tester( new TestfileControllerBuilder( collector_ptr->get_data() ) );
  tester.generate_testfile();
  TestfileProduct * testfile = tester.get_testfile();
  std::cout << testfile->get_dependencies()
            << testfile->get_test_class();

  for( int i = 0; i < testfile->get_valid_testcases()->size(); i++ )
  {
    std::cout << (* testfile->get_valid_testcase( i ) ) << "\n";
  }
}
