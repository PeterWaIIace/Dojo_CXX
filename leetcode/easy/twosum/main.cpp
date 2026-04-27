#include <iostream>
#include <utility>
#include <vector>
#include <map>

class Solution{
    private:
    public:
    std::vector<int> twoSum(std::vector<int> numbers, int target) {
        std::vector<int> ret;
        std::map<int,std::pair<int,int>> rest; // rest and index
        for(int i{0uz} ; i < numbers.size() ; i++) {
            if (rest.find(numbers[i]) != rest.end()) {
                auto [number, index] = rest[numbers[i]];
                if (number + numbers[i] == target && i != index) {
                    ret = {index, i};
                }
            }
            rest[target - numbers[i]] = {numbers[i], i};
        };
        return ret;
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    auto vec = s.twoSum(nums, 9);
    std::cout << "twoSum: "<< vec[0] << " " << vec[1] << std::endl;
    return 0;
}