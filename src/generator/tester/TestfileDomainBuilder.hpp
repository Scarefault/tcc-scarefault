#ifndef TESTFILEDOMAINSBUILDER_HPP_
#define TESTFILEDOMAINSBUILDER_HPP_


#include "TestfileGrailsBuilder.hpp"


namespace Tester
{
  class TestfileDomainBuilder : public TestfileGrailsBuilder
  {
    public:
      TestfileDomainBuilder();

      void build_package();
      void build_imports();
      void build_test_class();
      void build_valid_testcases();
  };
}

#endif // TESTFILEDOMAINSBUILDER_HPP_
