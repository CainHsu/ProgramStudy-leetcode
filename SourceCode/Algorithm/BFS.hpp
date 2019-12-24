//
// Created by xuche on 2019/12/20.
//

#ifndef PROGRAMSTUDY_LEETCODE_BFS_HPP
#define PROGRAMSTUDY_LEETCODE_BFS_HPP

#include <vector>
#include "queue"
#include "string"
#include "unordered_set"

using std::vector;
using std::queue;
using std::pair;

int numIslandsBFS(vector<vector<char>>& grid) {
    if(grid.empty())
        return 0;
    unsigned int row = grid.size();
    unsigned int col = grid[0].size();
    int num_island = 0;
    for(unsigned int i = 0; i < row; ++i){
        for(unsigned int j = 0; j <  col; ++j){
            if(grid[i][j] == '1'){
                ++num_island;
                queue<pair<int, int>> Q;
                grid[i][j] = '0';
                Q.push({i, j});
                while(!Q.empty()){
                    int x = Q.front().first;
                    int y = Q.front().second;
                    Q.pop();
                    if((y + 1 < col) && (grid[x][y + 1] == '1')){
                        Q.push({x, y+1});
                        grid[x][y+1] = '0';
                    }
                    if((x - 1 >= 0)  && (grid[x - 1][y] == '1')){
                        Q.push({x - 1, y});
                        grid[x - 1][y] = '0';
                    }
                    if((x + 1 < row) && (grid[x + 1][y] == '1')){
                        Q.push({x+1, y});
                        grid[x+1][y] = '0';
                    }
                    if((y - 1 >= 0) && (grid[x][y - 1] == '1')){
                        Q.push({x, y-1});
                        grid[x][y-1] = '0';
                    }
                }
            }
        }
    }
    return num_island;
}


using std::vector;
using std::string;
using std::unordered_set;

int openLock(vector<string>& deadends, string target) {
    if(target == "0000") return 0;
    unordered_set<string> deads(deadends.begin(), deadends.end());
    queue<string > Q;
    unordered_set<string> visited;
    Q.push("0000");
    int depth = 0;
    while(!Q.empty()){
        string cur = Q.front();
        Q.pop();
        int size = Q.size();
        for(int cir = 0; cir < size; ++cir) {
            ++depth;
            for (int i = 0; i < 4; ++i) {
                string temp = cur;
                temp[i] = (temp[i] + 1) % 10;
                if (deads.find(temp) != deads.end() && visited.find(temp) != visited.end()) {
                    if (temp == target) return depth;
                    Q.push(temp);
                    visited.insert(temp);
                }
                temp = cur;
                temp[i] = (temp[i] - 1) % 10;
                if (deads.find(temp) != deads.end() && visited.find(temp) != visited.end()) {
                    if (temp == target) return depth;
                    Q.push(temp);
                    visited.insert(temp);
                }
            }
        }
    }
    return -1;
}

#endif //PROGRAMSTUDY_LEETCODE_BFS_HPP
