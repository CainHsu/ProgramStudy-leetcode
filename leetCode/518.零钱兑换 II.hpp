//
// Created by xuche on 2020/9/7.
//

#ifndef PROGRAMSTUDY_LEETCODE_518_零钱兑换_II_HPP
#define PROGRAMSTUDY_LEETCODE_518_零钱兑换_II_HPP

#include "vector"

using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp.front() = 1;
    for(int coin : coins){
        for(int i = coin; i <= amount; ++i){
            dp[i] += dp[i - coin];
        }
    }
    return dp.back();
}

#endif //PROGRAMSTUDY_LEETCODE_518_零钱兑换_II_HPP
