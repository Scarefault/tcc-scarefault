#ifndef TESTFILECONTROLLERBUILDER_HPP_
#define TESTFILECONTROLLERBUILDER_HPP_


#include <sstream>


#include "TestfileGrailsBuilder.hpp"
#include "../../helper/Helper.hpp"


namespace Tester
{
  class TestfileControllerBuilder : public TestfileGrailsBuilder
  {
    public:
      TestfileControllerBuilder( Collector::FileMVC * );

      void build_test_class();
      void build_valid_testcases();

    protected:
      std::string build_package();
      std::string build_imports();


      std::string build_valid_setup();

      std::string build_index();
      std::string build_create();
      std::string build_show();
      std::string build_delete();
      std::string build_list();
      std::string build_save();
      std::string build_edit();
      std::string build_update();
  };
}

#endif // TESTFILECONTROLLERBUILDER_HPP_
