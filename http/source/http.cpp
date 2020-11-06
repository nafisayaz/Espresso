

#include "../headers/http.hpp"

static Request          req;
static Response         res;
static Parser           parser;
static Reader           reader;

void Http::onClientConnected( int socket){

  std::ostringstream oss; 
  std::string content = {};

  if(parser.get_m_path().find("text/css") != std::string::npos){
    oss = parser.get_oss(parser.get_contentType());
    content = reader.read(parser.get_m_path());

  }else{
    oss = parser.get_oss(parser.get_contentType());
    content = res.get_message();
  }
  oss << "Content-Length: "+content.size()+1<<"\r\n";
  oss << "\r\n";
  oss << content;

  std::string output = oss.str();

  response(socket, output.c_str(), output.size()+1);
}
void Http::onClientDisconnected(int socket){

}
void Http::onMessageReceived(int clientSocket){

  char buffer[1024] = {0};
  int valread = read( clientSocket , buffer, 1024); 

  const char* msg = buffer;
  
  parser.parse(msg);

  req.set_header(msg);

  res.set_response(clientSocket);

  execute_restfull_APIs(req, res);


}