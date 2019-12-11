//
// Created by xuche on 2019/12/11.
//

#ifndef PROGRAMSTUDY_LEETCODE_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_HPP
#define PROGRAMSTUDY_LEETCODE_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_HPP

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<TreeNode*> Q;
    Q.push(root);
    TreeNode* p;
    while(!Q.empty()){
        int width = Q.size();
        vector<int> temp;
        for(int i = 0; i < width; ++i){
            p = Q.front();
            Q.pop();
            temp.push_back(p->val);
            if(p->left) Q.push(p->left);
            if(p->right) Q.push(p->right);
        }
        ans.push_back(temp);
    }
    return ans;
}


vector<vector<int>> res;
void goDeeper(TreeNode* root, int depth){
    if(root){
        if(res.size() <= depth) res.emplace_back();
        res[depth].emplace_back(root->val);
    }
    else return;
    if(root->left) goDeeper(root->left, depth+1);
    if(root->right) goDeeper(root->right, depth+1);
}
vector<vector<int>> levelOrderRecur(TreeNode* root){
    goDeeper(root, 0);
    return res;
}


#endif //PROGRAMSTUDY_LEETCODE_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_HPP
