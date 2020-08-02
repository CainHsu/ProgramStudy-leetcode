//
// Created by xuche on 2020/8/2.
//

#ifndef PROGRAMSTUDY_LEETCODE_160_INTERSECTION_OF_TWO_LINKED_LISTS_HPP
#define PROGRAMSTUDY_LEETCODE_160_INTERSECTION_OF_TWO_LINKED_LISTS_HPP

#include "../SourceCode/DataStructure/ListNode.hpp"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *fast, *slow;
    fast = headA, slow = headB;
    while(fast != slow){
        slow = slow == NULL ? headA : slow->next;
        fast = fast == NULL ? headB : fast->next;
    }
    return fast;
}

#endif //PROGRAMSTUDY_LEETCODE_160_INTERSECTION_OF_TWO_LINKED_LISTS_HPP
