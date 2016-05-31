#ifndef COLLECTOR_SCAREFAULT_HPP_
#define COLLECTOR_SCAREFAULT_HPP_

#include <string>
#include <vector>

#include "Data.hpp"

namespace Collector
{
  class CollectorScarefault
  {
    public:
      void collect_data( const char *, ... );

    private:
      static const char EOL = '\0';
      static const char PARAM = 'p';
      static const char RANGE = 'r';


      std::vector<Helper::Param> params;


      void insert_param( std::string );
      void set_range( std::string );
  };
}

#endif // COLLECTOR_SCAREFAULT_HPP_
