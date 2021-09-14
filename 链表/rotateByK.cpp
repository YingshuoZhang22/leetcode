/* 61
Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
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
    ListNode* rotateRight(ListNode* head, int _k) {
        if (!head) return nullptr;
        int len = 1;
        ListNode *p = head, *q = head;
        while(p->next) {    // 需要让p指向链表的最后一个节点
            p = p->next;
            len++;
        }

        int kk = _k % len;
        if (kk == 0) return head;
        int k = len - kk;

        ListNode *cur = head;
        for (int i = 1; i < k; i++) {
            cur = cur->next;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = cur->next;
        cur->next = nullptr;    // 为什么不写这步就会一直报错呢，因为判题程序在遍历我的链表，本来到这一步（尾节点）就该停止了，但他还在试图往后遍历
        p->next = head;
        return dummy->next;
    }
};