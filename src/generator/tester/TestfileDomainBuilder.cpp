#include <iomanip>
#include <vector>
#include <iostream>


#include "TestfileDomainBuilder.hpp"
#include "../../helper/Helper.hpp"


namespace Tester
{
  TestfileDomainBuilder::TestfileDomainBuilder( Collector::FileMVC * data )
  {
    this->data_ptr = data;
    this->value_generator = new Generator::ValueGenerator();
    this->testfile = new Tester::TestfileProduct();
  }

  std::string TestfileDomainBuilder::build_package()
  {
    std::stringstream stream;

    stream << "package " << data_ptr->package
           << std::endl
           << std::endl;

    return stream.str();
  }

  std::string TestfileDomainBuilder::build_imports()
  {
    std::stringstream stream;

    stream << "import grails.test.*"
           << std::endl
           << std::endl;

    return stream.str();
  }

  void TestfileDomainBuilder::build_test_class()
  {
    std::stringstream stream;

    stream << "class " << data_ptr->class_name << "Tests "
           << "extends GrailsUnitTestCase {"
           << std::endl
           << std::endl;

    this->testfile->set_test_class( stream.str() );
  }

  void TestfileDomainBuilder::build_setup()
  {
    std::stringstream stream;
    std::string obj = Helper::convert_to_lower( data_ptr->class_name );
    std::string values( "(" );
    for( int i = 0; i < data_ptr->proprieties.size(); i++ )
    {
      std::cout << "AQUI" << "\n";
      values.append( data_ptr->proprieties[ i ].name );
      values.append( ": " );
      values.append( value_generator->generate_random_value( data_ptr->proprieties[ i ].type ) );
      if( data_ptr->proprieties.size()-1 != i )
      {
        values.append( ", " );
      } else
      {
        values.append( ")" );
      }
    }

    stream << "  def " << obj << std::endl
           << std::endl
           << "  protected void setUp() {" << std::endl
           << "    super.setUp()" << std::endl
           << "    " << obj << " = new " << data_ptr->class_name << values << std::endl
           << "  }" << std::endl
           << std::endl;

    this->testfile->set_setup( stream.str() );
  }

  void TestfileDomainBuilder::build_valid_testcases()
  {
    std::string obj = Helper::convert_to_lower( data_ptr->class_name );
    std::stringstream stream;
    std::vector<std::string> valid_testcases;

    for( int i = 0; i < data_ptr->methods.size(); i++ )
    {
      for( int j = 0; j < data_ptr->methods[ i ].test_cases.size(); j++ )
      {
        stream << "  void testMethodName() {"
               << std::endl
               << "    def expect = "
               << (* data_ptr->methods[ i ].test_cases[ j ].get_expected_result() )
               << std::endl
               << "    def result = "
               << obj << "."
               << (* data_ptr->methods[ i ].test_cases[ j ].get_bound_method() )
               << "(";

        for( int k = 0; k < data_ptr->methods[ i ].test_cases[ j ].get_arguments()->size(); k++ )
        {
          stream << data_ptr->methods[ i ].test_cases[ j ].get_argument( k )->value;

          if( k < data_ptr->methods[ i ].test_cases[ j ].get_arguments()->size()-1 )
          {
            stream << ", ";
          } else
          {
            stream << ")" << std::endl << std::endl;
          }
        }

        stream << "    assertEquals expect, result"
               << std::endl
               << "  }" << std::endl << std::endl;

        valid_testcases.push_back( stream.str() );
        stream.clear();
        stream.str( std::string() );
      }
    }

    this->testfile->set_valid_testcases( valid_testcases );
  }
}
