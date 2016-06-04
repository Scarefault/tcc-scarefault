#include "Helper.hpp"

namespace Helper
{
    bool is_type( std::string token )
    {
      bool result = true;
      std::vector<std::string> types {
        "short", "Short", "int", "Integer", "long", "Long", "float", "Float",
        "double", "Double", "String", "Date", "List", "boolean" };

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

    char * convert_string_to_cstring( std::string text )
    {
      char * cstring = new char[ text.size() + 1 ];
      std::copy( text.begin(), text.end(), cstring );
      cstring[ text.size() ] = '\0';

      return cstring;
    }
}
