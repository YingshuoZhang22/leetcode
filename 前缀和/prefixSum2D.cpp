/*
输入一个 n 行 m 列的整数矩阵，再输入 q 个询问，每个询问包含四个整数 x1,y1,x2,y2，表示一个子矩阵的左上角坐标和右下角坐标。
对于每个询问输出子矩阵中所有数的和。

1 ≤ x1 ≤ x2 ≤ n,
1 ≤ y1 ≤ y2 ≤ m,
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m, q;

int main() {
    cin >> n >> m >> q;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0)), s(n + 1, vector<int>(m + 1, 0)); 
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) 
            scanf("%d", &a[i][j]);
            
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1] << endl;
    }
}