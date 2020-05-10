//
// Created by xuche on 2020/5/10.
//

#ifndef PROGRAMSTUDY_LEETCODE_108_CONVERT_SORTED_ARRAY_TO_BINARY_TREE_HPP
#define PROGRAMSTUDY_LEETCODE_108_CONVERT_SORTED_ARRAY_TO_BINARY_TREE_HPP

#include "../SourceCode/structs.hpp"
#include "vector"

using namespace std;

vector<int> vec;
TreeNode* maker(int a, int b){
    if(a > b) return NULL;
    int p = (a + b)/2;
    TreeNode* root = new TreeNode(vec[p]);
    root->left = maker(a, p-1);
    root->right = maker(p+1, b);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    vec = nums;
    TreeNode* root = maker(0, nums.size() - 1);
    return root;
}

#endif //PROGRAMSTUDY_LEETCODE_108_CONVERT_SORTED_ARRAY_TO_BINARY_TREE_HPP
