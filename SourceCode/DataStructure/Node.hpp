//
// Created by 徐琛 on 2019/10/18.
//

#ifndef TEST_NODE_HPP
#define TEST_NODE_HPP

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

#endif //TEST_NODE_HPP
