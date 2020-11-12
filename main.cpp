
#include "espresso/espresso.hpp"



int main(){

    auto app = espresso();

    app.use("/website");
    // app.use(".css", "/website");
   
    app.get("/", function(req, res){
        res.send("<br><br><br><h1><span style='margin-left:40%;color:green'> Home Page</span></h1>");

    });

    app.get("/get", function(req, res){
        console.log("\n method: ", req.m_method , "\n");
        console.log("\n filename: ", req.m_filename , "\n");
        console.log("\n m_body: \n", req.m_body , "\n");
        console.log("\n header: \n", req.header() , "\n");
        res.sendfile("/index.html");

    });
    

    app.post("/post", function(req, res){
        res.send("<br><br><br><h1><span style='margin-left:40%;color:green'> Home Page</span></h1>");

    });


    app.run(8080,"\n\nEspresso started at: " );



}
