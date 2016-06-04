#ifndef FILEMVC_HPP_
#define FILEMVC_HPP_

#include <vector>
#include <string>

#include "FileBase.hpp"

namespace Collector
{
  class Constraint
  {
    public:
      std::string name;
      std::string value;
  };

  class Propriety
  {
    public:
      std::string name;
      std::string type;
      std::vector<Constraint> contraints;
  };

  class FileMVC : public FileBase
  {
    public:
      std::string layer;
      std::string domain_base;
      std::string package_name;

      std::vector<Propriety> proprieties;
  };
}

#endif // FILEMVC_HPP_
