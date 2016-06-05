#ifndef FILEMVC_HPP_
#define FILEMVC_HPP_

#include <vector>
#include <string>

#include "FileBase.hpp"
#include "Propriety.hpp"

namespace Collector
{
  class FileMVC : public FileBase
  {
    public:
      std::string layer;
      std::string model_base;
      std::string package;

      std::vector<Propriety> proprieties;

      void set_package( std::string );
  };
}

#endif // FILEMVC_HPP_
