#include "TesterDirector.hpp"

namespace Tester
{
  TesterDirector::TesterDirector( Tester::TestfileBuilder * builder )
  {
    this->generator_testile = builder;
  }

  TesterDirector::generate_testfile()
  {
    generator_testile->build_dependencies();
    generator_testile->build_test_class();
    generator_testile->build_valid_testcase();
  }

  TesterDirector::get_testfile()
  {
    return this->generator_testile->get_testfile();
  }
}
