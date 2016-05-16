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
    typedef pair<std::string, std::string> Range;

    typedef struct param_info
    {
      std::string type;
      CollectorData::Range range;
    } ParamInfo;

    public:
      CollectorData();
      ~CollectorData();

      void collect_data( const char*, ... );

    private:
      std::string method_name;
      std::map<std::string, CollectorData::ParamInfo> params;
  };
}

#endif // COLLECTORDATA_HPP_
