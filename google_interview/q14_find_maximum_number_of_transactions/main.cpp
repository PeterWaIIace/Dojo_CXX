#include <iostream>
#include <vector>

int findMaxNOT(std::vector<int> input, int starting_balance){

    int balance = starting_balance;
    int longest_transaction_count = 0;
    int transaction_count = 0;
    for(int n = 0 ; n < input.size() ; n++){
        balance += input[n];
        transaction_count++;
        if(balance < 0){
            if(transaction_count > longest_transaction_count){
                longest_transaction_count = transaction_count;
            }
            transaction_count = 0;
            balance = 0;
        }

    }
    return longest_transaction_count;
}

int main(){

    std::vector<int> input = {12, 4, 5, -30, 15, 5};
    std::cout << findMaxNOT(input, 0) << std::endl;
    return 0;
}