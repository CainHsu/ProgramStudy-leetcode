//
// Created by xuche on 2020/7/10.
//

#ifndef PROGRAMSTUDY_LEETCODE_40_COMBINATION_SUM_II_HPP
#define PROGRAMSTUDY_LEETCODE_40_COMBINATION_SUM_II_HPP

#include "vector"
#include "algorithm"

using namespace std;

class Solution40 {
private:
    vector<int> path, candidates;
    vector<vector<int>> res;
public:
    void DFS(int subTarget, int start){
        if(subTarget == 0){
            for(auto i : res){
                if(path == i)
                    return;
            }
            res.push_back(path);
            return;
        }
        for(int i = start; i < candidates.size(); ++i){
            if(subTarget - candidates[i] >= 0){
                if (i > start && candidates[i] == candidates[i - 1])
                    continue;
                path.push_back(candidates[i]);
                DFS(subTarget - candidates[i], i + 1);
                path.pop_back();
            }
            else{
                break;
            }
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->candidates = candidates;
        sort(this->candidates.begin(), this->candidates.end());
        DFS(target, 0);
        return res;
    }
};


#endif //PROGRAMSTUDY_LEETCODE_40_COMBINATION_SUM_II_HPP
