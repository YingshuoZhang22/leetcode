#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1 = s.size(), l2 = t.size();
        if (l1 > l2)    return false;
        int i = 0, j = 0;
        while (i < l1 && j < l2) {
            if (s[i] == t[j])   i++, j++;   // greedy
            else j++;
        }
        return i == l1;
    }
};