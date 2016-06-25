#ifndef VALUE_GENERATOR_HPP_
#define VALUE_GENERATOR_HPP_


#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>


namespace Generator
{
  class ValueGenerator
  {
    public:
      std::string generate_string( std::vector<int> );

      std::string generate_integer( std::vector<int> );
      std::string generate_floating( std::vector<int> );
      std::string generate_boolean();

      std::string generate_random_string( int, int );
      std::string generate_random_integer( int, int );
      std::string generate_random_floating( int, int, int );

    private:
      // Order of elements of type_constraint, TesterController::TypeConstraint
      //   and ValueGenerator::TypeConstraint needs the same.
      //
      enum TypeConstraint {
        NULLABLE, BLANK, URL, EMAIL, CREDIT_CARD, UNIQUE,
        MIN_SIZE, MAX_SIZE, MIN, MAX,
        SCALE, SIZE, RANGE,
        IN_LIST, NOT_EQUAL, MATCHES
      };

      const std::string alphanum =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

      const std::vector<std::string> email_services {
        "@gmail.com", "@hotmail.com", "@outlook.com", "@yahoo.com"
      };

      const std::string null = "null";
      const std::string empty_string = "";

      std::string generate_random_email( int, int );
      std::string generate_random_url( int, int );
      std::string generate_random_credit_card();

      int verify_type_constraint( std::vector<int> );
  };
}

#endif // VALUE_GENERATOR_HPP_
