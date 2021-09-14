#include <bits/stdc++.h>
using namespace std;

/* 19
Given the head of a linked list, remove the nth node from the
end of the list and return its head.
*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //if (!head->next)    return nullptr;
        ListNode *fst = head, *slow = head;
        while (n--) 
            fst = fst -> next;
        
        if (!fst)   return head->next;  // 因为下面有fst->next；就要考虑边界处理
        while(fst->next) {
            fst = fst->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
