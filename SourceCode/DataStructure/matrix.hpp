//
// Created by xuche on 2019/11/5.
//

#ifndef TEST_MATRIX_HPP
#define TEST_MATRIX_HPP

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

#endif //TEST_MATRIX_HPP
