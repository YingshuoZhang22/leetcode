#include <iostream>
#include <vector>
using namespace std;

// 判断是否 A >= B
bool cmp(vector<int>& A, vector<int>& B) {
    if (A.size() != B.size())    return B.size() < A.size();
    for (int i = A.size(); i >= 0 ; -- i) {
        if (A[i] != B[i])   return B[i] < A[i];
    }
    return true;
}

// A - B
vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int carry = 0;
    for (int i = 0; i < A.size(); ++ i) {
        carry = A[i] - carry;
        if (i < B.size()) carry -= B[i];
        C.push_back((carry + 10) % 10); // -7 —> 3;  7 -> 7
        if (carry < 0)  carry = 1;
        else            carry = 0;
    }
    
    while (C.size() > 1 && C.back() == 0) //去掉前导0
        C.pop_back();
        
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; -- i)    A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; -- i)    B.push_back(b[i] - '0');
    
    vector<int> C;
    if (cmp(A, B)) {
        C = sub(A, B);
    } else {
        C = sub(B, A);
        cout << "-";
    }
    for (int i = C.size() - 1; i >= 0; -- i)    cout << C[i];
    return 0;
}