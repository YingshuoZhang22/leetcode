/* 133. Clone Graph (有向图)
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
*/

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> hash;   // mapping：原始点 - 复制点
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        dfs(node);  // 复制所有点

        for (auto [s, d]: hash) {
            for (auto ver: s->neighbors)    // 每个原始点对应的原始邻居
                d->neighbors.push_back(hash[ver]);  // 给复制点加上复制邻居
        }

        return hash[node];
    }

    void dfs(Node* node) {
        hash[node] = new Node(node->val);   // 新建一个点

        for (Node* ver: node->neighbors)
            if (hash.count(ver) == 0)   // 没有被遍历过的点
                dfs(ver);
    }
};
