#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int SZ=23;
int n, m, k, l;
int f[SZ][SZ][SZ][SZ];
int dp(int a, int b, int cntk, int cntl) {
    if (f[a][b][cntk][cntl]!=-1) return f[a][b][cntk][cntl];
    int cur=dp(a-1,b,cnk+1,0)+dp(a,b-1,0,cntl+1);
    return f[a][b][cntk][cntl]=cur;
}
int32_t main() {
    FastIO;
    freopen("BINARY.INP","r",stdin);
    freopen("BINARY.OUT","w",stdout);
    cin>>n>>m>>k>>l;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int _k=1;_k<k;_k++)
                for (int _l=1;_l<=l;_l++)
                    f[i][j][_k][_l]=-1;
    cout<<dp(n,m,0,0);
    return 0;
}