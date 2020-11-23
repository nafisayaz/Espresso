

#include "../headers/request.hpp"

const char* Request::header(){
    return m_header;
}

void Request::set_header(const char* header){

    m_header = header;
    std::vector<std::string>data = parse_header(header, [](){
        return '\n';
    });
    initialize(data);
    m_filename = fs::path(fs::path(m_params).filename()).extension() != "" ? fs::path(m_params).filename() : "";
    if(m_filename != "") { FileSystem::file_name = m_filename; }
    
    
}

auto Request::parse_header(const std::string header, std::function<char()> func)->std::vector<std::string>{
    
    std::stringstream ss(header);
    std::vector<std::string>data;
    std::string tmp = {};
    int count = {};
    while(std::getline(ss, tmp, func())){
        data.push_back(tmp);
    }

    return data;

}

void Request::initialize(const std::vector<std::string>& data){

    int count = 1;
    char delimeter = ' ';
    bool is_body = false;
    for(auto& d: data){
        if(count ==17) {
            is_body = true;
        }
        if(is_body){m_body += d;}
        std::vector<std::string> v_str = parse_header(d, [&]()->char{
            return delimeter;
        });
          
        if(count == 1){
            m_method = v_str[0];
            m_params = v_str[1];
            m_protocol = v_str[2];
        }
        else if(count == 2){
            m_hostname = v_str[1];
            m_port = v_str[2];
        }
        else if(count == 3){
            m_state = v_str[1];
        }
        else if(count == 6){
            m_userAgent = v_str[1];
        }else{
            // std::cout << count <<":   " << d <<"\n";
        }

        delimeter = ':';
        ++count;
    }
   
}

void Request::parse_element(const std::string element){

}

std::string Request::get_path(){
    
    std::istringstream iss(m_header);
    std::vector<std::string> parsed_data((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

    return parsed_data[1];

}