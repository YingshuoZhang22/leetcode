/* 138. Copy List with Random Pointer
ALL DEEP COPY
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)  return NULL;
        Node* p = head;
        while (p) { // 复制
            Node *neww = new Node(p->val);
            Node *tmp = p->next;
            neww->next = tmp, p->next = neww, p = tmp;
        }

        Node *odd = head;   //设置新指针
        while (odd) {
            if (odd->random)    odd->next->random = odd->random->next;  // 典
            else odd->next->random = NULL;
            odd = odd->next->next;
        }

        Node *dummy = new Node(-1);
        Node *cur = dummy, *copy = head;
        while(copy) {   // 提取并把原链表复原
            cur = cur->next = copy->next;
            copy = copy->next = copy->next->next;
        }

        return dummy->next;
    }
};