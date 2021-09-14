/* 147. Insertion Sort List
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
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
    ListNode* insertionSortList(ListNode* head) {
        auto dummy = new ListNode(-1);
        for (auto p = head; p;) {
            auto cur = dummy, next = p->next;
            // 找第一个cur满足 cur <= p < cur->next (第一个cur是最小的dummy node)
            // 找第一个 > p 的位置
            while (cur->next && cur->next->val <= p->val) 
                cur = cur->next;
            p->next = cur->next;
            cur->next = p;

            p = next;   // 继续排序p的下一个
        }
        return dummy->next;
    }
};