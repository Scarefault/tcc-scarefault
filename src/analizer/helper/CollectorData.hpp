#ifndef COLLECTORDATA_HPP_
#define COOLECTORDATA_HPP_

#include <string>
#include <cstdarg>
#include <iostream>
#include <vector>
#include <locale>
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
      static const char METHOD = 'm';

      Helper::Data data;

      void set_package_name( std::string );
      void set_class_name( std::string );
      void set_method_name( std::string );

      void identify_category( std::string );

      std::string get_package_name();
      std::string get_class_name();
      std::vector<Helper::Method> get_methods();

      std::string get_category_MVC();
      std::string get_domain_base();
  };
}

#endif // COLLECTORDATA_HPP_
