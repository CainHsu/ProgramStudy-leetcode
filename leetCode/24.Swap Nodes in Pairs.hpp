//
// Created by xuche on 2020/8/2.
//

#ifndef PROGRAMSTUDY_LEETCODE_24_SWAP_NODES_IN_PAIRS_HPP
#define PROGRAMSTUDY_LEETCODE_24_SWAP_NODES_IN_PAIRS_HPP

#include "../SourceCode/DataStructure/ListNode.hpp"

ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *pre, *p1, *p2, *ans;
    p1 = head;
    p2 = head->next;
    p1->next = p2->next;
    p2->next = p1;
    ans = p2;
    pre = p1;
    p1 = p1->next;
    if(p1)
        p2 = p1->next;
    while(p1 && p2){
        p1->next = p2->next;
        p2->next = p1;
        pre->next = p2;
        pre = p1;
        p1 = p1->next;
        if(p1)
            p2 = p1->next;
    }
    return ans;
}

#endif //PROGRAMSTUDY_LEETCODE_24_SWAP_NODES_IN_PAIRS_HPP
