#ifndef COLLECTORDATA_HPP_
#define COLLECTORDATA_HPP_

#define READ std::fstream::in

#define PATH_CONTROLLER "guestbook/grails-app/controllers/guestbook/"
#define PATH_DOMAIN "guestbook/grails-app/domain/guestbook/"

#include <string>
#include <cstring>
#include <cstdarg>
#include <iostream>
#include <fstream>
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

      void set_package( std::string );
      void set_class( std::string );
      void set_methods( std::vector<std::string> );

      void collect_proprieties( std::string );
      void identify_category( std::string );
      std::vector<Helper::Param> collect_params( std::vector<std::string> );
      Helper::Param find_param( std::string );
      Helper::Param create_param( std::string * );

      std::string extract_content_file( std::fstream * );
      char * convert_string_to_cstring( std::string );
      std::vector<std::string> extract_words( std::string, std::string );
      bool is_type( std::string );
      void collect_constraints( std::string );
  };
}

#endif // COLLECTORDATA_HPP_
