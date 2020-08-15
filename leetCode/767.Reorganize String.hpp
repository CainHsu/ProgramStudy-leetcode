//
// Created by xuche on 2020/8/15.
//

#ifndef PROGRAMSTUDY_LEETCODE_767_REORGANIZE_STRING_HPP
#define PROGRAMSTUDY_LEETCODE_767_REORGANIZE_STRING_HPP

#include "string"
#include "vector"
#include "algorithm"

using namespace std;

string reorganizeString(string &S) {
    vector<int> cnt(26, 0);
    for(const char &c : S) ++cnt[c - 'a'];
    int len = S.size();
    int maxCnt = (len + 1)/2;
    int maxVal = *max_element(cnt.begin(), cnt.end());
    if(maxVal > maxCnt) return "";
    int maxIndex = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    string ans(maxVal, 'a' + maxIndex);
    int insertIndex = 1;
    for(int i = 0; i < 26; ++i){
        if(i == maxIndex) continue;
        while(cnt[i] > 0) {
            ans.insert(insertIndex, 1, 'a' + i);
            insertIndex = (insertIndex + 2) % int(ans.size());
            --cnt[i];
        }
    }
    return ans;
}

#endif //PROGRAMSTUDY_LEETCODE_767_REORGANIZE_STRING_HPP
