#ifndef TESTGENERATOR_HPP_
#define TESTGENERATOR_HPP_


#include <string>
#include <vector>


/*
 * This namespace define everything associate to the Generator of Tests.
 */
namespace Generator
{
  class TestGenerator;


  /*
   * Define a new type to keep a reference to the address of the
   *   TestGenerator.
   */
  typedef TestGenerator* ADDRESS;

  /*
   * It's a global variable. Currently, it's necessary to allow access the
   *   references of all Test Generators. With this, Is possible access a
   *   Test Generator, created in grammar file, in other files.
   */
  extern vecto<ADDRESS> addresses_test_generators;


  /*
   * Class that define mechanisms to generate tests, starting to the source
   *   file.
   */
  class TestGenerator
  {
    public:
      TestGenerator( std::string name = "without name",
                     std::vector<int> input, int output );
      TestGenerator( std::string name = "without name" );

      std::string generate_method_header();
      std::string generate_expectations();
      std::string generate_call_method();
      std::string generate_assertation();

      void set_method_name( std::string name );
      void set_scenario_out( int output );
      void set_scenario_name( std::string name );
      void set_scenario_entries( std::vector<int> input );

    private:
      int              scenario_out;
      std::string      scenario_name;
      std::vector<int> scenario_entries;

      std::string      method_name;


      int              get_scenario_out();
      std::string      get_method_name()
      std::string      get_scenario_name();
      std::vector<int> get_scenario_entries();
  };
}

#endif // TESTGENERATOR_HPP_
