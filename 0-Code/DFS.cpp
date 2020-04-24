#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector <set <int> > a;
vector <bool> cx;
vector <int> T, res;
void Nhap() {
	freopen("PATH.INP","r",stdin);
	freopen("DFS.OUT","w",stdout);
	cin>>n>>m>>s>>t;
	a.resize(n+1);
	cx.resize(n+1,true);
	T.resize(n+1);
	int u, v;
	for (int i=1;i<=m;i++) {
		cin>>u>>v;
		a[u].insert(v);
	}
	T[s]=-1;
}
void DFS(int u) {
	cx[u]=false;
	if (a[u].empty()) return;
	for (auto v: a[u]) 
	if (cx[v]) {
		T[v]=u;
		DFS(v);
	}
}
void Find(int u) {
	if (T[u]!=-1) {
        res.push_back(u);
        Find(T[u]);
    } else res.push_back(u);
}
void Xuat() {
	Find(t);
	reverse(res.begin(),res.end());
	for (int x:res) cout<<x<<" ";
}
int32_t main(void) {
	Nhap();
	DFS(s);
	Xuat();
	return 0;
}