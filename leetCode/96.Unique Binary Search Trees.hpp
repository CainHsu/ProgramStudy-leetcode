//
// Created by xuche on 2020/7/23.
//

#ifndef PROGRAMSTUDY_LEETCODE_96_UNIQUE_BINARY_SEARCH_TREES_HPP
#define PROGRAMSTUDY_LEETCODE_96_UNIQUE_BINARY_SEARCH_TREES_HPP

#include "vector"

using namespace std;

int numTrees(int n) {
    if(n == 1) return 1;
    vector<int> G(n+1, 0);
    G[0] = 1;
    G[1] = 1;
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            G[i] += (G[j-1] * G[i-j]);
        }
    }
    return G[n];
}

#endif //PROGRAMSTUDY_LEETCODE_96_UNIQUE_BINARY_SEARCH_TREES_HPP
