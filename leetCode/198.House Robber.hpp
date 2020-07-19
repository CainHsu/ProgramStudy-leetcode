//
// Created by xuche on 2020/7/19.
//

#ifndef PROGRAMSTUDY_LEETCODE_198_HOUSE_ROBBER_HPP
#define PROGRAMSTUDY_LEETCODE_198_HOUSE_ROBBER_HPP

#include "vector"
#include "algorithm"

using namespace std;

int rob(vector<int>& nums) {
    if(nums.empty()) return 0;
    int n = nums.size();
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; ++i){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
}

#endif //PROGRAMSTUDY_LEETCODE_198_HOUSE_ROBBER_HPP
