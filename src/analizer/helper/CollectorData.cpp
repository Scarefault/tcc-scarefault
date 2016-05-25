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

    std::vector<std::string> info_method;

    while( *format != EOL )
    {
      std::string collected_text;

      switch( *format )
      {
        case PACKAGE:
          this->set_package( va_arg( arguments, char * ) );
          break;
        case CLASS:
          this->set_class( va_arg( arguments, char * ) );
          break;
        case METHOD:
          collected_text.assign( va_arg( arguments, char * ) );
          info_method.push_back( collected_text );
          break;
        case PARAM:
          collected_text.assign( va_arg( arguments, char * ) );
          info_method.push_back( collected_text );
          break;
      }

      format++;
    }

    this->set_methods( info_method );
  }

  Helper::Data* CollectorData::get_data()
  {
    return &data;
  }

// ------------------ PRIVATE FUNCTIONS IMPLEMENTANTION --------------------

  void CollectorData::set_package( std::string name )
  {
    this->data.package_name = name;
  }

  void CollectorData::set_class( std::string name )
  {
    this->data.class_name = name;

    identify_category( name );
  }

  void CollectorData::set_methods( std::vector<std::string> info )
  {
    if( !info.empty() )
    {
      Helper::Method method;
      method.name = info[ 0 ];

      this->data.methods.push_back( method );
    } else
    {
      // Nothing To do
    }
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

  std::string CollectorData::get_package()
  {
    return this->data.package_name;
  }

  std::string CollectorData::get_class()
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
