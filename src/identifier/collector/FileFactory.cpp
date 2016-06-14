#include "FileFactory.hpp"
#include "FileGrails.hpp"

namespace Collector
{
  FileBase * FileFactory::get_data_file( Collector::Language language )
  {
    FileBase * instance;

    switch( language )
    {
      case GRAILS:
        instance = new FileGrails();
        break;
    }

    return instance;
  }
}
