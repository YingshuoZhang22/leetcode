/*
输入一个长度为 n 的整数序列。
接下来输入 m 个操作，每个操作包含三个整数 l,r,c，表示将序列中 [l,r] 之间的每个数加上 c。

数据范围
1 ≤ n,m ≤ 100000,
1 ≤ l ≤ r ≤ n,
−1000 ≤ c ≤ 1000,
−1000 ≤ 整数序列中元素的值 ≤ 1000

输入样例：
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1

输出样例：
3 4 5 3 4 2
*/

#include <iostream>
using namespace std;
const int N = 100005;
int n, m, s[N], a[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)    scanf("%d", &s[i]);
    for (int i = 1; i <= n; ++i) {
        a[i] += s[i];       // s: 1 2 3 4 5
        a[i + 1] -= s[i];   // a: 1 1 1 1 1
    }
    while (m --) {
        int l, r, c;
        cin >> l >> r >> c; 
        a[l] += c;
        a[r + 1] -= c;      //本来每次修改原数组长度为k的区间需要k次操作，现在只需要2次操作
    }
    
    for (int i = 1; i <= n; ++i) 
        a[i] += a[i - 1];   //构造原本的前缀和数组
    
    for (int i = 1; i <= n; ++i) 
        printf("%d ", a[i]);
}