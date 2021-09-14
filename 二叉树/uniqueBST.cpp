/* 95
Given an integer n, return all the structurally unique BST's 
(binary search trees), which has exactly n nodes of unique values
from 1 to n. Return the answer in any order.
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
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return {};
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int l, int r) {
        if (l > r) return {NULL};
        vector<TreeNode*> res;
        for (int i = l; i <= r; i ++ ) {    // i是root的val，因为BST的性质。左子树是l~i-1, 右子树是i+1 ~ r
            vector<TreeNode*> left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (TreeNode* l: left)
                for (TreeNode* r: right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l, root->right = r;
                    res.push_back(root);
                }
        }

        return res;
    }
};
