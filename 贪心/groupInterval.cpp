/*
给定 N 个闭区间 [ai,bi]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。
输出最小组数。
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n;

struct Interval {
    int l, r;
    bool operator< (const Interval& I)const {
        return l < I.l;
    }
} Intervals[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        Intervals[i] = {l, r};
    }

    sort(Intervals, Intervals + n); // 按区间左端点从小到大排序

// 思路：能装下就装，装不下就开一个新区间
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < n; i ++) {
        auto Interval = Intervals[i];
// 如果一个区间的左端点比最小组的右端点要小，Intervals[i].l<=heap.top() ，就开一个新组 heap.push(range[i].r);
        if (minheap.empty() || minheap.top() >= Interval.l)
            minheap.push(Interval.r);
        else {
// 如果一个区间的左端点比最小组的右端点要大，则放在该组，heap.pop(), heap.push(Intervals[i].r);
            minheap.pop();
            minheap.push(Interval.r);
        }
    }

    cout << minheap.size() << endl;
    return 0;
}


