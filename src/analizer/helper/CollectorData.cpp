#include "CollectorData.hpp"

namespace Helper
{
  void CollectorData::collect_data( const char * format, ... )
  {
    va_list arguments;
    va_start( arguments, format );

    while( *format != '\0' )
    {
      switch ( *format )
      {
        case 'm':
          std::string name = va_args( arguments, std::string );
          this->set_method_name( name );
          this->std::cout << get_method_name() << std::endl;
          break;
        case 'p':
          break;
        case 't':
          break;
        case 'r':
          break;
        default:
      }

      format++;
    }
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
