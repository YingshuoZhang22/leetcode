// 字符串前缀哈希法，快速判断两个字符串是否相等，O(1)时间
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
const int N = 100010, P = 131;
int n, m;
char str[N];
ULL h[N], p[N]; // h[i]表示前i个字符的哈希值 P[i]表示r^i
//前缀和公式 h[i+1]=h[i]×P+s[i] i∈[0,n−1] i∈[0,n−1] h为前缀和数组，s为字符串数组
//区间和公式 h[l,r]=h[r]−h[l−1]×P^(r−l+1)

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    cin >> n >> m >> str + 1;
    p[0] = 1;
    for (int i = 1; i <= n; i ++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    while (m --) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        if (get(l1, r1) == get(l2, r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
