#ifndef FILEBASE_HPP_
#define FILEBASE_HPP_

#include <vector>
#include <utility>
#include <string>

namespace Collector
{
  class Constraint
  {
    public:
      std::string name;
      std::string value;
  };

  class Propriety
  {
    public:
      std::string name;
      std::string type;
      std::vector<Constraint> contraints;
  };

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
      std::string category_MVC;
      std::string domain_base;
      std::string package_name;
      std::string class_name;

      std::vector<Propriety> proprieties;
      std::vector<Method> methods;
  };
}

#endif // FILEBASE_HPP_
