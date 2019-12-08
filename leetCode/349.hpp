//
// Created by CainHsu on 2019/10/18.
//

#ifndef TEST_349_HPP
#define TEST_349_HPP

#include "iostream"
#include "unordered_set"
#include "vector"

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> res;
    for(auto i:nums1){
        for(auto j:nums2){
            if(i == j) res.insert(i);
        }
    }
    std::vector<int> ans;
    for(auto i:res){
        ans.push_back(i);
    }
    return ans;
}

#endif //TEST_349_HPP
