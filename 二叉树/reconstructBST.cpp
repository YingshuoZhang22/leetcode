/* 105
 Construct Binary Tree from Preorder and Inorder Traversal
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
    unordered_map<int, int> hash;
    vector<int> preorder, inorder;
    TreeNode* buildTree(vector<int>& preord, vector<int>& inord) {
        preorder = preord, inorder = inord;
        int len = preorder.size(); 
        if(!len)    return nullptr;
        for (int i = 0; i < len; i++)   hash.insert({inorder[i], i});
        return helper(0, len - 1, 0, len - 1);
    }

    // preorder开头的做root，root在inorder左边的是left tree，右边的是right tree，递归
    TreeNode* helper(int pre_st, int pre_ed, int in_st, int in_ed) {
        int len = pre_ed - pre_st + 1;
        if (len <= 0)   return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_st]);
        int root_posi = hash[preorder[pre_st]];
        int left_size = root_posi - in_st, right_size = in_ed - root_posi;
        root->left = helper(pre_st + 1, pre_st + left_size, in_st, root_posi - 1);
        root->right = helper(pre_st + left_size + 1, pre_ed, root_posi + 1, in_ed);
        return root;
    }
};

/* 106. Construct Binary Tree from Inorder and Postorder Traversal
*/

class Solution {
public:
    unordered_map<int,int> pos;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i ++ )
            pos[inorder[i]] = i;
        return dfs(postorder, inorder, 0, n - 1, 0, n - 1);
    }

    // pl, pr 表示当前子树后序遍历在数组中的位置
    // il, ir 表示当前子树中序遍历在数组中的位置
    TreeNode* dfs(vector<int>&post, vector<int>&in, int pl, int pr, int il, int ir) {
        if (pl > pr) return NULL;
        int k = pos[post[pr]] - il;
        TreeNode* root = new TreeNode(post[pr]);
        root->left = dfs(post, in, pl, pl + k - 1, il, il + k - 1);
        root->right = dfs(post, in, pl + k, pr - 1, il + k + 1, ir);
        return root;
    }
};

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 109. Convert Sorted List to Binary Search Tree
*/
class Solution {
public:
// 简简单单递个鬼
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)  return nullptr;
        if (!head->next)    return new TreeNode(head->val);
        ListNode *pre = head, *slow = pre->next, *fst = slow->next; // 快慢指针找中点
        while (fst && fst->next) {
            fst = fst->next->next, slow = slow->next, pre = pre->next;
        }
        pre->next = nullptr;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head), root->right = sortedListToBST(slow->next);
        return root;
    }
};

