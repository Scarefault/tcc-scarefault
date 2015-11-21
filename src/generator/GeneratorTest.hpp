#ifndef GENERATORTEST_HPP_
#define GENERATORTEST_HPP_


#include <string>
#include <vector>


/*
 * This namespace define everything associate to the Generator of Tests.
 */
namespace Generator
{
  /*
   * Class that define mechanisms to generate tests, starting to the source
   *   file.
   */
  class GeneratorTest
  {
    public:
      GeneratorTest( std::string name = "without name",
                     std::vector<int> input, int output );
      GeneratorTest( std::string name = "without name" );

      std::string generate_method_header();
      std::string generate_expectations();
      std::string generate_call_method();
      std::string generate_assertation();

      int              get_scenario_out();
      std::string      get_method_name()
      std::string      get_scenario_name();
      std::vector<int> get_scenario_entries();

      void set_method_name( std::string name );
      void set_scenario_out( int output );
      void set_scenario_name( std::string name );
      void set_scenario_entries( std::vector<int> input );

    private:
      int              scenario_out;
      std::string      scenario_name;
      std::vector<int> scenario_entries;

      std::string      method_name;
  };
}

#endif // GENERATORTEST_HPP_
