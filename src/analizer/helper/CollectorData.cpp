#include "CollectorData.hpp"

namespace Helper
{
  void CollectorData::collect_data( const char * format, ... )
  {
    // TODO: all tasks to collect and record the data in data file.
  }

  std::string CollectorData::get_method_name()
  {
    return this->method_name;
  }

  std::map<std::string, CollectorData::ParamInfo> CollectorData::get_params()
  {
    return this->params;
  } 

  void CollectorData::set_method_name( std::string name )
  {
    this->method_name = name;
  }

  void CollectorData::set_params( std::map<std::string, CollectorData::ParamInfo> param_list )
  {
    this->params = param_list;
  }
}
