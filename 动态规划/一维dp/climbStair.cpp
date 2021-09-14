/* 70
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include <bits/stdc++.h>
using namespace std;

// f[i] = f[i - 1] + f[i - 2]

class Solution {
public:
    int climbStairs(int n) {
        if  (n == 1)    return 1;
        if  (n == 2)    return 2;
        int a = 1, b = 2, temp;
        for (int i = 3; i <= n; i++) {
            temp = a;
            a = b;
            b = temp + b;
        }
        return b;   
    }
};

