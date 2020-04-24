#include <bits/stdc++.h>

using namespace std;
const int MaxN=5005;
const int64_t oo=8888888888888888;
long n,m,k;
int64_t a[MaxN], f[MaxN][MaxN];
int main() {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("KTX.INP","r",stdin);
    freopen("KTX.OUT","w",stdout);
    cin>>n>>m>>k;
    for (int i=0;i<=m;i++)
        for (int j=0;j<=k;j++)
            f[i][j]=oo;

    for (int i=0;i<=k;i++) f[0][i]=0;
    for (int i=1;i<=n;i++) {
        int u; cin>>u;
        a[u]++;
    }
    for (int i=1;i<=m;i++) 
        for (int j=0;j<=k;j++) 
            for (int t=0;t<=j;t++) {
                int64_t x=a[i]/(t+1);
                int64_t y=a[i]%(t+1);
                int64_t kq=((x*(x+1))/2)*(t+1) + (x+1)*y;
                f[i][j]=min(f[i][j],kq+f[i-1][j-t]);
            }
    cout<<f[m][k];

    return 0;
}
