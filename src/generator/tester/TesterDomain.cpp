#include "TesterDomain.hpp"

namespace Tester
{
  TesterDomain::TesterDomain( Helper::Data * ptr_data )
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
    (* test_stream) << "package " << data_ptr->package_name
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
    std::cout << "Package: " << data_ptr->package_name << "\n";
    std::cout << "Class: " << data_ptr->class_name << "\n";
    std::cout << "Domain: " << data_ptr->domain_base << "\n";
    std::cout << "Category: " << data_ptr->category_MVC << "\n";
    std::cout << "Qtd methods: " << data_ptr->methods.size() << "\n";
    std::cout << "Qtd proprieties: " << data_ptr->proprieties.size() << "\n";
    std::cout << std::endl
              << "Methods: " << std::endl;
    for( int i = 0; i < data_ptr->methods.size(); ++i )
    {
      std::cout << "[ " << i+1 << " ]: " << std::endl
                << "Name: " << data_ptr->methods[ i ].name << std::endl
                << "Return type: " << data_ptr->methods[ i ].return_type << std::endl
                << "Params:" << std::endl;
      for ( int j = 0; j < data_ptr->methods[ i ].params.size(); ++j )
      {
        std::cout << "[ " << j+1 << " ]: " << std::endl
                  << "Name: " << data_ptr->methods[ i ].params[ j ].param_name << std::endl
                  << "Type: " << data_ptr->methods[ i ].params[ j ].param_type << std::endl
                  << "Range Min: " << data_ptr->methods[ i ].params[ j ].range.first << std::endl
                  << "Range Max: " << data_ptr->methods[ i ].params[ j ].range.second << std::endl
                  << std::endl;
      }
    }
  }
}
