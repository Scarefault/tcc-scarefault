#include "ValueGenerator.hpp"

namespace Generator
{
  std::string
    ValueGenerator::generate_random_string( int size, bool url, bool email,
      bool credit_card, bool blank, bool nullable )
  {
    std::string random_string;

    if( !nullable )
    {
      if( !blank )
      {
        if( !url )
        {
          if( !email )
          {
            if( !credit_card )
            {
              static const std::string alphanum =
                  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

              for( int i = 0; i < size; i++ )
              {
                random_string += alphanum[ rand() % ( alphanum.size()-1 ) ];
              }

              random_string.insert( random_string.begin(), '\"' );
              random_string.insert( random_string.end(), '\"' );
            } else
            {
              random_string = "\"4556647559902\"";
            }
          } else
          {
            random_string = "\"example@gmail.com\"";
          }
        } else
        {
          random_string = "\"www.somthing.com\"";
        }
      } else
      {
        random_string = "";
      }
    } else
    {
      random_string = "null";
    }

    return random_string;
  }

  std::string ValueGenerator::generate_random_integer( int max )
  {
    int random_integer = rand() % max;
    return std::to_string( random_integer );
  }

  std::string ValueGenerator::generate_random_floating( int max, int scale )
  {
    double random_integer = rand() % max;
    double fractional = pow( 0.5, scale );

    double random_double = random_integer + fractional;
    return std::to_string( random_double );
  }

  std::string ValueGenerator::generate_random_boolean()
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
}
