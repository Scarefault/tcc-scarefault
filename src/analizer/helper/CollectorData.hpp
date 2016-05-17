#ifndef COLLECTORDATA_HPP_
#define COOLECTORDATA_HPP_

#define DATAFILE "datafile.dat"

#define WRITE std::fstream::out
#define APPEND std::fstream::app

#include <string>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <queue>

namespace Helper
{
  class CollectorData
  {
    typedef struct input_file
    {
      std::string package_name;
      std::string class_name;
    } InputFile;

    public:
      void collect_data( const char *, ... );
      void record_data();

    private:
      static const char EOL = '\0';
      static const char PACKAGE = 'p';
      static const char CLASS = 'c';

      InputFile input;
      std::queue<std::string> data;

      void insert_data();
      void insert_data_package();
      void insert_data_class();

      void set_package_name( std::string );
      void set_class_name( std::string );

      std::string get_package_name();
      std::string get_class_name();
  };
}

#endif // COLLECTORDATA_HPP_
