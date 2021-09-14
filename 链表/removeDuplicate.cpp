/* 82
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.
（如果重复了就全删掉）

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while (p->next) {
            auto q = p->next->next;
            while (q && q->val == p->next->val) q = q->next;
            if (p->next->next == q) p = p->next;    //一个都没删
            else p->next = q;   // 删过
        }
        return dummy->next;
    }
};


/* 83
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
重复的只保留一个

Input: head = [1,1,2]
Output: [1,2]
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)   return head;
        ListNode *cur = head, *p = head->next;
        while (p) {
            if (p->val == cur->val)
                p = p->next;
            else 
                cur = cur->next = p, p = p->next;
        }
        cur->next = nullptr;
        return head;
    }
};