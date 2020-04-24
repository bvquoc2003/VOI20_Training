#include <bits/stdc++.h>
#define oo 1000111000
#define MaxN 1005
using namespace std;
int n, r, d, s, t, Res;
int a[MaxN][MaxN], f[MaxN];
bool cx[MaxN];
void Nhap() {
    freopen("GUIDE.INP","r",stdin);
    cin>>n>>r;
    int x,y,z;
    for(int i=1;i<=r;i++) {
        cin>>x>>y>>z;
        z-=2;
        a[x][y]=z;
        a[y][x]=z;
    }
    cin>>s>>t>>d;
}
void Dijkstra() {
    memset(cx,true,sizeof(cx));
    f[s]=oo;
    while(true) {
        bool OUT=true;
        int Max=0, u;
        for(int i=1;i<=n;i++) {
            if(cx[i] && f[i]>Max) {
                OUT=false;
                Max=f[i];
                u=i;
            }
        }
        if (OUT) break;
        cx[u]=false;
        for(int v=1;v<=n;v++) if(cx[v]==true && a[u][v]>0) f[v]=max(f[v],min(f[u],a[u][v]));
    }
    Res=d/f[t];
    if(d%f[t]>0) ++Res;
}
void Xuat() {
    freopen("GUIDE.OUT","w",stdout);
    cout<<Res;
}
int main() {
    Nhap();
    Dijkstra();
    Xuat();
    return 0;
}
