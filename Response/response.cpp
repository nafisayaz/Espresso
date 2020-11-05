

#include "response.hpp"

void Response::send(std::string message){
    m_message = message;
}

void Response::sendfile(std::string filePath){

    const char* c_filePath = filePath.c_str();
    std::fstream f(c_filePath);//, std::ios::in);
    if(!f.good() ){
        m_message = "NOT FOUND : " + filePath;
        return;
    }
    std::string message((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    m_message = message;


}
std::string Response::get_message(){
    return m_message;
}

void Response::set_response(int socketfd){
    m_socketfd = socketfd;
}