/* 44
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // f[i][j] 表示s[i]与p[j]是否匹配：
    // 1. p[j]不是"*": (p[j] == "?" || p[j] == s[i]) && f[i-1][j-1]
    // 2. p[j]是"*" :
    //  (1) 匹配0个：f[i][j-1]

    //  (2)匹配1+个：f[i-1][j-1] || f[i-2][j-1] || f[i-3][j-1] || .... 
    //这部分就是f[i-1][j] = f[i-1][j-1] || f[i-2][j-1] || ... || f[0][j-1]

    // 所以p[j]是"*"时候：f[i][j-1] ||  f[i-1][j]
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        // s空，p非空时仍有可能匹配成功
        for (int i = 1; i <= m; i++) {
            if (p[i] == '*')    dp[0][i] = dp[0][i - 1];
            else dp[0][i] = false; 
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = (s[i] == p[j] || p[j] == '?') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};