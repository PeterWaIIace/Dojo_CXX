#include <iostream>
#include <utility>
#include <vector>
#include <queue>

std::vector<std::vector<std::pair<int,int>>> directions = {
    {},                   // placeholder for index 0
    {{0,-1}, {0,1}},     // 1: left, right
    {{-1,0}, {1,0}},     // 2: up, down
    {{0,-1}, {1,0}},     // 3: left, down
    {{0,1},  {1,0}},     // 4: right, down
    {{0,-1}, {-1,0}},    // 5: left, up
    {{0,1},  {-1,0}},    // 6: right, up
};

class Solution{
    private:
    public:
        bool bfs(std::vector<std::vector<int>> grid){
            int max_y = grid.size();
            int max_x = grid[0].size();

            std::vector<std::vector<bool>> visited(max_y, std::vector<bool>(max_x, false));
            std::queue<std::pair<int,int>> q;

            q.push({0, 0});
            visited[0][0] = true;

            while(!q.empty()) {
                auto [x,y] = q.front();
                q.pop();

                int street = grid[y][x];

                // checking for final condition
                if( x == max_x - 1  && y == max_y - 1) return true;

                for(auto [dy, dx] : directions[street]) {

                    int nx = x + dx;
                    int ny = y + dy;
                    if(nx < 0 || nx >= max_x || ny < 0 || ny >= max_y) continue;
                    if(visited[ny][nx]) continue;
                    //reverse 
                    int next_street = grid[ny][nx];
                    for(auto [ry, rx] : directions[next_street]) {
                        if(nx + rx == x && ny + ry == y) {
                            std::cout << "next: " << nx << " " << ny << std::endl;
                            visited[ny][nx] = true;
                            q.push({nx,ny});
                            break;
                        };
                    };
                };
            };
            return false;
        };
};

bool valid_path(std::vector<std::vector<int>> grid){
    Solution s;
    return s.bfs(grid);
};

int main() {
    std::vector<std::vector<int>> grid = {{2,4,3},
                                          {6,5,2}}; // should be true
    std::cout << "Valid path: " << valid_path(grid) << std::endl;
    return 0;
}