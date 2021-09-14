/* 29
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// https://www.acwing.com/solution/content/87/
    int divide(int dividend, int divisor) {
        const int HALF_INT_MIN = -1073741824;
        int x = dividend, y = divisor;

        bool sign = (x > 0) ^ (y > 0);

        if (x > 0) x = -x;
        if (y > 0) y = -y;

        vector<pair<int, int>> ys;

        for (int t1 = y, t2 = -1; t1 >= x; t1 += t1, t2 += t2) {
            ys.emplace_back(t1, t2);
            if (t1 < HALF_INT_MIN)
                break;
        }

        int ans = 0;
        for (int i = ys.size() - 1; i >= 0; i--)
            if (x <= ys[i].first) {
                x -= ys[i].first;
                ans += ys[i].second;
            }

        if (!sign) {
            if (ans == INT_MIN)
                return INT_MAX;
            ans = -ans;
        }

        return ans;
    }
};
