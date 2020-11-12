
#pragma once

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <functional>
#include "../Request/headers/request.hpp"
#include "../Response/header/response.hpp"




struct GET{
    const char*                          PATH;
    void(*CALLBACK)(Request, Response);
};
typedef std::map<std::string, GET> REST_MAP;
typedef std::map<std::string, GET>::iterator ITR; 
static REST_MAP REST_APIS ;

struct POST{
    const char*                          PATH;
    void(*CALLBACK)(Request, Response);
};
typedef std::map<std::string, POST> REST_POST;
typedef std::map<std::string, POST>::iterator ITR_POST; 
static REST_POST REST_APIS_POST ;

struct DELETE{
    const char*                          PATH;
    void(*CALLBACK)(const char*, const char*);
};
typedef std::map<std::string, DELETE> REST_DELETE;
typedef std::map<std::string, DELETE>::iterator ITR_DELETE; 
static REST_DELETE REST_APIS_DELETE ;

struct PUT{
    const char*                          PATH;
    void(*CALLBACK)(const char*, const char*);
};
typedef std::map<std::string, PUT> REST_PUT;
typedef std::map<std::string, PUT>::iterator ITR_PUT; 
static REST_PUT REST_APIS_PUT ;


// struct RESTFUL_APIs{ struct GET; struct POST; struct PUT; struct DELETE; };
// typedef std::map<std::string, RESTFUL_APIs> REST_MAP;
// typedef std::map<std::string, RESTFUL_APIs>::iterator ITR; 
// static REST_MAP REST_APIS ;


// enum Base { A, B, C, D, };
// enum Func { X, Y, }; 

// template<Base> struct GetBaseTraits;
// template<> struct GetBaseTraits<Base::A> { using type = RESTFUL_APIs::GET; };
// template<> struct GetBaseTraits<Base::B> { using type = RESTFUL_APIs::POST; };
// template<> struct GetBaseTraits<Base::C> { using type = RESTFUL_APIs::PUT; };
// template<> struct GetBaseTraits<Base::D> { using type = RESTFUL_APIs::DELETE; };

// template<Base b>
// typename GetBaseTraits<b>::type getBase(RESTFUL_APIs f);

// template<> typename GetBaseTraits<A>::type getBase<A>(RESTFUL_APIs f) { return f.a; }
// template<> typename GetBaseTraits<B>::type getBase<B>(RESTFUL_APIs f) { return f.b; }
// template<> typename GetBaseTraits<C>::type getBase<C>(RESTFUL_APIs f) { return f.c; }
// template<> typename GetBaseTraits<C>::type getBase<C>(RESTFUL_APIs f) { return f.c; }



#include "restfull_APIs.cpp"
