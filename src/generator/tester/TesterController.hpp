#ifndef TESTCONTROLLER_HPP_
#define TESTCONTROLLER_HPP_

#include "TesterBase.hpp"
#include "../../analizer/helper/Data.hpp"

namespace Tester
{
  class TesterController : public TesterBase
  {
    public:
      TesterController( Helper::Data * );

      void write_data();

    private:
      void make_header( std::fstream * );
      void make_valid_setup( std::fstream * );
      void test_methods( std::fstream * );

      void make_test_index( std::fstream * );
      void make_test_create( std::fstream * );
      void make_test_show( std::fstream * );
      void make_test_delete( std::fstream * );
      void make_test_list( std::fstream * );
      void make_test_save( std::fstream * );
      void make_test_edit( std::fstream * );
      void make_test_update( std::fstream * );
  };
}

#endif // TESTCONTROLLER_HPP_
