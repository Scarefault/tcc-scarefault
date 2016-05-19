#include "analizer/parser/Parser.h"
#include "generator/tester/TesterBase.hpp"

using namespace Tester;

int main( int argc, char **argv )
{
  Parser parser;
  parser.parse();

  TesterBase * tester_ptr = address_tester;
  tester_ptr->write_data();
}
