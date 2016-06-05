#include "FileBase.hpp"

namespace Collector {
  void FileBase::insert_method( Collector::Method method )
  {
    this->methods.push_back( method );
  }
}
