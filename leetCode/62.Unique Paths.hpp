//
// Created by xuche on 2020/7/21.
//

#ifndef PROGRAMSTUDY_LEETCODE_62_UNIQUE_PATHS_HPP
#define PROGRAMSTUDY_LEETCODE_62_UNIQUE_PATHS_HPP

#include "vector"

using namespace std;

int uniquePaths(int m, int n) {
    if(m == 0 || n == 0) return 0;
    if(n == 1 || m == 1) return 1;
    vector<int> dp(m-1,1);
    for(int i = 1; i < n; ++i){
        int begin = 1;
        for(int j = 0; j < m-1; ++j){
            dp[j] = begin + dp[j];
            begin = dp[j];
        }
    }
    return dp.back();
}

#endif //PROGRAMSTUDY_LEETCODE_62_UNIQUE_PATHS_HPP
