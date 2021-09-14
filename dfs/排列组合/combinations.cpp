/* 77
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

Example 1:
Input: n = 4, k = 2
Output:[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4],]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<bool> used;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        used = vector<bool>(n + 1, false);
        dfs(k, n, 1);
        return ans;
    }

    // 多一个start参数
    void dfs(int k, int n, int start) {
        if (path.size() == k)
            ans.push_back(path);
        for (int i = start; i <= n; i++) {
            if (!used[i]) {
                path.push_back(i);
                //used[i] = true;
                dfs(k, n, i + 1);
                //used[i] = false;
                path.pop_back();
            }
        }
    }
};