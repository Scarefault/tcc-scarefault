#ifndef TESTERANALIZER_HPP_
#define TESTERANALIZER_HPP_


#define READ std::fstream::in
#define WRITE std::fstream::out
#define APPEND std::fstream::app


#include <string>
#include <fstream>
#include <vector>


#include "../value_generator/ValueGenerator.hpp"
#include "../../identifier/file/FileMVC.hpp"


namespace Tester
{
  class Matrix
  {
    public:
      Matrix( int columns )
      {
        first = std::vector<std::string>( columns, "" );
        second = std::vector<std::string>( columns, "" );
        third = std::vector<std::string>( columns, "" );
        fourth = std::vector<std::string>( columns, "" );
      };

      std::vector<std::string> first;
      std::vector<std::string> second;
      std::vector<std::string> third;
      std::vector<std::string> fourth;
  };


  class TesterAnalizer
  {
    public:
      TesterAnalizer( Collector::FileMVC * );

      void insert_testcases( std::fstream *, std::string );

    private:
      Collector::FileMVC * data;

      std::string create_testcases( Collector::Method );
      void fill_column_analysis( int, std::vector<Matrix> *, Collector::Method );
      void fill_columns_adjacent( int, std::vector<Matrix> *, Collector::Method );
  };
}

#endif // TESTERANALIZER_HPP_
