//
// Created by xuche on 2020/8/17.
//

#ifndef PROGRAMSTUDY_LEETCODE_1451_REARRANGE_WORDS_IN_A_SENTENCE_HPP
#define PROGRAMSTUDY_LEETCODE_1451_REARRANGE_WORDS_IN_A_SENTENCE_HPP

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void exchangeX(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

string arrangeWords(string text) {
    if(text.empty()) return text;
    stringstream ss(text);
    string p;
    vector<string> strs;
    while(getline(ss, p, ' ')){
        p[0] = tolower(p[0]);
        strs.push_back(p);
    }
    stable_sort(strs.begin(), strs.end(), [](const string &a, const string &b){
        return a.size() < b.size();
    });
    string res;
    for(auto &i : strs){
        res += i;
        res += " ";
    }
    res.pop_back();
    res.front() = res.front() - 'a' + 'A';
    return res;
}

#endif //PROGRAMSTUDY_LEETCODE_1451_REARRANGE_WORDS_IN_A_SENTENCE_HPP
