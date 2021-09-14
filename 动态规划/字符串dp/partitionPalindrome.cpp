/* 132. Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<vector<bool>> g(n + 1, vector<bool>(n + 1));
        vector<int> f(n + 1, 1e8);

        for (int j = 1; j <= n; j ++ )  // g[i][j]表示s[i~j]是否是回文串
            for (int i = 1; i <= n; i ++ )
                if (i == j) g[i][j] = true;
                else if (s[i] == s[j]) {
                    if (i + 1 > j - 1 || g[i + 1][j - 1]) g[i][j] = true;
                }

        f[0] = 0;   // f[j][i]表示s[j~i]的最小partition次数
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= i; j ++ )
// 对于给定的s[1~i]，在s[1~j-1]是回文串的前提下，如果s[j~i]是回文串，可以直接加一转移过来，我们全遍历一遍
                if (g[j][i])
                    f[i] = min(f[i], f[j - 1] + 1); 
        }

        return f[n] - 1;
    }
};
