#include "TestfileGrailsBuilder.hpp"

namespace Tester
{
  TestfileGrailsBuilder::build_dependencies()
  {
    this->build_package();
    this->build_imports();
  }
}
