#ifndef TESTFILEGRAILSBUILDER_HPP_
#define TESTFILEGRAILSBUILDER_HPP_


#include "TestfileBuilder.hpp"


namespace Tester
{
  class TestfileGrailsBuilder : public TestfileBuilder
  {
    public:
      void build_dependencies();

    protected:
      virtual std::string build_package() = 0;
      virtual std::string build_imports() = 0;


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

#endif // TESTFILEGRAILSBUILDER_HPP_
