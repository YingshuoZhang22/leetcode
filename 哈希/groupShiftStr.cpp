/* 249. Group Shifted Strings
We can shift a string by shifting each of its letters to its successive letter.

For example, "abc" can be shifted to be "bcd".
We can keep shifting the string to form a sequence.

For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hashmap;
        for(string s : strings){
            string ss(s);
            for(int i = 0; i < ss.size(); i++) ss[i] = (ss[i] - s[0] + 26) % 26 +'a';
            hashmap[ss].push_back(s);
        }
        for(auto i : hashmap) res.push_back(i.second);
        return res;
    }
};
