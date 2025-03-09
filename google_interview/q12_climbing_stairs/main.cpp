#include <iostream>
#include <vector>

int findways(int input){
    if(input <= 2){
        return input;
    }

    return findways(input-1) + findways(input-2);
}

int findways_array(int input){
    if(input <= 2){
        return input;
    }

    int prev_1 = 1; // if n == 1 then there is only 1 option
    int prev_2 = 2; // if n == 1 then there is only 1 option
    int current = 2; // if n == 2 then there are only 2 options
    for(int i = 2 ; i < input; i++){
        current = current + prev_1;
        prev_1 = prev_2;
        prev_2 = current;
    }
    return current;
}

int main(){
    int input = 3;
    std::cout << findways_array(input) << std::endl;
    std::cout << findways_array(4) << std::endl;
    std::cout << findways_array(5) << std::endl;
    std::cout << findways_array(6) << std::endl;
    return 0;
}