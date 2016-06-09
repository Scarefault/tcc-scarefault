#ifndef TESTFILEDOMAINSBUILDER_HPP_
#define TESTFILEDOMAINSBUILDER_HPP_


#include <sstream>


#include "TestfileGrailsBuilder.hpp"


namespace Tester
{
  class TestfileDomainBuilder : public TestfileGrailsBuilder
  {
    public:
      TestfileDomainBuilder( Collector::FileMVC * );

      void build_package();
      void build_imports();
      void build_test_class();
      void build_valid_testcases();
  };
}

#endif // TESTFILEDOMAINSBUILDER_HPP_
