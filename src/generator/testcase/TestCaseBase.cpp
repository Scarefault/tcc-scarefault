#include "TestCaseBase.hpp"

namespace Tester {
  TestCaseBase::TestCaseBase(
      std::string method, std::string result, std::vector<Tester::Arg> args )
  {
    this->bound_method = method;
    this->expected_result = result;
    this->arguments = args;
  }

  TestCaseBase::TestCaseBase( std::string method, std::string result )
  {
    this->bound_method = method;
    this->expected_result = result;
  }

  std::string TestCaseBase::get_bound_method()
  {
    return this->bound_method;
  }

  std::string TestCaseBase::get_expected_result()
  {
    return this->expected_result;
  }

  std::vector<Tester::Arg> TestCaseBase::get_arguments()
  {
    return this->arguments;
  }

  Tester::Arg TestCaseBase::get_argument( int index )
  {
    return this->arguments[ index ];
  }

  void TestCaseBase::insert_argument( Tester::Arg argument )
  {
    this->arguments.push_back( argument );
  }
}
