
#include "../headers/http.hpp"

int main(){

    Http http("0.0.0.0");

    if(http.init(8080) != 0){
        std::cout << "ERROR\n";
    }

    http.run();


}
