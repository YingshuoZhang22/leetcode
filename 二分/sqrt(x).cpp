/* 69
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., 
and since the decimal part is truncated, 2 is returned.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;  

        int  l = 1, r = x;
        while(l < r) {
            int mid = l + (r - l + 1) / 2 ;
            if (mid <= x / mid)  l = mid;    
            // check函数找的是小于等于根号x的第一个数，如果check函数的mid恰好满足，实际值也可能是mid，
            // 所以区间被分为[l, mid] 和[mid + 1, right], 用模版2
            else r = mid - 1 ;
        }
        return l;  // 返回l-1
    }
};