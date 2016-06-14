#ifndef WRITER_HPP_
#define WRITER_HPP_


#define TESTFILE "testfile.groovy"
#define WRITE std::fstream::out
#define APPEND std::fstream::app


#include <fstream>


#include "../tester/TesterDirector.hpp"


namespace Tester
{
  class Writer
  {
    public:
      Writer( Tester::TesterDirector * );

      void write_testfile();

    private:
      Tester::TesterDirector * tester;
  };
}

#endif // WRITER_HPP_
