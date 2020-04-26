//
// Created by xuche on 2020/4/27.
//

#ifndef PROGRAMSTUDY_LEETCODE_404_SUM_OF_LEFT_LEAVES_HPP
#define PROGRAMSTUDY_LEETCODE_404_SUM_OF_LEFT_LEAVES_HPP

#include "../SourceCode/structs.hpp"

int ans = 0;
void goDeeper(TreeNode* root){
    if(!root) return;
    goDeeper(root->left);
    goDeeper(root->right);
    if(root->left){
        if(!root->left->left && !root->left->right){
            ans += root->left->val;
        }
    }
}
int sumOfLeftLeaves(TreeNode* root) {
    goDeeper(root);
    return ans;
}

#endif //PROGRAMSTUDY_LEETCODE_404_SUM_OF_LEFT_LEAVES_HPP
