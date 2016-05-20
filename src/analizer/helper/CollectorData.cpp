#include "CollectorData.hpp"

namespace Helper
{
  ADDRESS address_collector;

// ------------------ PUBLIC FUNCTIONS IMPLEMENTATION -------------------
  CollectorData::CollectorData()
  {
    address_collector = this;
  }

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
        case METHOD:
          this->set_method_name( va_arg( arguments, char * ) );
          break;
      }

      format++;
    }
  }

  Helper::Data* CollectorData::get_data()
  {
    return &data;
  }

// ------------------ PRIVATE FUNCTIONS IMPLEMENTANTION --------------------

  void CollectorData::set_package_name( std::string name )
  {
    this->data.package_name = name;
  }

  void CollectorData::set_class_name( std::string name )
  {
    this->data.class_name = name;

    identify_category( name );
  }

  void CollectorData::set_method_name( std::string name )
  {
    Helper::Method method;
    method.name = name;

    this->data.methods.push_back( method );
  }

  void CollectorData::identify_category( std::string name )
  {
    if( name.compare( "Controller" ) != std::string::npos )
    {
      std::size_t found = name.find( "Controller" );
      std::string category = name.substr( found );
      std::string domain_base = name.substr( 0, found );

      this->data.domain_base = domain_base;
      this->data.category_MVC = category;
    } else
    {
      // Nothing to do
    }
  }

  std::string CollectorData::get_package_name()
  {
    return this->data.package_name;
  }

  std::string CollectorData::get_class_name()
  {
    return this->data.class_name;
  }

  std::vector<Helper::Method> CollectorData::get_methods()
  {
    return this->data.methods;
  }

  std::string CollectorData::get_category_MVC()
  {
    return this->data.category_MVC;
  }

  std::string CollectorData::get_domain_base()
  {
    return this->data.domain_base;
  }
}
