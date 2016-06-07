#ifndef ARG_HPP_
#define ARG_HPP_

#include <string>


namespace Tester {
  class Arg
  {
    public:
      Arg( std::string, std::string );

      std::string bound_param;
      std::string value;
  };
}

#endif // ARG_HPP_
