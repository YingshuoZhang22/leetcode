/* 202. Happy Number
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//这题可以用快慢指针的思想去做，有点类似于检测是否为环形链表那道题
//如果给定的数字最后会一直循环重复，那么快的指针（值）一定会追上慢的指针（值），也就是
//两者一定会相等。如果没有循环重复，那么最后快慢指针也会相等，且都等于1。
    int happy(int x) {
        int res = 0;
        while (x != 0) {
            res += (x % 10) * (x % 10);
            x /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int fast = happy(n), slow = n;
        while (fast != slow) {
            fast = happy(happy(fast));
            slow = happy(slow);
        }
        return fast == 1;
    }
};