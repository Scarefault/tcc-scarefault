#include "CollectorBase.hpp"
#include "CollectorGrails.hpp"

namespace Collector
{
  ADDRESS address_collector;

// ------------------ PUBLIC FUNCTIONS IMPLEMENTATION -------------------
  CollectorBase::CollectorBase()
  {
    address_collector = this;
  }

  void CollectorBase::collect_data( const char * format, ... )
  {
    va_list arguments;
    va_start( arguments, format );

    std::vector<std::string> info_method;

    while( *format != EOL )
    {
      std::string collected_text;

      switch( *format )
      {
        case CLASS:
          this->collect_class( va_arg( arguments, char * ) );
          break;
        case METHOD:
          collected_text.assign( va_arg( arguments, char * ) );
          info_method.push_back( collected_text );
          break;
        case PARAM:
          collected_text.assign( va_arg( arguments, char * ) );
          info_method.push_back( collected_text );
          break;
      }

      format++;
    }

    this->collect_methods( info_method );
  }

  Collector::FileMVC * CollectorBase::get_data()
  {
    return &data;
  }

// ------------------ PRIVATE FUNCTIONS IMPLEMENTANTION --------------------

  void CollectorBase::collect_class( std::string name )
  {
    this->data.set_class( name );
  }

  void CollectorBase::collect_methods( std::vector<std::string> info )
  {
    if( !info.empty() )
    {
      Collector::Method method;
      method.name = info[ 0 ];

      method.params = collect_params( info );

      this->set_params_range( &method );
      this->set_test_cases( &method );
      this->data.insert_method( method );
    } else
    {
      // Nothing To do
    }
  }

  void CollectorBase::set_test_cases( Collector::Method * method )
  {
    int qtd_test_cases = this->collector_scarefault.get_test_cases()->size();

    for( int i = 0; i < qtd_test_cases; i++ )
    {
      this->collector_scarefault.get_test_case(i)->set_bound_method( method->name );

      int qtd_args = this->collector_scarefault.get_test_case(i)->get_arguments()->size();

      for( int j = 0; j < qtd_args; j++ )
      {
        this->collector_scarefault.get_test_case(i)->get_argument(j)->bound_param = method->params[j].name;
      }
    }

    method->test_cases = this->collector_scarefault.get_test_cases_by_copy();
    this->collector_scarefault.clear_test_cases();
  }

  void CollectorBase::set_params_range( Collector::Method * method )
  {
    if( !method->params.empty() )
    {
      int index = this->collector_scarefault.get_params()->size()-1;

      while( !this->collector_scarefault.get_params()->empty() )
      {
        Collector::Param compared_param = collector_scarefault.get_param( index );

        for( int i = method->params.size()-1; i >= 0; i-- )
        {
          if( !method->params[ i ].name.compare( compared_param.name ) )
          {
            method->params[ i ].range = compared_param.range;
            this->collector_scarefault.get_params()->pop_back();
          } else
          {
            // Nothing to do
          }
        }

        index--;
      }
    } else
    {
      // Nothing to do
    }
  }

  std::vector<Collector::Param>
  CollectorBase::collect_params( std::vector<std::string> info )
  {
    std::vector<Collector::Param> params;

    if( info.size() > 1 )
    {
      std::string collected_params = info[ 1 ];

      while( !collected_params.empty() )
      {
        Collector::Param new_param = create_param( &collected_params );
        params.push_back( new_param );
      }
    } else
    {
      // Nothing To do
    }

    return params;
  }

  Collector::Param CollectorBase::create_param( std::string * text )
  {
    std::size_t comma_position = text->find( "," );

    Collector::Param new_param;

    if( comma_position != std::string::npos )
    {
      std::string found_param = text->substr( 0, comma_position );

      new_param = find_param( found_param );

      text->erase( text->begin(), text->begin()+comma_position+1 );
    } else
    {
      new_param = find_param( *text );

      text->clear();
    }

    return new_param;
  }

  Collector::Param CollectorBase::find_param( std::string text )
  {
    std::size_t blank_position = text.find( " " );
    std::string type = text.substr( 0, blank_position );
    std::string name = text.substr( blank_position+1 );

    Collector::Param new_param;

    new_param.name = name;
    new_param.type = type;

    return new_param;
  }
}
