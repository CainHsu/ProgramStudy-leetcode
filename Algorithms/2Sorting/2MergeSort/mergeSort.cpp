//
// Created by xuche on 2020/6/7.
//

#include "mergeSort.hpp"


void mergeSort::merge(int lo, int mid, int hi) {
    int i = lo - lo, j = mid + 1 - lo;
    vector<int> temp(NUM.getNums().begin() + lo, NUM.getNums().begin() + hi);
    for(int k = lo; k < hi; ++k){
        if(i > mid)
            NUM.getNums()[k] = temp[j++];
        else if(j > hi)
            NUM.getNums()[k] = temp[i++];
        else if(NUM.getNums()[i] < NUM.getNums()[j])
            NUM.getNums()[k] = temp[i++];
        else
            NUM.getNums()[k] = temp[j++];
    }
}

void mergeSort::sort(int lo, int hi) {
    if(hi <= lo) return;
    int mid = lo + (hi - lo)/2;
    this->sort(lo, mid);
    this->sort(mid, hi);
    this->merge(lo, mid, hi);
}

void mergeSort::sort() {
    this->sort(0, NUM.getNums().size());
}
