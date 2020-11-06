
#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>



class Parser{
    public:
        void parse(const char* message );
        auto parse_header(const char* message )->void; //std::map<std::string, std::string>;
        std::string get_contentType();
        std::string get_m_path();
        auto get_oss(std::string msg);

    private:

        static std::string          m_method;
        static std::string          m_type;
        static std::string          m_path;
        static std::string          m_query;
        static std::string          m_hostname;
        static std::string          m_connection;
        static std::string          m_userAgent;
        static std::string          m_contentType;
};

std::string          Parser::m_method           = {};
std::string          Parser::m_type             = {};
std::string          Parser::m_path             = {};
std::string          Parser::m_query            = {};
std::string          Parser::m_hostname         = {};
std::string          Parser::m_connection       = {};
std::string          Parser::m_userAgent        = {};
std::string          Parser::m_contentType      = {};

#include "../source/parser.cpp"

