//
// Created by xuche on 2020/8/9.
//

#ifndef PROGRAMSTUDY_LEETCODE_1487_MAKING_FILE_NAMES_UNIQUE_HPP
#define PROGRAMSTUDY_LEETCODE_1487_MAKING_FILE_NAMES_UNIQUE_HPP

#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> fileVer;
    vector<string> ans;
    for(const auto &x : names){
        auto iter = fileVer.find(x);
        if(iter == fileVer.end()){
            ans.push_back(x);
            fileVer.insert(make_pair(x, 1));
        }else{
            int ver = iter->second;
            while (fileVer.find(x + "(" + to_string(ver) + ")") != fileVer.end()){
                ver++;
            }
            string name = x + "(" + to_string(ver) + ")";
            fileVer.insert(make_pair(name, 1));
            ++fileVer[x];
            ans.push_back(name);
        }
    }
    return ans;
}

#endif //PROGRAMSTUDY_LEETCODE_1487_MAKING_FILE_NAMES_UNIQUE_HPP
