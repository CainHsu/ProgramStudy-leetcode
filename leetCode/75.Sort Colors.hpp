//
// Created by CainHsu on 2019/11/5.
//

#ifndef TEST_75_SORT_COLORS_HPP
#define TEST_75_SORT_COLORS_HPP

#include "stdio.h"
#include "vector"

void sortColors(std::vector<int>& nums) {
    if(nums.empty())
        return;
    std::vector<int> temp;
    temp.resize(3,0);
    for(auto i : nums){
        switch(i){
            case 0:
                temp[0]++;
                break;
            case 1:
                temp[1]++;
                break;
            case 2:
                temp[2]++;
                break;
            default:
                break;
        }
    }
    for(int i = 0; i < temp[0]; ++i) nums[i] = 0;
    for(int i = temp[0]; i < temp[0]+temp[1]; ++i) nums[i] = 1;
    for(int i = temp[0] + temp[1]; i < temp[0] + temp[1]+temp[2]; ++i) nums[i] = 2;
}

#endif //TEST_75_SORT_COLORS_HPP
