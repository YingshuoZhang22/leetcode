#include <iostream>
#include <vector>
using namespace std;

int quick_select(vector<int>& v, int l, int r, int k) {
    if (l == r) return v[l];
    int lptr = l - 1, rptr = r + 1, mid = v[(l + r) / 2];
    while (lptr < rptr) {
        do lptr++; while (v[lptr] < mid);
        do rptr--; while (v[rptr] > mid);
        if (lptr < rptr)
            swap(v[lptr], v[rptr]);
    }
    int cnt = rptr - l + 1; // 这里必须用rptr，不能用lptr
    if (cnt >= k)
        return quick_select(v, l, rptr, k);
    else 
        return quick_select(v, rptr + 1, r, k - cnt);
}

int main() {
    int n, k, i;
    vector<int> v;
    cin >> n >> k;
    while (cin >> i)
        v.push_back(i);
    
    cout << quick_select(v, 0, n - 1, k);
    return 0;
}
