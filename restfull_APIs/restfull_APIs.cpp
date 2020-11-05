
#include "restfull_APIs.hpp"



void push(const char* path, void(*CALLBACK)(Request, Response) ){

    GET get;
    get.PATH = path;
    get.CALLBACK = CALLBACK;

    auto pair = std::make_pair(path,get );
    REST_APIS.insert(pair);

}


void execute_restfull_APIs(Request req, Response res){

    for(ITR itr = REST_APIS.begin(); itr != REST_APIS.end(); ++itr){
        if(req.get_path() == itr->first){
            itr->second.CALLBACK(req,res);
        }
    }
}