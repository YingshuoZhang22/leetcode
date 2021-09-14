/* 131
给定一个字符串，用O(n^2)预处理，再用O(1)判断是否为palindrome
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<bool>> f;
    vector<vector<string>> ans;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        int n = s.size();

// f[i][j]表示s[i~j]是否为palindrome
        f = vector<vector<bool>>(n, vector<bool>(n));
        for (int j = 0; j < n; j ++ )   // 必须先枚举j再枚举i，这样才能保证f[i + 1][j - 1])被提前算出来
            for (int i = 0; i <= j; i ++ )
                if (i == j) f[i][j] = true;
                else if (s[i] == s[j]) {
                    // i + 1 > j - 1：长度为2的子串，也可写成i == j - 1
                    if (i + 1 > j - 1 || f[i + 1][j - 1]) f[i][j] = true;
                }

        dfs(s, 0);
        return ans;
    }

    void dfs(string& s, int u) {
        if (u == s.size()) ans.push_back(path);
        else {
            for (int i = u; i < s.size(); i ++ )
                if (f[u][i]) {
                    path.push_back(s.substr(u, i - u + 1));
                    dfs(s, i + 1);
                    path.pop_back();
                }
        }
    }
};
