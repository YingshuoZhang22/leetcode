/* 71
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res, name;
        if (path.back() != '/') path += '/';    // 给末尾也补一个'/'，方便处理
        for (auto c : path) {
            if (c != '/') name += c;    // 读一个name
            else {
                if (name == "..") {     // 删除上一级目录
                    while (res.size() && res.back() != '/') res.pop_back();
                    if (res.size()) res.pop_back(); // 删除'/'
                } else if (name != "." && name != "") { // 是一个有效的文件名
                    res += '/' + name;
                }
                name.clear();   // 清空name
            }
        }

        if (res.empty()) res = "/";
        return res;
    }
};
