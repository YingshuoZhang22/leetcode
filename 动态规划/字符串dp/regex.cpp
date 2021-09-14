/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// 为什么dp：无后效性，只需要有一种匹配方式就可以了
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true; // f[i][j]表示s[1-i]与p[1-j]能匹配
        for (int i = 0; i <= n; i ++ )  // s从0开始，因为s="", p=a*也可以匹配
            for (int j = 1; j <= m; j ++ ) {    // p从1开始，因为p=""不能匹配任何非空的s
                if (j + 1 <= m && p[j + 1] == '*') continue;    // 有*的到下一轮在处理
                if (i && p[j] != '*') { // p不是*，那就s[i]=p[j]或者p是.
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                } else if (p[j] == '*') {   // 使用了完全背包的优化
                // f[i][j - 2]：p*看成空串；i && f[i - 1][j]：使用了完全背包的优化
                    f[i][j] = f[i][j - 2] || i && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');
                }
            }

        return f[n][m];
    }
};





