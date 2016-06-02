#ifndef TESTER_DOMAIN_HPP_
#define TESTER_DOMAIN_HPP_

#define TESTFILE "testfile.groovy"

#define WRITE std::fstream::out
#define APPEND std::fstream::app


#include <string>
#include <fstream>
#include <iostream>
#include <locale>


#include "../../analizer/helper/Data.hpp"

namespace Tester
{
  class TesterDomain : public TesterBase
  {
    public:
      TesterDomain( Helper::Data * )

      void write_data();

    private:
      void make_header( std::fstream * );
      void test_methods( std::fstream * );
  };
}

#endif // TESTER_DOMAIN_HPP_
