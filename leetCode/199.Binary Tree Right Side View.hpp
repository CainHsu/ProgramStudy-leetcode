//
// Created by xuche on 2019/12/28.
//

#ifndef PROGRAMSTUDY_LEETCODE_199_BINARY_TREE_RIGHT_SIDE_VIEW_HPP
#define PROGRAMSTUDY_LEETCODE_199_BINARY_TREE_RIGHT_SIDE_VIEW_HPP

#include "vector"
#include "queue"

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> res;
    if(!root)
        return res;
    std::queue<TreeNode*> Q;
    TreeNode* p;
    Q.push(root);

    while(!Q.empty()){
        std::vector<int> temp;
        int width = Q.size();
        for(int i = 0; i < width; i++){
            p = Q.front();
            temp.push_back(p->val);
            Q.pop();
            if(p->left)
                Q.push(p->left);
            if(p->right)
                Q.push(p->right);
        }
        res.push_back(temp.back());
    }
    return res;
}

#endif //PROGRAMSTUDY_LEETCODE_199_BINARY_TREE_RIGHT_SIDE_VIEW_HPP
