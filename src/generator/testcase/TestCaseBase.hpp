#ifndef TESTCASEBASE_HPP_
#define TESTCASEBASE_HPP_


#include <string>
#include <vector>


#include "Arg.hpp"


namespace Tester
{
  class TestCaseBase
  {
    public:
      TestCaseBase( std::string, std::string, std::vector<Tester::Arg> );
      TestCaseBase( std::string, std::vector<Tester::Arg> );
      TestCaseBase( std::string, std::string );
      TestCaseBase();


      std::string * get_bound_method();
      std::string * get_expected_result();
      std::string * get_tested_propriety();
      Tester::Arg * get_argument( int );

      std::vector<Tester::Arg> * get_arguments();

      void set_bound_method( std::string );
      void set_tested_propriety( std::string );
      void set_expected_result( std::string );
      void insert_argument( Tester::Arg );


    protected:
      std::string bound_method;
      std::string expected_result;
      std::string tested_propriety;
      std::vector<Tester::Arg> arguments;
  };
}

#endif // TESTCASEBASE_HPP_
