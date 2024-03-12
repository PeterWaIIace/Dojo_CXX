#include "classes.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]){

    Base B;
    Daughter D;
    Protected_Daughter PD;

    std::cout << "Types: " << B.getType() << " " << D.getType() << " " << PD.getProtectedType() << std::endl; 
};