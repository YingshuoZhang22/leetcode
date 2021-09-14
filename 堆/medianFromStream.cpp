/* 295. Find Median from Data Stream
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    // 对顶堆，yyds
    int min_size = 0, up_size = 0;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (min_size == up_size) {
            if (min_size == 0 || num >= minheap.top()) {
                min_size++, minheap.push(num);
            } else {
                maxheap.push(num);
                minheap.push(maxheap.top());
                maxheap.pop(), min_size++;
            }
        } else {
            if (num >= minheap.top()) {
                minheap.push(num);
                maxheap.push(minheap.top());
                minheap.pop(), up_size++;
            } else {
                maxheap.push(num), up_size++;
            }
        }
    }
    
    double findMedian() {
        if (min_size > up_size) {
            return minheap.top();
        } else {
            return (minheap.top() + maxheap.top()) / 2.0;
        }
    }
};
