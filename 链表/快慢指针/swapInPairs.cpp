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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {  //dummy->1->2->3->4；每次在待交换的两个节点的前一个节点开始操作
            ListNode *p = cur->next->next->next;
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            cur->next->next = tmp;
            tmp->next = p;
            cur = tmp;
        }
        return dummy->next;
    }
};