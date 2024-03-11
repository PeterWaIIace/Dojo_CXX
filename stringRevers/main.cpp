#include <iostream>
#include <stdio.h>

std::string reverse(std::string input){
    int start = 0;
    int end = input.length() - 1;

    while( start < end ){
        char tmp = input[start];
        input[start] = input[end];
        input[end] = tmp;

        start++;
        end--;
    }
    return input;
}

int main(int argc, char *argv[]){

    if(argc > 1){
        std::cout << "Input: " << argv[1] << " reversed: " << reverse(std::string(argv[1])) << std::endl;
    }
    return 0;
}