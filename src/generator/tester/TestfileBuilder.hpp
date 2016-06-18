#ifndef TESTFILEBUILDER_HPP_
#define TESTFILEBUILDER_HPP_


#include "TestfileProduct.hpp"
#include "../../identifier/file/FileMVC.hpp"
#include "../value_generator/ValueGenerator.hpp"

namespace Tester
{
  class TestfileBuilder
  {
    public:
      Tester::TestfileProduct * get_testfile();

      virtual void build_dependencies() = 0;
      virtual void build_test_class() = 0;
      virtual void build_valid_testcases() = 0;

    protected:
      Tester::TestfileProduct * testfile;
      Collector::FileMVC * data_ptr;
      Generator::ValueGenerator * value_generator;
  };
}

#endif // TESTFILEBUILDER_HPP_
