/* 155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
*/
#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk, minStk;
    MinStack() {
        stk = stack<int>(), minStk = stack<int>();
    }
    
    void push(int val) {
        stk.push(val);
        if (minStk.empty() || minStk.top() > val) {
            minStk.push(val);
        } else {
            minStk.push(minStk.top());
        }
    }
    
    void pop() {
        stk.pop(), minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};