   


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


int main(int argc, char const *argv[]) 
{ 

    auto sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = 8080;
    sock_addr.sin_addr.s_addr = INADDR_ANY;
    std::cout << "FROM Network\n";

    inet_pton(AF_INET, "127.0.0.1", &sock_addr.sin_addr );

    while( connect(sockfd,  reinterpret_cast<sockaddr*>(&sock_addr), sizeof(sock_addr)) == -1 ){
        std::cout << "NOT CONNECTED\n";
    }
    std::cout << "CONNECTED \n";

    if( send(sockfd, "123456", 7, 0) == -1 ){
        std::cout <<"send() failed" << "\n";
    }else{
        std::cout << "Sent !!";
    }

    char buffer[1024] = {0};
    int valread = read( sockfd , buffer, 1024); 
    printf("%s\n",buffer );



    return 1;
} 