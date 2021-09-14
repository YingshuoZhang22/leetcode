/*
给定 N 个闭区间 [ai,bi] 以及一个线段区间 [s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。
输出最少区间数，如果无法完全覆盖则输出 −1。
*/

// 1. 将所有区间按照左端点从小到大进行排序
// 2. 从前往后枚举每个区间，在所有能覆盖start的区间中，选择右端点的最大区间，然后将start更新成右端点的最大值
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

int n;
struct Interval {
    int l, r;
    bool operator< (const Interval& I) {
        return l < I.l;
    }
}Intervals[N];

int main() {
    int st, ed;
    scanf("%d%d", &st, &ed);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        int l, r;
        scanf("%d%d", &l, &r);
        Intervals[i] = {l, r};
    }

    sort(Intervals, Intervals + n);

    int res = 0;
    bool success = false;
    for (int i = 0; i < n; i ++ ) {
        int j = i, r = -2e9;    // 双指针
        while (j < n && Intervals[j].l <= st) { // 遍历所有左端点在st左边的区间中，右端点的最大值是多少
            r = max(r, Intervals[j].r);
            j ++ ;
        }

        if (r < st) {   // 左端点都在st右边，无解
            res = -1;
            break;
        }

        res ++ ;
        if (r >= ed) {  // 右端点在ed右边，直接结束
            success = true;
            break;
        }

        st = r;
        i = j - 1;      // 因为等会还要 i ++
    }

    if (!success) res = -1;
    printf("%d\n", res);

    return 0;
}
