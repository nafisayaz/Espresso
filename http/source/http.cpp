

#include "../headers/http.hpp"

static Request req;
static Response res;


void Http::onClientConnected( int socket){

  std::ostringstream oss;

  oss << "HTTP/1.1 200 OK\r\n";
  oss << "Cache-Control: no-cache, private\r\n";
  oss << "Content-Type: text/html\r\n";
  oss << "Content-Length: "+res.get_message().size()<<"\r\n";
  oss << "\r\n";
  oss << res.get_message();

  std::string output = oss.str();

  response(socket, output.c_str(), output.size()+1);
}
void Http::onClientDisconnected(int socket){

}
void Http::onMessageReceived(int clientSocket){  //(int clientSocket, const char* msg, int length){
  char buffer[1024] = {0};
  int valread = read( clientSocket , buffer, 1024); 
  // printf(" \n\n %s \n\n",buffer );

  const char* msg = buffer;
  
  req.set_header(msg);

  res.set_response(clientSocket);

  execute_restfull_APIs(req, res);


}