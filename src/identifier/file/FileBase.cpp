#include "FileBase.hpp"


namespace Collector {
  void FileBase::insert_method( Collector::Method method )
  {
    this->methods.push_back( method );
  }

  void FileBase::set_class( std::string name )
  {
    this->class_name = name;
  }

  void FileBase::set_package( std::string name )
  {
    this->package = name;
  }
}
