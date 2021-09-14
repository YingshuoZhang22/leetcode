/* 141. Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

/* 142. Linked List Cycle II
find the begin of cycle
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)   return nullptr;
        ListNode *fast = head, *slow = head;
        while (true) {
            if (!fast || !fast->next)    return nullptr;
            slow = slow->next, fast = fast->next->next;
            if (fast == slow) {
                break;
            }
        }

        // 相遇之后，快指针指向链表头，二者以相同速度移动，相遇的就是环
        fast = head;
        while (fast != slow) {
            fast = fast->next, slow = slow->next;
        }
        return fast;
    }
};


/* 287. Find the Duplicate Number
Given an array of integers nums containing n + 1 integers 
where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums 
and uses only constant extra space.

Input: nums = [1,3,4,2,2]
Output: 2
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow =0, fast = 0;
        while (true) {
            slow = nums[slow], fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        fast = 0;
        while (fast != slow) {
            fast = nums[fast], slow = nums[slow];
        }
        return fast;
    }
};
