//
// Created by xuche on 2020/6/6.
//

#include "data.hpp"

vector<int> &data::getNums() {
    return nums;
}

void data::exch(int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
