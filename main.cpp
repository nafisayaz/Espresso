
#include "espresso/espresso.hpp"


int main(){

    auto app = espresso()("http");
   
    app.get("/", function(req, res){
        console.log("\nREQUEST HEADER: \n", req.header());
        res.send("<br><br><br><h1><span style='margin-left:40%;color:green'> Home Page</span></h1>");

    });

    app.get("/home", function(req, res){
        console.log("\nREQUEST HEADER: \n", req.header());
        res.sendfile("/home/nafis/new_projects/Espresso/website/index.html");
    });


    app.run(8080,"\n\nEspresso started at: " ); 

}
