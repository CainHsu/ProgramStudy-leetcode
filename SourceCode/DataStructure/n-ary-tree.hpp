//
// Created by xuche on 2020/8/17.
//

#ifndef PROGRAMSTUDY_LEETCODE_N_ARY_TREE_HPP
#define PROGRAMSTUDY_LEETCODE_N_ARY_TREE_HPP

#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

#endif //PROGRAMSTUDY_LEETCODE_N_ARY_TREE_HPP
