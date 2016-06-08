#ifndef METHOD_HPP_
#define METHOD_HPP_

#include <vector>
#include <string>

#include "Param.hpp"
#include "../../generator/testcase/TestCaseBase.hpp"

namespace Collector
{
  class Method
  {
    public:
      std::string name;
      std::string return_type;
      std::vector<Param> params;
      std::vector<Tester::TestCaseBase> test_cases;
  };
}

#endif // METHOD_HPP_
