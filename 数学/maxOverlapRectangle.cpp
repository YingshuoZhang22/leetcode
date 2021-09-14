/*223. Rectangle Area
Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

Rectangle Area
Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
Output: 45

Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
Output: 16
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

class Solution {
public:
    // (A,B) (C,D) (E,F) (G.H)
/*两个矩形并集的面积 = 两个矩形的总面积 - 两个矩形交集的面积。

两个矩形如果有交集，那么交集一定是矩形，剩下的问题是求出交集的长和宽。

求交集的长和宽是一个一维问题，即在数轴上给出线段 [A,B] 和 [C,D]，求它们交集的长度。
其交集的长度：L=min(B,D)−max(A,C)，如果 L<0，说明两个线段不重合。
*/
    int computeArea(LL A, LL B, LL C, LL D, LL E, LL F, LL G, LL H) {
        LL X = max(0ll, min(C, G) - max(A, E)); // 线段交线套路
        LL Y = max(0ll, min(D, H) - max(B, F));
        return (C - A) * (D - B) + (G - E) * (H - F) - X * Y;
    }
};