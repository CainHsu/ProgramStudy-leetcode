//
// Created by xuche on 2020/7/12.
//

#ifndef PROGRAMSTUDY_LEETCODE_38_COUNT_AND_SAY_HPP
#define PROGRAMSTUDY_LEETCODE_38_COUNT_AND_SAY_HPP

#include "string"

using namespace std;

string countAndSay(int n) {
    if(n == 1)
        return "1";
    string data = "123";
    string now = countAndSay(n-1);
    string res = "";
    int count = 0;
    for(int i = 0; i < now.length(); ++i){
        if(now[i] == now[i+1]) {
            ++count;
            continue;
        }
        else{
            res += data[count];
            count = 0;
            res += now[i];
        }
    }
    return res;
}

#endif //PROGRAMSTUDY_LEETCODE_38_COUNT_AND_SAY_HPP
