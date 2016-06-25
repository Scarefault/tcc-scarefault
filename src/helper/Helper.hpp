#ifndef HELPER_HPP_
#define HELPER_HPP_


#define READ std::fstream::in


#define PATH_CONTROLLER "guestbook/grails-app/controllers/guestbook/"
#define PATH_DOMAIN "guestbook/grails-app/domain/guestbook/"


#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <locale>


namespace Helper
{
    bool is_type( std::string );

    int count_char( std::string );

    char * convert_string_to_cstring( std::string );

    bool is_string( std::string );
    bool is_integer( std::string );
    bool is_floating( std::string );
    bool is_boolean( std::string );

    std::string extract_content_file( std::string );
    std::string remove_spaces( std::string );
    std::string convert_to_lower( std::string );

    std::vector<std::string> extract_words( std::string, std::string );
}

#endif
