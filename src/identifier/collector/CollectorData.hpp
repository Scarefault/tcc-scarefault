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
#include "CollectorScarefault.hpp"
#include "../../helper/Helper.hpp"

namespace Collector
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
      Collector::Data* get_data();
      Collector::CollectorScarefault collector_scarefault;

    private:
      static const char EOL = '\0';
      static const char PACKAGE = 'P';
      static const char CLASS = 'c';
      static const char METHOD = 'm';
      static const char PARAM = 'p';


      Collector::Data data;


      void set_package( std::string );
      void set_class( std::string );
      void set_methods( std::vector<std::string> );

      void collect_proprieties( std::string );
      std::vector<Collector::Param> collect_params( std::vector<std::string> );
      void collect_constraints( std::string );

      void identify_category( std::string );
      Collector::Param find_param( std::string );
      Collector::Param create_param( std::string * );
      void set_params_range( Collector::Method * );

      std::string extract_content_file( std::fstream * );
      std::string extract_content_file( std::string );
      std::vector<std::string> extract_words( std::string, std::string );
  };
}

#endif // COLLECTORDATA_HPP_
