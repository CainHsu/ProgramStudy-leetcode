//
// Created by xuche on 2019/12/16.
//

#ifndef PROGRAMSTUDY_LEETCODE_101_SYMMETRIC_TREE_HPP
#define PROGRAMSTUDY_LEETCODE_101_SYMMETRIC_TREE_HPP

#include "iostream"

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归法
bool ifSym(TreeNode* r1, TreeNode* r2){
    if(!r1 && !r2) return true;
    if(!r1 || !r2) return false;
    return (r1->val == r2->val) && ifSym(r1->left, r2->right) && ifSym(r1->right, r2->left);
}
bool isSymmetric(TreeNode* root) {
    return ifSym(root, root);
}

#endif //PROGRAMSTUDY_LEETCODE_101_SYMMETRIC_TREE_HPP
