//
// Created by xuche on 2019/12/29.
//

#ifndef PROGRAMSTUDY_LEETCODE_144_BINARY_TREE_PREORDER_TRAVERSAL_HPP
#define PROGRAMSTUDY_LEETCODE_144_BINARY_TREE_PREORDER_TRAVERSAL_HPP

#include "vector"
#include "stack"
#include "../SourceCode/structs.hpp"


using std::vector;
using std::stack;

static vector<int> pTAns;
void toGoDeeper(TreeNode* root){
    pTAns.emplace_back(root->val);
    if(root->left) toGoDeeper(root->left);
    if(root->right) toGoDeeper(root->right);
}
vector<int> preorderTraversalRecur(TreeNode* root) {
    if(!root) return pTAns;
    toGoDeeper(root);
    return pTAns;
}

vector<int> preorderTraversalIter(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        TreeNode* p = nodes.top();
        if(p->right){
            nodes.pop();
            nodes.push(p->right);
        }
        else nodes.pop();
        ans.emplace_back(p->val);
        if(p->left) nodes.push(p->left);
    }
    return ans;
}

#endif //PROGRAMSTUDY_LEETCODE_144_BINARY_TREE_PREORDER_TRAVERSAL_HPP
