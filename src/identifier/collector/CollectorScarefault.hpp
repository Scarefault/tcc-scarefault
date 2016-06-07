#ifndef COLLECTOR_SCAREFAULT_HPP_
#define COLLECTOR_SCAREFAULT_HPP_

#include <string>
#include <vector>
#include <cstdarg>

#include "Param.hpp"
#include "../../helper/Helper.hpp"
#include "../../generator/testcase/TestCaseBase.hpp"

namespace Collector
{
  class CollectorScarefault
  {
    public:
      void collect_data( const char *, ... );
      std::vector<Collector::Param> * get_params();
      Collector::Param get_param( int );

    private:
      static const char EOL = '\0';
      static const char PARAM = 'p';
      static const char RANGE = 'r';
      static const char TEST_CASE = 't';


      std::vector<Collector::Param> params;
      std::vector<Tester::TestCaseBase> test_cases;


      void insert_test_case( Tester::TestCaseBase );
      void insert_param( std::string );
      void set_range( std::string );
  };
}

#endif // COLLECTOR_SCAREFAULT_HPP_
