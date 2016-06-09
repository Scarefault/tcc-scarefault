#ifndef TESTFILEGRAILSBUILDER_HPP_
#define TESTFILEGRAILSBUILDER_HPP_


#include "TestfileBuilder.hpp"


namespace Tester
{
  class TestfileGrailsBuilder : public TestfileBuilder
  {
    public:
      TestfileGrailsBuilder();

      void build_dependencies();

    protected:
      virtual void build_package() = 0;
      virtual void build_imports() = 0;
  };
}

#endif // TESTFILEGRAILSBUILDER_HPP_
