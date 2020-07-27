//
// Created by xuche on 2020/7/27.
//

#ifndef PROGRAMSTUDY_LEETCODE_63_UNIQUE_PATHS_II_HPP
#define PROGRAMSTUDY_LEETCODE_63_UNIQUE_PATHS_II_HPP

#include "vector"

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid.empty()) return 0;
    if(obstacleGrid[0][0] == 1) return 0;
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 1; i < m; ++i){
        if(obstacleGrid[0][i] == 1){
            while(i < m){
                dp[0][i] = 0;
                ++i;
            }
        } else
            dp[0][i] = 1;
    }
    for(int i = 0; i < n; ++i){
        if(obstacleGrid[i][0] == 1){
            while (i < n){
                dp[i][0] = 0;
                ++i;
            }
        } else
            dp[i][0] = 1;
    }
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < m; ++j){
            if(obstacleGrid[i][j] == 1){
                dp[i][j] = 0;
            } else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}


#endif //PROGRAMSTUDY_LEETCODE_63_UNIQUE_PATHS_II_HPP
