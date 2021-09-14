/* 149. Max Points on a Line
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        // 点的数量不够
        if(len < 3) {
            return len;
        }
        int maxNum = 2;
        // 遍历每两个点
        for(int i = 0; i < len; i ++) {
            unordered_map<double, int> count;
            for(int j = 0; j < len; j ++) {
                if(i != j) {
// 因为j的循环从0开始，所以能够保证任意两个点都能正反计算两次，当dx==0时，总会有一个同一条线上最大的y保证所有dy都为正
// c++浮点数为0除法不会报错
                    long long dx = points[i][0] - points[j][0];
                    long long dy = points[i][1] - points[j][1];
                    double gradient = dy * 1.0 / dx;
                    if(count.count(gradient)) {
                        count[gradient] ++;
                    } else {
                        count[gradient] = 2;
                    }
                    maxNum = max(maxNum, count[gradient]);
                } 
            }  
        }
        return maxNum;
    }
};