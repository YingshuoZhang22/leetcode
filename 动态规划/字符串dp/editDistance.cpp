#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // dp[i][j]表示a[1~i]变到b[1~j]需要的最少次数
    // 六种转移：插入/删除/修改  a/b  
    //         删除a与插入b等价；删除b与插入a等价，所以一共有4种转移状态
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        a = ' ' + a, b = ' ' + b;
        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        // 从空串变到另一个长度为i的字符串需要i次操作
        for (int i = 0; i <= n; i ++ ) f[i][0] = i;
        for (int i = 1; i <= m; i ++ ) f[0][i] = i;

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ ) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;    // 插入或者删除
                int t = (a[i] != b[j]); // 如果相同，修改0次；否则修改1次
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + t);    // 找最小值
            }

        return f[n][m];      
    }
};