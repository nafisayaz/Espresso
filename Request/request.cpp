

#include "request.hpp"

const char* Request::header(){
    return m_header;
}

void Request::set_header(const char* header){
    m_header = header;
}
