#ifndef TESTFILECONTROLLERBUILDER_HPP_
#define TESTFILECONTROLLERBUILDER_HPP_


#include <sstream>


#include "TestfileGrailsBuilder.hpp"


namespace Tester
{
  class TestfileControlllerBuilder : public TestfileGrailsBuilder
  {
    public:
      TestfileControlllerBuilder( Collector::FileMVC * );

      void build_test_class();
      void build_valid_testcases();

    protected:
      std::string build_package();
      std::string build_imports();


      void build_valid_setup();

      void build_index();
      void build_create();
      void build_show();
      void build_delete();
      void build_list();
      void build_save();
      void build_edit();
      void build_update();
  };
}

#endif // TESTFILECONTROLLERBUILDER_HPP_
