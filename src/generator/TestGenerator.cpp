/*
 * Implementation of the interface TestGenerator.cpp
 */

#include <cctype>

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
    addresses_test_generators.push_back( this );
}

  /********************** End of Constructors ********************************/


  /******************** Public Member Functions ******************************/

  std::string TestGenerator::generate_method_header()
  {
    std::string scenario( this->get_scenario_name() );

    std::string method_header( "void" );
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
    std::string output( std::to_string( this->get_scenario_out() ) );

    std::string expectation( "\tresult = " );
    expectation.append( output );
    expectation.append( "\n" );

    return expectation;
  }

  std::string TestGenerator::generate_call_method()
  {
    std::string input( "" );

    std::vector<int> entries = this->get_scenario_entries();

    for( unsigned index = 0; index < entries.size(); index++ )
    {
      input.append( std::to_string( entries.at( index ) ) );

      if( index != ( entries.size() - 1 ) )
      {
        input.append( ", " );
      } else
      {
        /* Nothing to do. */
      }
    }

    std::string call_method;

    call_method.append( "\texpectedResult = " );
    call_method.append( method_name );
    call_method.append( "( " );
    call_method.append( input );
    call_method.append( " )" );
    call_method.append( "\n" );

    return call_method;
  }

  std::string TestGenerator::generate_assertation()
  {
    std::string assertation( "\tassert" );
    assertation.append( "Equals " );
    assertation.append( "expectedResult, " );
    assertation.append( "result" );
    assertation.append( "\n" );
    assertation.append( "}" );
    assertation.append( "\n" );

    return assertation;
  }

  void TestGenerator::add_scenario_entry( int input )
  {
    this->scenario_entries.push_back( input );
  }

  /**************** End of Public Member Functions ***************************/


  /******************* Private Member Functions ******************************/

  std::string TestGenerator::prepare_scenario_name()
  {
    std::string scenario( this->scenario_name );

    while( check_whitespaces( scenario ) || check_quotes( scenario ) )
    {
      if( check_whitespaces( scenario ) )
      {
        remove_character( &scenario, ' ' );
      } else
      {
        /* Nothing to do. */
      }

      if( check_quotes( scenario ) )
      {
        remove_character( &scenario, '\"' );
      } else
      {
        /* Nothing to do. */
      }
    }

    return scenario;
  }

  bool TestGenerator::check_whitespaces( const std::string text )
  {
    bool is_exist = EXIST;
    char whitespace = ' ';
    
    if( text.find_first_of( whitespace ) != std::string::npos )
    {
      is_exist  = EXIST;
    } else
    {
      is_exist = NOT_EXIST;
    }
    
    return is_exist;
  }

  bool TestGenerator::check_quotes( const std::string text )
  {
    bool is_exist = EXIST;
    char quote = '\"';
    
    if( text.find_first_of( quote ) != std::string::npos )
    {
      is_exist  = EXIST;
    } else
    {
      is_exist = NOT_EXIST;
    }

    return is_exist;
  }

  void TestGenerator::remove_character( std::string* text, char character )
  {
    int position = text->find_first_of( character );
    text->erase( text->begin() + position );
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
    int first_alpha = 1;

    name.at( first_alpha ) = std::toupper( name.at( first_alpha ) );

    for( unsigned position = first_alpha; position < name.length();
         position++ )
    {
      if( ( name.length() - 1 ) > position )
      {
        if( name.at( position ) == ' ' && isalpha( name.at( position + 1 ) ) )
        {
          name.at( position + 1 ) = std::toupper( name.at( position + 1 ) );
        } else
        {
          name.at( position + 1 ) = std::tolower( name.at( position + 1 ) );
        }
      }
    }

    this->scenario_name = name; 
  }

  void TestGenerator::set_scenario_entries( std::vector<int> input )
  {
    this->scenario_entries = input;
  }

  void TestGenerator::set_package_name( std::string name )
  {
    this->package_name = name;
  }

  void TestGenerator::set_import_name( std::string name )
  {
    this->import_name = name;
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
    return this->prepare_scenario_name();
  }

  std::vector<int> TestGenerator::get_scenario_entries()
  {
    return this->scenario_entries;
  }

  std::string TestGenerator::get_package_name()
  {
    return this->package_name;
  }

  std::string TestGenerator::get_import_name()
  {
    return this->import_name;
  }
}

/********************* End of Setters and Getters ****************************/
