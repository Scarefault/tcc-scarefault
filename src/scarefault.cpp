#include "analizer/parser/Parser.h"
#include "generator/TestGenerator.hpp"

int main( int argc, char **argv )
{
  Parser parser;
  parser.parse();

  Generator::TestGenerator* test_generator_ptr;
  test_generator_ptr = Generator::addresses_test_generators.at( 0 );

  std::string method_header( test_generator_ptr->generate_method_header() );
  std::string expectation( test_generator_ptr->generate_expectations() );
  std::string call_method( test_generator_ptr->generate_call_method() );
  std::string assertation( test_generator_ptr->generate_assertation() );

  cout << method_header;
  cout << expectation;
  cout << call_method;
  cout << assertation << endl;
}
