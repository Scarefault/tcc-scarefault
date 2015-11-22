/*
 * Implementation of the interface TestGenerator.cpp
 */

#include "TestGenerator.hpp"

namespace Generator
{
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

  void TestGenerator::add_scenario_entry( int input )
  {
    this->scenario_entries.push_back( input );
  }

  void TestGenerator::set_scenario_out( int output )
  {
    this->scenario_out = output;
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
