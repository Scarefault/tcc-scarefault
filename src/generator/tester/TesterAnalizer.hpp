#ifndef TESTERANALIZER_HPP_
#define TESTERANALIZER_HPP_


#define READ std::fstream::in
#define WRITE std::fstream::out
#define APPEND std::fstream::app


#include <string>
#include <fstream>


#include "../value_generator/ValueGenerator.hpp"
#include "../../identifier/file/FileMVC.hpp"


namespace Tester
{
  class TesterAnalizer
  {
    public:
      TesterAnalizer( Collector::FileMVC * );

      void create_testcases( std::fstream *, std::string );

    private:
      Collector::FileMVC * data;
  };
}

#endif // TESTERANALIZER_HPP_
