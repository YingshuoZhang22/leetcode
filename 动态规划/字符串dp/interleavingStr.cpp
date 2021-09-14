/* 97
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where they are divided into
 non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//  二维数组，f[i][j]表示s[i+j]能否有s1[i]和s2[j]拼凑而成
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1 + l2 != l3) return false;

        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;    // 腾位置
        vector<vector<bool>> dp(l1 + 1, vector(l2 + 1,false));
        // base case
        dp[0][0] = true; 
        for (int i = 1; i <= l1; i++)
            if (s1[i] == s3[i]) dp[i][0] = dp[i - 1][0];
        for (int i = 1; i <= l2; i++)   
            if (s2[i] == s3[i]) dp[0][i] = dp[0][i - 1];
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                // s3[i+j] 与 s1[i]相同,从s1的前i-1个转移
                if (s3[i + j] == s1[i]) dp[i][j] = dp[i - 1][j];
                
                // s3[i+j]与s2[j]相同，从s2的前j-1个转移
                if (s3[i + j] == s2[j]) dp[i][j] = dp[i][j] || dp[i][j - 1];   // 这里的||保证二者取其一即可
            }
        }
        return dp[l1][l2];
    }
};
