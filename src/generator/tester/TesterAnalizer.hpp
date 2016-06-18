#ifndef TESTERANALIZER_HPP_
#define TESTERANALIZER_HPP_


#include "../value_generator/ValueGenerator.hpp"
#include "../../identifier/file/FileMVC.hpp"


namespace Tester
{
  class TesterAnalizer
  {
    public:
      TesterAnalizer( Collector::FileMVC * );

    private:
      Collector::FileMVC * data_ptr;
  };
}

#endif // TESTERANALIZER_HPP_
