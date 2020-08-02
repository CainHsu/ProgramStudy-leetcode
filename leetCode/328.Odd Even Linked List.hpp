//
// Created by xuche on 2020/8/2.
//

#ifndef PROGRAMSTUDY_LEETCODE_328_ODD_EVEN_LINKED_LIST_HPP
#define PROGRAMSTUDY_LEETCODE_328_ODD_EVEN_LINKED_LIST_HPP


#include "../SourceCode/DataStructure/ListNode.hpp"

ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *p1, *p2, *p, *per;
    p1 = head, p2 = head->next;
    if(p2->next){
        p = p2->next;
        if(p->next) // len = 4
            per = p->next;
        else{
            // len = 3
            p1->next = p;
            p->next = p2;
            p2->next = NULL;
            return head;
        }
    }
    else // len = 2
        return head;
    while(per){
        ListNode *temp = p1->next;
        p1->next = p;
        p2->next = per;
        p->next = temp;
        if(per->next){
            per = per->next;
            if(per->next){
                // tail = 2
                p = per;
                per = per->next;
                p1 = p1->next;
                p2 = p2->next;
            }
            else{
                // tail = 1
                p2->next->next = NULL;
                ListNode *temp = p->next;
                p->next = per;
                per->next = temp;
                return head;
            }
        }
        else{
            // tail = 0
            break;
        }
    }
    return head;
}

#endif //PROGRAMSTUDY_LEETCODE_328_ODD_EVEN_LINKED_LIST_HPP
