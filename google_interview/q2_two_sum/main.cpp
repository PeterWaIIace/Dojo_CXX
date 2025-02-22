#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <tuple>
// naive O(log(n))
std::array<int,2> naive_find(std::vector<int> nums, int target){
    std::array<int,2>  ret = {-1,-1};
    for(int n = 0 ; n < nums.size() ; n++){
        for(int m = n ; m < nums.size() ; m++){
            if((m != n) && (nums[n] + nums[m] == target)){
                ret[0] = n;
                ret[1] = m;
                return ret;
            }
        }
    }
    return ret;
}

// naive O(n)
std::array<int,2> On_find(std::vector<int> nums, int target){
    std::array<int,2> ret = {-1,-1};
    std::map<int,int> complement;
    int COMPLEMENT = 0 ;
    int INDEX = 1;
    for(int n = 0 ; n < nums.size() ; n++){
        if(complement.find(nums[n]) != complement.end()){
            if(n != complement[nums[n]]){
                ret[0] = n;
                ret[1] = complement[nums[n]];
                return ret;
            }
        }
        complement[target - nums[n]] = n;
    }
    return ret;
}

int main(){
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto result = On_find(nums,target);
    std::cout << result[0] << " " << result[1] << std::endl;

    target = 11;
    nums = {2, 7, 11, 15, 23, 1 ,2 ,5, 3, 5, 6 , 7 , 8 ,3 ,2};
    result = On_find(nums,target);
    std::cout << result[0] << " " << result[1] << std::endl;

    target = 4;
    nums = {2, 7, 11, 15, 23, 2, 1 ,3 ,9 ,10};
    result = On_find(nums,target);
    std::cout << result[0] << " " << result[1] << std::endl;

    return 0;
}