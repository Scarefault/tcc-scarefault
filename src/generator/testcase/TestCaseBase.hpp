#ifndef TESTCASEBASE_HPP_
#define TESTCASEBASE_HPP_

#include <string>
#include <vector>


namespace Tester
{
  class TestCaseBase
  {
    public:
      TestCase( std::string, std::string, std::vector<Tester::Arg> = nullptr );


      std::string get_bound_method();
      std::string get_expected_result();

      std::vector<Tester::Arg> get_arguments();
      Tester::Arg get_argument( int );

      void insert_argument( Tester::Arg );


    protected:
      std::string bound_method;
      std::string expected_result;
      std::vector<Tester::Arg> arguments;
  };
}

#endif // TESTCASEBASE_HPP_
