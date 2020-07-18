//
// Created by xuche on 2020/7/18.
//

#ifndef PROGRAMSTUDY_LEETCODE_53_MAXIMUM_SUBARRAY_HPP
#define PROGRAMSTUDY_LEETCODE_53_MAXIMUM_SUBARRAY_HPP

#include "vector"
#include "algorithm"

using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.empty()) return -2147483648;
    int pre = 0, maxAns = nums[0];
    for(auto const &x:nums){
        pre = max(pre+x, x);
        maxAns = max(pre, maxAns);
    }
    return maxAns;
}

#endif //PROGRAMSTUDY_LEETCODE_53_MAXIMUM_SUBARRAY_HPP
