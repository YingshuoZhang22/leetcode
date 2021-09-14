/* 60
"123" "132" "213" "231" "312" "321"

Input: n = 3, k = 3
Output: "213"

Input: n = 4, k = 9
Output: "2314"

Input: n = 3, k = 1
Output: "123"
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // 找规律，数位dp
        string res;
        vector<bool> st(10);
        for (int i = 0; i < n; i++) {
            // 每当填好一个数，都会有(n - i - 1)! 个数剩下
            int fact = 1;
            for (int j = 1; j <= n - i - 1; j++)    fact *= j;  // 算(n - i - 1)! 

            for (int j = 1; j <= n; j++) {
                if (!st[j]) {   //没有用过的数字
                    if (fact < k)   k -= fact;  // 以j开头的这一组都不行
                    else {
                        res += to_string(j);
                        st[j] = true;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
