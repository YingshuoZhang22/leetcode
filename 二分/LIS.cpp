#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> q;
        for (auto x: nums) {
            if (q.empty() || x > q.back())  q.push_back(x);
            else {
                if (x <= q[0])  q[0] = x;
                else {  // 把比x小的最大的数字的下一个位置更新成x
                    int l = 0, r = q.size() - 1;
                    while (l < r) {
                        int mid = l + r + 1 >> 1;
                        if (q[mid] < x) l = mid;
                        else r = mid - 1;
                    }
                    q[l + 1] = x;
                }
            }
        }
        return q.size();
    }
};

// 长度为1-k的上升子序列的最小值的结尾是单调的

int main() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++ i) cin >> arr[i];

    vector<int> stk;//模拟堆栈
    stk.push_back(arr[0]);

    for (int i = 1; i < n; ++ i) {
        if (arr[i] > stk.back())    //如果该元素大于栈顶元素,将该元素入栈
            stk.push_back(arr[i]);
        else    //替换掉第一个大于或者等于这个数字的那个数
            *lower_bound(stk.begin(), stk.end(), arr[i]) = arr[i];
    }
    cout << stk.size() << endl;
    return 0;
}
/*
例 n: 7
arr : 3 1 2 1 8 5 6

stk : 3

1 比 3 小
stk : 1

2 比 1 大
stk : 1 2

1 比 2 小
stk : 1 2

8 比 2 大
stk : 1 2 8

5 比 8 小
stk : 1 2 5

6 比 5 大
stk : 1 2 5 6
*/