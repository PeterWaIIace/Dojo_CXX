#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define FIZZ_CURR "fizz"
#define BUZZ_CURR "buzz"

struct Transaction{
    std::string m_name = "";
    int m_amount = 0;
    std::string m_currency  = "";

    Transaction(std::string name, int amount, std::string currency) : m_name(name), m_amount(amount), m_currency(currency) {};
};

struct Trader{
    std::string m_name = "";
    std::map<std::string,int> m_relations;
    int m_fizz_amount = 0;
    int m_buzz_amount = 0;

    void add_relation(int amount, std::string trader_name)
    {
        if(m_relations.find(trader_name) != m_relations.end())
        {
            m_relations[trader_name] += amount;
        }
        else
        {
            m_relations[trader_name] = amount;
        }
    }

    Trader(){}
    Trader(std::string name, int fizz_amount, int buzz_amount) : m_name(name), m_fizz_amount(fizz_amount), m_buzz_amount(buzz_amount){};
};

std::map<std::string, Trader> fizzBuzzExchange(std::vector<Transaction> transactions){
    std::map<std::string,Trader> traders;
    std::queue<Transaction> buzz;
    std::queue<Transaction> fizz;

    for(auto transaction : transactions){
        if(traders.find(transaction.m_name) != traders.end())
        {
            // find old trader
            if(transaction.m_name == FIZZ_CURR){
                traders[transaction.m_name].m_fizz_amount = transaction.m_amount;
            }
            else if(transaction.m_name == BUZZ_CURR){
                traders[transaction.m_name].m_buzz_amount = transaction.m_amount;
            }
        }
        else{
            // new trader
            if(transaction.m_name == FIZZ_CURR){
                traders[transaction.m_name] = Trader(transaction.m_name,transaction.m_amount,0);
            }
            else if(transaction.m_name == BUZZ_CURR){
                traders[transaction.m_name] = Trader(transaction.m_name,0,transaction.m_amount);
            }
        }

        if(transaction.m_currency == FIZZ_CURR){
            fizz.push(transaction);
        }
        else if(transaction.m_currency == BUZZ_CURR){
            buzz.push(transaction);
        }

        if(fizz.size() && buzz.size()){
            auto fizzTransaction = fizz.front();
            fizz.pop();
            auto buzzTransaction = buzz.front();
            buzz.pop();
            std::cout << "processing: " << fizzTransaction.m_name << " " << buzzTransaction.m_name << std::endl;

            int exchange_amount = std::min(fizzTransaction.m_amount,buzzTransaction.m_amount);

            traders[fizzTransaction.m_name].m_fizz_amount -= exchange_amount;
            traders[buzzTransaction.m_name].m_buzz_amount -= exchange_amount;
            traders[fizzTransaction.m_name].m_buzz_amount += exchange_amount;
            traders[buzzTransaction.m_name].m_fizz_amount += exchange_amount;

            traders[fizzTransaction.m_name].add_relation(exchange_amount,buzzTransaction.m_name);
            traders[buzzTransaction.m_name].add_relation(exchange_amount,fizzTransaction.m_name);
        }
    }

    return traders;
};

int main(){
    std::vector<Transaction> transactions = {
        Transaction("Alice", 20, "buzz"),
        Transaction("Bob", 10, "fizz"),
        Transaction("Tom", 10, "fizz"),
        Transaction("Bob", 2, "fizz"),
        Transaction("Alice", 4, "buzz")
    };

    auto all_traders = fizzBuzzExchange(transactions);

    for(auto trader : all_traders){
        std::cout << "@@@@@@@@@@@@@" << std::endl;
        for(auto relation : trader.second.m_relations){
            std::cout << trader.first << " relation: " << relation.first << " amount: " << relation.second << " " << std::endl;
        }
        std::cout << "=============" << std::endl;
    }

    return 0;
};