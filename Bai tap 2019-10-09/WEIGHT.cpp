#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo=INT_MAX;
int n, res=0;
vector <int> a, L, R;
void Solve_Min() {
    stack <int> S;
    for (int i=1;i<=n;++i) {
        while (!S.empty() && a[S.top()]>=a[i]) S.pop();
        L[i]=(S.empty() ? 0 : (S.top()));
        L[i]++;
        S.push(i);
    }
    while (!S.empty()) S.pop();
    for (int i=n;i>=1;--i) {
        while (!S.empty() && a[S.top()]>a[i]) S.pop();
        R[i]=(S.empty() ? n+1 : S.top());
        R[i]--;
        S.push(i);
    }
    for (int i=1;i<=n;i++) res-=a[i]*((i-L[i]+1)*(R[i]-i+1));
    // for (int i=1;i<=n;i++) cout<<a[i]<<" "<<L[i]<<" "<<R[i]<<endl;
    // cout<<"--------\n";
}
void Solve_Max() {
    stack <int> S;
    for (int i=1;i<=n;++i) {
        while (!S.empty() && a[S.top()]<=a[i]) S.pop();
        L[i]=(S.empty() ? 0 : (S.top()));
        L[i]++;
        S.push(i);
    }
    while (!S.empty()) S.pop();
    for (int i=n;i>=1;--i) {
        while (!S.empty() && a[S.top()]<a[i]) S.pop();
        R[i]=(S.empty() ? n+1 : S.top());
        R[i]--;
        S.push(i);
    }
    for (int i=1;i<=n;i++) res+=a[i]*((i-L[i]+1)*(R[i]-i+1));
    // for (int i=1;i<=n;i++) cout<<a[i]<<" "<<L[i]<<" "<<R[i]<<endl;
    // cout<<"--------\n";
}
int32_t main(void) {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("WEIGHT.INP","r",stdin);
    cin>>n; a.resize(n+1);
    L.resize(n+2); R.resize(n+2);
    for (int i=1;i<=n;i++) cin>>a[i];
    Solve_Min();
    Solve_Max();
    freopen("WEIGHT.OUT","w",stdout);
    cout<<res;
}