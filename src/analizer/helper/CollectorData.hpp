#ifndef COLLECTORDATA_HPP_
#define COLLECTORDATA_HPP_

#include <string>
#include <cstdarg>
#include <iostream>
#include <vector>
#include <locale>
#include "Data.hpp"

namespace Helper
{
  class CollectorData;


  /*
   * Define a new type to keep a reference to the address of the
   *   CollectorData.
   */
  typedef CollectorData * ADDRESS;

  /*
   * It's a global variable. Currently, it's necessary to allow access the
   *   reference of CollectorData. With this, Is possible access a
   *   CollectorData, created in parser file, in other files.
   */
  extern ADDRESS address_collector;


  class CollectorData
  {

    public:
      CollectorData();

      void collect_data( const char *, ... );
      Helper::Data* get_data();

    private:
      static const char EOL = '\0';
      static const char PACKAGE = 'P';
      static const char CLASS = 'c';
      static const char METHOD = 'm';
      static const char PARAM = 'p';

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
