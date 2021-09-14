/*207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);   //g[i]存要上i指向的所有课程
        vector<int> d(n);   // d[i]是第i门课的入度，即多少条边指向d[i]，如果d[i]==0表示可以修d[i]
        for (auto& e: edges) {
            int b = e[0], a = e[1];
            g[a].push_back(b);
            d[b] ++ ;
        }

        queue<int> q;   // 对列里存的都是可以上的课
        for (int i = 0; i < n; i ++ )
            if (d[i] == 0)
                q.push(i);

        int cnt = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt ++ ;
            for (auto i : g[t])
                if ( -- d[i] == 0)  // 如果上完第i门导致i的出度里有可以上的，就把它加进队列
                    q.push(i);
        }

        return cnt == n;
    }
};
