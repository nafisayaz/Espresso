

#pragma once


#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/errno.h>
#include <errno.h>
#include <sys/socket.h>
#include <memory>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sstream>




class TCPListener{

  public:
    TCPListener(){}
    TCPListener( const char* ip_addr): m_ipAddress(ip_addr){}
    // ~TCPListener(){ delete m_ipAddress; }

    int init(int port, const char* optional_msg);
    int run();

  protected:
    virtual void onClientConnected( int socket);
    virtual void onClientDisconnected(int socket);
    virtual void onMessageReceived(int clientSocket);//(int clientSocket, const char* msg, int length);

    void response(int clientSocket, const char* msg, int length );
    void broadcast(int clientSocket, const char* msg, int length );



  private:

    const char*   m_ipAddress;
    int           m_port;
    int           m_socket;
    int           m_udpSocket;
    fd_set        m_master;
    sockaddr_in   m_sock_addr;

};

#include "../source/tcpListener.cpp"
