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

void data::show() {
    if(sortedFlag == static_cast<char>(0))
        cout << "Original vector:" << endl;
    else
        cout << "Sorted vector:" << endl;
    for(int i = 0; i < nums.size(); ++i){
        if(i%10 == 0 && i != 0)
            cout << endl;
        cout << nums[i] << "    ";
    }
}

data::data(int N) {
    sortedFlag = static_cast<char>(0);
}

void data::generateRanVec(int N) {

}
