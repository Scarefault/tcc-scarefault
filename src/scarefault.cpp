#include <iostream>
#include <fstream>
#include <cstring>


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
  if( argc == 3 )
  {
    cout << "Tem 3 argumentos" << endl;
    std::ifstream target;
    target.open( argv[ 1 ], std::fstream::in );

    if( target.is_open() )
    {
      cout << "Abriu o target" << endl;
      if( !strcmp( argv[ 2 ], "generate" ) )
      {
        cout << "Opção 'generate'" << endl;
        srand( time( NULL ) );

        std::istream& stream = target;

        Parser parser( GRAILS, stream );
        cout << "instanciou o parser" << endl;
        parser.parse();
        cout << "fez o parser" << endl;

        CollectorBase * collector_ptr = address_collector;

        TesterDirector tester( new TestfileDomainBuilder( collector_ptr->get_data() ) );
        tester.generate_testfile();

        Writer writer( &tester );
        writer.write_testfile();
        target.close();
      } else
      {
        cout << "Option " << argv[ 2 ] << " is invalid..." << endl;
      }
    } else
    {
      cout << "Unable to open " << argv[ 1 ] << endl;
    }
  } else
  {
    cout << "Number of options is invalid..." << endl;
  }
}
