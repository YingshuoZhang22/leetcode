#include <vector>
#include <iostream>
using namespace std;

long long merge_sort(vector<int>& v, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    long long res = merge_sort(v, l, mid) + merge_sort(v, mid + 1, r);

    int i = 0, lptr = l, rptr = mid + 1;
    vector<int> tmp(r - l + 1, 0);

    //                 *         *
    // 例： 某刻数组为 3 5 7   0 1 2
    // 需要添加 3,5,7共3个逆序对
    
    while (lptr <= mid && rptr <= r) {
        if (v[lptr] > v[rptr]) 
            tmp[i++] = v[rptr++], res += mid - lptr + 1;
        else 
            tmp[i++] = v[lptr++];
    }
    while (lptr <= mid)     tmp[i++] = v[lptr++];
    while (rptr <= r)       tmp[i++] = v[rptr++];

    for (int m = 0, n = l; n <= r; m++, n++)
        v[n] = tmp[m];
        
    return res;
}

int main() {
    int i, n;
    cin >> n;
    vector<int> v;
    while (cin >> i)
        v.push_back(i);
    cout << merge_sort(v, 0, n - 1);
}
