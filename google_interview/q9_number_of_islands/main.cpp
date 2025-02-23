#include <iostream>
#include <utility>
#include <array>
#include <queue>
#include <set>

template <int Rows, int Cols>
using matrix = std::array<std::array<int,Rows>,Cols>;

using coordinates = std::pair<int,int>;

template <int Rows, int Cols>
void exploreIsland(matrix<Rows,Cols> mat, std::set<coordinates> &visited,  int i = 0, int j = 0){
    std::queue<coordinates> work_queue;

    coordinates up = {1,0};
    coordinates down = {-1,0};
    coordinates left = {0,1};
    coordinates right = {0,-1};
    std::vector<coordinates> directions = {up,down,left,right};

    work_queue.push({i,j}); // start coordinates

    while(work_queue.size()){
        auto pos = work_queue.front();
        work_queue.pop();

        if(visited.find(pos) != visited.end() || mat[pos.first][pos.second] == 0) continue;
        else
        {
            visited.insert(pos);
            for(auto direction: directions)
            {
                coordinates new_pos = {pos.first + direction.first,pos.second + direction.second};
                if(new_pos.first < 0 || new_pos.first >= mat.size()) {
                    continue;
                };
                if(new_pos.second < 0 || new_pos.second >= mat[0].size()) {
                    continue;
                };

                work_queue.push(new_pos);
            }
        }
    }

}

template <int Rows, int Cols>
int countIslands(matrix<Rows,Cols> mat){
    std::set<coordinates> visited;
    int countedIslands = 0;
    for(int i = 0 ; i < mat.size(); i++){
        for(int j = 0 ; j < mat[0].size(); j++){
            if(visited.find({i,j}) == visited.end() && mat[i][j] == 1){
                exploreIsland(mat,visited,i,j);
                countedIslands += 1;
            }
        }
    }
    return countedIslands;
}

int main(){
    matrix<5,4> mat = {{
        {{1,1,0,0,0}},
        {{1,1,0,0,0}},
        {{0,0,1,0,0}},
        {{0,0,0,1,1}},
    }};

    std::cout << countIslands(mat) << std::endl;
    return 0;
}