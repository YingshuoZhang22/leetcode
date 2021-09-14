/* 23
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
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
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;   // 用小顶堆
        for (auto l : lists)    if(l)   pq.push(l);
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (!pq.empty()) {
            auto a = pq.top();
            pq.pop();
            cur->next = a;
            a = a->next;
            if (a)  pq.push(a);
            cur = cur->next;
        }
        return dummy->next;
    }
};
