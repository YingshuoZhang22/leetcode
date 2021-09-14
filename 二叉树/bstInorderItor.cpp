/* 173. Binary Search Tree Iterator
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
// 中序迭代遍历代码分拆
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        while (root) {  // 初始化迭代器，只会被执行一次
            stk.push(root);
            root = root->left;
        }
    }
    
    int next() {
        auto root = stk.top();  // 不仅要返回，还要让下一次即插即用
        stk.pop();
        int val = root->val;
        root= root->right;
        while (root) {
            stk.push(root);
            root = root->left;
        }
        return val;
    }
    
    bool hasNext() {
        return stk.size();
    }
};

