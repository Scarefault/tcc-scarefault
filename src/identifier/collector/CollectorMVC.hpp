#ifndef COLLECTORMVC_HPP_
#define COLLECTORMVC_HPP_

#include "CollectorBase.hpp"

namespace Collector {
  class CollectorMVC : public CollectorBase
  {
    public:
      CollectorMVC();

      void collect_data( const char *, ... );

      void collect_package( std::string );
      void collect_class( std::string );
      void collect_proprieties( std::string );
      void collect_constraints( std::string );

      void identify_category( std::string );

      std::string extract_content_file( std::string );
      std::vector<std::string> extract_words( std::string, std::string );
  };
}

#endif // COLLECTORMVC_HPP_
