//
// Created by xuche on 2020/7/4.
//

#ifndef PROGRAMSTUDY_LEETCODE_18_4SUM_HPP
#define PROGRAMSTUDY_LEETCODE_18_4SUM_HPP

#include "vector"
#include "algorithm"

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if(nums.empty())
        return ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i < n ; ++i){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        for(int j = i+1; j < n; ++j){
            if(j > i+1 && nums[j-1] == nums[j]){
                continue;
            }

            int temp = target - (nums[i] + nums[j]);
            int l = n-1;
            for(int k = j+1; k < n; ++k){
                if(k > j+1 && nums[k-1] == nums[k]){
                    continue;
                }
                while(k < l && temp < nums[k] + nums[l]){
                    --l;
                }
                if(k == l)
                    break;
                if(nums[k] + nums[l] == temp)
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
            }
        }
    }
    return ans;
}

#endif //PROGRAMSTUDY_LEETCODE_18_4SUM_HPP
