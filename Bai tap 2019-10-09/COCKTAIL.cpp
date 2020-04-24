#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int lim=1e4, NA=1e9;
int n, t, trace[lim];
vector<int> a, res;
void Nhap() {
	freopen("COCKTAIL.INP","r",stdin);
	cin>>n>>t;
	a.resize(n);
	res.resize(n);
	for (int& x:a) cin>>x;
	for (int& x:trace) x=NA;
}
void Solve() {
	queue<int> q;
	for (int i=0;i<n;i++) {
		a[i]-=t;
		if (a[i]>0 && trace[a[i]]==NA) {
			trace[a[i]]=i;
			q.push(a[i]);
		}
	}
	while (!q.empty())  {
		int u=q.front(); q.pop();
		for (int i=0;i<n;i++) {
			int v=u+a[i];
			if (v<0) continue;
			if (v<lim && trace[v]==NA) {
				trace[v]=i;
				if (v==0) return;
				q.push(v);
			}
		}
	}
}
void Xuat() {
	freopen("COCKTAIL.OUT","w",stdout);
	if (trace[0]==NA) {
        cout<<"NO";
        return;
	}
	int v=0;
    do {
		int i=trace[v];
		res[i]++;
		v-=a[i];
	} while (v!=0);
    cout<<"YES\n";
    for (int i=0;i<n;i++) cout<<res[i]<<" ";
}
int main() {
	FastIO;
	Nhap();
	Solve();
	Xuat();
}