/*
给定 n 组 ai,bi,pi，对于每组数据，求出 abiimodpi 的值。
输入格式:
第一行包含整数 n。
接下来 n 行，每行包含三个整数 ai,bi,pi。
输出格式:
对于每组数据，输出一个结果，表示 abiimodpi 的值。
*/

#include <bits/stdc++.h>
using namespace std;
// 把bi写成二进制，例：求4^5 mod 10：
// 4^1 = 4 (mod 10); 4^2 = 6 (mod 10); 4^4 = 6 (mod 10);
// 4^5 = 4^(101) = 4^4 * 4^1 = 6 * 4 = 4 (mod 10)
typedef long long LL;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1)  res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n -- ) {
        int a, k, p;
        cin >> a >> k >> p;
        cout << qmi(a, k, p) << endl;
    }
    return 0;
}
