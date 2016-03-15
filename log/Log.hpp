#ifndef LOG_HPP_ 
#define LOG_HPP_

#define LOGFILE "scarefault.log"

#define WRITE std::fstream::out
#define APPEND std::fstream::app

#include <fstream>
#include <string>

class Log
{
  public:
    Log();

    void info( std::string );

  private:
    std::fstream log_stream;

    std::fstream* get_log_stream();
};

#endif // LOG_HPP_
