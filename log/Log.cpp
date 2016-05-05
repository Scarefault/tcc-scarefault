#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>

#include "Log.hpp"

namespace LogSystem
{
  void Log::message( Category log_category, std::string message )
  {
    std::string category;
    int category_size = 0;

    switch( log_category )
    {
      case INFO:
        category = "INFO";
        category_size = 4;

      break;

      case SUCCESS:
        category = "SUCCESS";
        category_size = 7;

      break;

      case WARNING:
        category = "WARNING";
        category_size = 7;

      break;

      case ERROR:
        category = "ERROR";
        category_size = 5;

      break;

      default:
        category = "NO CATEGORY";
        category_size = 11;

    }

    if( message == this->last_message )
    {
      this->times_counted++;
    } else
    {
      this->times_counted = 0;
    }

    this->last_message = message;

    std::fstream* log_stream_ptr = this->get_log_stream();

    log_stream_ptr->open( LOGFILE, WRITE|APPEND );

    if( log_stream_ptr->is_open() )
    {
      log_stream_ptr->write( this->get_date_time( buffer ), date_time_size );
      log_stream_ptr->write( "\t", 2 );

      const unsigned int size_message = sizeof(char)*message.size();

      std::string times( " ( " );
      times += std::to_string( this->times_counted + 1 );
      times += " )";

      log_stream_ptr->write( category.c_str(), category_size );
      log_stream_ptr->write( "\t", 2 );
      log_stream_ptr->write( message.c_str(), size_message );
      log_stream_ptr->write( times.c_str(), times.size() );
      log_stream_ptr->write( "\n", 2 );
    } else
    {
      std::cout << std::endl << "Something Wrong. File not opened..."
                << std::endl;
    }

    log_stream_ptr->close();
  }

  char* Log::get_date_time( char* buffer )
  {
    time_t t = time( 0 );
    strftime( buffer, date_time_size, date_time_format.c_str(),
              localtime( &t ) );

    return buffer;
  }

  std::fstream* Log::get_log_stream()
  {
    return &this->log_stream;
  }
}
