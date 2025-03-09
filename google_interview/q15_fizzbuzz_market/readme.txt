FizzBuzz Exchange
Problem Description

You are given a list of transactions where each transaction represents an exchange of a specific amount of either fizz or buzz. The goal is to simulate the exchange process where fizz and buzz are traded in a 1:1 ratio in a FIFO (first-in, first-out) manner. Each exchange occurs between two participants, and the transactions are completed as long as there are enough fizz and buzz available for trade.

After performing all possible exchanges, return a list of all exchanges performed and the final remaining amounts of fizz and buzz for each participant. Each exchange should appear only once in the result, and you should output the final state for each participant who has remaining fizz or buzz.

For example:
Input
transactions = [
    ["Alice", 20, "buzz"],
    ["Bob", 10, "fizz"],
    ["Tom", 10, "fizz"],
    ["Bob", 2, "fizz"],
    ["Alice", 4, "buzz"]
]


Output

[["Alice", 12, "Bob"], ["Alice", 10, "Tom"], ["Alice", 2 ,"buzz"]]
