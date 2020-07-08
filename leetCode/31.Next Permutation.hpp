//
// Created by xuche on 2020/7/8.
//

#ifndef PROGRAMSTUDY_LEETCODE_31_NEXT_PERMUTATION_HPP
#define PROGRAMSTUDY_LEETCODE_31_NEXT_PERMUTATION_HPP

#include "vector"

using namespace std;

void nextPermutation(vector<int>& nums) {
    int p = nums.size() - 1;
    while(p > 0 && nums[p] <= nums[p-1]){
        --p;
    }
    reverse(nums.begin() + p, nums.end());
    if(p > 0){
        for(int ex = p; ex < nums.size(); ++ex){
            if(nums[p - 1] < nums[ex]){
                int temp = nums[p - 1];
                nums[p - 1] = nums[ex];
                nums[ex] = temp;
                break;
            }
        }
    }
}

#endif //PROGRAMSTUDY_LEETCODE_31_NEXT_PERMUTATION_HPP
