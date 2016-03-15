#ifndef LOG_HPP_ 
#define LOG_HPP_

#define LOGFILE "scarefault.log"

#define WRITE std::fstream::out
#define APPEND std::fstream::app


#include <fstream>
#include <string>

const std::string date_time_format( "%d %B %Y%t%a%t%T - " );
const int date_time_size = 50;

class Log
{
  public:
    Log();

    void info( std::string );

  private:
    char buffer[date_time_size];
    std::fstream log_stream;

    char* get_date_time( char* );
    std::fstream* get_log_stream();
};

#endif // LOG_HPP_
