/* 129. Sum Root to Leaf Numbers
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:

Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
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
// 树的dfs
    int a;
    
    void dfs(TreeNode* root, int val) {
        if (!root)  return;
        else if (!root->left && !root->right)    a += (val * 10 + root->val);
        else if (!root->left)    dfs(root->right, val * 10 + root->val);
        else if (!root->right)    dfs(root->left, val * 10 + root->val);
        else dfs(root->left, val * 10 + root->val), dfs(root->right, val * 10 + root->val);
    }
    
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return a;
    }
};