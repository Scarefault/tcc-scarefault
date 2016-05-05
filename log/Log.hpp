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
  const int date_time_size = 28;

  enum Category { INFO, SUCCESS, WARNING, ERROR };

  typedef struct log_cat
  {
    std::string type;
    int size;
  } Log_Category;

  class Log
  {
    public:
      void message( Category, std::string );

    private:
      char buffer[date_time_size];
      std::fstream log_stream;
      std::string last_message;
      int times_counted;
      Log_Category category;

      char* get_date_time( char* );
      std::fstream* get_log_stream();
      void set_log_category( Category );
      void verify_last_message( std::string );
      void write( std::fstream&, std::string );
      void write_date_time( std::fstream& );
      void write_message( std::fstream&, std::string );
      void write_times( std::fstream& );
  };
}

#endif // LOG_HPP_
