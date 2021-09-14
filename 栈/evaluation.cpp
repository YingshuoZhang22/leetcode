#include <bits/stdc++.h>
using namespace std;

stack<int> num;
stack<char> op;

void eval() {
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();
    char c = op.top(); op.pop();
    int x;
    if (c == '+') x = a + b;
    else if (c == '-') x = a - b;
    else if (c == '*') x = a * b;
    else x = a / b;
    num.push(x);
}

int main() {
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string str;
    cin >> str;
    num.push(0);    // 处理 "-"开头的情况
    for (int i = 0; i < str.size(); i ++ ) {
        char c = str[i];
        if (isdigit(c)) {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 - '0' + str[j ++ ] ; // 先减0，防止溢出        
            i = j - 1;
            num.push(x);
        } else if (c == '(') 
            op.push(c);
          else if (c == ')') {
            while (op.top() != '(') eval();
            op.pop();
        } else if (c == ' ') {
            continue;
        } else {    // operator
            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c]) eval();   // 栈顶优先级高就先算
            op.push(c);
        }
    }
    while (op.size()) eval();
    cout << num.top() << endl;
    return 0;
}