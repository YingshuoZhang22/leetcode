/* 116. Populating Next Right Pointers in Each Node
完全二叉树
You are given a perfect binary tree where all leaves 
are on the same level, and every parent has two children. 

Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
// bfs
    Node* connect(Node* root) {
        if (!root)  return nullptr;
        Node* source = root;
        while (root->left) {
            for (auto p = root; p != nullptr; p = p->next) {    // 一层一层搞
                p->left->next = p->right;
                if (p->next)    p->right->next = p->next->left;
            }
            root = root->left;
        }
        return source;
    }
};


/* 117 不完全二叉树

*/