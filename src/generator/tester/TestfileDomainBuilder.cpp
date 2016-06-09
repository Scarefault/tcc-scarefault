#include "TestfileDomainBuilder.hpp"

namespace Tester
{
  TestfileDomainBuilder::TestfileDomainBuilder( Collector::FileMVC * data )
  {
    this->data_ptr = data;
    this->value_generator = new Generator::ValueGenerator();
  }

  void TestfileDomainBuilder::build_package()
  {
    std::stringstream stream;

    stream << "package " << data_ptr->package
           << std::endl
           << std::endl;
  }

  void TestfileDomainBuilder::build_imports()
  {
    std::stringstream stream;

    stream << "import grails.test.*"
           << std::endl
           << std::endl;
  }

  void TestfileDomainBuilder::build_test_class()
  {
    std::stringstream stream;

    stream << "class " << data_ptr->class_name << "Tests "
           << "extends GrailsUnitTestCase {"
           << std::endl
           << std::endl;
  }

  void TestfileDomainBuilder::build_valid_testcases()
  {
  }
}
