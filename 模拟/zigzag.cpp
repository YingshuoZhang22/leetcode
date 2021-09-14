/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)   return s;
        vector<string> v(numRows, "");
        int flag = 0;
        for (int i = 0, counter = 0; i < s.size(); i++) {
            v[counter] += s[i];
            if (flag == 0) counter++;
            else counter--;
            if (counter == numRows) 
                flag = 1, counter = numRows - 2;
            else if (counter == -1) 
                flag = 0, counter = 1;
        }
        string res;
        for (auto str: v)   res += str;
        return res;
    }
};
