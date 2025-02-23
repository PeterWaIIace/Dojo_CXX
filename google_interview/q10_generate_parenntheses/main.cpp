#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <stack>

using vstring = std::vector<std::string>;

void generate_pair(
    std::pair<char,char> character_set,
    std::string base,
    vstring &output,
    int first, // open count (
    int second, // close count )
    int n
){
    if(base.size() == 2*n)
    {
        output.push_back(base);
        return;
    };

    if(first < n){
        generate_pair(
            character_set,
            base + character_set.first,
            output,
            first+1,
            second,
            n
        );
    };

    if(first > second){
        generate_pair(
            character_set,
            base + character_set.second,
            output,
            first,
            second+1,
            n
        );
    };
}

int main(){
    std::pair<char,char> bpair('(',')');
    int number_pairs = 3;
    vstring output;
    generate_pair(bpair,"(",output,1,0,number_pairs);

    std::cout << "[";
    for(auto str : output){
        std::cout << str << ", ";
    }
    std::cout << "]" << std::endl;
    return 0;
}