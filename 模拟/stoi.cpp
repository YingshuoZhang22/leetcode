#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, len = s.size();
        while (i < len && s[i] == ' ')  i++;
        if (i == len)  return 0;

        int minus = 1;
        if (s[i] == '-')  minus = -1, i++;
        else if (s[i] == '+') i++;

        long long res = 0;
        while (i < len && s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + s[i] - '0';
            if (res > INT_MAX)  break;
            i++;
        }
        res *= minus;
        if (res > INT_MAX)  return INT_MAX;
        if (res < INT_MIN)  return INT_MIN;  
        return res;
    }
};