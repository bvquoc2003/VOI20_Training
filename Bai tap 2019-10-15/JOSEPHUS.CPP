#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, t=0;
vector<int> a, b;
int32_t main(void) {
	FastIO;
	freopen("JOSEPHUS.INP","r",stdin);
	freopen("JOSEPHUS.OUT","w",stdout);
	cin>>n>>m;
	a.resize(n+1);
	for (int i=1;i<=n;i++) a[i]=i;
	for (int i=1;i<=n;i++){
		t+=m;
		t%=a.size()-1;
		if (t==0) t=a.size()-1;
		b.push_back(a[t]);
		a.erase(a.begin()+t--);
	}
	for (int x:b) cout<<x<<" ";
	return 0;
}