
#include "../header/filesystem.hpp"


void Use::use(const char* directory){

    m_directories.push_back(directory);
    FileSystem::current_path = fs::current_path();
    FileSystem::current_path += directory;

}
void Use::get_use(){
    for(auto& d : m_directories){
        std::cout << d <<"\n";
    }
}


auto FileSystem::dirname()->std::string{ 
    return fs::current_path(); 
}
