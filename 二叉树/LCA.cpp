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

/* 235. Lowest Common Ancestor of a Binary Search Tree
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p1, TreeNode* q1) {
        int v = root->val, p = p1->val, q = q1->val;
        if (v == p || v == q)   return root;
        if (v > p && v > q) return lowestCommonAncestor(root->left, p1, q1);
        if (v < p && v < q) return lowestCommonAncestor(root->right, p1, q1);
        return root;
    }
};

/*236. Lowest Common Ancestor of a Binary Tree
*/

class Solution {
public:
// 类似树中的二分查找,树中没有parent指针的。O(nlogn)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = root->val, p1 = p->val, q1 = q->val;
        if ((hasVal(root->left, p1) && hasVal(root->left, q1)))     return lowestCommonAncestor(root->left, p, q);
        if ((hasVal(root->right, p1) && hasVal(root->right, q1)))     return lowestCommonAncestor(root->right, p, q);
        return root;
    }

    bool hasVal(TreeNode* root, int val) {
        if (!root)  return false;
        if (root->val == val) return true;
        return hasVal(root->left, val) || hasVal(root->right, val);
    }
};


// 倒序枚举，timeO(n), spaceO(n)
class Solution {
public:

    bool dfs(TreeNode *cur, TreeNode *des, vector<TreeNode*> &path_node) {
        if (cur == NULL)
            return false;
        if (cur == des) {
            path_node.push_back(cur);
            return true;
        }
        if (dfs(cur -> left, des, path_node) || dfs(cur -> right, des, path_node)) {
            path_node.push_back(cur);
            return true;
        }

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_node_p, path_node_q;
        dfs(root, p, path_node_p);
        dfs(root, q, path_node_q);
        reverse(path_node_p.begin(), path_node_p.end());
        reverse(path_node_q.begin(), path_node_q.end());

        int n = min(path_node_p.size(), path_node_q.size());
        for (int i = n - 1; i >= 0; i--)
            if (path_node_p[i] == path_node_q[i])
                return path_node_p[i];

        return NULL;
    }
};


/* 我们可以用哈希表存储所有节点的父节点，然后我们就可以利用节点的父节点信息从 p 结点开始不断往上跳，并记录已经访问过的节点，再从 q 节点开始不断往上跳，如果碰到已经访问过的节点，那么这个节点就是我们要找的最近公共祖先。
*/
class Solution {
public:
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root){
        if (root->left != nullptr) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) return q;
            q = fa[q->val];
        }
        return nullptr;
    }
};
