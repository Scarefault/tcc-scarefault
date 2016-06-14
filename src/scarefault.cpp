#include "identifier/parser/Parser.h"
#include "identifier/collector/CollectorBase.hpp"
#include "identifier/collector/Language.hpp"
#include "generator/tester/TesterDirector.hpp"
#include "generator/tester/TestfileDomainBuilder.hpp"
#include "generator/tester/TestfileControllerBuilder.hpp"
#include "generator/tester/TestfileProduct.hpp"
#include "generator/writer/Writer.hpp"


using namespace Collector;
using namespace Tester;


int main( int argc, char **argv )
{
  srand( time( NULL ) );

  Parser parser( GRAILS );
  parser.parse();

  CollectorBase * collector_ptr = address_collector;

  TesterDirector tester( new TestfileDomainBuilder( collector_ptr->get_data() ) );
  tester.generate_testfile();

  Writer writer( &tester );
  writer.write_testfile();
}
