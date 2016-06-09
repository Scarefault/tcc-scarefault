#ifndef TESTERDIRECTOR_HPP_
#define TESTERDIRECTOR_HPP_


#include "TestfileBuilder.hpp"
#include "TestfileProduct.hpp"
#include "../../identifier/collector/FileMVC.hpp"


namespace Tester
{
  class TesterDirector
  {
    public:
      TesterDirector( Tester::TestfileBuilder, Collector::FileMVC * );

      void generate_testfile();
       Tester::TestfileProduct get_testfile();

    protected:
      Tester::TestfileBuilder generator_testile;
  };
}

#endif // TESTERDIRECTOR_HPP_
