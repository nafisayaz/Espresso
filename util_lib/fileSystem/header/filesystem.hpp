
#pragma once
#include <iostream>
#include <experimental/filesystem>
#include <string>
#include <vector>


namespace fs = std::experimental::filesystem;


struct FileSystem{

    static std::string current_path;
    static std::string file_name;
    static auto dirname()->std::string;

};


class Use{

    public:
        Use(){}
        ~Use(){}

        void use(const char* directory);
        void get_use();

    private:
        static  std::vector<std::string> m_directories;

};
std::vector<std::string> Use::m_directories;
std::string FileSystem::current_path        = {}; 
std::string FileSystem::file_name           = {}; 

#define     __pathname      FileSystem::current_path
#define     __filename      FileSystem::file_name
#define     __dirname       FileSystem::dirname()


#include "../source/filesystem.cpp"
