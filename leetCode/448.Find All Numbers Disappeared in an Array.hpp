//
// Created by xuche on 2020/7/12.
//

#ifndef PROGRAMSTUDY_LEETCODE_448_FIND_ALL_NUMBERS_DISAPPEARED_IN_AN_ARRAY_HPP
#define PROGRAMSTUDY_LEETCODE_448_FIND_ALL_NUMBERS_DISAPPEARED_IN_AN_ARRAY_HPP

#include "vector"
#include "unordered_set"

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    if(nums.empty() || nums.size() == 1) return ans;
    for(int i = 0; i < nums.size(); ++i){
        int newIndex = abs(nums[i]) - 1;
        if(nums[newIndex] > 0)
            nums[newIndex] *= -1;
    }
    for(int i = 0; i < nums.size(); ++i){
        if(nums[i] > 0)
            ans.push_back(i + 1);
    }
    return ans;
}

vector<int> findDisappearedNumbers2(vector<int>& nums){
    vector<int> ans;
    if(nums.empty() || nums.size() == 1) return ans;
    unordered_set<int> s;
    for(auto num : nums){
        s.insert(num);
    }
    for(int i = 0; i < nums.size(); ++i){
        auto iter = s.find(i+1);
        if(iter == s.end())
            ans.push_back(i+1);
    }
    return ans;
}

#endif //PROGRAMSTUDY_LEETCODE_448_FIND_ALL_NUMBERS_DISAPPEARED_IN_AN_ARRAY_HPP
