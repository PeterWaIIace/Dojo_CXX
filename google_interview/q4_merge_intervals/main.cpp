#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <map>

std::vector<std::array<int,2>> overlap(std::vector<std::array<int,2>> &intervals)
{
    std::sort(
        intervals.begin(),
        intervals.end(),
        [](std::array<int,2> &a, std::array<int,2> &b){
            return a < b;
        }
    );

    std::vector<std::array<int,2>> merged;

    // lets append first interval to merged
    merged.push_back(intervals[0]);
    for(int n = 1 ; n < intervals.size() ; n++)
    {
        if(intervals[n-1][1] > intervals[n][0])
        {
            merged[n-1][1] = intervals[n][1];
        }
        else
        {
            merged.push_back(intervals[n]);
        }
    }
    return merged;
}

int main(){

    std::vector<std::array<int,2>> input_intervals = {{1,3},{2,6},{8,10},{15,18}};

    auto output_overlapping = overlap(input_intervals);
    for(auto merged : output_overlapping){
        std::cout << "[" << merged[0] << " " << merged[1] << "]";
    }
    return 0;
}