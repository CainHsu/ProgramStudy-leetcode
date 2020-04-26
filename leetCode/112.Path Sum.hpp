//
// Created by xuche on 2020/4/27.
//

#ifndef PROGRAMSTUDY_LEETCODE_112_PATH_SUM_HPP
#define PROGRAMSTUDY_LEETCODE_112_PATH_SUM_HPP

#include "101.Symmetric Tree.hpp"

bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    sum -= root->val;
    if(!root->left && !root->right) return (sum == 0);
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

#endif //PROGRAMSTUDY_LEETCODE_112_PATH_SUM_HPP
