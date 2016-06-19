#include "TesterAnalizer.hpp"
#include <iostream>


namespace Tester
{
  TesterAnalizer::TesterAnalizer( Collector::FileMVC * data )
  {
    this->data = data;
  }

  void TesterAnalizer::create_testcases( std::fstream * stream, std::string name )
  {
    std::string line;
    std::string new_name( name );
    new_name.append( ".temp" );

    std::fstream new_source( new_name, WRITE|APPEND );

    if( new_source.is_open() )
    {
      while( std::getline( (* stream ), line ) )
      {
        if( line.find( "*/" ) != std::string::npos )
        {
          line.pop_back();
          line.pop_back();
        }

        if( line.find( data->methods[ 0 ].name ) != std::string::npos )
        {
          long found = new_source.tellp();
          new_source.seekp( found-10 );

          new_source << "\t\tINSIRA OS TESTCASES AQUI" << std::endl << "\t*/" << std::endl;
        }

        new_source << line << std::endl;
      }

      new_source.close();
    }

    std::remove( name.c_str() );
    std::rename( new_name.c_str(), name.c_str() );
  }
}
