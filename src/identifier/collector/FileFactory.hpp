#ifndef FILEFACTORY_HPP_
#define FILEFACTORY_HPP_


#include "FileBase.hpp"
#include "Language.hpp"

namespace Collector
{
  class FileFactory
  {
    public:
      FileBase * get_data_file( Collector::Language );
  };
}

#endif // FILEFACTORY_HPP_
