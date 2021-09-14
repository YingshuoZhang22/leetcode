/*
在一个 3×3 的网格中，1∼8 这 8 个数字和一个 x 恰好不重不漏地分布在这 3×3 的网格中。
例如：
1 2 3
x 4 6
7 5 8
在游戏过程中，可以把 x 与其上、下、左、右四个方向之一的数字交换（如果存在）。
我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：
1 2 3
4 5 6
7 8 x
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int bfs(string start) {
    string end = "12345678x";
    queue<string> q;
    unordered_map<string, int> d;
    
    q.push(start);
    d[start] = 0;
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    
    while (q.size()) {
        auto t = q.front();
        q.pop();
        int distance = d[t];
        if (t == end)   return distance;
        
        // state transfer
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(t[k], t[a * 3 + b]);
                
                if (!d.count(t)) {
                    d[t] = distance + 1;
                    q.push(t);
                }
                
                swap(t[k], t[a * 3 + b]);   //本轮循环的t用完还要回复回去
            }
        }
    }
    return -1;
}

int main() {
    string start;
    for (int i = 0; i < 9; i ++) {
        char c;
        cin >> c;
        start += c;
    }
    cout << bfs(start) << endl;
    return 0;
}