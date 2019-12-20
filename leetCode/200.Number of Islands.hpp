//
// Created by xuche on 2019/12/20.
//

#ifndef PROGRAMSTUDY_LEETCODE_200_NUMBER_OF_ISLANDS_HPP
#define PROGRAMSTUDY_LEETCODE_200_NUMBER_OF_ISLANDS_HPP

#include "vector"
#include "queue"

using std::vector;
using std::queue;
using std::pair;

int numIslandsBFS(vector<vector<char>>& grid) {
    if(grid.empty())
        return 0;
    unsigned int row = grid.size();
    unsigned int col = grid[0].size();
    unsigned int num_island = 0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j <  col; ++j){
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

#endif //PROGRAMSTUDY_LEETCODE_200_NUMBER_OF_ISLANDS_HPP
