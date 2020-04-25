//
// Created by xuche on 2020/2/25.
//

#ifndef PROGRAMSTUDY_LEETCODE_147_INSERTION_SORT_LIST_HPP
#define PROGRAMSTUDY_LEETCODE_147_INSERTION_SORT_LIST_HPP

#include "iostream"
#include "stack"

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* insertionSortList(ListNode* head) {
    if(!head||!head->next) return head;
    ListNode* pre = new ListNode(-1);
    pre->next = head;
    ListNode* tail = head;
    ListNode* node = tail->next;
    while(node){
        if(tail->val > node->val){
            ListNode* cur = pre;
            while(cur->next && node->val > cur->next->val){
                cur = cur->next;
            } // 使找到此时的node放到cur->next处
            tail->next = node->next;
            node->next = tail;

        }
        else{
            tail = tail->next;
            node = tail->next;
        }

    }
}

#endif //PROGRAMSTUDY_LEETCODE_147_INSERTION_SORT_LIST_HPP
