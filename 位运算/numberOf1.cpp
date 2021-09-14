/* 191. Number of 1 Bits
Write a function that takes an unsigned integer and
 returns the number of '1' bits it has (also known as the Hamming weight).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};

// lowbit运算 
class Solution {
public:
// 所以假设一个数的二进制最低位的1在从右往左数的第𝑘位，那么它的𝑙𝑜𝑤𝑏𝑖𝑡值就是 2^(k-1)
    uint32_t lowbit(uint32_t x) {
        return x & (-x);
    }

    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n -= lowbit(n);
            ans++;
        }
        return ans;
    }
};