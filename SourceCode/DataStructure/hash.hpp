//
// Created by 徐琛 on 2019/10/18.
//

#ifndef TEST_HASH_HPP
#define TEST_HASH_HPP

#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include "vector"
#include "string"

using namespace std;

void showVector(std::vector<int> &temp){
    std::cout << temp[0];
    if(temp.size() == 1) return;
    for(int i = 1; i < temp.size(); ++i){
        std::cout << " ---> ";
        std::cout << temp[i];
    }
    std::cout << std::endl;
}

int singleNumber(std::vector<int>& nums) {
    std::unordered_set<int> bobo;
    int ans;
    for(auto i : nums){
        if(bobo.count(i))   bobo.erase(i);
        else    bobo.insert(i);
    }
    for(auto j : bobo)  ans = j;
    return ans;


}

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


bool isIsomorphic(std::string s, std::string t) {
    if(s.size() != t.size()) return false;
    std::unordered_map<char, char> temp;
    for(int i = 0; i < s.size(); ++i){
        auto iter = temp.find(s[i]);

        // 存在key但映射与原映射不相同则false
        if(iter != temp.end())
            if(temp[s[i]] != t[i]) return false;
            else continue;

        // 若不同key的value相同则false
        for(int j = 0; j < temp.size(); ++j)
            if(temp[s[j]] == t[i]) return false;


         temp[s[i]] = t[i];
    }
    return true;
}


std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::unordered_map<std::string, int> temp;
    std::vector<std::string> tempVec, res;
    int pre = list1.size() + list2.size();

    // 生成名称和Index和的map
    for(int i = 0; i < list1.size(); ++i){
        for(int j = 0; j < list2.size(); ++j){
            if(list1[i] == list2[j]){
                temp[list1[i]] = i + j;
                tempVec.push_back(list1[i]);
            }
        }
    }


    for(int i = 0; i < tempVec.size(); ++i){
        if(temp[tempVec[i]] <= pre){
            pre = temp[tempVec[i]];
        }
    }

    for(int i = 0; i < tempVec.size(); ++i){
        if(temp[tempVec[i]] == pre){
            res.push_back(tempVec[i]);
        }
    }

    return res;
}


int firstUniqChar(std::string s) {
    std::unordered_map<char, int> temp;
    for(auto i:s){
        auto iter = temp.find(i);
        if(iter == temp.end())
            temp[i] = 1;
        else
            temp[i]++;
    }
    for(int i = 0; i < s.size(); ++i){
        if(temp[s[i]] == 1)
            return i;
    }
    return -1;
}

int singleNumber(vector<int>& nums) {
    int num = 0;
    for (vector<int>::size_type i = 0; i < nums.size(); ++i)
        num ^= nums[i];
    return num;
}

#endif //TEST_HASH_HPP
