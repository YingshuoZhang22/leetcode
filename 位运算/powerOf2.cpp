/* 231. Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t lowbit(uint32_t x) {
        return x & (-x);
    }
    bool isPowerOfTwo(int n) {
        return n > 0 && n == lowbit(n);
    }
};