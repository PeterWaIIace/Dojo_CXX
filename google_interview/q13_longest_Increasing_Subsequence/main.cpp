#include <algorithm>
#include <iostream>
#include <vector>

void show(std::vector<int> v){
    std::cout << "[" ;

    for(auto v_i : v){
        std::cout << v_i << ", ";
    }

    std::cout << "]" << std::endl;
}

int exploreSubsequence(std::vector<int>& nums, std::vector<int> subsequence,int start){
    int candidate = subsequence.size();

    for(int n = start; n < nums.size() ; n++)
    {
        if(nums[n] > subsequence[subsequence.size() - 1]){
            std::vector<int> subsequence_copy = subsequence;
            subsequence_copy.push_back(nums[n]);
            show(subsequence_copy);
            int new_candidate = exploreSubsequence(nums,subsequence_copy,n+1);
            if(new_candidate > candidate){
                candidate = new_candidate;
            }
        }
    }

    return candidate;
};

int lis(std::vector<int>& nums){
    int candidate = 0;
    for(int n = 0 ; n < nums.size() ; n++){
        std::vector<int> subsequence;
        subsequence.push_back(nums[n]);
        int new_candidate = exploreSubsequence(nums, subsequence, n + 1);
        if(candidate < new_candidate){
            candidate = new_candidate;
        }
    }
    return candidate;
}

int lis_optimal(std::vector<int>& nums){
    std::vector<int> longest_inc_sub; // so this is [2,3,7,101] kind of sorted

    for(auto num : nums){
        auto result = std::lower_bound(longest_inc_sub.begin(), longest_inc_sub.end(), num);
        if(result == longest_inc_sub.end()){
            longest_inc_sub.push_back(num);
        }
        else{
            *result = num;
        }
    }

    return longest_inc_sub.size();
}

int main(){

    std::vector<int> input = {10,9,2,5,3,7,101,18};
    std::cout << lis_optimal(input) << std::endl;

    input = {0,1,0,3,2,3};
    std::cout << lis_optimal(input) << std::endl;
    return 0;
}