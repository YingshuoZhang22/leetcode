#include <vector>
#include <iostream>
using namespace std;

void merge_sort(vector<int>& v, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(v, l, mid), merge_sort(v, mid + 1, r);

    int i = 0, lptr = l, rptr = mid + 1;
    vector<int> tmp(r - l + 1, 0);

    while (lptr <= mid && rptr <= r) {
        if (v[lptr] > v[rptr]) 
            tmp[i++] = v[rptr++];
        else 
            tmp[i++] = v[lptr++];
    }
    while (lptr <= mid)     tmp[i++] = v[lptr++];
    while (rptr <= r)       tmp[i++] = v[rptr++];

    for (int m = 0, n = l; n <= r; m++, n++)
        v[n] = tmp[m];
}

int main() {
    int i;
    vector<int> v;
    while (cin >> i)
        v.push_back(i);
    merge_sort(v, 0, v.size() - 1);
    for (auto i : v)
        cout << i << ' ';
}