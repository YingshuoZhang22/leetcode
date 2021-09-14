/* 115. Distinct Subsequences
Given two strings s and t, return the number of distinct 
subsequences of s which equals t.

A string's subsequence is a new string formed from the 
original string by deleting some (can be none) of the 
characters without disturbing the remaining characters' 
relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer.

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
    // dp[i][j]表示前s[1-i]中 t[1-j]出现了几次
    int n = s.size(), m = t.size();
    vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
    s = ' ' + s, t = ' ' + t;

    for (int i = 0; i <= n; i++)    dp[i][0] = 1;    // 如果target为空，则当作在s中出现1次（空集是所有字符串的子集？）

    // 如果s为空但target不为空，那么视作0次，已经被初始化
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 若s[i]和t[j]相等，那么可以选s[i](dp[i - 1][j - 1])，也可以不选s[i](dp[i - 1][j])
            if (s[i] == t[j])   dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j];   // 不等，直接转移
        }
    }
    return dp[n][m];
    }
};