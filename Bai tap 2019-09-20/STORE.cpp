#include <bits/stdc++.h>
#define MaxN 105
#define oo 1000111000
using namespace std;
int n, m, a[MaxN][MaxN], cs;
long L[MaxN][MaxN], Res=INT_MAX;
void Nhap() {
    freopen("STORE.INP","r",stdin);
    cin>>n>>m;
    int x, y, z;
    for (int i=1;i<=m;i++) {
        cin>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;
    }
}
void Floyd() {
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) {
        if (i==j) L[i][j]=0;
        else
        if (a[i][j]!=0) L[i][j]=a[i][j];
        else L[i][j]=oo;
    }
    for (int k=1;k<=n;k++)
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    if (L[i][j]>L[i][k]+L[k][j]) L[i][j]=L[i][k]+L[k][j];
}
void Xuli() {
    Floyd();
    for (int i=1;i<=n;i++) {
        long Tmp=0;
        for (int j=1;j<=n;j++) if (i!=j) Tmp+=L[i][j];
        if (Res>Tmp) {
            Res=Tmp;
            cs=i;
        }
    }
}
void Xuat() {
    freopen("STORE.OUT","w",stdout);
    cout<<cs<<" "<<Res;
}
int main() {
    Nhap();
    Xuli();
    Xuat();
    return 0;
}
