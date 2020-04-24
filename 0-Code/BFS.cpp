#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector <vector<int> > a;
vector <bool> cx;
vector <int> T, res;
queue <int> q;
void Nhap() {
    freopen("BFS.INP","r",stdin);
    cin>>n>>m>>s>>t;
    a.resize(n+1);
    cx.resize(n+1,true);
    T.resize(n+1);
    int u, v;
    for (int i=1;i<=m;i++) {
        cin>>u>>v;
        a[u].push_back(v);
    }
    for (int i=1;i<=n;i++) if (!a[i].empty()) sort(a[i].begin(),a[i].end());
    T[s]=-1;
}
void BFS() {
    q.push(s);
    cx[s]=false;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        if (a[u].empty()) continue;
        for (int v:a[u]) 
        if(cx[v]) {
            q.push(v);
            cx[v]=false;
            T[v]=u;
        }
    }
}
void Xuat() {
    freopen("BFS.OUT","w",stdout);
    while (t!=s) {
        res.push_back(t);
        t=T[t];
    } res.push_back(s);
    reverse(res.begin(),res.end());
    for (int i=0;i<res.size();i++) cout<<res[i]<<' ';

}
int32_t main(void) {
    Nhap();
    BFS();
    Xuat();
    return 0;
}