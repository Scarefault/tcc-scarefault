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

namespace Helper
{
    char * convert_string_to_cstring( std::string );
    bool is_type( std::string );
    std::string extract_content_file( std::string );
    std::vector<std::string> extract_words( std::string, std::string );
}

#endif
