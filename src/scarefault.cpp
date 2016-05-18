#include "analizer/parser/Parser.h"
#include "generator/helper/SpreaderData.hpp"

using namespace Helper;

int main( int argc, char **argv )
{
  Parser parser;
  parser.parse();

  SpreaderData * spreader_ptr = address_spreader;
  spreader_ptr->write_data();
  spreader_ptr->write_test_create();
}
