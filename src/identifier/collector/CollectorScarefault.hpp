#ifndef COLLECTOR_SCAREFAULT_HPP_
#define COLLECTOR_SCAREFAULT_HPP_

#include <string>
#include <vector>
#include <cstdarg>

#include "Param.hpp"
#include "../../helper/Helper.hpp"
#include "../../generator/testcase/TestCaseBase.hpp"
#include "../../generator/testcase/Arg.hpp"

namespace Collector
{
  class CollectorScarefault
  {
    public:
      void collect_data( const char *, ... );
      std::vector<Collector::Param> * get_params();
      Collector::Param get_param( int );

      void clear_test_cases();
      std::vector<Tester::TestCaseBase> * get_test_cases();
      std::vector<Tester::TestCaseBase> get_test_cases_by_copy();
      Tester::TestCaseBase * get_test_case( int );

    private:
      static const char EOL = '\0';
      static const char PARAM = 'p';
      static const char RANGE = 'r';
      static const char ARGUMENTS_FOR_TEST_CASE = 'a';
      static const char EXPECTED_RESULT = 'e';


      Tester::TestCaseBase collected_case;
      std::vector<Collector::Param> params;
      std::vector<Tester::TestCaseBase> test_cases;


      void collect_arguments( std::string );
      void collect_expected_result( std::string );
      void insert_test_case();
      void insert_param( std::string );
      void set_range( std::string );

      void clear_collected_case();
  };
}

#endif // COLLECTOR_SCAREFAULT_HPP_
