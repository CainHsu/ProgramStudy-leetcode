//
// Created by xuche on 2020/6/11.
//

#include "quickSort.hpp"

int quickSort::partition(int lo, int hi) {
    int i = lo, j = hi, v = NUM->getNums().front();
    while(true){
        while(NUM->getNums()[++i] > v)
            if(i == hi) break;
        while (NUM->getNums()[--j] < v)
            if(j == lo) break;
        if(i >= j) break;
        NUM->exch(i, j);
    }
    NUM->exch(lo, j);
    return j;
}

void quickSort::sort() {
    sort(0, NUM->getNums().size()-1);
}

void quickSort::sort(int lo, int hi) {
    if(lo <= hi) return;
    int j = partition(lo, hi);
    sort(0, j-1);
    sort(j+1, hi);
}

void quickSort::sort3(int lo, int hi) {
    if(hi <= lo) return;
    int lt = lo, i = lo + 1, gt = hi;
    int v = NUM->getNums()[lo];
    while(i <= gt){
        int cmp = NUM->getNums()[i] - v;
        if(cmp > 0) NUM->exch(i, gt--);
        else if(cmp < 0) NUM->exch(lt++, i++);
        else i++;
    }
    sort3(lo, lt-1);
    sort3(gt+1, hi);
}
