#ifndef TESTERDIRECTOR_HPP_
#define TESTERDIRECTOR_HPP_


#include "TestfileBuilder.hpp"
#include "TestfileProduct.hpp"


namespace Tester
{
  class TesterDirector
  {
    public:
      TesterDirector( Tester::TestfileBuilder * );

      void generate_testfile();
       Tester::TestfileProduct * get_testfile();

    protected:
      Tester::TestfileBuilder * generator_testile;
  };
}

#endif // TESTERDIRECTOR_HPP_
