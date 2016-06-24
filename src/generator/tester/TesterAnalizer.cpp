#include <iostream>


#include "../../identifier/file/Method.hpp"
#include "TesterAnalizer.hpp"


namespace Tester
{
  TesterAnalizer::TesterAnalizer( Collector::FileMVC * data )
  {
    this->data = data;
  }

  void TesterAnalizer::insert_testcases( std::fstream * stream, std::string name )
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

          std::string testcase = create_testcases( data->methods[ 0 ] );

          new_source << testcase << std::endl;
        }

        new_source << line << std::endl;
      }

      new_source.close();
    }

    std::remove( name.c_str() );
    std::rename( new_name.c_str(), name.c_str() );
  }

  std::string TesterAnalizer::create_testcases( Collector::Method method )
  {
    std::string testcases( "\t\tINSERT TESTCASE HERE\n\t*/" );

    int qtd_params = method.params.size();
    Matrix matrix( qtd_params );
    std::vector<Matrix> conj_testcases( qtd_params, matrix );

    for( int i = 0; i < qtd_params; i++ )
    {
      fill_column_analysis( i, &conj_testcases, method );
      fill_columns_adjacent( i, &conj_testcases, method );
    }

    return testcases;
  }

  void TesterAnalizer::fill_column_analysis( int column, std::vector<Matrix> * conj,
      Collector::Method method )
  {
    std::vector<std::string> values;
    values.push_back( std::to_string( method.params[ column ].range.first ) );
    values.push_back( std::to_string( method.params[ column ].range.first+1 ) );
    values.push_back( std::to_string( method.params[ column ].range.second-1 ) );
    values.push_back( std::to_string( method.params[ column ].range.second ) );

    conj->at( column ).first[ column ] = values[ 0 ];
    conj->at( column ).second[ column ] = values[ 1 ];
    conj->at( column ).third[ column ] = values[ 2 ];
    conj->at( column ).fourth[ column ] = values[ 3 ];
  }

  void TesterAnalizer::fill_columns_adjacent( int column, std::vector<Matrix> *conj,
      Collector::Method method )
  {
    for( int i = 0; i < method.params.size(); i++ )
    {
      if( i != column )
      {
        int min = method.params[ i ].range.first;
        int max = method.params[ i ].range.second;
        int mid = ( min+max )/2;
        std::string value = std::to_string( mid );

        conj->at( column ).first[ i ] = mid;
        conj->at( column ).second[ i ] = mid;
        conj->at( column ).third[ i ] = mid;
        conj->at( column ).fourth[ i ] = mid;
      } else
      {
        continue;
      }
    }
  }
}
