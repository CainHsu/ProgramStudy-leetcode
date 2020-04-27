//
// Created by xuche on 2020/4/27.
//

#ifndef PROGRAMSTUDY_LEETCODE_513_FIND_BOTTOM_LEFT_TREE_VALUE_HPP
#define PROGRAMSTUDY_LEETCODE_513_FIND_BOTTOM_LEFT_TREE_VALUE_HPP


#include "../SourceCode/structs.hpp"
#include "queue"

using namespace std;

int findBottomLeftValue(TreeNode* root) {
    if(!root) return 0;
    queue<TreeNode*> q;
    vector<vector<int>> datas;
    q.push(root);
    while(!q.empty()){
        int depth = q.size();
        vector<int> row;
        for(int i = 0; i < depth; ++i){
            TreeNode* p = q.front();
            q.pop();
            row.emplace_back(p->val);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        datas.emplace_back(row);
    }
    return datas.back().front();
}



#endif //PROGRAMSTUDY_LEETCODE_513_FIND_BOTTOM_LEFT_TREE_VALUE_HPP
