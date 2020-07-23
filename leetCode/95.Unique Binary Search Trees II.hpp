//
// Created by xuche on 2020/7/23.
//

#ifndef PROGRAMSTUDY_LEETCODE_95_UNIQUE_BINARY_SEARCH_TREES_II_HPP
#define PROGRAMSTUDY_LEETCODE_95_UNIQUE_BINARY_SEARCH_TREES_II_HPP

#include "vector"
#include "../SourceCode/structs.hpp"

using namespace std;

vector<TreeNode*> treeGenerator(int begin, int end){
    if(begin > end) return {nullptr};
    vector<TreeNode*> allTrees;
    for(int i = begin; i <= end; ++i){
        vector<TreeNode*> leftTrees = treeGenerator(begin, i-1), rightTrees = treeGenerator(i+1, end);
        for(auto & rightNode : rightTrees){
            for(auto & leftNode : leftTrees){
                TreeNode *now = new TreeNode(i);
                now->right = rightNode;
                now->left = leftNode;
                allTrees.push_back(now);
            }
        }
    }
    return allTrees;
}

vector<TreeNode*> generateTrees(int n) {
    if(n == 0) return {};
    return treeGenerator(1, n);
}

#endif //PROGRAMSTUDY_LEETCODE_95_UNIQUE_BINARY_SEARCH_TREES_II_HPP
