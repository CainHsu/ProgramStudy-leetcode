//
// Created by xuche on 2020/7/12.
//

#ifndef PROGRAMSTUDY_LEETCODE_287_FIND_THE_DUPLICATE_NUMBER_HPP
#define PROGRAMSTUDY_LEETCODE_287_FIND_THE_DUPLICATE_NUMBER_HPP

#include "vector"
#include "algorithm"

using namespace std;

int findDuplicate(vector<int>& nums) {
    if(nums.empty()) return -1;
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int findDuplicate2(vector<int>& nums){
     sort(nums.begin(), nums.end());
     for(int i = 0; i < nums.size(); ++i){
         if(i>0){
             if(nums[i] == nums[i-1])
                 return nums[i];
         }
     }
     return -1;
}

#endif //PROGRAMSTUDY_LEETCODE_287_FIND_THE_DUPLICATE_NUMBER_HPP
