#include "CollectorData.hpp"

namespace Helper
{
// ------------------ PUBLIC FUNCTIONS IMPLEMENTATION -------------------

  void CollectorData::collect_data( const char * format, ... )
  {
    va_list arguments;
    va_start( arguments, format );

    while( *format != EOL )
    {
      switch( *format )
      {
        case PACKAGE:
          this->set_package_name( va_arg( arguments, char * ) );
          break;
        case CLASS:
          this->set_class_name( va_arg( arguments, char * ) );
          break;
      }

      format++;
    }
  }

// ------------------ PRIVATE FUNCTIONS IMPLEMENTANTION --------------------

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
