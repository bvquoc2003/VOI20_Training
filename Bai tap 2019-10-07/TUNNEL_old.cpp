#include <bits/stdc++.h>
#define oo 1000111000
#define MaxN 5005
using namespace std;
int n, m, s, t, MaxH;
int h[MaxN][MaxN], d[MaxN][MaxN];
int f[MaxN], T[MaxN];
bool cx[MaxN];
void Nhap() {
    freopen("TUNNEL.INP","r",stdin);
    cin>>n>>s>>t;
    cin>>m;
    int x,y,H,D;
    for (int i=1;i<=m;i++) {
        cin>>x>>y>>H>>D;
        h[x][y]=H; h[y][x]=H;
        d[x][y]=D; d[y][x]=D;
    }
}
void Dijkstra1() {
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
        for(int v=1;v<=n;v++) if(cx[v] && h[u][v]>0) f[v]=max(f[v],min(f[u],h[u][v]));
    }
    MaxH=f[t];
}

void Dijkstra2() {
    for (int i=1;i<=n;i++) {
        f[i]=oo;
        T[i]=-1;
        cx[i]=true;
    }
    f[s]=0;
    while (true) {
        int u=0, Min=oo;
        for (int i=1;i<=n;i++)
        if (cx[i] && f[i]<Min) {
            u=i;
            Min=f[i];
        }
        cx[u]=false;
        if (u==0 || u==t) break;
        for (int v=1;v<=n;v++) {
            if (cx[v] && d[u][v]!=0 && h[u][v]>=MaxH && f[v]>f[u]+d[u][v]) {
                f[v]=f[u]+d[u][v];
                T[v]=u;
            }
        }
    }
}
void Xuat() {
    freopen("TUNNEL.OUT","w",stdout);
    int x=t; vector <int> luu;
    while (T[x]!=-1) {
        luu.push_back(x);
        x=T[x];
        if (x==s) {
            luu.push_back(s);
            break;
        }
    }
    cout<<luu.size()<<endl;
    for (int i=luu.size()-1;i>=0;i--) cout<<luu[i]<<" ";
}
int main() {
    Nhap();
    Dijkstra1();
    Dijkstra2();
    Xuat();
    return 0;
}