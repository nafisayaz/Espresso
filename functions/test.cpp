
#include <iostream>

#include "./headers/function.hpp"




// template<typename F>
void say(void(*foo)(const char*, const char*)){
  foo("hello world", " : Nafis");
}


int main(){


  say(function( x, y){
    console.log(x, ", ", y, "\n");

  });

  // std::function<void(char*)> Function1 = function(x){
  //   console.log(x);
  // };
  // Function1("hello function\n");

  // App app;
  // app.get("path", function(x, y){
	//    console.log("x: ",x , "y: ", y, "\n" );
  //  });


}
