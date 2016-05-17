#include "CollectorData.hpp"

namespace Helper
{
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
      data_stream.write( "[package:", 9 );
      data_stream.write( get_package_name().c_str(), get_package_name().size() );
      data_stream.write( "[class:", 7 );
      data_stream.write( get_class_name().c_str(), get_class_name().size() );
      data_stream.write( "]]\n", 4 );
    } else
    {
      std::cout << "Unable to open datafile.dat..." << std::endl;
    }

    data_stream.close();
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
