
#include "../headers/tcpListener.hpp"

int main(){

    TCPListener tcp("127.0.0.1");

    if(tcp.init(8080) != 0){
        std::cout << "ERROR\n";
    }

    tcp.run();

    // auto server = std::make_shared<Server>("127.0.0.1",8080);
    // //
    // server->create();
    // server->receive();

}
