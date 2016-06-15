#ifndef FILEBASE_HPP_
#define FILEBASE_HPP_

#include <vector>
#include <string>


#include "Method.hpp"
#include "Propriety.hpp"


namespace Collector
{
  class FileBase
  {
    public:
      std::string class_name;
      std::vector<Method> methods;
      std::string layer;
      std::string model_base;
      std::string package;
      std::vector<Propriety> proprieties;

      void insert_method( Collector::Method );
      void set_class( std::string );
      void set_package( std::string );
  };
}

#endif // FILEBASE_HPP_
