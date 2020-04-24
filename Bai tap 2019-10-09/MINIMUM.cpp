#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, k, x;
vector <int> ST;
void update(int id, int l, int r, int i, int v) {
    if (i < l || r < i) return;
    if (l==r) {
        ST[id]=v;
        return;
    }
    int mid=(l+r)>>1, id1=id<<1, id2=(id<<1)+1;
    update(id1,l,mid,i,v);
    update(id2,mid+1,r,i,v);
    ST[id]=min(ST[id1],ST[id2]);
}
int getmin(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return INT_MAX;
    if (u <= l && r <= v) return ST[id];
    int mid=(l+r)>>1, id1=id<<1, id2=(id<<1)+1;
    return min(getmin(id1,l,mid,u,v), getmin(id2, mid+1, r, u, v));
}
int32_t main() {
    freopen("MINIMUM.INP","r",stdin);
    freopen("MINIMUM.OUT","w",stdout);
    cin>>n>>k;
    ST.resize(4*n+5);
    for (int i=1;i<=n;i++) {
        scanf("%d",&x);
        update(1,1,n,i,x);
    }
    for (int i=0;i<n-k+1;i++) printf("%d\n",getmin(1,1,n,i+1,i+k));
    return 0;
}