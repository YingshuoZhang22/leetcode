/*
给定 N 个闭区间 [ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。
输出选择的点的最小数量。
位于区间端点上的点也算作区间内。

1 <= points.length <= 1e4
points[i].length == 2
-2e31 <= xstart < xend <= 2e31 - 1

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 区间选点,按右端升序排列

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });
        int len = points.size(), res = 0, end = INT_MIN;
        for (int i = 0; i < len; i++) {
            if (points[i][0] > end || points[i][0] == INT_MIN) {
                res ++;
                end = points[i][1]; // 选的点都是区间的右端点
            }
        }
        return res;
    }
};