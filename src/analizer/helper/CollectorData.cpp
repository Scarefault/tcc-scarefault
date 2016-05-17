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

  void CollectorData::record_data()
  {
    std::fstream data_stream;

    data_stream.open( DATAFILE, WRITE|APPEND );

    if( data_stream.is_open() )
    {
      insert_data();

      while( !data.empty() )
      {
        std::string current_data = data.front();
        data_stream.write( current_data.c_str(), current_data.size() );
        data.pop();
      }

    } else
    {
      std::cout << "Unable to open datafile.dat..." << std::endl;
    }

    data_stream.close();
  }

// ------------------ PRIVATE FUNCTIONS IMPLEMENTANTION --------------------

  void CollectorData::insert_data()
  {
    insert_data_package();
    insert_data_class();
    conclude_data();
  }
  void CollectorData::insert_data_package()
  {
    data.push( "[package: " );
    data.push( this->get_package_name() );
  }

  void CollectorData::insert_data_class()
  {
    data.push( "[class: " );
    data.push( this->get_class_name() );
  }

  void CollectorData::conclude_data()
  {
    data.push( "]]\n" );
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
