//
// Created by xuche on 2019/12/28.
//

#ifndef PROGRAMSTUDY_LEETCODE_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_HPP
#define PROGRAMSTUDY_LEETCODE_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_HPP

#include "vector"
#include "queue"

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> ans;
    if(!root) return ans;
    std::queue<TreeNode*> Q;
    Q.push(root);
    int row = 0;
    while(!Q.empty()){
        std::vector<int> temp;
        int depth = Q.size();
        for(int i = 0; i < depth; ++i){
            TreeNode* p = Q.front();
            temp.emplace_back(p->val);
            Q.pop();
            if(p->left) Q.push(p->left);
            if(p->right) Q.push(p->right);
        }
        if(row & 1) reverse(temp.begin(), temp.end());
        ++row;
        ans.emplace_back(temp);
    }
    return ans;
}

#endif //PROGRAMSTUDY_LEETCODE_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_HPP
