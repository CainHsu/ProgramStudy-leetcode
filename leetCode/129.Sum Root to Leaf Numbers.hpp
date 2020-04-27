//
// Created by xuche on 2020/4/27.
//

#ifndef PROGRAMSTUDY_LEETCODE_129_SUM_ROOT_TO_LEAF_NUMBERS_HPP
#define PROGRAMSTUDY_LEETCODE_129_SUM_ROOT_TO_LEAF_NUMBERS_HPP


#include "../SourceCode/structs.hpp"

int sum = 0;
void goDeeper(TreeNode* root, int ans){
    if(root) ans = ans * 10 + root->val;
    else return;
    if(!root->left && !root->right){
        sum += ans;
        return;
    }
    if(root->left) goDeeper(root->left, ans);
    if(root->right) goDeeper(root->right, ans);
}
int sumNumbers(TreeNode* root){
    //int ans = 0;
    goDeeper(root, 0);
    return sum;
}

#endif //PROGRAMSTUDY_LEETCODE_129_SUM_ROOT_TO_LEAF_NUMBERS_HPP
