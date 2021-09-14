#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
char a[N], b[N];    
int dp[N][N];   // dp[m][n]表示a[1-m]b[1-n]的LCS

int main() {
    cin >> n >> m >> a + 1 >> b + 1;    // 字符串的下标从1开始
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            // 集合包含：https://www.acwing.com/video/946/ 10:00
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            if (a[i] == b[j])   dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n][m];
    return 0;
}