//
// Created by xuche on 2020/7/10.
//

#ifndef PROGRAMSTUDY_LEETCODE_39_COMBINATION_SUM_HPP
#define PROGRAMSTUDY_LEETCODE_39_COMBINATION_SUM_HPP

#include "vector"
#include "algorithm"

using namespace std;

class Solution39 {
private:
    vector<int> candidates;
public:
    vector<vector<int>> res;
    vector<int> path;
    void DFS(int subTarget, int start){
        if(subTarget == 0){
            res.push_back(path);
            return;
        }
        for(int i = start; i < candidates.size(); ++i){
            if(subTarget - candidates[i] >= 0){
                path.push_back(candidates[i]);
                DFS(subTarget - candidates[i], i);
                path.pop_back();
            }
            else
                break;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates = candidates;
        sort(this->candidates.begin(), this->candidates.end());
        DFS(target, 0);
        return res;
    }
};


#endif //PROGRAMSTUDY_LEETCODE_39_COMBINATION_SUM_HPP
