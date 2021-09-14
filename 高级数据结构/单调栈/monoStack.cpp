// 给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1。
#include <bits/stdc++.h>
using namespace std;

// 单调栈说明：所有满足i > j 且 a[i] < a[j]的都不是解
// 栈中的元素是单调的，每次都要新加入一个元素，而且不能破坏单调性
// 一种“覆盖”效应，比如a[i]是5，那么a[i]前所有大于等于5的数字都不考虑了
int main() {
    int n;
    cin >> n;
    int a[100005];
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    stack<int> stk;
    for (int i = 0; i < n; i ++) {
        while (stk.size() && stk.top() >= a[i])  stk.pop();   //如果栈顶元素大于当前待入栈元素，则出栈，直到满足栈顶小于当前元素
        // 把while循环 >= 换成 >，输出的是左边第一个小于等于他的数字 
        if (stk.size())   cout << stk.top() << ' ';        //栈顶元素就是左侧第一个比它小的元素。
        else cout << -1 << ' ';
        stk.push(a[i]);
    }
}