#include "CollectorData.hpp"

namespace Helper
{
  void CollectorData::set_package_name( std::string name )
  {
    this->input.package_name = name;
  }

  void CollectorData::set_class_name( std::string name )
  {
    this->input.class_name = name;
  }

  std::string CollectorData::get_package_name()
  {
    return this->input.package_name;
  }

  std::string CollectorData::get_class_name()
  {
    return this->input.class_name;
  }
}
