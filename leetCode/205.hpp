//
// Created by CainHsu on 2019/10/19.
//

#ifndef TEST_205_HPP
#define TEST_205_HPP


#include <unordered_set>
#include <unordered_map>
#include <string>
#include "vector"


bool isIsomorphic(std::string s, std::string t) {
    if(s.size() != t.size()) return false;
    std::unordered_map<char, char> temp;
    for(int i = 0; i < s.size(); ++i){
        auto iter = temp.find(s[i]);

        // 存在key但映射与原映射不相同则false
        if(iter != temp.end())
            if(temp[s[i]] != t[i]) return false;
            else continue;

        // 若不同key的value相同则false
        for(int j = 0; j < temp.size(); ++j)
            if(temp[s[j]] == t[i]) return false;


        temp[s[i]] = t[i];
    }
    return true;
}

#endif //TEST_205_HPP
