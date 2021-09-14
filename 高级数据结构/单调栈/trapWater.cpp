// 42
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

// 换一种思路，考虑每个位置左边和右边 第一个 比自身不低的矩形条，以及三个矩形条构成的 U 型，相当于对水的面积按 行 进行拆解。
// 维护严格单调递减的单调栈。在每次检查栈顶要出栈时，i 为右边第一个比 st.top() 不低的矩形，st.top() 弹出栈顶，并将其记为 top。
// 假设此时栈中仍然存在矩形，现在 st.top()（弹栈后的栈顶）、top 与 i 三个位置构成一个 U 型，其中 top 位置代表 U 型的底部，此时可以计算出该 U 型所能接受的水的面积为 (i - st.top() - 1) * (min(height[st.top()], height[i]) - height[top])。
// 最后当前矩形进栈。

    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] <= height[i]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                ans += (i - st.top() - 1) 
                        * (min(height[st.top()], height[i]) - height[top]);
            }
            st.push(i);
        }
        return ans;
    }
};