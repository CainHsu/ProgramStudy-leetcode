//
// Created by CainHsu on 2019/10/17.
//

#ifndef TEST_2_HPP
#define TEST_2_HPP

#include "iostream"

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// using ListNode
// in case of overflow
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    bool carry = false;
    ListNode* head = new ListNode(0), *p1, *p2, *p;
    p1 = l1;
    p2 = l2;

    // special cases
    if(!p1 && !p2)
        return NULL;
    if(p1 && !p2)
        return p1;
    if(!p1 && p2)
        return p2;

    int sum = 0;
    p = head;
    while(p1 || p2){
        // new List must be initialized before assignment
        sum = 0;
        if(p1) sum += p1->val;
        if(p2) sum += p2->val;
        if(carry) ++sum;
        if(sum >= 10) carry = true;
        else carry = false;
        p->next = new ListNode(sum%10);
        p = p->next;
        p1 = p1->next;
        p2 = p2->next;
    }
    if(carry){
        ListNode *temp = new ListNode(1);
        p->next = temp;
    }
    return head->next;
}

#endif //TEST_2_HPP
