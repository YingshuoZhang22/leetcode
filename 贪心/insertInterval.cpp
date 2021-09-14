/* 57
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> res;
        sort(a.begin(), a.end());
        int l = a[0][0], r = a[0][1];
        for (int i = 1; i < a.size(); i++) {
            if (a[i][0] > r) {
                res.push_back({l, r});
                l = a[i][0], r = a[i][1];
            } else {
                r = max(r, a[i][1]);
            }
        }
        res.push_back({l, r});
        return res;
    }


    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 抄55题代码
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        return merge(intervals);

    }
};