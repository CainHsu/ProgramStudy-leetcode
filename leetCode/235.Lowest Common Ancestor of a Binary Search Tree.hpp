//
// Created by xuche on 2020/4/30.
//

#ifndef PROGRAMSTUDY_LEETCODE_235_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_HPP
#define PROGRAMSTUDY_LEETCODE_235_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_HPP

#include "../SourceCode/structs.hpp"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int parentVal = root->val;
    int pVal = p->val;
    int qVal = q->val;
    TreeNode* ans;
    if(pVal > parentVal && qVal > parentVal)
        ans = lowestCommonAncestor(root->right, p, q);
    else if(pVal < parentVal && qVal < parentVal)
        ans = lowestCommonAncestor(root->left, p, q);
    else
        return root;
    return ans;
}


#endif //PROGRAMSTUDY_LEETCODE_235_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_HPP
