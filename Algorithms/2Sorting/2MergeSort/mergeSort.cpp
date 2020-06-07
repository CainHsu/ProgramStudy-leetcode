//
// Created by xuche on 2020/6/7.
//

#include "mergeSort.hpp"


void mergeSort::merge(int lo, int mid, int hi) {
    int i = lo, j = mid + 1;
    vector<int> temp(NUM.getNums().begin() + lo, NUM.getNums().begin()+hi);
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
