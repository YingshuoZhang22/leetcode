/* 84
Given an array of integers heights representing the histogram's 
bar height where the width of each bar is 1, return the area of
the largest rectangle in the histogram.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 三次遍历，用单调栈求每个数左边/右边小于它的第一个元素，然后对每个矩形求一次
    // 用单调递增栈
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size(), res = 0;
        stack<int> stk;
        vector<int> left(len, 0), right(len, 0);

        // left[i]是左边第一个比i小的元素的下标位置
        for (int i = 0; i < len; i++) {
            while (stk.size() && heights[stk.top()] >= heights[i])  stk.pop();
            if (stk.empty())    left[i] = -1;   // 哨兵
            else left[i] = stk.top();
            stk.push(i);
        }

        stk = stack<int>(); // 没有clear
        // right[i]是i右边第一个比i小的元素的下标位置
        for (int i = len - 1; i >= 0; i--) {
            while (stk.size() && heights[stk.top()] >= heights[i])  stk.pop();
            if (stk.empty())    right[i] = len;
            else right[i] = stk.top();
            stk.push(i);
        }

        for (int i = 0; i < len; i++) 
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        return res;
    }
};

/* 85
Given a rows x cols binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and return its area.
*/

class Solution {
public:
    // 先用dp求出每一行每个格子上最高的连续矩形，再对每一行使用上一题的思路
    int maximalRectangle(vector<vector<char>>& input) {
        if (input.empty())  return 0;
        int row = input.size(), col = input[0].size(), res = 0;
        if (!row || !col)   return 0;
        vector<vector<int>> matrix(row, vector<int>(col, 0));
        
        for (int i = 0; i < row; ++i) 
            for (int j = 0; j < col; ++j) {
                if (i == 0) matrix[i][j] = input[i][j] - '0';
                else if (input[i][j] == '1')   matrix[i][j] = 1 + matrix[i - 1][j];
            }
        
        stack<int> stk;
        vector<int> left(col, 0), right(col, 0);
        for (int i = 0; i < row; i++) {
            stk = stack<int>();
            for (int j = 0; j < col; j++) {
                while (stk.size() && matrix[i][stk.top()] >= matrix[i][j])  stk.pop();
                if (stk.empty())    left[j] = -1;
                else left[j] = stk.top();
                stk.push(j);
            }

            stk = stack<int>();
            for (int j = col - 1; j >= 0; j--) {
                while (stk.size() && matrix[i][stk.top()] >= matrix[i][j])  stk.pop();
                if (stk.empty())    right[j] = col;
                else right[j] = stk.top();
                stk.push(j);
            }

            for (int j = 0; j < col; j++) {
                res = max(res, (right[j] - left[j] - 1) * matrix[i][j]);
            }
        }
        return res;
    }
};
