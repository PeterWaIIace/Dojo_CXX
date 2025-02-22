#include <iostream>
#include <string>
#include <map>

// hashmap approach O(n)
std::string longest(std::string input){
    std::map<char, int> repetition_guard;
    std::string the_best_candidate = "";
    std::string the_inspected_candidate = "";
    for(char c : input){
        if(repetition_guard.find(c) != repetition_guard.end())
        {
            if(the_inspected_candidate.size() > the_best_candidate.size())
            {
                the_best_candidate = the_inspected_candidate;
            }

            std::map<char, int> new_empty_guard;
            repetition_guard = new_empty_guard;
            the_inspected_candidate = "";
        }
        else
        {
            the_inspected_candidate += c;
            repetition_guard[c] = 1;
        }
    }

    if(the_inspected_candidate.size() > the_best_candidate.size())
    {
        the_best_candidate = the_inspected_candidate;
    }
    return the_best_candidate;
}

int main(){
    std::string input = "abcabcbb";
    auto output = longest(input);
    std::cout << output << std::endl;

    input = "this is next test of longest non-repetitive substring";
    output = longest(input);
    std::cout << output << std::endl;
    return 0;
}