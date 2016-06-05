#ifndef COLLECTORMVC_HPP_
#define COLLECTORMVC_HPP_

#include "CollectorBase.hpp"

namespace Collector {
  class CollectorMVC : public CollectorBase
  {
    public:
      CollectorMVC();

      void collect_data( const char *, ... );

    protected:
      void collect_package( std::string );
      void collect_class( std::string );
      void collect_proprieties( std::string );
      void collect_constraints( std::string );

    private:
      void identify_category( std::string );
  };
}

#endif // COLLECTORMVC_HPP_
