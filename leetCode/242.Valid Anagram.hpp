//
// Created by xuche on 2020/6/7.
//

#ifndef PROGRAMSTUDY_LEETCODE_242_VALID_ANAGRAM_HPP
#define PROGRAMSTUDY_LEETCODE_242_VALID_ANAGRAM_HPP

#include "string"

using namespace std;

void exch(string & s, int i, int j){
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
void sort(string & s){
    int N = s.size();
    int h = 1;
    while(h < N/3) h = 3*h + 1;
    while(h >= 1){
        for(int i = h; i < N; ++i){
            for(int j = i; j >= h && s[j] < s[j - h]; j -= h){
                exch(s, j, j-h);
            }
        }
        h /= 3;
    }
}
bool isAnagram(string s, string t) {
    if(s.size() != t.size())
        return false;
    if(s.empty() && t.empty())
        return true;
    if(!s.empty()&&t.empty() || !t.empty()&&s.empty())
        return false;
    sort(s);
    sort(t);
    return s == t;
}

#endif //PROGRAMSTUDY_LEETCODE_242_VALID_ANAGRAM_HPP
