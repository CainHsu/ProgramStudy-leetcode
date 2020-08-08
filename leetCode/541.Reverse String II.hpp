//
// Created by xuche on 2020/8/9.
//

#ifndef PROGRAMSTUDY_LEETCODE_541_REVERSE_STRING_II_HPP
#define PROGRAMSTUDY_LEETCODE_541_REVERSE_STRING_II_HPP

#include "string"

using namespace std;

string reverseStr(string s, int k) {
    string res;
    res = "";
    int len = s.size();
    if(len <= k){
        reverse(s.begin(), s.end());
        return s;
    }
    int i = 0;
    for(; i < len/k; ++i){
        if(i % 2 == 0){
            int j = i * k + k - 1;
            while(j >= i*k){
                res.push_back(s[j]);
                --j;
            }
        }
        else{
            int j = i*k;
            while(j < i*k + k){
                res.push_back(s[j]);
                ++j;
            }
        }
    }
    if(len % k){
        if(i % 2){
            int j = i*k;
            while(j < len){
                res.push_back(s[j]);
                ++j;
            }
        }
        else{
            int j = len - 1;
            while(j >= i * k){
                res.push_back(s[j]);
                --j;
            }
        }
    }
    return res;
}

#endif //PROGRAMSTUDY_LEETCODE_541_REVERSE_STRING_II_HPP
