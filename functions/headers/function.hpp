
#pragma once

#include <iostream>
#include <functional>
#include "../../Request/headers/request.hpp"
#include "../../Response/header/response.hpp"


#define function(req, res) []( Request req, Response res)
// #define function(req) []( auto req)
std::function<void(char*)> function1;

// typedef void(char*) Func;



class App{

public:
  App(){}
  ~App(){}
  template<typename PATH, typename F>void get(PATH path, F f  ){
    f(123, 123);
  }

};


class Console{
  public:

    template<typename... Args> void log( Args... args){
      // std::cout << __PRETTY_FUNCTION__ <<"\n";
      (std::cout << ... << std::forward<Args>(args));
    }
}console;

