
#pragma once
#include <future>
#include <thread>
#include "../http/headers/http.hpp"
#include "../util_lib/functions/headers/function.hpp"
#include "../restfull_APIs/restfull_APIs.hpp"
#include "../util_lib/fileSystem/header/filesystem.hpp"




class espresso
{

    public:
        espresso();
        ~espresso();

        espresso& operator()(const char* module);
        void run(int port, const char* optional_msg);

        void get(const char* path, void(*foo)(Request, Response));
        void post(const char* path, void(*foo)(Request, Response));
        void use(const char* directory);
        void get_use();

    private:
        Http                m_module;
        Use                 m_use;
        // std::thread         m_run_thread;
        // std::thread         m_get_thread;

        // static espresso*     m_instance; 

    
};

// espresso*     espresso::m_instance = nullptr; 

#include "espresso.cpp"


