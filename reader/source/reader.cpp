
#include "../header/reader.hpp"

std::string Reader::read(std::string filePath){

    const char* c_filePath = filePath.c_str();
    std::fstream f(c_filePath);
    if(!f.good() ){
        return "NOT FOUND : " + filePath;
    }
    
    std::string message((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    std::cout << "message: \n" << message << "\n"; 
    return message;


}