/* 160. Intersection of Two Linked Lists
Given the heads of two singly linked-lists headA and
 headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)   return NULL;
        ListNode *p1 = headA, *p2 = headB;
        // 我来到你的城市，走过你来时的路 
        while (p1 != p2) {
            if (!p1)    {
                p1 = headB, p2 = p2->next;
            } else if (!p2) {
                p2 = headA, p1 = p1->next;
            } else {
                p1 = p1->next, p2 = p2->next;
            }
        }
        return p1;
    }
};