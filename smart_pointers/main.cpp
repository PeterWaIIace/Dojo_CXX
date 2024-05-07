#include <memory>
#include <iostream>

int main(int argc, char* argv[]){
    std::shared_ptr<int[]> ptr(new int[20]);

    // not allowed
    std::shared_ptr<int[]> ptr2 = ptr;
}