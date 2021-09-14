/* 141. Linked List Cycle
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
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
    // 四步走
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* mid = FindMiddleNode(head);   // 找到中间节点
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = ReverseList(l2);   // 反转后半段的链表节点
        mergeList(l1, l2);      // 合并两端长度相差不超过1的链表
    }

    // 快慢指针找到中间节点
    ListNode* FindMiddleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 反转链表
    ListNode* ReverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre; // 反转
            pre = cur;       // 向后移动
            cur = next;
        }
        return pre;
    }

    // 合并链表
    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* temp1;
        ListNode* temp2;
        while (l1 != nullptr && l2 != nullptr) {
            temp1 = l1->next;
            temp2 = l2->next;
            
            l1->next = l2;
            l1 = temp1;

            l2->next = l1;
            l2 = temp2;
        }
    }
};