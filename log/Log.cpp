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
    set_log_category( log_category );
    verify_last_message( message );

    std::fstream* log_stream_ptr = this->get_log_stream();

    log_stream_ptr->open( LOGFILE, WRITE|APPEND );

    if( log_stream_ptr->is_open() )
    {
      write( *log_stream_ptr, message );
    } else
    {
      std::cout << std::endl << "Something Wrong. File not opened..."
                << std::endl;
    }

    log_stream_ptr->close();
  }

  void Log::set_log_category( Category log_category )
  {
    switch( log_category )
    {
      case INFO:
        this->category.type = "INFO";
        this->category.size = 4;

      break;

      case SUCCESS:
        this->category.type = "SUCCESS";
        this->category.size = 7;

      break;

      case WARNING:
        this->category.type = "WARNING";
        this->category.size = 7;

      break;

      case ERROR:
        this->category.type = "ERROR";
        this->category.size = 5;

      break;

      default:
        this->category.type = "NO CATEGORY";
        this->category.size = 11;
    }
  }

  void Log::verify_last_message( std::string message )
  {
    if( message == this->last_message )
    {
      this->times_counted++;
    } else
    {
      this->times_counted = 0;
    }

    this->last_message = message;
  }

  void Log::write( std::fstream& log_stream, std::string message )
  {
    write_date_time( log_stream );
    write_message( log_stream, message );
    write_times( log_stream );
  }

  void Log::write_date_time(std::fstream& log_stream )
  {
    log_stream.write( this->get_date_time( buffer ), date_time_size );
    log_stream.write( "\t", 2 );
  }

  void Log::write_message( std::fstream& log_stream, std::string message )
  {
    const unsigned int size_message = sizeof(char)*message.size();

    log_stream.write( this->category.type.c_str(), this->category.size );
    log_stream.write( "\t", 2 );
    log_stream.write( message.c_str(), size_message );
  }

  void Log::write_times( std::fstream& log_stream )
  {
    std::string times( " ( " );
    times += std::to_string( this->times_counted + 1 );
    times += " )";

    log_stream.write( times.c_str(), times.size() );
    log_stream.write( "\n", 2 );
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
