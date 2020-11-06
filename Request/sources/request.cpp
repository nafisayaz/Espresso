

#include "../headers/request.hpp"

const char* Request::header(){
    return m_header;
}

void Request::set_header(const char* header){
    m_header = header;
}

std::string Request::get_path(){
    
    std::istringstream iss(m_header);
    std::vector<std::string> parsed_data((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
    // for(auto s: parsed_data){
    //     std::cout <<s <<"\n";
    // }
    return parsed_data[1];

}