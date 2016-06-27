#include "TestfileProduct.hpp"
#include <iostream>


namespace Tester
{
  TestfileProduct::TestfileProduct() { /* Empty Constructor */ }

  std::string TestfileProduct::get_setup()
  {
    return this->setup;
  }

  void TestfileProduct::set_setup( std::string text )
  {
    this-> setup = text;
  }

  std::string TestfileProduct::get_dependencies()
  {
    return this->dependencies;
  }

  std::string TestfileProduct::get_test_class()
  {
    return this->test_class;
  }

  std::vector<std::string> * TestfileProduct::get_valid_testcases()
  {
    return &valid_testcases;
  }

  std::string * TestfileProduct::get_valid_testcase( int index )
  {
    return &( valid_testcases[ index ] );
  }

  void TestfileProduct::set_dependencies( std::string text )
  {
    this->dependencies = text;
  }

  void TestfileProduct::set_test_class( std::string text )
  {
    this->test_class = text;
  }

  void TestfileProduct::set_valid_testcases( std::vector<std::string> tescases )
  {
    this->valid_testcases = tescases;
  }

  void TestfileProduct::insert_valid_testcase( std::string testcase )
  {
    this->valid_testcases.push_back( testcase );
  }
}
