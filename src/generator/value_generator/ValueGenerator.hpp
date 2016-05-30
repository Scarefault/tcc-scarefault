#ifndef VALUE_GENERATOR_HPP_
#define VALUE_GENERATOR_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

namespace Generator
{
  class ValueGenerator
  {
    public:
      std::string generate_string( bool = false, bool = false, bool = false,
        bool = false, bool = false, int = 3, int = 12 );

      std::string generate_integer( int = 100 );
      std::string generate_floating( int = 100, int = 2 );
      std::string generate_boolean();

    private:
      enum TypeConstraint {
        BLANK, CREDIT_CARD, EMAIL, IN_LIST, MATCHES, MAX,
        MAX_SIZE, MIN, MIN_SIZE, NOT_EQUAL, NULLABLE, RANGE,
        SCALE, SIZE, UNIQUE, URL
      };

      const std::string alphanum =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

      const std::vector<std::string> email_services {
        "@gmail.com", "@hotmail.com", "@outlook.com", "@yahoo.com"
      };

      const std::string null = "null";
      const std::string empty_string = "";

        std::string generate_random_string( int, int );
        std::string generate_random_email( int, int );
        std::string generate_random_url( int, int );

        int verify_type_constraint( bool, bool, bool, bool, bool );
  };
}

#endif // VALUE_GENERATOR_HPP_
