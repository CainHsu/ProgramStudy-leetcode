//
// Created by xuche on 2019/12/8.
//

#ifndef PROGRAMSTUDY_LEETCODE_150_EVALUATE_REVERSE_POLISH_NOTATION_HPP
#define PROGRAMSTUDY_LEETCODE_150_EVALUATE_REVERSE_POLISH_NOTATION_HPP

#include "vector"
#include "string"
#include "stack"

using namespace std;

int evalRPN(vector<string>& tokens) {
    int res = 0;
    stack<string > temp;
    for(auto i:tokens){
        if(i != "+" && i != "-" && i != "*" && i != "/") temp.push(i);
        else{
            if(i == "+"){
                string a = temp.top();
                temp.pop();
                string b = temp.top();
                temp.pop();
                temp.push(to_string(stoi(a) + stoi(b)));
            }
            if(i == "-"){
                string a = temp.top();
                temp.pop();
                string b = temp.top();
                temp.pop();
                temp.push(to_string(stoi(b) - stoi(a)));
            }
            if(i == "*"){
                string a = temp.top();
                temp.pop();
                string b = temp.top();
                temp.pop();
                temp.push(to_string(stoi(a) * stoi(b)));
            }
            if(i == "/"){
                string a = temp.top();
                temp.pop();
                string b = temp.top();
                temp.pop();
                temp.push(to_string((int)(stoi(b) / stoi(a))));
            }
        }
    }
    return stoi(temp.top());
}

#endif //PROGRAMSTUDY_LEETCODE_150_EVALUATE_REVERSE_POLISH_NOTATION_HPP
