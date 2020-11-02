
#include "espresso/espresso.hpp"

int main(){

    auto app = import("http");
   
    app.get("/", function(req, res){
        console.log("\nREQUEST HEADER: \n", req.header());

        res.send("<br><br><h1 style='margin-left:40%; color:red'>Hello World <br> <br> <span style='margin-left:-25%;color:green'>This message is delivered from Espresso Web-Framework :))</span><h1>");


    });

    app.run(8080,"\n\nEspresso started at: " ); 

}
