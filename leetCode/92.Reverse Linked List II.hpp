//
// Created by xuche on 2020/8/2.
//

#ifndef PROGRAMSTUDY_LEETCODE_92_REVERSE_LINKED_LIST_II_HPP
#define PROGRAMSTUDY_LEETCODE_92_REVERSE_LINKED_LIST_II_HPP

#include "../SourceCode/DataStructure/ListNode.hpp"

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(!head || n == 1 || m == n) return head;
    int len = n - m;
    ListNode *p, *pre;
    p = head;
    if(m > 1){
        int start = m;
        pre = head;
        while(start > 1){
            pre = p;
            p = p->next;
            --start;
        }
    } else if(m == 1){
        p = p->next;
        pre = head;
        while (len>0){
            pre->next = p->next;
            p->next = head;
            head = p;
            p = pre->next;
            --len;
        }
        return head;
    }
    ListNode *ex;
    ex = p->next;
    while(len > 0){
        p->next = ex->next;
        ex->next = pre->next;
        pre->next = ex;
        ex = p->next;
        --len;
    }

    return head;
}

#endif //PROGRAMSTUDY_LEETCODE_92_REVERSE_LINKED_LIST_II_HPP
