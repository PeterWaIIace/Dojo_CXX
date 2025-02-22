
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
// result = [everythign except 1, everything except 2]
//Input: nums = [1,2,3,4]
// 1 -> aside to some variable leftover = 1
// 2 -> aside to some variable leftover *= 2

/*
L         R
[1,1,1,_] [_,1,1,1]
[1,1,1,_] [_,1,1,4]
[1,2,1,_] [_,1,12,4]
[1,2,6,_] [_,24,12,4]
[1,2,6,_] [_,24,12,4]
*/
std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    // initizalize vector by
    std::vector<int> product(nums.size(),1);
    int leftover_product = 1;
    int rightover_product = 1;
    int size = nums.size();
    for(int n = 0; n < nums.size()-1; n++)
    {
        leftover_product *= nums[n];
        rightover_product *= nums[(size-1) - n];
        product[(size-1)-n-1] *= rightover_product;
        product[n+1] *= leftover_product;
    }
    return product;
};

void printVector(std::vector<int> input)
{
    std::cout << "[" ;
    for(auto value : input){
        std::cout << " "<< value << ",";
    }
    std::cout << "]" << std::endl;
}

int main(){
    std::vector<int> input = {1,2,3,4};
    auto output = productExceptSelf(input);
    printVector(output);
    input = {-1,1,0,-3,3};
    output = productExceptSelf(input);
    printVector(output);
    return 0;
}