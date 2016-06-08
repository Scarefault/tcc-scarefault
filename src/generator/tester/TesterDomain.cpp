#include "TesterDomain.hpp"

namespace Tester
{
  TesterDomain::TesterDomain( Collector::FileMVC * ptr_data )
  {
    this->set_data( ptr_data );
  }

  void TesterDomain::write_data()
  {
    std::fstream test_stream;

    test_stream.open( TESTFILE, WRITE|APPEND );

    if( test_stream.is_open() )
    {
      make_header( &test_stream );
      test_methods( &test_stream );
      TesterBase::conclude_data( &test_stream );

      test_stream.close();
    } else
    {
      std::cout << "Unable to open TESTFILE..." << std::endl;
    }
  }

  void TesterDomain::make_header( std::fstream * test_stream )
  {
    (* test_stream) << "package " << data_ptr->package
                    << std::endl
                    << std::endl
                    << "import org.junit.*"
                    << std::endl
                    << "import grails.test.mixin.*"
                    << std::endl
                    << std::endl
                    << "@TestFor(" << data_ptr->class_name << ")"
                    << std::endl
                    << "class " << data_ptr->class_name << "Tests {"
                    << std::endl
                    << std::endl;
  }

  void TesterDomain::test_methods( std::fstream * test_stream )
  {
    this->print_result(); // TODO: temporary
  }

  // TODO: temporary
  void TesterDomain::print_result()
  {
    std::cout << "Package: " << data_ptr->package << "\n";
    std::cout << "Class: " << data_ptr->class_name << "\n";
    std::cout << "Domain: " << data_ptr->model_base << "\n";
    std::cout << "Category: " << data_ptr->layer << "\n";
    std::cout << "Qtd methods: " << data_ptr->methods.size() << "\n";
    std::cout << "Qtd proprieties: " << data_ptr->proprieties.size() << "\n";
    std::cout << std::endl
              << "Methods: " << std::endl;
    for( int i = 0; i < data_ptr->methods.size(); ++i )
    {
      std::cout << "\t[ " << i+1 << " ]: " << std::endl
                << "\tName: " << data_ptr->methods[ i ].name << std::endl
                << "\tReturn type: " << data_ptr->methods[ i ].return_type << std::endl
                << "\t\tParams:" << std::endl;
      for ( int j = 0; j < data_ptr->methods[ i ].params.size(); ++j )
      {
        std::cout << "\t\t\t[ " << j+1 << " ]: " << std::endl
                  << "\t\t\tName: " << data_ptr->methods[ i ].params[ j ].name << std::endl
                  << "\t\t\tType: " << data_ptr->methods[ i ].params[ j ].type << std::endl
                  << "\t\t\tRange Min: " << data_ptr->methods[ i ].params[ j ].range.first << std::endl
                  << "\t\t\tRange Max: " << data_ptr->methods[ i ].params[ j ].range.second << std::endl
                  << std::endl;
      }

      std::cout << "\t\tTest Cases: " << "\n";
      for( int j = 0; j < data_ptr->methods[i].test_cases.size(); j++ )
      {
        std::cout << "\t\t\t[ " << j+1 << " ]:" << "\n"
                  << "\t\t\tBound Method: " << data_ptr->methods[ i ].test_cases[ j ].get_bound_method()
                  << std::endl
                  << "\t\t\tExpected Result: " << data_ptr->methods[ i ].test_cases[ j ].get_expected_result()
                  << std::endl
                  << "\t\t\tArguments: " << std::endl;
        for( int k = 0; k < data_ptr->methods[ i ].test_cases[ j ].get_arguments()->size(); k++ )
        {
          std::cout << "\t\t\t\tArg[ " << k+1 << " ]:" << "\n"
                    << "\t\t\t\tBound Param: " << data_ptr->methods[ i ].test_cases[ j ].get_argument(k)->bound_param
                    << std::endl
                    << "\t\t\t\tValue: " << data_ptr->methods[ i ].test_cases[ j ].get_argument(k)->value
                    << std::endl;
        }
      }
    }
  }
}
