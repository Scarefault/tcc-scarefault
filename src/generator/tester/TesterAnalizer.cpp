#include <iostream>


#include "../../identifier/file/Method.hpp"
#include "../../helper/Helper.hpp"
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

        for( int i = 0; i < data->methods.size(); i++ )
        {
          if( line.find( data->methods[ i ].name ) != std::string::npos )
          {
            long found = new_source.tellp();
            new_source.seekp( found-10 );

            std::string testcase = create_testcases( data->methods[ i ] );

            new_source << testcase << std::endl;
          }
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
    std::string testcases;

    int qtd_params = method.params.size();
    Matrix matrix( qtd_params );
    std::vector<Matrix> conj_testcases( qtd_params, matrix );

    for( int i = 0; i < qtd_params; i++ )
    {
      fill_column_analysis( i, &conj_testcases, method );
      fill_columns_adjacent( i, &conj_testcases, method );
    }

    for( int i = 0; i < qtd_params; i++ )
    {
      std::string cases;
      cases.append( "\t\t@test (" );
      for( int j = 0; j < conj_testcases[ i ].first.size(); j++ )
      {
        if( j != conj_testcases[ i ].first.size()-1 )
        {
          cases.append( conj_testcases[ i ].first[ j ] );
          cases.append( ", " );
        } else
        {
          cases.append( conj_testcases[ i ].first[ j ] );
          cases.append( ") @expect EXPECTATION\n" );
        }
      }
      cases.append( "\t\t@test (" );
      for( int j = 0; j < conj_testcases[ i ].second.size(); j++ )
      {
        if( j != conj_testcases[ i ].second.size()-1 )
        {
          cases.append( conj_testcases[ i ].second[ j ] );
          cases.append( ", " );
        } else
        {
          cases.append( conj_testcases[ i ].second[ j ] );
          cases.append( ") @expect EXPECTATION\n" );
        }
      }
      cases.append( "\t\t@test (" );
      for( int j = 0; j < conj_testcases[ i ].third.size(); j++ )
      {
        if( j != conj_testcases[ i ].third.size()-1 )
        {
          cases.append( conj_testcases[ i ].third[ j ] );
          cases.append( ", " );
        } else
        {
          cases.append( conj_testcases[ i ].third[ j ] );
          cases.append( ") @expect EXPECTATION\n" );
        }
      }
      cases.append( "\t\t@test (" );
      for( int j = 0; j < conj_testcases[ i ].fourth.size(); j++ )
      {
        if( j != conj_testcases[ i ].fourth.size()-1 )
        {
          cases.append( conj_testcases[ i ].fourth[ j ] );
          cases.append( ", " );
        } else
        {
          cases.append( conj_testcases[ i ].fourth[ j ] );
          cases.append( ") @expect EXPECTATION\n" );
        }
      }

      testcases.append( cases );
    }

    testcases.append( "\n\t*/" );

    return testcases;
  }

  void TesterAnalizer::fill_column_analysis( int column, std::vector<Matrix> * conj,
      Collector::Method method )
  {
    std::vector<std::string> values = generate_args( column , method );

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

        std::string value;

        if( Helper::is_integer( method.params[ i ].type ) )
        {
          value = generator.generate_random_integer( min, max );
        } else if( Helper::is_string( method.params[ i ].type ) )
        {
          value = generator.generate_random_string( min, max );
        } else
        {
          // Nothing to do
        }

        conj->at( column ).first[ i ] = value;
        conj->at( column ).second[ i ] = value;
        conj->at( column ).third[ i ] = value;
        conj->at( column ).fourth[ i ] = value;
      } else
      {
        continue;
      }
    }
  }

  std::vector<std::string> TesterAnalizer::generate_args( int column, Collector::Method method )
  {
    std::vector<std::string> args;

    if( Helper::is_integer( method.params[ column ].type ) )
    {
      args = generate_ints( column, method );
    } else if( Helper::is_string( method.params[ column ].type ) )
    {
      args = generate_strings( column, method );
    } else
    {
      // Nothing to do
    }

    return args;
  }

  std::vector<std::string> TesterAnalizer::generate_ints( int column, Collector::Method method )
  {
    std::vector<std::string> ints;
    ints.push_back( std::to_string( method.params[ column ].range.first ) );
    ints.push_back( std::to_string( method.params[ column ].range.first+1 ) );
    ints.push_back( std::to_string( method.params[ column ].range.second-1 ) );
    ints.push_back( std::to_string( method.params[ column ].range.second ) );
    return ints;
  }

  std::vector<std::string> TesterAnalizer::generate_strings( int column, Collector::Method method )
  {
    int min = method.params[ column ].range.first;
    int max = method.params[ column ].range.second;
    std::vector<std::string> strings;

    strings.push_back( generator.generate_random_string( min, min+1 ) );
    strings.push_back( generator.generate_random_string( min+1, min+2 ) );
    strings.push_back( generator.generate_random_string( max-2, max-1 ) );
    strings.push_back( generator.generate_random_string( max-1, max ) );
    return strings;
  }
}
