//
// Created by xuche on 2020/6/6.
//

#ifndef PROGRAMSTUDY_LEETCODE_DATA_HPP
#define PROGRAMSTUDY_LEETCODE_DATA_HPP

#include "vector"

using namespace std;

class data {
private:
    vector<int> nums;
public:
    vector<int>& getNums();
    void exch(int i, int j);
};


#endif //PROGRAMSTUDY_LEETCODE_DATA_HPP
