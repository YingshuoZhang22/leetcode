/*
给定 N 个闭区间 [ai,bi]，请你在数轴上选择若干区间，使得选中的区间之间互不相交（包括端点）。
输出可选取区间的最大数量。
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 100005;
int n;
PII s[N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &s[i].first, &s[i].second);

    sort(s + 1, s + 1 + n);

    int ans = 1, maxR = s[1].second;
    for(int i = 2; i <= n; i++){
        if(s[i].first <= maxR) 
            maxR = min(maxR, s[i].second);
        else 
            ans++, maxR = s[i].second;
    }
    printf("%d\n", ans);
}
