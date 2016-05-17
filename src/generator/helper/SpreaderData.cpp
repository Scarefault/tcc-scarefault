#include "SpreaderData.hpp"

namespace Helper
{
  ADDRESS address_spreader;
 
  SpreaderData::SpreaderData()
  {
    address_spreader = this;
  }


  void SpreaderData::write_data()
  {


    std::fstream test_stream;

    test_stream.open( TESTFILE, WRITE|APPEND );

    if( test_stream.is_open() )
    {
      test_stream << "package " << data_ptr->package_name << std::endl
                  << std::endl
                  << "import org.junit.*" << std::endl
                  << "import grails.test.mixin.*" << std::endl
                  << std::endl
                  << "@TestFor(" << data_ptr->class_name << ")" << std::endl
                  << "class " << data_ptr->class_name << "Tests" << std::endl;
    } else
    {
      std::cout << "Unable to open TESTFILE..." << std::endl;
    }
  }

  void SpreaderData::set_Data( Helper::Data * ptr )
  {
      this->data_ptr = ptr;
  }
}