//
// Created by xuche on 2020/8/21.
//

#ifndef PROGRAMSTUDY_LEETCODE_78_SUBSETS_HPP
#define PROGRAMSTUDY_LEETCODE_78_SUBSETS_HPP

#include <vector>

using namespace std;

vector<vector<int>> res;
void traceBack(vector<int> &trace, vector<int> &nums, int lastIndex){
    res.emplace_back(trace);
    // cout << trace.size() << endl;
    for(int i = lastIndex; i < nums.size(); ++i){
        trace.emplace_back(nums[i]);
        traceBack(trace, nums, i + 1);
        trace.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> trace;
    traceBack(trace, nums, 0);
    return res;
}

#endif //PROGRAMSTUDY_LEETCODE_78_SUBSETS_HPP
