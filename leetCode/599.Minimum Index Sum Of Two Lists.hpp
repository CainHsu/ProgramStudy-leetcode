//
// Created by CainHsu on 2019/10/20.
//

#ifndef TEST_599_MINIMUM_INDEX_SUM_OF_TWO_LISTS_HPP
#define TEST_599_MINIMUM_INDEX_SUM_OF_TWO_LISTS_HPP

#include "string"
#include "unordered_map"
#include "vector"

std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::unordered_map<std::string, int> temp;
    std::vector<std::string> tempVec, res;
    int pre = list1.size() + list2.size();

    // 生成名称和Index和的map
    for(int i = 0; i < list1.size(); ++i){
        for(int j = 0; j < list2.size(); ++j){
            if(list1[i] == list2[j]){
                temp[list1[i]] = i + j;
                tempVec.push_back(list1[i]);
            }
        }
    }


    for(int i = 0; i < tempVec.size(); ++i){
        if(temp[tempVec[i]] <= pre){
            pre = temp[tempVec[i]];
        }
    }

    for(int i = 0; i < tempVec.size(); ++i){
        if(temp[tempVec[i]] == pre){
            res.push_back(tempVec[i]);
        }
    }

    return res;
}

#endif //TEST_599_MINIMUM_INDEX_SUM_OF_TWO_LISTS_HPP
