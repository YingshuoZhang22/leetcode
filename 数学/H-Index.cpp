/* 274. H-Index
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return compute the researcher's h-index.

According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.

If there are several possible values for h, the maximum one is taken as the h-index.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& c) {
        int len = c.size();
        sort(c.begin(), c.end(), greater<int>());   // 从大到小排序
        for (int h = c.size(); h >= 1; h--) {   // 因为有c[h-1]
            if (c[h - 1] >= h)  // 判断第h个数是否大于等于h
            return h; 
        }
        return 0;
    }
};


// 进阶：对数时间复杂度
// 极小化极大：枚举所有可能结果+二分
class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (c[n - mid] >= mid) l = mid; // 找第一个满足c[n - mid] >= mid的数字
            else r = mid - 1;
        }
        return r;
    }
};
