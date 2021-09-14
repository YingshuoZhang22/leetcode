/* 201. Bitwise AND of Numbers Range
Given two integers left and right that represent the range [left, right], 
return the bitwise AND of all numbers in this range, inclusive.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// 有符号整型除了符号位还剩31位，编号为0 - 30
//【笔记】当一个数+1时，总会有这么一个规律“某一位后的数字，全部被置为相反数”。举个例子：

// 010111 + 1 = 011000，则010111 & 011000 = 010000。那么，x & (x+1) 后几位相反数的“与操作”，结果总为0。
// 所以，当(m,m+1,...n-1,n)进行连续“与操作”时，会按照上述规律被抵消很大一部分，而只剩下n的前缀部分，最后只需将n归位。举个例子：

// m = 5(0101), n = 7 (0111)。不停右移，得到n前缀部分为01，最后归位前缀得res=0100=4
    int rangeBitwiseAnd(int m, int n) {
        int offset = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            offset++;
        }
        return n << offset;
    }
};