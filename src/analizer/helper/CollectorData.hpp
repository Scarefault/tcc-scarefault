#ifndef COLLECTORDATA_HPP_
#define COOLECTORDATA_HPP_

#include <string>
#include <cstdarg>
#include <iostream>
#include <vector>
#include "Data.hpp"

namespace Helper
{
  class CollectorData
  {

    public:
      void collect_data( const char *, ... );
      Helper::Data* get_data();

    private:
      static const char EOL = '\0';
      static const char PACKAGE = 'p';
      static const char CLASS = 'c';

      Helper::Data data;

      void set_package_name( std::string );
      void set_class_name( std::string );

      std::string get_package_name();
      std::string get_class_name();
  };
}

#endif // COLLECTORDATA_HPP_
