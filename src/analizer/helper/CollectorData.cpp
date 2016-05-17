#include "CollectorData.hpp"

namespace Helper
{
  void CollectorData::collect_data( const char * format, ... )
  {
    va_list arguments;
    va_start( arguments, format );

    while( *format != '\0' )
    {
      switch( *format )
      {
        case 'p':
          this->set_package_name( va_arg( arguments, char * ) );
          break;
        case 'c':
          this->set_class_name( va_arg( arguments, char * ) );
          break;
        default:
          std::cout << "Unable to identify format..." << std::endl;
          // Nothing to do
      }

      format++;
    }
  }

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
