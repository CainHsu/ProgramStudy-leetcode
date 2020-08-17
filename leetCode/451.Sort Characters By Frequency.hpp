//
// Created by xuche on 2020/8/17.
//

#ifndef PROGRAMSTUDY_LEETCODE_451_SORT_CHARACTERS_BY_FREQUENCY_HPP
#define PROGRAMSTUDY_LEETCODE_451_SORT_CHARACTERS_BY_FREQUENCY_HPP

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string frequencySort(string s) {
    if(s.empty()) return s;
    unordered_map<char, int> cnt;
    for(const char& c:s) ++cnt[c];
    sort(s.begin(), s.end(), [&](char &a, char &b){
        return cnt[a] > cnt[b] || cnt[a] == cnt[b] && a < b;
    });
    return s;
}

#endif //PROGRAMSTUDY_LEETCODE_451_SORT_CHARACTERS_BY_FREQUENCY_HPP
