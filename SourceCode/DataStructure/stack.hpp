//
// Created by CainHsu on 2019/12/6.
//

#ifndef TEST_STACK_HPP
#define TEST_STACK_HPP

#include "string"
#include "stack"

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


vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans;
    if(T.empty()) return ans;
    ans.resize(T.size());
    stack<int> index;
    for(int i = 0; i < T.size(); ++i){
        while ((!index.empty()) && T[i] > T[index.top()]) {
            ans[index.top()] = i - index.top();
            index.pop();
        }
        index.push(i);
    }
    while(!index.empty()){
        ans[index.top()] = 0;
        index.pop();
    }
    return ans;
}


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

#endif //TEST_STACK_HPP
