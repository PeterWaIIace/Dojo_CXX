#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <set>

using coordinates = std::pair<int,int>;
using wordboard = std::vector<std::vector<char>>;

struct Task{
    coordinates m_pos = {0,0};
    int m_length = 0;

    Task(coordinates pos, int length) : m_pos(pos), m_length(length){};
};
// bfs
bool exploreArea(wordboard board, std::string word, int i, int j){
    coordinates start = {i,j};
    std::set<coordinates> visited;

    std::queue<Task> work_queue;
    work_queue.push(Task(start,0));

    std::vector<coordinates> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    while(work_queue.size()){
        auto task = work_queue.front();
        auto pos = task.m_pos;
        int word_length = task.m_length;
        work_queue.pop();

        if(visited.find(pos) != visited.end()) continue;
        visited.insert(pos);

        if(word_length >= word.size()){
            return true;
        }

        if(board[pos.first][pos.second] == word[word_length]){
            word_length++;
            for(auto dir : directions){
                coordinates new_pos = {
                    dir.first + pos.first,
                    dir.second + pos.second
                };
                if(new_pos.first < 0 || new_pos.first >= board.size()) continue;
                if(new_pos.second < 0 || new_pos.second >= board[0].size()) continue;
                work_queue.push(Task(new_pos,word_length));
            }
        }
    }
    return false;
}

bool findword(wordboard board, std::string word){

    char first_letter = word[0];

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(first_letter == board[i][j]){
                if(exploreArea(board,word,i,j)){
                    return true;
                };
            }
        }
    }
    return false;
}

int main(){
    wordboard board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    std::cout << findword(board,"ABCCED") << " expected true" << std::endl;

    board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    std::cout << findword(board,"ABCCE") << " expected true" << std::endl;

    board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    std::cout << findword(board,"ABCCEX") << " expected false" << std::endl;

    board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    std::cout << findword(board,"ABCB") << " expected false" << std::endl;
    return 0;
}