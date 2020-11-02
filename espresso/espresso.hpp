
#pragma once
#include <future>
#include <thread>
#include "../http/headers/http.hpp"
#include "../functions/headers/function.hpp"
#include "../restfull_APIs/restfull_APIs.hpp"




class espresso
{

    public:
        espresso();
        ~espresso();

        espresso& operator()(const char* module);
        void run(int port, const char* optional_msg);

        void get(const char* path, void(*foo)(Request, Response));

    private:
        Http                m_module;
        // std::thread         m_run_thread;
        // std::thread         m_get_thread;

        // static espresso*     m_instance; 

    
}import;

// espresso*     espresso::m_instance = nullptr; 

#include "espresso.cpp"


