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

/* 100
Given the roots of two binary trees p and q, write a 
function to check if they are the same or not.
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)   return true;
        if (!p && q)    return false;
        if (p && !q)    return false;
        if (p->val != q->val)   return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


/* 101
Given the root of a binary tree, check whether it 
is a mirror of itself (i.e., symmetric around its center).
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)  return true;
        return helper(root->left, root->right);
    }
    bool  helper(TreeNode *l, TreeNode *r) {
        if (!l && !r)    return true;
        if (!l || !r)    return false;
        if(l->val != r->val)    return false;
        return helper(l->right, r->left) && helper(l->left, r->right);
    }
};

/* 104
Given the root of a binary tree, return its maximum depth.
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};



/*  111. Minimum Depth of Binary Tree
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
// 如果根节点的左或右子树为空的话是构不成子树的。而最小深度是要求从根节点到子树的。当左或右子树为空时，不符合要求。
        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;        
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};



/* 
108. Convert Sorted Array to Binary Search Tree
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)   return nullptr;
        vector<int> v1,v2;
        int half = len / 2;
        for (int i = 0; i < half; i++) 
            v1.push_back(nums[i]);
        
        for (int i = half + 1; i < len; i++) 
            v2.push_back(nums[i]);
        
        TreeNode *root = new TreeNode(nums[half]);
        root->left = sortedArrayToBST(v1);
        root->right = sortedArrayToBST(v2);
        return root;
    }
};


/* 110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced:
a binary tree in which the left and right subtrees
 of every node differ in height by no more than 1.
*/

class Solution {
public:
    bool flag;
    bool isBalanced(TreeNode* root) {
        flag = true;
        maxDepth(root);
        return flag;
    }
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        int hl = maxDepth(root->left), hr = maxDepth(root->right);
        if (abs(hl - hr) > 1)   flag = false;
        return 1 + max(hl, hr);
    }
};

/*226. Invert Binary Tree
Given the root of a binary tree, invert the tree, and return its root.
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)  return root;
        swap(root->left, root->right);
        invertTree(root->left), invertTree(root->right);
        return root;
    }
};

/* 257. Binary Tree Paths
Given the root of a binary tree, return all root-to-leaf 
paths in any order.

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
*/

class Solution {
public:
    vector<string> res;
    vector<string> tmp;     // 用vector方便回溯，字符串不好删除
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)  return res;
        dfs(root);
        return res;
    }
    void dfs(TreeNode *root) {
        int v = root->val;
        if (!root->left && !root->right) {
            string s;
            tmp.push_back(to_string(v));
            for (auto str : tmp)   s += str;
            res.push_back(s);
            return;
        } 
        string s = to_string(v) + "->";
        tmp.push_back(s);            

        if (root->left)  dfs(root->left), tmp.pop_back();
        if (root->right) dfs(root->right), tmp.pop_back();
    }
};


/* 270. Closest Binary Search Tree Value
Given the root of a binary search tree and a target value, 
return the value in the BST that is closest to the target.
*/

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int l = root->val, r = root->val;
        while (root){
            if(target < root->val){
                r = root->val;
                root = root->left;
            } else if (target > root->val){
                l = root->val;
                root = root->right;
            } else
                return root->val;
        }
        return abs(target - l) < abs(r - target) ? l:r;
    }
};

/* 扩展：272. Closest Binary Search Tree Value II
Given the root of a binary search tree, a target value, and an integer k,
 return the k values in the BST that are closest to the target. 
 You may return the answer in any order.

You are guaranteed to have only one unique set of k values in the BST 
that are closest to the target.
*/

/* 285. Inorder Successor in BST
Given the root of a binary search tree and a node p in it, 
return the in-order successor of that node in the BST. 
If the given node has no in-order successor in the tree, return null.

The successor of a node p is the node with the smallest key greater than p.val.
*/

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = NULL;
        while (root) {
            if (p->val < root->val) {
                res = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return res;
    }
};


/* 298. Binary Tree Longest Consecutive Sequence
Given the root of a binary tree, return the length of 
the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node
 to any node in the tree along the parent-child connections. 
 The longest consecutive path needs to be from parent to child 
 (cannot be the reverse).
*/