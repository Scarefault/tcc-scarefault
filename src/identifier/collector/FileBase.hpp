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
      std::string name;
      std::string type;
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

      void insert_method( Collector::Method );
      void set_class( std::string );
  };
}

#endif // FILEBASE_HPP_
