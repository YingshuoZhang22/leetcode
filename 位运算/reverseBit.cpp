/* 190. Reverse Bits
Reverse bits of a given 32 bits unsigned integer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        // 和颠倒十进制其实差不多
        for (int i = 0; i < 32; i++) {
            res = (res << 1) + (n >> i & 1);  // 取出n的第i位
        }
        return res;
    }
};