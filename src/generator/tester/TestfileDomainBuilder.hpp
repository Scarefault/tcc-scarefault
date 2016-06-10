#ifndef TESTFILEDOMAINBUILDER_HPP_
#define TESTFILEDOMAINBUILDER_HPP_


#include <sstream>


#include "TestfileGrailsBuilder.hpp"


namespace Tester
{
  class TestfileDomainBuilder : public TestfileGrailsBuilder
  {
    public:
      TestfileDomainBuilder( Collector::FileMVC * );

      void build_test_class();
      void build_valid_testcases();

    protected:
      std::string build_package();
      std::string build_imports();
  };
}

#endif // TESTFILEDOMAINBUILDER_HPP_
