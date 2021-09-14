/* 17 
Given a string containing digits from 2-9 inclusive, return all possible
letter combinations that the number could represent. Return the answer in any order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, string> table{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}};
    vector<string> res;
    string target;
    void dfs(string str) { // 可以直接加一个参数看当前到第几位了
        int len = str.size();
        if (len == target.size()) {
            res.push_back(str);
            return;
        }
        for (auto ch : table[target[len]]) 
            dfs(str + ch);
    }  
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)    return res;        
        target = digits;
        dfs("");
        return res;
    }
};