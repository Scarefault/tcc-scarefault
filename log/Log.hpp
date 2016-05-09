#ifndef LOG_HPP_ 
#define LOG_HPP_

#define LOGFILE "log/scarefault.log"

#define WRITE std::fstream::out
#define APPEND std::fstream::app


#include <fstream>
#include <string>

namespace LogSystem
{
  const std::string DATETIME_FORMAT( "[%d %B %Y %a %T] " );
  const int DATETIME_SIZE = 28;

  enum Category { INFO, SUCCESS, WARNING, ERROR };

  typedef struct log_cat
  {
    std::string type;
    int size;
  } LogCategory;

  class Log
  {
    public:
      void message( LogSystem::Category, std::string );

    private:
      char buffer[ DATETIME_SIZE ];
      std::fstream log_stream;
      LogCategory category;

      char* get_date_time( char* );
      std::fstream* get_log_stream();

      void set_log_category( Category );
      void verify_last_message( std::string );

      void write( std::fstream&, std::string );
      void write_date_time( std::fstream& );
      void write_message( std::fstream&, std::string );
  };
}

#endif // LOG_HPP_
