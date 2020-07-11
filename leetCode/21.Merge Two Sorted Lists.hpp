//
// Created by xuche on 2020/7/12.
//

#ifndef PROGRAMSTUDY_LEETCODE_21_MERGE_TWO_SORTED_LISTS_HPP
#define PROGRAMSTUDY_LEETCODE_21_MERGE_TWO_SORTED_LISTS_HPP

#include "../SourceCode/DataStructure/ListNode.hpp"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    if(!l1 && !l2)
        return l1;
    ListNode *res, *cur;
    if( l1->val > l2->val){
        res = l2;
        l2 = l2->next;
    }
    else {
        res = l1;
        l1 = l1->next;
    }
    cur = res;
    while(l1 && l2){
        if(l1->val > l2->val){
            cur->next = l2;
            l2 = l2->next;
        }
        else{
            cur->next = l1;
            l1 = l1->next;
        }
        cur = cur->next;
    }
    if(l1)
        cur->next = l1;
    if(l2)
        cur->next = l2;
    return res;
}

#endif //PROGRAMSTUDY_LEETCODE_21_MERGE_TWO_SORTED_LISTS_HPP
