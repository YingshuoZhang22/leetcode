/* 250. Count Univalue Subtrees
Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.
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
    bool allsame(TreeNode *root) {
        if (!root || (!root->left && !root->right))    return true;
        if (!root->right)   return allsame(root->left) && (root->val == root->left->val);
        if (!root->left)   return allsame(root->right) && root->val == root->right->val;
        return allsame(root->right) && allsame(root->left) && root->val == root->left->val && root->val == root->right->val;
    }

    int countUnivalSubtrees(TreeNode* root) {
        if (!root)  return 0;
        if (!root->left && !root->right)    return 1;
        if (!root->right && root->left) {
            int res = countUnivalSubtrees(root->left);
            return allsame(root) ? res + 1 : res;
        } else if (!root->left && root->right) {
            int res = countUnivalSubtrees(root->right);
            return allsame(root) ? res + 1 : res;
        } else {
            int res = countUnivalSubtrees(root->left) + countUnivalSubtrees(root->right);
            return allsame(root) ? res + 1 : res;
        }
    }
};
