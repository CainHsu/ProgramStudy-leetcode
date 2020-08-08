//
// Created by xuche on 2020/8/9.
//

#ifndef PROGRAMSTUDY_LEETCODE_58_LENGTH_OF_LAST_WORD_HPP
#define PROGRAMSTUDY_LEETCODE_58_LENGTH_OF_LAST_WORD_HPP

#include "string"

using namespace std;

int lengthOfLastWord(string s) {
    int j = s.size() - 1;
    int res = 0;
    while(j >= 0 && s[j] == ' '){
        --j;
    }
    while(j >= 0 && s[j] != ' '){
        ++res;
        --j;
    }
    return res;
}

#endif //PROGRAMSTUDY_LEETCODE_58_LENGTH_OF_LAST_WORD_HPP
