//
// Created by xuche on 2020/6/11.
//

#ifndef PROGRAMSTUDY_LEETCODE_QUICKSORT_HPP
#define PROGRAMSTUDY_LEETCODE_QUICKSORT_HPP

#include "../data.hpp"

class quickSort {
private:
    unique_ptr<class data> NUM;
public:
    quickSort() : NUM(new class data(100)){};

    int partition(int lo, int hi);
    void sort(int lo, int hi);
    void sort();

    void sort3(int lo, int hi);
};


#endif //PROGRAMSTUDY_LEETCODE_QUICKSORT_HPP
