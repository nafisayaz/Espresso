
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

    // if(!m_instance){
    //     return m_instance;
    // }else{
        if(str_module  == "http"){
            Http http("0.0.0.0");
            m_module = http;
            // m_instance = this;
            // return m_instance;
            return *this;
            // return 1;
        }
    // }

}

void espresso::run(int port, const char* optional_msg){

    
    // std::future<void> f2 = std::async(std::launch::async, [this, &port, &optional_msg]{
    //     m_module.init(port, optional_msg);
    //     m_module.run();
    //  });
    // f2.get();

    // m_run_thread = std::thread([this, &port, &optional_msg]{
        m_module.init(port, optional_msg);
        m_module.run();
    //  });
    // m_run_thread.join();

}

void espresso::get(const char* path, void(*foo)(Request, Response)){
    // std::future<void> f = std::async(std::launch::async, [&path, &foo]{
    //     foo(path, path);
        
    //  });
    // return f;

    // m_get_thread = std::thread([&path, &foo]{
        push(path, foo);

    // }, this);
    // m_get_thread.join();
}

void espresso::use(const char* directory){
    m_use.use(directory);
}
void espresso::get_use(){
    m_use.get_use();
}







