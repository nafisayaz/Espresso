
#include "../header/reader.hpp"

std::string Reader::read(std::string filePath){

    const char* c_filePath = filePath.c_str();
    std::fstream f(__pathname +"/"+ __filename);
    if(!f.good() ){
        return "NOT FOUND : " + __pathname + "/" + __filename;
    }
    
    std::string message((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    //std::cout << "message: \n" << message << "\n"; 
    std::cout << "message size: \n" << message.size() << "\n"; 
    return message;


}