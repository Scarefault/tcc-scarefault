#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "Log.hpp"

Log::Log()
{
}

void Log::info( std::string message )
{
  std::fstream* log_stream_ptr = this->get_log_stream();

  log_stream_ptr->open( LOGFILE, WRITE|APPEND );

  if( log_stream_ptr->is_open() )
  {
    log_stream_ptr->write( this->get_date_time( buffer ), date_time_size );
    log_stream_ptr->write( "\t", 2 );

    const unsigned int size_message = sizeof(char)*message.size();

    log_stream_ptr->write( message.c_str(), size_message );
    log_stream_ptr->write( "\n", 2 );
  } else
  {
    /* Nothing To Do. */
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
