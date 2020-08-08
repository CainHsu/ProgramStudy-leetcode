//
// Created by xuche on 2020/8/9.
//

#ifndef PROGRAMSTUDY_LEETCODE_917_REVERSE_ONLY_LETTERS_HPP
#define PROGRAMSTUDY_LEETCODE_917_REVERSE_ONLY_LETTERS_HPP

#include "string"

using namespace std;

string reverseOnlyLetters(string S) {
    int i = 0, j = S.size() - 1;
    while(i < j){
        if(!(S[i] >= 'a' && S[i] <= 'z' || S[i] >= 'A' && S[i] <= 'Z')){
            ++i;
            continue;
        }
        if(!(S[j] >= 'a' && S[j] <= 'z' || S[j] >= 'A' && S[j] <= 'Z')){
            --j;
            continue;
        }
        char temp = S[i];
        S[i] = S[j];
        S[j] = temp;
        ++i;
        --j;
    }
    return S;
}

#endif //PROGRAMSTUDY_LEETCODE_917_REVERSE_ONLY_LETTERS_HPP
