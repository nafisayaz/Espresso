


#pragma once

#include <iostream>

class Response{

    public:
        Response(){}
        ~Response(){}
        // const char* header();
        // void set_header(const char* header);

        void send(std::string message);
        std::string get_message();
        void set_response(int socketfd);

    private:
        int                     m_socketfd;
        static std::string      m_message;

};
std::string Response::m_message = {};

#include "response.cpp"