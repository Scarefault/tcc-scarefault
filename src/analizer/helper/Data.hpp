#ifndef DATA_HPP_
#define DATA_HPP_

#include <vector>
#include <string>

namespace Helper
{
  typedef struct file_param
  {
    std::string param_name;
    std::string param_type;
  } Param;

  typedef struct file_method
  {
    std::string name;
    std::string return_type;
    std::vector<Param> params;
  } Method;

  typedef struct file_data
  {
    std::string package_name;
    std::string class_name;
    std::vector<Method> methods;
  } Data;
}

#endif // DATA_HPP_
