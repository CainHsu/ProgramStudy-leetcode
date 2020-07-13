//
// Created by xuche on 2020/7/13.
//

#ifndef PROGRAMSTUDY_LEETCODE_41_FIRST_MISSING_POSITIVE_HPP
#define PROGRAMSTUDY_LEETCODE_41_FIRST_MISSING_POSITIVE_HPP

#include "vector"

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(auto &num : nums){
        if(num <= 0)
            num = n+1;
    }
    for(int i = 0; i < n; ++i){
        int newIndex = abs(nums[i]);
        if(newIndex <= n){
            nums[newIndex - 1] = -abs(nums[newIndex - 1]);
        }
    }
    for(int i = 0; i < n; ++i){
        if(nums[i] > 0)
            return i + 1;
    }
    return n + 1;
}

#endif //PROGRAMSTUDY_LEETCODE_41_FIRST_MISSING_POSITIVE_HPP
