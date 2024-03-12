#include <chrono>
#include <string>
#include <iostream>
#include <functional>
using namespace std::chrono;

long superLongCalculation(int n){
    long result = 1;
    result = result + result;
    std::cout << "ret: " << result << std::endl;
    for(int i = 0 ; i  < n*n; i++){
        result = result + result;
        result = result * result;
        // std::cout << "ret: " << result << std::endl;
    }
    // std::cout << "ret: " << result << std::endl;
    return result;
}

template <typename T> 
T timeit(std::function<T()>func){
    auto start = high_resolution_clock::now();
    T ret = func();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Execution took: " << duration.count() << "us" << std::endl;
    return ret; 
}

constexpr int FIRST_VALUE = 1;
int main(int argc, char * argv[])
{
    if(argc > 1){
        std::cout << "int bitsize: " << sizeof(int)*8 << std::endl;
        int integer_value = std::stoi(argv[FIRST_VALUE]);
        long ret = timeit<int>(
            [integer_value](){
                return superLongCalculation(integer_value);
            }
        );
        std::cout << "Ret: " << ret << std::endl;
    }
}