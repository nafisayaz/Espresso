# Espresso


Espresso - A web framework that compatible to C++14 and above. Espresso+ compiler which combines espresso code and C++ and converts 
to executable code, c++/stl headers can easily be included in espresso source files. This web framework accept callback function as an argument. 
Distributed to apt repository from where can be installed on Linux system. APIs reference documentation, provides details information about all 
fuctions and objects of Espresso, this documentation expalins every APIs in more details, so to implement easily C++ projects and 
all APIs are complete compatible with C++11/14/17.


``` cpp
#include "espresso/espresso.hpp"

int main(){

    auto app = import("http");
   
    app.get("/", function(req, res){
        console.log("\nREQUEST HEADER: \n", req.header());
        res.send("<br><br><h1 style='margin-left:40%; color:red'>Hello World <br> <br> <span style='margin-left:-25%;color:green'>This message is delivered from Espresso Web-Framework :))</span><h1>");
    });

    app.run(8080,"\n\nEspresso started at: " ); 
}

```

###DOCUMENTATION
