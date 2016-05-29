#ifndef TESTCONTROLLER_HPP_
#define TESTCONTROLLER_HPP_

#include <cmath>
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

      void create_params( std::fstream * );
      std::string create_value( Helper::Propriety );

      std::string generate_random_string( int = 50, bool = false );
      std::string generate_random_integer( int = 100 );
      std::string generate_random_floating( int = 100, int = 2 );
      std::string generate_random_boolean();

      bool is_string( Helper::Propriety );
      bool is_integer( Helper::Propriety );
      bool is_floating( Helper::Propriety );
      bool is_boolean( Helper::Propriety );
  };
}

#endif // TESTCONTROLLER_HPP_
