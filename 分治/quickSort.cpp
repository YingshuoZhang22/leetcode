#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& v, int l, int r) {
    if (l >= r) return;
    int mid = v[l + (r-l) / 2], lptr = l - 1, rptr = r + 1;
    while (lptr < rptr) {
        do lptr++; while(v[lptr] < mid);    // 这里必须写mid，不能写v[l + (r-l) / 2]
        do rptr--; while(v[rptr] > mid);
        if (lptr < rptr)    
            swap(v[lptr], v[rptr]);
    }
    quicksort(v, l, rptr), quicksort(v, rptr + 1, r); // 这里必须用rptr，不能用lptr
}

int main() {
    vector<int> v;
    int i;
    cin >> i;
    
    while (cin >> i) 
        v.push_back(i);
    
    quicksort(v, 0, v.size() - 1);
    for (auto i : v)
        cout << i << ' ';
}
