//
// Created by xuche on 2020/9/1.
//

#ifndef PROGRAMSTUDY_LEETCODE_338_COUNTING_BITS_HPP
#define PROGRAMSTUDY_LEETCODE_338_COUNTING_BITS_HPP

#include "vector"

using namespace std;

vector<int> countBits(int num) {
    vector<int> res(num + 1, 1);
    res[0] = 0;
    for(int i = 2; i <= num; ++i){
        int temp = log(i)/log(2);
        res[i] = res[i - pow(2, temp)] + 1;
    }
    return res;
}

#endif //PROGRAMSTUDY_LEETCODE_338_COUNTING_BITS_HPP
