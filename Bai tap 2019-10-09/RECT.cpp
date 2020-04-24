#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MaxN=500005;
int m, n;
vector <int> h;
int64_t res;
int64_t Solve_Area() {
    stack <int> S;
    vector <int> L(n+2), R(n+2);
    for (int i=1;i<=n;++i) {
        while (!S.empty() && h[S.top()] >= h[i]) S.pop();
        L[i]=(S.empty() ? 0 : S.top());
        S.push(i);
    }
    while (!S.empty()) S.pop();
    for (int i=n;i>=1;--i) {
        while (!S.empty() && h[S.top()] >= h[i]) S.pop();
        R[i]=(S.empty() ? n+1 : S.top());
        S.push(i);
    }
    int64_t maxArea=0;
    for (int i=1;i<=n; ++i) {
        int64_t t=(int64_t) h[i]*(R[i]-L[i]-1);
        if (maxArea<t) maxArea=t;
    }
    return maxArea;
}
int32_t main() {
    FastIO;
    freopen("RECT.INP","r",stdin);
    freopen("RECT.OUT","w",stdout);
    cin>>m>>n;
    h.resize(n+2);
    for (int i=1;i<=n;i++) cin>>h[i];
    res=Solve_Area();
    for (int i=1;i<=n;i++) h[i]=m-h[i];
    res=max(res,Solve_Area());
    cout<<res;
    return 0;
}