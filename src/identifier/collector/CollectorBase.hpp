#ifndef COLLECTORDATA_HPP_
#define COLLECTORDATA_HPP_


#include <string>
#include <cstring>
#include <cstdarg>
#include <fstream>
#include <vector>


#include "FileMVC.hpp"
#include "CollectorScarefault.hpp"
#include "Language.hpp"

#include "../../helper/Helper.hpp"

namespace Collector
{
  class CollectorBase;


  /*
   * Define a new type to keep a reference to the address of the
   *   CollectorBase.
   */
  typedef CollectorBase * ADDRESS;

  /*
   * It's a global variable. Currently, it's necessary to allow access the
   *   reference of CollectorBase. With this, Is possible access a
   *   CollectorBase, created in parser file, in other files.
   */
  extern ADDRESS address_collector;


  class CollectorBase
  {
    public:
      CollectorBase();

      virtual void collect_data( const char *, ... );
      Collector::FileMVC * get_data();
      Collector::CollectorScarefault collector_scarefault;

    protected:
      static const char EOL = '\0';
      static const char PACKAGE = 'P';
      static const char CLASS = 'c';
      static const char METHOD = 'm';
      static const char PARAM = 'p';

      Collector::FileMVC data;

      virtual void collect_class( std::string );
      void collect_methods( std::vector<std::string> );

    private:

      std::vector<Collector::Param> collect_params( std::vector<std::string> );

      Collector::Param find_param( std::string );
      Collector::Param create_param( std::string * );
      void set_params_range( Collector::Method * );
      void set_test_cases( Collector::Method * );
  };
}

#endif // COLLECTORDATA_HPP_
