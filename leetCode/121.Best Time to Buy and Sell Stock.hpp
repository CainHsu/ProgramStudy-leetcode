//
// Created by xuche on 2020/7/18.
//

#ifndef PROGRAMSTUDY_LEETCODE_121_BEST_TIME_TO_BUY_AND_SELL_STOCK_HPP
#define PROGRAMSTUDY_LEETCODE_121_BEST_TIME_TO_BUY_AND_SELL_STOCK_HPP

#include "vector"
#include "algorithm"

using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;
    int minPrice = prices[0], profit = 0;
    for(int index = 0; index < prices.size(); ++index){
        minPrice = min(prices[index], minPrice);
        profit = max(prices[index]-minPrice, profit);
    }
    return profit;
}

#endif //PROGRAMSTUDY_LEETCODE_121_BEST_TIME_TO_BUY_AND_SELL_STOCK_HPP
