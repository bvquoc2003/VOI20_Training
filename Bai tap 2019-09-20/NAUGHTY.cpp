#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, k; vector <int> a;
int Solve(int i) {
    int res=1;
    for (int j=i-1;j>0;j--) if (a[i]>=a[j] || a[j]-a[i]<=k) res++; else break;
    for (int j=i+1;j<=n;j++) if (a[i]>=a[j] || a[j]-a[i]<=k) res++; else break;
    return res;
}
const int MaxN=5000005;
int dq[MaxN], l[MaxN], r[MaxN], top=0;
int ChatNP(int t) {
    if (top==0) return dq[0];
    if (top==1) return ((t>=a[dq[1]])?dq[0]:dq[1]);
    if (t<a[dq[top]]) return dq[top];
    int left=1, right=top, p=0, mid;
    while (left<=right) {
        mid=(left+right)/2;
        if (a[dq[mid]]<=t) {
            p=mid-1;
            right=mid-1;
        } else left=mid+1;
    }
    return dq[p];
}
int32_t main(void) {
    FastIO;
    freopen("NAUGHTY.INP","r",stdin);
    freopen("NAUGHTY.OUT","w",stdout);
    cin>>n>>k; a.resize(n+2);
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        l[i]=0;
        r[i]=0;
    }
    if (n<=1000) {
        for (int i=1;i<=n;i++) 
            cout<<Solve(i)<<" ";
        return 0;
    }
    for (int i=1;i<=n;i++) {
        while (top>0 && a[i]>=a[dq[top]]) top--;
        l[i]=ChatNP(a[i]+k);
        dq[++top]=i;
    }
    top=0; dq[0]=n+1;
    for (int i=n;i>=1;i--) {
        while (top>0 && a[i]>=a[dq[top]]) top--;
        r[i]=ChatNP(a[i]+k);
        dq[++top]=i;
    }
    for (int i=1;i<=n;i++) cout<<(r[i]-l[i]-1)<<" ";
    return 0;
}