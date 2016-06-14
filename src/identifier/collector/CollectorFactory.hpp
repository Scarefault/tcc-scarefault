#ifndef COLLECTORFACORY_HPP_
#define COLLECTORFACORY_HPP_


#include "Language.hpp"
#include "CollectorGrails.hpp"


namespace Collector
{
  class CollectorFactory
  {
    public:
      CollectorBase * get_collector( Collector::Language );
  };
}

#endif // COLLECTORFACORY_HPP_
