
#pragma once

#include "../../TcpListener/headers/tcpListener.hpp"
#include "../../restfull_APIs/restfull_APIs.hpp"
#include "../../parser/header/parser.hpp"
#include "../../reader/header/reader.hpp"


class Http : public TCPListener{

    public:
       Http( const char* ip_addr): TCPListener(ip_addr){

       }

    virtual void onClientConnected( int socket);
    virtual void onClientDisconnected(int socket);
    virtual void onMessageReceived(int clientSocket); //(int clientSocket, const char* msg, int length);

};

#include "../source/http.cpp"

