/* 在一条数轴上有 N 家商店，它们的坐标分别为 A1∼AN。
现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。
为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。 
*/

/* 结论：如果有奇数个点，选中位数；如果有偶数个点，中间的随便二选一 */

/* 证明：
绝对值不等式: |x-a| + |x-b| >= |a-b|, 当仅当x在ab之间的时候取等
泛化到n个点：|x-a1| + |x-a2| + |x-a3| + .. + |x-an| >= 
           |a1-an| + |a2-an-1| + .. + |aMid - aMid+1|
           取中位数的时候取等 
*/

// 拓展到二维：
/* 296. Best Meeting Point
Given an m x n binary grid grid where each 1 marks the home of one friend, return the minimal total travel distance.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.

The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.


Input: grid = [[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]
Output: 6
Explanation: Given three friends living at (0,0), (0,4), and (2,2).
The point (0,2) is an ideal meeting point, as the total travel distance of 2 + 2 + 2 = 6 is minimal.
So return 6.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minTotalDistance(vector<vector<int>>& grid) {
        // 因为曼哈顿距离在x，y上相互独立，变成两次一维的选点问题
		vector<int> vx, vy;
		for (int x = 0; x < grid.size(); x++) {
			for (int y = 0; y < grid[x].size(); y++) {
				if (grid[x][y] > 0) {
					vx.push_back(x);
					vy.push_back(y);
				}
			}
		}

		sort(vy.begin(), vy.end());
		int mx = vx[vx.size() / 2];
		int my = vy[vy.size() / 2];

		int ans = 0;
		for (int x : vx) ans += abs(x - mx);
		for (int y : vy) ans += abs(y - my);
		return ans;
	}
};