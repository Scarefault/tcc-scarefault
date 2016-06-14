#ifndef PROPRIETY_HPP_
#define PROPRIETY_HPP_

#include <vector>
#include <string>

#include "Constraint.hpp"

namespace Collector
{
  class Propriety
  {
    public:
      std::string name;
      std::string type;
      std::vector<Constraint> contraints;
  };
}

#endif // PROPRIETY_HPP_
