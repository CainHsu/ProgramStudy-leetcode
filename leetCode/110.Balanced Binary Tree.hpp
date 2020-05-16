//
// Created by xuche on 2020/5/17.
//

#ifndef PROGRAMSTUDY_LEETCODE_110_BALANCED_BINARY_TREE_HPP
#define PROGRAMSTUDY_LEETCODE_110_BALANCED_BINARY_TREE_HPP

#include "../SourceCode/structs.hpp"
#include "cmath"
#include "algorithm"

template<class T>
T max(T a, T b){
    return a>b?a:b;
}

int TreeNodeHeight(TreeNode* root){
    if(root == nullptr) return -1;
    return 1+max(TreeNodeHeight(root->right), TreeNodeHeight(root->left));
}

bool isBalanced(TreeNode* root) {
    if(!root) return true;
    return isBalanced(root->right) && isBalanced(root->left)
           && abs(TreeNodeHeight(root->left) - TreeNodeHeight(root->right)) <= 1;
}

#endif //PROGRAMSTUDY_LEETCODE_110_BALANCED_BINARY_TREE_HPP
