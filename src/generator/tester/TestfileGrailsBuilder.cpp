#include "TestfileGrailsBuilder.hpp"

namespace Tester
{
  void TestfileGrailsBuilder::build_dependencies()
  {
    std::stringstream stream;
    stream << this->build_package() << this->build_imports();
    this->testfile->set_dependencies( stream.str() );
  }
}
