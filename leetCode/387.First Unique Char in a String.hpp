//
// Created by CainHsu on 2019/10/22.
//

#ifndef TEST_387_FIRST_UNIQUE_CHAR_IN_A_STRING_HPP
#define TEST_387_FIRST_UNIQUE_CHAR_IN_A_STRING_HPP

#include "iostream"
#include "unordered_map"

int firstUniqChar(std::string s) {
    std::unordered_map<char, int> temp;
    for(auto i:s){
        auto iter = temp.find(i);
        if(iter == temp.end())
            temp[i] = 1;
        else
            temp[i]++;
    }
    for(int i = 0; i < s.size(); ++i){
        if(temp[s[i]] == 1)
            return i;
    }
    return -1;
}

#endif //TEST_387_FIRST_UNIQUE_CHAR_IN_A_STRING_HPP
