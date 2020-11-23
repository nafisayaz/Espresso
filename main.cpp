
#include "espresso/espresso.hpp"



int main(){

    auto app = espresso();

    app.use("/website");
    
    app.get("/", function(req, res){
        res.send("<br><br><br><h1><span style='margin-left:40%;color:green'> Home Page</span></h1>");

    });

    app.get("/get", function(req, res){
        console.log("\n m_method: ", req.m_method , "\n");
        console.log("\n m_filename: ", req.m_filename , "\n");
        console.log("\n m_body: ", req.m_body , "\n");
        console.log("\n m_header: ", req.header() , "\n");
        res.sendfile("/index.html");

    });
    

    app.post("/post", function(req, res){
        res.send("<br><br><br><h1><span style='margin-left:40%;color:green'> Home Page</span></h1>");

    });


    app.run(8080,"\n\nEspresso started at: " );



}
