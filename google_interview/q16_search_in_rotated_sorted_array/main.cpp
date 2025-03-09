#include <iostream>
#include <vector>

int findTarget_naive(std::vector<int> &inputs, int target){
    for(int i = 0 ; i < inputs.size() ; i++){
        if(inputs[i] == target)
        {
            return i;
        }
    }
}

int binary_search(std::vector<int> &inputs, int target){
    int left = 0;
    int right = inputs.size() - 1;

    while(left <= right){
        int mid = left + (right - left)/2;
        if(inputs[mid] == target) return mid;

        // detect which side is sorted
        if(inputs[left] < inputs[mid]){
            // left is sorted
            if(inputs[left] <= target && target < inputs[mid]){
                // it is in left half
                right = mid - 1;
            }
            else{
                left = mid + 1;
                // it is in right half
            }

        }else{
            // right is sorted
            if(inputs[mid] < target && target <= inputs[right]){
                // it is in left half
                left = mid + 1;
            }
            else{
                right = mid - 1;
                // it is in right half
            }

        }
    }
    return -1;

}


int main()
{
    std::vector<int> inputs = {4,5,6,7,0,1,2};
    int target = 0;

    std::cout << "output: "  << binary_search(inputs,0) << " expected: " << 4 << std::endl;
    std::cout << "output: "  << binary_search(inputs,5) << " expected: " << 1 << std::endl;
    std::cout << "output: "  << binary_search(inputs,7) << " expected: " << 3 << std::endl;
    std::cout << "output: "  << binary_search(inputs,2) << " expected: " << 6 << std::endl;

    inputs = {15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    std::cout << "output: "  << binary_search(inputs,0) << " expected: " << 36 << std::endl;
    std::cout << "output: "  << binary_search(inputs,21) << " expected: " << 6 << std::endl;
    std::cout << "output: "  << binary_search(inputs,9) << " expected: " << 45 << std::endl;
    std::cout << "output: "  << binary_search(inputs,16) << " expected: " << 1 << std::endl;
    return 0;
}