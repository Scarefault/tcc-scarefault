#include "CollectorFactory.hpp"


namespace Collector
{
  CollectorBase * CollectorFactory::get_collector( Collector::Language language )
  {
    CollectorBase * instance;

    switch( language )
    {
      case GRAILS:
        instance = new CollectorGrails();
        break;
    }

    return instance;
  }
}
