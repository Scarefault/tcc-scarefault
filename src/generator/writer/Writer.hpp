#ifndef WRITER_HPP_
#define WRITER_HPP_


#define WRITE std::fstream::out
#define APPEND std::fstream::app


#include <fstream>


#include "../tester/TesterDirector.hpp"


namespace Tester
{
  class Writer
  {
    public:
      Writer( Tester::TesterDirector *, std::string );

      void write_testfile();

    private:
      Tester::TesterDirector * tester;
      std::string testfile_name;

      std::string create_testfile_name( std::string );
  };
}

#endif // WRITER_HPP_
