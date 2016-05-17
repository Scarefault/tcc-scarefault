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

  void SpreaderData::write_data()
  {
    std::fstream test_stream;

    test_stream.open( TESTFILE, WRITE|APPEND );

    if( test_stream.is_open() )
    {
      test_stream << "package " << output.package_name << std::endl
                  << std::endl
                  << "import org.junit.*" << std::endl
                  << "import grails.test.mixin.*" << std::endl
                  << std::endl
                  << "@TestFor(" << output.class_name << ")" << std::endl
                  << "class " << output.class_name << "Tests" << std::endl;
    } else
    {
      std::cout << "Unable to open TESTFILE..." << std::endl;
    }
  } 
}
