
#include <string>
#include "espresso.hpp"

espresso::espresso(): m_module(Http("0.0.0.0"))
{
}

espresso::~espresso()
{
}

espresso& espresso::operator()(const char* module){
    std::string str_module(module);
    if(str_module  == "http"){
        Http http("0.0.0.0");
        m_module = http;
        
        return *this;
    }
}

void espresso::run(int port, const char* optional_msg){
 
    m_module.init(port, optional_msg);
    m_module.run();
   

}

void espresso::get(const char* path, void(*foo)(Request, Response)){
    
    push(path, foo);
}
void espresso::post(const char* path, void(*foo)(Request, Response)){
    push_post(path, foo);
}

void espresso::use(const char* directory){
    m_use.use(directory);
}
void espresso::get_use(){
    m_use.get_use();
}







