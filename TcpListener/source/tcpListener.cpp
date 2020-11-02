

#include "../headers/tcpListener.hpp"

int TCPListener::init(int port, const char* optional_msg){
  m_port = port;

  m_socket = socket(AF_INET, SOCK_STREAM, 0);
  m_udpSocket = socket(AF_INET, SOCK_DGRAM, 0);

  sockaddr_in sock_addr;
  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(m_port);
  sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  inet_pton(AF_INET, m_ipAddress, &sock_addr.sin_addr );

  int opt = 1;
  if (setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0){
    std::cout << "Failed to set SO_REUSEADDR option. "<< "\n";
  }

  // FOR SOCKET STREAM
  while( bind(m_socket, reinterpret_cast<sockaddr*>(&sock_addr), sizeof(sock_addr)) == -1){
      std::cout<< "m_socket binding failed!! " <<std::endl;
  }


  // FOR UDP DGRAM
  while( bind(m_udpSocket, reinterpret_cast<sockaddr*>(&sock_addr), sizeof(sock_addr)) == -1){
      std::cout<< "m_udpSocket binding failed!! " <<std::endl;
  }
  std::cout<< optional_msg << m_port <<std::endl;

  if( listen(m_socket, 5) == -1){
    std::cout<<"listen() failed"<< "\n";
    return 0;
  }

  FD_ZERO(&m_master);

  FD_SET(m_socket, &m_master);
  FD_SET(m_udpSocket, &m_master);

  m_sock_addr = sock_addr;

  return 0;

}


int max(int x, int y) 
{ 
    if (x > y) 
        return x; 
    else
        return y; 
} 

int TCPListener::run(){

  fd_set copy; //= m_master;
  memcpy(&copy, &m_master, sizeof(m_master));

  while (true){
    int s = max(m_socket, m_udpSocket) +1 ;
    int socketCount = select(s, &copy, nullptr, nullptr, nullptr);
    
    if( socketCount < 0){
        std::cout <<"selction error!! \n";
        return 1;
    }else
    {
        // for(int i=0; i < socketCount; ++i){
          // std::cout <<"line: "<<__LINE__ << "socketCount: "<< socketCount<<"\n";
          if (FD_ISSET(m_socket, &copy)){
            // continue;
          // if(m_socket == m_socket){
            int  client = accept(m_socket, nullptr, nullptr);

            FD_SET(client, &m_master);
            onMessageReceived(client);
          // TO DO SOMETHING
            onClientConnected(client);
          }else{
            char buffer[4096];
            memset(buffer, 0, 4096);

            int byteIn = recv(m_socket, buffer, 4096, 0);

            if(byteIn <= 0){
              //TODO: CLIENT DISCONNECTED
              onClientDisconnected(m_socket);

              close(m_socket); 
              FD_CLR(m_socket, &m_master);


            }else{
              // onMessageReceived(m_socket, buffer, byteIn); 
            }
          }
        // }
    }

    // int new_socket;
    //   sockaddr_in their_addr {};
	  //   socklen_t  their_size {};
    //   if ((new_socket = accept(m_socket, reinterpret_cast<sockaddr*>(&their_addr), &their_size))<0){ 
    //       perror("accept"); 
    //       exit(EXIT_FAILURE); 
    //   }
    //   std::cout << "m_socket: " << m_socket <<"\n";
    //   char buffer[1024] = {0};
    //   int valread = read( new_socket , buffer, 1024); 
    //   printf("%s\n",buffer ); 
    //   char *hello = "Hello Nafis from server"; 
    //   send(new_socket , hello , strlen(hello) , 0 ); 
    //   printf("message sent\n"); 

    
  }

  return 0;

}



void TCPListener::response(int clientSocket, const char* msg, int length ){

  send(clientSocket, msg, length, 0);
  close(clientSocket);

}

void TCPListener::broadcast(int clientSocket, const char* msg, int length ){

  int socketCount = select(0, &m_master, nullptr, nullptr, nullptr);
  for(int outsocket=0; outsocket < socketCount; ++outsocket){
    
    if(!FD_ISSET(outsocket, &m_master))
      continue;

    if(outsocket != m_socket){
      response(outsocket, msg, length);
    }
  }
} 

void TCPListener::onClientConnected(int socket){

  std::ostringstream oss;
  oss << "HTTP/1.1 200 OK\r\n";
  oss << "Cache-Control: no-cache, private\r\n";
  oss << "Content-Type: text/plain\r\n";
  oss << "Content-Length: 5\r\n";
  oss << "\r\n";
  oss << "hello";
  // oss << "<h1>hello<h1>";

  std::string output = oss.str();
  int size = output.size()+1;
  std::cout << "responded to socket id: " << socket <<"\n";
  response(socket, output.c_str(), size);
  // broadcast(socket, output.c_str(), size);
  // response(socket, "12345678", 8);

}

void TCPListener::onClientDisconnected(int socket){

}
void TCPListener::onMessageReceived(int clientSocket){   //(int clientSocket, const char* msg, int length){


}
