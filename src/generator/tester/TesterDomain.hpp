#ifndef TESTER_DOMAIN_HPP_
#define TESTER_DOMAIN_HPP_


#include "TesterBase.hpp"
#include "../../analizer/helper/Data.hpp"
#include  "../value_generator/ValueGenerator.hpp"

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
