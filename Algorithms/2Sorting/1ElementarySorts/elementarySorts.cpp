//
// Created by xuche on 2020/6/6.
//

#include "elementarySorts.hpp"

void ElementarySorts::selectionSort() {
    for(int i = 0; i < NUM.getNums().size() - 1; ++i){
        int min = i;
        for(int j = i + 1; j < NUM.getNums().size(); ++j){
            if (NUM.getNums()[min] > NUM.getNums()[j])
                min = j;
        }
        NUM.exch(i, min);
    }
}

void ElementarySorts::insertionSort() {
    for(int i = 1; i < NUM.getNums().size() - 1; ++i){
        int insert = NUM.getNums()[1];
        for(int j = i; j > 0 && NUM.getNums()[j] < NUM.getNums()[j+1]; ++j){
            NUM.exch(j, j+1);
        }
    }
}

void ElementarySorts::shellSort() {
    int N = NUM.getNums().size();
    int h = 1;
    while(h < N/3) h = 3*h + 1;
    while(h>=1){

    }
}



