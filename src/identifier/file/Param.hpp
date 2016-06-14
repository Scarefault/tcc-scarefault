#ifndef PARAM_HPP_
#define PARAM_HPP_

#include <utility>
#include <string>

namespace Collector
{
  class Param
  {
    public:
      std::string name;
      std::string type;
      std::pair<int, int> range;
  };
}

#endif // PARAM_HPP_
