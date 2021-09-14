#include <iostream>
#include <vector>
#include <deque>
using namespace std;
const int N = 100001;
int n, k, a[N], mq[N]; //单调队列存数组元素下标

int main() {
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i ++) 
        cin >> a[i];

    deque<int> que;
    // 输出最小值（在队头）   
    for (int i = 0; i < n; i ++) {
        // 判断队头是否已经滑出窗口
        if (que.size() && que.front() <= i - k) // 弹出过期元素
            que.pop_front();
        while (que.size() && a[que.back()] >= a[i])     //插入一个新的元素前，移除队列中所有比这个元素大的元素
            que.pop_back();
        que.push_back(i);   // 添加新元素
        if (i >= k - 1)     cout << a[que.front()] << ' ';  // 添加新元素
    }
    cout << endl; 
    
    // 输出最大值    
    que.clear();
    for (int i = 0; i < n; i ++) {
        // 判断队头是否已经滑出窗口
        if (que.size() && que.front() <= i - k)
            que.pop_front();
        while (que.size() && a[que.back()] <= a[i])     //插入一个新的元素前，移除队列中所有比这个元素大的元素
            que.pop_back();
        que.push_back(i);
        if (i >= k - 1)     cout << a[que.front()] << ' ';
    }
    
    return 0;
}
