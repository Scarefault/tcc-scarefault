#ifndef SPREADERDATA_HPP_
#define SPREADERDATA_HPP_

#define DATAFILE "datafile.dat"
#define TESTFILE "testfile.dat"

#define WRITE std::fstream::out
#define APPEND std::fstream::app
#define READ std::fstream::in

#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>

namespace Helper
{
  class SpreaderData
  {
    typedef struct output_file
    {
      std::string package_name;
      std::string class_name;
    } OutputFile;

    public:
      void recover_data();
      void write_data();

    private:
      OutputFile output;
  };
}

#endif // SPREADERDATA_HPP_
