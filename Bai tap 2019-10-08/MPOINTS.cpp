#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int64_t oo = 999999999999999999;
typedef pair<int64_t, int> ii;
typedef pair<int,int> pi;
vector<vector <ii> >a; 
int n, k;
vector <int64_t> one_to, n_to, res;
vector <pi> queries;

void Nhap() {
	freopen("MPOINTS.INP","r",stdin);
	int m;
	cin>>n>>m>>k;
	a.resize(n+1);
    one_to.resize(n+1);
    n_to.resize(n+1);
    int u, v, w;
    while (m--) {
    	cin>>u>>v>>w;
    	a[u].push_back(ii(w,v));
    }
    for (int i=1;i<=n;i++) a[i].push_back(ii(0,0));
    while (k--) {
    	cin>>u>>v;
    	queries.push_back(make_pair(u,v));
    }
}
void dijkstra_init1();
void dijkstra_init2();
void Brute_Force() {
	int64_t ans;
	for (pi q:queries) {
		ans=oo;
		for (int i=1;i<=n;i++) {
			if (one_to[i]==oo || n_to[i]==oo) continue;
			ans=min(ans,one_to[i]*q.first+n_to[i]*q.second);
		}
		res.push_back(ans);
	}
}
void Greedy() {
	int x=1;
	int64_t tmp=n_to[1];
	for (int i=2;i<=n;i++) 
	if (tmp>one_to[i]+n_to[i]) {
		tmp=one_to[i]+n_to[i];
		x=i;
	}
	for (pi q:queries) res.push_back(int64_t(one_to[x]*q.first+n_to[x]*q.second));
}
void Xuat() {
	freopen("MPOINTS.OUT","w",stdout);
	for (int64_t x:res) cout<<x<<endl;
}

int32_t main(void) {
	FastIO;
	Nhap();
	dijkstra_init1();
	dijkstra_init2();
	Brute_Force();
	Xuat();
	return 0;
}

void dijkstra_init1() {
	priority_queue <ii, vector<ii>, greater<ii> > pq;
    for (int i=1; i<=n; i++) one_to[i] = oo;
    one_to[1]=0;
    pq.push(ii(0,1));
    while (pq.size()){
        int u=pq.top().second;
        int64_t du=pq.top().first;
        pq.pop();
        if (du!=one_to[u]) continue;
        for (int i=0; int v=a[u][i].second; i++) {
            int64_t uv=a[u][i].first;
            if (one_to[v]>du+uv) {
                one_to[v]=du+uv;
                pq.push(ii(one_to[v], v));
            }
        }
    }
}
void dijkstra_init2() {
	priority_queue <ii, vector<ii>, greater<ii> > pq;
    for (int i=1; i<=n; i++) n_to[i] = oo;
    n_to[n]=0;
    pq.push(ii(0,n));
    while (pq.size()){
        int u=pq.top().second;
        int64_t du=pq.top().first;
        pq.pop();
        if (du!=n_to[u]) continue;
        for (int i=0; int v=a[u][i].second; i++) {
            int64_t uv=a[u][i].first;
            if (n_to[v]>du+uv) {
                n_to[v]=du+uv;
                pq.push(ii(n_to[v], v));
            }
        }
    }
}