#ifndef COLLECTORDATA_HPP_
#define COOLECTORDATA_HPP_

#include <string>
#include <utility>
#include <cstdarg>
#include <map>

namespace Helper
{
  class CollectorData
  {
    typedef struct input_file
    {
      std::string package_name;
      std::string class_name;
    } InputFile;

    public:
      CollectorData();
      ~CollectorData();

    private:
      InputFile input;

      void set_package_name( std::string );
      void set_class_name( std::string );

      std::string get_package_name();
      std::string get_class_name();
  };
}

#endif // COLLECTORDATA_HPP_
