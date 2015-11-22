/*
 * Implementation of the interface TestGenerator.cpp
 */

#include "TestGenerator.hpp"

namespace Generator
{
  std::vector<ADDRESS> addresses_test_generators;


  /************************** Constructors ***********************************/

  TestGenerator::TestGenerator( std::vector<int> input, int output,
                                std::string name )
  {
    this->set_scenario_name( name );
    this->set_scenario_entries( input );
    this->set_scenario_out( output );
  }

  TestGenerator::TestGenerator( std::string name )
  {
    this->set_scenario_name( name );
  }

  /********************** End of Constructors ********************************/


  /******************** Public Member Functions ******************************/

  std::string TestGenerator::generate_method_header()
  {
    std::string scenario( this->prepare_scenario_name() );

    std::string method_header( "def" );
    method_header.append( " " );
    method_header.append( "test" );
    method_header.append( scenario );
    method_header.append( "(" );
    method_header.append( ")" );
    method_header.append( " " );
    method_header.append( "{" );
    method_header.append( "\n" );

    return method_header;
  }

  std::string TestGenerator::generate_expectations()
  {
  }

  std::string TestGenerator::generate_call_method()
  {
  }

  std::string TestGenerator::generate_assertation()
  {
  }

  void TestGenerator::add_scenario_entry( int input )
  {
    this->scenario_entries.push_back( input );
  }

  /**************** End of Public Member Functions ***************************/


  /******************* Private Member Functions ******************************/

  std::string TestGenerator::prepare_scenario_name()
  {
    std::string scenario( this->get_scenario_name() );

    while( check_whitespaces() || check_quotes() )
    {
      if( check_whitespaces() )
      {
        remove_character( " " );
      } else
      {
        /* Nothing to do. */
      }

      if( check_quotes() )
      {
        remove_character( "\"" );
      } else
      {
        /* Nothing to do. */
      }
    }
  }

  /**************** End of Private Member Functions **************************/


  /********************** Setters and Getters ********************************/

  void TestGenerator::set_scenario_out( int output )
  {
    this->scenario_out = output;
  }

  void TestGenerator::set_method_name( std::string name )
  {
    this->method_name = name;
  }

  void TestGenerator::set_scenario_name( std::string name )
  {
    this->scenario_name = name;
  }

  void TestGenerator::set_scenario_entries( std::vector<int> input )
  {
    this->scenario_entries = input;
  }
 
  int TestGenerator::get_scenario_out()
  {
    return this->scenario_out;
  }

  std::string TestGenerator::get_method_name()
  {
    return this->method_name;
  }

  std::string TestGenerator::get_scenario_name()
  {
    return this->scenario_name;
  }

  std::vector<int> TestGenerator::get_scenario_entries()
  {
    return this->scenario_entries;
  }
}

/********************* End of Setters and Getters ****************************/
