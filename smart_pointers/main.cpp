#include <memory>
#include <iostream>

int main(int argc, char* argv[]){
    std::unique_ptr<int[]> ptr(new int[20]);

    // not allowed
    std::unique_ptr<int[]> ptr2 = ptr;
}