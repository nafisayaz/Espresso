
#include "../header/parser.hpp"


 auto Parser::parse_header(const char* message )->void{  //std::map<std::string, std::string>{
    
    std::stringstream ss(message);
    std::vector<std::string>data;
    std::string tmp = {};

    while(std::getline(ss, tmp, '\n')){
        std::string el={};
        std::stringstream elss(tmp);
        while(std::getline(elss, el, ':' )){
            data.push_back(el);
        }
    }

    std::cout <<message<<"\n";
    for(auto& d: data){
        std::cout<<d<<"\n";
    }

}

void Parser::parse(const char* message){
    
    std::istringstream iss(message);
    std::vector<std::string> parsed_data((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

    m_method = parsed_data[0];
    m_path = parsed_data[1];
    m_type = parsed_data[2];
    m_hostname = parsed_data[4];
    m_contentType = parsed_data[19];
    std::cout << "m_contentType: " << m_contentType <<"\n";

    std::cout << "REQ: \n";
    for(auto& s: parsed_data){
        // std::cout << s <<"\n";
    }
    
    
    


}


std::string Parser::get_contentType(){
    return m_contentType;
    
}
std::string Parser::get_m_path(){
    return m_path;
    
}
auto Parser::get_oss(std::string msg){

    std::ostringstream oss;

    if(msg == "text/css,*/*;q=0.1")
    {
        std::cout << "\n\nm_path: \n" << m_path <<"\n";
        oss << "HTTP/1.1 200 OK\r\n";
        oss << "Cache-Control: no-cache, private\r\n";
        oss << "Content-Type: text/css\r\n";

    }
    oss << "HTTP/1.1 200 OK\r\n";
    oss << "Cache-Control: no-cache, private\r\n";
    oss << "Content-Type: text/html\r\n";
    
    
    return oss;

}

