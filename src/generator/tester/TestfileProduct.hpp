#ifndef TESTFILEPRODUCT_HPP_
#define TESTFILEPRODUCT_HPP_


#include <string>


namespace Tester
{
  class TestfileProduct
  {
    public:
      TestfileProduct();

    private:
      std::string dependencies;
      std::string test_class;
      std::vector<std::string> valid_testcases;
  };
}

#endif // TESTFILEPRODUCT_HPP_
