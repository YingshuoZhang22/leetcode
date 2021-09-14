/* 114. Flatten Binary Tree to Linked List
 Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child 
pointer points to the next node in the list and the left child pointer is always null.

The "linked list" should be in the same order as a pre-order traversal of the binary tree.
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

class Solution {
public:
    void flatten(TreeNode* root) {
// 迭代先序遍历
// 我们先定义右链：指一棵子树最右侧的路径。
// 我们从根节点开始迭代，每次将当前节点的左子树的右链，插入当前节点的右链，如下所示：
        while (root) {
            auto p = root->left;
            if (p) {
                while (p->right) p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = NULL;  // 每次解决一个root
            }
            root = root->right;
        }
    }
};