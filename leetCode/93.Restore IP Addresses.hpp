//
// Created by xuche on 2020/8/21.
//

#ifndef PROGRAMSTUDY_LEETCODE_93_RESTORE_IP_ADDRESSES_HPP
#define PROGRAMSTUDY_LEETCODE_93_RESTORE_IP_ADDRESSES_HPP

#include "vector"
#include "string"
#include "sstream"

using namespace std;

vector<string> res;
bool isVaildIP(string &s){
    stringstream ss(s);
    string num;
    // cout << "-" << s << endl;
    while(getline(ss, num, '.')){
        if(num.size() > 3 || stoi(num) > 255 || num.size() > 1 && num.front() == '0') return false;
    }
    return true;
}
void trackBack(string &s, int dotsLeft, int lastDotIndex){
    if(dotsLeft == 0){
        if(!isVaildIP(s)) return;
        else res.emplace_back(s);
    }
    //    cout << s << "-" << dotsLeft << "-" <<lastDotIndex << endl;
    for(int i = lastDotIndex + 1; i < s.size() && i - lastDotIndex < 4; ++i){
        if(dotsLeft == 1 && s.size() - i > 5) return;
        s.insert(s.begin() + i,  '.');
        --dotsLeft;
        trackBack(s, dotsLeft, i + 1);
        s.erase(i, 1);
        ++dotsLeft;
    }
}
vector<string> restoreIpAddresses(string &s) {
    trackBack(s, 3, 0);
    return res;
}

#endif //PROGRAMSTUDY_LEETCODE_93_RESTORE_IP_ADDRESSES_HPP
