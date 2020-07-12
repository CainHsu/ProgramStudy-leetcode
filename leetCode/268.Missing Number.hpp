//
// Created by xuche on 2020/7/12.
//

#ifndef PROGRAMSTUDY_LEETCODE_268_MISSING_NUMBER_HPP
#define PROGRAMSTUDY_LEETCODE_268_MISSING_NUMBER_HPP

#include "vector"
#include "unordered_set"
#include "algorithm"

using namespace std;

int missingNumber(vector<int>& nums) {

    if(nums.empty()) return 0;
    int n = nums.size();
    int all = n*(n+1)/2;
    for(auto num : nums){
        all -= num;
    }
    return all;
}

int missingNumber2(vector<int>& nums){
     if(nums.empty()) return 0;
     unordered_set<int> s;
     for(auto num : nums){
         s.insert(num);
     }
     for(int i = 0; i < nums.size() + 1; ++i){
         auto iter = s.find(i);
         if(iter == s.end())
             return i;
     }
     return 0;
}

int missingNumber3(vector<int>& nums){
     if(nums.empty()) return 0;
     sort(nums.begin(), nums.end());
     if(nums.size()-1 == nums.back()) return nums.size();
     for(int i = 0; i < nums.size() + 1; ++i){
         if(nums[i] != i){
             return i;
         }
     }
     return -1;
}

#endif //PROGRAMSTUDY_LEETCODE_268_MISSING_NUMBER_HPP
