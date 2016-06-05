#ifndef METHOD_HPP_
#define METHOD_HPP_

#include <vector>
#include <string>

#include "Param.hpp"

namespace Collector
{
  class Method
  {
    public:
      std::string name;
      std::string return_type;
      std::vector<Param> params;
  };
}

#endif // METHOD_HPP_
