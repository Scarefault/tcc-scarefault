#ifndef TESTCONTROLLER_HPP_
#define TESTCONTROLLER_HPP_


#include "TesterBase.hpp"
#include "../../analizer/collector/Data.hpp"
#include  "../value_generator/ValueGenerator.hpp"

namespace Tester
{
  class TesterController : public TesterBase
  {
    public:
      TesterController( Collector::Data * );

      void write_data();

    private:
      // Order of elements of type_constraint, TesterController::TypeConstraint
      //   and ValueGenerator::TypeConstraint needs the same.
      //
      enum TypeConstraint {
        NULLABLE, BLANK, URL, EMAIL, CREDIT_CARD, UNIQUE,
        MIN_SIZE, MAX_SIZE, MIN, MAX,
        SCALE, SIZE, RANGE,
        IN_LIST, NOT_EQUAL, MATCHES
      };

      // Order of elements of type_constraint, TesterController::TypeConstraint
      //   and ValueGenerator::TypeConstraint needs the same.
      //
      const std::vector<std::string> type_constraint {
        "nullable", "blank", "url", "email", "creditCard", "unique",
        "minSize", "maxSize", "min", "max",
        "scale", "size", "range",
        "inList", "notEqual", "matches"
      };

      std::vector<int> constraints {
        false, false, false, false, false, false,
        1, 25, 1, 9999, 2
      };

      Generator::ValueGenerator value_generator;

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
      std::string create_value( Collector::Propriety );
      std::string create_string( Collector::Propriety );
      std::string create_integer( Collector::Propriety );
      std::string create_floating( Collector::Propriety );

      bool is_string( Collector::Propriety );
      bool is_integer( Collector::Propriety );
      bool is_floating( Collector::Propriety );
      bool is_boolean( Collector::Propriety );

      bool convert_to_bool( std::string );
      void extract_size( std::string );
      void extract_range( std::string );
      void clear_constraints();
  };
}

#endif // TESTCONTROLLER_HPP_
