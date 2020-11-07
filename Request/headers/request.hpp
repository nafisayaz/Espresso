

#pragma once

#include <vector>
#include <istream>
#include <string>
#include <iterator>
#include <functional>
#include "../../util_lib/fileSystem/header/filesystem.hpp"
#include "../../util_lib/parser/header/parser.hpp"



struct Request{

    public:
        Request(){}
        ~Request(){}

        const char* header();
        void set_header(const char* header);
        auto parse_header(const std::string header, std::function<char()> func)->std::vector<std::string>;
        void parse_element(const std::string element);
        void initialize(const std::vector<std::string>& data);

        std::string get_path();
        std::string accepts(){};
        std::string ip(){};
        std::string state(){};

    
        const char*         m_header; // set
        std::string         m_baseUrl;
        std::string         m_body;
        std::string         m_hostname; // set
        std::string         m_port; // set
        std::string         m_ip; 
        std::string         m_method; // set
        std::string         m_query; 
        std::string         m_params; // set
        std::string         m_filename;
        std::string         m_protocol; // set
        std::string         m_state; // set
        std::string         m_userAgent; // set

};

#include "../sources/request.cpp"

// #define header get_header()

