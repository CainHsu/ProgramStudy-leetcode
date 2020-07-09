//
// Created by xuche on 2020/7/9.
//

#ifndef PROGRAMSTUDY_LEETCODE_34_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_HPP
#define PROGRAMSTUDY_LEETCODE_34_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_HPP

#include "vector"

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    if(nums.size() == 1){
        if(nums.front() == target){
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
    }
    for(int i = 0, j = nums.size()-1; i <= j; ){
        int mid = (i + j)/2;
        if(nums[mid] > target){
            j = mid - 1;
        }
        else if(nums[mid] < target){
            i = mid + 1;
        }
        else{
            int k = mid;
            while(0 < k && nums[k] == nums[k-1]){
                --k;
            }
            ans.push_back(k);
            k = mid;
            while(k < nums.size()-1 && nums[k] == nums[k+1]){
                ++k;
            }
            ans.push_back(k);
            return ans;
        }
    }
    vector<int> noans({-1,-1});
    return noans;
}

#endif //PROGRAMSTUDY_LEETCODE_34_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_HPP
