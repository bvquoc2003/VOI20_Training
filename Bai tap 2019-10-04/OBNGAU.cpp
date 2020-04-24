#include <bits/stdc++.h>
using namespace std;
const int64_t oo = 888888888888;
typedef pair<int64_t, int> ii;

vector<vector <ii> >a; 
int n, m, s, t, res=0;
vector <int64_t> d;
vector <int> T;
void dijkstra() {
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    d.resize(n+1);
    T.resize(n+1);
    for (int i=1; i<=n; i++) {
        d[i] = oo;
        T[i] = 0;
    }
    d[s] = 0;
    T[s] = -1;
    pq.push(ii(0, s));

    while (pq.size()) {
        int u=pq.top().second;
        int64_t du=pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (int i=0; int v=a[u][i].second; i++) {
            int64_t uv=a[u][i].first;
            if (d[v]>du+uv) {
                d[v]=du+uv;
                T[v]=u;
                pq.push(ii(d[v], v));
            }
        }
    }
    if (d[t]==oo) return;
    int x=t;
    while (T[x]!=-1) {
        cout<<x<<endl;
        res++;
        x=T[x];
    }
}

int32_t main(void) {
    freopen("OBNGAU.INP","r",stdin);
    freopen("OBNGAU.OUT","w",stdout);
    int p, q, m, w;
    cin>>n>>m>>s>>t;
    a.resize(n+1);
    for (int i=1;i<=m;i++) {
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(ii(w,q));
        a[q].push_back(ii(w,p));
    }
    for (int i=1; i<=n; i++) a[i].push_back(ii(0,0));
    dijkstra();
    if (d[t]==oo) cout<<"CRY";
    else cout<<res;
}