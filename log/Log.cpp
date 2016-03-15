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
    time_t rawtime;
    time( &rawtime );

    std::cout << ctime(&rawtime) << std::endl;

    const unsigned int size_message = sizeof(char)*message.size();
    const unsigned int size_time = sizeof( ctime( &rawtime ) );

    log_stream_ptr->write( ctime( &rawtime ), size_time );
    log_stream_ptr->write( " - ", 3 );

    log_stream_ptr->write( message.c_str(), size_message );
    log_stream_ptr->write( "\n", 2 );
  } else
  {
    /* Nothing To Do. */
  }

  log_stream_ptr->close();
}

std::fstream* Log::get_log_stream()
{
  return &this->log_stream;
}
