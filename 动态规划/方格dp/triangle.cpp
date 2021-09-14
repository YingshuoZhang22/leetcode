/*
给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。

        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5

输入格式
第一行包含整数 n，表示数字三角形的层数。
接下来 n 行，每行包含若干整数，其中第 i 行表示数字三角形第 i 层包含的整数。

输出格式
输出一个整数，表示最大的路径数字和。
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int tri[N][N], dp[N][N];

int main() {
    int n; 
    cin >> n;
    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= i; j ++)
            cin >> tri[i][j];
    
    // 只能向下或者向右下方走
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            if (i != j && j != 1)   
                dp[i][j] = max(dp[i - 1][j] + tri[i][j], dp[i - 1][j - 1] + tri[i][j]);
            if (j == i) dp[i][j] = dp[i - 1][j - 1] + tri[i][j];    // 对角线只能向右下方走
            if (j == 1) dp[i][j] = dp[i - 1][j] + tri[i][j];        // 第一列只能向正下方走
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++)   res = max(res, dp[n][i]);
    cout << res << endl;
}
