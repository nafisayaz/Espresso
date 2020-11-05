

#pragma once

#include <vector>
#include <istream>
#include <string>
#include <iterator>

class Request{

    public:
        Request(){}
        ~Request(){}
        const char* header();
        void set_header(const char* header);
        std::string get_path();
    private:
        const char*         m_header;

};

#include "request.cpp"

// #define header get_header()

