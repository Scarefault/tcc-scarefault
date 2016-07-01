#include "TestCaseBase.hpp"


namespace Tester {
  TestCaseBase::TestCaseBase(
      std::string method, std::string result, std::vector<Tester::Arg> args )
  {
    this->bound_method = method;
    this->expected_result = result;
    this->arguments = args;
  }

  TestCaseBase::TestCaseBase( std::string result, std::vector<Tester::Arg> args )
  {
    this->expected_result = result;
    this->arguments = args;
  }

  TestCaseBase::TestCaseBase( std::string method, std::string result )
  {
    this->bound_method = method;
    this->expected_result = result;
  }

  TestCaseBase::TestCaseBase() { /* Empty Constructor */ }

  std::string * TestCaseBase::get_bound_method()
  {
    return &bound_method;
  }

  std::string * TestCaseBase::get_expected_result()
  {
    return &expected_result;
  }

  std::vector<Tester::Arg> * TestCaseBase::get_arguments()
  {
    return &arguments;
  }

  Tester::Arg * TestCaseBase::get_argument( int index )
  {
    return &arguments[ index ];
  }

  std::string * TestCaseBase::get_tested_propriety()
  {
    return &tested_propriety;
  }

  void TestCaseBase::insert_argument( Tester::Arg argument )
  {
    this->arguments.push_back( argument );
  }

  void TestCaseBase::set_bound_method( std::string method )
  {
    this->bound_method = method;
  }

  void TestCaseBase::set_expected_result( std::string result )
  {
    this->expected_result = result;
  }

  void TestCaseBase::set_tested_propriety( std::string propriety )
  {
    this->tested_propriety = propriety;
  }
}
