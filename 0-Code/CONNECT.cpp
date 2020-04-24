#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <vector <int> > a;
vector <bool> cx;
void Nhap() {
	freopen("CONNECT.INP","r",stdin);
	cin>>n>>m;
	cx.resize(n+1,true);
	a.resize(n+1);
	int u,v;
	for (int i=1;i<=n;i++) {
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
}
void DFS(int i) {
	cx[i]=false;
	cout<<i<<" ";
	if (a[i].empty()) return;
	for (int v: a[i]) if (cx[v]) DFS(v);
}
int32_t main(void) {
	freopen("CONNECT.OUT","w",stdout);
	Nhap();
	for (int i=1;i<=n;i++)
	if (cx[i]) {
		DFS(i);
		cout<<endl;
	}
	return 0;
}