/* 264. Ugly Number II
An ugly number is a positive integer whose prime factors 
are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
pi的含义是有资格同i相乘的最小丑数的位置。这里资格指的是：如果一个丑数nums[pi]通过乘以i可以得到下一个丑数，那么这个丑数nums[pi]就永远失去了同i相乘的资格（没有必要再乘了），我们把pi++让nums[pi]指向下一个丑数即可。

一开始，丑数只有{1}，1可以同2，3，5相乘，取最小的1×2=2添加到丑数序列中。

现在丑数中有{1，2}，在上一步中，1已经同2相乘过了，所以今后没必要再比较1×2了，我们说1失去了同2相乘的资格。

现在1有与3，5相乘的资格，2有与2，3，5相乘的资格，但是2×3和2×5是没必要比较的，因为有比它更小的1可以同3，5相乘，所以我们只需要比较1×3，1×5，2×2。

依此类推，每次我们都分别比较有资格同2，3，5相乘的最小丑数，选择最小的那个作为下一个丑数，假设选择到的这个丑数是同i（i=2，3，5）相乘得到的，所以它失去了同i相乘的资格，把对应的pi++，让pi指向下一个丑数即可。
*/
    int nthUglyNumber(int n) {
        vector<int> v(1,1);
        int p2 = 0, p3 = 0, p5 = 0;
        while (v.size() < n) {
            int next = min(v[p2] * 2, min(v[p3] * 3, v[p5] * 5));
            v.push_back(next);
            if (next == v[p2] * 2)  p2++;
            if (next == v[p3] * 3)  p3++;   // 不能写else if， 因为可能多个if同时满足
            if (next == v[p5] * 5)  p5++;
        }
        return v.back();
    }
};


/* 313. Super Ugly Number
A super ugly number is a positive integer whose prime factors are in the array primes.

Given an integer n and an array of integers primes, return the nth super ugly number.

The nth super ugly number is guaranteed to fit in a 32-bit signed integer.


Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the
 first 12 super ugly numbers given primes = [2,7,13,19].
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        typedef pair<long long, int> PII;
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        for (int x: primes) heap.push({x, 0});
        vector<int> q(n);
        q[0] = 1;
        for (int i = 1; i < n;) {
            auto t = heap.top(); heap.pop();
            if (t.first != q[i - 1]) q[i ++ ] = t.first;    // 保证heap中没有重复元素
            int idx = t.second, p = t.first / q[idx];
            heap.push({(long long)p * q[idx + 1], idx + 1});
        }
        return q[n - 1];
    }
};
