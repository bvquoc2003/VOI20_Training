#include <bits/stdc++.h>
using namespace std;
const int oo=INT_MAX, tmp=100000;
typedef pair<int, int> ii;
int a[1000][1000];
int n, d[1000], T[1000], res=0, cnt;
int cx[1000];
priority_queue <ii, vector<ii>, greater<ii> > pq;
void dijkstra(){
    for (int i=1; i<=n; i++) d[i] = oo;
    d[1] = 0;
    pq.push(ii(0, 1));
    while (pq.size()) {
        int u=pq.top().second;
        int du=pq.top().first;
        pq.pop();
        if (du!=d[u] || u>n) continue;
        for (int v=1;v<=n;v++) 
        if (a[u][v]!=0 && u!=v) {
            int uv=a[u][v];
            if (v>n) continue;
            if (d[v]>du+uv) {
                d[v]=du+uv;
                T[v]=u;
                pq.push(ii(d[v], v));
            }
        }
    }
}
int32_t main(void){
    freopen("ROBINSON.INP","r",stdin);
    freopen("ROBINSON.OUT","w",stdout);
    cin>>n;
    int u, v, w;
    while (!cin.eof()) {
        cin>>u>>v>>w;
        if (w==0) w=tmp;
        if (u==v) continue;
        if (u>n || v>n) continue;
        a[u][v]=w;
        a[v][u]=w;
    }
    dijkstra();
    if (d[n]==oo) {
        cout<<"-1";
        return 0;
    }
    res=d[n]%tmp;
    cnt=d[n]/tmp;
    cout<<res<<endl<<cnt;
}