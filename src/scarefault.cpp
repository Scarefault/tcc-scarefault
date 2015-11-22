#include "analizer/parser/Parser.h"
#include "generator/TestGenerator.hpp"

int main( int argc, char **argv )
{
  Parser parser;
  parser.parse();

  Generator::TestGenerator* test_generator_ptr;
  test_generator_ptr = Generator::addresses_test_generators.at( 0 );

  cout << test_generator_ptr->get_scenario_name() << endl;
}
