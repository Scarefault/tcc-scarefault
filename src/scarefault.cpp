#include "analizer/parser/Parser.h"
#include "generator/Tester.hpp"

using namespace Helper;

int main( int argc, char **argv )
{
  Parser parser;
  parser.parse();

  Tester * tester_ptr = address_spreader;
  tester_ptr->write_data();
}
