// Server program 
#include <arpa/inet.h> 
#include <errno.h> 
#include <netinet/in.h> 
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <strings.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <iostream>

#define PORT 8080 
#define MAXLINE 1024 


int max(int x, int y) 
{ 
    if (x > y) 
        return x; 
    else
        return y; 
} 
int main() 
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0); 
    // bzero(&servaddr, sizeof(servaddr)); 
    
    sockaddr_in servaddr;
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    inet_pton(AF_INET, "0.0.0.0", &servaddr.sin_addr );
    int opt = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0){
        std::cout << "Failed to set SO_REUSEADDR option. "<< "\n";
    }

    
    pid_t childpid;
    const int on = 1; 
    char* message = "Hello Client"; 
    void sig_chld(int); 
  
    /* create listening TCP socket */
    
  
    // binding server addr structure to listenfd 
    while( bind(listenfd, reinterpret_cast<sockaddr*>(&servaddr), sizeof(servaddr)) == -1){
      std::cout<< "m_socket binding failed!! " <<std::endl;
    }
    listen(listenfd, 10); 
  
    /* create UDP socket */
    int udpfd = socket(AF_INET, SOCK_DGRAM, 0); 
    while( bind(udpfd, reinterpret_cast<sockaddr*>(&servaddr), sizeof(servaddr)) == -1){
      std::cout<< "m_udpSocket binding failed!! " <<std::endl;
    }
  
    // clear the descriptor set 
    
    fd_set rset; 
    FD_ZERO(&rset); 
  
    // get maxfd 
    int maxfdp1 = max(listenfd, udpfd) + 1; 
    for (;;) { 
  
        // set listenfd and udpfd in readset 
        FD_SET(listenfd, &rset); 
        FD_SET(udpfd, &rset); 
  
        // select the ready descriptor 
        std::cout << "line: " << __LINE__ <<"\n";
        int nready = select(maxfdp1, &rset, NULL, NULL, NULL); 
        std::cout << "line: " << __LINE__ <<"\n";
  
        // if tcp socket is readable then handle 
        // it by accepting the connection 
        if (FD_ISSET(listenfd, &rset)) { 

            int connfd = accept(listenfd, nullptr, nullptr);//(struct sockaddr*)&cliaddr, &length); 
            if ((childpid = fork()) == 0) { 
                close(listenfd);
                char buffer[MAXLINE];  
                bzero(buffer, sizeof(buffer)); 
                printf("Message From TCP client: "); 
                read(connfd, buffer, sizeof(buffer)); 
                puts(buffer); 
                write(connfd, (const char*)message, sizeof(buffer)); 
                close(connfd); 
                exit(0); 
            } 
            close(connfd); 
        } 
        
    } 
} 