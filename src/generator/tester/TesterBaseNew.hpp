#ifndef TESTERNEW_HPP_
#define TESTERNEW_HPP_


#include <string>


#include "../../helper/Helper.hpp"
#include "../../identifier/collector/FileMVC.hpp"
#include "../value_generator/ValueGenerator.hpp"

namespace Tester
{
  class TesterNew
  {
    public:
      TesterNew();

      virtual void generate_tesfile() { /* Implement it in Subclass */ };

    protected:
      Collector::FileMVC * data_ptr;
      Generator::ValueGenerator value_generator;


      virtual void init_testfile();
      virtual void test_methods() { /* Implement it in Subclass */ };

      void set_data();
      void generate_valid_test();
  };
}

#endif // TESTERNEW_HPP_
