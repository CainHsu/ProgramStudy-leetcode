//
// Created by xuche on 2020/8/9.
//

#ifndef PROGRAMSTUDY_LEETCODE_468_VALIDATE_IP_ADDRESS_HPP
#define PROGRAMSTUDY_LEETCODE_468_VALIDATE_IP_ADDRESS_HPP

#include "string"

using namespace std;

bool isIPV4(const string &s){
    if(s[0] == '.') return false;
    int l = 0, r = 0;
    int labelCnt = 0, numCnt = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '.'){
            if(i+1 < s.size() && s[i+1] == '.') return false;
            ++labelCnt;
            if(labelCnt > 3 || i == s.size()-1) return false;
            r = i;
            int temp = stoi(s.substr(l, r));
            int numLen = 0;
            if(numCnt > 1 && temp == 0) return false;
            if(temp > 255 || temp < 0){
                return false;
            }
            l = i + 1;
            int tempNum = temp;
            while(temp > 0){
                temp /= 10;
                numLen++;
            }
            if(numLen != numCnt && tempNum != 0) return false;
            numCnt = 0;
        }else{
            ++numCnt;
            if(numCnt > 3) return false;
            if(s[i] > '9' || s[i] < '0') return false;
        }
    }
    int temp = stoi(s.substr(l, s.size()));
    if(s.size() - l != 1 && temp == 0) return false;
    if(temp > 255 || temp < 0){
        return false;
    }
    int tempNum = temp, numLen = 0;
    while(temp > 0){
        temp /= 10;
        numLen++;
    }
    if(numLen != numCnt && tempNum != 0) return false;
    if(labelCnt != 3) return false;
    return true;
}
bool isIPV6(const string &s){
    int labelCnt = 0;
    int cnt = 0;
    int lastIndex = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == ':' ){
            ++labelCnt;
            if(labelCnt > 7 || i == s.size()-1) return false;
            if(cnt <= 0 || cnt > 4){
                return false;
            } else
                cnt = 0;
            lastIndex = i;
        }
        else{
            if(s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'F' || s[i] >= 'a' && s[i] <= 'f'){
                ++cnt;
            } else{
                return false;
            }
        }
    }
    cnt = 0;
    ++lastIndex;
    while(lastIndex < s.size()){
        if(s[lastIndex] >= '0' && s[lastIndex] <= '9' || s[lastIndex] >= 'A' || s[lastIndex] <= 'F'){
            ++cnt;
        } else{
            return false;
        }
        ++lastIndex;
    }
    if(cnt == 0 || cnt > 4 || labelCnt != 7)
        return false;
    return true;
}
string validIPAddress(string IP) {
    if(IP.find('.') != IP.npos){
        if(isIPV4(IP)){
            return "IPv4";
        }
    }
    else if(IP.find(":") != IP.npos){
        if(isIPV6(IP)){
            return "IPv6";
        }
    }
    return "Neither";
}

#endif //PROGRAMSTUDY_LEETCODE_468_VALIDATE_IP_ADDRESS_HPP
