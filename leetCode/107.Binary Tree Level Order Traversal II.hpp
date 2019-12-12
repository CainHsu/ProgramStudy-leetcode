//
// Created by xuche on 2019/12/12.
//

#ifndef PROGRAMSTUDY_LEETCODE_107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_HPP
#define PROGRAMSTUDY_LEETCODE_107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_HPP

#include "vector"
#include "iostream"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

vector<vector<int>> ans;
void goDeeper(TreeNode* root, int depth){
    if(ans.size() <= depth) ans.emplace_back();
    ans[depth].emplace_back(root->val);
    if(root->left) goDeeper(root->left, depth+1);
    if(root->right) goDeeper(root->right, depth+1);
}
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(!root) return ans;
    goDeeper(root, 0);
    reverse(ans.begin(), ans.end());
    return ans;
}

#endif //PROGRAMSTUDY_LEETCODE_107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_HPP
