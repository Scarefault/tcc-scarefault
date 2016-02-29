#include "../catch.hpp"
#include "../../src/generator/TestGenerator.hpp"

TEST_CASE( "Infomations can be captured", "[TestGenerator]" )
{
  Generator::TestGenerator test_generator;

  std::string package_name = "br.com.xcompany.domain";
  std::string import_name = "br.com.xcompany.controller";
 
  SECTION( "Captured package name and show it" )
  {
      test_generator.set_package_name( package_name );

      CHECK( test_generator.get_package_name() == package_name );
   }

  SECTION( "Captured importation and show it" )
  {
    test_generator.set_import_name( import_name );

    CHECK( test_generator.get_import_name() == import_name );
  }
}
