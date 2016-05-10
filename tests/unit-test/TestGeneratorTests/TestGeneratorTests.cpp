#include "../catch.hpp"
#include "../../../src/generator/TestGenerator.hpp"

TEST_CASE( "Infomations can be captured", "[TestGenerator]" )
{
  Generator::TestGenerator test_generator;

  std::string first_package = "br.com.xcompany.domain";
  std::string second_package = "br.com.xcompany.controller";
 
  SECTION( "Captured package name and show it" )
  {
    test_generator.set_package_name( first_package );

    CHECK( test_generator.get_package_name() == first_package );
  }

  SECTION( "Captured importation and show it" )
  {
    SECTION( "When there is only one importation" )
    {
      test_generator.add_import_name( second_package );
      
      CHECK( test_generator.get_import_names().at( 0 ) == second_package );
    }

    SECTION( "When there are many importations" )
    {
      test_generator.add_import_name( first_package );
      test_generator.add_import_name( second_package );

      std::vector<std::string> importations;
      importations.push_back( first_package );
      importations.push_back( second_package );

      CHECK( test_generator.get_import_names() == importations );
    }
  }
}
