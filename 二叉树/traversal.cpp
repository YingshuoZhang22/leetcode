/* 94
inorder traversal (left-root-right)
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
    // 颜色标记法，标记 = 0，表示还没遍历该节点的左子树；标记 = 1，表示已经遍历完左子树，但还没遍历右子树；标记 = 2，表示已经遍历完右子树；
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*, int>>sta;
        sta.push(make_pair(root, 0));
        while (!sta.empty()) {
            if (sta.top().first == NULL) {
                sta.pop();
                continue;
            }
            int t = sta.top().second;
            if (t == 0) {   //标记 = 0，则将该节点的标记改成1，然后将其左儿子压入栈中；
                sta.top().second = 1;
                sta.push(make_pair(sta.top().first->left, 0));
            }
            else if (t == 1) {  //标记 = 1，则说明左子树已经遍历完，将根节点的值插入答案序列中，然后将该节点的标记改成2，并将右儿子压入栈中；
                res.push_back(sta.top().first->val);
                sta.top().second = 2;
                sta.push(make_pair(sta.top().first->right, 0));
            }
            else sta.pop(); //标记 = 2，则说明以该节点为根的子树已经遍历完，直接从栈中弹出即可；
        }
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root || stk.size()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top(), stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};


/* 102
level order traversal 
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (!root)  return res;
        que.push(root);
        while (que.size()) {
            int n = que.size();
            vector<int> level;
            
            while (n--) {
                TreeNode *tmp = que.front();
                que.pop();
                level.push_back(tmp->val);
                if (tmp->left)  que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

/* 144. Binary Tree Preorder Traversal （root->left->right)
*/

class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;

        while (root || stk.size()) {
            while (root) {
                res.push_back(root->val);
                stk.push(root);
                root = root->left;
            }

            root = stk.top(), stk.pop();
            root = root->right;
        }
        return res;
    }
};


/* 145. Binary Tree Postorder Traversal
左右根
*/

class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;

        while (root || stk.size()) {
            while (root) {
                res.push_back(root->val);
                stk.push(root);
                root = root->right;  // 注意这里,得到根右左
            }

            root = stk.top(), stk.pop();
            root = root->left;
        }
        // 反转得到根左右
        reverse(res.begin(), res.end());
        return res;
    }
};



/* 314. Binary Tree Vertical Order Traversal
Given the root of a binary tree, return the vertical order traversal 
of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

就是把树中点映射成x,y坐标
*/

class Solution {
public:
    map<int, vector<vector<int>>> S;  // y-coord -> [x-coord, value]

    // 行为x，列为y
    void dfs(TreeNode* root, int x, int y) {
        if (!root) return;
        S[y].push_back({x, root->val});
        dfs(root->left, x + 1, y - 1);
        dfs(root->right, x + 1, y + 1);
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for (auto& [k, v]: S) {
            sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
            // 这个重载函数很重要，我们希望只按照v[0]比较，v[0]相等的话，保持相对顺序不便而不是按照v[1]继续比，所以要重写
            vector<int> col;
            for (auto& p: v) col.push_back(p[1]);
            res.push_back(col);
        }
        return res;
    }
};