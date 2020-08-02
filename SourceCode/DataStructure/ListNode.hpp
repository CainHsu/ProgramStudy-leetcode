//
// Created by 徐琛 on 2019/10/11.
//

#ifndef TEST_LISTNODE_HPP
#define TEST_LISTNODE_HPP


#include "iostream"
#include "stack"
#include "math.h"


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void showList(ListNode *head){
    std::cout << std::endl;
    ListNode* p;
    p = head;
    std::cout << p->val;
    p = p->next;
    while(p){
        std::cout << " --> ";
        std::cout << p->val;
        p = p->next;
    }
}

ListNode *detectCycle(ListNode *head) {
    if(!head)
        return NULL;
    if(!head->next)
        return NULL;
    ListNode *slow;
    ListNode *fast;
    slow = head;
    fast = head->next;
    while(fast){
        if(fast <= slow) return fast;
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB)
        return NULL;
    if(!headA->next || !headB->next)
        return NULL;
    if(headA == headB)
        return headA;
    ListNode* p1, *p2;
    p1 = headA;
    p2 = headB;
    for(int i = 0; p1 != p2;){
        if(p1)
            int a = p1->val;
        if(p2)
            int b = p2->val;
        if(!p1){
            if(!i%2) p1 = headB;
            else p1 = headA;
            ++i;
        }
        if(!p2){
            if(!i%2) p2 = headA;
            else p2 = headB;
            ++i;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}


ListNode* removeElements(ListNode* head, int val) {
    if(!head) return NULL;
    if(!head->next){
        if(head->val == val) return NULL;
        if(head->val != val) return head;
    }
    ListNode *pre, *p;
    while(head->val == val){
        head = head->next;
        if(head == NULL) return NULL;
    }
    p = head->next;
    pre = head;
    while(p){
        if(p->val == val){
            pre->next = p->next;
            p = p->next;
        }
        else {
            p = p->next;
            pre = pre->next;
        }
    }

    return head;
}


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









#endif //TEST_LISTNODE_HPP
