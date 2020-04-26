//
// Created by xuche on 2020/4/27.
//

#ifndef PROGRAMSTUDY_LEETCODE_STRUCTS_HPP
#define PROGRAMSTUDY_LEETCODE_STRUCTS_HPP

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //PROGRAMSTUDY_LEETCODE_STRUCTS_HPP
