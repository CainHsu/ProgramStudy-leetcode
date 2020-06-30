//
// Created by xuche on 2020/6/30.
//

#ifndef PROGRAMSTUDY_LEETCODE_16_3SUM_CLOSEST_HPP
#define PROGRAMSTUDY_LEETCODE_16_3SUM_CLOSEST_HPP

#include "vector"
#include "algorithm"

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = 10*(target+10)+10;
    int n = nums.size();
    for(int first = 0; first < n ; first++){
        if(first > 0 && nums[first] == nums[first-1]){

            continue;
        }

        int second = first+1, third = n-1;
        while(second < third){
            int threeSum = nums[first] + nums[second] + nums[third];
            if(threeSum == target){
                return target;
            }
            if(abs(target - ans) > abs(target - threeSum)){
                ans = threeSum;
            }
            if(threeSum > target){
                int t0 = third - 1;
                while(second < t0 && nums[t0] == nums[third]){
                    --t0;
                }
                third = t0;
            }
            else{
                int s0 = second + 1;
                while(s0 < third && nums[s0] == nums[second]){
                    ++s0;
                }
                second = s0;
            }

        }
    }
    return ans;
}


#endif //PROGRAMSTUDY_LEETCODE_16_3SUM_CLOSEST_HPP
