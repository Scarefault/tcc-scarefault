#include "FileBase.hpp"
#include "FileGrails.hpp"

namespace Collector {
  FileBase * FileBase::get_data_file( Collector::Language language )
  {
    FileBase * instance;

    switch ( language )
    {
      case GRAILS:
        instance = new FileGrails();
        break;
    }

    return instance;
  }

  void FileBase::insert_method( Collector::Method method )
  {
    this->methods.push_back( method );
  }
}
