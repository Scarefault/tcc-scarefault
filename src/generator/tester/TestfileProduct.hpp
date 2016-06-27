#ifndef TESTFILEPRODUCT_HPP_
#define TESTFILEPRODUCT_HPP_


#include <string>
#include <vector>


namespace Tester
{
  class TestfileProduct
  {
    public:
      TestfileProduct();

      std::string get_dependencies();
      std::string get_test_class();
      std::string get_setup();
      std::vector<std::string> * get_valid_testcases();
      std::string * get_valid_testcase( int );

      void set_dependencies( std::string );
      void set_test_class( std::string );
      void set_setup( std::string );
      void set_valid_testcases( std::vector<std::string> );
      void insert_valid_testcase( std::string );


    private:
      std::string dependencies;
      std::string test_class;
      std::string setup;
      std::vector<std::string> valid_testcases;
  };
}

#endif // TESTFILEPRODUCT_HPP_
