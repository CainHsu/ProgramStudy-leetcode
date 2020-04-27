//
// Created by xuche on 2020/4/28.
//

#ifndef PROGRAMSTUDY_LEETCODE_226_INVERT_BINARY_TREE_HPP
#define PROGRAMSTUDY_LEETCODE_226_INVERT_BINARY_TREE_HPP

#include "../SourceCode/structs.hpp"
#include "queue"

using namespace std;

TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int depth = q.size();
        for(int i = 0; i < depth; ++i){
            TreeNode* p = q.front();
            q.pop();
            TreeNode* temp = p->left;
            p->left = p->right;
            p->right = temp;
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
    }
    return root;
}

#endif //PROGRAMSTUDY_LEETCODE_226_INVERT_BINARY_TREE_HPP
