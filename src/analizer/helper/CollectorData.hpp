#ifndef COLLECTORDATA_HPP_
#define COOLECTORDATA_HPP_

#include <string>
#include <cstdarg>
#include <iostream>

namespace Helper
{
  typedef struct file_param
  {
    std::string param_name;
    std::string param_type;
  } Param;

  typedef struct file_method
  {
    std::string method_name;
    std::string return_type;
    std::vector<Param> params;
  } Method;

  typedef struct file_data
  {
    std::string package_name;
    std::string class_name;
    std::vector<Method> methods;
  } Data;


  class CollectorData
  {

    public:
      void collect_data( const char *, ... );

    private:
      static const char EOL = '\0';
      static const char PACKAGE = 'p';
      static const char CLASS = 'c';


      void set_package_name( std::string );
      void set_class_name( std::string );

      std::string get_package_name();
      std::string get_class_name();
  };
}

#endif // COLLECTORDATA_HPP_
