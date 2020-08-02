//
// Created by xuche on 2020/8/2.
//

#ifndef PROGRAMSTUDY_LEETCODE_876_MIDDLE_OF_THE_LINKED_LIST_HPP
#define PROGRAMSTUDY_LEETCODE_876_MIDDLE_OF_THE_LINKED_LIST_HPP

#include "../SourceCode/DataStructure/ListNode.hpp"

ListNode* middleNode(ListNode* head) {
    if(!head) return nullptr;
    ListNode *p1, *p2;
    p1 = head, p2 = head->next;
    while(p2){
        p1 = p1->next;
        p2 = p2->next;
        if(p2)
            p2 = p2->next;
    }
    return p1;
}

#endif //PROGRAMSTUDY_LEETCODE_876_MIDDLE_OF_THE_LINKED_LIST_HPP
