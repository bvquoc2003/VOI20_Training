#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MaxN=100;
int m, n;
int a[MaxN][MaxN];
int64_t f[MaxN][MaxN], res;
void Nhap() {
    freopen("INVEST.INP","r",stdin);
    cin>>m>>n;
    for (int i=1;i<=m;i++) 
    for (int j=1;j<=n;j++) 
    cin>>a[i][j];
}
void QHD() {
    for (int i=0;i<=m+1;i++) for (int j=0;j<=n+1;j++) f[i][j]=0;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    for (int k=0;k<=j;k++)
    f[i][j]=max(f[i][j],int64_t(f[i-1][j-k]+a[k][i]));
    res=f[n][m];
}
void Xuat() {
    freopen("INVEST.OUT","w",stdout);
    cout<<res;
}
int32_t main(void) {
    FastIO;
    Nhap();
    QHD();
    Xuat();
    return 0;
}