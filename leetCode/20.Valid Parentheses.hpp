//
// Created by CainHsu on 2019/12/7.
//

#ifndef TEST_20_VALID_PARENTHESES_HPP
#define TEST_20_VALID_PARENTHESES_HPP

#include "stack"
#include "string"

using namespace std;

bool isValid(string s) {

    if(s.empty()) return true;
    if(s.length()&1) return false;
    stack<char> temp;

    for(auto i:s){
        if(i == '[' || i == '(' || i == '{') temp.push(i);

        if((i == '}' || i == ')' || i == ']') && temp.empty()) {
            return false;
        }

        if((i == ')' && temp.top() == '(') || (i == ']' && temp.top() == '[') || (i == '}' && temp.top() == '{')) temp.pop();
    }
    return temp.empty();

}

#endif //TEST_20_VALID_PARENTHESES_HPP
