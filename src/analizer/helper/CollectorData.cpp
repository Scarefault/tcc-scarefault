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

      method.params = collect_params( info );

      this->data.methods.push_back( method );
    } else
    {
      // Nothing To do
    }
  }

  std::vector<Helper::Param>
  CollectorData::collect_params( std::vector<std::string> info )
  {
    std::vector<Helper::Param> params;

    if( info.size() > 1 )
    {
      std::string collected_params = info[ 1 ];

      while( !collected_params.empty() )
      {
        Helper::Param new_param = create_param( &collected_params );
        params.push_back( new_param );
      }
    } else
    {
      // Nothing To do
    }

    return params;
  }

  Helper::Param CollectorData::create_param( std::string * text )
  {
    std::size_t comma_position = text->find( "," );

    Helper::Param new_param;

    if( comma_position != std::string::npos )
    {
      std::string found_param = text->substr( 0, comma_position );

      new_param = find_param( found_param );

      text->erase( text->begin(), text->begin()+comma_position+1 );
    } else
    {
      new_param = find_param( *text );

      text->clear();
    }

    return new_param;
  }

  Helper::Param CollectorData::find_param( std::string text )
  {
    std::size_t blank_position = text.find( " " );
    std::string type = text.substr( 0, blank_position );
    std::string name = text.substr( blank_position+1 );

    Helper::Param new_param;

    new_param.param_name = name;
    new_param.param_type = type;

    return new_param;
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
}
