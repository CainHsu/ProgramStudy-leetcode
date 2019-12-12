//
// Created by xuche on 2019/12/12.
//

#ifndef PROGRAMSTUDY_LEETCODE_111_MINIMUM_DEPTH_OF_BINARY_TREE_HPP
#define PROGRAMSTUDY_LEETCODE_111_MINIMUM_DEPTH_OF_BINARY_TREE_HPP

#include "iostream"
#include "queue"


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) {
    if(!root)
        return 0;
    int depth = 1;
    std::queue<TreeNode*> Q;
    Q.push(root);
    TreeNode* p = root;
    while(!Q.empty()){
        int size = Q.size();
        for(int i = 0; i < size; ++i){
            p = Q.front();
            Q.pop();
            if(!p->left && !p->right) return depth;
            if(p->left) Q.push(p->left);
            if(p->right) Q.push(p->right);
        }
        ++depth;
    }
    return depth;
}

#endif //PROGRAMSTUDY_LEETCODE_111_MINIMUM_DEPTH_OF_BINARY_TREE_HPP
