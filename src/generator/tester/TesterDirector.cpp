#include "TesterDirector.hpp"


namespace Tester
{
  TesterDirector::TesterDirector( Tester::TestfileBuilder * builder )
  {
    this->generator_testile = builder;
  }

  void TesterDirector::generate_testfile()
  {
    generator_testile->build_dependencies();
    generator_testile->build_test_class();
    generator_testile->build_setup();
    generator_testile->build_valid_testcases();
  }

  Tester::TestfileProduct * TesterDirector::get_testfile()
  {
    return this->generator_testile->get_testfile();
  }
}
