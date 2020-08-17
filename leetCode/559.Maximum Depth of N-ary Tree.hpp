//
// Created by xuche on 2020/8/17.
//

#ifndef PROGRAMSTUDY_LEETCODE_559_MAXIMUM_DEPTH_OF_N_ARY_TREE_HPP
#define PROGRAMSTUDY_LEETCODE_559_MAXIMUM_DEPTH_OF_N_ARY_TREE_HPP

#include "../SourceCode/DataStructure/n-ary-tree.hpp"
#include "algorithm"

int maxDepth(Node* root) {
    if(!root) return 0;
    int res = 0;
    for(const auto &i : root->children){
        res = max(res, maxDepth(i));
    }
    return res + 1;
}

#endif //PROGRAMSTUDY_LEETCODE_559_MAXIMUM_DEPTH_OF_N_ARY_TREE_HPP
