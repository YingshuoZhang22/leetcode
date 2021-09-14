/*
输入一个 n 行 m 列的整数矩阵，再输入 q 个操作，每个操作包含五个整数 x1,y1,x2,y2,c，其中 (x1,y1) 和 (x2,y2) 表示一个子矩阵的左上角坐标和右下角坐标。
每个操作都要将选中的子矩阵中的每个元素的值加上 c。

数据范围
1 ≤ n,m ≤ 1000,
1 ≤ q ≤ 100000,
1 ≤ x1 ≤ x2 ≤ n,
1 ≤ y1 ≤ y2 ≤ m,
−1000 ≤ c ≤ 1000,
−1000 ≤ 矩阵内元素的值 ≤ 1000

输入样例：
3 4 3
1 2 2 1
3 2 2 1
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1
输出样例：
2 3 4 1
4 3 4 1
2 2 2 2
*/

#include <iostream>
using namespace std;
const int N = 1010;
int n, m, q, s[N][N], a[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    a[x1][y1] += c;
    a[x2 + 1][y1] -= c;
    a[x1][y2 + 1] -= c;
    a[x2 + 1][y2 + 1] += c;
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) 
            scanf("%d", &s[i][j]);
            
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) 
            insert(i, j, i, j, s[i][j]);    //给一个空的矩阵的一个位置插入s[i][j]
            
    while (q --) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1]; // 反求新的前缀和矩阵
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
