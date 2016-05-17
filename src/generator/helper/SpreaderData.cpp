#include "SpreaderData.hpp"

namespace Helper
{
  void SpreaderData::recover_data()
  {
    std::fstream data_stream;

    data_stream.open( DATAFILE, READ );

    if( data_stream.is_open() )
    {
      std::string category;
      std::string value;

      while( data_stream >> category >> value )
      {
        if( !category.compare("package:") )
        {
          output.package_name = value;
        } else if( !category.compare("class:") )
        {
          output.class_name = value;
        }
      }

      std::cout << "output.package: " << output.package_name << std::endl;
      std::cout << "output.class: " << output.class_name << std::endl;

      data_stream.close();
    } else
    {
      std::cout << "Unable to open DATAFILE..." << std::endl;
    }
  }
}
