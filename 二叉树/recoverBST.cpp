/* 99
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /*
 这里我们有个规律发现这两个节点：
第一个节点，是第一个按照中序遍历时候前一个节点大于后一个节点，我们选取前一个节点，这里指节点 4；

第二个节点，是在第一个节点找到之后，后面出现前一个节点大于后一个节点，我们选择后一个节点，这里指节点 1；
https://leetcode-cn.com/problems/recover-binary-search-tree/solution/zhong-xu-bian-li-by-powcai/
 */
class Solution {
public:
    TreeNode *fir = nullptr;
    TreeNode *sec = nullptr;
    TreeNode *pre = nullptr;

    void dfs(TreeNode *root) {
        if (!root)  return;
        dfs(root->left);
        if (pre != nullptr) {
            if (fir == nullptr && pre->val >= root->val) fir = pre;
            if (fir != nullptr && pre->val >= root->val) sec = root;
        }
        pre = root;
        dfs(root->right);
    }

    void recoverTree(TreeNode *root) {
        dfs(root);
        swap(fir->val, sec->val);
    }
};

