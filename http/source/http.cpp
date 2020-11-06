

#include "../headers/http.hpp"

static Request          req;
static Response         res;
static Parser           parser;
static Reader           reader;

void Http::onClientConnected( int socket){

  std::ostringstream oss; //= parser.get_oss(parser.get_contentType());
  std::string content = {};

  if(parser.get_m_path().find("text/css") != std::string::npos){
    // std::cout << "================> " << parser.get_contentType() <<"\n";
    
    oss = parser.get_oss(parser.get_contentType());
    content = reader.read(parser.get_m_path());

  }else{
    std::cout << "================> " << parser.get_contentType() <<"\n";
    oss = parser.get_oss(parser.get_contentType());
    content = res.get_message();
  }
  // std::cout << "content ================> " << content <<"\n";
  

  oss << "Content-Length: "+content.size()+1<<"\r\n";
  oss << "\r\n";
  oss << content;

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
  
  parser.parse(msg);

  req.set_header(msg);

  res.set_response(clientSocket);

  execute_restfull_APIs(req, res);


}