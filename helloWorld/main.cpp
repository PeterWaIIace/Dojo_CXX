#include <iostream>

int add(int x, int y);

int main(){
    [[maybe_unused]] int i{};
    __attribute_maybe_unused__ int k{0};
    int j(0);
    
    std::cout << "Here is some text, and here is addition result: " << add(4,5) << "\n";
    return EXIT_SUCCESS;
}