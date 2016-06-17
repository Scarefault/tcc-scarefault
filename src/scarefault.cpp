#include <iostream>
#include <fstream>
#include <cstring>


#define LIMIT_OF_ARGS 3
#define SOURCE_FILE_NAME 1
#define OPTION 2


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
using namespace std;


int main( int argc, char **argv )
{
  if( argc == LIMIT_OF_ARGS )
  {
    std::ifstream target;
    target.open( argv[ SOURCE_FILE_NAME ], std::fstream::in );

    if( target.is_open() )
    {
      srand( time( NULL ) );

      std::istream& stream = target;

      Parser parser( GRAILS, stream );
      parser.parse();

      CollectorBase * collector_ptr = address_collector;

      if( !strcmp( argv[ OPTION ], "generate" ) )
      {
        TesterDirector tester( new TestfileDomainBuilder( collector_ptr->get_data() ) );
        tester.generate_testfile();

        Writer writer( &tester, argv[ SOURCE_FILE_NAME ] );
        writer.write_testfile();
      } else if( !strcmp( argv[ OPTION ], "create" ) )
      {
        Writer writer( argv[ SOURCE_FILE_NAME ] );
        writer.write_testcases();
        cout << "Selected option: " << argv[ OPTION ] << endl;
      } else
      {
        cout << "Option " << argv[ OPTION ] << " is invalid..." << endl;
      }

      target.close();
    } else
    {
      cout << "Unable to open " << argv[ SOURCE_FILE_NAME ] << endl;
    }
  } else
  {
    cout << "Number of options is invalid..." << endl;
  }
}
