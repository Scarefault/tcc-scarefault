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
      void write_test_create();
      void analiser_methods();


      Helper::Data * data_ptr;
  };
}

#endif // SPREADERDATA_HPP_
