#ifndef TESTERBASE_HPP_
#define TESTERBASE_HPP_

#define TESTFILE "testfile.groovy"

#define WRITE std::fstream::out
#define APPEND std::fstream::app

#include <string>
#include <fstream>
#include <iostream>


#include "../../helper/Helper.hpp"
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

      virtual void make_header( std::fstream * ) { /* Implement it in Subclass */ };
      virtual void test_methods( std::fstream * ) { /* Implement it in Subclass */ };

      void conclude_data( std:: fstream * );
  };
}

#endif // TESTERBASE_HPP_
