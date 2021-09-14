/* 113. Path Sum II
 Given the root of a binary tree and an integer targetSum, 
 return all root-to-leaf paths where the sum of the node values
  in the path equals targetSum. Each path should be returned
   as a list of the node values, not node references.
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
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root) dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode* root, int sum) {
        if (!root)  return;
        path.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right) {
            if (!sum) ans.push_back(path);
        } 
        if (root->left) dfs(root->left, sum);
        if (root->right) dfs(root->right, sum);
        path.pop_back();
    }
};


/* 124. Binary Tree Maximum Path Sum 
A path in a binary tree is a sequence of nodes where each pair of 
adjacent nodes in the sequence has an edge connecting them. A node
 can only appear in the sequence at most once. Note that the path
  does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.
*/

class Solution {
public:
// 枚举树中路径的最高点（LCA）
    int res = -2e9;

    int maxPathSum(TreeNode* root) {
        if (!root)  return 0;
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if (!root)  return 0;
        int left_max = max(0, dfs(root->left)), right_max = max(0, dfs(root->right));   // 如果子树小于0就不走了
        res = max(res, root->val + left_max + right_max);
        return root->val + max(left_max, right_max);
    }
};