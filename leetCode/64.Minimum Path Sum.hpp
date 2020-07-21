//
// Created by xuche on 2020/7/21.
//

#ifndef PROGRAMSTUDY_LEETCODE_64_MINIMUM_PATH_SUM_HPP
#define PROGRAMSTUDY_LEETCODE_64_MINIMUM_PATH_SUM_HPP

#include "vector"
#include "algorithm"

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for(int i = 1; i < n; ++i){
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    for(int i = 1; i < m; ++i){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp.back().back();
}

#endif //PROGRAMSTUDY_LEETCODE_64_MINIMUM_PATH_SUM_HPP
