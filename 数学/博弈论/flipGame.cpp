/* 294. Flip Game II
You are playing a Flip Game with your friend.

You are given a string currentState that contains only '+' and '-'. 
You and your friend take turns to flip two consecutive "++" into "--". 
The game ends when a person can no longer make a move, and 
therefore the other person will be the winner.

Return true if the starting player can guarantee a win, and false otherwise.

Input: currentState = "++++"
Output: true
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> cache;
    bool canWin(string s) {   //回溯
        if (cache.count(s)) return cache[s];

        int n = s.size();
        for (int i = 0; i < n - 1; i ++) {
            if (s[i] == '+' && s[i+1] == '+') {
                if (canWin (s.substr(0, i) + "--" + s.substr(i+2)) == false) {
                    cache[s] = true;
                    return true;
                }    
            }
        }
        cache[s] = false;
        return false;
    }
};
