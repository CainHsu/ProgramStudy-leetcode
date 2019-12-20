//
// Created by 徐琛 on 2019/10/18.
//

#ifndef TEST_ELSE_HPP
#define TEST_ELSE_HPP

#include "vector"
#include "unordered_map"

int majorityElement(std::vector<int>& nums) {
    int n = nums.size();
    std::unordered_map<int, int> temp;
    for(auto i:nums){
        temp[i] = 0;
    }
    for(auto i:nums){
        ++temp[i];
    }
    for(auto i:nums){
        if(temp[i] > n/2){
            return i;
        }
    }
    return 0;
}

#endif //TEST_ELSE_HPP
