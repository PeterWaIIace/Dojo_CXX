#include <cctype>
#include <cstdio>
#include <iostream>

void checkChar(char c){
    if(isalnum(c)){
        std::cout << "characted " << c << " is alphanumeric" << std::endl;
    };
    if(isalpha(c)){
        std::cout << "characted " << c << " is alphabetic" << std::endl;
    };
    if(isblank(c)){
        std::cout << "characted " << c << " is blank" << std::endl;
    };
    if(iscntrl(c)){
        std::cout << "characted " << c << " is a control character" << std::endl;
    };
    if(isdigit(c)){
        std::cout << "characted " << c << " is decimal digit" << std::endl;
    };
    if(isgraph(c)){
        std::cout << "characted " << c << " is graphical representation" << std::endl;
    };
    if(islower(c)){
        std::cout << "characted " << c << " is lowercase" << std::endl;
    };
    if(isprint(c)){
        std::cout << "characted " << c << " is printable" << std::endl;
    };
    if(ispunct(c)){
        std::cout << "characted " << c << " is punctuation" << std::endl;
    };
    if(isspace(c)){
        std::cout << "characted " << c << " is white space" << std::endl;
    };
    if(isupper(c)){
        std::cout << "characted " << c << " is uppercase" << std::endl;
    };
    if(isxdigit(c)){
        std::cout << "characted " << c << " is haxedecimal" << std::endl;
    };
}

int main(int argc, char* argv[]){

    std::cout << "Process first argument." << std::endl;
    if(argc > 1){
        std::string str(argv[1]);
        for(auto c : str){
            checkChar(c);
        }
    }
    return 0;
}