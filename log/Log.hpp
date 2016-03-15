#ifndef LOG_HPP_ 
#define LOG_HPP_

#define LOGFILE "log/scarefault.log"

#define WRITE std::fstream::out
#define APPEND std::fstream::app


#include <fstream>
#include <string>

namespace LogSystem
{
  const std::string date_time_format( "[%d %B %Y %a %T] " );
  const int date_time_size = 30;

  class Log
  {
    public:
      void info( std::string );

    private:
      char buffer[date_time_size];
      std::fstream log_stream;

      char* get_date_time( char* );
      std::fstream* get_log_stream();
  };
}

#endif // LOG_HPP_
