//
// Created by xuche on 2020/8/2.
//

#ifndef PROGRAMSTUDY_LEETCODE_1290_CONVERT_BINARY_NUMBER_IN_A_LINKED_LIST_TO_INTEGER_HPP
#define PROGRAMSTUDY_LEETCODE_1290_CONVERT_BINARY_NUMBER_IN_A_LINKED_LIST_TO_INTEGER_HPP

#include "../SourceCode/DataStructure/ListNode.hpp"

int getDecimalValue(ListNode* head) {
    if(!head) return 0;
    ListNode *p;
    p = head;

    int ans = 0;
    while(p){
        ans += p->val;
        p = p->next;
        if(p)
            ans *= 2;
    }
    return ans;
}

#endif //PROGRAMSTUDY_LEETCODE_1290_CONVERT_BINARY_NUMBER_IN_A_LINKED_LIST_TO_INTEGER_HPP
