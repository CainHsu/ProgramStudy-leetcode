//
// Created by xuche on 2020/7/23.
//

#ifndef PROGRAMSTUDY_LEETCODE_213_HOUSE_ROBBER_II_HPP
#define PROGRAMSTUDY_LEETCODE_213_HOUSE_ROBBER_II_HPP

#include "vector"
#include "algorithm"

using namespace std;

int rob(vector<int>& nums) {
    if(nums.empty()) return 0;
    int numOfHouse = nums.size();
    if(numOfHouse == 1) return nums[0];
    if(numOfHouse == 2) return max(nums[0], nums[1]);
    int maxValOrder = 0, maxValReserve = 0;
    vector<int> dp(numOfHouse);
    dp[0] = 0;
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for(int i = 2; i < numOfHouse; ++i){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    maxValOrder = dp[numOfHouse-1];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < numOfHouse-1; ++i){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    maxValReserve = dp[numOfHouse-2];
    return max(maxValOrder, maxValReserve);
}

#endif //PROGRAMSTUDY_LEETCODE_213_HOUSE_ROBBER_II_HPP
