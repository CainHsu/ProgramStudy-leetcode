//
// Created by xuche on 2020/7/11.
//

#ifndef PROGRAMSTUDY_LEETCODE_48_ROTATE_IMAGE_HPP
#define PROGRAMSTUDY_LEETCODE_48_ROTATE_IMAGE_HPP

#include "vector"

using namespace std;

void exch(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            exch(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n/2; ++j){
            exch(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}

#endif //PROGRAMSTUDY_LEETCODE_48_ROTATE_IMAGE_HPP
