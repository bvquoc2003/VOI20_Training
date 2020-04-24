#include <bits/stdc++.h>
using namespace std;
typedef pair <int64_t,int> ii;
const int64_t oo=1000111000;
int n, m, cs=0; int64_t res=888888888888;
vector <int64_t> d;
int a[5005][5005];
void Nhap() {
    freopen("TRUNGTAM.INP","r",stdin);
    freopen("TRUNGTAM.OUT","w",stdout);
    cin>>n>>m;
    d.resize(n+1);
    int u, v, w;
    for (int i=1;i<=m;i++) {
    	cin>>u>>v>>w;
    	a[u][v]=w;
    	a[v][u]=w;
    }
}
void Dijkstra(int s) {
	priority_queue <ii, vector<ii>, greater<ii> > pq;
	for (int i=1; i<=n; i++) d[i] = oo;
	d[s] = 0;
    pq.push(ii(0,s));
    while (pq.size()){
        int u=pq.top().second;
        int64_t du=pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (int v=1;v<=n;v++)
        if (a[u][v]!=0) {
            int64_t uv=a[u][v];
            if (d[v]>du+uv) {
				d[v]=du+uv;
				pq.push(ii(d[v], v));
            }
        }
    }
    int64_t tmp=0;
    for (int i=1;i<=n;i++) tmp+=d[i];
    if (res>tmp) {
    	cs=s;
    	res=tmp;
    }
}
int32_t main(void) {
    Nhap();
    for (int i=1;i<=n;i++) Dijkstra(i);
    cout<<cs<<endl<<res;
    return 0;
}
