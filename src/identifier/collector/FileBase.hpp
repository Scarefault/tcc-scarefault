#ifndef FILEBASE_HPP_
#define FILEBASE_HPP_

#include <vector>
#include <utility>
#include <string>

namespace Collector
{
  class Param
  {
    public:
      std::string param_name;
      std::string param_type;
      std::pair<int, int> range;
  };

  class Method
  {
    public:
      std::string name;
      std::string return_type;
      std::vector<Param> params;
  };

  class FileBase
  {
    public:
      std::string class_name;

      std::vector<Method> methods;
  };
}

#endif // FILEBASE_HPP_
