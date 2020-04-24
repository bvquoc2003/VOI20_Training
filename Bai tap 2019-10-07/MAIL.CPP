#include <bits/stdc++.h>
using namespace std;
const int64_t oo = 888888888888;
typedef pair<int64_t, int> ii;
vector<vector <ii> > a; 
int n, m, s, t; int64_t res=0;
vector <int64_t> d;
void Nhap() {
    freopen("MAIL.INP","r",stdin);
    cin>>n>>m>>s>>t;
    a.resize(n+1);
    d.resize(n+1);
    int p,q,w;
    for (int i=1;i<=m;i++) {
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(ii(w,q));
        a[q].push_back(ii(w,p));
    }
    for (int i=1; i<=n; i++) a[i].push_back(ii(0,0));
}
void dijkstra(int _s) {
    priority_queue <ii, vector<ii>, greater<ii> > pq;

    for (int i=1; i<=n; i++) d[i] = oo;
    d[_s] = 0;
    pq.push(ii(0, _s));

    while (pq.size()) {
        int u=pq.top().second;
        int64_t du=pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (int i=0; int v=a[u][i].second; i++) {
            int64_t uv=a[u][i].first;
            if (d[v]>du+uv) {
                d[v]=du+uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}
void Xuat() {
    dijkstra(s);
    res+=d[1];
    dijkstra(1);
    res+=d[t];
    freopen("MAIL.OUT","w",stdout);
    cout<<res;
}
int32_t main(void){
    Nhap();
    Xuat();
}