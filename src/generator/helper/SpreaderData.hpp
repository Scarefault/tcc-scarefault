#ifndef SPREADERDATA_HPP_
#define SPREADERDATA_HPP_

#define TESTFILE "testfile.dat"

#define WRITE std::fstream::out
#define APPEND std::fstream::app

#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include "../../analizer/helper/Data.hpp"

namespace Helper
{
  class SpreaderData;


  /*
   * Define a new type to keep a reference to the address of the
   *   SpreaderData.
   */
  typedef SpreaderData* ADDRESS;

  /*
   * It's a global variable. Currently, it's necessary to allow access the
   *   reference of SpreaderData. With this, Is possible access a
   *   SpreaderData, created in parser file, in other files.
   */
  extern ADDRESS address_spreader;


  class SpreaderData
  {
    public:
      SpreaderData();

      void set_data( Helper::Data * );
      void write_data();

    private:
      Helper::Data * data_ptr;

      void write_header( std::fstream * );
      void analizer_methods( std::fstream * );
      void write_test_create( std::fstream * );
      void write_test_show( std::fstream * );
      void write_test_delete( std::fstream * );
      void write_test_list( std::fstream * );
      void write_test_save( std::fstream * );
      void write_test_edit( std::fstream * );
      void conclude_data( std:: fstream * );
  };
}

#endif // SPREADERDATA_HPP_
