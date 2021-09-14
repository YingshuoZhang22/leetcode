#include <bits/stdc++.h>
using namespace std;
int m, n;

int main() {
    cin >> m >> n;
    vector<int> q(m + 1, 0);
    for (int i = 0; i < m; ++i)
        scanf("%d", &q[i]);
        
    while (n --) {
        int target;
        cin >> target;
        
        int l = 0, r = m - 1;
        while (l < r) {
            int mid = l + r >> 1;
            // 找 >= target的第一个数
            if (q[mid] >= target)   r = mid;    //找 >= target 左边界
            else    l = mid + 1;
        }
        
        if (q[l] != target) {   //左边界的值不等于target，不存在
            cout << "-1 -1" << endl;
            continue;
        }
        cout << l << " ";
        
        int l2 = 0, r2 = m - 1;
        while (l2 < r2) {
            int mid = l2 + r2 + 1 >> 1;
            if (q[mid] <= target)   l2 = mid;   // 找 <= target 右边界
            else r2 = mid - 1;
        }
        cout << l2 << endl;
    }
    
    return 0;
}
