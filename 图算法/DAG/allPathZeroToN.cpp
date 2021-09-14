/* 797. All Paths From Source to Target
Given a directed acyclic graph (DAG) of n nodes labeled from 0 
to n - 1, find all possible paths from node 0 to node n - 1 
and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes 
you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/

#include <bits/stdc++.h>
using namespace std;

// 简单dfs，没什么好说的
class Solution {
public:
    int n;
    vector<vector<int>> g;
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int u) {
        path.push_back(u);
        if (u == n - 1) ans.push_back(path);
        for (auto v: g[u]) dfs(v);
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        g = graph;
        n = g.size();
        dfs(0);
        return ans;
    }
};
