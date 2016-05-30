#ifndef TESTCONTROLLER_HPP_
#define TESTCONTROLLER_HPP_


#include "TesterBase.hpp"
#include "../../analizer/helper/Data.hpp"
#include  "../value_generator/ValueGenerator.hpp"

namespace Tester
{
  class TesterController : public TesterBase
  {
    public:
      TesterController( Helper::Data * );

      void write_data();

    private:
      // Order of elements of type_constraint, TesterController::TypeConstraint
      //   and ValueGenerator::TypeConstraint needs the same.
      //
      enum TypeConstraint {
        NULLABLE, BLANK, URL, EMAIL, CREDIT_CARD, UNIQUE, IN_LIST,
        MATCHES, MAX, MAX_SIZE, MIN, MIN_SIZE, NOT_EQUAL, RANGE,
        SCALE, SIZE
      };

      // Order of elements of type_constraint, TesterController::TypeConstraint
      //   and ValueGenerator::TypeConstraint needs the same.
      //
      const std::vector<std::string> type_constraint {
        "nullable", "blank", "url", "email", "creditCard", "unique", "inList",
        "matches", "max", "maxSize", "min", "minSize", "notEqual", "range",
        "scale", "size"
      };

      std::vector<bool> boolean_constraints {
        false, false, false, false, false, false
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
      std::string create_value( Helper::Propriety );
      std::string create_string( Helper::Propriety );

      bool is_string( Helper::Propriety );
      bool is_integer( Helper::Propriety );
      bool is_floating( Helper::Propriety );
      bool is_boolean( Helper::Propriety );

      bool convert_to_bool( std::string );
      void clear_boolean_constraints();
  };
}

#endif // TESTCONTROLLER_HPP_
