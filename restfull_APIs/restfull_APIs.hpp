
#pragma once

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <functional>
#include "../Request/request.hpp"
#include "../Response/response.hpp"


struct GET{
    const char*                          PATH;
    void(*CALLBACK)(Request, Response);
};
typedef std::map<std::string, GET> REST_MAP;
typedef std::map<std::string, GET>::iterator ITR; 
static REST_MAP REST_APIS ;

struct POST{
    const char*                          PATH;
    void(*CALLBACK)(const char*, const char*);
};
typedef std::map<std::string, POST> REST_POST;
typedef std::map<std::string, POST>::iterator ITR_POST; 
static REST_MAP REST_APIS_POST ;

struct DELETE{
    const char*                          PATH;
    void(*CALLBACK)(const char*, const char*);
};
typedef std::map<std::string, DELETE> REST_DELETE;
typedef std::map<std::string, DELETE>::iterator ITR_DELETE; 
static REST_MAP REST_APIS_DELETE ;

struct PUT{
    const char*                          PATH;
    void(*CALLBACK)(const char*, const char*);
};
typedef std::map<std::string, PUT> REST_PUT;
typedef std::map<std::string, PUT>::iterator ITR_PUT; 
static REST_MAP REST_APIS_PUT ;


#include "restfull_APIs.cpp"
