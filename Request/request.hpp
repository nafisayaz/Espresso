

#pragma once

class Request{

    public:
        Request(){}
        ~Request(){}
        const char* header();
        void set_header(const char* header);
    private:
        const char*         m_header;

};

#include "request.cpp"

// #define header get_header()

