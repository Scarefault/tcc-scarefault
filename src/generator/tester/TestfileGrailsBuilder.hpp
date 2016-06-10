#ifndef TESTFILEGRAILSBUILDER_HPP_
#define TESTFILEGRAILSBUILDER_HPP_


#include "TestfileBuilder.hpp"


namespace Tester
{
  class TestfileGrailsBuilder : public TestfileBuilder
  {
    public:
      void build_dependencies();

    protected:
      virtual std::string build_package() = 0;
      virtual std::string build_imports() = 0;
  };
}

#endif // TESTFILEGRAILSBUILDER_HPP_
