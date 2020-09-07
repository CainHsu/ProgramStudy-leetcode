//
// Created by xuche on 2020/9/7.
//

#ifndef PROGRAMSTUDY_LEETCODE_322_零钱兑换_HPP
#define PROGRAMSTUDY_LEETCODE_322_零钱兑换_HPP

#include "vector"
#include "algorithm"

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for(int i = 1; i <= amount; ++i){
        int temp = 2*amount;
        for(int coin : coins){
            if(i - coin < 0 || dp[i - coin] == -1) continue;
            temp = min(dp[i - coin] + 1, temp);
        }
        dp[i] = temp == 2*amount ? -1 : temp;
    }
    return dp.back();
}

#endif //PROGRAMSTUDY_LEETCODE_322_零钱兑换_HPP
