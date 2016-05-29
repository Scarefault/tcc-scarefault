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

      std::string generate_random_string( int, int );
      std::string generate_random_email( int, int );
      std::string generate_random_url( int, int );

      std::string generate_integer( int = 100 );
      std::string generate_floating( int = 100, int = 2 );
      std::string generate_boolean();

    private:
      const std::string alphanum =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

      const std::vector<std::string> email_services {
        "@gmail.com", "@hotmail.com", "@outlook.com", "@yahoo.com"
      };
  };
}

#endif // VALUE_GENERATOR_HPP_
