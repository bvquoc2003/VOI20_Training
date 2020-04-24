#include <bits/stdc++.h>
using namespace std;
const int64_t oo = 888888888888;
typedef pair<int64_t, int> ii;

vector<vector <ii> >a;
int n, x;
vector <int64_t> d;
vector <int> T;
int64_t res=0;

int dijkstra(int _u, int _v){
    int u, v, du, uv;
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    for (int i=1; i<=n; i++) {
        d[i] = oo;
        T[i] = 0;
    }
    d[_u] = 0;
    T[_u] = -1;
    pq.push(ii(0, _u));
    while (pq.size()) {
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (int i=0; v=a[u][i].second; i++) {
            uv=a[u][i].first;
            if (d[v]>du+uv) {
                d[v]=du+uv;
                T[v]=u;
                pq.push(ii(d[v], v));
            }
        }
    }
    if (d[_v]==oo) return -1;
    int re;
    for (int i=0;i<a[T[_v]].size();i++)
    if (a[T[_v]][i].second==_v) {
        re=a[T[_v]][i].first;
        break;
    }
    return re;
}
int32_t main(void){
    freopen("TRUONGHOC.INP","r",stdin);
    freopen("TRUONGHOC.OUT","w",stdout);
    int p, q, m, w;
    scanf("%d%d", &n, &x);
    a.resize(n+1);
    T.resize(n+1);
    d.resize(n+1);
    for (int i=1;i<=n;i++) {
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(ii(w,q));
        a[q].push_back(ii(w,p));
    }
    for (int i=1; i<=n; i++) a[i].push_back(ii(0,0));
    for (int i=1;i<=n;i++)
    if (i!=x) res+=dijkstra(x,i);
    cout<<res;
}