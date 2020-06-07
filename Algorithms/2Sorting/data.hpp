//
// Created by xuche on 2020/6/6.
//

#ifndef PROGRAMSTUDY_LEETCODE_DATA_HPP
#define PROGRAMSTUDY_LEETCODE_DATA_HPP

#include "vector"
#include "iostream"

using namespace std;

class data {
private:
    vector<int> nums;
    char sortedFlag;
public:
    explicit data(int N);
    vector<int>& getNums();
    void generateRanVec(int N);
    void exch(int i, int j);
    void show();
};


#endif //PROGRAMSTUDY_LEETCODE_DATA_HPP
