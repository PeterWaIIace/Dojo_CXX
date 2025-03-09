#include <iostream>
#include <vector>
#include <map>

int findSingle(std::vector<int> input)
{
    std::map<int,int> counter;

    for(auto a : input){
        if(counter.find(a) != counter.end()){
            counter[a] += 1;
        }
        else{
            counter[a] = 1;
        }
    }

    for(auto item : counter){
        if(item.second == 1){
            return item.first;
        }
    }
    return -1;
}

int main()
{
    std::cout << findSingle({4,1,2,1,2}) << std::endl;
    std::cout << findSingle({9,7,3,3,1,2,1,2,9}) << std::endl;
    return 0;
}