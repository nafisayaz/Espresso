
#include "restfull_APIs.hpp"



void push(const char* path, void(*CALLBACK)(Request, Response) ){

    GET get;
    get.PATH = path;
    get.CALLBACK = CALLBACK;

    auto pair = std::make_pair(path,get );
    REST_APIS.insert(pair);

}

void push_post(const char* path, void(*CALLBACK)(Request, Response) ){

    POST post;
    post.PATH = path;
    post.CALLBACK = CALLBACK;

    auto pair = std::make_pair(path, post );
    REST_APIS_POST.insert(pair);

}

template<class T> void execute( const std::map<std::string, T>& REST_APIS, Request req, Response res ){
    for(auto itr = REST_APIS.begin(); itr != REST_APIS.end(); ++itr){
        if(req.get_path() == itr->first){
            itr->second.CALLBACK(req,res);
        }
    }
}

auto which_API(const Request& req, const Response& res)->void{

    if(req.m_method == "GET") {  execute(REST_APIS, req, res); }
    else if(req.m_method == "POST") { execute(REST_APIS_POST, req, res); }
    // else if(req.m_method == "/put") { execute(REST_APIS_PUT, req, res); }
    // else if(req.m_method == "/delete") { execute(REST_APIS_DELETE, req, res); }
    else { }

}

void execute_restfull_APIs(Request req, Response res){ which_API(req, res); }