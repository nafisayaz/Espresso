
#include "espresso/espresso.hpp"

int main(){

    auto app = espresso();

    app.use("/website");
   
    app.get("/", function(req, res){
        res.send("<br><br><br><h1><span style='margin-left:40%;color:green'> Home Page</span></h1>");

    });

    app.get("/home", function(req, res){
        // console.log("\nREQUEST HEADER: \n", req.header());
        res.sendfile("/index.html");
    });

    app.run(8080,"\n\nEspresso started at: " ); 

}
