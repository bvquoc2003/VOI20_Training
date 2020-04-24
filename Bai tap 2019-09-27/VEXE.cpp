#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define int64 long long
using namespace std;
typedef pair<int64,int64> ii;
const int64 oo=888888888888, MaxN=100005;
int64 n, m, k, s, t;
vector <ii> a[MaxN], e;
int64 s_[MaxN], t_[MaxN], res=oo;
void Dijkstra() {
    for (int64 i=1; i<=n; i++) a[i].push_back(ii(0,0));
    priority_queue <ii, vector<ii>, greater<ii> > pq1, pq2;
    for (int64 i=1; i<=n; i++) {
        s_[i] = oo;
        t_[i] = oo;
    }
    s_[s] = 0;
    pq1.push(ii(0,s));
    while (pq1.size()){
        int64 u=pq1.top().second;
        int64 du=pq1.top().first;
        pq1.pop();
        if (du!=s_[u]) continue;
        for (int64 i=0; int64 v=a[u][i].second; i++) {
            int64 uv=a[u][i].first;
            if (s_[v]>du+uv) {
                s_[v]=du+uv;
                pq1.push(ii(s_[v], v));
            }
        }
    }
    t_[t] = 0;
    pq2.push(ii(0,t));
    while (pq2.size()){
        int64 u=pq2.top().second;
        int64 du=pq2.top().first;
        pq2.pop();
        if (du!=t_[u]) continue;
        for (int64 i=0; int64 v=a[u][i].second; i++) {
            int64 uv=a[u][i].first;
            if (t_[v]>du+uv) {
                t_[v]=du+uv;
                pq2.push(ii(t_[v], v));
            }
        }
    }
}
int main(void) {
    FastIO;
    freopen("VEXE.INP","r",stdin);
    cin>>n>>m;
    k=1; s=1; t=n;
    if (k>1) {
        cout<<"0";
        return 0;
    }
    int64 p, q, w;
    for (int64 i=1;i<=m;i++) {
        cin>>p>>q>>w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
        e.push_back(ii(p,q));
    }
    Dijkstra();
    for (int64 i=0;i<e.size();i++) {
        p=e[i].first; q=e[i].second;
        w=min(s_[p]+t_[q],s_[q]+t_[p]);
        res=min(res,w);
    }
    // for (int64 i=1;i<=n;i++) cout<<s<<"->"<<i<<"="<<s_[i]<<endl; cout<<endl;
    // for (int64 i=1;i<=n;i++) cout<<i<<"->"<<t<<"="<<t_[i]<<endl; cout<<endl;
    freopen("VEXE.OUT","w",stdout);
    cout<<res;
    return 0;
}
