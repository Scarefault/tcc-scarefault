#include "TestfileGrailsBuilder.hpp"

namespace Tester
{
  void TestfileGrailsBuilder::build_dependencies()
  {
    std::stringstream stream;
    stream << this->build_package() << this->build_imports();
    this->testfile->set_dependencies( stream.str() );
  }

  void TesterController::create_params( std::fstream * test_stream )
  {
    for( int i = 0; i < data_ptr->proprieties.size(); i++ )
    {
      Collector::Propriety propriety = data_ptr->proprieties[ i ];

      if( propriety.name.compare( "dateCreated") &&
          propriety.name.compare( "lastUpdated") )
      {
        std::string value = create_value( propriety );

        (* test_stream) << "  params[\""
                        << propriety.name
                        << "\"] = "
                        << value
                        << std::endl;
      } else
      {
        // Nothing to do
      }
    }

    std::string TesterController::create_value( Collector::Propriety propriety )
    {
      std::string value( "VALID VALUE" );
      std::vector<Collector::Constraint> constraints = propriety.contraints;

      if( is_string( propriety ) )
      {
        value = create_string( propriety );
      } else if( is_integer( propriety ) )
      {
        value = create_integer( propriety );
      } else if( is_floating( propriety ) )
      {
        value = create_floating( propriety );
      } else if( is_boolean( propriety ) )
      {
        value = value_generator.generate_boolean();
      } else
      {
        // Nothing to do
      }

      return value;
    }

    std::string TesterController::create_string( Collector::Propriety propriety )
    {
      clear_constraints();

      for( int i = 0; i < propriety.contraints.size(); i++ )
      {
        Collector::Constraint constraint = propriety.contraints[ i ];

        for( int type = 0; type < type_constraint.size(); type++ )
        {
          if( !constraint.name.compare( type_constraint[ type ] ) )
          {
            switch( type )
            {
              case BLANK:
                constraints[ BLANK ] = convert_to_bool( constraint.value );
                break;
              case CREDIT_CARD:
                constraints[ CREDIT_CARD ] = convert_to_bool( constraint.value );
                break;
              case EMAIL:
                constraints[ EMAIL ] = convert_to_bool( constraint.value );
                break;
              case NULLABLE:
                constraints[ NULLABLE ] = convert_to_bool( constraint.value );
                break;
              case SIZE:
                extract_size( constraint.value );
                break;
              case URL:
                constraints[ URL ] = convert_to_bool( constraint.value );
                break;
            }
          }
        }
      }

      return value_generator.generate_string( constraints );
    }

    std::string TesterController::create_integer( Collector::Propriety propriety )
    {
      clear_constraints();

      for( int i = 0; i < propriety.contraints.size(); i++ )
      {
        Collector::Constraint constraint = propriety.contraints[ i ];

        for( int type = 0; type < type_constraint.size(); type++ )
        {
          if( !constraint.name.compare( type_constraint[ type ] ) )
          {
            switch( type )
            {
              case NULLABLE:
                constraints[ NULLABLE ] = convert_to_bool( constraint.value );
                break;
              case MAX:
                constraints[ MAX ] = std::stoi( constraint.value );
                break;
              case MIN:
                constraints[ MIN ] = std::stoi( constraint.value );
                break;
              case RANGE:
                extract_range( constraint.value );
                break;
            }
          }
        }
      }

      return value_generator.generate_integer( constraints );
    }

    std::string TesterController::create_floating( Collector::Propriety propriety )
    {
      clear_constraints();

      for( int i = 0; i < propriety.contraints.size(); i++ )
      {
        Collector::Constraint constraint = propriety.contraints[ i ];

        for( int type = 0; type < type_constraint.size(); type++ )
        {
          if( !constraint.name.compare( type_constraint[ type ] ) )
          {
            switch( type )
            {
              case NULLABLE:
                constraints[ NULLABLE ] = convert_to_bool( constraint.value );
                break;
              case MAX:
                constraints[ MAX ] = std::stoi( constraint.value );
                break;
              case MIN:
                constraints[ MIN ] = std::stoi( constraint.value );
                break;
              case SCALE:
                constraints[ SCALE ] = std::stoi( constraint.value );
                break;
              case RANGE:
                extract_range( constraint.value );
                break;
            }
          }
        }
      }

      return value_generator.generate_floating( constraints );
    }

    bool TesterController::is_string( Collector::Propriety propriety )
    {
      bool is_string = false;

      if( !propriety.type.compare( "String" ) )
      {
        is_string = true;
      } else
      {
        // Nothing to do
      }

      return is_string;
    }

    bool TesterController::is_integer( Collector::Propriety propriety )
    {
      bool is_integer = false;

      if( !propriety.type.compare( "Integer" ) || !propriety.type.compare( "int" ) )
      {
        is_integer = true;
      } else
      {
        // Nothing to do
      }

      return is_integer;
    }

    bool TesterController::is_floating( Collector::Propriety propriety )
    {
      bool is_floating = false;

      if( !propriety.type.compare( "Double" ) || !propriety.type.compare( "double" ) ||
          !propriety.type.compare( "Float" ) || !propriety.type.compare( "float" ) )
      {
        is_floating = true;
      } else
      {
        // Nothing to do
      }

      return is_floating;
    }

    bool TesterController::is_boolean( Collector::Propriety propriety )
    {
      bool is_boolean = false;

      if( !propriety.type.compare( "boolean" ) )
      {
        is_boolean = true;
      } else
      {
        // Nothing to do
      }

      return is_boolean;
    }

    bool TesterController::convert_to_bool( std::string text )
    {
      return ( text == "true" ) ? true : false;
    }

    void TesterController::extract_size( std::string text )
    {
      int range_op_position = text.find( ".." );
      std::string min_string = text.substr( 0, range_op_position );
      std::string max_string = text.substr( range_op_position+2 );

      constraints[ MIN_SIZE ] = std::stoi( min_string );
      constraints[ MAX_SIZE ] = std::stoi( max_string );
    }

    void TesterController::extract_range( std::string text )
    {
      int range_op_position = text.find( ".." );
      std::string min_string = text.substr( 0, range_op_position );
      std::string max_string = text.substr( range_op_position+2 );

      constraints[ MIN ] = std::stoi( min_string );
      constraints[ MAX ] = std::stoi( max_string );
    }

    void TesterController::clear_constraints()
    {
      int QTD_BOOLEAN_CONSTRAINTS = 6;

      for( int i = 0; i < QTD_BOOLEAN_CONSTRAINTS; i++ )
      {
        constraints[ i ] = false;
      }

      constraints[ MIN_SIZE ] = 1;
      constraints[ MAX_SIZE ] = 25;
      constraints[ MIN ] = 1;
      constraints[ MAX ] = 999;
      constraints[ SCALE ] = 2;
    }
}
