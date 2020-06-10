//
// Created by xuche on 2020/6/7.
//

#ifndef PROGRAMSTUDY_LEETCODE_MERGESORT_HPP
#define PROGRAMSTUDY_LEETCODE_MERGESORT_HPP

#include "../data.hpp"
#include "vector"

using namespace std;

class mergeSort {
private:
    class data NUM;
public:

    // 将lo~mid，mid~hi这两个排列好的子数组合并为一个大的有序数组
    void merge(int lo, int mid, int hi);

    void sort(int lo, int hi);

    void sort();
};


#endif //PROGRAMSTUDY_LEETCODE_MERGESORT_HPP
