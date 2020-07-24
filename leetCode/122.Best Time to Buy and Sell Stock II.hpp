//
// Created by xuche on 2020/7/24.
//

#ifndef PROGRAMSTUDY_LEETCODE_122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_HPP
#define PROGRAMSTUDY_LEETCODE_122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_HPP

#include "vector"
#include "algorithm"

using namespace std;

int maxProfit(vector<int>& prices) {
    int maxVal = 0, minPrice = prices[0];
    for(const auto& x:prices){
        minPrice = min(x, minPrice);
        if(maxVal + x - minPrice > maxVal){
            maxVal = maxVal + x - minPrice;
            minPrice = x;
        }
    }
    return maxVal;
}

#endif //PROGRAMSTUDY_LEETCODE_122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_HPP
