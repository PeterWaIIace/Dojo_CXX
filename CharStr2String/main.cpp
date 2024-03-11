#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <sstream>

int main(int argc, char* argv[]){

    std::cout << "Arguments: "<< std::endl;
    for(int i = 0 ; i < argc ; i++){
        std::string string(argv[i]);
        std::ostringstream oss;
        oss << "[" << i << "]";
        std::cout << oss.str() << "string: " << string << std::endl;   
    }

    return 0;

}