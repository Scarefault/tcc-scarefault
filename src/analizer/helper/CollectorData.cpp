#include "CollectorData.hpp"

namespace Helper
{
  ADDRESS address_collector;

// ------------------ PUBLIC FUNCTIONS IMPLEMENTATION -------------------
  CollectorData::CollectorData()
  {
    address_collector = this;
  }

  void CollectorData::collect_data( const char * format, ... )
  {
    va_list arguments;
    va_start( arguments, format );

    std::vector<std::string> info_method;

    while( *format != EOL )
    {
      std::string collected_text;

      switch( *format )
      {
        case PACKAGE:
          this->set_package( va_arg( arguments, char * ) );
          break;
        case CLASS:
          this->set_class( va_arg( arguments, char * ) );
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

    this->set_methods( info_method );
  }

  Helper::Data* CollectorData::get_data()
  {
    return &data;
  }

// ------------------ PRIVATE FUNCTIONS IMPLEMENTANTION --------------------

  void CollectorData::set_package( std::string name )
  {
    this->data.package_name = name;
  }

  void CollectorData::set_class( std::string name )
  {
    this->data.class_name = name;

    identify_category( name );
  }

  void CollectorData::set_methods( std::vector<std::string> info )
  {
    if( !info.empty() )
    {
      Helper::Method method;
      method.name = info[ 0 ];

      method.params = collect_params( info );

      this->data.methods.push_back( method );
    } else
    {
      // Nothing To do
    }
  }

  std::vector<Helper::Param>
  CollectorData::collect_params( std::vector<std::string> info )
  {
    std::vector<Helper::Param> params;

    if( info.size() > 1 )
    {
      std::string collected_params = info[ 1 ];

      while( !collected_params.empty() )
      {
        Helper::Param new_param = create_param( &collected_params );
        params.push_back( new_param );
      }
    } else
    {
      // Nothing To do
    }

    return params;
  }

  Helper::Param CollectorData::create_param( std::string * text )
  {
    std::size_t comma_position = text->find( "," );

    Helper::Param new_param;

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

  Helper::Param CollectorData::find_param( std::string text )
  {
    std::size_t blank_position = text.find( " " );
    std::string type = text.substr( 0, blank_position );
    std::string name = text.substr( blank_position+1 );

    Helper::Param new_param;

    new_param.param_name = name;
    new_param.param_type = type;

    return new_param;
  }

  void CollectorData::identify_category( std::string name )
  {
    if( name.compare( "Controller" ) != std::string::npos )
    {
      std::size_t found = name.find( "Controller" );
      std::string category = name.substr( found );
      std::string domain_base = name.substr( 0, found );

      collect_proprieties( domain_base );

      this->data.domain_base = domain_base;
      this->data.category_MVC = category;
    } else
    {
      // Nothing to do
    }
  }

  void CollectorData::collect_proprieties( std::string domain )
  {
    std::fstream domain_stream;

    std::string domain_file( PATH_DOMAIN );
    domain_file.append( domain );
    domain_file.append( ".groovy" );

    domain_stream.open( domain_file, READ );

    if( domain_stream.is_open() )
    {
      std::string content_file = extract_content_file( &domain_stream );
      std::vector<std::string> content = extract_words( content_file, " ={" );

      for( int i = 0; i < content.size(); i++ )
      {
        Helper::Propriety new_propriety;

        if( is_type( content[ i ] ) )
        {
          new_propriety.name = content[i+1];
          new_propriety.type = content[i];

          data.proprieties.push_back( new_propriety );
        }

        if( !content[i].compare( "constraints" ) )
        {
          collect_constraints( content_file );
        }
      }

      domain_stream.close();
    } else
    {
      std::cout << "Unable to open "<< domain_file << "..." << std::endl;
    }
  }

  void CollectorData::collect_constraints( std::string text )
  {
    std::size_t found = text.find( "constraints" );
    std::string sub = text.substr( found+11 );
    std::size_t bracket_found = sub.find( "}" );
    std::string substring = sub.substr( 0, bracket_found );

    std::vector<std::string> words = extract_words( substring, " ={:,(" );
    std::vector<Propriety> proprieties = data.proprieties;

    for( int i = 0; i < proprieties.size(); i++ )
    {
      if( !proprieties[ i ].name.compare( words[ 0 ] ) )
      {
        int k = 1;

        while( words[ k ].compare( ")" ) )
        {
          Helper::Constraint new_constraint;
          new_constraint.name = words[ k ];
          new_constraint.value = words[ k+1 ];

          data.proprieties[ i ].contraints.push_back( new_constraint );
          k += 2;
        }

          words.erase( words.begin(), words.begin()+k+1 );
      }
    }
  }

  std::string CollectorData::extract_content_file( std::fstream * file )
  {
    std::string content;
    std::string line;

    while( std::getline( *file, line ) )
    {
      content.append( line );
    }

    return content;
  }

  char * CollectorData::convert_string_to_cstring( std::string text )
  {
    char * cstring = new char[text.size() + 1];
    std::copy( text.begin(), text.end(), cstring );
    cstring[ text.size() ] = '\0';

    return cstring;
  }

  std::vector<std::string>
  CollectorData::extract_words( std::string text, std::string delimiters )
  {
    char * cdelimiters = convert_string_to_cstring( delimiters );
    char * ctext = convert_string_to_cstring( text );

    std::vector<std::string> words;
    char * phrase = strtok( ctext, cdelimiters );

    while( phrase != NULL )
    {
      std::string token( phrase );
      words.push_back( token );
      phrase = strtok( NULL, cdelimiters );
    }

    delete[] cdelimiters;
    delete[] ctext;
    delete[] phrase;

    return words;
  }

  bool CollectorData::is_type( std::string token )
  {
    bool result = true;
    std::vector<std::string> types {
      "short", "Short", "int", "Integer", "long", "Long", "float", "Float",
      "double", "Double", "String", "Date", "List" };

    for( int i = 0; i < types.size(); i++ )
    {
      if( !token.compare( types[ i ] ) )
      {
        result = true;
        break;
      } else
      {
        result = false;
      }
    }

    return result;
  }
}
