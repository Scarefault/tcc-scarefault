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
   *   Test Generator, created in parser file, in other files.
   */
  extern std::vector<ADDRESS> addresses_test_generators;


  /*
   * Class that define mechanisms to generate tests, starting to the source
   *   file.
   */
  class TestGenerator
  {
    public:
      TestGenerator( std::vector<int> input, int output,
                     std::string name = "\"without name\"" );
      TestGenerator( std::string name = "\"without name\"" );


      std::string generate_method_header();
      std::string generate_expectations();
      std::string generate_call_method();
      std::string generate_assertation();


      void add_scenario_entry( int );
      void add_import_name( std::string );
      void set_method_name( std::string );
      void set_scenario_out( int );
      void set_scenario_name( std::string );
      void set_scenario_entries( std::vector<int> );
      void set_package_name( std::string );
      void set_import_names( std::vector<std::string> );

    private:
      const static bool EXIST = true;
      const static bool NOT_EXIST = false;


      int scenario_out;
      std::vector<int> scenario_entries;
      std::vector<std::string> import_names;
      std::string scenario_name;
      std::string method_name;
      std::string package_name;


      int get_scenario_out();
      std::vector<int> get_scenario_entries();
      std::vector<std::string> get_import_names();
      std::string get_scenario_name();
      std::string get_method_name();
      std::string get_package_name();

      void remove_character( std::string*, char );
      bool check_whitespaces( std::string );
      bool check_quotes( std::string );
      std::string prepare_scenario_name();
  };
}

#endif // TESTGENERATOR_HPP_
