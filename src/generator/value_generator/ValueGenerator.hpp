#ifndef VALUE_GENERATOR_HPP_
#define VALUE_GENERATOR_HPP_

#include <string>
#include <cmath>

namespace Generator
{
  class ValueGenerator
  {
    public:
      std::string generate_random_string( int = 50, bool = false,
        bool = false, bool = false, bool = false, bool = false );

      std::string generate_random_integer( int = 100 );
      std::string generate_random_floating( int = 100, int = 2 );
      std::string generate_random_boolean();
  };
}

#endif // VALUE_GENERATOR_HPP_
