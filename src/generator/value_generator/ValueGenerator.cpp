#include "ValueGenerator.hpp"

namespace Generator
{
  std::string
    ValueGenerator::generate_string( std::vector<bool> bool_constraints, int min, int max )
  {
    std::string random_string;
    switch( verify_type_constraint( bool_constraints ) )
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

    int index = rand() % 10;

    std::string random_card( "\"" );
    random_card.append( card_numbers[ index ] );
    random_card.append( "\"" );

    return random_card;
  }

  std::string ValueGenerator::generate_integer( int min )
  {
    std::string random_integer = "0";

    return random_integer;
  }

  std::string ValueGenerator::generate_floating( int max, int scale )
  {
    double random_integer = rand() % max;
    double fractional = pow( 0.5, scale );

    double random_double = random_integer + fractional;
    return std::to_string( random_double );
  }

  std::string ValueGenerator::generate_boolean()
  {
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

  int ValueGenerator::verify_type_constraint( std::vector<bool> bool_constraints )
  {
    bool nullable = bool_constraints[ NULLABLE ];
    bool blank = bool_constraints[ BLANK ];
    bool url = bool_constraints[ URL ];
    bool email = bool_constraints[ EMAIL ];
    bool credit_card = bool_constraints[ CREDIT_CARD ];
    std::cout << "nullable: " << nullable << "\n";
    std::cout << "blank: " << blank << "\n";
    std::cout << "url: " << url << "\n";
    std::cout << "email: " << email << "\n";
    std::cout << "credit_card: " << credit_card << "\n";

    int result = ( nullable ? NULLABLE :
                 ( blank ? BLANK :
                 ( url ? URL :
                 ( email ? EMAIL :
                 ( credit_card ? CREDIT_CARD : SIZE )))));
    std::cout << "verify_type: " << result << "\n\n";
    return result;
  }
}
