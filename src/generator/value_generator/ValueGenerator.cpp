#include "ValueGenerator.hpp"

namespace Generator
{
  std::string
    ValueGenerator::generate_string( std::vector<bool> bool_data, int min, int max )
  {
    std::string random_string;

    switch( verify_type_constraint( bool_data ) )
    {
      case NULLABLE:
        random_string = null;
        break;
      case BLANK:
        random_string = empty_string;
        break;
      case URL:
        random_string = generate_random_url( min, max );
        break;
      case EMAIL:
        random_string = generate_random_email( min, max );
        break;
      case CREDIT_CARD:
        random_string = generate_random_credit_card();
        break;
      case SIZE:
        random_string = generate_random_string( min, max );
        break;
    }

    return random_string;
  }

  std::string ValueGenerator::generate_random_string( int min, int max )
  {
    srand( time( NULL ) );

    std::string random_string( "\"" );

    int size = rand() % ( max-min ) + min;

    for( int i = 0; i < size; i++ )
    {
      random_string += alphanum[ rand() % ( alphanum.size()-1 ) ];
    }

    random_string.insert( random_string.end(), '\"' );

    return random_string;
  }

  std::string ValueGenerator::generate_random_email( int min, int max )
  {
    srand( time( NULL ) );

    std::string random_email( "\"" );

    int size = rand() % ( max-min ) + min;

    for( int i = 0; i < size; i++ )
    {
      random_email += alphanum[ rand() % ( alphanum.size()-1 ) ];
    }

    int email_service = rand() % email_services.size();

    random_email.append( email_services[ email_service ] );
    random_email.insert( random_email.end(), '\"' );

    return random_email;
  }

  std::string ValueGenerator::generate_random_url( int min, int max )
  {
    srand( time( NULL ) );

    std::string random_url( "\"www." );

    int size = rand() % ( max-min ) + min;

    for( int i = 0; i < size; i++ )
    {
      random_url += alphanum[ rand() % ( alphanum.size()-1 ) ];
    }

    random_url.append( ".com" );

    return random_url;
  }

  std::string ValueGenerator::generate_random_credit_card()
  {
    std::vector<std::string> card_numbers {
      "4532940024597", "4916893184492", "4916267903709", "4916547540461",
      "4485563878726", "4716555160701", "4172379054151", "4916012101617",
      "4929190395208", "4508797568381" };

    srand( time( NULL ) );
    int index = rand() % 10;

    std::string random_card( "\"" );
    random_card.append( card_numbers[ index ] );
    random_card.append( "\"" );

    return random_card;
  }

  std::string ValueGenerator::generate_integer( int max )
  {
    srand( time( NULL ) );
    int random_integer = rand() % max;
    return std::to_string( random_integer );
  }

  std::string ValueGenerator::generate_floating( int max, int scale )
  {
    srand( time( NULL ) );

    double random_integer = rand() % max;
    double fractional = pow( 0.5, scale );

    double random_double = random_integer + fractional;
    return std::to_string( random_double );
  }

  std::string ValueGenerator::generate_boolean()
  {
    srand( time( NULL ) );

    int result = rand() % 2;
    std::string random_boolean;

    if( result )
    {
      random_boolean = "true";
    } else
    {
      random_boolean = "false";
    }

    return random_boolean;
  }

  int ValueGenerator::verify_type_constraint( std::vector<bool> bool_data )
  {
    bool nullable = bool_data[ 0 ];
    bool blank = bool_data[ 1 ];
    bool url = bool_data[ 2 ];
    bool email = bool_data[ 3 ];
    bool credit_card = bool_data[ 4 ];

    int result = ( nullable ? NULLABLE :
                 ( blank ? BLANK :
                 ( url ? URL :
                 ( email ? EMAIL :
                 ( credit_card ? CREDIT_CARD : SIZE )))));

    return result;
  }
}
