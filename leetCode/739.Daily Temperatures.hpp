//
// Created by CainHsu on 2019/12/7.
//

#ifndef TEST_739_DAILY_TEMPERATURES_HPP
#define TEST_739_DAILY_TEMPERATURES_HPP

#include "vector"
#include "stack"

using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans;
    if(T.empty()) return ans;
    ans.resize(T.size());
    stack<int> index;
    for(int i = 0; i < T.size(); ++i){
        while ((!index.empty()) && T[i] > T[index.top()]) {
            ans[index.top()] = i - index.top();
            index.pop();
        }
        index.push(i);
    }
    while(!index.empty()){
        ans[index.top()] = 0;
        index.pop();
    }
    return ans;
}

#endif //TEST_739_DAILY_TEMPERATURES_HPP
