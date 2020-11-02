

#include "response.hpp"

void Response::send(std::string message){
    m_message = message;
}
std::string Response::get_message(){
    return m_message;
}

void Response::set_response(int socketfd){
    m_socketfd = socketfd;
}