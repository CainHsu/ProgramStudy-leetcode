//
// Created by xuche on 2020/7/14.
//

#ifndef PROGRAMSTUDY_LEETCODE_120_TRIANGLE_HPP
#define PROGRAMSTUDY_LEETCODE_120_TRIANGLE_HPP

#include "vector"
#include "algorithm"

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> nums;
    int n = triangle.size();
    nums.push_back({triangle[0][0]});
    for(int i = 1; i < n; ++i){
        nums.push_back({});
        nums[i].push_back(nums[i-1][0] + triangle[i][0]);
        for(int j = 1; j < triangle[i].size() - 1; ++j){
            nums[i].push_back(min(nums[i-1][j-1], nums[i-1][j]) + triangle[i][j]);
        }
        int lastEndNumIndex = nums[i-1].size() - 1;
        int nowEndNumIndex = lastEndNumIndex + 1;
        nums[i].push_back(nums[i-1][lastEndNumIndex] + triangle[i][nowEndNumIndex]);
    }
    return *min_element(nums[n-1].begin(), nums[n-1].end());
}

#endif //PROGRAMSTUDY_LEETCODE_120_TRIANGLE_HPP
