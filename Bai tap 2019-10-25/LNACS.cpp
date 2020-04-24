// https://vn.spoj.com/problems/LNACS/
#include <bits/stdc++.h>
using namespace std;
vector <int> a, b;
int f[1001][1001];
int32_t main(void) {
    freopen("input.txt","r",stdin);
    int m, n; cin>>m>>n;
    a.resize(m+2); b.resize(n+2);
    for (int i=1; i<=m; i++) cin>>a[i];
    for (int i=1; i<=n; i++) cin>>b[i];
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i]==b[j]) {
                if (i==1 || j==1) f[i][j]=1;
                else f[i][j]=1+f[i-2][j-2];
            }
            else f[i][j]=max(f[i-1][j], f[i][j-1]);
        }
    }
    cout<<f[m][n];
    return 0;
}