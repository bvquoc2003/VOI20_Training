#include <bits/stdc++.h>
using namespace std;
struct pack {int u, l;};
typedef vector< vector<pack> > dsk;
int n, m;
dsk ke;
vector <int> d;
vector <long long> f;
vector <bool> b;
int main() {
    freopen("GIAOTHONG.INP","r",stdin);
    freopen("GIAOTHONG.OUT","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    ke.resize(n+1);
    for (int i=1;i<=m;i++) {
        int u, v, l;
        cin>>u>>v>>l;
        ke[u].push_back({v,l});
        ke[v].push_back({u,l});
    }
    d.resize(n+1,1e9);
    f.resize(n+1,0ll);
    b.resize(n+1,true);
    d[1]=0;
    f[1]=1ll;
    for (int tmp=n;tmp--;) {
        int u=-1;
        for (int v=1; v<=n; v++) if (b[v] && (u == -1 || d[u] > d[v])) u = v;
        if (u==-1 || u==n) break;
        b[u]=false;
        for (pack p:ke[u]) {
            int v = p.u, l = p.l;
            if (d[v]>d[u]+l) {
                d[v]=d[u]+l;
                f[v]=f[u];
            } else if (d[v]==d[u] + l) f[v]+=f[u];
        }
    }
    cout<<d[n]<<" "<<f[n];
    return 0;
}