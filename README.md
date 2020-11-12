# Espresso - Webframework


Espresso - A web framework that compatible to C++14 and above. Espresso+ compiler which combines espresso code and C++ and converts 
to executable code, c++/stl headers can easily be included in espresso source files. This web framework accept callback function as an argument. 
Distributed to apt repository from where can be installed on Linux system. 

APIs reference documentation, provides details information about all fuctions and objects of Espresso, this documentation expalins every APIs
in more details, so to implement easily C++ projects and all APIs are complete compatible with C++14/17.



Looks easy and simple 
``` cpp

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
    

    // app.post("/post", function(req, res){
    //     res.send("<br><br><br><h1><span style='margin-left:40%;color:green'> Home Page</span></h1>");

    // });


    app.run(8080,"\n\nEspresso started at: " );



}



```

###DOCUMENTATION
- [https://nafisayaz.github.io/espresso/doc.html][doc]

[doc]:https://nafisayaz.github.io/espresso/doc.html


APIs reference documentation, provides details information about all fuctions and objects of Espresso, 
this documentation expalins every APIs in more details, so to implement easily C++ projects and all APIs are complete compatible with C++11/14/17.
Espresso is very fast web-framework hybrid of C++, the main objective is just to make it easy and simple for C++ developers. 
This framework is built on top of C++14 and above




NOTE: It's the first version: Espresso_v_1.0.0, so there may occur some exeptions-throw, error or you find any idea.
Kindly contact me: sir.ayaz47@gmail.com



