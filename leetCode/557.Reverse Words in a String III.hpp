//
// Created by xuche on 2020/8/9.
//

#ifndef PROGRAMSTUDY_LEETCODE_557_REVERSE_WORDS_IN_A_STRING_III_HPP
#define PROGRAMSTUDY_LEETCODE_557_REVERSE_WORDS_IN_A_STRING_III_HPP

#include "string"

using namespace std;

string reverseWords(string s) {
    int lastSpace = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == ' '){
            reverse(s.begin() + lastSpace, s.begin() + i);
            lastSpace = i + 1;
        }
    }
    reverse(s.begin() + lastSpace, s.end());
    return s;
}

#endif //PROGRAMSTUDY_LEETCODE_557_REVERSE_WORDS_IN_A_STRING_III_HPP
