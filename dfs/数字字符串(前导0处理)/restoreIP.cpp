/* 93
Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return ans;
    }

    // u是枚举到的s下表，k是枚举次数
    void dfs(string& s, int u, int k, string path) {
        if (u == s.size()) {
            if (k == 4) {
                path.pop_back();    // 去掉结尾的"."
                ans.push_back(path);
            }
            return;
        }
        if (k == 4) return; // 字符串没用完
        for (int i = u, t = 0; i < s.size(); i ++ ) {
            if (i > u && s[u] == '0') break;  // 有前导0
            t = t * 10 + s[i] - '0';
            if (t <= 255) dfs(s, i + 1, k + 1, path + to_string(t) + '.');
            else break;
        }
    }
};


// naive method
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;

        for (int a = 1; a < 4; a ++ )
            for (int b = 1; b < 4; b ++ )
                for (int c = 1; c < 4; c ++ )
                    for (int d = 1; d < 4; d ++ )           //abcd分别表示四段ip地址长度
                    {
                        if (a + b + c + d == s.size())      //四段长度刚好
                        {
                            string s1 = s.substr(0, a);     //分别截取四段ip地址
                            string s2 = s.substr(a, b);
                            string s3 = s.substr(a + b, c);
                            string s4 = s.substr(a + b + c);

                            if (check(s1) && check(s2) && check(s3) && check(s4))
                            {
                                string ip = s1 + '.' + s2 + '.' + s3 + '.' + s4;
                                res.push_back(ip);
                            }
                        }
                    }

        return res;
    }

    bool check(string s)  {      //判断ip地址每段的第一位不为0，或只有一位且该位为0{
        if (stoi(s) <= 255)
            if (s[0] != '0' || (s[0] == '0' && s.size() == 1)) 
                return true;
        return false;
    }
};