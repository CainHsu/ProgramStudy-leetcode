//
// Created by xuche on 2020/4/27.
//

#ifndef PROGRAMSTUDY_LEETCODE_872_LEAF_SIMILIAR_TREES_HPP
#define PROGRAMSTUDY_LEETCODE_872_LEAF_SIMILIAR_TREES_HPP

#include "../SourceCode/structs.hpp"
#include "vector"

using namespace std;

vector<int> v1;
void goDeeper(TreeNode* root){
    if(!root) return;
    if(root->left) goDeeper(root->left);
    if(root->right) goDeeper(root->right);
    if(!root->left && !root->right) v1.emplace_back(root->val);
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    goDeeper(root1);
    vector<int> v2(v1);
    v1.clear();
    goDeeper(root2);
    return v2 == v1;
}

#endif //PROGRAMSTUDY_LEETCODE_872_LEAF_SIMILIAR_TREES_HPP
