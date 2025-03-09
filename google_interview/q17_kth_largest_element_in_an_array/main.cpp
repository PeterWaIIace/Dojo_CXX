#include <iostream>
#include <vector>
#include <queue>

// worst case: target == inputs.size() -> O(n ^ 2)
// best case: target == 1 -> O(n)

void swap(int& x, int& y){
    int tmp = y;
    y = x;
    x = tmp;
}

void show(std::vector<int> a)
{
    std::cout << "[ ";
    for(auto n : a){
        std::cout << n << " " ;
    }
    std::cout << "]" << std::endl;
}

void quickSort(std::vector<int>& a, int l, int r) {
    if (l >= r) return;
    int p = a[r], i = l;
    for (int j = l; j < r; j++){
        if (a[j] < p) swap(a[i++],a[j]);
    }
    swap(a[i], a[r]);
    quickSort(a, l, i - 1);
    quickSort(a, i + 1, r);
}


int findKthLargest(std::vector<int> inputs, int target)
{
    auto copy = inputs;
    quickSort(copy,0,inputs.size()-1);

    for(auto n : copy){
        std::cout << n << " " ;
    }
    std::cout << std::endl;
    return copy[inputs.size() - target];
}

int PQKthLargetTree(std::vector<int> inputs, int target)
{
    std::priority_queue<int> mp;

    for(int i = 0 ; i < inputs.size() ; i++)
    {
        mp.push(inputs[i]);
    }

    int ret_value = -1;
    for(int i = 0 ; i < target ; i++)
    {
        ret_value = mp.top();
        mp.pop();
    }
    return ret_value;
}

int main(){

    std::cout << findKthLargest({3,2,1,5,6,4},1) << std::endl;
    std::cout << findKthLargest({3,7,1,5,6,4},2) << std::endl;
    std::cout << findKthLargest({3,0,1,5,6,4},3) << std::endl;
    std::cout << findKthLargest({7,2,9,5,6,4},4) << std::endl;

    std::cout << PQKthLargetTree({3,2,1,5,6,4},1) << std::endl;
    std::cout << PQKthLargetTree({3,7,1,5,6,4},2) << std::endl;
    std::cout << PQKthLargetTree({3,0,1,5,6,4},3) << std::endl;
    std::cout << PQKthLargetTree({7,2,9,5,6,4},4) << std::endl;
    return 0;
}