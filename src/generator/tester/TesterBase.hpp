#ifndef TESTERBASE_HPP_
#define TESTERBASE_HPP_

#define TESTFILE "testfile.groovy"

#define WRITE std::fstream::out
#define APPEND std::fstream::app

#include <string>
#include <fstream>
#include <iostream>
#include <locale>


#include "../../identifier/collector/FileMVC.hpp"

namespace Tester
{
  class TesterBase
  {
    public:
      static TesterBase * get_tester( Collector::FileMVC * );

      void set_data( Collector::FileMVC * );
      virtual void write_data() { /* Implement it in Subclass */ };

    protected:
      Collector::FileMVC * data_ptr;
      std::locale locale;

      virtual void make_header( std::fstream * ) { /* Implement it in Subclass */ };
      virtual void test_methods( std::fstream * ) { /* Implement it in Subclass */ };

      void conclude_data( std:: fstream * );

      std::string convert_to_lower( std::string );
  };
}

#endif // TESTERBASE_HPP_
